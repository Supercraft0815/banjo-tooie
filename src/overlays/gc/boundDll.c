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
}    typedef struct { s32 unk0; BtIntPtr unk4; s32 unk8; BtIntPtr unkC; s32 unk10; BtIntPtr unk14; u8 pad18[0xC8]; BtIntPtr unkE0; } ObjboundDll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void gcboundDll_entrypoint_1(void *arg0) {
    s16 *func_800B42FC(s32 size, s32 count);
    BtIntPtr heap_alloc(s32);
    (((ObjboundDll_arg0 *)arg0)->unk4) = heap_alloc(0);
    (((ObjboundDll_arg0 *)arg0)->unkC) = heap_alloc(0);
    (((ObjboundDll_arg0 *)arg0)->unk14) = heap_alloc(0);
    (((ObjboundDll_arg0 *)arg0)->unkE0) = func_800B42FC(0x18, 0xA);
}

/* extern */

void func_808000AC_gcboundDll(BtIntPtr arg0, s32 *arg1, u32 *arg2) {
    void func_800B422C(BtIntPtr, BtIntPtr);
    void heap_free(void *memory);
    BtUIntPtr temp_s1;
    BtUIntPtr var_a3;
    BtUIntPtr var_s0;

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

void gcboundDll_entrypoint_2(BtIntPtr arg0) {
    void func_800B42DC(void* arg0);
    func_808000AC_gcboundDll(arg0, (s32 *) arg0, arg0 + 4);
    func_808000AC_gcboundDll(arg0, arg0 + 8, arg0 + 0xC);
    func_808000AC_gcboundDll(arg0, arg0 + 0x10, arg0 + 0x14);
    func_800B42DC((((ObjboundDll_arg0 *)arg0)->unkE0));
    (((ObjboundDll_arg0 *)arg0)->unkE0) = 0;
}

/* extern */

void func_808001A8_gcboundDll(BtIntPtr arg0, BtIntPtr arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    BtIntPtr func_800B3CDC(s32 *, BtIntPtr);
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
    void *heap_realloc(void *, BtIntPtr);
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

void gcboundDll_entrypoint_3(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    BtIntPtr func_808013D4_gcboundDll(void *, s32, s32, BtIntPtr);
    s32 func_80801484_gcboundDll(u8 *, s16 *, s32, s16 *, s32);
    s16 *entry;
    s32 found = 0;

    entry = (s16 *)func_808013D4_gcboundDll(arg0, arg1, arg7, 0);
    if (entry != NULL) {
        do {
            if (func_80801484_gcboundDll(arg0, entry, arg1, arg2, arg3)) {
                func_808001A8_gcboundDll((BtIntPtr)arg0, (BtIntPtr)entry, arg2, arg3, arg4, arg5, arg6, arg7, 0);
                if (arg7 == 0) {
                    goto done;
                }
                found = 1;
            }
            entry = (s16 *)func_808013D4_gcboundDll(arg0, arg1, arg7, (BtIntPtr)entry);
        } while (entry != NULL);
    }
    if (arg7 == 0 || found == 0) {
        func_808001A8_gcboundDll((BtIntPtr)arg0, (BtIntPtr)func_80800280_gcboundDll((s32 *)arg0, (void **)(arg0 + 4), arg1), arg2, arg3, arg4, arg5, arg6, arg7, 0);
    }
done:
    ;
}

void gcboundDll_entrypoint_4(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    BtIntPtr func_8080141C_gcboundDll(u8 *, s32, BtIntPtr);
    s32 func_80801484_gcboundDll(u8 *, s16 *, s32, s16 *, s32);
    s32 func_8080132C_gcboundDll(s32);
    s16 *entry;

    entry = (s16 *)func_8080141C_gcboundDll(arg0, arg1, 0);
    while (entry != NULL) {
        if (func_80801484_gcboundDll(arg0, entry, arg1, arg2, arg3)) {
            break;
        }
        entry = (s16 *)func_8080141C_gcboundDll(arg0, arg1, (BtIntPtr)entry);
    }
    if (entry == NULL) {
        entry = func_80800280_gcboundDll((s32 *)(arg0 + 8), (void **)(arg0 + 0xC), arg1);
    }
    func_808001A8_gcboundDll((BtIntPtr)arg0, (BtIntPtr)entry, arg2, arg3, arg5, 0, 0, 0, func_8080132C_gcboundDll(arg4));
}

void gcboundDll_entrypoint_5(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    BtIntPtr func_80801450_gcboundDll(u8 *, s32, BtIntPtr);
    s32 func_80801484_gcboundDll(u8 *, s16 *, s32, s16 *, s32);
    s16 *entry;

    entry = (s16 *)func_80801450_gcboundDll(arg0, arg1, 0);
    while (entry != NULL) {
        if (func_80801484_gcboundDll(arg0, entry, arg1, arg2, arg3)) {
            break;
        }
        entry = (s16 *)func_80801450_gcboundDll(arg0, arg1, (BtIntPtr)entry);
    }
    if (entry == NULL) {
        entry = func_80800280_gcboundDll((s32 *)(arg0 + 0x10), (void **)(arg0 + 0x14), arg1);
    }
    func_808001A8_gcboundDll((BtIntPtr)arg0, (BtIntPtr)entry, arg2, arg3, arg4, 0, arg6, 0, arg5);
}

BtIntPtr func_80800630_gcboundDll(u8 *arg0, s16 *arg1) {
    void *func_800B42A0(u8 *data, s16 *range);
    return func_800B42A0(*(u8 **)(arg0 + 0xE0), arg1 + 12);
}

BtIntPtr func_80800654_gcboundDll(u8 *arg0, s16 *arg1) {
    return arg1[13] * 0x18 + func_80800630_gcboundDll(arg0, arg1);
}

BtIntPtr func_80800688_gcboundDll(u8 *arg0, s16 *arg1)
{
    return func_80800630_gcboundDll(arg0, arg1);
}

BtIntPtr func_808006A8_gcboundDll(u8 *arg0, s16 *arg1) {
    return ((*(u32 *)arg1 >> 9) * 0x18) + func_80800688_gcboundDll(arg0, arg1);
}

s32 func_808006E0_gcboundDll(u8 *arg0, s16 *arg1)
{
    BT_NATIVE_ONLY(return) func_808006A8_gcboundDll(arg0, arg1);
}

BtIntPtr func_80800700_gcboundDll(u8 *arg0, s16 *arg1)
{
    return func_80800654_gcboundDll(arg0, arg1);
}

/* extern */

void func_80800720_gcboundDll(BtIntPtr arg0, s32 arg1, u32 arg2) {
    void func_80800EBC_gcboundDll(u8 *, s16 *);
    u32 temp_s1;
    BtUIntPtr var_s0;

    temp_s1 = (arg1 * 0x1C) + arg2;
    var_s0 = arg2;
    if (arg2 < temp_s1) {
        do {
            func_80800EBC_gcboundDll((u8 *)arg0, (s16 *)var_s0);
            var_s0 += 0x1C;
        } while (var_s0 < temp_s1);
    }
}

void gcboundDll_entrypoint_6(u8 *arg0) {
    void func_80800E6C_gcboundDll(u8 *, u8 *);
    void func_80800EBC_gcboundDll(u8 *, s16 *);
    struct BoundEntry {
        u8 data[0x14];
        u32 : 11;
        u32 flag : 1;
        u32 : 20;
    };
    s16 *var_s5;
    s32 temp_fp;
    BtIntPtr temp_s4;
    BtIntPtr temp_v0;
    s32 var_s7;
    BtUIntPtr var_s0;
    BtUIntPtr var_s3;
    u8 *temp_v0_2;
    u8 *var_s1;

    temp_fp = *(s32 *)arg0;
    var_s5 = *(s16 **)(arg0 + 4);
    var_s7 = 0;
    if (temp_fp > 0) {
        do {
            temp_s4 = func_80800630_gcboundDll(arg0, var_s5);
            temp_v0 = func_80800654_gcboundDll(arg0, var_s5);
            var_s3 = temp_v0 - 0x30;
            if (var_s3 >= (u32)temp_s4) {
                do {
                    temp_v0_2 = (u8 *)(var_s3 + 0x18);
                    var_s0 = var_s3;
                    var_s1 = temp_v0_2;
                    if ((var_s3 < (u32)temp_v0) &&
                        ((struct BoundEntry *)var_s3)->flag &&
                        !((struct BoundEntry *)temp_v0_2)->flag) {
loop_5:
                        func_80800E6C_gcboundDll((u8 *)var_s0, var_s1);
                        var_s0 += 0x18;
                        var_s1 += 0x18;
                        if ((var_s0 < (u32)temp_v0) &&
                            ((struct BoundEntry *)var_s0)->flag) {
                            if (!((struct BoundEntry *)var_s1)->flag) {
                                goto loop_5;
                            }
                        }
                    }
                    var_s3 -= 0x18;
                } while (var_s3 >= (u32)temp_s4);
            }
            func_80800EBC_gcboundDll(arg0, var_s5);
            var_s7 += 1;
            var_s5 += 0xE;
        } while (var_s7 != temp_fp);
    }
    func_80800720_gcboundDll((BtIntPtr)arg0, *(s32 *)(arg0 + 8), *(u32 *)(arg0 + 0xC));
    func_80800720_gcboundDll((BtIntPtr)arg0, *(s32 *)(arg0 + 0x10), *(u32 *)(arg0 + 0x14));
}
typedef struct { f32 v[2]; } Pair;
void func_808008D8_gcboundDll(void *arg0, s32 arg1, s32 arg2) {
    f32 sqrtf(f32);

    extern Pair D_808015B0_gcboundDll;
    extern Pair D_808015B8_gcboundDll;
    extern Pair D_808015C0_gcboundDll;
    extern Pair D_808015C8_gcboundDll;
    BtUIntPtr group;
    u32 group_end;
    BtUIntPtr first;
    BtUIntPtr end;

    if (arg2 != 0 && arg1 != 0) {
        group_end = arg2 + arg1 * 0x1C;
        for (group = (u32)arg2; group < group_end; group += 0x1C) {
            Pair minimum = D_808015B0_gcboundDll;
            Pair maximum = D_808015B8_gcboundDll;
            Pair lower = D_808015C0_gcboundDll;
            Pair upper = D_808015C8_gcboundDll;
            BtUIntPtr item;
            f32 radius;
            f32 distance;

            first = func_80800688_gcboundDll((u8 *)arg0, (s16 *)group);
            end = func_808006A8_gcboundDll((u8 *)arg0, (s16 *)group);
            for (item = first; item < end; item += 0x18) {
                lower.v[0] = *(f32 *)item - *(s16 *)(item + 0xC);
                lower.v[1] = *(f32 *)(item + 8) - *(s16 *)(item + 0xC);
                upper.v[0] = *(s16 *)(item + 0xC) + *(f32 *)item;
                upper.v[1] = *(s16 *)(item + 0xC) + *(f32 *)(item + 8);
                if (item == first || lower.v[0] < minimum.v[0]) {
                    minimum.v[0] = lower.v[0];
                }
                if (item == first || lower.v[1] < minimum.v[1]) {
                    minimum.v[1] = lower.v[1];
                }
                if (item == first || maximum.v[0] < upper.v[0]) {
                    maximum.v[0] = upper.v[0];
                }
                if (item == first || maximum.v[1] < upper.v[1]) {
                    maximum.v[1] = upper.v[1];
                }
                radius = *(s16 *)(item + 0xC);
                *(f32 *)(item + 0x10) = radius * radius;
            }
            end = func_80800700_gcboundDll((u8 *)arg0, (s16 *)group);
            for (item = func_808006E0_gcboundDll((u8 *)arg0, (s16 *)group);
                 item < end; item += 0x18) {
                *(f32 *)(item + 0x10) = (f32)*(s16 *)(item + 0xC) * (f32)*(s16 *)(item + 0xC);
            }
            *(f32 *)(group + 4) = (maximum.v[0] + minimum.v[0]) * 0.5f;
            *(f32 *)(group + 0xC) = (maximum.v[1] + minimum.v[1]) * 0.5f;
            *(f32 *)(group + 8) = 0;
            *(f32 *)(group + 0x10) = 0.0f;
            end = func_808006A8_gcboundDll((u8 *)arg0, (s16 *)group);
            for (item = first; item < end; item += 0x18) {
                lower.v[0] = *(f32 *)item - *(f32 *)(group + 4);
                lower.v[1] = *(f32 *)(item + 8) - *(f32 *)(group + 0xC);
                radius = sqrtf(lower.v[0] * lower.v[0] + lower.v[1] * lower.v[1]);
                distance = radius + *(s16 *)(item + 0xC);
                radius = distance * distance;
                if (*(f32 *)(group + 0x10) < radius) {
                    *(f32 *)(group + 0x10) = radius;
                }
            }
        }
    }
}

struct BoundHeader {
    u32 count : 23;
    u32 rest : 9;
    u32 unused[4];
    s32 key;
    s16 start;
    s16 length;
};

void gcboundDll_entrypoint_7(BtIntPtr arg0) {
    void func_80800F6C_gcboundDll(BtIntPtr, s32 *, struct BoundHeader **);
    func_80800F6C_gcboundDll(arg0, (s32 *)arg0, (struct BoundHeader **)(arg0 + 4));
    func_80800F6C_gcboundDll(arg0, (s32 *)(arg0 + 8), (struct BoundHeader **)(arg0 + 0xC));
    func_80800F6C_gcboundDll(arg0, (s32 *)(arg0 + 0x10), (struct BoundHeader **)(arg0 + 0x14));
}    typedef struct { u8 pad0[0x18]; s16 unk18; } ObjboundDll_func_80800CA8_gcboundDll_var_a0; /* offsets.py genstruct: fields from raw offsets on var_a0; rename once understood */

void *func_80800CA8_gcboundDll(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 *count = &arg0;
    BtUIntPtr temp_t0;
    BtUIntPtr var_a0;
    BtUIntPtr var_v1;

    var_v1 = 0;
    if ((arg1 == 0) || (arg2 == *arg3)) {
        return NULL;
    }
    var_a0 = arg1;
    temp_t0 = (*count * 0x1C) + var_a0;
    if (var_a0 < temp_t0) {
        do {
            arg1 = ((ObjboundDll_func_80800CA8_gcboundDll_var_a0 *)var_a0)->unk18;
            if (arg1 >= arg2) {
                if ((*arg3 == 0) || (arg1 < *arg3)) {
                    *arg3 = arg1;
                    arg1 = ((ObjboundDll_func_80800CA8_gcboundDll_var_a0 *)var_a0)->unk18;
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
            temp_v0 = func_80800CA8_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk0), (((ObjboundDll_arg0 *)arg0)->unk4), var_s2, &sp2C);
            if (temp_v0 != 0) {
                var_s0 = temp_v0;
            }
            temp_v0 = func_80800CA8_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk8), (((ObjboundDll_arg0 *)arg0)->unkC), var_s2, &sp2C);
            if (temp_v0 != 0) {
                var_s0 = temp_v0;
            }
            temp_v0 = func_80800CA8_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk10), (((ObjboundDll_arg0 *)arg0)->unk14), var_s2, &sp2C);
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

void gcboundDll_entrypoint_8(void *arg0) { void func_808008D8_gcboundDll(void *, s32, s32); void func_80800D40_gcboundDll(void *); func_808008D8_gcboundDll(arg0, (((ObjboundDll_arg0 *)arg0)->unk0), (((ObjboundDll_arg0 *)arg0)->unk4)); func_808008D8_gcboundDll(arg0, (((ObjboundDll_arg0 *)arg0)->unk8), (((ObjboundDll_arg0 *)arg0)->unkC)); func_808008D8_gcboundDll(arg0, (((ObjboundDll_arg0 *)arg0)->unk10), (((ObjboundDll_arg0 *)arg0)->unk14)); func_80800D40_gcboundDll(arg0); }

void func_80800E6C_gcboundDll(u8 *arg0, u8 *arg1) { void rare_memcpy(void *, void *, int); u8 sp18[0x18]; rare_memcpy(sp18, arg0, 0x18); rare_memcpy(arg0, arg1, 0x18); rare_memcpy(arg1, sp18, 0x18); }

void func_80800EBC_gcboundDll(u8 *arg0, s16 *arg1) {     struct BoundEntry {         u32 unused[5];         u32 pad : 11;         u32 flag : 1;         u32 rest : 20;     };     BtIntPtr start;     struct BoundEntry *end;     int n;     struct BoundEntry *entry;     u32 old;      n = 0;     start = func_80800630_gcboundDll(arg0, arg1);     end = (struct BoundEntry *)func_80800654_gcboundDll(arg0, arg1) - 1;     entry = end;     if ((BtUIntPtr)end >= (u32)start) {         if (end->flag) {         do {             entry--;             n++;         } while ((BtUIntPtr)entry >= (u32)start && entry->flag);         }     }     old = *(u32 *)arg1;     *(u32 *)arg1 = (((((arg1[13] - n) & 0x7FFFFF) ^ (old >> 9)) << 9) ^ old);     ((s8 *)arg1)[3] = n; } 
void func_80800F6C_gcboundDll(BtIntPtr arg0, s32 *pCount, struct BoundHeader **pList) {
    BtIntPtr func_800B3CDC(s32 *, BtIntPtr);
    void func_800B422C(BtIntPtr, BtIntPtr);
    void func_800B4290(void *);
    int func_800F0064(f32 *, f32, f32 *);
    void *heap_realloc(void *, BtIntPtr);
    void rare_memcpy(void *, void *, int);
    struct BoundHeader *current;
    struct BoundHeader *other;
    BtUIntPtr second;
    BtIntPtr first;
    s32 searching;
    BtIntPtr end1;
    BtIntPtr end2;
    BtUIntPtr copy;

    if (pList == NULL || pCount == NULL) {
        return;
    }
    for (current = *pList; current < *pList + *pCount; current++) {
        for (other = current + 1; other < *pList + *pCount; other++) {
            if (current->key == other->key && current->length != 0 && other->length != 0) {
                end1 = func_80800654_gcboundDll(arg0, (s16 *)current);
                searching = 1;
                for (first = func_80800630_gcboundDll(arg0, (s16 *)current); (u32)first < (u32)end1 && searching; first += 0x18) {
                    end2 = func_80800654_gcboundDll(arg0, (s16 *)other);
                    for (second = func_80800630_gcboundDll(arg0, (s16 *)other); second < (u32)end2 && searching; second += 0x18) {
                        if (func_800F0064((f32 *)first, (f32)(*(s16 *)(second + 0xC) + *(s16 *)(first + 0xC)), (f32 *)second)) {
                            copy = func_80800630_gcboundDll(arg0, (s16 *)other);
                            for (; copy < (u32)end2; copy += 0x18) {
                                rare_memcpy(func_800B3CDC((s32 *)(arg0 + 0xE0), (BtIntPtr)&current->start), (void *)copy, 0x18);
                            }
                            func_800B422C(arg0 + 0xE0, (BtUIntPtr)&other->start);
                            other->count = ((u8 *)other)[3] = 0;
                            other = current;
                            searching = 0;
                        }
                    }
                }
            }
        }
    }
    for (current = *pList; current < *pList + *pCount; current++) {
        if (current->length == 0) {
            searching = 1;
            for (other = current + 1; other < *pList + *pCount && searching; other++) {
                if (other->length != 0) {
                    rare_memcpy(current, other, 0x1C);
                    searching = 0;
                    func_800B4290(&other->start);
                }
            }
        }
    }
    for (current = *pList; current < *pList + *pCount && current->length != 0; current++) {
    }
    *pCount = current - *pList;
    *pList = heap_realloc(*pList, *pCount * sizeof(struct BoundHeader));
}

s32 func_8080132C_gcboundDll(s32 arg0) { switch (arg0) { case 1: return 1; case 2: return 2; case 3: return 4; default: return 7; } }

BtIntPtr func_80801370_gcboundDll(s32 arg0, s32 arg1, BtIntPtr arg2, s32 arg3, s32 arg4) {
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

BtIntPtr func_808013D4_gcboundDll(void *arg0, s32 arg1, s32 arg2, BtIntPtr arg3) {
    BtIntPtr func_80801370_gcboundDll(s32, s32, BtIntPtr, s32, s32);
    return func_80801370_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk0), (((ObjboundDll_arg0 *)arg0)->unk4), arg3, arg1, arg2);
}

BtIntPtr func_8080141C_gcboundDll(u8 *arg0, s32 arg1, BtIntPtr arg2) {
    BtIntPtr func_80801370_gcboundDll(s32, s32, BtIntPtr, s32, s32);
    return func_80801370_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk8), (((ObjboundDll_arg0 *)arg0)->unkC), arg2, arg1, 0);
}

BtIntPtr func_80801450_gcboundDll(u8 *arg0, s32 arg1, BtIntPtr arg2) {
    BtIntPtr func_80801370_gcboundDll(s32, s32, BtIntPtr, s32, s32);
    return func_80801370_gcboundDll((((ObjboundDll_arg0 *)arg0)->unk10), (((ObjboundDll_arg0 *)arg0)->unk14), arg2, arg1, 0);
}

s32 func_80801484_gcboundDll(u8 *arg0, s16 *arg1, s32 arg2, s16 *arg3, s32 arg4) {
    void func_800EE88C(f32 *, s16 *);
    int func_800F0064(f32 *, f32, f32 *);
    f32 distance;
    BtUIntPtr end;
    f32 position[3];
    BtUIntPtr current;

    func_800EE88C(position, arg3);
    end = func_80800654_gcboundDll(arg0, arg1);
    current = func_80800630_gcboundDll(arg0, arg1);
    while (current < end) {
        distance = (f32)arg3[1] - ((f32 *)current)[1];
        if (distance * distance < 250000.0f &&
            func_800F0064(position, (f32)(((s16 *)current)[6] + arg4), (f32 *)current)) {
            return 1;
        }
        current += 0x18;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/gc/boundDll.data.s */
Pair D_808015B0_gcboundDll BT_DATA(4, overlays_gc_boundDll, 0x0) = { { 0.0f, 0.0f } };
Pair D_808015B8_gcboundDll BT_DATA(4, overlays_gc_boundDll, 0x8) = { { 0.0f, 0.0f } };
Pair D_808015C0_gcboundDll BT_DATA(4, overlays_gc_boundDll, 0x10) = { { 0.0f, 0.0f } };
Pair D_808015C8_gcboundDll BT_DATA(4, overlays_gc_boundDll, 0x18) = { { 0.0f, 0.0f } };
