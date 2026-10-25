#include "common.h"

s32 func_80800000_vpmodule(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (((arg0 >= 0x4B0) && (arg0 < 0x6A4)) || ((arg0 >= 0x834) && (arg0 < 0x898))) {
        return 1;
    }
    if ((arg0 >= 0xC8) && (arg0 < 0x12C)) {
        return 2;
    }
    if ((arg0 >= 0x1F4) && (arg0 < 0x258)) {
        return 3;
    }
    if ((arg0 >= 0x64) && (arg0 < 0xC8)) {
        return 4;
    }
    return -1;
}

typedef struct {
    void *(*unk0)(void *, void *);
    void (*update)(void *, void *);
    void (*free)(void *);
    s32 unkC;
    s32 unk10;
} ModuleEntry;
extern ModuleEntry D_808008C0_vpmodule[];

void *vpmodule_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x20];
        s16 count20;
        s16 count22;
        u8 pad24[8];
        s32 count2C;
        s32 offsets[1];
    } ModuleInput;
    void *heap_alloc(s32);
    void _dbvpl_entrypoint_1(void *, void *, s32, s32);
    void func_808005C4_vpmodule(void *, void *, s32);
    u8 *allocation;
    s32 i;
    s32 *entry;
    s32 count;
    s32 size;
    s32 type;
    void *created;
    u8 *aligned;
    u8 *output;
    u8 *input;
    ModuleEntry *table;

    count = ((ModuleInput *)arg0)->count2C;
    if (count == 0) {
        return NULL;
    }
    size = count * 8 + 8;
    if (size & 0xF) {
        do {
            size++;
        } while (size & 0xF);
    }
    size += ((ModuleInput *)arg0)->count20 * 16 + ((ModuleInput *)arg0)->count22 * 16;
    allocation = heap_alloc(size);
    output = allocation + 8;
    i = 0;
    if (count > 0) {
        table = D_808008C0_vpmodule;
        input = arg0; do {
            entry = (s32 *)(arg0 + *(s32 *)(input + 0x30));
            type = func_80800000_vpmodule(*entry);
            output[0] = type;
            output[1] = 1;
            *(s16 *)(output + 2) = i;
            created = table[type].unk0(arg0, entry);
            i++;
            input += 4;
            output += 8;
            *(void **)(output - 4) = created;
        } while (i != count);
    }
    aligned = output;
    if ((s32)output & 0xF) {
        do {
            aligned++;
        } while ((s32)aligned & 0xF);
    }
    *(s32 *)allocation = aligned - allocation;
    _dbvpl_entrypoint_1(arg0, aligned, arg1, arg2);
    *(s32 *)(allocation + 4) = *(s32 *)allocation + ((ModuleInput *)arg0)->count20 * 16;
    func_808005C4_vpmodule(allocation, arg0, arg1);
    return allocation;
}

void vpmodule_entrypoint_1(u8 *arg0, void *arg1) {
    void heap_free(void *);
    u8 *temp_s1;
    u8 *var_s0;

    var_s0 = arg0 + 8;
    temp_s1 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    if (var_s0 < temp_s1) {
        do {
            D_808008C0_vpmodule[*var_s0].free(*(void **)(var_s0 + 4));
            var_s0 += 8;
        } while (var_s0 < temp_s1);
    }
    heap_free(arg0);
}

void vpmodule_entrypoint_2(u8 *arg0, void *arg1) {
    u8 *temp_s3;
    u8 *var_s0;

    var_s0 = arg0 + 8;
    temp_s3 = ((*(s32 *)((s8 *)arg1 + 0x2C)) * 8) + arg0 + 8;
    if (var_s0 < temp_s3) {
        do {
            if (var_s0[1] != 0) {
                D_808008C0_vpmodule[*var_s0].update(*(void **)(var_s0 + 4), arg1);
            }
            var_s0 += 8;
        } while (var_s0 < temp_s3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/func_808005C4_vpmodule.s")

s32 vpmodule_entrypoint_4(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u32 temp_t0;
    u32 var_v1;

    var_v1 = arg0 + 8;
    temp_t0 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    while (var_v1 < temp_t0) {
        s32 *record = (s32 *)(((s32 *)(arg1 + 0x30))[*(s16 *)(var_v1 + 2)] + arg1);
        if (arg2 == *record) {
            (*(s8 *)((s8 *)(var_v1) + (1))) = arg3;
            return 1;
        }
        var_v1 += 8;
    }
    return 0;
}
