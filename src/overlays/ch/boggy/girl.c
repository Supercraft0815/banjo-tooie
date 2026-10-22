#include "ch/boggy/girl.h"

void *func_80100094(Actor *, u32);

OSThread *chboggygirl_entrypoint_0(void)
{
    extern u8 D_80800CF0_chboggygirl[];

    return (OSThread *) D_80800CF0_chboggygirl;
}

void func_8080000C_chboggygirl(Actor *arg0) {
    typedef struct {
        u8 unk0[8];
        u8 route[0xC];
        s16 unk14;
        s16 unk16;
        u8 item[1];
    } GirlData;
    typedef struct {
        f32 unk18[3];
        f32 unk24;
    } GirlActorData;
    s32 _chboggykids_entrypoint_0(Actor *);
    void func_800FFAB0(Actor *);
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void _subaddieitem_entrypoint_0(void *, u32, s32, s32);
    void func_8080093C_chboggygirl(Actor *);
    GirlData *sp24;

    sp24 = func_80100094(arg0, 0);
    if (_chboggykids_entrypoint_0(arg0) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    ((GirlActorData *)arg0->actorData)->unk24 = 240.0f;
    _subaddieDll_entrypoint_1(arg0);
    _subaddierouteDll_entrypoint_3(arg0, sp24->route, arg0->position);
    _subaddieitem_entrypoint_0(sp24->item, 0x3CB, 0x190, 1);
    sp24->unk14 = 0;
    func_8080093C_chboggygirl(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_808000A8_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800508_chboggygirl.s")

void func_80800708_chboggygirl(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x14];
        s16 unk14;
        u8 high : 1;
        u8 flag : 1;
        u8 low : 6;
        u8 unk17;
        u8 item[1];
    } GirlData;
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void _subaddieitem_entrypoint_2(void *);
    void func_800C01A8(s16, s32);
    void func_800C0850(void);
    void func_800DA544(s32);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(Actor *, s32);
    void func_80102924(void *, f32);
    void func_80800A4C_chboggygirl(Actor *);
    s32 func_80800B5C_chboggygirl(s32);
    extern s32 D_80800C50_chboggygirl;
    GirlData *sp2C;

    sp2C = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x1090:
        func_80102424(arg0, 5);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_800DA544(0x8D);
        func_80800A4C_chboggygirl(arg0);
        func_80101180(0x13F, 0x23, 0);
        break;
    case 0x108F:
        func_80102924(arg0, arg0->rotation[1] + 180.0f);
        func_80102424(arg0, 3);
        sp2C->unk14 = 0;
        break;
    case 0x108E:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x108B, 0x4E, arg0->position, 0x3C);
        break;
    case 0x108B:
        if (arg2 > 0) {
            func_80102424(arg0, 0xF);
            _subaddieitem_entrypoint_2(sp2C->item);
        } else {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x108F, 0xE, arg0->position, 0x3C);
        }
        break;
    case 0x1098:
    case 0x1099:
        sp2C->flag = 0;
        break;
    default:
        switch (_subaddiedialog_entrypoint_9(arg0, arg1, &D_80800C50_chboggygirl, 3)) {
        case 1:
            func_800DA544(0xB9);
            if (func_80800B5C_chboggygirl(0x3CB)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x108E, 0xE, arg0->position, 0x3C);
                break;
            }
            func_800C01A8(0x64, 0);
            func_800C0850();
        case 2:
            func_80102924(arg0, arg0->rotation[1] + 180.0f);
            func_80102424(arg0, 3);
            sp2C->unk14 = 0;
            break;
        default:
            func_80102424(arg0, 1);
            break;
        }
        break;
    }
}

void func_8080091C_chboggygirl(Actor* arg0)
{
    func_80800B28_chboggygirl(arg0);
}

void func_8080093C_chboggygirl(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32 *);
    void func_800EE940(void *, f32 *);
    void *sp24;
    f32 sp18[3];

    sp24 = func_80100094(arg0, 0U);
    ((s16 *)sp24)[3] = _glsplinefind_entrypoint_0(0x3A1U, sp18);
    func_800EE940(sp24, sp18);
}

void func_8080097C_chboggygirl(Actor *arg0) {
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    struct Flags {
        u8 pad[0x14];
        u32 high : 17;
        u32 flag : 1;
        u32 low : 14;
    };
    struct Flags *sp24;
    struct Flags *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    if (arg0->unk70_10 == 0x10) {
        if (!temp_v0->flag) {
            func_800FFAB0(arg0);
        }
    } else {
        func_80105834(arg0);
        _sudeflect_entrypoint_0(arg0->position, 100.0f, 50.0f, 0xA);
        func_80105230(arg0, 0);
        if (func_80105A5C(arg0) != 0) {
            if (sp24->flag) {
                func_80102424(arg0, 0x10);
                arg0->unk64_16 = 0;
                return;
            }
            func_800FFAB0(arg0);
        }
    }
}

void func_80800A4C_chboggygirl(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA980(s32, s32);
    struct Flags { u8 pad[0x16]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    struct Flags *data;
    s32 dialog;

    dialog = (func_800DA980(0x8C, 3) == 3) ? 0x1099 : 0x1098;
    _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xF, arg0->position, 0x3C);
    data = func_80100094(arg0, 0);
    data->flag = 1;
}

/* extern */

void func_80800ABC_chboggygirl(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3C);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800B28_chboggygirl(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

s32 func_80800B5C_chboggygirl(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, arg0) > 0;
}
