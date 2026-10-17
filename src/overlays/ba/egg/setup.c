#include "common.h"
typedef struct player_state_s PlayerState;

s32 baeggsetup_entrypoint_0() 
{
    return 0x28;
}

/* extern */

s32 func_80800008_baeggsetup(void *arg0) {
    s32 func_8009E674(void *, s32);
    s32 result;
    result = func_8009E674(arg0, 2);
    return result == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_3.s")

/* extern */

void baeggsetup_entrypoint_4(s32 arg0) {
    s32 baeggsetup_entrypoint_3(s32, u8, u8 *, u8 *, u8 *);
    u8 *func_800F53D0();
    u8 *temp_a2;

    temp_a2 = (*(u8 **)((s8 *)(func_800F53D0()) + (0x70)));
    baeggsetup_entrypoint_3(arg0, (*(u8 *)((s8 *)(temp_a2) + (0x24))), temp_a2, temp_a2 + 0xC, temp_a2 + 0x18);
}

void baeggsetup_entrypoint_5(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, s32);
    void func_80094C0C(PlayerState *, s32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F3E84();
    extern s32 _baeggsetup_entrypoint_4;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_80094C0C(arg0, arg1);
    func_8009C128(arg0, sp20);
    sp20[1] += arg2;
    func_800EE7F8(sp44, sp20);
    func_800F3E84(arg0, sp38);
    func_800EEB9C(sp2C, sp38[1] * 1.0f, arg3);
    func_800EF04C(sp20, sp2C);
    func_800EEB9C(sp2C, sp38[1] *= 1.0f, 800.0f);
    sp2C[1] = 0.0f;
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70), sp44);
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70) + 3, sp20);
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70) + 6, sp2C);
    *(s8 *)(*(u8 **)((s8 *)arg0 + 0x70) + 0x24) = arg1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_4, *(s32 *)((s8 *)arg0 + 0x184));
}

void baeggsetup_entrypoint_6(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, s32);
    void func_80094C0C();
    void func_800EE7F8(f32 *, f32 *);
    extern s32 _baeggsetup_entrypoint_4;
    func_80094C0C();
    func_800EE7F8((*(f32 **)((s8 *)(arg0) + (0x70))), arg2);
    func_800EE7F8((*(f32 **)((s8 *)(arg0) + (0x70))) + 3, arg3);
    func_800EE7F8((*(f32 **)((s8 *)(arg0) + (0x70))) + 6, arg4);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x70)))) + (0x24))) = (s8) arg1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_4, (*(s32 *)((s8 *)(arg0) + (0x184))));
}

void baeggsetup_entrypoint_7(u8 *arg0, s32 *arg1) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, s32);
    _chbaddiesetup_entrypoint_1(arg1, (*(s32 *)((s8 *)(arg0) + (0x184))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_9.s")

void baeggsetup_entrypoint_10(void *arg0) {
    void func_800C4B64(f32);
    void func_800C4B70(s32 arg0);
    void func_800C4B7C(s32 arg0);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_8010D930(s32, s32, u8 *, s32 *);
    extern s32 D_80800860_baeggsetup;
    f32 sp1C[3];
    s32 pad;

    func_8009C128(arg0, sp1C);
    func_800C4B64(1.0f);
    func_800C4B70(0x7FFF);
    func_800C4B7C(0x4A5);
    func_8010D930(0xA, -1, sp1C, &D_80800860_baeggsetup);
}
