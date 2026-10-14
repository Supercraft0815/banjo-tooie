#include "common.h"

/* extern */

void func_800E1120(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, 0.0f, arg2, 0.0f);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E119C.s")

/* extern */

void func_800E1218(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, arg2, 0.0f, 0.0f);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

void func_800E1294(s32 arg0, f32 position[3], f32 rotation[3], f32 delta) {
    void func_800E1218(f32 *, f32 *, f32);
    void func_800E1120(f32 *, f32 *, f32);
    void func_800E119C(f32 *, f32 *, f32);
    switch (arg0) {
    case 1:
        func_800E1218(position, rotation, delta);
        return;
    case 0:
        func_800E1120(position, rotation, delta);
        return;
    case 2:
        func_800E119C(position, rotation, delta);
        return;
    case 3:
        position[1] += delta;
        return;
    }
}

f32 func_800E1338(s32 arg0) {
    extern f32 D_8012CFB8[];
    return *(f32 *)((s32)&D_8012CFB8 + ((arg0 * 31) * 4));
}

s32 func_800E1354(s32 arg0) {
    extern u8 D_8012D004[];
    return D_8012D004[(arg0 * 31) * 4] != 1;
}

/* extern */

void func_800E1378(s32 arg0) {
    void func_800E13F0(s32, f32);
    void func_800E144C(s32, f32);
    void func_800E146C(s32, f32);
    void func_800E148C(s32, f32, f32);
    s32 func_800EA068(s32);
    func_800E13F0(arg0, 30.0f);
    func_800E144C(arg0, 0.65f);
    func_800E148C(arg0, 1000.0f, 2000.0f);
    if (func_800EA068(0x20) != 0) {
        func_800E146C(arg0, 0.0f);
        return;
    }
    func_800E146C(arg0, 0.5f);
}

void func_800E13F0(s32 arg0, f32 arg1) {
    extern f32 D_8012CFB8[];
    *(f32 *)((s32)&D_8012CFB8 + ((arg0 * 31) * 4)) = arg1;
}

typedef struct {
    f32 position[3];
    s8 padC[0x68];
    s8 active;
    s8 unk75;
    s8 updated;
    s8 pad77[5];
} Entry;
extern Entry D_8012CF90[];

void func_800E1410(s32 arg0, f32 arg1, f32 arg2) {
    typedef struct { u8 pad0[0x18]; f32 unk18; f32 unk1C; f32 unk20; f32 unk24; f32 unk28; f32 unk2C; f32 unk30; u8 pad34[0x48]; } EntryFields;
    EntryFields *entries = (EntryFields *)D_8012CF90;

    entries[arg0].unk24 = entries[arg0].unk28;
    entries[arg0].unk20 = entries[arg0].unk28 + arg1;
    entries[arg0].unk30 = arg2;
    entries[arg0].unk18 = arg2;
}

void func_800E144C(s32 arg0, f32 arg1) {
    extern f32 D_8012CFAC[];
    *(f32 *)((s32)&D_8012CFAC + ((arg0 * 31) * 4)) = arg1;
}

void func_800E146C(s32 arg0, f32 arg1) {
    extern f32 D_8012CFA4[];
    *(f32 *)((s32)&D_8012CFA4 + ((arg0 * 31) * 4)) = arg1;
}

void func_800E148C(s32 arg0, f32 arg1, f32 arg2) {
    extern f32 D_8012CFA4[];
    f32 *entry;

    entry = (f32 *)((s32)((u8 *)D_8012CFA4 - 0x14) + ((arg0 * 31) * 4));
    entry[3] = arg1;
    entry[4] = arg2;
}

void func_800E14B8(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);

    func_800EE7F8(D_8012CF90[arg0].position, arg1);
    D_8012CF90[arg0].updated = 1;
}

void func_800E14F8(s32 arg0, u8 *arg1, s16 arg2) {
    void rare_memcpy(void *, void *, int);
    s32 entry = (s32)D_8012CF90 + (arg0 * 31) * 4;
    s16 *countPtr = &arg2;
    s16 count = *countPtr;
    *(u8 *)(entry + 0x78) = count;
    rare_memcpy((u8 *)(entry + 0x34), arg1, count * 8);
}

s32 func_800E1540(s32 arg0) {
    s32 func_800DC128(s32, s32);
    s32 index;
    Entry *entry;

    for (index = 0; index < 10; index++) {
        if ((u8)D_8012CF90[index].active == 1) {
            break;
        }
    }
    if (index == 10) {
        index = func_800DC128(0, 10);
    }
    entry = &D_8012CF90[index];
    entry->unk75 = arg0;
    entry->active = 2;
    entry->pad77[0] = 0;
    return index;
}

s32 func_800E15CC(s32 arg0, f32 arg1, f32 arg2) {
    s32 func_800E1540(s32);
    s32 entry = func_800E1540(arg0);
    func_800E13F0(entry, arg1);
    func_800E144C(entry, arg2);
    return entry;
}

s32 func_800E1610(s32 arg0, f32 arg1, f32 arg2, f32 *arg3) { s32 func_800E1540(s32); s32 entry = func_800E1540(arg0); func_800E13F0(entry, arg1); func_800E144C(entry, arg2); func_800E14B8(entry, arg3); return entry; }

s32 func_800E1664(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, u8 *arg4, s16 arg5) {
    s32 sp1C;
    s32 temp_v0;
    Entry *temp_v0_2;

    temp_v0 = func_800E1540(arg0);
    sp1C = temp_v0;
    func_800E14F8(temp_v0, arg4, arg5);
    temp_v0_2 = &D_8012CF90[sp1C];
    temp_v0_2->active = 4;
    (*(f32 *)((s8 *)(temp_v0_2) + (0x20))) = arg1;
    (*(f32 *)((s8 *)(temp_v0_2) + (0x30))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0_2) + (0x18))) = arg2;
    if (arg1 >= 0.0f) {
        (*(f32 *)((s8 *)(temp_v0_2) + (0x2C))) = 1.0f;
    } else {
        (*(f32 *)((s8 *)(temp_v0_2) + (0x2C))) = -1.0f;
    }
    if (arg3 != 0) {
        func_800E14B8(sp1C, arg3);
    }
    return sp1C;
}

s32 func_800E1720(s32 arg0) {
    Entry *entry;

    entry = &D_8012CF90[arg0];
    entry->active = 1;
    entry->updated = 0;
    return (s32)entry;
}

/* extern */

void func_800E1748(void) {
    s32 func_800E1720(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800E1720(var_s0);
        var_s0 += 1;
    } while (var_s0 != 0xA);
}

/* extern */

void func_800E1788(void) {
    void func_800E1378(s32);
    s32 func_800EFD24(Entry *);
    Entry *var_s0;
    s32 var_s1;

    var_s0 = D_8012CF90;
    var_s1 = 0;
    do {
        var_s0->active = 1;
        (*(f32 *)((s8 *)(var_s0) + (0x30))) = 0.0f;
        var_s0->updated = 0;
        func_800EFD24(var_s0);
        func_800E1378(var_s1);
        var_s1 += 1;
        var_s0++;
    } while (var_s1 != 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBAA10/func_800E1A58.s")
