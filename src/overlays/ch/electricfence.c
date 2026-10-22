#include "common.h"

OSThread *chelectricfence_entrypoint_0(void)
{
    extern u8 D_808004C0_chelectricfence[];

    return (OSThread *) D_808004C0_chelectricfence;
}

/* extern */

void func_8080000C_chelectricfence(s32 arg0) {
    s32 func_800EA05C();
    s32 func_80104004(s32, s32, s32);
    void func_8010A570(Actor *);
    s32 func_8010A624(s32);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
        func_8010A570(arg0);
    }
    func_80104004(arg0, arg0 + 0x18, arg0 + 0x28);
}

void func_80800060_chelectricfence(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    s32 chelectricfence_entrypoint_2(Actor *, u32 *, u32 *);
    u8 func_800D9078(f32 *);
    int func_800DC298(f32);
    void func_8010A590(Actor *);
    extern s32 D_80800508_chelectricfence;
    if (func_800D9078(&arg0->unk58) != 0) {
        func_8010A590(arg0);
    }
    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, arg0->unk70_10 == 1, -1, &D_80800508_chelectricfence);
    if ((arg0->unk70_10 == 1) && arg0->unk7C_12 && (func_800DC298(0.2f) != 0)) {
        chelectricfence_entrypoint_2(arg0, arg0->actorData, &arg0->actorData[4]);
    }
}

s32 func_8080010C_chelectricfence(Actor *arg0, s32 arg1, void *volatile arg2) {
    f32 func_800EC75C(void *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    s32 func_800F64A4(s32, s32);
    void func_8010A570(Actor *);
    u32 func_8010A5B0(Actor *, s32);
    void chelectricfence_entrypoint_1(Actor *, f32 *);
    f32 sp2C[3];
    Unk80132ED0 *sp28;
    s32 var_a1;
    s32 pad[2];

    switch (arg1) {
        case 0x3F:
            sp28 = arg2;
            func_800EC75C(sp28, sp2C);
            chelectricfence_entrypoint_1(arg0, sp2C);
            arg0->unk58 = 0.2f;
            func_8010A570(arg0);
            if ((sp28->unk24 >> 22) == 0) {
            }
            break;
        case 0x95:
            var_a1 = func_800F6438(func_800F54E4()) != 0;
            if (var_a1 != 0) {
                var_a1 = func_800F64A4(func_800F54E4(), 0x8000) == 0;
            }
            func_8010A5B0(arg0, var_a1);
            break;
        default:
            return 0;
    }
    return 1;
}

void chelectricfence_entrypoint_1(Actor *arg0, f32 *arg1) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    extern s32 D_8080051C_chelectricfence;
    extern s32 D_80800558_chelectricfence;
    extern s32 D_8080058C_chelectricfence;
    extern u32 D_80800598_chelectricfence;
    s32 light;

    func_800BBCB8(arg1, arg1, 1.0f, 3, &D_80800558_chelectricfence);
    func_800BBCB8(arg1, arg1, 1.0f, 0xC, &D_8080051C_chelectricfence);
    _subaddieaudioquick_entrypoint_2(arg0, arg1, &D_8080058C_chelectricfence);
    light = func_800C8A98();
    func_800C8CB8(light, arg1);
    func_800C8E84(light, &D_80800598_chelectricfence);
    func_800C8E54(light, 300.0f, 600.0f);
    _chlightfader_entrypoint_1(light, 0.8f, 5);
}

s32 chelectricfence_entrypoint_2(Actor *arg0, u32 *arg1, u32 *arg2) {
    s32 func_800B5BE4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EF934(f32[3], f32[3], f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    extern s32 D_808005A4_chelectricfence[];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;
    s32 sp3C;
    f32 sp38;

    if (func_800DC298(0.5f)) {
        sp40 = ((f32 *)arg1)[2];
    } else {
        sp40 = ((f32 *)arg2)[2];
    }
    func_800EFA4C(sp5C, func_800DC178(((f32 *)arg1)[0], ((f32 *)arg2)[0]),
                 func_800DC178(((f32 *)arg1)[1], ((f32 *)arg2)[1]), sp40);
    func_800EFA4C(sp50, func_800DC178(((f32 *)arg1)[0], ((f32 *)arg2)[0]),
                 func_800DC178(((f32 *)arg1)[1], ((f32 *)arg2)[1]), sp40);
    func_800EF934(sp5C, sp5C, arg0->rotation[1]);
    func_800EF04C(sp5C, arg0->position);
    func_800EF934(sp50, sp50, arg0->rotation[1]);
    func_800EF04C(sp50, arg0->position);
    func_800EFB24(sp44, sp50, sp5C);
    func_800EF368(sp44, 400.0f);
    sp38 = func_800EEAD4(sp50, sp5C) / 500.0f;
    sp3C = func_800B5BE4(0x12);
    func_800BABB8(sp3C, sp5C, NULL, 1.8f, D_808005A4_chelectricfence);
    func_800BA930(sp3C, (s16)sp44[0], (s16)sp44[1], (s16)sp44[2],
                 (s16)sp44[0], (s16)sp44[1], (s16)sp44[2]);
    func_800BA8F8((void *)sp3C, sp38, sp38);
    func_800BA22C(sp3C, 1);
}
