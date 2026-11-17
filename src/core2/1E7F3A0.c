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
}    typedef struct { u8 pad0[0x2]; s8 unk2; } Obj1E7F3A0_func_800A5B6C_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

s8 func_800A5B6C(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5B6C_D_80127100 *)D_80127100)->unk2);
}    typedef struct { u8 pad0[0x3]; s8 unk3; } Obj1E7F3A0_func_800A5B7C_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

s8 func_800A5B7C(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5B7C_D_80127100 *)D_80127100)->unk3);
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1E7F3A0_func_800A5B8C_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

f32 func_800A5B8C(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5B8C_D_80127100 *)D_80127100)->unk4);
}    typedef struct { u8 pad0[0x8]; u8 unk8; } Obj1E7F3A0_func_800A5B9C_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

u8 func_800A5B9C(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5B9C_D_80127100 *)D_80127100)->unk8);
}    typedef struct { u8 pad0[0x9]; u8 unk9; } Obj1E7F3A0_func_800A5BAC_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

u8 func_800A5BAC(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5BAC_D_80127100 *)D_80127100)->unk9);
}    typedef struct { u8 pad0[0xA]; u8 unkA; } Obj1E7F3A0_func_800A5BBC_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

u8 func_800A5BBC(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5BBC_D_80127100 *)D_80127100)->unkA);
}    typedef struct { u8 pad0[0xB]; u8 unkB; } Obj1E7F3A0_func_800A5BCC_D_80127100; /* offsets.py genstruct: fields from raw offsets on D_80127100; rename once understood */

u8 func_800A5BCC(void) {
    extern void *D_80127100;
    return (((Obj1E7F3A0_func_800A5BCC_D_80127100 *)D_80127100)->unkB);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
void * D_80127100 BT_DATA(4, bss_core2bss1_0_1, 0xA0);
#endif
