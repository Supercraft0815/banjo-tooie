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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weather/func_80800050_chweather.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weather/func_80800138_chweather.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weather/func_808002A8_chweather.s")

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
