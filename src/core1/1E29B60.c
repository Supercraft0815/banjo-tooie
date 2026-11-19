#include "core1/1E29B60.h"
#ifdef BT_NATIVE
#include <stdint.h>
#include "threads.h"
void func_800D5E74(void);
s32 _cosection_entrypoint_0(void);
#endif

s32 D_800459D0;
u64 D_800459D8;

void func_80012030(void *unused) {
    extern u8 core1_BSS_START[];
    extern u8 core1_BSS_END[];
    void func_80013620(void);
#ifndef BT_NATIVE // host .bss starts zeroed and caches are coherent
    bzero(core1_BSS_START, core1_BSS_END - core1_BSS_START);
    osWritebackDCacheAll();
#endif
    osInitialize();
    func_80013620();
}

void func_8001207C(void) 
{
    func_800D5E74();
}

void func_8001209C(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1)) {
    void func_800155BC(void);
    void func_8001A2B0();
    void func_800A7B24(BT_IDO_ONLY(void) BT_PASS2(s32, s32));
    void func_800A7BB8(s32 arg0);
    extern s32 D_800459CC;
    func_8001A2B0();
    func_800155BC();
    if (D_80043380 == 1) {
        func_800A7B24(BT_PASS2(arg0, bt_a1));
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

#ifdef BT_NATIVE
// N64 memory-map sizes; the host binary has no core2 end address, so these only
// keep their callers' arithmetic well defined.
s32 func_80012194(void) { extern u8 *D_8007E994; return (s32)((uintptr_t)D_8007E994 - (uintptr_t)core2_VRAM_END); }

s32 func_800121AC(void) { return (s32)((uintptr_t)core2_VRAM_END - (uintptr_t)func_80012030) + (s32)0xFFF21DD0; }
#else
s32 func_80012194(void) { extern u8 *D_8007E994; return (s32)D_8007E994 - (s32)core2_VRAM_END; }

s32 func_800121AC(void) { return (s32)core2_VRAM_END - (s32)func_80012030 + (s32)0xFFF21DD0; }
#endif

void func_800121D0(void) {
    u32 func_8001E830(void);
    s32 a = func_80012194();
    s32 x;

    a = func_8001E830() + a;
    x = a & 0xFFFFFFFF;
    while (x & 0xF) {
        x--;
    }
}

// Needs migration
#if 0
void func_80012214(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1)) {
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
    func_8001209C(1 BT_PASS2(, bt_a1));
}
#else
void func_80012214(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1)) {
    extern u8 core2_DATA_START[];
    extern u8 core2_RODATA_END[];

    D_800459D0 = osGetMemSize();
    func_8001DDF0(); // start_cic_thread
    init_crc_check();
    func_80014FE8(); // start_vi_thread
    func_8001E7E8();
    func_8001C1C0();
#ifndef BT_NATIVE // core2 is linked into the executable, nothing to load
    func_80019EC0(0, core2_VRAM, core2_VRAM_END, core2_ROM_START, core2_ROM_END, core2_TEXT_START, core2_TEXT_END, core2_DATA_START, core2_RODATA_END, core2_BSS_START, core2_BSS_END);
#endif
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
    func_800D740C();
    func_8001253C(_cosection_entrypoint_1());
    func_8001209C(1 BT_PASS2(, bt_a1));
}
#endif

s32 func_800123B0()
{
    return D_800459D0;
}

/* extern */

void func_800123BC(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    void func_800A5D1C(void);
    void func_800A7840(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1) BT_PASS2(, s32 bt_a2));
    s32 func_800A7D84(BT_PASS2(s32, s32));
    if (func_800A7D84(BT_PASS2(bt_a0, bt_a1)) != 0) {
        func_800A7840(0 BT_PASS2(, bt_a1) BT_PASS2(, bt_a2));
    }
    func_800A5D1C();
}

void func_800123F4(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    void do_crc_check(void);
    s32 func_80012530(void);
    void func_8001608C(void);
    void func_80018444(void);
    void func_8001E010(void);
    void func_8008160C(s32);
    void func_800A7D30(void);
    s16 func_800A8184(void);
    f32 func_800D9004(void);

    extern s32 D_80043384;

    func_8001207C();
    if ((D_80043380 != 1) || (func_800A8184() != 4)) {
        D_800459C8 += 1;
    }
    if (func_80012530() == 1) {
        func_800A7D30();
    }
    func_8001608C();
    func_80018444();
    if (D_80043380 == 1) {
        func_800123BC(BT_PASS2(bt_a0, bt_a1) BT_PASS2(, bt_a2));
    }
    func_8008160C(1);
    func_8001E010();
    if (func_800D9004() <= 0.05f) {
        do_crc_check();
    }
    if (D_80043384 != 0) {
        func_8001209C(D_80043384 - 1 BT_PASS2(, bt_a1));
        D_80043384 = 0;
    }
}

/* extern */

void func_800124EC(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    void func_80012214(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1));
    void func_800123F4(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1) BT_PASS2(, s32 bt_a2));
    func_80012214(BT_PASS2((s32)arg0, bt_a1));
loop_1:
    func_800123F4(BT_PASS2((s32)arg0, bt_a1) BT_PASS2(, bt_a2));
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

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80043380 BT_DATA(16, bss_core1bss1_0, 0x0);
s32 D_80043384 BT_DATA(4, bss_core1bss1_0, 0x4);
u8 D_80045788 [ 432 ] BT_DATA(4, bss_core1bss1_0, 0x2408);
__OSThreadOddFpStorage D_80045938 BT_DATA(8, bss_core1bss1_0, 0x25B8);
s32 D_800459C8 BT_DATA(4, bss_core1bss1_0, 0x2648);
s32 D_800459CC BT_DATA(4, bss_core1bss1_0, 0x264C);
u8 * D_8007E994 BT_DATA(4, bss_core1bss1_2_cic_tail, 0xE14);
#endif
