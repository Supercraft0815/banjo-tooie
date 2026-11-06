#include "common.h"
#if defined(BT_ILP32) // defined in pc/native/platform/handwritten.c
#elif defined(BT_NATIVE)
void *func_80100368(void *data) {
    Actor *actor=data;
    return actor && actor->factory ? actor->factory() : NULL;
}
#else
void *func_80100368(void *arg0) {
    return (*(void *(**)())((s8 *)(arg0) + (0x10)))();
}
#endif
