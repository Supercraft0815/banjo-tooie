#include "common.h"

OSThread *chspotlight_entrypoint_0(void)
{
    extern u8 D_808009B0_chspotlight[];

    return (OSThread *) D_808009B0_chspotlight;
}

void func_8080000C_chspotlight(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8FE0(s32, s32);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808008A4_chspotlight(void *);
    s32 *func_808008EC_chspotlight(u8 *);
    extern f32 D_80800990_chspotlight[];
    extern u32 D_80800998_chspotlight[3];
    struct SpotlightData {
        s32 light;
        s32 unk4[3];
        f32 position[3];
        f32 yaw;
        f32 unk20;
        s32 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        f32 unk34;
        f32 unk38;
    } *data;
    Actor *other;

    data = func_80100094(arg0, 0);
    func_800EE7F8(data->position, arg0->position);
    if (func_800DA298(0x9C) || !func_808008EC_chspotlight((u8 *)arg0)) {
        func_80101FDC(arg0, 5);
    } else if (func_808008A4_chspotlight(arg0)) {
        other = func_80106790(arg0->unk3C);
        func_800EE7F8(data->position, other->position);
        arg0->rotation[1] = arg0->unk54 = func_80102D78(arg0, other->position);
    }
    if ((s32)arg0->unk74_7 < 0x34) {
        data->light = func_800C8A98();
        data->yaw = arg0->rotation[1];
        data->unk20 = 0.0f;
        data->unk24 = 0;
        func_800C8D4C(data->light, D_80800990_chspotlight);
        func_800C8E84(data->light, D_80800998_chspotlight);
        func_800C8CB8(data->light, data->position);
        func_800C8FE0(data->light, 0);
    } else {
        data->light = 0;
    }
    data->unk28 = func_800DC178(0.0f, 360.0f);
    data->unk2C = func_800DC178(20.0f, 60.0f) * (func_800DC298(0.5f) ? 1.0f : -1.0f);
    data->unk30 = func_800DC178(0.0f, 360.0f);
    data->unk34 = func_800DC178(20.0f, 60.0f) * (func_800DC298(0.5f) ? 1.0f : -1.0f);
    data->unk38 = 525.0f;
}

void func_80800210_chspotlight(Actor *arg0)
{
  void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
  void func_800C8FE0(s32, s32);
  f32 func_800D8FF8(void);
  s32 func_800DA298(s32);
  f32 func_800DC178(f32, f32);
  int func_800DC298(f32);
  void *func_80100094(Actor *, u32);
  void func_80101FDC(Actor *, u32);
  void func_80102B2C(Actor *, f32);
  void func_80102B6C(u8 *, f32);
  s32 func_80102CA4(void *);
  s32 func_80102CCC(void *);
  void func_808007F4_chspotlight(Actor *, f32);
  struct SpotlightData
  {
    s32 light;
    s32 unk4[3];
    f32 position[3];
    f32 yaw;
    f32 unk20;
    s32 unk24;
  } *data;
  s32 state;
  f32 intensity;
  data = func_80100094(arg0, 0);
  _sudeflect_entrypoint_1(arg0->position, arg0->scale * 200.0f, 0.0f, arg0->scale * 125.0f, 10);
  state = arg0->unk70_10;
  switch (state)
  {
    case 1:
      if (!arg0->unk70_10)
    {
    }
      if (func_800DA298((arg0->unk74_7 == 0x33) ? (2) : (4)))
    {
      func_80101FDC(arg0, 2);
      data->unk24 = 1;
      if (data->light)
      {
        func_800C8FE0(data->light, 1);
      }
    }
      break;

    case 2:
      intensity = data->unk20;
      intensity += 0.06f;
      if (intensity > 1.0f)
    {
      data->unk20 = (intensity = 1.0f);
      func_80101FDC(arg0, 3);
    }
    else
    {
      data->unk20 = intensity;
      if ((intensity < 0.9f) && func_800DC298(0.6f))
      {
        intensity *= func_800DC178(0.25f, 0.5f);
        data->unk24 = 0;
      }
      else
      {
        data->unk24 = 1;
      }
    }
      func_808007F4_chspotlight(arg0, intensity);
      break;

    case 3:
      func_808007F4_chspotlight(arg0, 1.0f);
      break;

    case 4:
      func_80102B2C(arg0, func_800D8FF8() * 60.0f);
      func_80102B6C((u8 *) arg0, func_800D8FF8() * 60.0f);
      if (func_80102CCC(arg0) && func_80102CA4(arg0))
    {
      arg0->rotation[1] = data->yaw;
      arg0->rotation[0] = 0.0f;
      func_80101FDC(arg0, 5);
    }
      break;

  }

}

/* extern */

void func_8080047C_chspotlight(Actor *arg0) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800DF41C(s32);
    void func_800DF744(s32, s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    s32 func_801040D0(void);
    s32 *sp3C;
    s32 sp38;
    f32 sp2C[3];
    f32 sp1C[4];

    sp3C = func_80100094(arg0, 0);
    sp38 = func_801040D0();
    func_801015D0(arg0);
    func_800DF41C(sp38);
    func_800EFA4C(sp2C, arg0->rotation[0] + 90.0f, 0.0f, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C((u8 **)sp38, 1, sp1C);
    func_800DF744(1, sp3C[9]);
}

/* extern */

void func_80800518_chspotlight(u8 *arg0, s32 arg1) {
    s32 pad[2];
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4);
    void func_800DF47C(s32 arg0, s32 arg1);
    extern s32 func_801017D0;
    void func_80102780(void *arg0, void *arg1);
    s32 func_8010347C(s32);
    f32 sp2C;

    func_80102780(arg0, &sp2C);
    sp2C = 0.0f;
    func_800DF47C((s32) &func_801017D0, (s32) arg0);
    func_800DE448(arg0 + 4, &sp2C, (*(f32 *)((s8 *)(arg0) + (0x38))), NULL, func_8010347C((*(s32 *)((s8 *)(arg0) + (0)))));
}

/* extern */

void func_80800580_chspotlight(Actor *arg0) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 *sp1C;
    Actor *sp18;
    f32 temp_f0;

    sp1C = func_80100094(arg0, 0);
    sp18 = func_80106790(arg0->unk3C);
    temp_f0 = func_800D8FF8();
    sp1C[10] += sp1C[11] * temp_f0;
    sp1C[12] += sp1C[13] * temp_f0;
    sp1C[14] = ((f32 *)sp18->actorData)[4] * 1500.0f;
}

void func_80800600_chspotlight(Actor *arg0, f32 arg1) {
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E84(s32, u32[3]);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    extern u32 D_80800998_chspotlight[3];
    extern u32 D_808009A4_chspotlight[3];
    typedef struct {
        s32 light;
        f32 position[3];
        f32 direction[3];
    } SpotlightData;
    SpotlightData *data;
    u32 sp30[3];
    f32 distance;

    data = func_80100094(arg0, 0);
    distance = func_800EEAD4(arg0->position, data->position);
    func_800EEC30(data->direction, -arg0->rotation[0], arg0->rotation[1], distance);
    func_800EF04C(data->direction, arg0->position);
    if (data->light != 0) {
        func_800F3214(sp30, D_80800998_chspotlight, D_808009A4_chspotlight, arg1);
        func_800C8E84(data->light, sp30);
        func_800C8CB8(data->light, data->direction);
    }
}

void func_808006B8_chspotlight(Actor *arg0) {
    void func_800C8D4C(s32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_80800990_chspotlight[];
    s32 *sp24;
    f32 sp1C[2];
    Actor *temp_v0_2;

    sp24 = func_80100094(arg0, 0);
    if (*sp24 != 0) {
        temp_v0_2 = func_80106790(arg0->unk3C);
        sp1C[0] = D_80800990_chspotlight[0] * ((f32 *)temp_v0_2->actorData)[4];
        sp1C[1] = D_80800990_chspotlight[1] * ((f32 *)temp_v0_2->actorData)[4];
        func_800C8D4C(*sp24, sp1C);
    }
}

void func_80800730_chspotlight(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101038(f32 *);
    s32 func_8010114C(s32, s32, s32);
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);
    f32 angles[2];
    f32 *data;

    data = func_80100094(arg0, 0);
    if (func_800DA298(0) == 0) {
        if (func_8010114C((s32)arg0->unk3C, 6, 4) != 0) {
            func_80101038(data + 1);
        }
        if (func_800DA298(4) != 0) {
            func_800EF214(data + 1, data[10], data[12], data[14]);
        }
        func_800F18FC(arg0->position, data + 1, angles);
        arg0->unk50 = -angles[0];
        arg0->unk54 = angles[1];
        func_80102B2C(arg0, 2.0f);
        func_80102B6C((u8 *)arg0, 2.0f);
    }
}

void func_808007F4_chspotlight(Actor *arg0, f32 arg1) {
    void func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_808008A4_chspotlight(void *);
    f32 *sp24;
    s32 temp_a0;

    sp24 = func_80100094(arg0, 0);
    if (func_808008A4_chspotlight(arg0) == 0) {
        func_80101FDC(arg0, 4);
        arg0->unk50 = 0.0f;
        arg0->unk54 = sp24[7];
        temp_a0 = ((s32 *)sp24)[0];
        ((s32 *)sp24)[9] = 0;
        sp24[8] = 0.0f;
        if (temp_a0 != 0) {
            func_800C8FE0(temp_a0, 0);
        }
    } else {
        func_80800580_chspotlight(arg0);
        func_80800730_chspotlight(arg0);
        func_80800600_chspotlight(arg0, arg1);
        func_808006B8_chspotlight(arg0);
    }
}

/* extern */

s32 func_808008A4_chspotlight(void *arg0) {
    s32 func_800DA298(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x3C))) == 0) {
        return 0;
    }
    if (func_800DA298(3) != 0) {
        return 0;
    }
    return 1;
}

/* extern */

s32 *func_808008EC_chspotlight(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    s32 *temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0(arg0 + 4, 0x13C, -1, 0);
    if (temp_v0 != NULL) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *temp_v0;
    }
    return temp_v0;
}

u32 func_80800934_chspotlight(s32 unused, s32 arg1, s32 arg2) {
    void func_8080047C_chspotlight(Actor *);

    if (arg1 == 0x1F) {
        func_8080047C_chspotlight((Actor *) unused);
        return 1;
    }
    return 0;
}
