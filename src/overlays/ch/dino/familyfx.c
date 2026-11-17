#include "common.h"
struct FamilyFxColor { s32 rgba[4]; };
void chdinofamilyfx_entrypoint_0(Actor *arg0) {

    extern struct FamilyFxColor D_80800BC0_chdinofamilyfx;
    extern u8 D_80800BD0_chdinofamilyfx[];
    extern u8 D_80800BF8_chdinofamilyfx[];
    extern u8 D_80800C20_chdinofamilyfx[];
    s32 _subaddieskeleton_entrypoint_0(Actor *arg0, s32 arg1, f32 *arg2);
    void func_80800A28_chdinofamilyfx(f32 *, f32, s32, void *);
    void func_800C4140(s32, f32 *, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C(void);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    f32 sp9C[3];
    f32 sp90[3];
    s32 sp8C;
    struct FamilyFxColor sp7C;
    s32 sp78;
    s32 sp74;
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    s32 sp40;
    s32 sp3C;
    f32 sp30[3];
    s32 sp2C;

    switch (func_801022E4(arg0)) {
        case 0x3F7:
            if (func_80101E14(arg0, 0.04f)) {
                func_800C4140(0x7FEDAD02, &arg0->position[0], 0x07D0012C);
            } else if (func_80101E14(arg0, 0.17f)) {
                func_800C4140(0x930DAD02, &arg0->position[0], 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.37f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x2B, sp9C);
                func_80800A28_chdinofamilyfx(sp9C, arg0->rotation[1], 2, D_80800BD0_chdinofamilyfx);
                func_800C4140(0xA62FA503, &arg0->position[0], 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.4f)) {
                sp8C = func_800EA05C() == 0x118;
                _subaddieskeleton_entrypoint_0(arg0, 0x10, sp90);
                func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 45.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 45.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 6, sp90);
                func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 135.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 135.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp90);
                func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 225.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 225.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp90);
                func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 315.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, arg0->rotation[1] + 315.0f, 1, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4A, &arg0->position[0], 0x07D0012C);
            }
            break;
        case 0x14D:
            sp7C = D_80800BC0_chdinofamilyfx;
            if (func_80101E14(arg0, 0.34f) || func_80101E14(arg0, 0.64f)) {
                func_800C4140(0x99738D51, &arg0->position[0], 0x07D0012C);
            } else if (func_80101E14(arg0, 0.76f)) {
                func_800C4140((((u32)(func_800DC178(1.0f, 1.1f) * 1023.0f) & 0x7FF) << 21) + 0xDAD33, &arg0->position[0], 0x07D0012C);
            }
            break;
        case 0x14C:
            sp78 = func_800EA05C() == 0x118;
            sp74 = func_800EA05C() == 0x114 || sp78;
            if (func_80101E14(arg0, 0.49f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp68);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp68, arg0->rotation[1] + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp68, arg0->rotation[1] + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4B, sp68, 0x07D0012C);
            } else if (func_80101E14(arg0, 0.72f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp5C);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp5C, arg0->rotation[1] + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp5C, arg0->rotation[1] + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4B, sp5C, 0x07D0012C);
            } else if (func_80101E14(arg0, 0.55f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x10, sp50);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp50, arg0->rotation[1] + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp50, arg0->rotation[1] + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
            } else if (func_80101E14(arg0, 0.6f)) {
                _subaddieskeleton_entrypoint_0(arg0, 6, sp44);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp44, arg0->rotation[1] + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp44, arg0->rotation[1] + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
            }
            break;
        case 0x3F8:
            if (func_80101E14(arg0, 0.19f) || func_80101E14(arg0, 0.46f)) {
                sp40 = 0x44B;
                sp3C = 1;
            } else if (func_80101E14(arg0, 0.8f)) {
                sp40 = 0x44A;
                sp3C = 2;
            } else {
                sp40 = 0;
            }
            if (sp40) {
                sp2C = func_800EA05C() == 0x118;
                _subaddieskeleton_entrypoint_0(arg0, 0x10, sp30);
                func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 45.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 45.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 6, sp30);
                func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 135.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 135.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp30);
                func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 225.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 225.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp30);
                func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 315.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, arg0->rotation[1] + 315.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140((sp40 & 0x7FF) + 0x7FF38800, &arg0->position[0], 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.65f)) {
                func_800C4140(0x7FEDAE1F, &arg0->position[0], 0x07D0012C);
            }
            break;
    }
}

void func_80800A28_chdinofamilyfx(f32 *arg0, f32 arg1, s32 arg2, void *arg3) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA450(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    s32 pad;
    f32 sp40[3];
    f32 sp34[3];
    BtIntPtr temp_s0;

    temp_s0 = func_800B53A4(arg2);
    func_800EEC30(sp40, 10.0f, arg1, 200.0f);
    func_800EEC30(sp34, 25.0f, arg1, 300.0f);
    func_800BA930(temp_s0, (s32)sp40[0], (s32)sp40[1], (s32)sp40[2],
                 (s32)sp34[0], (s32)sp34[1], (s32)sp34[2]);
    func_800EF334(sp40, -0.5f);
    func_800EF334(sp34, -0.5f);
    func_800BA450(temp_s0, (s32)sp40[0], -200, (s32)sp40[2],
                 (s32)sp34[0], -400, (s32)sp34[2]);
    func_800BABB8(temp_s0, arg0, NULL, 1.0f, arg3);
    func_800BA22C(temp_s0, arg2);
}
/* data_to_c.py: from asm/data/overlays/ch/dino/familyfx.data.s */
struct FamilyFxColor D_80800BC0_chdinofamilyfx BT_DATA(4, overlays_ch_dino_familyfx, 0x0) = { { 1051595899, 1060320051, 1062333317, -1082130432 } };
u8 D_80800BD0_chdinofamilyfx [40] BT_DATA(4, overlays_ch_dino_familyfx, 0x10) = { 0, 0x1D, 9, 0xDC, 0, 0x2B, 1, 0, 1, 0x80, 0, 0x22, 0, 0x80, 1, 0, 2, 0, 4, 0, 0, 0x15, 0, 0x33, 0, 0x33, 0, 0x19, 0, 0, 0, 0x12, 0, 0x20, 0xC8, 0xC8, 0x64, 0x73, 0, 0 };
u8 D_80800BF8_chdinofamilyfx [40] BT_DATA(4, overlays_ch_dino_familyfx, 0x38) = { 0, 0x1D, 9, 0xC9, 0, 0x2B, 1, 0, 1, 0x80, 0, 0x22, 0, 0x80, 1, 0, 2, 0, 2, 0, 0, 0x15, 0, 0x33, 0, 0x33, 0, 0x19, 0, 0, 0, 7, 0, 0x20, 0x8C, 0x78, 0x28, 0x82, 0, 0 };
u8 D_80800C20_chdinofamilyfx [48] BT_DATA(4, overlays_ch_dino_familyfx, 0x60) = { 0, 0x1D, 8, 0xA2, 0, 0x16, 0x14, 4, 0, 0x2B, 1, 0x80, 2, 0, 0, 0x22, 2, 0, 1, 0x80, 1, 0, 1, 0, 0, 0x15, 0, 0x19, 0, 0xE6, 0, 0x27, 0, 0x64, 0, 0x64, 0, 0xC8, 0, 0xC8, 0, 0, 0, 0, 0, 0, 0, 0 };
