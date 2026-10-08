#include "common.h"

s32 ncbawaypoint_entrypoint_0() 
{
    return 0x84;
}

void ncbawaypoint_entrypoint_1(void *arg0) {
    *(*(s32 **)((s8 *)(arg0) + (0x5C))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/waypoint/ncbawaypoint_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/waypoint/ncbawaypoint_entrypoint_3.s")
