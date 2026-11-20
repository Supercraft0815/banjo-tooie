#include "common.h"

void chhoneyb_entrypoint_2(BT_NATIVE_ONLY(Gfx **) BT_IDO_ONLY(s32) arg0, BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) arg1, s32 arg2, s32 arg3)
{
  s32 _scinfobar_entrypoint_11(void *arg0);
  s32 _scinfobar_entrypoint_14(s32 *arg0);
  f32 _scinfobar_entrypoint_18(f32 *arg0);
  s32 _scinfobar_entrypoint_19(s32 *arg0);
  s32 _scinfobar_entrypoint_20(s32 *arg0);
  BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) func_800D674C(s32);
  void func_800E253C(f32);
  void func_800E257C(s32);
  void func_800E30E0(BtIntPtr arg0, void *arg1, s32 arg2, void *arg3);
  BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) image;
  s32 limit;
  f32 scale;
  f32 fraction;
  s32 count;
  s32 alpha;
  union
  {
    s32 i;
    f32 f;
  } value;
  s32 i;
  s32 x;
  s32 previous;
  s32 pos[2];
  s32 initialWidth;
  s32 y;
  int new_var;
  initialWidth = 40;
  image = func_800D674C(0xB4D);
  limit = _scinfobar_entrypoint_11(arg1);
  scale = _scinfobar_entrypoint_18(arg1);
  value.i = _scinfobar_entrypoint_14(arg1);
  fraction = value.f;
  value.i = _scinfobar_entrypoint_19(arg1);
  count = _scinfobar_entrypoint_20(arg1);
  y = (s32) (initialWidth * scale);
  if (limit < y)
  {
    alpha = (s32) ((1.0f - (((f32) (y - limit)) / y)) * 256.0f);
  }
  else
  {
    alpha = 256;
  }
  for (i = count - 1; i >= 0; i--)
  {
    x = (s32) ((40 + (i * 20)) * scale);
    if (i < value.i)
    {
      previous = i + 1;
      if ((value.i == previous) && (fraction < 1.0f))
      {
        i--;
        previous = (s32) ((40 + (i * 20)) * scale);
        i++;
        x = (s32) (previous + (fraction * (x - previous)));
      }
      new_var = alpha * 255;
      if (limit < x)
      {
        x = limit;
      }
      func_800E257C(new_var >> 8);
      func_800E253C(scale);
      pos[0] = (arg2 + x) * 4;
      pos[1] = arg3 << 2;
      func_800E30E0(BT_NATIVE_ONLY((BtIntPtr))arg0, image, 0, pos);
    }
  }

}
