#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E81E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E829C.s")

void func_800E82EC(void) {
    void _chjiggygamenew_entrypoint_2(void);
    void *freelist_at(s32, s32);
    s32 freelist_capacity(s32);
    s32 freelist_is_element_alive(s32, s32);
    s32 func_8001A0C0(s32, s32);
    s32 func_800A8984(s32);
    void func_800CA6D4(void *, f32 *, f32 *);
    s32 func_800DA298(s32);
    f32 func_800E81E0(s32, s32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 mlAbsF(f32);
    extern s32 D_8012D600;
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
        s32 list;
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
    s32 freelist_free(s32);
    extern s32 D_8012D600;
    if (D_8012D600 != 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8714.s")

void func_800E87E0(u8 arg0) {
    s32 freelist_erase(s32, s32);
    s32 freelist_free(s32);
    s32 freelist_used_count(s32);
    extern s32 D_8012D600;
    freelist_erase(D_8012D600, arg0);
    if (freelist_used_count(D_8012D600) == 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8830.s")

void func_800E8870(u8 arg0, f32 arg1) {
    void *freelist_at(s32, s32);
    extern s32 D_8012D600;
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
    s32 freelist_defrag(s32);
    extern s32 D_8012D600;
    if (D_8012D600 != 0) {
        D_8012D600 = freelist_defrag(D_8012D600);
    }
}
