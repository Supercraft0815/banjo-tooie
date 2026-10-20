#include "common.h"

s32 bamum_entrypoint_0() 
{
    return 0x8;
}

void func_80800008_bamum(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xD0)))) + (4))) = 0.0f;
}

void func_80800018_bamum(arg0)
{
    typedef struct player_state_s PlayerState;
    void func_80092C48(PlayerState *, f32[3]);
    void func_80092C6C(PlayerState *, f32[3]);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009C15C(u8 *, f32 *);
    s32 func_800B5BE4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    void func_800F1A88(f32 *, f32 *);
    extern s32 D_80800280_bamum[];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp34[2];
    s32 sp30;

    sp30 = func_800B5BE4(0xD);
    if (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xD0) + 4) != 0.0f) {
        func_8009C128(arg0, sp6C);
        func_8009C15C(arg0, sp60);
        func_800EFB24(sp78, sp6C, sp60);
        func_80092C6C(arg0, sp54);
        func_80092C48(arg0, sp48);
        func_800EF04C(sp54, sp78);
        func_800EF04C(sp48, sp78);
        func_800EFB24(sp78, sp48, sp54);
        func_800F1A88(sp78, sp34);
        sp34[0] = -sp34[0];
        func_800EFD24(sp84);
        func_800EE780(sp3C, sp48, sp84);
        func_800BA994(sp30, sp34[0] - 20.0f, sp34[1] - 40.0f, 400,
                     sp34[0] + 20.0f, sp34[1] + 40.0f, 400);
        func_800BABB8(sp30, sp3C, NULL, 1.0f, D_80800280_bamum);
        func_800BA22C(sp30, (s32)((*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0xD0) + 4) * 3.0f) + 0.5f));
    }
}

void bamum_entrypoint_1(s32 arg0) 
{
}
/* extern */

void bamum_entrypoint_2(void *arg0) {
    s32 func_8009ADF0(void *, s32, s32);
    func_80800008_bamum(arg0);
    func_8009ADF0(arg0, 5, 0);
}

void bamum_entrypoint_3()
{
    func_80800018_bamum();
}

void bamum_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 func_8009ADF0(void *, s32, s32);
    if (arg1 != 0) {
        func_8009ADF0(arg0, 5, 1);
        func_80800008_bamum(arg0);
        return;
    }
    func_8009ADF0(arg0, 5, 0);
}

void bamum_entrypoint_5(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 208) + 4) = arg1;
}
