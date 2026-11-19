#ifndef BT_MARKER_HIT_CALLBACKS_H
#define BT_MARKER_HIT_CALLBACKS_H

typedef struct {
    void (*collision[3])(void *, void *);
    void (*impact)(void *, void *, s32);
    s32 (*accept)(void *, void *);
} MarkerHitMethods;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define MARKER_HIT_LAYOUT(native, retail) native
#else
#define MARKER_HIT_LAYOUT(native, retail) retail
#endif

#endif
