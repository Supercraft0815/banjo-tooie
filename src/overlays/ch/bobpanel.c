#include "common.h"

void func_80800000_chbobpanel(Actor *arg0) {
    void _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
    f32 func_80103EAC(Actor*);
    f32 func_80103EF4(Actor*);
    f32 sp20[2];

    sp20[0] = func_80103EF4(arg0);
    _sudeflect_entrypoint_1(arg0->position, sp20[0], 0.0f, func_80103EAC(arg0), 0x1E);
}

s32 func_8080004C_chbobpanel(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor*);
    if (arg1 == 0x1F) {
        func_801015D0(arg0);
        func_800DF744(2, 3);
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        return 1;
    }
    return 0;
}

OSThread *chbobpanel_entrypoint_0(void)
{
    extern u8 D_808000C0_chbobpanel[];

    return (OSThread *) D_808000C0_chbobpanel;
}
