#include "camera_tint.inc"
#include "core1/heap.h"
s32 func_80114E80(s32 arg0) { u8 *base = (u8 *)D_80124A50.rows; u8 *p = (u8 *)D_80124A50.rows; if (D_80124A50.rows[0].map != 0) { do { if (arg0 == *p) { return (p - base) / 5; } p += 5; } while (*p != 0); } return (p - base) / 5; }                 typedef struct { BtIntPtr unk0; u8 pad4[0x4]; f32 unk8; u8 padC[0x1]; s8 unkD; u8 padE[0x2]; f32 unk10; } Obj1EEE770_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80114EEC(void *arg0, BtIntPtr arg1) {
    s32 pad;
    f32 func_80013970(f32);
    s32 func_800A940C(s32);
    void func_800C4B90(s32 arg0, f32 arg1, f32 arg2);
    s32 func_800EA068(s32);
    BtIntPtr func_80110014(s32 *arg0);
    s32 func_80110840(BtIntPtr);
    f32 sp28;
    f32 sp24;

    sp24 = func_80013970(TINT_FIELD(arg0, phase, (((Obj1EEE770_arg0 *)arg0)->unk10))) * 1.5f;
    sp28 = func_80013970(TINT_FIELD(arg0, phase, (((Obj1EEE770_arg0 *)arg0)->unk10)) * 1.5f) * 1.5f;
    if (func_800EA068(0x20) == 0) {
        func_800C4B90(func_800A940C(func_80110840(func_80110014(TINT_FIELD(arg0, controller, (((Obj1EEE770_arg0 *)arg0)->unk0))))), sp24, sp28);
        TINT_FIELD(arg0, oscillating, (((Obj1EEE770_arg0 *)arg0)->unkD)) = 1;
        TINT_FIELD(arg0, phase, (((Obj1EEE770_arg0 *)arg0)->unk10)) = (f32) (TINT_FIELD(arg0, phase, (((Obj1EEE770_arg0 *)arg0)->unk10)) + 2.0f);
    }
}

void func_80114FA4(Gfx **arg0, u8 *arg1) {
    void func_800B99CC(Gfx **, s32, s32 *);

    s32 i;
    f32 fraction;
    u8 component;
    s32 color[3];
    u8 (*table)[5] = (u8 (*)[5])D_80124A50.rows;
    f32 alpha;

    if (TINT_FIELD(arg1, submerged, arg1[0xC]) != 0) {
        if (TINT_FIELD(arg1, draw, arg1[0xE]) != 0) {
            if (3000.0f < TINT_FIELD(arg1, depth, *(f32 *)(arg1 + 8))) {
                fraction = 1.0f;
            } else {
                fraction = TINT_FIELD(arg1, depth, *(f32 *)(arg1 + 8)) * 0.00033333333f;
            }
            for (i = 0; i != 3; i++) {
                component = table[TINT_FIELD(arg1, preset, *(s32 *)(arg1 + 4))][i + 1];
                color[i] = -(s32)component * (fraction * 0.4f) + (f32)component;
            }
            alpha = (f32)table[TINT_FIELD(arg1, preset, *(s32 *)(arg1 + 4))][4];
            func_800B99CC(arg0, (s32)(alpha * fraction + alpha), color);
        }
    }
}

u32 func_801150F0(u8 *arg0) {
    return TINT_FIELD(arg0, submerged, arg0[12]);
}

void func_801150F8(void* arg0) 
{
    heap_free(arg0);
}

void *func_80115118(BtIntPtr arg0) {
    s32 func_800EA05C();
    s32 func_80114E80(s32);
    s16 *ptr;
    s16 map;
    CameraTintEffect *result;

    result = heap_alloc(sizeof(*result));
    result->controller = (void *)arg0;
    result->preset = func_80114E80(func_800EA05C());
    result->submerged = 0;
    result->oscillating = 0;
    result->draw = 1;
    result->phase = 0.0f;
    map = func_800EA05C();
    ptr = D_80124A58;
    while (*ptr != 0) {
        if (map == *ptr) {
            result->draw = 0;
            break;
        }
        ptr++;
    }
    return result;
}

void func_801151C4(void *arg0) {
    s32 func_800BEAAC(BtIntPtr, BtIntPtr);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800CA7E4(BtIntPtr, s32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    BtIntPtr func_8010FF80(s32 *);

    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    s32 pad;
    BtIntPtr camera;
    s32 *triangle;
    u8 flag;

    camera = func_8010FF80(TINT_FIELD(arg0, controller, *(s32 **)arg0));
    func_800CA7E4(camera, (s32 *)sp40);
    if (func_800BEAAC((BtIntPtr)sp40, (BtIntPtr)&sp30) == 0) {
        func_800EFA4C(sp34, sp40[0], sp40[1] + 10000.0f, sp40[2]);
        triangle = func_800BEF00(sp40, sp34, sp4C, 0x1F00);
        if (triangle != NULL) {
            flag = (triangle[2] & 0x20000) ? 1 : 0;
            TINT_FIELD(arg0, submerged, *((u8 *)arg0 + 0xC)) = flag;
        } else {
            TINT_FIELD(arg0, submerged, *((u8 *)arg0 + 0xC)) = 0;
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
            TINT_FIELD(arg0, submerged, *((u8 *)arg0 + 0xC)) = 1;
        } else {
            TINT_FIELD(arg0, submerged, *((u8 *)arg0 + 0xC)) = 0;
        }
    }
    if (TINT_FIELD(arg0, submerged, *((u8 *)arg0 + 0xC)) != 0) {
        TINT_FIELD(arg0, depth, ((Obj1EEE770_arg0 *)arg0)->unk8) = sp34[1] - sp40[1];
        func_80114EEC(arg0, camera);
    }
}

/* extern */

s32 *func_80115324(s32 *arg0, BtIntPtr arg1) {
    void *defrag(void *);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    ((CameraTintEffect *)arg0)->controller = (void *)arg1;
#else
    *arg0 = arg1;
#endif
    return defrag(arg0);
}
