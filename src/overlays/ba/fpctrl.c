#include "common.h"

s32 bafpctrl_entrypoint_0() 
{
    return 0x1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800008_bafpctrl.s")

/* extern */

void func_808000DC_bafpctrl(void *arg0, s32 arg1, f32 arg2) {
    s32 func_800A4C68(f32);
    s32 func_800C51A4(s32, s32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x90)))) + (0x18))) = arg2;
    func_800C51A4(func_800A4C68(arg2), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800114_bafpctrl.s")

/* extern */

typedef struct player_state_s PlayerState;
PlayerState *func_800A4CA8(PlayerState *);
void _ncba1p_entrypoint_7(PlayerState *, f32[3]);

void func_8080022C_bafpctrl(PlayerState *arg0) {
    f32 baroll_get(PlayerState *);
    f32 func_8009BFCC(PlayerState *);
    void func_800F3E84(s32, void *);
    f32 yaw_getIdeal(PlayerState *);
    f32 sp24[3];

    func_800F3E84(arg0, sp24);
    sp24[0] = -func_8009BFCC(arg0);
    sp24[1] = yaw_getIdeal(arg0) + 180.0f;
    sp24[2] = -baroll_get(arg0);
    _ncba1p_entrypoint_7(func_800A4CA8(arg0), sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_808002A4_bafpctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_808003BC_bafpctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800424_bafpctrl.s")

/* extern */

void func_808005FC_bafpctrl(s32 arg0, f32 *arg1) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32[3], f32[3]);
    s32 func_800F3BD0(void *, s32, f32 *);
    f32 yaw_get(s32);
    f32 sp1C[3];

    func_800F3BD0((void *) arg0, 5, arg1);
    func_800EEB9C(sp1C, yaw_get(arg0), 5.0f);
    func_800EF04C(arg1, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_8080064C_bafpctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800704_bafpctrl.s")

/* extern */

void func_80800880_bafpctrl(u8 *arg0) {
    if ((*(*(s32 **)((s8 *)arg0 + 0x90)) & 1) != 0) {
        _ncba1p_entrypoint_7(func_800A4CA8(arg0), (struct ba_flag_s **)(*(s32 **)((s8 *)arg0 + 0x90) + 1));
    }
}

/* extern */

void func_808008CC_bafpctrl(s32 arg0) {
    void func_808005FC_bafpctrl(s32, f32 *);
    s32 _ncba1p_entrypoint_6(void *, f32 *);
    f32 sp1C[3];

    func_808005FC_bafpctrl(arg0, sp1C);
    _ncba1p_entrypoint_6(func_800A4CA8((void *)arg0), sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800904_bafpctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/func_80800970_bafpctrl.s")

u32 bafpctrl_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 17);
}

u32 bafpctrl_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 18);
}

void bafpctrl_entrypoint_3(u8 *arg0) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    func_800F10B4((*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x90)))) + (0x18))), 10.0f, 40.0f, 0.2f, 1.0f);
}

u32 bafpctrl_entrypoint_4(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 16);
}

s32 bafpctrl_entrypoint_5(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x90)))) + (0x14))) == 2;
}

u32 bafpctrl_entrypoint_6(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 19);
}

void bafpctrl_entrypoint_7(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/bafpctrl_entrypoint_8.s")

void bafpctrl_entrypoint_9(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 17) = arg1;
}

void bafpctrl_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 144) + 18) = arg1;
}

void bafpctrl_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0;
    s32 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(s32 **)((s8 *)(arg0) + (0x90)));
        *temp_v0 |= arg1;
        return;
    }
    temp_v0_2 = (*(s32 **)((s8 *)(arg0) + (0x90)));
    *temp_v0_2 &= ~arg1;
}

/* extern */

void bafpctrl_entrypoint_12(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x90))) + 4);
}

/* extern */

void bafpctrl_entrypoint_13(void *arg0, s32 arg1) {
    s32 _baeggcursor_entrypoint_6();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x90)))) + (0x13))) = arg1;
    _baeggcursor_entrypoint_6();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/bafpctrl_entrypoint_14.s")

/* extern */

int func_80800E30_bafpctrl(PlayerState *arg0) {
    s32 _ncba1p_entrypoint_10();
    int bakey_pressed(PlayerState *, int);
    s32 func_800F6774(u32);

    return bakey_pressed(arg0, 0xC) && bafpctrl_entrypoint_6(arg0)
        && func_800F6774(*(u32 *)((s8 *)arg0 + 0x184))
        && _ncba1p_entrypoint_10(func_800A4CA8(arg0)) != 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/bafpctrl_entrypoint_15.s")

/* extern */

void bafpctrl_entrypoint_16(void *arg0) {
    s32 bafpctrl_entrypoint_14();
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x90)));
    if (((*(u8 *)((s8 *)(temp_v0) + (0x13))) != 0) && ((*(u8 *)((s8 *)(temp_v0) + (0x10))) != 3)) {
        bafpctrl_entrypoint_14();
    }
}

void bafpctrl_entrypoint_17(u8 *arg0) {
    s32 bafpctrl_entrypoint_14(void *, s32);
    if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x90)))) + (0x13))) != 0) {
        bafpctrl_entrypoint_14(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fpctrl/bafpctrl_entrypoint_18.s")

/* extern */

void bafpctrl_entrypoint_19(void *arg0) {
    s32 _plcamera_entrypoint_0(s32);
    s32 bafpctrl_entrypoint_14(void *, s32);
    s32 func_8009337C(void *, s32);
    s32 func_800A3544(void *, s32);
    s32 func_800A4EC8(void *);
    if (bafpctrl_entrypoint_4(arg0) == 3) {
        bafpctrl_entrypoint_14(arg0, 1);
        func_800A3544(arg0, 0);
        func_8009337C(arg0, 1);
        func_800A4EC8(arg0);
        _plcamera_entrypoint_0((*(s32 *)((s8 *)(arg0) + (0x184))));
    }
}
