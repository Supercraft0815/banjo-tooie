#include "common.h"

/* extern */

void subaddiepalette_entrypoint_0(Actor *arg0, u8 *arg1, u16 arg2) {
    void *func_800D674C(s32);
    s32 func_800D6CEC(s32);
    s32 func_801032B0(Actor *, u16, u16);
    void rare_memcpy(void *, void *, int);
    void subaddiepalette_entrypoint_4(void *, void *);
    rare_memcpy(arg1 + 0x10, func_800D674C(arg2), 0x800);
    func_800D6CEC(arg2);
    (*(u16 *)(arg1 + 0)) = arg2;
    (*(s16 *)(arg1 + 4)) = 0;
    subaddiepalette_entrypoint_4(arg0, arg1);
    func_801032B0(arg0, arg0->unk0->unk14, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_1.s")

s32 subaddiepalette_entrypoint_2(void **arg0, void *arg1, u16 arg2, f32 arg3) {
    u16 old;
    old = *(u16 *)arg1;
    if (old == arg2) return 0;
    *(s16 *)((s8 *)arg1 + 4) = 1;
    *(f32 *)((s8 *)arg1 + 12) = arg3;
    *(f32 *)((s8 *)arg1 + 8) = arg3;
    *(u16 *)((s8 *)arg1 + 2) = old;
    *(u16 *)arg1 = arg2;
    *(u16 *)((s8 *)*arg0 + 22) = arg2;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_3.s")

void subaddiepalette_entrypoint_4(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (6))) = 1;
    if ((((*(s16 *)((s8 *)(arg0) + (0x60))) == 0) || ((((u32) (*(u8 *)((s8 *)(arg0) + (0x7B)))) >> 6) == 0)) && ((*(u8 *)((s8 *)(arg0) + (0x70))) & 1)) {
        (*(s16 *)((s8 *)(arg1) + (6))) = (s16) ((*(s16 *)((s8 *)(arg1) + (6))) + 1);
    }
}
