#ifndef BT_ML_SPLINE_H
#define BT_ML_SPLINE_H
#include "types.h"

typedef void (*SplineDerivativeFunc)(f32, s32, void *, f32 *);
void mlspline_entrypoint_0(f32, s32, void *, f32 *);
void mlspline_entrypoint_2(f32, s32, void *, f32 *);
void mlspline_entrypoint_4(f32, s32, void *, f32 *);
void mlspline_entrypoint_5(f32, s32, void *, f32 *);
void mlspline_entrypoint_6(f32, s32, void *, f32 *);
void mlspline_entrypoint_7(f32, s32, void *, f32 *);
void mlspline_entrypoint_8(f32, s32, void *, f32 *);
void mlspline_entrypoint_10(f32, s32, void *, f32 *);
f32 mlspline_entrypoint_11(s32, void *, f32, f32, SplineDerivativeFunc);
f32 mlspline_entrypoint_12(s32, void *, f32, f32, s32, SplineDerivativeFunc);
f32 mlspline_entrypoint_13(s32, void *, f32, f32, f32, SplineDerivativeFunc);

#endif
