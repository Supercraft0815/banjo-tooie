#include "common.h"

void chbaddieDll_entrypoint_0(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    (*(s8 *)((s8 *)(arg0) + (5))) = 1;
}

/* extern */

void chbaddieDll_entrypoint_1(void *arg0) {
    s32 _suautobaddies_entrypoint_0();
    s32 func_8001E204();
    s32 func_800BDCB8();
    s32 func_800BDD00();
    s32 func_800CB9B4();
    s32 func_800FF390();
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
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
    s32 func_800CB9D8();
    s32 func_800FF564();
    s32 heap_free(s32);
    func_800FF564();
    func_800CB9D8();
    heap_free((*(s32 *)((s8 *)(arg0) + (0))));
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
}

void chbaddieDll_entrypoint_3(void *arg0) {
    typedef struct {
        void (*callback)();
        s32 args[6];
        u32 count;
    } Callback;
    typedef struct {
        Callback *callbacks;
        u8 count;
    } Queue;
    Queue *queue = arg0;
    s32 offset;
    s32 limit;
    Callback *callback;

    offset = 0;
    if ((s32)queue->count > 0) {
        do {
            callback = (Callback *)((u8 *)queue->callbacks + offset);
            switch (callback->count) {
                case 0:
                    callback->callback();
                                    limit = queue->count << 5;
                    break;
                case 1:
                    callback->callback(callback->args[0]);
                                    limit = queue->count << 5;
                    break;
                case 2:
                    callback->callback(callback->args[0], callback->args[1]);
                                    limit = queue->count << 5;
                    break;
                case 3:
                    callback->callback(callback->args[0], callback->args[1], callback->args[2]);
                                    limit = queue->count << 5;
                    break;
                case 4:
                    callback->callback(callback->args[0], callback->args[1], callback->args[2], callback->args[3]);
                                    limit = queue->count << 5;
                    break;
                case 5:
                    callback->callback(callback->args[0], callback->args[1], callback->args[2], callback->args[3], callback->args[4]);
                                    limit = queue->count << 5;
                    break;
                case 6:
                    callback->callback(callback->args[0], callback->args[1], callback->args[2], callback->args[3], callback->args[4], callback->args[5]);
                                    limit = queue->count << 5;
                    break;
                default:
                    limit = queue->count << 5;
                    break;
            }
            offset += 0x20;
        } while (offset < limit);
    }
    queue->count = 0;
}
