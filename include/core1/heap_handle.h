#ifndef BT_CORE1_HEAP_HANDLE_H
#define BT_CORE1_HEAP_HANDLE_H
#include "common.h"

enum { HEAP_HANDLE_COUNT = 250 };
typedef struct {
    void *ptr;
    s32 type;
} HeapHandle;
extern HeapHandle D_8007BF10[HEAP_HANDLE_COUNT];
#ifdef BT_ILP32
_Static_assert(sizeof(HeapHandle) == 8, "heap handle layout");
#endif
#endif
