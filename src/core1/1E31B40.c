#include "common.h"

void func_80013D10(OSMesg);

extern s32 D_8007BCC4;

void func_8001A010(void) {
}

s32 func_8001A018(s32 arg0) {
    void *heap_alloc(s32);
    extern void *D_8007BCC0;
    s16 *var_v1;

    var_v1 = D_8007BCC0 = heap_alloc(arg0 + 0x40);
    if ((s32)var_v1 % 64) {
        do {
            var_v1++;
        } while ((s32)var_v1 % 64);
    }
    return (s32)var_v1;
}

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

s32 func_8001A0C0(s32 arg0, s32 arg1) { return *(u16 *)((u8 *)D_8007BCC4 + ((arg1 * 0x13) << 5) + (arg0 << 1)); }

void func_8001A0F0(void) {
    extern OSMesgQueue D_8007BEE0;
    osRecvMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A11C(void) {
    extern OSMesgQueue D_8007BEE0;
    osSendMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A148(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    u8 *temp_a0;

    func_8001A0F0();
    temp_a0 = (D_8007BED8 * 0x18) + &D_8007BCF8;
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    (*(s32 *)((s8 *)(temp_a0) + (0))) = 0;
    (*(s32 *)((s8 *)(temp_a0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_a0) + (0xC))) = arg1;
    (*(s32 *)((s8 *)(temp_a0) + (0x10))) = arg2;
    (*(s32 *)((s8 *)(temp_a0) + (0x14))) = arg3;
    func_80013D10(temp_a0);
}

void func_8001A1E0(Gfx *arg0, Gfx *arg1, s32 arg2) {
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    u8 *temp_a0;

    func_8001A0F0();
    temp_a0 = (D_8007BED8 * 0x18) + &D_8007BCF8;
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    (*(s32 *)((s8 *)(temp_a0) + (0))) = 1;
    (*(s32 *)((s8 *)(temp_a0) + (4))) = arg2;
    (*(s32 *)((s8 *)(temp_a0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_a0) + (0xC))) = arg1;
    func_80013D10(temp_a0);
}

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

void func_8001A3A0(void) {
    void func_8001A570(void);
    s32 func_800A9800();
    void *heap_alloc(s32);
    extern s32 D_8007BCD0;
    extern s32 D_8007BCD4;
    extern s32 D_8007BCD8;
    extern s32 D_8007BCDC;
    extern s32 D_8007BCE0;
    extern s32 D_8007BCE4;
    extern s16 D_8007BEDA;
    if (D_8007BCD0 == 0) {
        D_8007BCD0 = heap_alloc(0x76C0);
        D_8007BCD4 = heap_alloc(0x76C0);
        D_8007BCD8 = heap_alloc(0x12C00);
        D_8007BCDC = heap_alloc(0x12C00);
        D_8007BCE0 = heap_alloc(0x1AE0);
        D_8007BCE4 = heap_alloc(0x1AE0);
        func_8001A570();
    }
    D_8007BEDA = 0;
    func_800A9800();
}

void func_8001A440(s32 arg0) {
    void func_80015430(s32);
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    s32 *temp_a0;

    func_8001A0F0();
    func_80015430(arg0);
    temp_a0 = (s32 *)((D_8007BED8 * 0x18) + &D_8007BCF8);
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    *temp_a0 = 7;
    func_80013D10(temp_a0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A4B8.s")

void func_8001A570(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E31B40/func_8001A578.s")

s32 func_8001A63C(void) {
    s32 heap_free(s32);
    extern s32 D_8007BCE8;
    extern s32 D_8007BCEC;
    extern s32 D_8007BCF0;
    extern s32 D_8007BCF4;
    s32 sp18[2];

    sp18[0] = D_8007BCF0;
    if (D_8007BCE8 != 0) {
        heap_free(D_8007BCE8);
        heap_free(D_8007BCEC);
        D_8007BCE8 = 0;
    }
    if (sp18[0] != 0) {
        heap_free(D_8007BCF0);
        heap_free(D_8007BCF4);
        D_8007BCF0 = 0;
    }
}
