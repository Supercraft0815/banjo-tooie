#include "common.h"

typedef struct {
    u16 header[2];
    u16 entries[32];
} HitTable;
extern HitTable D_80800530_glhittableDll[];

void glhittableDll_entrypoint_0(void) {
    void *func_800D8F40(void);
    s16 *var_a3;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;

    var_a3 = func_800D8F40();
    for (var_a2 = 0; var_a2 < 0x398; var_a2++) {
        for (var_a0 = 0, var_a1 = 0, var_a3[var_a2] = -1;
             var_a0 < 0x99 && var_a1 == 0; var_a0++) {
            if (var_a2 == D_80800530_glhittableDll[var_a0].header[0]) {
                var_a3[var_a2] = var_a0;
                var_a1 = 1;
            }
        }
    }
}

/* extern */

s32 glhittableDll_entrypoint_1(s32 arg0, s32 arg1) {
    void func_800EB2DC(void *, s32, s32);
    s32 glhittableDll_entrypoint_4();
    s32 temp_v0;

    temp_v0 = glhittableDll_entrypoint_4();
    if (temp_v0 == -1) {
        return 0;
    }
    if (temp_v0 == -2) {
        return 1;
    }
    func_800EB2DC(arg1, arg0, temp_v0);
    func_800EB2DC(arg0, arg1, temp_v0);
    return 1;
}

int glhittableDll_entrypoint_2(s32 arg0) {
    return ((arg0 + 1) != 0) && ((arg0 + 2) != 0);
}

s32 glhittableDll_entrypoint_3(s32 arg0, s32 arg1, s32 arg2) {
    void func_800EB2DC(void *, s32, s32);

    if (arg2 == -1) {
        return 0;
    }
    if (arg2 == -2) {
        return 1;
    }
    func_800EB2DC(arg1, arg0, arg2);
    func_800EB2DC(arg0, arg1, arg2);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_4.s")

s32 glhittableDll_entrypoint_5(s32 arg0) {
    HitTable *table;
    u16 *entry;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    entry = &table->entries[arg0 & 0xFFFF];
    return ((u32)table->header[1] >> 12) | ((u32)*entry >> 12);
}

s32 glhittableDll_entrypoint_6(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 20) >> 30) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 20) >> 30);
}

s32 glhittableDll_entrypoint_7(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 22) >> 29) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 22) >> 29);
}

s32 glhittableDll_entrypoint_8(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 25) >> 30) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 25) >> 30);
}

s32 glhittableDll_entrypoint_9(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 27) >> 29) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 27) >> 29);
}

s32 glhittableDll_entrypoint_10(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return (table->header[1] & 3) |
           (table->entries[arg0 & 0xFFFF] & 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/func_80800444_glhittableDll.s")

/* extern */

int func_808004D8_glhittableDll(void *arg0, Unk80132ED0 *arg1) {
    s32 func_800F52B8(s32, Unk80132ED0 *);
    s32 var_v0;
    if (arg0 == NULL) {
        return 6;
    }
    var_v0 = 0;
    if (((u32) (*(u32 *)((s8 *)(arg0) + (0x24))) >> 0x16) != 0) {
        var_v0 = 0;
    } else {
        return func_800F52B8((u32) (*(u16 *)((s8 *)(arg0) + (0x1A))) >> 5, arg1);
    }
    return var_v0;
}
