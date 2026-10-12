#include "common.h"

void func_80104350(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136E80;
    D_80136E80 = freelist_new(0x2C, 8);
}

void func_80104378(void) {
    s32 freelist_free(s32);
    extern s32 D_80136E80;
    freelist_free(D_80136E80);
    D_80136E80 = 0;
}

void func_801043A0(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136E80;
    if (D_80136E80 != 0) {
        D_80136E80 = freelist_defrag(D_80136E80);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801043D8.s")

s32 *func_80104410(void *arg0) {
    s32 *freelist_at(s32, s16);
    extern s32 D_80136E80;
    extern s32 D_80136E88;
    extern s8 D_80136E8B;
    extern s32 D_80136EAC;
    extern s8 D_80136EB0;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0x8E)));
    if (temp_a1 == 0) {
        D_80136E8B = 0;
        D_80136EAC = 0;
        D_80136EB0 = 0;
        return &D_80136E88;
    }
    return freelist_at(D_80136E80, temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104460.s")

void func_80104504(void *arg0) {
    s32 freelist_erase(s32, s16, void *);
    extern s32 D_80136E80;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0x8E)));
    if (temp_a1 != 0) {
        freelist_erase(D_80136E80, temp_a1, arg0);
        (*(s16 *)((s8 *)(arg0) + (0x8E))) = 0;
    }
}

int func_80104544(void) {
    void *func_801043D8();
    void *temp_v0;
    temp_v0 = func_801043D8();
    return temp_v0 != NULL && (*(u8 *)((s8 *)temp_v0 + 3)) != 0;
}

/* extern */

void func_80104580(void) {
    void *func_801043D8();
    void *temp_v0;

    temp_v0 = func_801043D8();
    if (temp_v0 != NULL) {
        (*(s8 *)((s8 *)(temp_v0) + (3))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801045AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_8010473C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_8010486C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801048E4.s")

/* extern */

void func_80104958(u8 *arg0) {
    void func_800AAD28(f32 *);
    f32 sp34[9];
    s16 *var_s1;
    f32 *var_s0;

    func_800AAD28(sp34);
    var_s1 = (s16 *)(arg0 + 4);
    arg0 = (u8 *)(sp34 + 9);
    var_s0 = sp34;
    do {
        func_800EE940(var_s1, var_s0);
        var_s0 += 3;
        var_s1 += 3;
    } while ((u8 *)var_s0 != arg0);
}

void func_801049B4(u8 *arg0, f32 *arg1, s32 *arg2) {
    typedef struct {
        u8 header[4];
        s16 position[3][3];
        u8 pad16[2];
        u8 color[3][4];
        s32 flags;
    } Triangle;
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE830(s32 *, s32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFA88(void *, s32, s32, s32);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F36D4(s32 *, s32 *);
    void func_80105390(u8 *, u8 *);
    extern f32 D_80126444;
    extern f32 D_80126448;
    extern f32 D_8012644C;
    f32 point[3];
    f32 delta[3];
    f32 offset[3];
    f32 denominator;
    f32 t;
    f32 distance;
    f32 blend;
    f32 perpendicular[3];
    f32 edge[3];
    f32 intersection[3];
    s32 colors[3][3];
    s32 i;
    f32 vertices[3][3];
    f32 normal[3];
    f32 edge10[3];
    f32 edge20[3];
    f32 edge21[3];
    s32 j;

    if (((Triangle *)arg0)->flags & 0x200000) {
        func_800EFA88(arg2, 255, 255, 255);
        return;
    }
    func_800EE7F8(point, arg1);
    for (i = 0; i < 3; i++) {
        func_800EE88C(vertices[i], ((Triangle *)arg0)->position[i]);
        for (j = 0; j < 3; j++) {
            colors[i][j] = ((Triangle *)arg0)->color[i][j];
        }
    }
    if (func_800F36D4(colors[0], colors[1]) &&
        func_800F36D4(colors[0], colors[2])) {
        func_800EE830(arg2, colors[0]);
        return;
    }
    func_800EFB24(delta, point, vertices[0]);
    func_800EFB24(edge, vertices[0], vertices[1]);
    func_800EFB24(edge10, vertices[1], vertices[0]);
    func_800EFB24(edge20, vertices[2], vertices[0]);
    func_800EFB24(edge21, vertices[2], vertices[1]);
    func_800EE97C(normal, edge10, edge20);
    func_800EE97C(perpendicular, edge21, normal);
    denominator = func_800EEAA4(delta, perpendicular);
    if (denominator == 0.0f) {
        denominator = D_80126444;
    }
    t = -func_800EEAA4(edge, perpendicular) / denominator;
    func_800EFA4C(intersection, vertices[0][0] + delta[0] * t, 0.0,
                 vertices[0][2] + delta[2] * t);
    func_800EFB24(offset, intersection, vertices[1]);
    distance = func_800EEF94(offset);
    blend = distance / (func_800EEF94(perpendicular) + D_80126448);
    for (i = 0; i < 3; i++) {
        arg2[i] = (s32)((f32)colors[1][i] + (f32)(colors[2][i] - colors[1][i]) * blend);
    }
    func_800EFB24(offset, intersection, vertices[0]);
    distance = func_800EEF94(delta);
    blend = 1.0f - distance / (func_800EEF94(offset) + D_8012644C);
    for (i = 0; i < 3; i++) {
        arg2[i] = (s32)((f32)arg2[i] + (f32)(colors[0][i] - arg2[i]) * blend);
    }
    if (((Triangle *)arg0)->flags & 0x04000000) {
        func_80105390((u8 *)arg2, (u8 *)arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105010.s")

/* extern */

void func_80105138(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) { s32 func_800C696C(s32, f32, f32, s32, f32 *); func_800C696C(arg1 ? arg1 : (s32)(arg0 + 4), arg2, arg3, *(s32 *)((s8 *)arg0 + 0x14), (f32 *)arg4); }

/* extern */

s32 func_8010518C(s32 arg0) {
    void *func_801043D8(s32);
    int func_80104544();
    if (func_80104544() == 0) {
        return 0;
    }
    return (*(s32 *)((s8 *)(func_801043D8(arg0)) + (0x24)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801051C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105230.s")

void func_80105390(u8 *arg0, u8 *arg1) {
    s32 temp_f16;

    temp_f16 = (s32) ((f32) ((*(s32 *)((s8 *)(arg1) + (0))) + (*(s32 *)((s8 *)(arg1) + (4))) + (*(s32 *)((s8 *)(arg1) + (8)))) / 3.0f);
    (*(s32 *)((s8 *)(arg0) + (0))) = temp_f16;
    (*(s32 *)((s8 *)(arg0) + (4))) = temp_f16;
    (*(s32 *)((s8 *)(arg0) + (8))) = temp_f16;
}

/* extern */

s32 func_801053D4(void) {
    s32 func_800C84B0(s32);
    s32 func_8010518C();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800C84B0(func_8010518C());
    var_v1 = temp_v0;
    if (temp_v0 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}
