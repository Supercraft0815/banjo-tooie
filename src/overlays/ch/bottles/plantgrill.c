#include "common.h"

OSThread *chbottlesplantgrill_entrypoint_0(void)
{
    extern ActorData D_808000F0_chbottlesplantgrill[];

    return (OSThread *) D_808000F0_chbottlesplantgrill;
}

/* extern */

void func_8080000C_chbottlesplantgrill(Actor *arg0) {
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_12(Actor *, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_12(Actor *, s32, u16);)
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_8010A800(Actor *, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 250.0f, 0, -1) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x3F800000);
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_8(arg0, 5);
        _chdoormake_entrypoint_12(arg0, 0, 0x65);
        _chdoormake_entrypoint_9(arg0, 0, 3, 0x2900);
    }
    func_8010A800(arg0, 0);
    if ((_glcutDll_entrypoint_19(0x65) == 0) && ((func_800DA298(0x1A5) != 0) || (func_800DA298(0x3B) != 0))) {
        func_800FFAB0(arg0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/bottles/plantgrill.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_808000F0_chbottlesplantgrill [1] BT_DATA(4, overlays_ch_bottles_plantgrill, 0x0) = { { 172, 1258, 1921, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chbottlesplantgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
