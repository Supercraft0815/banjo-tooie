#include "common.h"

void func_80800000_indrv_fx(Unk80132ED0 *arg0, s32 arg1, f32 arg2, s32 arg3, s32 *arg4) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800EE88C(f32 *, s16 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp24[3];
    Actor *actor;

    actor = func_80106790(arg0);
    if (actor->unk7C_12 || arg1 == -1) {
        if (arg1 != -1) {
            func_800DBEFC((s32 *)arg0->unk4, arg1, sp24);
        } else {
            func_800EE88C(sp24, (s16 *)(arg0->unk0 + 1));
        }
        func_800BBCB8(sp24, sp24, arg2, arg3, arg4);
    } else if (arg1 != -1) {
        return;
    }
}

void indrv_fx_entrypoint_0(Unk80132ED0 *arg0, u32 arg1, s32 arg2) {
    void func_80800000_indrv_fx(Unk80132ED0 *, s32, f32, s32, s32 *);
    extern s32 D_808005B0_indrv_fx;
    extern s32 D_80800608_indrv_fx;
    extern s32 D_80800648_indrv_fx;
    extern s32 D_80800684_indrv_fx;
    extern s32 D_808006E4_indrv_fx;
    extern s32 D_80800720_indrv_fx;
    extern s32 D_80800780_indrv_fx;
    extern s32 D_808007E0_indrv_fx;
    extern s32 D_80800818_indrv_fx;
    extern s32 D_80800870_indrv_fx;
    extern s32 D_808008C0_indrv_fx;
    extern s32 D_80800920_indrv_fx;
    extern s32 D_80800964_indrv_fx;
    extern s32 D_808009A8_indrv_fx;
    extern s32 D_808009F4_indrv_fx;
    extern s32 D_80800A4C_indrv_fx;
    extern s32 D_80800AA4_indrv_fx;
    extern s32 D_80800AFC_indrv_fx;
    extern s32 D_80800B2C_indrv_fx;
    extern s32 D_80800B5C_indrv_fx;
    extern s32 D_80800BA0_indrv_fx;
    extern s32 D_80800BE8_indrv_fx;
    extern s32 D_80800C3C_indrv_fx;
    extern s32 D_80800CA4_indrv_fx;
    extern s32 D_80800CF0_indrv_fx;
    extern s32 D_80800D30_indrv_fx;
    extern s32 D_80800D6C_indrv_fx;
    extern s32 D_80800DBC_indrv_fx;
    extern s32 D_80800E0C_indrv_fx;
    extern s32 D_80800E5C_indrv_fx;
    extern s32 D_80800EAC_indrv_fx;
    switch (arg1) {
    case 0:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 2, &D_808005B0_indrv_fx);
        return;
    case 1:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 5, &D_80800608_indrv_fx);
        return;
    case 2:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 5, &D_80800648_indrv_fx);
        return;
    case 3:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800684_indrv_fx);
        return;
    case 4:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 4, &D_808006E4_indrv_fx);
        return;
    case 5:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800720_indrv_fx);
        return;
    case 10:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800780_indrv_fx);
        return;
    case 6:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 3, &D_808007E0_indrv_fx);
        return;
    case 7:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 6, &D_80800818_indrv_fx);
        return;
    case 8:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800870_indrv_fx);
        return;
    case 9:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_808008C0_indrv_fx);
        return;
    case 11:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800920_indrv_fx);
        return;
    case 12:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800964_indrv_fx);
        return;
    case 13:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_808009A8_indrv_fx);
        return;
    case 14:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 2, &D_808009F4_indrv_fx);
        return;
    case 15:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 2, &D_80800A4C_indrv_fx);
        return;
    case 16:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 3, &D_80800AA4_indrv_fx);
        return;
    case 17:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800AFC_indrv_fx);
        return;
    case 18:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800B2C_indrv_fx);
        return;
    case 19:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800B5C_indrv_fx);
        return;
    case 20:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x1E, &D_80800BA0_indrv_fx);
        return;
    case 21:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 6, &D_80800BE8_indrv_fx);
        return;
    case 22:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800C3C_indrv_fx);
        return;
    case 23:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800CA4_indrv_fx);
        return;
    case 24:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800CF0_indrv_fx);
        return;
    case 25:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 1, &D_80800D30_indrv_fx);
        return;
    case 26:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800D6C_indrv_fx);
        return;
    case 27:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800DBC_indrv_fx);
        return;
    case 28:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800E0C_indrv_fx);
        return;
    case 29:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800E5C_indrv_fx);
        return;
    case 30:
        func_80800000_indrv_fx(arg0, arg2, 1.0f, 0x20, &D_80800EAC_indrv_fx);
        /* fallthrough */
    default:
        return;
    }
}
