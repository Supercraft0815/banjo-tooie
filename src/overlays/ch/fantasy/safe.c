#include "common.h"
#include "gameflags.h"

void func_80800000_chfantasysafe(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(GameFlag);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80800998_chfantasysafe[];
    f32 angle;
    s32 fourth;
    s32 pad;
    s32 third;
    s32 second;
    s32 first;

    func_800EFA4C(arg0->position, 4539.4f, -748.6f, 2277.6f);
    if (_glcutDll_entrypoint_20()) {
        arg0->actorData[4] = 0;
        arg0->unk79_4 = 0;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        arg0->unk50 = 0.0f;
        arg0->unk54 = 0.0f;
        arg0->unk58 = 0.0f;
        arg0->rotation[1] = 228.0f;
        func_80101FDC(arg0, 6);
        return;
    }
    if (func_800DA298(0x38D)) {
        arg0->rotation[1] = 360.0f;
        arg0->unk50 = 0.0f;
        arg0->unk54 = 110.0f;
        func_80101FDC(arg0, 5);
        return;
    }
    first = func_800DA298(0x38B) ? 1 : 0;
    second = func_800DA298(0x38A) ? 1 : 0;
    third = func_800DA298(0x389) ? 1 : 0;
    fourth = func_800DA298(0x38C) ? 1 : 0;
    angle = D_80800998_chfantasysafe[fourth + third + second + first];
    ((f32 *)arg0->actorData)[7] = angle;
    ((f32 *)arg0->actorData)[3] = angle;
    arg0->unk50 = angle;
    arg0->unk54 = 0.0f;
    arg0->rotation[1] = 228.0f;
}

void func_808001A0_chfantasysafe(u8 *arg0) {
    typedef struct {
        f32 time;
        f32 value;
        u8 sound;
        u8 pad[3];
    } SafeStep;
    void _subaddieaudioloop_entrypoint_2(void *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _subaddiedialog_entrypoint_8(u8 *, void *, u32 *, u32 *, s32);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    f32 func_800D91B8(f32 *);
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800FC6B0(u32);
    void func_80101FDC(Actor *, u32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    void func_80103110(void *, s32);
    extern u32 D_808009AC_chfantasysafe[];
    extern u32 D_808009D4_chfantasysafe[];
    extern u32 D_808009DC_chfantasysafe[];
    extern u32 D_808009F4_chfantasysafe[];
    extern u32 D_808009FC_chfantasysafe[];
    extern SafeStep D_80800A08_chfantasysafe[];
    extern u32 D_80800A98_chfantasysafe[];
    void *model;
    s32 music;
    f32 fraction;
    f32 startTime;
    s32 flag389;
    s32 flag38A;
    s32 flag38B;
    s32 flag38C;
    f32 timer;
    f32 nextTime;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _subaddiedialog_entrypoint_8(arg0, arg0 + 4, D_808009DC_chfantasysafe, D_808009AC_chfantasysafe, 5);
            break;
        case 2:
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                if (func_800DA298(0x38B)) {
                    flag38B = 1;
                } else {
                    flag38B = 0;
                }
                if (func_800DA298(0x38A)) {
                    flag38A = 1;
                } else {
                    flag38A = 0;
                }
                if (func_800DA298(0x389)) {
                    flag389 = 1;
                } else {
                    flag389 = 0;
                }
                if (func_800DA298(0x38C)) {
                    flag38C = 1;
                } else {
                    flag38C = 0;
                }
                if (flag38C + flag389 + flag38A + flag38B >= 3) {
                    *(f32 *)(arg0 + 0x58) = 1.0f;
                    func_80101FDC((Actor *)arg0, 3);
                    music = 0x10;
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x13DD, 0, (f32 *)(arg0 + 4), 0);
                } else {
                    func_80101FDC((Actor *)arg0, 1);
                    music = 0xE;
                }
                func_800DA544((*(s32 *)(arg0 + 0x6C) & 0x1FF) + 0x389);
                _subaddieaudioloop_entrypoint_2(arg0);
                func_800FC6B0(music);
                *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x24);
                *(f32 *)(arg0 + 0x50) = *(f32 *)(arg0 + 0x24);
            } else {
                _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, D_808009F4_chfantasysafe);
                *(f32 *)(arg0 + 0x50) = func_800F10B4(*(f32 *)(arg0 + 0x58), 2.0f, 0.0f, *(f32 *)(arg0 + 0x34), *(f32 *)(arg0 + 0x24));
            }
            break;
        case 3:
            *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x58), 1.0f, 0.0f, 0.0f, 110.0f);
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                *(f32 *)(arg0 + 0x54) = 110.0f;
                *(f32 *)(arg0 + 0x58) = 3.0f;
                func_80101FDC((Actor *)arg0, 4);
                _subaddieaudioquick_entrypoint_2((Actor *)arg0, (f32 *)(arg0 + 4), D_808009D4_chfantasysafe);
            }
            break;
        case 4:
            if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                func_80101FDC((Actor *)arg0, 5);
                func_800DA544(0x38D);
                _subaddieaudioloop_entrypoint_2(arg0);
                _subaddieaudioquick_entrypoint_2((Actor *)arg0, (f32 *)(arg0 + 4), D_808009D4_chfantasysafe);
            } else {
                _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, D_808009FC_chfantasysafe);
            }
            *(f32 *)(arg0 + 0x48) = func_800F10B4(*(f32 *)(arg0 + 0x58), 3.0f, 0.0f, 228.0f, 360.0f);
            break;
        case 5:
            func_80103110(arg0, 0);
            break;
        case 6:
            func_800D91B8(&((Actor *)arg0)->unk58);
            /* Direct array accesses preserve IDO's global-base alias information. */
            nextTime = D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28) + 1].time;
            timer = ((Actor *)arg0)->unk58;
            if (nextTime < timer) {
                ++*(s32 *)(arg0 + 0x28);
                if (D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28)].value == 0.0f) {
                    func_800C3F48(0x66538CA0);
                    func_800C3F48(0x4CB38CA1);
                } else {
                    func_800C3F48(0x66538CA1);
                }

                ((Actor *)arg0)->unk79_4 = D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28)].sound;
                nextTime = D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28) + 1].time;
                timer = ((Actor *)arg0)->unk58;
            }
            startTime = D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28)].time;
            fraction = func_800F12D4(timer, startTime, nextTime, D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28)].value, D_80800A08_chfantasysafe[*(s32 *)(arg0 + 0x28) + 1].value);
            *(f32 *)(arg0 + 0x48) = func_800F1214(fraction, 228.0f, 360.0f);
            *(f32 *)(arg0 + 0x54) = func_800F1214(fraction, 0.0f, 110.0f);
            *(f32 *)(arg0 + 0x50) = func_800F1214(fraction, 0.0f, 360.0f);
            _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, D_80800A98_chfantasysafe);
            break;
    }
    model = (void *)func_8010262C(*(Unk80132ED0 **)arg0, 2);
    if (model) {
        func_800E0AFC(model, 0x2A, 1.0f, 0.0f, 0.0f, *(f32 *)(arg0 + 0x54));
        func_800E0AFC(model, 0x2B, 1.0f, 0.0f, 0.0f, *(f32 *)(arg0 + 0x50));
    }
}

s32 func_80800630_chfantasysafe(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(GameFlag);
    int func_800DB9B0(void);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80800998_chfantasysafe[];
    s32 index;
    s32 flags;

    switch (arg1) {
    case 0x49:
        index = arg2 - 0x51;
        flags = 0x810 | (func_800DB9B0() ? 0x100 : 0);
        if (index < 4 && index >= 0) {
            arg0->unk58 = 2.0f;
            func_80101FDC(arg0, 2);
            arg0->unk6C_0 = index;
            ((f32 *)arg0->actorData)[7] = arg0->unk50 = D_80800998_chfantasysafe[index];
            ((f32 *)arg0->actorData)[3] = D_80800998_chfantasysafe[index + 1];
            if ((func_800DA298(0x389) ? 1 : 0) +
                (func_800DA298(0x38A) ? 1 : 0) +
                (func_800DA298(0x38B) ? 1 : 0) +
                (func_800DA298(0x38C) ? 1 : 0) >= 3) {
                _capod_entrypoint_13(arg0->unk0, NULL, 0, flags);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 2, flags);
            }
            return 1;
        }
        return 0;
    case 0x1F:
        func_801015D0(arg0);
        if (_glcutDll_entrypoint_20()) {
            func_800DF744(1, (arg0->unk79_4 & 1) ? 1 : 0);
            func_800DF744(2, (arg0->unk79_4 & 2) ? 1 : 0);
            func_800DF744(3, (arg0->unk79_4 & 4) ? 1 : 0);
            func_800DF744(4, (arg0->unk79_4 & 8) ? 1 : 0);
        } else {
            func_800DF744(1, func_800DA298(0x389) ? 1 : 0);
            func_800DF744(2, func_800DA298(0x38A) ? 1 : 0);
            func_800DF744(3, func_800DA298(0x38B) ? 1 : 0);
            func_800DF744(4, func_800DA298(0x38C) ? 1 : 0);
        }
        return 1;
    }
    return 0;
}

OSThread *chfantasysafe_entrypoint_0(void)
{
    extern u8 D_80800AA0_chfantasysafe[];

    return (OSThread *) D_80800AA0_chfantasysafe;
}

OSThread *chfantasysafe_entrypoint_1(void)
{
    extern u8 D_80800AE8_chfantasysafe[];

    return (OSThread *) D_80800AE8_chfantasysafe;
}
