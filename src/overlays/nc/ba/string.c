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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/string/ncbastring_entrypoint_4.s")
