#include "common.h"

OSThread *chfactorylobbydoor_entrypoint_0(void)
{
    extern ActorData D_80800160_chfactorylobbydoor[];

    return (OSThread *) D_80800160_chfactorylobbydoor;
}

/* extern */

void func_8080000C_chfactorylobbydoor(BtIntPtr arg0) {
    s32 _chdoormake_entrypoint_3(BtIntPtr, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *arg0, f32 arg1);
    void _chdoormake_entrypoint_8(Actor *arg0, u32 arg1);
    s32 func_8009E958();
    s32 func_800D0A9C(s32, s32);
    s32 func_800EA090();
    void func_80101FDC(Actor *actor,u32 state);
    if ((func_800EA090() == 1) && ((func_800D0A9C(0x35, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}

void func_808000A8_chfactorylobbydoor(s32 arg0)
{
    func_808000D0_chfactorylobbydoor();
    _chdoor_entrypoint_0(arg0);
}
int func_808000D0_chfactorylobbydoor(s32 arg0) { s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *); void _chmrtannoy_entrypoint_0(void); extern s32 D_808001A8_chfactorylobbydoor[10]; if (_subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_808001A8_chfactorylobbydoor) != 0) { _chmrtannoy_entrypoint_0(); } BT_NATIVE_ONLY(return 0;) }

s32 func_80800108_chfactorylobbydoor(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    s32 func_8010108C(Actor*, s32, BtIntPtr, s32);
    if (arg1 == 0x2E) {
        if (*(s16 *) &arg2 == 0x1370) {
            func_8010108C(arg0, 7, 0, arg3);
        }
        return 1;
    }
    return _chdoor_entrypoint_1((BtIntPtr) arg0, arg1, (s32) arg2);
}
/* data_to_c.py: from asm/data/overlays/ch/factory/lobbydoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800160_chfactorylobbydoor [1] BT_DATA(4, overlays_ch_factory_lobbydoor, 0x0) = { { 172, 706, 2127, 4, 0, (void (*)(struct Actor *))func_808000A8_chfactorylobbydoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chfactorylobbydoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))func_80800108_chfactorylobbydoor, 0 } };
s32 D_808001A8_chfactorylobbydoor[10] BT_DATA(4, overlays_ch_factory_lobbydoor, 0x48) = { 400, 326112112, 256, 304283648, 10682368, 671744, 0, 0, 0, 0 };
