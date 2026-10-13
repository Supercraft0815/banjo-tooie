#include "common.h"

void func_80800000_chlavagargoyle(Actor *arg0) {
    struct { u8 pad[0x64]; u8 : 7; u8 flag : 1; } *flags = (void *)arg0;
    f32 func_800DC178(f32, f32);
    s32 func_80105010();
    flags->flag = 1;
    arg0->unk58 = func_800DC178(5.0f, 8.0f);
    func_80105010(arg0);
    arg0->unk54 = *(f32 *)((s8 *)arg0 + 0x48);
}

void func_80800054_chlavagargoyle(Actor *arg0) {
    struct GargoyleFlags {
        u8 pad0[0x64];
        u32 : 2;
        u32 flag64 : 1;
        u32 : 29;
        u8 pad68[0x10];
        u32 : 29;
        u32 flag78 : 1;
        u32 : 2;
    };
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800C4140(s32, f32 *, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_80102424(s32, s32);
    void *func_8010262C(Unk80132ED0 *, s32);
    void func_80108B04(Actor *, u32);
    void func_8010C908(s32, s32);
    s32 func_8080064C_chlavagargoyle(Actor *);
    extern s32 D_80800D2C_chlavagargoyle;
    void *joint;
    f32 progress;
    f32 position[3];

    func_8010C908((s32)arg0, (s32)arg0->position);
    if (!((struct GargoyleFlags *)arg0)->flag78) {
        switch (arg0->unk70_10) {
            case 3:
                break;
            case 1:
                if (((struct GargoyleFlags *)arg0)->flag64) {
                    if (func_8080064C_chlavagargoyle(arg0) && _subaddiejoy_entrypoint_6((u8 *)arg0, 1)) {
                        func_80102424((s32)arg0, 2);
                    }
                } else if (func_800D90A4(&arg0->unk58) && func_8080064C_chlavagargoyle(arg0)) {
                    func_80102424((s32)arg0, 2);
                }
                break;
            case 2:
                progress = func_80101F24(arg0);
                if (func_80101DDC(arg0)) {
                    if (((struct GargoyleFlags *)arg0)->flag64) {
                        arg0->unk58 = 4.0f;
                    } else {
                        arg0->unk58 = func_800DC178(5.0f, 8.0f);
                    }
                    func_80102424((s32)arg0, 1);
                    _subaddieaudioloop_entrypoint_2((u8 *)arg0);
                } else if (progress <= 0.35f) {
                    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, 1, 2500, &D_80800D2C_chlavagargoyle);
                    _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4(progress, 0.0f, 0.35f, 0.8f, 0.9f));
                } else if (progress >= 0.65f) {
                    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, 1, 2500, &D_80800D2C_chlavagargoyle);
                    _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4(progress, 0.65f, 1.0f, 0.9f, 0.8f));
                } else {
                    _subaddieaudioloop_entrypoint_2((u8 *)arg0);
                }
                if (func_80101E14(arg0, 0.18f) && func_8080064C_chlavagargoyle(arg0)) {
                    func_80108B04(arg0, 0);
                    func_800C4140(0xA63B5DD1, arg0->position, 0x0FA000FA);
                }
                break;
        }
    }
    joint = func_8010262C(arg0->unk0, 2);
    if (joint != NULL) {
        func_800F5A00(func_800F54E4(), position);
        arg0->unk54 = func_80013728(func_800F1DF4(arg0->position, position) - arg0->rotation[1]);
        arg0->unk54 = func_800136E4(func_800F0D50(arg0->unk54, func_80013728(-75.0f), func_80013728(75.0f)));
        arg0->unk50 = func_800F1FF0(arg0->unk50, arg0->unk54, 0.5f, 1.0f, 7.0f);
        func_800E0AFC(joint, 0x12, -1.0f, 0.0f, arg0->unk50, 0.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800394_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_8080064C_chlavagargoyle.s")

OSThread *chlavagargoyle_entrypoint_0(void)
{
    extern u8 D_80800D7C_chlavagargoyle[];

    return (OSThread *) D_80800D7C_chlavagargoyle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_808006EC_chlavagargoyle.s")

void func_8080099C_chlavagargoyle(Actor *arg0, s32 arg1) {
    struct Color { s32 values[3]; };
    extern struct Color D_80800E44_chlavagargoyle;
    s32 sp24;
    struct Color sp18;

    sp18 = D_80800E44_chlavagargoyle;
    sp24 = func_800DC128(0, 0xA);
    func_800C8CB8(arg0->unk14, arg1);
    sp18.values[0] -= sp24;
    sp18.values[1] -= sp24;
    func_800C8E84(arg0->unk14, sp18.values);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800A2C_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800B8C_chlavagargoyle.s")

void chlavagargoyle_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800ED8_chlavagargoyle;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80800ED8_chlavagargoyle);
}

OSThread *chlavagargoyle_entrypoint_2(void)
{
    extern u8 D_80800F20_chlavagargoyle[];

    return (OSThread *) D_80800F20_chlavagargoyle;
}
