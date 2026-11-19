#include "common.h"

OSThread *chlavafall_entrypoint_0(void)
{
    extern ActorData D_808000B0_chlavafall[];

    return (OSThread *) D_808000B0_chlavafall;
}    typedef struct { u8 pad0[0x7A]; u8 unk7A; } Objfall_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chlavafall(void *arg0) {
    (((Objfall_arg0 *)arg0)->unk7A) = (u8) (((((Objfall_arg0 *)arg0)->unk7A) & 0xFF3F) | 0x80);
}

typedef struct {
    u8 pad0[0x1A];
    BT_BITFIELD_ORDER(u16 playerIndex : 11, u16 pad1A : 5);
    BT_BITFIELD_ORDER(u16 pad1A : 5, u16 playerIndex : 11);
    u8 pad1C[8];
    BT_BITFIELD_ORDER(u32 flags : 10, u32 pad24 : 22);
    BT_BITFIELD_ORDER(u32 pad24 : 22, u32 flags : 10);
} LavaFallContact;

typedef union {
    LavaFallContact *contact;
    s32 value;
} LavaFallEvent;

s32 func_80800020_chlavafall(Actor *arg0, s32 arg1, LavaFallEvent arg2) {
    s32 func_800F6AA4(BtIntPtr);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    LavaFallContact *sp1C;

    sp1C = arg2.contact;
    switch (arg1) {
    case 0x3E:
        if (sp1C->flags == 0) {
            arg2.value = func_800F6AA4(sp1C->playerIndex);
            if (arg2.value == 0) {
                func_800F79DC(sp1C->playerIndex, 4, (BtIntPtr)arg0->unk0);
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/fall.data.s */
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808000B0_chlavafall [1] BT_DATA(4, overlays_ch_lava_fall, 0x0) = { { 777, 1282, 2374, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 7000, 0, 0, 0, 2, 5120, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chlavafall, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3072, (void (*)(struct Actor *, long, long))func_80800020_chlavafall, 0 } };
