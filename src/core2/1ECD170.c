#include "core2/1ECD170.h"

void func_800F3880(s32 arg0)
{
    func_80098E64();
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F38A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3B3C.s")

void func_800F3B90(Actor *arg0, u32 arg1) {
    u32* func_800F3B3C(Actor*, u32, u32);
    func_800F3B3C(arg0, arg1, 0U);
}

void func_800F3BB0()
{
    func_8009C128();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3BD0.s")

/* extern */

void func_800F3E84(s32 arg0, void *arg1) {
    f32 baroll_get(s32);
    f32 func_8009BFCC();
    f32 yaw_get(s32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_8009BFCC();
    (*(f32 *)((s8 *)(arg1) + (4))) = yaw_get(arg0);
    (*(f32 *)((s8 *)(arg1) + (8))) = baroll_get(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F3ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F40EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4200.s")

s32 func_800F4244(s32 *arg0) {
    return arg0[95];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F43A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F44DC.s")

void func_800F4524(s32 *arg0, s32 arg1) {
    arg0[96] = arg1;
}

/* extern */

void func_800F452C(s32 arg0) {
    s32 func_80095C94(s32);
    s32 func_8009C0BC();
    s32 func_800A10A0(s32);
    s32 func_800A380C(s32);
    s32 func_800A4030(s32);
    s32 func_800A4B08(s32);
    func_8009C0BC();
    func_80095C94(arg0);
    func_800A10A0(arg0);
    func_800A4030(arg0);
    func_800A4B08(arg0);
    func_800A380C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F457C.s")

s32 func_800F45B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8009CCFC(s32, s32);
    s32 func_8009CD70(s32, s32);
    func_8009CCFC(arg0, arg1);
    func_8009CD70(arg0, arg2);
}

/* extern */

struct player_state_s;
void func_800F45E0(struct player_state_s *arg0, f32 *arg1) {
    void func_8009BF5C(struct player_state_s *, f32);
    void yaw_setIdeal(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    void baroll_applyIdeal(struct player_state_s *);
    void func_8009BFBC(void *);
    func_8009BF5C(arg0, arg1[0]);
    yaw_setIdeal(arg0, arg1[1]);
    baroll_setIdeal(arg0, arg1[2]);
    func_8009BFBC(arg0);
    yaw_applyIdeal(arg0);
    baroll_applyIdeal(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F4648.s")

/* extern */

void func_800F468C(void *arg0) {
    s32 func_800991B0(void *);
    s32 func_800EA09C();
    if (((*(s32 *)((s8 *)(arg0) + (0x17C))) != 0) && ((*(s32 *)((s8 *)(arg0) + (0x180))) == 0) && (func_800EA09C() == 2)) {
        func_800991B0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECD170/func_800F46D8.s")
