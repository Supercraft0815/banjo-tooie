#include "common.h"

s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);

OSThread *chstatuebossbits_entrypoint_0(void)
{
    extern u8 D_808006F0_chstatuebossbits[];

    return (OSThread *) D_808006F0_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_1(void)
{
    extern u8 D_80800738_chstatuebossbits[];

    return (OSThread *) D_80800738_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_2(void)
{
    extern u8 D_80800780_chstatuebossbits[];

    return (OSThread *) D_80800780_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_3(void)
{
    extern u8 D_808007C8_chstatuebossbits[];

    return (OSThread *) D_808007C8_chstatuebossbits;
}

void func_80800030_chstatuebossbits(s32 arg0) 
{
}
void func_80800038_chstatuebossbits(Actor *arg0) {
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32 *);
    void func_800EA600(s32, s32);
    void func_800EA614(void);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_8010108C(Actor *, s32, s32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80109FB8(s32, volatile s32);
    void func_80800270_chstatuebossbits(Actor *);
    s32 sp3C;
    s32 sp38;
    Actor *sp34;
    s32 sp30;
    s32 sp2C;

    switch (arg0->unk70_10) {
        case 1:
            arg0->unk3C = NULL;
            func_800EA600((s32)func_80109FB8, (s32)arg0->unk0);
            sp3C = func_8010B990(arg0, 0x100005);
            func_800EA614();
            arg0->rotation[2] += func_800D8FF8() * 150.0f;
            if (sp3C != 0) {
                sp38 = 0;
                if (arg0->unk3C != NULL) {
                    sp34 = func_80106790(arg0->unk3C);
                    if (sp34->unk6C_9 == 0x449) {
                        func_8010108C(sp34, 0x40, (s32)arg0->unk0);
                        if (*(s32 *)&sp34->unk54 >= 3) {
                            sp38 = 1;
                        }
                    }
                }
                func_800EF1B8(arg0->position, arg0->rotation[1] + 180.0f, 100.0f);
                func_80800270_chstatuebossbits(arg0);
                func_8010A570(arg0);
                if (sp38 != 0) {
                    func_80101FDC(arg0, 3);
                    _subaddiefade_entrypoint_3(arg0);
                    return;
                }
                func_80101FDC(arg0, 2);
                arg0->unk58 = 1.4f;
            }
            break;
        case 2:
            sp30 = func_800D9078(&arg0->unk58);
            sp2C = func_8001210C(1) ? -1 : 1;
            arg0->rotation[0] = func_800F10B4(arg0->unk58, 0.0f, 1.4f, 0.0f, 10.0f) * (f32)sp2C;
            if (sp30 != 0) {
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
    }
}

/* extern */

s32 func_80800224_chstatuebossbits(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800FFA88(s32);
    void func_80800270_chstatuebossbits(Actor *);
    s32 ret;
    if (arg1 == 0x40) {
        func_80800270_chstatuebossbits((Actor *) arg0);
        func_800FFA88(*arg0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

void func_80800270_chstatuebossbits(Actor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800810_chstatuebossbits;
    extern s32 D_8080084C_chstatuebossbits;
    (void)&arg0;
    func_800BBCB8(arg0->position, 0, arg0->scale, 2, &D_80800810_chstatuebossbits);
    func_8010D930(4, -1, arg0->position, &D_8080084C_chstatuebossbits);
}

/* extern */

void func_808002CC_chstatuebossbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    s32 sp24;

    sp24 = func_800DA298(0x88);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    *(s32 *)&arg0->unk54 = 0;
    ((f32 *)arg0->actorData)[5] -= 180.0f;
    if (sp24 != 0) {
        func_80101FDC(arg0, 1);
        func_8010A590(arg0);
        return;
    }
    arg0->position[1] = ((f32 *)arg0->actorData)[5];
}

/* extern */

void func_80800360_chstatuebossbits(Actor *arg0) {
    u8 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_8010A590(Actor *);
    s32 sp2C;
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 != 1) && (temp_t6 != 2) && (temp_t6 == 3)) {
        sp2C = func_800D9078(&arg0->unk58);
        func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4], (f32 *)arg0->actorData, func_800F12D4(arg0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
        if (sp2C != 0) {
            func_80101FDC(arg0, 1);
            func_80103110(arg0, 0);
            func_8010A590(arg0);
        }
    }
}

/* extern */

void func_8080040C_chstatuebossbits(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    func_800DF744(1, *(s32 *)&arg0->unk54 == 0 ? 1 : 0);
    func_800DF744(2, *(s32 *)&arg0->unk54 == 1 ? 1 : 0);
    func_800DF744(3, *(s32 *)&arg0->unk54 == 2 ? 1 : 0);
    func_800DF744(4, *(s32 *)&arg0->unk54 == 3 ? 1 : 0);
    func_800DF744(5, 0);
    func_80101870(arg0, arg1);
}

s32 func_808004D8_chstatuebossbits(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80800604_chstatuebossbits(s32, s32);
    s32 func_800EC398(s32, f32 *);
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    extern s32 D_8080085C_chstatuebossbits;
    s32 sp2C;
    f32 *position;

    switch (arg1) {
    case 0x40:
        sp2C = arg2;
        (*(s32 *)&arg0->unk54)++;
        func_80800604_chstatuebossbits((s32)arg0, sp2C);
        position = (f32 *)arg0->actorData;
        if (*(s32 *)&arg0->unk54 >= 3) {
            func_800EC398(sp2C, position);
            ((f32 *)arg0->actorData)[1] = arg0->position[1];
            _chexploder_entrypoint_3(arg0, position, 0xC);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080085C_chstatuebossbits);
        }
        break;
    case 7:
        func_80101FDC(arg0, 3);
        func_80103110(arg0, 1);
        arg0->unk58 = 3.0f;
        break;
    case 0x90:
        arg0 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(arg0, 2, 0);
        _chexploder_entrypoint_9(arg0, 5, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800604_chstatuebossbits(s32 arg0, s32 arg1) {
    s32 func_800EC398(s32, f32 *);
    extern s32 D_80800864_chstatuebossbits;
    f32 sp24[3];

    func_800EC398(arg1, sp24);
    func_800BBCB8(sp24, sp24, 1.0f, 4, &D_80800864_chstatuebossbits);
}

/* extern */

void func_8080064C_chstatuebossbits(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    s32 var_v1;

    var_v1 = func_800DA298(0x88) != 0;
    if (var_v1 == 0) {
        var_v1 = _glcutDll_entrypoint_20() != 0;
    }
    if (var_v1 != 0) {
        func_80101FDC(arg0, 1);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 180.0f, 0x102, -1);
    _chdoormake_entrypoint_5(arg0, 2.0f);
    _chdoormake_entrypoint_8(arg0, 0xD);
}
