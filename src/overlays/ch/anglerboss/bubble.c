#include "common.h"

OSThread *changlerbossbubble_entrypoint_0(void)
{
    extern u8 D_808005D0_changlerbossbubble[];

    return (OSThread *) D_808005D0_changlerbossbubble;
}

/* extern */

void func_8080000C_changlerbossbubble(void *arg0) {
    s32 func_800EC75C(s32, s32 *);
    s32 func_800EFD4C(s32);
    s32 sp1C[3];

    func_800EC75C((*(s32 *)((s8 *)(arg0) + (0))), sp1C);
    func_800EFD4C((*(s32 *)((s8 *)(arg0) + (0))) + 0x1E);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800054_changlerbossbubble.s")

/* extern */

s32 func_80800194_changlerbossbubble(s32 arg0) {
    s32 func_800F64A4(s32, s32);
    s32 func_800F6D24(s32);
    s32 func_800F8B88();
    if (func_800F64A4(arg0, 0xA01) == 0) {
        return 0;
    }
    if (func_800F6D24(arg0) == 0) {
        return 1;
    }
    if (func_800F8B88() == 3) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800200_changlerbossbubble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800334_changlerbossbubble.s")

/* extern */

void func_80800450_changlerbossbubble(u8 *arg0) {
    s32 func_800F5BF0(s32, u8 *, u8 *);
    func_800F5BF0((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0 + 4, arg0);
}

/* extern */

void func_80800480_changlerbossbubble(Actor *arg0, s32 arg1) {
    s32 _chbubble_entrypoint_0(s32, f32 *, f32 *, f32, f32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F13C4(f32, f32);
    s32 func_800F18FC(f32 *, f32 *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp30[2];

    func_800EE7F8(sp38, arg0->position);
    func_800E3980(sp44);
    func_800F18FC(sp38, sp44, sp30);
    func_800EEBF0(sp44, sp30, 75.0f);
    func_800EF04C(sp38, sp44);
    sp30[0] = func_80013970((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.1f + 1.0f;
    sp30[1] = func_800138D0((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.15f + 1.0f;
    arg0->unk7C_12 = _chbubble_entrypoint_0(arg1, sp38, sp30, arg0->scale, 0.0f);
}
