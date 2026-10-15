#include "common.h"

void func_80800000_chjadesnake(Actor *arg0) {
    void func_8010A85C(u8 *, s32);
    func_8010A85C((u8 *) arg0, 2);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 9);
        func_8010A85C((u8 *) arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800048_chjadesnake.s")

/* extern */

int func_8080009C_chjadesnake(s32 arg0) {
    s32 pad;
    u32 func_800F54E4(void);
    s32 func_800F56AC(s32);
    s32 func_800F6478(s32);
    s32 func_800F651C(s32);
    s32 func_800F6C5C(s32);
    int func_800F72DC(s32);
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_t8;
    s32 temp_t9;
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_800F54E4();
    sp30 = func_800F651C(temp_v0);
    sp2C = func_800F6C5C(temp_v0);
    sp28 = func_800F72DC(temp_v0);
    sp24 = func_800F56AC(temp_v0) == 0x10;
    var_v0 = func_800F6478(temp_v0);
    if (sp24 == 0) {
        return 0;
    }
    return var_v0 && (sp28 || (sp2C && !sp30));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800150_chjadesnake.s")

void func_80800728_chjadesnake(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0xF3C) {
        if (arg1 == 0xF3D) {
            func_80102424(arg0, 8);
        }
    } else {
        func_80102424(arg0, 6);
    }
}

void func_80800770_chjadesnake(Actor *arg0, u8 *arg1) {
    s32 func_800DBEFC(s32, s32, s32);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (((struct { u32 unused : 19; u32 active : 1; u32 rest : 12; } *)((u8 *)arg0 + 0x7C))->active) {
        func_800DBEFC(func_80104130(), 4, (s32) arg0->actorData);
        func_800DBEFC(func_80104130(), 5, (s32) &arg0->actorData[4]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_808007DC_chjadesnake.s")

OSThread *chjadesnake_entrypoint_0(void)
{
    extern u8 D_808009F4_chjadesnake[];

    return (OSThread *) D_808009F4_chjadesnake;
}
