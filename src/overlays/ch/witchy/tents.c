#include "common.h"

/* extern */

void func_80800000_chwitchytents(BtIntPtr arg0) {
    s32 func_800EA05C();
    void func_8010A624(Actor *arg0);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
    }
}

OSThread *chwitchytents_entrypoint_0(void)
{
    extern ActorData D_80800050_chwitchytents[];

    return (OSThread *) D_80800050_chwitchytents;
}

OSThread *chwitchytents_entrypoint_1(void)
{
    extern ActorData D_80800098_chwitchytents[];

    return (OSThread *) D_80800098_chwitchytents;
}
/* data_to_c.py: from asm/data/overlays/ch/witchy/tents.data.s */
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800050_chwitchytents [1] BT_DATA(4, overlays_ch_witchy_tents, 0x0) = { { 344, 1220, 2141, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 7180, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chwitchytents, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, 0, 0 } };
ActorData D_80800098_chwitchytents [1] BT_DATA(4, overlays_ch_witchy_tents, 0x48) = { { 344, 1221, 2141, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 7180, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chwitchytents, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, 0, 0 } };
