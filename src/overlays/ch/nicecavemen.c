#include "common.h"

OSThread *chnicecavemen_entrypoint_0(void)
{
    extern u8 D_80801A5C_chnicecavemen[];

    return (OSThread *) D_80801A5C_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_1(void)
{
    extern u8 D_80801AA4_chnicecavemen[];

    return (OSThread *) D_80801AA4_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_2(void)
{
    extern u8 D_80801AEC_chnicecavemen[];

    return (OSThread *) D_80801AEC_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_3(void)
{
    extern u8 D_80801B34_chnicecavemen[];

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
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    s32 _subaddiepalette_entrypoint_1(Actor *, void *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 func_800DA298(s32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F7B9C(s32, u32);
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80800AB8_chnicecavemen(Actor *, s32);
    void func_80800CC8_chnicecavemen(Actor *);
    s32 func_80801178_chnicecavemen(Actor *);
    s32 func_8080134C_chnicecavemen(Actor *, s32 *, s32 *, s32, s32);
    extern s32 D_80801810_chnicecavemen;
    extern s32 D_80801848_chnicecavemen;
    extern s32 D_80801880_chnicecavemen;
    extern s32 D_808018B8_chnicecavemen;
    extern s32 D_80801B7C_chnicecavemen;
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
                func_8080134C_chnicecavemen(arg0, &D_80801B7C_chnicecavemen, &D_80801810_chnicecavemen, 7, 2);
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
                func_8080134C_chnicecavemen(arg0, &D_80801B7C_chnicecavemen, &D_80801848_chnicecavemen, 7, 2);
            }
            break;
        case 10:
            func_8080134C_chnicecavemen(arg0, &D_80801B7C_chnicecavemen, &D_80801880_chnicecavemen, 7, 3);
            break;
        case 11:
            if (func_80101DDC(arg0)) {
                func_80800AB8_chnicecavemen(arg0, 12);
            }
            break;
        case 12:
            func_8080134C_chnicecavemen(arg0, &D_80801B7C_chnicecavemen, &D_808018B8_chnicecavemen, 4, 4);
            break;
    }
    func_80800CC8_chnicecavemen(arg0);
    _subaddiepalette_entrypoint_1(arg0, data->palette);
}

void func_808003B8_chnicecavemen(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_808003D8_chnicecavemen.s")

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
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
    void _subaddieitem_entrypoint_2(s32);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA298(s32);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    void func_80800AB8_chnicecavemen(Actor *, s32);
    int func_80800BF8_chnicecavemen(s32);
    s32 func_8080126C_chnicecavemen(void *);
    void func_80801428_chnicecavemen(void *);
    void func_80801508_chnicecavemen(Actor *, s32, s32);
    int func_80801580_chnicecavemen(f32 *);
    extern s32 D_80801810_chnicecavemen;
    extern s32 D_80801848_chnicecavemen;
    extern s32 D_80801880_chnicecavemen;
    extern s32 D_808018B8_chnicecavemen;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    switch (arg1) {
    case 0x17D5:
    case 0x1803:
        if (arg2 > 0) {
            sp3C = (s32)func_80100094(arg0, 0);
            func_800FC660(0xE);
            func_80800AB8_chnicecavemen(arg0, func_800DA298(arg0->actorData[4]) ? 6 : 5);
            _subaddieitem_entrypoint_0(sp3C, arg0->actorData[6], -1, 1);
            _subaddieitem_entrypoint_2(sp3C);
        } else {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D6, 0xF, arg0->position, 0xA2);
        }
        break;
    case 0x17D7:
        if (!func_80800BF8_chnicecavemen((s32)arg0)) {
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
        sp38 = _subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80801810_chnicecavemen, 7);
        sp34 = _subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80801848_chnicecavemen, 7);
        sp30 = _subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80801880_chnicecavemen, 7);
        sp2C = _subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_808018B8_chnicecavemen, 4);
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
            if (!func_80800BF8_chnicecavemen((s32)arg0)) {
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
    s32 _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void *func_80100094(Actor *, u32);
    int func_801021BC(Actor *, s32);
    void func_80102424(Actor *, s32);
    s32 func_80800C6C_chnicecavemen(Actor *);
    void func_80801508_chnicecavemen(Actor *, s32, s32);
    extern s32 D_808018E8_chnicecavemen;
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
            func_800BBCB8(arg0->position, NULL, 1.0f, 1, &D_808018E8_chnicecavemen);
        }
        break;
    }
    func_80102424(arg0, arg1);
}

/* extern */

int func_80800BF8_chnicecavemen(s32 arg0) {
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
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    void func_80102424(Actor*, s32);
    int func_80800BF8_chnicecavemen();
    if (func_80800BF8_chnicecavemen() != 0) {
        func_80102424(arg0, 4);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D8U, 0xEU, arg0->position, 0xA2U);
        return 1;
    }
    return 0;
}

void func_80800CC8_chnicecavemen(Actor *arg0) {
    typedef struct { s32 values[7]; } SoundParams;
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
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
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
                    func_800EF1B8(end, *(f32 *)((u8 *)arg0 + 0x48), -50.0f);
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
                func_800EF1B8(target, *(f32 *)((u8 *)arg0 + 0x48) - 30.0f, -20.0f);
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
    u32 func_800F54E4(void);
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
    s32 _subaddiepalette_entrypoint_0(void *, void *, s32);
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
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 sp24;
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
}

s32 func_8080134C_chnicecavemen(Actor *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    void func_80801464_chnicecavemen(Actor *, s32, s32);
    s32 temp_v0;

    *(s8 *)((s8 *)arg1 + 0xE) = arg4;
    temp_v0 = _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, arg1, arg2, arg3);
    if (temp_v0 == 0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9((s32)arg0, temp_v0, arg2, arg3) != 3) {
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
    extern u32 D_808018D8_chnicecavemen;

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x13, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->actorData[0] = 2;
            _gcdialogcamera_entrypoint_3(&D_808018D8_chnicecavemen, arg0->scale);
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
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 func_8010CB84(f32 *, u32);
    s32 sp1C;
    s32 temp_v0;

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
    typedef struct { u8 pad[0x18]; u16 unused : 15; u16 flags : 1; } CavemanEvent;
    s32 _chfirefx_entrypoint_5(Actor *, s32, s32);
    void func_800DA544(s32);
    void func_800FC6B0(u32);
    s32 func_8010114C(s32, s32, s32);
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
