#include "common.h"

/* extern */

u8 *dbtex_entrypoint_0(u8 *arg0) {
    s32 func_800D5944();
    s32 func_800E6950(s32, s32, u8 *);
    void *heap_alloc_sided(s32, s32);
    void rare_memcpy(void *, void *, int);
    s32 *var_s0;
    s32 temp_s1;
    u8 *temp_s2;
    u8 *temp_v0;
    u8 *var_s1;

    if (arg0 == NULL) {
        return NULL;
    }
    if (!((*(s16 *)((s8 *)(arg0) + (6))) & 0x100)) {
        return NULL;
    }
    temp_s1 = ((*(s16 *)((s8 *)(arg0) + (4))) * 8) + 8;
    temp_v0 = heap_alloc_sided((*(s32 *)((s8 *)(arg0) + (0))) + temp_s1, 1);
    rare_memcpy(temp_v0, arg0, temp_s1);
    var_s0 = temp_v0 + 8;
    temp_s2 = ((*(s16 *)((s8 *)(temp_v0) + (4))) * 8) + temp_v0 + 8;
    var_s1 = temp_s2;
    if ((u32) var_s0 < (u32) temp_s2) {
        do {
            func_800E6950(*var_s0 + 0x1EF6, 0, var_s1);
            var_s1 += func_800D5944();
            var_s0 += 2;
        } while ((u32) var_s0 < (u32) temp_s2);
    }
    return temp_v0;
}

/* extern */

void dbtex_entrypoint_1(s32 arg0) {
    s32 heap_free();
    if (arg0 != 0) {
        heap_free();
    }
}
