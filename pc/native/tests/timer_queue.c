#include "common.h"
#include "core2/1EA1DA0.h"
#include "native_actor.h"
#include "vector.h"
#include "memory.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void func_800C9F48(f32 time, u8 *actor, s32 arg2);
void func_800C9CD0(f32 time, BtIntPtr actor, s32 dialog, s32 arg3, f32 *position, s16 arg5);
void func_800C9EF8(f32 time, void *callback, void *payload, size_t payload_size);
void func_800C9FD0(void);
extern Vector *D_8012AB60;

static u8 *seen_actor;
static Unk80132ED0 *seen_dialog_actor;
static u32 seen_dialog;
static f32 seen_volume;
static s32 seen_sound_id;
static u32 seen_rate;
static f32 seen_sound_position[3];
static u8 captured_payload[0x50];
static size_t captured_payload_size;

#define check(condition) do { if (!(condition)) { fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); abort(); } } while (0)
s32 func_801069A4(Unk80132ED0 *actor) { seen_actor = (u8 *)actor; return 0; }
s32 func_8010114C(BtIntPtr actor, s32 message, BtIntPtr player) {
    (void)actor; (void)message; (void)player; abort();
}
f32 func_800D8FF8(void) { return 1.0f; }
void func_800EE7F8(f32 dst[3], f32 src[3]) { __builtin_memcpy(dst, src, sizeof(f32) * 3); }
void func_800EFD24(f32 value[3]) { value[0] = value[1] = value[2] = 0.0f; }
int func_800EEEA8(f32 position[3]) { (void)position; return 0; }
void func_800C4244(s32 sound_id, f32 volume, u32 rate, f32 *position, f32 near, f32 far) {
    seen_sound_id = sound_id;
    seen_volume = volume;
    seen_rate = (u32)rate;
    __builtin_memcpy(seen_sound_position, position, sizeof(seen_sound_position));
    (void)near; (void)far;
}
s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *actor, u32 dialog, u32 arg2, f32 *position, s16 arg5) {
    seen_dialog_actor = actor;
    seen_dialog = dialog;
    check(arg2 == 19 && arg5 == 7 && position != NULL);
    return 0;
}
static void capture_payload(void *payload) {
    __builtin_memcpy(captured_payload, payload, captured_payload_size);
}

int main(void) {
    check(sizeof(void *) == 8);

    /* Real func_800C9F48 reads this structure then schedules its pointer. */
    u8 *actor = calloc(1, 0x40);
    check(actor && (uintptr_t)actor > UINT32_MAX);
    *(u16 *)(actor + 0x12) = 0x246;
    func_800C9F48(0.125f, actor, 77);
    func_800CA0A8();
    check(seen_actor == actor);
    check(D_8012AB60 == NULL);

    f32 position[3] = { 1.0f, 2.0f, 3.0f };
    func_800C9C70(0.125f, 41, 0.75f, 47, position, 9.0f, 10.0f);
    func_800CA0A8();
    check(seen_sound_id == 41 && seen_rate == 47 && seen_volume == 0.75f);
    check(!__builtin_memcmp(seen_sound_position, position, sizeof(position)));

    func_800C9CD0(0.125f, (BtIntPtr)actor, 23, 19, position, 7);
    func_800CA0A8();
    check(seen_dialog_actor == (Unk80132ED0 *)actor && seen_dialog == 23);

    u8 payload[0x23];
    for (size_t i = 0; i < sizeof(payload); i++) payload[i] = (u8)(i * 7 + 3);
    captured_payload_size = sizeof(payload);
    func_800C9EF8(0.0f, capture_payload, payload, sizeof(payload));
    func_800C9FD0();
    check(!__builtin_memcmp(captured_payload, payload, sizeof(payload)));
    check(D_8012AB60 == NULL);

    func_800C9EF8(0, capture_payload, payload, 0x51);
    check(D_8012AB60 == NULL);
    free(actor);
    return 0;
}
