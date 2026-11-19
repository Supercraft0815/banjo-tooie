#include "common.h"
BT_NATIVE_ONLY(s32 func_80103140(Actor *, u32, u16);)

OSThread *chbottlesparty_entrypoint_0(void)
{
    extern ActorData D_80800410_chbottlesparty[];

    return (OSThread *) D_80800410_chbottlesparty;
}

OSThread *chbottlesparty_entrypoint_1(void)
{
    extern ActorData D_80800458_chbottlesparty[];

    return (OSThread *) D_80800458_chbottlesparty;
}

/* extern */

void func_80800018_chbottlesparty(BtIntPtr arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_8010A800(void **arg0, s32 arg1);
    if (func_800DA298(0x3B) == 0) {
        func_800FFAB0((Actor *)arg0);
        return;
    }
    func_8010A800(arg0, 0);
}

void func_8080022C_chbottlesparty(BtIntPtr);
void func_8080005C_chbottlesparty(BtIntPtr arg0) { void func_80800170_chbottlesparty(BtIntPtr); func_8080022C_chbottlesparty(arg0); if (((Actor *)arg0)->unk70_10 == 1) { func_80800170_chbottlesparty(arg0); } }

s32 func_8080009C_chbottlesparty(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void func_80101FDC(Actor *, u32);
    void func_80800138_chbottlesparty(Actor *);
    extern s32 D_808004A0_chbottlesparty[4];

    switch (arg1) {
    case 0x2E:
        *(f32 *)&arg0->actorData[4] = 6.0f;
        func_80101FDC(arg0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808004A0_chbottlesparty, arg0->scale);
        break;
    case 0x95:
        func_80800138_chbottlesparty(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800138_chbottlesparty(Actor *arg0) {
    if ((u32) arg0->unk74_7 == 0x32) {
        func_80103140(arg0, 0x653U, 0U);
    }
}

void func_80800170_chbottlesparty(BtIntPtr arg) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_7(Actor *, f32 *, s32 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80101FDC(Actor *, u32);
    s32 func_8010CAC0(f32 *, u32);
    extern s32 D_808004B0_chbottlesparty[7];
    Actor *arg0 = (Actor *)arg;
    if (func_800DA298(0x43) == 0) {
        if (func_800DA298(0x67C) == 0) {
            _subaddiedialog_entrypoint_7(arg0, arg0->position, D_808004B0_chbottlesparty);
            return;
        }
        if ((func_800F64A4(func_800F54E4(), 0x601) != 0) && (func_8010CAC0(arg0->position, 0x1F4) != 0) && (func_800D90A4((f32 *)&arg0->actorData[4]) != 0)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x154F, 4, 0, 0xF);
            func_80101FDC(arg0, 2);
        }
    }
}

void func_8080022C_chbottlesparty(BtIntPtr arg0) 
{
}
void func_80800234_chbottlesparty(Actor *arg0) {
    void func_800FFAB0(Actor *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    f32 delay;
    s32 handle;

    if ((func_800DA298(0x3B) == 0) || (func_800DA298(0x43) != 0)) {
        func_800FFAB0(arg0);
        return;
    }
    delay = func_800DC178(0.4f, 0.6f);
    *(f32 *)&arg0->actorData[5] = delay;
    arg0->unk58 = func_800DC178(0.0f, delay);
    arg0->unk6C_0 = arg0->unk74_7 - 0x32;
    if (arg0->unk6C_0 >= 5U) {
        arg0->unk6C_0 = 0;
    }
    handle = func_800C8A98();
    arg0->actorData[4] = handle;
    func_800C8E54(handle, arg0->scale * 300.0f, arg0->scale * 600.0f);
    func_800C8CB8(arg0->actorData[4], arg0->position);
}

void func_80800330_chbottlesparty(Actor *arg0) {
    void func_800C8E84(s32, u32[3]);
    f32 func_800D8FF8(void);
    f32 func_800F0F9C(f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    f32 func_800F3780(f32, u8 *, s16);
    void func_80103DFC(Actor *, f32 *);
    extern s32 D_808004CC_chbottlesparty[][3];
    extern s32 D_808004FC_chbottlesparty[3];
    extern f32 D_80800508_chbottlesparty[3][2];
    u32 sp3C[3];
    f32 sp30[3];
    f32 delta;
    f32 sp28;

    if (arg0->actorData[4] != 0) {
        sp28 = func_800F3780(func_800F0F9C(arg0->unk58, *(f32 *)&arg0->actorData[5]), (u8 *)D_80800508_chbottlesparty, 3);
        func_80103DFC(arg0, sp30);
        func_800F3214(sp3C, D_808004FC_chbottlesparty, D_808004CC_chbottlesparty[arg0->unk6C_0], sp28);
        func_800C8E84(arg0->actorData[4], sp3C);
        delta = func_800D8FF8();
        arg0->unk58 += delta;
    }
}
s32 func_808003E4_chbottlesparty(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}
#include "party_data.inc"
