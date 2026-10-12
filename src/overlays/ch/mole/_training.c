#include "common.h"

/* extern */

void func_80800000_chmole_training(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _gcnewoption_entrypoint_6(Actor *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
}

void func_80800034_chmole_training(Actor *arg0, s32 arg1)
{
  void *func_80100094(Actor *, u32);
  s32 _gcnewoption_entrypoint_1(u8 *, s32);
  u32 temp_t6;
  temp_t6 = (u16) (*((u16 *) (((s8 *) arg0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  if (((temp_t6 == 5) || (temp_t6 == 7)) || (temp_t6 == 6))
  {
    _gcnewoption_entrypoint_1(func_80100094(arg0, 0U), arg1);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800088_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800270_chmole_training.s")

/* extern */

void func_808003D4_chmole_training(void *arg0) {
    void _sumole_entrypoint_19(void *, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);

    switch ((u32) (*(f32 *)((s8 *)(arg0) + (0x54)))) {
    case 6:
        if (func_800DA298(0x53) == 0) {
            func_800DA3B8(0x53, 1);
            return;
        }
    default:
        return;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        _sumole_entrypoint_19(arg0, 3);
        (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 0xC);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_808004D0_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/chmole_training_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_808008E4_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800988_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800A48_chmole_training.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_training/func_80800BA8_chmole_training.s")

void func_80800C28_chmole_training(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 0x34);
}

void func_80800C3C_chmole_training(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x54))) = (s32) (*(f32 *)((s8 *)(arg0) + (0x48)));
    (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 4);
}

void func_80800C70_chmole_training(Actor *arg0) {
    void _sumole_entrypoint_0(Actor*, u32);
    arg0->unk54 = (f32) (s32) arg0->rotation[1];
    _sumole_entrypoint_0(arg0, 1U);
}

OSThread *chmole_training_entrypoint_1(void)
{
    extern u8 D_80800F30_chmole_training[];

    return (OSThread *) D_80800F30_chmole_training;
}
