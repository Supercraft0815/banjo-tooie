#include "common.h"

OSThread *chicestationbits_entrypoint_0(void)
{
    extern ActorData D_80800280_chicestationbits[];

    return (OSThread *) D_80800280_chicestationbits;
}

OSThread *chicestationbits_entrypoint_1(void)
{
    extern ActorData D_808002C8_chicestationbits[];

    return (OSThread *) D_808002C8_chicestationbits;
}

/* extern */

void func_80800018_chicestationbits(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    _chswitch_entrypoint_7(arg0, 0x1CF);
    _chswitch_entrypoint_9(arg0);
    _chswitch_entrypoint_8(arg0, 2);
}

s32 func_80800050_chicestationbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    BtUIntPtr func_800F54E4(void);
    int func_800F6B94(BtIntPtr);
    s32 result;

    switch (arg1) {
        case 7:
            _glcutDll_entrypoint_6(0x12A, 0x48);
            result = 1;
            break;
        case 0x91:
            if (func_800F6B94(func_800F54E4()) == 0) {
                return 0;
            }
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return result;
}

/* extern */

void func_808000D4_chicestationbits(Actor *arg0) {
    void _chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void _chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    f32 var_f0;

    var_f0 = arg0->rotation[1];
    if (arg0->unk74_7 == 0x32) {
        var_f0 += 180.0f;
    }
    func_800EFD24(arg0->position);
    func_80103014((u8 *)arg0);
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, 600.0f, 0x20, 0x1CF) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.5f);
        _chdoormake_entrypoint_6(arg0, 0.5f);
        _chdoormake_entrypoint_12(arg0, 0, 0x48);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(arg0, 9);
            _chdoormake_entrypoint_9(arg0, 0, 0, 0x900);
        }
    }
    if ((func_800DA298(0x1CF) != 0) && (_glcutDll_entrypoint_19(0x48) == 0)) {
        func_800FFAB0(arg0);
    }
}

void func_808001E0_chicestationbits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void func_800FFAB0(Actor *);
    s32 func_80103140(Actor *, u32, u16);
    s32 id;

    switch (arg1) {
        case 0x95:
            id = arg0->unk74_7 == 0x32 ? 0x872 : 0x873;
            func_80103140(arg0, (u16)id, arg0->unk0->unk16);
            break;
        case 0x9D:
            func_800FFAB0(arg0);
            break;
    }
    _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
}
/* data_to_c.py: from asm/data/overlays/ch/icestationbits.data.s */
extern u8 D_8011A248[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void _chdoor_entrypoint_0();
ActorData D_80800280_chicestationbits [1] BT_DATA(4, overlays_ch_icestationbits, 0x0) = { { 835, 1050, 2157, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2060, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chicestationbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800050_chicestationbits, 0 } };
ActorData D_808002C8_chicestationbits [1] BT_DATA(4, overlays_ch_icestationbits, 0x48) = { { 172, 1051, -1, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_808000D4_chicestationbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808001E0_chicestationbits, 0 } };
