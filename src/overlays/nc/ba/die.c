#include "nc/ba/die.h"

s32 ncbadie_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbadie(PlayerState *arg0, f32 *arg1) { func_80112524(arg0, arg1); arg1[1] = *(f32 *)*(void **)((s8 *)arg0 + 0x10) + arg1[1]; }

void func_80800048_ncbadie(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbadie_entrypoint_1(void *arg0) {
    void ncbadie_entrypoint_3(void *, f32);
    void func_80111B8C(s32 *, f32, f32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    void func_801124D0(s32, s32);
    ncbadie_entrypoint_3(arg0, 30.0f);
    func_80111B8C(arg0, 1.4f, 14.0f);
    func_80115858(arg0, 0);
    func_80115870(arg0, 5.0f);
    func_801124D0((s32) arg0, 4);
}

void ncbadie_entrypoint_2(s32 arg0) 
{
}
void ncbadie_entrypoint_3(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 16) + 0) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/die/ncbadie_entrypoint_4.s")
