#include "common.h"

/* extern */

void func_80800000_chrainbow(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800270_chrainbow(s32, s32);

    func_80800270_chrainbow(arg0, func_800DA298(0x1E1) ? 0xD : 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_8080003C_chrainbow.s")

s32 func_80800270_chrainbow(s32 actor, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chglowbo_entrypoint_6(void);
    s32 _fxrain_entrypoint_7(s32);
    s32 _fxrain_entrypoint_8(s32);
    s32 _subaddieDll_entrypoint_0(Actor *);
    s32 func_800B7C54(void);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    u32 *func_80100074(Actor *, u32, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_8010A63C(Actor *);
    void func_80800440_chrainbow(Actor *);
    Actor *arg0 = (Actor *)actor;

    switch (arg1) {
    case 1:
        func_80103110(arg0, 0);
        arg0->unk64_20 = 0;
        arg0->unk64_16 = 0;
        arg0->unk58 = 0.0f;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        break;
    case 2:
        func_80800440_chrainbow(arg0);
        func_800DA524(0x9DF);
        break;
    case 3:
        func_80101180(0x2B0, 0xBB, 0xC);
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 9, 0x810);
        arg0->unk58 = 0.0f;
        break;
    case 4:
        _fxrain_entrypoint_7(func_800B7C54());
        _chglowbo_entrypoint_6();
        func_800DA544(0x580);
        break;
    case 8:
        arg0->unk64_16 = 1;
        ((f32 *)arg0->actorData)[7] = 1.0f;
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0xC, 0x4810);
        _subaddieDll_entrypoint_0(arg0);
        break;
    case 12:
        arg0->unk58 = 18.5f;
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0x5A, 0x2810);
        break;
    case 13:
        _fxrain_entrypoint_8(func_800B7C54());
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x1E1);
        func_80100074(arg0, 0, 0);
        _subaddieDll_entrypoint_0(arg0);
        func_8010A63C(arg0);
        arg0->unk64_20 = 0;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        arg0->unk58 = 20.5f;
        func_80103110(arg0, 0);
        break;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800440_chrainbow(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC70(void *, f32, f32, f32);
    void func_800EFD24(f32 *);
    u32 *func_80100074(Actor *, u32, u32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    struct RainbowPart {
        s8 active;
        f32 value;
        f32 velocity[3];
        f32 position[3];
    };
    struct RainbowPart *part;
    s32 i;
    f32 offset[3];
    f32 position[3];

    part = (struct RainbowPart *)func_80100074(arg0, 0, 0xC0);
    for (i = 0; i < 6; i++) {
        part[i].active = 1;
        func_800EFD24(part[i].velocity);
        part[i].value = 0.0f;
        func_800EEC70(offset, arg0->rotation[0], arg0->rotation[1] - 90.0f, func_80103EAC(arg0));
        position[0] = arg0->position[0] + offset[0];
        position[1] = arg0->position[1] - func_80103EF4(arg0);
        position[2] = arg0->position[2] + offset[2];
        func_800EEC70(offset, arg0->rotation[0], arg0->rotation[1] - 180.0f, arg0->scale * 800.0f * ((f32)i / 5.0f));
        func_800EE780(part[i].position, position, offset);
    }
}

void func_808005E0_chrainbow(s32 arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800FD0_chrainbow;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1 + 0x9DF);
    func_800BABB8(sp24, arg0, 0, 0x3F800000, &D_80800FD0_chrainbow);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_8080063C_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800838_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/chrainbow_entrypoint_0.s")

void func_80800CD4_chrainbow(s32 arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80800270_chrainbow(s32, s32);
    u8 *actors[3];
    s32 found;
    s32 index;

    index = _subaddiefind_entrypoint_4(0x480, &actors[0], 3) - 1;
    found = 0;
    for (; index >= 0; index--) {
        if (func_8010114C((s32)((Actor *)actors[index])->unk0, 0x4B, 0) != 0) {
            found = 1;
            break;
        }
    }
    if (found != 0) {
        func_80800270_chrainbow(arg0, 0xB);
        return;
    }
    func_80800270_chrainbow(arg0, 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800D88_chrainbow.s")

void func_80800EB4_chrainbow(Actor *arg0, void *arg1) {
    void func_800B99CC(s32, s32, s32);
    f32 func_800F1214(f32, f32, f32);
    void func_80101870(Actor *, void *);
    struct RainbowValues { s32 values[3]; } sp24;
    extern struct RainbowValues D_80801004_chrainbow;
    u32 temp_t6;

    func_80101870(arg0, arg1);
    temp_t6 = arg0->unk70_10;
    if ((temp_t6 != 1) && (temp_t6 != 0xD)) {
        sp24 = D_80801004_chrainbow;
        func_800B99CC((s32)arg1, (s32)func_800F1214(*(f32 *)&arg0->actorData[7], 0.0f, 100.0f), (s32)&sp24);
    }
}

OSThread *chrainbow_entrypoint_1(void)
{
    extern u8 D_80801010_chrainbow[];

    return (OSThread *) D_80801010_chrainbow;
}
