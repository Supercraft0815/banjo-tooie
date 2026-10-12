#include "common.h"

/* extern */

void subaddieDll_entrypoint_0(void *arg0) {
    void func_80103014(u8 *);
    u32 func_8010A654(void ***, s32);
    u32 func_8010A698(void ***);
    s32 sp1C;
    struct Flags {
        u8 pad[0x10];
        u32 upper : 31;
        u32 enabled : 1;
    } *flags;

    if (!(((Actor *)arg0)->unk0->unk10 & 1)) {
        sp1C = func_8010A698(arg0);
        flags = (void *)((Actor *)arg0)->unk0;
        flags->enabled = 1;
        func_80103014(arg0);
        func_8010A654(arg0, sp1C);
    }
}

/* extern */

void subaddieDll_entrypoint_1(s32 arg0) {
    s32 subaddieDll_entrypoint_2(s32, s32);
    subaddieDll_entrypoint_2(arg0, arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_3.s")

/* extern */

void subaddieDll_entrypoint_4(void *arg0, s32 arg1) {
    void *func_80100368();
    if (arg1 != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x7C))) = 0U;
        return;
    }
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) (*(u16 *)((s8 *)(func_80100368()) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/func_80800260_subaddieDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_6.s")

void subaddieDll_entrypoint_7()
{
    func_80800260_subaddieDll();
}

s32 subaddieDll_entrypoint_8(s32 arg0) {
    Actor* func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor*);
    Actor *volatile sp1C;
    Actor *temp_v0;

    temp_v0 = func_80106790((Unk80132ED0 *) arg0);
    sp1C = temp_v0;
    func_8010A570(temp_v0);
    return (s32) sp1C;
}

/* extern */

void subaddieDll_entrypoint_9(s32 arg0, s32 arg1) {
    s32 func_800DA544(s32);
    s32 subaddieDll_entrypoint_8(s32);
    func_800DA544(arg1);
    subaddieDll_entrypoint_8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_11.s")

/* extern */

void subaddieDll_entrypoint_12(void *arg0, void *arg1) {
    s16 func_800DC128(s16, s16, void *);
    (*(s16 *)((s8 *)(arg1) + (0))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (0))), (*(s16 *)((s8 *)(arg0) + (4))), arg0);
    (*(s16 *)((s8 *)(arg1) + (2))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (2))), (*(s16 *)((s8 *)(arg0) + (6))), arg0);
}
