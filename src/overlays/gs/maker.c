#include "common.h"

// void stuff() {
    
// }

/* extern */

void gsmaker_entrypoint_0(void *arg0) {
    s32 func_800D6CEC(s16);
    s32 func_800D70F8(s16, s32);
    s32 func_800D721C(s16, s32);
    s32 heap_free(void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x14))) == 2) {
        func_800D721C((*(s16 *)((s8 *)(arg0) + (0x20))), 0);
        func_800D70F8((*(s16 *)((s8 *)(arg0) + (0x20))), 0);
        func_800D6CEC((*(s16 *)((s8 *)(arg0) + (0x20))));
    }
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_1.s")

/* extern */

void gsmaker_entrypoint_2(s32 arg0) {
    s32 gsmaker_entrypoint_1(s32);
    gsmaker_entrypoint_1(arg0 + 0x955);
}

/* extern */

void gsmaker_entrypoint_3(s32 arg0, s32 arg1) {
    s32 gsmaker_entrypoint_1(s32);
    gsmaker_entrypoint_1(arg0 + arg1);
}

void gsmaker_entrypoint_4(s32 arg0, s32 arg1) {
    void* heap_alloc(s32 size);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 3;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0x10))) = (s32) (arg0 + arg1);
}

u8 *gsmaker_entrypoint_5(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;
    u8 *temp_v0_2;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 4;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    sp1C = temp_v0;
    temp_v0_2 = heap_alloc(0x20);
    (*(u8 **)((s8 *)(sp1C) + (8))) = temp_v0_2;
    (*(u8 **)((s8 *)(sp1C) + (0xC))) = temp_v0_2;
    (*(s32 *)((s8 *)(sp1C) + (0x10))) = (s32) (temp_v0_2 + 0x20);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_6.s")

void gsmaker_entrypoint_7(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_8.s")

void gsmaker_entrypoint_9(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_10.s")

void gsmaker_entrypoint_11(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_13.s")

void gsmaker_entrypoint_14(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_23.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_25.s")
