#include "common.h"

OSThread *chfactoryposter_entrypoint_0(void)
{
    extern ActorData D_80800110_chfactoryposter[];

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
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
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
/* data_to_c.py: from asm/data/overlays/ch/factory/poster.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800110_chfactoryposter [1] BT_DATA(4, overlays_ch_factory_poster, 0x0) = { { 344, 1261, 0, 1, 0, (void (*)(struct Actor *))func_8080005C_chfactoryposter, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 19660800, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chfactoryposter, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, 0, 0 } };
u8 D_80800158_chfactoryposter [8] BT_DATA(4, overlays_ch_factory_poster, 0x48) = { 0, 0x13, 4, 0x84, 0, 0, 0, 0 };
