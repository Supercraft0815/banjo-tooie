#include "common.h"

OSThread *chbadbeehive_entrypoint_0(void)
{
    extern u8 D_80800B1C_chbadbeehive[];

    return (OSThread *) D_80800B1C_chbadbeehive;
}

f32 func_8080000C_chbadbeehive(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 480.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 700.0f;
    default:
        return 0.0f;
    }
}

/* extern */

void func_808000EC_chbadbeehive(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_8080000C_chbadbeehive(void);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0U);
    _subaddierouteDll_entrypoint_3(arg0, sp24, arg0->position);
    ((f32 *)arg0->actorData)[3] = 0.0f;
    ((f32 *)arg0->actorData)[5] = 0.0f;
    func_800EE7F8((f32 *)(sp24 + 0x10), arg0->position);
    ((f32 *)arg0->actorData)[6] = func_8080000C_chbadbeehive();
}

void func_80800158_chbadbeehive(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    void func_800C3CE8(u8);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    extern s32 D_80800AEC_chbadbeehive;
    extern f32 D_80800B64_chbadbeehive;
    extern f32 D_80800B74_chbadbeehive;
    s32 sp2C;
    s32 temp_v0;

    sp2C = 0;
    temp_v0 = func_801022E4(arg0);
    if (temp_v0 != 0x54) {
        if (temp_v0 == 0x1C7) {
            if ((func_80101E14(arg0, 0.48f) != 0) || (func_80101E14(arg0, 0.98f) != 0)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AEC_chbadbeehive);
            }
            if (func_80101E4C(arg0, &D_80800B74_chbadbeehive) != 0) {
                sp2C = 1;
            }
        }
    } else if (func_80101E4C(arg0, &D_80800B64_chbadbeehive) != 0) {
        sp2C = 1;
    }
    if (sp2C != 0) {
        func_800C3CE8(arg0->unk5F);
        func_800C301C(arg0->unk5F, 0x447);
        func_800C3058(arg0->unk5F, 0x2EE0);
        func_800C31DC(arg0->unk5F, func_80101F24(arg0) + 0.5f);
        func_800C35E8(arg0->unk5F, arg0->position);
        func_800C3584(arg0->unk5F, 300.0f, 1500.0f);
        func_800C330C(arg0->unk5F, 3);
        func_800C3BDC(arg0->unk5F);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_80800298_chbadbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_8080070C_chbadbeehive.s")

void func_808008F0_chbadbeehive(s32 arg0) 
{
}
void func_808008F8_chbadbeehive(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0U);
    func_80102424(arg0, arg1);
    switch (arg1) {
        case 1:
            break;
        case 2:
            ((f32 *)arg0->actorData)[5] = ((f32 *)arg0->actorData)[6];
            break;
        case 3:
            func_800EE7F8((f32 *)arg0->actorData, (f32 *)(sp24 + 0x10));
            ((f32 *)arg0->actorData)[5] *= 0.5f;
            break;
    }
}

/* extern */

s32 func_80800990_chbadbeehive(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010C9B0(arg0->position, 0x3E8) != 0) && (_suchase_entrypoint_1(arg0) != 0) && (func_8010C500(arg0) != 0)) {
        return 1;
    }
    return 0;
}
