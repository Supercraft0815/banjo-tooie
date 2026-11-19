#include <stdint.h>
#define CHECK(condition) do { if (!(condition)) return __LINE__; } while (0)
#include "core2/sky_state.h"
#include "memory.h"

extern SkyState D_80128770;
extern BtIntPtr func_800BFFA0(s32 index);
extern void func_800BFCD0(s32 index, s32 value);
extern void func_800BFF70(void);
extern void func_800BFFF4(void);

s32 D_80127EF8;

f32 func_800D8FF8(void) { return 0.25f; }

int main(void) {
    void *controller = heap_alloc(0x20);
    void *model = heap_alloc(0x20);
    void *handle = heap_alloc(0x20);

    CHECK(sizeof(void *) == 8);
    CHECK((uintptr_t)controller > UINT32_MAX);
    CHECK((uintptr_t)model > UINT32_MAX);
    CHECK((uintptr_t)handle > UINT32_MAX);
    D_80128770.controllers[0] = controller;
    D_80128770.models[0] = model;
    D_80128770.handles[0] = handle;
    D_80128770.render_switches[59] = 0x12345678;
    D_80128770.age = 1.5f;

    CHECK(func_800BFFA0(0) == (BtIntPtr)handle);
    CHECK(func_800BFFA0(2) == (BtIntPtr)model);
    CHECK(func_800BFFA0(69) == 0x12345678);
    func_800BFCD0(59, 0x12345678);
    CHECK(D_80128770.render_switches[59] == 0x12345678);
    func_800BFF70();
    CHECK(D_80128770.age == 1.75f);

    /* Host defrag is the production no-move implementation; still exercise its caller. */
    D_80128770.controllers[1] = heap_alloc(0x20);
    func_800BFFF4();
    CHECK(D_80128770.controllers[0] == controller);
    CHECK(D_80128770.controllers[1] != NULL);
    CHECK(D_80128770.handles[0] == handle);
    return 0;
}
