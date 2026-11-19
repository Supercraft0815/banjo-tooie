/* The four player slots are followed by the shared view in slot four. */
#ifdef BT_NATIVE
#include "common.h"

typedef struct {
    void *unk0;
    union { BtIntPtr unk4; void *camera; };
    f32 unk8;
} ViewportSlot;

ViewportSlot D_80127688[5];
#define viewportSlots D_80127688
#ifdef BT_ILP32
_Static_assert(sizeof(ViewportSlot) == 12, "viewport record");
#endif
typedef ViewportSlot ViewportReleaseEntry;
#ifndef BT_ILP32
#include "native_camera_frame.h"
void func_80015CE8(void *, void *);

BtIntPtr func_800A88C4(s32 view, BtIntPtr camera, BtIntPtr unused) {
    ViewportSlot *slot = &viewportSlots[view];
    if (!slot->unk0) return 0;
    void *previous = slot->camera;
    slot->camera = (void *)camera;
    func_80015CE8(slot->unk0, slot->camera);
    if (view == VIEWPORT_CURRENT) func_800E42B4(slot->camera);
    return (BtIntPtr)previous;
}

BtIntPtr func_800A8948(s32 view) {
    ViewportSlot *slot = &viewportSlots[view];
    if (!slot->unk0) return 0;
    void *previous = slot->camera;
    slot->camera = NULL;
    if (view == VIEWPORT_CURRENT) func_800E42B4(viewportSlots[4].camera);
    return (BtIntPtr)previous;
}

BtIntPtr func_800A8984(s32 view) {
    return (BtIntPtr)viewportSlots[view].camera;
}

#endif

#define VIEWPORT_DEFAULT_CAMERA viewportSlots[4].camera
#define VIEWPORT_RELEASE_BEGIN viewportSlots
#define VIEWPORT_RELEASE_END (viewportSlots + 5)
#define VIEWPORT_RELEASE_HANDLE(entry) ((entry)->unk0)
#else
typedef unk_D_80127688 ViewportSlot;
#define viewportSlots D_80127688
typedef s32 ViewportReleaseEntry[3];
#define VIEWPORT_DEFAULT_CAMERA D_801276BC
#define VIEWPORT_RELEASE_BEGIN ((ViewportReleaseEntry *)((s8 *)&D_801276BC - 0x34))
#define VIEWPORT_RELEASE_END ((ViewportReleaseEntry *)&D_801276C4)
#define VIEWPORT_RELEASE_HANDLE(entry) ((entry)[0][0])
#endif
