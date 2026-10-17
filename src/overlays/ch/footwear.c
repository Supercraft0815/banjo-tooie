#include "common.h"

void func_80800000_chfootwear(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        s32 unk10;
        s32 unk14;
        s32 unk18;
        f32 unk1C;
    } FootwearData;
    void func_800EE7F8(f32 *, f32 *);
    void func_80800424_chfootwear(Actor *, s32);

    switch (arg0->unk6C_9) {
        case 0x21A:
            ((FootwearData *)arg0->actorData)->unk14 = 0;
            break;
        case 0x22E:
            ((FootwearData *)arg0->actorData)->unk14 = 1;
            break;
        case 0x3DB:
            ((FootwearData *)arg0->actorData)->unk14 = 2;
            break;
        case 0x16A:
            ((FootwearData *)arg0->actorData)->unk14 = 3;
            break;
        case 0x471:
            ((FootwearData *)arg0->actorData)->unk14 = 4;
            break;
    }
    func_800EE7F8(((FootwearData *)arg0->actorData)->unk0, arg0->position);
    arg0->unk50 = arg0->rotation[1];
    ((FootwearData *)arg0->actorData)->unk1C = 0.0f;
    func_80800424_chfootwear(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_808000B8_chfootwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_80800364_chfootwear.s")

void func_80800424_chfootwear(Actor *arg0, s32 arg1) {
    typedef struct {
        s32 unk0[3];
        f32 unkC;
        s32 unk10;
        s32 unk14;
        s32 unk18;
    } FootwearData;
    extern s16 D_808006E6_chfootwear[][5];
    void _fxsparkle_entrypoint_1(f32 *, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);

    switch (arg1) {
        case 1:
            _subaddieDll_entrypoint_4(arg0, 0);
            arg0->unk64_16 = 1;
            func_8010A590(arg0);
            break;
        case 2:
            func_8010A570(arg0);
            _fxsparkle_entrypoint_1(arg0->position, D_808006E6_chfootwear[((FootwearData *)arg0->actorData)->unk14][0]);
            _subaddieDll_entrypoint_4(arg0, 1);
            arg0->unk64_16 = 0;
            ((FootwearData *)arg0->actorData)->unkC = 1.0f;
            break;
        case 3:
            break;
        case 4:
            arg0->alpha = 0;
            ((FootwearData *)arg0->actorData)->unkC = 1.0f;
            break;
    }
    ((FootwearData *)arg0->actorData)->unk18 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_8080050C_chfootwear.s")

void func_80800644_chfootwear(s32 arg0, s32 arg1) { func_8080050C_chfootwear(arg0, arg1, 0); }

void func_80800664_chfootwear(s32 arg0,s32 arg1)
{
    func_8080050C_chfootwear(arg0,arg1,0x1);
}

OSThread *chfootwear_entrypoint_0(void)
{
    extern u8 D_80800788_chfootwear[];

    return (OSThread *) D_80800788_chfootwear;
}

OSThread *chfootwear_entrypoint_1(void)
{
    extern u8 D_808007D0_chfootwear[];

    return (OSThread *) D_808007D0_chfootwear;
}

OSThread *chfootwear_entrypoint_2(void)
{
    extern u8 D_80800818_chfootwear[];

    return (OSThread *) D_80800818_chfootwear;
}

OSThread *chfootwear_entrypoint_3(void)
{
    extern u8 D_80800860_chfootwear[];

    return (OSThread *) D_80800860_chfootwear;
}

OSThread *chfootwear_entrypoint_4(void)
{
    extern u8 D_808008A8_chfootwear[];

    return (OSThread *) D_808008A8_chfootwear;
}
