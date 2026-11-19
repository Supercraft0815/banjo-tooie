#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1E95F80_native.inc"
#else
#include "common.h"
#include "core2/reflection_planes.h"

BT_IDO_ONLY(extern) NativeReflection D_801282E0;
#ifdef BT_ILP32
_Static_assert(__builtin_offsetof(NativeReflection, fixed) == 0x58 &&
               __builtin_offsetof(NativeReflection, restore) == 0xC8, "reflection state layout");
#endif

void func_800BC690(void) {
    void func_800B5680(s32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void *heap_alloc(s32);

    extern s8 D_8011A7C0[];
    BT_IDO_ONLY(extern s32 D_801282F4;) BT_IDO_ONLY(extern s32 D_80128338;)
    BT_IDO_ONLY(extern f32 D_80128324[];) BT_IDO_ONLY(extern f32 D_80128378[];) BT_IDO_ONLY(extern f32 D_80128384[];)
    s32 i;
    s32 map;
    f32 normal[3];

    map = func_800EA05C();
    i = 0;
    do {
        if (map == D_8011A760[i].map) break;
        i++;
    } while (i < 3);
    if (BT_DATA_FIELD(i < 3, D_8011A7C0 != (s8 *)&D_8011A760[i])) {
        if (D_8011A760[i].water) {
            func_800B5680((s32)D_8011A760[i].point[1]);
        }
        D_801282E0.cull_enabled = D_801282E0.active = 1;
        D_801282E0.bounds_cached = D_801282E0.bounds_valid = 0;
        D_801282E0.model = D_8011A760[i].model;
        D_801282E0.alpha = D_8011A760[i].alpha;
        D_801282E0.buffers[0] = heap_alloc(0x5DC0);
        D_801282E0.buffers[1] = heap_alloc(0x5DC0);
        func_800EF410(normal, D_8011A760[i].normal);
        D_801282E0.matrix.m[0][0] = 1.0f - (2.0f * normal[0]) * normal[0];
        D_801282E0.matrix.m[1][0] = (2.0f * -normal[1]) * normal[0];
        D_801282E0.matrix.m[2][0] = (2.0f * -normal[2]) * normal[0];
        D_801282E0.matrix.m[0][1] = (2.0f * -normal[0]) * normal[1];
        D_801282E0.matrix.m[1][1] = 1.0f - (2.0f * normal[1]) * normal[1];
        D_801282E0.matrix.m[2][1] = (2.0f * -normal[2]) * normal[1];
        D_801282E0.matrix.m[0][2] = (2.0f * -normal[0]) * normal[2];
        D_801282E0.matrix.m[1][2] = (2.0f * -normal[1]) * normal[2];
        D_801282E0.matrix.m[2][2] = 1.0f - (2.0f * normal[2]) * normal[2];
        D_801282E0.matrix.m[0][3] = D_801282E0.matrix.m[1][3] = D_801282E0.matrix.m[2][3] = 0.0f;
        func_800EFA20(BT_DATA_FIELD(D_801282E0.matrix.m[3], D_80128324), normal, 2.0f * func_800EEAA4(D_8011A760[i].point, normal));
        D_801282E0.matrix.m[3][3] = 1.0f;
        guMtxF2L(BT_DATA_FIELD(D_801282E0.matrix.m, (f32 (*)[4])&D_801282F4), BT_DATA_FIELD(&D_801282E0.fixed, (Mtx *)&D_80128338));
        func_800EE7F8(BT_DATA_FIELD(D_801282E0.normal, D_80128384), normal);
        func_800EE7F8(BT_DATA_FIELD(D_801282E0.point, D_80128378), D_8011A760[i].point);
    }
}

void func_800BC8A0(void) {
    void heap_free(void *);
    if ((D_801282E0.active) != 0) {
        heap_free((D_801282E0.buffers[0]));
        heap_free((D_801282E0.buffers[1]));
        (D_801282E0.buffers[1]) = 0;
        (D_801282E0.buffers[0]) = 0;
        (D_801282E0.active) = 0U;
    }
}

/* extern */

void func_800BC8F8(Gfx **arg0) {
    s32 func_800E42E4(s32);
    if ((D_801282E0.active) != 0) {
        (D_801282E0.saved_gfx) = *arg0;
        *arg0 = D_801282E0.buffers[D_801282E0.index];
        func_800E42E4(1);
    }
}

void func_800BC948(Gfx **arg0) {
    BT_IDO_ONLY(extern f32 D_80128390[];) BT_IDO_ONLY(extern f32 D_8012839C[];)
    void func_800B21CC(void *, void *, void *);
    s32 func_800B2840(s32);
    void func_800BCC90(Gfx **);
    s32 func_800CAA24(f32 *, f32 *, f32 *);
    struct ImageStruct;
    struct ImageStruct *func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF440(s32);
    void func_800DF830(s32);
    s32 func_800E42A8(void);
    s32 func_800E42E4(s32);
    void func_800E4640(Gfx **);
    void func_800E46E0(Gfx **, void *);
    void func_800E7FF8(Gfx **, s32);
    Gfx *sp5C;
    Gfx *sp58;

    if (D_801282E0.active) {
        D_801282E0.cull_enabled = 0;
        gSPEndDisplayList((*arg0)++);
        {
            Gfx *start = D_801282E0.buffers[D_801282E0.index];
            osWritebackDCache(start, (*arg0 - start) * sizeof(Gfx));
        }
        *arg0 = D_801282E0.saved_gfx;
        func_800E42E4(0);
        sp5C = (Gfx *)(D_801282E0.restore[D_801282E0.index]);
        func_800E4640(&sp5C);
        func_800BCC90(&sp5C);
        gSPEndDisplayList(sp5C++);
        sp58 = sp5C;
        func_800E4640(&sp5C);
        gSPEndDisplayList(sp5C++);
        {
            Gfx *start;
            osWritebackDCache(D_801282E0.restore[D_801282E0.index],
                (sp5C - (D_801282E0.restore[D_801282E0.index])) * sizeof(Gfx));
        }
        if (!D_801282E0.bounds_valid || func_800CAA24((f32 *)func_800E42A8(), BT_DATA_FIELD(D_801282E0.minimum, D_80128390), BT_DATA_FIELD(D_801282E0.maximum, D_8012839C))) {
            func_800E46E0(arg0, D_801282E0.restore[D_801282E0.index]);
            func_800BCC90(arg0);
            gSPClearGeometryMode((*arg0)++, 0x600);
            func_800E7FF8(arg0, 0x200);
            {
            struct ImageStruct *model;
            gSPDisplayList((*arg0)++, (BtUIntPtr)D_801282E0.buffers[D_801282E0.index] + 0x80000000);
            func_800E4640(arg0);
            gSPClearGeometryMode((*arg0)++, 0x600);
            func_800E7FF8(arg0, 0x400);
            if (D_801282E0.model) {
                model = func_800D674C(D_801282E0.model);
                if (!D_801282E0.bounds_cached) {
                    func_800B21CC((void *)func_800B2840((s32)model), BT_DATA_FIELD(D_801282E0.minimum, D_80128390), BT_DATA_FIELD(D_801282E0.maximum, D_8012839C));
                    D_801282E0.bounds_valid = 1;
                    D_801282E0.bounds_cached = D_801282E0.bounds_valid;
                }
                func_800DF440(0);
                func_800DF830(1);
                func_800DF410(D_801282E0.alpha);
                func_800DE498(arg0, NULL, NULL, 1.0f, NULL, (s32)model);
            }
            }
            D_801282E0.cull_enabled = 1;
        }
        func_800E46E0(arg0, sp58);
        gSPDisplayList((*arg0)++, (BtUIntPtr)D_801282E0.buffers[D_801282E0.index] + 0x80000000);
        D_801282E0.index ^= 1;
    }
}

void func_800BCC28(f32 *arg0, f32 *arg1) {
    void func_800F23D0(MtxF *, f32 *, f32 *);
    BT_IDO_ONLY(extern s32 D_801282F4;)
    func_800F23D0(BT_DATA_FIELD(&D_801282E0.matrix, (MtxF *)&D_801282F4), arg0, arg1);
}

int func_800BCC58(void) {
    return ((D_801282E0.active) != 0) && ((D_801282E0.cull_enabled) != 0);
}

u32 func_800BCC84(void) {
    BT_IDO_ONLY(extern u8 D_801282ED;)
    return BT_DATA_FIELD(D_801282E0.active, D_801282ED);
}

void func_800BCC90(Gfx **arg0) {
    BT_IDO_ONLY(extern s32 D_80128338;)
    gSPMatrix((*arg0)++, BT_DATA_FIELD((BtUIntPtr)&D_801282E0.fixed - 0x80000000U, &D_80128338 - 0x20000000),
              G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
}
#endif

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
Mtx * D_8012D558 BT_DATA(4, bss_core2bss2_1, 0xC18);
#endif
