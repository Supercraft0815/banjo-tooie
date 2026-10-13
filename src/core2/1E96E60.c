#include "common.h"

extern s32 D_80128410;
extern s32 D_80128434;

void func_800BD570()
{
    _gccubeDll_entrypoint_1(&D_80128410);
}

/* extern */

void func_800BD594(s32 arg0) {
    s32 func_800D3104(s32, s32 *);
    s32 func_800EA068(s32);
    s32 func_8010A874(s32);
    if (func_800EA068(0x200) != 0) {
        func_8010A874(arg0);
        return;
    }
    func_800D3104(arg0, &D_80128410);
}

void func_800BD5DC()
{
    _gccubeDll_entrypoint_2(&D_80128410);
}

void func_800BD600(void) {
    s32 defrag(s32);
    s32 func_800D2EE4();
    s32 func_800E9DF8();
    extern s32 D_80128454;
    (*(s32 *)((s8 *)(&D_80128410) + (0))) = defrag((*(s32 *)((s8 *)(&D_80128410) + (0))));
    D_80128454 = defrag((*(s32 *)((s8 *)(&D_80128410) + (0x44))));
    func_800E9DF8();
    func_800D2EE4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD860.s")

s32 func_800BD948(s32 arg0) {
    s32 base = (s32)&D_80128410;
    s32 result;
    if (arg0 == base + 0x34) {
        result = -1;
    } else {
        result = (arg0 - *(s32 *)base) >> 3;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BD97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDAD4.s")

s32 func_800BDB9C(s32 arg0) {
    extern u8 D_80128444;
    s32 result;
    if (arg0 < 0) {
        result = (s32)&D_80128444;
    } else {
        result = arg0 * 8 + D_80128410;
    }
    return result;
}

s32 func_800BDBC4(s32 arg0)
{
    return func_800BDB9C(func_800BD97C(arg0));
}

void func_800BDBEC(f32 *arg0) {
    s32 pos[3];
    pos[0] = (s32)arg0[0];
    pos[1] = (s32)arg0[1];
    pos[2] = (s32)arg0[2];
    func_800BDBC4((s32)pos);
}

void * func_800BDC44(void) {
    extern u8 D_80128444;
    return &D_80128444;
}

s32 func_800BDC50()
{
    return D_80128434;
}

s32 func_800BDC5C(void) {
    extern s16 D_8012844C;
    return *(s16 *)((u8 *)&D_8012844C + 0);
}

/* extern */

void func_800BDC68(s32 arg0) {
    s32 _gccubeDll_entrypoint_3(s32 *, s32);
    _gccubeDll_entrypoint_3(&D_80128410, arg0);
}

/* extern */

void func_800BDC90(s32 arg0) {
    s32 _gccubeDll_entrypoint_4(s32 *, s32);
    _gccubeDll_entrypoint_4(&D_80128410, arg0);
}

void func_800BDCB8()
{
    _gccubeDll_entrypoint_0(&D_80128410);
}

void func_800BDCDC()
{
    _gccubeDll_entrypoint_5(&D_80128410);
}

void func_800BDD00()
{
    _gccubeDll_entrypoint_6(&D_80128410);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BDD24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE09C.s")

s32 *func_800BE3F8(u8 *arg0) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    s32 func_800BE09C(s32 *, s32 *);
    extern s32 D_801284C8;
    s32 sp1C[3];

    func_800EE904(sp1C, (f32 *) arg0);
    (&D_801284C8)[func_800BE09C(&D_801284C8, sp1C)] = 0;
    return &D_801284C8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE444.s")

/* extern */

s32 func_800BE4C4(void) {
    extern u8 D_80128444;
    s32 func_800E9CF4(u8 *);
    u8 *var_s0;
    u8 *temp_s1;

    temp_s1 = *(u8 **)&D_80128410 + (*(s32 *)((s8 *)&D_80128410 + 0x24)) * 8;
    var_s0 = *(u8 **)&D_80128410;
    for (; var_s0 < temp_s1; var_s0 += 8) {
        func_800E9CF4(var_s0);
    }
    return func_800E9CF4(&D_80128444);
}

void func_800BE52C(s32 *arg0, s32 *arg1) {
    *arg0 = (*(s32 *)((s8 *)(&D_80128410) + (0)));
    *arg1 = (*(s32 *)((s8 *)(&D_80128410) + (0))) + ((*(s32 *)((s8 *)(&D_80128410) + (0x24))) << 3);
}

void func_800BE554(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128414;
    extern s32 D_80128420;
    func_800EE830(arg0, &D_80128414);
    func_800EE830(arg1, &D_80128420);
}

void func_800BE58C(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128438;
    extern s32 D_8012842C;
    func_800EE830(arg0, &D_80128438);
    func_800EE830(arg1, &D_8012842C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E96E60/func_800BE5C4.s")
