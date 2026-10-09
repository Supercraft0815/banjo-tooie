#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/flicker/vpflicker_entrypoint_0.s")

void vpflicker_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/flicker/vpflicker_entrypoint_2.s")

void vpflicker_entrypoint_3(f32 *arg0, s16 arg1, Vtx *arg2, s32 arg3)
{
  Vtx *end = arg2 + arg3;
  f32 scale = *arg0;
  s32 more;
  if (arg2 < end)
  {
 do { for (;;) { arg2->v.cn[0] *= scale; arg2->v.cn[1] *= scale; arg2->v.cn[2] *= scale; arg2++; more = arg2 < end; if (!more) { return; } } } while (0);
  }
}
