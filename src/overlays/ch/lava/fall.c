#include "common.h"

OSThread *chlavafall_entrypoint_0(void)
{
    extern u8 D_808000B0_chlavafall[];

    return (OSThread *) D_808000B0_chlavafall;
}

void func_8080000C_chlavafall(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x7A))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x7A))) & 0xFF3F) | 0x80);
}

typedef struct {
    u8 pad0[0x1A];
    u16 playerIndex : 11;
    u16 pad1A : 5;
    u8 pad1C[8];
    u32 flags : 10;
    u32 pad24 : 22;
} LavaFallContact;

typedef union {
    LavaFallContact *contact;
    s32 value;
} LavaFallEvent;

s32 func_80800020_chlavafall(Actor *arg0, s32 arg1, LavaFallEvent arg2) {
    s32 func_800F6AA4(s32);
    s32 func_800F79DC(s32, s32, s32);
    LavaFallContact *sp1C;

    sp1C = arg2.contact;
    switch (arg1) {
    case 0x3E:
        if (sp1C->flags == 0) {
            arg2.value = func_800F6AA4(sp1C->playerIndex);
            if (arg2.value == 0) {
                func_800F79DC(sp1C->playerIndex, 4, (s32)arg0->unk0);
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
