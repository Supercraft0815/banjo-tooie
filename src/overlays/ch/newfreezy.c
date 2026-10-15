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

/* extern */

void func_80800BFC_chnewfreezy(Actor *arg0, u8 *arg1) {
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    s32 func_800AE080(s16);
    s32 func_800AE1E8(s16, s32, s32);
    s32 func_800AE630(u8 *, u8 *, s32, s32);
    s32 func_800DF324(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 temp_s4;
    u32 var_s1;
    struct FreezyPartPosition {
        f32 position[3];
        u8 pad0C[0x18];
        f32 previousPosition[3];
        u8 pad30[0x1C];
        f32 unk4C;
        u8 pad50[0x10];
    } *var_s0;

    var_s0 = func_80100094(arg0, 0);
    func_800AE1E8(*(s16 *)&arg0->unk0->unk10, arg1, func_800DF324());
    temp_s4 = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            func_800AE630(temp_s4, arg1, _dbskeleton_entrypoint_4(arg1, var_s1), var_s0);
            func_800EF334(var_s0->position, *(f32 *)&arg0->actorData[7]);
            func_800EF5A0(var_s0->position, arg0->rotation, var_s0->position[0], var_s0->position[1], var_s0->position[2]);
            func_800EF04C(var_s0->position, arg0->position);
            var_s0->unk4C = 0.0f;
            func_800EE7F8(var_s0->previousPosition, var_s0->position);
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800D28_chnewfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_80800E74_chnewfreezy.s")

void func_808011A8_chnewfreezy(f32 arg0, f32 arg1) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800D9470(f32[4], f32[4], f32[4]);
    s32 func_800DF324(void);
    void func_800DFB40(s32 *, s32, u8 *);
    void func_800DFF2C(u8 **, s32, f32[4]);
    struct Quaternion { f32 v[4]; };
    struct Vector { f32 v[3]; };
    extern struct Quaternion D_8080195C_chnewfreezy;
    extern struct Vector D_8080196C_chnewfreezy;
    struct Quaternion sp58;
    struct Vector sp4C;
    f32 sp3C[4];
    f32 sp2C[4];
    s32 sp28;


    sp58 = D_8080195C_chnewfreezy;
    sp4C = D_8080196C_chnewfreezy;
    sp28 = func_800DF324();
    func_800DFB40(sp28, 0x12, sp3C);
    sp4C.v[1] = arg0 * 0.75f;
    sp4C.v[0] = -arg1 * 0.9f;
    func_800D93A0(sp58.v, sp4C.v);
    func_800D9470(sp58.v, sp58.v, sp3C);
    func_800DFF2C(sp28, 0x12, sp58.v);
    func_800DFB40(sp28, 1, sp2C);
    sp4C.v[1] = arg0 * 0.25f;
    sp4C.v[0] = -arg1 * 0.1f;
    func_800D93A0(sp58.v, sp4C.v);
    func_800D9470(sp58.v, sp58.v, sp2C);
    func_800DFF2C(sp28, 1, sp58.v);
}

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

/* extern */

void func_808016B4_chnewfreezy(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF830(s32);
    s32 func_800E3E8C(f32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 models[4];
    u32 i;
    struct FreezyRenderPart {
        u8 pad00[0xC];
        f32 rotation[3];
        u8 pad18[0x24];
        f32 position[3];
        f32 pad48;
        f32 scale;
        u8 pad50[0xC];
        s8 state;
        s8 model;
        u8 pad5E[2];
    } *part;

    if (func_800E3E8C((f32 *)&arg0->actorData[4], arg0->unk74_7)) {
        part = func_80100094(arg0, 0);
        models[0] = func_800D674C(0x74C);
        models[1] = func_800D674C(0x74D);
        models[2] = func_800D674C(0x74E);
        i = 0;
        if (arg0->unk6C_0) {
            do {
                if (part->state != 3) {
                    if (_subaddiefade_entrypoint_0(arg0) < 0xFF) {
                        func_800DF410(_subaddiefade_entrypoint_0(arg0));
                    }
                    func_800DF830(2);
                    func_800DE448(part->position, part->rotation, part->scale, 0, models[part->model]);
                }
                i++;
                part++;
            } while (i < arg0->unk6C_0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808017FC_chnewfreezy.s")

OSThread *chnewfreezy_entrypoint_1(void)
{
    extern u8 D_80801978_chnewfreezy[];

    return (OSThread *) D_80801978_chnewfreezy;
}
