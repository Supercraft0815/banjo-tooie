#include "common.h"

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}

void baflameline_entrypoint_1(void *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA77C(s32, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFE50(f32[3], f32[3], f32[3], f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_808006F0_baflameline[];
    f32 t;
    f32 sp90[3];
    f32 sp84[3];
    s32 temp_s1;
    s32 var_s0;
    void *temp_v1;

    temp_s1 = func_800B53A4(0xE);
    temp_v1 = *(void **)((s8 *)arg0 + 0x84);
    func_800EFA20(sp90, (s8 *)temp_v1 + 0xC, *(f32 *)((s8 *)temp_v1 + 0x18));
    func_800EF04C(sp90, *(f32 **)((s8 *)arg0 + 0x84));
    for (var_s0 = 0; var_s0 != 7; var_s0++) {
        t = func_800F10B4(((f32)var_s0 + 0.5f) / 7.0f, 0.0f, 1.0f, 0.2f, 1.0f);
        func_800EFE50(sp84, *(f32 **)((s8 *)arg0 + 0x84), sp90, t);
        func_800BA77C(temp_s1, 0, 0, (s16)(s32)func_800DC178(0.0f, 359.0f));
        func_800BABB8(temp_s1, sp84, NULL, 1, D_808006F0_baflameline);
    }
}

void func_80800184_baflameline(void *arg0, f32 arg1[3]) { void func_800BA77C(s32, s16, s16, s16); void func_800BA930(s32, s16, s16, s16, s16, s16, s16); s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]); f32 func_800DC178(f32, f32); void func_800EFA20(void *, void *, f32); extern s32 D_80800738_baflameline[]; f32 sp34[3]; func_800EFA20(sp34, (s8 *)*(void **)((s8 *)arg0 + 0x84) + 0xC, *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x18) / 0.3f); sp34[1] -= (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x18) / 0.3f) * 0.1f; func_800BA77C(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), 0, 0, (s16)(s32)func_800DC178(0.0f, 359.0f)); func_800BA930(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), (s16)sp34[0], (s16)sp34[1], (s16)sp34[2], (s16)sp34[0], (s16)sp34[1], (s16)sp34[2]); func_800BABB8(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), arg1, NULL, 1.0f, D_80800738_baflameline); }

/* extern */

void baflameline_entrypoint_2(void *arg0) {
    s32 func_800B5450(s32, void *);
    s32 func_800C2FDC(u8, void *);
    s32 func_800C8B84(s32, void *);
    s32 temp_a0;
    void *var_v0;

    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x20))), arg0);
    var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    temp_a0 = (*(s32 *)((s8 *)(var_v0) + (0x24)));
    if (temp_a0 != 0) {
        func_800C8B84(temp_a0, arg0);
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
        var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    }
    func_800B5450((*(s32 *)((s8 *)(var_v0) + (0x1C))), arg0);
}

void baflameline_entrypoint_3(u8 *arg0) {
    s32 func_800B53A4(s32);
    s32 func_800B5534(s32);
    s32 func_800BF8E4();
    s8 func_800C4350(s32, s32, s32 *);
    s32 func_800C8A98();
    s32 func_800C8F64(s32, s32);
    s32 func_800C8FE0(s32, s32);
    s32 func_800EFD24(u8 *);
    extern s32 D_80800784_baflameline;
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))));
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))) + 0xC);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x18))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))) = func_800B53A4(0x28);
    func_800B5534((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))));
    if (func_800BF8E4() > 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = func_800C8A98();
        func_800C8F64((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0xB);
        func_800C8FE0((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0);
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
    }
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x20))) = func_800C4350(0, 0, &D_80800784_baflameline);
}

/* extern */

void baflameline_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))));
}

/* extern */

void baflameline_entrypoint_5(void *arg0) {
    s32 func_800EE7F8(s32);
    s32 func_800EF2A0(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
    func_800EF2A0((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
}

void baflameline_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 132) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_7.s")
