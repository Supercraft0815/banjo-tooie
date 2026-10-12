#include "core2/1EE9AB0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_801101C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110424.s")

void func_801104F4(PlayerState *arg0) {
    s32 func_801106A8(PlayerState *, s32);
    s32 func_80113410();
    void heap_free(void* mem);
    func_801106A8(arg0, 0);
    func_80113410(arg0);
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110588.s")

s32 func_801106A0(s32 *arg0) {
    return arg0[27];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_801106A8.s")

void func_80110720(s8 *arg0, s32 arg1) {
    arg0[112] = arg1;
}

void func_80110728(s8 *arg0, s32 arg1) {
    arg0[113] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110730.s")

/* extern */

void func_80110770(s32 arg0) {
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x74);
}

/* extern */

void func_80110790(s32 arg0) {
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x80);
}

/* extern */

void func_801107B0(void *arg0) {
    s32 func_800F5A00(s32);
    func_800F5A00((*(s32 *)((s8 *)(arg0) + (0x68))));
}

/* extern */

void func_801107D0(void *arg0) {
    s32 func_800F5B38(s32);
    func_800F5B38((*(s32 *)((s8 *)(arg0) + (0x68))));
}

void func_801107F0(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x74);
}

void func_80110818(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x80);
}

s32 func_80110840(s32 *arg0) {
    return arg0[26];
}

void func_80110848(f32 *arg0, f32 *arg1, f32 *arg2) { void func_800EE7F8(); func_800EE7F8(arg1, arg0 + 29); func_800EE7F8(arg2, arg0 + 32); }

u32 func_80110888(u8 *arg0) {
    return arg0[113];
}

u32 func_80110890(u8 *arg0) {
    return arg0[114];
}

s32 func_80110898(s32 *arg0) {
    return arg0[25];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_801108A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110970.s")

void func_80110A24(PlayerState *player, f32 position[3], f32 rotation[3]) {
    void func_80112524(PlayerState *, f32 *);
    void func_800A516C(f32 *, f32 *, f32 *);
    f32 pos[3];
    func_80112524(player, pos);
    func_800A516C(position, pos, rotation);
    position[2] = 0.0f;
}

/* extern */

void func_80110A68(s32 arg0, s32 arg1, s32 arg2) {
    void func_800A516C(f32 *, f32 *, f32 *);
    func_800A516C((f32 *)arg1, (f32 *)arg2, (f32 *)(arg0 + 0x74));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110A9C.s")

/* extern */

void func_80110B68(void *arg0, s32 arg1) {
    s32 func_80093700(s32, s32);
    s32 func_800F53D0(s32);
    s32 func_800F6BE4(s32);
    s32 func_800F7B9C(s32, s32);
    if (arg1 != 0) {
        if (func_800F6BE4((*(s32 *)((s8 *)(arg0) + (0x68)))) != 0) {
            func_800F7B9C((*(s32 *)((s8 *)(arg0) + (0x68))), 0x6C);
            func_80093700(func_800F53D0((*(s32 *)((s8 *)(arg0) + (0x68)))), 1);
        }
    } else if (func_800F6BE4((*(s32 *)((s8 *)(arg0) + (0x68)))) != 0) {
        func_800F7B9C((*(s32 *)((s8 *)(arg0) + (0x68))), 0x6B);
        func_80093700(func_800F53D0((*(s32 *)((s8 *)(arg0) + (0x68)))), 0);
    }
}

/* extern */

void func_80110BF0(PlayerState *self) {
    s32 _ncba1p_entrypoint_5(PlayerState *, s32);
    s32 _ncba1p_entrypoint_6(PlayerState *, u8 *);
    s32 _ncba1p_entrypoint_7(PlayerState *, struct ba_flag_s **);
    _ncba1p_entrypoint_5(self, 1);
    _ncba1p_entrypoint_6(self, &self->pad48[0x2C]);
    _ncba1p_entrypoint_7(self, &self->flag);
}

/* extern */

void func_80110C2C(PlayerState *self) {
    s32 _ncba1p_entrypoint_10();
    s32 _ncba1p_entrypoint_13(PlayerState *, u8 *, struct ba_flag_s **);
    s32 _ncba1p_entrypoint_5(PlayerState *, s32);
    s32 temp_v0;

    temp_v0 = _ncba1p_entrypoint_10();
    if ((temp_v0 != 0) && (temp_v0 != 3)) {
        if (self->pad48[0x2A] != 0) {
            _ncba1p_entrypoint_13(self, &self->pad48[0x2C], &self->flag);
        }
        _ncba1p_entrypoint_5(self, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110C88.s")

/* extern */

void func_80110CC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 func_8011539C();
    s32 func_80115D08(s32, s32, s32, s32, f32);
    func_8011539C();
    func_80115D08(arg0, arg1, arg2, arg3, arg4);
}

void func_80110D08()
{
    func_80115864();
}

void func_80110D28(u8 *arg0, s32 arg1) {
    void func_80116050(void *arg0, f32 arg1);
    func_80116050(arg0, (f32) arg1);
}

void func_80110D58(u8 *arg0, f32 arg1) {
    void func_801125D8(void *arg0, f32 arg1);
    func_801125D8(arg0, arg1);
}

void func_80110D80()
{
    func_8011396C();
}

void func_80110DA0()
{
    func_80115460();
}

void func_80110DC0()
{
    func_8011546C();
}

void func_80110DE0()
{
    func_80115478();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110FCC.s")

void func_80111018(s32 arg0, s32 arg1) {
    s32 _ncba1p_entrypoint_1(s32);
    s32 func_8011337C(s32);
    s32 func_80113410();
    s32 rare_memcpy(s32, s32, s32);
    extern s16 D_80137372;
    func_80113410();
    rare_memcpy(arg0 + 0x98, arg1 + 0x98, D_80137372 - 0x98);
    func_8011337C(arg0);
    _ncba1p_entrypoint_1(arg0);
}

void func_8011106C(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x8C);
}

/* extern */

void func_80111094(s32 arg0, s32 arg1) {
    s32 func_800EE780(s32, s32, s32, s32);
    func_800EE780(arg1, arg0 + 0x74, arg0 + 0x8C, arg0);
}

void func_801110C4(s32 arg0, u8 *arg1) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    func_800EFB24(arg0 + 0x8C, arg1, arg0 + 0x74);
}

/* extern */

s32 func_801110EC(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _ncbatarget_entrypoint_4(u8 *, s32);
    s32 _ncbatarget_entrypoint_5();
    switch (*(s32 *)(arg0 + 0x6C)) {
    case 0x14:
        _ncbatarget_entrypoint_5(arg0, arg1);
        _ncbatarget_entrypoint_4(arg0, arg2);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_8011113C(void) {
    return 0;
}

s32 func_80111144(void) {
    return 0;
}

s32 func_8011114C(void) {
    return 0;
}

/* extern */

s32 func_80111154(s32 arg0, f32 arg1) {
    f32 func_800136E4(f32);
    s32 func_80112D90(s32, f32, s32, s32, s32);
    func_80112D90(arg0, func_800136E4(arg1), 0x42960000, 2, 2);
    return 1;
}

/* extern */

s32 func_80111198(s32 arg0, f32 arg1) {
    f32 func_800136E4(f32);
    s32 func_80115DEC(s32, f32, s32);
    func_80115DEC(arg0, func_800136E4(arg1), 0x42960000);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_801111D0.s")

/* extern */

f32 func_801112B0(void *arg0) {
    s32 func_80092BC4(s32);
    f32 func_80092BD0(s32);
    s32 func_800F53D0(s32);
    f32 func_800F5F24(s32);
    s32 sp1C;
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53D0((*(s32 *)((s8 *)(arg0) + (0x68))));
    sp1C = temp_v0;
    if (func_80092BC4(temp_v0) != 0) {
        var_f2 = func_80092BD0(sp1C) - 180.0f;
    } else {
        var_f2 = func_800F5F24((*(s32 *)((s8 *)(arg0) + (0x68))));
    }
    return var_f2;
}

/* extern */

void func_80111310(s32 *arg0) {
    s32 func_800A509C(s32);
    s32 func_800F53D0(s32);
    func_800A509C(func_800F53D0(func_80110840(arg0)));
}

s32 func_80111340() 
{
    return 0x8C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111348.s")

/* extern */

void func_801113B8(void *arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x10);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x38);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111410.s")

void func_80111590(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (4))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (8))) = arg3;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0xC))) = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_801115C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111A38.s")

void func_80111A98(u8 *arg0) {
    func_801107F0(arg0, (*(s32 *)((s8 *)(arg0) + (0x34))) + 0x5C);
}

/* extern */

void func_80111ABC(void *arg0) {
    void func_800EE7F8();
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x68);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111AE0.s")

/* extern */

void func_80111B8C(s32 *arg0, f32 arg1, f32 arg2) {
    f32 func_800A3048(s32);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x30))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x34))) = (f32) (arg2 * var_f2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111DB0.s")

/* extern */

void func_80111E88(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 func_800D8FF8();
    f32 var_f20;
    f32 temp_f0;
    f32 targetVelocity;
    f32 acceleration;

    temp_f0 = func_800D8FF8();
    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    targetVelocity = (arg0 - *arg1) * arg3;
    acceleration = (targetVelocity - *arg2) * arg4;
    *arg2 += acceleration * temp_f0;
    var_f20 = *arg1 + (*arg2 * temp_f0);
    if (arg0 < *arg1) {
        if (var_f20 < arg0) {
            var_f20 = arg0;
            *arg2 = 0.0f;
        }
    } else if (arg0 < var_f20) {
        var_f20 = arg0;
        *arg2 = 0.0f;
    }
    *arg1 = var_f20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111FD4.s")

/* extern */

void func_801120CC(s32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800A3048(s32);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x7C))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x80))) = (f32) (arg2 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x84))) = (f32) (arg3 * var_f2);
}
