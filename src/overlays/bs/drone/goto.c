#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_80800000_bsdronegoto.s")

/* extern */

s32 func_8080009C_bsdronegoto(void) {
    s32 func_800A3274();
    return func_800A3274() != 0x12;
}

void func_808000C0_bsdronegoto()
{
    func_8009B7C0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_808000E0_bsdronegoto.s")

void func_80800148_bsdronegoto(s32 arg0) 
{
}
/* extern */

void func_80800150_bsdronegoto(void *arg0) {
    void _badata_entrypoint_1(void *, s32 *, f32 *);
    s32 _badrone_entrypoint_7(void *);
    s32 _badrone_entrypoint_8(void *, f32 *, f32 *, s32 *);
    void _bamovegoto_entrypoint_0(void *);
    s32 _bamovegoto_entrypoint_10(void *, s32);
    void _bamovegoto_entrypoint_12(void *, f32 *);
    void _bamovegoto_entrypoint_13(void *);
    void _bamovegoto_entrypoint_7(void *, f32);
    s32 _bamovegoto_entrypoint_8(void *, s32);
    s32 _bamovegoto_entrypoint_9(void *, s32);
    void baanim_playForDuration_loopSmooth(void *, s32, f32);
    u32 func_80095898(s32 *);
    s32 func_800961A0(s32 *, s32);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    f32 sp3C;
    s32 sp38;
    f32 sp2C[3];
    s32 sp28;

    _badata_entrypoint_1(arg0, &sp28, &sp3C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp3C);
    _badrone_entrypoint_8(arg0, sp2C, &sp3C, &sp38);
    _bamovegoto_entrypoint_0(arg0);
    _bamovegoto_entrypoint_12(arg0, sp2C);
    if (sp3C != 0.0f) {
        _bamovegoto_entrypoint_9(arg0, 1);
        _bamovegoto_entrypoint_7(arg0, sp3C);
    } else {
        _bamovegoto_entrypoint_9(arg0, 2);
        _bamovegoto_entrypoint_8(arg0, sp38);
    }
    func_8009FFD8(arg0, 1, 1, 3, 0);
    (*(s32 *)((s8 *)(arg0) + (0x198))) = func_80095898(arg0);
    if (_badrone_entrypoint_7(arg0) != 0) {
        func_800961A0(arg0, 0);
        _bamovegoto_entrypoint_10(arg0, 1);
    } else {
        func_800961A0(arg0, 1);
    }
    _bamovegoto_entrypoint_13(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_8080026C_bsdronegoto.s")

/* extern */

void func_8080032C_bsdronegoto(void *arg0) {
    s32 func_800961A0(s32 *, s32);
    func_800961A0(arg0, (*(s32 *)((s8 *)(arg0) + (0x198))));
}

/* extern */

void bsdronegoto_entrypoint_0(void *arg0) {
    s32 _badata_entrypoint_14(void *);
    s32 _gcgoto_entrypoint_14(s32);
    s32 func_80091E48(void *, s32);
    s32 func_80800000_bsdronegoto(void *, s32);
    int player_isStable(void *);
    (*(s32 *)((s8 *)(arg0) + (0x190))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x194))) = 0;
    _gcgoto_entrypoint_14(1);
    func_80091E48(arg0, 0x3F);
    if ((player_isStable(arg0) == 0) && (_badata_entrypoint_14(arg0) != 0)) {
        func_80800000_bsdronegoto(arg0, 1);
        return;
    }
    func_80800000_bsdronegoto(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/bsdronegoto_entrypoint_1.s")

/* extern */

void bsdronegoto_entrypoint_2(void *arg0) {
    s32 _gcgoto_entrypoint_14(s32);
    void func_80091E6C(void *);
    s32 func_80800000_bsdronegoto(void *, s32);
    func_80800000_bsdronegoto(arg0, 0);
    func_80091E6C(arg0);
    _gcgoto_entrypoint_14(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/bsdronegoto_entrypoint_3.s")
