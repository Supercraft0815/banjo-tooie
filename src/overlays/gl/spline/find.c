#include "common.h"

/* extern */

s32 glsplinefind_entrypoint_0(s32 arg0, f32 arg1[3]) { s32 _gccubesearch_entrypoint_2(s32, s32 *); void func_800EE84C(f32 *, s32 *); void glsplinefind_entrypoint_2(s32); s32 sp1C[3]; if (_gccubesearch_entrypoint_2(arg0, sp1C) == 0) return -1; func_800EE84C(arg1, sp1C); glsplinefind_entrypoint_2((s32) sp1C); }

/* extern */

s32 glsplinefind_entrypoint_1(s32 arg0) { s32 _gccubesearch_entrypoint_2(s32, s32 *); void glsplinefind_entrypoint_2(s32); s32 sp1C[3]; if (_gccubesearch_entrypoint_2(arg0, sp1C) == 0) return -1; glsplinefind_entrypoint_2((s32) sp1C); }

/* extern */

void glsplinefind_entrypoint_2(s32 arg0) {
    void func_800EE84C(f32 *, s32 *);
    s32 glsplinefind_entrypoint_3(f32 *);
    f32 sp1C[3];

    func_800EE84C(sp1C, arg0);
    glsplinefind_entrypoint_3(sp1C);
}

/* extern */

s32 glsplinefind_entrypoint_3(f32 arg0[3]) {
    void *func_8001B798(s16);
    void *func_800D7400(void);
    int func_800EECE0(f32 [3], f32 [3]);
    s32 var_s1;
    s32 var_s4;
    s32 var_s5;
    u8 temp_s2;
    u8 *temp_v0;
    u8 *temp_v0_2;
    f32 *var_s0;

    temp_v0 = func_800D7400();
    var_s4 = 0;
    var_s5 = 0;
    if (*(s32 *)(temp_v0 + 0x188) > 0) {
        do {
            temp_v0_2 = func_8001B798(*(s16 *)((u8 *)func_8001B798(*(s16 *)(temp_v0 + 0x184)) + var_s5));
            var_s1 = 0;
            temp_s2 = temp_v0_2[2];
            var_s0 = (f32 *)(temp_v0_2 + 0x14);
            if (temp_s2 > 0) {
                do {
                    if (func_800EECE0(arg0, var_s0) != 0) {
                        return var_s4;
                    }
                    var_s1++;
                    var_s0 += 3;
                } while (var_s1 != temp_s2);
            }
            var_s4++;
            var_s5 += 2;
        } while (var_s4 < *(s32 *)(temp_v0 + 0x188));
    }
    return -1;
}

/* extern */

s32 glsplinefind_entrypoint_4(s32 arg0[3], s32 arg1[3]) {
    void *func_8001B798(s16);
    void *func_800D7400(void);
    void func_800EE84C(f32 *, s32 *);
    int func_800EECE0(f32 a[3], f32 b[3]);
    s32 var_s1;
    s32 var_s5;
    s32 var_s6;
    f32 sp58[3];
    f32 sp4C[3];
    u8 temp_s2;
    u8 *temp_s7;
    f32 *var_s0;

    temp_s7 = func_800D7400();
    func_800EE84C(sp58, arg0);
    func_800EE84C(sp4C, arg1);
    var_s6 = 0;
    var_s5 = 0;
    if (*(s32 *)(temp_s7 + 0x188) > 0) {
        do {
            var_s0 = func_8001B798(*(s16 *)((u8 *)func_8001B798(*(s16 *)(temp_s7 + 0x184)) + var_s5));
            var_s1 = 0;
            temp_s2 = ((u8 *)var_s0)[2];
            var_s0 = (f32 *)((u8 *)var_s0 + 0x14);
            if (temp_s2 > 0) {
                do {
                    if (func_800EECE0(sp58, var_s0) != 0 && func_800EECE0(sp4C, var_s0 + 3) != 0) {
                        return var_s6;
                    }
                    var_s1++;
                    var_s0 += 3;
                } while (var_s1 != temp_s2);
            }
            var_s6++;
            var_s5 += 2;
        } while (var_s6 < *(s32 *)(temp_s7 + 0x188));
    }
    return -1;
}
