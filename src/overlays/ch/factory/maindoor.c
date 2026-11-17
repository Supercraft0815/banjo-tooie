#include "ch/factory/maindoor.h"

/* extern */

void func_80800000_chfactorymaindoor(Actor *arg0) {
    void func_80101FDC(Actor *, u32);
    f32 func_80103EF4(Actor *);
    if (func_800DA298(FLAG_1AB_PHYSICAL_GI_MainEntranceOpen) != 0) {
        func_80101FDC(arg0, 3);
        arg0->position[1] += func_80103EF4(arg0) * 0.8f;
    } else {
        arg0->unk58 = 8.0f;
    }
    ((f32 *)arg0->actorData)[7] = arg0->position[1];
}

void func_80800078_chfactorymaindoor(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_8009EC88(s32, s32, s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    f32 func_80103EF4(Actor *);
    extern u32 D_808004C0_chfactorymaindoor[];
    extern u32 D_808004CC_chfactorymaindoor[];
    f32 temp;
    f32 sp28;

    switch (arg0->unk70_10) {
    case 1:
        if (func_800DA298(FLAG3_A00_UNK) != 0 && func_800DA298(FLAG3_A01_UNK) != 0) {
            func_8009EC88(0x102, 2, 0x100, 9);
            func_80101FDC(arg0, 2);
            _capod_entrypoint_13(arg0->unk0, arg0->unk0, 4, 0x830);
        }
        break;
    case 2:
        if (func_800D90A4(&arg0->unk58) != 0) {
            func_80101FDC(arg0, 3);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808004CC_chfactorymaindoor);
            _subaddieaudioloop_entrypoint_2(arg0);
            arg0->position[1] = func_80103EF4(arg0) * 0.8f;
            arg0->position[1] += ((f32 *)arg0->actorData)[7];
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808004C0_chfactorymaindoor);
            sp28 = func_80103EF4(arg0);
            arg0->position[1] = func_800F10B4(arg0->unk58, 8.0f, 0.0f, 0.0f, 0.8f) * sp28;
            arg0->position[1] += ((f32 *)arg0->actorData)[7];
        }
        break;
    case 3:
        func_800DA544(FLAG_1AB_PHYSICAL_GI_MainEntranceOpen);
        func_80103110(arg0, 0);
        break;
    }
}

s32 func_808001F0_chfactorymaindoor(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor *, u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800EA05C();
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _glcutDll_entrypoint_6(u32, u32);

    switch (arg1) {
    case 0x49:
        if (arg2 == 0x43) {
            func_80101FDC(arg0, 2);
            arg0->unk58 = func_800F10B4(0.4f, 0.0f, 1.0f, 8.0f, 0.0f);
            _capod_entrypoint_13(arg0->unk0, arg0->unk0, 3, 0x2910);
            return 1;
        }
        return 0;
    case 0x95:
        if (func_800EA05C() == 0x101 && arg0->unk70_10 == 2) {
            func_80101FDC(arg0, 2);
            arg0->unk58 = func_800F10B4(0.66f, 0.0f, 1.0f, 8.0f, 0.0f);
            _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0x1D, 0x2810);
        }
        return 1;
    case 0xB:
        if (arg2 == 4 && func_800EA05C() == 0x101) {
            _glcutDll_entrypoint_6(0x100, 0x43);
            return 3;
        }
        return 3;
    default:
        return 0;
    }
}

OSThread *chfactorymaindoor_entrypoint_0(void)
{
    extern ActorData D_808004D4_chfactorymaindoor[];

    return (OSThread *) D_808004D4_chfactorymaindoor;
}    typedef struct { u8 pad0[0x76]; u16 unk76; } Objmaindoor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800344_chfactorymaindoor(u8 *arg0)
{
  s32 _chswitch_entrypoint_7(BtIntPtr, s32);
  void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
  if ((((unsigned int) ((u16) (((Objmaindoor_arg0 *)arg0)->unk76))) >> 7) == 0x32)
  {
    _chswitch_entrypoint_7((BtIntPtr) arg0, 0xA01);
    _chswitch_entrypoint_8(arg0, 0x200);
    return;
  }
  _chswitch_entrypoint_7((BtIntPtr) arg0, 0xA00);
  _chswitch_entrypoint_8(arg0, 0x400);
}

void func_808003A8_chfactorymaindoor(Actor *arg0, s32 arg1, s32 arg2)
{
  BtIntPtr new_var;
  s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
  s32 func_80103140(Actor *actor,u32 id,u16 palette);
  if ((arg1 == 0x95) && (((((u16) (*((u16 *) (((s8 *) arg0) + 0x76)))) & 0xFFFFFFFF) >> 7) == 0x32))
  {
 do { func_80103140(arg0, 0x7B8U, arg0->unk0->unk16); } while (0);
  }
  new_var = (BtIntPtr) arg0;
  _chswitch_entrypoint_10(new_var, arg1, arg2);
}

OSThread *chfactorymaindoor_entrypoint_1(void)
{
    extern ActorData D_8080051C_chfactorymaindoor[];

    return (OSThread *) D_8080051C_chfactorymaindoor;
}

void func_8080041C_chfactorymaindoor(s32 arg0)
{
    _chswitch_entrypoint_3(arg0,FLAG_188_UNK);
}

void func_8080043C_chfactorymaindoor(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_5(Actor *arg0, s32 arg1, u32 arg2);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x100U, 0x86U);
    }
    _chswitch_entrypoint_5(arg0, arg1, arg2);
}

OSThread *chfactorymaindoor_entrypoint_2(void)
{
    extern ActorData D_80800564_chfactorymaindoor[];

    return (OSThread *) D_80800564_chfactorymaindoor;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/maindoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_8011A1BC[];
void _chswitch_entrypoint_6();
void _chswitch_entrypoint_4();
u32 D_808004C0_chfactorymaindoor [3] BT_DATA(4, overlays_ch_factory_maindoor, 0x0) = { 0x1305B0, 0x18000A, 0x1330000 };
u32 D_808004CC_chfactorymaindoor [2] BT_DATA(4, overlays_ch_factory_maindoor, 0xC) = { 0x1304C7, 0x180000 };
ActorData D_808004D4_chfactorymaindoor [1] BT_DATA(4, overlays_ch_factory_maindoor, 0x14) = { { 285, 1016, 2172, 1, 0, (void (*)(struct Actor *))func_80800078_chfactorymaindoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chfactorymaindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9218, (void (*)(struct Actor *, long, long))func_808001F0_chfactorymaindoor, 0 } };
ActorData D_8080051C_chfactorymaindoor [1] BT_DATA(4, overlays_ch_factory_maindoor, 0x5C) = { { 283, 1017, 1977, 1, (void *)((u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800344_chfactorymaindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_808003A8_chfactorymaindoor, 0 } };
ActorData D_80800564_chfactorymaindoor [1] BT_DATA(4, overlays_ch_factory_maindoor, 0xA4) = { { 835, 1242, 2185, 1, (void *)((u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_4, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080041C_chfactorymaindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_8080043C_chfactorymaindoor, 0 } };
