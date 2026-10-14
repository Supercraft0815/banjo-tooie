#include "core2/1E78170.h"

s32 D_80127050[4];

extern s32 D_80127080;

void func_8009E880(void) {
    extern f32 D_80127040;
    extern f32 D_80127068;
    (*(s8 *)((s8 *)(&D_80127068) + (0xC))) = 1;
    (*(s8 *)((s8 *)(&D_80127068) + (0xD))) = 0;
    (*(s8 *)((s8 *)(&D_80127040) + (0xC))) = 1;
    (*(f32 *)((s8 *)(&D_80127040) + (0))) = 0.0f;
    (*(f32 *)((s8 *)(&D_80127040) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(&D_80127040) + (8))) = 0.0f;
}

void func_8009E8B4(void)
{
    func_800C6E58();
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78170/func_8009E8D4.s")

u32 func_8009E958(void) {
    extern u8 D_8012704C;
    return *(u8 *)((u8 *)&D_8012704C + 0);
}

u32 func_8009E964(void) {
    extern u8 D_80127078;
    return *(u8 *)((u8 *)&D_80127078 + 0);
}

f32 func_8009E970(void) {
    extern f32 D_80127048;
    return *(f32 *)((u8 *)&D_80127048 + 0);
}

f32 func_8009E97C(void) {
    extern f32 D_80127040;
    return *(f32 *)((u8 *)&D_80127040 + 0);
}

f32 func_8009E988(void) {
    extern f32 D_80127044;
    return *(f32 *)((u8 *)&D_80127044 + 0);
}

u32 func_8009E994(void) {
    extern u8 D_80127075;
    return *(u8 *)((u8 *)&D_80127075 + 0);
}

void func_8009E9A0(void) {
}

void func_8009E9A8(void) {
    extern void func_8009E9FC(f32);
    extern void func_8009EB0C(f32);
    func_8009E9FC(0.0f); func_8009EB0C(0.0f);
}

void func_8009E9D8(s32 arg0) {
    extern u8 D_8012704C;
    D_8012704C = arg0;
}

void func_8009E9E4(s32 arg0) {
    extern u8 D_80127078;
    D_80127078 = arg0;
}

void func_8009E9F0(f32 arg0) {
    extern f32 D_80127048;
    *(f32 *)((u8 *)&D_80127048 + 0) = arg0;
}

void func_8009E9FC(f32 arg0) {
    extern f32 D_80127040;
    *(f32 *)((u8 *)&D_80127040 + 0) = arg0;
}

void func_8009EA08(f32 arg0) {
    extern f32 D_80127070;
    *(f32 *)((u8 *)&D_80127070 + 0) = arg0;
}

f32 func_8009EA14(void) {
    extern f32 D_8012706C;
    return *(f32 *)((u8 *)&D_8012706C + 0);
}

u8 func_8009EA20(void) {
    extern u8 D_80127077;
    return D_80127077;
}

s32 func_8009EA2C()
{
    return func_800DA298(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
}

u32 func_8009EA4C(void) {
    extern u8 D_80127074;
    return *(u8 *)((u8 *)&D_80127074 + 0);
}

s32 func_8009EA58()
{
    return D_80127080;
}

s32 func_8009EA64(void) {
    extern s16 D_8012707C;
    return *(s16 *)((u8 *)&D_8012707C + 0);
}

u32 func_8009EA70(void) {
    extern u8 D_80127076;
    return *(u8 *)((u8 *)&D_80127076 + 0);
}

f32 func_8009EA7C(void) {
    extern f32 D_80127068;
    return *(f32 *)((u8 *)&D_80127068 + 0);
}

f32 func_8009EA88(void) {
    extern f32 D_80127070;
    return *(f32 *)((u8 *)&D_80127070 + 0);
}

void func_8009EA94(f32 arg0) {
    extern f32 D_8012706C;
    *(f32 *)((u8 *)&D_8012706C + 0) = arg0;
}

void func_8009EAA0(s32 arg0) {
    extern u8 D_80127077;
    D_80127077 = arg0;
}

void func_8009EAAC(s32 arg0) {
    func_800DA3B8(FLAG_3EC_ABILITY_DRAGON_KAZOOIE, arg0);
}

void func_8009EAD0(s32 arg0) {
    extern u8 D_80127074;
    D_80127074 = arg0;
}

void func_8009EADC(s32 arg0) {
    *(s32 *)((u8 *)&D_80127080 + 0) = arg0;
}

void func_8009EAE8(s32 arg0) {
    extern s16 D_8012707C;
    *(s16 *)((u8 *)&D_8012707C + 0) = arg0;
}

void func_8009EAF4(s32 arg0) {
    extern u8 D_80127076;
    D_80127076 = arg0;
}

void func_8009EB00(f32 arg0) {
    extern f32 D_80127068;
    *(f32 *)((u8 *)&D_80127068 + 0) = arg0;
}

void func_8009EB0C(f32 arg0) {
    extern f32 D_80127044;
    *(f32 *)((u8 *)&D_80127044 + 0) = arg0;
}

void func_8009EB18(s32 arg0) {
    extern u8 D_80127075;
    D_80127075 = arg0;
}

void func_8009EB24(s16 arg0, s16 arg1)
{
  extern f32 D_80127040;
  extern u8 D_8012704C;
  void func_8009EC60(s16, s16);
  s32 *var_v0;
  u32 end;
 do { var_v0 = (s32 *) (&D_8012704C); end = (u32) (&D_80127040); while (1) { var_v0[4] = var_v0[3]; var_v0--; if (((u32) var_v0) == end) { break; } } } while (0);
  *(((u8 *) (&D_80127040)) + 0x20) += 1;
  func_8009EC60(arg0, arg1);
}

void func_8009EB8C(s16 arg0, s16 arg1) {
    extern f32 D_80127040;
    void func_8009EC3C(void);
    void func_8009EC60(s16, s16);
    func_8009EC3C();
    *((u8 *)&D_80127040 + 0x20) += 1;
    func_8009EC60(arg0, arg1);
}

void func_8009EBD0(void) {
    extern f32 D_80127040;
    extern u8 D_8012704C;
    s32 i;

    for (i = 0; i < 3; i++) {
        ((s32 *)&D_80127040)[i + 4] = ((s32 *)&D_80127040)[i + 5];
    }
    *((u8 *)&D_80127040 + 0x20) -= 1;
}

s32 func_8009EC08(s16 *arg0, s16 *arg1) {
    extern f32 D_80127040;
    if ((*(s16 *)((s8 *)(&D_80127040) + (0x10))) != 0) {
        *arg0 = (*(s16 *)((s8 *)(&D_80127040) + (0x10)));
        *arg1 = (*(s16 *)((s8 *)(&D_80127040) + (0x12)));
        return 1;
    }
    return 0;
}

void func_8009EC3C(void) {
    extern u8 D_80127060;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80127050[i] = 0;
    }
    D_80127060 = 0;
}

void func_8009EC60(s16 arg0, s16 arg1) {
    extern f32 D_80127040;
    (*(s16 *)((s8 *)(&D_80127040) + (0x10))) = arg0;
    (*(s16 *)((s8 *)(&D_80127040) + (0x12))) = arg1;
}

u32 func_8009EC7C(void) {
    extern u8 D_80127060;
    return *(u8 *)((u8 *)&D_80127060 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E78170/func_8009EC88.s")
