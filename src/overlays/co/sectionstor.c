#include "common.h"

void cosectionstor_entrypoint_0(void) {
    extern f32 D_80127194;
    s32 i;

    for (i = 1; i < 267; i++) {
        ((s32 *)&D_80127194)[i] = 0;
    }
}

void cosectionstor_entrypoint_1(void) {
    void heap_free(void *);
    extern f32 D_80127194;
    void **var_s0;
    void **end;
    void *temp_a0;

    var_s0 = (void **)(&D_80127194 + 1); end = (void **)(&D_80127194 + 267);
    do {
        temp_a0 = *var_s0;
        if (temp_a0 != 0) {
            heap_free(temp_a0);
            *var_s0 = 0;
        }
        var_s0++;
    } while (var_s0 != end);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_4.s")
