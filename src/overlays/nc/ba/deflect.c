#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/deflect/ncbadeflect_entrypoint_0.s")

void ncbadeflect_entrypoint_1(s32 arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F13F0(f32, f32);
    void func_80111094(s32, s32);
    void func_801110C4(s32, u8 *);
    f32 sqrtf(f32);
    f32 pad[2];
    f32 radius;
    f32 amount;
    f32 position[3];
    f32 direction[3];
    f32 origin[3];
    f32 distance;
    f32 randomY;

    func_800EFA4C(origin, arg1[0], arg1[1] + arg2, arg1[2]);
    func_80111094(arg0, (s32)position);
    func_800EFB24(direction, position, origin);
    radius = arg3 + 80.0f;
    distance = direction[0] * direction[0] + direction[1] * direction[1] + direction[2] * direction[2];
    if (!(radius * radius < distance)) {
        distance = sqrtf(distance);
        amount = func_800F13F0(func_800D8FF8() * arg4, radius - distance);
        if (distance == 0.0f) {
            distance = func_800DC0C0();
            randomY = func_800DC0C0();
            func_800EFA4C(direction, distance, randomY, func_800DC0C0());
        }
        func_800EF368(direction, amount);
        func_800EF04C(position, direction);
        func_801110C4(arg0, (u8 *)position);
    }
}
