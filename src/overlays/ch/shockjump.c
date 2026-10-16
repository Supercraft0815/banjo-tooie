#include "common.h"

OSThread *chshockjump_entrypoint_0(void)
{
    extern u8 D_808002B0_chshockjump[];

    return (OSThread *) D_808002B0_chshockjump;
}

OSThread *chshockjump_entrypoint_1(void)
{
    extern u8 D_808002F8_chshockjump[];

    return (OSThread *) D_808002F8_chshockjump;
}

s32 func_80800018_chshockjump(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800F7B9C(s32, u32);
    s32 _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 _chexploder_entrypoint_7(Actor *, f32, f32);
    Actor *actor;

    switch (arg1) {
    case 0x90:
        actor = func_80106790(func_80101080());
        _chexploder_entrypoint_6(actor, 400.0f, 600.0f);
        _chexploder_entrypoint_7(actor, -600.0f, -400.0f);
        break;
    case 0x91:
        func_800F7B9C(arg2, 0x49U);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808000AC_chshockjump(s32 arg0, s32 arg1, s32 arg2) {
    void func_800F7B9C(s32, u32);
    switch (arg1) {
    case 0x91:
        func_800F7B9C(arg2, 0x4AU);
        break;
    default:
        return 0;
    }
    return 1;
}

void chshockjump_entrypoint_2(Unk80132ED0 *arg0) {
    s32 _chexploder_entrypoint_5(u8 *, s32, u8 *, s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800340_chshockjump;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80106790(arg0);
    sp24 = temp_v0;
    _chexploder_entrypoint_5(temp_v0, 0x756, temp_v0 + 4, (*(s32 *)((s8 *)(temp_v0) + (0x48))), (*(f32 *)((s8 *)(temp_v0) + (0x38))), 0xC);
    _subaddieaudioquick_entrypoint_2(sp24, sp24 + 4, &D_80800340_chshockjump);
}

/* extern */

void func_80800148_chshockjump(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_8(Actor *, s32);
    int func_800C6E38(s32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_80101870(void *, s32);
    s32 var_a0;
    s32 sp18;
    s32 var_a1;

    sp18 = _subaddiefade_entrypoint_0(arg0);
    var_a0 = arg0->unk6C_9 == 0x210 ? 0xD : 9;
    if ((func_800C6E38(var_a0) != 0) && (func_800F64A4(func_800F54E4(), 0x401) != 0)) {
        var_a1 = (s32) func_800F15F8((f32) sp18, 255.0f, 5.0f);
    } else {
        var_a1 = (s32) func_800F15F8((f32) sp18, 90.0f, 5.0f);
    }
    _subaddiefade_entrypoint_8(arg0, var_a1);
    func_80101870(arg0, arg1);
}

/* extern */

void func_80800228_chshockjump(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    void _subaddiesect_entrypoint_2(Actor *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80102E08(void *);
    u32 func_8010A654(Actor *, s32);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1(arg0);
    arg0->actorData[4] = temp_v0;
    if (temp_v0 == -1) {
        if (arg0->unk74_7 != 0x33) {
            func_80102E08(arg0);
        }
    } else {
        _subaddiesect_entrypoint_2(arg0, arg0->actorData[4], arg0->unk74_7 != 0x33);
    }
    func_8010A654(arg0, func_800DA298(0x661));
}
