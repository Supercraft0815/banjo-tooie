#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800000_chfactorysparkroom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_8080013C_chfactorysparkroom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_808005E0_chfactorysparkroom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_808006D0_chfactorysparkroom.s")

void func_808007E0_chfactorysparkroom(Actor *arg0) {
    void func_800C8B84(volatile s32);
    void* func_80100094(Actor*, u32);
    s32 var_s1;
    u8 *var_s0;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s1 = 0;
    var_s0 = temp_v0;
    do {
        func_800C8B84((*(s32 *)((s8 *)(var_s0) + (0x200))));
        var_s1 += 1;
        var_s0 += 4;
        (*(s32 *)((s8 *)(var_s0) + (0x1FC))) = 0;
    } while (var_s1 != 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800838_chfactorysparkroom.s")

/* extern */

void func_80800B60_chfactorysparkroom(Actor *arg0, s32 arg1) {
    void func_800C8B84(volatile s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    struct Spark {
        f32 values[7];
        s32 handle;
    };
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    ((struct Spark *)(sp1C + (arg1 << 5)))->values[0] = func_800DC178(1.0f, 3.0f);
    ((struct Spark *)(sp1C + (arg1 << 5)))->values[1] = 0.0f;
    func_800C8B84(((struct Spark *)(sp1C + (arg1 << 5)))->handle);
    ((struct Spark *)(sp1C + (arg1 << 5)))->handle = 0;
    arg0->actorData[7]--;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800BE0_chfactorysparkroom.s")

/* extern */

void func_80800D30_chfactorysparkroom(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_3(u8);
    u32 var_s0;

    var_s0 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        do {
            _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x50))));
            var_s0 += 1;
            (*(u8 *)((s8 *)(arg0) + (0x50))) = 0U;
        } while (var_s0 < (u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF));
    }
}

u32 func_80800D90_chfactorysparkroom(s32 unused, s32 arg1, s32 arg2) {
    void func_80800DC8_chfactorysparkroom(Actor *);

    if (arg1 == 0x95) {
        func_80800DC8_chfactorysparkroom((Actor *) unused);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800DC8_chfactorysparkroom.s")

OSThread *chfactorysparkroom_entrypoint_0(void)
{
    extern u8 D_80801108_chfactorysparkroom[];

    return (OSThread *) D_80801108_chfactorysparkroom;
}

/* extern */

void func_80800E94_chfactorysparkroom(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _subaddiefade_entrypoint_14();
    s32 func_8010A63C(s32);
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
    _chswitch_entrypoint_7(arg0, 0xA2F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800EC8_chfactorysparkroom.s")

OSThread *chfactorysparkroom_entrypoint_1(void)
{
    extern u8 D_8080115C_chfactorysparkroom[];

    return (OSThread *) D_8080115C_chfactorysparkroom;
}
