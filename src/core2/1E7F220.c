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

void func_800A5A4C(void) {
    typedef struct { s32 id; CameraDistanceEntry *table; } MapEntry;
    extern CameraDistanceEntry *D_801270F0;
    extern CameraDistanceEntry D_80119BC0[];
    extern MapEntry D_80119BD8[];
    extern u8 D_8012762C;
    int i;
    int level = D_8012762C;
    D_801270F0 = D_80119BC0;
    for (i = 0; D_80119BD8[i].id != 0; i++) {
        if (D_80119BD8[i].id == level) {
            D_801270F0 = D_80119BD8[i].table;
        }
    }
}
