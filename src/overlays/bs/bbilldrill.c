#include "common.h"

void func_80800000_bsbbilldrill(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x168) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800008_bsbbilldrill.s")

void func_808000C0_bsbbilldrill(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x168)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x168))) = _chlightfader_entrypoint_1(temp_a3, 0.6f, 2);
    }
}

/* extern */

void func_80800100_bsbbilldrill(void *arg0) {
    f32 func_80092BF4(void *);
    void func_80093300(void *, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_80092BF4(arg0);
    var_f2 = temp_f0;
    if (temp_f0 == 0.0f) {
        var_f2 = 8.0f;
    }
    var_f2 = -var_f2;
    func_80093300(arg0, var_f2);
}

void func_80800158_bsbbilldrill(s32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800AC8_bsbbilldrill;
    func_800BABB8(func_800B5BE4(9), arg0, 0, 0x3F800000, &D_80800AC8_bsbbilldrill);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_8080019C_bsbbilldrill.s")

/* extern */

void func_80800250_bsbbilldrill(void *arg0) {
    void func_800BA22C(s32, s32);
    s32 _fxdlsmoke_entrypoint_0(f32 *);
    void func_8009C128(void *, f32[3]);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    sp1C[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(sp1C), 1);
}

/* extern */

void func_80800298_bsbbilldrill(s32 arg0) {
    s32 _bswalk_entrypoint_1();
    f32 baphysics_get_target_horizontal_velocity(s32);
    s32 baphysics_set_target_horizontal_velocity(s32, f32);
    _bswalk_entrypoint_1();
    baphysics_set_target_horizontal_velocity(arg0, baphysics_get_target_horizontal_velocity(arg0) * 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_808002DC_bsbbilldrill.s")

/* extern */

void func_808005C0_bsbbilldrill(u8 *arg0) {
    f32 func_800D8FF8(void);
    s32 func_8009328C(u8 *, f32);
    f32 delta = func_800D8FF8();
    f32 *velocity = (f32 *) (arg0 + 0x170);
    f32 *position = (f32 *) (arg0 + 0x16C);
    *position += *velocity * delta;
    func_8009328C(arg0, *position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_2.s")

s32 bsbbilldrill_entrypoint_3(s32 arg0) {
    extern s32 D_80800B68_bsbbilldrill[];
    return ((s32 *)&D_80800B68_bsbbilldrill)[arg0];
}
