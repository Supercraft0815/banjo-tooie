#include "common.h"

struct FortuneEntry {
        s16 unk0;
        s16 ability;
        f32 unk4;
        f32 weight;
    };

OSThread *chmadamegrunty_entrypoint_0(void)
{
    extern u8 D_80800B50_chmadamegrunty[];

    return (OSThread *) D_80800B50_chmadamegrunty;
}

OSThread *chmadamegrunty_entrypoint_1(void)
{
    extern u8 D_80800B98_chmadamegrunty[];

    return (OSThread *) D_80800B98_chmadamegrunty;
}

/* extern */

void func_80800018_chmadamegrunty(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    if (func_800DA298(0xA02) != 0) {
        func_80101FDC(arg0, 7);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 20.0f;
    }
}

void func_8080005C_chmadamegrunty(Actor *arg0) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_16(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    void func_800F4924(s32, s32);
    u32 func_800F54E4(void);
    s32 func_80101180(s32, s32, s32);
    void func_80800200_chmadamegrunty(Actor *);
    void func_808003B0_chmadamegrunty(Actor *);
    void func_8080082C_chmadamegrunty(void *, s32);
    s32 func_808008D4_chmadamegrunty(Actor *);
    s32 state;

    switch (arg0->unk70_10) {
        case 1:
            func_80800200_chmadamegrunty(arg0);
            break;
        case 5:
            if (func_808008D4_chmadamegrunty(arg0) == 0) {
                func_800F4924(func_800F54E4(), -1);
                func_808003B0_chmadamegrunty(arg0);
            }
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 6:
            if (func_800D9078(&arg0->unk58) != 0) {
                state = arg0->unk64_20 ? 7 : 1;
                func_8080082C_chmadamegrunty(arg0, state);
                arg0->unk64_20 = 0;
            }
            break;
        case 7:
            if (func_800D90A4(&arg0->unk58) != 0 &&
                _subaddiedialog_entrypoint_16() != 0 &&
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x10CB, 0, 0, 0x43) != 0) {
                func_8080082C_chmadamegrunty(arg0, 1);
                func_80101180(0x3D4, 7, 0);
                _subaddieDll_entrypoint_4(arg0, 0);
            }
            break;
    }
}

s32 func_80800198_chmadamegrunty(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800784_chmadamegrunty(Actor *, s32, s16);
    void func_80800460_chmadamegrunty(Actor *);
    s16 *data = (s16 *)&arg2;
    switch (arg1) {
        case 0x2E:
            func_80800784_chmadamegrunty(arg0, data[0], data[1]);
            break;
        case 0x32:
            func_80800460_chmadamegrunty(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800200_chmadamegrunty(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4AC0(s32, f32 *, f32);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    s32 func_800F6478(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_8010C500(void *);
    void func_8080082C_chmadamegrunty(void *, s32);
    extern s32 func_8010D5DC;
    u32 temp_v0;

    temp_v0 = func_800F54E4();
    if (func_800F6438(temp_v0) && func_800F6478(temp_v0) &&
        func_8010C500(arg0) && !func_800F64A4(temp_v0, 0x10000)) {
        func_800F497C(temp_v0);
        func_800F49D4(temp_v0, &func_8010D5DC, arg0->unk0);
        func_800F4AC0(temp_v0, arg0->position, 170.0f);
        func_8080082C_chmadamegrunty(arg0, 2);
        _capod_entrypoint_13(arg0->unk0, NULL, 0xAE, 0x20);
    }
}

void func_808002BC_chmadamegrunty(Actor *arg0) {
    void _capod_entrypoint_14(void);
    int func_800DC298(f32);
    void func_800EEB9C(f32 [3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4AC0(s32, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    s32 func_80101180(s32, s32, s32);
    void func_8080082C_chmadamegrunty(void *, s32);
    extern s32 func_8010D5DC;
    f32 sp24[3];

    func_800EEB9C(sp24, arg0->rotation[1], 400.0f);
    func_800EF04C(sp24, arg0->position);
    func_800F82D4(func_800F54E4(), 0);
    func_800F497C(func_800F54E4());
    func_800F49D4(func_800F54E4(), &func_8010D5DC, arg0->unk0);
    func_800F4AC0(func_800F54E4(), sp24, 170.0f);
    func_8080082C_chmadamegrunty(arg0, 4);
    arg0->unk64_20 = func_800DC298(0.25f);
    if (arg0->unk64_20) {
        func_80101180(0x3D4, 8, 0);
    }
    _capod_entrypoint_14();
}

void func_808003B0_chmadamegrunty(Actor *arg0) {
    void _capod_entrypoint_14(void);
    int func_800DC298(f32);
    u32 func_800F54E4(void);
    void func_800F7C0C(s32, s32, f32);
    void func_800F82D4(s32, s32);
    s32 func_80101180(s32, s32, s32);
    void func_8080082C_chmadamegrunty(void *, s32);

    func_800F82D4(func_800F54E4(), 0);
    func_800F7C0C(func_800F54E4(), 0x44, arg0->rotation[1]);
    func_8080082C_chmadamegrunty(arg0, 6);
    arg0->unk58 = 1.5f;
    arg0->unk64_20 = func_800DC298(0.25f);
    if (arg0->unk64_20) {
        func_80101180(0x3D4, 8, 0);
    }
    _capod_entrypoint_14();
}

void func_80800460_chmadamegrunty(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    void func_800F82D4(s32, s32);
    void func_8080082C_chmadamegrunty(void *, s32);
    s32 state;

    state = arg0->unk70_10;
    switch (state) {
        case 2:
            if (func_800F64A4(func_800F54E4(), 0x201) == 0) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x10A0, 0xF, NULL, 0x43);
                func_8080082C_chmadamegrunty(arg0, 3);
            } else {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x109F, 0xF, NULL, 0x43);
                func_8080082C_chmadamegrunty(arg0, 3);
            }
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 4:
            state = arg0->unk64_20 ? 7 : 1;
            func_8080082C_chmadamegrunty(arg0, state);
            arg0->unk64_20 = 0;
            break;
    }
}

s32 func_80800564_chmadamegrunty(Actor *arg0) {
    int func_800C6E38(s32);
    f32 func_800DC178(f32, f32);
    extern struct FortuneEntry D_80800AF0_chmadamegrunty[];
    extern u8 D_80800B50_chmadamegrunty[];
    struct FortuneEntry *entry;
    u8 *end;
    f32 total = 0.0f;
    f32 cumulative = 0.0f;
    s32 i;

    end = D_80800B50_chmadamegrunty; entry = D_80800AF0_chmadamegrunty;
    do {
        if (entry->ability == -1 || func_800C6E38(entry->ability)) {
            total += entry->weight;
        }
        entry++;
    } while ((u8 *)entry < end);
    total = func_800DC178(0.0f, total);
    for (i = 0; i != 8; i++) {
        if (D_80800AF0_chmadamegrunty[i].ability == -1 || func_800C6E38(D_80800AF0_chmadamegrunty[i].ability)) {
            cumulative += D_80800AF0_chmadamegrunty[i].weight;
            if (total <= cumulative) {
                *(s32 *)&arg0->unk50 = i;
                return i + 0x10A1;
            }
        }
    }
    return 0;
}

void func_80800670_chmadamegrunty(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D175C(s16, s16);
    s32 func_800D3EF4(s32);
    s32 func_800EE7F8(s32 *, u8 *);
    s32 func_800EF1B8(s32 *, f32, s32);
    void func_800F4924(s32, s32);
    u32 func_800F54E4(void);
    s32 func_800FC660(s32);
    s32 func_80101FDC(void *, s32);

    extern struct FortuneEntry D_80800AF0_chmadamegrunty[];
    s32 sp34[3];
    u32 sp30;
    u8 *temp_v0;

    sp30 = *(u32 *)&arg0->unk50;
    func_800EE7F8(sp34, (u8 *)arg0 + 4);
    func_800EF1B8(sp34, arg0->rotation[1], 0x43C80000);
    switch (sp30) {
    case 0:
        func_800D3EF4(6);
        func_800FC660(0xE);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10A9, 0xE, 0, 0x43);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        temp_v0 = (sp30 * 0xC) + (u8 *)D_80800AF0_chmadamegrunty;
        func_800D175C((*(s16 *)((s8 *)(temp_v0) + (0))), (*(s16 *)((s8 *)(temp_v0) + (4))));
        func_808002BC_chmadamegrunty(arg0);
        return;
    case 6:
        func_800F4924(func_800F54E4(), 1);
        func_808002BC_chmadamegrunty(arg0);
        return;
    case 7:
        func_80101FDC(arg0, 5);
        arg0->unk58 = 4.0f;
        /* fallthrough */
    default:
        return;
    }
}

void func_80800784_chmadamegrunty(Actor *arg0, s32 arg1, s16 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80800670_chmadamegrunty();
    s32 dialog;
    switch (arg1) {
        case 0x109F:
            dialog = func_80800564_chmadamegrunty(arg0);
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xE, NULL, 0x43);
            return;
        case 0x10A9:
            func_808002BC_chmadamegrunty(arg0);
            return;
        case 0x10A0:
            func_808002BC_chmadamegrunty(arg0);
            return;
        default:
#ifdef BT_NATIVE
            ((void (*)())func_80800670_chmadamegrunty)();
#else
            func_80800670_chmadamegrunty();
#endif
        case 0x10CA:
        case 0x10CB:
            return;
    }
}

/* extern */

void func_8080082C_chmadamegrunty(void *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80101FDC();
    Actor *actor = arg0;
    func_80101FDC();
    if (arg1 == 7) {
        _subaddieDll_entrypoint_4(arg0, 1);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 60.0f;
        _subaddiedialog_entrypoint_11(actor->unk0, 0x10CA, 4, NULL, 0x43);
    }
}

s32 func_80800898_chmadamegrunty(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg0 <= arg2) && (arg2 < arg1)) {
        return 1;
    }
    return 0;
}

s32 func_808008D4_chmadamegrunty(Actor *arg0) {
    s32 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_808009AC_chmadamegrunty(Actor *, s32, f32);
    typedef struct {
        s32 sound;
        f32 time;
        f32 pitch;
    } MadameGruntySound;
    extern MadameGruntySound D_80800BE0_chmadamegrunty[];
    s32 timer_result[2]; /* Preserve IDO stack allocation. */
    MadameGruntySound *sound;
    f32 previous_time;
    s32 i;

    previous_time = arg0->unk58;
    timer_result[0] = func_800D9078(&arg0->unk58);
    for (i = 0; i < 9; i++) {
        sound = &D_80800BE0_chmadamegrunty[i];
        if (func_80800898_chmadamegrunty(
                arg0->unk58,
                previous_time,
                func_800F10B4(
                    sound->time,
                    0.0f,
                    1.0f,
                    4.0f,
                    0.0f)) != 0) {
            func_808009AC_chmadamegrunty(arg0, sound->sound, sound->pitch);
        }
    }
    return timer_result[0] == 0;
}

void func_808009AC_chmadamegrunty(Actor *arg0, s32 arg1, f32 arg2) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C301C(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800DC178(f32, f32);
    extern s32 D_80800C4C_chmadamegrunty;
    u8 sp27;

    sp27 = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
    func_800C4350(sp27 & 0xFF, arg0->position, &D_80800C4C_chmadamegrunty);
    func_800C301C(sp27, arg1);
    func_800C31DC(sp27, func_800DC178(-0.05f, 0.05f) + arg2);
    func_800C3BDC(sp27);
}

/* extern */

void func_80800A30_chmadamegrunty(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _chdoormake_entrypoint_7(void *, f32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 200.0f, 0x2812, 0xA02) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.0f);
        _chdoormake_entrypoint_7(arg0, 1.0f);
    }
}
