#include "common.h"

s32 badrone_entrypoint_0() 
{
    return 0x4C;
}

u8 badrone_entrypoint_1(void *arg0) {
    extern u8 D_80800630_badrone[];
    return D_80800630_badrone[*(*(u8 **)((s8 *)arg0 + 0x54))];
}

void badrone_entrypoint_2(void *arg0, s32 arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, *(u8 **)((u8 *)arg0 + 0x54) + 0x24);
}

u32 badrone_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 0);
}

void badrone_entrypoint_4(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x54)));
    (*(u8 *)((s8 *)(temp_v0) + (0))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (1)));
}

/* extern */

void badrone_entrypoint_5(u8 *arg0) {
    s32 func_800EFD24(u8 *, u8 *);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (4))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (5))) = 1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (8))) = 1.0f;
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x54))) + 0x10, arg0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0xC))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x1C))) = 0;
}

void badrone_entrypoint_6(void *arg0) {
    s32 (*temp_v1)(s32, s32, void *);
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x54)));
    temp_v1 = (*(s32 (**)(s32, s32, void *))((s8 *)(temp_v0) + (0x1C)));
    if (temp_v1 != NULL) {
        temp_v1((*(s32 *)((s8 *)(temp_v0) + (0x20))), (*(s32 *)((s8 *)(arg0) + (0x184))), arg0);
    }
}

u32 badrone_entrypoint_7(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 4);
}

void badrone_entrypoint_8(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (f32 *)(*(u8 **)(arg0 + 0x54) + 0x10));
    *arg2 = *(f32 *)(*(u8 **)(arg0 + 0x54) + 8);
    *arg3 = *(f32 *)(*(u8 **)(arg0 + 0x54) + 0xC);
}

u32 badrone_entrypoint_9(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 5);
}

void badrone_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 4) = arg1;
}

void badrone_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x1C))) = arg1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x20))) = arg2;
}

void badrone_entrypoint_12(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 5) = arg1;
}

/* extern */

void badrone_entrypoint_13(void *arg0, s32 arg1) {
    s32 _bamovegoto_entrypoint_12(void *, s32);
    s32 func_8009BAF4(void *);
    void func_800EE7F8();
    func_800EE7F8((*(u8 **)((s8 *)(arg0) + (0x54))) + 0x10);
    if ((*(*(u8 **)((s8 *)(arg0) + (0x54))) == 1) && (func_8009BAF4(arg0) == 0xC)) {
        _bamovegoto_entrypoint_12(arg0, arg1);
    }
}

/* extern */

void badrone_entrypoint_14(u8 *arg0, f32 *arg1, f32 arg2) {
    s32 bs_setState(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 _badata_entrypoint_21();
    func_800EE7F8((f32 *)((*(u8 **)((s8 *)(arg0) + (0x54))) + 0x10), arg1);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0xC))) = arg2;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (8))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (1))) = 1;
    bs_setState((s32) arg0, _badata_entrypoint_21(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_16.s")

/* extern */

void func_80800348_badrone(void *arg0, s32 arg1) {
    s32 _badata_entrypoint_21();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = arg1;
    _badata_entrypoint_21();
}

/* extern */

void badrone_entrypoint_17(void *arg0) {
    s32 _badata_entrypoint_23();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = 7;
    _badata_entrypoint_23();
}

void badrone_entrypoint_18(void *arg0, s32 arg1) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x48))) = arg1;
    func_80800348_badrone(arg0, 0xC);
}

void badrone_entrypoint_19(s32 arg0)
{
    func_80800348_badrone(arg0,0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_20.s")

/* extern */

void badrone_entrypoint_21(void *arg0) {
    s32 _badata_entrypoint_22();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = 15;
    _badata_entrypoint_22();
}

/* extern */

void badrone_entrypoint_22(void *arg0) {
    void func_800EE7F8();
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x54))) + 0x34);
    func_80800348_badrone(arg0, 0xB);
}

/* extern */

void badrone_entrypoint_23(void *arg0) {
    void func_800EE7F8();
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x54))) + 0x34);
    func_80800348_badrone(arg0, 0xA);
}

void badrone_entrypoint_24(s32 arg0)
{
    func_80800348_badrone(arg0,0x2);
}

void badrone_entrypoint_25(s32 arg0)
{
    func_80800348_badrone(arg0,0x9);
}

/* extern */

void badrone_entrypoint_26(void *arg0) {
    s32 _badata_entrypoint_23();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = 3;
    _badata_entrypoint_23();
}

void badrone_entrypoint_27(s32 arg0)
{
    func_80800348_badrone(arg0,0x6);
}

/* extern */

void badrone_entrypoint_28(void *arg0) {
    s32 baflag_clear(s32, s32);
    baflag_clear(arg0, 0x19);
    func_80800348_badrone(arg0, 4);
}

void badrone_entrypoint_29(s32 arg0)
{
    func_80800348_badrone(arg0,0xE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_30.s")

s32 badrone_entrypoint_31(void *arg0) {
    if (*(*(u8 **)((s8 *)(arg0) + (0x54))) == 1) {
        return 1;
    }
    return 0;
}

void badrone_entrypoint_32(void *arg0) {
    void *temp_v0;

    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = 0U;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x54)));
    (*(u8 *)((s8 *)(temp_v0) + (0))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (1)));
}

/* extern */

void badrone_entrypoint_33(void *arg0) {
    void func_800EE7F8();
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x54))) + 0x24);
}
