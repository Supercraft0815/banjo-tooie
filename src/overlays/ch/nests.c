#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800000_chnests.s")

/* extern */
void func_808002E0_chnests(void *);
void func_80800098_chnests(void *arg0) {
    s32 func_800D3948(void);
    u32 func_800F54E4(void);
    s32 func_800F7150(s32);
    func_80800000_chnests();
    if ((func_800D3948() == 0) && (func_800F7150(func_800F54E4()) != 0)) {
        func_808002E0_chnests(arg0);
    }
}

struct Entry { s16 value; s16 rest[6]; };
extern struct Entry D_80801118_chnests[];

void func_808000E8_chnests(void *arg0) {
    s8 *entry;

    entry = (s8 *)D_80801118_chnests + *(s32 *)((s8 *)arg0 + 0x1C) * 14;
    if (*(s16 *)(entry + 8) != 0) {
        if (func_800DA298(*(s16 *)(entry + 8)) == 0) {
            _sudialog_entrypoint_0(*(s16 *)(entry + 8), 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800144_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808001F0_chnests.s")

/* extern */

void func_808002E0_chnests(void *arg0) {
    s32 func_80101FDC(void *, s32);
    s32 func_8010A570();
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    func_8010A570();
    (*(u32 *)((s8 *)(arg0) + (0x18))) = ((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA;
    func_80101FDC(arg0, 4);
}

void func_80800144_chnests(void);

void func_80800324_chnests(s32 arg0)
{
    func_80800144_chnests();
    func_808002E0_chnests(arg0);
}
/* extern */

void func_8080034C_chnests(void *arg0) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiefade_entrypoint_2();
    s32 func_80101FDC(void *, s32);
    void func_80103110(void *, s32);
    s32 func_8010A590(void *);
    _subaddiefade_entrypoint_2();
    func_80103110(arg0, 0);
    _subaddieDll_entrypoint_4(arg0, 0);
    func_8010A590(arg0);
    ((Actor *)arg0)->unk64_16 = 1;
    func_80101FDC(arg0, (*(s32 *)((s8 *)(arg0) + (0x18))));
}

/* extern */

void func_808003AC_chnests(Actor *arg0) {
    if (((u32) arg0->unk70_10 == 4) && (func_800D9078(&arg0->unk58) != 0)) {
        func_8080034C_chnests(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808003F4_chnests.s")

void func_80800670_chnests(void *arg0) {
    s32 _gleeprom_entrypoint_0(void);
    func_80800144_chnests();
    func_808000E8_chnests(arg0);
    if ((_gleeprom_entrypoint_0() >> 0x18) == 0x10) {
        func_800D0BD4(*(s32 *)((s8 *)arg0 + 0x20), 6);
    }
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_808006C4_chnests.s")

/* extern */

void func_808007C8_chnests(Actor *arg0) {
    union NestActorView {
        Actor actor;
        struct {
            u32 prefix[29];
            u32 pad74_28 : 4;
            u32 active : 1;
            u32 pad74_0 : 27;
        } flags;
    } *view = (union NestActorView *)arg0;
    f32 func_800D8FF8(void);
    void func_80103110(void *, s32);
    f32 delta;
    if (((u32)arg0->unk70_10 == 2) && view->flags.active) {
        delta = func_800D8FF8();
        arg0->rotation[1] += *(f32 *)&arg0->actorData[5] * delta;
        func_80103110(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_8080082C_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800898_chnests.s")

s32 func_8080093C_chnests(u8 *arg0, u8 *arg1) {
    int func_8010DD20(u8 *, s32, u8 *);
    return func_8010DD20(arg0, 0, arg1);
}

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
void func_80800A00_chnests(void *arg0, s32 arg1) {
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

void func_80800BA0_chnests(void *arg0, s32 arg1) {
    struct Flags { u16 value : 10; u16 rest : 6; };
    void *ptr;

    ptr = *(void **)arg0;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    ((struct Flags *)((s8 *)ptr + 0x24))->value = D_80801118_chnests[arg1].value;
}

/* extern */

void func_80800BD8_chnests(Actor *arg0, s32 arg1, f32 arg2, f32 arg3) { struct Flags { u16 value : 10; u16 rest : 6; }; ((struct Flags *)((s8 *)arg0->unk0 + 0x24))->value = arg1; func_80800000_chnests(); arg0->unk64_20 = 1; ((f32 *)arg0->actorData)[4] = arg2; ((f32 *)arg0->actorData)[5] = arg3; func_80800B4C_chnests(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800C3C_chnests.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nests/func_80800D8C_chnests.s")

/* extern */

void func_80800ED8_chnests(s32 arg0) {
    func_80800BD8_chnests(arg0, 0x1CE, 1.0f, 1.0f);
}

/* extern */

void func_80800F08_chnests(s32 arg0) {
    func_80800BD8_chnests(arg0, 0x1D5, 1.0f, 1.0f);
}

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
