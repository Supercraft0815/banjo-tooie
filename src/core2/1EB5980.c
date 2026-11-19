#include "core2/1EB5980.h"
#include "random_float_bits.inc"
s32 func_800DC090(void) {
    extern s32 D_8012C7F0;
    return D_8012C7F0 = (D_8012C7F0 * 0x19660DU) + 0x3C6EF35FU;
}

f32 func_800DC0C0(void) {


    extern s32 D_8012C7F0;
    union { s32 i; f32 f; } sp4;
    f32 result;
    D_8012C7F0 = (D_8012C7F0 * 0x19660DU) + 0x3C6EF35FU;
    sp4.i = (D_8011B9A4 & D_8012C7F0) | D_8011B9A0;
    return (result = sp4.f - 1.0f, result);
}

s32 func_800DC128(s32 arg0, s32 arg1) { return (s32)((func_800DC0C0() * (f32)(arg1 - arg0)) + (f32)arg0); }

f32 func_800DC178(f32 arg0, f32 arg1) {
    return (func_800DC0C0() * (arg1 - arg0)) + arg0;
}

f32 func_800DC1AC(void) {


    extern s32 D_8012C7F4;
    union { s32 i; f32 f; } sp4;
    f32 result;
    D_8012C7F4 = (D_8012C7F4 * 0x19660DU) + 0x3C6EF35FU;
    sp4.i = (D_8011B9A4 & D_8012C7F4) | D_8011B9A0;
    return (result = sp4.f - 1.0f, result);
}

/* extern */

s32 func_800DC214(s32 arg0, s32 arg1) {
    f32 func_800DC1AC();
    return (s32) ((func_800DC1AC() * (f32) (arg1 - arg0)) + (f32) arg0);
}

/* extern */

f32 func_800DC264(f32 arg0, f32 arg1) {
    f32 func_800DC1AC();
    return (func_800DC1AC() * (arg1 - arg0)) + arg0;
}

int func_800DC298(f32 arg0) {
    f32 func_800DC0C0();
    return (func_800DC0C0() < arg0) ? 1 : 0;
}

/* extern */

s32 func_800DC2D4(f32 arg0) {
    f32 func_800DC1AC();
    return (func_800DC1AC() < arg0) ? 1 : 0;
}

void func_800DC310(void) {
    extern s32 D_8012C7F0;
    D_8012C7F0 = 0xEAA0C7;
}    typedef struct { s32 unk0; } Obj1EB5980_D_8012C7F0; /* offsets.py genstruct: fields from raw offsets on &D_8012C7F0; rename once understood */

void func_800DC324(s32 arg0) {
    extern s32 D_8012C7F0;
    ((Obj1EB5980_D_8012C7F0 *)&D_8012C7F0)->unk0 = arg0;
}

void func_800DC330(void) {
    extern s32 D_8012C7F0;
    extern s32 D_8012C7F4;
    extern s32 D_8012C7F8;
    extern s32 D_8012C7FC;
    D_8012C7F8 = D_8012C7F0;
    D_8012C7FC = D_8012C7F4;
}

void func_800DC354(void) {
    extern s32 D_8012C7F8;
    extern s32 D_8012C7FC;
    extern s32 D_8012C7F0;
    extern s32 D_8012C7F4;
    D_8012C7F0 = D_8012C7F8;
    D_8012C7F4 = D_8012C7FC;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012C7F0 BT_DATA(16, bss_core2bss2, 0x0);
s32 D_8012C7F4 BT_DATA(4, bss_core2bss2, 0x4);
s32 D_8012C7F8 BT_DATA(4, bss_core2bss2, 0x8);
s32 D_8012C7FC BT_DATA(4, bss_core2bss2, 0xC);
#endif
