#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80800000_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808000D8_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80800950_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80800B68_chfantasyeyeball.s")

/* extern */

void func_80800F78_chfantasyeyeball(Actor *arg0, Actor *arg1) {
    void* func_80100094(Actor*, u32);
    s32 _subaddielink_entrypoint_5(u8 *, u8 *);
    s32 func_80800950_chfantasyeyeball(Actor *, s32, Actor *, Actor *);
    void *sp18[2];

    arg0->unk64_20 = 0;
    arg1->unk64_20 = 1;
    func_80800950_chfantasyeyeball(arg1, 6, arg1, arg0);
    sp18[0] = func_80100094(arg0, 0U);
    _subaddielink_entrypoint_5(sp18[0], func_80100094(arg1, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80800FEC_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808010B0_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808011D0_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80801290_chfantasyeyeball.s")

/* extern */

void func_80801314_chfantasyeyeball(void *arg0) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800A50B0(s32);
    s32 func_800F54E4();
    s32 func_800F7B9C(s32, s32);
    s32 func_800F82D4(s32, s32);
    func_800F82D4(func_800F54E4(), 0);
    _subaddieDll_entrypoint_4(arg0, 0);
    func_800F7B9C(func_800F54E4(), 0x6C);
    func_800A50B0(2);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFF7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80801378_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808013F8_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808016B4_chfantasyeyeball.s")

/* extern */

void func_80801740_chfantasyeyeball(Actor *arg0, f32 *arg1) {
    void _subaddieskeleton_entrypoint_1(Actor *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_1(arg0, 4, arg1);
    } else {
        func_800EE7F8(arg1, arg0->position);
        arg1[1] += arg0->scale * 224.0f;
    }
}

/* extern */

s32 func_808017B4_chfantasyeyeball(void) {
    s32 func_8010C754();
    s32 func_8010D248();
    f32 temp_f0;

    temp_f0 = (f32) func_8010C754();
    if ((temp_f0 > 5000.0f) || (temp_f0 < 500.0f)) {
        return 0;
    }
    return func_8010D248();
}

OSThread *chfantasyeyeball_entrypoint_0(void)
{
    extern u8 D_80801F28_chfantasyeyeball[];

    return (OSThread *) D_80801F28_chfantasyeyeball;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_8080182C_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80801A50_chfantasyeyeball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80801BC4_chfantasyeyeball.s")

OSThread *chfantasyeyeball_entrypoint_1(void)
{
    extern u8 D_80802008_chfantasyeyeball[];

    return (OSThread *) D_80802008_chfantasyeyeball;
}
