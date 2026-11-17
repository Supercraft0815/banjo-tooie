#include "su/quiz.h"

s32 func_80800000_suquiz(u32 arg0) {
    extern void *D_80127614;
    s32 suquiz_entrypoint_4(void);
    switch (arg0) {
    case 0:
    case 1:
        return suquiz_entrypoint_4() == 0 ? ((u8 *)D_80127614)[arg0 + 0x31] : 2;
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    default:
        return 0;
    }
}

f32 func_80800074_suquiz(s32 arg0, s32 arg1, s32 arg2) {
    extern f32 D_80801050_suquiz[][3][2];
    return D_80801050_suquiz[arg1][arg2][0];
}

f32 func_8080009C_suquiz(s32 arg0, s32 arg1, s32 arg2) {
    extern f32 D_80801054_suquiz[][3][2];
    return D_80801054_suquiz[arg1][arg2][0];
}

int func_808000C4_suquiz(s32 arg0) { s32 sp18[6]; void func_80015E80(s32, void *); func_80015E80(arg0, sp18); return sp18[1] == 1; }

void suquiz_entrypoint_0(void) {
    extern void *D_80127614;
    u8 _gcstatusDll_entrypoint_11(void);
    s32 func_800D3948(void);
    int func_800DC298(f32);
    void *heap_alloc(s32);
    void rare_memset(void *, u8, int);
    void suquiz_entrypoint_21(s32, s32);

    func_800DA544(FLAG2_6B6_UNK);
    if (D_80127614 == NULL) {
        D_80127614 = heap_alloc(0x38);
    }
    rare_memset(D_80127614, 0, 0x38);
    if (func_800D3948() != 0) {
        suquiz_entrypoint_21(3, 0);
        suquiz_entrypoint_21(4, 1);
        suquiz_entrypoint_21(5, _gcstatusDll_entrypoint_11() < 3 ? -1 : 2);
        suquiz_entrypoint_21(6, _gcstatusDll_entrypoint_11() < 4 ? -1 : 3);
    } else {
        suquiz_entrypoint_21(0, -1);
        suquiz_entrypoint_21(1, -1);
        suquiz_entrypoint_21(2, 0);
        if (func_800DC298(0.5f) != 0) {
            ((u8 *)D_80127614)[0x31] = 0;
        } else {
            ((u8 *)D_80127614)[0x31] = 1;
        }
        if (((u8 *)D_80127614)[0x31] == 0) {
            ((u8 *)D_80127614)[0x32] = 1;
        } else {
            ((u8 *)D_80127614)[0x32] = 0;
        }
    }
}

void suquiz_entrypoint_1(void) {
    extern void *D_80127614;
    u8 _gcstatusDll_entrypoint_17(void);
    void func_800C3F48(u32 arg0);
    s32 func_800D2498(u32 itemDisplayUI, s32 value, u32 a2);
    s32 func_800D3948(void);
    f32 func_800D9004(void);
    int func_800DB9B0(void);
    s32 func_800DC128(s32 arg0, s32 arg1);
    s32 suquiz_entrypoint_11(s32 arg0);
    int suquiz_entrypoint_10(s32 arg0);
    void suquiz_entrypoint_28(s32 arg0, s32 arg1, s32 arg2);
    f32 dt = func_800D9004();
    int i;
    int count;
    int first;
    int last;
    struct QuizChoices {
        int values[4];
    } choices;
    extern struct QuizChoices D_808010E0_suquiz;
    int running;

    choices = D_808010E0_suquiz;
    count = 0;

    if (D_80127614 != NULL) {
        running = ((u8 *)D_80127614)[0x24];
        if (func_800D3948() != 0) {
            running = running && (f32)(s32)_gcstatusDll_entrypoint_17() > 0;
        }
        if (running) {
            ((f32 *)D_80127614)[8] -= dt;
            if (((f32 *)D_80127614)[8] <= 0) {
                func_800C3F48(0x7FFFFE90);
                ((u8 *)D_80127614)[0x24] = 0;
            }
            func_800D2498(0x117, (s32)((f32 *)D_80127614)[8], 0);
        }
        ((f32 *)D_80127614)[7] += dt;
        if (((s8 *)D_80127614)[0x28] == -1) {
            if (func_800D3948() != 0) {
                first = 3;
                last = 6;
            } else {
                first = 0;
                last = 2;
            }
            for (i = first; i <= last; i++) {
                if (i == ((s8 *)D_80127614)[0x29]) {
                    continue;
                }
                if (suquiz_entrypoint_11(i) &&
                    func_808000C4_suquiz(suquiz_entrypoint_10(i))) {
                    choices.values[count] = i;
                    count++;
                }
            }
            if (count) {
                ((s8 *)D_80127614)[0x28] = choices.values[func_800DC128(0, count)];
            }
            if (((s8 *)D_80127614)[0x28] == -1 &&
                ((f32 *)D_80127614)[6] <= ((f32 *)D_80127614)[7]) {
                ((s8 *)D_80127614)[0x28] = ((s8 *)D_80127614)[0x26];
            }
            if (func_800DB9B0() != 0) {
                if (((s8 *)D_80127614)[0x28] != -1) {
                    suquiz_entrypoint_28(0, ((s8 *)D_80127614)[0x28], 0);
                }
            }
        }
    }
}

void suquiz_entrypoint_2(void) {
    extern void *D_80127614;
    void heap_free(void* mem);
    if (D_80127614 != NULL) {
        func_800DA524(FLAG2_6B6_UNK);
        heap_free(D_80127614);
        D_80127614 = NULL;
    }
}

s32 suquiz_entrypoint_3(void) {
    u32 temp_v0;

    if (func_800DA298(FLAG_441_UNK) != 0) {
        return 4;
    }
    if (func_800DA298(FLAG2_6E3_UNK) != 0) {
        func_800DA524(FLAG2_6E3_UNK);
        func_800DA524(FLAG2_6EB_UNK);
        return 5;
    }
    temp_v0 = func_800DA564(FLAG_442_UNK, 3);
    switch (temp_v0) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 6;
    }
    return 0;
}

s32 suquiz_entrypoint_4(void) {
    s32 temp_v0;

    temp_v0 = func_800DA564(FLAG_442_UNK, 3);
    switch (temp_v0) {
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    default:
        return 0;
    }
}    typedef struct { u8 pad0[0x28]; s8 unk28; } Objquiz_suquiz_entrypoint_5_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

s32 suquiz_entrypoint_5(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return ((((Objquiz_suquiz_entrypoint_5_D_80127614 *)D_80127614)->unk28) + 1) != 0;
    }
    return 0;
}    typedef struct { u8 pad0[0x28]; s8 unk28; } Objquiz_suquiz_entrypoint_6_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

s8 suquiz_entrypoint_6(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (((Objquiz_suquiz_entrypoint_6_D_80127614 *)D_80127614)->unk28);
    }
    return -1;
}    typedef struct { u8 pad0[0x25]; u8 unk25; } Objquiz_suquiz_entrypoint_7_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

u8 suquiz_entrypoint_7(void) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (((Objquiz_suquiz_entrypoint_7_D_80127614 *)D_80127614)->unk25);
    }
    return 6U;
}

f32 suquiz_entrypoint_8(s32 arg0) {
    s32 suquiz_entrypoint_4();
    extern f32 D_80800F94_suquiz[][6][2];
    s32 row = suquiz_entrypoint_4();
    return D_80800F94_suquiz[row][arg0][0];
}

s32 suquiz_entrypoint_9(s32 arg0) {
    if (arg0 != 0) {
        if (arg0 == 1) {
            return func_800DA298(FLAG_582_UNK);
        }
    } else {
        return func_800DA298(FLAG_583_UNK);
    }
    return 0;
}

int suquiz_entrypoint_10(s32 arg0) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return ((s8 *) ((u8 *) D_80127614 + arg0))[0x2A];
    }
    return 0;
}

/* extern */

s32 suquiz_entrypoint_11(s32 arg0) {
    int suquiz_entrypoint_10(s32);
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (suquiz_entrypoint_10(arg0) + 1) != 0;
    }
    return 0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) suquiz_entrypoint_12(void) {
    int func_800DC298(f32);
    s32 suquiz_entrypoint_4();
    extern f64 D_80800F74_suquiz[];
    BT_NATIVE_ONLY(return) func_800DC298(*(f32 *)&D_80800F74_suquiz[suquiz_entrypoint_4()]);
}

void suquiz_entrypoint_13(f32 *arg0) {
    extern void *D_80127614;
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg0, (f32 *) D_80127614);
}    typedef struct { u8 pad0[0xC]; f32 unkC; } Objquiz_suquiz_entrypoint_14_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

void suquiz_entrypoint_14(f32 *arg0) { extern void *D_80127614; void func_800EE7F8(f32 *, f32 *); func_800EE7F8(arg0, &((Objquiz_suquiz_entrypoint_14_D_80127614 *)D_80127614)->unkC); }    typedef struct { u8 pad0[0x27]; s8 unk27; } Objquiz_suquiz_entrypoint_15_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

s8 suquiz_entrypoint_15(s32 arg0) {
    extern void *D_80127614;
    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (((Objquiz_suquiz_entrypoint_15_D_80127614 *)D_80127614)->unk27);
    }
    return 0;
}    typedef struct { u8 pad0[0x20]; f32 unk20; } Objquiz_suquiz_entrypoint_16_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

int suquiz_entrypoint_16(void) {
    extern void *D_80127614;

    if (func_800DA298(FLAG2_6B6_UNK) != 0) {
        return (((Objquiz_suquiz_entrypoint_16_D_80127614 *)D_80127614)->unk20) <= 0.0f;
    } else {
        return 1;
    }
}

s32 suquiz_entrypoint_17()
{
    return func_800DA298(FLAG2_6E3_UNK);
}

/* extern */

void suquiz_entrypoint_18(u32 arg0) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    switch (arg0) {
    case 0:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 0, 3);
        return;
    case 1:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 1, 3);
        _gcfrontend_entrypoint_9(0x74);
        return;
    case 2:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 2, 3);
        _gcfrontend_entrypoint_9(0x75);
        return;
    case 3:
        func_800DA524(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 3, 3);
        _gcfrontend_entrypoint_9(0x76);
        return;
    case 4:
        func_800DA544(FLAG_441_UNK);
        func_800DA7A8(FLAG_442_UNK, 4, 3);
        _gcfrontend_entrypoint_9(0x84);
        /* fallthrough */
    default:
        return;
    }
}    typedef struct { u8 pad0[0x18]; f32 unk18; f32 unk1C; } Objquiz_suquiz_entrypoint_19_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

void suquiz_entrypoint_19(s32 arg0) {
    s32 func_800D3948(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    extern void *D_80127614;
    extern f32 D_80800F90_suquiz[][6][2];
    s32 pad[6];
    f32 chance;
    f32 duration;
    f32 random;
    s32 i;
    s32 kind;
    s32 last;
    s32 first;
    s32 index;

    switch (arg0) {
    case 3:
    case 5:
        break;
    case 0:
    case 2:
        ((s8 *)D_80127614)[0x26] = -1;
        ((s8 *)D_80127614)[0x28] = -1;
        ((s8 *)D_80127614)[0x29] = -1;
        break;
    case 1:
        ((s8 *)D_80127614)[0x26] = -1;
        break;
    case 4:
        ((s8 *)D_80127614)[0x29] = ((s8 *)D_80127614)[0x28];
        ((s8 *)D_80127614)[0x26] = -1;
        ((s8 *)D_80127614)[0x28] = -1;
        break;
    }
    if (arg0 != 0 && arg0 != 1 && arg0 != 2 && arg0 != 4) {
        goto done;
    } else {
        if (func_800D3948()) {
            first = 3;
            last = 6;
        } else {
            last = 2;
            first = 0;
        }
        i = first;
        if (first <= last) {
        do {
            if (i != ((s8 *)D_80127614)[0x29] && !suquiz_entrypoint_9(i) && !suquiz_entrypoint_11(i)) {
                kind = func_80800000_suquiz(i);
                chance = func_80800074_suquiz(i, arg0, kind);
                if (func_800DC0C0() <= chance) {
                    index = suquiz_entrypoint_4();
                    chance = func_800DC178(D_80800F90_suquiz[index][arg0][0], D_80800F90_suquiz[suquiz_entrypoint_4()][arg0][1] - 0.4f);
                    duration = func_8080009C_suquiz(i, arg0, kind);
                    random = func_800DC0C0();
                    ((s8 *)D_80127614)[0x26] = i;
                    ((Objquiz_suquiz_entrypoint_19_D_80127614 *)D_80127614)->unk18 = chance;
                    ((s8 *)D_80127614)[0x27] = random <= duration;
                    break;
                }
            }
            i++;
        } while (i != last + 1);
        }
    }
done:
    ((Objquiz_suquiz_entrypoint_19_D_80127614 *)D_80127614)->unk1C = 0.0f;
    ((u8 *)D_80127614)[0x25] = arg0;
}

void suquiz_entrypoint_20(s32 arg0) {
    if (arg0 != 0) {
        if (arg0 == 1) {
            func_800DA544(FLAG_582_UNK);
        }
    } else {
        func_800DA544(FLAG_583_UNK);
    }
}

void suquiz_entrypoint_21(s32 arg0, s32 arg1) { extern void *D_80127614; ((s8 *) ((u8 *) D_80127614 + arg0))[0x2A] = arg1; }

void suquiz_entrypoint_22(s32 arg0, s32 arg1) {
    extern void *D_80127614;
    void func_800EE7F8();
    func_800EE7F8(D_80127614, arg0);
    func_800EE7F8((u8 *) D_80127614 + 0xC, arg1);
}    typedef struct { u8 pad0[0x20]; f32 unk20; s8 unk24; } Objquiz_suquiz_entrypoint_23_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

void suquiz_entrypoint_23(void) {
    u8 _gcstatusDll_entrypoint_17(void);
    s32 func_800D3948();
    s32 suquiz_entrypoint_4();
    extern void *D_80127614;
    extern f32 D_80800F70_suquiz[][2];
    if (func_800D3948() != 0) {
        (((Objquiz_suquiz_entrypoint_23_D_80127614 *)D_80127614)->unk20) = (f32) ((f32) (s32) _gcstatusDll_entrypoint_17() * 60.0f);
    } else {
        (((Objquiz_suquiz_entrypoint_23_D_80127614 *)D_80127614)->unk20) = D_80800F70_suquiz[suquiz_entrypoint_4()][0];
    }
    (((Objquiz_suquiz_entrypoint_23_D_80127614 *)D_80127614)->unk24) = 1;
}    typedef struct { u8 pad0[0x34]; s16 unk34; } Objquiz_suquiz_entrypoint_24_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

void suquiz_entrypoint_24(u32 arg0, s32 arg1) {
    extern void *D_80127614;
    void _glcutDll_entrypoint_6(u32, u32);
    (((Objquiz_suquiz_entrypoint_24_D_80127614 *)D_80127614)->unk34) = arg1;
    func_800DA544(FLAG2_6E3_UNK);
    func_800DA524(FLAG2_6EB_UNK);
    _glcutDll_entrypoint_6(arg0, 0x8AU);
}

/* extern */

void suquiz_entrypoint_25(void) {
    void _glcutDll_entrypoint_17(void);
    if (func_800DA298(FLAG2_6EB_UNK) == 0) {
        _glcutDll_entrypoint_17();
        func_800DA544(FLAG2_6EB_UNK);
    }
}    typedef struct { u8 pad0[0x34]; s16 unk34; } Objquiz_suquiz_entrypoint_26_D_80127614; /* offsets.py genstruct: fields from raw offsets on D_80127614; rename once understood */

s16 suquiz_entrypoint_26(void) {
    extern void *D_80127614;
    return (((Objquiz_suquiz_entrypoint_26_D_80127614 *)D_80127614)->unk34);
}

void suquiz_entrypoint_27(void) {
    Actor *func_80108474(u32 arg0, f32 *arg1, s32 arg2);
    extern s32 D_808010F0_suquiz;
    func_80108474(0x217, &D_808010F0_suquiz, 0);
} 

void suquiz_entrypoint_28(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C3F48(u32);
    extern s32 D_808010FC_suquiz;
    void *temp_v0;

    temp_v0 = (arg1 * 0x30) + (arg0 * 0xC) + (s8 *)&D_808010FC_suquiz;
    func_800C3F48(((*(s32 *)temp_v0 & 0x7FF) + (((*(s32 *)((s8 *)temp_v0 + 8) >> 5) & 0x3FF) << 11)) + (((u32)(*(f32 *)((s8 *)temp_v0 + 4) * 1023.0f) & 0x7FF) << 21));
}
