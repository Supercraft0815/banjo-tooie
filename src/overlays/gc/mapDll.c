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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_8080045C_gcmapDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_808005A8_gcmapDll.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_3.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_4.s")

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
    s32 func_800D674C(u16);
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
