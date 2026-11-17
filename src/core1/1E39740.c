#include "common.h"

f32 func_80021C10(s32 arg0) {
    extern f32 D_80041990;
    f32 sp4;
    f32 sp0;

    arg0 &= 0xFF;
    sp4 = D_80041990;
    sp0 = 1.0f;
    if (arg0 != 0) {
        do {
            if (arg0 & 1) {
                sp0 *= sp4;
            }
            sp4 *= sp4;
            arg0 = ((u32)arg0 >> 1) & 0xFF;
        } while (arg0 != 0);
    }
    return sp0;
}

s32 func_80021C8C(ALLink **arg0, f32 *arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    extern ALLink *D_8007EA40;
    ALLink *sp2C;
    s32 sp28;

    sp28 = 0;
    if (arg5 == 0) {
        return 0;
    }
    if (D_8007EA40 != NULL) {
        sp2C = D_8007EA40;
        D_8007EA40 = D_8007EA40->next;
        (*(u8 *)((s8 *)(sp2C) + (4))) = arg2;
        *arg0 = sp2C;
        sp28 = arg5 << 0xE;
        switch (arg2) {
        case 0x1:
            (*(s16 *)((s8 *)(sp2C) + (0x24))) = 0;
            (*(s16 *)((s8 *)(sp2C) + (0x22))) = (s16) (0x103 - arg3);
            (*(u8 *)((s8 *)(sp2C) + (0x28))) = (s32) arg4 >> 1;
            (*(u8 *)((s8 *)(sp2C) + (0x29))) = (u8) (0x7F - (*(u8 *)((s8 *)(sp2C) + (0x28))));
            *arg1 = (f32) (*(u8 *)((s8 *)(sp2C) + (0x29)));
            break;
        case 0x80:
            (*(f32 *)((s8 *)(sp2C) + (0x28))) = func_80021C10((s32) arg4);
            (*(s16 *)((s8 *)(sp2C) + (0x24))) = 0;
            (*(s16 *)((s8 *)(sp2C) + (0x22))) = (s16) (0x103 - arg3);
            *arg1 = 1.0f;
            break;
        default:
            break;
        }
    }
    return sp28;
}    typedef struct { u8 pad0[0x4]; u8 unk4; u8 pad5[0x1D]; u16 unk22; u16 unk24; u8 pad26[0x2]; u8 unk28; u8 unk29; } Obj1E39740_func_80021E1C_sp28; /* offsets.py genstruct: fields from raw offsets on sp28; rename once understood */

s32 func_80021E1C(void *arg0, f32 *arg1) {
    f32 func_8001395C(f32);
    f32 func_80027170(s32);
    extern f32 D_80041994;
    extern f32 D_80041998;
    f32 sp2C;
    void *sp28;
    s32 sp24;

    sp28 = arg0;
    sp24 = 0x3E80;
    switch (((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk4) {
        case 1:
            (((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24)++;
            if (((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 >= ((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk22) {
                ((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 = 0;
            }
            sp2C = (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 / (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk22;
            sp2C = func_8001395C(sp2C * D_80041994);
            sp2C = (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk28 * sp2C;
            *arg1 = (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk29 + sp2C;
            break;
        case 0x80:
            (((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24)++;
            if (((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 >= ((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk22) {
                ((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 = 0;
            }
            sp2C = (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk24 / (f32)*&((Obj1E39740_func_80021E1C_sp28 *)sp28)->unk22;
            sp2C = *(f32 *)((s8 *)sp28 + 0x28) * func_8001395C(sp2C * D_80041998);
            *arg1 = func_80027170((s32)sp2C);
            break;
        default:
            break;
    }
    return sp24;
}

void func_80022060(ALLink *arg0) {
    extern ALLink *D_8007EA40;

    arg0->next = D_8007EA40;
    D_8007EA40 = arg0;
}

void func_80022084(void *arg0, s32 arg1) {
    BtIntPtr func_80020EE4(s32, s32, void *, s32, s32);
    extern ALLink *D_8007EA40;
    extern ALLink *D_8007EA44;
    s32 func_80021C8C(ALLink **, f32 *, u8, u8, u8, u8);
    extern s32 func_80021E1C(void *, f32 *);
    ALLink *sp24;
    s32 sp20;

    D_8007EA44 = (ALLink *)func_80020EE4(0, 0, *(void **)((s8 *)arg0 + 0xC), arg1, 0x2C);
    D_8007EA40 = D_8007EA44;
    D_8007EA40 = D_8007EA44;
    sp24 = D_8007EA44;
    for (sp20 = 0; sp20 < arg1 - 1; sp20++) {
        sp24->next = (ALLink *)(sp20 * 0x2C + (s8 *)D_8007EA44 + 0x2C);
        sp24 = sp24->next;
    }
    sp24->next = NULL;
    (*(s32 **)((s8 *)(arg0) + (0x10))) = &func_80021C8C;
    (*(s32 **)((s8 *)(arg0) + (0x14))) = &func_80021E1C;
    (*(void (**)(ALLink *))((s8 *)arg0 + 0x18)) = func_80022060;
}
