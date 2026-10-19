#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_80800000_chlagoonufoext.s")

/* extern */

void func_80800168_chlagoonufoext(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void *func_80100094(Actor *, u32);
    (*(u8 *)((s8 *)(arg0) + (0x34))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x34))));
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0));
    }
}

OSThread *chlagoonufoext_entrypoint_0(void)
{
    extern u8 D_80800558_chlagoonufoext[];

    return (OSThread *) D_80800558_chlagoonufoext;
}

void func_808001D8_chlagoonufoext(Actor *arg0) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
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
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
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
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
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
  s32 _subaddieskeleton_entrypoint_3(s32, s32, u8 *);
  s32 func_800DF428(f32);
  s32 func_800DF440(s32);
  s32 func_80101808(u8 *, s32 *);
  extern s32 func_801015D0;
  if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) != 3)
  {
    func_800DF428(9000.0);
  }
  else
  {
    func_800DF440(0);
  }
  func_80101808(arg0, &func_801015D0);
  _subaddieskeleton_entrypoint_3(*((s32 *) (((s8 *) arg0) + 0)), 4, arg0 + 0x18);
}
