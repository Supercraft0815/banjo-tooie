#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *suegg_entrypoint_0(void)
{
    extern u8 D_80800E40_suegg[];

    return (OSThread *) D_80800E40_suegg;
}

void func_8080000C_suegg(Actor *arg0) {
    s32 func_800AF5A0(s16 *);
    s32 func_800EC3E8(u8 *);
    void *sp1C;

    sp1C = func_80100094(arg0, 0);
    *(f32 *)((s8 *)sp1C + 4) = 0.0f;
    *(s32 *)((s8 *)sp1C + 8) = func_800AF5A0((s16 *)func_800EC3E8((u8 *)arg0->unk0));
    *(f32 *)((s8 *)sp1C + 0) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/func_80800064_suegg.s")

void suegg_entrypoint_1(Actor *arg0, f32 arg1) { *(f32 *)func_80100094(arg0, 0) = arg1; }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_2.s")

void suegg_entrypoint_3(Actor *arg0)
{
    suegg_entrypoint_4(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_4.s")

/* extern */

void suegg_entrypoint_5(Actor *arg0) {
    s32 func_80800DC0_suegg(Actor *, s32);
    Unk80132ED0 *temp_v0;

    if (func_80800DC0_suegg(arg0, (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x3A)))) == 0) {
        temp_v0 = arg0->unk0;
        (*(u8 *)((s8 *)(temp_v0) + (0x2A))) = (u8) (((*(u8 *)((s8 *)(temp_v0) + (0x2A))) & ~4) | 4);
    }
}

s16 suegg_entrypoint_6(Unk80132ED0 *arg0, f32 *arg1, s32 *arg2) {
    s32 _gcegg_entrypoint_0(u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800EFB24(void *, void *, void *);
    Actor *sp1C;
    void *sp18;

    sp1C = func_80106790(arg0);
    sp18 = func_80100094(sp1C, 0);
    func_800EFB24(arg1, sp1C->position, sp1C->actorData);
    *arg2 = _gcegg_entrypoint_0(arg0->unk24 >> 22);
    return *(s16 *)((u8 *)sp18 + 0x3A);
}

/* extern */

s16 suegg_entrypoint_7(void) {
    Actor *func_80106790();
    return (*(s16 *)((s8 *)(func_80100094(func_80106790(), 0)) + (0x3A)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/func_80800390_suegg.s")

void suegg_entrypoint_8(s32 arg0)
{
    suegg_entrypoint_9(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_9.s")

/* extern */

void suegg_entrypoint_10(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    struct Flags {
        u8 pad[0x39];
        u8 active : 1;
        u8 rest : 7;
    };
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_9(s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct Flags *temp_v0;

    if ((_glhittableDll_entrypoint_6(arg2) != 0) && (_glhittableDll_entrypoint_9(arg2) != 0)) {
        temp_v0 = func_80100094(func_80106790(arg0), 0);
        temp_v0->active = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_14.s")

void suegg_entrypoint_15(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_17.s")

/* extern */

void suegg_entrypoint_18(s32 arg0, s32 arg1) {
    void func_800EFB24();
    func_800EFB24(arg1, arg0 + 0x4, arg0 + 0x18, arg0);
}

void suegg_entrypoint_19(void *arg0, f32 *arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x18);
}

void suegg_entrypoint_20(void *arg0, f32 *arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/egg/suegg_entrypoint_22.s")

void suegg_entrypoint_23(s32 arg0) {
    s32 func_8010D930(s32, s32, s32, s32 *);
    extern s32 D_80800E64_suegg;
    func_8010D930(8, 0, arg0 + 4, &D_80800E64_suegg);
}

/* extern */

s32 func_80800DC0_suegg(Actor *arg0, s32 arg1) {
    s32 func_800D3948(void);
    s32 func_800F6CC8(s32);
    struct {
        u8 pad[0x39];
        u8 : 1;
        u8 active : 1;
        u8 : 6;
    } *temp_v0;

    if ((func_800D3948() == 0) && (func_800F6CC8(arg1) != 0)) {
        temp_v0 = func_80100094(arg0, 0);
        temp_v0->active = 1;
        suegg_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}
