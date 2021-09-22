//+--------------------------------------------------------------------------
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  Abstract:
//     DirectX Typography Services public API definitions.
//
//----------------------------------------------------------------------------

#ifndef DWRITE_3_H_INCLUDED
#define DWRITE_3_H_INCLUDED

#pragma once

#include <DWrite_2.h>

interface IDWriteFontFaceReference;
interface IDWriteFont3;
interface IDWriteFontFace3;
interface IDWriteFontSet;
interface IDWriteFontSetBuilder;
interface IDWriteFontCollection1;
interface IDWriteFontFamily1;
interface IDWriteStringList;
interface IDWriteFontDownloadQueue;


/// <summary>
/// A font resource could not be accessed because it was remote. This can happen
/// when calling CreateFontFace on a non-local font or trying to measure/draw
/// glyphs that are not downloaded yet.
/// </summary>
#ifndef DWRITE_E_REMOTEFONT
#define DWRITE_E_REMOTEFONT    _HRESULT_TYPEDEF_(0x8898500DL)
#endif

/// <summary>
/// The download was canceled, which happens if the application calls
/// IDWriteFontDownloadQueue::CancelDownload before they finish.
/// </summary>
#ifndef DWRITE_E_DOWNLOADCANCELLED
#define DWRITE_E_DOWNLOADCANCELLED  _HRESULT_TYPEDEF_(0x8898500EL)
#endif

/// <summary>
/// The download failed to complete because the remote resource is missing
/// or the network is down.
/// </summary>
#ifndef DWRITE_E_DOWNLOADFAILED
#define DWRITE_E_DOWNLOADFAILED  _HRESULT_TYPEDEF_(0x8898500FL)
#endif

/// <summary>
/// A download request was not added or a download failed because there
/// are too many active downloads.
/// </summary>
#ifndef DWRITE_E_TOOMANYDOWNLOADS
#define DWRITE_E_TOOMANYDOWNLOADS  _HRESULT_TYPEDEF_(0x88985010L)
#endif

/// <summary>
/// The font property enumeration identifies a string in a font.
/// </summary>
enum DWRITE_FONT_PROPERTY_ID
{
    /// <summary>
    /// Unspecified font property identifier.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_NONE,

    /// <summary>
    /// Family name for the weight-stretch-style model.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME,

    /// <summary>
    /// Family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with
    /// GDI. This name is typically only present if it differs from the GDI-compatible family name.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME,

    /// <summary>
    /// Face name of the for the weight-stretch-style (e.g., Regular or Bold).
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FACE_NAME,

    /// <summary>
    /// The full name of the font, e.g. "Arial Bold", from name id 4 in the name table.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_FULL_NAME,

    /// <summary>
    /// GDI-compatible family name. Because GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names
    /// (e.g., "Arial", "Arial Narrow", "Arial Black").
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_WIN32_FAMILY_NAME,

    /// <summary>
    /// The postscript name of the font, e.g. "GillSans-Bold" from name id 6 in the name table.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_POSTSCRIPT_NAME,

    /// <summary>
    /// Script/language tag to identify the scripts or languages that the font was
    /// primarily designed to support.
    /// </summary>
    /// <remarks>
    /// The design script/language tag is meant to be understood from the perspective of
    /// users. For example, a font is considered designed for English if it is considered
    /// useful for English users. Note that this is different from what a font might be
    /// capable of supporting. For example, the Meiryo font was primarily designed for
    /// Japanese users. While it is capable of displaying English well, it was not
    /// meant to be offered for the benefit of non-Japanese-speaking English users.
    ///
    /// As another example, a font designed for Chinese may be capable of displaying
    /// Japanese text, but would likely look incorrect to Japanese users.
    /// 
    /// The valid values for this property are "ScriptLangTag" values. These are adapted
    /// from the IETF BCP 47 specification, "Tags for Identifying Languages" (see
    /// http://tools.ietf.org/html/bcp47). In a BCP 47 language tag, a language subtag
    /// element is mandatory and other subtags are optional. In a ScriptLangTag, a
    /// script subtag is mandatory and other subtags are option. The following
    /// augmented BNF syntax, adapted from BCP 47, is used:
    /// 
    ///     ScriptLangTag = [language "-"]
    ///                     script
    ///                     ["-" region]
    ///                     *("-" variant)
    ///                     *("-" extension)
    ///                     ["-" privateuse]
    /// 
    /// The expansion of the elements and the intended semantics associated with each
    /// are as defined in BCP 47. Script subtags are taken from ISO 15924. At present,
    /// no extensions are defined, and any extension should be ignored. Private use
    /// subtags are defined by private agreement between the source and recipient and
    /// may be ignored.
    /// 
    /// Subtags must be valid for use in BCP 47 and contained in the Language Subtag
    /// Registry maintained by IANA. (See
    /// http://www.iana.org/assignments/language-subtag-registry/language-subtag-registry
    /// and section 3 of BCP 47 for details.
    /// 
    /// Any ScriptLangTag value not conforming to these specifications is ignored.
    /// 
    /// Examples:
    ///   "Latn" denotes Latin script (and any language or writing system using Latin)
    ///   "Cyrl" denotes Cyrillic script
    ///   "sr-Cyrl" denotes Cyrillic script as used for writing the Serbian language;
    ///       a font that has this property value may not be suitable for displaying
    ///       text in Russian or other languages written using Cyrillic script
    ///   "Jpan" denotes Japanese writing (Han + Hiragana + Katakana)
    ///
    /// When passing this property to GetPropertyValues, use the overload which does
    /// not take a language parameter, since this property has no specific language.
    /// </remarks>
    DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG,

    /// <summary>
    /// Script/language tag to identify the scripts or languages that the font declares
    /// it is able to support.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_SUPPORTED_SCRIPT_LANGUAGE_TAG,

    /// <summary>
    /// Semantic tag to describe the font (e.g. Fancy, Decorative, Handmade, Sans-serif, Swiss, Pixel, Futuristic).
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_SEMANTIC_TAG,

    /// <summary>
    /// Weight of the font represented as a decimal string in the range 1-999.
    /// </summary>
    /// <remark>
    /// This enum is discouraged for use with IDWriteFontSetBuilder2 in favor of the more generic font axis
    /// DWRITE_FONT_AXIS_TAG_WEIGHT which supports higher precision and range.
    /// </remark>
    DWRITE_FONT_PROPERTY_ID_WEIGHT,

    /// <summary>
    /// Stretch of the font represented as a decimal string in the range 1-9.
    /// </summary>
    /// <remark>
    /// This enum is discouraged for use with IDWriteFontSetBuilder2 in favor of the more generic font axis
    /// DWRITE_FONT_AXIS_TAG_WIDTH which supports higher precision and range.
    /// </remark>
    DWRITE_FONT_PROPERTY_ID_STRETCH,

    /// <summary>
    /// Style of the font represented as a decimal string in the range 0-2.
    /// </summary>
    /// <remark>
    /// This enum is discouraged for use with IDWriteFontSetBuilder2 in favor of the more generic font axes
    /// DWRITE_FONT_AXIS_TAG_SLANT and DWRITE_FONT_AXIS_TAG_ITAL.
    /// </remark>
    DWRITE_FONT_PROPERTY_ID_STYLE,

    /// <summary>
    /// Face name preferred by the designer. This enables font designers to group more than four fonts in a single
    /// family without losing compatibility with GDI.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FACE_NAME,

    /// <summary>
    /// Total number of properties for NTDDI_WIN10 (IDWriteFontSet).
    /// </summary>
    /// <remarks>
    /// DWRITE_FONT_PROPERTY_ID_TOTAL cannot be used as a property ID.
    /// </remarks>
    DWRITE_FONT_PROPERTY_ID_TOTAL = DWRITE_FONT_PROPERTY_ID_STYLE + 1,

    /// <summary>
    /// Total number of properties for NTDDI_WIN10_RS3 (IDWriteFontSet1).
    /// </summary>
    DWRITE_FONT_PROPERTY_ID_TOTAL_RS3 = DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FACE_NAME + 1,

    // Obsolete aliases kept to avoid breaking existing code.
    DWRITE_FONT_PROPERTY_ID_PREFERRED_FAMILY_NAME = DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME,
    DWRITE_FONT_PROPERTY_ID_FAMILY_NAME = DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME,
    DWRITE_FONT_PROPERTY_ID_FACE_NAME = DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FACE_NAME,
};


/// <summary>
/// Font property used for filtering font sets and
/// building a font set with explicit properties.
/// </summary>
struct DWRITE_FONT_PROPERTY
{
    /// <summary>
    /// Specifies the requested font property, such as DWRITE_FONT_PROPERTY_ID_FAMILY_NAME.
    /// </summary>
    DWRITE_FONT_PROPERTY_ID propertyId;

    /// <summary>
    /// Specifies the property value, such as "Segoe UI".
    /// </summary>
    _Field_z_ WCHAR const* propertyValue;

    /// <summary>
    /// Specifies the language / locale to use, such as "en-US". 
    /// </summary>
    /// <remarks>
    /// When passing property information to AddFontFaceReference, localeName indicates
    /// the language of the property value. BCP 47 language tags should be used. If a
    /// property value is inherently non-linguistic, this can be left empty.
    ///
    /// When used for font set filtering, leave this empty: a match will be found
    /// regardless of language associated with property values.
    /// </remarks>
    _Field_z_ _Maybenull_ WCHAR const* localeName;
};


/// <summary>
/// Specifies the locality of a resource.
/// </summary>
enum DWRITE_LOCALITY
{
    /// <summary>
    /// The resource is remote, and information is unknown yet, including the file size and date.
    /// Attempting to create a font or file stream will fail until locality becomes at least partial.
    /// </summary>
    DWRITE_LOCALITY_REMOTE,

    /// <summary>
    /// The resource is partially local, meaning you can query the size and date of the file
    /// stream, and you may be able to create a font face and retrieve the particular glyphs
    /// for metrics and drawing, but not all the glyphs will be present.
    /// </summary>
    DWRITE_LOCALITY_PARTIAL,

    /// <summary>
    /// The resource is completely local, and all font functions can be called
    /// without concern of missing data or errors related to network connectivity.
    /// </summary>
    DWRITE_LOCALITY_LOCAL,
};


/// <summary>
/// Represents a method of rendering glyphs.
/// </summary>
enum DWRITE_RENDERING_MODE1
{
    /// <summary>
    /// Specifies that the rendering mode is determined automatically based on the font and size.
    /// </summary>
    DWRITE_RENDERING_MODE1_DEFAULT = DWRITE_RENDERING_MODE_DEFAULT,

    /// <summary>
    /// Specifies that no antialiasing is performed. Each pixel is either set to the foreground 
    /// color of the text or retains the color of the background.
    /// </summary>
    DWRITE_RENDERING_MODE1_ALIASED = DWRITE_RENDERING_MODE_ALIASED,

    /// <summary>
    /// Specifies that antialiasing is performed in the horizontal direction and the appearance
    /// of glyphs is layout-compatible with GDI using CLEARTYPE_QUALITY. Use DWRITE_MEASURING_MODE_GDI_CLASSIC 
    /// to get glyph advances. The antialiasing may be either ClearType or grayscale depending on
    /// the text antialiasing mode.
    /// </summary>
    DWRITE_RENDERING_MODE1_GDI_CLASSIC = DWRITE_RENDERING_MODE_GDI_CLASSIC,

    /// <summary>
    /// Specifies that antialiasing is performed in the horizontal direction and the appearance
    /// of glyphs is layout-compatible with GDI using CLEARTYPE_NATURAL_QUALITY. Glyph advances
    /// are close to the font design advances, but are still rounded to whole pixels. Use
    /// DWRITE_MEASURING_MODE_GDI_NATURAL to get glyph advances. The antialiasing may be either
    /// ClearType or grayscale depending on the text antialiasing mode.
    /// </summary>
    DWRITE_RENDERING_MODE1_GDI_NATURAL = DWRITE_RENDERING_MODE_GDI_NATURAL,

    /// <summary>
    /// Specifies that antialiasing is performed in the horizontal direction. This rendering
    /// mode allows glyphs to be positioned with subpixel precision and is therefore suitable
    /// for natural (i.e., resolution-independent) layout. The antialiasing may be either
    /// ClearType or grayscale depending on the text antialiasing mode.
    /// </summary>
    DWRITE_RENDERING_MODE1_NATURAL = DWRITE_RENDERING_MODE_NATURAL,

    /// <summary>
    /// Similar to natural mode except that antialiasing is performed in both the horizontal
    /// and vertical directions. This is typically used at larger sizes to make curves and
    /// diagonal lines look smoother. The antialiasing may be either ClearType or grayscale
    /// depending on the text antialiasing mode.
    /// </summary>
    DWRITE_RENDERING_MODE1_NATURAL_SYMMETRIC = DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC,

    /// <summary>
    /// Specifies that rendering should bypass the rasterizer and use the outlines directly. 
    /// This is typically used at very large sizes.
    /// </summary>
    DWRITE_RENDERING_MODE1_OUTLINE = DWRITE_RENDERING_MODE_OUTLINE,

    /// <summary>
    /// Similar to natural symmetric mode except that when possible, text should be rasterized
    /// in a downsampled form.
    /// </summary>
    DWRITE_RENDERING_MODE1_NATURAL_SYMMETRIC_DOWNSAMPLED,
};


/// <summary>
/// The interface that represents text rendering settings for glyph rasterization and filtering.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("B7924BAA-391B-412A-8C5C-E44CC2D867DC") IDWriteRenderingParams3 : public IDWriteRenderingParams2
{
    /// <summary>
    /// Gets the rendering mode.
    /// </summary>
    STDMETHOD_(DWRITE_RENDERING_MODE1, GetRenderingMode1)() PURE;
};


/// <summary>
/// The root factory interface for all DWrite objects.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("9A1B41C3-D3BB-466A-87FC-FE67556A3B65") IDWriteFactory3 : public IDWriteFactory2
{
    /// <summary>
    /// Creates a glyph run analysis object, which encapsulates information
    /// used to render a glyph run.
    /// </summary>
    /// <param name="glyphRun">Structure specifying the properties of the glyph run.</param>
    /// <param name="transform">Optional transform applied to the glyphs and their positions. This transform is applied after the
    /// scaling specified by the emSize.</param>
    /// <param name="renderingMode">Specifies the rendering mode, which must be one of the raster rendering modes (i.e., not default
    /// and not outline).</param>
    /// <param name="measuringMode">Specifies the method to measure glyphs.</param>
    /// <param name="gridFitMode">How to grid-fit glyph outlines. This must be non-default.</param>
    /// <param name="baselineOriginX">Horizontal position of the baseline origin, in DIPs.</param>
    /// <param name="baselineOriginY">Vertical position of the baseline origin, in DIPs.</param>
    /// <param name="glyphRunAnalysis">Receives a pointer to the newly created object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateGlyphRunAnalysis)(
        _In_ DWRITE_GLYPH_RUN const* glyphRun,
        _In_opt_ DWRITE_MATRIX const* transform,
        DWRITE_RENDERING_MODE1 renderingMode,
        DWRITE_MEASURING_MODE measuringMode,
        DWRITE_GRID_FIT_MODE gridFitMode,
        DWRITE_TEXT_ANTIALIAS_MODE antialiasMode,
        FLOAT baselineOriginX,
        FLOAT baselineOriginY,
        _COM_Outptr_ IDWriteGlyphRunAnalysis** glyphRunAnalysis
        ) PURE;

    using IDWriteFactory::CreateGlyphRunAnalysis;
    using IDWriteFactory2::CreateGlyphRunAnalysis;

    /// <summary>
    /// Creates a rendering parameters object with the specified properties.
    /// </summary>
    /// <param name="gamma">The gamma value used for gamma correction, which must be greater than zero and cannot exceed 256.</param>
    /// <param name="enhancedContrast">The amount of contrast enhancement, zero or greater.</param>
    /// <param name="grayscaleEnhancedContrast">The amount of contrast enhancement to use for grayscale antialiasing, zero or greater.</param>
    /// <param name="clearTypeLevel">The degree of ClearType level, from 0.0f (no ClearType) to 1.0f (full ClearType).</param>
    /// <param name="pixelGeometry">The geometry of a device pixel.</param>
    /// <param name="renderingMode">Method of rendering glyphs. In most cases, this should be DWRITE_RENDERING_MODE_DEFAULT to automatically use an appropriate mode.</param>
    /// <param name="gridFitMode">How to grid fit glyph outlines. In most cases, this should be DWRITE_GRID_FIT_DEFAULT to automatically choose an appropriate mode.</param>
    /// <param name="renderingParams">Receives a pointer to the newly created rendering parameters object, or NULL in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateCustomRenderingParams)(
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT grayscaleEnhancedContrast,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE1 renderingMode,
        DWRITE_GRID_FIT_MODE gridFitMode,
        _COM_Outptr_ IDWriteRenderingParams3** renderingParams
        ) PURE;

    using IDWriteFactory::CreateCustomRenderingParams;
    using IDWriteFactory1::CreateCustomRenderingParams;
    using IDWriteFactory2::CreateCustomRenderingParams;

    /// <summary>
    /// Creates a reference to a font given a full path.
    /// </summary>
    /// <param name="filePath">Absolute file path. Subsequent operations on the constructed object may fail
    ///     if the user provided filePath doesn't correspond to a valid file on the disk.</param>
    /// <param name="lastWriteTime">Last modified time of the input file path. If the parameter is omitted,
    ///     the function will access the font file to obtain its last write time, so the clients are encouraged to specify this value
    ///     to avoid extra disk access. Subsequent operations on the constructed object may fail
    ///     if the user provided lastWriteTime doesn't match the file on the disk.</param>
    /// <param name="faceIndex">The zero based index of a font face in cases when the font files contain a collection of font faces.
    ///     If the font files contain a single face, this value should be zero.</param>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontFaceReference)(
        _In_z_ WCHAR const* filePath,
        _In_opt_ FILETIME const* lastWriteTime,
        UINT32 faceIndex,
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;

    /// <summary>
    /// Creates a reference to a font given a file.
    /// </summary>
    /// <param name="fontFile">User provided font file representing the font face.</param>
    /// <param name="faceIndex">The zero based index of a font face in cases when the font files contain a collection of font faces.
    ///     If the font files contain a single face, this value should be zero.</param>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontFaceReference)(
        _In_ IDWriteFontFile* fontFile,
        UINT32 faceIndex,
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;

    /// <summary>
    /// Retrieves the list of system fonts.
    /// </summary>
    /// <param name="fontSet">Receives a pointer to the font set object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontSet)(
        _COM_Outptr_ IDWriteFontSet** fontSet
        ) PURE;

    /// <summary>
    /// Creates an empty font set builder to add font face references
    /// and create a custom font set.
    /// </summary>
    /// <param name="fontSetBuilder">Receives a pointer to the newly created font set builder object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontSetBuilder)(
        _COM_Outptr_ IDWriteFontSetBuilder** fontSetBuilder
        ) PURE;

    /// <summary>
    /// Create a weight-stretch-style based collection of families (DWRITE_FONT_FAMILY_MODEL_WEIGHT_STRETCH_STYLE)
    /// from a set of fonts.
    /// </summary>
    /// <param name="fontSet">A set of fonts to use to build the collection.</param>
    /// <param name="fontCollection">Receives a pointer to the newly created font collection object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontCollectionFromFontSet)(
        IDWriteFontSet* fontSet,
        _COM_Outptr_ IDWriteFontCollection1** fontCollection
        ) PURE;

    /// <summary>
    /// Retrieves a weight-stretch-style based collection of font families.
    /// </summary>
    /// <param name="includeDownloadableFonts">Include downloadable fonts or only locally installed ones.</param>
    /// <param name="fontCollection">Receives a pointer to the newly created font collection object, or nullptr in
    ///     case of failure.</param>
    /// <param name="checkForUpdates">If this parameter is nonzero, the function performs an immediate check for changes 
    ///     to the set of system fonts. If this parameter is FALSE, the function will still detect changes if the font
    ///     cache service is running, but there may be some latency. For example, an application might specify TRUE if
    ///     it has itself just installed a font and wants to be sure the font collection contains that font.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontCollection)(
        BOOL includeDownloadableFonts,
        _COM_Outptr_ IDWriteFontCollection1** fontCollection,
        BOOL checkForUpdates = FALSE
        ) PURE;

    using IDWriteFactory::GetSystemFontCollection;

    /// <summary>
    /// Gets the font download queue associated with this factory object.
    /// </summary>
    /// <param name="IDWriteFontDownloadQueue">Receives a pointer to the font download queue interface.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontDownloadQueue)(
        _COM_Outptr_ IDWriteFontDownloadQueue** fontDownloadQueue
        ) PURE;
};


/// <summary>
/// Set of fonts used for creating font faces, selecting nearest matching fonts, and filtering.
/// Unlike IDWriteFontFamily and IDWriteFontList, which are part of the IDWriteFontCollection heirarchy, font sets
/// are unordered flat lists.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("53585141-D9F8-4095-8321-D73CF6BD116B") IDWriteFontSet : public IUnknown
{
    /// <summary>
    /// Get the number of total fonts in the set.
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD_(UINT32, GetFontCount)() PURE;

    /// <summary>
    /// Get a reference to the font at this index, which may be local or remote.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font.</param>
    /// <param name="fontFaceReference">Receives a pointer the font face reference object, or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;

    /// <summary>
    /// Gets the index of the matching font face reference in the font set, with the same file, face index, and simulations.
    /// </summary>
    /// <param name="fontFaceReference">Font face reference object that specifies the physical font.</param>
    /// <param name="listIndex">Receives the zero-based index of the matching font if the font was found, or UINT_MAX otherwise.</param>
    /// <param name="exists">Receives TRUE if the font exists or FALSE otherwise.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(FindFontFaceReference)(
        IDWriteFontFaceReference* fontFaceReference,
        _Out_ UINT32* listIndex,
        _Out_ BOOL* exists
        ) PURE;

    /// <summary>
    /// Gets the index of the matching font face reference in the font set, with the same file, face index, and simulations.
    /// </summary>
    /// <param name="fontFaceReference">Font face object that specifies the physical font.</param>
    /// <param name="listIndex">Receives the zero-based index of the matching font if the font was found, or UINT_MAX otherwise.</param>
    /// <param name="exists">Receives TRUE if the font exists or FALSE otherwise.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(FindFontFace)(
        IDWriteFontFace* fontFace,
        _Out_ UINT32* listIndex,
        _Out_ BOOL* exists
        ) PURE;

    /// <summary>
    /// Returns the property values of a specific font item index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font.</param>
    /// <param name="propertyID">Font property of interest.</param>
    /// <param name="exists">Receives the value TRUE if the font contains the specified property identifier or FALSE if not.</param>
    /// <param name="strings">Receives a pointer to the newly created localized strings object, or nullptr on failure or non-existent property.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetPropertyValues)(
        UINT32 listIndex,
        DWRITE_FONT_PROPERTY_ID propertyId,
        _Out_ BOOL* exists,
        _COM_Outptr_result_maybenull_ IDWriteLocalizedStrings** values
        ) PURE;

    /// <summary>
    /// Returns all unique property values in the set, which can be used
    /// for purposes such as displaying a family list or tag cloud. Values are
    /// returned in priority order according to the language list, such that if
    /// a font contains more than one localized name, the preferred one will be
    /// returned.
    /// </summary>
    /// <param name="propertyID">Font property of interest.</param>
    /// <param name="preferredLocaleNames">List of semicolon delimited language names in preferred
    ///     order. When a particular string like font family has more than one localized name,
    ///     the first match is returned.</param>
    /// <param name="stringsList">Receives a pointer to the newly created strings list.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// For example, suppose the font set includes the Meiryo family, which has both Japanese and English family names.
    /// The returned list of distinct family names would include either the Japanese name (if "ja-jp" was specified as
    /// a preferred locale) or the English name (in all other cases).
    /// </remarks>
    STDMETHOD(GetPropertyValues)(
        DWRITE_FONT_PROPERTY_ID propertyID,
        _In_z_ WCHAR const* preferredLocaleNames,
        _COM_Outptr_ IDWriteStringList** values
        ) PURE;

    /// <summary>
    /// Returns all unique property values in the set, which can be used
    /// for purposes such as displaying a family list or tag cloud. All values
    /// are returned regardless of language, including all localized names.
    /// </summary>
    /// <param name="propertyID">Font property of interest.</param>
    /// <param name="stringsList">Receives a pointer to the newly created strings list.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// For example, suppose the font set includes the Meiryo family, which has both Japanese and English family names.
    /// The returned list of distinct family names would include both the Japanese and English names.
    /// </remarks>
    STDMETHOD(GetPropertyValues)(
        DWRITE_FONT_PROPERTY_ID propertyID,
        _COM_Outptr_ IDWriteStringList** values
        ) PURE;

    /// <summary>
    /// Returns how many times a given property value occurs in the set.
    /// </summary>
    /// <param name="property">Font property of interest.</param>
    /// <param name="propertyOccurrenceCount">How many times that property occurs.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// For example, the family name "Segoe UI" may return a count of 12,
    /// whereas Harrington only has 1.
    /// </remarks>
    STDMETHOD(GetPropertyOccurrenceCount)(
        _In_ DWRITE_FONT_PROPERTY const* property,
        _Out_ UINT32* propertyOccurrenceCount
        ) PURE;

    /// <summary>
    /// Returns a subset of fonts filtered by the given properties.
    /// </summary>
    /// <param name="properties">List of properties to filter using.</param>
    /// <param name="propertyCount">How many properties to filter.</param>
    /// <param name="filteredSet">Subset of fonts that match the properties,
    ///     or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// If no fonts matched the filter, the subset will be empty (GetFontCount
    /// returns 0), but the function does not return an error. The subset will
    /// always be equal to or less than the original set.
    /// </remarks>
    STDMETHOD(GetMatchingFonts)(
        _In_reads_(propertyCount) DWRITE_FONT_PROPERTY const* properties,
        UINT32 propertyCount,
        _COM_Outptr_ IDWriteFontSet** filteredSet
        ) PURE;

    /// <summary>
    /// Returns a list of fonts within the given WWS family prioritized by
    /// WWS distance.
    /// </summary>
    /// <param name="familyName">Neutral or localized family name of font.</param>
    /// <param name="fontWeight">Weight of font.</param>
    /// <param name="fontStretch">Stretch of font.</param>
    /// <param name="fontStyle">Slope of font.</param>
    /// <param name="filteredSet">Subset of fonts that match the properties,
    ///     or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The returned list can include simulated bold and oblique variants,
    /// which would be useful for font fallback selection.
    /// </remarks>
    STDMETHOD(GetMatchingFonts)(
        _In_z_ WCHAR const* familyName,
        DWRITE_FONT_WEIGHT fontWeight,
        DWRITE_FONT_STRETCH fontStretch,
        DWRITE_FONT_STYLE fontStyle,
        _COM_Outptr_ IDWriteFontSet** filteredSet
        ) PURE;
};


/// <summary>
/// Builder interface to add font face references and create a font set.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("2F642AFE-9C68-4F40-B8BE-457401AFCB3D") IDWriteFontSetBuilder : public IUnknown
{
    /// <summary>
    /// Adds a reference to a font to the set being built. The necessary
    /// metadata will automatically be extracted from the font upon calling
    /// CreateFontSet.
    /// </summary>
    /// <param name="fontFaceReference">Font face reference object to add to the set.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AddFontFaceReference)(
        _In_ IDWriteFontFaceReference* fontFaceReference
        ) PURE;

    /// <summary>
    /// Adds a reference to a font to the set being built. The caller
    /// supplies enough information to search on, avoiding the need to open
    /// the potentially non-local font. Any properties not supplied by the
    /// caller will be missing, and those properties will not be available as
    /// filters in GetMatchingFonts. GetPropertyValues for missing properties
    /// will return an empty string list. The properties passed should generally
    /// be consistent with the actual font contents, but they need not be. You
    /// could, for example, alias a font using a different name or unique
    /// identifier, or you could set custom tags not present in the actual
    /// font.
    /// </summary>
    /// <param name="fontFaceReference">Reference to the font.</param>
    /// <param name="properties">List of properties to associate with the reference.</param>
    /// <param name="propertyCount">How many properties are defined.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AddFontFaceReference)(
        _In_ IDWriteFontFaceReference* fontFaceReference,
        _In_reads_(propertyCount) DWRITE_FONT_PROPERTY const* properties,
        UINT32 propertyCount
        ) PURE;

    /// <summary>
    /// Appends an existing font set to the one being built, allowing
    /// one to aggregate two sets or to essentially extend an existing one.
    /// </summary>
    /// <param name="fontSet">Font set to append font face references from.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AddFontSet)(
        _In_ IDWriteFontSet* fontSet
        ) PURE;

    /// <summary>
    /// Creates a font set from all the font face references added so
    /// far via AddFontFaceReference.
    /// </summary>
    /// <param name="fontSet">Receives a pointer to the newly created font set object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// Creating a font set takes less time if the references were added
    /// with metadata rather than needing to extract the metadata from the
    /// font file.
    /// </remarks>
    STDMETHOD(CreateFontSet)(
        _COM_Outptr_ IDWriteFontSet** fontSet
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("53585141-D9F8-4095-8321-D73CF6BD116C") IDWriteFontCollection1 : public IDWriteFontCollection
{
    /// <summary>
    /// Get the underlying font set used by this collection.
    /// </summary>
    /// <param name="fontSet">Contains font set used by the collection.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSet)(
        _COM_Outptr_ IDWriteFontSet** fontSet
        ) PURE;

    /// <summary>
    /// Creates a font family object given a zero-based font family index.
    /// </summary>
    /// <param name="index">Zero-based index of the font family.</param>
    /// <param name="fontFamily">Receives a pointer the newly created font family object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFamily)(
        UINT32 index,
        _COM_Outptr_ IDWriteFontFamily1** fontFamily
        ) PURE;

    using IDWriteFontCollection::GetFontFamily;
};


/// <summary>
/// The IDWriteFontFamily interface represents a set of fonts that share the same design but are differentiated
/// by weight, stretch, and style.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("DA20D8EF-812A-4C43-9802-62EC4ABD7ADF") IDWriteFontFamily1 : public IDWriteFontFamily
{
    /// <summary>
    /// Gets the current locality of a font given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <remarks>
    /// The locality enumeration. For fully local files, the result will always
    /// be DWRITE_LOCALITY_LOCAL. For downloadable files, the result depends on how
    /// much of the file has been downloaded, and GetFont() fails if the locality
    /// is REMOTE and potentially fails if PARTIAL. The application can explicitly
    /// ask for the font to be enqueued for download via EnqueueFontDownloadRequest
    /// followed by BeginDownload().
    /// </remarks>
    /// <returns>
    /// The locality enumeration.
    /// </returns>
    STDMETHOD_(DWRITE_LOCALITY, GetFontLocality)(UINT32 listIndex) PURE;

    /// <summary>
    /// Gets a font given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <param name="font">Receives a pointer to the newly created font object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFont)(
        UINT32 listIndex, 
        _COM_Outptr_ IDWriteFont3** font
        ) PURE;

    using IDWriteFontFamily::GetFont;

    /// <summary>
    /// Gets a font face reference given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;
};


/// <summary>
/// The IDWriteFontList interface represents a list of fonts.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("DA20D8EF-812A-4C43-9802-62EC4ABD7ADE") IDWriteFontList1 : public IDWriteFontList
{
    /// <summary>
    /// Gets the current locality of a font given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <remarks>
    /// The locality enumeration. For fully local files, the result will always
    /// be DWRITE_LOCALITY_LOCAL. For downloadable files, the result depends on how
    /// much of the file has been downloaded, and GetFont() fails if the locality
    /// is REMOTE and potentially fails if PARTIAL. The application can explicitly
    /// ask for the font to be enqueued for download via EnqueueFontDownloadRequest
    /// followed by BeginDownload().
    /// </remarks>
    /// <returns>
    /// The locality enumeration.
    /// </returns>
    STDMETHOD_(DWRITE_LOCALITY, GetFontLocality)(UINT32 listIndex) PURE;

    /// <summary>
    /// Gets a font given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <param name="font">Receives a pointer to the newly created font object.</param>
    /// <returns>
    /// Standard HRESULT error code. The function returns DWRITE_E_REMOTEFONT if it could not construct a remote font.
    /// </returns>
    STDMETHOD(GetFont)(
        UINT32 listIndex, 
        _COM_Outptr_ IDWriteFont3** font
        ) PURE;

    using IDWriteFontList::GetFont;

    /// <summary>
    /// Gets a font face reference given its zero-based index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the font list.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;
};


/// <summary>
/// A uniquely identifying reference to a font, from which you can create a font
/// face to query font metrics and use for rendering. A font face reference
/// consists of a font file, font face index, and font face simulation. The file
/// data may or may not be physically present on the local machine yet.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("5E7FA7CA-DDE3-424C-89F0-9FCD6FED58CD") IDWriteFontFaceReference : public IUnknown
{
    /// <summary>
    /// Creates a font face from the reference for use with layout,
    /// shaping, or rendering.
    /// </summary>
    /// <param name="fontFace">Newly created font face object, or nullptr in the case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// This function can fail with DWRITE_E_REMOTEFONT if the font is not local.
    /// </remarks>
    STDMETHOD(CreateFontFace)(
        _COM_Outptr_ IDWriteFontFace3** fontFace
        ) PURE;

    /// <summary>
    /// Creates a font face with alternate font simulations, for example, to
    /// explicitly simulate a bold font face out of a regular variant.
    /// </summary>
    /// <param name="fontFaceSimulationFlags">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontFace">Newly created font face object, or nullptr in the case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// This function can fail with DWRITE_E_REMOTEFONT if the font is not local.
    /// </remarks>
    STDMETHOD(CreateFontFaceWithSimulations)(
        DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags,
        _COM_Outptr_ IDWriteFontFace3** fontFace
        ) PURE;

    /// <summary>
    /// Compares two instances of a font face references for equality.
    /// </summary>
    STDMETHOD_(BOOL, Equals)(IDWriteFontFaceReference* fontFaceReference) PURE;

    /// <summary>
    /// Obtains the zero-based index of the font face in its font file. If the font files contain a single face,
    /// the return value is zero.
    /// </summary>
    STDMETHOD_(UINT32, GetFontFaceIndex)() PURE;

    /// <summary>
    /// Obtains the algorithmic style simulation flags of a font face.
    /// </summary>
    STDMETHOD_(DWRITE_FONT_SIMULATIONS, GetSimulations)() PURE;

    /// <summary>
    /// Obtains the font file representing a font face.
    /// </summary>
    STDMETHOD(GetFontFile)(
        _COM_Outptr_ IDWriteFontFile** fontFile
        ) PURE;

    /// <summary>
    /// Get the local size of the font face in bytes.
    /// </summary>
    /// <remarks> 
    /// The value returned by GetLocalFileSize will always be less than or
    /// equal to the value returned by GetFullSize. If the locality is remote, 
    /// the GetLocalFileSize value is zero. If the locality is local, this 
    /// value will equal the value returned by GetFileSize. If the locality is 
    /// partial, this value will equal the size of the portions of the font 
    /// data that have been downloaded, which will be greater than zero and 
    /// less than or equal to the GetFileSize value.
    /// </remarks>
    STDMETHOD_(UINT64, GetLocalFileSize)() PURE;

    /// <summary>
    /// Get the total size of the font face in bytes.
    /// </summary>
    /// <remarks>
    /// If the locality is remote, this value is unknown and will be zero.
    /// If the locality is partial or local, the value is the full size of
    /// the font face.
    /// </remarks>
    STDMETHOD_(UINT64, GetFileSize)() PURE;

    /// <summary>
    /// Get the last modified date.
    /// </summary>
    /// <remarks>
    /// The time may be zero if the font file loader does not expose file time.
    /// </remarks>
    STDMETHOD(GetFileTime)(_Out_ FILETIME* lastWriteTime) PURE;

    /// <summary>
    /// Get the locality of this font face reference. You can always successfully
    /// create a font face from a fully local font. Attempting to create a font
    /// face on a remote or partially local font may fail with DWRITE_E_REMOTEFONT.
    /// This function may change between calls depending on background downloads
    /// and whether cached data expires.
    /// </summary>
    STDMETHOD_(DWRITE_LOCALITY, GetLocality)() PURE;

    /// <summary>
    /// Adds a request to the font download queue (IDWriteFontDownloadQueue).
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(EnqueueFontDownloadRequest)() PURE;

    /// <summary>
    /// Adds a request to the font download queue (IDWriteFontDownloadQueue).
    /// </summary>
    /// <param name="characters">Array of characters to download.</param>
    /// <param name="characterCount">The number of elements in the character array.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// Downloading a character involves downloading every glyph it depends on
    /// directly or indirectly, via font tables (cmap, GSUB, COLR, glyf).
    /// </remarks>
    STDMETHOD(EnqueueCharacterDownloadRequest)(
        _In_reads_(characterCount) WCHAR const* characters,
        UINT32 characterCount
        ) PURE;

    /// <summary>
    /// Adds a request to the font download queue (IDWriteFontDownloadQueue).
    /// </summary>
    /// <param name="glyphIndices">Array of glyph indices to download.</param>
    /// <param name="glyphCount">The number of elements in the glyph index array.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// Downloading a glyph involves downloading any other glyphs it depends on
    /// from the font tables (GSUB, COLR, glyf).
    /// </remarks>
    STDMETHOD(EnqueueGlyphDownloadRequest)(
        _In_reads_(glyphCount) UINT16 const* glyphIndices,
        UINT32 glyphCount
        ) PURE;

    /// <summary>
    /// Adds a request to the font download queue (IDWriteFontDownloadQueue).
    /// </summary>
    /// <param name="fileOffset">Offset of the fragment from the beginning of the font file.</param>
    /// <param name="fragmentSize">Size of the fragment in bytes.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(EnqueueFileFragmentDownloadRequest)(
        UINT64 fileOffset,
        UINT64 fragmentSize
        ) PURE;
};


/// <summary>
/// The IDWriteFont interface represents a font in a font collection.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("29748ED6-8C9C-4A6A-BE0B-D912E8538944") IDWriteFont3 : public IDWriteFont2
{
    /// <summary>
    /// Creates a font face object for the font.
    /// </summary>
    /// <param name="fontFace">Receives a pointer to the newly created font face object.</param>
    /// <returns>
    /// Standard HRESULT error code. The function returns DWRITE_E_REMOTEFONT if it could not construct a remote font.
    /// </returns>
    STDMETHOD(CreateFontFace)(
        _COM_Outptr_ IDWriteFontFace3** fontFace
        ) PURE;

    using IDWriteFont::CreateFontFace;

    /// <summary>
    /// Compares two instances of a font references for equality.
    /// </summary>
    STDMETHOD_(BOOL, Equals)(IDWriteFont* font) PURE;

    /// <summary>
    /// Return a font face reference identifying this font.
    /// </summary>
    /// <param name="fontFaceReference">A uniquely identifying reference to a font face.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;

    /// <summary>
    /// Determines whether the font supports the specified character.
    /// </summary>
    /// <param name="unicodeValue">Unicode (UCS-4) character value.</param>
    /// <returns>
    /// Returns TRUE if the font has the specified character, FALSE if not.
    /// </returns>
    STDMETHOD_(BOOL, HasCharacter)(
        UINT32 unicodeValue
        ) PURE;

    using IDWriteFont::HasCharacter;

    /// <summary>
    /// Gets the current locality of the font.
    /// </summary>
    /// <remarks>
    /// The locality enumeration. For fully local files, the result will always
    /// be DWRITE_LOCALITY_LOCAL. A downloadable file may be any of the states,
    /// and this function may change between calls.
    /// </remarks>
    /// <returns>
    /// The locality enumeration.
    /// </returns>
    STDMETHOD_(DWRITE_LOCALITY, GetLocality)() PURE;
};


/// <summary>
/// The interface that represents an absolute reference to a font face.
/// It contains font face type, appropriate file references and face identification data.
/// Various font data such as metrics, names and glyph outlines is obtained from IDWriteFontFace.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("D37D7598-09BE-4222-A236-2081341CC1F2") IDWriteFontFace3 : public IDWriteFontFace2
{
    /// <summary>
    /// Return a font face reference identifying this font.
    /// </summary>
    /// <param name="fontFaceReference">A uniquely identifying reference to a font face.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        _COM_Outptr_ IDWriteFontFaceReference** fontFaceReference
        ) PURE;

    /// <summary>
    /// Gets the PANOSE values from the font, used for font selection and
    /// matching.
    /// </summary>
    /// <param name="panose">PANOSE structure to fill in.</param>
    /// <remarks>
    /// The function does not simulate these, such as substituting a weight or
    /// proportion inferred on other values. If the font does not specify them,
    /// they are all set to 'any' (0).
    /// </remarks>
    STDMETHOD_(void, GetPanose)(
        _Out_ DWRITE_PANOSE* panose
        ) PURE;

    /// <summary>
    /// Gets the weight of the specified font.
    /// </summary>
    STDMETHOD_(DWRITE_FONT_WEIGHT, GetWeight)() PURE;

    /// <summary>
    /// Gets the stretch (aka. width) of the specified font.
    /// </summary>
    STDMETHOD_(DWRITE_FONT_STRETCH, GetStretch)() PURE;

    /// <summary>
    /// Gets the style (aka. slope) of the specified font.
    /// </summary>
    STDMETHOD_(DWRITE_FONT_STYLE, GetStyle)() PURE;

    /// <summary>
    /// Creates an localized strings object that contains the weight-stretch-style family names for the font family, indexed by locale name.
    /// </summary>
    /// <param name="names">Receives a pointer to the newly created localized strings object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFamilyNames)(
        _COM_Outptr_ IDWriteLocalizedStrings** names
        ) PURE;

    /// <summary>
    /// Gets a localized strings collection containing the weight-stretch-style face names for the font (e.g., Regular or Bold), indexed by locale name.
    /// </summary>
    /// <param name="names">Receives a pointer to the newly created localized strings object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFaceNames)(
        _COM_Outptr_ IDWriteLocalizedStrings** names
        ) PURE;

    /// <summary>
    /// Gets a localized strings collection containing the specified informational strings, indexed by locale name.
    /// </summary>
    /// <param name="informationalStringID">Identifies the string to get.</param>
    /// <param name="informationalStrings">Receives a pointer to the newly created localized strings object.</param>
    /// <param name="exists">Receives the value TRUE if the font contains the specified string ID or FALSE if not.</param>
    /// <returns>
    /// Standard HRESULT error code. If the font does not contain the specified string, the return value is S_OK but 
    /// informationalStrings receives a NULL pointer and exists receives the value FALSE.
    /// </returns>
    STDMETHOD(GetInformationalStrings)(
        DWRITE_INFORMATIONAL_STRING_ID informationalStringID,
        _COM_Outptr_result_maybenull_ IDWriteLocalizedStrings** informationalStrings,
        _Out_ BOOL* exists
        ) PURE;

    /// <summary>
    /// Determines whether the font supports the specified character.
    /// </summary>
    /// <param name="unicodeValue">Unicode (UCS-4) character value.</param>
    /// <returns>
    /// Returns TRUE if the font has the specified character, FALSE if not.
    /// </returns>
    STDMETHOD_(BOOL, HasCharacter)(
        UINT32 unicodeValue
        ) PURE;

    /// <summary>
    /// Determines the recommended text rendering and grid-fit mode to be used based on the
    /// font, size, world transform, and measuring mode.
    /// </summary>
    /// <param name="fontEmSize">Logical font size in DIPs.</param>
    /// <param name="dpiX">Number of pixels per logical inch in the horizontal direction.</param>
    /// <param name="dpiY">Number of pixels per logical inch in the vertical direction.</param>
    /// <param name="transform">Specifies the world transform.</param>
    /// <param name="outlineThreshold">Specifies the quality of the graphics system's outline rendering,
    /// affects the size threshold above which outline rendering is used.</param>
    /// <param name="measuringMode">Specifies the method used to measure during text layout. For proper
    /// glyph spacing, the function returns a rendering mode that is compatible with the specified 
    /// measuring mode.</param>
    /// <param name="renderingParams">Rendering parameters object. This parameter is necessary in case the rendering parameters 
    /// object overrides the rendering mode.</param>
    /// <param name="renderingMode">Receives the recommended rendering mode.</param>
    /// <param name="gridFitMode">Receives the recommended grid-fit mode.</param>
    /// <remarks>
    /// This method should be used to determine the actual rendering mode in cases where the rendering 
    /// mode of the rendering params object is DWRITE_RENDERING_MODE_DEFAULT, and the actual grid-fit
    /// mode when the rendering params object is DWRITE_GRID_FIT_MODE_DEFAULT.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetRecommendedRenderingMode)(
        FLOAT fontEmSize,
        FLOAT dpiX,
        FLOAT dpiY,
        _In_opt_ DWRITE_MATRIX const* transform,
        BOOL isSideways,
        DWRITE_OUTLINE_THRESHOLD outlineThreshold,
        DWRITE_MEASURING_MODE measuringMode,
        _In_opt_ IDWriteRenderingParams* renderingParams,
        _Out_ DWRITE_RENDERING_MODE1* renderingMode,
        _Out_ DWRITE_GRID_FIT_MODE* gridFitMode
        ) PURE;

    using IDWriteFontFace2::GetRecommendedRenderingMode;

    /// <summary>
    /// Determines whether the character is locally downloaded from the font.
    /// </summary>
    /// <param name="unicodeValue">Unicode (UCS-4) character value.</param>
    /// <returns>
    /// Returns TRUE if the font has the specified character locally available,
    /// FALSE if not or if the font does not support that character.
    /// </returns>
    STDMETHOD_(BOOL, IsCharacterLocal)(
        UINT32 unicodeValue
        ) PURE;

    /// <summary>
    /// Determines whether the glyph is locally downloaded from the font.
    /// </summary>
    /// <param name="glyphId">Glyph identifier.</param>
    /// <returns>
    /// Returns TRUE if the font has the specified glyph locally available.
    /// </returns>
    STDMETHOD_(BOOL, IsGlyphLocal)(
        UINT16 glyphId
        ) PURE;

    /// <summary>
    /// Determines whether the specified characters are local.
    /// </summary>
    /// <param name="characters">Array of characters.</param>
    /// <param name="characterCount">The number of elements in the character array.</param>
    /// <param name="enqueueIfNotLocal">Specifies whether to enqueue a download request
    /// if any of the specified characters are not local.</param>
    /// <param name="isLocal">Receives TRUE if all of the specified characters are local,
    /// FALSE if any of the specified characters are remote.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AreCharactersLocal)(
        _In_reads_(characterCount) WCHAR const* characters,
        UINT32 characterCount,
        BOOL enqueueIfNotLocal,
        _Out_ BOOL* isLocal
        ) PURE;

    /// <summary>
    /// Determines whether the specified glyphs are local.
    /// </summary>
    /// <param name="glyphIndices">Array of glyph indices.</param>
    /// <param name="glyphCount">The number of elements in the glyph index array.</param>
    /// <param name="enqueueIfNotLocal">Specifies whether to enqueue a download request
    /// if any of the specified glyphs are not local.</param>
    /// <param name="isLocal">Receives TRUE if all of the specified glyphs are local,
    /// FALSE if any of the specified glyphs are remote.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AreGlyphsLocal)(
        _In_reads_(glyphCount) UINT16 const* glyphIndices,
        UINT32 glyphCount,
        BOOL enqueueIfNotLocal,
        _Out_ BOOL* isLocal
        ) PURE;
};


/// <summary>
/// Represents a collection of strings indexed by number.
/// An IDWriteStringList is otherwise identical to IDWriteLocalizedStrings except
/// for the semantics, where localized strings are indexed on language (each
/// language has one string property) whereas a string list may contain multiple
/// strings of the same language, such as a string list of family names from a
/// font set. You can QueryInterface from an IDWriteLocalizedStrings to an
/// IDWriteStringList.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("CFEE3140-1157-47CA-8B85-31BFCF3F2D0E") IDWriteStringList : public IUnknown
{
    /// <summary>
    /// Gets the number of strings.
    /// </summary>
    STDMETHOD_(UINT32, GetCount)() PURE;

    /// <summary>
    /// Gets the length in characters (not including the null terminator) of the locale name with the specified index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the locale name.</param>
    /// <param name="length">Receives the length in characters, not including the null terminator.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLocaleNameLength)(
        UINT32 listIndex,
        _Out_ UINT32* length
        ) PURE;

    /// <summary>
    /// Copies the locale name with the specified index to the specified array.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the locale name.</param>
    /// <param name="localeName">Character array that receives the locale name.</param>
    /// <param name="size">Size of the array in characters. The size must include space for the terminating
    /// null character.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLocaleName)(
        UINT32 listIndex,
        _Out_writes_z_(size) WCHAR* localeName,
        UINT32 size
        ) PURE;

    /// <summary>
    /// Gets the length in characters (not including the null terminator) of the string with the specified index.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the string.</param>
    /// <param name="length">Receives the length in characters, not including the null terminator.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetStringLength)(
        UINT32 listIndex,
        _Out_ UINT32* length
        ) PURE;

    /// <summary>
    /// Copies the string with the specified index to the specified array.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the string.</param>
    /// <param name="stringBuffer">Character array that receives the string.</param>
    /// <param name="size">Size of the array in characters. The size must include space for the terminating
    ///     null character.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetString)(
        UINT32 listIndex,
        _Out_writes_z_(stringBufferSize) WCHAR* stringBuffer,
        UINT32 stringBufferSize
        ) PURE;
};


/// <summary>
/// Application-defined callback interface that receives notifications from the font 
/// download queue (IDWriteFontDownloadQueue interface). Callbacks will occur on the
/// downloading thread, and objects must be prepared to handle calls on their methods
/// from other threads at any time.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("B06FE5B9-43EC-4393-881B-DBE4DC72FDA7") IDWriteFontDownloadListener : public IUnknown
{
    /// <summary>
    /// The DownloadCompleted method is called back on an arbitrary thread when a
    /// download operation ends.
    /// </summary>
    /// <param name="downloadQueue">Pointer to the download queue interface on which
    /// the BeginDownload method was called.</param>
    /// <param name="context">Optional context object that was passed to BeginDownload.
    /// AddRef is called on the context object by BeginDownload and Release is called
    /// after the DownloadCompleted method returns.</param>
    /// <param name="downloadResult">Result of the download operation.</param>
    STDMETHOD_(void, DownloadCompleted)(
        _In_ IDWriteFontDownloadQueue* downloadQueue,
        _In_opt_ IUnknown* context,
        HRESULT downloadResult
        ) PURE;
};


/// <summary>
/// Interface that enqueues download requests for remote fonts, characters, glyphs, and font fragments.
/// Provides methods to asynchronously execute a download, cancel pending downloads, and be notified of
/// download completion. Callbacks to listeners will occur on the downloading thread, and objects must
/// be must be able to handle calls on their methods from other threads at any time.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("B71E6052-5AEA-4FA3-832E-F60D431F7E91") IDWriteFontDownloadQueue : public IUnknown
{
    /// <summary>
    /// Registers a client-defined listener object that receives download notifications.
    /// All registered listener's DownloadCompleted will be called after BeginDownload
    /// completes.
    /// </summary>
    /// <param name="listener">Listener object to add.</param>
    /// <param name="token">Receives a token value, which the caller must subsequently
    /// pass to RemoveListener.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// An IDWriteFontDownloadListener can also be passed to BeginDownload via the
    /// context parameter, rather than globally registered to the queue.
    /// </remarks>
    STDMETHOD(AddListener)(
        IDWriteFontDownloadListener* listener,
        _Out_ UINT32* token
        ) PURE;

    /// <summary>
    /// Unregisters a notification handler that was previously registered using
    /// AddListener.
    /// </summary>
    /// <param name="token">Token value previously returned by AddListener.</param>
    /// <returns>
    /// Returns S_OK if successful or E_INVALIDARG if the specified token does not
    /// correspond to a registered listener.
    /// </returns>
    STDMETHOD(RemoveListener)(
        UINT32 token
        ) PURE;

    /// <summary>
    /// Determines whether the download queue is empty. Note that the queue does not
    /// include requests that are already being downloaded. In other words, BeginDownload
    /// clears the queue.
    /// </summary>
    /// <returns>
    /// TRUE if the queue is empty, FALSE if there are requests pending for BeginDownload.
    /// </returns>
    STDMETHOD_(BOOL, IsEmpty)() PURE;

    /// <summary>
    /// Begins an asynchronous download operation. The download operation executes
    /// in the background until it completes or is cancelled by a CancelDownload call.
    /// </summary>
    /// <param name="context">Optional context object that is passed back to the 
    /// download notification handler's DownloadCompleted method. If the context object
    /// implements IDWriteFontDownloadListener, its DownloadCompleted will be called
    /// when done.</param>
    /// <returns>
    /// Returns S_OK if a download was successfully begun, S_FALSE if the queue was 
    /// empty, or a standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// BeginDownload removes all download requests from the queue, transferring them
    /// to a background download operation. If any previous downloads are still ongoing
    /// when BeginDownload is called again, the new download does not complete until
    /// the previous downloads have finished. If the queue is empty and no active
    /// downloads are pending, the DownloadCompleted callback is called immediately with
    /// DWRITE_DOWNLOAD_RESULT_NONE.
    /// </remarks>
    STDMETHOD(BeginDownload)(
        _In_opt_ IUnknown* context = nullptr
        ) PURE;

    /// <summary>
    /// Removes all download requests from the queue and cancels any active download
    /// operations. This calls DownloadCompleted with DWRITE_E_DOWNLOADCANCELLED.
    /// Applications should call this when shutting down if they started any
    /// downloads that have not finished yet with a call to DownloadCompleted.
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CancelDownload)() PURE;

    /// <summary>
    /// Get the current generation number of the download queue, which is incremented
    /// every time after a download completes, whether failed or successful. This cookie
    /// comparison value may be used to compared against cached data to know when it is
    /// stale.
    /// </summary>
    /// <returns>
    /// The number of download queue generations.
    /// </returns>
    STDMETHOD_(UINT64, GetGenerationCount)() PURE;
};


/// <summary>
/// The GDI interop interface provides interoperability with GDI.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("4556BE70-3ABD-4F70-90BE-421780A6F515") IDWriteGdiInterop1 : public IDWriteGdiInterop
{
    /// <summary>
    /// Creates a font object that matches the properties specified by the LOGFONT structure.
    /// </summary>
    /// <param name="logFont">Structure containing a GDI-compatible font description.</param>
    /// <param name="fontCollection">The font collection to search. If NULL, the local system font collection is used.</param>
    /// <param name="font">Receives a newly created font object if successful, or NULL in case of error.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The only fields that matter include: lfFaceName, lfCharSet, lfWeight, lfItalic.
    /// Font size and rendering mode are a rendering time property, not a font property,
    /// and text decorations like underline are drawn separately from the text. If no
    /// font matches the given weight, slope, and character set, the best match within
    /// the given GDI family name will be returned. DWRITE_E_NOFONT is returned if there
    /// is no matching font name using either the GDI family name (e.g. Arial) or the
    /// full font name (e.g. Arial Bold Italic).
    /// </remarks>
    STDMETHOD(CreateFontFromLOGFONT)(
        _In_ LOGFONTW const* logFont,
        _In_opt_ IDWriteFontCollection* fontCollection,
        _COM_Outptr_ IDWriteFont** font
        ) PURE;

    /// <summary>
    /// Reads the font signature from the given font.
    /// </summary>
    /// <param name="font">Font to read font signature from.</param>
    /// <param name="fontSignature">Font signature from the OS/2 table, ulUnicodeRange and ulCodePageRange.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSignature)(
        _In_ IDWriteFont* font,
        _Out_ FONTSIGNATURE* fontSignature
        ) PURE;

    /// <summary>
    /// Reads the font signature from the given font.
    /// </summary>
    /// <param name="font">Font to read font signature from.</param>
    /// <param name="fontSignature">Font signature from the OS/2 table, ulUnicodeRange and ulCodePageRange.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSignature)(
        _In_ IDWriteFontFace* fontFace,
        _Out_ FONTSIGNATURE* fontSignature
        ) PURE;

    /// <summary>
    /// Get a list of matching fonts based on the LOGFONT values. Only fonts
    /// of that family name will be returned.
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetMatchingFontsByLOGFONT)(
        _In_ LOGFONT const* logFont,
        _In_ IDWriteFontSet* fontSet,
        _COM_Outptr_ IDWriteFontSet** filteredSet
        ) PURE;

    using IDWriteGdiInterop::CreateFontFromLOGFONT;
};

/// <summary>
/// Information about a formatted line of text.
/// </summary>
struct DWRITE_LINE_METRICS1 : DWRITE_LINE_METRICS
{
    /// <summary>
    /// White space before the content of the line. This is included in the line height and baseline distances.
    /// If the line is formatted horizontally either with a uniform line spacing or with proportional
    /// line spacing, this value represents the extra space above the content.
    /// </summary>
    FLOAT leadingBefore;

    /// <summary>
    /// White space after the content of the line. This is included in the height of the line.
    /// If the line is formatted horizontally either with a uniform line spacing or with proportional
    /// line spacing, this value represents the extra space below the content.
    /// </summary>
    FLOAT leadingAfter;
};

/// <summary>
/// Specify whether DWRITE_FONT_METRICS::lineGap value should be part of the line metrics. 
/// </summary>
enum DWRITE_FONT_LINE_GAP_USAGE
{
    /// <summary>
    /// The usage of the font line gap depends on the method used for text layout.
    /// </summary>
    DWRITE_FONT_LINE_GAP_USAGE_DEFAULT,

    /// <summary>
    /// The font line gap is excluded from line spacing
    /// </summary>
    DWRITE_FONT_LINE_GAP_USAGE_DISABLED,

    /// <summary>
    /// The font line gap is included in line spacing
    /// </summary>
    DWRITE_FONT_LINE_GAP_USAGE_ENABLED
};

/// <summary>
/// The DWRITE_LINE_SPACING structure specifies the parameters used to specify how to manage space between lines.
/// </summary>
struct DWRITE_LINE_SPACING
{
    /// <summary>
    /// Method used to determine line spacing.
    /// </summary>
    DWRITE_LINE_SPACING_METHOD method;

    /// <summary>
    /// Spacing between lines.
    /// The interpretation of this parameter depends upon the line spacing method, as follows:
    /// - default line spacing: ignored
    /// - uniform line spacing: explicit distance in DIPs between lines
    /// - proportional line spacing: a scaling factor to be applied to the computed line height; 
    ///   for each line, the height of the line is computed as for default line spacing, and the scaling factor is applied to that value.
    /// </summary>
    FLOAT height;

    /// <summary>
    /// Distance from top of line to baseline. 
    /// The interpretation of this parameter depends upon the line spacing method, as follows:
    /// - default line spacing: ignored
    /// - uniform line spacing: explicit distance in DIPs from the top of the line to the baseline
    /// - proportional line spacing: a scaling factor applied to the computed baseline; for each line, 
    ///   the baseline distance is computed as for default line spacing, and the scaling factor is applied to that value.
    /// </summary>
    FLOAT baseline;

    /// <summary>
    /// Proportion of the entire leading distributed before the line. The allowed value is between 0 and 1.0. The remaining
    /// leading is distributed after the line. It is ignored for the default and uniform line spacing methods.
    /// The leading that is available to distribute before or after the line depends on the values of the height and
    /// baseline parameters.
    /// </summary>
    FLOAT leadingBefore;

    /// <summary>
    /// Specify whether DWRITE_FONT_METRICS::lineGap value should be part of the line metrics.
    /// </summary>
    DWRITE_FONT_LINE_GAP_USAGE fontLineGapUsage;
};

interface DWRITE_DECLARE_INTERFACE("F67E0EDD-9E3D-4ECC-8C32-4183253DFE70") IDWriteTextFormat2 : public IDWriteTextFormat1
{
    /// <summary>
    /// Set line spacing.
    /// </summary>
    /// <param name="lineSpacing">How to manage space between lines.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetLineSpacing)(_In_ DWRITE_LINE_SPACING const* lineSpacingOptions) PURE;

    /// <summary>
    /// Get line spacing.
    /// </summary>
    /// <param name="lineSpacing">How to manage space between lines.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLineSpacing)(_Out_ DWRITE_LINE_SPACING* lineSpacingOptions) PURE;

    using IDWriteTextFormat1::SetLineSpacing;
    using IDWriteTextFormat1::GetLineSpacing;
};

interface DWRITE_DECLARE_INTERFACE("07DDCD52-020E-4DE8-AC33-6C953D83F92D") IDWriteTextLayout3 : public IDWriteTextLayout2
{
    /// <summary>
    /// Invalidates the layout, forcing layout to remeasure before calling the
    /// metrics or drawing functions. This is useful if the locality of a font
    /// changes, and layout should be redrawn, or if the size of a client
    /// implemented IDWriteInlineObject changes.
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(InvalidateLayout)() PURE;

    /// <summary>
    /// Set line spacing.
    /// </summary>
    /// <param name="lineSpacing">How to manage space between lines.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetLineSpacing)(_In_ DWRITE_LINE_SPACING const* lineSpacingOptions) PURE;

    /// <summary>
    /// Get line spacing.
    /// </summary>
    /// <param name="lineSpacing">How to manage space between lines.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLineSpacing)(_Out_ DWRITE_LINE_SPACING* lineSpacingOptions) PURE;

    /// <summary>
    /// GetLineMetrics returns properties of each line.
    /// </summary>
    /// <param name="lineMetrics">The array to fill with line information.</param>
    /// <param name="maxLineCount">The maximum size of the lineMetrics array.</param>
    /// <param name="actualLineCount">The actual size of the lineMetrics
    /// array that is needed.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// If maxLineCount is not large enough E_NOT_SUFFICIENT_BUFFER, 
    /// which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER),
    /// is returned and *actualLineCount is set to the number of lines
    /// needed.
    /// </remarks>
    STDMETHOD(GetLineMetrics)(
        _Out_writes_to_opt_(maxLineCount, *actualLineCount) DWRITE_LINE_METRICS1* lineMetrics,
        UINT32 maxLineCount,
        _Out_ UINT32* actualLineCount
        ) PURE;

    using IDWriteTextLayout2::SetLineSpacing;
    using IDWriteTextLayout2::GetLineSpacing;
    using IDWriteTextLayout2::GetLineMetrics;
};


////////////////////////////////////////////////////////////////////////////////////////////////////


#if NTDDI_VERSION >= NTDDI_WIN10_RS1


/// <summary>
/// Represents a color glyph run. The IDWriteFactory4::TranslateColorGlyphRun
/// method returns an ordered collection of color glyph runs of varying types
/// depending on what the font supports.
/// </summary>
/// <summary>
/// For runs without any specific color, such as PNG data, the runColor field will be zero.
/// </summary>
struct DWRITE_COLOR_GLYPH_RUN1 : DWRITE_COLOR_GLYPH_RUN
{
    /// <summary>
    /// Type of glyph image format for this color run. Exactly one type will be set since
    /// TranslateColorGlyphRun has already broken down the run into separate parts.
    /// </summary>
    DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat;

    /// <summary>
    /// Measuring mode to use for this glyph run.
    /// </summary>
    DWRITE_MEASURING_MODE measuringMode;
};


/// <summary>
/// Data for a single glyph from GetGlyphImageData.
/// </summary>
struct DWRITE_GLYPH_IMAGE_DATA
{
    /// <summary>
    /// Pointer to the glyph data, be it SVG, PNG, JPEG, TIFF.
    /// </summary>
    _Field_size_bytes_(imageDataSize) void const* imageData;

    /// <summary>
    /// Size of glyph data in bytes.
    /// </summary>
    UINT32 imageDataSize;

    /// <summary>
    /// Unique identifier for the glyph data. Clients may use this to cache a parsed/decompressed
    /// version and tell whether a repeated call to the same font returns the same data.
    /// </summary>
    UINT32 uniqueDataId;

    /// <summary>
    /// Pixels per em of the returned data. For non-scalable raster data (PNG/TIFF/JPG), this can be larger
    /// or smaller than requested from GetGlyphImageData when there isn't an exact match.
    /// For scaling intermediate sizes, use: desired pixels per em * font em size / actual pixels per em.
    /// </summary>
    UINT32 pixelsPerEm;

    /// <summary>
    /// Size of image when the format is pixel data.
    /// </summary>
    D2D1_SIZE_U pixelSize;

    /// <summary>
    /// Left origin along the horizontal Roman baseline.
    /// </summary>
    D2D1_POINT_2L horizontalLeftOrigin;

    /// <summary>
    /// Right origin along the horizontal Roman baseline.
    /// </summary>
    D2D1_POINT_2L horizontalRightOrigin;

    /// <summary>
    /// Top origin along the vertical central baseline.
    /// </summary>
    D2D1_POINT_2L verticalTopOrigin;

    /// <summary>
    /// Bottom origin along vertical central baseline.
    /// </summary>
    D2D1_POINT_2L verticalBottomOrigin;
};


/// <summary>
/// Enumerator for an ordered collection of color glyph runs.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("7C5F86DA-C7A1-4F05-B8E1-55A179FE5A35") IDWriteColorGlyphRunEnumerator1 : public IDWriteColorGlyphRunEnumerator
{
    /// <summary>
    /// Gets the current color glyph run.
    /// </summary>
    /// <param name="colorGlyphRun">Receives a pointer to the color
    /// glyph run. The pointer remains valid until the next call to
    /// MoveNext or until the interface is released.</param>
    /// <returns>
    /// Standard HRESULT error code. An error is returned if there is
    /// no current glyph run, i.e., if MoveNext has not yet been called
    /// or if the end of the sequence has been reached.
    /// </returns>
    STDMETHOD(GetCurrentRun)(
        _Outptr_ DWRITE_COLOR_GLYPH_RUN1 const** colorGlyphRun
        ) PURE;

    using IDWriteColorGlyphRunEnumerator::GetCurrentRun;
};


/// <summary>
/// The interface that represents an absolute reference to a font face.
/// It contains font face type, appropriate file references and face identification data.
/// Various font data such as metrics, names and glyph outlines is obtained from IDWriteFontFace.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("27F2A904-4EB8-441D-9678-0563F53E3E2F") IDWriteFontFace4 : public IDWriteFontFace3
{
    /// <summary>
    /// Gets all the glyph image formats supported by the entire font (SVG, PNG, JPEG, ...).
    /// </summary>
    STDMETHOD_(DWRITE_GLYPH_IMAGE_FORMATS, GetGlyphImageFormats)() PURE;

    /// <summary>
    /// Gets the available image formats of a specific glyph and ppem. Glyphs often have at least TrueType
    /// or CFF outlines, but they may also have SVG outlines, or they may have only bitmaps
    /// with no TrueType/CFF outlines. Some image formats, notably the PNG/JPEG ones, are size
    /// specific and will return no match when there isn't an entry in that size range.
    /// </summary>
    /// <remarks>
    /// Glyph ids beyond the glyph count return DWRITE_GLYPH_IMAGE_FORMATS_NONE.
    /// </remarks>
    STDMETHOD(GetGlyphImageFormats)(
        UINT16 glyphId,
        UINT32 pixelsPerEmFirst,
        UINT32 pixelsPerEmLast,
        _Out_ DWRITE_GLYPH_IMAGE_FORMATS* glyphImageFormats
        ) PURE;

    /// <summary>
    /// Gets a pointer to the glyph data based on the desired image format.
    /// </summary>
    /// <remarks>
    /// The glyphDataContext must be released via ReleaseGlyphImageData when done if the data is not empty,
    /// similar to IDWriteFontFileStream::ReadFileFragment and IDWriteFontFileStream::ReleaseFileFragment.
    /// The data pointer is valid so long as the IDWriteFontFace exists and ReleaseGlyphImageData has not
    /// been called.
    /// </remarks>
    /// <remarks>
    /// The DWRITE_GLYPH_IMAGE_DATA::uniqueDataId is valuable for caching purposes so that if the same
    /// resource is returned more than once, an existing resource can be quickly retrieved rather than
    /// needing to reparse or decompress the data.
    /// </remarks>
    /// <remarks>
    /// The function only returns SVG or raster data - requesting TrueType/CFF/COLR data returns
    /// DWRITE_E_INVALIDARG. Those must be drawn via DrawGlyphRun or queried using GetGlyphOutline instead.
    /// Exactly one format may be requested or else the function returns DWRITE_E_INVALIDARG.
    /// If the glyph does not have that format, the call is not an error, but the function returns empty data. 
    /// </remarks>
    STDMETHOD(GetGlyphImageData)(
        _In_ UINT16 glyphId,
        UINT32 pixelsPerEm,
        DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat,
        _Out_ DWRITE_GLYPH_IMAGE_DATA* glyphData,
        _Outptr_result_maybenull_ void** glyphDataContext
        ) PURE;

    /// <summary>
    /// Releases the table data obtained earlier from ReadGlyphData.
    /// </summary>
    /// <param name="glyphDataContext">Opaque context from ReadGlyphData.</param>
    STDMETHOD_(void, ReleaseGlyphImageData)(
        void* glyphDataContext
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("4B0B5BD3-0797-4549-8AC5-FE915CC53856") IDWriteFactory4 : public IDWriteFactory3
{
    /// <summary>
    /// Translates a glyph run to a sequence of color glyph runs, which can be
    /// rendered to produce a color representation of the original "base" run.
    /// </summary>
    /// <param name="baselineOriginX">Horizontal and vertical origin of the base glyph run in
    /// pre-transform coordinates.</param>
    /// <param name="glyphRun">Pointer to the original "base" glyph run.</param>
    /// <param name="glyphRunDescription">Optional glyph run description.</param>
    /// <param name="glyphImageFormats">Which data formats TranslateColorGlyphRun
    /// should split the runs into.</param>
    /// <param name="measuringMode">Measuring mode, needed to compute the origins
    /// of each glyph.</param>
    /// <param name="worldToDeviceTransform">Matrix converting from the client's
    /// coordinate space to device coordinates (pixels), i.e., the world transform
    /// multiplied by any DPI scaling.</param>
    /// <param name="colorPaletteIndex">Zero-based index of the color palette to use.
    /// Valid indices are less than the number of palettes in the font, as returned
    /// by IDWriteFontFace2::GetColorPaletteCount.</param>
    /// <param name="colorLayers">If the function succeeds, receives a pointer
    /// to an enumerator object that can be used to obtain the color glyph runs.
    /// If the base run has no color glyphs, then the output pointer is NULL
    /// and the method returns DWRITE_E_NOCOLOR.</param>
    /// <returns>
    /// Returns DWRITE_E_NOCOLOR if the font has no color information, the glyph run
    /// does not contain any color glyphs, or the specified color palette index
    /// is out of range. In this case, the client should render the original glyph 
    /// run. Otherwise, returns a standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The old IDWriteFactory2::TranslateColorGlyphRun is equivalent to passing
    /// DWRITE_GLYPH_IMAGE_FORMATS_TRUETYPE|CFF|COLR.
    /// </remarks>
    STDMETHOD(TranslateColorGlyphRun)(
        D2D1_POINT_2F baselineOrigin,
        _In_ DWRITE_GLYPH_RUN const* glyphRun,
        _In_opt_ DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
        DWRITE_GLYPH_IMAGE_FORMATS desiredGlyphImageFormats,
        DWRITE_MEASURING_MODE measuringMode,
        _In_opt_ DWRITE_MATRIX const* worldAndDpiTransform,
        UINT32 colorPaletteIndex,
        _COM_Outptr_ IDWriteColorGlyphRunEnumerator1** colorLayers
        ) PURE;

    using IDWriteFactory2::TranslateColorGlyphRun;

    /// <summary>
    /// Converts glyph run placements to glyph origins.
    /// </summary>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The transform and DPI have no affect on the origin scaling.
    /// They are solely used to compute glyph advances when not supplied
    /// and align glyphs in pixel aligned measuring modes.
    /// </remarks>
    STDMETHOD(ComputeGlyphOrigins)(
        DWRITE_GLYPH_RUN const* glyphRun,
        DWRITE_MEASURING_MODE measuringMode,
        D2D1_POINT_2F baselineOrigin,
        _In_opt_ DWRITE_MATRIX const* worldAndDpiTransform,
        _Out_writes_(glyphRun->glyphCount) D2D1_POINT_2F* glyphOrigins
        ) PURE;

    /// <summary>
    /// Converts glyph run placements to glyph origins. This overload is for natural metrics, which
    /// includes SVG, TrueType natural modes, and bitmap placement.
    /// </summary>
    STDMETHOD(ComputeGlyphOrigins)(
        DWRITE_GLYPH_RUN const* glyphRun,
        D2D1_POINT_2F baselineOrigin,
        _Out_writes_(glyphRun->glyphCount) D2D1_POINT_2F* glyphOrigins
        ) PURE;
};

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS1


////////////////////////////////////////////////////////////////////////////////////////////////////


#if NTDDI_VERSION >= NTDDI_WIN10_RS2

interface DWRITE_DECLARE_INTERFACE("3FF7715F-3CDC-4DC6-9B72-EC5621DCCAFD") IDWriteFontSetBuilder1 : public IDWriteFontSetBuilder
{
    /// <summary>
    /// Adds references to all the fonts in the specified font file. The method
    /// parses the font file to determine the fonts and their properties.
    /// </summary>
    /// <param name="fontFile">Font file reference object to add to the set.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AddFontFile)(
        _In_ IDWriteFontFile* fontFile
        ) PURE;
};

/// <summary>
/// The IDWriteAsyncResult interface represents the result of an asynchronous
/// operation. A client can use the interface to wait for the operation to
/// complete and to get the result.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("CE25F8FD-863B-4D13-9651-C1F88DC73FE2") IDWriteAsyncResult : public IUnknown
{
    /// <summary>
    /// The GetWaitHandleMethod method returns a handle that can be used to wait 
    /// for the asynchronous operation to complete. The handle remains valid
    /// until the interface is released.
    /// </summary>
    STDMETHOD_(HANDLE, GetWaitHandle)() PURE;

    /// <summary>
    /// The GetResult method returns the result of the asynchronous operation.
    /// The return value is E_PENDING if the operation has not yet completed.
    /// </summary>
    STDMETHOD(GetResult)() PURE;
};


/// <summary>
/// DWRITE_FILE_FRAGMENT represents a range of bytes in a font file.
/// </summary>
struct DWRITE_FILE_FRAGMENT
{
    /// <summary>
    /// Starting offset of the fragment from the beginning of the file.
    /// </summary>
    UINT64 fileOffset;

    /// <summary>
    /// Size of the file fragment, in bytes.
    /// </summary>
    UINT64 fragmentSize;
};


/// <summary>
/// IDWriteRemoteFontFileStream represents a font file stream parts of which may be 
/// non-local. Non-local data must be downloaded before it can be accessed using 
/// ReadFragment. The interface exposes methods to download font data and query the 
/// locality of font data.
/// </summary>
/// <remarks>
/// For more information, see the description of IDWriteRemoteFontFileLoader.
/// </remarks>
interface DWRITE_DECLARE_INTERFACE("4DB3757A-2C72-4ED9-B2B6-1ABABE1AFF9C") IDWriteRemoteFontFileStream : public IDWriteFontFileStream
{
    /// <summary>
    /// GetLocalFileSize returns the number of bytes of the font file that are
    /// currently local, which should always be less than or equal to the full
    /// file size returned by GetFileSize. If the locality is remote, the return
    /// value is zero. If the file is fully local, the return value must be the
    /// same as GetFileSize.
    /// </summary>
    /// <param name="localFileSize">Receives the local size of the file.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLocalFileSize)(
        _Out_ UINT64* localFileSize
        ) PURE;

    /// <summary>
    /// GetFileFragmentLocality returns information about the locality of a byte range (i.e.,
    /// font fragment) within the font file stream.
    /// </summary>
    /// <param name="fileOffset">Offset of the fragment from the beginning of the font file.</param>
    /// <param name="fragmentSize">Size of the fragment in bytes.</param>
    /// <param name="isLocal">Receives TRUE if the first byte of the fragment is local, FALSE if not.</param>
    /// <param name="partialSize">Receives the number of contiguous bytes from the start of the
    /// fragment that have the same locality as the first byte.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFileFragmentLocality)(
        UINT64 fileOffset,
        UINT64 fragmentSize,
        _Out_ BOOL* isLocal,
        _Out_range_(0, fragmentSize) UINT64* partialSize
        ) PURE;

    /// <summary>
    /// Gets the current locality of the file.
    /// </summary>
    /// <returns>
    /// Returns the locality enumeration (i.e., remote, partial, or local).
    /// </returns>
    STDMETHOD_(DWRITE_LOCALITY, GetLocality)() PURE;

    /// <summary>
    /// BeginDownload begins downloading all or part of the font file.
    /// </summary>
    /// <param name="fileFragments">Array of structures, each specifying a byte
    /// range to download.</param>
    /// <param name="fragmentCount">Number of elements in the fileFragments array.
    /// This can be zero to just download file information, such as the size.</param>
    /// <param name="asyncResult">Receives an object that can be used to wait for
    /// the asynchronous download to complete and to get the download result upon 
    /// completion. The result may be NULL if the download completes synchronously.
    /// For example, this can happen if method determines that the requested data
    /// is already local.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(BeginDownload)(
        _In_ UUID const* downloadOperationID,
        _In_reads_(fragmentCount) DWRITE_FILE_FRAGMENT const* fileFragments,
        UINT32 fragmentCount,
        _COM_Outptr_result_maybenull_ IDWriteAsyncResult** asyncResult
        ) PURE;
};


/// <summary>
/// Specifies the container format of a font resource. A container format is distinct from
/// a font file format (DWRITE_FONT_FILE_TYPE) because the container describes the container
/// in which the underlying font file is packaged.
/// </summary>
enum DWRITE_CONTAINER_TYPE
{
    DWRITE_CONTAINER_TYPE_UNKNOWN,
    DWRITE_CONTAINER_TYPE_WOFF,
    DWRITE_CONTAINER_TYPE_WOFF2
};


/// <summary>
/// The IDWriteRemoteFontFileLoader interface represents a font file loader that can access 
/// remote (i.e., downloadable) fonts. The IDWriteFactory5::CreateHttpFontFileLoader method
/// returns an instance of this interface, or a client can create its own implementation.
/// </summary>
/// <remarks>
/// Calls to a remote file loader or stream should never block waiting for network operations.
/// Any call that cannot succeeded immediately using local (e.g., cached) must should return
/// DWRITE_E_REMOTEFONT. This error signifies to DWrite that it should add requests to the 
/// font download queue.
/// </remarks>
interface DWRITE_DECLARE_INTERFACE("68648C83-6EDE-46C0-AB46-20083A887FDE") IDWriteRemoteFontFileLoader : public IDWriteFontFileLoader
{
    /// <summary>
    /// Creates a remote font file stream object that encapsulates an open file resource
    /// and can be used to download remote file data.
    /// </summary>
    /// <param name="fontFileReferenceKey">Font file reference key that uniquely identifies the font file resource
    /// within the scope of the font loader being used.</param>
    /// <param name="fontFileReferenceKeySize">Size of font file reference key in bytes.</param>
    /// <param name="fontFileStream">Pointer to the newly created font file stream.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// Unlike CreateStreamFromKey, this method can be used to create a stream for a remote file. If the file is 
    /// remote, the returned stream's BeginDownload method can be used to download all or part of the font file. 
    /// However, the stream cannot be used to get the file size or access font data unless the file is at least 
    /// partially local.
    /// </remarks>
    STDMETHOD(CreateRemoteStreamFromKey)(
        _In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
        UINT32 fontFileReferenceKeySize,
        _COM_Outptr_ IDWriteRemoteFontFileStream** fontFileStream
        ) PURE;

    /// <summary>
    /// Gets the locality of the file resource identified by the unique key.
    /// </summary>
    /// <param name="fontFileReferenceKey">Font file reference key that uniquely identifies the font file resource
    /// within the scope of the font loader being used.</param>
    /// <param name="fontFileReferenceKeySize">Size of font file reference key in bytes.</param>
    /// <param name="locality">Locality of the file.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetLocalityFromKey)(
        _In_reads_bytes_(fontFileReferenceKeySize) void const* fontFileReferenceKey,
        UINT32 fontFileReferenceKeySize,
        _Out_ DWRITE_LOCALITY* locality
        ) PURE;

    /// <summary>
    /// Creates a font file reference from a URL if the loader supports this capability.
    /// </summary>
    /// <param name="factory">Factory used to create the font file reference.</param>
    /// <param name="baseUrl">Optional base URL. The base URL is used to resolve the fontFileUrl
    /// if it is relative. For example, the baseUrl might be the URL of the referring document
    /// that contained the fontFileUrl.</param>
    /// <param name="fontFileUrl">URL of the font resource.</param>
    /// <param name="fontFile">Receives a pointer to the newly created font file reference.</param>
    /// <returns>
    /// Standard HRESULT error code, or E_NOTIMPL if the loader does not implement this method.
    /// </returns>
    STDMETHOD(CreateFontFileReferenceFromUrl)(
        IDWriteFactory* factory,
        _In_opt_z_ WCHAR const* baseUrl,
        _In_z_ WCHAR const* fontFileUrl,
        _COM_Outptr_ IDWriteFontFile** fontFile
        ) PURE;
};


/// <summary>
/// The IDWriteInMemoryFontFileLoader interface enables clients to reference
/// in-memory fonts without having to implement a custom loader. The 
/// IDWriteFactory5::CreateInMemoryFontFileLoader method returns an instance
/// of this interface, which the client is responsible for registering and
/// unregistering using IDWriteFactory::RegisterFontFileLoader and 
/// IDWriteFactory::UnregisterFontFileLoader.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("DC102F47-A12D-4B1C-822D-9E117E33043F") IDWriteInMemoryFontFileLoader : public IDWriteFontFileLoader
{
    /// <summary>
    /// The CreateInMemoryFontFileReference method creates a font file reference
    /// (IDWriteFontFile object) from an array of bytes. The font file reference
    /// is bound to the IDWriteInMemoryFontFileLoader instance with which it was
    /// created and remains valid for as long as that loader is registered with
    /// the factory.
    /// </summary>
    /// <param name="factory">Factory object used to create the font file reference.</param>
    /// <param name="fontData">Pointer to a memory block containing the font data.</param>
    /// <param name="fontDataSize">Size of the font data.</param>
    /// <param name="ownerObject">Optional object that owns the memory specified by
    /// the fontData parameter. If this parameter is not NULL, the method stores a
    /// pointer to the font data and adds a reference to the owner object. The
    /// fontData pointer must remain valid until the owner object is released. If
    /// this parameter is NULL, the method makes a copy of the font data.</param>
    /// <param name="fontFile">Receives a pointer to the newly-created font file
    /// reference.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateInMemoryFontFileReference)(
        IDWriteFactory* factory,
        _In_reads_bytes_(fontDataSize) void const* fontData,
        UINT32 fontDataSize,
        _In_opt_ IUnknown* ownerObject,
        _COM_Outptr_ IDWriteFontFile** fontFile
        ) PURE;

    /// <summary>
    /// The GetFileCount method returns the number of font file references that
    /// have been created using this loader instance.
    /// </summary>
    STDMETHOD_(UINT32, GetFileCount)() PURE;
};


/// <summary>
/// The root factory interface for all DWrite objects.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("958DB99A-BE2A-4F09-AF7D-65189803D1D3") IDWriteFactory5 : public IDWriteFactory4
{
    /// <summary>
    /// Creates an empty font set builder to add font face references
    /// and create a custom font set.
    /// </summary>
    /// <param name="fontSetBuilder">Receives a pointer to the newly created font set builder object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontSetBuilder)(
        _COM_Outptr_ IDWriteFontSetBuilder1** fontSetBuilder
        ) PURE;

    using IDWriteFactory3::CreateFontSetBuilder;

    /// <summary>
    /// The CreateInMemoryFontFileLoader method creates a loader object that can
    /// be used to create font file references to in-memory fonts. The caller is 
    /// responsible for registering and unregistering the loader.
    /// </summary>
    /// <param name="newLoader">Receives a pointer to the newly-created loader object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateInMemoryFontFileLoader)(
        _COM_Outptr_ IDWriteInMemoryFontFileLoader** newLoader
        ) PURE;

    /// <summary>
    /// The CreateHttpFontFileLoader function creates a remote font file loader 
    /// that can create font file references from HTTP or HTTPS URLs. The caller
    /// is responsible for registering and unregistering the loader.
    /// </summary>
    /// <param name="referrerUrl">Optional referrer URL for HTTP requests.</param>
    /// <param name="extraHeaders">Optional additional header fields to include 
    /// in HTTP requests. Each header field consists of a name followed by a colon
    /// (":") and the field value, as specified by RFC 2616. Multiple header fields 
    /// may be separated by newlines.</param>
    /// <param name="newLoader">Receives a pointer to the newly-created loader object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateHttpFontFileLoader)(
        _In_opt_z_ wchar_t const* referrerUrl,
        _In_opt_z_ wchar_t const* extraHeaders,
        _COM_Outptr_ IDWriteRemoteFontFileLoader** newLoader
        ) PURE;

    /// <summary>
    /// The AnalyzeContainerType method analyzes the specified file data to determine
    /// whether it is a known font container format (e.g., WOFF or WOFF2).
    /// </summary>
    /// <returns>
    /// Returns the container type if recognized. DWRITE_CONTAINER_TYPE_UNKOWNN is
    /// returned for all other files, including uncompressed font files.
    /// </returns>
    STDMETHOD_(DWRITE_CONTAINER_TYPE, AnalyzeContainerType)(
        _In_reads_bytes_(fileDataSize) void const* fileData,
        UINT32 fileDataSize
        ) PURE;

    /// <summary>
    /// The UnpackFontFile method unpacks font data from a container file (WOFF or
    /// WOFF2) and returns the unpacked font data in the form of a font file stream.
    /// </summary>
    /// <param name="containerType">Container type returned by AnalyzeContainerType.</param>
    /// <param name="fileData">Pointer to the compressed data.</param>
    /// <param name="fileDataSize">Size of the compressed data, in bytes.</param>
    /// <param name="unpackedFontStream">Receives a pointer to a newly created font
    /// file stream containing the uncompressed data.</param>
    /// <returns>
    /// Standard HRESULT error code. The return value is E_INVALIDARG if the container
    /// type is DWRITE_CONTAINER_TYPE_UNKNOWN.
    /// </returns>
    STDMETHOD(UnpackFontFile)(
        DWRITE_CONTAINER_TYPE containerType,
        _In_reads_bytes_(fileDataSize) void const* fileData,
        UINT32 fileDataSize,
        _COM_Outptr_ IDWriteFontFileStream** unpackedFontStream
        ) PURE;
};

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS2


////////////////////////////////////////////////////////////////////////////////////////////////////


#if NTDDI_VERSION >= NTDDI_WIN10_RS3


interface IDWriteFontResource;
interface IDWriteFontFace5;
interface IDWriteFontFaceReference1;
interface IDWriteFontSet1;
interface IDWriteFontCollection2;
interface IDWriteTextFormat3;
interface IDWriteFontSetBuilder2;


/// <summary>
/// Creates an OpenType tag for a font axis.
/// </summary>
#define DWRITE_MAKE_FONT_AXIS_TAG(a,b,c,d) (static_cast<DWRITE_FONT_AXIS_TAG>(DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)))


/// <summary>
/// Four character identifier for a font axis.
/// </summary>
/// <remarks>
/// Use DWRITE_MAKE_FONT_AXIS_TAG() to create a custom one.
/// <remarks>
enum DWRITE_FONT_AXIS_TAG : UINT32
{
    DWRITE_FONT_AXIS_TAG_WEIGHT         = DWRITE_MAKE_FONT_AXIS_TAG('w','g','h','t'),
    DWRITE_FONT_AXIS_TAG_WIDTH          = DWRITE_MAKE_FONT_AXIS_TAG('w','d','t','h'),
    DWRITE_FONT_AXIS_TAG_SLANT          = DWRITE_MAKE_FONT_AXIS_TAG('s','l','n','t'),
    DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE   = DWRITE_MAKE_FONT_AXIS_TAG('o','p','s','z'),
    DWRITE_FONT_AXIS_TAG_ITALIC         = DWRITE_MAKE_FONT_AXIS_TAG('i','t','a','l'),
};


/// <summary>
/// Value for a font axis, used when querying and creating font instances.
/// </summary>
struct DWRITE_FONT_AXIS_VALUE
{
    /// <summary>
    /// Four character identifier of the font axis (weight, width, slant, italic...).
    /// </summary>
    DWRITE_FONT_AXIS_TAG axisTag;

    /// <summary>
    /// Value for the given axis, with the meaning and range depending on the axis semantics.
    /// Certain well known axes have standard ranges and defaults, such as weight (1..1000, default=400),
    /// width (>0, default=100), slant (-90..90, default=-20), and italic (0 or 1).
    /// </summary>
    FLOAT value;
};


/// <summary>
/// Minimum and maximum range of a font axis.
/// </summary>
struct DWRITE_FONT_AXIS_RANGE
{
    /// <summary>
    /// Four character identifier of the font axis (weight, width, slant, italic...).
    /// </summary>
    DWRITE_FONT_AXIS_TAG axisTag;

    /// <summary>
    /// Minimum value supported by this axis.
    /// </summary>
    FLOAT minValue;

    /// <summary>
    /// Maximum value supported by this axis. The maximum can equal the minimum.
    /// </summary>
    FLOAT maxValue;
};


/// <summary>
/// How font families are grouped together, used by IDWriteFontCollection.
/// </summary>
enum DWRITE_FONT_FAMILY_MODEL
{
    /// <summary>
    /// Families are grouped by the typographic family name preferred by the font author. The family can contain as
    /// many face as the font author wants.
    /// This corresponds to the DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME.
    /// </summary>
    DWRITE_FONT_FAMILY_MODEL_TYPOGRAPHIC,

    /// <summary>
    /// Families are grouped by the weight-stretch-style family name, where all faces that differ only by those three
    /// axes are grouped into the same family, but any other axes go into a distinct family. For example, the Sitka
    /// family with six different optical sizes yields six separate families (Sitka Caption, Display, Text, Subheading,
    /// Heading, Banner...). This corresponds to the DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME.
    /// </summary>
    DWRITE_FONT_FAMILY_MODEL_WEIGHT_STRETCH_STYLE,
};


/// <summary>
/// Apply certain axes automatically in layout during font selection.
/// </summary>
enum DWRITE_AUTOMATIC_FONT_AXES
{
    /// <summary>
    /// No axes are automatically applied.
    /// </summary>
    DWRITE_AUTOMATIC_FONT_AXES_NONE         = 0x0000,

    /// <summary>
    /// Automatically pick an appropriate optical value based on the font size (via SetFontSize) when no value is
    /// specified via DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE. Callers can still explicitly apply the 'opsz' value over
    /// text ranges via SetFontAxisValues, which take priority.
    /// </summary>
    DWRITE_AUTOMATIC_FONT_AXES_OPTICAL_SIZE = 0x0001,
};

#ifdef DEFINE_ENUM_FLAG_OPERATORS
DEFINE_ENUM_FLAG_OPERATORS(DWRITE_AUTOMATIC_FONT_AXES);
#endif


/// <summary>
/// Attributes for a font axis.
/// </summary>
enum DWRITE_FONT_AXIS_ATTRIBUTES
{
    /// <summary>
    /// No attributes.
    /// </summary>
    DWRITE_FONT_AXIS_ATTRIBUTES_NONE     = 0x0000,

    /// <summary>
    /// This axis is implemented as a variation axis in a variable font, with a continuous range of
    /// values, such as a range of weights from 100..900. Otherwise it is either a static axis that
    /// holds a single point, or it has a range but doesn't vary, such as optical size in the Skia
    /// Heading font which covers a range of points but doesn't interpolate any new glyph outlines.
    /// </summary>
    DWRITE_FONT_AXIS_ATTRIBUTES_VARIABLE = 0x0001,

    /// <summary>
    /// This axis is recommended to be remain hidden in user interfaces. The font developer may
    /// recommend this if an axis is intended to be accessed only programmatically, or is meant for
    /// font-internal or font-developer use only. The axis may be exposed in lower-level font
    /// inspection utilities, but should not be exposed in common or even advanced-mode user
    /// interfaces in content-authoring apps.
    /// </summary>
    DWRITE_FONT_AXIS_ATTRIBUTES_HIDDEN   = 0x0002,
};

#ifdef DEFINE_ENUM_FLAG_OPERATORS
DEFINE_ENUM_FLAG_OPERATORS(DWRITE_FONT_AXIS_ATTRIBUTES);
#endif


interface DWRITE_DECLARE_INTERFACE("F3744D80-21F7-42EB-B35D-995BC72FC223") IDWriteFactory6 : public IDWriteFactory5
{
    /// <summary>
    /// Creates a reference to a specific font instance within a file.
    /// </summary>
    /// <param name="fontFile">User provided font file representing the font face.</param>
    /// <param name="faceIndex">The zero based index of a font face in cases when the font files contain a collection of font faces.
    /// If the font files contain a single face, this value should be zero.</param>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontFaceReference)(
        _In_ IDWriteFontFile* fontFile,
        UINT32 faceIndex,
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontFaceReference1** fontFaceReference
        ) PURE;

    using IDWriteFactory5::CreateFontFaceReference;

    /// <summary>
    /// Creates a font resource given a font file and face index.
    /// </summary>
    /// <param name="fontFile">User provided font file representing the font face.</param>
    /// <param name="faceIndex">The zero based index of a font face in cases when the font files contain a collection of font faces.
    /// If the font files contain a single face, this value should be zero.</param>
    /// <param name="fontResource">Receives a pointer to the newly created font resource object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontResource)(
        _In_ IDWriteFontFile* fontFile,
        UINT32 faceIndex,
        _COM_Outptr_ IDWriteFontResource** fontResource
        ) PURE;

    /// <summary>
    /// Retrieves the set of system fonts.
    /// </summary>
    /// <param name="includeDownloadableFonts">Include downloadable fonts or only locally installed ones.</param>
    /// <param name="fontSet">Receives a pointer to the font set object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontSet)(
        BOOL includeDownloadableFonts,
        _COM_Outptr_ IDWriteFontSet1** fontSet
        ) PURE;

    using IDWriteFactory3::GetSystemFontSet;

    /// <summary>
    /// Retrieves a collection of fonts grouped into families.
    /// </summary>
    /// <param name="includeDownloadableFonts">Include downloadable fonts or only locally installed ones.</param>
    /// <param name="fontFamilyModel">How to group families in the collection.</param>
    /// <param name="fontCollection">Receives a pointer to the font collection object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontCollection)(
        BOOL includeDownloadableFonts,
        DWRITE_FONT_FAMILY_MODEL fontFamilyModel,
        _COM_Outptr_ IDWriteFontCollection2** fontCollection
        ) PURE;

    using IDWriteFactory3::GetSystemFontCollection;

    /// <summary>
    /// Create a collection of fonts grouped into families from a font set.
    /// </summary>
    /// <param name="fontSet">A set of fonts to use to build the collection.</param>
    /// <param name="fontFamilyModel">How to group families in the collection.</param>
    /// <param name="fontCollection">Receives a pointer to the newly created font collection object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontCollectionFromFontSet)(
        IDWriteFontSet* fontSet,
        DWRITE_FONT_FAMILY_MODEL fontFamilyModel,
        _COM_Outptr_ IDWriteFontCollection2** fontCollection
        ) PURE;

    using IDWriteFactory5::CreateFontCollectionFromFontSet;

    /// <summary>
    /// Creates an empty font set builder to add font instances and create a custom font set.
    /// </summary>
    /// <param name="fontSetBuilder">Receives a pointer to the newly created font set builder object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontSetBuilder)(
        _COM_Outptr_ IDWriteFontSetBuilder2** fontSetBuilder
        ) PURE;

    using IDWriteFactory3::CreateFontSetBuilder;
    using IDWriteFactory5::CreateFontSetBuilder;

    /// <summary>
    /// Create a text format object used for text layout.
    /// </summary>
    /// <param name="fontFamilyName">Name of the font family from the collection.</param>
    /// <param name="fontCollection">Font collection, with nullptr indicating the system font collection.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="fontSize">Logical size of the font in DIP units.</param>
    /// <param name="localeName">Locale name (e.g. "ja-JP", "en-US", "ar-EG").</param>
    /// <param name="textFormat">Receives a pointer to the newly created text format object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// If fontCollection is nullptr, the system font collection is used, grouped by typographic family name
    /// (DWRITE_FONT_FAMILY_MODEL_TYPOGRAPHIC) without downloadable fonts.
    /// </remarks>
    STDMETHOD(CreateTextFormat)(
        _In_z_ WCHAR const* fontFamilyName,
        _In_opt_ IDWriteFontCollection* fontCollection,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        FLOAT fontSize,
        _In_z_ WCHAR const* localeName,
        _COM_Outptr_ IDWriteTextFormat3** textFormat
        ) PURE;

    using IDWriteFactory::CreateTextFormat;
};


interface DWRITE_DECLARE_INTERFACE("98EFF3A5-B667-479A-B145-E2FA5B9FDC29") IDWriteFontFace5 : public IDWriteFontFace4
{
    /// <summary>
    /// Get the number of axes defined by the font. This includes both static and variable axes.
    /// </summary>
    STDMETHOD_(UINT32, GetFontAxisValueCount)() PURE;

    /// <summary>
    /// Get the list of axis values used by the font.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Maximum number of font axis values to write.</param>
    /// <returns>
    /// Standard HRESULT error code, or E_INVALIDARG if fontAxisValueCount doesn't match GetFontAxisValueCount.
    /// </returns>
    /// <remarks>
    /// The values are returned in the canonical order defined by the font, clamped to the actual range supported,
    /// not specifically the same axis value array passed to CreateFontFace.
    /// </remarks>
    STDMETHOD(GetFontAxisValues)(
        _Out_writes_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE* fontAxisValues,
        UINT32 fontAxisValueCount
        ) PURE;

    /// <summary>
    /// Whether this font's resource supports any variable axes. When true, at least one DWRITE_FONT_AXIS_RANGE
    /// in the font resource has a non-empty range (maximum > minimum).
    /// </summary>
    STDMETHOD_(BOOL, HasVariations)() PURE;

    /// <summary>
    /// Get the underlying font resource for this font face. A caller can use that to query information on the resource
    /// or recreate a new font face instance with different axis values.
    /// </summary>
    /// <param name="fontResource">Newly created font resource object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontResource)(
        _COM_Outptr_ IDWriteFontResource** fontResource
        ) PURE;

    /// <summary>
    /// Compares two instances of a font face for equality.
    /// </summary>
    STDMETHOD_(BOOL, Equals)(IDWriteFontFace* fontFace) PURE;
};


/// <summary>
/// Interface to return axis information for a font resource and create specific font face instances.
/// </summary>
interface DWRITE_DECLARE_INTERFACE("1F803A76-6871-48E8-987F-B975551C50F2") IDWriteFontResource : public IUnknown
{
    /// <summary>
    /// Get the font file of the resource.
    /// </summary>
    /// <param name="fontFile">Receives a pointer to the font file.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFile)(
        _COM_Outptr_ IDWriteFontFile** fontFile
        ) PURE;

    /// <summary>
    /// Obtains the zero-based index of the font face in its font file. If the font files contain a single face,
    /// the return value is zero.
    /// </summary>
    STDMETHOD_(UINT32, GetFontFaceIndex)() PURE;

    /// <summary>
    /// Get the number of axes supported by the font resource. This includes both static and variable axes.
    /// </summary>
    STDMETHOD_(UINT32, GetFontAxisCount)() PURE;

    /// <summary>
    /// Get the default values for all axes supported by the font resource.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Maximum number of font axis values to write.</param>
    /// <remarks>
    /// Different font resources may have different defaults.
    /// For OpenType 1.8 fonts, these values come from the STAT and fvar tables.
    /// For older fonts without a STAT table, weight-width-slant-italic are read from the OS/2 table.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code, or E_INVALIDARG if fontAxisValueCount doesn't match GetFontAxisCount.
    /// </returns>
    STDMETHOD(GetDefaultFontAxisValues)(
        _Out_writes_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE* fontAxisValues,
        UINT32 fontAxisValueCount
        ) PURE;

    /// <summary>
    /// Get ranges of each axis.
    /// </summary>
    /// <param name="fontAxisRanges"></param>
    /// <param name="fontAxisRangeCount">Total number of axis ranges</param>
    /// <returns>
    /// Standard HRESULT error code, or E_INVALIDARG if fontAxisRangeCount doesn't match GetFontAxisCount.
    /// </returns>
    /// <remarks>
    /// Non-varying axes will have empty ranges (minimum==maximum).
    /// </remarks>
    STDMETHOD(GetFontAxisRanges)(
        _Out_writes_(fontAxisRangeCount) DWRITE_FONT_AXIS_RANGE* fontAxisRanges,
        UINT32 fontAxisRangeCount
        ) PURE;

    /// <summary>
    /// Gets attributes about the given axis, such as whether the font author recommends to hide the axis
    /// in user interfaces.
    /// </summary>
    /// <param name="axisIndex">Font axis, from 0 to GetFontAxisValueCount - 1.</param>
    /// <param name="axisAttributes">Receives the attributes for the given axis.</param>
    /// <returns>
    /// Attributes for a font axis, or NONE if axisIndex is beyond the font count.
    /// </returns>
    STDMETHOD_(DWRITE_FONT_AXIS_ATTRIBUTES, GetFontAxisAttributes)(
        UINT32 axisIndex
        ) PURE;

    /// <summary>
    /// Gets the localized names of a font axis.
    /// </summary>
    /// <param name="axisIndex">Font axis, from 0 to GetFontAxisCount - 1.</param>
    /// <param name="names">Receives a pointer to the newly created localized strings object.</param>
    /// <remarks>
    /// The font author may not have supplied names for some font axes. The localized strings
    /// will be empty in that case.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetAxisNames)(
        UINT32 axisIndex,
        _COM_Outptr_ IDWriteLocalizedStrings** names
        ) PURE;

    /// <summary>
    /// Get the number of named values for a specific axis.
    /// </summary>
    /// <param name="axisIndex">Font axis, from 0 to GetFontAxisCount - 1.</param>
    /// <returns>
    /// Number of named values.
    /// </returns>
    STDMETHOD_(UINT32, GetAxisValueNameCount)(
        UINT32 axisIndex
        ) PURE;

    /// <summary>
    /// Gets the localized names of specific values for a font axis.
    /// </summary>
    /// <param name="axisIndex">Font axis, from 0 to GetFontAxisCount - 1.</param>
    /// <param name="axisValueIndex">Value index, from 0 to GetAxisValueNameCount - 1.</param>
    /// <param name="fontAxisRange">Range of the named value.</param>
    /// <param name="names">Receives a pointer to the newly created localized strings object.</param>
    /// <remarks>
    /// The font author may not have supplied names for some font axis values. The localized strings
    /// will be empty in that case. The range may be a single point, where minimum == maximum.
    /// All ranges are in ascending order by axisValueIndex.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetAxisValueNames)(
        UINT32 axisIndex,
        UINT32 axisValueIndex,
        _Out_ DWRITE_FONT_AXIS_RANGE* fontAxisRange,
        _COM_Outptr_ IDWriteLocalizedStrings** names
        ) PURE;

    /// <summary>
    /// Whether this font's resource supports any variable axes. When true, at least one DWRITE_FONT_AXIS_RANGE
    /// in the font resource has a non-empty range (maximum > minimum).
    /// </summary>
    STDMETHOD_(BOOL, HasVariations)() PURE;

    /// <summary>
    /// Creates a font face instance with specific axis values.
    /// </summary>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="fontFace">Receives a pointer to the newly created font face object, or nullptr on failure.</param>
    /// <remarks>
    /// The passed input axis values are permitted to be a subset or superset of all the ones actually supported by
    /// the font. Any unspecified axes use their default values, values beyond the ranges are clamped, and any
    /// non-varying axes have no effect.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code, or DWRITE_E_REMOTEFONT if the face is not local.
    /// </returns>
    STDMETHOD(CreateFontFace)(
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontFace5** fontFace
        ) PURE;

    /// <summary>
    /// Creates a font face reference with specific axis values.
    /// </summary>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="fontFaceReference">Receives a pointer to the newly created font face reference object, or nullptr on failure.</param>
    /// <remarks>
    /// The passed input axis values are permitted to be a subset or superset of all the ones actually supported by
    /// the font. Any unspecified axes use their default values, values beyond the ranges are clamped, and any
    /// non-varying axes have no effect.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(CreateFontFaceReference)(
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontFaceReference1** fontFaceReference
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("C081FE77-2FD1-41AC-A5A3-34983C4BA61A") IDWriteFontFaceReference1 : public IDWriteFontFaceReference
{
    /// <summary>
    /// Creates a font face from the reference for use with layout, shaping, or rendering.
    /// </summary>
    /// <param name="fontFace">Newly created font face object, or nullptr in the case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// This function can fail with DWRITE_E_REMOTEFONT if the font is not local.
    /// </remarks>
    STDMETHOD(CreateFontFace)(
        _COM_Outptr_ IDWriteFontFace5** fontFace
        ) PURE;

    using IDWriteFontFaceReference::CreateFontFace;

    /// <summary>
    /// Get the number of axes specified by the reference.
    /// </summary>
    STDMETHOD_(UINT32, GetFontAxisValueCount)() PURE;

    /// <summary>
    /// Get the list of font axis values specified by the reference.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <returns>
    /// Standard HRESULT error code, or E_INVALIDARG if fontAxisValueCount doesn't match GetFontAxisValueCount.
    /// </returns>
    STDMETHOD(GetFontAxisValues)(
        _Out_writes_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE* fontAxisValues,
        UINT32 fontAxisValueCount
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("EE5BA612-B131-463C-8F4F-3189B9401E45") IDWriteFontSetBuilder2 : public IDWriteFontSetBuilder1
{
    /// <summary>
    /// Adds a font to the set being built, with the caller supplying enough information to search on
    /// and determine axis ranges, avoiding the need to open the potentially non-local font.
    /// </summary>
    /// <param name="fontFile">Font file reference object to add to the set.</param>
    /// <param name="faceIndex">The zero based index of a font face in a collection.</param>
    /// <param name="fontSimulations">Font face simulation flags for algorithmic emboldening and italicization.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="fontAxisRanges">List of axis ranges.</param>
    /// <param name="fontAxisRangeCount">Number of axis ranges.</param>
    /// <param name="properties">List of properties to associate with the reference.</param>
    /// <param name="propertyCount">How many properties are defined.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The font properties should include at least a family (typographic or weight/style/stretch).
    /// Otherwise the font would be accessible in the IDWriteFontSet only by index, not name.
    /// </returns>
    STDMETHOD(AddFont)(
        _In_ IDWriteFontFile* fontFile,
        UINT32 fontFaceIndex,
        DWRITE_FONT_SIMULATIONS fontSimulations,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _In_reads_(fontAxisRangeCount) DWRITE_FONT_AXIS_RANGE const* fontAxisRanges,
        UINT32 fontAxisRangeCount,
        _In_reads_(propertyCount) DWRITE_FONT_PROPERTY const* properties,
        UINT32 propertyCount
        ) PURE;

    /// <summary>
    /// Adds references to all the fonts in the specified font file. The method
    /// parses the font file to determine the fonts and their properties.
    /// </summary>
    /// <param name="filePath">Absolute file path to add to the font set.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(AddFontFile)(
        _In_z_ WCHAR const* filePath
        ) PURE;

    using IDWriteFontSetBuilder1::AddFontFile;
};


interface DWRITE_DECLARE_INTERFACE("7E9FDA85-6C92-4053-BC47-7AE3530DB4D3") IDWriteFontSet1 : public IDWriteFontSet
{
    /// <summary>
    /// Generates a matching font set based on the requested inputs, ordered so that nearer matches are earlier.
    /// </summary>
    /// <param name="property">Font property of interest, such as typographic family or weight/stretch/style family.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="matchingSet">Prioritized list of fonts that match the properties, or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// This can yield distinct items that were not in the original font set, including items with simulation flags
    /// (if they would be a closer match to the request) and instances that were not named by the font author.
    /// Items from the same font resources are collapsed into one, the closest possible match.
    /// </remarks>
    STDMETHOD(GetMatchingFonts)(
        _In_opt_ DWRITE_FONT_PROPERTY const* fontProperty,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontSet1** matchingFonts
        ) PURE;

    /// <summary>
    /// Returns a font set that contains only the first occurrence of each font resource in the given set.
    /// </summary>
    /// <param name="fontSet">New font set consisting of single default instances from font resources.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFirstFontResources)(
        _COM_Outptr_ IDWriteFontSet1** filteredFontSet
        ) PURE;

    /// <summary>
    /// Returns a subset of fonts filtered by the given properties.
    /// </summary>
    /// <param name="properties">List of properties to filter using.</param>
    /// <param name="propertyCount">How many properties to filter.</param>
    /// <param name="selectAnyProperty">Select any property rather rather than the intersection of them all.</param>
    /// <param name="filteredSet">Subset of fonts that match the properties, or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// If no fonts matched the filter, the returned subset will be empty (GetFontCount returns 0).
    /// The subset will always be equal to or less than the original set.
    /// </remarks>
    STDMETHOD(GetFilteredFonts)(
        _In_reads_opt_(propertyCount) DWRITE_FONT_PROPERTY const* properties,
        UINT32 propertyCount,
        BOOL selectAnyProperty,
        _COM_Outptr_ IDWriteFontSet1** filteredFontSet
        ) PURE;

    /// <summary>
    /// Returns a subset of fonts filtered by the given ranges, endpoint-inclusive.
    /// </summary>
    /// <param name="fontAxisRanges">List of axis ranges.</param>
    /// <param name="fontAxisRangeCount">Number of axis ranges.</param>
    /// <param name="selectAnyRange">Select any range rather rather than the intersection of them all.</param>
    /// <param name="filteredSet">Subset of fonts that fall within the ranges, or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// If no fonts matched the filter, the subset will be empty (GetFontCount returns 0), but the function does not
    /// return an error. The subset will always be equal to or less than the original set.
    /// </remarks>
    STDMETHOD(GetFilteredFonts)(
        _In_reads_(fontAxisRangeCount) DWRITE_FONT_AXIS_RANGE const* fontAxisRanges,
        UINT32 fontAxisRangeCount,
        BOOL selectAnyRange,
        _COM_Outptr_ IDWriteFontSet1** filteredFontSet
        ) PURE;

    /// <summary>
    /// Returns a subset of fonts filtered by the given indices.
    /// </summary>
    /// <param name="indices">Array of indices, each index from [0..GetFontCount() - 1].</param>
    /// <param name="indexCount">Number of indices.</param>
    /// <param name="filteredSet">Subset of fonts that come from the given indices, or nullptr on failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    /// <remarks>
    /// The indices can come in any order, meaning this function can produce a new set with items removed, duplicated,
    /// or reordered from the original. If zero indices were passed, an empty font set is returned.
    /// </remarks>
    STDMETHOD(GetFilteredFonts)(
        _In_reads_(indexCount) UINT32 const* indices,
        UINT32 indexCount,
        _COM_Outptr_ IDWriteFontSet1** filteredFontSet
        ) PURE;

    /// <summary>
    /// Get all the item indices filtered by the given properties.
    /// </summary>
    /// <param name="properties">List of properties to filter using.</param>
    /// <param name="propertyCount">How many properties to filter.</param>
    /// <param name="selectAnyProperty">Select any property rather rather than the intersection of them all.</param>
    /// <param name="indices">Ascending array of indices [0..GetFontCount() - 1].</param>
    /// <param name="indexCount">Number of indices.</param>
    /// <param name="actualIndexCount">Actual number of indices written or needed [0..GetFontCount()-1].</param>
    /// <returns>
    /// E_NOT_SUFFICIENT_BUFFER if the buffer is too small, with actualIndexCount set to the needed size.
    /// The actualIndexCount will always be <= IDwriteFontSet::GetFontCount.
    /// </returns>
    STDMETHOD(GetFilteredFontIndices)(
        _In_reads_(propertyCount) DWRITE_FONT_PROPERTY const* properties,
        UINT32 propertyCount,
        BOOL selectAnyProperty,
        _Out_writes_(maxIndexCount) UINT32* indices,
        UINT32 maxIndexCount,
        _Out_ UINT32* actualIndexCount
        ) PURE;

    /// <summary>
    /// Get all the item indices filtered by the given ranges.
    /// </summary>
    /// <param name="fontAxisRanges">List of axis ranges.</param>
    /// <param name="fontAxisRangeCount">Number of axis ranges.</param>
    /// <param name="selectAnyRange">Select any property rather rather than the intersection of them all.</param>
    /// <param name="indices">Ascending array of indices [0..GetFontCount() - 1].</param>
    /// <param name="indexCount">Number of indices.</param>
    /// <param name="actualIndexCount">Actual number of indices written or needed [0..GetFontCount()-1].</param>
    /// <returns>
    /// E_NOT_SUFFICIENT_BUFFER if the buffer is too small, with actualIndexCount set to the needed size.
    /// </returns>
    STDMETHOD(GetFilteredFontIndices)(
        _In_reads_(fontAxisRangeCount) DWRITE_FONT_AXIS_RANGE const* fontAxisRanges,
        UINT32 fontAxisRangeCount,
        BOOL selectAnyRange,
        _Out_writes_(maxIndexCount) UINT32* indices,
        UINT32 maxIndexCount,
        _Out_ UINT32* actualIndexCount
        ) PURE;

    /// <summary>
    /// Gets all axis ranges in the font set, the union of all contained items.
    /// </summary>
    /// <param name="fontAxisRanges">List of axis ranges.</param>
    /// <param name="fontAxisRangeCount">Number of axis ranges.</param>
    /// <param name="actualFontAxisRangeCount">Actual number of axis ranges written or needed.</param>
    /// <returns>
    /// E_NOT_SUFFICIENT_BUFFER if the buffer is too small, with actualFontAxisRangeCount set to the needed size.
    /// </returns>
    STDMETHOD(GetFontAxisRanges)(
        _Out_writes_(maxFontAxisRangeCount) DWRITE_FONT_AXIS_RANGE* fontAxisRanges,
        UINT32 maxFontAxisRangeCount,
        _Out_ UINT32* actualFontAxisRangeCount
        ) PURE;

    /// <summary>
    /// Get the axis ranges of a single item.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font in the set.</param>
    /// <param name="fontAxisRanges">List of axis ranges.</param>
    /// <param name="fontAxisRangeCount">Number of axis ranges.</param>
    /// <param name="actualFontAxisRangeCount">Actual number of axis ranges written or needed.</param>
    /// <returns>
    /// E_NOT_SUFFICIENT_BUFFER if the buffer is too small, with actualFontAxisRangeCount set to the needed size.
    /// </returns>
    STDMETHOD(GetFontAxisRanges)(
        UINT32 listIndex,
        _Out_writes_(maxFontAxisRangeCount) DWRITE_FONT_AXIS_RANGE* fontAxisRanges,
        UINT32 maxFontAxisRangeCount,
        _Out_ UINT32* actualFontAxisRangeCount
        ) PURE;

    /// <summary>
    /// Get the font face reference of a single item.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font item in the set.</param>
    /// <param name="fontFaceReference">Receives a pointer to the font face reference.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFaceReference)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontFaceReference1** fontFaceReference
        ) PURE;

    using IDWriteFontSet::GetFontFaceReference;

    /// <summary>
    /// Create the font resource of a single item.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font item in the set.</param>
    /// <param name="fontResource">Receives a pointer to the font resource.</param>
    /// <returns>
    /// Standard HRESULT error code, or DWRITE_E_REMOTEFONT if the file is not local.
    /// </returns>
    STDMETHOD(CreateFontResource)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontResource** fontResource
        ) PURE;

    /// <summary>
    /// Create a font face for a single item (rather than going through the font face reference).
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font item in the set.</param>
    /// <param name="fontFile">Receives a pointer to the font face.</param>
    /// <returns>
    /// Standard HRESULT error code, or DWRITE_E_REMOTEFONT if the file is not local.
    /// </returns>
    STDMETHOD(CreateFontFace)(
        UINT32 listIndex,
        _COM_Outptr_ IDWriteFontFace5** fontFace
        ) PURE;

    /// <summary>
    /// Return the locality of a single item.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font item in the set.</param>
    /// <remarks>
    /// The locality enumeration. For fully local files, the result will always
    /// be DWRITE_LOCALITY_LOCAL. For downloadable files, the result depends on how
    /// much of the file has been downloaded.
    /// </remarks>
    /// <returns>
    /// The locality enumeration.
    /// </returns>
    STDMETHOD_(DWRITE_LOCALITY, GetFontLocality)(UINT32 listIndex) PURE;
};


interface DWRITE_DECLARE_INTERFACE("C0763A34-77AF-445A-B735-08C37B0A5BF5") IDWriteFontList2 : public IDWriteFontList1
{
    /// <summary>
    /// Get the underlying font set used by this list.
    /// </summary>
    /// <param name="fontSet">Contains font set used by the list.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSet)(
        _COM_Outptr_ IDWriteFontSet1** fontSet
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("3ED49E77-A398-4261-B9CF-C126C2131EF3") IDWriteFontFamily2 : public IDWriteFontFamily1
{
    /// <summary>
    /// Gets a list of fonts in the font family ranked in order of how well they match the specified axis values.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="matchingFonts">Receives a pointer to the newly created font list object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetMatchingFonts)(
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontList2** matchingFonts
        ) PURE;

    using IDWriteFontFamily::GetMatchingFonts;

    /// <summary>
    /// Get the underlying font set used by this family.
    /// </summary>
    /// <param name="fontSet">Contains font set used by the family.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSet)(
        _COM_Outptr_ IDWriteFontSet1** fontSet
        ) PURE;
};


interface DWRITE_DECLARE_INTERFACE("514039C6-4617-4064-BF8B-92EA83E506E0") IDWriteFontCollection2 : public IDWriteFontCollection1
{
    /// <summary>
    /// Creates a font family object given a zero-based font family index.
    /// </summary>
    /// <param name="index">Zero-based index of the font family.</param>
    /// <param name="fontFamily">Receives a pointer the newly created font family object.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontFamily)(
        UINT32 index,
        _COM_Outptr_ IDWriteFontFamily2** fontFamily
        ) PURE;

    /// <summary>
    /// Gets a list of fonts in the specified font family ranked in order of how well they match the specified axis values.
    /// </summary>
    /// <param name="familyName">Name of the font family. The name is not case-sensitive but must otherwise exactly match a family name in the collection.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="matchingFonts">Receives a pointer to the newly created font list object.</param>
    /// <remarks>
    /// If no fonts matched, the list will be empty (GetFontCount returns 0),
    /// but the function does not return an error.
    /// </remarks>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetMatchingFonts)(
        _In_z_ WCHAR const* familyName,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _COM_Outptr_ IDWriteFontList2** fontList
        ) PURE;

    /// <summary>
    /// Get the font family model used by the font collection to group families.
    /// </summary>
    /// <returns>
    /// Family model enumeration.
    /// </returns>
    STDMETHOD_(DWRITE_FONT_FAMILY_MODEL, GetFontFamilyModel)() PURE;

    /// <summary>
    /// Get the underlying font set used by this collection.
    /// </summary>
    /// <param name="fontSet">Contains font set used by the collection.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSet)(
        _COM_Outptr_ IDWriteFontSet1** fontSet
        ) PURE;

    using IDWriteFontCollection::GetFontFamily;
    using IDWriteFontCollection1::GetFontFamily;
    using IDWriteFontCollection1::GetFontSet;
};


interface DWRITE_DECLARE_INTERFACE("05A9BF42-223F-4441-B5FB-8263685F55E9") IDWriteTextLayout4 : public IDWriteTextLayout3
{
    /// <summary>
    /// Set values for font axes over a range of text.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetFontAxisValues)(
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        DWRITE_TEXT_RANGE textRange
        ) PURE;

    /// <summary>
    /// Get the number of axes set on the text position.
    /// </summary>
    STDMETHOD_(UINT32, GetFontAxisValueCount)(
        UINT32 currentPosition
        ) PURE;

    /// <summary>
    /// Get the list of font axis values on the text position.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Maximum number of font axis values to write.</param>
    /// <returns>
    /// Standard HRESULT error code, or E_INVALIDARG if fontAxisValueCount doesn't match GetFontAxisValueCount.
    /// </returns>
    STDMETHOD(GetFontAxisValues)(
        UINT32 currentPosition,
        _Out_writes_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE* fontAxisValues,
        UINT32 fontAxisValueCount,
        _Out_opt_ DWRITE_TEXT_RANGE* textRange = nullptr
        ) PURE;

    /// <summary>
    /// Get the automatic axis options.
    /// </summary>
    /// <returns>
    /// Automatic axis options.
    /// </returns>
    STDMETHOD_(DWRITE_AUTOMATIC_FONT_AXES, GetAutomaticFontAxes)() PURE;

    /// <summary>
    /// Sets the automatic font axis options.
    /// </summary>
    /// <param name="automaticFontAxes">Automatic font axis options.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetAutomaticFontAxes)(DWRITE_AUTOMATIC_FONT_AXES automaticFontAxes) PURE;
};


interface DWRITE_DECLARE_INTERFACE("6D3B5641-E550-430D-A85B-B7BF48A93427") IDWriteTextFormat3 : public IDWriteTextFormat2
{
    /// <summary>
    /// Set values for font axes of the format.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetFontAxisValues)(
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount
        ) PURE;

    /// <summary>
    /// Get the number of axes set on the format.
    /// </summary>
    STDMETHOD_(UINT32, GetFontAxisValueCount)() PURE;

    /// <summary>
    /// Get the list of font axis values on the format.
    /// </summary>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Maximum number of font axis values to write.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontAxisValues)(
        _Out_writes_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE* fontAxisValues,
        UINT32 fontAxisValueCount
        ) PURE;

    /// <summary>
    /// Get the automatic axis options.
    /// </summary>
    /// <returns>
    /// Automatic axis options.
    /// </returns>
    STDMETHOD_(DWRITE_AUTOMATIC_FONT_AXES, GetAutomaticFontAxes)() PURE;

    /// <summary>
    /// Sets the automatic font axis options.
    /// </summary>
    /// <param name="automaticFontAxes">Automatic font axis options.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(SetAutomaticFontAxes)(DWRITE_AUTOMATIC_FONT_AXES automaticFontAxes) PURE;
};


interface DWRITE_DECLARE_INTERFACE("2397599D-DD0D-4681-BD6A-F4F31EAADE77") IDWriteFontFallback1 : public IDWriteFontFallback
{
    /// <summary>
    /// Determines an appropriate font to use to render the range of text.
    /// </summary>
    /// <param name="source">The text source implementation holds the text and locale.</param>
    /// <param name="textLength">Length of the text to analyze.</param>
    /// <param name="baseFontCollection">Default font collection to use.</param>
    /// <param name="baseFamilyName">Family name of the base font. If you pass nullptr, no matching will be done against
    /// the base family.</param>
    /// <param name="fontAxisValues">List of font axis values.</param>
    /// <param name="fontAxisValueCount">Number of font axis values.</param>
    /// <param name="mappedLength">Length of text mapped to the mapped font. This will always be less or equal to the
    /// input text length and greater than zero (if the text length is non-zero) so that the caller advances at
    /// least one character each call.</param>
    /// <param name="mappedFontFace">The font face that should be used to render the first mappedLength characters of the text.
    /// If it returns null, then no known font can render the text, and mappedLength is the number of unsupported
    /// characters to skip.</param>
    /// <param name="scale">Scale factor to multiply the em size of the returned font by.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(MapCharacters)(
        IDWriteTextAnalysisSource* analysisSource,
        UINT32 textPosition,
        UINT32 textLength,
        _In_opt_ IDWriteFontCollection* baseFontCollection,
        _In_opt_z_ WCHAR const* baseFamilyName,
        _In_reads_(fontAxisValueCount) DWRITE_FONT_AXIS_VALUE const* fontAxisValues,
        UINT32 fontAxisValueCount,
        _Deref_out_range_(0, textLength) UINT32* mappedLength,
        _Out_ FLOAT* scale,
        _COM_Outptr_ IDWriteFontFace5** mappedFontFace
        ) PURE;

    using IDWriteFontFallback::MapCharacters;
};

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS3

#if NTDDI_VERSION >= NTDDI_WIN10_RS4

interface DWRITE_DECLARE_INTERFACE("DC7EAD19-E54C-43AF-B2DA-4E2B79BA3F7F") IDWriteFontSet2 : public IDWriteFontSet1
{
    /// <summary>
    /// Gets the expiration event for the font set, if any. The expiration event is set on a system font set object if
    /// it is out of date due to fonts being installed, uninstalled, or updated. The client should handle the event by
    /// getting a new system font set.
    /// </summary>
    /// <returns>
    /// Returns an event handle if called on the system font set, or nullptr if called on a custom font set.
    /// </returns>
    /// <remarks>
    /// The client must not call CloseHandle on the returned event handle. The handle is owned by the font set 
    /// object, and remains valid as long as the client holds a reference to the font set. The client can wait
    /// on the returned event or use RegisterWaitForSingleObject to request a callback when the event is set.
    /// </remarks>
    STDMETHOD_(HANDLE, GetExpirationEvent)() PURE;
};

interface DWRITE_DECLARE_INTERFACE("A4D055A6-F9E3-4E25-93B7-9E309F3AF8E9") IDWriteFontCollection3 : public IDWriteFontCollection2
{
    /// <summary>
    /// Gets the expiration event for the font collection, if any. The expiration event is set on a system font 
    /// collection object if it is out of date due to fonts being installed, uninstalled, or updated. The client 
    /// should handle the event by getting a new system font collection.
    /// </summary>
    /// <returns>
    /// Returns an event handle if called on the system font collection, or nullptr if called on a custom font 
    /// collection.
    /// </returns>
    /// <remarks>
    /// The client must not call CloseHandle on the returned event handle. The handle is owned by the font collection 
    /// object, and remains valid as long as the client holds a reference to the font collection. The client can wait
    /// on the returned event or use RegisterWaitForSingleObject to request a callback when the event is set.
    /// </remarks>
    STDMETHOD_(HANDLE, GetExpirationEvent)() PURE;
};

interface DWRITE_DECLARE_INTERFACE("35D0E0B3-9076-4D2E-A016-A91B568A06B4") IDWriteFactory7 : public IDWriteFactory6
{
    /// <summary>
    /// Retrieves the set of system fonts.
    /// </summary>
    /// <param name="includeDownloadableFonts">Include downloadable fonts or only locally installed ones.</param>
    /// <param name="fontSet">Receives a pointer to the font set object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontSet)(
        BOOL includeDownloadableFonts,
        _COM_Outptr_ IDWriteFontSet2** fontSet
        ) PURE;

    using IDWriteFactory6::GetSystemFontSet;

    /// <summary>
    /// Retrieves a collection of fonts grouped into families.
    /// </summary>
    /// <param name="includeDownloadableFonts">Include downloadable fonts or only locally installed ones.</param>
    /// <param name="fontFamilyModel">How to group families in the collection.</param>
    /// <param name="fontCollection">Receives a pointer to the font collection object, or nullptr in case of failure.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetSystemFontCollection)(
        BOOL includeDownloadableFonts,
        DWRITE_FONT_FAMILY_MODEL fontFamilyModel,
        _COM_Outptr_ IDWriteFontCollection3** fontCollection
        ) PURE;

    using IDWriteFactory6::GetSystemFontCollection;
};

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS4

#if NTDDI_VERSION >= NTDDI_WIN10_RS5

/// <summary>
/// The font source type identifies the mechanism by which a font came to be included in a font set.
/// </summary>
enum DWRITE_FONT_SOURCE_TYPE
{
    /// <summary>
    /// The font source is unknown or is not any of the other defined font source types.
    /// </summary>
    DWRITE_FONT_SOURCE_TYPE_UNKNOWN,

    /// <summary>
    /// The font source is a font file, which is installed for all users on the device.
    /// </summary>
    DWRITE_FONT_SOURCE_TYPE_PER_MACHINE,

    /// <summary>
    /// The font source is a font file, which is installed for the current user.
    /// </summary>
    DWRITE_FONT_SOURCE_TYPE_PER_USER,

    /// <summary>
    /// The font source is an APPX package, which includes one or more font files.
    /// The font source name is the full name of the package.
    /// </summary>
    DWRITE_FONT_SOURCE_TYPE_APPX_PACKAGE,

    /// <summary>
    /// The font source is a font provider for downloadable fonts.
    /// </summary>
    DWRITE_FONT_SOURCE_TYPE_REMOTE_FONT_PROVIDER
};

interface DWRITE_DECLARE_INTERFACE("7C073EF2-A7F4-4045-8C32-8AB8AE640F90") IDWriteFontSet3 : public IDWriteFontSet2
{
    /// <summary>
    /// Gets the font source type of the specified font.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font.</param>
    STDMETHOD_(DWRITE_FONT_SOURCE_TYPE, GetFontSourceType)(UINT32 fontIndex) PURE;

    /// <summary>
    /// Gets the length of the font source name for the specified font.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font.</param>
    STDMETHOD_(UINT32, GetFontSourceNameLength)(UINT32 listIndex) PURE;

    /// <summary>
    /// Copies the font source name for the specified font to an output array.
    /// </summary>
    /// <param name="listIndex">Zero-based index of the font.</param>
    /// <param name="stringBuffer">Character array that receives the string.</param>
    /// <param name="stringBufferSize">Size of the array in characters. The size must include space for the terminating
    /// null character.</param>
    /// <returns>
    /// Standard HRESULT error code.
    /// </returns>
    STDMETHOD(GetFontSourceName)(
        UINT32 listIndex, 
        _Out_writes_z_(stringBufferSize) WCHAR* stringBuffer, 
        UINT32 stringBufferSize
        ) PURE;
};

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS5

#endif // DWRITE_3_H_INCLUDED
