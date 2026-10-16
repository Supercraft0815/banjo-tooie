#include "core2/1E6B900.h"

s32 func_80092010(void)
{
	return 0x118;
}

/* extern */

void func_80092018(u8 *arg0) {
    void func_80019750(f32 *, f32 *, f32, f32 *);
    s32 func_80019CD4(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void mlMtxGet(void *);
    void mlMtxRotPitch(f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 var_f0;
    u8 *temp_s0;

    temp_s0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    if ((*(u8 *)((s8 *)(temp_s0) + (0xC4))) != 0) {
        var_f0 = (*(f32 *)((s8 *)(temp_s0) + (0xC8)));
    } else {
        var_f0 = (*(f32 *)((s8 *)(temp_s0) + (0x28)));
    }
    func_800EFA4C(sp34, *(f32 *)(temp_s0 + 0x20), var_f0, *(f32 *)(temp_s0 + 0x24));
    temp_s0 = *(u8 **)(arg0 + 0x50);
    func_800EE780(sp28, (f32 *)(temp_s0 + 0x2C), (f32 *)(temp_s0 + 0x44));
    func_80019CD4();
    temp_s0 = *(u8 **)(arg0 + 0x50);
    func_80019750((f32 *)(temp_s0 + 0x44), sp34, *(f32 *)(temp_s0 + 0x1C), sp28);
    temp_s0 = *(u8 **)(arg0 + 0x50);
    if (*(u8 *)(temp_s0 + 0xC4) != 0) {
        mlMtxRotPitch(*(f32 *)(temp_s0 + 0x28));
        temp_s0 = *(u8 **)(arg0 + 0x50);
    }
    mlMtxGet(temp_s0 + 0xCC);
}

void func_800920C8(void *arg0) {
    void func_80093504();
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    func_80093504(arg0, temp_v0 + 0x64, temp_v0 + 0x50);
}

void func_800920F0(PlayerState *arg0) {
    f32 yaw_get(PlayerState *);
    f32 func_800136E4(f32);
    u8 temp_v0;

    temp_v0 = (*(u8 **)((u8 *)arg0 + 0x50))[0x15];
    switch (temp_v0) {
        case 2:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28) = func_800136E4(yaw_get(arg0) + 180.0f);
            break;
        default:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28) = yaw_get(arg0);
            break;
        case 3:
            break;
    }
}

void func_8009216C(PlayerState *arg0, f32 arg1[3], f32 arg2[3]) {
    f32 baroll_get(PlayerState *);
    f32 func_8009BFCC(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u8 *temp_v0;

    func_800920F0(arg0);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x24) = baroll_get(arg0);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x20) = func_8009BFCC(arg0);
    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    func_800EFA4C(arg2, *(f32 *)(temp_v0 + 0x20), *(f32 *)(temp_v0 + 0x28), *(f32 *)(temp_v0 + 0x24));
    func_8009C128(arg0, arg1);
}

void func_800921E0(PlayerState *player, s32 id, f32 dst[3]) {
    void func_8009C2A0(void *, s32, f32 *);
    int func_800EEEA8(f32[3]);
    void func_8009C128(PlayerState *, f32[3]);
    func_8009C2A0((void *)((s32 **)player)[20][1], id, dst);
    if (func_800EEEA8(dst)) {
        func_8009C128(player, dst);
    }
}

void func_80092224(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x1A))) = 1;
}

void func_80092234(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x1A))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x16))) = 1;
}

s32 func_8009224C(u8 **arg0) {
    return arg0[20][26];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092258.s")

s32 func_8009239C(u8 **arg0) {
    return arg0[20][25];
}

/* extern */

void func_800923A8(void *arg0, s32 arg1) {
    s32 func_80092258();
    s32 func_800A2540(void *, s32);
    void func_800DF464(f32);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF738(s32);
    void func_800DF830(s32);
    u8 sp1F;
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = func_80092258();
    sp1F = temp_v0;
    func_800A2540(arg0, temp_v0);
    func_800DF464(2.0f);
    if (arg1 != 0) {
        temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x50)));
        if ((*(u8 *)((s8 *)(temp_v0_2) + (0x16))) == 0) {
            func_800DF738((*(s32 *)((s8 *)(temp_v0_2) + (4))));
        }
    }
    func_800DF830(1);
    temp_v0_3 = (*(void **)((s8 *)(arg0) + (0x50)));
    if ((*(u8 *)((s8 *)(temp_v0_3) + (0x88))) != 0) {
        func_800DF5D8((*(u8 *)((s8 *)(temp_v0_3) + (0x89))), (*(u8 *)((s8 *)(temp_v0_3) + (0x8A))), (*(u8 *)((s8 *)(temp_v0_3) + (0x8B))), sp1F);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092444.s")

void func_8009272C(s32 *arg0, s32 arg1) {
    ((u8 *)arg0[20])[17] = arg1;
}

u32 func_80092738(s32 *arg0) {
    return ((u8 *)arg0[20])[17];
}

void func_80092744(s32 *arg0, s32 arg1) {
    ((u8 *)arg0[20])[0x88] = arg1;
}

void func_80092750(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x89))) = arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x8A))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x8B))) = arg3;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x8C))) = (s8) arg4;
}

/* extern */

void func_80092778(PlayerState *arg0) {
    s32 _bapreload_entrypoint_0(PlayerState *, s32, s16 *, s16 *);
    s32 func_80092EC8(PlayerState *, s16);
    void func_8009312C(PlayerState *, s32);
    s32 func_800A3274();
    s16 sp1E;
    s16 sp1C;

    _bapreload_entrypoint_0(arg0, func_800A3274(), &sp1E, &sp1C);
    func_80092EC8(arg0, sp1E);
    func_8009312C(arg0, sp1C);
}

/* extern */

void func_800927C4(u32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    typedef struct {
        u32 *unk0;
        u32 *unk4;
        u32 *unk8;
        u32 unkC;
        u32 unk10;
        u16 unk14;
        u16 unk16;
        u32 unk18;
        u32 unk1C;
        u32 unk20;
        u32 unk24;
        u32 unk28;
        u32 unk2C;
    } Unk80132ED0;
    typedef struct Actor {
        Unk80132ED0 *unk0;
    } Actor;
    void func_800A70D0(Unk80132ED0 *, s32);
    void func_800A7108(Unk80132ED0 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F6BE4(s32);
    Actor *func_80108474(u32, f32 *, s32);
    struct unknown50_s {
        u8 pad0[0x78];
        f32 unk78;
        u8 pad7C[8];
        Unk80132ED0 *unk84;
    };
    f32 sp28[4];
    PlayerState *temp_s0;
    struct unknown50_s *temp_v0;

    if (func_800F6BE4(arg4) != 0) {
        temp_s0 = func_800F53D0(arg4);
        func_800EFA4C(sp28, arg1, arg2, arg3);
        (*(struct unknown50_s **)&temp_s0->pad48[8])->unk84 = func_80108474(arg0, sp28, 0)->unk0;
        func_800A70D0((*(struct unknown50_s **)&temp_s0->pad48[8])->unk84, temp_s0->unk184);
        temp_v0 = *(struct unknown50_s **)&temp_s0->pad48[8];
        func_800A7108(temp_v0->unk84, temp_v0->unk78);
    }
}

void func_80092864(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x78))) = arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x7C))) = 1;
}

void func_80092880(PlayerState *arg0, s32 arg1) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x80))) = (s8) arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x81))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092A1C.s")

void func_80092AA4(PlayerState* arg0)
{
    (*(s32 **)((u8 *)arg0 + 0x50))[0x21] = 0;
}

void func_80092AB0(PlayerState* arg0)
{
    func_800E0ACC(func_80092AD8(arg0));
}

/* extern */

Unkfunc_800E0960_1 *func_80092AD8(PlayerState *arg0) {
    s32 func_800AE080(s16);
    Unkfunc_800E0960_1 *func_800AE6BC(s32);
    return func_800AE6BC(func_800AE080(*(*(s16 **)((s8 *)(arg0) + (0x50)))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092B04.s")

s32 func_80092B80(PlayerState *arg0)
{
    return (*(s16 **)((u8 *)arg0 + 0x50))[6];
}

f32 func_80092B8C(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg1, (u8 *)(*(u32 *)((u8 *)arg0 + 0x50)) + 0x64);
    return *(f32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 0x50)) + 0x70);
}

u32 func_80092BC4(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x50))[0xC4];
}

f32 func_80092BD0(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC8);
}

f32 func_80092BDC(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x1C);
}

f32 func_80092BE8(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28);
}

f32 func_80092BF4(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x30);
}

void func_80092C00(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0, 0x1, arg1);
}

void func_80092C24(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0,0x2,arg1);
}

void func_80092C48(PlayerState* arg0,f32* arg1)
{
    func_800921E0(arg0,0x7,arg1);
}

void func_80092C6C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x6,arg1);
}

/* extern */

void func_80092C90(void *arg0, f32 arg1[3], s32 arg2) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800DBEFC(s32 *, s32, f32[3]);
    int func_800EEEA8(f32[3]);
    func_800DBEFC((*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
    if (func_800EEEA8(arg1) != 0) {
        func_8009C128(arg0, arg1);
    }
}

/* extern */

void func_80092CDC(void *arg0, f32 arg1[3], s32 arg2) {
    void func_800DBEFC(s32 *, s32, f32[3]);
    int func_800EEF24(f32[3]);
    func_800DBEFC((*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
    func_800EEF24(arg1);
}

void func_80092D18(void *arg0, s32 arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, *(u8 **)((u8 *)arg0 + 0x50) + 0x44);
}

void func_80092D44(PlayerState *player, f32 dst[3]) {
    void func_800921E0(PlayerState *, s32, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 tmp2[3];
    f32 tmp1[3];
    func_800921E0(player, 4, tmp1);
    func_800921E0(player, 3, tmp2);
    func_800EE780(dst, tmp1, tmp2);
    func_800EF334(dst, 0.5f);
}

void func_80092D9C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x3,arg1);
}

void func_80092DC0(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x4,arg1);
}

void func_80092DE4(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x8,arg1);
}

void func_80092E08(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x9,arg1);
}

void func_80092E2C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0xA,arg1);
}

u32 func_80092E50(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x15);
}

void func_80092E5C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x5,arg1);
}

/* extern */

void func_80092E80(void *arg0) {
    s32 func_800AE080(s16);
    func_800AE080(*(*(s16 **)((s8 *)(arg0) + (0x50))));
}

u32 func_80092EA4(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x17);
}

u32 func_80092EB0(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x18);
}

void func_80092EBC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 20) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093070.s")

void func_8009312C(PlayerState *arg0, s32 arg1) {
    s32 func_80093070(PlayerState *, s32, s16, u8 *);
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg1 != 0) {
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        if (arg1 != (*(s16 *)((s8 *)(temp_v0) + (0xE)))) {
            (*(s16 *)((s8 *)(temp_v0) + (0xE))) = arg1;
            temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
            func_80093070(arg0, arg1, (*(s16 *)((s8 *)(temp_v0) + (0xC))), temp_v0 + 0x12);
        }
    }
}

void func_8009316C(PlayerState *arg0, s32 arg1) {
    s32 func_80093070(PlayerState *, s32, s16, u8 *);
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg1 != 0) {
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        if (arg1 != (*(s16 *)((s8 *)(temp_v0) + (0x9E)))) {
            (*(s16 *)((s8 *)(temp_v0) + (0x9E))) = arg1;
            temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
            func_80093070(arg0, arg1, (*(s16 *)((s8 *)(temp_v0) + (0x9C))), temp_v0 + 0xA0);
        }
    }
}

/* extern */

void func_800931AC(PlayerState *arg0, s32 arg1) {
    f32 func_800136E4(f32);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 temp_v1;
    s32 temp_a0;
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    temp_a0 = 2;
    temp_v1 = (*(u8 *)((s8 *)(var_v0) + (0x15)));
    if ((arg1 != temp_v1) && ((arg1 == temp_a0) || (temp_a0 == temp_v1))) {
        yaw_setIdeal(arg0, func_800136E4(yaw_get(arg0) + 180.0f));
        yaw_applyIdeal(arg0);
        var_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    }
    (*(s8 *)((s8 *)(var_v0) + (0x15))) = (s8) arg1;
}

/* extern */

void func_80093230(PlayerState *arg0, f32 arg1) {
    void func_800EF334(f32 *, f32);
    u8 *temp_v0;

    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x1C))) = arg1;
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    (*(f32 *)((s8 *)(temp_v0) + (0x70))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x1C))) * (*(f32 *)((s8 *)(temp_v0) + (0x5C))));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    (*(f32 *)((s8 *)(temp_v0) + (0x74))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x1C))) * (*(f32 *)((s8 *)(temp_v0) + (0x60))));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    func_800EF334((f32 *)(temp_v0 + 0x64), (*(f32 *)((s8 *)(temp_v0) + (0x1C))));
}

/* extern */

void func_8009328C(PlayerState *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x28))) = func_800136E4(arg1);
}

void func_800932BC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 200) = arg1;
}

void func_800932CC(PlayerState *arg0, s32 arg1)
{
    u8 *temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);

    if (arg1 != temp_v0[0xC4]) {
        if (arg1 != 0) {
            *(f32 *)(temp_v0 + 0xC8) = 0.0f;
            temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
        }
        temp_v0[0xC4] = arg1;
    }
}

void func_80093300(void *arg0, f32 arg1) {
    void func_8009332C(void *arg0, f32 arg1);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30) = arg1;
    func_8009332C(arg0, arg1);
}

void func_8009332C(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 60) = arg1;
}

/* extern */

void func_8009333C(void *arg0) {
    void func_800EE7F8();
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x50))) + 0x44);
}

void func_80093360(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x48))) = arg1;
}

void func_80093370(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 23) = arg1;
}

void func_8009337C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 24) = arg1;
}

void func_80093388(void *arg0) {
    f32 mlAbsF(f32);
    extern f32 D_80124D40;
    f32 difference;
    f32 step;

    difference = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x3C)
               - *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30);
    step = mlAbsF(difference);
    if (step < D_80124D40) {
        *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x3C);
    } else {
        if (step > 5.0f) {
            step = 1.0f;
        }
        if (difference > 0.0f) {
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30) += step;
        } else {
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30) -= step;
        }
    }
}

void func_80093448(void *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    union {
        f32 f[3];
        s32 i[3];
    } position;

    if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x84) == 0) {
        func_8009C128(arg0, position.f);
        _chbaddiesetup_entrypoint_5(func_800927C4, 0x215,
            position.i[0], position.i[1], position.i[2],
            *(s32 *)((u8 *)arg0 + 0x184));
    }
    func_80093388(arg0);
    func_80092018(arg0);
    func_800920C8(arg0);
}

/* extern */

void func_800934C4(void *arg0) {
    s32 func_800DC060(s32);
    s32 temp;

    temp = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 4);
    if (temp != 0) {
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 4) = func_800DC060(temp);
    }
}

/* extern */

void func_80093504(void *arg0) {
    s32 func_800F23D0(s32);
    func_800F23D0((*(s32 *)((s8 *)(arg0) + (0x50))) + 0xCC);
}

/* extern */

void func_80093528(void *arg0) {
    s32 func_800DBEB0(s32, void *);
    u8 temp_v1;
    void *temp_v0;

    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x1A))) = 0;
    func_800DBEB0((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg0);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x16))) = 0;
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0xA5))) = 0U;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0xA5)));
    (*(u8 *)((s8 *)(temp_v0) + (0xA1))) = temp_v1;
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x10))) = temp_v1;
}

void func_80093584(void *arg0) {
    void *temp_v0;

    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x94))) = 0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    (*(s32 *)((s8 *)(temp_v0) + (8))) = (s32) (*(s32 *)((s8 *)(temp_v0) + (0x94)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_8009359C.s")

void func_800936CC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 162) = arg1;
}

void func_800936D8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 152) = arg1;
}

void func_800936E8(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 163) = arg1;
}

u32 func_800936F4(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 163);
}

void func_80093700(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 25) = arg1;
}

void func_8009370C(u8 *arg0) {
    s32 func_800AE080(s16);
    Unkfunc_800E0960_1 *func_800AE6BC(s32);
    func_800AE6BC(func_800AE080((*(s16 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x90)))));
}

/* extern */

void func_80093738(void *arg0) {
    s32 func_800D674C(s32);
    func_800D674C((*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x9C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_8009375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093AB8.s")

s32 func_80093DF4(void *arg0, s32 arg1) {
    return arg1 == (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0xA2))) ? 1 : 0;
}

/* extern */

void func_80093E18(u8 *arg0, Gfx **arg1) {
    s32 pad;
    s32 _bsfirstp_entrypoint_0(u8 *, u8 *, u8 *);
    void _bsfirstp_entrypoint_1(u8 *, s32);
    s32 func_8009375C(u8 *, Gfx **, s32);
    s32 func_80093864(u8 *, Gfx **, s32);
    s32 func_800A5090(void *);
    s32 func_800A88C4(s32, s32);
    s32 func_800A89F8();
    void func_800E44FC(Gfx **);
    s32 sp28;
    s32 sp24;
    u8 *temp_v0;

    sp24 = func_800A89F8();
    sp28 = func_800A88C4(sp24, func_800A5090(arg0));
    func_800E44FC(arg1);
    if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0xA1))) == 0) {
        _bsfirstp_entrypoint_1(arg0, 1);
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        _bsfirstp_entrypoint_0(arg0, temp_v0 + 0xAC, temp_v0 + 0xB8);
        func_8009375C(arg0, arg1, 1);
    }
    func_80093864(arg0, arg1, 1);
    func_800A88C4(sp24, sp28);
    func_800E44FC(arg1);
}

/* extern */

f32 func_80093ECC(u8 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32[3], f32[3]);
    void func_8009216C(PlayerState *, f32 *, f32 *);
    u8 *self = arg0;
    func_8009216C(self, arg1, arg2);
    func_800EE7F8(arg3, (f32 *)(*(u8 **)(self + 0x50) + 0x2C));
    func_800EF04C(arg1, (f32 *)(*(u8 **)(self + 0x50) + 0x44));
    func_800EF04C(arg3, (f32 *)(*(u8 **)(self + 0x50) + 0x44));
    return *(f32 *)(*(u8 **)(self + 0x50) + 0x1C);
}

s32 func_80093F30(s32 arg0) {
    s32 func_8009EA2C(void);
    extern s32 D_80117DD8[][4];
    extern s32 D_80117DDC[][4];
    if (func_8009EA2C() != 0) {
        return D_80117DDC[arg0][0];
    }
    return D_80117DD8[arg0][0];
}

/* extern */

s32 func_80093F7C(u8 *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    s32 func_800D62E4(s32);
    struct { s32 pad; s32 value; } sp1C;
    s32 var_v1;

    sp1C.value = func_800D674C((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x10C))));
    var_v1 = sp1C.value;
    if (arg1 == 0) {
        func_800D62E4((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x10C))));
        var_v1 = sp1C.value;
    }
    return var_v1;
}

void func_80093FD4(s32 arg0, s32 arg1) {
    s32 func_800941C8(s32, s32);
    s32 func_800EA05C();
    extern s16 D_80117DF0[][2];
    s32 temp_v0;
    s32 var_a1;

    if (arg1 == 0x607) {
        temp_v0 = func_800EA05C();
        for (var_a1 = 0; D_80117DF0[var_a1][0] != -1; var_a1++) {
            if (temp_v0 == D_80117DF0[var_a1][0]) {
                break;
            }
        }
        func_800941C8(arg0, func_80093F30(D_80117DF0[var_a1][1]));
        return;
    }
    func_800941C8(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800941C8.s")

s32 func_800942D0(u8 *arg0, s32 arg1) {
    s32 func_8001BDAC(s32 *, s32);
    extern s32 D_80117DD4[][4];
    s32 sp1C;

    func_8001BDAC(&sp1C, 1);
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x110))) != 0) {
        sp1C += D_80117DD4[arg1][0];
    }
    return sp1C >= 0x32001;
}

s32 func_80094340(void)
{
	return 0x4;
}

s32 func_80094348(void *arg0, s32 arg1) {
    return ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (2))) & arg1) ? 1 : 0;
}

void func_80094370(s32 arg0)
{
    func_800946C4(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094430.s")

s32 func_800944E0(PlayerState *arg0, s32 arg1) {
    extern u8 D_80117E3C[];
    return D_80117E3C[arg1 * 2];
}

s32 func_800944F8(PlayerState *arg0, s32 arg1) {
    extern u8 D_80117E3D[];
    return D_80117E3D[arg1 * 2];
}

s32 func_80094510(PlayerState *arg0) {
    extern u8 *D_80117E30[];
    u8 *p = *(u8 **)((u8 *)arg0 + 0x64);
    return *(p[1] + D_80117E30[p[0]]);
}

/* extern */

void func_80094538(PlayerState *arg0) {
    f32 _batimer_get(PlayerState *, s32);
    s32 func_8009E9E4(s32);
    s32 func_8009E9F0(f32);
    func_8009E9E4(func_80094510(arg0));
    func_8009E9F0(_batimer_get(arg0, 0xD));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094574.s")

/* extern */

void func_80094644(void *arg0) {
    s32 func_80094430(void *, f32);
    s32 func_80094574(void *, s32);
    s32 func_8009E964();
    f32 func_8009E970();
    s32 temp_f4;

    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (2))) = 0;
    func_80094370((s32) arg0);
    func_80094574(arg0, func_8009E964());
    temp_f4 = (s32) func_8009E970();
    if (temp_f4 != 0) {
        func_80094430(arg0, (f32) temp_f4);
    }
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (3))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800946C4.s")

void func_800947EC(PlayerState *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x64)));
        (*(u8 *)((s8 *)(temp_v0) + (2))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (2))) | arg1);
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x64)));
    (*(u8 *)((s8 *)(temp_v0_2) + (2))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (2))) & ~arg1);
}

/* extern */

void func_80094824(PlayerState *arg0) {
    s32 bainput_func_80097C7C();
    s32 func_80094A10(PlayerState *);
    void func_80094C88(void *);
    void func_80094D04(void *);
    if (bainput_func_80097C7C() != 0) {
        func_80094A10(arg0);
        func_80094C88(arg0);
    }
    func_80094D04(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094864.s")

/* extern */

int func_800949BC(PlayerState *arg0) {
    s32 func_8009E674(PlayerState *, s32);
    s32 _baeggfire_entrypoint_8(PlayerState *);
    s32 _bafpctrl_entrypoint_5(PlayerState *);
    s32 temp_t6;
    s32 temp_t7;
    s32 var_v0;

    return func_8009E674(arg0, 0x80000) != 0 ||
           (_bafpctrl_entrypoint_5(arg0) != 0 && _baeggfire_entrypoint_8(arg0) != 0);
}

s32 func_80094A10(PlayerState *arg0) {
    s32 _gcegg_entrypoint_6(s32);
    void func_80094E40(s32);
    s32 result;
    s32 previous;
    s32 current;
    u8 *state;

    previous = func_80094510(arg0);
    if (func_800949BC(arg0) != 0) {
        return previous;
    }
    do {
        state = *(u8 **)((u8 *)arg0 + 0x64);
        state[1]++;
        result = func_80094510(arg0);
        current = result;
        if (result == 0) {
            (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
            current = func_80094510(arg0);
        }
    } while (_gcegg_entrypoint_6(current) == 0);
    if (current != previous) {
        func_80094E40(current);
    }
    return current;
}

/* extern */

void func_80094AB4(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    u8 func_80094C64(void *, s32);
    void func_800D1824(s32);
    s32 temp_v0;
    s32 sp1C;

    if (func_80094348(arg0, 2) == 0) {
        temp_v0 = func_80094C64(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (1))));
        if (temp_v0 != 0) {
            sp1C = temp_v0;
            if (_gcegg_entrypoint_6(temp_v0) != 0) {
                func_800D1824(_gcegg_entrypoint_5(sp1C));
            }
        }
    }
}

s32 func_80094B14(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _plsu_entrypoint_1(s32);
    int baflag_isTrue(PlayerState *, s32);
    void func_800D1824(s32);
    s32 func_800D1C38(s32);
    void func_800FC660(u32);
    s32 sp1C;

    sp1C = _gcegg_entrypoint_5(func_80094510(arg0));
    if ((baflag_isTrue(arg0, 0x34) != 0) ||
        ((func_80094348(arg0, 4) == 0) && (func_800D1C38(sp1C) != 0))) {
        func_800D1824(sp1C);
        func_800FC660(0xF);
        return 0;
    }
    if ((func_80094510(arg0) == 5) && (_plsu_entrypoint_1(0x11) != -1)) {
        return 0;
    }
    return 1;
}

/* extern */

s32 func_80094BC0(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    if (func_80094348(arg0, 4) != 0) {
        return 1;
    }
    return func_800D1A04(_gcegg_entrypoint_5(func_80094510(arg0)));
}

/* extern */

void func_80094C0C(PlayerState *arg0, s32 arg1) {
    s32 _gcegg_entrypoint_5(s32);
    s32 func_8009EA2C(void);
    void func_800D1804(s32);
    if ((func_80094348(arg0, 4) == 0) && ((arg1 != 2) || (func_8009EA2C() == 0))) {
        func_800D1804(_gcegg_entrypoint_5(arg1));
    }
}

u8 func_80094C64(void *arg0, s32 arg1) {
    extern u8 *D_80117E30[];
    return D_80117E30[**(u8 **)((u8 *)arg0 + 0x64)][arg1];
}

void func_80094C88(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    void func_800D1824(s32);
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if (_gcegg_entrypoint_6(var_s0) != 0) {
                func_800D1824(_gcegg_entrypoint_5(var_s0));
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
}

void func_80094D04(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    s32 func_800D1C5C(u32);
    s32 func_800D27C8(s32);
    void func_800FAA34(s32);
    s32 temp_v0_3;
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if ((var_s1 != (*(u8 **)((u8 *)arg0 + 0x64))[1]) && (_gcegg_entrypoint_6(var_s0) != 0)) {
                temp_v0_3 = func_800D27C8(func_800D1C5C(_gcegg_entrypoint_5(var_s0)));
                if (temp_v0_3 >= 0) {
                    func_800FAA34(temp_v0_3);
                }
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
}

s32 func_80094DA8(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    s32 func_800D1C5C(u32);
    int func_800D27F4(s32);
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if ((_gcegg_entrypoint_6(var_s0) != 0) && (func_800D27F4(func_800D1C5C(_gcegg_entrypoint_5(var_s0))) == 0)) {
                return 0;
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
    return 1;
}

/* extern */

void func_80094E40(s32 arg0) {
    s32 _gcegg_entrypoint_2(s32);
    void func_800FC660(u32);
    func_800FC660(_gcegg_entrypoint_2(arg0));
}
