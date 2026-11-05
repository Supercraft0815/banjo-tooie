#include "common.h"
#ifdef BT_NATIVE
#include "native_spawn_queue.h"
#include "memory.h"
void _suautobaddies_entrypoint_0(void);
u8 func_8001E204(void);
void func_800BDCB8(void);
void func_800BDD00(void);
void func_800CB9B4(void);
void func_800FF390(void);
void func_800CB9D8(void);
#define QUEUE_FIELD(queue, field, original) (((NativeSpawnQueue *)(queue))->field)
#define SPAWN_STRIDE sizeof(NativeSpawnCall)
#define QUEUE_CALL(record, n, original) ((record)->callback.f##n)
#else
#define QUEUE_FIELD(queue, field, original) (original)
#define SPAWN_STRIDE 0x20
#define QUEUE_CALL(record, n, original) (original)
#endif

void chbaddieDll_entrypoint_0(void *arg0) {
    QUEUE_FIELD(arg0, count, (*(s8 *)((s8 *)(arg0) + (4)))) = 0;
    QUEUE_FIELD(arg0, enabled, (*(s8 *)((s8 *)(arg0) + (5)))) = 1;
}

/* extern */

void chbaddieDll_entrypoint_1(void *arg0) {
#ifndef BT_NATIVE
    s32 _suautobaddies_entrypoint_0();
#endif
#ifndef BT_NATIVE
    s32 func_8001E204();
#endif
#ifndef BT_NATIVE
    s32 func_800BDCB8();
#endif
#ifndef BT_NATIVE
    s32 func_800BDD00();
#endif
#ifndef BT_NATIVE
    s32 func_800CB9B4();
#endif
#ifndef BT_NATIVE
    s32 func_800FF390();
#endif
    QUEUE_FIELD(arg0, count, (*(s8 *)((s8 *)(arg0) + (4)))) = 0;
    func_800CB9B4();
    func_800BDD00();
    func_800FF390();
    if (func_8001E204() == 0) {
        func_800BDCB8();
        _suautobaddies_entrypoint_0();
    }
}

/* extern */

void chbaddieDll_entrypoint_2(void *arg0) {
#ifndef BT_NATIVE
    s32 func_800CB9D8();
#endif
    s32 func_800FF564();
#ifndef BT_NATIVE
    s32 heap_free(s32);
#endif
    func_800FF564();
    func_800CB9D8();
    heap_free(QUEUE_FIELD(arg0, callbacks, (*(s32 *)((s8 *)(arg0) + (0)))));
    QUEUE_FIELD(arg0, callbacks, (*(s32 *)((s8 *)(arg0) + (0)))) = 0;
    QUEUE_FIELD(arg0, count, (*(s8 *)((s8 *)(arg0) + (4)))) = 0;
}

void chbaddieDll_entrypoint_3(void *arg0) {
#ifdef BT_NATIVE
    typedef NativeSpawnCall Callback;
    typedef NativeSpawnQueue Queue;
#else
    typedef struct {
        void (*callback)();
        s32 args[6];
        u32 count;
    } Callback;
    typedef struct {
        Callback *callbacks;
        u8 count;
    } Queue;
#endif
    Queue *queue = arg0;
    s32 offset;
    s32 limit;
    Callback *callback;

#ifdef BT_NATIVE
    if (queue->processing) return;
    if (!queue->callbacks || queue->count > NATIVE_SPAWN_CAPACITY) { queue->count = 0; return; }
    queue->processing = 1;
#endif
    offset = 0;
    if ((s32)queue->count > 0) {
        do {
            callback = (Callback *)((u8 *)queue->callbacks + offset);
            switch (callback->count) {
                case 0:
                    QUEUE_CALL(callback, 0, callback->callback)();
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 1:
                    QUEUE_CALL(callback, 1, callback->callback)(callback->args[0]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 2:
                    QUEUE_CALL(callback, 2, callback->callback)(callback->args[0], callback->args[1]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 3:
                    QUEUE_CALL(callback, 3, callback->callback)(callback->args[0], callback->args[1], callback->args[2]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 4:
                    QUEUE_CALL(callback, 4, callback->callback)(callback->args[0], callback->args[1], callback->args[2], callback->args[3]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 5:
                    QUEUE_CALL(callback, 5, callback->callback)(callback->args[0], callback->args[1], callback->args[2], callback->args[3], callback->args[4]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                case 6:
                    QUEUE_CALL(callback, 6, callback->callback)(callback->args[0], callback->args[1], callback->args[2], callback->args[3], callback->args[4], callback->args[5]);
                                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
                default:
                    limit = QUEUE_FIELD(queue, count, queue->count) * SPAWN_STRIDE;
                    break;
            }
            offset += SPAWN_STRIDE;
        } while (offset < limit);
    }
    queue->count = 0;
#ifdef BT_NATIVE
    queue->processing = 0;
#endif
}
