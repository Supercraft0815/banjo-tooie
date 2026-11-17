#include "common.h"

s32 func_800A21C0() 
{
    return 0x14;
}    typedef struct { u8 pad0[0xB4]; u8 * unkB4; } Obj1E7BAB0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_800A21C8(void *arg0) {
    struct MapEntry { s16 map; u8 first; u8 second; };
    extern struct MapEntry D_80119270[];
    s32 func_800C8C18(void);
    s32 func_800EA05C();
    s32 map;
    s32 i;
    struct MapEntry *entry;
    s8 first;
    void *data;

    map = func_800EA05C();
    for (i = 0; D_80119270[i].map != -1; i++) {
        if (map == D_80119270[i].map) {
            break;
        }
    }
    entry = &D_80119270[i];
    (((Obj1E7BAB0_arg0 *)arg0)->unkB4)[0] = entry->first;
    (((Obj1E7BAB0_arg0 *)arg0)->unkB4)[1] = entry->second;
    if (entry->map == -1 && func_800C8C18() > 0) {
        (*(s8 **)((u8 *)arg0 + 0xB4))[0] = 2;
        (*(s8 **)((u8 *)arg0 + 0xB4))[1] = 0;
    }
    data = *(void **)((u8 *)arg0 + 0xB4);
    first = *(s8 *)data;
    if (first >= 3) {
        *(u8 *)data = 2;
        first = (*(s8 **)((u8 *)arg0 + 0xB4))[0];
    }
    func_800A25DC((BtIntPtr)arg0, first);
}

void func_800A22A8(BtIntPtr arg0)
{
    func_800A25DC(arg0,0);
}

void func_800A22C8(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = (arg0[i] * arg1[i]) / 256;
    }
}

/* extern */
BT_NATIVE_ONLY(void func_800C87B8(s32 *);)
void func_800A2314(void *arg0, s32 *arg1) {
    s32 sp1C[3];
    func_800C87B8(sp1C);
    func_800A22C8(sp1C, arg1);
    func_800B38A8(*(s32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 0xB4)) + 4), sp1C);
}

struct player_state_s;
void func_800A235C(void *arg0) {
    f32 func_80092B8C(struct player_state_s *, f32 *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_800A1F0C(void *, s32 *);
    s32 func_800B3494(BtIntPtr, f32 *, f32);
    int func_800B36C0(BtIntPtr, f32 *, s32 *, f32);
    void func_800B37A4(u8 *, s32 *, s32 *);
    void func_800C8960(s32 *, f32 *);
    void func_800EE830(s32 *, s32 *);
    void func_800EF04C(f32 *, f32 *);
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp7C;
    s32 sp78;
    s32 sp6C[3];
    BtIntPtr sp68;
    s32 sp64;
    f32 sp58[3];
    s32 sp4C[3];
    BtIntPtr offset;
    s32 sp3C[3];
    s32 *p;
    s32 *end;

    func_800A1F0C(arg0, sp6C);
    func_800A2314(arg0, sp6C);
    sp7C = func_80092B8C(arg0, sp80);
    func_8009C128(arg0, sp8C);
    func_800EF04C(sp80, sp8C);
    sp78 = func_800B3494(*(s32 *)(((Obj1E7BAB0_arg0 *)arg0)->unkB4 + 4), sp80, sp7C);
    func_800B37A4(*(u8 **)(((Obj1E7BAB0_arg0 *)arg0)->unkB4 + 4), &sp68, &sp64);
    if (sp78 < **(s8 **)((u8 *)arg0 + 0xB4) && (((Obj1E7BAB0_arg0 *)arg0)->unkB4)[1]) {
        func_800C8960(sp4C, sp58);
        func_800A22C8(sp4C, sp6C);
        sp78 += func_800B36C0(*(s32 *)(((Obj1E7BAB0_arg0 *)arg0)->unkB4 + 4), sp58, sp4C, sp78 ? *(f32 *)(sp68 + 0x18) : 500.0f);
    }
    if (sp78) {
        func_800EE830(sp3C, (s32 *)(sp68 + 0xC));
        func_800EE830((s32 *)(sp68 + 0xC), (s32 *)(((Obj1E7BAB0_arg0 *)arg0)->unkB4 + 8));
        offset = 0;
        p = sp3C;
        end = sp3C + 3;
        do {
            if (((s32 *)(sp68 + offset))[3] < *p) {
                ((s32 *)(sp68 + offset))[3] += 40;
                if (*p < ((s32 *)(sp68 + offset))[3]) {
                    ((s32 *)(sp68 + offset))[3] = *p;
                }
            } else if (*p < ((s32 *)(sp68 + offset))[3]) {
                ((s32 *)(sp68 + offset))[3] -= 40;
                if (((s32 *)(sp68 + offset))[3] < *p) {
                    ((s32 *)(sp68 + offset))[3] = *p;
                }
            }
            p++;
            offset += 4;
        } while (p != end);
        func_800EE830((s32 *)(((Obj1E7BAB0_arg0 *)arg0)->unkB4 + 8), (s32 *)(sp68 + 0xC));
    }
}

void func_800A2534(s32 *arg0)
{
    *(u8 *)(arg0[0xB4 / 4] + 3) = 0;
}    typedef struct { u8 pad0[0x3]; u8 unk3; s32 unk4; } Obj1E7BAB0_func_800A2540_temp; /* offsets.py genstruct: fields from raw offsets on temp; rename once understood */

void func_800A2540(void *arg0, s32 arg1) {
    u32 func_800A25D0(void *);
    void func_800A1F0C(void *, s32 *);
    void func_800A235C(void *);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF660(s32 type,uintptr_t a,uintptr_t b,s32 alpha);
    s32 color[3];
    void *temp;

    if (func_800A25D0(arg0) == 0) {
        func_800A1F0C(arg0, color);
        func_800DF5D8(color[0], color[1], color[2], arg1);
        return;
    }
    temp = *(void **)((u8 *)arg0 + 0xB4);
    if (((Obj1E7BAB0_func_800A2540_temp *)temp)->unk3 == 0) {
        func_800A235C(arg0);
        *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xB4) + 3) = 1;
        temp = *(void **)((u8 *)arg0 + 0xB4);
    }
    func_800DF660(1, 0, ((Obj1E7BAB0_func_800A2540_temp *)temp)->unk4, arg1);
}

u32 func_800A25D0(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 180) + 2);
}    typedef struct { u8 pad0[0x2]; u8 unk2; u8 pad3[0x1]; s32 unk4; } Obj1E7BAB0_func_800A25DC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

int func_800A25DC(BtIntPtr arg0, s32 arg1) {
    void * func_800B3310(s32 capacity);
    void func_800B3370(void *list);
    BtIntPtr temp_a0;
    void *temp_v0;

    if (arg1 != 0) {
        *(s8 *)((u8 *)*(void **)(arg0 + 0xB4) + 2) = 1;
    } else {
        *(u8 *)((u8 *)*(void **)(arg0 + 0xB4) + 2) = 0;
    }
    temp_v0 = *(void **)(arg0 + 0xB4);
    if (((Obj1E7BAB0_func_800A25DC_temp_v0 *)temp_v0)->unk2 != 0) {
        if (((Obj1E7BAB0_func_800A25DC_temp_v0 *)temp_v0)->unk4 == 0) {
            *(s32 *)((u8 *)*(void **)(arg0 + 0xB4) + 4) = func_800B3310(*(s8 *)temp_v0);
        }
    } else {
        temp_a0 = ((Obj1E7BAB0_func_800A25DC_temp_v0 *)temp_v0)->unk4;
        if (temp_a0 != 0) {
            func_800B3370(temp_a0);
            *(s32 *)((u8 *)*(void **)(arg0 + 0xB4) + 4) = 0;
        }
    }
    BT_NATIVE_ONLY(return 0;)}

void func_800A266C(u8 *arg0) {
    void * func_800B38E8(void *list);
    BtIntPtr temp_a1;

    temp_a1 = (*(s32 *)((s8 *)((((Obj1E7BAB0_arg0 *)arg0)->unkB4)) + (4)));
    if (temp_a1 != 0) {
        (*(s32 *)((s8 *)((((Obj1E7BAB0_arg0 *)arg0)->unkB4)) + (4))) = func_800B38E8(temp_a1);
    }
}
