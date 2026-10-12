#include "common.h"

extern u32 D_80800070_chjiggybeam;

void * chjiggybeam_entrypoint_0(void) {
    return &D_80800070_chjiggybeam;
}

void func_8080000C_chjiggybeam(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 1.0f;
}

void func_8080001C_chjiggybeam(void) {
}

/* extern */

void func_80800024_chjiggybeam(Actor *arg0, void *arg1) {
    void func_800E3A58(f32 *);
    void func_80101870(Actor *, void *);
    f32 sp1C[3];

    func_800E3A58(sp1C);
    func_80101870(arg0, arg1);
}

s32 func_80800058_chjiggybeam(s32 arg0, u32 arg1, u32 arg2) {
    return 0;
}
