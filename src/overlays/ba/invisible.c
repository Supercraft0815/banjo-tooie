#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/func_80800000_bainvisible.s")

void func_808001BC_bainvisible(void *arg0) {
    f32 func_80013728(f32);
    void func_8009BC08(void *, f32 *);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    u8 *sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];
    f32 sp40;
    f32 turn;
    s32 i;
    u8 *p;

    sp5C = *(u8 **)((u8 *)arg0 + 0xA8) + 0x1C;
    sp50 = 1.0f / func_800D8FF8();
    func_8009BC08(arg0, sp44);
    sp58 = func_800EFB8C(sp44, *(f32 **)((u8 *)arg0 + 0xA8)) * sp50;
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0xA8), sp44);
    if ((*(f32 **)((u8 *)arg0 + 0xA8))[5] < sp58) {
        sp58 = 1.0f;
    } else {
        sp58 = sp58 / (*(f32 **)((u8 *)arg0 + 0xA8))[5];
    }
    sp40 = yaw_get(arg0);
    sp54 = mlAbsF(func_80013728(sp40 - (*(f32 **)((u8 *)arg0 + 0xA8))[3]));
    (*(f32 **)((u8 *)arg0 + 0xA8))[3] = sp40;
    turn = sp54 * sp50;
    if (*(f32 *)(*(u8 **)((u8 *)arg0 + 0xA8) + 0x18) < turn) {
        sp54 = 1.0f;
    } else {
        sp54 = turn / *(f32 *)(*(u8 **)((u8 *)arg0 + 0xA8) + 0x18);
    }
    if (sp54 < sp58) {
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xA8) + 0x10) = sp58;
    } else {
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xA8) + 0x10) = sp54;
    }
    if (sp54 < sp58) {
        turn = sp58;
    } else {
        turn = sp54;
    }
    if (sp5C[0] == 3) {
        *(f32 *)(sp5C + 8) = 0.255f * turn + 0.074999996f;
    }
    if (sp5C[0x30] == 3) {
        *(f32 *)(sp5C + 0x38) = 0.19999999f * turn + 0.39999998f;
    }
    for (i = 0; i < 2; i++) {
        p = sp5C + i * 0x30;
        if (p[0x1C] != 0) {
            if (*(f32 *)(p + 8) < *(f32 *)(p + 0x10)) {
                *(f32 *)(p + 8) = *(f32 *)(p + 0x10);
            }
            if (*(f32 *)(p + 0x14) < *(f32 *)(p + 8)) {
                *(f32 *)(p + 8) = *(f32 *)(p + 0x14);
            }
        }
    }
}

/* extern */

int func_808003AC_bainvisible(void *arg0) {
    f32 func_800F214C(f32, f32);
    f32 temp_f0;
    f32 temp_f12;
    f32 step;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    temp_f12 = (*(f32 *)((s8 *)(arg0) + (8))) - temp_f0;
    step = temp_f12 * 0.25f;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = temp_f0 + step;
    return func_800F214C(temp_f12, 0.01f) == 0.0f;
}

s32 bainvisible_entrypoint_0() 
{
    return 0x7C;
}

void bainvisible_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA8)))) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA8)))) + (0x18))) = arg2;
}

f32 bainvisible_entrypoint_2(void *arg0, s32 arg1) {
    return (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0xA8))) + (arg1 * 0x30))) + (0x28)));
}

void bainvisible_entrypoint_3(s32 arg0) {
    s32 bastatetimer_clear(void *, s32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 1);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 1);
    bastatetimer_clear((void *)arg0, 9);
}

void bainvisible_entrypoint_4(s32 arg0) {
    s32 bastatetimer_clear(void *, s32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 0);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 0);
    bastatetimer_clear((void *)arg0, 9);
}

void bainvisible_entrypoint_5(s32 arg0, f32 arg1) {
    void bastatetimer_set(void *, s32, f32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 2);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 2);
    bastatetimer_set((void *)arg0, 9, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/bainvisible_entrypoint_6.s")

void bainvisible_entrypoint_7(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s8 var_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    var_v0 = arg4 != 0.0f ? 1 : 0;
    if (arg1 & 1) {
        temp_v1 = (*(u8 **)((s8 *)(arg0) + (0xA8)));
        (*(s8 *)((s8 *)(temp_v1) + (0x38))) = var_v0;
        (*(f32 *)((s8 *)(temp_v1) + (0x34))) = arg4;
        (*(f32 *)((s8 *)(temp_v1) + (0x2C))) = arg2;
        temp_v1 += 0x1C;
        (*(f32 *)((s8 *)(temp_v1) + 0x14)) = arg3;
    }
    if (arg1 & 2) {
        temp_v1_2 = (*(u8 **)((s8 *)(arg0) + (0xA8)));
        (*(s8 *)((s8 *)(temp_v1_2) + (0x68))) = var_v0;
        (*(f32 *)((s8 *)(temp_v1_2) + (0x64))) = arg4;
        (*(f32 *)((s8 *)(temp_v1_2) + (0x5C))) = arg2;
        temp_v1_2 += 0x4C;
        (*(f32 *)((s8 *)(temp_v1_2) + 0x14)) = arg3;
    }
}

/* extern */

void func_808007CC_bainvisible(s32 arg0, void *arg1, f32 arg2, f32 arg3) {
    void func_80800000_bainvisible(s32, void *, s32);
    func_80800000_bainvisible(arg0, arg1, 4);
    (*(f32 *)((s8 *)(arg1) + (0x20))) = arg2;
    (*(f32 *)((s8 *)(arg1) + (0x2C))) = arg3;
}

void bainvisible_entrypoint_8(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    if (arg1 & 1) {
        func_808007CC_bainvisible((s32) arg0, (*(s32 *)((s8 *)(arg0) + (0xA8))) + 0x1C, arg2, arg3);
    }
    if (arg1 & 2) {
        func_808007CC_bainvisible((s32) arg0, (*(s32 *)((s8 *)(arg0) + (0xA8))) + 0x4C, arg2, arg3);
    }
}

void bainvisible_entrypoint_9(void **arg0, s32 arg1, void *arg2) {
    void func_8009BC08(void *, f32 *);
    f32 func_800EFC7C(void *, void *);
    f32 position[3];
    f32 distances[8];
    s32 i;
    s32 j;
    void *player;
    f32 distance;

    for (i = 0; i < arg1; i++) {
        func_8009BC08(arg0[i], position);
        distance = func_800EFC7C(position, arg2);
        player = arg0[i];
        j = i;
        while (j > 0 && distances[j - 1] < distance) {
            arg0[j] = arg0[j - 1];
            distances[j] = distances[j - 1];
            j--;
        }
        arg0[j] = player;
        distances[j] = distance;
    }
}
