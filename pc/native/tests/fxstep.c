#include "overlays/ba/playerstate.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void func_800A300C(PlayerState *);
void *fxstep_entrypoint_1(void);
void fxstep_entrypoint_4(void *, BtIntPtr, s32);
void fxstep_entrypoint_7(void *, BtIntPtr, s32);

#if UINTPTR_MAX == UINT32_MAX
_Static_assert(sizeof(BtIntPtr) == 4, "O32 pointer words stay 32-bit");
_Static_assert(offsetof(PlayerState, unk124) == 0x124, "O32 PlayerState offset preserved");
#else
_Static_assert(sizeof(BtIntPtr) == 8, "LP64 handles retain full pointer width");
_Static_assert(sizeof(((PlayerState *)0)->unk124) == sizeof(void *), "native slot pointer width");
#endif

typedef struct {
    s32 id;
    f32 position[3];
    s32 unk10;
    s32 (*callback_a)(u8 *, s32, s32);
    s32 arg_a;
    s32 (*callback_b)(void *, s32, s32);
    s32 arg_b;
    u8 sound_a, sound_b, flag_a, flag_b;
} StepObject;
s32 func_800A26B0(void);
void func_800A2EDC(PlayerState *, f32);

static s32 callback_a_probe(u8 *p, s32 a, s32 b) { (void)p; (void)a; (void)b; return 0; }
static s32 callback_b_probe(void *p, s32 a, s32 b) { (void)p; (void)a; (void)b; return 0; }
static void *moved_from;
static void *moved_to;
static int allocation_bad;
void *heap_alloc(s32 size) {
    void *p = malloc((size_t)size);
    if (!p || (sizeof(void *) > 4 && (uintptr_t)p <= UINT32_MAX)) allocation_bad = 1;
    return p;
}
void heap_free(void *p) { free(p); }
u8 func_800C2E04(void) { static u8 next = 1; return next++; }
void func_800C330C(u8 a, s32 b) { (void)a; (void)b; }
void func_800C3418(u8 a, s32 b) { (void)a; (void)b; }
void func_800EFD24(f32 *v) { v[0] = v[1] = v[2] = 0.0f; }
s32 func_800D3948(void) { return 0; }
void func_800C2FDC(u8 id) { (void)id; }
void *func_800BC3F0(void *p) {
    void *q = malloc(sizeof(StepObject));
    if (!p || (uintptr_t)p <= UINT32_MAX || !q || (uintptr_t)q <= UINT32_MAX) allocation_bad = 2;
    for (size_t i = 0; i < sizeof(StepObject); i++) ((u8 *)q)[i] = ((u8 *)p)[i];
    moved_from = p; moved_to = q;
    return q;
}

int main(void) {
    PlayerState player = {0};
    PlayerFootstep state = {0};
    if (func_800A26B0() != sizeof(state)) return 1;
    player.unk124 = &state;
    state.mode = 7;
    func_800A2EDC(&player, 0.375f);
    if (state.mode != 7 || state.amount != 0.375f) return 1;
    player.unk184 = 0x12345678;
    void *created = fxstep_entrypoint_1();
    if (allocation_bad || !created || (sizeof(void *) > 4 && (uintptr_t)created <= UINT32_MAX)) return 1;
    state.effect = (BtIntPtr)(uintptr_t)created;
    fxstep_entrypoint_7(created, (BtIntPtr)(uintptr_t)callback_a_probe, player.unk184);
    fxstep_entrypoint_4(created, (BtIntPtr)(uintptr_t)callback_b_probe, player.unk184);
    StepObject *step = (StepObject *)(uintptr_t)state.effect;
    if (step->callback_a != callback_a_probe || step->callback_b != callback_b_probe ||
        (sizeof(void *) > 4 && ((uintptr_t)step->callback_a <= UINT32_MAX || (uintptr_t)step->callback_b <= UINT32_MAX)) ||
        step->arg_a != 0x12345678 || step->arg_b != 0x12345678) return 2;
    s32 (*callback_a)(u8 *, s32, s32) = step->callback_a;
    s32 (*callback_b)(void *, s32, s32) = step->callback_b;
    func_800A300C(&player);
    if (allocation_bad || !moved_from || !moved_to || moved_from == moved_to ||
        state.effect != (BtIntPtr)(uintptr_t)moved_to ||
        ((StepObject *)moved_to)->callback_a != callback_a ||
        ((StepObject *)moved_to)->callback_b != callback_b) return 3;
    if (state.effect != (BtIntPtr)(uintptr_t)moved_to || allocation_bad) return 4;
    free(moved_from);
    free(moved_to);
    return 0;
}
