#ifndef BT_GUEST_MATH_H
#define BT_GUEST_MATH_H
// Basic operations are wasm instructions (guest libc.c); transcendental functions come from the host libm.
#define isnan(x) __builtin_isnan(x)
#define isinf(x) __builtin_isinf(x)
#define isfinite(x) __builtin_isfinite(x)
#define INFINITY __builtin_inff()
#define NAN __builtin_nanf("")
#define HUGE_VALF __builtin_huge_valf()
#define M_PI 3.14159265358979323846
float sqrtf(float);
double sqrt(double);
float fabsf(float);
double fabs(double);
float floorf(float);
double floor(double);
float ceilf(float);
double ceil(double);
float truncf(float);
double trunc(double);
float roundf(float);
double round(double);
float fminf(float, float);
float fmaxf(float, float);
float copysignf(float, float);
float nearbyintf(float);
float sinf(float);
float cosf(float);
float tanf(float);
float asinf(float);
float acosf(float);
float atanf(float);
float atan2f(float, float);
float powf(float, float);
float expf(float);
float logf(float);
float fmodf(float, float);
double sin(double);
double cos(double);
double tan(double);
double asin(double);
double acos(double);
double atan(double);
double atan2(double, double);
double pow(double, double);
double exp(double);
double log(double);
double fmod(double, double);
#endif
