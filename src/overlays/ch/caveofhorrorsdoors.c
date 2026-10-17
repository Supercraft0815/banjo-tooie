#include "common.h"

OSThread *chcaveofhorrorsdoors_entrypoint_0(void)
{
    extern u8 D_808001C0_chcaveofhorrorsdoors[];

    return (OSThread *) D_808001C0_chcaveofhorrorsdoors;
}

/* extern */

void func_8080000C_chcaveofhorrorsdoors(s32 arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80109EEC(s32, s32);
    s32 func_8010A63C(s32);
    s32 func_808001A4_chcaveofhorrorsdoors(s32);
    if (func_800DA298(func_808001A4_chcaveofhorrorsdoors(arg0)) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_80109EEC(arg0, 0x40);
    _subaddiefade_entrypoint_14(arg0);
    func_8010A63C(arg0);
}

s32 func_8080006C_chcaveofhorrorsdoors(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F8300(s32, s32, s32);
    void func_80800144_chcaveofhorrorsdoors(s32);
    f32 sp2C[3];

    switch (arg1) {
    case 0x40:
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] += 150.0f;
        func_800EF1B8(sp2C, arg0->rotation[1], -80.0f);
        _chexploder_entrypoint_3(arg0, sp2C, 7);
        if ((s32)arg0->unk74_7 < 0x34) {
            func_800F8300(func_800F54E4(), 2, (s32)arg0->position);
        }
        break;
    case 0x90:
        func_80800144_chcaveofhorrorsdoors((s32)arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800144_chcaveofhorrorsdoors(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 func_800C4AF0(s32, s32 *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 func_808001A4_chcaveofhorrorsdoors(s32);
    extern s32 D_80800208_chcaveofhorrorsdoors;
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800C4AF0(arg0 + 4, &D_80800208_chcaveofhorrorsdoors);
    func_800DA544(func_808001A4_chcaveofhorrorsdoors(arg0));
    func_800FFAB0(arg0);
}

s32 func_808001A4_chcaveofhorrorsdoors(s32 arg0) {
    return ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x65;
}
