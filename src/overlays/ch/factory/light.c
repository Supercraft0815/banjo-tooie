#include "common.h"

OSThread *chfactorylight_entrypoint_0(void)
{
    extern u8 D_80800B90_chfactorylight[];

    return (OSThread *) D_80800B90_chfactorylight;
}

/* extern */

void func_8080000C_chfactorylight(s32 arg0) {
    s32 func_8010A800(s32, s32);
    s32 func_80800830_chfactorylight();
    func_80800830_chfactorylight();
    func_8010A800(arg0, 0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/light/func_80800038_chfactorylight.s")

void func_80800408_chfactorylight(Actor *arg0) {
    void func_800C8B84(s32);
    void* func_80100094(Actor*, u32);
    u8 *var_s0;
    u8 *temp_v0;
    s32 temp_a0;
    s32 var_s1;

    temp_v0 = func_80100094(arg0, 0U);
    var_s1 = 0;
    var_s0 = temp_v0;
    do {
        temp_a0 = *(s32 *) var_s0;
        if (temp_a0 != 0) {
            func_800C8B84(temp_a0);
            *(s32 *) var_s0 = 0;
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 8);
}

/* extern */

void chfactorylight_entrypoint_1(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor = func_80106790(arg4);
    Vtx *end = arg2 + arg3;

    for (; arg2 < end; arg2++) {
        arg2->v.cn[3] = (u32)(arg1++)->v.cn[3] * actor->unk54;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/light/func_8080057C_chfactorylight.s")

void func_808006B8_chfactorylight(Actor *arg0, s32 arg1) {
    void func_800DF5D8(u32, u32, u32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101808(Actor *, s32 (*)(Actor *));
    s32 func_80101970();
    s32 func_801015D0(Actor *);
    struct LightColor {
        u8 pad[0x10];
        s32 red;
        s32 green;
        s32 blue;
    };
    f32 temp_f0;
    u32 temp_t6;
    struct LightColor *temp_v1;

    temp_v1 = func_80100094(arg0, 0U);
    temp_t6 = arg0->unk70_10;
    if ((temp_t6 == 1) || (temp_t6 == 3)) {
        temp_f0 = arg0->unk54;
        func_800DF5D8((s32) ((f32) temp_v1->red * temp_f0), (s32) ((f32) temp_v1->green * temp_f0), (s32) ((f32) temp_v1->blue * temp_f0), 0xFF);
    }
    func_80101970(arg0);
    func_80101808(arg0, &func_801015D0);
}

void func_80800778_chfactorylight(void *arg0, s32 *arg1)
{
  struct LightSelector
  {
    u8 pad[0x6C];
    u32 unused : 23;
    u32 index : 9;
  };
  u32 var_v0;
  struct ColorChannels
  {
    u32 red;
    u32 green;
    u32 blue;
  };
  switch (((struct LightSelector *) arg0)->index)
  {
    case 0:
      var_v0 = 0xFFFF2000;
      break;

    case 1:
      var_v0 = 0x20FF0000;
      break;

    case 2:
      var_v0 = 0xFF202000;
      break;

    case 3:
      var_v0 = 0x96FF00;
      break;

    case 4:
      var_v0 = 0x20FFFF00;
      break;

    case 5:
      var_v0 = 0xFF802000;
      break;

    case 6:
      var_v0 = 0xFF60FF00;
      break;

    case 7:
      var_v0 = -0x100;
      break;

    default:
      var_v0 = 0xFFFF2000;
      break;

  }

  ((struct ColorChannels *) arg1)->red = var_v0 & 0xFF000000;
  ((struct ColorChannels *) arg1)->green = var_v0 & 0xFF0000;
  ((struct ColorChannels *) arg1)->blue = var_v0 & 0xFF00;
 ((struct ColorChannels *) arg1)->red /= 0x1000000; ((struct ColorChannels *) arg1)->green /= 0x10000; ((struct ColorChannels *) arg1)->blue /= 0x100;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/light/func_80800830_chfactorylight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/light/func_808008E4_chfactorylight.s")
