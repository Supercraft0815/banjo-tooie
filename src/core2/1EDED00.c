#include "common.h"

typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;
typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

extern s32 D_80136ED8;

void func_80105410(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136EC0;
    D_80136EC0 = freelist_new(0x48, 8);
}

void func_80105438(void) {
    void freelist_free(FreeList *);
    extern FreeList *D_80136EC0;
    freelist_free(D_80136EC0);
}

void func_8010545C(void) {
    FreeList *freelist_defrag(FreeList *);
    extern FreeList *D_80136EC0;
    if (D_80136EC0 != 0) {
        D_80136EC0 = freelist_defrag(D_80136EC0);
    }
}

void *func_80105494(Actor *arg0) {
    extern FreeList *D_80136EC0;
    void *freelist_at(FreeList *, s32);
    if (arg0->unk7C_0 == 0) {
        return NULL;
    }
    return freelist_at(D_80136EC0, arg0->unk7C_0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801054D4.s")

void *func_8010556C(Actor *arg0) {
    typedef struct {
        s16 unk0;
        s16 pad2_11 : 5;
        s16 unk2_1 : 10;
        s16 pad2_0 : 1;
        u8 pad4[0x10];
        f32 unk14;
        u8 unk18_7 : 1;
        u8 unk18_6 : 1;
        u8 unk18_0 : 6;
        u8 pad19[0xE];
        u8 pad27_6 : 2;
        u8 unk27_5 : 1;
        u8 pad27_0 : 5;
        u8 unk28_5 : 3;
        u8 pad28_0 : 5;
    } Entry;
    void *freelist_next(FreeList **, s32 *);
    void rare_memset(void *, u8, int);
    u32 func_800E6A00(void);
    extern FreeList *D_80136EC0;
    s32 sp1C;
    Entry *sp18;

    sp1C = 0;
    sp18 = freelist_next(&D_80136EC0, &sp1C);
    arg0->unk7C_0 = sp1C;
    rare_memset(sp18, 0, 0x48);
    sp18->unk2_1 = -1;
    sp18->unk28_5 = 7;
    sp18->unk18_7 = 0;
    sp18->unk14 = 100.0f;
    sp18->unk18_6 = func_800E6A00();
    sp18->unk27_5 = 0;
    return sp18;
}

void func_80105634(Actor *arg0) {
    void freelist_erase(FreeList *, s32);
    extern FreeList *D_80136EC0;
    if (arg0->unk7C_0 != 0) {
        freelist_erase(D_80136EC0, arg0->unk7C_0);
        (*(u16 *)((s8 *)(arg0) + (0x7E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7E))) & 0xF000);
        (*(u8 *)((s8 *)(arg0) + (0x77))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x77))) & 0xFFEF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010568C.s")

/* extern */

void func_801056EC(Actor *arg0, f32 arg1) {
    s32 func_800D86F0(s32, f32, void *);
    void *temp_v0;

    temp_v0 = func_80105494(arg0);
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    func_800D86F0((s32) ((*(s32 *)((s8 *)(temp_v0) + (0))) << 0x15) >> 0x16, arg1, (s8 *)arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010573C.s")

void func_80105834()
{
    func_801054D4();
}

void func_80105854(Actor *arg0) { s32 func_80105A5C(Actor *); func_801054D4(); if (func_80105A5C(arg0) != 0) { func_800FFAB0(arg0); } }

void func_8010588C(Actor *arg0) { void func_8010A570(Actor *); struct { u32 words[10]; u32 upper : 21; u32 flag : 1; u32 lower : 10; } *flags; func_8010A570(arg0); flags = (void *)arg0->unk0; flags->flag = 1; func_801054D4(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801058C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105998.s")

/* extern */

s32 func_80105A5C(Actor *arg0) {
    void *func_80105494(Actor *);

    return (*(f32 *)((s8 *)func_80105494(arg0) + 0xC)) == 1.0f;
}

void func_80105A9C(Actor *arg0, f32 arg1) {
    void *func_80105494(Actor *);
    (*(f32 *)((s8 *)(func_80105494(arg0)) + 0x14)) = arg1;
}

/* extern */

f32 func_80105AC4(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0x14)));
}

/* extern */

f32 func_80105AE8(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105B0C.s")

void func_80105BAC(Actor *arg0) {
    void *func_80105494(Actor *);
    struct {
        u8 pad[0x18];
        u8 flag : 1;
        u8 rest : 7;
    } *temp_v0;

    temp_v0 = func_80105494(arg0);
    if (temp_v0 != NULL) {
        temp_v0->flag = 1;
    }
}

/* extern */

void func_80105BE0(Actor *arg0, s32 arg1) {
    void *func_80105494(Actor *);
    struct {
        u8 pad[0x27];
        u8 high : 2;
        u8 flag : 1;
        u8 low : 5;
    } *temp_v0;
    temp_v0 = func_80105494(arg0);
    if (temp_v0 != NULL) {
        temp_v0->flag = arg1;
    }
}

void func_80105C20(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136ED0;
    D_80136ED0 = freelist_new(0x8, 0);
}

void func_80105C48(void) {
    s16 freelist_capacity(FreeList *);
    void freelist_free(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    void func_801060E4(s16);
    extern FreeList *D_80136ED0;
    s32 var_s0;
    s32 temp_v0;

    temp_v0 = freelist_capacity(D_80136ED0);
    var_s0 = 1;
    if (temp_v0 >= 2) {
        do {
            if (freelist_is_element_alive(D_80136ED0, var_s0) != 0) {
                func_801060E4(var_s0);
            }
            var_s0 += 1;
        } while (var_s0 < temp_v0);
    }
    freelist_free(D_80136ED0);
    D_80136ED0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105DFC.s")

void func_801060E4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    void freelist_erase(FreeList *, s32);
    s32 vector_free(s32);
    s32 _glidmake_entrypoint_4(s32);
    extern FreeList *D_80136ED0;
    s32 *entry;

    entry = freelist_at(D_80136ED0, arg0);
    vector_free(entry[1]);
    _glidmake_entrypoint_4(entry[0]);
    freelist_erase(D_80136ED0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801061D8.s")

s32 func_80106314()
{
    return D_80136ED8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106320.s")

void *func_801063C0(void *arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80136ED0;
    return freelist_at(D_80136ED0, (*(s16 *)((s8 *)(arg0) + (0x90))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801063EC.s")

/* extern */

void func_8010647C(void *arg0) {
    s32 func_801063EC(s16);
    func_801063EC((*(s16 *)((s8 *)(arg0) + (0x90))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010649C.s")

void *func_80106520(s32 arg0) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80136ED4;
    s32 pad;
    u32 sp18;
    u32 temp_v0;
    u32 var_v1;

    sp18 = vector_end(D_80136ED4);
    temp_v0 = vector_begin(D_80136ED4);
    var_v1 = temp_v0;
    if (temp_v0 < sp18) {
loop_2:
        if (((*(s16 *)((s8 *)(var_v1) + (4))) == 7) && (arg0 == (*(s16 *)((s8 *)(var_v1) + (6))))) {
            return var_v1 + 8;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp18) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

s32 func_801065A4(void *arg0) {
    s32 result = 0;
    if (*(s16 *)((s8 *)arg0 + 0x90) != 0) {
        return *(s32 *)func_801063C0(arg0);
    }
    return result;
}
