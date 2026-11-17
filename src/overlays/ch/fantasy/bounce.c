#include "common.h"

/* extern */

void func_80800000_chfantasybounce(s32 arg0) {
    s32 func_800EFA4C(s32, s32, s32, s32);
    func_800EFA4C(arg0 + 4, 0xC62C8A36, 0x4604CA00, 0xC6149236);
}

OSThread *chfantasybounce_entrypoint_0(void)
{
    extern ActorData D_80800060_chfantasybounce[];

    return (OSThread *) D_80800060_chfantasybounce;
}

OSThread *chfantasybounce_entrypoint_1(void)
{
    extern ActorData D_808000A8_chfantasybounce[];

    return (OSThread *) D_808000A8_chfantasybounce;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/bounce.data.s */
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800060_chfantasybounce [1] BT_DATA(4, overlays_ch_fantasy_bounce, 0x0) = { { 344, 1222, 1580, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 7180, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chfantasybounce, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, 0, 0 } };
ActorData D_808000A8_chfantasybounce [1] BT_DATA(4, overlays_ch_fantasy_bounce, 0x48) = { { 344, 1223, 1581, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 7180, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, 0, 0 } };
