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

void func_808001CC_chboxingglove(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    extern u32 D_80800798_chboxingglove;
    s32 active = 0;

    switch (arg0->unk70_10) {
        case 2:
            func_800D90A4(&arg0->unk58);
            arg0->position[1] = ((f32 *)arg0->actorData)[4] - func_800F10B4(arg0->unk58, 0.0f, 1.5f, 0.0f, 70.0f);
            active = 1;
            break;
        case 4:
            func_800D90A4(&arg0->unk58);
            arg0->position[1] = ((f32 *)arg0->actorData)[4] - func_800F10B4(arg0->unk58, 0.0f, 1.5f, 70.0f, 0.0f);
            active = 1;
            break;
    }
    if (active || (!active && arg0->unk5F)) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, active, &D_80800798_chboxingglove);
    }
}

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

s32 func_80800544_chboxingglove(Actor *arg0, f32 *arg1) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    void *func_80100094(Actor *, u32);
    f32 start[3];
    f32 end[3];
    f32 hit[3];
    s32 i;
    f32 (*data)[4];
    f32 (*dst)[4];

    data = func_80100094(arg0, 0);
    dst = data;
    for (i = 0; i < 4; i++) {
        if (func_800F0064(arg1, dst[i][3], dst[i])) {
            return 0;
        }
    }
    func_800EE7F8(start, arg1);
    func_800EE7F8(end, arg1);
    start[1] = ((f32 *)arg0->actorData)[4] + 200.0f;
    end[1] = ((f32 *)arg0->actorData)[4] - 50.0f;
    return func_800BEF00(start, end, hit, arg0->unk14) ? 1 : 0;
}

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
