#include "common.h"

/* extern */

void func_80800000_chfoodwarn(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_1(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg1 + 0x521, arg0 + 4), arg2);
}

void func_8080003C_chfoodwarn(s32 arg0) {
    func_80800000_chfoodwarn(arg0, 0, arg0 + 0x28);
    func_80800000_chfoodwarn(arg0, 1, arg0 + 0x18);
}

/* extern */

s32 func_80800074_chfoodwarn(s32 arg0, s32 arg1) {
    f32 func_800EFC7C(f32 *, f32 *);
    if (func_800EFC7C((f32 *)arg1, (f32 *)(arg0 + 0x28)) < func_800EFC7C((f32 *)arg1, (f32 *)(arg0 + 0x18))) {
        return 1;
    }
    return 0;
}

void func_808000D4_chfoodwarn(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800D1A04(s32);
    s32 func_8010C500(Actor *);
    void func_8010D254(f32 *);
    extern s32 D_80800270_chfoodwarn;
    extern s32 D_8080028C_chfoodwarn;
    f32 sp34[3];
    s32 sp30;
    s32 temp_v0;
    s32 sp28;
    s32 temp_v1;

    temp_v1 = func_800D1A04(0x4B) != 0;
    sp28 = temp_v1;
    if (temp_v1 == 0) {
        sp28 = func_800D1A04(0x4C) != 0;
    }
    func_8010D254(sp34);
    temp_v0 = func_8010C500(arg0);
    sp30 = temp_v0;
    if ((temp_v0 != 0) && !arg0->unk6C_0) {
        arg0->unk64_20 = func_80800074_chfoodwarn((s32)arg0, (s32)sp34);
    }
    if (sp30 != 0) {
        if (arg0->unk64_20 && !arg0->unk6C_0 && (sp28 != 0)) {
            *(s16 *)&D_80800270_chfoodwarn = arg0->unk74_7 + 0x541;
            _subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0 + 4, &D_80800270_chfoodwarn);
        } else {
            _subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0 + 4, &D_8080028C_chfoodwarn);
        }
    }
    arg0->unk6C_0 = sp30;
}

/* extern */

s32 func_808001F4_chfoodwarn(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80105010();
    s32 func_8010C500(Actor *);
    if (arg1 != 0x2E) {
        if (arg1 == 0x95) {
            func_80105010();
            arg0->unk6C_0 = func_8010C500(arg0);
            goto block_4;
        }
        return 0;
    }
block_4:
    return 1;
}

OSThread *chfoodwarn_entrypoint_0(void)
{
    extern u8 D_808002A8_chfoodwarn[];

    return (OSThread *) D_808002A8_chfoodwarn;
}
