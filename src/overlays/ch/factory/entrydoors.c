#include "ch/factory/entrydoors.h"

/* extern */

void func_80800000_chfactoryentrydoors(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(Actor *arg0, f32 arg1, u32 arg2, s32 arg3);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _sujiggy_entrypoint_20(u32);
    s32 func_800D3E40(s32);
    void func_800DA544(s32 index);
    void func_80101FDC(Actor *, u32);
    f32 var_f0;
    s32 var_a3;

    if (_sujiggy_entrypoint_20(5) != 0) {
        func_800DA544(0x397);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7F) == 0)) {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_a3 = 0x397;
    }
    if (arg0->unk74_7 == 0x33) {
        var_f0 = -75.0f;
    } else {
        var_f0 = 75.0f;
    }
    _chdoormake_entrypoint_0(arg0, var_f0, 0, var_a3);
    _chdoormake_entrypoint_8(arg0, 1);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

/* extern */

void func_808000CC_chfactoryentrydoors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    s32 var_v0;

    if (arg1 == 0x95) {
        var_v0 = (arg0->unk74_7 == 0x33) ? 0x971 : 0x972;
        func_80103140(arg0, var_v0 & 0xFFFF, arg0->unk0->unk16);
    }
    _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
}

OSThread *chfactoryentrydoors_entrypoint_0(void)
{
    extern ActorData D_808002B0_chfactoryentrydoors[];

    return (OSThread *) D_808002B0_chfactoryentrydoors;
}

void func_8080014C_chfactoryentrydoors(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800D3E40(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    if (((func_800DA298(0x397) != 0) || (func_800D3E40(0xB) != 0)) && (_glcutDll_entrypoint_19(0x7F) == 0)) {
        func_800FFAB0(arg0);
    }
}    typedef struct { u8 pad0[0x34]; f32 unk34; } Objentrydoors_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808001A0_chfactoryentrydoors(u8 *arg0) {
    s32 func_800D90A4(BtIntPtr);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (func_800D90A4(arg0 + 0x58) != 0) {
        func_80101180(0x48B, 7, (s32) (((Objentrydoors_arg0 *)arg0)->unk34));
        func_800FFAB0(arg0);
    }
}

s32 func_808001F0_chfactoryentrydoors(Actor *arg0, s32 arg1, s32 arg2) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    void func_80103110(Actor *, u32);
    extern s32 D_808002F8_chfactoryentrydoors[38];
    extern s32 D_80800390_chfactoryentrydoors[4];

    if (arg1 == 7) {
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_808002F8_chfactoryentrydoors);
        func_800C4AF0(arg0->position, D_80800390_chfactoryentrydoors);
        arg0->unk64_16 = 0;
        arg0->unk58 = 2.0f;
        func_80103110(arg0, 1);
        *(f32 *)&arg0->actorData[7] = (f32) arg2;
        return 1;
    }
    return 0;
}

OSThread *chfactoryentrydoors_entrypoint_1(void)
{
    extern ActorData D_808003A0_chfactoryentrydoors[];

    return (OSThread *) D_808003A0_chfactoryentrydoors;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/entrydoors.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808002B0_chfactoryentrydoors [1] BT_DATA(4, overlays_ch_factory_entrydoors, 0x0) = { { 172, 1163, 2417, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chfactoryentrydoors, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_808000CC_chfactoryentrydoors, 0 } };
s32 D_808002F8_chfactoryentrydoors[38] BT_DATA(4, overlays_ch_factory_entrydoors, 0x48) = { 84934685, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2140071, -1480589302, -6553575, -6553500, 4915300, 85590288, 1902963, 1834208, -45875154, 14090540, 52429045, 21627880, 1441794, 2162918, 0, 2556204, 19661100, 19660837, 16777472, 1376256, 15073323, 167774720, 262310, 458758, 197655, 983040008, 15073536, 18481152 };
s32 D_80800390_chfactoryentrydoors[4] BT_DATA(4, overlays_ch_factory_entrydoors, 0xE0) = { 1246227, 655590, 1469792, 131072 };
ActorData D_808003A0_chfactoryentrydoors [1] BT_DATA(4, overlays_ch_factory_entrydoors, 0xF0) = { { 344, 1243, 2419, 1, 0, (void (*)(struct Actor *))func_808001A0_chfactoryentrydoors, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 919, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080014C_chfactoryentrydoors, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808001F0_chfactoryentrydoors, 0 } };
