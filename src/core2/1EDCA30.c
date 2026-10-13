#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103140.s")

/* extern */

s32 func_801032B0(Actor *arg0, u16 arg1, u16 arg2) {
    s32 func_80103140(Actor *, u32, u16);
    void func_80104328(s32);
    s32 var_v1;
    s32 sp18;

    sp18 = ((s16 *)&arg0->pad8C)[0];
    ((s16 *)&arg0->pad8C)[0] = 0;
    var_v1 = func_80103140(arg0, arg1, arg2);
    if (((s16 *)&arg0->pad8C)[0] != 0) {
        func_80104328((s32) arg0);
    }
    ((s16 *)&arg0->pad8C)[0] = sp18;
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_8010347C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_8010381C.s")

void func_80103930(s32 arg0) 
{
}
/* extern */

void func_80103938(void *arg0) {
    s32 func_80104504();
    if ((*(s16 *)((s8 *)(arg0) + (0x8E))) != 0) {
        func_80104504();
    }
}

/* extern */

s32 func_80103964(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a1);
}

s32 func_801039A4(u8 *arg0) {
    s32 func_800D6B0C(s32);
    s32 temp_a1;

    temp_a1 = *(u16 *)(arg0 + 0x14);
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return func_800D6B0C(temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_801039E4.s")

void func_80103AA0(u8 *arg0)
{
    func_801039A4(arg0);
}

/* extern */

void func_80103AC0(void **arg0) {
    s32 func_800D6C34(u16);
    func_800D6C34((*(u16 *)((s8 *)(*arg0) + (0x14))));
}

/* extern */

s32 func_80103AE4(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103BF0.s")

void func_80103C94(Actor *arg0) {
    u32* func_80103BF0(Actor*, u32, u32);
    func_80103BF0(arg0, 0U, 0U);
}

void func_80103CB8(Actor *arg0, u32 arg1) {
    u32* func_80103BF0(Actor*, u32, u32);
    func_80103BF0(arg0, 0U, arg1);
}

s32 func_80103CDC(u8 *arg0, u8 *arg1) {
    int func_80103B24(u8 *, s32, u8 *);
    return func_80103B24(arg0, 0, arg1);
}

void func_80103D00(s32 arg0,s32 arg1)
{
    func_80103B24(arg0,0x1,arg1);
}

void func_80103D24(Actor *arg0) {
    u32* func_80103BF0(Actor*, u32, u32);
    func_80103BF0(arg0, 1, 0);
}

/* extern */

void func_80103D48(void **arg0) {
    s32 func_800D70F8(u16, s32);
    func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 1);
}

/* extern */

void func_80103D70(void **arg0) {
    s32 func_800D70F8(u16, s32);
    func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103D98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103DFC.s")

/* extern */

f32 func_80103EAC(Actor *arg0) {
    s32 func_80103328();
    func_80103328(arg0);
    return arg0->scale * (u32)(u16)arg0->pad60;
}

/* extern */

f32 func_80103EF4(Actor *arg0) {
    s32 func_80103328();
    func_80103328();
    return (f32) ((*(s16 *)((s8 *)(arg0) + (0x8A))) - (*(s16 *)((s8 *)(arg0) + (0x88)))) * arg0->scale;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103F38.s")

/* extern */

f32 func_80103FB8(Actor *arg0) {
    s32 func_80103328();
    func_80103328(arg0);
    return (f32) (u32) (u16) arg0->pad68 * arg0->scale;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80104004.s")

/* extern */

void func_801040A8(void **arg0) {
    s32 func_800AE080(s16);
    func_800AE080((*(s16 *)((s8 *)(*arg0) + (0x10))));
}
