;++
;
; Copyright (c) Microsoft Corporation.  All rights reserved.
;
;
; Module:
;
;   kxarm64.w
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

#include "kxarm64unw.h"

        ;
        ; Global variables
        ;

        ; Current function names and labels
        GBLS    __FuncNameNoBars
        GBLS    __FuncStartLabel
        GBLS    __FuncEpilog1StartLabel
        GBLS    __FuncEpilog2StartLabel
        GBLS    __FuncEpilog3StartLabel
        GBLS    __FuncEpilog4StartLabel
        GBLS    __FuncPDataLabel
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
        GBLS    __SectAlign
        GBLS    __AlignStmt


        ;
        ; Helper macro: generate the various labels we will use internally
        ; for a function
        ;
        ; Output is placed in the various __Func*Label globals
        ;

        MACRO
        __DeriveFunctionLabels $FuncName

__FuncNameNoBars        SETS "$FuncName"
        IF ("$FuncName":LEFT:1 == "|") && ("$FuncName":RIGHT:1 == "|")
__FuncNameNoBars        SETS ("$FuncName":LEFT:(:LEN:"$FuncName" - 1):RIGHT:(:LEN:"$FuncName" - 2))
        ENDIF
__FuncStartLabel        SETS "|$__FuncNameNoBars|"
__FuncEndLabel          SETS "|$__FuncNameNoBars._end|"
__FuncEpilog1StartLabel SETS "|$__FuncNameNoBars._epilog1_start|"
__FuncEpilog2StartLabel SETS "|$__FuncNameNoBars._epilog2_start|"
__FuncEpilog3StartLabel SETS "|$__FuncNameNoBars._epilog3_start|"
__FuncEpilog4StartLabel SETS "|$__FuncNameNoBars._epilog4_start|"
__FuncPDataLabel        SETS "|$__FuncNameNoBars._pdata|"
__FuncXDataLabel        SETS "|$__FuncNameNoBars._xdata|"
__FuncXDataPrologLabel  SETS "|$__FuncNameNoBars._xdata_prolog|"
__FuncXDataEpilog1Label SETS "|$__FuncNameNoBars._xdata_epilog1|"
__FuncXDataEpilog2Label SETS "|$__FuncNameNoBars._xdata_epilog2|"
__FuncXDataEpilog3Label SETS "|$__FuncNameNoBars._xdata_epilog3|"
__FuncXDataEpilog4Label SETS "|$__FuncNameNoBars._xdata_epilog4|"
__FuncXDataEndLabel     SETS "|$__FuncNameNoBars._xdata_end|"

        MEND


        ;
        ; Helper macro: create a global label for the given name,
        ; decorate it, and export it for external consumption.
        ;

        MACRO
        __ExportName $FuncName

        LCLS    Name

        IF ("$FuncName":LEFT:1 == "|") && ("$FuncName":RIGHT:1 == "|")
Name    SETS    "$FuncName"
        ELSE
Name    SETS    "|$FuncName|"
        ENDIF

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
        ; N.B. The ALIGN attribute here specifies an exponent of base 2; not a
        ;      direct byte count. Thus ALIGN=4 specifies a 16 byte alignment.
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
        NESTED_ENTRY $FuncName, $AreaName, $ExceptHandler, $Alignment

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

__AlignStmt   SETS  ""
__SectAlign   SETS  ""

#ifdef _CHPE_X86_ARM64_

        ; For chpe targets, append a comdat name to the area name
__FuncArea   SETS   __FuncArea:CC:"{|$__FuncNameNoBars|}"
        ; Use the section alignment directive to achive alignment
__SectAlign  SETS  ",ALIGN=4"

        IF "$Alignment" != ""
        IF $Alignment > 4
__SectAlign   SETS   ",ALIGN=$Alignment"
        ENDIF
        ENDIF

#else

        ; for non-chpe targets, use a separate alignment directive
        IF "$Alignment" != ""
__AlignStmt  SETS "ALIGN 0x":CC: :STR:(1 << $Alignment)
        ENDIF

#endif

#ifdef _CHPE_X86_ARM64_

        AREA    $__FuncArea,CODE,READONLY$__SectAlign

#else

        ; switch to the specified area
        AREA    $__FuncArea,CODE,READONLY

#endif

        $__AlignStmt

        ; export the function name
        __ExportProc $__FuncNameNoBars

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

#if defined(_CHPE_X86_ARM64_)

        LCLS __FuncPDataArea

__FuncPDataArea  SETS "|.pdata|{$__FuncPDataLabel}"

        AREA    $__FuncPDataArea,ALIGN=2,READONLY,ASSOC=$__FuncArea

$__FuncPDataLabel

#else

        AREA    |.pdata|,ALIGN=2,READONLY

#endif

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
        LEAF_ENTRY $FuncName, $AreaName, $Alignment

        NESTED_ENTRY $FuncName, $AreaName, "", $Alignment

        MEND


        ;
        ; Macro for indicating the end of a leaf function.
        ;

        MACRO
        LEAF_END $FuncName

        NESTED_END $FuncName

        MEND


#if !defined(_CHPE_X86_ARM64_)

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
        __ExportProc $__FuncNameNoBars

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

#endif


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


        ;
        ; Macro for getting the address of a data item.
        ;
        
        MACRO
        ADDROF $Reg, $Variable
        
        adrp    $Reg, $Variable                 ; get the page address first
        add     $Reg, $Reg, $Variable           ; add in the low bits
        
        MEND


        ;
        ; Macro for loading a 32-bit constant.
        ;
        
        MACRO
        MOVL32 $Reg, $Variable
        
        IF ((($Variable):SHR:16):AND:0xffff) == 0
        movz    $Reg, #$Variable
        ELIF ((($Variable):SHR:0):AND:0xffff) == 0
        movz    $Reg, #((($Variable):SHR:16):AND:0xffff), lsl #16
        ELSE
        movz    $Reg, #(($Variable):AND:0xffff)
        movk    $Reg, #((($Variable):SHR:16):AND:0xffff), lsl #16
        ENDIF
        
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

        stp x0, x1, [sp, #-16]!

        ldr x0, =$arg1
        ldr x1, =$arg2
        bl _CAP_Start_Profiling

        ldp x0, x1, [sp], #16

        MEND


        ;
        ; Macro to record a return record
        ;

        MACRO
        CAPEND $arg1

        sub sp, sp, #16
        str x0, [sp, #0]

        ldr x0, =$arg1
        bl _CAP_End_Profiling

        ldr x0, [sp, #0]
        add sp, sp, #16

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
        ; Macro to align a Control Flow Guard valid call target.
        ;

        MACRO
        CFG_ALIGN
#if defined(_CONTROL_FLOW_GUARD)
        ALIGN 16
#endif
        MEND


        ;
        ; Macro to perform a Control Flow Guard check on a live call target.
        ;
        ; $TargetReg - Target address register
        ; x16 - Bitmap address
        ; $FailLabel - Label to jump to in the event of a failure
        ; 
        ; N.B. x16-x17 are free, other registers should be treated as live.
        ;
        ; N.B. This macro expects the $FailLabel to be right after this macro.
        ;

        MACRO
        CFG_ICALL_CHECK_BITMAP $TargetReg, $ValidTarget, $FailLabel

        LCLS    ValidLabel

ValidLabel SETS ""

        IF ("$ValidTarget":LEFT:1 != "x" && "$ValidTarget":LEFT:1 != "w" && "$ValidTarget" != "lr")

ValidLabel SETS "$ValidTarget"

        ENDIF

;
; Bitmap is an array of 2-bit values. Each 2-bit value represents 16 bytes, with the low
; bit set if jumps are permitted, and the upper bit set if misaligned jumps are permitted.
;
; The bit index is (address >> 4).
; Each byte holds 4 entries, so the byte index is (address >> 6).
; The shift amount is computed as 2*((address >> 4) & 3), or (address >> 3) & 6
; If address is aligned, (address >> 3) & 7 is equivalent, and ubfx can be used to extract.
;

        lsr     x17, $TargetReg, #6             ; compute bitmap byte index
        tst     $TargetReg, #15                 ; misaligned address?
        ldrb    w17, [x16, x17]                 ; load byte from bitmap
        ubfx    x16, $TargetReg, #3, #3         ; compute bit index*2
        bne     %F2                             ; if misaligned, account for extra bits
        lsr     x17, x17, x16                   ; shift bitmap chunk over to valid align bit
        tbz     x17, #0, %F3                    ; if low bit not set, verify the upper bit to
                                                ; allow an export suppressed target
1 ; Valid

;
; "ret lr" and "br lr" have different encodings and use of "ret lr" is
; preferred to hint that it is returning to the caller.
;

        IF "$ValidLabel" != ""
            b       $ValidLabel                 ; jump to valid target
        ELIF "$ValidTarget" != "lr"
            br      $ValidTarget                ; jump to valid target
        ELSE
            ret     lr                          ; return
        ENDIF

2 ; Misaligned
        ;
        ; Code on ARM64 should always be 16 byte aligned if address taken.
        ;
        ; TODO:  Compress bitmap format to 1 bit per address on ARM64?
        ; TODO:  We are seeing 8-byte aligned code now. (1/22/14)
        ;
        and     x16, x16, #0xfffffffffffffffe   ; force low bit of shift to 0
        lsr     x17, x17, x16                   ; shift bitmap chunk down
        tbz     x17, #0, $FailLabel             ; invalid if the low bit was clear
3 ; FailOpen
        tbnz    x17, #1, %B1                    ; valid if upper bit was set as well

        MEND


        ;
        ; Macro to perform a Control Flow Guard check on a live call target with export suppression.
        ;
        ; $TargetReg - Target address register
        ; x16 - Bitmap address
        ; $FailLabel - Label to jump to in the event of a failure
        ; 
        ; N.B. x16-x17 are free, other registers should be treated as live.
        ;
        ; N.B. This macro expects the $FailLabel to be right after this macro.
        ;

        MACRO
        CFG_ICALL_CHECK_BITMAP_ES $TargetReg, $ValidTarget, $FailLabel

        LCLS    ValidLabel

ValidLabel SETS ""

        IF ("$ValidTarget":LEFT:1 != "x" && "$ValidTarget":LEFT:1 != "w" && "$ValidTarget" != "lr")

ValidLabel SETS "$ValidTarget"

        ENDIF

;
; Bitmap is an array of 2-bit values. Each 2-bit value represents 16 bytes, with the low
; bit set if jumps are permitted, and the upper bit set if misaligned jumps are permitted.
;
; The bit index is (address >> 4).
; Each byte holds 4 entries, so the byte index is (address >> 6).
; The shift amount is computed as 2*((address >> 4) & 3), or (address >> 3) & 6
; If address is aligned, (address >> 3) & 7 is equivalent, and ubfx can be used to extract.
;

        lsr     x17, $TargetReg, #6             ; compute bitmap byte index
        tst     $TargetReg, #15                 ; misaligned address?
        ldrb    w17, [x16, x17]                 ; load byte from bitmap
        ubfx    x16, $TargetReg, #3, #3         ; compute bit index*2
        bne     %F2                             ; if misaligned, account for extra bits
        lsr     x17, x17, x16                   ; shift bitmap chunk over to valid align bit
        tbz     x17, #0, $FailLabel             ; if low bit not set, either invalid or export
                                                ; suppressed target
1 ; Valid

;
; "ret lr" and "br lr" have different encodings and use of "ret lr" is
; preferred to hint that it is returning to the caller.
;

        IF "$ValidLabel" != ""
            b       $ValidLabel                 ; jump to valid target
        ELIF "$ValidTarget" != "lr"
            br      $ValidTarget                ; jump to valid target
        ELSE
            ret     lr                          ; return
        ENDIF

2 ; Misaligned
        ;
        ; Code on ARM64 should always be 16 byte aligned if address taken.
        ;
        ; TODO:  Compress bitmap format to 1 bit per address on ARM64?
        ; TODO:  We are seeing 8-byte aligned code now. (1/22/14)
        ;
        and     x16, x16, #0xfffffffffffffffe   ; force low bit of shift to 0
        lsr     x17, x17, x16                   ; shift bitmap chunk down
        tbz     x17, #0, $FailLabel             ; invalid if the low bit was clear
        tbnz    x17, #1, %B1                    ; valid if upper bit was set as well
        MEND


        ;
        ; Macro to acquire a spin lock at address $Reg + $Offset. Clobbers {r0-r2}
        ;

; ARM64_WORKITEM : should we use acquire/release semantics instead of DMB?

        MACRO
        ACQUIRE_SPIN_LOCK $Reg, $Offset

        mov     x0, #1                                  ; we want to exchange with a 1
        dmb                                             ; memory barrier ahead of the loop
1
        ldxr    x1, [$Reg, $Offset]                     ; load the new value
        stxr    x2, x0, [$Reg, $Offset]                 ; attempt to store the 1
        cbnz    x2, %B1                                 ; did we succeed before someone else did?
        cbz     x1, %F3                                 ; was the lock previously owned? if not, we're done
        yield                                           ; yield execution
        b       %B1                                     ; and try again
3
        dmb

        MEND


        ;
        ; Macro to release a spin lock at address $Reg + $Offset.
        ;

; ARM64_WORKITEM : should we use acquire/release semantics instead of DMB?

        MACRO
        RELEASE_SPIN_LOCK $Reg, $Offset

        dmb
        str     xzr, [$Reg, $Offset]                    ; store 0

        MEND


        ;
        ; Macro to increment a 64-bit statistic.
        ;

        MACRO
        INCREMENT_STAT $AddrReg, $Temp1, $Temp2

1       ldxr    $Temp1, [$AddrReg]                      ; load current value
        add     $Temp1, $Temp1, #1                      ; increment
        stxr    $Temp2, $Temp1, [$AddrReg]              ; attempt to store
        cbnz    $Temp2, %B1                             ; loop until it works?

        MEND


        ;
        ; Macros to enable/disable interrupts.
        ;
        
        MACRO
        ENABLE_INTERRUPTS
        msr     DAIFClr, #2                             ; enable interrupts
        MEND

        MACRO
        DISABLE_INTERRUPTS
        msr     DAIFSet, #2                             ; disable interrupts
        MEND


        ;
        ; Macros to read/write the current IRQL
        ;
        ; N.B. These macros do not do hardware and software IRQL processing.
        ;

        MACRO
        GET_IRQL $Irql
        ldrb    $Irql, [x18, #PcCurrentIrql]            ; read IRQL
        MEND

        MACRO
        RAISE_IRQL $Reg, $NewIrql

#if DBG

        GET_IRQL $Reg                                   ; get old IRQL
        cmp      $Reg, #$NewIrql                        ; check if old IRQL is lower or same
        bls      %F1                                    ; if LS, valid transition

        EMIT_BREAKPOINT                                 ; break
1
#endif

        mov     $Reg, #$NewIrql                         ; get new IRQL
        strb    $Reg, [x18, #PcCurrentIrql]             ; update IRQL
        MEND


        ;
        ; Macros to output special undefined opcodes that indicate breakpoints
        ; and debug services.
        ;

        MACRO
        EMIT_BREAKPOINT
        brk     #ARM64_BREAKPOINT
        MEND


        MACRO
        EMIT_DEBUG_SERVICE
        brk     #ARM64_DEBUG_SERVICE
        MEND

        MACRO
        FASTFAIL $FastFailCode
        mov     x0, $FastFailCode
        brk     #ARM64_FASTFAIL
        MEND


        ;
        ; Macro to generate an exception frame; this is intended to
        ; be used within the prolog of a function.
        ;

        MACRO
        GENERATE_EXCEPTION_FRAME
        PROLOG_SAVE_REG_PAIR x19, x20, #-96!
        PROLOG_SAVE_REG_PAIR x21, x22, #16
        PROLOG_SAVE_REG_PAIR x23, x24, #32
        PROLOG_SAVE_REG_PAIR x25, x26, #48
        PROLOG_SAVE_REG_PAIR x27, x28, #64
        PROLOG_SAVE_REG_PAIR fp, lr, #80
        MEND


        ;
        ; Macro to restore from an exception frame; this is intended to
        ; be used within the epilog of a function.
        ;

        MACRO
        RESTORE_EXCEPTION_STATE
        EPILOG_RESTORE_REG_PAIR fp, lr, #80
        EPILOG_RESTORE_REG_PAIR x27, x28, #64
        EPILOG_RESTORE_REG_PAIR x25, x26, #48
        EPILOG_RESTORE_REG_PAIR x23, x24, #32
        EPILOG_RESTORE_REG_PAIR x21, x22, #16
        EPILOG_RESTORE_REG_PAIR x19, x20, #96!
        MEND
