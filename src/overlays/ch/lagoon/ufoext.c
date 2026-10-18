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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_8080032C_chlagoonufoext.s")

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
