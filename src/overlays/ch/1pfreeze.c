#include "common.h"

OSThread *ch1pfreeze_entrypoint_0(void)
{
    extern ActorData D_80800420_ch1pfreeze[];

    return (OSThread *) D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 arg0) 
{
}
/* extern */

void *func_80100094(Actor *, u32);
void func_80800014_ch1pfreeze(Actor *arg0) { if ((s32) arg0->unk70_10 < 4) { func_800F7B9C(*(s32 *)func_80100094(arg0, 0), 0xF); } }

void func_80800054_ch1pfreeze(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F1214(f32, f32, f32);
    s32 func_800F1574(f32 *, f32);
    void func_800FFAB0(Actor *);
    void func_808002D0_ch1pfreeze(Actor *, s32);
    struct {
        s32 unk0;
        s32 color[3];
        s32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 2:
            if (func_800F1574(&data->unk14, func_800D8FF8())) {
                func_808002D0_ch1pfreeze(arg0, 3);
            }
            data->unk1C = 1.0f - data->unk14 / data->unk18;
            break;
        case 4:
            if (func_800F1574(&data->unk14, func_800D8FF8())) {
                func_800FFAB0(arg0);
                return;
            }
            data->unk1C = data->unk14 / data->unk18;
            break;
    }
    data->unk10 = func_800F1214(data->unk1C, 0.0f, 128.0f);
}

void func_8080014C_ch1pfreeze(Actor *arg0, Gfx **arg1)
{
  s32 func_800A89F8();
  void func_800B99CC(Gfx **, s32, s32 *);
  BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F5794(BtIntPtr, f32 *, s32);
  s32 func_800F5ECC(s32);
  void func_80101870(Actor *, void *);
  f32 temp_f0;
  f32 var_f20;
  f32 var_f2;
  s32 temp_s0;
  s32 var_s0;
  struct {
    s32 unk0;
    s32 color[3];
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
  } *temp_s2;
  temp_s2 = func_80100094(arg0, 0U);
  temp_s0 = func_800A89F8();
  if (func_800F5ECC(temp_s2->unk0) != temp_s0)
  {
    var_f20 = 0.0f;
    var_s0 = 0;
    if (arg0->unk70_10 != 4)
    {
      do
      {
        temp_f0 = BT_IDO_ONLY(func_800F5794(temp_s2->unk0, arg0->position, var_s0)) BT_NATIVE_ONLY(((union { s32 i; f32 f; }){ .i = func_800F5794(temp_s2->unk0, arg0->position, var_s0) }).f);
        var_f2 = temp_f0;
        if (var_s0 != 2)
        {
          arg0->rotation[0] = 0.0;
          var_f20 += temp_f0;
        }
        else
        {
          var_f2 = var_f20 * 0.25f;
          arg0->rotation[0] = 90.0f;
        }
        arg0->scale = temp_s2->unk1C * (var_f2 / 75.0f);
        func_80101870(arg0, arg1);
        var_s0 += 1;
      }
      while (var_s0 != 3);
    }
  }
  else
  {
    func_800B99CC(arg1, temp_s2->unk10, temp_s2->color);
  }
}

s32 func_80800294_ch1pfreeze(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808002D0_ch1pfreeze(Actor *, s32);
    switch (arg1) {
        case 0x4:
            func_808002D0_ch1pfreeze(arg0, 0x4);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002D0_ch1pfreeze(Actor *arg0, s32 arg1) {
    void func_800EFA88(void *, s32, s32, s32);
    void func_80103110(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void _sufreezy_entrypoint_4(Unk80132ED0 *, s32);
    struct {
        s32 unk0;
        s32 color[3];
        s32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 2:
            func_800EFA88(data->color, 0x80, 0xC0, 0xFF);
            data->unk10 = 0;
            data->unk14 = 0.25f;
            data->unk18 = 0.25f;
            data->unk1C = 0.0f;
            break;
        case 3:
            func_80103110(arg0, 0);
            break;
        case 4:
            _sufreezy_entrypoint_4(arg0->unk0, 8);
            data->unk14 = 0.25f;
            data->unk18 = 0.25f;
            func_80103110(arg0, 1);
            break;
    }
    func_80101FDC(arg0, arg1);
}

/* extern */

s32 ch1pfreeze_entrypoint_1(s32 arg0) {
    f32 func_800F5F24(BtUIntPtr);
    Actor *sp2C;
    f32 sp20[3];
    void *temp_v0;
    void func_808002D0_ch1pfreeze(Actor *, s32);

    func_800F5A00(arg0, sp20);
    sp2C = func_80108474(0x2C5, sp20, 0);
    temp_v0 = func_80100094(sp2C, 0);
    *(s32 *)temp_v0 = arg0;
    sp2C->rotation[1] = func_800F5F24(arg0);
    func_808002D0_ch1pfreeze(sp2C, 2);
    return (*(s32 *)((s8 *)sp2C + 0));
}
/* data_to_c.py: from asm/data/overlays/ch/1pfreeze.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800420_ch1pfreeze [1] BT_DATA(4, overlays_ch_1pfreeze, 0x0) = { { 344, 709, 1885, 1, 0, (void (*)(struct Actor *))func_80800054_ch1pfreeze, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8080014C_ch1pfreeze, 0, 0, 0, 0, 2, 0, (void (*)(struct Actor *))func_80800014_ch1pfreeze, (BtIntPtr)func_80108ED0, 36, 0, (void (*)(struct Actor *))func_8080000C_ch1pfreeze, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9234, (void (*)(struct Actor *, long, long))func_80800294_ch1pfreeze, 0 } };
