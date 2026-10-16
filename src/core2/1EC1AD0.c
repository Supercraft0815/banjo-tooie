#include "common.h"

typedef struct FreeList FreeList;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E81E0.s")

void func_800E829C(void) {
    extern FreeList *D_8012D600;
    extern s32 D_8012D678;
    int i;
    int j;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 5; i++) {
            *(s32 *)((s8 *)&D_8012D600 + j * 60 + i * 12 + 12) = 0;
        }
    }
}

void func_800E82EC(void) {
    void _chjiggygamenew_entrypoint_2(void);
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    s32 func_8001A0C0(s32, s32);
    s32 func_800A8984(s32);
    void func_800CA6D4(void *, f32 *, f32 *);
    s32 func_800DA298(s32);
    f32 func_800E81E0(s32, s32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 mlAbsF(f32);
    extern FreeList *D_8012D600;
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
    s32 camera;
    f32 near;
    f32 far;
    f32 reciprocal;
    Entry *entry;
    Sample *sample;
    DepthView *depth;
    f32 difference;
    f32 factor = 2.0f;

    for (i = 0; i < 5; i++) {
        camera = func_800A8984(i);
        if (camera != 0) {
            func_800CA6D4((void *)camera, &near, &far);
            reciprocal = 1.0f / (near - far);
            ((State *)&D_8012D600)->depth[((State *)&D_8012D600)->index][i].a = -((near + far) * reciprocal);
            ((State *)&D_8012D600)->depth[((State *)&D_8012D600)->index][i].b = -(factor * near * far * reciprocal);
            ((State *)&D_8012D600)->depth[((State *)&D_8012D600)->index][i].active = 1;
        } else {
            ((State *)&D_8012D600)->depth[((State *)&D_8012D600)->index][i].active = 0;
        }
    }
    if (++((State *)&D_8012D600)->index >= 2) {
        ((State *)&D_8012D600)->index = 0;
    }
    if (func_800DA298(0xD4E) || func_800DA298(0xD4F)) {
        _chjiggygamenew_entrypoint_2();
    }
    if (D_8012D600 != 0) {
        capacity = freelist_capacity(D_8012D600);
        for (slot = 1; slot < capacity; slot++) {
            if (freelist_is_element_alive(D_8012D600, slot)) {
                entry = freelist_at(D_8012D600, slot);
                for (i = 0; i < 5; i++) {
                    sample = &entry->sample[((State *)&D_8012D600)->index][i];
                    if (sample->valid && (depth = (DepthView *)((u8 *)&((State *)&D_8012D600)->depth[((State *)&D_8012D600)->index][i] - 4), depth->active)) {
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
    extern FreeList *D_8012D600;
    if (D_8012D600 != 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

u8 func_800E8714(s32 arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    void bzero(void *, int);
    extern FreeList *D_8012D600;
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

    if (D_8012D600 == NULL) {
        D_8012D600 = freelist_new(0x244, 4);
    }
    entry = freelist_next(&D_8012D600, &index);
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
    extern FreeList *D_8012D600;
    freelist_erase(D_8012D600, arg0);
    if (freelist_used_count(D_8012D600) == 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

void func_800E8830(u8 arg0, f32 arg1[3]) {
    extern FreeList *D_8012D600;
    void *freelist_at(FreeList *, s32);
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(freelist_at(D_8012D600, arg0), arg1);
}

void func_800E8870(u8 arg0, f32 arg1) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_8012D600;
    (*(f32 *)((s8 *)freelist_at(D_8012D600, arg0) + 0xC)) = arg1;
}

/* extern */

void func_800E88AC(u8 arg0, s32 arg1) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, s32, s32);
    func_800E8918(arg0, func_800A89F8(), 0, arg1);
}

/* extern */

void func_800E88E4(u8 arg0) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, s32, s32);
    func_800E8918(arg0, func_800A89F8(), 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8918.s")

void func_800E8A20(void) {
    FreeList *freelist_defrag(FreeList *);
    extern FreeList *D_8012D600;
    if (D_8012D600 != 0) {
        D_8012D600 = freelist_defrag(D_8012D600);
    }
}
