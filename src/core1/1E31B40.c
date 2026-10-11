#include "common.h"

extern s32 D_8007BCC4;

void func_8001A010(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A018.s")

/* extern */

void func_8001A080(void) {
    s32 func_8001A018(s32);
    D_8007BCC4 = func_8001A018(0x21D80);
}

s32 func_8001A0A8()
{
    return D_8007BCC4;
}

u32 func_8001A0B4(void) {
    return 0x00021D80U;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A0C0.s")

void func_8001A0F0(void) {
    extern OSMesgQueue D_8007BEE0;
    osRecvMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A11C(void) {
    extern OSMesgQueue D_8007BEE0;
    osSendMesg(&D_8007BEE0, NULL, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A1E0.s")

void func_8001A270(Gfx *start, Gfx *end) {
    void func_8001A1E0(Gfx *start, Gfx *end, s32 flags);

    func_8001A1E0(start, end, 0x40000000);
}

void func_8001A290()
{
    func_80015190();
}

void func_8001A2B0()
{
    func_80013D10(0x3);
}

void func_8001A2D0(void) {
    s32 func_80014C40();
    extern s16 D_8007BED8;
    extern OSMesgQueue D_8007BEE0;
    extern void *D_8007BEF8;
    D_8007BED8 = 0;
    osCreateMesgQueue(&D_8007BEE0, &D_8007BEF8, 1);
    osSendMesg(&D_8007BEE0, NULL, 1);
    func_80014C40();
}

void func_8001A324(void) {
    s32 func_8001A63C();
    s32 heap_free(s32);
    extern s32 D_8007BCD0;
    extern s32 D_8007BCD4;
    extern s32 D_8007BCD8;
    extern s32 D_8007BCDC;
    extern s32 D_8007BCE0;
    extern s32 D_8007BCE4;
    if (D_8007BCD0 != 0) {
        heap_free(D_8007BCD0);
        heap_free(D_8007BCD4);
        heap_free(D_8007BCD8);
        heap_free(D_8007BCDC);
        heap_free(D_8007BCE0);
        heap_free(D_8007BCE4);
        D_8007BCD0 = 0;
    }
    func_8001A63C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A4B8.s")

void func_8001A570(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A63C.s")
