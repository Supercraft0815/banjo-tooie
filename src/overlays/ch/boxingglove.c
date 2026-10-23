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

void func_80800018_chboxingglove(Actor *arg0) {
    s32 func_8008FF18(void);
    s32 func_800D90A4(f32 *);
    s32 func_80101DDC(Actor *);
    s32 func_8010D248(void);
    void func_8010D254(f32 *);
    void func_808002E0_chboxingglove(Actor *, s32);
    s32 func_808004F8_chboxingglove(void *);
    f32 position[3];

    switch (arg0->unk70_10) {
        case 1:
            if (!func_808004F8_chboxingglove(arg0) &&
                ((!func_8008FF18() && func_8010D248()) || !arg0->unk64_20) &&
                func_800D90A4(&arg0->unk58)) {
                func_8010D254(position);
                if (position[1] < ((f32 *)arg0->actorData)[4] + 500.0f || !arg0->unk64_20) {
                    func_808002E0_chboxingglove(arg0, 2);
                }
            }
            break;
        case 2:
            if (func_800D90A4(&arg0->unk58)) {
                func_808002E0_chboxingglove(arg0, 3);
            }
            break;
        case 3:
            if (func_80101DDC(arg0)) {
                func_808002E0_chboxingglove(arg0, 4);
            }
            break;
        case 4:
            if (func_800D90A4(&arg0->unk58)) {
                func_808002E0_chboxingglove(arg0, 1);
            }
            break;
    }
}

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

void func_808002E0_chboxingglove(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800DC178(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_80101FDC(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010D09C(s32, f32 *, f32);
    void func_8010D254(f32 *);
    s32 func_808004F8_chboxingglove(void *);
    s32 func_80800544_chboxingglove(Actor *, f32 *);
    extern u8 D_808007A0_chboxingglove[];
    Actor *other;
    f32 sp40[3];
    f32 sp34[3];

    other = func_80106790(arg0->unk3C);
    switch (arg1) {
        case 1:
            arg0->unk58 = func_800DC178(2.0f, 3.0f);
            func_80102424(arg0, 1);
            func_80101FDC(other, arg1);
            other->unk64_16 = 0;
            break;
        case 2:
            if (arg0->unk64_20) {
                func_8010D09C(func_800F54E4(), sp40, 1.5f);
                if (func_80800544_chboxingglove(arg0, sp40) ||
                    (func_8010D254(sp40), func_80800544_chboxingglove(arg0, sp40))) {
                    arg0->position[0] = other->position[0] = sp40[0];
                    arg0->position[2] = other->position[2] = sp40[2];
                } else {
                    return;
                }
            } else {
                arg0->unk64_20 = 1;
            }
            arg0->unk58 = 1.5f;
            other->unk58 = 1.5f;
            func_80102424(arg0, arg1);
            func_80101FDC(other, arg1);
            other->unk64_16 = 1;
            break;
        case 3:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808007A0_chboxingglove);
            func_80102424(arg0, arg1);
            func_80101FDC(other, arg1);
            func_8010A590(arg0);
            arg0->unk64_16 = 1;
            func_8010D254(sp34);
            func_800F1E6C(sp34, arg0->position, &arg0->rotation[1]);
            break;
        case 4:
            arg0->unk58 = 1.5f;
            other->unk58 = 1.5f;
            func_80102424(arg0, arg1);
            func_80101FDC(other, arg1);
            func_8010A570(arg0);
            arg0->unk64_16 = 0;
            func_808004F8_chboxingglove(arg0);
            break;
    }
}

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
