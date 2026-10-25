#include "common.h"

/* extern */

void func_80800000_chboggy(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.18f;
    if ((func_800DA298(0x439) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80101FDC(arg0, 3);
    }
}

void func_80800054_chboggy(Actor *arg0, s32 arg1, s32 arg2) {
    u8 _subaddiedialog_entrypoint_9();
    s32 func_800DA544(s32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_80800790_chboggy;
    extern s32 D_808007C8_chboggy;
    s32 first;
    s32 second;

    first = _subaddiedialog_entrypoint_9(arg0, arg1, &D_80800790_chboggy, 7);
    second = _subaddiedialog_entrypoint_9(arg0, arg1, &D_808007C8_chboggy, 7);
    if (first == 1) {
        func_80101FDC(arg0, 1);
        func_800DA544(0x447);
        return;
    }
    if (second == 1) {
        func_800F82D4(func_800F54E4(), 0);
    }
}

s32 func_808000EC_chboggy(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D10D4(u32, u32, f32 *, s32, s32);
    void func_800DF3E0(void);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 *_chbounce_entrypoint_9(Actor *);
    extern s32 D_80800820_chboggy;

    switch (arg1) {
        case 0x2E:
            func_80800054_chboggy(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x1F:
            func_800DF3E0();
            func_801015D0(arg0);
            func_800DF744(3, arg0->unk70_10 == 1 ? 1 : 2);
            break;
        case 0x7D:
            func_80101FDC(arg0, 2);
            break;
        case 0x3D:
            if (arg2 == 0x22B) {
                _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80800820_chboggy);
                ((f32 *)arg0->actorData)[1] -= 60.0f;
                _chbounce_entrypoint_9(func_80106790((Unk80132ED0 *)func_800D10D4(0x40, 1, (f32 *)arg0->actorData, 0, 0)))[1] = 0.0f;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800220_chboggy(Actor *arg0) {
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    void func_80800554_chboggy(s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 func_8008FE14(void);
    s32 func_80090818(void);
    s32 func_80090768(f32 *);
    void func_800D1824(s32);
    void func_800F8300();
    s32 func_80101E14(Actor *, f32);
    s32 func_800D0B68(u32, u32);
    s32 func_800D0A9C(u32, u32);
    void func_80108B04(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    extern u32 D_808006A0_chboggy, D_808006B0_chboggy, D_808006B8_chboggy;
    extern u32 D_808006C8_chboggy, D_808006D8_chboggy, D_808006E8_chboggy;
    extern u32 D_808006F8_chboggy, D_80800704_chboggy, D_80800710_chboggy;
    extern u32 D_80800720_chboggy, D_80800730_chboggy, D_80800740_chboggy;
    extern u32 D_8080074C_chboggy, D_80800760_chboggy;
    extern s32 D_80800790_chboggy, D_808007C8_chboggy;
    extern s32 D_80800800_chboggy, D_80800810_chboggy;

    _sudeflect_entrypoint_0(arg0->position, 175.0f, 175.0f, 14);
    func_80800554_chboggy((s32)arg0);
    switch (arg0->unk70_10) {
        case 1:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], &D_808006A0_chboggy, 0.1298f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], &D_80800704_chboggy, &D_80800740_chboggy);
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], &D_80800710_chboggy, 0.42f);
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], &D_808006F8_chboggy, 0.58f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], &D_808006C8_chboggy, &D_8080074C_chboggy);
            if (func_800DA298(0x447)) {
                func_800902E4(arg0->position, 400.0f, 0x4D7, &arg0);
                if ((func_800F640C(func_800F54E4(), 0x4D7) || func_8008FE14() == 0x4D7) && func_80090818()) {
                    func_80090768((f32 *)arg0->actorData);
                    func_800D1824(0x51);
                    func_800F8300(func_800F54E4(), 2, arg0->position);
                }
            }
            if (func_800DA298(0x439)) {
                func_800DA544(0x437);
            }
            _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, &D_80800800_chboggy, &D_80800790_chboggy, 7);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], &D_808006B0_chboggy, 0.05f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], &D_808006E8_chboggy, &D_80800760_chboggy);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], &D_808006B8_chboggy, &D_80800730_chboggy);
            if (func_80101E14(arg0, 0.6f) && !func_800D0B68(0x40, 1) && !func_800D0A9C(0x40, 1)) {
                func_80108B04(arg0, 0x22B);
            }
            if (func_80101E14(arg0, 0.99f)) {
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], &D_808006D8_chboggy, 0.22f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], &D_808006B8_chboggy, &D_80800720_chboggy);
            _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, &D_80800810_chboggy, &D_808007C8_chboggy, 7);
            break;
    }
}

void func_80800504_chboggy(Actor *arg0, s32 arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_800DBEFC(s32 *, s32, s32);
    void func_801018A4(Actor *, s32);
    OSThread * func_80104130(void);
    func_801018A4(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_800DBEFC((s32 *)func_80104130(), 4, (s32)arg0 + 0x18);
    }
}

void func_80800554_chboggy(s32 arg0) {
    f32 _idglowa_entrypoint_1(s32);
    s32 _idworld_entrypoint_0(s32);
    void func_800C36F4(u8, s32);
    void func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    extern s32 D_80800830_chboggy;
    s32 temp_f8;
    s32 sp24;
    u8 sp1F;
    s32 temp_v0;
    s32 var_v1;
    u8 temp_v0_2;

    temp_v0 = _idworld_entrypoint_0(0x35C);
    if (temp_v0 != 0) {
        temp_f8 = (s32) (_idglowa_entrypoint_1(temp_v0) * 32.0f);
        var_v1 = temp_f8;
        if (temp_f8 == 0x13) {
            sp24 = temp_f8;
            func_800DA544(0xA2E);
            var_v1 = sp24;
        }
        if ((var_v1 == 0x12) && (func_800DA298(0xA2E) != 0)) {
            temp_v0_2 = func_800C4350(0, 0, &D_80800830_chboggy);
            sp1F = temp_v0_2;
            func_800C36F4(temp_v0_2, 1);
            func_800C3A40(sp1F, 1.0f, 1.4f, 1.0f);
            func_800C3BDC(sp1F);
            func_800DA524(0xA2E);
        }
    }
}

OSThread *chboggy_entrypoint_0(void)
{
    extern u8 D_80800840_chboggy[];

    return (OSThread *) D_80800840_chboggy;
}

void func_80800634_chboggy(Actor *arg0) {
    arg0->rotation[0] = (f32)arg0->unk74_7;
    arg0->rotation[2] = arg0->scale * 100.0f;
    arg0->scale = 2.0f;
}

OSThread *chboggy_entrypoint_1(void)
{
    extern u8 D_80800888_chboggy[];

    return (OSThread *) D_80800888_chboggy;
}
