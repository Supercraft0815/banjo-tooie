#include "core2/1E6B900.h"

s32 func_80092010(void)
{
	return 0x118;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092018.s")

void func_800920C8(void *arg0) {
    void func_80093504();
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    func_80093504(arg0, temp_v0 + 0x64, temp_v0 + 0x50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800920F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_8009216C.s")

void func_800921E0(PlayerState *player, s32 id, f32 dst[3]) {
    void func_8009C2A0(void *, s32, f32 *);
    s32 func_800EEEA8(s32);
    s32 func_8009C128(void *, s32);
    func_8009C2A0((void *)((s32 **)player)[20][1], id, dst);
    if (func_800EEEA8((s32)dst)) {
        func_8009C128(player, (s32)dst);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800923A8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800927C4.s")

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

f32 func_80092B8C(PlayerState *arg0, s32 arg1) {
    void func_800EE7F8();
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

void func_80092C90(void *arg0, s32 arg1, s32 arg2) {
    s32 func_8009C128(void *, s32);
    s32 func_800DBEFC(s32, s32, s32);
    s32 func_800EEEA8(s32);
    func_800DBEFC((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
    if (func_800EEEA8(arg1) != 0) {
        func_8009C128(arg0, arg1);
    }
}

/* extern */

void func_80092CDC(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800DBEFC(s32, s32, s32);
    s32 func_800EEF24(s32);
    func_800DBEFC((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800931AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093230.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093448.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093E18.s")

/* extern */

f32 func_80093ECC(u8 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32[3], f32[3]);
    s32 func_8009216C(u8 *, f32 *, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093FD4.s")

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

void func_80094824(s32 arg0) {
    s32 bainput_func_80097C7C();
    s32 func_80094A10(s32);
    s32 func_80094C88(s32);
    s32 func_80094D04(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094B14.s")

/* extern */

s32 func_80094BC0(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    if (func_80094348(arg0, 4) != 0) {
        return 1;
    }
    return func_800D1A04(_gcegg_entrypoint_5(func_80094510(arg0)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094C0C.s")

u8 func_80094C64(void *arg0, s32 arg1) {
    extern u8 *D_80117E30[];
    return D_80117E30[**(u8 **)((u8 *)arg0 + 0x64)][arg1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094DA8.s")

/* extern */

void func_80094E40(void) {
    s32 _gcegg_entrypoint_2();
    s32 func_800FC660(s32);
    func_800FC660(_gcegg_entrypoint_2());
}
