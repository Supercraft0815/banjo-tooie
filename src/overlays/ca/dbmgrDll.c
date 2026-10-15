#include "common.h"

/* extern */

void cadbmgrDll_entrypoint_0(u8 **arg0, s32 arg1) {
    s32 func_800A56A4();
    void *heap_alloc(s32);
    s32 i;

    *arg0 = heap_alloc((arg1 * 2) + 0x40);
    for (i = 1; i < 9; i++) {
        ((s16 *)*arg0)[i + 15] = 0;
        ((s32 *)*arg0)[i - 1] = 0;
    }
    (*(s32 *)((s8 *)(*arg0) + (0x38))) = arg1;
    func_800A56A4();
}

/* extern */

void cadbmgrDll_entrypoint_1(s32 *arg0) {
    s32 func_800A56A4();
    s32 heap_free(s32);
    func_800A56A4();
    heap_free(*arg0);
    *arg0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/func_808000F4_cadbmgrDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/cadbmgrDll_entrypoint_2.s")

/* extern */

struct CadbmgrData {
    s32 counts[8];
    s16 handles[8];
    s32 invalid;
    s32 zero;
};

s32 func_808003D8_cadbmgrDll(struct CadbmgrData *arg0, s32 arg1, s32 arg2) {
    s16 func_8001B668(s32, s32);
    void *func_8001B710(s16, s32);
    void func_8001B754(s16);
    s32 func_800A57EC(s32);
    s16 handle;
    s16 *temp_v0;
    s16 *saved[2];

    if (arg2 != 0) {
        if (arg0->counts[arg1 - 1] != 0) {
            func_8001B710(arg0->handles[arg1 - 1], func_800A57EC(arg1) * arg2);
        } else {
            arg0->handles[arg1 - 1] = func_8001B668(0, func_800A57EC(arg1));
        }
    } else {
        temp_v0 = (s16 *)arg0 + arg1;
        if (arg0->counts[arg1 - 1] != 0) {
            handle = temp_v0[15];
            saved[1] = temp_v0;
            func_8001B754(handle);
            temp_v0 = saved[1];
            temp_v0[15] = 0;
        }
    }
    arg0->counts[arg1 - 1] = arg2;
    arg0->invalid = -1;
    arg0->zero = 0;
    return 1;
}

s32 func_808004C4_cadbmgrDll(s32 *arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 var_v1;
    u8 temp_a0;
    u16 *var_a2;

    var_v0 = arg0[14] - 1;
    var_v1 = *(arg0 + arg1 - 1);
    if (var_v0 >= 0) {
        var_a2 = (u16 *)arg0 + var_v0;
        do {
            if ((arg1 == (*(u8 *)((s8 *)(var_a2) + (0x3C)))) && (arg2 < var_v0)) {
                temp_a0 = (*(u8 *)((s8 *)(var_a2) + (0x3D)));
                if (var_v1 >= (s32) temp_a0) {
                    var_v1 = (s32) temp_a0;
                }
            }
            var_v0 -= 1;
            var_a2 -= 1;
        } while (var_v0 >= 0);
    }
    return var_v1;
}

/* extern */

void func_80800528_cadbmgrDll(s32 arg0, s32 arg1, s32 arg2) {
    void func_808005AC_cadbmgrDll(s32, s32, s32, s32);
    s32 var_s0;

    for (var_s0 = *((s32 *)arg0 + arg1 - 1) - 1; arg2 < var_s0; var_s0--) {
        func_808005AC_cadbmgrDll(arg0, arg1, var_s0 - 1, var_s0);
    }
}

/* extern */

void func_808005AC_cadbmgrDll(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_8001B798(s16);
    s32 func_800A57EC(s32);
    void rare_memcpy(void *, void *, int);
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_800A57EC(arg1);
    temp_v0 = func_8001B798(*(s16 *)((s8 *)arg0 + (arg1 << 1) + 0x1E));
    rare_memcpy((void *)((s8 *)temp_v0 + arg3 * sp1C), (void *)((s8 *)temp_v0 + arg2 * sp1C), sp1C);
}
