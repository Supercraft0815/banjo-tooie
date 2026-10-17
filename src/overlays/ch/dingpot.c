#include "common.h"

OSThread *chdingpot_entrypoint_0(void)
{
    extern u8 D_80800500_chdingpot[];

    return (OSThread *) D_80800500_chdingpot;
}

void func_8080000C_chdingpot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.5f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dingpot/func_80800040_chdingpot.s")

s32 func_8080021C_chdingpot(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80102424(Actor *, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    extern s32 D_808005A4_chdingpot;

    switch (arg1) {
    case 0x2E:
        func_80102424(arg0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_808005A4_chdingpot, arg0->scale);
        break;
    case 0xB:
        func_800F7F98(func_800F54E4(), 0);
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_808002B4_chdingpot(Actor *arg0, f32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C301C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    s32 func_800DC128(s32, s32);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_808005B8_chdingpot;
    union SoundPair {
        s32 word;
        s16 sound[2];
    } sp2C;
    extern union SoundPair D_808005B4_chdingpot;
    s32 pad28;
    f32 *volatile sp24;

    sp2C = D_808005B4_chdingpot;
    if (func_80101E4C(arg0, arg1) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        }
        sp24 = arg0->position;
        func_800C301C(arg0->unk5F, sp2C.sound[func_800DC128(0, 2)]);
        func_800C4350(arg0->unk5F, sp24, &D_808005B8_chdingpot);
        func_800C3BDC(arg0->unk5F);
    }
}

void func_80800350_chdingpot(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808004B0_chdingpot;
    extern s32 D_808005C8_chdingpot;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_808005C8_chdingpot, &D_808004B0_chdingpot, 5);
}

void func_80800388_chdingpot(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C9C04(f32, u32, u32);
    s32 func_800DA298(s32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F4CEC(s32, u32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F64A4(s32, s32);
    s32 func_800F7F98(s32, u32);
    s32 func_800F82D4(s32, s32);
    void func_80102424(Actor *, s32);
    extern s32 D_808005D8_chdingpot;
    s32 temp_s0;
    f32 sp28[3];
    f32 *sp24;

    if (func_800DA298(0x1AC) != 0) {
        temp_s0 = _plsu_entrypoint_3((&arg0)[0]->unk0);
        if ((func_800F54E4() == temp_s0) && (temp_s0 != -1) && (func_800F64A4(temp_s0, 0xB) != 0)) {
            func_800F5A00(temp_s0, sp28);
            if (func_800EEB40(sp24 = (&arg0)[0]->position, sp28) < 10000.0f) {
                _subaddieaudioquick_entrypoint_2(arg0, sp24, &D_808005D8_chdingpot);
                _subaddieDll_entrypoint_4(arg0, 1);
                func_80102424(arg0, 3);
                func_800F82D4(temp_s0, 2);
                func_800F7F98(temp_s0, 1);
                _capod_entrypoint_13(arg0->unk0, 0, 2, 0x10);
                func_800F4CEC(temp_s0, 0x60);
                func_800C9C04(0.5f, 0x15, 0x55F0);
            }
        }
    }
}
