#include "ch/alienkids.h"

OSThread *chalienkids_entrypoint_0(void)
{
    extern u8 D_808020DC_chalienkids[];

    return (OSThread *) D_808020DC_chalienkids;
}

OSThread *chalienkids_entrypoint_1(void)
{
    extern u8 D_80802124_chalienkids[];

    return (OSThread *) D_80802124_chalienkids;
}

OSThread *chalienkids_entrypoint_2(void)
{
    extern u8 D_8080216C_chalienkids[];

    return (OSThread *) D_8080216C_chalienkids;
}

OSThread *chalienkids_entrypoint_3(void)
{
    extern u8 D_808021B4_chalienkids[];

    return (OSThread *) D_808021B4_chalienkids;
}

/* extern */

void func_80800030_chalienkids(s32 arg0) {
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x32, 0x372, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800058_chalienkids.s")

/* extern */

void func_8080017C_chalienkids(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_8010A85C(u8 *, s32);
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x33, 0x373, 6);
    if ((func_800DA298(0x373) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_8010A85C((u8 *) arg0, 2);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808001D0_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800370_chalienkids.s")

/* extern */

void func_80800408_chalienkids(u8 *arg0) {
    void func_8010A63C(void ***);
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x34, 0x374, 9);
    if (((Actor *) arg0)->unk70_10 == 9) {
        func_8010A63C((void ***) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800454_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800648_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800D58_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800DB8_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800FA4_chalienkids.s")

void func_80801138_chalienkids(Actor* arg0)
{
    func_80801994_chalienkids(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801158_chalienkids.s")

void *func_80100094(Actor *, u32);

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x74];
        u32 pad74_6 : 26;
        u32 unk74_5 : 1;
        u32 pad74_0 : 5;
    } flags;
} AlienKidsActor;

void func_808014B0_chalienkids(AlienKidsActor *arg0, s32 arg1) {
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80103014(u8 *);
    s32 func_80104E78(Actor *);
    f32 *data;

    data = func_80100094(&arg0->actor, 0);
    func_800EE7F8(arg0->actor.position, data);
    arg0->actor.rotation[1] = data[4];
    arg0->flags.unk74_5 = 1;
    func_80103014((u8 *)arg0);
    func_80104E78(&arg0->actor);
    func_800DA544(arg1);
}

/* extern */

void func_80801520_chalienkids(void *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiefade_entrypoint_2();
    s32 func_80102424(void *, s32);
    s32 func_8010A3E8(void *, s32);
    void func_808014B0_chalienkids(AlienKidsActor *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 2.0f;
    _subaddiefade_entrypoint_2();
    _subaddieDll_entrypoint_4(arg0, 1);
    func_8010A3E8(arg0, 0x3F19999A);
    func_80102424(arg0, 0xD);
    func_808014B0_chalienkids(arg0, arg1);
}

/* extern */

void func_8080158C_chalienkids(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void func_8008FB58(f32 *, f32, f32);
    f32 func_80103EAC(Actor *);
    f32 func_8010A40C(void *);
    u32 func_8010A698(void ***);
    f32 sp2C[3];
    f32 sp28;
    f32 sp24;

    sp24 = func_80103EAC(arg0);
    sp28 = func_8010A40C(arg0) * sp24;
    if (arg0->unk64_16) {
        if (func_8010A698(arg0) == 0) {
            if (_subaddieskeleton_entrypoint_0(arg0, 3, sp2C) != 0) {
                func_8008FB58(sp2C, 0.5f * sp28, sp28);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801628_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808016D4_chalienkids.s")

void func_8080184C_chalienkids(s32 arg0, s32 *arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_8080226C_chalienkids;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_8080226C_chalienkids, arg1, arg2);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801884_chalienkids.s")

/* extern */

void func_8080193C_chalienkids(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0xB7);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x3E8);
    }
}

void func_80801994_chalienkids(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

void func_808019C8_chalienkids(Actor *arg0) {
    s32 _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
    s32 _suexpression_entrypoint_18(void *, s32);
    s32 func_801022E4(Actor *);
    void *sp1C;
    s32 temp_v0_2;
    void *temp_v0;

    if ((*(u16 *)((s8 *)(arg0) + (0x64))) & 1) {
        temp_v0 = func_80100094(arg0, 1U);
        sp1C = temp_v0;
        if (temp_v0 != NULL) {
            temp_v0_2 = func_801022E4(arg0);
            switch (temp_v0_2) {
            case 0x325:
            case 0x326:
            case 0x329:
            case 0x32C:
            case 0x32E:
                break;
            default:
            case 0x327:
            case 0x328:
            case 0x32A:
            case 0x32B:
            case 0x32D:
                _suexpression_entrypoint_18(sp1C, 1);
                break;
            }
            _suexpression_entrypoint_10(sp1C, arg0->unk0, 0);
        }
    }
}

void func_80801A50_chalienkids(u8 *arg0) {
    void func_80109F08(void *arg0, s32 arg1);
    func_80109F08(arg0, 0x44);
    (*(u8 *)((s8 *)(arg0) + (0x7A))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x7A))) & 0xFF3F) | 0x80);
}

/* extern */

void func_80801A88_chalienkids(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _subaddieDll_entrypoint_6(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A570(Actor *);
    f32 sp24[3];

    if ((arg0->unk70_10 == 2) && (_subaddieDll_entrypoint_6(arg0, 0xA) != 0)) {
        func_8010A570(arg0);
        func_800EE7F8(sp24, arg0->position);
        sp24[1] -= 100.0f;
        _chexploder_entrypoint_3(arg0, sp24, 0);
    }
}

/* extern */

void func_80801B08_chalienkids(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_80101870(arg0, arg1);
}

s32 func_80801B40_chalienkids(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_5(Actor *, s32);
    void func_80103110(void *, s32);
    void func_80101FDC(Actor *, u32);
    void func_80801BC4_chalienkids(u8 *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(arg0, arg2) != 0) {
                func_80103110(arg0, 1);
                func_80101FDC(arg0, 2);
                return 0;
            }
            break;
        case 0x90:
            func_80801BC4_chalienkids((u8 *)arg0);
            return 0;
        default:
            return 0;
    }
    return 0;
}

void func_80801BC4_chalienkids(u8 *arg0) {
    s32 _chexploder_entrypoint_9(s32, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0(u8 *);
    s32 func_80101080();
    s32 func_8010114C(s32, s32, s32);
    s32 func_80106790(s32);
    extern s32 D_80802284_chalienkids;
    s32 temp_a0;

    _chexploder_entrypoint_9(func_80106790(func_80101080()), 3, 2);
    func_8010114C((*(s32 *)((s8 *)(arg0) + (0x3C))), 0xA, 0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80802284_chalienkids);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a0 != 0) {
        func_800DA544(temp_a0);
    }
    func_800FFAB0(arg0);
}
