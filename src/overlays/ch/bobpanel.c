#include "common.h"

void func_80800000_chbobpanel(Actor *arg0) {
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
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
    extern ActorData D_808000C0_chbobpanel[];

    return (OSThread *) D_808000C0_chbobpanel;
}
/* data_to_c.py: from asm/data/overlays/ch/bobpanel.data.s */
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808000C0_chbobpanel [1] BT_DATA(4, overlays_ch_bobpanel, 0x0) = { { 344, 1330, 2248, 1, 0, (void (*)(struct Actor *))func_80800000_chbobpanel, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 0, 4096, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_8080004C_chbobpanel, 0 } };
