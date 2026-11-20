#include "common.h"
#include "overlays/ba/playerstate.h"

void func_800A5004(PlayerState *);
void func_800A5044(PlayerState *);
BtIntPtr func_800A5090(void *);
s32 func_800A3B70(void);
void *func_800CA334(void);

static unsigned destroyed;
static BtIntPtr destroyed_pointer;

void *func_800CA334(void) { return (void *)(uintptr_t)0x12345678AABBCCDDull; }
s32 func_800CA364(BtIntPtr camera) { destroyed++; destroyed_pointer = camera; return 0; }
s32 func_800A93E4(BtIntPtr arg) { (void)arg; return 0; }
s32 func_80110BF0(void *camera) { (void)camera; return 0; }
s32 func_80110C2C(void *camera) { (void)camera; return 0; }
s32 func_801106A8(PlayerState *player, s32 mode) { (void)player; (void)mode; return 0; }
s32 func_80090C28(PlayerState *player, s32 mode) { (void)player; (void)mode; return 0; }
PlayerState *func_80110014(s16 *camera) { (void)camera; return NULL; }
void func_80110CC0(BtIntPtr camera, f32 x, f32 y, f32 z, f32 zoom) { (void)camera; (void)x; (void)y; (void)z; (void)zoom; }
void func_80115564(u8 *player) { (void)player; }

int main(void) {
    PlayerState player = {0};
    union { u8 bytes[0x48]; u64 align; } state = {{0}};
    *(void **)((u8 *)&player + 0x38) = state.bytes;
    state.bytes[6] = 2;
    func_800A5004(&player);
    if (func_800A5090(&player) != (BtIntPtr)(uintptr_t)0x12345678AABBCCDDull) return 1;
    if (*(u32 *)(state.bytes + 0x3C) != 0) return 2;
    if (func_800A3B70() != 0x48) return 3;
    func_800A5044(&player);
    if (destroyed != 1 || destroyed_pointer != (BtIntPtr)(uintptr_t)0x12345678AABBCCDDull) return 4;
    if (func_800A5090(&player) != 0) return 5;
    return 0;
}
