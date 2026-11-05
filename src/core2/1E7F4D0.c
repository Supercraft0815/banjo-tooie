#include "common.h"

#ifdef BT_NATIVE
#include "native_spawn_queue.h"
#include "memory.h"
#include "native_actor.h"
#include "core2/1EC3810.h"
void _gccollectDll_entrypoint_4(void);
u8 func_8001E204(void);
void func_800BDCDC(void);
void func_800FFB74(void);
void func_801002C0(void);
void _subaddietaxi_entrypoint_3(void);
NativeSpawnQueue D_80127110;
#define D_80127114 D_80127110.count
#define D_80127115 D_80127110.enabled
#define QUEUE_STORAGE D_80127110.callbacks
#else
extern s32 D_80127110;
#define QUEUE_STORAGE D_80127110
#endif

void func_800A5BE0()
{
    _chbaddieDll_entrypoint_0(&D_80127110);
}

/* extern */

void func_800A5C04(void) {
#ifdef BT_NATIVE
    if (QUEUE_STORAGE) return;
    QUEUE_STORAGE = heap_alloc(NATIVE_SPAWN_CAPACITY * sizeof(NativeSpawnCall));
    D_80127110.count = 0;
#else
    s32 heap_alloc(s32);
    D_80127110 = heap_alloc(0x2C0);
#endif
}

/* extern */

void func_800A5C28(void) {
#ifndef BT_NATIVE
    s32 _chbaddieDll_entrypoint_1(s32 *);
#endif
    void _cosectionstor_entrypoint_4(s32);
#ifndef BT_NATIVE
    s32 _gccollectDll_entrypoint_4();
#endif
    s32 _subaddietaxi_entrypoint_4();
#ifndef BT_NATIVE
    s32 func_8001E204();
#endif
#ifndef BT_NATIVE
    s32 func_800BDCDC();
#endif
#ifndef BT_NATIVE
    s32 func_800EA05C();
#endif
#ifndef BT_NATIVE
    s32 func_800FFB74();
#endif
#ifndef BT_NATIVE
    s32 func_80108C14();
#endif
    _gccollectDll_entrypoint_4();
    _chbaddieDll_entrypoint_1(&D_80127110);
    _subaddietaxi_entrypoint_4();
    _cosectionstor_entrypoint_4(func_800EA05C());
    func_80108C14();
    func_800FFB74();
    if (func_8001E204() == 0) {
        func_800BDCDC();
    }
}

/* extern */

void func_800A5C94(void) {
#ifndef BT_NATIVE
    extern s8 D_80127115;
#endif
#ifndef BT_NATIVE
    s32 func_801002C0();
#endif
    if ((u8) D_80127115 != 0) {
        func_801002C0();
    }
}

/* extern */

void func_800A5CC4(void) {
#ifndef BT_NATIVE
    s32 _chbaddieDll_entrypoint_2(s32 *);
#endif
#ifndef BT_NATIVE
    s32 _subaddietaxi_entrypoint_3();
#endif
    _subaddietaxi_entrypoint_3();
    _chbaddieDll_entrypoint_2(&D_80127110);
}

void func_800A5CF0(s32 arg0) {
#ifndef BT_NATIVE
    extern s8 D_80127115;
#endif
    *(s8 *)((u8 *)&D_80127115 + 0) = arg0;
}

void func_800A5CFC()
{
#ifdef BT_NATIVE
    void func_800FF62C(void);
#endif
    func_800FF62C();
}

void func_800A5D1C(void) {
#ifndef BT_NATIVE
    s32 _chbaddieDll_entrypoint_3(s32 *);
#endif
#ifndef BT_NATIVE
    s32 func_800FFB74();
#endif
    s32 func_8010D1E8();
#ifndef BT_NATIVE
    extern u8 D_80127114;
#endif
    if (D_80127114 != 0) {
        func_8010D1E8();
        _chbaddieDll_entrypoint_3(&D_80127110);
    }
    func_800FFB74();
}

void * func_800A5D60(void) {
    return &D_80127110;
}

/* extern */

void func_800A5D6C(void) {
#ifndef BT_NATIVE
    s32 defrag(s32);
#endif
    if (QUEUE_STORAGE != 0) {
        QUEUE_STORAGE = defrag(QUEUE_STORAGE);
    }
}
