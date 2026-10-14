#include "core2/1E7B250.h"

s32 func_800A1960() 
{
    return 0x10;
}

void func_800A1968(PlayerState *arg0, f32 *arg1) {
    s32 func_80091E80(u8 *, s32);
    f32 func_800962D4(void *);
    f32 func_80096364(PlayerState *);
    s32 func_800965D4(void *);
    void func_800965E0(void *, u8 *);
    void func_80096604(void *, f32 *);
    s32 func_80096628(PlayerState *);
    void func_8009C128(PlayerState *, f32 *);
    void func_800EE84C(f32 *, s32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F36D4(s32 *, s32 *);
    s32 func_800F40EC(PlayerState *);
    Actor *func_80106790(Unk80132ED0 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    extern f32 D_801254A0, D_801254A4, D_801254A8;
    extern f32 D_801254AC, D_801254B0;
    f32 pos[3];
    f32 direction[3];
    f32 delta[3];
    f32 dot;
    s32 i;
    s32 j;
    s32 flags;
    f32 temp;
    f32 normal[3];
    f32 edge[3];
    f32 point[3];
    u8 rgba[3][4];
    s32 colors[3][3];
    s32 shade;
    f32 unused[2];
    f32 vertices[3][3];
    f32 ratio;
    s32 tint[3];

    arg1[0] = arg1[1] = arg1[2] = 255.0f;
    if (!func_80091E80((u8 *)arg0, 4)) return;
    func_8009C128(arg0, pos);
    if (pos[1] - func_80096364(arg0) > 1000.0f) return;
    flags = func_80096628(arg0);
    if (flags & 0x200000) return;
    func_80096604(arg0, vertices[0]);
    func_800965E0(arg0, rgba[0]);
    for (i = 0; i < 3; i++) {
        vertices[i][1] = 0.0f;
        for (j = 0; j < 3; j++) {
            colors[i][j] = rgba[i][j];
        }
    }
    if (func_800F36D4(colors[0], colors[1]) && func_800F36D4(colors[0], colors[2])) {
        func_800EE84C(arg1, colors[0]);
    } else {
        pos[1] = 0.0f;
        func_800EFB24(direction, pos, vertices[0]);
        direction[1] = 0.0f;
        func_800EFB24(edge, vertices[0], vertices[1]);
        edge[1] = 0.0f;
        func_800EFB24(normal, vertices[2], vertices[1]);
        temp = normal[0];
        normal[1] = 0.0f;
        normal[0] = -normal[2];
        normal[2] = temp;
        dot = func_800EEAA4(direction, normal);
        if (dot == 0.0f) dot = D_801254A0;
        ratio = -func_800EEAA4(edge, normal) / dot;
        func_800EFA4C(point, vertices[0][0] + direction[0] * ratio, 0, vertices[0][2] + direction[2] * ratio);
        func_800EFB24(delta, point, vertices[1]);
        ratio = func_800EEF94(delta) / (func_800EEF94(normal) + D_801254A4);
        for (i = 0; i < 3; i++) {
            arg1[i] = colors[1][i] + (colors[2][i] - colors[1][i]) * ratio;
        }
        func_800EFB24(delta, point, vertices[0]);
        ratio = 1.0f - func_800EEF94(direction) / (func_800EEF94(delta) + D_801254A8);
        for (i = 0; i < 3; i++) {
            arg1[i] = arg1[i] + (colors[0][i] - arg1[i]) * ratio;
        }
    }
    ratio = func_800962D4(arg0) / 1000.0f;
    for (i = 0; i < 3; i++) {
        arg1[i] = arg1[i] + (255.0f - arg1[i]) * ratio;
    }
    for (i = 0; i < 3; i++) {
        if (arg1[i] > 255.0f) arg1[i] = 255.0f;
        if (arg1[i] < 0.0f) arg1[i] = 0.0f;
    }
    if (func_80091E80((u8 *)arg0, 4)) {
        i = func_800965D4(arg0);
        if (i) {
            _subaddiefade_entrypoint_9(func_80106790((Unk80132ED0 *)i), tint);
            for (i = 0; i < 3; i++) {
                arg1[i] = ((s32)arg1[i] * tint[i]) >> 8;
            }
        }
    }
    if (**(u8 **)((u8 *)arg0 + 0x108) == 1) shade = 50;
    else shade = !func_800F40EC(arg0) ? 200 : 250;
    if (flags & 0x4000000) {
        arg1[0] = ((arg1[0] + arg1[1]) + arg1[2]) * (255.0f - shade) * D_801254AC + shade;
        ratio = arg1[0];
        arg1[1] = ratio;
        arg1[2] = ratio;
    } else {
        dot = D_801254B0;
        arg1[0] = arg1[0] * (255.0f - shade) * dot + shade;
        arg1[1] = arg1[1] * (255.0f - shade) * dot + shade;
        arg1[2] = arg1[2] * (255.0f - shade) * dot + shade;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A1F0C.s")

void func_800A1F78(void *arg0) {
    s32 func_800EA05C();
    extern s16 D_80119260[];
    s32 i;
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = func_800EA05C();
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (4))) = 255.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (8))) = 255.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (0xC))) = 255.0f;
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (0))) = 1U;
    for (i = 0; D_80119260[i] != 0; i++) {
        if (temp_v0 == D_80119260[i]) {
            (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (0))) = 2U;
            break;
        }
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x108)));
    (*(u8 *)((s8 *)(temp_v0_2) + (1))) = (u8) (*(u8 *)((s8 *)(temp_v0_2) + (0)));
}

void func_800A2018(PlayerState *arg0, s32 arg1) {
    u8 temp_v1;
    void *temp_v0;
    void *temp_v0_2;

    if (arg1 == -1) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x108)));
        (*(u8 *)((s8 *)(temp_v0) + (0))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (1)));
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x108)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0_2) + (0)));
    if (arg1 != temp_v1) {
        (*(u8 *)((s8 *)(temp_v0_2) + (1))) = temp_v1;
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x108)))) + (0))) = (u8) arg1;
    }
}

void func_800A2058(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7B250/func_800A2060.s")
