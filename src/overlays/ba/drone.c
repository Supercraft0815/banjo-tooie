#include "common.h"

s32 badrone_entrypoint_0() 
{
    return 0x4C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_2.s")

u32 badrone_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 84) + 0);
}

void badrone_entrypoint_4(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x54)));
    (*(u8 *)((s8 *)(temp_v0) + (0))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (1)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_5.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/func_80800348_badrone.s")

/* extern */

void badrone_entrypoint_17(void *arg0) {
    s32 _badata_entrypoint_23();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (1))) = 7;
    _badata_entrypoint_23();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_18.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_23.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/drone/badrone_entrypoint_28.s")

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
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x54))) + 0x24);
}
