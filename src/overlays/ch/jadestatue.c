#include "common.h"

OSThread *chjadestatue_entrypoint_0(void)
{
    extern u8 D_80800310_chjadestatue[];

    return (OSThread *) D_80800310_chjadestatue;
}

/* extern */

void func_8080000C_chjadestatue(Actor *arg0) {
    s32 func_800D035C(s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *);
    void func_80102FDC(Actor *, f32);
    u32 func_8010A5B0(Actor *, s32);
    s32 sp24;
    s32 temp_at;

    func_80102FDC(arg0, 0.75f);
    sp24 = func_800D0B68(arg0->unk74_7 - 0x32, 5);
    temp_at = func_800D035C(5);
    if ((sp24 != 0) || (temp_at >= 0x14)) {
        func_800FFA88(arg0->unk0);
    }
    arg0->unk64_20 = 0;
    func_8010A5B0(arg0, func_800DA298(0x680) == 0);
}

/* extern */

void func_80800098_chjadestatue(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800FFA88(Unk80132ED0 *);
    void func_80103110(Actor *, u32);
    void func_808001C0_chjadestatue(Actor *);
    arg0->rotation[1] -= func_800D8FF8() * 120.0f;
    func_80103110(arg0, 0);
    if (arg0->unk64_20) {
        func_808001C0_chjadestatue(arg0);
        func_800FFA88(arg0->unk0);
    }
}

void func_80800104_chjadestatue(Actor *arg0, u8 *arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_80101870(Actor* arg0, void* arg1);
    void func_80103110(Actor *, u32);
    func_80101870(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_80103110(arg0, 1);
    }
}

/* extern */

s32 func_80800140_chjadestatue(void *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_800FFAB0(Actor *);
    void func_80109EEC(s16 *, s32);
    Actor *actor = arg0;
    switch (arg1) {
        case 0x95:
            func_80109EEC(arg0, 0x44);
            break;
        case 0x3E:
            actor->unk64_20 = 1;
            _subaddieDll_entrypoint_4(arg0, 1);
            break;
        case 0x2C:
            func_800FFAB0(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808001C0_chjadestatue(Actor *arg0) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    s32 func_800D035C(s32);
    void func_800D0BD4(s32, u32);
    s32 func_800D24E8(s32, s32, u32);
    void func_800FC63C(u32, u32);
    s32 func_80101180(s32, s32, s32);
    s32 sp1C;

    _fxsparkle_entrypoint_1(arg0->position, 0xC);
    func_800D0BD4(arg0->unk74_7 - 0x32, 5);
    sp1C = func_800D035C(5);
    func_800D24E8(0xEE, sp1C, 0);
    func_800FC63C(0xE, 0x3E80);
    switch (sp1C) {
        case 10:
            func_80101180(0x2B4, 7, 0);
            return;
        case 20:
            func_80101180(0x2B4, 7, 1);
            return;
    }
}

/* extern */

void func_8080026C_chjadestatue(Actor *arg0) {
    s32 func_800D035C(s32);
    void func_800FFAB0(Actor *);
    if (func_800D035C(5) >= 0x14) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_808002A4_chjadestatue(Actor *arg0) {
    s32 func_800D035C(s32);
    s32 func_800D24E8(s32, s32, u32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800D035C(5);
    sp1C = temp_v0;
    func_800D24E8(0xEE, temp_v0, 0);
    if (sp1C >= 0x14) {
        func_80101180(0x2B3, 0x2C, 0);
        func_800FFAB0(arg0);
    }
}

OSThread *chjadestatue_entrypoint_1(void)
{
    extern u8 D_80800358_chjadestatue[];

    return (OSThread *) D_80800358_chjadestatue;
}
