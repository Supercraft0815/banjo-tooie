#include "core2/transition.h"
#include <stdlib.h>
#include <stdio.h>

BtIntPtr func_800C9150(s32 id);
BtIntPtr func_800C91C8(s32 id);
void func_800C9214(void *transition);
void func_800C929C(void);
void func_800C92A8(void);
void func_800C9310(void);
void func_800C9484(void);
void func_800C968C(s32 id, s32 state);
s32 func_800C96CC(s32 id);
s32 func_800C9714(s32 id);

extern Transition *D_8012AB40[5];
u8 D_8012AB54;
static int visits;
static int control_before, control_after;

void *heap_alloc(s32 size) {
    if ((size_t)size != sizeof(Transition)) abort();
    return malloc(size);
}

void heap_free(void *p) { free(p); }

void *defrag(void *p) {
    Transition *copy = malloc(sizeof(*copy));
    if (!copy) abort();
    *copy = *(Transition *)p;
    free(p);
    return copy;
}

struct anctrl_s *func_8008AEB4(struct anctrl_s *control) {
    if (control != (struct anctrl_s *)&control_before) abort();
    return (struct anctrl_s *)&control_after;
}

void _gctransitionDll_entrypoint_8(Transition *entry, s32 id) { entry->id = id; }
void _gctransitionDll_entrypoint_9(Transition *entry) { ++entry->update_count; ++visits; }
void _gctransitionDll_entrypoint_7(Transition *entry, s32 state) { entry->state = state; }
void _gctransitionDll_entrypoint_5(Transition *entry) { func_800C9214(entry); }
s32 _gctransitionDll_entrypoint_3(Transition *entry) { return entry->state != 1; }

#define CHECK(test) do { if (!(test)) { fprintf(stderr, "line %d: %s\n", __LINE__, #test); return 1; } } while (0)

int main(void) {
    int i;
    Transition *entry;
    func_800C929C();
    for (i = 0; i < 5; ++i) {
        entry = (Transition *)func_800C9150(i);
        CHECK(entry && entry->id == i && D_8012AB40[i] == entry);
        CHECK(func_800C9150(i) == (BtIntPtr)entry);
    }
    CHECK(D_8012AB54 == 5 && !func_800C91C8(9));
    entry = D_8012AB40[3];
    if (sizeof(void *) > 4) CHECK((BtUIntPtr)entry > 0xffffffffu);
    entry->control = (struct anctrl_s *)&control_before;
    entry->data.next_state = 2;
    func_800C968C(3, 2);
    CHECK(func_800C96CC(3) && func_800C9714(3));
    func_800C92A8();
    CHECK(visits == 5 && entry->update_count == 1);
    func_800C9484();
    entry = (Transition *)func_800C91C8(3);
    CHECK(entry == D_8012AB40[3] && entry->update_count == 1);
    CHECK(entry->control == (struct anctrl_s *)&control_after);
    func_800C9214(D_8012AB40[1]);
    CHECK(D_8012AB54 == 4 && !func_800C91C8(1) && D_8012AB40[1]->id == 4);
    func_800C9310();
    CHECK(!D_8012AB54);
    return 0;
}
