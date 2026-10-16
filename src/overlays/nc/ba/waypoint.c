#include "common.h"

s32 ncbawaypoint_entrypoint_0() 
{
    return 0x84;
}

void ncbawaypoint_entrypoint_1(void *arg0) {
    *(*(s32 **)((s8 *)(arg0) + (0x5C))) = 0;
}

s32 ncbawaypoint_entrypoint_2(void *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    f32 *volatile point;
    s32 *data;
    s32 count;

    data = *(s32 **)((s8 *)arg0 + 0x5C);
    count = *data;
    if (count >= 4) {
        return 0;
    }
    func_800EE7F8(point = (f32 *)((s8 *)data + (count << 5) + 4), arg1);
    func_800EE7F8(point + 3, arg2);
    point[6] = arg3;
    data = *(s32 **)((s8 *)arg0 + 0x5C);
    *data += 1;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/waypoint/ncbawaypoint_entrypoint_3.s")
