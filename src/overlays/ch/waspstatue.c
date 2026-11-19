#include "common.h"

/* extern */

void func_80800000_chwaspstatue(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800134_chwaspstatue(BtIntPtr, s32);

    func_80800134_chwaspstatue(arg0, func_800DA298(0x35A) ? 0x6 : 1);
}

void func_8080003C_chwaspstatue(Actor *actor) {
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    s32 func_800DA298(s32);
    void func_8010C93C(BtIntPtr, BtIntPtr, f32);
    s32 func_80800134_chwaspstatue(BtIntPtr, s32);

    switch (actor->unk70_10) {
    case 1:
    case 6:
        break;
    case 2:
        if (func_800D91EC(&actor->unk58, 2.0f) && func_800DA298(0x6D8)) {
            func_80800134_chwaspstatue((BtIntPtr)actor, 3);
        }
        func_800D2498(0xFF, actor->unk6C_0, 0);
        break;
    case 3:
        func_800D2498(0xFF, actor->unk6C_0, 0);
        break;
    case 4:
        if (func_800D90A4(&actor->unk58)) {
            func_80800134_chwaspstatue((BtIntPtr)actor, 1);
        }
        break;
    case 5:
        func_80800134_chwaspstatue((BtIntPtr)actor, 6);
        break;
    }
    func_8010C93C((BtIntPtr)actor, (BtIntPtr)actor->position, 0.75f);
}

s32 func_80800134_chwaspstatue(BtIntPtr arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_800D2498(u32, s32, u32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_800FC6B0(u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void _chwaspstatue_entrypoint_0(s32, s32);
    Actor *actor = (Actor *)arg0;

    switch (arg1) {
    case 1:
        _subaddieDll_entrypoint_4(actor, 0);
        break;
    case 2:
        _subaddieDll_entrypoint_4(actor, 1);
        func_800CE8D8(0, 10.0f, 10);
        func_800CE928(0, (BtIntPtr)_chwaspstatue_entrypoint_0, (BtIntPtr)actor->unk0);
        actor->unk6C_0 = 20;
        actor->unk58 = 0.0f;
        if (func_800DA298(0x6D8) == 0) {
            _capod_entrypoint_13(actor->unk0, actor->unk0, 0x15, 0x810);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1416, 0xF, actor->position, 0x6D);
        } else {
            func_800CE88C(0, 1);
        }
        break;
    case 3:
        if (func_800DA298(0x6D8) == 0) {
            func_800CE88C(0, 1);
        }
        actor->unk58 = 2.0f;
        break;
    case 4:
        if (func_800DA298(0x6D9) == 0) {
            func_800DA544(0x6D9);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1419, 0xF, actor->position, 0x6D);
            _capod_entrypoint_13(actor->unk0, actor->unk0, 0x1B, 0x810);
        }
        func_800FC6B0(0x19);
        actor->unk58 = 2.0f;
        break;
    case 5:
        func_800FC6B0(0x10);
        func_800D2498(0xFF, 0, 0);
        _subaddiedialog_entrypoint_11(actor->unk0, 0x1418, 0xF, actor->position, 0x6D);
        func_80101180(0x411, 7, 0);
        func_800DA544(0x35A);
        actor->unk58 = 2.0f;
        func_800CE88C(0, 0);
        break;
    case 6:
        _subaddieDll_entrypoint_4(actor, 0);
        actor->unk58 = 2.0f;
        break;
    }
    func_80101FDC(actor, arg1);
    BT_NATIVE_ONLY(return 0;)}

s32 func_80800350_chwaspstatue(Actor *actor, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_800DF6BC(s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FC660(u32);
    s32 func_801015D0(Actor *);
    u32 state;
    s16 *dialog;

    switch (arg1) {
    case 0x3F:
        if (func_800DA298(0x6DA) == 0) {
            func_800DA544(0x6DA);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1417, 0xF, actor->position, 0x6D);
        }
        return 1;
    case 0x40:
        state = actor->unk70_10;
        if (state == 1) {
            func_80800134_chwaspstatue((BtIntPtr)actor, 2);
            func_800FC660(0xE);
            return 1;
        }
        if (state == 3) {
            actor->unk6C_0--;
            if (actor->unk6C_0 == 0) {
                func_80800134_chwaspstatue((BtIntPtr)actor, 5);
            }
            func_800FC660(0xE);
        }
        return 1;
    case 0xB:
        if (arg2 == 0x15) {
            func_80800134_chwaspstatue((BtIntPtr)actor, 3);
            func_800DA544(0x6D8);
        }
        return 3;
    case 0x1F:
        func_801015D0(actor);
        func_800DF6BC((s32)func_800F10B4(actor->unk58, 0.0f, 2.0f, 0.0, 255.0f), 0xFF);
        return 1;
    case 0x30:
        dialog = (s16 *)&arg2;
        if (dialog[0] == 0x1416) {
            if (dialog[1] != 0) {
                return 0x14;
            }
            return 0xA;
        }
        return 0;
    default:
        return 0;
    }
}

/* extern */

void chwaspstatue_entrypoint_0(s32 arg0, s32 arg1) {
    BtIntPtr func_80106790(BtIntPtr);
    s32 func_80800134_chwaspstatue(BtIntPtr, s32);
    func_80800134_chwaspstatue(func_80106790(arg1), 4);
}

OSThread *chwaspstatue_entrypoint_1(void)
{
    extern ActorData D_80800740_chwaspstatue[];

    return (OSThread *) D_80800740_chwaspstatue;
}

/* extern */

void func_80800544_chwaspstatue(Actor *arg0) {
    s32 _chdoormake_entrypoint_10(void *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 var_a1;

    var_a1 = func_800F64A4(func_800F54E4(), 0x20) != 0;
    if (var_a1 != 0) {
        var_a1 = func_800DA298(0x35A) != 0;
    }
    func_800DA3B8(0x9FD, var_a1);
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], arg0->rotation[0] + 90.0f, arg0->scale * 346.0f, 0x83, 0x9FD);
    _chdoormake_entrypoint_5(arg0, 2.0f);
    _chdoormake_entrypoint_6(arg0, 0x3F000000);
    _chdoormake_entrypoint_8(arg0, 5);
    _chdoormake_entrypoint_9(arg0, 0, 0x1D, 0x810);
    _chdoormake_entrypoint_10(arg0, 0, 0x3DF);
}

OSThread *chwaspstatue_entrypoint_2(void)
{
    extern ActorData D_80800788_chwaspstatue[];

    return (OSThread *) D_80800788_chwaspstatue;
}
/* data_to_c.py: from asm/data/overlays/ch/waspstatue.data.s */
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
void _chdoor_entrypoint_0();
void func_80101870(Actor* arg0, void* arg1);
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_80800740_chwaspstatue [1] BT_DATA(4, overlays_ch_waspstatue, 0x0) = { { 850, 1039, 2256, 1, 0, (void (*)(struct Actor *))func_8080003C_chwaspstatue, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 65550000, 0, 0, 0, 0, 1024, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chwaspstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9216, (void (*)(struct Actor *, long, long))func_80800350_chwaspstatue, 0 } };
ActorData D_80800788_chwaspstatue [1] BT_DATA(4, overlays_ch_waspstatue, 0x48) = { { 853, 1041, 2257, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800544_chwaspstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
