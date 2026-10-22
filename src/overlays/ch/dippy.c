#include "common.h"

OSThread *chdippy_entrypoint_0(void)
{
    extern u8 D_80801580_chdippy[];

    return (OSThread *) D_80801580_chdippy;
}

OSThread *chdippy_entrypoint_1(void)
{
    extern u8 D_808015C8_chdippy[];

    return (OSThread *) D_808015C8_chdippy;
}

void func_80800018_chdippy(Actor *actor) {
    struct DippyFlags {
        u8 pad[0x70];
        u8 index : 7;
        u8 pad70 : 1;
        u8 pad71;
        u16 pad72 : 6;
        u16 state : 6;
        u16 pad73 : 4;
    };
    s32 _chcredits_entrypoint_1(void);
    s32 _gccubesearch_entrypoint_3(s32, f32[3]);
    s32 _glcutDll_entrypoint_20();
    s32 func_800CBC3C(f32 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80800654_chdippy(Actor *, s32);
    f32 sp2C[3];
    s32 pad;
    s32 flag;

    flag = _glcutDll_entrypoint_20() != 0;
    if (flag) {
        flag = _chcredits_entrypoint_1() == 0x61;
    }
    _gccubesearch_entrypoint_3(0x3AD, sp2C);
    ((struct DippyFlags *)actor)->index = func_800CBC3C(sp2C) + 1;
    ((struct DippyFlags *)actor)->state = 1;
    if (func_800DA298(0x327)) {
        func_800DA544(0x328);
    }
    flag = flag ? 0xE : 1;
    func_80800654_chdippy(actor, flag);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808000D8_chdippy.s")

s32 func_80800374_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_8080047C_chdippy(Actor *, s32, s32);
    void func_80800654_chdippy(Actor *, s32);
    void func_80800CBC_chdippy(Actor *, s32, s32);
    void func_80800D44_chdippy(u8 *);

    switch (arg1) {
    case 0x2E:
        func_8080047C_chdippy(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        return 1;
    case 0xB:
        switch (arg2) {
        case 0x47:
            func_80800654_chdippy(arg0, 7);
            return 4;
        case 0x37:
            func_80800D44_chdippy((u8 *)arg0);
            if (_glcutDll_entrypoint_19(0x36)) {
                _glcutDll_entrypoint_17();
            }
            return 4;
        }
        return 3;
    case 0x95:
        if (_glcutDll_entrypoint_19(0x36)) {
            _subaddieDll_entrypoint_4(arg0, 1);
            func_80800654_chdippy(arg0, 2);
            func_80800CBC_chdippy(arg0, 0x47, 0x2030);
            return 1;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080047C_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800654_chdippy(Actor *, s32);
    switch (arg1) {
    case 0x17E9:
        func_80800654_chdippy(arg0, 6);
        break;
    case 0x17EA:
        func_80800654_chdippy(arg0, 6);
        break;
    case 0x17EB:
        func_80800654_chdippy(arg0, 0xA);
        break;
    case 0x17EC:
        func_800D0C78(0x2A, 1, 0);
        func_80800654_chdippy(arg0, 9);
        break;
    case 0x17ED:
        func_80800654_chdippy(arg0, 0xD);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800530_chdippy.s")

void func_80800654_chdippy(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void func_80800CBC_chdippy(Actor *, s32, s32);
    extern s32 D_80801610_chdippy;
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    func_80102424(arg0, arg1);
    arg0->unk64_16 = 1;
    switch (arg1) {
    case 1:
    case 2:
        arg0->unk64_16 = 0;
        break;
    case 3:
        func_800DA544(0x328);
        func_80800CBC_chdippy(arg0, 0x29, 0x30);
        break;
    case 4:
        func_80800CBC_chdippy(arg0, 0x2E, 0x30);
        break;
    case 5:
        func_80800CBC_chdippy(arg0, 0x31, 0x30);
        break;
    case 6:
        func_80800CBC_chdippy(arg0, 0x37, 0x30);
        _subaddieaudioquick_entrypoint_2(arg0, sp1C, &D_80801610_chdippy);
        break;
    case 7:
        func_80800CBC_chdippy(arg0, 0x2E, 0x30);
        break;
    case 8:
        func_80800CBC_chdippy(arg0, 0x31, 0x30);
        break;
    case 9:
        func_80800CBC_chdippy(arg0, 0x37, 0x30);
        break;
    case 10:
        func_80800CBC_chdippy(arg0, 0x34, 0x30);
        break;
    case 11:
        func_80800CBC_chdippy(arg0, 0x2E, 0x30);
        break;
    case 12:
        func_80800CBC_chdippy(arg0, 0x31, 0x30);
        break;
    case 13:
        func_80800CBC_chdippy(arg0, 0x37, 0x30);
        break;
    }
}

void func_80800800_chdippy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 func_8001211C(void);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_80101F24(Actor *);
    extern s32 D_80801480_chdippy;
    extern u32 D_808014A0_chdippy;
    extern s32 D_80801620_chdippy;
    extern u32 D_8080164C_chdippy;
    extern u32 D_8080165C_chdippy;
    extern u32 D_8080166C_chdippy;
    extern u32 D_80801688_chdippy;
    extern u32 D_80801698_chdippy;
    f32 sp34[3];
    f32 sp30;
    s32 sp2C;

    sp30 = func_80101F24(arg0);
    sp2C = func_8001211C();
    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp34);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, &D_808014A0_chdippy, &D_80801688_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_80801480_chdippy, 0.43f);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, &D_8080164C_chdippy, &D_80801698_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_8080165C_chdippy, 0.9f);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_8080166C_chdippy, 0.61f);
    if (sp30 > 0.61f && sp30 < 0.66f && !(sp2C & 1) &&
        _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp34)) {
        func_800BBCB8(sp34, NULL, 1.0f, 1, &D_80801620_chdippy);
    }
}

void func_80800948_chdippy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    extern s32 D_80801480_chdippy;
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801480_chdippy, 0.4f);
}

void func_80800990_chdippy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    extern s32 D_80801490_chdippy;
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801490_chdippy, 0.15f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808009D8_chdippy.s")

void chdippy_entrypoint_2(s32 arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808014B0_chdippy;
    func_800BBCB8(arg1, NULL, 1.2f, 1, &D_808014B0_chdippy);
}

/* extern */

void func_80800CBC_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _glcutDll_entrypoint_19(u32);

    if (arg0->unk64_20) {
        _capod_entrypoint_14();
        arg2 |= 0x2000;
    }
    if (_glcutDll_entrypoint_19(0x36) != 0) {
        arg2 |= 0x800;
    }
    _capod_entrypoint_13(arg0->unk0, NULL, arg1, arg2);
    arg0->unk64_20 = 1;
}

void func_80800D44_chdippy(u8 *arg0) {
    struct Flags {
        u8 pad[0x64];
        unsigned int : 11;
        unsigned int active : 1;
        unsigned int : 20;
    };
    void _capod_entrypoint_14(void);
    if (((struct Flags *)arg0)->active) {
        _capod_entrypoint_14();
        arg0[0x65] &= 0xFFEF;
    }
}

void func_80800D84_chdippy(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800D9C_chdippy.s")

/* extern */

s32 func_80801110_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DF500(f32, f32, f32);
    void func_800E3980(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_801015D0(Actor *);
    s32 func_80801200_chdippy();
    f32 sp34[3];

    switch (arg1) {
        case 0x95:
            func_80801200_chdippy();
            return 1;
        case 0x1F:
            if (arg0->unk64_16) {
                func_801015D0(arg0);
                func_800E3980(sp34);
                arg0->rotation[1] = func_800F1DF4(arg0->position, sp34);
                if (arg0->unk58 < 3.0f) {
                    func_800DF500(1.0f, func_800F10B4(arg0->unk58, 3.0f, 0.0f, 5.0f, 0.001f), 1.0f);
                } else {
                    func_800DF500(1.0f, 5.0f, 1.0f);
                }
            }
            return 1;
    }
    return 0;
}

s32 func_80801200_chdippy(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    s32 _glcutDll_entrypoint_20();
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    void func_800C4AF0(f32 *, void *);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_8080174C_chdippy[];
    s32 sp24;

    sp24 = func_800BEA88(1);
    if (_glcutDll_entrypoint_20() != 0) {
        arg0->unk79_4 = 2;
        *(f32 *)&arg0->actorData[0] = 0.0f;
        func_80101FDC(arg0, 3);
    } else if (_glcutDll_entrypoint_19(0x36) != 0) {
        arg0->unk58 = 6.0f;
        func_80101FDC(arg0, 2);
        arg0->unk64_16 = 1;
        *(f32 *)&arg0->actorData[2] = 30.0f;
        *(f32 *)&arg0->actorData[3] = func_800DC178(0.2f, 0.5f);
    } else if (func_800DA298(0x327) == 0) {
        arg0->unk79_4 = 2;
        *(f32 *)&arg0->actorData[0] = -2000.0f;
        func_80101FDC(arg0, 1);
        return;
    } else {
        arg0->unk79_4 = 2;
        *(f32 *)&arg0->actorData[0] = 0.0f;
        func_80101FDC(arg0, 3);
    }
    _idworldmake_entrypoint_1(sp24, 0x659, 1, 1);
    if (arg0->unk70_10 == 2) {
        func_800C4AF0((f32 *)arg0->actorData, D_8080174C_chdippy);
    }
}

/* extern */

void chdippy_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    s16 offset;
    Vtx *end;

    offset = *(f32 *)&func_80106790(arg4)->actorData[0];
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
            arg2++;
            arg1++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + offset;
        } while (arg2 < end);
    }
}
