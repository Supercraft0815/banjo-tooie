#include "native_spline.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include "marker_world.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); exit(1); } } while (0)

/* Level prop enumeration, clocks and memory pressure are controlled here. */
u8 D_8012762C = 13;
static int cursor;
static u32 prop[5];
static struct { f32 time; u32 data[4]; } events[2] = {{0.75f, {0}}, {0.25f, {0}}};
s32 func_80800000_glsplineDll(u32 *, s32 *, u32 *, u32 *, u32 *, u32 *, s32 *, void *);
s32 func_8001211C(void) { return 100; }
s32 func_800A9F14(s32 mode) { return mode == 2 ? 3 : 18; }
s32 func_800A9F30(void) { return 1; }
f32 func_800D8FF8(void) { return 0.1f; }
f32 _glintrosyncDll_entrypoint_5(void) { return 0.2f; }
u32 func_800E6A00(void) { return 1; }
s32 _gspropctrl_entrypoint_6(void *p) { (void)p; return 0; }
s32 _gccubesearch_entrypoint_2(s32 id, s32 *position) {
    if (id != 1 && id != 3 && id != 5) return 0;
    position[0] = (id - 1) * 5;
    position[1] = id == 5 ? 10 : 0;
    position[2] = 0;
    return 1;
}
Prop *_gccubesearch_entrypoint_17(s32 id, s32 *unused) {
    CHECK(unused==NULL);
    CHECK(id == 2 || id == 4);
    return (Prop *)&events[id / 2 - 1];
}
u32 _gccubesearch_entrypoint_18(s32 mode, s32 *position, u32 *next,
    s32 *is_event, s32 *settings, s32 *unused, Prop **source) {
    int id;
    (void)settings; (void)unused;
    if (!mode) { cursor = 1; return 0; }
    if (cursor > 5) return -1;
    id = cursor++;
    position[0] = (id - 1) * 5;
    position[1] = id == 5 ? 10 : 0;
    position[2] = 0;
    *next = id == 5 ? 0 : id + 1;
    *is_event = !(id & 1);
    *source = (Prop *)prop;
    return id;
}

static void check_path(void) {
    NativeSplineContext *context = func_800D7400();
    u8 *path = func_800D7520(0);
    f32 *times = (f32 *)func_800D7570(0), position[3];
    Actor actor = {0};
    s32 first[3] = {0, 0, 0}, middle[3] = {10, 0, 0}, last[3] = {20, 10, 0};
    void *marker = heap_alloc(32);
    CHECK(context == &native_spline_context && context->count == 1);
    CHECK(path && path[2] == 3 && path[4] == 1);
    CHECK(times && times[0] == 0.25f && times[5] == 0.75f);
    CHECK(func_800D75DC(0, 0.25f) == 0 && func_800D75DC(0, 0.5f) == 1);
    CHECK(func_800D75DC(0, 1) == 2);
    CHECK(!func_800D7520(-1) && !func_800D7520(1));
    CHECK(!func_800D7570(-1) && !func_800D7570(1) && func_800D75DC(-1, 0) == 0);
    func_800D86F0(0, 0.5f, position);
    CHECK(fabsf(position[0] - 10) < 0.00001f && fabsf(position[1]) < 0.00001f);
    CHECK(func_800D7708(0, 0, 4) > 20);
    CHECK(glsplinefind_entrypoint_0(3, position) == 0 && position[0] == 10);
    CHECK(glsplinefind_entrypoint_1(5) == 0 && glsplinefind_entrypoint_1(99) == -1);
    CHECK(glsplinefind_entrypoint_4(first, middle) == 0);
    CHECK(glsplinefind_entrypoint_4(last, first) == -1);
    func_800D8744();
    CHECK(fabsf(context->value0 - 12) < 0.00001f && context->value1 == 0);
    context->map = 0;
    func_800D8744();
    CHECK(fabsf(context->value0 - 18) < 0.00001f && context->value1 == 12);
    actor.unk0 = marker;
    func_800D87D4(&actor, 5);
    CHECK(func_800D87EC(5) == marker);
    context->cache[0].used = 1;
    context->cache[0].object = marker;
    func_800D8674();
    CHECK(context->cache[0].object == marker);
    func_800D8808(1);
    CHECK(context->cache[0].used == 0 && context->cache[0].object == marker);
    heap_free(marker);
}

int main(int argc, char **argv) {
    marker_world_reset();
    *func_800E9A24(marker_world[1])=(Prop){.unk10=5<<5};
    NativeSplineContext *context = &native_spline_context;
    int iteration, invalid = argc == 3 && argv[2][0] == 'i';
    u32 encoded[5] = {0, 22, 0x2300, (5 << 23) | (7 << 14) | (9 << 4), 0};
    u32 flag0, value, flag2, high, low;
    s32 flag1, prop_value;
    CHECK(argc == 2 || argc == 3);
    CHECK(func_80800000_glsplineDll(&flag0, &flag1, &value, &flag2, &high, &low, &prop_value, encoded));
    CHECK(flag0 == 1 && flag1 == 1 && flag2 == 1 && value == 9 && high == 5 && low == 7);
    events[1].data[0] = 1;
    events[1].data[2] = 0xFF000001;
    CHECK(native_assets_open(argv[1]));
    func_800D66AC();
    func_800D743C(); /* Cleanup must also accept an uninitialized context. */
    for (iteration = 0; iteration < 40; ++iteration) {
        func_800D7418();
        check_path();
        if (invalid) {
            CHECK(!context->commands && !context->offsets && !context->asset);
            CHECK(context->counters[7] == 0);
        } else {
            int i;
            CHECK(context->asset == 0xAFF && context->commands && context->unk1A0 > 0);
            for (i = 0; i < context->unk1A0; ++i) {
                s32 offset = context->offsets[i];
                CHECK(offset >= 0 && offset < context->command_size && offset % 4 == 0);
                CHECK(context->commands[offset / 4] == 0x10005 || context->commands[offset / 4] == 0x10006);
            }
            if (argc == 3) {
                CHECK(context->unk1A0 == 2 && context->offsets[1] == 12);
                CHECK(context->counters[7] == 9 && context->initial_counters[7] == 9);
            }
        }
        func_800D743C();
        CHECK(context->count == 0 && !context->cache && !context->commands);
        CHECK(!context->handle0 && !context->handle1 && !func_800D87EC(5));
        func_800D743C();
    }
    func_800D6C64();
    native_assets_close();
    marker_world_cleanup();
    puts("Native path construction, command decoding and repeated cleanup passed");
    return 0;
}
