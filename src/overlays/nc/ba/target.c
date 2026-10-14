#include "nc/ba/target.h"

s32 ncbatarget_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void func_80800008_ncbatarget(PlayerState *arg0, f32 *arg1) {
    s32 func_800EF174(f32 *, s32 *, s32);
    s32 func_800EFB24(s32 *, void *, f32 *);
    s32 sp1C[3];

    func_80112524(arg0, arg1);
    func_800EFB24(sp1C, (*(void **)((s8 *)(arg0) + (0x58))), arg1);
    func_800EF174(arg1, sp1C, (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x58)))) + (0xC))));
}

void func_80800058_ncbatarget(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbatarget_entrypoint_1(void *arg0) {
    void func_800EFD24(f32 *);
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    void func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    void func_8011607C(void *, s32);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0((s32) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_800EFD24((*(void **)((s8 *)(arg0) + (0x58))));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x58)))) + (0xC))) = 0.5f;
    func_8011607C(arg0, 1);
}

void ncbatarget_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/target/ncbatarget_entrypoint_3.s")

void ncbatarget_entrypoint_4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 12) = arg1;
}

/* extern */

void ncbatarget_entrypoint_5(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))));
}
