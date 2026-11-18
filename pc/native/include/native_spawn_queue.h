#ifndef BT_NATIVE_SPAWN_QUEUE_H
#define BT_NATIVE_SPAWN_QUEUE_H
#include "common.h"
enum { NATIVE_SPAWN_CAPACITY = 22 };
typedef void (*NativeSpawn0)(void);
typedef void (*NativeSpawn1)(uintptr_t);
typedef void (*NativeSpawn2)(uintptr_t, uintptr_t);
typedef void (*NativeSpawn3)(uintptr_t, uintptr_t, uintptr_t);
typedef void (*NativeSpawn4)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef void (*NativeSpawn5)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef void (*NativeSpawn6)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef union {
    NativeSpawn0 f0;
    NativeSpawn1 f1;
    NativeSpawn2 f2;
    NativeSpawn3 f3;
    NativeSpawn4 f4;
    NativeSpawn5 f5;
    NativeSpawn6 f6;
} NativeSpawnFunction;
typedef struct {
    NativeSpawnFunction callback;
    uintptr_t args[6];
    u32 count;
} NativeSpawnCall;
typedef struct {
    NativeSpawnCall *callbacks;
    u8 count, enabled, processing;
} NativeSpawnQueue;
void _chbaddiesetup_entrypoint_0(NativeSpawn0);
void _chbaddiesetup_entrypoint_1(NativeSpawn1, uintptr_t);
void _chbaddiesetup_entrypoint_2(NativeSpawn2, uintptr_t, uintptr_t);
void _chbaddiesetup_entrypoint_3(NativeSpawn3, uintptr_t, uintptr_t, uintptr_t);
void _chbaddiesetup_entrypoint_4(NativeSpawn4, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
void _chbaddiesetup_entrypoint_5(NativeSpawn5, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
void _chbaddiesetup_entrypoint_6(NativeSpawn6, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
void chbaddieDll_entrypoint_0(void *);
void chbaddieDll_entrypoint_1(void *);
void chbaddieDll_entrypoint_2(void *);
void chbaddieDll_entrypoint_3(void *);
void func_800A5BE0(void);
void func_800A5C04(void);
void func_800A5C28(void);
void func_800A5C94(void);
void func_800A5CC4(void);
void func_800A5CF0(s32);
s32 func_800A5CFC(void);
void func_800A5D1C(void);
void *func_800A5D60(void);
void func_800A5D6C(void);
#endif
