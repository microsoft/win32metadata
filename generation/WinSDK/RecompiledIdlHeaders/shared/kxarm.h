;++
;
; Copyright (c) Microsoft Corporation.  All rights reserved.
;
;
; Module:
;
;   kxarm.w
;
; Abstract:
;
;   Contains ARM architecture constants and assembly macros.
;
;--

;
; The ARM assembler uses a baroque syntax that is documented as part
; of the online Windows CE documentation.  The syntax derives from
; ARM's own assembler and was chosen to allow the migration of
; specific assembly code bases, namely ARM's floating point runtime.
; While this compatibility is no longer strictly necessary, the
; syntax lives on....
;
; Highlights:
;      * Assembler is white space sensitive.  Symbols are defined by putting
;        them in the first column
;      * The macro definition mechanism is very primitive
;
; To augment the assembler, assembly files are run through CPP (as they are
; on IA64).  This works well for constants but not structural components due
; to the white space sensitivity.
;
; For now, we use a mix of native assembler and CPP macros.
;

#undef TRUE
#undef FALSE

#define TRUE 1
#define FALSE 0

#define ENABLE_FRAME_POINTER 1

#include "kxarmunw.h"


        ;
        ; Global variables
        ;

        ; Current function names and labels
        GBLS    __FuncStartLabel
        GBLS    __FuncEpilog1StartLabel
        GBLS    __FuncEpilog2StartLabel
        GBLS    __FuncEpilog3StartLabel
        GBLS    __FuncEpilog4StartLabel
        GBLS    __FuncXDataLabel
        GBLS    __FuncXDataPrologLabel
        GBLS    __FuncXDataEpilog1Label
        GBLS    __FuncXDataEpilog2Label
        GBLS    __FuncXDataEpilog3Label
        GBLS    __FuncXDataEpilog4Label
        GBLS    __FuncXDataEndLabel
        GBLS    __FuncEndLabel

        ; other globals relating to the current function
        GBLS    __FuncArea
        GBLS    __FuncExceptionHandler


        ;
        ; Helper macro: generate the various labels we will use internally
        ; for a function
        ;
        ; Output is placed in the various __Func*Label globals
        ;

        MACRO
        __DeriveFunctionLabels $FuncName

__FuncStartLabel        SETS "|$FuncName|"
__FuncEndLabel          SETS "|$FuncName._end|"
__FuncEpilog1StartLabel SETS "|$FuncName._epilog1_start|"
__FuncEpilog2StartLabel SETS "|$FuncName._epilog2_start|"
__FuncEpilog3StartLabel SETS "|$FuncName._epilog3_start|"
__FuncEpilog4StartLabel SETS "|$FuncName._epilog4_start|"
__FuncXDataLabel        SETS "|$FuncName._xdata|"
__FuncXDataPrologLabel  SETS "|$FuncName._xdata_prolog|"
__FuncXDataEpilog1Label SETS "|$FuncName._xdata_epilog1|"
__FuncXDataEpilog2Label SETS "|$FuncName._xdata_epilog2|"
__FuncXDataEpilog3Label SETS "|$FuncName._xdata_epilog3|"
__FuncXDataEpilog4Label SETS "|$FuncName._xdata_epilog4|"
__FuncXDataEndLabel     SETS "|$FuncName._xdata_end|"

        MEND


        ;
        ; Helper macro: create a global label for the given name,
        ; decorate it, and export it for external consumption.
        ;

        MACRO
        __ExportName $FuncName

        LCLS    Name
Name    SETS    "|$FuncName|"
        ALIGN   4
        EXPORT  $Name
$Name
        MEND

        MACRO
        __ExportProc $FuncName

        LCLS    Name
Name    SETS    "|$FuncName|"
        ALIGN   4
        EXPORT  $Name
$Name   PROC
        MEND


        ;
        ; Declare that all following code/data is to be put in the .text segment
        ;

        MACRO
        TEXTAREA
#if defined(_CONTROL_FLOW_GUARD)
        AREA    |.text|,ALIGN=4,CODE,READONLY
#else
        AREA    |.text|,ALIGN=2,CODE,READONLY
#endif
        MEND


        ;
        ; Declare that all following code/data is to be put in the .data segment
        ;

        MACRO
        DATAAREA
        AREA    |.data|,DATA
        MEND


        ;
        ; Declare that all following code/data is to be put in the .rdata segment
        ;

        MACRO
        RODATAAREA
        AREA    |.rdata|,DATA,READONLY
        MEND


        ;
        ; Macro for indicating the start of a nested function. Nested functions
        ; imply a prolog, epilog, and unwind codes.
        ;

        MACRO
        NESTED_ENTRY $FuncName, $AreaName, $ExceptHandler

        ; compute the function's labels
        __DeriveFunctionLabels $FuncName

        ; determine the area we will put the function into
__FuncArea   SETS    "|.text|"
        IF "$AreaName" != ""
__FuncArea   SETS    "$AreaName"
        ENDIF

        ; set up the exception handler itself
__FuncExceptionHandler SETS ""
        IF "$ExceptHandler" != ""
__FuncExceptionHandler SETS    "|$ExceptHandler|"
        ENDIF

        ; switch to the specified area
        AREA    $__FuncArea,CODE,READONLY

        ; export the function name
        __ExportProc $FuncName

        ; flush any pending literal pool stuff
        ROUT

        ; reset the state of the unwind code tracking
        __ResetUnwindState

        MEND


        ;
        ; Macro for indicating the end of a nested function. We generate the
        ; .pdata and .xdata records here as necessary.
        ;

        MACRO
        NESTED_END $FuncName

        ; mark the end of the function
$__FuncEndLabel
        LTORG
        ENDP

        ; generate .pdata
        AREA    |.pdata|,ALIGN=2,READONLY
        DCD     $__FuncStartLabel
        RELOC   2                                       ; make this relative to image base

        DCD     $__FuncXDataLabel
        RELOC   2                                       ; make this relative to image base

        ; generate .xdata
        __EmitUnwindXData

        ; back to the original area
        AREA    $__FuncArea,CODE,READONLY

        ; reset the labels
__FuncStartLabel SETS    ""
__FuncEndLabel  SETS    ""

        MEND


        ;
        ; Macro for indicating the start of a leaf function.
        ;

        MACRO
        LEAF_ENTRY $FuncName, $AreaName

        NESTED_ENTRY $FuncName, $AreaName

        MEND


        ;
        ; Macro for indicating the end of a leaf function.
        ;

        MACRO
        LEAF_END $FuncName

        NESTED_END $FuncName

        MEND


        ;
        ; Macro for indicating the start of a leaf function.
        ;

        MACRO
        LEAF_ENTRY_NO_PDATA $FuncName, $AreaName

        ; compute the function's labels
        __DeriveFunctionLabels $FuncName

        ; determine the area we will put the function into
__FuncArea   SETS    "|.text|"
        IF "$AreaName" != ""
__FuncArea   SETS    "$AreaName"
        ENDIF

        ; switch to the specified area
        AREA    $__FuncArea,CODE,READONLY

        ; export the function name
        __ExportProc $FuncName

        ; flush any pending literal pool stuff
        ROUT

        MEND


        ;
        ; Macro for indicating the end of a leaf function.
        ;

        MACRO
        LEAF_END_NO_PDATA $FuncName

        ; mark the end of the function
$__FuncEndLabel
        LTORG
        ENDP

        ; reset the labels
__FuncStartLabel SETS    ""
__FuncEndLabel  SETS    ""

        MEND


        ;
        ; Macro for indicating an alternate entry point into a function.
        ;

        MACRO
        ALTERNATE_ENTRY $FuncName

        ; export the entry point's name
        __ExportName $FuncName

        ; flush any pending literal pool stuff
        ROUT

        MEND


#if defined(_CAPKERN)

        ;
        ; Icecap entrypoints
        ;

        IMPORT _CAP_Start_Profiling
        IMPORT _CAP_End_Profiling

        ;
        ; Macro to record a call record
        ;

        MACRO
        CAPSTART $arg1, $arg2

        push {r0,r1}
        ldr r0, =$arg1
        ldr r1, =$arg2
        bl _CAP_Start_Profiling
        pop {r0,r1}

        MEND


        ;
        ; Macro to record a return record
        ;

        MACRO
        CAPEND $arg1

        push {r0}
        sub sp, sp, #4
        ldr r0, =$arg1
        bl _CAP_End_Profiling
        add sp, sp, #4
        pop {r0}

        MEND

#else

        MACRO
        CAPSTART $arg1, $arg2
        MEND

        MACRO
        CAPEND $arg1
        MEND

#endif


        ;
        ; Macro to acquire a spin lock at address $Reg + $Offset. Clobbers {r0-r2}
        ;

        MACRO
        ACQUIRE_SPIN_LOCK $Reg, $Offset

        movs    r0, #1                                  ; we want to exchange with a 1
        dmb                                             ; memory barrier ahead of the loop
1
        ldrex   r1, [$Reg, $Offset]                     ; load the new value
        strex   r2, r0, [$Reg, $Offset]                 ; attempt to store the 1
        cmp     r2, #1                                  ; did we succeed before someone else did?
        beq     %B1                                     ; if not, try again
        cbz     r1, %F3                                 ; was the lock previously owned? if not, we're done
2
        yield                                           ; yield execution
        b       %B1                                     ; and try again
3
        dmb

        MEND


        ;
        ; Macro to release a spin lock at address $Reg + $Offset. If $ZeroReg is specified,
        ; that register is presumed to contain 0; otherwise, r0 is clobbered and used.
        ;

        MACRO
        RELEASE_SPIN_LOCK $Reg, $Offset, $ZeroReg

        dmb

        LCLS    Zero
Zero    SETS    "$ZeroReg"
        IF (Zero == "")
Zero    SETS    "r0"
        movs    r0, #0                                  ; need a 0 value to store
        ENDIF
        str     $Zero, [$Reg, $Offset]                  ; store it

        MEND


        ;
        ; Macro to increment a 64-bit statistic.
        ;

        MACRO
        INCREMENT_STAT $AddrReg, $Temp1, $Temp2, $Temp3

1       ldrexd  $Temp1, $Temp2, [$AddrReg]              ; load current  value
        adds    $Temp1, $Temp1, #1                      ; increment low word
        adc     $Temp2, $Temp2, #0                      ; carry into high word
        strexd  $Temp3, $Temp1, $Temp2, [$AddrReg]      ; attempt to store
        cmp     $Temp3, #0                              ; did it succeed?
        bne     %B1                                     ; if not, try again

        MEND


        ;
        ; Macro to restore the interrupt enable state to what it was in the SPSR
        ; held by the $SpsrReg parameter.
        ;

        MACRO
        RESTORE_INTERRUPT_STATE $SpsrReg

        tst     $SpsrReg, #CPSRC_INT                    ; were interrupts enabled previously?
        bne     %F1                                     ; if not, skip
        cpsie   i                                       ; enable interrupts
1
        MEND


        ;
        ; Macros to read/write coprocessor registers. These macros are preferred over
        ; raw mrc/mcr because they put the register parameter first and strip the
        ; prefixes which allow them to use the same C preprocessor macros as the C
        ; code.
        ;

        MACRO
        CP_READ $rd, $coproc, $op1, $crn, $crm, $op2
        mrc     p$coproc, $op1, $rd, c$crn, c$crm, $op2 ; just shuffle params and add prefixes
        MEND


        MACRO
        CP_WRITE $rd, $coproc, $op1, $crn, $crm, $op2
        mcr     p$coproc, $op1, $rd, c$crn, c$crm, $op2 ; just shuffle params and add prefixes
        MEND


        ;
        ; Macros to read/write the TEB register
        ;

        MACRO
        TEB_READ $Reg
        CP_READ $Reg, CP15_TPIDRURW                     ; read from user r/w coprocessor register
        MEND


        MACRO
        TEB_WRITE $Reg
        CP_WRITE $Reg, CP15_TPIDRURW                    ; write to user r/w coprocessor register
        MEND


        ;
        ; Macros to read/write the current thread register
        ;

        MACRO
        CURTHREAD_READ $Reg
        CP_READ $Reg, CP15_TPIDRURO                     ; read from user r/o coprocessor register
        bic     $Reg, #CP15_THREAD_RESERVED_MASK        ; clear reserved thread bits
        MEND

        ;
        ; Macro to read the PCR register
        ;

        MACRO
        PCR_READ $Reg
        CP_READ $Reg, CP15_TPIDRPRW                     ; read from svc r/w coprocessor register
        bfc     $Reg, #0, #12                           ; clear reserved PCR bits
        MEND

        ;
        ; Macros to read/write the current IRQL
        ;
        ; N.B. These macros do not do hardware and software IRQL processing.
        ;

        MACRO
        RAISE_IRQL $Reg, $NewIrql

#if DBG

        GET_IRQL $Reg                                   ; get old IRQL
        cmp      $Reg, $NewIrql                         ; check if old IRQL is lower or same
        bls      %F1                                    ; if LS, valid transition

        EMIT_BREAKPOINT                                 ; break
1
#endif

        CP_READ $Reg, CP15_TPIDRURO                     ; get IRQL and thread
        bfi     $Reg, $NewIrql, #0, #4                  ; set new IRQL
        CP_WRITE $Reg, CP15_TPIDRURO                    ; store new value
        MEND

        MACRO
        SET_THREAD_AND_IRQL $Reg, $Thread, $Irql
        orrs    $Reg, $Thread, $Irql                    ; set IRQL bits
        CP_WRITE $Reg, CP15_TPIDRURO                    ; store new thread and irql
        MEND

        MACRO
        GET_IRQL $Irql
        CP_READ $Irql, CP15_TPIDRURO                    ; get IRQL and thread
        ands    $Irql, #0xF                             ; isolate IRQL
        MEND

        MACRO
        GET_THREAD_AND_IRQL $ThreadReg, $IrqlReg
        CP_READ $IrqlReg, CP15_TPIDRURO                 ; get thread and irql
        bic     $ThreadReg, $IrqlReg, #CP15_THREAD_RESERVED_MASK ; isolate thread
        ands    $IrqlReg, #0xF                          ; isolate IRQL
        MEND

        MACRO
        CURTHREAD_READ_PASSIVE $ThreadReg
        CP_READ $ThreadReg, CP15_TPIDRURO               ; get thread and irql
#if DBG
        tst     $ThreadReg, #CP15_THREAD_RESERVED_MASK  ; validate irql bits
        beq     %F1                                     ; if eq, bits were 0

        EMIT_BREAKPOINT                                 ; IRQL was not passive
        bic     $ThreadReg, #CP15_THREAD_RESERVED_MASK  ; isolate thread
1
#endif
        MEND

        MACRO
        CURTHREAD_WRITE_PASSIVE $ThreadReg
        CP_WRITE $ThreadReg, CP15_TPIDRURO              ; write thread and PASSIVE IRQL
        MEND

        ;
        ; Macros to output special undefined opcodes that indicate breakpoints
        ; and debug services.
        ;

        MACRO
        EMIT_BREAKPOINT
        DCW     THUMB_BREAKPOINT                        ; undefined per ARM ARM
        MEND


        MACRO
        EMIT_DEBUG_SERVICE
        DCW     THUMB_DEBUG_SERVICE                     ; undefined per ARM ARM
        MEND

        ;
        ; Macro to emit a fastfail instruction.
        ;

        MACRO
        FASTFAIL $FastFailCode
        mov     r0, $FastFailCode
        DCW     THUMB_FASTFAIL                          ; undefined per ARM ARM
        MEND


        ;
        ; Macro to generate an exception frame; this is intended to
        ; be used within the prolog of a function.
        ;

        MACRO
        GENERATE_EXCEPTION_FRAME
        PROLOG_PUSH         {r4-r11, lr}                ; save non-volatile registers
        PROLOG_STACK_ALLOC  ExR4                        ; allocate remainder of exception frame
        MEND


        ;
        ; Define the instrumentation return macro.
        ;
        ;   This macro determines whether an instrumentation callback is
        ;   enabled for this threads's process.  If it is, then the return
        ;   address in the trap frame is replaced with the instrumentation
        ;   callback address, and r12 is used to indicate the actual return
        ;   address.
        ;
        ; Arguments:
        ;
        ;   None
        ;
        ; Implicit arguments:
        ;
        ;   r2 - Scratch register (must be sanitized)
        ;
        ;   r3 - Supplies the address of the trap frame (must be sanitized)
        ;
        ;   r12 - Current thread pointer (must be sanitized)
        ;
        ;   sp - Pointer to INT KARM_MINI_STACK
        ;

        MACRO
        SETUP_FOR_INSTRUMENTATION_RETURN

        ldr     r2, [r12, #ThDebugActive]               ; get debugging state
        tst     r2, #DEBUG_ACTIVE_INSTRUMENTED          ; is instrumentation active?
        beq     %F1                                     ; if not, skip
        ldr     r2, [r12, #ThApcState + AsProcess]      ; get current process
        ldr     r2, [r2, #PrInstrumentationCallback]    ; get callback address
        cbz     r2, %F1                                 ; if NULL, skip it
        ldr     r12, [r3, #TrPc]                        ; load original return PC
        str     r12, [r3, #TrR12]                       ; store in R12
        str     r2, [r3, #TrPc]                         ; update PC in trap frame (for debugger only)
        bic     r2, r2, #1                              ; clear the PC's low bit
        str     r2, [sp, #MsPc]                         ; store PC to INT ministack
        movs    r2, #0                                  ; sanitize remaining volatiles
        movs    r3, #0                                  ; sanitize remaining volatiles
        rfeia   sp                                      ; restore from exception
1
        MEND


        ;
        ; Macro to restore from an exception frame; this is intended to
        ; be used within the epilog of a function.
        ;

        MACRO
        RESTORE_EXCEPTION_FRAME
        EPILOG_STACK_FREE    ExR4                       ; adjust SP to point to non-volatile registers
        EPILOG_POP           {r4-r11, lr}               ; restore non-volatile registers
        MEND


        ;
        ; Macro to flush the current VFP state to a KARM_VFP_STATE structure
        ;

        MACRO
        SAVE_VFP_STATE $base, $temp

        vmrs    $temp, fpscr                            ; load floating point control/status
        str     $temp, [$base, #VsFpscr]                ; store it
        adds    $base, $base, #VsVfpD                   ; point to the registers themselves
        vstm    $base!, {d0-d15}                        ; save d0-d15
        vstm    $base, {d16-d31}                        ; save d16-d31
2
        MEND


        ;
        ; Macro to restore the current VFP state from a KARM_VFP_STATE structure
        ;

        MACRO
        RESTORE_VFP_STATE $base, $temp

        ldr     $temp, [$base, #VsFpscr]                ; load floating point control/status
        bic     $temp, $temp, #FPSCRM_DEPRECATED        ; clear deprecated bits
        vmsr    fpscr, $temp                            ; set it
        adds    $base, $base, #VsVfpD                   ; point to the registers themselves
        vldm    $base!, {d0-d15}                        ; load d0-d15
        vldm    $base, {d16-d31}                        ; load d16-d31
2
        MEND


        ;
        ; Macro to return the current cycle time in the target registers.
        ;

        MACRO
        READ_CYCLE_COUNTER_64BIT $lo, $hi, $scratch1, $scratch2, $prcb

        IF ("$prcb" == "")
        PCR_READ    $scratch1                           ; get PCR in scratch
        add         $scratch1, $scratch1, #PcCycleCounterHigh ; point to cycle counter address
        ELSE
        add         $scratch1, $prcb, #PbCycleCounterHigh ; point to cycle counter address
        ENDIF
0
        ldrexd      $scratch2, $hi, [$scratch1]         ; get last high/low value in hi:scratch
        CP_READ     $lo, CP15_PMCCNTR                   ; read cycle counter in lo
        teq         $scratch2, $lo                      ; EOR the new low with the previous
        bpl         %F1                                 ; if the same sign, nothing to do
        adds        $hi, $hi, $scratch2, lsr #31        ; clock into the high word if we wrapped
1
        strexd      $scratch2, $lo, $hi, [$scratch1]    ; store the updated hi/lo
        cmp         $scratch2, #0                       ; did it succeed?
        bne         %B0                                 ; if not, try again
        MEND

        ;
        ; Macro to update the cycle counter based upon the target registers.
        ;
        ; N.B. This is not an atomic operation and should only be used when
        ;      interrupts are disabled for processor initialization.
        ;

        MACRO
        WRITE_CYCLE_COUNTER_64BIT $lo, $hi, $scratch1

        PCR_READ    $scratch1                           ; get PCR in scratch
        add         $scratch1, $scratch1, #PcCycleCounterHigh ; point to cycle counter address
        str         $lo, [$scratch1]                    ; store lo in shadow
        str         $hi, [$scratch1, #4]                ; store hi
        CP_WRITE    $lo, CP15_PMCCNTR                   ; write lo to cycle counter
        MEND

        ;
        ; Macro to align a Control Flow Guard valid call target.
        ;

        MACRO
        CFG_ALIGN
#if defined(_CONTROL_FLOW_GUARD)
        ALIGN 16
#endif
        MEND

        ;
        ; Macro to read the CPSR.
        ;

        MACRO
        READ_CPSR $Reg
        mrs     $Reg, cpsr                               ; read CPSR
        orr     $Reg, $Reg, CPSRC_THUMB                  ; add the thumb bit
        MEND
