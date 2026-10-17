#include "gc/goto.h"

typedef struct
{
    u8 unk0[0x42C];
    u8 unk42C;
} UNKD_80127194;

/* extern */
extern UNKD_80127194 D_80127194;

s32 func_80800000_gcgoto(s8 *arg0, s16 arg1) {
    s32 i = 0;

    while (arg0[i] != -1) {
        if (arg0[i++] == arg1) {
            return 1;
        }
    }
    return 0;
}

void gcgoto_entrypoint_0(s32 *arg0, s32 *arg1) {
    extern s8 D_80800710_gcgoto;
    extern s8 D_80800720_gcgoto;
    extern s8 D_8080072C_gcgoto;
    extern s8 D_8080073C_gcgoto;
    if (*arg0 == 0xFB) {
        if (func_80800000_gcgoto(&D_80800710_gcgoto, (*(s16 *)((s8 *)(arg1) + (2)))) != 0) {
            *arg0 = 0x1A7;
            return;
        }
        if (func_80800000_gcgoto(&D_80800720_gcgoto, (*(s16 *)((s8 *)(arg1) + (2)))) != 0) {
            *arg0 = 0x1A8;
            return;
        }
        if (func_80800000_gcgoto(&D_8080072C_gcgoto, (*(s16 *)((s8 *)(arg1) + (2)))) != 0) {
            *arg0 = 0x1A9;
            return;
        }
        if (func_80800000_gcgoto(&D_8080073C_gcgoto, (*(s16 *)((s8 *)(arg1) + (2)))) != 0) {
            *arg0 = 0x1A6;
        }
    }
}

void func_8080011C_gcgoto(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (D_80127194.unk42C == 0)
    {
        if ((arg0 == 0xCE) && (arg1 == 4))
        {
            func_800DA544(FLAG_503_UNK);
        }
        gcgoto_entrypoint_0(&arg0, &arg1);
        func_800A7990(arg0, arg1, arg3);
        func_800EA334(arg2);
        gcgoto_entrypoint_14(1);
    }
}

void gcgoto_entrypoint_1(u32 a0, u32 a1)
{
    func_8080011C_gcgoto(a0, a1, 0, 1);
}

void gcgoto_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) {
    func_8080011C_gcgoto(arg0, arg1, 0, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/func_808001E0_gcgoto.s")

/* extern */

void func_808003D0_gcgoto(s16 *arg0, s32 arg1) {
    void func_800EE88C(f32 *, s16 *);
    void func_808001E0_gcgoto(f32 *, s32, s32, s32);
    f32 vec[3];
    f32 unused[3];

    if (D_80127194.unk42C == 0) {
        if (arg0 != 0) {
            func_800EE88C(vec, arg0);
            func_808001E0_gcgoto(vec, arg1 >> 8, arg1 & 0xFF, 0);
            return;
        }
        func_808001E0_gcgoto(NULL, arg1 >> 8, arg1 & 0xFF, 1);
    }
}

void gcgoto_entrypoint_3(s16 *arg0, s32 arg1, s32 arg2) {
    func_808003D0_gcgoto(arg0, (arg1 << 8) + arg2);
}

void gcgoto_entrypoint_4(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    void func_8008FE68(f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    void _plcamera_entrypoint_11(u32, f32 *);
    void func_800A1618(s32);
    void func_80090358(f32 *, f32, void *, s32);
    f32 pos[3];
    f32 dest[3];
    f32 offset[3];

    func_8008FE68(pos);
    func_800EEB9C(offset, arg3, func_800F10B4((f32)arg4, 0.0f, 200.0f, 10.0f, 800.0f));
    offset[0] += pos[0];
    offset[1] += pos[1];
    offset[2] += pos[2];
    dest[0] = offset[0];
    dest[1] = arg2;
    dest[2] = offset[2];
    _plcamera_entrypoint_11(func_800F54E4(), dest);
    func_8080011C_gcgoto(arg0, arg1, 1, 1);
    func_800A1618(1);
    func_80090358(dest, 1.0f, NULL, 0);
}

void gcgoto_entrypoint_5(s32 arg0, s32 arg1, f32 arg2) {
    void func_8008FE68(f32 *);
    void gcgoto_entrypoint_4(s32, s32, f32, f32, s32);
    f32 vec[3];
    func_8008FE68(vec);
    gcgoto_entrypoint_4(arg0, arg1, vec[1], arg2, 0x25);
}

void gcgoto_entrypoint_6(s32 arg0, s32 arg1) {
    func_8080011C_gcgoto(arg0, arg1, 0, 1);
}

void gcgoto_entrypoint_7(s32 arg0, s32 arg1) {
}
/* extern */

void gcgoto_entrypoint_8(s32 arg0, s32 arg1) {
    s32 func_80015FA0(s32);
    s32 func_800A7AD4(s32, s32);
    s32 func_800FC1CC(s32, s32);
    s32 func_800FE3EC();
    if (func_80015FA0(0) == 1) {
        func_800A7AD4(1, 2);
        func_800FC1CC(0, 0x320);
        func_800FE3EC();
        gcgoto_entrypoint_7(arg0, arg1);
    }
}

/* extern */

void gcgoto_entrypoint_9(s32 arg0, s32 arg1) {
    s32 func_8008FD48();
    if (func_8008FD48() == 8) {
        func_808003D0_gcgoto(arg0, 0xBC02);
    }
}

/* extern */

void gcgoto_entrypoint_10(s32 arg0, s32 arg1) {
    s32 func_8008FD48();
    if (func_8008FD48() == 8) {
        func_808003D0_gcgoto(arg0, 0xC403);
    }
}

void gcgoto_entrypoint_11(s32 arg0, u32 arg1)
{
    s32 sp1C;
    s32 sp18;

    _sutempleboss_entrypoint_0(arg0, &sp1C, &sp18);
    if (sp1C != 0)
    {
        func_808003D0_gcgoto(arg0, (sp1C << 8) + sp18);
    }
}

void gcgoto_entrypoint_12(void) {
}

void gcgoto_entrypoint_13(void) {
    u32 address = (u32)&D_80127194.unk42C;
    u8 *state = (u8 *)address;
    state[0] = 0;
    *(s32 *)(state + 4) = 0;
}

void gcgoto_entrypoint_14(s32 arg0) {
    *(s8 *)((u8 *)&D_80127194 + 1068) = arg0;
}

u32 gcgoto_entrypoint_15(void) {
    return *(u8 *)((u8 *)&D_80127194 + 1068);
}
