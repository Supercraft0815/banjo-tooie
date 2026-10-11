#include "common.h"

void chdinofamilyfx_entrypoint_0(Actor *arg0) {
    struct FamilyFxColor { s32 rgba[4]; };
    extern struct FamilyFxColor D_80800BC0_chdinofamilyfx;
    extern u8 D_80800BD0_chdinofamilyfx[];
    extern u8 D_80800BF8_chdinofamilyfx[];
    extern u8 D_80800C20_chdinofamilyfx[];
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
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
                func_800C4140(0x7FEDAD02, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            } else if (func_80101E14(arg0, 0.17f)) {
                func_800C4140(0x930DAD02, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.37f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x2B, sp9C);
                func_80800A28_chdinofamilyfx(sp9C, *(f32 *)((u8 *)arg0 + 0x48), 2, D_80800BD0_chdinofamilyfx);
                func_800C4140(0xA62FA503, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.4f)) {
                sp8C = func_800EA05C() == 0x118;
                _subaddieskeleton_entrypoint_0(arg0, 0x10, sp90);
                func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 45.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 45.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 6, sp90);
                func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 135.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 135.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp90);
                func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 225.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 225.0f, 1, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp90);
                func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 315.0f, 1, D_80800BF8_chdinofamilyfx);
                if (sp8C) {
                    func_80800A28_chdinofamilyfx(sp90, *(f32 *)((u8 *)arg0 + 0x48) + 315.0f, 1, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4A, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            break;
        case 0x14D:
            sp7C = D_80800BC0_chdinofamilyfx;
            if (func_80101E14(arg0, 0.34f) || func_80101E14(arg0, 0.64f)) {
                func_800C4140(0x99738D51, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            } else if (func_80101E14(arg0, 0.76f)) {
                func_800C4140((((u32)(func_800DC178(1.0f, 1.1f) * 1023.0f) & 0x7FF) << 21) + 0xDAD33, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            break;
        case 0x14C:
            sp78 = func_800EA05C() == 0x118;
            sp74 = func_800EA05C() == 0x114 || sp78;
            if (func_80101E14(arg0, 0.49f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp68);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp68, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp68, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4B, sp68, 0x07D0012C);
            } else if (func_80101E14(arg0, 0.72f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp5C);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp5C, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp5C, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140(0x7FF38C4B, sp5C, 0x07D0012C);
            } else if (func_80101E14(arg0, 0.55f)) {
                _subaddieskeleton_entrypoint_0(arg0, 0x10, sp50);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp50, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp50, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 3, D_80800C20_chdinofamilyfx);
                }
            } else if (func_80101E14(arg0, 0.6f)) {
                _subaddieskeleton_entrypoint_0(arg0, 6, sp44);
                if (sp74) {
                    func_80800A28_chdinofamilyfx(sp44, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 1, D_80800BF8_chdinofamilyfx);
                }
                if (sp78) {
                    func_80800A28_chdinofamilyfx(sp44, *(f32 *)((u8 *)arg0 + 0x48) + 180.0f, 3, D_80800C20_chdinofamilyfx);
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
                func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 45.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 45.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 6, sp30);
                func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 135.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 135.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x14, sp30);
                func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 225.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 225.0f, 3, D_80800C20_chdinofamilyfx);
                }
                _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp30);
                func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 315.0f, sp3C, D_80800BF8_chdinofamilyfx);
                if (sp2C) {
                    func_80800A28_chdinofamilyfx(sp30, *(f32 *)((u8 *)arg0 + 0x48) + 315.0f, 3, D_80800C20_chdinofamilyfx);
                }
                func_800C4140((sp40 & 0x7FF) + 0x7FF38800, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            if (func_80101E14(arg0, 0.65f)) {
                func_800C4140(0x7FEDAE1F, (f32 *)((u8 *)arg0 + 4), 0x07D0012C);
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familyfx/func_80800A28_chdinofamilyfx.s")
