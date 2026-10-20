#include "common.h"

s32 func_80800000_chweather(s32 arg0) {
    return 1;
}

s32 func_8080000C_chweather(s32 arg0) {
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 values[3];
    } position;

    func_8010D254(position.words);
    return position.values[2] < -1700.0f;
}

 s32 func_80800050_chweather(s32 arg0) {
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 values[3];
    } position;

    func_8010D254(position.words);
    return position.values[2] > 1700.0f;
}

s32 func_80800094_chweather(s32 arg0) {
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
    extern u8 D_80800440_chweather[];

    return (OSThread *) D_80800440_chweather;
}

OSThread *chweather_entrypoint_1(void)
{
    extern u8 D_80800488_chweather[];

    return (OSThread *) D_80800488_chweather;
}

OSThread *chweather_entrypoint_2(void)
{
    extern u8 D_808004D0_chweather[];

    return (OSThread *) D_808004D0_chweather;
}

OSThread *chweather_entrypoint_3(void)
{
    extern u8 D_80800518_chweather[];

    return (OSThread *) D_80800518_chweather;
}

OSThread *chweather_entrypoint_4(void)
{
    extern u8 D_80800560_chweather[];

    return (OSThread *) D_80800560_chweather;
}

OSThread *chweather_entrypoint_5(void)
{
    extern u8 D_808005A8_chweather[];

    return (OSThread *) D_808005A8_chweather;
}

OSThread *chweather_entrypoint_6(void)
{
    extern u8 D_808005F0_chweather[];

    return (OSThread *) D_808005F0_chweather;
}

OSThread *chweather_entrypoint_7(void)
{
    extern u8 D_80800638_chweather[];

    return (OSThread *) D_80800638_chweather;
}

struct WeatherEntry {
    s16 state;
    s16 rain;
    s32 (*check)();
};

s32 func_80800138_chweather(s32 arg0, s32 arg1) {
    s32 _fxleaves_entrypoint_5(s32);
    s32 _fxleaves_entrypoint_6(s32);
    s32 _fxrain_entrypoint_6(s32, f32, f32, f32, f32);
    s32 _fxrain_entrypoint_7(s32);
    s32 _fxrain_entrypoint_8(s32);
    s32 func_800B7C10(void);
    s32 func_800B7C54(void);
    s32 func_800B7CA4(void);
    void func_800B90C8(void);
    void func_800B90E8(void);
    extern struct WeatherEntry D_80800410_chweather[];
    s32 rain;
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
        entry = (struct WeatherEntry *)((u8 *)D_80800410_chweather +
                                      ((actor->unk6C_9 - 0x204) << 3));
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
    actor->unk70_10 = arg1;
}

void func_808002A8_chweather(s32 arg0) {
    s32 func_80800138_chweather(s32, s32);
    extern struct WeatherEntry D_80800410_chweather[];
    struct WeatherEntry *entry;
    Actor *actor = (Actor *)arg0;

    entry = (struct WeatherEntry *)((u8 *)D_80800410_chweather +
                                  ((actor->unk6C_9 - 0x204) << 3));
    if ((actor->unk70_10 == 2) && (entry->check() != 0)) {
        func_80800138_chweather(arg0, entry->state);
    }
    if ((actor->unk70_10 != 2) && (entry->check(arg0) == 0)) {
        func_80800138_chweather(arg0, 2);
    }
}

/* extern */

void func_8080035C_chweather(void) {
    s32 func_800B7D28();
    s32 func_8010C500();
    if (func_8010C500() != 0) {
        func_800B7D28();
    }
}

/* extern */

void func_8080038C_chweather(void) {
    s32 func_800B7DC8();
    s32 func_8010C500();
    if (func_8010C500() != 0) {
        func_800B7DC8();
    }
}

/* extern */

s32 func_808003BC_chweather(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800138_chweather(s32, s32);
    if (arg1 == 0x95) {
        func_80800138_chweather(arg0, 2);
        return 1;
    }
    return 0;
}
