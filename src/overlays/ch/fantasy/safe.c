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
typedef struct { f32 time; f32 value; u8 sound; u8 pad[3]; } SafeStep;
void func_808001A0_chfantasysafe(u8 *arg0) {






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
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
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
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
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
    extern ActorData D_80800AA0_chfantasysafe[];

    return (OSThread *) D_80800AA0_chfantasysafe;
}

OSThread *chfantasysafe_entrypoint_1(void)
{
    extern ActorData D_80800AE8_chfantasysafe[];

    return (OSThread *) D_80800AE8_chfantasysafe;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/safe.data.s */
extern u8 D_80800960_chfantasysafe[];
void func_80105834(Actor*);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
void func_8010C964();
void func_80101870(Actor* arg0, void* arg1);
u8 D_80800960_chfantasysafe[56] BT_DATA(4, overlays_ch_fantasy_safe, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x44 };
f32 D_80800998_chfantasysafe [5] BT_DATA(4, overlays_ch_fantasy_safe, 0x38) = { 135.0f, 720.0f, 320.0f, 640.0f, 120.0f };
u32 D_808009AC_chfantasysafe [10] BT_DATA(4, overlays_ch_fantasy_safe, 0x4C) = { 1, 0x13DB0100, 0x601, 0x13DC0200, 0x200, 0x14570100, 0x400, 0x14580100, 0xFFFEDFFF, 0x120B0300 };
u32 D_808009D4_chfantasysafe [2] BT_DATA(4, overlays_ch_fantasy_safe, 0x74) = { 0x1304C7, 0 };
u32 D_808009DC_chfantasysafe [6] BT_DATA(4, overlays_ch_fantasy_safe, 0x7C) = { 0x3880000, 0x3E80069, 0xF, 0x100, 0x130521, 0 };
u32 D_808009F4_chfantasysafe [2] BT_DATA(4, overlays_ch_fantasy_safe, 0x94) = { 0x130507, 0 };
u32 D_808009FC_chfantasysafe [3] BT_DATA(4, overlays_ch_fantasy_safe, 0x9C) = { 0x1304A1, 0xA0099, 0 };
SafeStep D_80800A08_chfantasysafe [12] BT_DATA(4, overlays_ch_fantasy_safe, 0xA8) = { { 0.0f, 0.0f, 0, { 0, 0, 0 } }, { 2.0f, 1.0f, 1, { 0, 0, 0 } }, { 2.5f, 0.0f, 0, { 0, 0, 0 } }, { 3.0f, 0.25f, 2, { 0, 0, 0 } }, { 3.5f, 0.0f, 0, { 0, 0, 0 } }, { 4.0f, 0.5f, 4, { 0, 0, 0 } }, { 4.5f, 0.0f, 0, { 0, 0, 0 } }, { 5.0f, 0.75f, 8, { 0, 0, 0 } }, { 5.5f, 0.0f, 0, { 0, 0, 0 } }, { 6.25f, 1.0f, 0, { 0, 0, 0 } }, { 7.0f, 0.0f, 0xF, { 0, 0, 0 } }, { 100.0f, 0.0f, 0xF, { 0, 0, 0 } } };
u32 D_80800A98_chfantasysafe [2] BT_DATA(4, overlays_ch_fantasy_safe, 0x138) = { 0x130507, 0 };
ActorData D_80800AA0_chfantasysafe [1] BT_DATA(4, overlays_ch_fantasy_safe, 0x140) = { { 172, 1047, 2266, 1, (void *)D_80800960_chfantasysafe, (void (*)(struct Actor *))func_808001A0_chfantasysafe, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 128, 3104, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chfantasysafe, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800630_chfantasysafe, 0 } };
ActorData D_80800AE8_chfantasysafe [1] BT_DATA(4, overlays_ch_fantasy_safe, 0x188) = { { 344, 1293, 2352, 1, 0, (void (*)(struct Actor *))func_8010C964, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 19660800, 0, 0, 0, 0, 256, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, 0, 0 } };
