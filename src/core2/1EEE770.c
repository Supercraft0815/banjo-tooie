#include "common.h"

s32 func_80114E80(s32 arg0) { extern u8 D_80124A50; u8 *base = &D_80124A50; u8 *p = &D_80124A50; if (D_80124A50 != 0) { do { if (arg0 == *p) { return (p - base) / 5; } p += 5; } while (*p != 0); } return (p - base) / 5; }

/* extern */

void func_80114EEC(void *arg0, s32 arg1) {
    s32 pad;
    f32 func_80013970(f32);
    s32 func_800A940C(s32);
    s32 func_800C4B90(s32, f32, f32);
    s32 func_800EA068(s32);
    s32 func_80110014(s32);
    s32 func_80110840(s32);
    f32 sp28;
    f32 sp24;

    sp24 = func_80013970((*(f32 *)((s8 *)(arg0) + (0x10)))) * 1.5f;
    sp28 = func_80013970((*(f32 *)((s8 *)(arg0) + (0x10))) * 1.5f) * 1.5f;
    if (func_800EA068(0x20) == 0) {
        func_800C4B90(func_800A940C(func_80110840(func_80110014((*(s32 *)((s8 *)(arg0) + (0)))))), sp24, sp28);
        (*(s8 *)((s8 *)(arg0) + (0xD))) = 1;
        (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x10))) + 2.0f);
    }
}

void func_80114FA4(Gfx **arg0, u8 *arg1) {
    void func_800B99CC(Gfx **, s32, s32 *);
    extern u8 D_80124A50;
    extern f32 D_80126600, D_80126604, D_80126608;
    s32 i;
    f32 fraction;
    u8 component;
    s32 color[3];
    u8 (*table)[5] = (u8 (*)[5])&D_80124A50;
    f32 alpha;

    if (arg1[0xC] != 0) {
        if (arg1[0xE] != 0) {
            if (D_80126600 < *(f32 *)(arg1 + 8)) {
                fraction = 1.0f;
            } else {
                fraction = *(f32 *)(arg1 + 8) * D_80126604;
            }
            for (i = 0; i != 3; i++) {
                component = table[*(s32 *)(arg1 + 4)][i + 1];
                color[i] = -(s32)component * (fraction * D_80126608) + (f32)component;
            }
            alpha = (f32)table[*(s32 *)(arg1 + 4)][4];
            func_800B99CC(arg0, (s32)(alpha * fraction + alpha), color);
        }
    }
}

u32 func_801150F0(u8 *arg0) {
    return arg0[12];
}

void func_801150F8(void* arg0) 
{
    heap_free(arg0);
}
void *func_80115118(s32 arg0) {
    s32 func_800EA05C();
    s32 func_80114E80(s32);
    extern s16 D_80124A58;
    s16 *ptr;
    s16 map;
    void *result;

    result = heap_alloc(0x14);
    (*(s32 *)((s8 *)result + 0)) = arg0;
    (*(s32 *)((s8 *)result + 4)) = func_80114E80(func_800EA05C());
    (*(s8 *)((s8 *)result + 0xC)) = 0;
    (*(s8 *)((s8 *)result + 0xD)) = 0;
    (*(s8 *)((s8 *)result + 0xE)) = 1;
    (*(f32 *)((s8 *)result + 0x10)) = 0.0f;
    map = func_800EA05C();
    ptr = &D_80124A58;
    while (*ptr != 0) {
        if (map == *ptr) {
            (*(s8 *)((s8 *)result + 0xE)) = 0;
            break;
        }
        ptr++;
    }
    return result;
}

void func_801151C4(void *arg0) {
    s32 func_800BEAAC(s32, s32);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800CA7E4(s32, s32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_8010FF80(s32 *);
    extern f32 D_8012660C;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    s32 pad;
    s32 camera;
    s32 *triangle;
    u8 flag;

    camera = func_8010FF80(*(s32 **)arg0);
    func_800CA7E4(camera, (s32 *)sp40);
    if (func_800BEAAC((s32)sp40, (s32)&sp30) == 0) {
        func_800EFA4C(sp34, sp40[0], sp40[1] + D_8012660C, sp40[2]);
        triangle = func_800BEF00(sp40, sp34, sp4C, 0x1F00);
        if (triangle != NULL) {
            flag = (triangle[2] & 0x20000) ? 1 : 0;
            *((u8 *)arg0 + 0xC) = flag;
        } else {
            *((u8 *)arg0 + 0xC) = 0;
        }
    } else {
        sp34[0] = sp40[0];
        sp34[2] = sp40[2];
        sp34[1] = sp40[1] + 1000.0f;
        triangle = func_800BEF00(sp40, sp34, sp4C, 0x1F00);
        if (triangle == NULL || !(triangle[2] & 0x20000)) {
            sp34[1] = sp30;
        }
        if (sp40[1] <= sp34[1]) {
            *((u8 *)arg0 + 0xC) = 1;
        } else {
            *((u8 *)arg0 + 0xC) = 0;
        }
    }
    if (*((u8 *)arg0 + 0xC) != 0) {
        *(f32 *)((u8 *)arg0 + 8) = sp34[1] - sp40[1];
        func_80114EEC(arg0, camera);
    }
}

/* extern */

s32 *func_80115324(s32 *arg0, s32 arg1) {
    void *defrag(void *);
    *arg0 = arg1;
    return defrag(arg0);
}
