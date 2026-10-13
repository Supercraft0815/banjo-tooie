#include "common.h"

typedef struct { void *ptr; s32 type; } Entry;
extern Entry D_8007BF10[];

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E32FE0/func_8001B4B0.s")

void func_8001B4E8(void)
{
    s32 i;

    for (i = 2; i < 250; i++) {
        if (D_8007BF10[i].ptr != NULL) {
        }
    }
}

void func_8001B50C(void)
{
    extern s32 D_8007C6E0;

    D_8007C6E0 = 0;
}

void func_8001B518(s32 arg0)
{
    extern s32 D_8007C6E0;
    extern s32 D_8007C6E4;
    void *defrag(void *);
    void func_800E0040(u32 *);
    void func_800E0AC0();
    void vector_update_pointers();
    void *old;
    void *saved;
    void *moved;
    s32 type;
    s32 i;
    s32 count;
    Entry *entry;

    if (D_8007C6E0 == 0 || arg0 != 0) {
        D_8007C6E0 = 1;
        if (arg0 != 0) {
            count = 250;
        } else {
            count = 20;
        }
        for (i = 1; i < count; i++) {
            D_8007C6E4++;
            if (D_8007C6E4 >= 250) {
                D_8007C6E4 = 0;
            }
            if (D_8007BF10[D_8007C6E4].ptr != 0) {
                saved = D_8007BF10[D_8007C6E4].ptr;
                moved = defrag(D_8007BF10[D_8007C6E4].ptr);
                entry = &D_8007BF10[D_8007C6E4];
                entry->ptr = moved;
                if (moved != saved) {
                    type = entry->type;
                    if (type != 0) {
                        switch (type) {
                        case 1:
                            func_800E0040((u32 *)entry->ptr);
                            break;
                        case 3:
                            func_800E0AC0(entry->ptr);
                            break;
                        case 5:
                            vector_update_pointers(entry->ptr);
                            break;
                        }
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E32FE0/func_8001B668.s")

/* extern */

void *func_8001B710(s16 arg0, s32 arg1) {
    void *heap_realloc(void *, s32);
    return (D_8007BF10[arg0].ptr = heap_realloc(D_8007BF10[arg0].ptr, arg1),
            D_8007BF10[arg0].ptr);
}

/* extern */
void func_8001B754(s16 arg0) {
    heap_free(D_8007BF10[arg0].ptr), D_8007BF10[arg0].ptr = NULL;
}

void *func_8001B798(s16 arg0) {
    return D_8007BF10[arg0].ptr;
}

/* extern */

void func_8001B7B8(s16 arg0) {
    s32 heap_get_allocation_size(void *);
    heap_get_allocation_size(D_8007BF10[arg0].ptr);
}

/* extern */

void func_8001B7F0(s16 arg0, u8 arg1, int arg2) { u32 value = arg1;
    rare_memset(D_8007BF10[arg0].ptr, value, arg2);
}
