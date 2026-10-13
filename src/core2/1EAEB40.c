#include "common.h"

void func_800D5250()
{
    func_800D52B0();
}

void func_800D5270(void)
{
    extern u8 D_8012B431;

    D_8012B431 = 0;
}

void func_800D527C(s32 arg0) {
    extern u8 D_8012B430;
    (*(u8 *)((s8 *)(&D_8012B430) + (0))) = arg0 + 1;
    (*(s8 *)((s8 *)(&D_8012B430) + (1))) = 1;
}

u32 func_800D5298(void) {
    extern u8 D_8012B431;
    return *(u8 *)((u8 *)&D_8012B431 + 0);
}

u32 func_800D52A4(void) {
    extern u8 D_8012B430;
    return *(u8 *)((u8 *)&D_8012B430 + 0);
}

int func_800D52B0(void) {
    extern u8 D_8012B430;
    (*(s8 *)((s8 *)(&D_8012B430) + (1))) = 0;
    (*(s16 *)((s8 *)(&D_8012B430) + (2))) = -1;
    (*(s8 *)((s8 *)(&D_8012B430) + (0))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAEB40/func_800D52CC.s")

s32 func_800D52F4(void) {
    extern s16 D_8012B432;
    return *(s16 *)((u8 *)&D_8012B432 + 0);
}

void func_800D5300(s32 arg0, s32 arg1) {
}
void func_800D530C(s32 arg0, s32 arg1) {
}
void func_800D5318(void *arg0, s32 arg1) {
    extern s32 _gspropctrl_entrypoint_2(void *);
    extern s32 _gspropctrl_entrypoint_3(void *);
    extern s32 _gspropctrl_entrypoint_4(void *);
    extern void _gspropctrl_entrypoint_5(void *, s32);
    extern s32 func_8001211C(void);
    extern void _gcsectionskip_entrypoint_1(void *, s32, s32, u8, s32);
    extern void (*D_8011B680[])(void *, s32);
    extern void (*D_8011B7C0[])(void *, s32);
    s32 frame;

    switch (_gspropctrl_entrypoint_2(arg0)) {
        case 3:
            frame = func_8001211C();
            if (_gspropctrl_entrypoint_3(arg0) + 1 != frame) {
                D_8011B680[_gspropctrl_entrypoint_4(arg0)](arg0, arg1);
            }
            _gspropctrl_entrypoint_5(arg0, frame);
            break;
        case 5:
            _gcsectionskip_entrypoint_1(arg0, *(u16 *)((u8 *)arg0 + 8) + 0xA0,
                *(s32 *)((u8 *)arg0 + 0xC) & 0x7FFFFF,
                *((u8 *)arg0 + 0xB), arg1);
            break;
        case 4:
            D_8011B7C0[_gspropctrl_entrypoint_4(arg0)](arg0, arg1);
            break;
    }
}

s32 func_800D5424(s32 arg0) {
    return arg0 - 0x16;
}

s32 func_800D542C(s32 arg0) {
    return arg0 + 0x9A;
}
