#include "common.h"

void func_80800000_chskeletonexplode(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    arg0->unk58 = 0.0f;
    *temp_v0 = 0.0f;
}

/* extern */

void func_80800034_chskeletonexplode(void **arg0) {
    s32 func_800ADFE0(s16);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_8080007C_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808001BC_chskeletonexplode.s")

/* extern */

void func_808004DC_chskeletonexplode(Actor *arg0, Actor *arg1, u16 arg2, s32 arg3) {
    s32 func_80103140(Actor *, u32, u16);
    struct SkeletonExplodeFlags {
        u8 pad[0x74];
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
        u32 pad78_14 : 18;
        u32 unk7A_13 : 2;
        u32 unk7A_11 : 3;
        u32 pad7A_8 : 9;
    };
    struct SkeletonExplodeFlags *dst = (void *)arg0;
    struct SkeletonExplodeFlags *src = (void *)arg1;

    arg0->rotation[0] = arg1->rotation[0];
    arg0->rotation[2] = arg1->rotation[2];
    arg0->rotation[1] = arg1->rotation[1];
    arg0->scale = arg1->scale;
    func_80103140(arg0, arg2, arg3);
    dst->unk74_0 = src->unk74_0;
    dst->unk7A_11 = src->unk7A_11;
    dst->unk7A_13 = src->unk7A_13;
}

void func_80800594_chskeletonexplode(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 800.0f;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1000.0f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = -2000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808005CC_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_80800894_chskeletonexplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_0.s")

void chskeletonexplode_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg2;
}

void chskeletonexplode_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

void chskeletonexplode_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    (*(s32 *)((s8 *)((temp_v0 + (arg1 * 4))) + (4))) = arg2;
    if ((*(s32 *)((s8 *)(temp_v0) + (4))) < arg1) {
        (*(s32 *)((s8 *)(temp_v0) + (4))) = arg1;
    }
}

void chskeletonexplode_entrypoint_4(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF4))) = (s8) arg1;
}

void chskeletonexplode_entrypoint_5(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF5))) = (s8) arg1;
}

void chskeletonexplode_entrypoint_6(s32 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[3];
    func_800EE904(sp, arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, *arg0, sp[0], sp[1], sp[2], arg2, arg3);
}

void chskeletonexplode_entrypoint_7(Actor *arg0, f32 *arg1) {
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[5];

    sp[1] = arg0->unk0->unk14;
    sp[0] = arg0->unk0->unk16;
    func_800EE904(&sp[2], arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (s32) arg0->unk0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

void chskeletonexplode_entrypoint_8(Actor **arg0, s16 *arg1) {
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[5];

    sp[1] = ((u16 *)&(*arg0)->unk14)[0];
    sp[0] = ((u16 *)&(*arg0)->unk14)[1];
    sp[2] = arg1[0];
    sp[3] = arg1[1];
    sp[4] = arg1[2];
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (s32) *arg0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_80800E88_chskeletonexplode.s")

/* extern */

s32 func_8080100C_chskeletonexplode(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800E88_chskeletonexplode();
    switch (arg1) {
    case 0x1F:
        func_80800E88_chskeletonexplode(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chskeletonexplode_entrypoint_9(void)
{
    extern u8 D_80801138_chskeletonexplode[];

    return (OSThread *) D_80801138_chskeletonexplode;
}
