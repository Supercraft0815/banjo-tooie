#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_spawn_queue.h"
#include "native_actor.h"
typedef NativeSpawnQueue SpawnQueue;
#define QUEUE_FIELD(queue, field, original) (((NativeSpawnQueue *)(queue))->field)
#define QUEUE_ENTRY(queue) (&((NativeSpawnQueue *)(queue))->callbacks[((NativeSpawnQueue *)(queue))->count])
#define QUEUE_CALLBACK(queue, n, original) (QUEUE_ENTRY(queue)->callback.f##n)
#define QUEUE_ARG(queue, n, original) (QUEUE_ENTRY(queue)->args[n])
#define QUEUE_ARITY(queue, original) (QUEUE_ENTRY(queue)->count)
#else
typedef Actor SpawnQueue;
#define QUEUE_FIELD(queue, field, original) (original)
#define QUEUE_CALLBACK(queue, n, original) (original)
#define QUEUE_ARG(queue, n, original) (original)
#define QUEUE_ARITY(queue, original) (original)
#endif

s32 func_80800000_chbaddiesetup(void *arg0) {
    if (QUEUE_FIELD(arg0, callbacks, (*(s32 *)((s8 *)(arg0) + (0)))) == 0) {
        return 0;
    }
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (((NativeSpawnQueue *)arg0)->count >= NATIVE_SPAWN_CAPACITY) {
#else
    if ((*(u8 *)((s8 *)(arg0) + (4))) == 0x16) {
#endif
        return 0;
    }
    return 1;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_0(NativeSpawn0 arg0)
#else
void chbaddiesetup_entrypoint_0(s32 arg0)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;

#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 0;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_1(NativeSpawn1 arg0, uintptr_t arg1)
#else
void chbaddiesetup_entrypoint_1(s32 arg0, s32 arg1)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;

#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 1;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_2(NativeSpawn2 arg0, uintptr_t arg1, uintptr_t arg2)
#else
void chbaddiesetup_entrypoint_2(s32 arg0, s32 arg1, s32 arg2)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 2, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARG(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8)) = arg2;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 2;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_3(NativeSpawn3 arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3)
#else
void chbaddiesetup_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 3, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARG(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8)) = arg2;
        QUEUE_ARG(actor, 2, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0xC)) = arg3;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 3;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_4(NativeSpawn4 arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4)
#else
void chbaddiesetup_entrypoint_4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 4, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARG(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8)) = arg2;
        QUEUE_ARG(actor, 2, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0xC)) = arg3;
        QUEUE_ARG(actor, 3, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x10)) = arg4;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 4;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_5(NativeSpawn5 arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5)
#else
void chbaddiesetup_entrypoint_5(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 5, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARG(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8)) = arg2;
        QUEUE_ARG(actor, 2, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0xC)) = arg3;
        QUEUE_ARG(actor, 3, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x10)) = arg4;
        QUEUE_ARG(actor, 4, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x14)) = arg5;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 5;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void chbaddiesetup_entrypoint_6(NativeSpawn6 arg0, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6)
#else
void chbaddiesetup_entrypoint_6(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
#endif
 {
    void *func_800A5D60(void);
    SpawnQueue *actor;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!arg0) return;
#endif
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        QUEUE_CALLBACK(actor, 6, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5))) = arg0;
        QUEUE_ARG(actor, 0, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4)) = arg1;
        QUEUE_ARG(actor, 1, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8)) = arg2;
        QUEUE_ARG(actor, 2, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0xC)) = arg3;
        QUEUE_ARG(actor, 3, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x10)) = arg4;
        QUEUE_ARG(actor, 4, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x14)) = arg5;
        QUEUE_ARG(actor, 5, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x18)) = arg6;
        QUEUE_ARITY(actor, *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C)) = 6;
        QUEUE_FIELD(actor, count, ((u8 *)actor->position)[0])++;
    }
}

void chbaddiesetup_entrypoint_7(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 pos[3];
    pos[0] = *(f32 *)&arg1;
    pos[1] = *(f32 *)&arg2;
    pos[2] = *(f32 *)&arg3;
    func_80108474(*(s32 *)&arg0, pos, 0);
}

/* extern */

void chbaddiesetup_entrypoint_8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    void func_80108454(s32, s32 *, u32);
#endif
    s32 pos[3];

    pos[0] = *(s32 *)&arg1;
    pos[1] = *(s32 *)&arg2;
    pos[2] = *(s32 *)&arg3;
    func_80108454(*(s32 *)&arg0, pos, 0);
}

/* extern */

void chbaddiesetup_entrypoint_9(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor *_chbounce_entrypoint_6(s32, f32 *);
    f32 pos[3];
    pos[0] = *(f32 *)&arg1;
    pos[1] = *(f32 *)&arg2;
    pos[2] = *(f32 *)&arg3;
    _chbounce_entrypoint_6(*(s32 *)&arg0, pos);
}

Actor *chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw) {
    void _chbounce_entrypoint_2(f32);
    Actor *_chbounce_entrypoint_6(s32, f32 *);
    f32 pos[3];
    pos[0] = *(f32 *)&x;
    pos[1] = *(f32 *)&y;
    pos[2] = *(f32 *)&z;
    _chbounce_entrypoint_2(*(f32 *)&yaw);
    return _chbounce_entrypoint_6(id, pos);
}
