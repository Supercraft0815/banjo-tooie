#include "nc/ba/string.h"

s32 ncbastring_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbastring_entrypoint_1(s32 arg0) {
    void func_80111B8C(s32 *, f32, f32);
    s32 func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C((s32 *) arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858((void *) arg0, 1);
    func_80115870((void *) arg0, 5.0f);
}

void ncbastring_entrypoint_2(s32 arg0) 
{
}
void func_8080007C_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/string/ncbastring_entrypoint_3.s")

/* extern */

void ncbastring_entrypoint_4(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_801107F0(void *, f32 *);
    void func_80115444(void *, f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    f32 temp_f0;
    void *temp_v0;

    func_8080007C_ncbastring(arg0, sp4C);
    func_801107F0(arg0, sp40);
    func_800EFB24(sp34, sp40, sp4C);
    temp_f0 = func_800EEF94(sp34);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))) = temp_f0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0))) = temp_f0;
    func_80115444(arg0, &sp30, &sp2C);
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    if ((*(f32 *)((s8 *)(temp_v0) + (0))) < sp30) {
        (*(s8 *)((s8 *)(temp_v0) + (8))) = 1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))) = sp2C;
        return;
    }
    if (sp2C < (*(f32 *)((s8 *)(temp_v0) + (4)))) {
        (*(s8 *)((s8 *)(temp_v0) + (8))) = 1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0))) = sp30;
        return;
    }
    (*(s8 *)((s8 *)(temp_v0) + (8))) = 0;
}
