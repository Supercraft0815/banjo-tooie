#include "common.h"

/* extern */

s32 glsplinefind_entrypoint_0(s32 arg0, f32 arg1[3]) { s32 _gccubesearch_entrypoint_2(s32, s32 *); void func_800EE84C(f32 *, s32 *); void glsplinefind_entrypoint_2(s32); s32 sp1C[3]; if (_gccubesearch_entrypoint_2(arg0, sp1C) == 0) return -1; func_800EE84C(arg1, sp1C); glsplinefind_entrypoint_2((s32) sp1C); }

/* extern */

s32 glsplinefind_entrypoint_1(s32 arg0) { s32 _gccubesearch_entrypoint_2(s32, s32 *); void glsplinefind_entrypoint_2(s32); s32 sp1C[3]; if (_gccubesearch_entrypoint_2(arg0, sp1C) == 0) return -1; glsplinefind_entrypoint_2((s32) sp1C); }

/* extern */

void glsplinefind_entrypoint_2(s32 arg0) {
    void func_800EE84C(f32 *, s32 *);
    s32 glsplinefind_entrypoint_3(s32 *);
    s32 sp1C[3];

    func_800EE84C(sp1C, arg0);
    glsplinefind_entrypoint_3(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/find/glsplinefind_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/find/glsplinefind_entrypoint_4.s")
