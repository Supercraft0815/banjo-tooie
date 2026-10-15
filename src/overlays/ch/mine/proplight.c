#include "common.h"

OSThread *chmineproplight_entrypoint_0(void)
{
    extern u8 D_80800240_chmineproplight[];

    return (OSThread *) D_80800240_chmineproplight;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/proplight/func_8080000C_chmineproplight.s")

void func_80800168_chmineproplight(Actor *arg0, void *arg1) {
    s32 func_800D674C(s32);
    u8 func_800D731C(u16);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_800DF7E8(u8);
    void func_800DF830(s32);
    s32 func_800EB854(void);
    void func_80101870(Actor *, void *);
    switch (func_800EB854()) {
        case 2:
            func_800DF830(1);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x695));
            func_800DF7E8(func_800D731C(0x696));
            func_800DF830(1);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x696));
            break;
        case 0:
            func_80101870(arg0, arg1);
            break;
    }
}

void func_80800228_chmineproplight(s32 arg0) 
{
}
