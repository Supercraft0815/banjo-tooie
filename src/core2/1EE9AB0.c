#include "core2/1EE9AB0.h"

void func_801101C0(void) {
    extern s16 (*D_80124950)(void);
    extern s16 D_80137340[25];
    extern s16 D_80137372;
    s16 (**var_s1)(void);
    s16 *var_s0;
    s16 temp_v1;
    s32 var_a0;
    s32 var_v0;
    u32 end;

    D_80137372 = 0x98;
    var_s0 = D_80137340; var_s1 = &D_80124950; end = (u32)&D_80137340[25];
    do {
        *var_s0 = (*var_s1)();
        temp_v1 = *var_s0;
        var_a0 = temp_v1 % 4;
        if (var_a0 != 0) {
            var_v0 = 4 - var_a0;
        } else {
            var_v0 = 0;
        }
        var_s0++;
        var_s1++;
        D_80137372 = D_80137372 + temp_v1 + var_v0;
    } while ((u32)var_s0 != end);
}

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

void func_80110528(PlayerState *arg0) { s32 func_801138A0(void *); void func_801138F4(PlayerState *); void func_80112524(PlayerState *, f32 *); void func_80110A68(s32, s32, s32); void func_80110790(s32, f32 *); f32 sp2C[3]; f32 sp20[3]; if (func_801138A0(arg0) != 0) { func_801138F4(arg0); } func_80112524(arg0, sp2C); func_80110A68((s32) arg0, (s32) sp20, (s32) sp2C); func_80110790((s32) arg0, sp20); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80110588.s")

s32 func_801106A0(s32 *arg0) {
    return arg0[27];
}

s32 func_801106A8(PlayerState *arg0, s32 arg1) {
    struct StateCallbacks {
        void (*enter)(PlayerState *, s32);
        void (*unk4)();
        void (*exit)();
        void (*unkC)();
    };
    extern s16 D_801247A0[];
    void (*exit)();
    void (*enter)(PlayerState *, s32);
    s32 oldState;

    oldState = ((s32 *)arg0)[27];
    if (arg1 != oldState) {
        exit = ((struct StateCallbacks *)D_801247A0)[oldState].exit;
        if (exit != NULL) {
            exit();
        }
        enter = ((struct StateCallbacks *)D_801247A0)[arg1].enter;
        if (enter != NULL) {
            enter(arg0, arg1);
        }
        ((s32 *)arg0)[27] = arg1;
    }
}

void func_80110720(s8 *arg0, s32 arg1) {
    arg0[112] = arg1;
}

void func_80110728(s8 *arg0, s32 arg1) {
    arg0[113] = arg1;
}

void func_80110730(s32 arg0, s32 arg1) {
    s32 func_8011337C(s32);
    s32 func_80113410();
    (*(s8 *)((s8 *)(arg0) + (0x72))) = arg1;
    func_80113410((void *) arg0);
    if (arg1 == 0) {
        func_8011337C(arg0);
    }
}

/* extern */

void func_80110770(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8((u8 *)arg0 + 0x74, arg1);
}

/* extern */

void func_80110790(s32 arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x80, arg1);
}

/* extern */

void func_801107B0(void *arg0, f32 *arg1) {
    void func_800F5A00(s32, f32 *);
    func_800F5A00((*(s32 *)((s8 *)(arg0) + (0x68))), arg1);
}

/* extern */

void func_801107D0(void *arg0, f32 *arg1) {
    void func_800F5B38(s32, f32 *);
    func_800F5B38((*(s32 *)((s8 *)(arg0) + (0x68))), arg1);
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

void func_801108A0(void *arg0) {
    s32 _ncba1p_entrypoint_1(s32);
    void func_8010FFB0(s32 *, f32 *, f32 *);
    void func_80111348(s32 *);
    void func_80112398(u8 *);
    s32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_8010FFB0(*(s32 **)((u8 *)arg0 + 0x64), sp30, sp24);
    func_80110770(arg0, sp30);
    func_80110790((s32)arg0, sp24);
    func_80111348(arg0);
    sp3C = func_801106A0(arg0);
    func_801106A8(arg0, 0);
    func_801106A8(arg0, sp3C);
    _ncba1p_entrypoint_1((s32)arg0);
    func_80112398(arg0);
}

void func_80110928(void *arg0) {
    void func_800F5B38(s32, f32 *);
    f32 func_800136E4(f32);
    void func_80110970(void *, f32);
    f32 rotation[3];

    func_800F5B38(*(s32 *)((s8 *)arg0 + 0x68), rotation);
    func_80110970(arg0, func_800136E4(rotation[1] + 180.0f));
}

void func_80110970(void *arg0, f32 arg1) {
    void func_800F5A00(s32, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_8010FE14(s32 *, f32 *, f32 *);
    s32 func_8010FF80(s32 *);
    void func_800CA3A4(s32, f32);
    f32 position[3];
    f32 rotation[3];
    s32 state;

    state = *(s32 *)((u8 *)arg0 + 0x6C);
    if (state == 8 || state == 0x11 || state == 0x13 || state == 2) {
        func_800F5A00(*(s32 *)((u8 *)arg0 + 0x68), position);
        position[1] += 100.0f;
        func_800EFA4C(rotation, 0.0f, arg1, 0.0f);
        func_8010FE14(*(s32 **)((u8 *)arg0 + 0x64), position, rotation);
        func_800CA3A4(func_8010FF80(*(s32 **)((u8 *)arg0 + 0x64)), 300.0f);
        func_801108A0(arg0);
    }
}

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

s32 func_80110A9C(PlayerState *arg0, f32 arg1[3], f32 *arg2) {
    void func_800EFB24(void *, void *, void *);
    s32 func_800F6438(u32);
    int func_800F6640(s32);
    s32 func_800F6690(s32);
    s32 func_800F6BE4(s32);
    f32 func_80112550(PlayerState *, f32[3]);
    f32 sqrtf(f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    if (func_800F6BE4(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6438(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6640(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6690(*(s32 *)((u8 *)arg0 + 0x68)) == 0) {
        return 0;
    }
    sp24 = func_80112550(arg0, sp34);
    func_800EFB24(sp28, arg1, sp34);
    *arg2 = sqrtf((sp28[0] * sp28[0] + sp28[1] * sp28[1]) + sp28[2] * sp28[2]) - sp24;
    return 1;
}

/* extern */

void func_80110B68(void *arg0, s32 arg1) {
    s32 func_80093700(s32, s32);
    PlayerState *func_800F53D0(s32);
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

void func_80110C88(s32 arg0) { void func_80110CC0(s32, s32, s32, s32, f32); func_80110CC0(arg0, 0x44098000, 0x441B0000, 0x43160000, 10.0f); }

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

s32 func_80110EFC(u8 *arg0) {
    s32 func_80110E00();
    extern s16 D_801247A0[];
    s32 index;
    index = *(s32 *)((s8 *)arg0 + 0x6C);
    if (D_801247A0[index * 8 + 6] != 0) {
        return func_80110E00();
    } else {
        return 0;
    }
}

void func_80110F44(void *arg0) {
    void func_800A4EFC(void *, f32);
    f32 func_800EEFFC(void *);
    void func_800EFB24(void *, void *, void *);
    PlayerState *func_800F53D0(s32);
    void func_80112524(PlayerState *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_80112524(arg0, sp44);
    func_801107F0(arg0, sp38);
    func_800EFB24(sp2C, sp38, sp44);
    func_800A4EFC(func_800F53D0(func_80110840(arg0)), func_800EEFFC(sp2C));
    if (*(s32 *)((s8 *)arg0 + 0x6C) == 0x11) {
        _ncbastring_entrypoint_4(arg0);
    }
}

/* extern */

s32 *func_80110FCC(s32 *arg0, s32 arg1) {
    s32 *original;

    original = arg0;
    arg0 = defrag(arg0);
    if (original != arg0) {
        func_80110280(arg0);
    }
    arg0[25] = arg1;
    return arg0;
}

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
    PlayerState *func_800F53D0(s32);
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
    PlayerState *func_800F53D0(s32);
    func_800A509C(func_800F53D0(func_80110840(arg0)));
}

s32 func_80111340() 
{
    return 0x8C;
}

void func_80111348(s32 *arg0) {
    void func_801113B8(void *);
    void func_80111590(void *, f32, f32, f32, f32);
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    func_801113B8(arg0);
    func_80111590(arg0, 10.0f, 10.0f, 120.0f, 120.0f);
    func_80111B8C(arg0, 1.4f, 14.0f);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
}

/* extern */

void func_801113B8(void *arg0) {
    void func_800EFD24(f32 *);
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

/* extern */

s32 func_801115C8(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 func_800EEAA4(f32 *, f32 *);
    f32 sp1C;
    f32 temp_f0;

    sp1C = func_800EEAA4(arg0, arg2);
    temp_f0 = func_800EEAA4(arg0, arg3);
    if (((sp1C < arg1 && arg1 < temp_f0) || (arg1 < sp1C && temp_f0 < arg1)) && temp_f0 != sp1C) {
        *arg4 = (arg1 - sp1C) / (temp_f0 - sp1C);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE9AB0/func_80111680.s")

/* extern */

void func_80111A38(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    void func_80111680(f32 *, f32 *, f32 *, void *, f32, f32, void *);
    f32 func_80112550(PlayerState *, f32[3]);
    f32 sp2C[3];
    u8 *temp_v0;
    func_80112550(arg0, sp2C);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111680(arg1, arg2, sp2C, temp_v0 + 0x24, (*(f32 *)((s8 *)(temp_v0) + (0x30))), (*(f32 *)((s8 *)(temp_v0) + (0x34))), temp_v0 + 0x38);
}

void func_80111A98(u8 *arg0) {
    func_801107F0(arg0, (*(s32 *)((s8 *)(arg0) + (0x34))) + 0x5C);
}

/* extern */

void func_80111ABC(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8((*(f32 **)((s8 *)arg0 + 0x34)) + 26, arg1);
}

void func_80111AE0(void *arg0, f32 *arg1) {
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80113640(s32, f32 *, f32 *);
    f32 sp24[3];
    s32 sp20;

    sp20 = func_80110898(arg0);
    func_801107F0(arg0, sp24);
    if (func_8010FFD0(sp20) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp24, arg1);
        func_80110770(arg0, arg1);
        return;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp24);
    func_80110770(arg0, sp24);
}

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

void func_80111C04(void *arg0) {
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    f32 dot;

    func_801107F0(arg0, (*(f32 **)((s8 *)arg0 + 0x34)) + 20);
    func_800EFB24(sp28, (*(f32 **)((s8 *)arg0 + 0x34)) + 26,
                 (*(f32 **)((s8 *)arg0 + 0x34)) + 23);
    func_800EFB24(sp34, (*(f32 **)((s8 *)arg0 + 0x34)) + 20,
                 (*(f32 **)((s8 *)arg0 + 0x34)) + 23);
    func_800EF2A0(sp28);
    func_800EF2A0(sp34);
    dot = func_800EEAA4(sp28, sp34);
    if (dot < 0.0f || (*(f32 **)((s8 *)arg0 + 0x34))[29] < 0.0f) {
        func_80110770(arg0, (*(f32 **)((s8 *)arg0 + 0x34)) + 23);
    }
    (*(f32 **)((s8 *)arg0 + 0x34))[29] = dot;
}

/* extern */

s32 func_80111CC8(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(s32, f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;

    sp24 = func_80110898(arg0);
    func_801107F0(arg0, sp34);
    if (func_8010FFD0(sp24) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp34, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp34);
    func_8011106C(arg0, sp28);
    func_800EF04C(sp34, sp28);
    func_80110770(arg0, sp34);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

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

/* extern */

void func_80111F70(u8 *arg0, u8 *arg1, u8 *arg2, void *arg3, f32 *arg4) {
    void func_80111DB0(u8 *, u8 *, u8 *, void *);
    f32 sp24;
    f32 temp_f12;
    u8 *temp_v0;

    sp24 = (*(f32 *)((s8 *)(arg2) + (4)));
    func_80111DB0(arg0, arg1, arg2, arg3);
    (*(f32 *)((s8 *)(arg2) + (4))) = sp24;
    temp_f12 = (*(f32 *)((s8 *)(arg1) + (4)));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111E88(temp_f12, arg2 + 4, arg4, (*(f32 *)((s8 *)(temp_v0) + (0x30))), (*(f32 *)((s8 *)(temp_v0) + (0x34))));
}

/* extern */

s32 func_80111FD4(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(s32, f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    u8 *temp_v0;

    sp2C = func_80110898(arg0);
    func_801107F0(arg0, sp3C);
    if (func_8010FFD0(sp2C) != 0) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x34)))) + (0x78))) = 0.0f;
        func_80113640(arg0, sp3C, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98((u8 *) arg0);
    func_80111ABC(arg0, arg1);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111F70(arg0, arg1, sp3C, temp_v0 + 0x78, temp_v0 + 0x88);
    func_8011106C(arg0, sp30);
    func_800EF04C(sp3C, sp30);
    func_80110770(arg0, sp3C);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

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
