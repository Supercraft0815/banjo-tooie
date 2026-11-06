#ifndef NATIVE_SCHEDULER_H
#define NATIVE_SCHEDULER_H

#include <ultra64.h>

// Task record passed from core1/1E31B40.c to the scheduler in core1/1E2B840.c:
// its AudioTask (type 0) and GraphicsTask (type 1) with host-width pointers.
typedef struct {
    s32 type;
    s32 flags;
    void *start;
    void *end;
    OSMesgQueue *queue;
    OSMesg msg;
} NativeSchedulerTask;

#endif
