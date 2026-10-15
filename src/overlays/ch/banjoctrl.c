#include "common.h"

OSThread *chbanjoctrl_entrypoint_0(void)
{
    extern u8 D_80801270_chbanjoctrl[];

    return (OSThread *) D_80801270_chbanjoctrl;
}

/* extern */

void func_8080000C_chbanjoctrl(Actor *arg0) {
    s32 func_800EA05C();
    void func_80101FDC(Actor *, u32);
    void func_80800098_chbanjoctrl(Actor *);
    s32 state;

    state = (s32) arg0->rotation[1];
    if (state == 3) {
        arg0->position[0] = 0.0f;
        arg0->position[2] = 0.0f;
        if (func_800EA05C() == 0x12B) {
            arg0->unk64_20 = 0;
        } else {
            arg0->unk64_20 = 1;
        }
    }
    func_80101FDC(arg0, state);
    func_80800098_chbanjoctrl(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800098_chbanjoctrl.s")

void func_808011F4_chbanjoctrl(void);
void func_8080012C_chbanjoctrl(Actor *arg0) { if ((u32) arg0->unk70_10 == 0xB) { func_808011F4_chbanjoctrl(); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800160_chbanjoctrl.s")

s32 func_808007D8_chbanjoctrl(u8 *);
void func_8080025C_chbanjoctrl(u8 *arg0) { if (func_808007D8_chbanjoctrl(arg0) && (*(f32 *)(arg0 + 0x1C) < *(f32 *)(arg0 + 8))) func_800904C8(0x91); }

/* extern */

s32 func_808002A4_chbanjoctrl(f32 arg0) {
    f32 func_800F2094(f32, f32);
    s32 i;

    for (i = 0; i < 0x168; i += 0x5A) {
        if (func_800F2094((f32) i, arg0) < 6.0f) {
            return 0;
        }
    }
    for (i = 0x2D; i != 0x195; i += 0x5A) {
        if (func_800F2094((f32) i, arg0) < 7.0f) {
            return 0;
        }
    }
    return 1;
}

/* extern */

f32 func_80800360_chbanjoctrl(f32 arg0) {
    s32 func_808002A4_chbanjoctrl(f32);
    f32 temp_f22;
    f32 temp_f22_2;
    f32 var_f20;
    s32 done;

    var_f20 = 1.0f;
    done = 0;
    do {
        temp_f22_2 = arg0 + var_f20;
        if (func_808002A4_chbanjoctrl(temp_f22_2) != 0) {
            return temp_f22_2;
        }
        temp_f22 = arg0 - var_f20;
        if (func_808002A4_chbanjoctrl(temp_f22) != 0) {
            return temp_f22;
        }
        var_f20 += 2.0f;
    } while (!done);
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808003F8_chbanjoctrl.s")

/* extern */

s32 chbanjoctrl_entrypoint_1(s32 arg0) {
    s32 _chhotwaterpoolbits_entrypoint_5(s32, s32);
    s32 func_800F54E4();
    s32 func_800F7B9C(s32, s32);
    if (func_800F7B9C(func_800F54E4(), 0x51) == 2) {
        _chhotwaterpoolbits_entrypoint_5(arg0, 0x3F800000);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800544_chbanjoctrl.s")

/* extern */

s32 chbanjoctrl_entrypoint_2(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F798C(s32, s32, s32);
    s32 func_80800544_chbanjoctrl(s32);
    if (func_800F798C(func_800F54E4(), 0xD, 3) != 0) {
        func_80800544_chbanjoctrl(arg0);
        return 1;
    }
    return 0;
}

void func_80800638_chbanjoctrl(void *arg0, s32 arg1) {
    if ((arg1 == 2) && ((*(s32 (**)())((s8 *)(arg0) + (0x24)))() != 0)) {
        (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x2C)));
    }
    (*(s8 *)((s8 *)(arg0) + (0x30))) = (s8) arg1;
}

void func_80800684_chbanjoctrl(void *arg0, f32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0x24))) = arg3;
    (*(s32 *)((s8 *)(arg0) + (0x50))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (0x30))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
}

/* extern */

int func_808006A8_chbanjoctrl(void *arg0) {
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_800F6DA0(s32);
    s32 func_800F6E40(s32);
    struct BanjoCtrl {
        u8 pad[0x50];
        s32 (*callback)(s32);
    };
    s32 player;

    player = func_800F54E4();
    return !func_800F6DA0(player) && !func_800F6E40(player)
        && !func_800F64A4(player, 0x8000)
        && ((struct BanjoCtrl *)arg0)->callback(player);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800728_chbanjoctrl.s")

/* extern */

s32 func_808007D8_chbanjoctrl(u8 *arg0) {
    s32 func_800CC338(u8 *, s32, s32, u8 *);
    u32 temp_t6;

    temp_t6 = (u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19;
    if (temp_t6 == 0) {
        return 1;
    }
    return (func_800CC338(arg0 + 0x18, temp_t6 - 1, 0, arg0) + 1) != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800824_chbanjoctrl.s")

void func_808008D8_chbanjoctrl(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0, (*(f32 *)((s8 *)(arg0) + (0))) + arg1, arg0[1], arg0[2] + arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080091C_chbanjoctrl.s")

/* extern */

void func_80800ADC_chbanjoctrl(s32 arg0) {
    s32 func_800F54E4();
    s32 func_80800824_chbanjoctrl(s32, s32);
    s32 func_8080091C_chbanjoctrl(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    func_80800824_chbanjoctrl(arg0, temp_v0);
    func_8080091C_chbanjoctrl(arg0, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800B18_chbanjoctrl.s")

/* extern */ void func_80800D04_chbanjoctrl(u8 *arg0) { s32 func_800F54E4(); s32 func_800F8418(s32, u8 *, u8 *); f32 temp_f0; temp_f0 = (*(f32 *)((s8 *)(arg0) + (8))); if (temp_f0 < (*(f32 *)((s8 *)(arg0) + (0x1C)))) { (*(f32 *)((s8 *)(arg0) + (0x1C))) = temp_f0; func_800F8418(func_800F54E4(), arg0 + 0x18, arg0); } }

/* extern */

void func_80800D50_chbanjoctrl(u8 *arg0) {
    s32 func_800D90A4(s32);
    s32 func_800F54E4();
    s32 func_800F56AC(s32);
    s32 func_800F6C5C(s32);
    s32 func_800F6DA0(s32);
    s32 func_800F7B9C(s32, s32);
    if ((func_800D90A4(arg0 + 0x58) != 0) && (func_800F56AC(func_800F54E4()) == 0x19) && (func_800F6DA0(func_800F54E4()) == 0) && (func_800F6C5C(func_800F54E4()) != 0) && (func_800F7B9C(func_800F54E4(), 0x51) == 2)) {
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 3.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800DF8_chbanjoctrl.s")

void func_8080102C_chbanjoctrl(Actor *arg0) {
    if (arg0->unk64_20) {
        func_800FECB8(3U);
        func_800FCAE0(0x4AU, 0U, 0x7D0U);
        func_800FCA90(0x4AU);
        arg0->unk64_20 = 0;
    }
}

/* extern */

void func_80801088_chbanjoctrl(Actor *arg0) {
    s32 func_800F4F34(u32, f32 *, f32, f32);
    s32 func_800F54E4();
    int func_800F6720(s32);
    s32 sp1C;

    sp1C = func_800F54E4();
    if (func_800F6720(sp1C) != 0) {
        func_800F4F34(sp1C, arg0->position, 0.0f, arg0->unk74_7);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808010FC_chbanjoctrl.s")

/* extern */

void func_808011F4_chbanjoctrl(void) {
    void func_8080102C_chbanjoctrl();
    func_8080102C_chbanjoctrl();
}
