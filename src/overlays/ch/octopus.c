#include "common.h"

OSThread *choctopus_entrypoint_0(void)
{
    extern u8 D_808008F4_choctopus[];

    return (OSThread *) D_808008F4_choctopus;
}

void func_8080000C_choctopus(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.8f);
    arg0->actorData[6] = _subaddiesect_entrypoint_1(arg0);
}

void func_80800054_choctopus(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _subaddiesect_entrypoint_0(Actor *, s32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 _suexpression_entrypoint_18(void *, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioloop_entrypoint_5(Actor *, f32 *, s32, s32, s32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101CDC(Actor *, f32);
    void func_80102424(Actor *, s32);
    extern u8 D_808008C0_choctopus[];
    extern f32 D_808008D4_choctopus;
    extern s32 D_8080093C_choctopus[];
    void *expression;
    f32 *position;

    expression = func_80100094(arg0, 1);
    _subaddiesect_entrypoint_0(arg0, arg0->actorData[6], 2);
    if (expression != NULL) {
        _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    }
    position = arg0->position;
    _subaddieaudioloop_entrypoint_5(arg0, position, arg0->unk70_10 == 1, 0x1194, D_8080093C_choctopus);
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            func_80101CDC(arg0, func_800F10B4(arg0->unk58, 0.0f, 1.25f, 30.0f, D_808008D4_choctopus));
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 3);
                arg0->unk58 = 8.0f;
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                _subaddieaudioquick_entrypoint_2(arg0, position, D_808008C0_choctopus);
                func_80102424(arg0, 4);
                func_80101CDC(arg0, 30.0f);
                arg0->unk58 = 3.75f;
            }
            break;
        case 4:
            func_80101CDC(arg0, func_800F10B4(arg0->unk58, 0.0f, 3.75f, D_808008D4_choctopus, 30.0f));
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 1);
                if (expression != NULL) {
                    _suexpression_entrypoint_18(expression, 0);
                }
                _subaddieDll_entrypoint_4(arg0, 0);
            }
            break;
    }
}

void func_808007E4_choctopus();

void func_80800210_choctopus()
{
    func_808007E4_choctopus();
}

void func_80800230_choctopus(Actor *arg0, s32 arg1) {
    s32 func_801015D0(Actor *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    void func_800DF5D8(u32, u32, u32, s32);
    extern s32 D_80800950_choctopus[][3];
    extern s32 D_80800980_choctopus[3];
    s32 value;
    s32 color[3];

    func_801015D0(arg0);
    switch (arg0->unk70_10) {
        case 2:
            value = func_800F10B4(arg0->unk58, 0.0, 1.25f, 255.0f, 0.0f);
            break;
        case 3:
            value = 255;
            break;
        case 4:
            value = func_800F10B4(arg0->unk58, 0.0, 3.75f, 0.0f, 255.0f);
            break;
        default:
            value = 0;
            break;
    }
    func_800F3214(color, D_80800950_choctopus[arg0->unk74_7 - 50], D_80800980_choctopus, (f32) value / 255.0f);
    func_800DF5D8(color[0], color[1], color[2], 255);
}

s32 func_80800348_choctopus(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80800428_choctopus(Actor *, s32);
    void func_80800790_choctopus(Actor *);
    void _subaddiecustomhits_entrypoint_0(Actor *, void *);
    extern s32 _choctopus_entrypoint_1;

    switch (arg1) {
        case 0x40:
            func_80800428_choctopus(arg0, arg2);
            break;
        case 0x1F:
            func_80800230_choctopus(arg0, arg2);
            break;
        case 0x29:
            func_80800790_choctopus(arg0);
            break;
        case 0x2A:
            func_808007E4_choctopus(arg0);
            break;
        case 0x1C:
            if (arg0->unk70_10 == 1) {
                return 2;
            }
            return 1;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(arg0, &_choctopus_entrypoint_1);
            break;
        default:
            return 0;
    }
    return 1;
}

void *func_80100094(Actor *, u32);

void func_80800428_choctopus(Actor *arg0, s32 arg1) {
    s16 func_800CB854(s32 *);
    void func_80102424(Actor *, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _suexpression_entrypoint_18(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u8 D_808008C0_choctopus[];
    extern u8 D_8080098C_choctopus[];
    s32 sp34;
    s32 sp30;
    void *sp2C;

    sp34 = arg0->unk6C_0 == 1;
    sp30 = func_800CB854(NULL) == 5;
    if (sp34 || sp30) {
        sp2C = func_80100094(arg0, 1);
        switch (arg0->unk70_10) {
            case 1:
                func_80102424(arg0, 2);
                _subaddieDll_entrypoint_4(arg0, 1);
                arg0->unk58 = 1.25f;
                if (sp2C != NULL) {
                    _suexpression_entrypoint_18(sp2C, 2);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808008C0_choctopus);
                if (!sp30) {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080098C_choctopus);
                }
                break;
            case 3:
                arg0->unk58 = 8.0f;
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800540_choctopus.s")

OSThread *choctopus_entrypoint_1(void)
{
    extern u8 D_80800998_choctopus[];

    return (OSThread *) D_80800998_choctopus;
}

void func_80800790_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_12(void*, f32, f32);
    void _suexpression_entrypoint_7(Actor*, u32, u32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1U, 0xB6U);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 80.0f, 30.0f);
    }
}

void func_808007E4_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
