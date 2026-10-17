#include "common.h"

OSThread *chlightdemon_entrypoint_0(void)
{
    extern u8 D_80800140_chlightdemon[];

    return (OSThread *) D_80800140_chlightdemon;
}

/* extern */

void func_8080000C_chlightdemon(Actor *arg0) {
    void func_800C8CB8(s32, f32 *);
    void func_80105834(Actor *);
    func_80105834(arg0);
    func_800C8CB8(arg0->actorData[4], arg0->position);
}

void func_8080003C_chlightdemon(Actor *arg0) {
    void func_80105A9C(Actor*, f32);
    func_80105A9C(arg0, 650.0f);
}

s32 func_80800060_chlightdemon(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    extern f32 D_80800194_chlightdemon[];
    extern u32 D_80800188_chlightdemon[];
    s32 temp_v0;

    if (arg1 == 0x95) {
        temp_v0 = func_800C8A98();
        arg0->actorData[4] = temp_v0;
        func_800C8D4C(temp_v0, D_80800194_chlightdemon);
        func_800C8CB8(arg0->actorData[4], arg0->position);
        func_800C8E84(arg0->actorData[4], D_80800188_chlightdemon);
        return 1;
    }
    return 0;
}

/* extern */

void func_808000D8_chlightdemon(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F581C(s32);
    s32 func_800F796C(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F581C(temp_v0) & 0x08000000) {
        func_800F796C(sp1C, 3);
    }
}

OSThread *chlightdemon_entrypoint_1(void)
{
    extern u8 D_8080019C_chlightdemon[];

    return (OSThread *) D_8080019C_chlightdemon;
}
