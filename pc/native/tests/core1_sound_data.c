#include "common.h"
#include <stdint.h>
#include <stdlib.h>
#define check(condition) do { if (!(condition)) abort(); } while (0)

void func_80020EC0(ALHeap *, u8 *, s32);
BtIntPtr func_80020EE4(s32, s32, void *, s32, s32);
void func_80020E40(ALLink *, ALLink *);
void func_80020E74(ALLink *);
void func_800263C0(ALEventQueue *, ALEventListItem *, s32);
void func_80026500(ALEventQueue *, void *, s32, s32);
s32 func_8002645C(ALEventQueue *, ALEvent *);
ALSynth *D_800411F4;
void func_800267F0(ALPlayer *);
s32 func_80026AA4(ALLink **, s16);
u32 osSetIntMask(u32 mask) { return mask; }

int main(void) {
    ALHeap heap;
    ALSynth synth = {0};
    ALPlayer player = {0}, previous = {0};
    ALLink *selected = NULL;
    u8 *arena = malloc(512);
    BtIntPtr first, second;
    ALLink head = {0}, a = {0}, b = {0};
    ALEventQueue queue;
    ALEventListItem *items = malloc(3 * sizeof(*items));
    ALEvent event = {0}, out = {0};

    check(arena != NULL && items != NULL);
#if UINTPTR_MAX > UINT32_MAX
    check((uintptr_t)&player > UINT32_MAX);
    check((uintptr_t)arena > UINT32_MAX);
#endif
    func_80020EC0(&heap, arena, 512);
    first = func_80020EE4(0, 0, &heap, 1, 1);
    second = func_80020EE4(0, 0, &heap, 2, 16);
    check((void *)first == arena);
    check((void *)second == arena + 16);
    check(heap.cur == arena + 48);
    check(func_80020EE4(0, 0, &heap, 1, 512) == 0);

    func_80020E40(&a, &head);
    func_80020E40(&b, &head);
    check(head.next == &b && b.prev == &head && b.next == &a && a.prev == &b);
    func_80020E74(&b);
    check(head.next == &a && a.prev == &head);

    func_800263C0(&queue, items, 3);
    event.type = 0x1234;
    func_80026500(&queue, &event, 7, 1);
    check(queue.allocList.next != NULL);
    check(func_8002645C(&queue, &out) == 7);
    check(out.type == event.type);
    check(queue.allocList.next == NULL);
    check(queue.freeList.next != NULL);

    free(items);
    free(arena);
    D_800411F4 = &synth;
    synth.head = &previous;
    synth.curSamples = 731;
    func_800267F0(&player);
    check(synth.head == &player && player.next == &previous && player.samplesLeft == 731);
    func_80020E40(&a, &synth.pLameList);
    check(func_80026AA4(&selected, 0) == 0 && selected == &a);
    check(!synth.pLameList.next && synth.pAllocList.next == &a);
    func_80020E40(&b, &synth.pFreeList);
    check(func_80026AA4(&selected, 0) == 0 && selected == &b);
    check(!synth.pFreeList.next && synth.pAllocList.next == &b && b.next == &a);
    return 0;
}
