#include "core2/1EA3AA0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA2A8.s")

void func_800CA314(s32 arg0,s32 arg1)
{
    aligned4_memcpy(arg0,arg1,0x168);
}

u8 *func_800CA334(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x168);
    sp1C = temp_v0;
    func_800CA440((s32) temp_v0);
    return sp1C;
}

void func_800CA364(void* arg0) 
{
    heap_free(arg0);
}
void* func_800CA384(void* arg0) 
{
    return defrag(arg0);
}
void func_800CA3A4(s32 arg0, f32 arg1) {
    void func_800EF04C(f32[3], f32[3]);
    void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
    f32 sp24[3];

    func_800EF4E4(sp24, (*(f32 *)((s8 *)(arg0) + (0x18))), (*(f32 *)((s8 *)(arg0) + (0x1C))), 0.0f, 0.0f, arg1);
    func_800EF04C((f32 *) arg0, sp24);
}

void func_800CA3F4(u8 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32[3], f32[3]);
    void func_800EF368(f32 vec[3], f32 target_length);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp1C[3];

    func_800EFB24(sp1C, arg0, arg1);
    func_800EF368(sp1C, arg2);
    func_800EF04C(arg1, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA440.s")

/* extern */

void func_800CA510(void *arg0, f32 arg1) {
    s32 func_800CA1B0(f32);
    s32 func_800CA2A8(void *, f32);
    (*(f32 *)((s8 *)(arg0) + (0xE8))) = arg1;
    func_800CA1B0(arg1);
    func_800CA2A8(arg0, (*(f32 *)((s8 *)(arg0) + (0xE4))) * 0.5f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA558.s")

void func_800CA5B8()
{
    func_800EE7F8();
}

void func_800CA5D8()
{
    func_800EE84C();
}

void func_800CA5F8(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0, arg1, arg2, arg3);
}

void func_800CA628(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = arg1[i];
        arg0[i + 6] = arg2[i];
    }
}

void func_800CA668(s32 arg0) { func_800EE7F8(arg0 + 0x18); }

void func_800CA688(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x18, arg1, arg2, arg3);
}

void func_800CA6C0(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0xEC))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0xF0))) = arg2;
}

void func_800CA6D4(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (0xEC)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (0xF0)));
}

f32 func_800CA6E8(f32 *arg0) {
    return arg0[89];
}

void func_800CA6F0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 356) = arg1;
}

f32 func_800CA6FC(f32 *arg0) {
    return arg0[58];
}

f32 func_800CA704(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    func_800EFB24((void *)arg2, (void *)arg1, (void *)arg0);
    return func_800EEAA4((f32 *)(arg0 + 0xC), (f32 *)arg2);
}

void func_800CA740(void *arg0, f32 *arg1) {
    func_800EE7F8(arg1, (u8 *)arg0 + 0xC);
}

/* extern */

void func_800CA768(s32 arg0, s32 arg1) {
    s32 func_800EEAD4(s32, s32, s32);
    func_800EEAD4(arg1, arg0, arg1);
}

f32 func_800CA794(f32 *arg0) {
    return arg0[57];
}

f32 func_800CA79C(f32 *arg0) {
    return arg0[61];
}

void *func_800CA7A4(void *arg0) {
    return (void *) ((u8 *) arg0 + 0x64);
}

void *func_800CA7AC(void *arg0) {
    return (void *) ((u8 *) arg0 + 0xA4);
}

f32 func_800CA7B4(f32 *arg0) {
    return arg0[59];
}

void func_800CA7BC(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (0xE4)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (0xE8)));
    *arg3 = (*(f32 *)((s8 *)(arg0) + (0xEC)));
    *arg4 = (*(f32 *)((s8 *)(arg0) + (0xF0)));
}

void func_800CA7E4(s32 arg0, s32 *arg1) { func_800EE7F8(arg1, (s32 *)arg0); }

void func_800CA810(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (0))) * 500.0f) / 500.0f);
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (4))) * 500.0f) / 500.0f);
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (8))) * 500.0f) / 500.0f);
}

void func_800CA8B4(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg1[i] = arg0[i];
        arg2[i] = arg0[i + 6];
    }
}

void func_800CA8F4(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg1[i] = arg0[i];
        arg2[i] = arg0[i + 3];
    }
}

void func_800CA934(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (0))) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (4))) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(arg0) + (8))) * 500.0f) / 500.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CA9D8.s")

void func_800CAA00(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (0x18)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (0x1C)));
    *arg3 = (*(f32 *)((s8 *)(arg0) + (0x20)));
}

f32 func_800CAA1C(f32 *arg0) {
    return arg0[7];
}

s32 func_800CAA24(f32 *arg0, f32 *arg1, f32 *arg2) {
    struct Data { f32 pad[9]; f32 planes[4][4]; };
    s32 i;
    f32 x, y, z, v;
    f32 *plane;

    for (i = 0; i < 4; i++) {
        plane = ((struct Data *)arg0)->planes[i];
        x = plane[0];
        y = plane[1];
        z = plane[2];
        v = x >= 0.0f ? arg1[0] : arg2[0];
        x *= v;
        v = y >= 0.0f ? arg1[1] : arg2[1];
        y *= v;
        v = z >= 0.0f ? arg1[2] : arg2[2];
        z *= v;
        if (plane[3] + (x + y + z) >= 0.0f) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CAB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CACEC.s")

s32 func_800CAD9C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 *p = arg0;

    if ((p[9] * arg1 + p[10] * arg2 + p[11] * arg3 + p[12] <= 0.0f) &&
        (p[13] * arg1 + p[14] * arg2 + p[15] * arg3 + p[16] <= 0.0f) &&
        (p[17] * arg1 + p[18] * arg2 + p[19] * arg3 + p[20] <= 0.0f) &&
        (p[21] * arg1 + p[22] * arg2 + p[23] * arg3 + p[24] <= 0.0f)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CAEA4.s")

f32 func_800CAF00(f32 *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    return func_800136E4(arg0[7] + arg1 + 90.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CAF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CB0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA3AA0/func_800CB124.s")
