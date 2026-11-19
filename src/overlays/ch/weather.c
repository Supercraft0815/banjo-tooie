#include "common.h"
#include "core2/weather_effects.h"

s32 func_80800000_chweather(BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32 arg0)) {
    return 1;
}

s32 func_8080000C_chweather(BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32 arg0)) {
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 values[3];
    } position;

    func_8010D254(position.words);
    return position.values[2] < -1700.0f;
}

 s32 func_80800050_chweather(BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32 arg0)) {
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 values[3];
    } position;

    func_8010D254(position.words);
    return position.values[2] > 1700.0f;
}

s32 func_80800094_chweather(BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32 arg0)) {
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 values[3];
    } position;

    func_8010D254(position.words);
    return position.values[0] > 1700.0f;
}

OSThread *chweather_entrypoint_0(void)
{
    extern ActorData D_80800440_chweather[];

    return (OSThread *) D_80800440_chweather;
}

OSThread *chweather_entrypoint_1(void)
{
    extern ActorData D_80800488_chweather[];

    return (OSThread *) D_80800488_chweather;
}

OSThread *chweather_entrypoint_2(void)
{
    extern ActorData D_808004D0_chweather[];

    return (OSThread *) D_808004D0_chweather;
}

OSThread *chweather_entrypoint_3(void)
{
    extern ActorData D_80800518_chweather[];

    return (OSThread *) D_80800518_chweather;
}

OSThread *chweather_entrypoint_4(void)
{
    extern ActorData D_80800560_chweather[];

    return (OSThread *) D_80800560_chweather;
}

OSThread *chweather_entrypoint_5(void)
{
    extern ActorData D_808005A8_chweather[];

    return (OSThread *) D_808005A8_chweather;
}

OSThread *chweather_entrypoint_6(void)
{
    extern ActorData D_808005F0_chweather[];

    return (OSThread *) D_808005F0_chweather;
}

OSThread *chweather_entrypoint_7(void)
{
    extern ActorData D_80800638_chweather[];

    return (OSThread *) D_80800638_chweather;
}

struct WeatherEntry {
    s16 state;
    s16 rain;
    s32 (*check)(BT_NATIVE_ONLY(void));
};

s32 func_80800138_chweather(BtIntPtr arg0, s32 arg1) {
    void func_800B7CA4();
    void func_800B90C8(void);
    void func_800B90E8(void);
    extern struct WeatherEntry D_80800410_chweather[];
    RainEmitter *rain;
    struct WeatherEntry *entry;
    Actor *actor = (Actor *)arg0;

    if (arg1 == 3) {
        _fxleaves_entrypoint_5(func_800B7C10());
    }
    if (actor->unk70_10 == 3) {
        _fxleaves_entrypoint_6(func_800B7C10());
    }
    if (arg1 == 4) {
        rain = func_800B7C54();
        entry = BT_DATA_FIELD(&D_80800410_chweather[actor->unk6C_9 - 0x204],
                          (struct WeatherEntry *)((u8 *)D_80800410_chweather + ((actor->unk6C_9 - 0x204) << 3)));
        _fxrain_entrypoint_7(rain);
        if (entry->rain != 0) {
            _fxrain_entrypoint_6(rain, 5.0f, 30.0f, 5.0f, 30.0f);
        }
    }
    if (actor->unk70_10 == 4) {
        _fxrain_entrypoint_8(func_800B7C54());
    }
    if (arg1 == 5) {
        func_800B7CA4();
        func_800B90C8();
    }
    if (actor->unk70_10 == 5) {
        func_800B7CA4();
        func_800B90E8();
    }
    actor->unk70_10 = arg1; BT_NATIVE_ONLY(return 0;)
}

void func_808002A8_chweather(BtIntPtr arg0) {
    s32 func_80800138_chweather(BtIntPtr, s32);
    extern struct WeatherEntry D_80800410_chweather[];
    struct WeatherEntry *entry;
    Actor *actor = (Actor *)arg0;

    entry = BT_DATA_FIELD(&D_80800410_chweather[actor->unk6C_9 - 0x204],
                          (struct WeatherEntry *)((u8 *)D_80800410_chweather + ((actor->unk6C_9 - 0x204) << 3)));
    if ((actor->unk70_10 == 2) && (entry->check() != 0)) {
        func_80800138_chweather(arg0, entry->state);
    }
    if ((actor->unk70_10 != 2) && (entry->check(BT_IDO_ONLY(arg0)) == 0)) {
        func_80800138_chweather(arg0, 2);
    }
}

/* extern */

void func_8080035C_chweather(BT_PARAM_OR_VOID(Actor *actor)) {
    void func_800B7D28(void);
    s32 func_8010C500(BT_NATIVE_ONLY(Actor *));
    if (func_8010C500(BT_NATIVE_ONLY(actor)) != 0) {
        func_800B7D28();
    }
}

/* extern */

void func_8080038C_chweather(BT_PARAM_OR_VOID(Actor *actor)) {
    void func_800B7DC8(void);
    s32 func_8010C500(BT_NATIVE_ONLY(Actor *));
    if (func_8010C500(BT_NATIVE_ONLY(actor)) != 0) {
        func_800B7DC8();
    }
}

/* extern */

s32 func_808003BC_chweather(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800138_chweather(BtIntPtr, s32);
    if (arg1 == 0x95) {
        func_80800138_chweather(arg0, 2);
        return 1;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/weather.data.s */
void func_8010A730();
void func_80107C2C();
struct WeatherEntry D_80800410_chweather [6] BT_DATA(4, overlays_ch_weather, 0x0) = { { 3, 1, func_80800000_chweather }, { 3, 0, func_8080000C_chweather }, { 4, 1, func_80800000_chweather }, { 4, 0, func_80800050_chweather }, { 5, 1, func_80800000_chweather }, { 5, 0, func_80800094_chweather } };
ActorData D_80800440_chweather [1] BT_DATA(4, overlays_ch_weather, 0x30) = { { 449, 516, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_80800488_chweather [1] BT_DATA(4, overlays_ch_weather, 0x78) = { { 449, 517, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_808004D0_chweather [1] BT_DATA(4, overlays_ch_weather, 0xC0) = { { 449, 518, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_80800518_chweather [1] BT_DATA(4, overlays_ch_weather, 0x108) = { { 449, 519, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_80800560_chweather [1] BT_DATA(4, overlays_ch_weather, 0x150) = { { 449, 520, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_808005A8_chweather [1] BT_DATA(4, overlays_ch_weather, 0x198) = { { 449, 521, 0, 1, 0, (void (*)(struct Actor *))func_808002A8_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_808005F0_chweather [1] BT_DATA(4, overlays_ch_weather, 0x1E0) = { { 449, 522, 0, 1, 0, (void (*)(struct Actor *))func_8080035C_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
ActorData D_80800638_chweather [1] BT_DATA(4, overlays_ch_weather, 0x228) = { { 449, 523, 0, 1, 0, (void (*)(struct Actor *))func_8080038C_chweather, 0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808003BC_chweather, 0 } };
