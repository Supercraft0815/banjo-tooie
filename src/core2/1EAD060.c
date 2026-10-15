#include "common.h"

int func_800D3770(void) {
    extern u8 D_8012762C;
    extern s8 D_8012B3F1;
    s32 level;
    int flag;

    level = D_8012762C;
    flag = level >= 0xF && level < 0x1C;
    if (level == 0x11) {
        flag = 0;
    }
    return (D_8012B3F1 + 1) && flag;
}

void func_800D37C0(s32 arg0) {
    extern s32 D_8012B3F0;
    (*(s8 *)((s8 *)(&D_8012B3F0) + (0))) = arg0;
    (*(s8 *)((s8 *)(&D_8012B3F0) + (1))) = arg0;
}

void func_800D37D4(void) {
    extern s32 D_8012B3F0;
    (*(s8 *)((s8 *)(&D_8012B3F0) + (1))) = -1;
    (*(s8 *)((s8 *)(&D_8012B3F0) + (0))) = (s8) (*(s8 *)((s8 *)(&D_8012B3F0) + (1)));
}

s32 func_800D37F0(void) {
    extern s8 D_8012B3F1;
    return *(s8 *)((u8 *)&D_8012B3F1 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAD060/func_800D37FC.s")

void func_800D389C(void) {
    s32 _glgamedata_entrypoint_1(void *);
    s32 _glsavegame_entrypoint_7(s8);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    extern s32 D_8012B3F0;

    if (func_800D3770() != 0) {
        _glsavegame_entrypoint_7((*(s8 *)((s8 *)(&D_8012B3F0) + (1))));
    }
    if ((*(u8 *)((s8 *)(&D_8012B3F0) + (9))) == 1) {
        (*(s16 *)((s8 *)(&D_8012B3F0) + (6))) = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798((*(s16 *)((s8 *)(&D_8012B3F0) + (6)))));
        (*(s8 *)((s8 *)(&D_8012B3F0) + (8))) = (*(s8 *)((s8 *)(&D_8012B3F0) + (1)));
        (*(u8 *)((s8 *)(&D_8012B3F0) + (0xB))) = (u8) (*(u8 *)((s8 *)(&D_8012B3F0) + (3)));
        (*(u8 *)((s8 *)(&D_8012B3F0) + (0xA))) = (u8) (*(u8 *)((s8 *)(&D_8012B3F0) + (2)));
        (*(s8 *)((s8 *)(&D_8012B3F0) + (1))) = -1;
        (*(u8 *)((s8 *)(&D_8012B3F0) + (9))) = 2U;
    }
}

s32 func_800D3934(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 1;
}

s32 func_800D3948(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 3;
}

s32 func_800D395C(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 2;
}

void func_800D3970(void) { void func_800D37D4(void); void func_800D3A14(s32); void func_800D3CF8(s32); void func_800D3D10(s32); func_800D37D4(); func_800D3A14(1); func_800D3CF8(0); func_800D3D10(1); }

void func_800D39A8(void) {
    s16 func_800B2DC0(s32, s32);
    extern s16 D_8012B3FC;
    D_8012B3FC = func_800B2DC0(0x14, 1);
}

void func_800D39D0(s32 arg0) {
    extern s8 D_8012B3F2;
    *(s8 *)((u8 *)&D_8012B3F2 + 0) = arg0;
}

void func_800D39DC(s32 arg0) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    if (arg0 >= 0) {
        func_800D3B6C(1, (s32 *) func_800D39D0, arg0, 0, 0);
    }
}

void func_800D3A14(s32 arg0) {
    extern s8 D_8012B3F3;
    *(s8 *)((u8 *)&D_8012B3F3 + 0) = arg0;
}

void func_800D3A20(s32 arg0) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    extern s32 func_800DA544;
    func_800D3B6C(1, &func_800DA544, arg0, 0, 0);
}

void func_800D3A54(s32 arg0, s32 arg1) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    extern s32 func_800C70B0;
    func_800D3B6C(2, &func_800C70B0, arg0, arg1, 0);
}

void func_800D3A88(void) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    extern s32 func_800C7010;
    func_800D3B6C(0, &func_800C7010, 0, 0, 0);
}

void func_800D3ABC(s32 arg0, s32 arg1) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    extern s32 func_800D1864;
    func_800D3B6C(3, &func_800D1864, arg0, arg1, 0);
}

void func_800D3AF0(s32 arg0) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    extern s32 func_800D1864;
    func_800D3B6C(3, &func_800D1864, arg0, 0x3E8, 0);
}

void func_800D3B24(void) {
    s32 func_800D3B6C(s32, s32 *, s32, s32, s32);
    void func_800DC324(s32 arg0);
    func_800D3B6C(1, (s32 *) func_800DC324, osGetCount(), 0, 0);
}

u32 func_800D3B60(void) {
    extern s8 D_8012B3F3;
    return (u8)D_8012B3F3;
}

s32 func_800D3B6C(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern s16 D_8012B3FC;
    void* func_800B2A58(s16 arg0);
    u8 *temp_v0;

    temp_v0 = func_800B2A58(D_8012B3FC);
    (*(s8 *)((s8 *)(temp_v0) + (0))) = (s8) arg0;
    (*(s32 **)((s8 *)(temp_v0) + (4))) = arg1;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = arg2;
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = arg3;
    (*(s32 *)((s8 *)(temp_v0) + (0x10))) = arg4;
    return (s32) temp_v0;
}

void func_800D3BC8(void *arg0) {
    struct Entry {
        u8 count;
        void (*callback)();
        s32 args[3];
    };
    struct Entry *entry = arg0;

    switch (entry->count) {
        case 0:
            entry->callback();
            break;
        case 1:
            entry->callback(entry->args[0]);
            break;
        case 2:
            entry->callback(entry->args[0], entry->args[1]);
            break;
        case 3:
            entry->callback(entry->args[0], entry->args[1], entry->args[2]);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAD060/func_800D3C70.s")

void func_800D3CF8(s32 arg0) {
    extern s8 D_8012B3F4;
    *(s8 *)((u8 *)&D_8012B3F4 + 0) = arg0;
}

u32 func_800D3D04(void) {
    extern s8 D_8012B3F4;
    return *(u8 *)&D_8012B3F4;
}

void func_800D3D10(s32 arg0) {
    extern s8 D_8012B3F5;
    *(s8 *)((u8 *)&D_8012B3F5 + 0) = arg0;
}

u32 func_800D3D1C(void) {
    extern s8 D_8012B3F5;
    return *(u8 *)&D_8012B3F5;
}

s32 func_800D3D28(void) {
    extern s32 D_8012B3F0;
    if ((*(u8 *)((s8 *)(&D_8012B3F0) + (9))) != 0) {
        return 0;
    }
    (*(u8 *)((s8 *)(&D_8012B3F0) + (9))) = 1U;
    return 1;
}

int func_800D3D58(void) { extern s32 D_8012B3F0; switch (*(u8 *)((s8 *)(&D_8012B3F0) + 9)) { case 1: (*(u8 *)((s8 *)(&D_8012B3F0) + 9)) = 0; return 1; case 2: (*(u8 *)((s8 *)(&D_8012B3F0) + 9)) = 3; return 1; default: return 0; } }

/* extern */

s32 func_800D3DA4(s32 arg0) {
    s32 func_800F54F0(s32);
    return func_800F54F0(arg0);
}
