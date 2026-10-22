#include "common.h"

/* extern */

void func_80800000_chboggyfish(s32 *arg0, void *arg1) {
    s32 func_800D1844(s32);
    s32 func_800DA544(s32);
    s32 func_800F54E4();
    s32 func_800F6388(s32, s32);
    s32 func_800FC6B0(s32);
    s32 func_800FFA88(s32);
    if (((u32) (*(u32 *)((s8 *)(arg1) + (0x24))) >> 0x16) == 0) {
        func_800F6388(func_800F54E4(), 0x4BA);
        func_800D1844(0x51);
        func_800FC6B0(0xE);
        func_800DA544(0x438);
        func_800FFA88(*arg0);
    }
}

s32 func_80800064_chboggyfish(Actor *arg0, s32 arg1, void *volatile arg2) {
    u8 func_800D731C(s32);
    s32 func_800DA298(s32);
    s32 func_800DBE60(u8, s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    s32 _glcutDll_entrypoint_20();
    u8 index;
    s32 value;

    switch (arg1) {
        case 0x3E:
            func_80800000_chboggyfish((s32 *)arg0, arg2);
            break;
        case 0x1F:
            func_801015D0(arg0);
            if (index = func_800D731C(arg0->unk0->unk14)) {
                value = (s32)((f32 *)arg0->actorData)[4];
                func_800DBE60(index, 0, value);
                func_800DBE60(index, 1, value);
                func_800DBE60(index, 2, value);
                func_800DBE60(index, 3, value);
            }
            break;
        case 0x95:
            if (func_800DA298(0x438) && !_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 0;
            }
            ((f32 *)arg0->actorData)[4] = 0.0f;
            ((f32 *)arg0->actorData)[5] = 0.5f;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080018C_chboggyfish(void *arg0) {
    (*(f32 *)((s8 *)arg0 + 0x28)) += (*(f32 *)((s8 *)arg0 + 0x2C));
    if ((*(f32 *)((s8 *)(arg0) + (0x28))) <= 0.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (0.0f - (*(f32 *)((s8 *)arg0 + 0x2C)));
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x28))) >= 4.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x28))) = 4.0f;
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (0.0f - (*(f32 *)((s8 *)(arg0) + (0x2C))));
    }
}

OSThread *chboggyfish_entrypoint_0(void)
{
    extern u8 D_80800220_chboggyfish[];

    return (OSThread *) D_80800220_chboggyfish;
}
