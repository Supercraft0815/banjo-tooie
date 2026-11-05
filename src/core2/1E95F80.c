#ifdef BT_NATIVE
#include "1E95F80_native.inc"
#else
#include "common.h"

void func_800BC690(void) {
    void func_800B5680(s32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void *heap_alloc(s32);
    typedef struct { s16 map, count, mode, flag; f32 point[3]; f32 normal[3]; } Entry;
    typedef struct { void *buffers[2]; s32 unk8; u8 unkC, active, unkE, unkF, unk10, mode; s16 count; f32 matrix[4][4]; } State;
    extern Entry D_8011A760[3];
    extern s8 D_8011A7C0[];
    extern s32 D_801282E0, D_801282F4, D_80128338;
    extern f32 D_80128324[], D_80128378[], D_80128384[];
    s32 i;
    s32 map;
    f32 normal[3];

    map = func_800EA05C();
    i = 0;
    do {
        if (map == D_8011A760[i].map) break;
        i++;
    } while (i < 3);
    if (D_8011A7C0 != (s8 *)&D_8011A760[i]) {
        if (D_8011A760[i].flag) {
            func_800B5680((s32)D_8011A760[i].point[1]);
        }
        ((State *)&D_801282E0)->unk10 = ((State *)&D_801282E0)->active = 1;
        ((State *)&D_801282E0)->unkF = ((State *)&D_801282E0)->unkE = 0;
        ((State *)&D_801282E0)->count = D_8011A760[i].count;
        ((State *)&D_801282E0)->mode = D_8011A760[i].mode;
        *(void **)&D_801282E0 = heap_alloc(0x5DC0);
        *(void **)((s8 *)&D_801282E0 + 4) = heap_alloc(0x5DC0);
        func_800EF410(normal, D_8011A760[i].normal);
        ((f32 *)&D_801282E0)[5] = 1.0f - (2.0f * normal[0]) * normal[0];
        ((f32 *)&D_801282E0)[9] = (2.0f * -normal[1]) * normal[0];
        ((f32 *)&D_801282E0)[13] = (2.0f * -normal[2]) * normal[0];
        ((f32 *)&D_801282E0)[6] = (2.0f * -normal[0]) * normal[1];
        ((f32 *)&D_801282E0)[10] = 1.0f - (2.0f * normal[1]) * normal[1];
        ((f32 *)&D_801282E0)[14] = (2.0f * -normal[2]) * normal[1];
        ((f32 *)&D_801282E0)[7] = (2.0f * -normal[0]) * normal[2];
        ((f32 *)&D_801282E0)[11] = (2.0f * -normal[1]) * normal[2];
        ((f32 *)&D_801282E0)[15] = 1.0f - (2.0f * normal[2]) * normal[2];
        ((f32 *)&D_801282E0)[8] = ((f32 *)&D_801282E0)[12] = ((f32 *)&D_801282E0)[16] = 0.0f;
        func_800EFA20(D_80128324, normal, 2.0f * func_800EEAA4(D_8011A760[i].point, normal));
        ((f32 *)&D_801282E0)[20] = 1.0f;
        guMtxF2L((f32 (*)[4])&D_801282F4, (Mtx *)&D_80128338);
        func_800EE7F8(D_80128384, normal);
        func_800EE7F8(D_80128378, D_8011A760[i].point);
    }
}

void func_800BC8A0(void) {
    s32 heap_free(s32);
    extern s32 D_801282E0;
    if ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) {
        heap_free((*(s32 *)((s8 *)(&D_801282E0) + (0))));
        heap_free((*(s32 *)((s8 *)(&D_801282E0) + (4))));
        (*(s32 *)((s8 *)(&D_801282E0) + (4))) = 0;
        (*(s32 *)((s8 *)(&D_801282E0) + (0))) = 0;
        (*(u8 *)((s8 *)(&D_801282E0) + (0xD))) = 0U;
    }
}

/* extern */

void func_800BC8F8(s32 *arg0) {
    extern s32 D_801282E0;
    s32 func_800E42E4(s32);
    if ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) {
        (*(s32 *)((s8 *)(&D_801282E0) + (8))) = (s32) *arg0;
        *arg0 = (&D_801282E0)[(*(u8 *)((s8 *)(&D_801282E0) + (0xC)))];
        func_800E42E4(1);
    }
}

void func_800BC948(Gfx **arg0) {
    extern s32 D_801282E0;
    extern f32 D_80128390[], D_8012839C[];
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

    if (*(u8 *)((u8 *)&D_801282E0 + 0xD)) {
        *(u8 *)((u8 *)&D_801282E0 + 0x10) = 0;
        gSPEndDisplayList((*arg0)++);
        {
            Gfx *start = ((Gfx **)&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)];
            osWritebackDCache(start, (*arg0 - start) * sizeof(Gfx));
        }
        *arg0 = *(Gfx **)((u8 *)&D_801282E0 + 8);
        func_800E42E4(0);
        sp5C = (Gfx *)(((Gfx (*)[6])&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 25);
        func_800E4640(&sp5C);
        func_800BCC90(&sp5C);
        gSPEndDisplayList(sp5C++);
        sp58 = sp5C;
        func_800E4640(&sp5C);
        gSPEndDisplayList(sp5C++);
        {
            Gfx *start;
            osWritebackDCache(((Gfx (*)[6])&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 25,
                (sp5C - (((Gfx (*)[6])&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 25)) * sizeof(Gfx));
        }
        if (!*(u8 *)((u8 *)&D_801282E0 + 0xE) || func_800CAA24((f32 *)func_800E42A8(), D_80128390, D_8012839C)) {
            func_800E46E0(arg0, ((Gfx (*)[6])&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 25);
            func_800BCC90(arg0);
            gSPClearGeometryMode((*arg0)++, 0x600);
            func_800E7FF8(arg0, 0x200);
            {
            struct ImageStruct *model;
            gSPDisplayList((*arg0)++, (&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 0x80000000);
            func_800E4640(arg0);
            gSPClearGeometryMode((*arg0)++, 0x600);
            func_800E7FF8(arg0, 0x400);
            if (*(s16 *)((u8 *)&D_801282E0 + 0x12)) {
                model = func_800D674C(*(s16 *)((u8 *)&D_801282E0 + 0x12));
                if (!*(u8 *)((u8 *)&D_801282E0 + 0xF)) {
                    func_800B21CC((void *)func_800B2840((s32)model), D_80128390, D_8012839C);
                    *(u8 *)((u8 *)&D_801282E0 + 0xE) = 1;
                    *(u8 *)((u8 *)&D_801282E0 + 0xF) = *(u8 *)((u8 *)&D_801282E0 + 0xE);
                }
                func_800DF440(0);
                func_800DF830(1);
                func_800DF410(*(u8 *)((u8 *)&D_801282E0 + 0x11));
                func_800DE498(arg0, NULL, NULL, 1.0f, NULL, (s32)model);
            }
            }
            *(u8 *)((u8 *)&D_801282E0 + 0x10) = 1;
        }
        func_800E46E0(arg0, sp58);
        gSPDisplayList((*arg0)++, (&D_801282E0)[*(u8 *)((u8 *)&D_801282E0 + 0xC)] + 0x80000000);
        *(u8 *)((u8 *)&D_801282E0 + 0xC) ^= 1;
    }
}

void func_800BCC28(s32 arg0, s32 arg1) {
    s32 func_800F23D0(s32 *, s32, s32);
    extern s32 D_801282F4;
    func_800F23D0(&D_801282F4, arg0, arg1);
}

int func_800BCC58(void) {
    extern s32 D_801282E0;
    return ((*(u8 *)((s8 *)(&D_801282E0) + (0xD))) != 0) && ((*(u8 *)((s8 *)(&D_801282E0) + (0x10))) != 0);
}

u32 func_800BCC84(void) {
    extern u8 D_801282ED;
    return *(u8 *)((u8 *)&D_801282ED + 0);
}

void func_800BCC90(Gfx **arg0) {
    extern s32 D_80128338;
    gSPMatrix((*arg0)++, &D_80128338 - 0x20000000,
              G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
}
#endif
