#include "ch/factory/flypad.h"

OSThread *chfactoryflypad_entrypoint_0(void)
{
    extern ActorData D_80800250_chfactoryflypad[];

    return (OSThread *) D_80800250_chfactoryflypad;
}

OSThread *chfactoryflypad_entrypoint_1(void)
{
    extern ActorData D_80800298_chfactoryflypad[];

    return (OSThread *) D_80800298_chfactoryflypad;
}

void func_80800018_chfactoryflypad(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_16B_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800044_chfactoryflypad(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x100U, 0x42U);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800080_chfactoryflypad(s32 arg0) 
{
}
void func_80800088_chfactoryflypad(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    void func_800FFAB0(Actor *);
    void func_80108B04(Actor *, u32);
    s32 sp1C;
    sp1C = 0;
    if ((arg0->unk74_7 == 0x32) && (_glcutDll_entrypoint_19(0x42) != 0)) {
    func_80108B04(arg0, 0);
    sp1C = 1;
    }
    if ((_glcutDll_entrypoint_19(0x42) == 0) && (func_800DA298(FLAG_16B_UNK) != 0)) {
    func_80108B04(arg0, 0);
    sp1C = 1;
    }
    if ((sp1C == 0) && (_glcutDll_entrypoint_19(0x42) == 0)) {
    func_800FFAB0(arg0);
    }
    }

s32 func_80800130_chfactoryflypad(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    s32 _glcutDll_entrypoint_19(u32);
    Unk80132ED0 **_subaddiefind_entrypoint_1(Actor *, s32, s32, s32);
    void func_800FFAB0(Actor *);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_80108B04(Actor *, u32);
    Actor *sp1C;

    switch (arg1) {
    case 0x3D:
        sp1C = func_801084B0(0x234, &arg0);
        if (_glcutDll_entrypoint_19(0x42) != 0) {
            _chappearfx_entrypoint_1(sp1C, 0x22, 2, 1.0f);
        }
        func_800FFAB0(arg0);
        break;
    case 0x49:
        if ((arg0->unk74_7 == 0x32) && (_glcutDll_entrypoint_19(0x42) != 0)) {
            _capod_entrypoint_13(arg0->unk0, *_subaddiefind_entrypoint_1(arg0, 0x42F, -1, 0), 5, 0x900);
            break;
        }
        return 0;
    case 0xC:
        func_80108B04(arg0, 0);
        return 3;
    case 0x95:
        func_80800088_chfactoryflypad(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/flypad.data.s */
extern u8 D_8011A270[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_80102EC0();
ActorData D_80800250_chfactoryflypad [1] BT_DATA(4, overlays_ch_factory_flypad, 0x0) = { { 835, 1070, 1978, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chfactoryflypad, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800044_chfactoryflypad, 0 } };
ActorData D_80800298_chfactoryflypad [1] BT_DATA(4, overlays_ch_factory_flypad, 0x48) = { { 834, 1071, 0, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800080_chfactoryflypad, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_80800130_chfactoryflypad, 0 } };
