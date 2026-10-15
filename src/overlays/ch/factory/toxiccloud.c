#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800000_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808000F0_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808001B8_chfactorytoxiccloud.s")

/* extern */

void func_80800A34_chfactorytoxiccloud(s32 arg0, void *arg1) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_800DC178(0.5f, 1.0f);
    (*(f32 *)((s8 *)(arg1) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg1) + (0xC))) = (f32) (func_800DC178(0.4f, 0.5f) + 0.2f);
    (*(f32 *)((s8 *)(arg1) + (0x10))) = (f32) (func_800DC178(0.7f, 0.9f) + 0.2f);
    (*(s32 *)((s8 *)(arg1) + (8))) = func_800DC128(0, 0x10);
}

/* extern */

void func_80800AD8_chfactorytoxiccloud(s32 arg0, f32 *volatile arg1) {
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 func_800F5410(s32);
    s32 func_800F54E4();
    void func_800F5A00(s32, f32 *);
    void func_800F5A2C(s32, s32, f32 *);
    f32 func_800F5F24(u32);
    f32 sp34[3];
    f32 sp28[3];
    s32 temp_v0;

    temp_v0 = func_800F5410(func_800F54E4());
    if ((temp_v0 == 1) || (temp_v0 == 0xA) || (temp_v0 == 0xB)) {
        func_800F5A2C(func_800F54E4(), 5, sp34);
        func_800F5A2C(func_800F54E4(), 2, sp28);
        func_800EFE50(arg1, sp34, sp28, 0.5f);
        func_800EEB9C(sp34, func_800F5F24(func_800F54E4()), 20.0f);
        sp34[1] += 20.0f;
        func_800EF04C(arg1, sp34);
        return;
    }
    func_800F5A00(func_800F54E4(), arg1);
    func_800EF1B8(arg1, func_800F5F24(func_800F54E4()), 30.0f);
    arg1[1] += 140.0f;
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x64];
        u32 pad64_30 : 2;
        u32 unk64_29 : 1;
        u32 pad64_0 : 29;
    } flags;
} ToxicCloudActor;

int func_80800BF8_chfactorytoxiccloud(ToxicCloudActor *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    f32 temp_f2;
    f32 var_f12;

    if (arg0->flags.unk64_29) {
        var_f12 = 6.0f;
    } else {
        var_f12 = 2.0f;
    }
    temp_f2 = var_f12 * 25.0f;
    return func_800EEB40(arg1, (f32 *)arg0->actor.actorData) < (temp_f2 * temp_f2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800C7C_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800FCC_chfactorytoxiccloud.s")

/* extern */

void func_808010B8_chfactorytoxiccloud(void *arg0) {
    f32 _subaddiejoy_entrypoint_3();
    f32 func_80013728(f32);
    s32 func_80102BAC(void *, s32, s32, s32);
    s32 func_8010BA80(void *, s32, s32);
    f32 mlAbsF(f32);
    f32 sp24;

    sp24 = _subaddiejoy_entrypoint_3() * 650.0f;
    func_80102BAC(arg0, 0x3FC00000, 0x3F800000, 0x41C80000);
    if (mlAbsF(func_80013728((*(f32 *)((s8 *)(arg0) + (0x54))) - (*(f32 *)((s8 *)(arg0) + (0x48))))) < 90.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = sp24;
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) (sp24 / 10.0f);
    }
    func_8010BA80(arg0, 0x200026, 0x20);
}

/* extern */

void func_80801164_chfactorytoxiccloud(void *arg0) {
    s32 func_8010BA80();
    f32 sp1C;

    sp1C = (*(f32 *)((s8 *)(arg0) + (0x48)));
    (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x54)));
    func_8010BA80();
    (*(f32 *)((s8 *)(arg0) + (0x48))) = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808011A0_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808012C4_chfactorytoxiccloud.s")

OSThread *chfactorytoxiccloud_entrypoint_0(void)
{
    extern u8 D_80801568_chfactorytoxiccloud[];

    return (OSThread *) D_80801568_chfactorytoxiccloud;
}
