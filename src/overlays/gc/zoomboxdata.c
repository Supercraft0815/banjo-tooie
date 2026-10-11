#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoomboxdata/gczoomboxdata_entrypoint_0.s")

u16 gczoomboxdata_entrypoint_1(s32 arg0) {
    extern u8 D_80800AA8_gczoomboxdata[];
    return *(u16 *)(D_80800AA8_gczoomboxdata + arg0 * 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoomboxdata/gczoomboxdata_entrypoint_2.s")

u8 gczoomboxdata_entrypoint_3(s32 arg0) {
    extern u8 D_80800AB0_gczoomboxdata[];
    return D_80800AB0_gczoomboxdata[(arg0 * 3) * 4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoomboxdata/gczoomboxdata_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoomboxdata/gczoomboxdata_entrypoint_5.s")

/* extern */

s32 gczoomboxdata_entrypoint_6(void) {
    s32 gczoomboxdata_entrypoint_5();
    s32 temp_v0;

    temp_v0 = gczoomboxdata_entrypoint_5();
    if ((temp_v0 == 0) || (temp_v0 == 0xBAE)) {
        return 0;
    }
    return 1;
}
