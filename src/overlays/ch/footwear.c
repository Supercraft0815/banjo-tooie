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

void func_808000B8_chfootwear(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        s32 unk10;
        s32 unk14;
        s32 unk18;
        f32 unk1C;
    } FootwearData;
    f32 sp3C[3];
    f32 sp30[3];
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    void func_800E3980(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F549C(s32, int);
    u32 func_800F54E4(void);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010D23C(void);
    void func_8010D254(f32 *);
    void func_8010D600(s32);
    void func_80800424_chfootwear(Actor *, s32);
    s32 func_80800644_chfootwear(s32, s32);
    extern s16 D_808006E4_chfootwear[][5];
    extern u32 D_80800754_chfootwear[];
    extern u32 D_80800768_chfootwear[];
    extern u32 D_80800774_chfootwear[];

    switch (((FootwearData *)arg0->actorData)->unk18) {
        case 1:
            switch (((FootwearData *)arg0->actorData)->unk14) {
                case 0:
                case 4:
                    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800754_chfootwear, D_80800768_chfootwear);
                    func_800EFCD8(sp3C, ((FootwearData *)arg0->actorData)->unk1C, 40.0f);
                    sp3C[1] = 0.0f;
                    func_800EE780(arg0->position, ((FootwearData *)arg0->actorData)->unk0, sp3C);
                    ((FootwearData *)arg0->actorData)->unk1C += 70.0f * func_800D8FF8();
                    arg0->rotation[1] = func_800136E4(((FootwearData *)arg0->actorData)->unk1C + 90.0f);
                    break;
                case 1:
                    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800774_chfootwear, 0.25f);
                    break;
                case 2:
                case 3:
                    if (func_8010D23C()) {
                        func_8010D254(sp30);
                    } else {
                        func_800E3980(sp30);
                    }
                    func_8010D600((s32)sp30);
                    arg0->unk54 = func_80102D78(arg0, sp30);
                    func_80102BF8(arg0, 0.1f, 3.0f, 120.0f);
                    break;
            }
            if (func_80800644_chfootwear((s32)arg0, func_800F54E4()) || _glcutDll_entrypoint_20()) {
                ((FootwearData *)arg0->actorData)->unk10 = 255;
            } else {
                ((FootwearData *)arg0->actorData)->unk10 = 120;
            }
            if (arg0->alpha < ((FootwearData *)arg0->actorData)->unk10 - 5) {
                arg0->alpha += 5;
            } else if (arg0->alpha > ((FootwearData *)arg0->actorData)->unk10 + 5) {
                arg0->alpha -= 5;
            } else {
                arg0->alpha = ((FootwearData *)arg0->actorData)->unk10;
            }
            break;
        case 2:
            if (func_800D90A4(&((FootwearData *)arg0->actorData)->unkC)) {
                func_80800424_chfootwear(arg0, D_808006E4_chfootwear[((FootwearData *)arg0->actorData)->unk14][0] ? 3 : 4);
            }
            break;
        case 3:
            if (func_800F549C(arg0->unk79_4, D_808006E4_chfootwear[((FootwearData *)arg0->actorData)->unk14][0]) == 0.0f) {
                func_80800424_chfootwear(arg0, 4);
            }
            break;
        case 4:
            if (func_800D90A4(&((FootwearData *)arg0->actorData)->unkC)) {
                func_80800424_chfootwear(arg0, 1);
            }
            break;
    }
}

s32 func_80800364_chfootwear(Actor *arg0, s32 arg1, void *volatile arg2) {
    typedef struct {
        u8 pad0[0x1A];
        u16 unk1A_5 : 11;
        u16 unk1A_0 : 5;
        u32 pad1C[2];
        u32 unk24_22 : 10;
        u32 unk24_0 : 22;
    } FootwearContact;
    FootwearContact *contact;
    s32 func_800DA298(s32);
    s32 func_80800664_chfootwear(Actor *, s32);
    void func_80800424_chfootwear(Actor *, s32);

    if (arg1 == 0x3E) {
        contact = arg2;
        if (contact->unk24_22 == 0 && func_800DA298(0x64F)) {
            if (func_80800664_chfootwear(arg0, contact->unk1A_5)) {
                arg0->unk79_4 = contact->unk1A_5;
                func_80800424_chfootwear(arg0, 2);
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

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

s32 func_8080050C_chfootwear(Actor *arg0, s32 arg1, s32 arg2) {
    void _sudialog_entrypoint_0(s32, s32);
    s32 func_800C6E38(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_800F65D0(s32);
    s32 func_800F6D24(s32);
    s32 func_800F7C0C(s32, s32, f32);
    extern s16 D_808006E0_chfootwear[][5];
    extern s16 D_808006E2_chfootwear[][5];
    extern s16 D_808006E8_chfootwear[][5];
    s16 temp_a0;

    if (!arg0->unk64_16) {
        return 0;
    }
    if (func_800F6D24(arg1) != 0) {
        return 0;
    }
    if (func_800F65D0(arg1) == 0) {
        return 0;
    }
    if (func_800C6E38(D_808006E0_chfootwear[arg0->actorData[5]][0]) == 0) {
        if (arg2 != 0) {
            temp_a0 = D_808006E8_chfootwear[arg0->actorData[5]][0];
            if (temp_a0 != 0) {
                _sudialog_entrypoint_0(temp_a0, 0xE);
            }
        }
        return 0;
    }
    if (func_800F64A4(arg1, 0x501) == 0) {
        return 0;
    }
    if ((arg2 != 0) && (func_800F7C0C(arg1, D_808006E2_chfootwear[arg0->actorData[5]][0], arg0->unk50) != 2)) {
        return 0;
    }
    return 1;
}

s32 func_80800644_chfootwear(s32 arg0, s32 arg1) { func_8080050C_chfootwear(arg0, arg1, 0); }

s32 func_80800664_chfootwear(Actor *arg0,s32 arg1)
{
    return func_8080050C_chfootwear(arg0,arg1,0x1);
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
