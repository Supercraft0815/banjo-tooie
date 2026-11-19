#include "common.h"

OSThread *chnicecavemen_entrypoint_0(void)
{
    extern ActorData D_80801A5C_chnicecavemen[];

    return (OSThread *) D_80801A5C_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_1(void)
{
    extern ActorData D_80801AA4_chnicecavemen[];

    return (OSThread *) D_80801AA4_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_2(void)
{
    extern ActorData D_80801AEC_chnicecavemen[];

    return (OSThread *) D_80801AEC_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_3(void)
{
    extern ActorData D_80801B34_chnicecavemen[];

    return (OSThread *) D_80801B34_chnicecavemen;
}

void func_80800030_chnicecavemen(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    void func_80801200_chnicecavemen(Actor *);
    s32 state;

    arg0->actorData[6] = 0;
    switch (arg0->unk74_7) {
        case 0x32:
            arg0->actorData[4] = 0x324;
            arg0->actorData[5] = 0x16C;
            break;
        case 0x33:
            arg0->actorData[4] = 0x325;
            arg0->actorData[5] = 0x16D;
            break;
        case 0x34:
            arg0->actorData[4] = 0x326;
            arg0->actorData[5] = 0x16E;
            break;
    }
    if (_glcutDll_entrypoint_20()) {
        state = 0xD;
    } else if (func_800DA298(arg0->actorData[4])) {
        if (func_800DA298(arg0->actorData[5])) {
            state = 0xC;
        } else {
            state = 0xA;
        }
    } else {
        if (func_800DA298(arg0->actorData[5])) {
            state = 9;
        } else {
            state = 1;
        }
    }
    func_80102424(arg0, state);
    func_80801200_chnicecavemen(arg0);
}

void func_80800128_chnicecavemen(Actor *arg0) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);)
    void _subaddiepalette_entrypoint_1(void *arg0, u8 *arg1);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    s32 func_800DA298(s32);
    s32 func_800F4F34(BtUIntPtr, f32 *, f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F7B9C(BtIntPtr, u32);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80800AB8_chnicecavemen(Actor *, s32);
    void func_80800CC8_chnicecavemen(Actor *);
    s32 func_80801178_chnicecavemen(Actor *);
    s32 func_8080134C_chnicecavemen(Actor *, s32 *, s32 *, s32, s32);
    extern s32 D_80801810_chnicecavemen[14];
    extern s32 D_80801848_chnicecavemen[14];
    extern s32 D_80801880_chnicecavemen[14];
    extern s32 D_808018B8_chnicecavemen[8];
    extern s32 D_80801B7C_chnicecavemen[4];
    struct {
        u8 pad0[0x10];
        f32 progress;
        u8 palette[0x810];
        s32 active;
    } *data;
    s32 pad;
    f32 *volatile position;

    data = func_80100094(arg0, 0);
    func_800F4F34(func_800F54E4(), position = arg0->position, 60.0f, 50.0f);
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(arg0->actorData[4])) {
                func_800F7B9C(func_800F54E4(), 0x93);
                func_80800AB8_chnicecavemen(arg0, 8);
            } else {
                func_8080134C_chnicecavemen(arg0, D_80801B7C_chnicecavemen, D_80801810_chnicecavemen, 7, 2);
            }
            break;
        case 5:
        case 6:
            func_80801178_chnicecavemen(arg0);
            if (data->progress > 0.75f) {
                func_80800AB8_chnicecavemen(arg0, 7);
            }
            break;
        case 7:
            func_80801178_chnicecavemen(arg0);
            if (func_80101DDC(arg0)) {
                if (data->active) {
                    if (data->active) {
                        func_800F82D4(func_800F54E4(), 0);
                        data->active = 0;
                    }
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D7, 0xE, position, 0xA2);
                    func_80800AB8_chnicecavemen(arg0, func_800DA298(arg0->actorData[4]) ? 4 : 2);
                }
            }
            break;
        case 9:
            if (func_800DA298(arg0->actorData[4])) {
                func_80800AB8_chnicecavemen(arg0, 8);
            } else {
                func_8080134C_chnicecavemen(arg0, D_80801B7C_chnicecavemen, D_80801848_chnicecavemen, 7, 2);
            }
            break;
        case 10:
            func_8080134C_chnicecavemen(arg0, D_80801B7C_chnicecavemen, D_80801880_chnicecavemen, 7, 3);
            break;
        case 11:
            if (func_80101DDC(arg0)) {
                func_80800AB8_chnicecavemen(arg0, 12);
            }
            break;
        case 12:
            func_8080134C_chnicecavemen(arg0, D_80801B7C_chnicecavemen, D_808018B8_chnicecavemen, 4, 4);
            break;
    }
    func_80800CC8_chnicecavemen(arg0);
    _subaddiepalette_entrypoint_1(arg0, data->palette);
}

void func_808003B8_chnicecavemen(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808003D8_chnicecavemen(Actor *arg0, s32 arg1, s32 arg2) {
    extern u32 D_808018D8_chnicecavemen[4];
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);)
    s32 _subaddiepalette_entrypoint_4(void *, void *);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 func_800DA298(s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    void func_80800624_chnicecavemen(Actor *, s32);
    void func_8080077C_chnicecavemen(Actor *, s32, s32);
    s32 func_80800C6C_chnicecavemen(Actor *);
    s32 func_808013D0_chnicecavemen(void *, s32, s32);
    void func_80801464_chnicecavemen(Actor *, s32, s32);
    s32 pad;
    s32 sp30;
    s32 sp2C;
    void *expression;
    struct { u8 pad[0x14]; u16 palette; } *data;

    switch (arg1) {
        case 0x2E:
            func_8080077C_chnicecavemen(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x29:
            data = func_80100094(arg0, 0);
            _subaddiepalette_entrypoint_4(arg0, &data->palette);
            break;
        case 0xB:
            switch (arg2) {
                case 9:
                case 0xC:
                case 0x10:
                    func_800F7F98(func_800F54E4(), 0);
                    if (!func_80800C6C_chnicecavemen(arg0)) {
                        if (func_800DA298(arg0->actorData[5])) {
                            sp30 = 0x17D9;
                        } else {
                            sp30 = 0x17D4;
                        }
                        func_80801464_chnicecavemen(arg0, 3, 1);
                        _subaddiedialog_entrypoint_11(arg0->unk0, sp30, 0xE, arg0->position, 0xA2);
                    }
                    return 4;
                case 1:
                    if (func_800F64A4(func_800F54E4(), 0x400)) {
                        sp2C = 0x1811;
                    } else {
                        sp2C = 0x17FD;
                    }
                    func_80801464_chnicecavemen(arg0, 3, 1);
                    _subaddiedialog_entrypoint_11(arg0->unk0, sp2C, 0xE, arg0->position, 0xA2);
                    return 4;
            }
            return 3;
        case 0x1F:
            func_80800624_chnicecavemen(arg0, *(s32 *)&arg2);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808018D8_chnicecavemen, arg0->scale);
            break;
        case 0x57:
            return func_808013D0_chnicecavemen(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            expression = _suexpression_entrypoint_7(arg0, 1, 0xA2);
            _suexpression_entrypoint_12(expression, 0x42700000, 0x41700000);
            _suexpression_entrypoint_17(expression, 0x320);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800624_chnicecavemen(Actor *arg0, s32 arg1) {
    void func_800DF6BC(s32, s32);
    void func_800DF744(s32, s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    s32 func_801022E4(Actor *);
    void _subaddiepalette_entrypoint_3(Actor *, void *, s32);
    s32 first;
    s32 second;
    struct {
        u8 pad0[0x14];
        u16 palette;
        u16 pad16;
        s16 state;
        s16 pad1A;
        f32 time;
        f32 duration;
    } *data;
    s32 state;
    s32 alpha;

    data = func_80100094(arg0, 0);
    state = func_801022E4(arg0);
    func_801015D0(arg0);
    first = arg0->unk6C_9 == 0x42C ? 1 : 0;
    if (state != 0x2D5 && state != 0x2D6) {
        second = 0;
    } else {
        second = 1;
    }
    func_800DF744(3, first);
    func_800DF744(4, first);
    func_800DF744(5, second);
    func_800DF744(7, arg0->unk74_7 - 0x31);
    func_800DF744(8, arg0->unk74_7 - 0x31);
    if (data->state == 1) {
        alpha = func_800F12D4(data->time, 0.0f, data->duration, 0.0f, 255.0f);
    } else {
        alpha = data->palette == 0x7E7 ? 0 : 255;
    }
    func_800DF6BC(alpha, 255);
    _subaddiepalette_entrypoint_3(arg0, &data->palette, arg1);
}

void func_8080077C_chnicecavemen(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_10(s32);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);)
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void _subaddieitem_entrypoint_0(BtIntPtr, BtUIntPtr, s32, s32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    s32 func_800D1000(s32, s32, s32 *, s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    void func_80800AB8_chnicecavemen(Actor *, s32);
    int func_80800BF8_chnicecavemen(BtIntPtr);
    s32 func_8080126C_chnicecavemen(void *);
    void func_80801428_chnicecavemen(void *);
    void func_80801508_chnicecavemen(Actor *, s32, s32);
    int func_80801580_chnicecavemen(f32 *);
    extern s32 D_80801810_chnicecavemen[14];
    extern s32 D_80801848_chnicecavemen[14];
    extern s32 D_80801880_chnicecavemen[14];
    extern s32 D_808018B8_chnicecavemen[8];
    BtIntPtr sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    switch (arg1) {
    case 0x17D5:
    case 0x1803:
        if (arg2 > 0) {
            sp3C = (BtIntPtr)func_80100094(arg0, 0);
            func_800FC660(0xE);
            func_80800AB8_chnicecavemen(arg0, func_800DA298(arg0->actorData[4]) ? 6 : 5);
            _subaddieitem_entrypoint_0(sp3C, arg0->actorData[6], -1, 1);
            _subaddieitem_entrypoint_2(sp3C);
        } else {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D6, 0xF, arg0->position, 0xA2);
        }
        break;
    case 0x17D7:
        if (!func_80800BF8_chnicecavemen((BtIntPtr)arg0)) {
            func_80801428_chnicecavemen(arg0);
        }
        func_80800AB8_chnicecavemen(arg0, func_800DA298(arg0->actorData[4]) ? 12 : 9);
        break;
    case 0x17D8:
        func_80801508_chnicecavemen(arg0, 1, 0x30);
        func_800D1000(0x2D, 1, NULL, 1, 0);
        break;
    case 0x17FD:
    case 0x1811:
        func_80801428_chnicecavemen(arg0);
        func_80800AB8_chnicecavemen(arg0, 12);
        break;
    default:
        sp38 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80801810_chnicecavemen, 7);
        sp34 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80801848_chnicecavemen, 7);
        sp30 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80801880_chnicecavemen, 7);
        sp2C = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_808018B8_chnicecavemen, 4);
        if (_subaddiedialog_entrypoint_10(sp38) || _subaddiedialog_entrypoint_10(sp30)) {
            if (func_80801580_chnicecavemen((f32 *)arg0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, func_8080126C_chnicecavemen(arg0), 0x4E, arg0->position, 0xA2);
            } else {
                func_800C01A8(0x64, 0);
                func_800C0850();
                func_80801428_chnicecavemen(arg0);
                func_80800AB8_chnicecavemen(arg0, func_800DA298(arg0->actorData[4]) ? 10 : 1);
            }
        } else if (_subaddiedialog_entrypoint_10(sp34)) {
            func_80801428_chnicecavemen(arg0);
            func_80800AB8_chnicecavemen(arg0, 9);
        } else if (_subaddiedialog_entrypoint_10(sp2C)) {
            if (!func_80800BF8_chnicecavemen((BtIntPtr)arg0)) {
                func_80801428_chnicecavemen(arg0);
            }
            func_80800AB8_chnicecavemen(arg0, 12);
        } else {
            if (func_800DA298(arg0->actorData[4])) {
                sp28 = func_800DA298(arg0->actorData[5]) ? 12 : 10;
            } else {
                sp28 = func_800DA298(arg0->actorData[5]) ? 9 : 1;
            }
            func_80801428_chnicecavemen(arg0);
            func_80800AB8_chnicecavemen(arg0, sp28);
        }
        break;
    }
}

void func_80800AB8_chnicecavemen(Actor *arg0, s32 arg1) {
    BT_IDO_ONLY(s32 _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);) BT_NATIVE_ONLY(s32 _subaddiepalette_entrypoint_2(Actor *, void *, u16, f32);)
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    int func_801021BC(Actor *, s32);
    void func_80102424(Actor *, s32);
    s32 func_80800C6C_chnicecavemen(Actor *);
    void func_80801508_chnicecavemen(Actor *, s32, s32);
    extern s32 D_808018E8_chnicecavemen[9];
    struct {
        u8 pad0[0x14];
        u16 palette;
    } *data;
    s32 value;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 7:
        break;
    case 11:
        if (func_801021BC(arg0, 11)) {
            break;
        }
        arg1 = 12;
    case 12:
        func_80800C6C_chnicecavemen(arg0);
        break;
    case 8:
        value = 0;
        switch (arg0->unk74_7) {
        case 0x32:
            value = 16;
            break;
        case 0x33:
            value = 12;
            break;
        case 0x34:
            value = 9;
            break;
        }
        func_80801508_chnicecavemen(arg0, value, 40);
        func_800F7F98(func_800F54E4(), 1);
        if (_subaddiepalette_entrypoint_2(arg0, &data->palette, 0x7E7, 3.0f)) {
            func_800BBCB8(arg0->position, NULL, 1.0f, 1, D_808018E8_chnicecavemen);
        }
        break;
    }
    func_80102424(arg0, arg1);
}

/* extern */

int func_80800BF8_chnicecavemen(BtIntPtr arg0) {
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA980(s32, s32);
    s32 first;
    s32 second;

    if (func_800D0A9C(0x2D, 1) == 0) {
        first = func_800DA980(0x16C, 3) == 3;
        second = func_800DA980(0x324, 3) == 3;
        return first && second;
    }
    return 0;
}

/* extern */

s32 func_80800C6C_chnicecavemen(Actor *arg0) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, s16);)
    void func_80102424(Actor*, s32);
    int func_80800BF8_chnicecavemen();
#ifdef BT_NATIVE
    if (((int (*)())func_80800BF8_chnicecavemen)() != 0) {
#else
    if (func_80800BF8_chnicecavemen() != 0) {
#endif
        func_80102424(arg0, 4);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D8U, 0xEU, arg0->position, 0xA2U);
        return 1;
    }
    return 0;
}
typedef struct { s32 values[7]; } SoundParams;
void func_80800CC8_chnicecavemen(Actor *arg0) {

    extern SoundParams D_80801B8C_chnicecavemen;
    extern u32 D_80801BA8_chnicecavemen[];
    extern s32 D_80801BC0_chnicecavemen[], D_80801BEC_chnicecavemen[], D_80801C1C_chnicecavemen[];
    extern s32 D_80801C60_chnicecavemen[], D_80801C8C_chnicecavemen[], D_80801CA0_chnicecavemen[];
    extern u32 D_80801C78_chnicecavemen[];
    extern s32 D_80801CB8_chnicecavemen[], D_80801CD0_chnicecavemen[];
    extern s32 D_80801CEC_chnicecavemen[], D_80801CF4_chnicecavemen[], D_80801D08_chnicecavemen[];
    extern f32 D_80801D1C_chnicecavemen[];
    extern u32 D_80801D28_chnicecavemen[], D_80801D38_chnicecavemen[];
    extern s32 D_80801D48_chnicecavemen[], D_80801D5C_chnicecavemen[], D_80801D70_chnicecavemen[];
    extern u32 D_80801D94_chnicecavemen[];
    extern s32 D_80801DA8_chnicecavemen[], D_80801DB8_chnicecavemen[];
    s32 func_801022E4(Actor *);
    f32 func_80101F24(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EF1B8(f32 *, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32 *, f32 *, f32, s32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_2(Actor *, f32 *, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, s32 *, s32 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    int func_800DC298(f32);
    s32 func_800DC128(s32, s32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    s32 animation;
    f32 progress;
    s32 loop;
    f32 start[3];
    f32 end[3];
    f32 mouth[3];
    SoundParams sound;
    s32 emit;
    s32 joint;
    f32 hit[3];
    f32 target[3];

    animation = func_801022E4(arg0);
    progress = func_80101F24(arg0);
    loop = 0;
    switch (animation) {
        case 0x2CD:
            if (func_80101E14(arg0, 0.7f)) {
                if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, start)) {
                    func_800EE7F8(end, start);
                    func_800EF1B8(end, arg0->rotation[1], -50.0f);
                    end[1] += 30.0f;
                    func_800BABB8(0, start, end, 1.0f, D_80801BC0_chnicecavemen);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801CA0_chnicecavemen);
            }
            loop = 1;
            break;
        case 0x2CF:
            if (_subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801CB8_chnicecavemen, D_80801CD0_chnicecavemen)
                && func_800DC298(0.4f)
                && _subaddieskeleton_entrypoint_2(arg0->unk0, 5, mouth)) {
                func_800BBCB8(mouth, arg0->position, 1.0f, 3, D_80801BEC_chnicecavemen);
            }
            loop = progress > 0.4f;
            break;
        case 0x2CE:
            sound = D_80801B8C_chnicecavemen;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C60_chnicecavemen, sound.values);
            loop = progress < 0.6f;
            break;
        case 0x2D0:
        case 0x2D1:
        case 0x2D2:
            if (func_80101E4C(arg0, D_80801D1C_chnicecavemen)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801CEC_chnicecavemen);
            }
            if (func_80101E14(arg0, 0.83f)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801CF4_chnicecavemen);
            }
            if (func_80101E14(arg0, 0.08f)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801D08_chnicecavemen);
            }
            break;
        case 0x2D6:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D28_chnicecavemen, 0.05f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D38_chnicecavemen, 0.16f);
            break;
        case 0x2D4:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801D48_chnicecavemen, D_80801D5C_chnicecavemen);
            break;
        case 0x2D3:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C60_chnicecavemen, D_80801D70_chnicecavemen);
            break;
        case 0x2E2:
            emit = 0;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C8C_chnicecavemen, D_80801DA8_chnicecavemen);
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801C78_chnicecavemen, 0.3f)) {
                emit = 1;
                joint = 4;
            }
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D94_chnicecavemen, 0.84f)) {
                emit = 1;
                joint = 6;
            }
            if (emit && _subaddieskeleton_entrypoint_2(arg0->unk0, joint, hit)) {
                func_800EE7F8(target, hit);
                func_800EF1B8(target, arg0->rotation[1] - 30.0f, -20.0f);
                target[1] -= 30.0f;
                func_800BBCB8(hit, target, 1.0f, func_800DC128(4, 8), D_80801C1C_chnicecavemen);
            }
            break;
        case 0x2E1:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C8C_chnicecavemen, D_80801DB8_chnicecavemen);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801C78_chnicecavemen, 0.3f);
            break;
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, loop, D_80801BA8_chnicecavemen);
}

/* extern */

s32 func_80801178_chnicecavemen(Actor *arg0) {
    typedef struct { u8 pad[0x824]; s32 unk824; } CavemanData;
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void func_800DA544(s32);
    BtUIntPtr func_800F54E4(void);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    CavemanData *sp34;
    f32 sp28[3];

    sp34 = func_80100094(arg0, 0U);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 4, sp28);
    if (_subaddieitem_entrypoint_3(arg0, sp28, sp34) != 0) {
        sp34->unk824 = 1;
        func_800F8300(func_800F54E4(), 2, arg0->position);
        func_800DA544(arg0->actorData[5]);
        return 1;
    }
    return 0;
}

/* extern */

void func_80801200_chnicecavemen(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    BT_IDO_ONLY(s32 _subaddiepalette_entrypoint_0(void *, void *, s32);) BT_NATIVE_ONLY(s32 _subaddiepalette_entrypoint_0(Actor *, u8 *, u16);)
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    s32 var_v0;

    sp1C = func_80100094(arg0, 0U);
    if ((func_800DA298((*(s32 *)((s8 *)(arg0) + (0x28)))) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        var_v0 = 0x7E7;
    } else {
        var_v0 = 0x7E6;
    }
    _subaddiepalette_entrypoint_0(arg0, sp1C + 0x14, var_v0 & 0xFFFF);
}

/* extern */

s32 func_8080126C_chnicecavemen(void *arg0) {
    int func_800DC298(f32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F640C(BtIntPtr, s32);
    BtIntPtr sp24;
    s32 var_v1;

    sp24 = func_800F54E4();
    if ((*(s32 *)((s8 *)arg0 + 0x30)) == 0) {
        if (func_800DC298(0.5f) != 0) {
            if (func_800F640C(sp24, 0x3CA) > 0) {
                (*(s32 *)((s8 *)(arg0) + (0x30))) = 0x3CA;
            } else {
                (*(s32 *)((s8 *)(arg0) + (0x30))) = 0x3CB;
            }
        } else if (func_800F640C(sp24, 0x3CB) > 0) {
            (*(s32 *)((s8 *)(arg0) + (0x30))) = 0x3CB;
        } else {
            (*(s32 *)((s8 *)(arg0) + (0x30))) = 0x3CA;
        }
    } else if (func_800F640C(sp24, (*(s32 *)((s8 *)arg0 + 0x30))) == 0) {
        (*(s32 *)((s8 *)arg0 + 0x30)) = (*(s32 *)((s8 *)arg0 + 0x30)) == 0x3CA ? 0x3CB : 0x3CA;
    }
    return (*(s32 *)((s8 *)arg0 + 0x30)) == 0x3CA ? 0x17D5 : 0x1803;
}    typedef struct { u8 pad0[0xE]; s8 unkE; } Objnicecavemen_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

s32 func_8080134C_chnicecavemen(Actor *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void func_80801464_chnicecavemen(Actor *, s32, s32);
    s32 temp_v0;

    ((Objnicecavemen_arg1 *)arg1)->unkE = arg4;
    temp_v0 = _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, arg1, arg2, arg3);
    if (temp_v0 == 0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, temp_v0, arg2, arg3) != 3) {
        func_80801464_chnicecavemen(arg0, 2, 0);
    }
    return 1;
}

/* extern */

s32 func_808013D0_chnicecavemen(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80801464_chnicecavemen(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 2) {
            func_80801464_chnicecavemen(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80801428_chnicecavemen(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

void func_80801464_chnicecavemen(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_808018D8_chnicecavemen[4];

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x13, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->actorData[0] = 2;
            _gcdialogcamera_entrypoint_3(D_808018D8_chnicecavemen, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80801508_chnicecavemen(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x13, arg2);
        case 2:
            arg0->actorData[0] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

int func_80801580_chnicecavemen(f32 *arg0) {
    BtUIntPtr func_800F54E4(void);
    s32 func_800F640C(BtIntPtr, s32);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_8010CB84(f32 *, u32);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    if (func_8010CB84(arg0 + 1, 0x12C) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, 0x3CA) > 0 || func_800F640C(sp1C, 0x3CB) > 0;
}

void func_80801604_chnicecavemen(Actor *arg0) {
    void _chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    s32 _glcutDll_entrypoint_20(void);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    void func_8010A570(Actor *);

    switch (arg0->unk74_7) {
        case 0x32:
        case 0x33:
            _chfirefx_entrypoint_2(arg0, 1.2f, 50.0f, 0xF, 0xD);
            arg0->actorData[4] = arg0->unk74_7 + 0x2F2;
            break;
        case 0x34:
            _chfirefx_entrypoint_2(arg0, 1.5f, 100.0f, 0x14, 5);
            arg0->actorData[4] = 0x326;
            func_80102FDC(arg0, 1.0f);
            break;
    }
    if (func_800DA298(arg0->actorData[4]) || _glcutDll_entrypoint_20()) {
        func_8010A570(arg0);
        func_80101FDC(arg0, 2);
    }
}

/* extern */

s32 func_808016E8_chnicecavemen(Actor *arg0, s32 arg1, volatile s32 arg2) {
    typedef struct { u8 pad[0x18]; BT_BITFIELD_ORDER(u16 unused : 15, u16 flags : 1); BT_BITFIELD_ORDER(u16 flags : 1, u16 unused : 15); } CavemanEvent;
    s32 _chfirefx_entrypoint_5(Actor *, s32, s32);
    void func_800DA544(s32);
    void func_800FC6B0(u32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    (void)&arg2;
    if (arg1 == 0x40) {
        if (((CavemanEvent *)*(s32 *)&arg2)->flags) {
            func_8010114C(*(s32 *)&arg2, 0x92, 0);
        }
        func_8010A570(arg0);
        func_80101FDC(arg0, 2);
        func_800DA544(arg0->actorData[4]);
        func_800FC6B0(0xE);
        return 1;
    }
    return _chfirefx_entrypoint_5(arg0, arg1, arg2);
}
/* data_to_c.py: from asm/data/overlays/ch/nicecavemen.data.s */
extern u8 D_8080190C_chnicecavemen[];
void func_80105834(Actor*);
void func_801018A4();
void func_80107C2C();
extern u8 D_808019EC_chnicecavemen[];
extern u8 D_8080197C_chnicecavemen[];
void _chfirefx_entrypoint_3();
void _chfirefx_entrypoint_4();
void func_80108ED0();
s32 D_80801810_chnicecavemen[14] BT_DATA(4, overlays_ch_nicecavemen, 0x0) = { 1, 399442176, 1, 399507968, 512, 403702016, 512, 399507968, 1024, 403636480, 1024, 399507968, -73729, 302711552 };
s32 D_80801848_chnicecavemen[14] BT_DATA(4, overlays_ch_nicecavemen, 0x38) = { 1, 399573248, 1, 399639040, 512, 399573248, 512, 399639040, 1024, 399573248, 1024, 399639040, -73729, 302711552 };
s32 D_80801880_chnicecavemen[14] BT_DATA(4, overlays_ch_nicecavemen, 0x70) = { 1, 399704320, 1, 399770112, 512, 399704320, 512, 399770112, 1024, 399704320, 1024, 399770112, -73729, 302711552 };
s32 D_808018B8_chnicecavemen[8] BT_DATA(4, overlays_ch_nicecavemen, 0xA8) = { 1, 400097792, 512, 400097792, 1024, 400097792, -73729, 302711552 };
u32 D_808018D8_chnicecavemen[4] BT_DATA(4, overlays_ch_nicecavemen, 0xC8) = { 0x43020000, 0x42F00000, 0x42F00000, 0x42700000 };
s32 D_808018E8_chnicecavemen[9] BT_DATA(4, overlays_ch_nicecavemen, 0xD8) = { 1902568, 2819430, 90570786, 33554944, 125831040, 1376256, 12582942, 262148, 0 };
u8 D_8080190C_chnicecavemen[112] BT_DATA(4, overlays_ch_nicecavemen, 0xFC) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x02, 0xCD, 0x00, 0x01, 0x40, 0xD0, 0x00, 0x00, 0x02, 0xCD, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x40, 0x6E, 0xB8, 0x52, 0x02, 0xD6, 0x00, 0x01, 0x40, 0xD0, 0x00, 0x00, 0x02, 0xCD, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x40, 0x6C, 0xCC, 0xCD, 0x02, 0xD0, 0x00, 0x02, 0x40, 0xD0, 0x00, 0x00, 0x02, 0xCD, 0x00, 0x01, 0x40, 0xD0, 0x00, 0x00, 0x02, 0xCD, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x3E, 0xDC, 0x28, 0xF6, 0x02, 0xD5, 0x00, 0x02, 0x40, 0x6E, 0xB8, 0x52, 0x02, 0xD6, 0x00, 0x01, 0x40, 0x6E, 0xB8, 0x52, 0x02, 0xD6, 0x00, 0x01 };
u8 D_8080197C_chnicecavemen[112] BT_DATA(4, overlays_ch_nicecavemen, 0x16C) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x07, 0x33, 0x33, 0x02, 0xCF, 0x00, 0x01, 0x41, 0x07, 0x33, 0x33, 0x02, 0xCF, 0x00, 0x01, 0x40, 0xC4, 0xCC, 0xCD, 0x02, 0xE1, 0x00, 0x01, 0x40, 0x7C, 0xCC, 0xCD, 0x02, 0xD4, 0x00, 0x01, 0x41, 0x07, 0x33, 0x33, 0x02, 0xCF, 0x00, 0x01, 0x40, 0xC4, 0xCC, 0xCD, 0x02, 0xE1, 0x00, 0x01, 0x40, 0x6C, 0xCC, 0xCD, 0x02, 0xD2, 0x00, 0x02, 0x41, 0x07, 0x33, 0x33, 0x02, 0xCF, 0x00, 0x01, 0x41, 0x07, 0x33, 0x33, 0x02, 0xCF, 0x00, 0x01, 0x40, 0xC4, 0xCC, 0xCD, 0x02, 0xE1, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x7C, 0xCC, 0xCD, 0x02, 0xD4, 0x00, 0x01, 0x40, 0x7C, 0xCC, 0xCD, 0x02, 0xD4, 0x00, 0x01 };
u8 D_808019EC_chnicecavemen[112] BT_DATA(4, overlays_ch_nicecavemen, 0x1DC) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xEA, 0x8F, 0x5C, 0x02, 0xCE, 0x00, 0x01, 0x40, 0xEA, 0x8F, 0x5C, 0x02, 0xCE, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x40, 0x26, 0x66, 0x66, 0x02, 0xD3, 0x00, 0x01, 0x40, 0xEA, 0x8F, 0x5C, 0x02, 0xCE, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x40, 0x6C, 0xCC, 0xCD, 0x02, 0xD1, 0x00, 0x02, 0x40, 0xEA, 0x8F, 0x5C, 0x02, 0xCE, 0x00, 0x01, 0x40, 0xEA, 0x8F, 0x5C, 0x02, 0xCE, 0x00, 0x01, 0x40, 0xC0, 0xA3, 0xD7, 0x02, 0xE2, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x26, 0x66, 0x66, 0x02, 0xD3, 0x00, 0x01, 0x40, 0x26, 0x66, 0x66, 0x02, 0xD3, 0x00, 0x01 };
ActorData D_80801A5C_chnicecavemen [1] BT_DATA(4, overlays_ch_nicecavemen, 0x24C) = { { 783, 934, 2021, 1, (void *)D_8080190C_chnicecavemen, (void (*)(struct Actor *))func_80800128_chnicecavemen, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 1065353216, 0, 0, 16512, 356, (void (*)(struct Actor *))func_808003B8_chnicecavemen, 0, 2088, 0, (void (*)(struct Actor *))func_80800030_chnicecavemen, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 29714, (void (*)(struct Actor *, long, long))func_808003D8_chnicecavemen, 0 } };
ActorData D_80801AA4_chnicecavemen [1] BT_DATA(4, overlays_ch_nicecavemen, 0x294) = { { 783, 1067, 2021, 1, (void *)D_808019EC_chnicecavemen, (void (*)(struct Actor *))func_80800128_chnicecavemen, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 1065353216, 0, 0, 16512, 356, (void (*)(struct Actor *))func_808003B8_chnicecavemen, 0, 2088, 0, (void (*)(struct Actor *))func_80800030_chnicecavemen, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 29714, (void (*)(struct Actor *, long, long))func_808003D8_chnicecavemen, 0 } };
ActorData D_80801AEC_chnicecavemen [1] BT_DATA(4, overlays_ch_nicecavemen, 0x2DC) = { { 783, 1068, 2021, 1, (void *)D_8080197C_chnicecavemen, (void (*)(struct Actor *))func_80800128_chnicecavemen, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 1065353216, 0, 0, 16512, 356, (void (*)(struct Actor *))func_808003B8_chnicecavemen, 0, 2088, 0, (void (*)(struct Actor *))func_80800030_chnicecavemen, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 29714, (void (*)(struct Actor *, long, long))func_808003D8_chnicecavemen, 0 } };
ActorData D_80801B34_chnicecavemen [1] BT_DATA(4, overlays_ch_nicecavemen, 0x324) = { { 784, 936, 1787, 1, 0, (void (*)(struct Actor *))_chfirefx_entrypoint_3, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_chfirefx_entrypoint_4, 262144000, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80801604_chnicecavemen, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25600, (void (*)(struct Actor *, long, long))func_808016E8_chnicecavemen, 0 } };
s32 D_80801B7C_chnicecavemen[4] BT_DATA(4, overlays_ch_nicecavemen, 0x36C) = { 24051712, 19660962, 12, 104595456 };
SoundParams D_80801B8C_chnicecavemen BT_DATA(4, overlays_ch_nicecavemen, 0x37C) = { { 1059313418, 1060655596, 1061662228, 1062836634, 1064011039, 1065185444, -1082130432 } };
u32 D_80801BA8_chnicecavemen [6] BT_DATA(4, overlays_ch_nicecavemen, 0x398) = { 0x13049A, 0xE0133, 0x14C0026, 0x164E20, 0x1012C, 0x7080000 };
s32 D_80801BC0_chnicecavemen [11] BT_DATA(4, overlays_ch_nicecavemen, 0x3B0) = { 68157469, 165478434, 3342400, 4980825, 1376307, 11730989, 1966120, 2752524, 3342592, 25165839, 0 };
s32 D_80801BEC_chnicecavemen [12] BT_DATA(4, overlays_ch_nicecavemen, 0x3DC) = { 1903069, 2088615, 1895825442, 3342400, 4980825, 1376307, 11730989, 1310750, 2818252, 16777230, 524298, 0 };
s32 D_80801C1C_chnicecavemen [17] BT_DATA(4, overlays_ch_nicecavemen, 0x40C) = { 1902244, 1446274, 1834808, -19660761, -39256664, 39322200, 2949240, 9175074, 458762, 196613, 2818406, 30146581, 179, 262246, 458754, 917509, 655360 };
s32 D_80801C60_chnicecavemen [6] BT_DATA(4, overlays_ch_nicecavemen, 0x450) = { 1246210, 1465792, 852211, 17563649, 19662600, 0 };
u32 D_80801C78_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x468) = { 0x1304D9, 0xD0099, 0xB30001, 0x12C0708, 0 };
s32 D_80801C8C_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x47C) = { 1246364, 852352, 26804225, 19662600, 0 };
s32 D_80801CA0_chnicecavemen [6] BT_DATA(4, overlays_ch_nicecavemen, 0x490) = { 1246571, 852185, 15925270, 1179648001, 19662600, 0 };
s32 D_80801CB8_chnicecavemen [6] BT_DATA(4, overlays_ch_nicecavemen, 0x4A8) = { 1246281, 852160, 14221313, 19662600, 1456792, 0 };
s32 D_80801CD0_chnicecavemen [7] BT_DATA(4, overlays_ch_nicecavemen, 0x4C0) = { 1008981770, 1032805417, 1039516303, 1044549468, 1048576000, 1050589266, -1082130432 };
s32 D_80801CEC_chnicecavemen [2] BT_DATA(4, overlays_ch_nicecavemen, 0x4DC) = { 1246651, 131072 };
s32 D_80801CF4_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x4E4) = { 1246260, 655513, 1469792, 65836, 117964800 };
s32 D_80801D08_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x4F8) = { 1246364, 852160, 14221313, 19662600, 0 };
f32 D_80801D1C_chnicecavemen [3] BT_DATA(4, overlays_ch_nicecavemen, 0x50C) = { 0.2f, 0.5f, -1.0f };
u32 D_80801D28_chnicecavemen [4] BT_DATA(4, overlays_ch_nicecavemen, 0x518) = { 0x1305B3, 0x164650, 0x1012C, 0x7080000 };
u32 D_80801D38_chnicecavemen [4] BT_DATA(4, overlays_ch_nicecavemen, 0x528) = { 0x1305B4, 0x164650, 0x1012C, 0x7080000 };
s32 D_80801D48_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x538) = { 1246564, 852134, 12582913, 19662600, 0 };
s32 D_80801D5C_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x54C) = { 1035489772, 1045220557, 1050589266, 1054615798, -1082130432 };
s32 D_80801D70_chnicecavemen [9] BT_DATA(4, overlays_ch_nicecavemen, 0x560) = { 1035489772, 1047233823, 1051931443, 1056293519, 1058642330, 1060823368, 1062836634, 1064849900, -1082130432 };
u32 D_80801D94_chnicecavemen [5] BT_DATA(4, overlays_ch_nicecavemen, 0x584) = { 0x130449, 0xD0099, 0xB30001, 0x12C0708, 0 };
s32 D_80801DA8_chnicecavemen [4] BT_DATA(4, overlays_ch_nicecavemen, 0x598) = { 1031127695, 1041865114, 1047904911, -1082130432 };
s32 D_80801DB8_chnicecavemen [6] BT_DATA(4, overlays_ch_nicecavemen, 0x5A8) = { 1031127695, 1041865114, 1047904911, -1082130432, 0, 0 };
