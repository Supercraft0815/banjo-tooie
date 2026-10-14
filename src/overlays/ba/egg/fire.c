#include "common.h"

s32 baeggfire_entrypoint_0() 
{
    return 0x14;
}

s32 func_80800008_baeggfire(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg1 == 1) {
        temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x6C)));
        (*(u8 *)((s8 *)(temp_v0_2) + (0x12))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (0x12))) + 1);
        return (s32) temp_v0_2;
    }
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x6C)));
    (*(u8 *)((s8 *)(temp_v0) + (0x11))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x11))) + 1);
    return (s32) temp_v0;
}

void func_80800040_baeggfire(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x12))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x11))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 0;
}

/* extern */

void baeggfire_entrypoint_1(void) {
    void *func_800F53D0();
    s32 func_80800008_baeggfire(void *, s32);
    void *temp_v0;

    temp_v0 = func_800F53D0();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(temp_v0) + (0x6C)))) + (0x13))) = 0;
    func_80800008_baeggfire(temp_v0, 0);
}

/* extern */

void baeggfire_entrypoint_2(void) {
    void *func_800F53D0();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(func_800F53D0()) + (0x6C)))) + (0x13))) = 0;
}

void func_808000B8_baeggfire(void *arg0) {
    s32 _baeggsetup_entrypoint_10(void *);
    s32 _baeggsetup_entrypoint_8(void *, u8);
    s32 func_800C9DE4(f32, s32 *, s32);
    extern s32 _baeggfire_entrypoint_1;
    extern s32 _baeggfire_entrypoint_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x6C)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x13))) == 0) {
        if ((*(u8 *)((s8 *)(temp_v0) + (0x12))) != 0) {
            func_800C9DE4(0.25f, &_baeggfire_entrypoint_1, (*(s32 *)((s8 *)(arg0) + (0x184))));
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 1;
            _baeggsetup_entrypoint_10(arg0);
            temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x6C)));
            (*(u8 *)((s8 *)(temp_v0_2) + (0x12))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (0x12))) - 1);
            return;
        }
        if ((*(u8 *)((s8 *)(temp_v0) + (0x11))) != 0) {
            func_800C9DE4(0.17f, &_baeggfire_entrypoint_2, (*(s32 *)((s8 *)(arg0) + (0x184))));
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 1;
            _baeggsetup_entrypoint_8(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x10))));
            temp_v0_3 = (*(void **)((s8 *)(arg0) + (0x6C)));
            (*(u8 *)((s8 *)(temp_v0_3) + (0x11))) = (u8) ((*(u8 *)((s8 *)(temp_v0_3) + (0x11))) - 1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_80800180_baeggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_80800250_baeggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_3.s")

void baeggfire_entrypoint_4(s32 arg0)
{
    func_8009E0AC(arg0,1);
}

void baeggfire_entrypoint_5(void *arg0) {
    void func_80800180_baeggfire(void *arg0, s32 arg1);
    (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C))) = 0.0f;
    (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0xC)) = 0;
    (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 8)) = 0;
    func_80800180_baeggfire(arg0, 1);
    func_8009E0AC(arg0, 0);
    func_80800040_baeggfire(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_6.s")

void baeggfire_entrypoint_7(void *arg0) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0xC))) = 1;
}

s32 baeggfire_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (8))) >= 2;
}
