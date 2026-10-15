#include "common.h"

void func_800B9990(Gfx **arg0) {
    void func_800D2CC4(void);
    extern u8 D_8011A6E0[];
    gSPDisplayList((*arg0)++, D_8011A6E0 - 0x80000000);
    func_800D2CC4();
}

void func_800B9A24(Gfx **arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_800B99CC(Gfx **arg0, s32 arg1, s32 *arg2) {
    s32 sp[4];

    func_800E7FCC(sp);
    func_800B9A24(arg0, arg1, arg2, sp[0], sp[1], sp[2], sp[3]);
}

void func_800B9A24(Gfx **arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void func_800D2CC4(void);
    extern u8 D_8011A6E0[];
    gSPDisplayList((*arg0)++, D_8011A6E0 - 0x80000000);
    gDPSetFogColor((*arg0)++, arg2[0], arg2[1], arg2[2], arg1);
    gSPTextureRectangle((*arg0)++, arg3 * 4, arg4 * 4,
                        (arg3 + arg5) * 4, (arg4 + arg6) * 4,
                        0, 0, 0, 0x100, 0x100);
    func_800D2CC4();
}
