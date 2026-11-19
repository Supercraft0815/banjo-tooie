#include "common.h"
#include "depth_compression.inc"
typedef struct FreeList FreeList;
#include "depth_frame_state.inc"
f32 func_800E81E0(s32 x, s32 y, f32 offset, f32 scale) {
    u16 func_8001A0C0(s32, s32);
    f32 mlAbsF(f32);



    f32 stack_padding[2];
    f32 difference;
    u16 sample;
    s32 *compression;

    sample = func_8001A0C0(x, y);
    compression = D_801234C0[(sample >> 0xD) & 7];
    y = (((sample >> 2) & 0x7FF) << compression[0]) + compression[1];
    difference = ((f32) ((y / 256) - 0x1FF) / 511.0f) - offset;
    return mlAbsF(difference) < 1e-06f ? 0.0f : scale / difference;
}

void func_800E829C(void) {
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    DEPTH_RETAIL(extern s32 D_8012D678;)
    int i;
    int j;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 5; i++) {
            DEPTH_FIELD(D_8012D600.depth[j][i].active, *(s32 *)((s8 *)&D_8012D600 + j * 60 + i * 12 + 12)) = 0;
        }
    }
}

void func_800E82EC(void) {
    void _chjiggygamenew_entrypoint_2(void);
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    u16 func_8001A0C0(s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800A8984(s32);
    void func_800CA6D4(void *, f32 *, f32 *);
    s32 func_800DA298(s32);
    f32 func_800E81E0(s32, s32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 mlAbsF(f32);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    typedef struct {
        f32 a;
        f32 b;
        s32 active;
    } Depth;
    typedef struct {
        s32 preceding;
        f32 a, b;
        s32 active;
    } DepthView;
    typedef struct {
        FreeList *list;
        Depth depth[2][5];
        s32 index;
    } State;
    typedef struct {
        f32 x, y, z, depth;
        f32 start[3];
        f32 end[3];
        f32 result[3];
        s16 visible;
        s16 valid;
    } Sample;
    typedef struct {
        f32 unused[3];
        f32 tolerance;
        Sample sample[2][5];
        s16 mode;
    } Entry;
    s32 i;
    s32 slot;
    s32 capacity;
    BtIntPtr camera;
    f32 near;
    f32 far;
    f32 reciprocal;
    Entry *entry;
    Sample *sample;
    DEPTH_FIELD(DepthSnapshot, DepthView) *depth;
    f32 difference;
    f32 factor = 2.0f;

    for (i = 0; i < 5; i++) {
        camera = func_800A8984(i);
        if (camera != 0) {
            func_800CA6D4((void *)camera, &near, &far);
            reciprocal = 1.0f / (near - far);
            DEPTH_STATE->depth[DEPTH_STATE->index][i].a = -((near + far) * reciprocal);
            DEPTH_STATE->depth[DEPTH_STATE->index][i].b = -(factor * near * far * reciprocal);
            DEPTH_STATE->depth[DEPTH_STATE->index][i].active = 1;
        } else {
            DEPTH_STATE->depth[DEPTH_STATE->index][i].active = 0;
        }
    }
    if (++DEPTH_STATE->index >= 2) {
        DEPTH_STATE->index = 0;
    }
    if (func_800DA298(0xD4E) || func_800DA298(0xD4F)) {
        _chjiggygamenew_entrypoint_2();
    }
    if (DEPTH_LIST != 0) {
        capacity = freelist_capacity(DEPTH_LIST);
        for (slot = 1; slot < capacity; slot++) {
            if (freelist_is_element_alive(DEPTH_LIST, slot)) {
                entry = freelist_at(DEPTH_LIST, slot);
                for (i = 0; i < 5; i++) {
                    sample = &entry->sample[DEPTH_STATE->index][i];
                    if (sample->valid && (depth = DEPTH_FIELD(&DEPTH_STATE->depth[DEPTH_STATE->index][i], (DepthView *)((u8 *)&DEPTH_STATE->depth[DEPTH_STATE->index][i] - 4)), depth->active)) {
                        if (!(sample->x < 0.0f) && !(sample->x >= 304.0f) && !(sample->y < 0.0f) && !(sample->y >= 228.0f)) {
                            switch (entry->mode) {
                                case 1:
                                    sample->depth = -func_800E81E0((s32)sample->x, (s32)sample->y, depth->a, depth->b);
                                    difference = sample->z - sample->depth;
                                    if (mlAbsF(difference) < entry->tolerance) {
                                        sample->visible = 1;
                                    } else if (difference > 0.0f) {
                                        sample->visible = 0;
                                    } else {
                                        sample->visible = 1;
                                    }
                                    func_800EFB24(sample->result, sample->end, sample->start);
                                    func_800EF334(sample->result, sample->depth / sample->z);
                                    func_800EF04C(sample->result, sample->start);
                                    break;
                                case 0:
                                    if (func_8001A0C0((s32)sample->x, (s32)sample->y) == 0xFFFC) {
                                        sample->visible = 1;
                                    } else {
                                        sample->visible = 0;
                                    }
                                    break;
                            }
                        } else {
                            sample->visible = -1;
                        }
                    } else {
                        sample->visible = -1;
                    }
                    sample->valid = 0;
                }
            }
        }
    }
}

void func_800E86DC(void) {
    void freelist_free(FreeList *);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    if (DEPTH_LIST != 0) {
        freelist_free(DEPTH_LIST);
        DEPTH_LIST = 0;
    }
}

u8 func_800E8714(s32 arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    void bzero(void *, int);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    typedef struct {
        f32 data[13];
        s16 visible;
        s16 valid;
    } Sample;
    typedef struct {
        f32 position[3];
        f32 radius;
        Sample samples[2][5];
        s16 mode;
    } Entry;
    s32 index;
    Entry *entry;
    s32 i;
    s32 j;

    if (DEPTH_LIST == NULL) {
        DEPTH_LIST = freelist_new(0x244, 4);
    }
    entry = freelist_next(&DEPTH_LIST, &index);
    bzero(entry, 0x244);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            entry->samples[i][j].visible = -1;
        }
    }
    entry->radius = 20.0f;
    entry->mode = arg0;
    return index;
}

void func_800E87E0(u8 arg0) {
    void freelist_erase(FreeList *, s32);
    void freelist_free(FreeList *);
    s32 freelist_used_count(FreeList *);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    freelist_erase(DEPTH_LIST, arg0);
    if (freelist_used_count(DEPTH_LIST) == 0) {
        freelist_free(DEPTH_LIST);
        DEPTH_LIST = 0;
    }
}

void func_800E8830(u8 arg0, f32 arg1[3]) {
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    void *freelist_at(FreeList *, s32);
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(freelist_at(DEPTH_LIST, arg0), arg1);
}

void func_800E8870(u8 arg0, f32 arg1) {
    void *freelist_at(FreeList *, s32);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    (*(f32 *)((s8 *)freelist_at(DEPTH_LIST, arg0) + 0xC)) = arg1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800E88AC(u8 arg0, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 *) arg1) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, BtIntPtr, BtIntPtr);
    BT_NATIVE_ONLY(return) func_800E8918(arg0, func_800A89F8(), 0, BT_NATIVE_ONLY((BtIntPtr)) arg1);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800E88E4(u8 arg0) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, BtIntPtr, BtIntPtr);
    BT_NATIVE_ONLY(return) func_800E8918(arg0, func_800A89F8(), 0, 0);
}

s32 func_800E8918(u8 arg0, s32 arg1, BtIntPtr arg2, BtIntPtr arg3) {
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    void *freelist_at(FreeList *, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800C4C34(s32, BtIntPtr, BtIntPtr, s32 *);
    f32 func_800E3928(BtIntPtr, BtIntPtr);
    void func_800E3980(f32 *);
    DEPTH_RETAIL(extern s32 D_8012D67C;)
    f32 sp34[3];
    u8 *entry;
    u8 *base;
    s32 result;
    s32 sp24;

    base = freelist_at(DEPTH_LIST, arg0);
    entry = (u8 *)((BtIntPtr)base + DEPTH_INDEX * 0x118) + arg1 * 0x38;
    entry += 0x10;
    if (*(s16 *)(entry + 0x36) != 0) {
        *(s16 *)(entry + 0x36) = 0;
    }
    result = func_800C4C34(arg1, (BtIntPtr)base, (BtIntPtr)entry, &sp24);
    if (sp24 != 0 && result != 0) {
        *(f32 *)(entry + 8) = func_800E3928((BtIntPtr)base, (BtIntPtr)sp34);
        func_800E3980((f32 *)(entry + 0x10));
        func_800EE7F8((f32 *)(entry + 0x1C), (f32 *)base);
        *(s16 *)(entry + 0x36) = 1;
    }
    if (arg3 != 0) {
        ((f32 *)arg3)[0] = ((f32 *)entry)[0];
        ((f32 *)arg3)[1] = ((f32 *)entry)[1];
    }
    if (arg2 != 0) {
        func_800EE7F8((f32 *)arg2, (f32 *)(entry + 0x28));
    }
    return *(s16 *)(entry + 0x34);
}

void func_800E8A20(void) {
    FreeList *freelist_defrag(FreeList *);
    DEPTH_RETAIL(extern FreeList *D_8012D600;)
    if (DEPTH_LIST != 0) {
        DEPTH_LIST = freelist_defrag(DEPTH_LIST);
    }
}
