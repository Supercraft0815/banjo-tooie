#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010F9C0.s")

s32 func_8010FAE4(s16 *arg0) {
    return arg0[11];
}

/* extern */

void func_8010FAEC(s32 arg0, void *arg1) {
    s32 func_800A9420(s32);
    s32 func_80114FA4(s32, s32, void *);
    if (((*(s32 *)((s8 *)(arg1) + (0xC))) != 0) && (func_800A9420((*(s32 *)((s8 *)(arg1) + (0x1C)))) != 0)) {
        func_80114FA4(arg0, (*(s32 *)((s8 *)(arg1) + (0xC))), arg1);
    }
}

/* extern */

void *func_8010FB34(s32 arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_8010F9C0(s32, s32);
    s32 func_80110424(void *, s32);
    void *func_80114BD4(void);
    void *func_80115118(s32);
    void *heap_alloc(s32);
    void *temp_v0;

    temp_v0 = heap_alloc(0x40);
    (*(s32 *)((s8 *)(temp_v0) + (0))) = arg0;
    (*(s8 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x19))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x20))) = 0;
    (*(void **)((s8 *)(temp_v0) + (0x10))) = func_80114BD4();
    if (func_800DA298(0x6B5) != 0) {
        (*(void **)((s8 *)(temp_v0) + (0xC))) = func_80115118(temp_v0);
    } else {
        (*(s32 *)((s8 *)(temp_v0) + (0xC))) = 0;
    }
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = arg1;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = func_80110424(temp_v0, arg1);
    (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x14))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = 0;
    func_8010F9C0(temp_v0, 1);
    return temp_v0;
}

/* extern */

void func_8010FBD4(void *arg0) {
    struct player_state_s;
    s32 func_8010F9C0(s32, s32);
    void func_801104F4(struct player_state_s *);
    void func_80114C7C(void *);
    void func_801150F8(void *);
    void heap_free(void *);
    struct player_state_s *temp_a0;
    void *temp_a0_2;

    func_8010F9C0(arg0, 1);
    temp_a0 = (*(struct player_state_s **)((s8 *)(arg0) + (4)));
    if (temp_a0 != 0) {
        func_801104F4(temp_a0);
    }
    temp_a0_2 = (*(void **)((s8 *)(arg0) + (0xC)));
    if (temp_a0_2 != 0) {
        func_801150F8(temp_a0_2);
    }
    func_80114C7C((*(void **)((s8 *)(arg0) + (0x10))));
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FC38.s")

void func_8010FD08(u8 *arg0) { s32 func_8010FC38(u8 *); arg0[0x19] = 1; func_8010FC38(arg0); arg0[0x19] = 0; }

void func_8010FD38(s32 arg0, f32 arg1) {
    void func_80114CB0(void *arg0, f32 arg1);
    func_80114CB0((*(u8 **)((s8 *)(arg0) + (0x10))), arg1);
}

void func_8010FD60(s32 arg0, f32 arg1) {
    void func_80114CC0(void *arg0, f32 arg1);
    func_80114CC0((*(u8 **)((s8 *)(arg0) + (0x10))), arg1);
}

void func_8010FD88(u8 *arg0)
{
    func_8010FD08(arg0);
}

void func_8010FDA8(u8 *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    (*(s8 *)((s8 *)(arg0) + (0x20))) = 0x28;
    func_800EE7F8(arg0 + 0x24, arg1);
    func_800EE7F8(arg0 + 0x30, arg2);
}

void func_8010FDEC(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x20))) = 0x29;
    (*(f32 *)((s8 *)(arg0) + (0x3C))) = arg1;
}

void func_8010FE00(void *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x18))) = (s8) (arg2 == 2);
}

/* extern */

void func_8010FE14(s32 *arg0) {
    s32 func_800CA628(s32);
    func_800CA628(*arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FE34.s")

s32 func_8010FF80(s32 *arg0) {
    return arg0[0];
}

/* extern */

void func_8010FF88(void *arg0) {
    void func_80114C9C();
    func_80114C9C((*(void **)((s8 *)(arg0) + (0x10))));
}

s32 func_8010FFA8(s16 *arg0) {
    return arg0[11];
}

/* extern */

void func_8010FFB0(s32 *arg0, f32 *arg1, f32 *arg2) {
    void func_800CA8B4(s32, f32 *, f32 *);
    func_800CA8B4(*arg0, arg1, arg2);
}

u32 func_8010FFD0(u8 *arg0) {
    return arg0[25];
}

/* extern */

s32 func_8010FFD8(s32 arg0) {
    u32 func_801150F0(u8 *);
    u8 *temp_a1;
    s32 var_v1;

    temp_a1 = (*(u8 **)((s8 *)(arg0) + (0xC)));
    if (temp_a1 != 0) {
        var_v1 = func_801150F0(temp_a1);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_80110014(s32 *arg0) {
    return arg0[1];
}

s32 func_8011001C(s32 *arg0) {
    return arg0[2];
}

void *func_80110024(s16 *arg0) {
    void *_ncpod_entrypoint_2(s16);
    s16 temp;
    void *result;
    temp = arg0[10];
    result = 0;
    if (temp != 0) {
        return _ncpod_entrypoint_2(temp);
    }
    return result;
}

s32 func_80110060(s32 *arg0) {
    return arg0[4];
}

/* extern */

void *func_80110068(void *arg0, s32 arg1) {
    void *defrag(void *);
    s32 *func_80110FCC(s32 *, s32);
    void *func_80114CD4(void *);
    s32 *func_80115324(s32 *, s32);
    struct {
        s32 owner;
        s32 *field4;
        s32 field8;
        s32 *fieldC;
        void *field10;
    } *temp_v0;
    s32 *temp_a0;
    void *temp_a0_2;

    temp_v0 = defrag(arg0);
    temp_v0->owner = arg1;
    if (temp_v0->field4 != 0) {
        temp_v0->field4 = func_80110FCC(temp_v0->field4, (s32)temp_v0);
    }
    temp_a0 = temp_v0->fieldC;
    if (temp_a0 != 0) {
        temp_v0->fieldC = func_80115324(temp_a0, (s32)temp_v0);
    }
    temp_a0_2 = temp_v0->field10;
    if (temp_a0_2 != 0) {
        temp_v0->field10 = func_80114CD4(temp_a0_2);
    }
    return temp_v0;
}

/* extern */

void func_801100E4(s32 *arg0, s32 *arg1) { void func_800CA314(s32, s32); void func_80110770(s32, f32 *); void func_80110790(s32, f32 *); void func_80111018(s32, s32); f32 sp2C[3]; f32 sp20[3]; if (arg0 != arg1) { func_800CA314(arg0[0], arg1[0]); if (arg0[1] != 0) { func_8010FFB0(arg1, sp2C, sp20); func_80110770(arg0[1], sp2C); func_80110790(arg0[1], sp20); func_80111018(arg0[1], arg1[1]); } } }

/* extern */

void func_80110164(u8 *arg0) {
    void func_800CA6C0(void *arg0, f32 arg1, f32 arg2);
    void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2);
    s32 func_8011490C(s32, u8 *, s32);
    f32 sp1C;
    f32 sp18;

    func_8011490C((*(s32 *)((s8 *)(arg0) + (0x10))), arg0, (*(s32 *)((s8 *)(arg0) + (0x1C))));
    func_80114C9C((*(u8 **)((s8 *)(arg0) + (0x10))), &sp1C, &sp18);
    func_800CA6C0((*(u8 **)((s8 *)(arg0) + (0))), sp1C, sp18);
}
