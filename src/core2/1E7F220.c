#include "common.h"

typedef struct {
    s16 map_id;
    s16 entry_id;
    s16 near[3];
    s16 medium[3];
    s16 far[3];
} CameraDistanceEntry;

CameraDistanceEntry *func_800A5930(s32 id) {
    extern CameraDistanceEntry *D_801270F0;
    s32 func_800EA05C(void);
    s32 map_id = func_800EA05C();
    s32 i;
    for (i = 0; D_801270F0[i].map_id != 0; i++) {
        if (map_id == D_801270F0[i].map_id && id == D_801270F0[i].entry_id) {
            return &D_801270F0[i];
        }
    }
    return &D_801270F0[i];
}

void func_800A59B8(s32 id, s32 *vec11, s32 *vec12, s32 *vec13, s32 *vec21, s32 *vec22, s32 *vec23, s32 *vec31, s32 *vec32, s32 *vec33) {
    CameraDistanceEntry *ptr = func_800A5930(id);
    *vec11 = ptr->near[0];
    *vec12 = ptr->near[1];
    *vec13 = ptr->near[2];
    *vec21 = ptr->medium[0];
    *vec22 = ptr->medium[1];
    *vec23 = ptr->medium[2];
    *vec31 = ptr->far[0];
    *vec32 = ptr->far[1];
    *vec33 = ptr->far[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F220/func_800A5A4C.s")
