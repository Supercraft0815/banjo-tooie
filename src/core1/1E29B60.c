#include "core1/1E29B60.h"

void func_80012030(void *unused) {
    extern u8 core1_BSS_START[];
    extern u8 core1_BSS_END[];
    void func_80013620(void);
    bzero(core1_BSS_START, core1_BSS_END - core1_BSS_START);
    osWritebackDCacheAll();
    osInitialize();
    func_80013620();
}

void func_8001207C(void) 
{
    func_800D5E74();
}

void func_8001209C(s32 arg0) {
    s32 func_800155BC();
    s32 func_8001A2B0();
    s32 func_800A7B24();
    s32 func_800A7BB8(s32);
    extern s32 D_800459CC;
    func_8001A2B0();
    func_800155BC();
    if (D_80043380 == 1) {
        func_800A7B24();
    }
    func_8001207C();
    D_80043380 = arg0;
    if (D_80043380 == 1) {
        func_800A7BB8(D_800459CC);
    }
}

s32 func_8001210C(s32 arg0) {
    return D_800459C8 & arg0;
}

s32 func_8001211C(void) 
{
    return D_800459C8;
}

void func_80012128(void)
{
    D_800459C8 = 0;
}

void func_80012520(s32);
void func_8001253C(s32);
void func_80012134(void) { func_8001253C(_cosection_entrypoint_1()); func_80012520(1); }

void func_80012164(void) { func_8001253C(_cosection_entrypoint_0()); func_80012520(1); }

s32 func_80012194(void) { extern u8 *D_8007E994; return (s32)D_8007E994 - (s32)core2_VRAM_END; }

s32 func_800121AC(void) { return (s32)core2_VRAM_END - (s32)func_80012030 + (s32)0xFFF21DD0; }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800121D0.s")

// Needs migration
#if 0
void func_80012214(void) {
    D_800459D0 = osGetMemSize();
    func_8001DDF0(); // start_cic_thread
    init_crc_check();
    func_80014FE8(); // start_vi_thread
    func_8001E7E8();
    func_8001C1C0();
    func_80019EC0(0, core2_VRAM, core2_VRAM_END, core2_ROM_START, core2_ROM_END, core2_TEXT_START, core2_TEXT_END, core2_RODATA_START, core2_DATA_END, core2_BSS_START, core2_BSS_END);
    heap_setup(TRUE);
    func_80014E6C();
    D_80043388.unk400 = 0x01020304;
    D_80043388.unk404 = 0x05060708;
    D_800459D8 = 0x0102030405060708ULL;
    func_801168F0();
    func_800815CC();
    func_8001A080();
    func_8001A2D0();
    func_800121D0();
    func_80016734();
    func_800184E8();
    func_800125B0();
    func_8001A3A0();
    func_800D66AC();
    func_800D5D70();
    func_800E692C();
    _gcstatusDll_entrypoint_0();
    func_800C929C();
    D_80043380 = 0;
    D_800459C8 = 0;
    func_800A5BE0();
    _cosection_entrypoint_1();
    func_8001253C(func_80087890());
    func_8001209C(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_80012214.s")
#endif

s32 func_800123B0()
{
    return D_800459D0;
}

/* extern */

void func_800123BC(void) {
    s32 func_800A5D1C();
    s32 func_800A7840(s32);
    s32 func_800A7D84();
    if (func_800A7D84() != 0) {
        func_800A7840(0);
    }
    func_800A5D1C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E29B60/func_800123F4.s")

/* extern */

void func_800124EC(void *arg0) {
    s32 func_80012214();
    s32 func_800123F4();
    func_80012214();
loop_1:
    func_800123F4();
    goto loop_1;
}

void func_80012520(s32 arg0) {
    extern s32 D_80043384;
    D_80043384 = arg0 + 1;
}

s32 func_80012530()
{
    return D_80043380;
}

void func_8001253C(s32 arg0)
{
    extern s32 D_800459CC;

    D_800459CC = arg0;
}

void func_80012548(void) {
    extern u8 D_80045788[];
    extern __OSThreadOddFpStorage D_80045938;
    func_8001DD28((OSThread *)D_80045788, &D_80045938, 6, func_800124EC, 0, (u8 *)&D_80043388 + 0x2400, 0x14);
}

OSThread *func_80012598(void)
{
    extern u8 D_80045788[];

    return (OSThread *) D_80045788;
}
