#include "common.h"

OSThread *chflowerbaddie_entrypoint_0(void)
{
    extern u8 D_80800C14_chflowerbaddie[];

    return (OSThread *) D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 600.0f;
    arg0->unk64_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_8080005C_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800380_chflowerbaddie.s")

/* extern */

void func_80800610_chflowerbaddie(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    func_800DF744(3, arg0->unk64_20 ? 1 : 0);
    func_800DF744(4, arg0->unk64_20 ? 2 : 1);
    func_800DF744(5, 1);
    func_800DF744(6, 0);
    func_80101870(arg0, arg1);
}

void func_808006A0_chflowerbaddie(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_80103DFC(Actor *, f32 *);
    extern s32 D_80800CCC_chflowerbaddie;
    extern s32 D_80800CF0_chflowerbaddie;
    extern s32 D_80800D04_chflowerbaddie;
    extern s32 D_80800D18_chflowerbaddie;
    f32 sp34[3];
    s32 emitter;

    func_80103DFC(arg0, sp34);
    emitter = func_800B53A4(1);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800D18_chflowerbaddie);
    func_800BA22C(emitter, 1);
    emitter = func_800B53A4(2);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CF0_chflowerbaddie);
    func_800BA22C(emitter, 2);
    emitter = func_800B53A4(4);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800D04_chflowerbaddie);
    func_800BA22C(emitter, 4);
    arg0->unk64_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808007F0_chflowerbaddie.s")

/* extern */

s32 func_808008D4_chflowerbaddie(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 1;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 1;
    }
    return _suchase_entrypoint_0() != arg0->unk0;
}

void func_80800980_chflowerbaddie(Actor *arg0, f32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_80800D28_chflowerbaddie;

    if (func_80101E4C(arg0, arg1) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
            func_800C4350(arg0->unk5F, arg0->position, &D_80800D28_chflowerbaddie);
        }
        func_800C3BDC(arg0->unk5F);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808009F0_chflowerbaddie.s")
