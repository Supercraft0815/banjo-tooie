#include "common.h"

s16 *func_80800000_gcmapDll(s32 arg0) {
    extern s16 D_80800F10_gcmapDll[];
    s16 *p = D_80800F10_gcmapDll;
    while (*p != 0) {
        if (arg0 == *p) return p;
        p += 7;
    }
    return NULL;
}

s32 gcmapDll_entrypoint_0(s32 arg0) {
    extern s16 D_80800F10_gcmapDll[];
    s16 *p = D_80800F10_gcmapDll;
    if (*p != 0) {
    do {
        if (arg0 == *p) return 1;
        p += 7;
    } while (*p != 0);
    }
    return 0;
}

/* extern */

void gcmapDll_entrypoint_1(void *arg0) {
    s32 _dblight_entrypoint_0(s32, s32, s32 *);
    s32 _dblight_entrypoint_1(s32, s32, s32);
    s32 _glid_entrypoint_6(s32, s32);
    s32 _glidmake_entrypoint_5(u16, s32);
    s32 _idworldmake_entrypoint_0(s32, s32);
    s32 _rtlight_entrypoint_1(s32, s32, s32);
    s32 _vpmodule_entrypoint_0(s32, s32, s32 *);
    s32 func_800A946C();
    s32 func_800B2400(s32, s32);
    s32 func_800B2464(s32, s32 *, s32);
    s32 func_800B274C(s32);
    s32 func_800B27A0(s32);
    s32 func_800B27BC(s32);
    s32 func_800B2868(s32);
    void func_800C87DC(s32 *);
    struct Map {
        s32 unk0, glid0, light0, model0, vertices0, clone0, vp0, module0;
        s32 unk20[4];
        s32 glid1, light1, model1, vertices1, clone1, vp1, module1;
        u8 unk4c[14];
        u16 id0, id1;
        u8 unk5e[6];
        u8 side0, side1;
    };
    s32 color[3];
    s32 light;

    func_800C87DC(color);
    if (((struct Map *)arg0)->model0 != 0 && func_800A946C() < 3) {
        light = func_800B27BC(((struct Map *)arg0)->model0);
    } else {
        light = 0;
    }
    if (light != 0) {
        _dblight_entrypoint_0(light, ((struct Map *)arg0)->vertices0, color);
        _dblight_entrypoint_1(light, ((struct Map *)arg0)->vertices0, func_800B27A0(((struct Map *)arg0)->model0));
    }
    if (light != 0) {
        ((struct Map *)arg0)->light0 = _rtlight_entrypoint_1(light, ((struct Map *)arg0)->vertices0, func_800B27A0(((struct Map *)arg0)->model0));
    } else {
        ((struct Map *)arg0)->light0 = 0;
    }
    if (((struct Map *)arg0)->model1 != 0 && func_800A946C() < 3) {
        light = func_800B27BC(((struct Map *)arg0)->model1);
    } else {
        light = 0;
    }
    if (light != 0) {
        _dblight_entrypoint_0(light, ((struct Map *)arg0)->vertices1, color);
        _dblight_entrypoint_1(light, ((struct Map *)arg0)->vertices1, func_800B27A0(((struct Map *)arg0)->model1));
    }
    if (light != 0) {
        ((struct Map *)arg0)->light1 = _rtlight_entrypoint_1(light, ((struct Map *)arg0)->vertices1, func_800B27A0(((struct Map *)arg0)->model1));
    } else {
        ((struct Map *)arg0)->light1 = 0;
    }
    if (((struct Map *)arg0)->model0 != 0 && func_800A946C() < 3 && (light = func_800B2868(((struct Map *)arg0)->model0), ((struct Map *)arg0)->vp0 = light, light != 0)) {
        ((struct Map *)arg0)->module0 = _vpmodule_entrypoint_0(light, ((struct Map *)arg0)->vertices0, color);
    } else {
        ((struct Map *)arg0)->module0 = 0;
    }
    if (((struct Map *)arg0)->model1 != 0 && func_800A946C() < 3 && (light = func_800B2868(((struct Map *)arg0)->model1), ((struct Map *)arg0)->vp1 = light, light != 0)) {
        ((struct Map *)arg0)->module1 = _vpmodule_entrypoint_0(light, ((struct Map *)arg0)->vertices1, color);
    } else {
        ((struct Map *)arg0)->module1 = 0;
    }
    if (((struct Map *)arg0)->model0 != 0 && ((struct Map *)arg0)->vp0 == 0 && ((struct Map *)arg0)->light0 == 0) {
        func_800B2464(((struct Map *)arg0)->vertices0, color, ((struct Map *)arg0)->vertices0);
    }
    if (((struct Map *)arg0)->model1 != 0 && ((struct Map *)arg0)->vp1 == 0 && ((struct Map *)arg0)->light1 == 0) {
        func_800B2464(((struct Map *)arg0)->vertices1, color, ((struct Map *)arg0)->vertices1);
    }
    if ((((struct Map *)arg0)->model0 != 0 && func_800A946C() < 3 ? func_800B274C(((struct Map *)arg0)->model0) : 0) != 0) {
        ((struct Map *)arg0)->glid0 = _glidmake_entrypoint_5(((struct Map *)arg0)->id0, 0);
    } else {
        ((struct Map *)arg0)->glid0 = 0;
    }
    if (((struct Map *)arg0)->glid0 != 0) {
        _idworldmake_entrypoint_0(((struct Map *)arg0)->glid0, 1);
    }
    if ((((struct Map *)arg0)->model1 != 0 && func_800A946C() < 3 ? func_800B274C(((struct Map *)arg0)->model1) : 0) != 0) {
        ((struct Map *)arg0)->glid1 = _glidmake_entrypoint_5(((struct Map *)arg0)->id1, 0);
    } else {
        ((struct Map *)arg0)->glid1 = 0;
    }
    if (((struct Map *)arg0)->glid1 != 0) {
        _idworldmake_entrypoint_0(((struct Map *)arg0)->glid1, 1);
    }
    if (((struct Map *)arg0)->vertices0 != 0 && ((struct Map *)arg0)->side0 != 0) {
        ((struct Map *)arg0)->clone0 = func_800B2400(((struct Map *)arg0)->vertices0, 1);
    } else {
        ((struct Map *)arg0)->clone0 = 0;
    }
    if (((struct Map *)arg0)->vertices1 != 0 && ((struct Map *)arg0)->side1 != 0) {
        ((struct Map *)arg0)->clone1 = func_800B2400(((struct Map *)arg0)->vertices1, 1);
    } else {
        ((struct Map *)arg0)->clone1 = 0;
    }
    if (((struct Map *)arg0)->glid0 != 0 && ((struct Map *)arg0)->clone0 != 0) {
        _glid_entrypoint_6(((struct Map *)arg0)->glid0, ((struct Map *)arg0)->clone0);
    }
    if (((struct Map *)arg0)->glid1 != 0 && ((struct Map *)arg0)->clone1 != 0) {
        _glid_entrypoint_6(((struct Map *)arg0)->glid1, ((struct Map *)arg0)->clone1);
    }
}

void func_8080045C_gcmapDll(void *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    void func_800B2198(void *, void *, void *);
    s32 func_800EA05C();
    s32 pad;
    void *vertices;

    vertices = *(void **)((u8 *)arg0 + arg1 * 0x2C + 0x10);
    if (vertices != NULL) {
        func_800B2198(vertices, arg2, arg3);
        return;
    }
    switch (func_800EA05C()) {
        case 0x1A7:
            arg2[0] = -18000;
            arg2[1] = -6000;
            arg2[2] = -16000;
            arg3[0] = 3000;
            arg3[1] = 12000;
            arg3[2] = 15000;
            break;
        case 0x1A8:
            arg2[0] = -20000;
            arg2[1] = -8000;
            arg2[2] = -3000;
            arg3[0] = 7000;
            arg3[1] = 2000;
            arg3[2] = 15000;
            break;
        case 0x1A9:
            arg2[0] = 1000;
            arg2[1] = -12000;
            arg2[2] = -13000;
            arg3[0] = 17000;
            arg3[1] = 0;
            arg3[2] = 12000;
            break;
        case 0x159:
            arg2[2] = -100;
            arg2[1] = -100;
            arg2[0] = -100;
            arg3[0] = 100;
            arg3[1] = 100;
            arg3[2] = 100;
            break;
    }
}

/* extern */

void func_808005A8_gcmapDll(u8 *arg0) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    s32 i;
    s32 sp40[3];
    s32 sp34[3];

    func_8080045C_gcmapDll(arg0, 0, (s32 *)(arg0 + 0x180), (s32 *)(arg0 + 0x18C));
    func_800EE830((s32 *)(arg0 + 0x198), (s32 *)(arg0 + 0x180));
    func_800EE830((s32 *)(arg0 + 0x1A4), (s32 *)(arg0 + 0x18C));
    if (*(s32 *)(arg0 + 0x38)) {
        func_8080045C_gcmapDll(arg0, 1, sp40, sp34);
        for (i = 0; i < 3; i++) {
            if (sp40[i] < ((s32 *)(arg0 + 0x198))[i]) {
                ((s32 *)(arg0 + 0x198))[i] = sp40[i];
            }
            if (((s32 *)(arg0 + 0x1A4))[i] < sp34[i]) {
                ((s32 *)(arg0 + 0x1A4))[i] = sp34[i];
            }
        }
    }
}

/* extern */

void func_80800668_gcmapDll(s32 arg0, u8 *arg1, s32 arg2) {
    s32 func_800BF744(s16, s16);
    s32 var_s1;
    u8 *var_s0;

    var_s1 = 0;
    if (arg2 > 0) {
        var_s0 = arg1;
        do {
            func_800BF744((*(s16 *)((s8 *)(var_s0) + (0))), (*(s16 *)((s8 *)(var_s0) + (2))));
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 != arg2);
    }
}

void gcmapDll_entrypoint_2(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    extern u8 D_80801B98_gcmapDll;
    extern u8 D_80801BA0_gcmapDll;
    extern u8 D_80801BA8_gcmapDll;
    extern u8 D_80801BB0_gcmapDll;
    extern u8 D_80801BB8_gcmapDll;
    extern u8 D_80801BC8_gcmapDll;
    extern u8 D_80801BD8_gcmapDll;
    s32 map;

    map = func_800EA05C();
    switch (map) {
    case 0xA1:
    case 0xA2:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xA6:
    case 0x18B:
        func_80800668_gcmapDll(arg0, &D_80801B98_gcmapDll, 2);
        break;
    case 0xA7:
    case 0xAF:
    case 0x193:
        func_80800668_gcmapDll(arg0, &D_80801BA0_gcmapDll, 2);
        break;
    case 0xB7:
    case 0xD9:
    case 0xEF:
    case 0x13E:
    case 0x13F:
    case 0x156:
    case 0x171:
    case 0x172:
    case 0x176:
        func_80800668_gcmapDll(arg0, &D_80801BB0_gcmapDll, 2);
        break;
    case 0x134:
        func_80800668_gcmapDll(arg0, &D_80801BA8_gcmapDll, 2);
        break;
    case 0x160:
        if (func_800DA298(0x360)) {
            func_80800668_gcmapDll(arg0, &D_80801BC8_gcmapDll, 4);
        } else {
            func_80800668_gcmapDll(arg0, &D_80801BB8_gcmapDll, 4);
        }
        break;
    case 0x18C:
        func_80800668_gcmapDll(arg0, &D_80801BB8_gcmapDll, 4);
        break;
    case 0x18D:
        func_80800668_gcmapDll(arg0, &D_80801BD8_gcmapDll, 4);
        break;
    case 0x194:
    case 0x195:
        func_80800668_gcmapDll(arg0, &D_80801BC8_gcmapDll, 4);
        break;
    }
}

void gcmapDll_entrypoint_3(u8 *arg0) {
    s32 func_800D674C(u32);
    void _gcmapsects_entrypoint_15(s32);
    s32 _glzone_entrypoint_0(u8 *);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    u8 *func_800B284C(u8 *);
    s32 func_800BF744(s16, s16);
    void func_800D70D0(s32);
    void func_800D71F4(s32);
    s32 func_800D731C(s32);
    u8 *func_800DBFF8(void);
    s32 func_800EA05C(void);
    s32 func_800EA068(s32);
    void rare_memcpy(void *, void *, int);
    s32 i;
    u16 asset;
    u16 asset2;
    u8 *zones;

    for (i = 0; i < 60; i++) {
        ((s32 *)(arg0 + 0x88))[i] = 0;
    }
    func_800BF744(1, 0);
    gcmapDll_entrypoint_2((s32)arg0);
    arg0[0x87] = 0xFF;
    arg0[0x86] = arg0[0x87];
    arg0[0x85] = 0xFF;
    *(s32 *)(arg0 + 0x17C) = 0;
    rare_memcpy(arg0 + 0x58, func_80800000_gcmapDll(func_800EA05C()), 0xE);
    asset = *(u16 *)(arg0 + 0x5A);
    arg0[0x55] = 0;
    arg0[0x29] = arg0[0x55];
    *(s32 *)(arg0 + 0x40) = 0;
    *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x40);
    if (asset != 0) {
        *(s32 *)(arg0 + 0xC) = func_800D674C((s32)asset);
        func_800D70D0(1);
        func_800D71F4(1);
        *(u8 **)arg0 = func_800B2720(*(u8 **)(arg0 + 0xC));
        *(s32 *)(arg0 + 0x10) = func_800B2840(*(s32 *)(arg0 + 0xC));
        zones = func_800B284C(*(u8 **)(arg0 + 0xC));
        *(u8 **)(arg0 + 0x20) = zones;
        if (zones != 0 && func_800EA068(0x80) != 0) {
            *(s32 *)(arg0 + 0x17C) = _glzone_entrypoint_0(*(u8 **)(arg0 + 0x20));
        }
    } else {
        *(s32 *)(arg0 + 0xC) = 0;
        *(s32 *)arg0 = 0;
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x20) = 0;
    }
    asset2 = *(u16 *)(arg0 + 0x5C);
    *(s32 *)(arg0 + 0x1B0) = 0;
    if (asset2 != 0) {
        *(s32 *)(arg0 + 0x38) = func_800D674C((s32)asset2);
        func_800D70D0(1);
        func_800D71F4(1);
        *(u8 **)(arg0 + 0x2C) = func_800B2720(*(u8 **)(arg0 + 0x38));
        *(s32 *)(arg0 + 0x3C) = func_800B2840(*(s32 *)(arg0 + 0x38));
        *(u8 **)(arg0 + 0x4C) = func_800B284C(*(u8 **)(arg0 + 0x38));
    } else {
        *(s32 *)(arg0 + 0x38) = 0;
        *(s32 *)(arg0 + 0x2C) = 0;
        *(s32 *)(arg0 + 0x3C) = 0;
        *(s32 *)(arg0 + 0x4C) = 0;
    }
    *(u8 **)(arg0 + 0x178) = func_800DBFF8();
    if (*(s32 *)(arg0 + 0xC) != 0) {
        arg0[0x28] = func_800D731C(*(u16 *)(arg0 + 0x5A));
    } else {
        arg0[0x28] = 0;
    }
    if (*(s32 *)(arg0 + 0x38) != 0) {
        arg0[0x54] = func_800D731C(*(u16 *)(arg0 + 0x5C));
    } else {
        arg0[0x54] = 0;
    }
    if (*(s32 *)arg0 != 0) {
        arg0[0x2A] = 1;
    } else {
        arg0[0x2A] = 0;
    }
    if (*(s32 *)(arg0 + 0x2C) != 0) {
        arg0[0x56] = 1;
    } else {
        arg0[0x56] = 0;
    }
    _gcmapsects_entrypoint_15((s32)arg0);
    func_808005A8_gcmapDll(arg0);
    arg0[0x2B] = arg0[0x57] = 1;
}

/* extern */

void func_80800A94_gcmapDll(s32 arg0[][11], s32 arg1) {
    s32 _dbtex_entrypoint_1(s32);
    s32 _glidmake_entrypoint_4(s32);
    s32 _rtlight_entrypoint_0(s32);
    s32 _vpmodule_entrypoint_1(s32, s32);
    void func_800B23E0(void *);
    void *temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a2;
    void *temp_s0;

    temp_s0 = arg0[arg1];
    temp_a2 = (*(s32 *)((s8 *)(temp_s0) + (0x24)));
    if (temp_a2 != 0) {
        _dbtex_entrypoint_1(temp_a2);
        (*(s32 *)((s8 *)(temp_s0) + (0x24))) = 0;
    }
    temp_a0 = (*(void **)((s8 *)(temp_s0) + (0x14)));
    if (temp_a0 != 0) {
        func_800B23E0(temp_a0);
    }
    temp_a0_2 = (*(s32 *)((s8 *)(temp_s0) + (4)));
    if (temp_a0_2 != 0) {
        _glidmake_entrypoint_4(temp_a0_2);
    }
    temp_a0_3 = (*(s32 *)((s8 *)(temp_s0) + (8)));
    if (temp_a0_3 != 0) {
        _rtlight_entrypoint_0(temp_a0_3);
        (*(s32 *)((s8 *)(temp_s0) + (8))) = 0;
    }
    temp_a0_4 = (*(s32 *)((s8 *)(temp_s0) + (0x1C)));
    if (temp_a0_4 != 0) {
        _vpmodule_entrypoint_1(temp_a0_4, (*(s32 *)((s8 *)(temp_s0) + (0x18))));
        (*(s32 *)((s8 *)(temp_s0) + (0x1C))) = 0;
    }
}

/* extern */

void gcmapDll_entrypoint_4(void *arg0) {
    s32 _gcmapsects_entrypoint_16(void *);
    s32 _glzone_entrypoint_1(s32);
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D721C(s32, s32);
    void func_800DBFD8(void *);
    s32 temp_a0;
    s32 var_s0;

    var_s0 = 0;
    do {
        func_80800A94_gcmapDll(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 != 2);
    if ((*(s32 *)((s8 *)(arg0) + (0xC))) != 0) {
        func_800D70F8((*(u16 *)((s8 *)(arg0) + (0x5A))), 0);
        func_800D721C((*(u16 *)((s8 *)(arg0) + (0x5A))), 0);
        func_800D6CEC((*(u16 *)((s8 *)(arg0) + (0x5A))));
        (*(s32 *)((s8 *)(arg0) + (0xC))) = 0;
    }
    if ((*(s32 *)((s8 *)(arg0) + (0x38))) != 0) {
        func_800D70F8((*(u16 *)((s8 *)(arg0) + (0x5C))), 0);
        func_800D721C((*(u16 *)((s8 *)(arg0) + (0x5C))), 0);
        func_800D6CEC((*(u16 *)((s8 *)(arg0) + (0x5C))));
        (*(s32 *)((s8 *)(arg0) + (0x38))) = 0;
    }
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x17C)));
    if (temp_a0 != 0) {
        _glzone_entrypoint_1(temp_a0);
    }
    func_800DBFD8((*(void **)((s8 *)(arg0) + (0x178))));
    if ((*(u8 *)((s8 *)(arg0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_16(arg0);
    }
}

s16 gcmapDll_entrypoint_5(void) {
    s32 func_800EA05C();
    extern s16 D_80801BE8_gcmapDll[][2];
    s32 map;
    s32 index;

    map = func_800EA05C();
    for (index = 0; D_80801BE8_gcmapDll[index][0] != -1; index++) {
        if (map == D_80801BE8_gcmapDll[index][0]) {
            break;
        }
    }
    return D_80801BE8_gcmapDll[index][1];
}

/* extern */

void gcmapDll_entrypoint_6(void *arg0, s32 arg1) {
    s32 _dbtex_entrypoint_0(s32);
    s32 func_800B27FC(s32);
    s32 func_800D5B24();
    s32 func_800D674C(u32);
    s16 *func_80800000_gcmapDll(s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_80800000_gcmapDll(arg1);
    sp1C = temp_v0;
    if ((*(u16 *)((s8 *)(temp_v0) + (2))) != 0) {
        func_800D5B24();
        (*(s32 *)((s8 *)(arg0) + (0x24))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((*(u16 *)((s8 *)(sp1C) + (2))))));
    }
    if ((*(u16 *)((s8 *)(sp1C) + (4))) != 0) {
        func_800D5B24();
        (*(s32 *)((s8 *)(arg0) + (0x50))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((*(u16 *)((s8 *)(sp1C) + (4))))));
    }
}
