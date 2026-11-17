#include "core2/1ECE0B0.h"

extern PlayerState* D_80135490[];
extern s32 func_800966BC(void *);
extern f32 func_800964DC(PlayerState *);
extern f32 func_8009C150(PlayerState *);
extern s32 func_8009E674(PlayerState *, s32);
extern u8 D_801354DA;

extern u32 D_801354DC;
extern u8 D_801354F8;
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;

extern f32 D_8013550C;

void func_800F9400(s32 arg0) {
    void func_800C964C(s32 arg0);
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xC);
        return;
    }
    func_800C964C(0xE);
}

/* extern */

void func_800F9444(s32 arg0) {
    void func_800C964C(s32 arg0);
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xD);
        return;
    }
    func_800C964C(0xF);
}

void func_800F9488(BtIntPtr arg0) {
    extern u8 D_80135520;
    extern u8 D_80135521;
    extern u8 D_80135522;

    s32 _plsu_entrypoint_1(s32);
    int func_800DB9B0(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F6224(s32);
    void func_800F759C(s32);
    s32 func_800F7CF4(BtIntPtr arg0, s32 arg1, void *arg2);
    void func_800F7E64(s32 arg0, s32 arg1);
    s16 func_800F8A5C();
    void func_800F9240(f32 *, s32);
    void func_800F92CC(u32 *, s32 *, s32 *, s32 *);
    void func_800F9354(u32 *, s32 *, s32 *);
    s32 sp5C;
    u32 sp58;
    s32 sp54;
    s32 sp50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    switch (D_80135520) {
        case 3:
            if (arg0 == 1) {
                func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
                func_800F82D4(sp58, 0);
                func_800F8268(sp58, 1, 1);
            }
            break;
        case 6:
            if (arg0 == 1) {
                func_800F9354(&sp58, &sp5C, &sp54);
                func_800F8EBC(sp58);
                func_800F8268(sp58, 1, 1);
                func_800F82D4(sp58, 0);
            }
            break;
        case 9:
            if (arg0 == 1) {
                func_800F93C4(&sp58, &sp5C);
                func_800F8EBC(sp58);
                func_800F8268(sp58, 1, 1);
                func_800F82D4(sp58, 0);
            }
            break;
        case 15:
            if (arg0 == 1) {
                func_800F93C4(&sp58, &sp5C);
                func_800F8E78(10);
            }
            break;
    }
    D_80135520 = arg0;
    switch (D_80135520) {
        case 2:
            func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
            func_800F82D4(sp58, 2);
            func_800F8268(sp58, 0, 1);
            func_800F9444(sp5C);
            break;
        case 3:
            func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
            func_800F8128(sp50);
            func_800F8EE4(sp58);
            func_800F8EBC(sp50);
            func_800F9400(sp54);
            break;
        case 4:
            func_800F9354(&sp58, &sp5C, &sp54);
            func_800F82D4(sp58, 2);
            func_800F9444(sp5C);
            break;
        case 5:
            func_800F9354(&sp58, &sp5C, &sp54);
            func_800F9070(sp54, 1);
            func_800F8268(sp58, 0, 1);
            func_800F8EE4(sp58);
            func_800F9070(sp5C, 0);
            func_800A7990(func_800F8A5C(sp54), 0, 0);
            break;
        case 6:
            func_800F9354(&sp58, &sp5C, &sp54);
            func_800F82D4(sp58, 2);
            func_800F9400(sp5C);
            break;
        case 7:
            func_800F9444(func_800F929C());
            break;
        case 8:
            sp54 = func_800F929C();
            func_800F9070(sp54, 1);
            if (func_800DB9B0() == 0) {
                func_800A7990(func_800F8A5C(sp54), 0, 0);
            }
            break;
        case 9:
            func_800F93C4(&sp58, &sp5C);
            func_800F82D4(sp58, 2);
            func_800F9400(sp5C);
            break;
        case 10:
            func_800F93C4(&sp58, &sp5C);
            sp50 = _plsu_entrypoint_1(17);
            func_800F8128(sp58);
            func_800F759C(sp50);
            func_800F8268(sp58, 1, 1);
            break;
        case 11:
            sp50 = D_80135522;
            sp58 = D_80135521;
            func_800F8128(sp50);
            func_800F759C(sp58);
            func_800F8268(sp50, 1, 1);
            break;
        case 13:
            func_800F93C4(&sp58, &sp5C);
            func_800F82D4(sp58, 2);
            func_800F9444(11);
            break;
        case 14:
            func_800F9070(10, 1);
            func_800A7990(func_800F8A5C(10), 0, 0);
            break;
        case 15:
            func_800F93C4(&sp58, &sp5C);
            sp50 = func_800F6224(sp58);
            func_800F7E64(sp50, 11);
            func_800F608C(sp50, 1);
            func_800F9240(sp44, sp58);
            func_800F7CF4(sp50, 0x50, sp44);
            func_800F9400(10);
            break;
        case 16:
            sp58 = _plsu_entrypoint_1(11);
            sp50 = _plsu_entrypoint_1(10);
            func_800F5A00(sp58, sp20);
            func_800F5A00(sp50, sp2C);
            if (func_800EEB40(sp20, sp2C) < 48400.0f) {
                func_800EE7F8(sp38, sp20);
            } else {
                func_800F9240(sp38, sp50);
            }
            func_800F7CF4(sp58, 0x50, sp38);
            func_800F8128(sp50);
            func_800F8EBC(sp50);
            func_800F8268(sp50, 1, 1);
            break;
        case 17:
            sp58 = _plsu_entrypoint_1(11);
            sp50 = _plsu_entrypoint_1(10);
            func_800F759C(sp58);
            func_800D5234(0);
            func_800A16BC(0);
            func_800F8128(sp50);
            func_800F8EBC(sp50);
            func_800F7B9C(sp50, 0x60);
            func_800F8268(sp50, 1, 1);
            break;
    }
}

s32 func_800F99E8(void) {
    extern u8 D_80135520;
    return D_80135520 != 1;
}

s32 func_800F99FC(void) {
    extern u8 D_80135520;
    if (D_80135520 == 0xE) {
        return 1;
    }
    return 0;
}

void func_800F9A24(void) {
    func_800F9488(NULL);
}

void func_800F9A44(void) {
    extern u8 D_80135520;
    D_80135520 = 0;
    func_800F9488(1);
}

void func_800F9A6C(void) {
    if (_plsu_entrypoint_2() != 0) {
        func_800F9488(2);
        return;
    }
    func_800F9488(4);
}

void func_800F9AAC(s32 arg0, s32 arg1) {
    extern u8 D_80135520;
    (&D_80135520)[1] = arg0;
    (&D_80135520)[2] = arg1;
    func_800F9488(0xB);
}

void func_800F9ADC()
{
    func_800F9488(0xC);
}

void func_800F9AFC(void) {
    s32 _plsu_entrypoint_1(s32);
    u32 sp20[2];
    s32 sp1C;

    func_800F93C4(&sp20[0], (s32 *) &sp20[1]);
    sp1C = _plsu_entrypoint_1(func_800F929C());
    func_800F8128(sp1C);
    func_800F8EBC(sp1C);
    func_800F8268(sp1C, 1, 1);
}

/* extern */

void func_800F9B54(void) {
    s32 _plsu_entrypoint_1(s32);
    BtUIntPtr sp1C;
    s32 sp18;

    sp1C = func_800F54E4();
    sp18 = _plsu_entrypoint_1(0x11);
    func_800F8128((s32) sp1C);
    func_800F8268((s32) sp1C, 1, 1);
    func_800F82C0(sp18);
}

void func_800F9BA4()
{
    func_800D9240(0x11);
}

void func_800F9BC4(void) {
    extern u8 D_80135520;
    void func_800BEAF4(void);

    if (func_800F8B88() == 3) {
        if (func_800DB9B0() == 0) {
            switch (D_80135520) {
                case 0xD:
                case 0xE:
                case 0xF:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                    break;
                default:
                    func_800BEAF4();
                    func_800F9488(0x12);
                    break;
            }
        }
    }
}

void func_800F9C38(void) { if (func_800F8B88() == 3) func_800F9488(0x13); }

void func_800F9C6C(void) {
    s32 _plsu_entrypoint_1(s32);
    s32 func_800C9510(void);
    s32 func_800C95D4(void);
    s32 func_800EA05C();
    s16 func_800F8A5C();
    extern u8 D_80135520;
    s32 pad;
    s32 sp18;

    switch (D_80135520) {
    case 2:
        if (func_800C9510() == 0) {
            func_800F9488(3);
        }
        break;
    case 3:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
        }
        break;
    case 4:
        if (func_800C9510() == 0) {
            func_800F9488(5);
        }
        break;
    case 5:
        func_800F9488(6);
        break;
    case 6:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
        }
        break;
    case 7:
        if (func_800C9510() == 0) {
            func_800F9488(8);
        }
        break;
    case 8:
        func_800F9488(9);
        break;
    case 9:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
        }
        break;
    case 10:
        func_800F9488(1);
        break;
    case 11:
        func_800F9488(1);
        break;
    case 12:
        if (_plsu_entrypoint_1(func_800F929C()) == -1) {
            func_800F9488(7);
        } else {
            func_800F9488(10);
        }
        break;
    case 13:
        if (func_800C9510() == 0) {
            func_800F9488(14);
        }
        break;
    case 14:
        func_800F9488(15);
        break;
    case 15:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
        }
        break;
    case 16:
        func_800F9488(1);
        break;
    case 17:
        func_800F9488(1);
        break;
    case 18:
        sp18 = func_800F8A5C(10);
        if (func_800EA05C() == sp18) {
            func_800F9488(16);
        } else {
            func_800F9488(13);
        }
        break;
    case 19:
        sp18 = func_800F8A5C(10);
        if (func_800EA05C() == sp18) {
            func_800F9488(17);
        }
        break;
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
PlayerState * D_80135490 [ 2 ] BT_DATA(4, bss_core2bss2_2, 0x25F0);
u8 D_80135520 BT_DATA(4, bss_core2bss2_2, 0x2680);
u8 D_80135521 BT_DATA(4, bss_core2bss2_2, 0x2681);
u8 D_80135522 BT_DATA(4, bss_core2bss2_2, 0x2682);
#endif
