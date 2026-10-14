#include "common.h"

OSThread *chboilerid_entrypoint_0(void)
{
    extern u8 D_80800D5C_chboilerid[];

    return (OSThread *) D_80800D5C_chboilerid;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080000C_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800128_chboilerid.s")

/* extern */
s32 func_808003AC_chboilerid(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    if (arg1 == 0x95) {
        _subaddielink_entrypoint_3((u8 *)func_80100094(arg0, 0U) + 0x60);
        return 1;
    }
    return 0;
}

/* extern */

void func_808003EC_chboilerid(s32 arg0) {
    s32 func_800CF494();
    s32 func_800DA524(s32);
    func_800DA524(0x66F);
    func_800CF494();
}

/* extern */

void func_80800418_chboilerid(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1(func_80100094(arg0, 0U));
}

void func_80800440_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1((u8 *)func_80100094(arg0, 0U) + 0x20);
}

void func_80800468_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1((u8 *)func_80100094(arg0, 0U) + 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800700_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080079C_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080084C_chboilerid.s")

/* extern */

void func_80800918_chboilerid(s16 *arg0, s16 *arg1, s16 *arg2) {
    f32 _mlwave_entrypoint_4(u8 *, f32, f32, f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEF94(f32 *);
    f32 sp24[3];
    f32 height;

    func_800EE88C(sp24, arg0);
    height = _mlwave_entrypoint_4((u8 *)arg2 + 0x3C, func_800EEF94(sp24), 0.0f, (f32)arg2[0x2E]);
    arg1[1] = arg0[1] + (s16) height;
}

void func_80800998_chboilerid(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_6.s")

/* extern */

s32 func_80800C48_chboilerid(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x118, -1, 0);
    if (temp_v0 != NULL) {
        _subaddielink_entrypoint_1(sp1C + 0x60, temp_v0->unk0);
        return 1;
    }
    _subaddielink_entrypoint_0(sp1C + 0x60);
    return 0;
}

/* extern */
s32 func_80800CB0_chboilerid(Actor *arg0) {
    switch (*(s16 *)&arg0->pad5E) {
        case 0xD1: return 0;
        case 0xE7: return 1;
        default: return 2;
    }
}
