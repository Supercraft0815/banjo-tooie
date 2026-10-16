#include "common.h"

OSThread *chboxingglove_entrypoint_0(void)
{
    extern u8 D_80800708_chboxingglove[];

    return (OSThread *) D_80800708_chboxingglove;
}

OSThread *chboxingglove_entrypoint_1(void)
{
    extern u8 D_80800750_chboxingglove[];

    return (OSThread *) D_80800750_chboxingglove;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800018_chboxingglove.s")

/* extern */

void func_80800168_chboxingglove(void *arg0) {
    void *_subaddiefind_entrypoint_2(s32, s32 *, void *);
    void func_80800630_chboxingglove(Actor *);
    s32 sp18[1];
    void *temp_v0;

    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    temp_v0 = _subaddiefind_entrypoint_2(0x36E, ((s32 *)&sp18) - 1, arg0);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) (*(s32 *)((s8 *)(temp_v0) + (0)));
    (*(s32 *)((s8 *)(temp_v0) + (0x3C))) = (s32) (*(s32 *)((s8 *)(arg0) + (0)));
    func_80800630_chboxingglove(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_808001CC_chboxingglove.s")

void func_808002AC_chboxingglove(void *arg0) {
    f32 temp_f0;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (8)));
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (temp_f0 - 70.0f);
    (*(f32 *)((s8 *)(arg0) + (0x28))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_808002E0_chboxingglove.s")

/* extern */

s32 func_808004F8_chboxingglove(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    s32 func_800FFAB0(void *);
    if (func_800DA298(0) != 0) {
        func_800FFAB0(arg0);
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0x3C))));
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boxingglove/func_80800544_chboxingglove.s")

void func_80800630_chboxingglove(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *actors[4];
    s32 count;
    s32 i;
    f32 (*data[1])[4];
    f32 (*dst)[4];

    data[0] = func_80100094(arg0, 0);
    count = _subaddiefind_entrypoint_4(0x34D, actors, 4);
    dst = data[0];
    for (i = 0; i < count; i++) {
        func_800EE7F8(*dst, ((Actor *)actors[i])->position);
        (*dst)[3] = ((Actor *)actors[i])->scale * 150.0f;
        dst++;
    }
}
