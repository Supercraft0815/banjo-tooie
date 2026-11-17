#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "tex_native.inc"
#else
#include "common.h"

/* extern */

typedef struct { s32 unk0; s16 unk4; s16 unk6; } Objtex_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x4]; s16 unk4; } Objtex_dbtex_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ u8 *dbtex_entrypoint_0(u8 *arg0) {
    s32 func_800D5944();
    void *func_800E6950(s32, s32, void *);
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
    if (!((((Objtex_arg0 *)arg0)->unk6) & 0x100)) {
        return NULL;
    }
    temp_s1 = ((((Objtex_arg0 *)arg0)->unk4) * 8) + 8;
    temp_v0 = heap_alloc_sided((((Objtex_arg0 *)arg0)->unk0) + temp_s1, 1);
    rare_memcpy(temp_v0, arg0, temp_s1);
    var_s0 = temp_v0 + 8;
    temp_s2 = ((((Objtex_dbtex_entrypoint_0_temp_v0 *)temp_v0)->unk4) * 8) + temp_v0 + 8;
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

#endif
