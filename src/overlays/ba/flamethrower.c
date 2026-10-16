#include "common.h"

s32 baflamethrower_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void func_80800008_baflamethrower(void *arg0) {
    s32 _baflameline_entrypoint_4(void *, s32 *);
    s32 _baflameline_entrypoint_5(void *, s32 *);
    s32 _baflameline_entrypoint_6(void *, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 sp2C[3];
    s32 sp20[3];

    (*(s32 (**)(void *, s32 *, s32 *))((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (0)))(arg0, sp2C, sp20);
    _baflameline_entrypoint_4(arg0, sp2C);
    _baflameline_entrypoint_5(arg0, sp20);
    _baflameline_entrypoint_6(arg0, (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (4))));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (4))) = func_800F15F8((*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x88)) + 4)), (*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x88)) + 8)), 20.0f);
}

void func_80800088_baflamethrower(void *arg0, s32 arg1) {
    s32 _baflameline_entrypoint_1(void *, s32);
    void *temp_v0;
    s32 temp_v1;

    temp_v0 = *(void **)((s8 *)arg0 + 0x88);
    temp_v1 = *(u8 *)((s8 *)temp_v0 + 0xC);
    if ((temp_v1 != 1 && temp_v1 != 3) || arg1 != 3) {
    *(u8 *)((s8 *)temp_v0 + 0xC) = arg1;
    if (arg1 != 0) {
        switch (arg1) {
            case 1:
                *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x88) + 8) = 0.0f;
                temp_v0 = *(void **)((s8 *)arg0 + 0x88);
                *(f32 *)((s8 *)temp_v0 + 4) = *(f32 *)((s8 *)temp_v0 + 8);
                func_80800008_baflamethrower(arg0);
                return;
            case 2:
                *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x88) + 4) = 150.0f;
                *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x88) + 8) = 300.0f;
                func_80800008_baflamethrower(arg0);
                return;
            case 3:
                *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x88) + 8) = 150.0f;
                _baflameline_entrypoint_1(arg0, arg1);
                break;
        }
    }
    }
}

void baflamethrower_entrypoint_1(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0);
    _baflameline_entrypoint_2(arg0);
}

void baflamethrower_entrypoint_2(s32 arg0, s32 arg1) { _baflameline_entrypoint_3(); (*(s32 *)((s8 *)(*(u8 **)((s8 *)(arg0) + 0x88)) + 0)) = arg1; (*(s8 *)((s8 *)(*(u8 **)((s8 *)(arg0) + 0x88)) + 0xC)) = 0; func_80800088_baflamethrower(arg0, 1); }

void baflamethrower_entrypoint_3(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x2);
}

void baflamethrower_entrypoint_4(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x3);
}

void baflamethrower_entrypoint_5(void *arg0) {
    void *temp;

    switch (*(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0x88) + 0xC)) {
        case 1:
            break;
        case 2:
            func_80800008_baflamethrower(arg0);
            break;
        case 3:
            func_80800008_baflamethrower(arg0);
            temp = *(void **)((s8 *)arg0 + 0x88);
            if (*(f32 *)((s8 *)temp + 8) == *(f32 *)((s8 *)temp + 4)) {
                func_80800088_baflamethrower(arg0, 1);
            }
            break;
    }
    _baflameline_entrypoint_7(arg0);
}
