#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_80800000_sulights.s")

void func_808000D0_sulights(s8 *arg0) {
    arg0[0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_808000D8_sulights.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_80800194_sulights.s")

/* extern */

void func_8080021C_sulights(u8 *arg0) {
    void func_800C8900(s32, u8 *);
    s32 func_800C8E84(s32, s32 *);
    f32 func_800DC0C0(void);
    s32 sp4C;
    s32 sp40[3];
    f32 sp3C;
    s32 *var_v0;
    s32 var_a0;
    u8 *var_v1;

    if (func_800DC0C0() > 0.5f) {
        sp3C = 1.0f;
    } else {
        sp3C = -1.0f;
    }
    func_800C8900(arg0[1], (u8 *)sp40);
    var_v0 = sp40;
    var_v1 = arg0;
    do {
        *var_v0 += sp3C * (*(f32 *)(arg0 + 0x38) * (f32)*(s32 *)(var_v1 + 0x10) * *(f32 *)(arg0 + 0x34));
        if (*var_v0 > *(s32 *)(var_v1 + 4) + *(s32 *)(var_v1 + 0x10)) {
            *var_v0 = *(s32 *)(var_v1 + 4) + *(s32 *)(var_v1 + 0x10);
        }
        if (*var_v0 < *(s32 *)(var_v1 + 4) - *(s32 *)(var_v1 + 0x10)) {
            *var_v0 = *(s32 *)(var_v1 + 4) - *(s32 *)(var_v1 + 0x10);
        }
        var_v0++;
        var_v1 += 4;
    } while (var_v0 != &sp4C);
    func_800C8E84(arg0[1], sp40);
    *(f32 *)(arg0 + 0x34) = 0.0f;
}

void func_80800340_sulights(u8 *arg0) {
    s32 i;
    s32 *p;
    s32 value;
    i = 0;
    p = (s32 *)arg0;
    *(f32 *)(arg0 + 0x34) = 0.0f;
    do {
        value = p[4];
        i++;
        p++;
        p[0] += value;
        p[3] = value * -1;
    } while (i != 3);
}

void func_8080038C_sulights(u8 *arg0) { s32 i; f32 *p; f32 value; i = 0; p = (f32 *)arg0; *(f32 *)(arg0 + 0x34) = 0.0f; do { value = p[10]; i++; p++; p[6] += value; p[9] = value * -1.0f; } while (i != 2); }

/* extern */

void sulights_entrypoint_0(s32 arg0, s32 *arg1, s32 *arg2, f32 arg3) {
    s32 func_800C8E84(s32, s32 *);
    void func_800EE830(s32 dst[3], s32 src[3]);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80800000_sulights(1, arg0);
    if (arg3 < 0.001f) {
        (*(f32 *)((s8 *)(temp_v0) + (0x38))) = 0.001f;
    } else {
        (*(f32 *)((s8 *)(temp_v0) + (0x38))) = arg3;
    }
    func_800EE830((s32 *)(temp_v0 + 4), arg1);
    for (i = 0; i < 3; i++) {
        ((s32 *)temp_v0)[i + 4] = arg2[i] - arg1[i];
    }
    func_800C8E84(arg0, arg1);
}

/* extern */

void sulights_entrypoint_1(s32 arg0, s32 *arg1, f32 arg2) {
    void func_800C8900(s32, u8 *);
    void sulights_entrypoint_0(s32, s32 *, s32 *, f32);
    s32 sp1C[3];

    func_800C8900(arg0, (u8 *) sp1C);
    sulights_entrypoint_0(arg0, sp1C, arg1, arg2);
}

/* extern */

void sulights_entrypoint_2(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800C8D4C(s32, f32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *p;
    p = func_80800000_sulights(2, arg0);
    if (arg3 < 0.001f) {
        *(f32 *)(p + 0x38) = 0.001f;
    } else {
        *(f32 *)(p + 0x38) = arg3;
    }
    for (i = 0; i < 2; i++) {
        ((f32 *)p)[i + 7] = arg1[i];
        ((f32 *)p)[i + 10] = arg2[i] - arg1[i];
    }
    func_800C8D4C(arg0, arg1);
}

/* extern */

void sulights_entrypoint_3(s32 arg0, f32 *arg1, f32 arg2) {
    void func_800C883C(s32 arg0, void *arg1);
    f32 sp18[2];

    func_800C883C(arg0, &sp18);
    sulights_entrypoint_2(arg0, sp18, arg1, arg2);
}

/* extern */

void sulights_entrypoint_4(s32 arg0, void *arg1, void *arg2, f32 arg3) {
    s32 func_800C8E84(s32, s32 *);
    u8 *func_80800000_sulights(s32, s32);
    f32 var_f0;
    void *temp_v1;

    temp_v1 = func_80800000_sulights(3, arg0);
    if (arg3 < 0.001f) {
        var_f0 = 0.001f;
    } else {
        var_f0 = arg3;
    }
    (*(f32 *)((s8 *)(temp_v1) + (0x38))) = (f32) (4.0f / var_f0);
    (*(s32 *)((s8 *)(temp_v1) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(temp_v1) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(temp_v1) + (0xC))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s32 *)((s8 *)(temp_v1) + (0x10))) = (s32) (*(s32 *)((s8 *)(arg2) + (0)));
    (*(s32 *)((s8 *)(temp_v1) + (0x14))) = (s32) (*(s32 *)((s8 *)(arg2) + (4)));
    (*(s32 *)((s8 *)(temp_v1) + (0x18))) = (s32) (*(s32 *)((s8 *)(arg2) + (8)));
    func_800C8E84(arg0, arg1);
}

/* extern */

void sulights_entrypoint_5(s32 arg0, s32 *arg1, s32 *arg2, f32 arg3) {
    s32 func_800C8E84(s32, s32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80800000_sulights(4, arg0);
    if (arg3 < 0.001f) {
        (*(f32 *)((s8 *)(temp_v0) + (0x38))) = 0.001f;
    } else {
        (*(f32 *)((s8 *)(temp_v0) + (0x38))) = (f32) (arg3 * 0.5f);
    }
    (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(temp_v0) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    for (i = 0; i < 3; i++) {
        ((s32 *)temp_v0)[i + 4] = arg2[i] - arg1[i];
    }
    func_800C8E84(arg0, arg1);
}

/* extern */

void sulights_entrypoint_6(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800C8D4C(s32, f32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *p;
    p = func_80800000_sulights(5, arg0);
    if (arg3 < 0.001f) {
        *(f32 *)(p + 0x38) = 0.001f;
    } else {
        *(f32 *)(p + 0x38) = arg3 * 0.5f;
    }
    for (i = 0; i < 2; i++) {
        ((f32 *)p)[i + 7] = arg1[i];
        ((f32 *)p)[i + 10] = arg2[i] - arg1[i];
    }
    func_800C8D4C(arg0, arg1);
}

void sulights_entrypoint_7(s32 arg0) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF0;
    u32 end;
    u32 begin;
    u32 ptr;

    if (D_80127EF0 != 0) {
        end = vector_end(D_80127EF0);
        begin = vector_begin(D_80127EF0);
        ptr = begin;
        if (begin < end) {
            do {
                if (*(u8 *)ptr != 0 && arg0 == *(u8 *)(ptr + 1)) {
                    func_808000D0_sulights((s8 *)ptr);
                }
                ptr += 0x3C;
            } while (ptr < end);
        }
    }
}

void sulights_entrypoint_8(void) {
    s32 vector_free(s32);
    extern s32 D_80127EF0;
    if (D_80127EF0 != 0) {
        vector_free(D_80127EF0);
        D_80127EF0 = 0;
    }
}

void sulights_entrypoint_9(void) {
    f32 func_800D8FF8();
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF0;
    typedef struct {
        s32 (*update)(u32);
        s32 (*finish)(u32);
    } LightCallbacks;
    extern LightCallbacks D_80800A00_sulights[];
    s32 (*temp_v0_2)(u32);
    f32 temp_f0;
    f32 temp_f20;
    u32 temp_s2;
    u32 temp_v0;
    u32 var_s0;

    temp_f20 = func_800D8FF8();
    temp_s2 = vector_end(D_80127EF0);
    temp_v0 = vector_begin(D_80127EF0);
    var_s0 = temp_v0;
    if (temp_v0 < temp_s2) {
        do {
            if ((*(u8 *)((s8 *)(var_s0) + (0))) != 0) {
                temp_f0 = (*(f32 *)((s8 *)(var_s0) + (0x38)));
                (*(f32 *)((s8 *)(var_s0) + (0x34))) = (f32) ((*(f32 *)((s8 *)(var_s0) + (0x34))) + temp_f20);
                if (temp_f0 < (*(f32 *)((s8 *)(var_s0) + (0x34)))) {
                    (*(f32 *)((s8 *)(var_s0) + (0x34))) = temp_f0;
                }
                D_80800A00_sulights[*(u8 *)var_s0 - 1].update(var_s0);
                if ((*(f32 *)((s8 *)(var_s0) + (0x38))) <= (*(f32 *)((s8 *)(var_s0) + (0x34)))) {
                    temp_v0_2 = D_80800A00_sulights[*(u8 *)var_s0 - 1].finish;
                    if (temp_v0_2 != NULL) {
                        temp_v0_2(var_s0);
                    }
                }
            }
            var_s0 += 0x3C;
        } while (var_s0 < temp_s2);
    }
}
