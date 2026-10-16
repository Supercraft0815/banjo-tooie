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

s32 sudialog_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, s32, s32, s16);
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    extern DialogMap D_808000E0_sudialog;
    extern s16 D_808000E2_sudialog[][2];
    s32 index;

    if (func_800DA298(arg0) != 0) {
        return 0;
    }
    index = func_80800000_sudialog(&D_808000E0_sudialog, arg0);
    if (index != -1) {
        if (func_800C05B8(D_808000E2_sudialog[index][0], arg1, NULL, NULL, 0, 0, 0) != 0) {
            func_800DA544(arg0);
        }
        return func_800DA298(arg0);
    }
    return 0;
}
