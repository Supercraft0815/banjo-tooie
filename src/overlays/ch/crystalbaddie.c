#include "common.h"

OSThread *chcrystalbaddie_entrypoint_0(void)
{
    extern u8 D_80800664_chcrystalbaddie[];

    return (OSThread *) D_80800664_chcrystalbaddie;
}

/* extern */

void func_8080000C_chcrystalbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void *func_80100094(Actor *, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0), (f32 *)((s8 *)arg0 + 4));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
}

void func_80800054_chcrystalbaddie(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    int func_800DC298(f32);
    f32 func_800F15F8(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D254(f32 *);
    void func_808003C4_chcrystalbaddie(Actor *, s32);
    s32 func_80800424_chcrystalbaddie(Actor *);
    void func_808004B4_chcrystalbaddie(s32);
    extern u32 D_808006AC_chcrystalbaddie[];
    struct {
        u16 pad0[3];
        u16 unk6;
        u32 unk8;
        u32 unkC;
    } *route;
    f32 sound;

    route = func_80100094(arg0, 0);
    func_8010D254((f32 *)arg0->actorData);
    func_800D9078(&arg0->unk58);
    switch (arg0->unk70_10) {
    case 1:
        if (arg0->unk64_29) {
            func_808003C4_chcrystalbaddie(arg0, 2);
        } else if (func_80800424_chcrystalbaddie(arg0)) {
            func_808003C4_chcrystalbaddie(arg0, 2);
        }
        break;
    case 2:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808006AC_chcrystalbaddie, 0.0f);
        if (func_80101DDC(arg0)) {
            func_808003C4_chcrystalbaddie(arg0, 3);
        }
        break;
    case 3:
        if (arg0->unk64_29) {
            sound = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
            ((f32 *)arg0->actorData)[3] = ((f32 *)arg0->actorData)[5];
            func_80102BF8(arg0, 0.2f, 8.0f, 500.0f);
            func_8010C3A8(arg0, 0x205015, sound);
        } else {
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                _subaddierouteDll_entrypoint_7(arg0, route, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
                route->unkC = route->unk6;
            }
            _subaddierouteDll_entrypoint_5(arg0, route, route->unkC, 0.15f, 8.0f, 200.0f);
            ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], func_800D8FF8() * 400.0f);
            func_8010B990(arg0, 0x305115);
            if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) &&
                (!func_8010C9B0(arg0->position, 1200) || !func_8010C500(arg0))) {
                func_808003C4_chcrystalbaddie(arg0, 4);
            }
        }
        func_808004B4_chcrystalbaddie((s32)arg0);
        break;
    case 4:
        if (func_80101DDC(arg0)) {
            func_808003C4_chcrystalbaddie(arg0, 1);
            arg0->unk58 = 1.4f;
        }
        break;
    }
}

s32 func_808002E0_chcrystalbaddie(Actor *arg0, s32 arg1, s32 *arg2) {
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_80107070(Actor *, s32);
    void func_808004D4_chcrystalbaddie(Actor *, s32 *);
    void func_8080052C_chcrystalbaddie(s32);
    s32 **data = &arg2;

    switch (arg1) {
    case 0x90:
        func_8080052C_chcrystalbaddie((s32)arg0);
        break;
    case 0x40:
        func_808004D4_chcrystalbaddie(arg0, arg2);
        break;
    case 2:
        if (_subaddieDll_entrypoint_3(arg0) == 0) {
            func_80107070(arg0, 1);
        }
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800384_chcrystalbaddie(s32 arg0) 
{
}
/* extern */

void func_8080038C_chcrystalbaddie(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_80101870(arg0, arg1);
}

/* extern */

void func_808003C4_chcrystalbaddie(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    void func_80102424(Actor *, s32);
    func_80102424(arg0, arg1);
    if ((arg1 != 1) && (arg1 == 3)) {
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = func_800DC178(400.0f, 450.0f);
        (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    }
}

/* extern */

s32 func_80800424_chcrystalbaddie(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010C9B0(arg0->position, 0x4B0) != 0) && (_suchase_entrypoint_1(arg0) != 0) && (func_8010C500(arg0) != 0)) {
        return 1;
    }
    return 0;
}

void func_808004B4_chcrystalbaddie(s32 arg0)
{
    func_80105230(arg0,0);
}

/* extern */

void func_808004D4_chcrystalbaddie(Actor *arg0, s32 *arg1) {
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    s32 _chexploder_entrypoint_4(void *, s32, s32);
    _subaddiejoy_entrypoint_10(arg0, 1.0f, 0.3f);
    _chexploder_entrypoint_4(arg0, *arg1 + 4, 4);
    (*(u8 *)((s8 *)(arg0) + 0x64)) = (u8)((*(u8 *)((s8 *)(arg0) + 0x64)) & 0xFFFE);
}

void func_8080052C_chcrystalbaddie(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 _chexploder_entrypoint_14(s32, s32);
    s32 _chexploder_entrypoint_15(s32, s32, s32);
    s32 _chexploder_entrypoint_9(s32, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    s32 func_800FFAB0(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 func_80107070(Actor *, s32);
    extern s32 D_808006BC_chcrystalbaddie;
    extern s32 D_808006CC_chcrystalbaddie;
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12(temp_v0, 0x14);
    _chexploder_entrypoint_14(temp_v0, 3);
    _chexploder_entrypoint_9(temp_v0, 2, 0);
    _chexploder_entrypoint_9(temp_v0, 3, 2);
    _chexploder_entrypoint_15(temp_v0, 2, 0x3F000000);
    temp_a0 = temp_v0 + 0x18;
    func_800BBCB8(temp_a0, temp_a0, 0x3F800000, 4, &D_808006CC_chcrystalbaddie);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_808006BC_chcrystalbaddie);
    if (func_80107070(arg0, 3) == 0) {
        func_800FFAB0(arg0);
    }
}
