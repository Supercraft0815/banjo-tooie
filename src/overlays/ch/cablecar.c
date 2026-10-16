#include "common.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "su/baddieaudioquick.h"

extern f32 D_80800F40_chcablecar[3];
extern s16 D_80800F4C_chcablecar[];
extern s16 D_80800F58_chcablecar[];

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 unk10;
} cablecarMemory;

OSThread *chcablecar_entrypoint_0(void)
{
    extern u8 D_80800EB0_chcablecar[];

    return (OSThread *) D_80800EB0_chcablecar;
}

OSThread *chcablecar_entrypoint_1(void)
{
    extern u8 D_80800EF8_chcablecar[];

    return (OSThread *) D_80800EF8_chcablecar;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800018_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808002E0_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800424_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808004EC_chcablecar.s")

void func_80800598_chcablecar(Actor *arg0) {
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    s32 pad;
    u8 *temp_a0;
    cablecarMemory *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_a0 = &temp_v0->unk10;
    _mlwave_entrypoint_1(temp_a0);
    arg0->rotation[0] = _mlwave_entrypoint_5(temp_a0, -5.0f, 5.0f);
}

void func_808005E0_chcablecar(Actor* arg0) {
    void* temp_a0;
    cablecarMemory* temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    temp_a0 = &temp_v0->unk10;
    if (temp_v0->unkC < 0.5f) {
        if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F4C_chcablecar);
        }
    } else if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F58_chcablecar);
    }
}

void func_8080069C_chcablecar(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    extern u32 D_80800F68_chcablecar;
    u32 var_a2;

    switch (arg0->unk70_10) {
        case 4:
        case 5:
        case 6:
            var_a2 = 1;
            break;
        default:
            var_a2 = 0;
            break;
    }
    if ((var_a2 != 0) || ((var_a2 == 0) && (arg0->unk5F != 0))) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, var_a2, &D_80800F68_chcablecar);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_8080070C_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808007C8_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800914_chcablecar.s")

void func_80800AF4_chcablecar(Actor *arg0, u32 arg1) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    void func_80015178(s32);
    void func_80101FDC(Actor *, u32);
    void func_80103D70(void **);
    typedef struct {
        u32 upper : 18;
        u32 active : 1;
        u32 lower : 13;
    } CablecarFlags;

    _subaddieDll_entrypoint_4(arg0, 0);
    func_80103D70((void **)arg0);
    func_80101FDC(arg0, arg1);
    if (((CablecarFlags *)&arg0->unk0->unk28)->active) {
        func_80015178(2);
        ((CablecarFlags *)&arg0->unk0->unk28)->active = 0;
    }
    arg0->actorData[4] = 0;
    arg0->unk64_19 = 0;
}

/* extern */

void func_80800B74_chcablecar(s32 arg0, s32 arg1, s32 arg2) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    if (func_800DA298(0x67E) == 0) {
        func_80101FDC(arg0, 2);
        return;
    }
    func_80101FDC(arg0, 3);
    _subaddieDll_entrypoint_4(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800BD0_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800D14_chcablecar.s")

void func_80800DC8_chcablecar(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    void func_80102FDC(Actor*, f32);
    Actor* func_801084B0(s32, Actor**);
    Actor *sp1C;
    union {
        Actor *actor;
        struct {
            u8 reserved[0x7C];
            u16 flags;
        } *fields;
    } view;
    sp1C = func_801084B0(0x33F, &arg0);
    func_80102FDC(sp1C, arg0->scale);
    view.actor = arg0;
    _subaddieDll_entrypoint_4(sp1C, view.fields->flags);
    sp1C->rotation[0] = arg0->rotation[0];
    arg0->unk3C = sp1C->unk0;
}

/* extern */

void func_80800E30_chcablecar(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0xD4);
    _chswitch_entrypoint_9(arg0);
}
