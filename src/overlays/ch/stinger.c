#include "common.h"

void func_80800000_chstinger(Actor *arg0) {
    s32 func_800B5BE4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    extern s32 D_808007D0_chstinger[];
    extern s32 D_808007FC_chstinger[];
    extern s32 D_80800844_chstinger[];
    s32 sp5C;
    f32 sp50[3];
    f32 sp44[3];

    if (arg0->unk7C_12) {
        sp5C = func_800B5BE4(0x1B);
        sp5C = func_800BABB8(sp5C, arg0->position, arg0->position, 1.0f, D_808007D0_chstinger);
        func_800EFA98(sp50, (f32 *)&arg0->actorData[4], func_800DC178(-200.0f, -400.0f));
        func_800BA930(sp5C, (s16)sp50[0], (s16)sp50[1], (s16)sp50[2],
            (s16)sp50[0], (s16)sp50[1], (s16)sp50[2]);
        func_800BA22C(sp5C, 3);
        func_800EFA98(sp50, (f32 *)&arg0->actorData[4], -25.0f);
        func_800EE780(sp44, arg0->position, sp50);
        func_800BBCB8(sp44, NULL, 1.0f, 1, D_80800844_chstinger);
        func_800EF04C(sp44, sp50);
        sp5C = func_800B5BE4(8);
        func_800BABB8(sp5C, sp44, NULL, 1.0f, D_808007FC_chstinger);
    }
}

void func_8080015C_chstinger(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_800CB840(s32, s32);
    void func_800CB870(void);
    void func_80109BEC(s32, f32, s32, s32, s32, s32);
    s8 *data;

    data = func_80100094(arg0, 0);
    if (arg1 != arg0->unk70_10) {
        func_80101FDC(arg0, arg1);
        switch (arg0->unk70_10) {
            case 2:
                data[0x28] = 1;
                break;
            case 3:
                func_800CB840(4, arg0);
                func_80109BEC(arg0->position, 120.0f, 2, 0, 0, arg0->unk0);
                func_800CB870();
                func_80800000_chstinger(arg0);
                break;
        }
    }
}

void func_80800218_chstinger(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

void func_8080025C_chstinger(s32 arg0) 
{
}
s32 func_80800264_chstinger(s32 arg0, s32 *arg1) {
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
    s32 func_800F5898(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    f32 distance;
    f32 bestDistance;
    f32 *origin;
    s32 i;
    f32 result[3];
    s32 best;
    s8 *data;
    s32 excluded;
    f32 position[4];

    data = func_80100094((Actor *)arg0, 0);
    bestDistance = 0.0f;
    origin = (f32 *)(data + 0x18);
    best = -1;
    excluded = *data;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6438(i) && i != excluded) {
            func_800F5A00(i, position);
            distance = func_800EEB40(position, origin);
            if ((best < 0 || distance < bestDistance) &&
                func_800F0734(origin, ((Actor *)arg0)->position, position, 55.0f, 120.0f, result, result)) {
                best = i;
                bestDistance = distance;
                func_800EE7F8((f32 *)arg1, result);
            }
        }
    }
    return best;
}

/* extern */

s32 func_808003B0_chstinger(s32 arg0) {
    s32 func_800EA068(s32);
    s32 func_800F7A7C(s32, s8, s32, s32, s32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80800264_chstinger(s32, s32 *);
    s32 sp2C[3];
    s32 sp28;
    s32 temp_v0;
    s8 *data;

    if (func_800EA068(0x4000) != 0) {
        temp_v0 = func_80800264_chstinger(arg0, sp2C);
        sp28 = temp_v0;
        if (temp_v0 >= 0) {
            data = func_80100094(arg0, 0);
            func_800F7A7C(sp28, *data, 1, 3, sp2C);
            return 1;
        }
    }
    return 0;
}

void func_80800420_chstinger(Actor *arg0) {
    void _sumissilehome_entrypoint_6(Actor *, void *);
    f32 func_800136E4(f32);
    void func_800CB840(s32, s32);
    void func_800CB870(void);
    u8 *func_800CD820(u8 *, f32 *, f32 *, f32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80103014(u8 *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010AA78(s32 *);
    s32 func_8010B990(Actor *, s32);
    struct StingerData {
        u8 pad[0x14];
        f32 unk14;
        f32 position[3];
        f32 unk24;
        u8 unk28;
    };
    f32 sp44;
    f32 sp40;
    u8 *sp3C;
    s32 sp38;
    s32 sp34;
    struct StingerData *data;

    data = func_80100094(arg0, 0);
    sp44 = data->unk14;
    sp40 = func_800D8FF8();
    switch (arg0->unk70_10) {
        case 2:
            if (data->unk28 != 0) {
                data->unk28 = 0;
                sp38 = 0;
            } else {
                _sumissilehome_entrypoint_6(arg0, data);
                sp38 = func_8010B990(arg0, 0x100004);
            }
            if (sp38 == 0x20) {
                func_8010AA78(arg0->position);
            }
            func_80800218_chstinger(arg0);
            arg0->rotation[2] = func_800136E4(arg0->rotation[2] + sp40 * 1200.0f);
            func_80103014(arg0);
            func_8010A590(arg0);
            func_800CB840(4, arg0);
            sp3C = func_800CD820(arg0->unk0, data->position, arg0->position, 80.0f);
            func_800CB870();
            func_8010A570(arg0);
            sp34 = sp3C != 0;
            if (sp38 == 0x20 || sp34 || data->unk24 > 5000.0f) {
                func_8080015C_chstinger(arg0, 3);
            }
            if (func_808003B0_chstinger(arg0) != 0) {
                func_8080015C_chstinger(arg0, 3);
            }
            break;
        case 3:
            func_800FFAB0(arg0);
            break;
    }
    data->unk14 = sp44 + sp40;
    data->unk24 += func_800EEAD4(arg0->position, data->position);
    func_800EE7F8(data->position, arg0->position);
}

Unk80132ED0 *chstinger_entrypoint_0(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4) {
    void _sumissilehome_entrypoint_0(Actor *, void *);
    void _sumissilehome_entrypoint_1(Actor *, void *, s32);
    void _sumissilehome_entrypoint_3(Actor *, void *, s32);
    void _sumissilehome_entrypoint_4(Actor *, void *, s32);
    void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    s32 func_800EA068(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA98(f32[3], f32[3], f32);
    void func_800EFB24(void *, void *, void *);
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    void func_8010A570(Actor *);
    Actor *actor;
    f32 sp40[3];
    f32 sp34[3];
    struct {
        u8 pad[0x14];
        f32 unk14;
        f32 position[3];
        f32 unk24;
    } *data;
    f32 sp24[3];

    func_800EFA98(sp40, arg2, 30.0f);
    func_800EF04C(arg0, sp40);
    if (func_800C6A7C(arg1, arg0, sp34, 0x20020) != NULL) {
        func_800EFB24(sp24, arg1, arg0);
        func_800EF368(sp24, 1.0f);
        func_800EF04C(arg0, sp24);
    }
    actor = func_80108474(0x16F, arg0, 0);
    data = func_80100094(actor, 0);
    ((f32 *)actor->actorData)[7] = 0.0f;
    func_800EE7F8((f32 *)&actor->actorData[4], arg2);
    func_80800218_chstinger(actor);
    data->unk24 = 0.0f;
    func_800EE7F8(data->position, arg0);
    data->unk14 = 0.0f;
    func_8010A570(actor);
    _sumissilehome_entrypoint_0(actor, data);
    _sumissilehome_entrypoint_3(actor, data, arg4);
    if (func_800EA068(0x20) != 0) {
        _sumissilehome_entrypoint_4(actor, data, 1);
    } else {
        _sumissilehome_entrypoint_1(actor, data, -1);
    }
    _sumissilehome_entrypoint_5(actor, data, 4500.0f, 1200.0f);
    func_8080015C_chstinger(actor, 2);
    return actor->unk0;
}

s32 func_80800774_chstinger(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80109EEC(s16*, s32);
    switch (arg1) {
        case 0x95:
            func_80109EEC((s16 *) arg0, 0x10);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chstinger_entrypoint_1(void)
{
    extern u8 D_80800870_chstinger[];

    return (OSThread *) D_80800870_chstinger;
}
