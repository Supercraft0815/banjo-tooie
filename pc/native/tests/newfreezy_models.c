#include "common.h"
#include <stdint.h>
#include <stdio.h>

void func_808016B4_chnewfreezy(Actor *actor, s32 unused);

static unsigned char high_asset[64];
static unsigned char part_memory[3 * 0x60];
static u8 *got_assets[3];
static u32 draw_count;
static int fixture_error;

struct ImageStruct *func_800D674C(s32 asset_id) {
    if (asset_id < 0x74C || asset_id > 0x74E) fixture_error = 1;
    return (struct ImageStruct *)(void *)(high_asset + (asset_id - 0x74C) * 8);
}

void *func_800DE448(f32 *position, f32 *rotation, f32 scale, f32 *extra, u8 *asset) {
    (void)position; (void)rotation; (void)scale; (void)extra;
    if (draw_count < 3) got_assets[draw_count] = asset;
    else fixture_error = 1;
    draw_count++;
    return NULL;
}

s32 func_800E3E8C(f32 *position, f32 scale) {
    (void)position; (void)scale;
    return 1;
}

void *func_80100094(Actor *actor, u32 arg) {
    (void)actor;
    if (arg != 0) fixture_error = 1;
    return part_memory;
}

s32 subaddiefade_entrypoint_0(Actor *actor) {
    (void)actor;
    return 0xFF;
}

void func_800DF410(s32 value) { (void)value; }
void func_800DF830(s32 value) { (void)value; }

int main(void) {
    Actor actor = {0};
    u32 i;
    if ((uintptr_t)high_asset <= UINT32_MAX) return 2;
    for (i = 0; i < 3; i++) {
        part_memory[i * 0x60 + 0x5C] = 0; /* visible part */
        part_memory[i * 0x60 + 0x5D] = (u8)i; /* model slot 0, 1, 2 */
    }
    actor.unk6C_0 = 3;
    actor.unk74_7 = 1;
    func_808016B4_chnewfreezy(&actor, 0);
    for (i = 0; i < 3; i++) {
        u8 *expected = high_asset + i * 8;
        printf("slot%u asset=%p received=%p\n", i, (void *)expected, (void *)got_assets[i]);
        if (got_assets[i] != expected) fixture_error = 1;
    }
    if (fixture_error || draw_count != 3) return 3;
    return 0;
}
