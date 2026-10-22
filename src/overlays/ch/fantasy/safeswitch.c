#include "common.h"

void func_80800000_chfantasysafeswitch(Actor *arg0) {
    void func_80103110(Actor*, u32);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
    func_80103110(arg0, 0U);
}

void func_8080002C_chfantasysafeswitch(Actor *arg0) {
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    if (arg0->unk70_10 == 2 && func_80101DDC(arg0) != 0) {
        func_80102424(arg0, 3);
    }
}

s32 func_80800070_chfantasysafeswitch(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_6(u32, u32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80101180(s32, s32, s32);
    s32 func_801015D0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    Actor *other;
    f32 sp30[3];
    f32 sp24[3];

    switch (arg1) {
    case 0x40:
        if (arg0->unk70_10 == 1) {
            other = _subaddiefind_entrypoint_2(0x2B2, 0);
            if (other != NULL) {
                func_800EE7F8(sp30, other->position);
                func_800EFA4C(sp24, arg0->position[0], arg0->position[1] + 40.0f, arg0->position[2]);
                if (func_800C6A7C(sp30, sp24, (f32 *)&arg0->actorData[4], 0) != NULL) {
                    return 0;
                }
            }
            func_80102424(arg0, 2);
            func_80103110(arg0, 1);
            arg0->unk64_20 = 1;
        }
        return 1;
    case 0x39:
        if (arg0->unk64_20) {
            if (func_800EA05C() == 0x13A) {
                func_80101180(0x417, 0x49, arg0->unk74_7 + 0x1F);
            } else {
                _glcutDll_entrypoint_6(0x13A, arg0->unk74_7 + 0x1F);
            }
            arg0->unk64_20 = 0;
            func_80102424(arg0, 3);
            return 1;
        }
        return 0;
    case 0x95:
        if (func_800DA298(arg0->unk74_7 + 0x357)) {
            func_80102424(arg0, 3);
            return 1;
        }
        func_80102424(arg0, 1);
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(1, arg0->unk74_7 - 0x31);
        return 1;
    default:
        return 0;
    }
}

OSThread *chfantasysafeswitch_entrypoint_0(void)
{
    extern u8 D_80800288_chfantasysafeswitch[];

    return (OSThread *) D_80800288_chfantasysafeswitch;
}
