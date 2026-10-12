#include "core2/1E93440.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800B9B50.s")

s32 func_800BA198(void *arg0) {
    s32 temp_v1;

    if (arg0 != NULL) {
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x90)));
        if (temp_v1 != 0) {
            return (s32) (temp_v1 - (*(s32 *)((s8 *)(arg0) + (0x8C)))) / 60;
        }
    }
    return 0;
}

void func_800BA1D0(s32 emitter, f32 position[3], f32 velocity[3], s32 count) {
    s32 func_800EE940();
    *(u16 *)emitter |= 0x40;
    func_800EE940((s16 *)(emitter + 0x28), position);
    func_800EE940((s16 *)(emitter + 0x2E), velocity);
    *(u8 *)(emitter + 5) = 0;
    func_800BA22C(emitter, count);
}

void func_800BA22C(s32 arg0, s32 n) {
    typedef u8 Particle[0x3C];
    typedef struct { u8 pad0[0x90]; Particle *end; Particle *capacity; } EmitterView;
    void func_800B9B50(EmitterView *, Particle *);
    EmitterView *this = (EmitterView *)arg0;
    for (; n > 0; n--) {
        if (this->end < this->capacity) func_800B9B50(this, this->end++);
    }
}

int func_800BA28C(void *arg0) {
    return ((*(s32 *)((s8 *)arg0 + 0x90) -
             *(s32 *)((s8 *)arg0 + 0x8C)) / 60 == 0) &&
           (*(u8 *)((s8 *)arg0 + 7) == 2);
}

/* extern */

s32 func_800BA2C4(void) {
    s32 heap_free();
    heap_free();
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA2E8.s")

/* extern */

void func_800BA3FC(s32 arg0, s32 arg1) {
    s8 func_800AF5A0(s32);
    s32 func_800D674C(u16);
    s8 func_800D738C(s32);
    if (arg1 != (*(u16 *)((s8 *)(arg0) + (2)))) {
        (*(u16 *)((s8 *)(arg0) + (2))) = (u16) arg1;
        (*(s8 *)((s8 *)(arg0) + (0xA))) = func_800D738C(arg1 & 0xFFFF);
        (*(s8 *)((s8 *)(arg0) + (0xB))) = func_800AF5A0(func_800D674C((*(u16 *)((s8 *)(arg0) + (2)))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA450.s")

void func_800BA4B0(s8 *arg0, s32 arg1) {
    arg0[131] = arg1;
}

void func_800BA4B8(s16 *arg0, s32 arg1, s32 arg2) {
    arg0[85] = arg1;
    ((s32 *) arg0)[47] = arg2;
}

void func_800BA4C4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 176) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA4D0.s")

void func_800BA544(s32 *arg0, s32 arg1) {
    arg0[48] = arg1;
}

void func_800BA54C(s16 *arg0, s32 arg1) {
    arg0[84] = arg1;
}

void func_800BA554(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0xB4))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0xB8))) = arg2;
}

void func_800BA568(s16 *arg0, s16 arg1) {
    arg0[87] = arg1;
}

/* extern */

void func_800BA574(s32 arg0) {
    s32 func_800EE814(s32);
    func_800EE814(arg0 + 0xC);
}

void func_800BA594(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = arg2;
}

void func_800BA5A8(s16 *arg0, s32 arg1) {
    arg0[0] = arg1;
}

void func_800BA5B0(s16 *arg0, s32 arg1, s32 arg2) {
    arg0[66] = arg1;
    arg0[67] = arg2;
}

void func_800BA5BC(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x78))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x7C))) = arg2;
}

void func_800BA5D0(void *arg0, s16 arg1) {
    u32 var_v0;

    *(s16 *)((s8 *)arg0 + 0x14) = arg1;
    if (*(u32 *)((s8 *)arg0 + 0x90) > (var_v0 = *(u32 *)((s8 *)arg0 + 0x8C))) {
        do {
            *(s16 *)((s8 *)var_v0 + 8) = arg1;
            var_v0 += 0x3C;
        } while (var_v0 < *(u32 *)((s8 *)arg0 + 0x90));
    }
}

/* extern */

void func_800BA610(s32 arg0, s16 arg1, s16 arg2) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x34), 0, arg1, 0);
    func_800EFA6C((void *)(arg0 + 0x3A), 0, arg2, 0);
}

void func_800BA660(void *arg0, s32 arg1, s16 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x88))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x98))) = arg2;
}

void func_800BA670(s32 arg0, s32 arg1) {
    s8 func_800D738C(s32);
    if (arg1 != (*(u16 *)((s8 *)(arg0) + (2)))) {
        (*(u16 *)((s8 *)(arg0) + (2))) = (u16) arg1;
        (*(s8 *)((s8 *)(arg0) + (0xA))) = func_800D738C(arg1 & 0xFFFF);
    }
}

void func_800BA6B0(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    (*(s8 *)((s8 *)(arg0) + (5))) = 0;
    func_800EFA6C(arg0 + 0x28, arg1, arg2, arg3);
    func_800EFA6C(arg0 + 0x2E, arg4, arg5, arg6);
}

void func_800BA714(void *arg0, s16 arg1, s16 arg2) {
    (*(s8 *)((s8 *)(arg0) + (5))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg2;
}

void func_800BA730(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    (*(s8 *)((s8 *)(arg0) + (5))) = 2;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x2C))) = arg3;
    (*(s16 *)((s8 *)(arg0) + (0x2E))) = arg4;
}

/* extern */

void func_800BA75C(s32 arg0, f32 arg1[3]) {
    s32 func_800EE940(s32, f32[3]);
    func_800EE940(arg0 + 0x12, arg1);
}

void func_800BA77C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x4C), arg1, arg2, arg3);
}

void func_800BA7C4(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x9A))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0x9C))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA7FC(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x9E))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0xA0))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA834(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x40), arg1, arg2, arg3);
    func_800EFA6C((void *)(arg0 + 0x46), arg4, arg5, arg6);
}

void func_800BA894(void *arg0, f32 arg1, f32 arg2)
{
  f32 *new_var;
  f32 func_800DC178(f32, f32);
  f32 temp_f0;
  s8 *new_var3;
  f32 *new_var2;
  new_var2 = (f32 *) (((s8 *) arg0) + 0x58);
  temp_f0 = *((f32 *) (((s8 *) arg0) + 0x20));
  *((f32 *) ((new_var3 = (s8 *) arg0) + 0x54)) = arg1;
 *new_var2 = arg2; if (((*((f32 *) (((s8 *) arg0) + 0x20))) == 0.0f) || (arg2 < temp_f0)) {
    new_var = (f32 *) (((s8 *) arg0) + 0x54);
    *((f32 *) (((s8 *) arg0) + 0x20)) = func_800DC178(*new_var, *new_var2);
  }
}

void func_800BA8F8(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0xA2))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0xA4))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA930(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    func_800EFA6C((void *)(arg0 + 0xC4), arg1, arg2, arg3);
    func_800EFA6C((void *)(arg0 + 0xCA), arg4, arg5, arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BA994.s")

void func_800BAA60(u8 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 func_800EE940();
    *(s8 *)(arg0 + 4) = 2;
    *(s16 *)(arg0 + 0xC4) = arg2;
    *(s16 *)(arg0 + 0xC6) = arg3;
    func_800EE940((s32)(arg0 + 0xC8), arg1);
}

void func_800BAA9C(void *arg0, f32 arg1) {
    func_800BA7C4(arg0, arg1, arg1);
    func_800BA7FC(arg0, arg1, arg1);
}

void func_800BAAE4(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x6C, arg1, arg2, arg3);
}

void func_800BAB1C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x60, arg1, arg2, arg3);
}

void func_800BAB54(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 92) = arg1;
}

/* extern */

void func_800BAB60(s32 arg0) {
    s32 func_800F2EA0(s32);
    func_800F2EA0(arg0 + 0x80);
}

/* extern */

void func_800BAB80(s32 arg0) {
    s32 func_800F2EBC(s32);
    func_800F2EBC(arg0 + 0x80);
}

void func_800BABA0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (7))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = arg1;
}

void func_800BABB0(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E93440/func_800BABB8.s")

s32 func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4) {
    s32 func_800B53A4(s32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg3);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, arg1, arg2, arg4);
    func_800BA22C(sp24, arg3);
    return sp24;
}

/* extern */

void func_800BBD18(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 *arg4) {
    s32 func_800B4790(s32);
    if (arg0 != 0) {
        func_800BABB8(arg0, arg1, arg2, arg3, arg4);
        func_800B4790(arg0);
    }
}
