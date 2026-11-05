#include "types.h"
#include <math.h>

f32 D_80125D20 = 0.00001f;

f32 mlAbsF(f32 value) { return fabsf(value); }

/* Host angle helpers use libm rather than the N64 lookup-table quantization. */
f32 func_800136E4(f32 degrees) {
    f32 result = fmodf(degrees, 360.0f);
    return result < 0.0f ? result + 360.0f : result;
}

f32 func_80013728(f32 degrees) {
    f32 result = fmodf(degrees, 360.0f);
    if (result >= 180.0f) result -= 360.0f;
    if (result < -180.0f) result += 360.0f;
    return result;
}

f32 func_80013B70(f32 y, f32 x, f32 radius) {
    f32 angle;
    if (y == 0.0f) return x < 0.0f ? 180.0f : 0.0f;
    if (x == 0.0f) return y > 0.0f ? 90.0f : 270.0f;
    angle = asinf(fmaxf(-1.0f, fminf(1.0f, y / radius))) * 57.29577951308232f;
    if (x < 0.0f) angle = 180.0f - angle;
    return angle < 0.0f ? angle + 360.0f : angle;
}

f32 func_80013B7C(f32 y, f32 x) {
    return func_80013B70(y, x, sqrtf(x * x + y * y));
}

/* Host libm uses degrees here but does not reproduce N64 table quantization. */
f32 func_80013970(f32 degrees) {
    return sinf(degrees * 0.017453292519943295f);
}
f32 func_800139F8(f32 degrees) {return tanf(degrees*0.017453292519943295f);}

f32 func_80013A7C(f32 cosine) {
    return acosf(cosine) * 57.29577951308232f;
}

void func_800D93A0(f32 quaternion[4], f32 angles[3]) {
    f32 x = angles[0] * 0.008726646259971648f;
    f32 y = angles[1] * 0.008726646259971648f;
    f32 z = angles[2] * 0.008726646259971648f;
    f32 cx = cosf(x), sx = sinf(x);
    f32 cy = cosf(y), sy = sinf(y);
    f32 cz = cosf(z), sz = sinf(z);
    f32 a = cx * cy, b = cx * sy, c = sx * cy, d = sx * sy;

    quaternion[0] = c * cz + b * sz;
    quaternion[1] = b * cz - c * sz;
    quaternion[2] = a * sz - d * cz;
    quaternion[3] = a * cz + d * sz;
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
    f32 x=angles[0]*0.008726646259971648f,y=angles[1]*0.008726646259971648f,z=angles[2]*0.008726646259971648f;
    f32 cx=cosf(x),sx=sinf(x),cy=cosf(y),sy=sinf(y),cz=cosf(z),sz=sinf(z);
    f32 a=cx*cy,b=cx*sy,c=sx*cy,d=sx*sy;
    out[0]=c*cz-b*sz;out[1]=b*cz+c*sz;
    out[2]=a*sz-d*cz;out[3]=a*cz+d*sz;
}
