/**************************************************************************\
*
* Copyright (c) 1998-2001, Microsoft Corp.  All Rights Reserved.
*
* Module Name:
*
*   GdiplusFlat.h
*
* Abstract:
*
*   Private GDI+ header file.
*
\**************************************************************************/

#ifndef _FLATAPI_H
#define _FLATAPI_H

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define WINGDIPAPI __stdcall

#define GDIPCONST const

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------------------------------
// GraphicsPath APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreatePath(GpFillMode brushMode, GpPath **path);

GpStatus WINGDIPAPI
GdipCreatePath2(GDIPCONST GpPointF*, GDIPCONST BYTE*, INT, GpFillMode,
                                    GpPath **path);

GpStatus WINGDIPAPI
GdipCreatePath2I(GDIPCONST GpPoint*, GDIPCONST BYTE*, INT, GpFillMode,
                                     GpPath **path);

GpStatus WINGDIPAPI
GdipClonePath(GpPath* path, GpPath **clonePath);

GpStatus WINGDIPAPI
GdipDeletePath(GpPath* path);

GpStatus WINGDIPAPI
GdipResetPath(GpPath* path);

GpStatus WINGDIPAPI
GdipGetPointCount(GpPath* path, INT* count);

GpStatus WINGDIPAPI
GdipGetPathTypes(_In_ GpPath* path,
                 _Out_writes_bytes_(count) BYTE* types, INT count);

GpStatus WINGDIPAPI
GdipGetPathPoints(GpPath*, GpPointF* points, INT count);

GpStatus WINGDIPAPI
GdipGetPathPointsI(GpPath*, GpPoint* points, INT count);

GpStatus WINGDIPAPI
GdipGetPathFillMode(GpPath *path, GpFillMode *fillmode);

GpStatus WINGDIPAPI
GdipSetPathFillMode(GpPath *path, GpFillMode fillmode);

GpStatus WINGDIPAPI
GdipGetPathData(GpPath *path, GpPathData* pathData);

GpStatus WINGDIPAPI
GdipStartPathFigure(GpPath *path);

GpStatus WINGDIPAPI
GdipClosePathFigure(GpPath *path);

GpStatus WINGDIPAPI
GdipClosePathFigures(GpPath *path);

GpStatus WINGDIPAPI
GdipSetPathMarker(GpPath* path);

GpStatus WINGDIPAPI
GdipClearPathMarkers(GpPath* path);

GpStatus WINGDIPAPI
GdipReversePath(GpPath* path);

GpStatus WINGDIPAPI
GdipGetPathLastPoint(GpPath* path, GpPointF* lastPoint);

GpStatus WINGDIPAPI
GdipAddPathLine(GpPath *path, REAL x1, REAL y1, REAL x2, REAL y2);

GpStatus WINGDIPAPI
GdipAddPathLine2(GpPath *path, GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathArc(GpPath *path, REAL x, REAL y, REAL width, REAL height,
                        REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipAddPathBezier(GpPath *path, REAL x1, REAL y1, REAL x2, REAL y2,
                           REAL x3, REAL y3, REAL x4, REAL y4);

GpStatus WINGDIPAPI
GdipAddPathBeziers(GpPath *path, GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathCurve(GpPath *path, GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathCurve2(GpPath *path, GDIPCONST GpPointF *points, INT count,
                           REAL tension);

GpStatus WINGDIPAPI
GdipAddPathCurve3(GpPath *path, GDIPCONST GpPointF *points, INT count,
                           INT offset, INT numberOfSegments, REAL tension);

GpStatus WINGDIPAPI
GdipAddPathClosedCurve(GpPath *path, GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathClosedCurve2(GpPath *path, GDIPCONST GpPointF *points, INT count,
                                 REAL tension);

GpStatus WINGDIPAPI
GdipAddPathRectangle(GpPath *path, REAL x, REAL y, REAL width, REAL height);

GpStatus WINGDIPAPI
GdipAddPathRectangles(GpPath *path, GDIPCONST GpRectF *rects, INT count);

GpStatus WINGDIPAPI
GdipAddPathEllipse(GpPath *path, REAL x, REAL y, REAL width,
                            REAL height);

GpStatus WINGDIPAPI
GdipAddPathPie(GpPath *path, REAL x, REAL y, REAL width, REAL height,
                        REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipAddPathPolygon(GpPath *path, GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathPath(GpPath *path, GDIPCONST GpPath* addingPath, BOOL connect);

GpStatus WINGDIPAPI
GdipAddPathString(GpPath *path, GDIPCONST WCHAR *string,
                        INT length, GDIPCONST GpFontFamily *family, INT style,
                        REAL emSize, GDIPCONST RectF *layoutRect,
                        GDIPCONST GpStringFormat *format);

GpStatus WINGDIPAPI
GdipAddPathStringI(GpPath *path, GDIPCONST WCHAR *string,
                        INT length, GDIPCONST GpFontFamily *family, INT style,
                        REAL emSize, GDIPCONST Rect *layoutRect,
                        GDIPCONST GpStringFormat *format);

GpStatus WINGDIPAPI
GdipAddPathLineI(GpPath *path, INT x1, INT y1, INT x2, INT y2);

GpStatus WINGDIPAPI
GdipAddPathLine2I(GpPath *path, GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathArcI(GpPath *path, INT x, INT y, INT width, INT height,
                        REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipAddPathBezierI(GpPath *path, INT x1, INT y1, INT x2, INT y2,
                           INT x3, INT y3, INT x4, INT y4);

GpStatus WINGDIPAPI
GdipAddPathBeziersI(GpPath *path, GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathCurveI(GpPath *path, GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathCurve2I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                           REAL tension);

GpStatus WINGDIPAPI
GdipAddPathCurve3I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                           INT offset, INT numberOfSegments, REAL tension);

GpStatus WINGDIPAPI
GdipAddPathClosedCurveI(GpPath *path, GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipAddPathClosedCurve2I(GpPath *path, GDIPCONST GpPoint *points, INT count,
                                 REAL tension);

GpStatus WINGDIPAPI
GdipAddPathRectangleI(GpPath *path, INT x, INT y, INT width, INT height);

GpStatus WINGDIPAPI
GdipAddPathRectanglesI(GpPath *path, GDIPCONST GpRect *rects, INT count);

GpStatus WINGDIPAPI
GdipAddPathEllipseI(GpPath *path, INT x, INT y, INT width, INT height);

GpStatus WINGDIPAPI
GdipAddPathPieI(GpPath *path, INT x, INT y, INT width, INT height,
                        REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipAddPathPolygonI(GpPath *path, GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipFlattenPath(GpPath *path, GpMatrix* matrix, REAL flatness);

GpStatus WINGDIPAPI
GdipWindingModeOutline(
    GpPath *path,
    GpMatrix *matrix,
    REAL flatness
);

GpStatus WINGDIPAPI
GdipWidenPath(
    GpPath *nativePath,
    GpPen *pen,
    GpMatrix *matrix,
    REAL flatness
);

GpStatus WINGDIPAPI
GdipWarpPath(GpPath *path, GpMatrix* matrix,
            GDIPCONST GpPointF *points, INT count,
            REAL srcx, REAL srcy, REAL srcwidth, REAL srcheight,
            WarpMode warpMode, REAL flatness);

GpStatus WINGDIPAPI
GdipTransformPath(GpPath* path, GpMatrix* matrix);

GpStatus WINGDIPAPI
GdipGetPathWorldBounds(GpPath* path, GpRectF* bounds, 
                       GDIPCONST GpMatrix *matrix, GDIPCONST GpPen *pen);

GpStatus WINGDIPAPI
GdipGetPathWorldBoundsI(GpPath* path, GpRect* bounds, 
                        GDIPCONST GpMatrix *matrix, GDIPCONST GpPen *pen);

GpStatus WINGDIPAPI
GdipIsVisiblePathPoint(GpPath* path, REAL x, REAL y,
                       GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisiblePathPointI(GpPath* path, INT x, INT y,
                        GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsOutlineVisiblePathPoint(GpPath* path, REAL x, REAL y, GpPen *pen,
                              GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsOutlineVisiblePathPointI(GpPath* path, INT x, INT y, GpPen *pen,
                               GpGraphics *graphics, BOOL *result);


//----------------------------------------------------------------------------
// PathIterator APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreatePathIter(GpPathIterator **iterator, GpPath* path);

GpStatus WINGDIPAPI
GdipDeletePathIter(GpPathIterator *iterator);

GpStatus WINGDIPAPI
GdipPathIterNextSubpath(GpPathIterator* iterator, INT *resultCount,
        INT* startIndex, INT* endIndex, BOOL* isClosed);

GpStatus WINGDIPAPI
GdipPathIterNextSubpathPath(GpPathIterator* iterator, INT* resultCount,
        GpPath* path, BOOL* isClosed);

GpStatus WINGDIPAPI
GdipPathIterNextPathType(GpPathIterator* iterator, _Out_ INT* resultCount,
        _Out_ BYTE* pathType, _Out_ INT* startIndex, _Out_ INT* endIndex);

GpStatus WINGDIPAPI
GdipPathIterNextMarker(GpPathIterator* iterator, INT *resultCount,
        INT* startIndex, INT* endIndex);

GpStatus WINGDIPAPI
GdipPathIterNextMarkerPath(GpPathIterator* iterator, INT* resultCount,
        GpPath* path);

GpStatus WINGDIPAPI
GdipPathIterGetCount(GpPathIterator* iterator, INT* count);

GpStatus WINGDIPAPI
GdipPathIterGetSubpathCount(GpPathIterator* iterator, INT* count);

GpStatus WINGDIPAPI
GdipPathIterIsValid(GpPathIterator* iterator, BOOL* valid);

GpStatus WINGDIPAPI
GdipPathIterHasCurve(GpPathIterator* iterator, BOOL* hasCurve);

GpStatus WINGDIPAPI
GdipPathIterRewind(GpPathIterator* iterator);

GpStatus WINGDIPAPI
GdipPathIterEnumerate(GpPathIterator* iterator, _Out_ INT* resultCount,
    _Out_writes_to_(count, *resultCount) GpPointF *points,
    _Out_writes_to_(count, *resultCount) BYTE *types, INT count);

GpStatus WINGDIPAPI
GdipPathIterCopyData(GpPathIterator* iterator, _Out_ INT* resultCount,
    _Out_writes_to_(endIndex - startIndex + 1, *resultCount) GpPointF* points,
    _Out_writes_to_(endIndex - startIndex + 1, *resultCount) BYTE* types,
    INT startIndex, INT endIndex);

//----------------------------------------------------------------------------
// Matrix APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateMatrix(GpMatrix **matrix);

GpStatus WINGDIPAPI
GdipCreateMatrix2(REAL m11, REAL m12, REAL m21, REAL m22, REAL dx,
                                      REAL dy, GpMatrix **matrix);

GpStatus WINGDIPAPI
GdipCreateMatrix3(GDIPCONST GpRectF *rect, GDIPCONST GpPointF *dstplg,
                                      GpMatrix **matrix);

GpStatus WINGDIPAPI
GdipCreateMatrix3I(GDIPCONST GpRect *rect, GDIPCONST GpPoint *dstplg,
                                       GpMatrix **matrix);

GpStatus WINGDIPAPI
GdipCloneMatrix(GpMatrix *matrix, GpMatrix **cloneMatrix);

GpStatus WINGDIPAPI
GdipDeleteMatrix(GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipSetMatrixElements(GpMatrix *matrix, REAL m11, REAL m12, REAL m21, REAL m22,
                      REAL dx, REAL dy);

GpStatus WINGDIPAPI
GdipMultiplyMatrix(GpMatrix *matrix, GpMatrix* matrix2,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslateMatrix(GpMatrix *matrix, REAL offsetX, REAL offsetY,
                    GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScaleMatrix(GpMatrix *matrix, REAL scaleX, REAL scaleY,
                GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotateMatrix(GpMatrix *matrix, REAL angle, GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipShearMatrix(GpMatrix *matrix, REAL shearX, REAL shearY,
                GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipInvertMatrix(GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipTransformMatrixPoints(GpMatrix *matrix, GpPointF *pts, INT count);

GpStatus WINGDIPAPI
GdipTransformMatrixPointsI(GpMatrix *matrix, GpPoint *pts, INT count);

GpStatus WINGDIPAPI
GdipVectorTransformMatrixPoints(GpMatrix *matrix, GpPointF *pts,
                                         INT count);

GpStatus WINGDIPAPI
GdipVectorTransformMatrixPointsI(GpMatrix *matrix, GpPoint *pts,
                                         INT count);

GpStatus WINGDIPAPI
GdipGetMatrixElements(GDIPCONST GpMatrix *matrix, REAL *matrixOut);

GpStatus WINGDIPAPI
GdipIsMatrixInvertible(GDIPCONST GpMatrix *matrix, BOOL *result);

GpStatus WINGDIPAPI
GdipIsMatrixIdentity(GDIPCONST GpMatrix *matrix, BOOL *result);

GpStatus WINGDIPAPI
GdipIsMatrixEqual(GDIPCONST GpMatrix *matrix, GDIPCONST GpMatrix *matrix2, 
                  BOOL *result);

//----------------------------------------------------------------------------
// Region APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateRegion(GpRegion **region);

GpStatus WINGDIPAPI
GdipCreateRegionRect(GDIPCONST GpRectF *rect, GpRegion **region);

GpStatus WINGDIPAPI
GdipCreateRegionRectI(GDIPCONST GpRect *rect, GpRegion **region);

GpStatus WINGDIPAPI
GdipCreateRegionPath(GpPath *path, GpRegion **region);

GpStatus WINGDIPAPI
GdipCreateRegionRgnData(GDIPCONST BYTE *regionData, INT size, 
                        GpRegion **region);

GpStatus WINGDIPAPI
GdipCreateRegionHrgn(HRGN hRgn, GpRegion **region);

GpStatus WINGDIPAPI
GdipCloneRegion(GpRegion *region, GpRegion **cloneRegion);

GpStatus WINGDIPAPI
GdipDeleteRegion(GpRegion *region);

GpStatus WINGDIPAPI
GdipSetInfinite(GpRegion *region);

GpStatus WINGDIPAPI
GdipSetEmpty(GpRegion *region);

GpStatus WINGDIPAPI
GdipCombineRegionRect(GpRegion *region, GDIPCONST GpRectF *rect,
                      CombineMode combineMode);

GpStatus WINGDIPAPI
GdipCombineRegionRectI(GpRegion *region, GDIPCONST GpRect *rect,
                       CombineMode combineMode);

GpStatus WINGDIPAPI
GdipCombineRegionPath(GpRegion *region, GpPath *path, CombineMode combineMode);

GpStatus WINGDIPAPI
GdipCombineRegionRegion(GpRegion *region,  GpRegion *region2,
                        CombineMode combineMode);

GpStatus WINGDIPAPI
GdipTranslateRegion(GpRegion *region, REAL dx, REAL dy);

GpStatus WINGDIPAPI
GdipTranslateRegionI(GpRegion *region, INT dx, INT dy);

GpStatus WINGDIPAPI
GdipTransformRegion(GpRegion *region, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipGetRegionBounds(GpRegion *region, GpGraphics *graphics,
                             GpRectF *rect);

GpStatus WINGDIPAPI
GdipGetRegionBoundsI(GpRegion *region, GpGraphics *graphics,
                             GpRect *rect);

GpStatus WINGDIPAPI
GdipGetRegionHRgn(GpRegion *region, GpGraphics *graphics, HRGN *hRgn);

GpStatus WINGDIPAPI
GdipIsEmptyRegion(GpRegion *region, GpGraphics *graphics,
                           BOOL *result);

GpStatus WINGDIPAPI
GdipIsInfiniteRegion(GpRegion *region, GpGraphics *graphics,
                              BOOL *result);

GpStatus WINGDIPAPI
GdipIsEqualRegion(GpRegion *region, GpRegion *region2,
                           GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipGetRegionDataSize(GpRegion *region, UINT * bufferSize);

GpStatus WINGDIPAPI
GdipGetRegionData(GpRegion *region,
                  _Out_writes_to_(bufferSize, *sizeFilled) BYTE * buffer,
                  UINT bufferSize, _Out_opt_ UINT * sizeFilled);

GpStatus WINGDIPAPI
GdipIsVisibleRegionPoint(GpRegion *region, REAL x, REAL y,
                                  GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisibleRegionPointI(GpRegion *region, INT x, INT y,
                                  GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisibleRegionRect(GpRegion *region, REAL x, REAL y, REAL width,
                        REAL height, GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisibleRegionRectI(GpRegion *region, INT x, INT y, INT width,
                         INT height, GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipGetRegionScansCount(GpRegion *region, UINT* count, GpMatrix* matrix);

GpStatus WINGDIPAPI
GdipGetRegionScans(GpRegion *region, GpRectF* rects, INT* count, 
                   GpMatrix* matrix);

GpStatus WINGDIPAPI
GdipGetRegionScansI(GpRegion *region, GpRect* rects, INT* count, 
                    GpMatrix* matrix);

//----------------------------------------------------------------------------
// Brush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCloneBrush(GpBrush *brush, GpBrush **cloneBrush);

GpStatus WINGDIPAPI
GdipDeleteBrush(GpBrush *brush);

GpStatus WINGDIPAPI
GdipGetBrushType(GpBrush *brush, GpBrushType *type);

//----------------------------------------------------------------------------
// HatchBrush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateHatchBrush(GpHatchStyle hatchstyle, ARGB forecol,
                              ARGB backcol, GpHatch **brush);

GpStatus WINGDIPAPI
GdipGetHatchStyle(GpHatch *brush, GpHatchStyle *hatchstyle);

GpStatus WINGDIPAPI
GdipGetHatchForegroundColor(GpHatch *brush, ARGB* forecol);

GpStatus WINGDIPAPI
GdipGetHatchBackgroundColor(GpHatch *brush, ARGB* backcol);

//----------------------------------------------------------------------------
// TextureBrush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateTexture(GpImage *image, GpWrapMode wrapmode,
                           GpTexture **texture);

GpStatus WINGDIPAPI
GdipCreateTexture2(GpImage *image, GpWrapMode wrapmode, REAL x,
                   REAL y, REAL width, REAL height, GpTexture **texture);

GpStatus WINGDIPAPI
GdipCreateTextureIA(GpImage *image, 
                    GDIPCONST GpImageAttributes *imageAttributes,
                    REAL x, REAL y, REAL width, REAL height,
                    GpTexture **texture);

GpStatus WINGDIPAPI
GdipCreateTexture2I(GpImage *image, GpWrapMode wrapmode, INT x,
                    INT y, INT width, INT height, GpTexture **texture);

GpStatus WINGDIPAPI
GdipCreateTextureIAI(GpImage *image, 
                     GDIPCONST GpImageAttributes *imageAttributes,
                     INT x, INT y, INT width, INT height,
                     GpTexture **texture);


GpStatus WINGDIPAPI
GdipGetTextureTransform(GpTexture *brush, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipSetTextureTransform(GpTexture *brush, GDIPCONST GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetTextureTransform(GpTexture* brush);

GpStatus WINGDIPAPI
GdipMultiplyTextureTransform(GpTexture* brush, GDIPCONST GpMatrix *matrix,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslateTextureTransform(GpTexture* brush, REAL dx, REAL dy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScaleTextureTransform(GpTexture* brush, REAL sx, REAL sy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotateTextureTransform(GpTexture* brush, REAL angle, GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipSetTextureWrapMode(GpTexture *brush, GpWrapMode wrapmode);

GpStatus WINGDIPAPI
GdipGetTextureWrapMode(GpTexture *brush, GpWrapMode *wrapmode);

GpStatus WINGDIPAPI
GdipGetTextureImage(GpTexture *brush, GpImage **image);

//----------------------------------------------------------------------------
// SolidBrush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateSolidFill(ARGB color, GpSolidFill **brush);

GpStatus WINGDIPAPI
GdipSetSolidFillColor(GpSolidFill *brush, ARGB color);

GpStatus WINGDIPAPI
GdipGetSolidFillColor(GpSolidFill *brush, ARGB *color);

//----------------------------------------------------------------------------
// LineBrush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateLineBrush(GDIPCONST GpPointF* point1,
                    GDIPCONST GpPointF* point2,
                    ARGB color1, ARGB color2,
                    GpWrapMode wrapMode,
                    GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipCreateLineBrushI(GDIPCONST GpPoint* point1,
                     GDIPCONST GpPoint* point2,
                     ARGB color1, ARGB color2,
                     GpWrapMode wrapMode,
                     GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipCreateLineBrushFromRect(GDIPCONST GpRectF* rect,
                            ARGB color1, ARGB color2,
                            LinearGradientMode mode,
                            GpWrapMode wrapMode,
                            GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectI(GDIPCONST GpRect* rect,
                             ARGB color1, ARGB color2,
                             LinearGradientMode mode,
                             GpWrapMode wrapMode,
                             GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectWithAngle(GDIPCONST GpRectF* rect,
                                     ARGB color1, ARGB color2,
                                     REAL angle,
                                     BOOL isAngleScalable,
                                     GpWrapMode wrapMode,
                                     GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipCreateLineBrushFromRectWithAngleI(GDIPCONST GpRect* rect,
                                     ARGB color1, ARGB color2,
                                     REAL angle,
                                     BOOL isAngleScalable,
                                     GpWrapMode wrapMode,
                                     GpLineGradient **lineGradient);

GpStatus WINGDIPAPI
GdipSetLineColors(GpLineGradient *brush, ARGB color1, ARGB color2);

GpStatus WINGDIPAPI
GdipGetLineColors(GpLineGradient *brush, ARGB* colors);

GpStatus WINGDIPAPI
GdipGetLineRect(GpLineGradient *brush, GpRectF *rect);

GpStatus WINGDIPAPI
GdipGetLineRectI(GpLineGradient *brush, GpRect *rect);

GpStatus WINGDIPAPI
GdipSetLineGammaCorrection(GpLineGradient *brush, BOOL useGammaCorrection);

GpStatus WINGDIPAPI
GdipGetLineGammaCorrection(GpLineGradient *brush, BOOL *useGammaCorrection);

GpStatus WINGDIPAPI
GdipGetLineBlendCount(GpLineGradient *brush, INT *count);

GpStatus WINGDIPAPI
GdipGetLineBlend(GpLineGradient *brush, REAL *blend, REAL* positions,
                 INT count);

GpStatus WINGDIPAPI
GdipSetLineBlend(GpLineGradient *brush, GDIPCONST REAL *blend,
                 GDIPCONST REAL* positions, INT count);

GpStatus WINGDIPAPI
GdipGetLinePresetBlendCount(GpLineGradient *brush, INT *count);

GpStatus WINGDIPAPI
GdipGetLinePresetBlend(GpLineGradient *brush, ARGB *blend,
                                           REAL* positions, INT count);

GpStatus WINGDIPAPI
GdipSetLinePresetBlend(GpLineGradient *brush, GDIPCONST ARGB *blend,
                       GDIPCONST REAL* positions, INT count);

GpStatus WINGDIPAPI
GdipSetLineSigmaBlend(GpLineGradient *brush, REAL focus, REAL scale);

GpStatus WINGDIPAPI
GdipSetLineLinearBlend(GpLineGradient *brush, REAL focus, REAL scale);

GpStatus WINGDIPAPI
GdipSetLineWrapMode(GpLineGradient *brush, GpWrapMode wrapmode);

GpStatus WINGDIPAPI
GdipGetLineWrapMode(GpLineGradient *brush, GpWrapMode *wrapmode);

GpStatus WINGDIPAPI
GdipGetLineTransform(GpLineGradient *brush, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipSetLineTransform(GpLineGradient *brush, GDIPCONST GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetLineTransform(GpLineGradient* brush);

GpStatus WINGDIPAPI
GdipMultiplyLineTransform(GpLineGradient* brush, GDIPCONST GpMatrix *matrix,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslateLineTransform(GpLineGradient* brush, REAL dx, REAL dy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScaleLineTransform(GpLineGradient* brush, REAL sx, REAL sy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotateLineTransform(GpLineGradient* brush, REAL angle, 
                        GpMatrixOrder order);

//----------------------------------------------------------------------------
// PathGradientBrush APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreatePathGradient(GDIPCONST GpPointF* points,
                                    INT count,
                                    GpWrapMode wrapMode,
                                    GpPathGradient **polyGradient);

GpStatus WINGDIPAPI
GdipCreatePathGradientI(GDIPCONST GpPoint* points,
                                    INT count,
                                    GpWrapMode wrapMode,
                                    GpPathGradient **polyGradient);

GpStatus WINGDIPAPI
GdipCreatePathGradientFromPath(GDIPCONST GpPath* path,
                                    GpPathGradient **polyGradient);

GpStatus WINGDIPAPI
GdipGetPathGradientCenterColor(
                        GpPathGradient *brush, ARGB* colors);

GpStatus WINGDIPAPI
GdipSetPathGradientCenterColor(
                        GpPathGradient *brush, ARGB colors);

GpStatus WINGDIPAPI
GdipGetPathGradientSurroundColorsWithCount(
                        _In_ GpPathGradient *brush,
                        _Out_writes_to_(*count, *count) ARGB* color,
                        _Inout_ INT* count);

GpStatus WINGDIPAPI
GdipSetPathGradientSurroundColorsWithCount(
                        GpPathGradient *brush,
                        GDIPCONST ARGB* color, INT* count);

GpStatus WINGDIPAPI
GdipGetPathGradientPath(GpPathGradient *brush, GpPath *path);

GpStatus WINGDIPAPI
GdipSetPathGradientPath(GpPathGradient *brush, GDIPCONST GpPath *path);

GpStatus WINGDIPAPI
GdipGetPathGradientCenterPoint(
                        GpPathGradient *brush, GpPointF* points);

GpStatus WINGDIPAPI
GdipGetPathGradientCenterPointI(
                        GpPathGradient *brush, GpPoint* points);

GpStatus WINGDIPAPI
GdipSetPathGradientCenterPoint(
                        GpPathGradient *brush, GDIPCONST GpPointF* points);

GpStatus WINGDIPAPI
GdipSetPathGradientCenterPointI(
                        GpPathGradient *brush, GDIPCONST GpPoint* points);

GpStatus WINGDIPAPI
GdipGetPathGradientRect(GpPathGradient *brush, GpRectF *rect);

GpStatus WINGDIPAPI
GdipGetPathGradientRectI(GpPathGradient *brush, GpRect *rect);

GpStatus WINGDIPAPI
GdipGetPathGradientPointCount(GpPathGradient *brush, INT* count);

GpStatus WINGDIPAPI
GdipGetPathGradientSurroundColorCount(GpPathGradient *brush, INT* count);

GpStatus WINGDIPAPI
GdipSetPathGradientGammaCorrection(GpPathGradient *brush, 
                                   BOOL useGammaCorrection);

GpStatus WINGDIPAPI
GdipGetPathGradientGammaCorrection(GpPathGradient *brush, 
                                   BOOL *useGammaCorrection);

GpStatus WINGDIPAPI
GdipGetPathGradientBlendCount(GpPathGradient *brush,
                                             INT *count);

GpStatus WINGDIPAPI
GdipGetPathGradientBlend(GpPathGradient *brush,
                                    REAL *blend, REAL *positions, INT count);

GpStatus WINGDIPAPI
GdipSetPathGradientBlend(GpPathGradient *brush,
                GDIPCONST REAL *blend, GDIPCONST REAL *positions, INT count);

GpStatus WINGDIPAPI
GdipGetPathGradientPresetBlendCount(GpPathGradient *brush, INT *count);

GpStatus WINGDIPAPI
GdipGetPathGradientPresetBlend(GpPathGradient *brush, ARGB *blend,
                                                REAL* positions, INT count);

GpStatus WINGDIPAPI
GdipSetPathGradientPresetBlend(GpPathGradient *brush, GDIPCONST ARGB *blend,
                                        GDIPCONST REAL* positions, INT count);

GpStatus WINGDIPAPI
GdipSetPathGradientSigmaBlend(GpPathGradient *brush, REAL focus, REAL scale);

GpStatus WINGDIPAPI
GdipSetPathGradientLinearBlend(GpPathGradient *brush, REAL focus, REAL scale);

GpStatus WINGDIPAPI
GdipGetPathGradientWrapMode(GpPathGradient *brush,
                                         GpWrapMode *wrapmode);

GpStatus WINGDIPAPI
GdipSetPathGradientWrapMode(GpPathGradient *brush,
                                         GpWrapMode wrapmode);

GpStatus WINGDIPAPI
GdipGetPathGradientTransform(GpPathGradient *brush,
                                          GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipSetPathGradientTransform(GpPathGradient *brush,
                                          GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetPathGradientTransform(GpPathGradient* brush);

GpStatus WINGDIPAPI
GdipMultiplyPathGradientTransform(GpPathGradient* brush, 
                                  GDIPCONST GpMatrix *matrix,
                                  GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslatePathGradientTransform(GpPathGradient* brush, REAL dx, REAL dy,
                                   GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScalePathGradientTransform(GpPathGradient* brush, REAL sx, REAL sy,
                               GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotatePathGradientTransform(GpPathGradient* brush, REAL angle,
                                GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipGetPathGradientFocusScales(GpPathGradient *brush, REAL* xScale, 
                               REAL* yScale);

GpStatus WINGDIPAPI
GdipSetPathGradientFocusScales(GpPathGradient *brush, REAL xScale, 
                               REAL yScale);

//----------------------------------------------------------------------------
// Pen APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreatePen1(ARGB color, REAL width, GpUnit unit, GpPen **pen);

GpStatus WINGDIPAPI
GdipCreatePen2(GpBrush *brush, REAL width, GpUnit unit,
                        GpPen **pen);

GpStatus WINGDIPAPI
GdipClonePen(GpPen *pen, GpPen **clonepen);

GpStatus WINGDIPAPI
GdipDeletePen(GpPen *pen);

GpStatus WINGDIPAPI
GdipSetPenWidth(GpPen *pen, REAL width);

GpStatus WINGDIPAPI
GdipGetPenWidth(GpPen *pen, REAL *width);

GpStatus WINGDIPAPI
GdipSetPenUnit(GpPen *pen, GpUnit unit);

GpStatus WINGDIPAPI
GdipGetPenUnit(GpPen *pen, GpUnit *unit);

GpStatus WINGDIPAPI
GdipSetPenLineCap197819(GpPen *pen, GpLineCap startCap, GpLineCap endCap,
                  GpDashCap dashCap);

GpStatus WINGDIPAPI
GdipSetPenStartCap(GpPen *pen, GpLineCap startCap);

GpStatus WINGDIPAPI
GdipSetPenEndCap(GpPen *pen, GpLineCap endCap);

GpStatus WINGDIPAPI
GdipSetPenDashCap197819(GpPen *pen, GpDashCap dashCap);

GpStatus WINGDIPAPI
GdipGetPenStartCap(GpPen *pen, GpLineCap *startCap);

GpStatus WINGDIPAPI
GdipGetPenEndCap(GpPen *pen, GpLineCap *endCap);

GpStatus WINGDIPAPI
GdipGetPenDashCap197819(GpPen *pen, GpDashCap *dashCap);

GpStatus WINGDIPAPI
GdipSetPenLineJoin(GpPen *pen, GpLineJoin lineJoin);

GpStatus WINGDIPAPI
GdipGetPenLineJoin(GpPen *pen, GpLineJoin *lineJoin);

GpStatus WINGDIPAPI
GdipSetPenCustomStartCap(GpPen *pen, GpCustomLineCap* customCap);

GpStatus WINGDIPAPI
GdipGetPenCustomStartCap(GpPen *pen, GpCustomLineCap** customCap);

GpStatus WINGDIPAPI
GdipSetPenCustomEndCap(GpPen *pen, GpCustomLineCap* customCap);

GpStatus WINGDIPAPI
GdipGetPenCustomEndCap(GpPen *pen, GpCustomLineCap** customCap);

GpStatus WINGDIPAPI
GdipSetPenMiterLimit(GpPen *pen, REAL miterLimit);

GpStatus WINGDIPAPI
GdipGetPenMiterLimit(GpPen *pen, REAL *miterLimit);

GpStatus WINGDIPAPI
GdipSetPenMode(GpPen *pen, GpPenAlignment penMode);

GpStatus WINGDIPAPI
GdipGetPenMode(GpPen *pen, GpPenAlignment *penMode);

GpStatus WINGDIPAPI
GdipSetPenTransform(GpPen *pen, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipGetPenTransform(GpPen *pen, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetPenTransform(GpPen *pen);

GpStatus WINGDIPAPI
GdipMultiplyPenTransform(GpPen *pen, GDIPCONST GpMatrix *matrix,
                           GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslatePenTransform(GpPen *pen, REAL dx, REAL dy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScalePenTransform(GpPen *pen, REAL sx, REAL sy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotatePenTransform(GpPen *pen, REAL angle, GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipSetPenColor(GpPen *pen, ARGB argb);

GpStatus WINGDIPAPI
GdipGetPenColor(GpPen *pen, ARGB *argb);

GpStatus WINGDIPAPI
GdipSetPenBrushFill(GpPen *pen, GpBrush *brush);

GpStatus WINGDIPAPI
GdipGetPenBrushFill(GpPen *pen, GpBrush **brush);

GpStatus WINGDIPAPI
GdipGetPenFillType(GpPen *pen, GpPenType* type);

GpStatus WINGDIPAPI
GdipGetPenDashStyle(GpPen *pen, GpDashStyle *dashstyle);

GpStatus WINGDIPAPI
GdipSetPenDashStyle(GpPen *pen, GpDashStyle dashstyle);

GpStatus WINGDIPAPI
GdipGetPenDashOffset(GpPen *pen, REAL *offset);

GpStatus WINGDIPAPI
GdipSetPenDashOffset(GpPen *pen, REAL offset);

GpStatus WINGDIPAPI
GdipGetPenDashCount(GpPen *pen, INT *count);

GpStatus WINGDIPAPI
GdipSetPenDashArray(GpPen *pen, GDIPCONST REAL *dash, INT count);

GpStatus WINGDIPAPI
GdipGetPenDashArray(GpPen *pen, REAL *dash, INT count);

GpStatus WINGDIPAPI
GdipGetPenCompoundCount(GpPen *pen, INT *count);

GpStatus WINGDIPAPI
GdipSetPenCompoundArray(GpPen *pen, GDIPCONST REAL *dash, INT count);

GpStatus WINGDIPAPI
GdipGetPenCompoundArray(GpPen *pen, REAL *dash, INT count);

//----------------------------------------------------------------------------
// CustomLineCap APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateCustomLineCap(GpPath* fillPath, GpPath* strokePath,
   GpLineCap baseCap, REAL baseInset, GpCustomLineCap **customCap);

GpStatus WINGDIPAPI
GdipDeleteCustomLineCap(GpCustomLineCap* customCap);

GpStatus WINGDIPAPI
GdipCloneCustomLineCap(GpCustomLineCap* customCap,
                       GpCustomLineCap** clonedCap);

GpStatus WINGDIPAPI
GdipGetCustomLineCapType(GpCustomLineCap* customCap,
                       CustomLineCapType* capType);

GpStatus WINGDIPAPI
GdipSetCustomLineCapStrokeCaps(GpCustomLineCap* customCap,
                               GpLineCap startCap, GpLineCap endCap);

GpStatus WINGDIPAPI
GdipGetCustomLineCapStrokeCaps(GpCustomLineCap* customCap,
                               GpLineCap* startCap, GpLineCap* endCap);

GpStatus WINGDIPAPI
GdipSetCustomLineCapStrokeJoin(GpCustomLineCap* customCap, 
                               GpLineJoin lineJoin);

GpStatus WINGDIPAPI
GdipGetCustomLineCapStrokeJoin(GpCustomLineCap* customCap, 
                               GpLineJoin* lineJoin);

GpStatus WINGDIPAPI
GdipSetCustomLineCapBaseCap(GpCustomLineCap* customCap, GpLineCap baseCap);

GpStatus WINGDIPAPI
GdipGetCustomLineCapBaseCap(GpCustomLineCap* customCap, GpLineCap* baseCap);

GpStatus WINGDIPAPI
GdipSetCustomLineCapBaseInset(GpCustomLineCap* customCap, REAL inset);

GpStatus WINGDIPAPI
GdipGetCustomLineCapBaseInset(GpCustomLineCap* customCap, REAL* inset);

GpStatus WINGDIPAPI
GdipSetCustomLineCapWidthScale(GpCustomLineCap* customCap, REAL widthScale);

GpStatus WINGDIPAPI
GdipGetCustomLineCapWidthScale(GpCustomLineCap* customCap, REAL* widthScale);

//----------------------------------------------------------------------------
// AdjustableArrowCap APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateAdjustableArrowCap(REAL height, REAL width, BOOL isFilled,
                             GpAdjustableArrowCap **cap);

GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapHeight(GpAdjustableArrowCap* cap, REAL height);

GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapHeight(GpAdjustableArrowCap* cap, REAL* height);

GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapWidth(GpAdjustableArrowCap* cap, REAL width);

GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapWidth(GpAdjustableArrowCap* cap, REAL* width);

GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapMiddleInset(GpAdjustableArrowCap* cap, 
                                     REAL middleInset);

GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapMiddleInset(GpAdjustableArrowCap* cap, 
                                     REAL* middleInset);

GpStatus WINGDIPAPI
GdipSetAdjustableArrowCapFillState(GpAdjustableArrowCap* cap, BOOL fillState);

GpStatus WINGDIPAPI
GdipGetAdjustableArrowCapFillState(GpAdjustableArrowCap* cap, BOOL* fillState);

//----------------------------------------------------------------------------
// Image APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipLoadImageFromStream(IStream* stream, GpImage **image);

GpStatus WINGDIPAPI
GdipLoadImageFromFile(GDIPCONST WCHAR* filename, GpImage **image);

GpStatus WINGDIPAPI
GdipLoadImageFromStreamICM(IStream* stream, GpImage **image);

GpStatus WINGDIPAPI
GdipLoadImageFromFileICM(GDIPCONST WCHAR* filename, GpImage **image);

GpStatus WINGDIPAPI
GdipCloneImage(GpImage *image, GpImage **cloneImage);

GpStatus WINGDIPAPI
GdipDisposeImage(GpImage *image);

GpStatus WINGDIPAPI
GdipSaveImageToFile(GpImage *image, GDIPCONST WCHAR* filename,
                    GDIPCONST CLSID* clsidEncoder, 
                    GDIPCONST EncoderParameters* encoderParams);

GpStatus WINGDIPAPI
GdipSaveImageToStream(GpImage *image, IStream* stream,
                      GDIPCONST CLSID* clsidEncoder, 
                      GDIPCONST EncoderParameters* encoderParams);

GpStatus WINGDIPAPI
GdipSaveAdd(GpImage *image, GDIPCONST EncoderParameters* encoderParams);

GpStatus WINGDIPAPI
GdipSaveAddImage(GpImage *image, GpImage* newImage,
                 GDIPCONST EncoderParameters* encoderParams);

GpStatus WINGDIPAPI
GdipGetImageGraphicsContext(GpImage *image, GpGraphics **graphics);

GpStatus WINGDIPAPI
GdipGetImageBounds(GpImage *image, GpRectF *srcRect, GpUnit *srcUnit);

GpStatus WINGDIPAPI
GdipGetImageDimension(GpImage *image, REAL *width, REAL *height);

GpStatus WINGDIPAPI
GdipGetImageType(GpImage *image, ImageType *type);

GpStatus WINGDIPAPI
GdipGetImageWidth(GpImage *image, UINT *width);

GpStatus WINGDIPAPI
GdipGetImageHeight(GpImage *image, UINT *height);

GpStatus WINGDIPAPI
GdipGetImageHorizontalResolution(GpImage *image, REAL *resolution);

GpStatus WINGDIPAPI
GdipGetImageVerticalResolution(GpImage *image, REAL *resolution);

GpStatus WINGDIPAPI
GdipGetImageFlags(GpImage *image, UINT *flags);

GpStatus WINGDIPAPI
GdipGetImageRawFormat(GpImage *image, GUID *format);

GpStatus WINGDIPAPI
GdipGetImagePixelFormat(GpImage *image, PixelFormat *format);

GpStatus WINGDIPAPI
GdipGetImageThumbnail(GpImage *image, UINT thumbWidth, UINT thumbHeight,
                      GpImage **thumbImage,
                      GetThumbnailImageAbort callback, VOID * callbackData);

GpStatus WINGDIPAPI
GdipGetEncoderParameterListSize(GpImage *image, GDIPCONST CLSID* clsidEncoder,
                                UINT* size);

GpStatus WINGDIPAPI
GdipGetEncoderParameterList(GpImage *image, GDIPCONST CLSID* clsidEncoder,
                            UINT size, EncoderParameters* buffer);

GpStatus WINGDIPAPI
GdipImageGetFrameDimensionsCount(GpImage* image, UINT* count);

GpStatus WINGDIPAPI
GdipImageGetFrameDimensionsList(GpImage* image, GUID* dimensionIDs, 
                                UINT count);

GpStatus WINGDIPAPI
GdipImageGetFrameCount(GpImage *image, GDIPCONST GUID* dimensionID, 
                       UINT* count);

GpStatus WINGDIPAPI
GdipImageSelectActiveFrame(GpImage *image, GDIPCONST GUID* dimensionID,
                           UINT frameIndex);

GpStatus WINGDIPAPI
GdipImageRotateFlip(GpImage *image, RotateFlipType rfType);

GpStatus WINGDIPAPI
GdipGetImagePalette(GpImage *image, ColorPalette *palette, INT size);

GpStatus WINGDIPAPI
GdipSetImagePalette(GpImage *image, GDIPCONST ColorPalette *palette);

GpStatus WINGDIPAPI
GdipGetImagePaletteSize(GpImage *image, INT *size);

GpStatus WINGDIPAPI
GdipGetPropertyCount(GpImage *image, UINT* numOfProperty);

GpStatus WINGDIPAPI
GdipGetPropertyIdList(GpImage *image, UINT numOfProperty, PROPID* list);

GpStatus WINGDIPAPI
GdipGetPropertyItemSize(GpImage *image, PROPID propId, UINT* size);

GpStatus WINGDIPAPI
GdipGetPropertyItem(GpImage *image, PROPID propId,UINT propSize,
                    PropertyItem* buffer);

GpStatus WINGDIPAPI
GdipGetPropertySize(GpImage *image, UINT* totalBufferSize, 
                    UINT* numProperties);

GpStatus WINGDIPAPI
GdipGetAllPropertyItems(GpImage *image, UINT totalBufferSize,
                        UINT numProperties, PropertyItem* allItems);

GpStatus WINGDIPAPI
GdipRemovePropertyItem(GpImage *image, PROPID propId);

GpStatus WINGDIPAPI
GdipSetPropertyItem(GpImage *image, GDIPCONST PropertyItem* item);

#if (GDIPVER >= 0x0110)
GpStatus WINGDIPAPI
GdipFindFirstImageItem(GpImage *image, ImageItemData* item);

GpStatus WINGDIPAPI
GdipFindNextImageItem(GpImage *image, ImageItemData* item);

GpStatus WINGDIPAPI
GdipGetImageItemData(GpImage *image, ImageItemData* item);
#endif //(GDIPVER >= 0x0110)

GpStatus WINGDIPAPI
GdipImageForceValidation(GpImage *image);

//----------------------------------------------------------------------------
// Bitmap APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateBitmapFromStream(IStream* stream, GpBitmap **bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromFile(GDIPCONST WCHAR* filename, GpBitmap **bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromStreamICM(IStream* stream, GpBitmap **bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromFileICM(GDIPCONST WCHAR* filename, GpBitmap **bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromScan0(INT width,
                          INT height,
                          INT stride,
                          PixelFormat format,
                          _In_reads_opt_(_Inexpressible_("height * stride")) BYTE* scan0,

                          _Outptr_ GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromGraphics(INT width,
                             INT height,
                             GpGraphics* target,
                             GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromDirectDrawSurface(IDirectDrawSurface7* surface,
                                      GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromGdiDib(GDIPCONST BITMAPINFO* gdiBitmapInfo,
                           VOID* gdiBitmapData,
                           GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateBitmapFromHBITMAP(HBITMAP hbm,
                            HPALETTE hpal,
                            GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateHBITMAPFromBitmap(GpBitmap* bitmap,
                            HBITMAP* hbmReturn,
                            ARGB background);

GpStatus WINGDIPAPI
GdipCreateBitmapFromHICON(HICON hicon,
                          GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCreateHICONFromBitmap(GpBitmap* bitmap,
                          HICON* hbmReturn);

GpStatus WINGDIPAPI
GdipCreateBitmapFromResource(HINSTANCE hInstance,
                             GDIPCONST WCHAR* lpBitmapName,
                             GpBitmap** bitmap);

GpStatus WINGDIPAPI
GdipCloneBitmapArea(REAL x, REAL y, REAL width, REAL height,
                            PixelFormat format,
                            GpBitmap *srcBitmap,
                            GpBitmap **dstBitmap);

GpStatus WINGDIPAPI
GdipCloneBitmapAreaI(INT x,
                     INT y,
                     INT width,
                     INT height,
                     PixelFormat format,
                     GpBitmap *srcBitmap,
                     GpBitmap **dstBitmap);

GpStatus WINGDIPAPI
GdipBitmapLockBits(GpBitmap* bitmap,
                   GDIPCONST GpRect* rect,
                   UINT flags,
                   PixelFormat format,
                   BitmapData* lockedBitmapData);

GpStatus WINGDIPAPI
GdipBitmapUnlockBits(GpBitmap* bitmap,
                     BitmapData* lockedBitmapData);

GpStatus WINGDIPAPI
GdipBitmapGetPixel(GpBitmap* bitmap, INT x, INT y, ARGB *color);

GpStatus WINGDIPAPI
GdipBitmapSetPixel(GpBitmap* bitmap, INT x, INT y, ARGB color);

#if (GDIPVER >= 0x0110)
GpStatus WINGDIPAPI GdipImageSetAbort(
    GpImage *pImage, 
    GdiplusAbort *pIAbort
    );

GpStatus WINGDIPAPI GdipGraphicsSetAbort(
    GpGraphics *pGraphics, 
    GdiplusAbort *pIAbort
    );

GpStatus WINGDIPAPI
GdipBitmapConvertFormat(
    IN GpBitmap *pInputBitmap,
    PixelFormat format,
    DitherType dithertype,
    PaletteType palettetype,
    ColorPalette *palette,
    REAL alphaThresholdPercent
    );

GpStatus WINGDIPAPI
GdipInitializePalette(
    OUT ColorPalette *palette,   // output palette. must be allocated.
    PaletteType palettetype,     // palette enumeration type.
    INT optimalColors,           // how many optimal colors
    BOOL useTransparentColor,    // add a transparent color to the palette.
    GpBitmap *bitmap             // optional bitmap for median cut.
    );
    
GpStatus WINGDIPAPI
GdipBitmapApplyEffect(
    GpBitmap* bitmap,
    CGpEffect *effect,
    RECT *roi,
    BOOL useAuxData,
    VOID **auxData,
    INT *auxDataSize
    );

GpStatus WINGDIPAPI
GdipBitmapCreateApplyEffect(
    GpBitmap **inputBitmaps,
    INT numInputs,
    CGpEffect *effect,
    RECT *roi,
    RECT *outputRect,
    GpBitmap **outputBitmap,
    BOOL useAuxData,
    VOID **auxData,
    INT *auxDataSize
);

GpStatus WINGDIPAPI
GdipBitmapGetHistogram(
    GpBitmap* bitmap, 
    IN HistogramFormat format,
    IN UINT NumberOfEntries,
    _Out_writes_bytes_(sizeof(UINT)*256) UINT *channel0,
    _Out_writes_bytes_(sizeof(UINT)*256) UINT *channel1,
    _Out_writes_bytes_(sizeof(UINT)*256) UINT *channel2,
    _Out_writes_bytes_(sizeof(UINT)*256) UINT *channel3
);

GpStatus WINGDIPAPI
GdipBitmapGetHistogramSize(
    IN HistogramFormat format,
    OUT UINT *NumberOfEntries
);
#endif

GpStatus WINGDIPAPI
GdipBitmapSetResolution(GpBitmap* bitmap, REAL xdpi, REAL ydpi);

//----------------------------------------------------------------------------
// ImageAttributes APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateImageAttributes(GpImageAttributes **imageattr);

GpStatus WINGDIPAPI
GdipCloneImageAttributes(GDIPCONST GpImageAttributes *imageattr,
                         GpImageAttributes **cloneImageattr);

GpStatus WINGDIPAPI
GdipDisposeImageAttributes(GpImageAttributes *imageattr);

GpStatus WINGDIPAPI
GdipSetImageAttributesToIdentity(GpImageAttributes *imageattr,
                                 ColorAdjustType type);
GpStatus WINGDIPAPI
GdipResetImageAttributes(GpImageAttributes *imageattr,
                         ColorAdjustType type);

GpStatus WINGDIPAPI
GdipSetImageAttributesColorMatrix(GpImageAttributes *imageattr,
                               ColorAdjustType type,
                               BOOL enableFlag,
                               GDIPCONST ColorMatrix* colorMatrix,
                               GDIPCONST ColorMatrix* grayMatrix,
                               ColorMatrixFlags flags);

GpStatus WINGDIPAPI
GdipSetImageAttributesThreshold(GpImageAttributes *imageattr,
                                ColorAdjustType type,
                                BOOL enableFlag,
                                REAL threshold);

GpStatus WINGDIPAPI
GdipSetImageAttributesGamma(GpImageAttributes *imageattr,
                            ColorAdjustType type,
                            BOOL enableFlag,
                            REAL gamma);

GpStatus WINGDIPAPI
GdipSetImageAttributesNoOp(GpImageAttributes *imageattr,
                           ColorAdjustType type,
                           BOOL enableFlag);

GpStatus WINGDIPAPI
GdipSetImageAttributesColorKeys(GpImageAttributes *imageattr,
                                ColorAdjustType type,
                                BOOL enableFlag,
                                ARGB colorLow,
                                ARGB colorHigh);

GpStatus WINGDIPAPI
GdipSetImageAttributesOutputChannel(GpImageAttributes *imageattr,
                                    ColorAdjustType type,
                                    BOOL enableFlag,
                                    ColorChannelFlags channelFlags);

GpStatus WINGDIPAPI
GdipSetImageAttributesOutputChannelColorProfile(GpImageAttributes *imageattr,
                                                ColorAdjustType type,
                                                BOOL enableFlag,
                                                GDIPCONST 
                                                  WCHAR *colorProfileFilename);

GpStatus WINGDIPAPI
GdipSetImageAttributesRemapTable(GpImageAttributes *imageattr,
                                 ColorAdjustType type,
                                 BOOL enableFlag,
                                 UINT mapSize,
                                 GDIPCONST ColorMap *map);
GpStatus WINGDIPAPI
GdipSetImageAttributesWrapMode(
    GpImageAttributes *imageAttr,
    WrapMode wrap,
    ARGB argb,
    BOOL clamp
);

GpStatus WINGDIPAPI
GdipSetImageAttributesICMMode(
    GpImageAttributes *imageAttr,
    BOOL on
);

GpStatus WINGDIPAPI
GdipGetImageAttributesAdjustedPalette(
    GpImageAttributes *imageAttr,
    ColorPalette * colorPalette,
    ColorAdjustType colorAdjustType
);

//----------------------------------------------------------------------------
// Graphics APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipFlush(GpGraphics *graphics, GpFlushIntention intention);

GpStatus WINGDIPAPI
GdipCreateFromHDC(HDC hdc, GpGraphics **graphics);

GpStatus WINGDIPAPI
GdipCreateFromHDC2(HDC hdc, HANDLE hDevice, GpGraphics **graphics);

GpStatus WINGDIPAPI
GdipCreateFromHWND(HWND hwnd, GpGraphics **graphics);

GpStatus WINGDIPAPI
GdipCreateFromHWNDICM(HWND hwnd, GpGraphics **graphics);

GpStatus WINGDIPAPI
GdipDeleteGraphics(GpGraphics *graphics);

GpStatus WINGDIPAPI
GdipGetDC(GpGraphics* graphics, HDC * hdc);

GpStatus WINGDIPAPI
GdipReleaseDC(GpGraphics* graphics, HDC hdc);

GpStatus WINGDIPAPI
GdipSetCompositingMode(GpGraphics *graphics, CompositingMode compositingMode);

GpStatus WINGDIPAPI
GdipGetCompositingMode(GpGraphics *graphics, CompositingMode *compositingMode);

GpStatus WINGDIPAPI
GdipSetRenderingOrigin(GpGraphics *graphics, INT x, INT y);

GpStatus WINGDIPAPI
GdipGetRenderingOrigin(GpGraphics *graphics, INT *x, INT *y);

GpStatus WINGDIPAPI
GdipSetCompositingQuality(GpGraphics *graphics, 
                          CompositingQuality compositingQuality);

GpStatus WINGDIPAPI
GdipGetCompositingQuality(GpGraphics *graphics, 
                          CompositingQuality *compositingQuality);
                          
GpStatus WINGDIPAPI
GdipSetSmoothingMode(GpGraphics *graphics, SmoothingMode smoothingMode);

GpStatus WINGDIPAPI
GdipGetSmoothingMode(GpGraphics *graphics, SmoothingMode *smoothingMode);

GpStatus WINGDIPAPI
GdipSetPixelOffsetMode(GpGraphics* graphics, PixelOffsetMode pixelOffsetMode);

GpStatus WINGDIPAPI
GdipGetPixelOffsetMode(GpGraphics *graphics, PixelOffsetMode *pixelOffsetMode);

GpStatus WINGDIPAPI
GdipSetTextRenderingHint(GpGraphics *graphics, TextRenderingHint mode);

GpStatus WINGDIPAPI
GdipGetTextRenderingHint(GpGraphics *graphics, TextRenderingHint *mode);

GpStatus  WINGDIPAPI
GdipSetTextContrast(GpGraphics *graphics, UINT contrast);

GpStatus  WINGDIPAPI
GdipGetTextContrast(GpGraphics *graphics, UINT * contrast);

GpStatus WINGDIPAPI
GdipSetInterpolationMode(GpGraphics *graphics, 
                         InterpolationMode interpolationMode);

GpStatus WINGDIPAPI
GdipGetInterpolationMode(GpGraphics *graphics, 
                         InterpolationMode *interpolationMode);

GpStatus WINGDIPAPI
GdipSetWorldTransform(GpGraphics *graphics, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetWorldTransform(GpGraphics *graphics);

GpStatus WINGDIPAPI
GdipMultiplyWorldTransform(GpGraphics *graphics, GDIPCONST GpMatrix *matrix,
                           GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipTranslateWorldTransform(GpGraphics *graphics, REAL dx, REAL dy,
                            GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipScaleWorldTransform(GpGraphics *graphics, REAL sx, REAL sy,
                        GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipRotateWorldTransform(GpGraphics *graphics, REAL angle, 
                         GpMatrixOrder order);

GpStatus WINGDIPAPI
GdipGetWorldTransform(GpGraphics *graphics, GpMatrix *matrix);

GpStatus WINGDIPAPI
GdipResetPageTransform(GpGraphics *graphics);

GpStatus WINGDIPAPI
GdipGetPageUnit(GpGraphics *graphics, GpUnit *unit);

GpStatus WINGDIPAPI
GdipGetPageScale(GpGraphics *graphics, REAL *scale);

GpStatus WINGDIPAPI
GdipSetPageUnit(GpGraphics *graphics, GpUnit unit);

GpStatus WINGDIPAPI
GdipSetPageScale(GpGraphics *graphics, REAL scale);

GpStatus WINGDIPAPI
GdipGetDpiX(GpGraphics *graphics, REAL* dpi);

GpStatus WINGDIPAPI
GdipGetDpiY(GpGraphics *graphics, REAL* dpi);

GpStatus WINGDIPAPI
GdipTransformPoints(GpGraphics *graphics, GpCoordinateSpace destSpace,
                             GpCoordinateSpace srcSpace, GpPointF *points,
                             INT count);

GpStatus WINGDIPAPI
GdipTransformPointsI(GpGraphics *graphics, GpCoordinateSpace destSpace,
                             GpCoordinateSpace srcSpace, GpPoint *points,
                             INT count);

GpStatus WINGDIPAPI
GdipGetNearestColor(GpGraphics *graphics, ARGB* argb);

// Creates the Win9x Halftone Palette (even on NT) with correct Desktop colors
HPALETTE WINGDIPAPI
GdipCreateHalftonePalette();

GpStatus WINGDIPAPI
GdipDrawLine(GpGraphics *graphics, GpPen *pen, REAL x1, REAL y1,
                      REAL x2, REAL y2);

GpStatus WINGDIPAPI
GdipDrawLineI(GpGraphics *graphics, GpPen *pen, INT x1, INT y1,
                      INT x2, INT y2);

GpStatus WINGDIPAPI
GdipDrawLines(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawLinesI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawArc(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
            REAL width, REAL height, REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipDrawArcI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                     INT width, INT height, REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipDrawBezier(GpGraphics *graphics, GpPen *pen, REAL x1, REAL y1,
                        REAL x2, REAL y2, REAL x3, REAL y3, REAL x4, REAL y4);

GpStatus WINGDIPAPI
GdipDrawBezierI(GpGraphics *graphics, GpPen *pen, INT x1, INT y1,
                        INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);

GpStatus WINGDIPAPI
GdipDrawBeziers(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                         INT count);

GpStatus WINGDIPAPI
GdipDrawBeziersI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                         INT count);

GpStatus WINGDIPAPI
GdipDrawRectangle(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                      REAL width, REAL height);

GpStatus WINGDIPAPI
GdipDrawRectangleI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                      INT width, INT height);

GpStatus WINGDIPAPI
GdipDrawRectangles(GpGraphics *graphics, GpPen *pen, GDIPCONST GpRectF *rects,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawRectanglesI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpRect *rects,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawEllipse(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                         REAL width, REAL height);

GpStatus WINGDIPAPI
GdipDrawEllipseI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                         INT width, INT height);

GpStatus WINGDIPAPI
GdipDrawPie(GpGraphics *graphics, GpPen *pen, REAL x, REAL y,
                     REAL width, REAL height, REAL startAngle, 
            REAL sweepAngle);

GpStatus WINGDIPAPI
GdipDrawPieI(GpGraphics *graphics, GpPen *pen, INT x, INT y,
                     INT width, INT height, REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipDrawPolygon(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                         INT count);

GpStatus WINGDIPAPI
GdipDrawPolygonI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                         INT count);

GpStatus WINGDIPAPI
GdipDrawPath(GpGraphics *graphics, GpPen *pen, GpPath *path);

GpStatus WINGDIPAPI
GdipDrawCurve(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawCurveI(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count);

GpStatus WINGDIPAPI
GdipDrawCurve2(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
                       INT count, REAL tension);

GpStatus WINGDIPAPI
GdipDrawCurve2I(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                       INT count, REAL tension);

GpStatus WINGDIPAPI
GdipDrawCurve3(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPointF *points,
               INT count, INT offset, INT numberOfSegments, REAL tension);

GpStatus WINGDIPAPI
GdipDrawCurve3I(GpGraphics *graphics, GpPen *pen, GDIPCONST GpPoint *points,
                INT count, INT offset, INT numberOfSegments, REAL tension);

GpStatus WINGDIPAPI
GdipDrawClosedCurve(GpGraphics *graphics, GpPen *pen,
                    GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipDrawClosedCurveI(GpGraphics *graphics, GpPen *pen,
                     GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipDrawClosedCurve2(GpGraphics *graphics, GpPen *pen,
                     GDIPCONST GpPointF *points, INT count, REAL tension);

GpStatus WINGDIPAPI
GdipDrawClosedCurve2I(GpGraphics *graphics, GpPen *pen,
                      GDIPCONST GpPoint *points, INT count, REAL tension);

GpStatus WINGDIPAPI
GdipGraphicsClear(GpGraphics *graphics, ARGB color);

GpStatus WINGDIPAPI
GdipFillRectangle(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
                  REAL width, REAL height);

GpStatus WINGDIPAPI
GdipFillRectangleI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
                   INT width, INT height);

GpStatus WINGDIPAPI
GdipFillRectangles(GpGraphics *graphics, GpBrush *brush,
                   GDIPCONST GpRectF *rects, INT count);

GpStatus WINGDIPAPI
GdipFillRectanglesI(GpGraphics *graphics, GpBrush *brush,
                    GDIPCONST GpRect *rects, INT count);

GpStatus WINGDIPAPI
GdipFillPolygon(GpGraphics *graphics, GpBrush *brush,
                GDIPCONST GpPointF *points, INT count, GpFillMode fillMode);

GpStatus WINGDIPAPI
GdipFillPolygonI(GpGraphics *graphics, GpBrush *brush,
                 GDIPCONST GpPoint *points, INT count, GpFillMode fillMode);

GpStatus WINGDIPAPI
GdipFillPolygon2(GpGraphics *graphics, GpBrush *brush,
                 GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipFillPolygon2I(GpGraphics *graphics, GpBrush *brush,
                  GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipFillEllipse(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
                REAL width, REAL height);

GpStatus WINGDIPAPI
GdipFillEllipseI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
                 INT width, INT height);

GpStatus WINGDIPAPI
GdipFillPie(GpGraphics *graphics, GpBrush *brush, REAL x, REAL y,
            REAL width, REAL height, REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipFillPieI(GpGraphics *graphics, GpBrush *brush, INT x, INT y,
             INT width, INT height, REAL startAngle, REAL sweepAngle);

GpStatus WINGDIPAPI
GdipFillPath(GpGraphics *graphics, GpBrush *brush, GpPath *path);

GpStatus WINGDIPAPI
GdipFillClosedCurve(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPointF *points, INT count);

GpStatus WINGDIPAPI
GdipFillClosedCurveI(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPoint *points, INT count);

GpStatus WINGDIPAPI
GdipFillClosedCurve2(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPointF *points, INT count,
                              REAL tension, GpFillMode fillMode);

GpStatus WINGDIPAPI
GdipFillClosedCurve2I(GpGraphics *graphics, GpBrush *brush,
                              GDIPCONST GpPoint *points, INT count,
                              REAL tension, GpFillMode fillMode);

GpStatus WINGDIPAPI
GdipFillRegion(GpGraphics *graphics, GpBrush *brush,
                        GpRegion *region);

#if (GDIPVER >= 0x0110)
GpStatus
WINGDIPAPI
GdipDrawImageFX(
    GpGraphics *graphics,
    GpImage *image,
    GpRectF *source,
    GpMatrix *xForm,
    CGpEffect *effect,
    GpImageAttributes *imageAttributes,
    GpUnit srcUnit
    );
#endif //(GDIPVER >= 0x0110)

GpStatus WINGDIPAPI
GdipDrawImage(GpGraphics *graphics, GpImage *image, REAL x, REAL y);

GpStatus WINGDIPAPI
GdipDrawImageI(GpGraphics *graphics, GpImage *image, INT x, INT y);

GpStatus WINGDIPAPI
GdipDrawImageRect(GpGraphics *graphics, GpImage *image, REAL x, REAL y,
                           REAL width, REAL height);

GpStatus WINGDIPAPI
GdipDrawImageRectI(GpGraphics *graphics, GpImage *image, INT x, INT y,
                           INT width, INT height);

GpStatus WINGDIPAPI
GdipDrawImagePoints(GpGraphics *graphics, GpImage *image,
                             GDIPCONST GpPointF *dstpoints, INT count);

GpStatus WINGDIPAPI
GdipDrawImagePointsI(GpGraphics *graphics, GpImage *image,
                             GDIPCONST GpPoint *dstpoints, INT count);

GpStatus WINGDIPAPI
GdipDrawImagePointRect(GpGraphics *graphics, GpImage *image, REAL x,
                                REAL y, REAL srcx, REAL srcy, REAL srcwidth,
                                REAL srcheight, GpUnit srcUnit);

GpStatus WINGDIPAPI
GdipDrawImagePointRectI(GpGraphics *graphics, GpImage *image, INT x,
                                INT y, INT srcx, INT srcy, INT srcwidth,
                                INT srcheight, GpUnit srcUnit);

GpStatus WINGDIPAPI
GdipDrawImageRectRect(GpGraphics *graphics, GpImage *image, REAL dstx,
                      REAL dsty, REAL dstwidth, REAL dstheight,
                      REAL srcx, REAL srcy, REAL srcwidth, REAL srcheight,
                      GpUnit srcUnit,
                      GDIPCONST GpImageAttributes* imageAttributes,
                      DrawImageAbort callback, VOID * callbackData);

GpStatus WINGDIPAPI
GdipDrawImageRectRectI(GpGraphics *graphics, GpImage *image, INT dstx,
                       INT dsty, INT dstwidth, INT dstheight,
                       INT srcx, INT srcy, INT srcwidth, INT srcheight,
                       GpUnit srcUnit,
                       GDIPCONST GpImageAttributes* imageAttributes,
                       DrawImageAbort callback, VOID * callbackData);

GpStatus WINGDIPAPI
GdipDrawImagePointsRect(GpGraphics *graphics, GpImage *image,
                        GDIPCONST GpPointF *points, INT count, REAL srcx,
                        REAL srcy, REAL srcwidth, REAL srcheight,
                        GpUnit srcUnit,
                        GDIPCONST GpImageAttributes* imageAttributes,
                        DrawImageAbort callback, VOID * callbackData);

GpStatus WINGDIPAPI
GdipDrawImagePointsRectI(GpGraphics *graphics, GpImage *image,
                         GDIPCONST GpPoint *points, INT count, INT srcx,
                         INT srcy, INT srcwidth, INT srcheight,
                         GpUnit srcUnit,
                         GDIPCONST GpImageAttributes* imageAttributes,
                         DrawImageAbort callback, VOID * callbackData);

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST PointF &      destPoint,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Point &       destPoint,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST RectF &       destRect,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Rect &        destRect,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPoints(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST PointF *      destPoints,
    INT                     count,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileDestPointsI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Point *       destPoints,
    INT                     count,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoint(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST PointF &      destPoint,
    GDIPCONST RectF &       srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Point &       destPoint,
    GDIPCONST Rect &        srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRect(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST RectF &       destRect,
    GDIPCONST RectF &       srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestRectI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Rect &        destRect,
    GDIPCONST Rect &        srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPoints(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST PointF *      destPoints,
    INT                     count,
    GDIPCONST RectF &       srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipEnumerateMetafileSrcRectDestPointsI(
    GpGraphics *            graphics,
    GDIPCONST GpMetafile *  metafile,
    GDIPCONST Point *       destPoints,
    INT                     count,
    GDIPCONST Rect &        srcRect,
    Unit                    srcUnit,
    EnumerateMetafileProc   callback,
    VOID *                  callbackData,
    GDIPCONST GpImageAttributes *     imageAttributes
    );

GpStatus WINGDIPAPI
GdipPlayMetafileRecord(
    GDIPCONST GpMetafile *  metafile,
    EmfPlusRecordType       recordType,
    UINT                    flags,
    UINT                    dataSize,
    GDIPCONST BYTE *        data
    );

GpStatus WINGDIPAPI
GdipSetClipGraphics(GpGraphics *graphics, GpGraphics *srcgraphics,
                    CombineMode combineMode);

GpStatus WINGDIPAPI
GdipSetClipRect(GpGraphics *graphics, REAL x, REAL y,
                         REAL width, REAL height, CombineMode combineMode);

GpStatus WINGDIPAPI
GdipSetClipRectI(GpGraphics *graphics, INT x, INT y,
                         INT width, INT height, CombineMode combineMode);

GpStatus WINGDIPAPI
GdipSetClipPath(GpGraphics *graphics, GpPath *path, CombineMode combineMode);

GpStatus WINGDIPAPI
GdipSetClipRegion(GpGraphics *graphics, GpRegion *region,
                  CombineMode combineMode);

GpStatus WINGDIPAPI
GdipSetClipHrgn(GpGraphics *graphics, HRGN hRgn, CombineMode combineMode);

GpStatus WINGDIPAPI
GdipResetClip(GpGraphics *graphics);

GpStatus WINGDIPAPI
GdipTranslateClip(GpGraphics *graphics, REAL dx, REAL dy);

GpStatus WINGDIPAPI
GdipTranslateClipI(GpGraphics *graphics, INT dx, INT dy);

GpStatus WINGDIPAPI
GdipGetClip(GpGraphics *graphics, GpRegion *region);

GpStatus WINGDIPAPI
GdipGetClipBounds(GpGraphics *graphics, GpRectF *rect);

GpStatus WINGDIPAPI
GdipGetClipBoundsI(GpGraphics *graphics, GpRect *rect);

GpStatus WINGDIPAPI
GdipIsClipEmpty(GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipGetVisibleClipBounds(GpGraphics *graphics, GpRectF *rect);

GpStatus WINGDIPAPI
GdipGetVisibleClipBoundsI(GpGraphics *graphics, GpRect *rect);

GpStatus WINGDIPAPI
GdipIsVisibleClipEmpty(GpGraphics *graphics, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisiblePoint(GpGraphics *graphics, REAL x, REAL y,
                           BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisiblePointI(GpGraphics *graphics, INT x, INT y,
                           BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisibleRect(GpGraphics *graphics, REAL x, REAL y,
                           REAL width, REAL height, BOOL *result);

GpStatus WINGDIPAPI
GdipIsVisibleRectI(GpGraphics *graphics, INT x, INT y,
                           INT width, INT height, BOOL *result);

GpStatus WINGDIPAPI
GdipSaveGraphics(GpGraphics *graphics, GraphicsState *state);

GpStatus WINGDIPAPI
GdipRestoreGraphics(GpGraphics *graphics, GraphicsState state);

GpStatus WINGDIPAPI
GdipBeginContainer(GpGraphics *graphics, GDIPCONST GpRectF* dstrect,
                   GDIPCONST GpRectF *srcrect, GpUnit unit, 
                   GraphicsContainer *state);

GpStatus WINGDIPAPI
GdipBeginContainerI(GpGraphics *graphics, GDIPCONST GpRect* dstrect,
                    GDIPCONST GpRect *srcrect, GpUnit unit, 
                    GraphicsContainer *state);

GpStatus WINGDIPAPI
GdipBeginContainer2(GpGraphics *graphics, GraphicsContainer* state);

GpStatus WINGDIPAPI
GdipEndContainer(GpGraphics *graphics, GraphicsContainer state);

GpStatus
GdipGetMetafileHeaderFromWmf(
    HMETAFILE           hWmf,
    GDIPCONST WmfPlaceableFileHeader *     wmfPlaceableFileHeader,
    MetafileHeader *    header
    );

GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromEmf(
    HENHMETAFILE        hEmf,
    MetafileHeader *    header
    );

GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromFile(
    GDIPCONST WCHAR*        filename,
    MetafileHeader *    header
    );

GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromStream(
    IStream *           stream,
    MetafileHeader *    header
    );

GpStatus
WINGDIPAPI
GdipGetMetafileHeaderFromMetafile(
    GpMetafile *        metafile,
    MetafileHeader *    header
    );

GpStatus
WINGDIPAPI
GdipGetHemfFromMetafile(
    GpMetafile *        metafile,
    HENHMETAFILE *      hEmf
    );

GpStatus WINGDIPAPI
GdipCreateStreamOnFile(GDIPCONST WCHAR * filename, UINT access, 
                       IStream **stream);

GpStatus WINGDIPAPI
GdipCreateMetafileFromWmf(HMETAFILE hWmf, BOOL deleteWmf,
                          GDIPCONST WmfPlaceableFileHeader * wmfPlaceableFileHeader, 
                          GpMetafile **metafile);

GpStatus WINGDIPAPI
GdipCreateMetafileFromEmf(HENHMETAFILE hEmf, BOOL deleteEmf,
                          GpMetafile **metafile);

GpStatus WINGDIPAPI
GdipCreateMetafileFromFile(GDIPCONST WCHAR* file, GpMetafile **metafile);

GpStatus WINGDIPAPI
GdipCreateMetafileFromWmfFile(GDIPCONST WCHAR* file, 
                              GDIPCONST WmfPlaceableFileHeader * wmfPlaceableFileHeader, 
                              GpMetafile **metafile);

GpStatus WINGDIPAPI
GdipCreateMetafileFromStream(IStream * stream, GpMetafile **metafile);


GpStatus WINGDIPAPI
GdipRecordMetafile(
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRectF * frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipRecordMetafileI(
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRect *  frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipRecordMetafileFileName(
    GDIPCONST WCHAR*    fileName,
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRectF * frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipRecordMetafileFileNameI(
    GDIPCONST WCHAR*    fileName,
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRect *  frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipRecordMetafileStream(
    IStream *           stream,
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRectF * frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipRecordMetafileStreamI(
    IStream *           stream,
    HDC                 referenceHdc,
    EmfType             type,
    GDIPCONST GpRect *  frameRect,
    MetafileFrameUnit   frameUnit,
    GDIPCONST WCHAR *   description,
    GpMetafile **       metafile
    );

GpStatus WINGDIPAPI
GdipSetMetafileDownLevelRasterizationLimit(
    GpMetafile *            metafile,
    UINT                    metafileRasterizationLimitDpi
    );

GpStatus WINGDIPAPI
GdipGetMetafileDownLevelRasterizationLimit(
    GDIPCONST GpMetafile *  metafile,
    UINT *                  metafileRasterizationLimitDpi
    );

GpStatus WINGDIPAPI
GdipGetImageDecodersSize(_Out_ UINT *numDecoders, _Out_ _Out_range_(>=, (*numDecoders) * sizeof(ImageCodecInfo)) UINT *size);

GpStatus WINGDIPAPI
GdipGetImageDecoders(_In_ UINT numDecoders,
                     _In_ UINT size,
                     _Out_writes_bytes_(size) ImageCodecInfo *decoders);

GpStatus WINGDIPAPI
GdipGetImageEncodersSize(_Out_ UINT *numEncoders, _Out_ _Out_range_(>=, (*numEncoders) * sizeof(ImageCodecInfo)) UINT *size);

GpStatus WINGDIPAPI
GdipGetImageEncoders(_In_ UINT numEncoders,
                     _In_ UINT size,
                     _Out_writes_bytes_(size) ImageCodecInfo *encoders);

GpStatus WINGDIPAPI
GdipComment(GpGraphics* graphics, UINT sizeData, GDIPCONST BYTE * data);

//----------------------------------------------------------------------------
// FontFamily APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateFontFamilyFromName(GDIPCONST WCHAR *name,
                             GpFontCollection *fontCollection,
                             GpFontFamily **fontFamily);

GpStatus WINGDIPAPI
GdipDeleteFontFamily(GpFontFamily *fontFamily);

GpStatus WINGDIPAPI
GdipCloneFontFamily(GpFontFamily *fontFamily, GpFontFamily **clonedFontFamily);

GpStatus WINGDIPAPI
GdipGetGenericFontFamilySansSerif(GpFontFamily **nativeFamily);

GpStatus WINGDIPAPI
GdipGetGenericFontFamilySerif(GpFontFamily **nativeFamily);

GpStatus WINGDIPAPI
GdipGetGenericFontFamilyMonospace(GpFontFamily **nativeFamily);


GpStatus WINGDIPAPI
GdipGetFamilyName(
    GDIPCONST GpFontFamily              *family,
    _Out_writes_(LF_FACESIZE) LPWSTR    name,
    LANGID                              language
);

GpStatus   WINGDIPAPI
GdipIsStyleAvailable(GDIPCONST GpFontFamily *family, INT style, 
                     BOOL * IsStyleAvailable);

GpStatus WINGDIPAPI
GdipFontCollectionEnumerable(
    GpFontCollection* fontCollection,
    GpGraphics* graphics,
    INT *       numFound
);

GpStatus WINGDIPAPI GdipFontCollectionEnumerate(
    GpFontCollection* fontCollection,
    INT             numSought,
    GpFontFamily*   gpfamilies[],
    INT*            numFound,
    GpGraphics*     graphics
);

GpStatus WINGDIPAPI
GdipGetEmHeight(GDIPCONST GpFontFamily *family, INT style, 
                UINT16 * EmHeight);

GpStatus WINGDIPAPI
GdipGetCellAscent(GDIPCONST GpFontFamily *family, INT style,
                  UINT16 * CellAscent);

GpStatus WINGDIPAPI
GdipGetCellDescent(GDIPCONST GpFontFamily *family, INT style, 
                   UINT16 * CellDescent);

GpStatus WINGDIPAPI
GdipGetLineSpacing(GDIPCONST GpFontFamily *family, INT style, 
                   UINT16 * LineSpacing);


//----------------------------------------------------------------------------
// Font APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateFontFromDC(
    HDC        hdc,
    GpFont   **font
);

GpStatus WINGDIPAPI
GdipCreateFontFromLogfontA(
    HDC        hdc,
    GDIPCONST LOGFONTA  *logfont,
    GpFont   **font
);

GpStatus WINGDIPAPI
GdipCreateFontFromLogfontW(
    HDC        hdc,
    GDIPCONST LOGFONTW  *logfont,
    GpFont   **font
);

GpStatus WINGDIPAPI
GdipCreateFont(
    GDIPCONST GpFontFamily  *fontFamily,
    REAL                 emSize,
    INT                  style,
    Unit                 unit,
    GpFont             **font
);

GpStatus WINGDIPAPI
GdipCloneFont(GpFont* font, GpFont** cloneFont);

GpStatus WINGDIPAPI
GdipDeleteFont(GpFont* font);

GpStatus WINGDIPAPI
GdipGetFamily(GpFont *font, GpFontFamily **family);

GpStatus WINGDIPAPI
GdipGetFontStyle(GpFont *font, INT *style);

GpStatus WINGDIPAPI
GdipGetFontSize(GpFont *font, REAL *size);

GpStatus WINGDIPAPI
GdipGetFontUnit(GpFont *font, Unit *unit);

GpStatus WINGDIPAPI
GdipGetFontHeight(GDIPCONST GpFont *font, GDIPCONST GpGraphics *graphics, 
                  REAL *height);

GpStatus WINGDIPAPI
GdipGetFontHeightGivenDPI(GDIPCONST GpFont *font, REAL dpi, REAL *height);

GpStatus WINGDIPAPI
GdipGetLogFontA(GpFont * font, GpGraphics *graphics, LOGFONTA * logfontA);

GpStatus WINGDIPAPI
GdipGetLogFontW(GpFont * font, GpGraphics *graphics, LOGFONTW * logfontW);

GpStatus WINGDIPAPI
GdipNewInstalledFontCollection(GpFontCollection** fontCollection);

GpStatus WINGDIPAPI
GdipNewPrivateFontCollection(GpFontCollection** fontCollection);

GpStatus WINGDIPAPI
GdipDeletePrivateFontCollection(GpFontCollection** fontCollection);

GpStatus WINGDIPAPI
GdipGetFontCollectionFamilyCount(
    GpFontCollection* fontCollection,
    INT *       numFound
);

GpStatus WINGDIPAPI
GdipGetFontCollectionFamilyList(
    _In_                                  GpFontCollection* fontCollection,
    _In_                                  INT             numSought,
    _Out_writes_to_(numSought, *numFound) GpFontFamily*   gpfamilies[],
    _Out_                                 INT*            numFound
);

GpStatus WINGDIPAPI
GdipPrivateAddFontFile(
    GpFontCollection* fontCollection,
    GDIPCONST WCHAR* filename
);

GpStatus WINGDIPAPI
GdipPrivateAddMemoryFont(
    GpFontCollection* fontCollection,
    GDIPCONST void* memory,
    INT length
);

//----------------------------------------------------------------------------
// Text APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipDrawString(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST RectF          *layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    GDIPCONST GpBrush        *brush
);

GpStatus WINGDIPAPI
GdipMeasureString(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST RectF          *layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    RectF                    *boundingBox,
    INT                      *codepointsFitted,
    INT                      *linesFilled
);

GpStatus
WINGDIPAPI
GdipMeasureCharacterRanges(
    GpGraphics               *graphics,
    GDIPCONST WCHAR          *string,
    INT                       length,
    GDIPCONST GpFont         *font,
    GDIPCONST RectF          &layoutRect,
    GDIPCONST GpStringFormat *stringFormat,
    INT                       regionCount,
    GpRegion                **regions
);

GpStatus WINGDIPAPI
GdipDrawDriverString(
    GpGraphics *graphics,
    GDIPCONST UINT16 *text,
    INT length,
    GDIPCONST GpFont *font,
    GDIPCONST GpBrush *brush,
    GDIPCONST PointF *positions,
    INT flags,
    GDIPCONST GpMatrix *matrix
);

GpStatus WINGDIPAPI
GdipMeasureDriverString(
    GpGraphics *graphics,
    GDIPCONST UINT16 *text,
    INT length,
    GDIPCONST GpFont *font,
    GDIPCONST PointF *positions,
    INT flags,
    GDIPCONST GpMatrix *matrix,
    RectF *boundingBox
);

//----------------------------------------------------------------------------
// String format APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateStringFormat(
    INT               formatAttributes,
    LANGID            language,
    GpStringFormat  **format
);

GpStatus WINGDIPAPI
GdipStringFormatGetGenericDefault(GpStringFormat **format);

GpStatus WINGDIPAPI
GdipStringFormatGetGenericTypographic(GpStringFormat **format);

GpStatus WINGDIPAPI
GdipDeleteStringFormat(GpStringFormat *format);

GpStatus WINGDIPAPI
GdipCloneStringFormat(GDIPCONST GpStringFormat *format, 
                      GpStringFormat **newFormat);

GpStatus WINGDIPAPI
GdipSetStringFormatFlags(GpStringFormat *format, INT flags);

GpStatus WINGDIPAPI GdipGetStringFormatFlags(GDIPCONST GpStringFormat *format, 
                                             INT *flags);

GpStatus WINGDIPAPI
GdipSetStringFormatAlign(GpStringFormat *format, StringAlignment align);

GpStatus WINGDIPAPI
GdipGetStringFormatAlign(GDIPCONST GpStringFormat *format, 
                         StringAlignment *align);

GpStatus WINGDIPAPI
GdipSetStringFormatLineAlign(GpStringFormat *format,
                             StringAlignment align);

GpStatus WINGDIPAPI
GdipGetStringFormatLineAlign(GDIPCONST GpStringFormat *format,
                             StringAlignment *align);

GpStatus WINGDIPAPI
GdipSetStringFormatTrimming(
    GpStringFormat  *format,
    StringTrimming   trimming
);

GpStatus WINGDIPAPI
GdipGetStringFormatTrimming(
    GDIPCONST GpStringFormat *format,
    StringTrimming       *trimming
);

GpStatus WINGDIPAPI
GdipSetStringFormatHotkeyPrefix(GpStringFormat *format, INT hotkeyPrefix);

GpStatus WINGDIPAPI
GdipGetStringFormatHotkeyPrefix(GDIPCONST GpStringFormat *format, 
                                INT *hotkeyPrefix);

GpStatus WINGDIPAPI
GdipSetStringFormatTabStops(GpStringFormat *format, REAL firstTabOffset, 
                            INT count, GDIPCONST REAL *tabStops);

GpStatus WINGDIPAPI
GdipGetStringFormatTabStops(GDIPCONST GpStringFormat *format, INT count, 
                            REAL *firstTabOffset, REAL *tabStops);

GpStatus WINGDIPAPI
GdipGetStringFormatTabStopCount(GDIPCONST GpStringFormat *format, INT * count);

GpStatus WINGDIPAPI
GdipSetStringFormatDigitSubstitution(GpStringFormat *format, LANGID language,
                                     StringDigitSubstitute substitute);

GpStatus WINGDIPAPI
GdipGetStringFormatDigitSubstitution(GDIPCONST GpStringFormat *format, 
                                     LANGID *language,
                                     StringDigitSubstitute *substitute);

GpStatus WINGDIPAPI
GdipGetStringFormatMeasurableCharacterRangeCount(
    GDIPCONST GpStringFormat    *format,
    INT                         *count
);

GpStatus WINGDIPAPI
GdipSetStringFormatMeasurableCharacterRanges(
    GpStringFormat              *format,
    INT                         rangeCount,
    GDIPCONST CharacterRange    *ranges
);

//----------------------------------------------------------------------------
// Cached Bitmap APIs
//----------------------------------------------------------------------------

GpStatus WINGDIPAPI
GdipCreateCachedBitmap(
    GpBitmap *bitmap,
    GpGraphics *graphics,
    GpCachedBitmap **cachedBitmap
);

GpStatus WINGDIPAPI
GdipDeleteCachedBitmap(GpCachedBitmap *cachedBitmap);

GpStatus WINGDIPAPI
GdipDrawCachedBitmap(
    GpGraphics *graphics,
    GpCachedBitmap *cachedBitmap,
    INT x,
    INT y
);

UINT WINGDIPAPI
GdipEmfToWmfBits(
    HENHMETAFILE hemf,
    UINT         cbData16,
    _Out_writes_to_opt_(cbData16, return) LPBYTE       pData16,
    INT          iMapMode,
    INT          eFlags
);

GpStatus WINGDIPAPI
GdipSetImageAttributesCachedBackground(
    GpImageAttributes *imageattr,
    BOOL enableFlag
);

GpStatus WINGDIPAPI
GdipTestControl(
    GpTestControlEnum control,
    void * param
);

GpStatus WINAPI
GdiplusNotificationHook(
    OUT ULONG_PTR *token
);

VOID WINAPI
GdiplusNotificationUnhook(
    ULONG_PTR token
);

#if (GDIPVER >= 0x0110)
GpStatus WINGDIPAPI
GdipConvertToEmfPlus(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   EmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);

GpStatus WINGDIPAPI
GdipConvertToEmfPlusToFile(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   const WCHAR* filename, 
   EmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);

GpStatus WINGDIPAPI
GdipConvertToEmfPlusToStream(
   const GpGraphics* refGraphics,
   GpMetafile*  metafile,
   INT* conversionFailureFlag,
   IStream* stream, 
   EmfType      emfType,
   const WCHAR* description,
   GpMetafile** out_metafile
);
#endif //(GDIPVER >= 0x0110)

#ifdef __cplusplus
}
#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // !_FLATAPI_H
