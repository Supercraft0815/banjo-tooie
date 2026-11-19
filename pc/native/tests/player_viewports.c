#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "core2/viewport_slots.inc"
#include "core2/player_viewports.inc"

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "%d: %s\n", __LINE__, #expr); abort(); } } while (0)

BtIntPtr func_8010FF80(s32 *);
BtIntPtr func_80110014(s32 *);
BtIntPtr func_80110060(s32 *);

s32 D_80127674;
static unsigned allocations;
static void *rendererCamera[4];

/* Force every live allocation to move during defrag, preserving the game's payload. */
typedef union { max_align_t alignment; size_t size; } Allocation;
void *heap_alloc(s32 size) {
    Allocation *block = malloc(sizeof(*block) + size);
    CHECK(size > 0 && block && (uintptr_t)(block + 1) > UINT32_MAX);
    block->size = size;
    allocations++;
    return block + 1;
}
void heap_free(void *payload) {
    CHECK(payload && allocations);
    free((Allocation *)payload - 1);
    allocations--;
}
void *defrag(void *payload) {
    size_t size = ((Allocation *)payload - 1)->size;
    void *moved = heap_alloc(size);
    for (size_t i = 0; i < size; i++) ((u8 *)moved)[i] = ((u8 *)payload)[i];
    heap_free(payload);
    return moved;
}

BtIntPtr _gcsectionDll_entrypoint_2(s32 section) { return section; }
s32 _gcsectionDll_entrypoint_3(BtIntPtr section, s32 mask) { return section == 7 && mask == 0x20; }
void _gcstatusDll_entrypoint_1(s32 section) { CHECK(section == 7); }
u8 _gcstatusDll_entrypoint_11(void) { return 4; }

s32 func_800A877C(s32 view) { viewportSlots[view].unk0 = &rendererCamera[view]; return 0; }
s32 func_800A87FC(s32 view) { viewportSlots[view].unk0 = NULL; return 0; }
void func_80015CE8(void *renderer, void *camera) { *(void **)renderer = camera; }

/* Movement and projection are child allocations owned by the real camera controller. */
void *func_80110424(s32 *owner, s32 player) {
    void **movement = heap_alloc(sizeof(*movement));
    *movement = owner;
    return movement;
}
void func_801104F4(void *movement) { heap_free(movement); }
s32 *func_80110FCC(s32 *movement, BtIntPtr owner) {
    void **moved = defrag(movement);
    *moved = (void *)owner;
    return (s32 *)moved;
}
void *func_80114BD4(void) { return heap_alloc(sizeof(f32)); }
void func_80114C7C(void *projection) { heap_free(projection); }
void *func_80114CD4(void *projection) { return defrag(projection); }
s32 func_800DA298(s32 flag) { CHECK(flag == 0x6B5); return 0; }
void *func_80115118(BtIntPtr owner) { abort(); }
void func_801150F8(void *effect) { abort(); }
s32 *func_80115324(s32 *effect, BtIntPtr owner) { abort(); }
void *_ncfixposrot_entrypoint_0(void) { abort(); }
void _ncfixposrot_entrypoint_1(void *state) { abort(); }
s16 _ncpod_entrypoint_0(s32 player) { abort(); }
void _ncpod_entrypoint_1(s16 pod) { abort(); }
void func_80110B68(void *movement, s32 active) { abort(); }

int main(void) {
    uintptr_t old[8][4];
    NativeCamera shared;
    viewportSlots[4].camera = &shared;
    D_80127674 = 2;
    func_800A8D70(7, 0);
    for (s32 i = 0; i < 8; i++) {
        CHECK(func_800A907C(i, i % 4, -1) == i % 4);
        s32 *control = (s32 *)func_800A93E4(i);
        old[i][0] = func_800A93F8(i);
        old[i][1] = (uintptr_t)control;
        old[i][2] = func_80110014(control);
        old[i][3] = func_80110060(control);
        CHECK((uintptr_t)func_8010FF80(control) == old[i][0]);
        CHECK(func_800A9420(i) == (i < 4));
    }
    CHECK(func_800A9460() == 8);
    func_800A91A8(6);
    func_800A95C4(0, 0, 0);
    for (s32 i = 0; i < 8; i++) {
        s32 *control = (s32 *)func_800A93E4(i);
        uintptr_t current[] = {func_800A93F8(i), (uintptr_t)control,
                               func_80110014(control), func_80110060(control)};
        for (s32 field = 0; field < 4; field++) {
            CHECK(current[field] > UINT32_MAX && current[field] != old[i][field]);
        }
        CHECK((uintptr_t)func_8010FF80(control) == current[0]);
        CHECK(*(void **)current[2] == control);
        if (i == 0 || i == 1 || i == 3 || i == 6) {
            CHECK((uintptr_t)func_800A8984(i % 4) == current[0]);
            CHECK(rendererCamera[i % 4] == (void *)current[0]);
        }
    }
    CHECK(func_800E42A8() == (NativeCamera *)func_800A93F8(6));
    func_800A91F4(2);
    CHECK(func_800A8984(2) == func_800A93F8(6));
    func_800A91F4(6);
    CHECK(!func_800A8984(2) && !func_800A93E4(6) && !func_800A93F8(6));
    CHECK(func_800E42A8() == &shared);
    func_800A8F68();
    CHECK(!allocations && !func_800A9460() && !func_800A946C());
    /* Joining with a separate view, then selecting by pad, can attach one camera twice. */
    func_800A8D70(7, 0);
    CHECK(func_800A907C(0, 2, 1) == 2);
    func_800A91A8(0);
    func_800A95C4(0, 0, 0);
    CHECK(func_800A8984(1) == func_800A93F8(0) && func_800A8984(2) == func_800A93F8(0));
    func_800A8F68();
    CHECK(!func_800A8984(1) && !func_800A8984(2) && !allocations && func_800E42A8() == &shared);
    return 0;
}
