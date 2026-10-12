#include "common.h"

void func_80020E40(ALLink *ln, ALLink *to) {
    ln->next = to->next;
    ln->prev = to;
    if (to->next != NULL) {
        to->next->prev = ln;
    }
    to->next = ln;
}

void func_80020E74(ALLink *ln) {
    if (ln->next != NULL) {
        ln->next->prev = ln->prev;
    }
    if (ln->prev != NULL) {
        ln->prev->next = ln->next;
    }
}
