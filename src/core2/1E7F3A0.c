#include "common.h"

void func_800A5AB0(void) {
    struct Entry { s16 map; u8 data[10]; };
    struct Level { s32 level; struct Entry *entries; };
    extern struct Entry D_8011A1B0;
    extern struct Level D_8011A1BC[];
    extern void *D_80127100;
    extern u8 D_8012762C;
    s32 func_800EA05C();
    s32 i;
    s32 level = D_8012762C;
    s32 map;
    struct Entry *entries = &D_8011A1B0;
    struct Entry *scan;

    for (i = 0; D_8011A1BC[i].level != 0; i++) {
        if (level == D_8011A1BC[i].level) {
            entries = D_8011A1BC[i].entries;
        }
    }
    map = func_800EA05C();
    for (i = 0; entries[i].map != 0; i++) {
        if (map == entries[i].map) {
            break;
        }
    }
    D_80127100 = &entries[i];
}

s8 func_800A5B6C(void) {
    extern void *D_80127100;
    return (*(s8 *)((s8 *)(D_80127100) + (2)));
}

s8 func_800A5B7C(void) {
    extern void *D_80127100;
    return (*(s8 *)((s8 *)(D_80127100) + (3)));
}

f32 func_800A5B8C(void) {
    extern void *D_80127100;
    return (*(f32 *)((s8 *)(D_80127100) + (4)));
}

u8 func_800A5B9C(void) {
    extern void *D_80127100;
    return (*(u8 *)((s8 *)(D_80127100) + (8)));
}

u8 func_800A5BAC(void) {
    extern void *D_80127100;
    return (*(u8 *)((s8 *)(D_80127100) + (9)));
}

u8 func_800A5BBC(void) {
    extern void *D_80127100;
    return (*(u8 *)((s8 *)(D_80127100) + (0xA)));
}

u8 func_800A5BCC(void) {
    extern void *D_80127100;
    return (*(u8 *)((s8 *)(D_80127100) + (0xB)));
}
