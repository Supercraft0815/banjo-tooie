#include "common.h"

s32 func_80800000_baeggcursor(s32 arg0) {
    extern s32 D_80800690_baeggcursor[];
    return ((s32 *)&D_80800690_baeggcursor)[arg0];
}

s32 baeggcursor_entrypoint_0() 
{
    return 0x1C;
}

s32 baeggcursor_entrypoint_7(void *, s32);

/* extern */

void baeggcursor_entrypoint_1(void *arg0) {
    int func_800A4C68(void *);
    s32 *func_800A7180(void);
    s32 func_800A89F8();
    s32 func_800A9C98(void);
    s32 func_800D674C(s32);
    void func_800E2434(s32);
    void func_800E24CC(s32);
    void func_800E253C(f32);
    void func_800E257C(s32);
    void func_800E30E0(s32 *, void *, s32, void *);
    s32 sp30[2];
    s32 sp2C;
    s32 *temp_s0;
    void *temp_v0;

    sp2C = func_800A89F8();
    if (func_800A4C68(arg0) == sp2C) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x68)));
        if (((*(u8 *)((s8 *)(temp_v0) + (8))) != 0) && ((*(u8 *)((s8 *)(temp_v0) + (0xA))) != 0) && (func_800A9C98() == 0)) {
            func_800E253C((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0x18))));
            func_800E257C((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0x14))));
            func_800E2434(1);
            func_800E24CC(1);
            sp30[0] = (s32) ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0))) * 4.0f);
            sp30[1] = (s32) ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (4))) * 4.0f);
            temp_s0 = func_800A7180();
            func_800E30E0(temp_s0, func_800D674C(0x64E), 0, sp30);
        }
    }
}

u32 baeggcursor_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 104) + 9);
}

void baeggcursor_entrypoint_3(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (4)));
}

void baeggcursor_entrypoint_4(s32 arg0)
{
    baeggcursor_entrypoint_7(arg0,0);
}

void baeggcursor_entrypoint_5(void *arg0) { *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 9) = 0; baeggcursor_entrypoint_7(arg0, 1); }

void baeggcursor_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 104) + 10) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_7.s")

void baeggcursor_entrypoint_8(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (9)));
    if ((temp_v0 != 0) && (temp_v0 != 1) && (temp_v0 != 4)) {
        baeggcursor_entrypoint_7(arg0, 5);
    }
}

s32 baeggcursor_entrypoint_9(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (9)));
    if ((temp_v0 != 0) && (temp_v0 != 1) && (temp_v0 != 4)) {
        return 1;
    }
    return 0;
}

void baeggcursor_entrypoint_10(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (4))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_11.s")
