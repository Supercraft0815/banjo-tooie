#include "common.h"

/* extern */

u8 *glzone_entrypoint_0(u8 *arg0) {
    void glzone_entrypoint_2(u8 *);
    void *heap_alloc(s32);
    u8 *temp_v0;

    temp_v0 = heap_alloc(*arg0 + 1);
    *temp_v0 = *arg0;
    glzone_entrypoint_2(temp_v0);
    return temp_v0;
}

void glzone_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void glzone_entrypoint_2(u8 *arg0) {
    u32 end;

    end = (u32) arg0 + *arg0 + 1;
    arg0++;
    while ((u32) arg0 < end) {
        arg0++;
        arg0[-1] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/zone/glzone_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/zone/glzone_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/zone/glzone_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/zone/glzone_entrypoint_6.s")
