#include "common.h"

typedef struct { s16 key; s16 dialog_id; } DialogMap;

s32 func_80800000_sudialog(DialogMap *map, s32 key) {
    s32 i = 0;
    while (map[i].key >= 0) {
        if (key == map[i].key) {
            return i;
        }
        i++;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/dialog/sudialog_entrypoint_0.s")
