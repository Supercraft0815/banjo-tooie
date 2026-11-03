#include "common.h"

typedef struct { s16 vtxStart; u8 vtxCount; u8 dirty; s16 a[3]; s16 b[3]; s32 pad10; } VpCell;
typedef struct { u8 type; u8 pad1; s16 index; s32 data; } VpModule;
typedef struct { s32 dataOffset; s32 vtxOffset; VpModule modules[1]; } VpHeaderA;
typedef struct { u8 pad0[0x14]; s32 cellCount; u8 pad18[4]; s32 cellOffset; u8 pad20[0xC]; s32 moduleCount; s32 recordOffsets[1]; } VpHeaderB;
typedef struct { u8 pad0[0x14]; u16 desc[1][2]; } VpRecord;
struct VpDst { u8 pad[0x18]; u8 v[1][16]; };

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
    void (*unk10)(void *, u8);
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
    void func_808005C4_vpmodule();
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

void vpmodule_entrypoint_3(VpHeaderA *arg0, VpHeaderB *arg1, struct VpDst *arg2) {
    s32 func_800E3DC0(s16 *, s16 *);
    s32 pad;
    VpModule *modulesEnd;
    VpCell *start;
    VpCell *cell;
    VpCell *end;
    u8 *p;
    VpModule *module;
    u8 *limit;
    u8 *vertices;
    s32 index;
    VpRecord *record;
    u16 *desc;
    u8 *vtxEnd;
    u8 (*dst)[16];

    start = (VpCell *)((u8 *)arg1 + arg1->cellOffset);
    end = arg1->cellCount + start;
    modulesEnd = (VpModule *)(arg1->moduleCount * 8 + (u8 *)arg0 + 8);
    for (cell = start; cell < end; cell++) {
        if (cell->dirty == 0) {
            continue;
        }
        if (func_800E3DC0(cell->a, cell->b) == 0) {
            continue;
        }
        vertices = (u8 *)arg0 + arg0->vtxOffset;
        aligned8_memcpy(vertices, (u8 *)arg0 + arg0->dataOffset + cell->vtxStart * 16, cell->vtxCount * 16);
        module = arg0->modules;
        if (arg0->modules < modulesEnd) {
            index = cell - start;
            do {
if (!arg1) {}
                record = (VpRecord *)((u8 *)arg1->recordOffsets[module->index] + (s32)arg1);
                desc = record->desc[index];
                if (desc[1] != 0) {
                    p = &(*(u8 (*)[1])record->desc[arg1->cellCount])[desc[0]];
                    limit = desc[1] + p;
                    while (p < limit) {
                        ((s32 (*)(s32, s32, u8 *, u8))D_808008C0_vpmodule[module->type].unkC)(module->data, index, p[1] * 16 + vertices, p[0]);
                        p += 2;
                    }
                }
                module++;
            } while (module < modulesEnd);
        }
        dst = arg2->v;
        vtxEnd = cell->vtxCount * 16 + vertices;
        while (vertices < vtxEnd) {
            aligned8_memcpy((u8 *)dst + (*(u16 *)(vertices + 6) & 0x7FFF) * 16, vertices, 16);
            vertices += 16;
        }
        cell->dirty = 0;
    }
}

void func_808005C4_vpmodule(u8 *arg0, u8 *arg1, u8 *arg2) {
    typedef struct { s16 index; u8 count; u8 pad[17]; } Chunk;
    typedef struct { u8 data[16]; } Vertex;
    typedef struct { u16 offset; u16 length; } Range;
    u32 sp40;
    u32 temp_fp;
    u8 *temp_v1;
    u32 var_s2;
    u8 *temp_t0;
    u8 *temp_a0;
    u8 *temp_s0;
    u8 *temp_s1;
    u8 *temp_v1_2;
    u8 *var_s0;
    u8 *var_s3;
    u8 *var_s7;
    Range *range;
    u32 vertex;
    u8 *destination;

    temp_v1 = arg1;
    temp_v1 += *(u32 *)(arg1 + 0x1C);
    temp_t0 = *(s32 *)(arg1 + 0x14) * 20 + temp_v1;
    temp_fp = *(s32 *)(arg1 + 0x2C) * 8 + arg0 + 8;
    var_s7 = temp_v1;
    if ((u32)temp_v1 < (u32)temp_t0) {
        sp40 = arg0 + 8;
        do {
            var_s3 = arg0;
            var_s3 += *(u32 *)(arg0 + 4);
            var_s2 = sp40;
            aligned8_memcpy(var_s3, *(s16 *)var_s7 + (Vertex *)(*(s32 *)arg0 + *(u8 (*)[1])arg0), var_s7[2] * 16);
            if (sp40 < temp_fp) {
                do {
                    if (D_808008C0_vpmodule[*(u8 *)var_s2].unk10 != 0) {
                        temp_v1_2 = ((s32 *)(arg1 + 0x30))[*(s16 *)(var_s2 + 2)] + arg1;
                        temp_a0 = temp_v1_2;
                        temp_a0 += ((Chunk *)var_s7 - (Chunk *)temp_v1) * 4;
                        range = (Range *)(temp_a0 + 0x14);
                        if (((volatile Range *)range)->length != 0) {
                            var_s0 = (u8 *)((s32)(*(s32 *)(arg1 + 0x14) * 4 + *(u8 (*)[1])temp_v1_2) + range->offset + 0x14);
                            temp_s1 = range->length + var_s0;
                            if ((u32)var_s0 < (u32)temp_s1) {
                                do {
                                    vertex = var_s0[1];
                                    D_808008C0_vpmodule[*(u8 *)var_s2].unk10(vertex * 16 + var_s3, *var_s0++);
                                    var_s0++;
                                } while ((u32)var_s0 < (u32)temp_s1);
                            }
                        }
                    }
                    var_s2 += 8;
                } while (var_s2 < temp_fp);
            }
            aligned8_memcpy(*(s16 *)var_s7 + (Vertex *)(*(s32 *)arg0 + *(u8 (*)[1])arg0), var_s3, var_s7[2] * 16);
            temp_s0 = var_s7[2] * 16 + var_s3;
            if ((u32)var_s3 < (u32)temp_s0) {
                temp_s1 = arg2 + 0x18;
                do {
                    aligned8_memcpy((*(u16 *)(var_s3 + 6) & 0x7FFF) * 16 + temp_s1, var_s3, 16);
                    var_s3 += 16;
                } while ((u32)var_s3 < (u32)temp_s0);
            }
            var_s7 += 20;
        } while ((u32)var_s7 < (u32)temp_t0);
    }
}

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
