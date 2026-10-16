#include "common.h"

OSThread *chfactoryposter_entrypoint_0(void)
{
    extern u8 D_80800110_chfactoryposter[];

    return (OSThread *) D_80800110_chfactoryposter;
}

/* extern */

void func_8080000C_chfactoryposter(Actor *arg0) {
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    if (func_800DA298(0x3D) != 0) {
        func_800BF744(2, 2);
        func_800FFAB0(arg0);
        return;
    }
    func_800BF744(2, 1);
}

void func_8080005C_chfactoryposter(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BF744(s32, s32);
    void func_800DA544(s32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    void func_800FFAB0(Actor *);
    extern u8 D_80800158_chfactoryposter[];
    f32 position[3];

    if (arg0->unk70_10 == 1 && func_800F6438(func_800F54E4()) != 0) {
        func_800F5A00(func_800F54E4(), position);
        if (position[0] < arg0->position[0]) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800158_chfactoryposter);
            func_800BF744(2, 2);
            func_800DA544(0x3D);
            func_800FFAB0(arg0);
        }
    }
}
