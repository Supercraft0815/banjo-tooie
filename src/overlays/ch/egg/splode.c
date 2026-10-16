#include "common.h"

OSThread *cheggsplode_entrypoint_0(void)
{
    extern u8 D_80800994_cheggsplode[];

    return (OSThread *) D_80800994_cheggsplode;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080000C_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_808002A8_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080035C_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080041C_cheggsplode.s")

/* extern */

f32 func_80800548_cheggsplode(s32 arg0) {
    s32 func_800F693C(s32);
    s32 func_800F6BE4(s32);
    if (func_800F6BE4(arg0) != 0) {
        return func_800F693C(arg0) != 0 ? 250.0f : 190.0f;
    }
    return 190.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/cheggsplode_entrypoint_1.s")

void cheggsplode_entrypoint_2(f32 *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Actor *func_80108474(u32, f32 *, s32);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    actor = func_80108474(0x2B2, arg0, (s32)arg1);
    data = func_80100094(actor, 0);
    data->unk0 = arg2;
    data->unk4 = arg3;
    data->unk6 = arg4 == 0;
    if (arg3 == 5) {
        actor->unk70_10 = 4;
        data->unkC = func_80800548_cheggsplode(arg2);
    }
}

void func_808006F0_cheggsplode(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808009E8_cheggsplode;
    u16 var_v0;
    s32 temp_a0;

    temp_a0 = func_800B53A4(6);
    var_v0 = arg0->unk70_10 == 3 ? 0x875 : 0x9B1;
    func_800BA670(temp_a0, var_v0);
    func_800BABB8(temp_a0, arg0->position, arg0->position, 0.25f, &D_808009E8_cheggsplode);
    func_800BA22C(temp_a0, 6);
}

/* extern */

void func_80800778_cheggsplode(Actor *arg0, s32 arg1) {
    s32 func_800D3948();
    s32 func_800F6BE4(s32);
    s32 func_800F6CC8(s32);
    void *func_80100094(Actor *, u32);
    if ((func_800D3948() == 0) && (func_800F6BE4(arg1) != 0) && (func_800F6CC8(arg1) != 0)) {
        (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (6))) = 1;
    }
}

/* extern */

s32 func_808007D4_cheggsplode(s32 arg0, s32 arg1) {
    s32 func_800F6478(s32);
    if (func_800F6478(arg1) == 0) {
        return 0;
    }
    return 1;
}
