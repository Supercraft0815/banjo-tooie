#include "common.h"

typedef struct {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    s32 stride, capacity;
#else
    s16 stride, capacity;
#endif
    s32 frame;
    void *data;
} VertexScratch;

VertexScratch D_801243A0[5] BT_DATA(4, vertex_scratch, 0) = {
    {3, 0, 0, NULL}, {4, 0, 0, NULL}, {12, 0, 0, NULL}, {12, 0, 0, NULL}, {6, 0, 0, NULL},
};
