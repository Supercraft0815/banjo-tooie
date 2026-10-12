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

void cosectionstor_entrypoint_2(void)
{
  s32 defrag(s32);
  s32 *new_var;
  s32 *new_var2;
  extern f32 D_80127194;
  s32 *var_s0;
  s32 *var_s1;
  s32 temp_a0;
 do { var_s0 = (s32 *) ((&D_80127194) + 1); new_var = (new_var2 = (s32 *) ((&D_80127194) + 267)); var_s1 = new_var2; do { temp_a0 = *var_s0; if (temp_a0) { *var_s0 = defrag(temp_a0); } var_s0++; } while (var_s0 != var_s1); } while (0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/sectionstor/cosectionstor_entrypoint_4.s")
