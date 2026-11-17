#include "types.h"
#include <math.h>

f32 D_80125D20 = 0.00001f;

f32 mlAbsF(f32 value) { return fabsf(value); }

/* 1EB2C90.s: half angles through the game's sine table (func_800137AC: cos, then 800137C4: sin). */
f32 func_800137AC(f32), func_800137C4(void);
static void half_angles(const f32 angles[3], f32 c[3], f32 s[3]) {
    for (int i = 0; i < 3; i++) { c[i] = func_800137AC(angles[i] * 0.5f); s[i] = func_800137C4(); }
}

void func_800D93A0(f32 quaternion[4], f32 angles[3]) {
    f32 c[3], s[3];
    half_angles(angles, c, s);
    f32 a = c[0] * c[1], b = c[0] * s[1], cc = s[0] * c[1], d = s[0] * s[1];

    quaternion[0] = cc * c[2] + b * s[2];
    quaternion[1] = b * c[2] - cc * s[2];
    quaternion[2] = a * s[2] - d * c[2];
    quaternion[3] = a * c[2] + d * s[2];
}

void func_800D9470(f32 out[4],f32 a[4],f32 b[4]) {
    f32 x=a[0],y=a[1],z=a[2],w=a[3];
    f32 bx=b[0],by=b[1],bz=b[2],bw=b[3];
    out[0]=((x*bw+y*bz)-z*by)+w*bx;
    out[1]=((y*bw-x*bz)+z*bx)+w*by;
    out[2]=((x*by-y*bx)+z*bw)+w*bz;
    out[3]=w*bw-((x*bx+y*by)+z*bz);
}

void func_800D952C(f32 out[4],f32 angles[3]) {
    f32 c[3], s[3];
    half_angles(angles, c, s);
    f32 a = c[0] * c[1], b = c[0] * s[1], cc = s[0] * c[1], d = s[0] * s[1];
    out[0] = cc * c[2] - b * s[2]; out[1] = b * c[2] + cc * s[2];
    out[2] = a * s[2] - d * c[2]; out[3] = a * c[2] + d * s[2];
}
