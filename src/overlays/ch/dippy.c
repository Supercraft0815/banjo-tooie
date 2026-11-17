#include "common.h"

OSThread *chdippy_entrypoint_0(void)
{
    extern ActorData D_80801580_chdippy[];

    return (OSThread *) D_80801580_chdippy;
}

OSThread *chdippy_entrypoint_1(void)
{
    extern ActorData D_808015C8_chdippy[];

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

/* extern */

void func_808000D8_chdippy(Actor *arg0) {
    void func_80800530_chdippy(Actor *arg0);
    void func_80800654_chdippy(Actor *arg0, s32 arg1);
    void func_80800800_chdippy(Actor *arg0);
    void func_80800948_chdippy(Actor *arg0);
    void func_80800990_chdippy(Actor *arg0);
    void func_80800D44_chdippy(u8 *arg0);
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, s32);
    s32 func_808009D8_chdippy(Actor *);

    switch (((Actor *)arg0)->unk70_10) {
    case 1:
        func_80800530_chdippy(arg0);
        return;
    case 3:
        if (func_80101E14(arg0, 0x3F19999A) != 0) {
            _chintrotext_entrypoint_1(0x18B9, 0xE, 1, 0);
        }
        func_80800800_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E9, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 5);
            return;
        }
    default:
        return;
    case 4:
        func_80800948_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) {
            if (func_800DA298(0x327) != 0) {
                func_80800654_chdippy(arg0, 0xA);
                return;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EA, 7, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 5);
            return;
        }
        break;
    case 6:
        if (func_80101DDC(arg0) != 0) {
            func_80800D44_chdippy((u8 *) arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 7:
        func_80800990_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EB, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 8);
            return;
        }
        break;
    case 9:
        if (func_80101DDC(arg0) != 0) {
            func_80800D44_chdippy((u8 *) arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 10:
        func_808009D8_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EC, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 8);
            return;
        }
        break;
    case 11:
        if (func_80101DDC(arg0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17ED, 7, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 0xC);
            return;
        }
        break;
    case 13:
        if (func_80101DDC(arg0) != 0) {
            func_80800D44_chdippy((u8 *) arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 14:
        func_80800990_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80800654_chdippy(arg0, 0xF);
        }
        break;
    }
}

s32 func_80800374_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(u32);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
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

void func_80800530_chdippy(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800F1DF4(f32 *, f32 *);
    int func_800F20BC(f32, f32, f32);
    s32 func_800F4BB8(BtUIntPtr, u32, s32);
    BtUIntPtr func_800F54E4(void);
    f32 func_800F5F24(BtUIntPtr);
    s32 func_800F5FE0(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F6C5C(BtIntPtr);
    s32 func_8010D23C(void);
    void func_8010D254(f32 *);
    void func_80800654_chdippy(Actor *, s32);
    BtUIntPtr sp2C;
    f32 sp20[3];

    sp2C = func_800F54E4();
    if (func_8010D23C() && func_800F6C5C(sp2C) && func_800F64A4(sp2C, 0x601) && func_8010C500(arg0)) {
        if (!func_800DA298(0x328)) {
            func_80800654_chdippy(arg0, 3);
            return;
        }
        if (func_80016B30(0, 1) == 1 && func_800F4BB8(sp2C, -1, 0)) {
            func_8010D254(sp20);
            if (!func_800F20BC(func_800F5F24(sp2C), func_800F1DF4(sp20, arg0->position), 60.0f)) {
                func_800F5FE0(sp2C);
                return;
            }
            if (func_800DA298(0x327)) {
                func_80800654_chdippy(arg0, 0xB);
                return;
            }
            func_80800654_chdippy(arg0, 4);
        }
    }
}

void func_80800654_chdippy(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void func_80800CBC_chdippy(Actor *, s32, s32);
    extern s32 D_80801610_chdippy[4];
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
        _subaddieaudioquick_entrypoint_2(arg0, sp1C, D_80801610_chdippy);
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
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 func_8001211C(void);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_80101F24(Actor *);
    extern s32 D_80801480_chdippy[4];
    extern u32 D_808014A0_chdippy[4];
    extern s32 D_80801620_chdippy[11];
    extern u32 D_8080164C_chdippy[4];
    extern u32 D_8080165C_chdippy[4];
    extern u32 D_8080166C_chdippy[7];
    extern u32 D_80801688_chdippy[4];
    extern u32 D_80801698_chdippy[3];
    f32 sp34[3];
    f32 sp30;
    s32 sp2C;

    sp30 = func_80101F24(arg0);
    sp2C = func_8001211C();
    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp34);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, D_808014A0_chdippy, D_80801688_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, D_80801480_chdippy, 0.43f);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, D_8080164C_chdippy, D_80801698_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, D_8080165C_chdippy, 0.9f);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, D_8080166C_chdippy, 0.61f);
    if (sp30 > 0.61f && sp30 < 0.66f && !(sp2C & 1) &&
        _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp34)) {
        func_800BBCB8(sp34, NULL, 1.0f, 1, D_80801620_chdippy);
    }
}

void func_80800948_chdippy(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    extern s32 D_80801480_chdippy[4];
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, D_80801480_chdippy, 0.4f);
}

void func_80800990_chdippy(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    extern s32 D_80801490_chdippy[4];
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, D_80801490_chdippy, 0.15f);
}

s32 func_808009D8_chdippy(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    BtIntPtr func_800B53A4(s32);
    void func_800BA1D0(BtIntPtr, f32 *, f32 *, s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA544(s32 *, BtIntPtr);
    void func_800BA5A8(s16 *, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, f32, s32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DC128(s32, s32);
    f32 func_80101F24(Actor *);
#ifdef BT_NATIVE
    void chdippy_entrypoint_2(s32 arg0, f32 *arg1);
#else
    void _chdippy_entrypoint_2(void);
#endif
    extern s32 D_808014B0_chdippy[10];
    extern s32 D_808014D8_chdippy[10];
    extern u32 D_808016A4_chdippy[4]; extern u32 D_808016B4_chdippy[4];
    extern u32 D_808016C4_chdippy[6]; extern u32 D_808016DC_chdippy[3];
    extern u8 D_808016E8_chdippy[][2];
    f32 sp8C[3];
    f32 sp88;
    f32 sp7C[3];
    s32 sp78;
    f32 sp48[4][3];
    s32 i;
    BtIntPtr emitter;

    sp88 = func_80101F24(arg0);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp8C);
    _subaddieaudioquick_entrypoint_4(arg0, sp8C, D_808016A4_chdippy, D_808016C4_chdippy);
    _subaddieaudioquick_entrypoint_4(arg0, sp8C, D_808016B4_chdippy, D_808016DC_chdippy);
    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp7C) && sp7C[1] < 1500.0f) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 5, sp8C);
        sp8C[1] = 1500.0f;
        func_800BBCB8(sp8C, NULL, 1.5f, 1, D_808014B0_chdippy);
        _subaddieskeleton_entrypoint_2(arg0->unk0, 7, sp8C);
        sp8C[1] = 1500.0f;
        func_800BBCB8(sp8C, NULL, 1.5f, 1, D_808014B0_chdippy);
    }
    if (sp88 > 0.3f && arg0->unk7C_12 && sp7C[1] > 1500.0f) {
        sp78 = func_800DC128(0, 3);
        for (i = 0; i < 4; i++) {
            _subaddieskeleton_entrypoint_2(arg0->unk0, i + 5, sp48[i]);
        }
        emitter = func_800B53A4(1);
        func_800BA994((u8 *)emitter, -45, (s32)(arg0->rotation[1] - 25.0f), 25, -25, (s32)(arg0->rotation[1] + 25.0f), 75);
        func_800BA5A8((s16 *)emitter, 0x1200);
        func_800BABB8(emitter, sp7C, NULL, 1.0f, D_808014D8_chdippy);
        func_800BA4D0(emitter, 1500);
        func_800BA544((s32 *)emitter, (BtIntPtr)_chdippy_entrypoint_2);
        func_800BA1D0(emitter, sp48[D_808016E8_chdippy[sp78][0]], sp48[D_808016E8_chdippy[sp78][1]], 1);
    }
    BT_NATIVE_ONLY(return 0;) }

void chdippy_entrypoint_2(s32 arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808014B0_chdippy[10];
    func_800BBCB8(arg1, NULL, 1.2f, 1, D_808014B0_chdippy);
}

/* extern */

void func_80800CBC_chdippy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
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
    s32 _capod_entrypoint_14(void);
    if (((struct Flags *)arg0)->active) {
        _capod_entrypoint_14();
        arg0[0x65] &= 0xFFEF;
    }
}                 typedef struct { u8 pad0[0x8]; f32 unk8; u8 padC[0x10]; f32 unk1C; u8 pad20[0x45]; u8 unk65; } Objdippy_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800D84_chdippy(void *arg0) {
    (((Objdippy_arg0 *)arg0)->unk65) = (u8) ((((Objdippy_arg0 *)arg0)->unk65) & 0xFFFE);
    (((Objdippy_arg0 *)arg0)->unk1C) = (f32) (((Objdippy_arg0 *)arg0)->unk8);
}

void func_80800D9C_chdippy(void *self) {
    struct Dippy {
        s32 marker;
        f32 position[3];
        u8 pad10[8];
        f32 offset;
        f32 baseY;
        f32 timer;
        f32 soundTimer;
        u8 pad28[0x30];
        f32 elapsed;
        u8 pad5C[9];
        u8 flags;
        u8 pad66[0xA];
        unsigned int : 16;
        unsigned int state : 6;
        unsigned int : 10;
        u8 pad74[4];
        unsigned int : 8;
        unsigned int counter : 4;
        unsigned int : 20;
        u8 pad7C[0x1C];
        u8 pad98[3];
        u8 alpha;
    };
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _idwibble_entrypoint_5(void *arg0, s16 arg1);
    BtIntPtr _idworld_entrypoint_4(BtIntPtr, s32);
#ifndef BT_NATIVE
    void _chdippy_entrypoint_2(void);
#endif
#ifdef BT_NATIVE
    void chdippy_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    void _chdippy_entrypoint_3(void);
#endif
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA544(s32 *, BtIntPtr);
    void func_800BA5A8(s16 *, s32);
    void func_800BA714(void *, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, f32, s32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void *func_800BEA88(s32 i);
    s32 func_800D9078(f32 *arg0);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *actor);
    void func_80101FDC(Actor *, u32);
    s32 func_8010D930(s32, s32, BtIntPtr, s32 *);
    extern s32 D_808014D8_chdippy[10];
    extern s32 D_808016F0_chdippy[17];
    extern s32 D_80801734_chdippy[6];
    s32 count;
    f32 position[3];
    BtIntPtr emitter;
    BtIntPtr glid;
    BtIntPtr world;
    BtIntPtr wibble;

    switch (((struct Dippy *)self)->state) {
        case 2:
            func_800D9078(&((struct Dippy *)self)->elapsed);
            ((struct Dippy *)self)->offset = func_800F12D4(((struct Dippy *)self)->elapsed, 0.0f, 6.0f, 0.0f, -2000.0f);
            ((struct Dippy *)self)->position[1] = ((struct Dippy *)self)->offset + ((struct Dippy *)self)->baseY;
            if (((struct Dippy *)self)->elapsed > 1.0f) {
                func_800BBCB8((BtIntPtr)((struct Dippy *)self)->position, (BtIntPtr)((struct Dippy *)self)->position, 1.0f, 2, D_808016F0_chdippy);
            } else {
                ((struct Dippy *)self)->alpha = (s32)func_800F10B4(((struct Dippy *)self)->elapsed, 1.0f, 0.0f, 255.0f, 0.0f);
            }
            ((Actor *)self)->unk64_16 = 1;
            if (func_800D90A4(&((struct Dippy *)self)->timer)) {
                ((struct Dippy *)self)->flags &= 0xFFFE;
                func_80101FDC((Actor *)self, 3);
            } else {
                if (func_800D90A4(&((struct Dippy *)self)->soundTimer)) {
                    ((struct Dippy *)self)->soundTimer = func_800DC178(0.2f, 0.5f);
                    func_8010D930(9, -1, (BtIntPtr)((struct Dippy *)self)->position, D_80801734_chdippy);
                }
                if (((struct Dippy *)self)->timer < 15.0f) {
                    if (func_800DC0C0() < func_800F10B4(((struct Dippy *)self)->timer, 15.0f, 0.0f, 1.0f, 0.0f)) {
                        count = 1;
                    } else {
                        count = 0;
                    }
                } else {
                    count = func_800F10B4(((struct Dippy *)self)->timer, 30.0f, 0.0f, 3.0f, 1.0f);
                }
                if (count) {
                    emitter = func_800B53A4(count);
                    func_800EE7F8(position, ((struct Dippy *)self)->position);
                    position[1] += 6000.0f;
                    func_800BA5A8((s16 *)emitter, 0x200);
                    func_800BA714((void *)emitter, 500, 500);
                    func_800BABB8(emitter, (BtIntPtr)position, 0, 1.0f, D_808014D8_chdippy);
                    func_800BA4D0(emitter, 1500);
                    func_800BA544((s32 *)emitter, (BtIntPtr)_chdippy_entrypoint_2);
                    func_800BA22C(emitter, count);
                }
            }
            break;
        case 1:
        case 3:
            glid = func_800BEA88(1);
            _glid_entrypoint_0(glid, 1, (s32 *)_chdippy_entrypoint_3, ((struct Dippy *)self)->marker);
            _glid_entrypoint_0(glid, 2, (s32 *)_chdippy_entrypoint_3, ((struct Dippy *)self)->marker);
            if (((struct Dippy *)self)->counter-- == 0) {
                func_800FFAB0((BtIntPtr)self);
            }
            break;
    }
    world = func_800BEA88(1);
    wibble = _idworld_entrypoint_4(world, 1);
    if (wibble) {
        _idwibble_entrypoint_5(wibble, (s16)((struct Dippy *)self)->offset);
    }
    _glid_entrypoint_0(world, 2, (s32 *)_chdippy_entrypoint_3, ((struct Dippy *)self)->marker);
}

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
    void _idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3);
    void *func_800BEA88(s32 i);
    void func_800C4AF0(f32 *, void *);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_8080174C_chdippy[];
    BtIntPtr sp24;

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
        return BT_NATIVE_ONLY(0);
    } else {
        arg0->unk79_4 = 2;
        *(f32 *)&arg0->actorData[0] = 0.0f;
        func_80101FDC(arg0, 3);
    }
    _idworldmake_entrypoint_1(sp24, 0x659, 1, 1);
    if (arg0->unk70_10 == 2) {
        func_800C4AF0((f32 *)arg0->actorData, D_8080174C_chdippy);
    }
    BT_NATIVE_ONLY(return 0;) }

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
/* data_to_c.py: from asm/data/overlays/ch/dippy.data.s */
extern u8 D_80801500_chdippy[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_801018A4();
s32 D_80801480_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x0) = { 1246410, 131096, 852083, 9175040 };
s32 D_80801490_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x10) = { 1246410, 131096, 852121, 11730944 };
u32 D_808014A0_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x20) = { 0x130551, 0x20018, 0xD00CC, 0xE60000 };
s32 D_808014B0_chdippy[10] BT_DATA(4, overlays_ch_dippy, 0x30) = { 1903067, 1441793, 2818227, 11730965, 179, 2228428, 13369804, 31850527, -512, 0 };
s32 D_808014D8_chdippy[10] BT_DATA(4, overlays_ch_dippy, 0x58) = { 1903091, 2162687, -21757918, 6684800, 3342412, 1831508, -229375993, 65579, 167774720, 0 };
u8 D_80801500_chdippy[128] BT_DATA(4, overlays_ch_dippy, 0x80) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x80, 0x00, 0x00, 0x02, 0xD7, 0x00, 0x02, 0x40, 0x80, 0x00, 0x00, 0x02, 0xD9, 0x00, 0x02, 0x41, 0x04, 0xCC, 0xCD, 0x02, 0xD8, 0x00, 0x01, 0x40, 0x60, 0x00, 0x00, 0x02, 0xDA, 0x00, 0x02, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xDE, 0x00, 0x02, 0x40, 0xB6, 0x66, 0x66, 0x02, 0xDC, 0x00, 0x01, 0x40, 0x66, 0x66, 0x66, 0x02, 0xDD, 0x00, 0x02, 0x40, 0xE3, 0x33, 0x33, 0x02, 0xDB, 0x00, 0x02, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xDE, 0x00, 0x02, 0x40, 0x99, 0x99, 0x9A, 0x02, 0xDF, 0x00, 0x01, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE0, 0x00, 0x02, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xDE, 0x00, 0x02, 0x40, 0xB6, 0x66, 0x66, 0x02, 0xDC, 0x00, 0x01 };
ActorData D_80801580_chdippy [1] BT_DATA(4, overlays_ch_dippy, 0x100) = { { 832, 1069, 2025, 5, (void *)D_80801500_chdippy, (void (*)(struct Actor *))func_808000D8_chdippy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 0, 1096, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chdippy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800374_chdippy, 0 } };
ActorData D_808015C8_chdippy [1] BT_DATA(4, overlays_ch_dippy, 0x148) = { { 344, 1089, 2271, 2, 0, (void (*)(struct Actor *))func_80800D9C_chdippy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 2, 7232, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800D84_chdippy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80801110_chdippy, 0 } };
s32 D_80801610_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x190) = { 1246484, 131096, 852019, 4980736 };
s32 D_80801620_chdippy[11] BT_DATA(4, overlays_ch_dippy, 0x1A0) = { 1903069, 1442304, 2818508, 36896802, 25166336, 75499008, 1376256, 2490393, 7, 2088615, 1895825408 };
u32 D_8080164C_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x1CC) = { 0x130430, 0x2000D, 0x800099, 0 };
u32 D_8080165C_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x1DC) = { 0x1304F8, 0x20018, 0xA0080, 0 };
u32 D_8080166C_chdippy[7] BT_DATA(4, overlays_ch_dippy, 0x1EC) = { 0x130410, 0x20018, 0x150000, 0x1000033, 0xC0000, 0x1330033, 0xB30000 };
u32 D_80801688_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x208) = { 0x3D8F5C29, 0x3DF5C28F, 0x3E0F5C29, 0xBF800000 };
u32 D_80801698_chdippy[3] BT_DATA(4, overlays_ch_dippy, 0x218) = { 0x3F4A3D71, 0x3F547AE1, 0xBF800000 };
u32 D_808016A4_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x224) = { 0x13040A, 0x20018, 0xD0059, 0x730000 };
u32 D_808016B4_chdippy[4] BT_DATA(4, overlays_ch_dippy, 0x234) = { 0x130434, 0x20018, 0xD0073, 0xA60000 };
u32 D_808016C4_chdippy[6] BT_DATA(4, overlays_ch_dippy, 0x244) = { 0x3E75C28F, 0x3EB851EC, 0x3F1EB852, 0x3F333333, 0x3F4CCCCD, 0xBF800000 };
u32 D_808016DC_chdippy[3] BT_DATA(4, overlays_ch_dippy, 0x25C) = { 0x3EF0A3D7, 0x3F6B851F, 0xBF800000 };
u8 D_808016E8_chdippy [4] [ 2 ] BT_DATA(4, overlays_ch_dippy, 0x268) = { { 1, 0 }, { 0, 3 }, { 2, 3 }, { 0, 0 } };
s32 D_808016F0_chdippy[17] BT_DATA(4, overlays_ch_dippy, 0x270) = { 1903069, 1446416, 1572864, 466432, 503316525, 13107500, 721076, 11796510, -655326, 30147123, 13369600, -1073610731, 1638553, 2818355, 23461915, 13107500, 0 };
s32 D_80801734_chdippy[6] BT_DATA(4, overlays_ch_dippy, 0x2B4) = { 1246547, 852224, 23461910, 1179648001, 10000, 0 };
f32 D_8080174C_chdippy [9] BT_DATA(4, overlays_ch_dippy, 0x2CC) = { 1.746281e-39f, 2.204066e-39f, 6.979512e-39f, 2.3509946e-38f, 4.68551e-39f, 1.1754972e-38f, 0.0f, 0.0f, 0.0f };
