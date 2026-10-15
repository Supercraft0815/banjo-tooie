#include "common.h"

void func_80800000_chnewfreezy()
{
    _sufreezy_entrypoint_1();
}

/* extern */

void func_80800020_chnewfreezy(void **arg0) {
    s32 func_800ADFE0(s16);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

/* extern */

void func_80800068_chnewfreezy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u32 func_8010A828(Actor*, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    func_8010A828(_subaddielink_entrypoint_4(func_80100094(arg0, 1U)), (u32) (*(u8 *)((s8 *)(arg0) + (0x79))) >> 4);
}

void func_808000AC_chnewfreezy(s32 arg0)
{
    _sufreezy_entrypoint_2();
    func_8010A570(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808000D4_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808002C0_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800824_chnewfreezy.s")

/* extern */

void func_80800974_chnewfreezy(Actor *arg0, u8 *arg1) {
    typedef struct { f32 m[4][4]; } MtxF;
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    u32 func_800ADE50(u8 *, u8 *, s32);
    s32 func_800AE080(s16);
    s32 func_800AE290(s16, s32, s32);
    s32 func_800DF324(void);
    void func_800F2C1C(MtxF *, f32 *);
    void mlMtxGet(void *);
    void mlMtxSet(void *);
    void mlMtxRotatePYR(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 temp_f8;
    s32 temp_s5;
    u32 var_s1;
    struct FreezyPartTransform {
        f32 position[3];
        f32 rotation[3];
        u8 pad18[0x48];
    } *var_s0;
    MtxF sp48;

    var_s0 = func_80100094(arg0, 0);
    func_800AE290(*(s16 *)&arg0->unk0->unk10, arg1, func_800DF324());
    temp_s5 = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            mlMtxSet(func_800ADE50(temp_s5, arg1, _dbskeleton_entrypoint_4(arg1, var_s1)));
            mlMtxRotatePYR(arg0->rotation[0], arg0->rotation[1], arg0->rotation[2]);
            mlMtxGet(&sp48);
            func_800F2C1C(&sp48, var_s0->rotation);
            var_s0->rotation[1] -= 90.0f;
            var_s0->rotation[2] = -var_s0->rotation[0];
            var_s0->rotation[0] = 0.0f;
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800AA4_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800BFC_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800D28_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800E74_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808011A8_chnewfreezy.s")

/* extern */

f32 func_808012F8_chnewfreezy(Actor *arg0) {
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct FreezyPart {
        f32 position[3];
        u8 pad0C[0x3C];
        f32 scale;
        u8 pad4C[0x10];
        s8 state;
        u8 pad5D[3];
    } *var_s0;
    f32 temp_f2;
    f32 var_f20;
    u32 var_s1;

    var_s0 = func_80100094(arg0, 0);
    var_f20 = 0.0f;
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            if (var_s0->state != 3) {
                temp_f2 = func_800EEAD4((f32 *)&arg0->actorData[4], var_s0->position) + (25.0f * var_s0->scale);
                if (var_f20 < temp_f2) {
                    var_f20 = temp_f2;
                }
            }
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
    return var_f20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/chnewfreezy_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808016B4_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808017FC_chnewfreezy.s")

OSThread *chnewfreezy_entrypoint_1(void)
{
    extern u8 D_80801978_chnewfreezy[];

    return (OSThread *) D_80801978_chnewfreezy;
}
