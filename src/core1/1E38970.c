#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38970/func_80020E40.s")

void func_80020E6C(void) {
}

void func_80020E74(ALLink *ln) {
    if (ln->next != NULL) {
        ln->next->prev = ln->prev;
    }
    if (ln->prev != NULL) {
        ln->prev->next = ln->next;
    }
}

void func_80020EAC(void) {
}