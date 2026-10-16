#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800000_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800088_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808000F4_chclinker.s")

/* extern */

s32 func_808002B0_chclinker(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80101180(s32, s32, s32);
    void func_80800304_chclinker(Actor *, u32);
    if (arg1 == 0x40) {
        func_80101180(0x2BF, 0x4F, 0);
        func_80800304_chclinker(arg0, 2);
    } else {
        return 0;
    }
    return 1;
}

void func_80800304_chclinker(Actor *arg0, u32 arg1) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    void* func_80100094(Actor*, u32);
    void func_80101FDC(Actor*, u32);
    void func_8010A570(Actor*);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (arg1 == 2) {
        func_8010A570(arg0);
        _subaddieDll_entrypoint_4(arg0, 1U);
        (*(s32 *)((s8 *)(sp1C) + (8))) = 0;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800368_chclinker(Actor *arg0, u8 *arg1) {
    void func_800DF744(s32, s32);
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))));
    func_80101870(arg0, arg1);
}

/* extern */

void func_808003A8_chclinker(Actor *arg0) {
    void _subaddiezone_entrypoint_0(void *);
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80103014(u8 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EE7F8(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], 100.0f);
    func_800EE7F8(sp30, arg0->position);
    func_800EF1B8(sp30, arg0->rotation[1], -200.0f);
    if (func_800BEF00(sp3C, sp30, sp24, arg0->unk14) != 0) {
        func_800EE7F8(arg0->position, sp30);
        func_800EF1B8(arg0->position, arg0->rotation[1], 5.0f);
        func_80103014((u8 *)arg0);
        _subaddiezone_entrypoint_0(arg0);
    }
}

OSThread *chclinker_entrypoint_0(void)
{
    extern u8 D_808014D4_chclinker[];

    return (OSThread *) D_808014D4_chclinker;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_8080045C_chclinker.s")

/* extern */

void func_80800574_chclinker(s32 arg0) {
    s32 _susubgame_entrypoint_11(s32);
    _susubgame_entrypoint_11(0);
}

void func_80800598_chclinker(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808005BC_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808006A4_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808007BC_chclinker.s")

void func_808008C0_chclinker(s32 arg0)
{
    func_808008E0_chclinker(arg0,0x5);
}

int func_808008E0_chclinker(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_800CE8D8(s32, f32, s32);
    s32 func_800D2498(s32, s32, s32);
    s32 func_800D2054(s32, s32, s32);
    void func_800F49D4(s32, void *, s32);
    void func_800FC63C(u32, u32);
    void *data;
    s32 player;
    s32 pad0;
    s32 pad1;
    s32 message;

    data = func_80100094(arg0, 0);
    if (arg1 != ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10)) {
        switch (arg1) {
        case 2:
            _gcfrontend_entrypoint_9(0x6C);
            func_800D2498(0x103, *(s32 *)data, 0);
            func_800CE8D8(0, (f32)((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7),
                         (u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7);
            func_800CE88C(0, 1);
            break;
        case 4:
            func_800FC63C(0x10, -1);
            func_80800BDC_chclinker(arg0, 0x1372);
            if (func_800CEAA8(0) != 0) {
                func_800CE88C(0, 0);
            }
            if (*(s32 *)((u8 *)arg0 + 0x3C) != 0) {
                func_8010114C(*(s32 *)((u8 *)arg0 + 0x3C), 0x4F, 0);
                *(s32 *)((u8 *)arg0 + 0x3C) = 0;
            }
            break;
        case 5:
            func_800D284C(0x103);
            if (func_800D395C() != 0) {
                func_800D284C(0xCC);
            } else {
                if (func_800CEAA8(0) != 0) {
                    func_800CE88C(0, 0);
                }
                func_800D284C(0xCC);
            }
            break;
        case 3:
            func_80108B04(arg0, 0);
            func_80800BDC_chclinker(arg0, 0x1371);
            break;
        case 9:
            player = func_800F54E4();
            func_800F49D4(player, 0, 0);
            func_800F7B9C(player, 0x8F);
            func_800F7B9C(player, 0x62);
            func_800F7C58(player, 0x61, 0);
            func_80800BDC_chclinker(arg0, func_800D211C(0x94) ? 0x137C : 0xCEC);
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 6:
            *(f32 *)((u8 *)data + 4) = 0.0f;
            func_800D2498(0x103, *(s32 *)data, 0);
            func_800D2498(0xCC, (s32)*(f32 *)((u8 *)data + 4), 0);
            break;
        case 7:
            switch (func_800D2054(1, 0x94, (s32)*(f32 *)((u8 *)data + 4))) {
            case -1:
                message = 0x137F;
                break;
            case 0:
                message = 0x137E;
                break;
            case 1:
                message = 0x137D;
                break;
            }
            func_800FC63C(0x10, -1);
            func_80800BDC_chclinker(arg0, message);
            break;
        case 8:
            func_80800BDC_chclinker(arg0, 0xCEB);
            break;
        }
        func_80101FDC(arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800BDC_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800C9C_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800D24_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800E1C_chclinker.s")

OSThread *chclinker_entrypoint_1(void)
{
    extern u8 D_80801550_chclinker[];

    return (OSThread *) D_80801550_chclinker;
}

void func_80800FFC_chclinker(s32 arg0) 
{
}
void func_80801004_chclinker(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_8080100C_chclinker.s")

void func_8080112C_chclinker(Actor *arg0) {
    s32 func_800D9078(f32 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800D1000(0x35, 1, NULL, 1, 0);
            func_80101FDC(arg0, 1);
        }
    case 2:
    case 4:
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808011A8_chclinker.s")

OSThread *chclinker_entrypoint_2(void)
{
    extern u8 D_80801598_chclinker[];

    return (OSThread *) D_80801598_chclinker;
}
