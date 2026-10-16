#include "common.h"

OSThread *chballoonbomb_entrypoint_0(void)
{
    extern u8 D_808004B0_chballoonbomb[];

    return (OSThread *) D_808004B0_chballoonbomb;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_8080000C_chballoonbomb.s")

/* extern */

void func_80800118_chballoonbomb(Actor *arg0) {
    f32 func_800136E4(f32);
    s32 func_8008FF18();
    f32 func_800D8FF8();
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80800230_chballoonbomb(Actor *, s32, s32);
    void func_80800294_chballoonbomb(Actor *);
    f32 *sp24;
    union {
        f32 f;
        s32 i;
    } sp20;

    sp24 = func_80100094(arg0, 0);
    sp20.f = func_800D8FF8();
    if (!arg0->unk64_17) {
        if (func_800DA298(0) != 0) {
            func_80800294_chballoonbomb(arg0);
            return;
        }
        if ((func_800DA298(0x641) == 0) && (func_8008FF18() == 0)) {
            arg0->rotation[1] = func_800136E4((*sp24 * sp20.f) + arg0->rotation[1]);
            func_80800230_chballoonbomb(arg0, sp20.i, 1);
            arg0->scale = func_800F15F8(arg0->scale, 1.4f, sp20.f * 1.5f);
        }
    }
}

u32 func_808001F8_chballoonbomb(s32 unused, s32 arg1, s32 arg2) {
    void func_80800294_chballoonbomb(Actor *);

    if (arg1 == 0x40) {
        func_80800294_chballoonbomb((Actor *) unused);
        return 1;
    }
    return 0;
}

/* extern */

void func_80800230_chballoonbomb(Actor *arg0, s32 arg1, s32 arg2) {
    f32 func_800D8FF8(void);
    s32 func_8010B990(Actor *, s32);
    void func_80800294_chballoonbomb(Actor *);
    f32 delta;

    delta = func_800D8FF8();
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x2C))) - (500.0f * delta));
    if (func_8010B990(arg0, 0x500007) & 0x20) {
        func_80800294_chballoonbomb(arg0);
    }
}

void func_80800294_chballoonbomb(Actor *arg0) {
    s32 *_fxgenlist_entrypoint_2(void);
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800FFAB0(Actor *);
    void func_80800440_chballoonbomb(u8 *);
    extern s32 D_808004F8_chballoonbomb;
    if (!arg0->unk64_20) {
        func_80800440_chballoonbomb((u8 *)arg0);
        func_800BBCB8(arg0->position, NULL, 1.0f, 1, _fxgenlist_entrypoint_2());
        func_800C4AF0(arg0->position, &D_808004F8_chballoonbomb);
        if (arg0->unk6C_0 >= 4U) {
            func_800E1610(0, 30.0f, 0.9f, arg0->position);
            func_80018820(0, 2.0f, 0.15f);
        }
        arg0->unk64_20 = 1;
        func_800FFAB0(arg0);
    }
}

void func_80800354_chballoonbomb(u8 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_8080050C_chballoonbomb;
    u8 *temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8((f32 *)temp_a0, (f32 *)temp_a0, (*(f32 *)((s8 *)(arg0) + (0x38))), 8, &D_8080050C_chballoonbomb);
}

void func_80800394_chballoonbomb(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800540_chballoonbomb;
    s32 sp24;
    f32 *temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_80800540_chballoonbomb);
    func_800BA22C(sp24, arg2);
}

void func_80800400_chballoonbomb(u8 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_8080057C_chballoonbomb;
    func_800BBCB8((f32 *)(arg0 + 4), 0, (*(f32 *)((s8 *)(arg0) + (0x38))), 1, &D_8080057C_chballoonbomb);
}

void func_80800440_chballoonbomb(u8 *arg0) {
    func_80800394_chballoonbomb(arg0, 0x93F, 2);
    func_80800394_chballoonbomb(arg0, 0x940, 3);
    func_80800394_chballoonbomb(arg0, 0x941, 4);
    func_80800400_chballoonbomb(arg0);
    func_80800354_chballoonbomb(arg0);
}
