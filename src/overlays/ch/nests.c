#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800000_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800098_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808000E8_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800144_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808001F0_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808002E0_chnests.s")

void func_80800324_chnests(s32 arg0)
{
    func_80800144_chnests();
    func_808002E0_chnests(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_8080034C_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808003AC_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808003F4_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800670_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808006C4_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808007C8_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_8080082C_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800898_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_8080093C_chnests.s")

void func_80800960_chnests(s32 arg0) 
{
}
void func_80800968_chnests(void *arg0, s32 arg1) {
    s32 func_800DF3E0();
    s32 func_800DF744(s32, s32);
    s32 func_801018A4(s32, s32);
    s32 func_80800898_chnests(void *, s32, s32);
    extern s32 D_80801124_chnests;
    if (func_80800898_chnests(arg0, arg1, *(s32 *)((s8 *)arg0 + 0x48)) != 0) {
        func_800DF3E0();
        func_800DF744(((u8 *)&D_80801124_chnests)[(*(s32 *)((s8 *)arg0 + 0x1C)) * 14], 1);
        func_801018A4((s32)arg0, arg1);
    }
}

void func_808009D4_chnests(s32 arg0,s32 arg1)
{
    func_8010DD20(arg0,0x1,arg1);
}

void func_808009F8_chnests(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800A00_chnests.s")

void func_80800A6C_chnests(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800A74_chnests.s")

/* extern */

void func_80800B4C_chnests(void *arg0) {
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178((*(f32 *)((s8 *)(arg0) + (0x28))), (*(f32 *)((s8 *)(arg0) + (0x2C))));
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
}

void func_80800B80_chnests(void *arg0) {
    struct Flags { u32 unused : 11; u32 enabled : 1; u32 remaining : 20; };
    if (((struct Flags *)((s8 *)arg0 + 0x64))->enabled) {
        (*(s32 *)((s8 *)(arg0) + (0x30))) = 2;
    }
}

struct Entry { s16 value; s16 rest[6]; };
extern struct Entry D_80801118_chnests[];

void func_80800BA0_chnests(void *arg0, s32 arg1) {
    struct Flags { u16 value : 10; u16 rest : 6; };
    void *ptr;

    ptr = *(void **)arg0;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    ((struct Flags *)((s8 *)ptr + 0x24))->value = D_80801118_chnests[arg1].value;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800BD8_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800C3C_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800D8C_chnests.s")

/* extern */

void func_80800ED8_chnests(s32 arg0) {
    s32 func_80800BD8_chnests(s32, s32, f32, f32);
    func_80800BD8_chnests(arg0, 0x1CE, 1.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800F08_chnests.s")

OSThread *chnests_entrypoint_0(void)
{
    extern u8 D_808011E8_chnests[];

    return (OSThread *) D_808011E8_chnests;
}

OSThread *chnests_entrypoint_1(void)
{
    extern u8 D_80801230_chnests[];

    return (OSThread *) D_80801230_chnests;
}

OSThread *chnests_entrypoint_2(void)
{
    extern u8 D_80801278_chnests[];

    return (OSThread *) D_80801278_chnests;
}

OSThread *chnests_entrypoint_3(void)
{
    extern u8 D_808012C0_chnests[];

    return (OSThread *) D_808012C0_chnests;
}

OSThread *chnests_entrypoint_4(void)
{
    extern u8 D_80801308_chnests[];

    return (OSThread *) D_80801308_chnests;
}

OSThread *chnests_entrypoint_5(void)
{
    extern u8 D_80801350_chnests[];

    return (OSThread *) D_80801350_chnests;
}

OSThread *chnests_entrypoint_6(void)
{
    extern u8 D_80801398_chnests[];

    return (OSThread *) D_80801398_chnests;
}

OSThread *chnests_entrypoint_7(void)
{
    extern u8 D_808013E0_chnests[];

    return (OSThread *) D_808013E0_chnests;
}

OSThread *chnests_entrypoint_8(void)
{
    extern u8 D_80801428_chnests[];

    return (OSThread *) D_80801428_chnests;
}

OSThread *chnests_entrypoint_9(void)
{
    extern u8 D_80801470_chnests[];

    return (OSThread *) D_80801470_chnests;
}

OSThread *chnests_entrypoint_10(void)
{
    extern u8 D_808014B8_chnests[];

    return (OSThread *) D_808014B8_chnests;
}

OSThread *chnests_entrypoint_11(void)
{
    extern u8 D_80801500_chnests[];

    return (OSThread *) D_80801500_chnests;
}

OSThread *chnests_entrypoint_12(void)
{
    extern u8 D_80801548_chnests[];

    return (OSThread *) D_80801548_chnests;
}

u8 chnests_entrypoint_13(s32 arg0) {
    struct Entry *entry;
    s32 i;
    s32 limit;

    limit = 14;
    entry = &D_80801118_chnests[i = 0];
    do {
        if (arg0 == entry->value) {
            return *((u8 *)entry + 0xB);
        }
        entry++;
    } while (++i < limit);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80801014_chnests.s")

int func_808010A0_chnests(void *arg0) {
    return ((u32)(*(s32 *)((u8 *)arg0 + 0x6C) << 11) >> 20) == 0x1CE
        || ((u32)(*(s32 *)((u8 *)arg0 + 0x6C) << 11) >> 20) == 0x1CF
        || ((u32)(*(s32 *)((u8 *)arg0 + 0x6C) << 11) >> 20) == 0x4A6;
}
