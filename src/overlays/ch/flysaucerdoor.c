#include "ch/flysaucerdoor.h"

OSThread *chflysaucerdoor_entrypoint_0(void)
{
    extern ActorData D_80800160_chflysaucerdoor[];

    return (OSThread *) D_80800160_chflysaucerdoor;
}

OSThread *chflysaucerdoor_entrypoint_1(void)
{
    extern ActorData D_808001A8_chflysaucerdoor[];

    return (OSThread *) D_808001A8_chflysaucerdoor;
}

void func_80800018_chflysaucerdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], 90.0f, 300.0f, 0x45, 8);
    _chdoormake_entrypoint_5(arg0, 3.5f);
    _chdoormake_entrypoint_8(arg0, 0x10U);
}

s32 func_8080006C_chflysaucerdoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_17(void);
    void _glcutDll_entrypoint_6(u32, u32);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    s32 func_80101180(s32, s32, BtIntPtr);

    switch (arg1) {
        case 7:
            if (func_800DA9E4(FLAG_0B3_UNK, 1) == 0) {
                _glcutDll_entrypoint_6(0xD6, 0x25);
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x830);
                _subaddieDll_entrypoint_4(arg0, 1);
            }
            return func_80101180(0x30C, arg1, arg2);
        case 11:
            _glcutDll_entrypoint_17();
            if (func_800DA298(FLAG_091_UNK) != 0) {
                _glcutDll_entrypoint_6(0xCA, 0x16);
                return 3;
            }
            _capod_entrypoint_14();
            return 4;
        default:
            return 0;
    }
}

void func_80800140_chflysaucerdoor(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG0_008_UNK);
}
/* data_to_c.py: from asm/data/overlays/ch/flysaucerdoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
extern u8 D_8011A270[];
void _chswitch_entrypoint_13();
OSThread *_chswitch_entrypoint_0(void);
ActorData D_80800160_chflysaucerdoor [1] BT_DATA(4, overlays_ch_flysaucerdoor, 0x0) = { { 721, 780, 1898, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 98304000, 0, 179, 0, 8, 3076, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chflysaucerdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8194, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_808001A8_chflysaucerdoor [1] BT_DATA(4, overlays_ch_flysaucerdoor, 0x48) = { { 722, 781, 1669, 1, (void *)((u8 *)D_8011A270 + 0x28), (void (*)(struct Actor *))_chswitch_entrypoint_13, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800140_chflysaucerdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_8080006C_chflysaucerdoor, 0 } };
