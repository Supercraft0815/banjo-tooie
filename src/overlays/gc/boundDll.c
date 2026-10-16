#include "common.h"

void gcboundDll_entrypoint_0(u8 *arg0) {
    s32 i;

    (*(s32 *)(arg0 + 4)) = 0;
    (*(s32 *)(arg0 + 0)) = 0;
    (*(s32 *)(arg0 + 0xC)) = 0;
    (*(s32 *)(arg0 + 8)) = 0;
    (*(s32 *)(arg0 + 0x14)) = 0;
    (*(s32 *)(arg0 + 0x10)) = 0;
    for (i = 0; i < 0xC8; i++) {
        arg0[i + 0x18] = 1;
    }
    (*(s32 *)(arg0 + 0xE0)) = 0;
}

/* extern */

void gcboundDll_entrypoint_1(void *arg0) {
    s32 func_800B42FC(s32, s32);
    s32 heap_alloc(s32);
    (*(s32 *)((s8 *)(arg0) + (4))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0xC))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0x14))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0xE0))) = func_800B42FC(0x18, 0xA);
}

/* extern */

void func_808000AC_gcboundDll(s32 arg0, s32 *arg1, u32 *arg2) {
    s32 func_800B422C(s32, s32);
    s32 heap_free(u32);
    u32 temp_s1;
    u32 var_a3;
    u32 var_s0;

    var_a3 = *arg2;
    if (var_a3 != 0) {
        var_s0 = var_a3;
        temp_s1 = (*arg1 * 0x1C) + var_a3;
        if (var_a3 < temp_s1) {
            do {
                func_800B422C(arg0 + 0xE0, var_s0 + 0x18);
                var_s0 += 0x1C;
            } while (var_s0 < temp_s1);
            var_a3 = *arg2;
        }
        heap_free(var_a3);
        *arg2 = 0;
        *arg1 = 0;
    }
}

/* extern */

void gcboundDll_entrypoint_2(s32 arg0) {
    s32 func_800B42DC(s32);
    func_808000AC_gcboundDll(arg0, (s32 *) arg0, arg0 + 4);
    func_808000AC_gcboundDll(arg0, arg0 + 8, arg0 + 0xC);
    func_808000AC_gcboundDll(arg0, arg0 + 0x10, arg0 + 0x14);
    func_800B42DC((*(s32 *)((s8 *)(arg0) + (0xE0))));
    (*(s32 *)((s8 *)(arg0) + (0xE0))) = 0;
}

/* extern */

void func_808001A8_gcboundDll(s32 arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 func_800B3CDC(s32 *, s32);
    void func_800EE88C(f32 *, s16 *);
    struct BoundData {
        f32 position[3];
        s16 value;
        s16 radius;
        u8 pad10[4];
        u16 index : 11;
        u16 flag7 : 1;
        u16 kind : 3;
        u16 flag6 : 1;
    } *entry;

    entry = (struct BoundData *)func_800B3CDC((s32 *)(arg0 + 0xE0), arg1 + 0x18);
    func_800EE88C(entry->position, arg2);
    entry->value = arg3;
    entry->radius = (s32)((f32)arg4 * 0.5f);
    entry->index = arg5;
    entry->flag6 = arg6;
    entry->flag7 = arg7;
    entry->kind = arg8;
}

/* extern */

void *func_80800280_gcboundDll(s32 *arg0, void **arg1, s32 arg2) {
    void func_800B4290(void *);
    void *heap_realloc(void *, s32);
    struct BoundEntry {
        u32 index : 23;
        u32 active : 1;
        u8 count : 8;
        u8 data[16];
        s32 value;
        u8 tail[4];
    } *entry;
    u8 *data;

    *arg0 += 1;
    data = heap_realloc(*arg1, *arg0 * 0x1C);
    *arg1 = data;
    entry = (struct BoundEntry *)(data + *arg0 * 0x1C) - 1;
    entry->index = 0;
    entry->count = 0;
    entry->value = arg2;
    entry->active = 1;
    func_800B4290(entry->tail);
    return entry;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_5.s")

s32 func_80800630_gcboundDll(u8 *arg0, s16 *arg1) {
    s32 func_800B42A0(u8 *, s16 *);
    return func_800B42A0(*(u8 **)(arg0 + 0xE0), arg1 + 12);
}

s32 func_80800654_gcboundDll(u8 *arg0, s16 *arg1) {
    return arg1[13] * 0x18 + func_80800630_gcboundDll(arg0, arg1);
}

s32 func_80800688_gcboundDll(u8 *arg0, s16 *arg1)
{
    return func_80800630_gcboundDll(arg0, arg1);
}

s32 func_808006A8_gcboundDll(u8 *arg0, s16 *arg1) {
    return ((*(u32 *)arg1 >> 9) * 0x18) + func_80800688_gcboundDll(arg0, arg1);
}

void func_808006E0_gcboundDll(u8 *arg0, s16 *arg1)
{
    func_808006A8_gcboundDll(arg0, arg1);
}

s32 func_80800700_gcboundDll(u8 *arg0, s16 *arg1)
{
    return func_80800654_gcboundDll(arg0, arg1);
}

/* extern */

void func_80800720_gcboundDll(s32 arg0, s32 arg1, u32 arg2) {
    void func_80800EBC_gcboundDll(u8 *, s16 *);
    u32 temp_s1;
    u32 var_s0;

    temp_s1 = (arg1 * 0x1C) + arg2;
    var_s0 = arg2;
    if (arg2 < temp_s1) {
        do {
            func_80800EBC_gcboundDll((u8 *)arg0, (s16 *)var_s0);
            var_s0 += 0x1C;
        } while (var_s0 < temp_s1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_808008D8_gcboundDll.s")

void gcboundDll_entrypoint_7(s32 arg0) {
    void func_80800F6C_gcboundDll(s32, s32, s32);
    func_80800F6C_gcboundDll(arg0, arg0, arg0 + 4);
    func_80800F6C_gcboundDll(arg0, arg0 + 8, arg0 + 0xC);
    func_80800F6C_gcboundDll(arg0, arg0 + 0x10, arg0 + 0x14);
}

void *func_80800CA8_gcboundDll(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 *count = &arg0;
    u32 temp_t0;
    u32 var_a0;
    u32 var_v1;

    var_v1 = 0;
    if ((arg1 == 0) || (arg2 == *arg3)) {
        return NULL;
    }
    var_a0 = arg1;
    temp_t0 = (*count * 0x1C) + var_a0;
    if (var_a0 < temp_t0) {
        do {
            arg1 = *(s16 *)((s8 *)var_a0 + 0x18);
            if (arg1 >= arg2) {
                if ((*arg3 == 0) || (arg1 < *arg3)) {
                    *arg3 = arg1;
                    arg1 = *(s16 *)((s8 *)var_a0 + 0x18);
                    var_v1 = var_a0;
                }
                if (arg2 == arg1) {
                    return (void *)var_a0;
                }
            }
            var_a0 += 0x1C;
        } while (var_a0 < temp_t0);
    }
    return (void *)var_v1;
}

/* extern */

void func_80800D40_gcboundDll(void *arg0) {
    s32 func_800B4134(u8 **, void *);
    void func_800B4354(u8 **);
    s32 func_800B4374(s16 *);
    void *temp_v0;
    void *var_s0;
    s32 sp2C;
    s32 var_s2;

    var_s2 = func_800B4374(*(s16 **)((s8 *)arg0 + 0xE0));
    if (var_s2 != 0) {
        do {
            sp2C = 0;
            var_s0 = 0;
            temp_v0 = func_80800CA8_gcboundDll((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4))), var_s2, &sp2C);
            if (temp_v0 != 0) {
                var_s0 = temp_v0;
            }
            temp_v0 = func_80800CA8_gcboundDll((*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0xC))), var_s2, &sp2C);
            if (temp_v0 != 0) {
                var_s0 = temp_v0;
            }
            temp_v0 = func_80800CA8_gcboundDll((*(s32 *)((s8 *)(arg0) + (0x10))), (*(s32 *)((s8 *)(arg0) + (0x14))), var_s2, &sp2C);
            if (temp_v0 != 0) {
                var_s0 = temp_v0;
            }
            if (var_s0 != 0) {
                func_800B4134((u8 **)((s8 *)arg0 + 0xE0), (s8 *)var_s0 + 0x18);
                var_s2 = sp2C + 1;
            }
        } while (var_s0 != 0);
    }
    func_800B4354((u8 **)((s8 *)arg0 + 0xE0));
}

void gcboundDll_entrypoint_8(void *arg0) { void func_808008D8_gcboundDll(void *, s32, s32); void func_80800D40_gcboundDll(void *); func_808008D8_gcboundDll(arg0, (*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4)))); func_808008D8_gcboundDll(arg0, (*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0xC)))); func_808008D8_gcboundDll(arg0, (*(s32 *)((s8 *)(arg0) + (0x10))), (*(s32 *)((s8 *)(arg0) + (0x14)))); func_80800D40_gcboundDll(arg0); }

void func_80800E6C_gcboundDll(u8 *arg0, u8 *arg1) { void rare_memcpy(void *, void *, int); u8 sp18[0x18]; rare_memcpy(sp18, arg0, 0x18); rare_memcpy(arg0, arg1, 0x18); rare_memcpy(arg1, sp18, 0x18); }

void func_80800EBC_gcboundDll(u8 *arg0, s16 *arg1) {     struct BoundEntry {         u32 unused[5];         u32 pad : 11;         u32 flag : 1;         u32 rest : 20;     };     s32 start;     struct BoundEntry *end;     int n;     struct BoundEntry *entry;     u32 old;      n = 0;     start = func_80800630_gcboundDll(arg0, arg1);     end = (struct BoundEntry *)func_80800654_gcboundDll(arg0, arg1) - 1;     entry = end;     if ((u32)end >= (u32)start) {         if (end->flag) {         do {             entry--;             n++;         } while ((u32)entry >= (u32)start && entry->flag);         }     }     old = *(u32 *)arg1;     *(u32 *)arg1 = (((((arg1[13] - n) & 0x7FFFFF) ^ (old >> 9)) << 9) ^ old);     ((s8 *)arg1)[3] = n; } 
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800F6C_gcboundDll.s")

s32 func_8080132C_gcboundDll(s32 arg0) { switch (arg0) { case 1: return 1; case 2: return 2; case 3: return 4; default: return 7; } }

s32 func_80801370_gcboundDll(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 end;

    end = arg0 * 0x1C + arg1;
    if (arg2 == 0) {
        arg2 = arg1 - 0x1C;
    }
    arg2 += 0x1C;
    while ((u32)arg2 < end) {
        if (arg3 == *(s32 *)(arg2 + 0x14) || arg4 != 0) {
            return arg2;
        }
        arg2 += 0x1C;
    }
    return 0;
}

/* extern */

void func_808013D4_gcboundDll(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4))), arg3, arg1, arg2);
}

void func_8080141C_gcboundDll(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0xC))), arg2, arg1, 0);
}

void func_80801450_gcboundDll(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (0x10))), (*(s32 *)((s8 *)(arg0) + (0x14))), arg2, arg1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80801484_gcboundDll.s")
