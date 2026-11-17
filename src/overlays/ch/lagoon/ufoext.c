#include "common.h"

s32 func_80800000_chlagoonufoext(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _gclevel_entrypoint_3(u32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800EA090(void);
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4AC0(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_808002A4_chlagoonufoext(Actor *);
    extern s32 func_8010D5DC;
    BtIntPtr sp24;

    switch (arg1) {
    case 0xB:
        if (arg2 == 0x32) {
            func_800DA544(0xB6);
            _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0));
            if (_gclevel_entrypoint_3(0x17)) {
                _glcutDll_entrypoint_6(0x128, 0x4A);
            }
            return 4;
        }
        return 3;
    case 0x32:
        func_808002A4_chlagoonufoext(arg0);
        break;
    case 0x95:
        if (func_800DA298(0x9F0) && func_80090178(1) && func_800EA090() == 9) {
            sp24 = func_800F54E4();
            func_800F608C(sp24, 1);
            func_800F497C(sp24);
            func_800F49D4(sp24, &func_8010D5DC, arg0->unk0);
            func_800F4AC0(sp24, (f32 *)&arg0->actorData[4], 300.0f);
            _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0), 0x42, 0x60, 0);
            func_80102424(arg0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}                typedef struct { s32 unk0; u8 pad4[0x30]; u8 unk34; u8 pad35[0x3D]; u16 unk72; } Objufoext_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800168_chlagoonufoext(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    u8 _susubgame_entrypoint_2(BtIntPtr arg0, u8 *arg1);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void *func_80100094(Actor *, u32);
    (((Objufoext_arg0 *)arg0)->unk34) = _subaddieaudioloop_entrypoint_3((((Objufoext_arg0 *)arg0)->unk34));
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0));
    }
}

OSThread *chlagoonufoext_entrypoint_0(void)
{
    extern ActorData D_80800558_chlagoonufoext[];

    return (OSThread *) D_80800558_chlagoonufoext;
}

void func_808001D8_chlagoonufoext(Actor *arg0) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    s32 _subaddiesect_entrypoint_1(Actor *);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void func_800CBB80(s32, s32);
    s32 func_800CBDD4(f32 *, s32, s32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    f32 unused[3];
    f32 sp28[3];
    s32 temp_a0;

    arg0->actorData[3] = func_800CBDD4(arg0->position, 0x64, 6);
    if (func_800DA298(0xB6) != 0) {
        temp_a0 = arg0->actorData[3];
        if (temp_a0 != -1) {
            func_800CBB80(temp_a0, 0);
        }
        func_800FFAB0(arg0);
    } else {
        arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
    }
    if (_subaddiemarker_entrypoint_0(arg0, 0x1C0, sp28, 1) != 0) {
        func_800EE7F8((f32 *)&arg0->actorData[4], sp28);
    }
    _susubgame_entrypoint_0(arg0, func_80100094(arg0, 0), 0);
}

void func_808002A4_chlagoonufoext(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void *func_80100094(Actor *, u32);
    void func_80101D4C(Actor *);
    void func_80101FDC(Actor *, u32);

    func_80101FDC(arg0, 3);
    func_80101D4C(arg0);
    func_800D1000(0x28, 1, 0, 3, 0);
    _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0), 0x32, 0x30, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1047, 0x40, arg0->position, 0);
}

void func_8080032C_chlagoonufoext(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddiesect_entrypoint_0(Actor *, s32, s32);
    void func_800CBB80(s32, s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80102320(Actor *, f32, f32);
    extern s32 D_80800500_chlagoonufoext[];
    extern u32 D_80800510_chlagoonufoext[];
    extern u32 D_80800524_chlagoonufoext[];
    extern u32 D_808005A0_chlagoonufoext[];
    s32 sp34[1];

    switch (arg0->unk70_10) {
    case 1:
        if (_subaddiesect_entrypoint_0(arg0, arg0->unk6C_0, 4) == 0) {
            return;
        }
        break;
    case 3:
        sp34[0] = 0;
        if (func_80101E14(arg0, 0.49f) != 0) {
            arg0->unk70_0 = 0;
        }
        if (func_80102320(arg0, 0.53f, 0.7f) != 0) {
            sp34[0] = 1;
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, (f32 *)arg0->actorData, 1, D_80800510_chlagoonufoext);
        }
        ((u8 *)&arg0->actorData[7])[0] = _subaddieaudioloop_entrypoint_7(((u8 *)&arg0->actorData[7])[0], (f32 *)arg0->actorData, sp34[0], D_80800500_chlagoonufoext, arg0->unk70_0);
        _subaddieaudioquick_entrypoint_4(arg0, (f32 *)arg0->actorData, D_80800524_chlagoonufoext, D_808005A0_chlagoonufoext);
        if (func_800DA298(0xB6) != 0) {
            if ((s32)arg0->actorData[3] != -1) {
                func_800CBB80(arg0->actorData[3], 0);
            }
            func_800FFAB0(arg0);
        }
        break;
    }
}

void func_8080047C_chlagoonufoext(u8 *arg0, s32 arg1)
{
  s32 _subaddieskeleton_entrypoint_3(BtIntPtr, s32, u8 *);
  f32 func_800DF428(f32 distance);
  void func_800DF440(s32 enabled);
  s32 func_80101808(u8 *, s32 *);
  extern s32 func_801015D0;
  if (((((u16) (((Objufoext_arg0 *)arg0)->unk72)) & 0xFFFFFFFF) >> 0xA) != 3)
  {
    func_800DF428(9000.0);
  }
  else
  {
    func_800DF440(0);
  }
  func_80101808(arg0, &func_801015D0);
  _subaddieskeleton_entrypoint_3(((Objufoext_arg0 *)arg0)->unk0, 4, arg0 + 0x18);
}
/* data_to_c.py: from asm/data/overlays/ch/lagoon/ufoext.data.s */
extern u8 D_80800538_chlagoonufoext[];
void func_80102EC0();
void func_80107C2C();
s32 D_80800500_chlagoonufoext [4] BT_DATA(4, overlays_ch_lagoon_ufoext, 0x0) = { 1246704, 1459792, 75536, 983040000 };
u32 D_80800510_chlagoonufoext [5] BT_DATA(4, overlays_ch_lagoon_ufoext, 0x10) = { 0x1304DF, 0x162EE0, 0x1B0102, 0x12710, 0x3A980000 };
u32 D_80800524_chlagoonufoext [5] BT_DATA(4, overlays_ch_lagoon_ufoext, 0x24) = { 0x1304B5, 0xA00D9, 0x1661A8, 0x12710, 0x3A980000 };
u8 D_80800538_chlagoonufoext[32] BT_DATA(4, overlays_ch_lagoon_ufoext, 0x38) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00, 0x01, 0xCD, 0x00, 0x00 };
ActorData D_80800558_chlagoonufoext [1] BT_DATA(4, overlays_ch_lagoon_ufoext, 0x58) = { { 344, 450, 1788, 1, (void *)D_80800538_chlagoonufoext, (void (*)(struct Actor *))func_8080032C_chlagoonufoext, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8080047C_chlagoonufoext, 0, 0, 0, 0, 0, 5126, (void (*)(struct Actor *))func_80800168_chlagoonufoext, 0, 24, 0, (void (*)(struct Actor *))func_808001D8_chlagoonufoext, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800000_chlagoonufoext, 0 } };
u32 D_808005A0_chlagoonufoext [8] BT_DATA(4, overlays_ch_lagoon_ufoext, 0xA0) = { 0x3F07AE14, 0x3F333333, 0x3F47AE14, 0x3F5EB852, 0xBF800000, 0, 0, 0 };
