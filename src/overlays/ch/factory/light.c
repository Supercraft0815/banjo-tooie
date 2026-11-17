#include "common.h"

OSThread *chfactorylight_entrypoint_0(void)
{
    extern ActorData D_80800B90_chfactorylight[];

    return (OSThread *) D_80800B90_chfactorylight;
}

/* extern */

void func_8080000C_chfactorylight(BtIntPtr arg0) {
    void func_8010A800(void **arg0, s32 arg1);
    void func_80800830_chfactorylight();
    func_80800830_chfactorylight();
    func_8010A800(arg0, 0x2);
}

void func_80800038_chfactorylight(Actor *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    s32 _subaddiezone_entrypoint_1(void *);
    f32 func_800136E4(f32);
    void func_800C4140(u32, f32 *, u32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    int func_800D9154(f32 *, f32);
    s32 func_800E3E8C(f32 *, f32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFD3C(u32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    void func_800F2E60(s32 arg0[3], s32 arg1[3]);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    BtIntPtr func_801065A4(void *);
#ifdef BT_NATIVE
    void chfactorylight_entrypoint_1(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chfactorylight_entrypoint_1;
#endif
    typedef struct {
        f32 unk18[3];
        f32 timer;
        f32 unk28[3];
        f32 speed;
    } LightActorData;
    typedef struct {
        s32 lights[2];
        f32 angles[2];
        u32 color[3];
    } LightData;
    u32 sp6C[3];
    LightData *sp68;
    s32 i;
    f32 sp58[3];
    f32 sp54;
    s32 sp50;
    u32 sp44[3];

    sp68 = func_80100094(arg0, 0);
    sp54 = func_800D8FF8();
    func_800EE7F8(sp58, arg0->position);
    func_800EF1B8(sp58, arg0->rotation[1], arg0->scale * 300.0f);
    sp50 = func_800E3E8C(sp58, arg0->scale * 1300.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_800F2E60(sp6C, sp68->color);
            arg0->unk54 = 1.0f;
            break;
        case 2:
            func_800EFD3C(sp6C);
            arg0->unk54 = 0.0f;
            break;
        case 3:
            if (func_800D90A4(&arg0->unk58)) {
                func_80101FDC(arg0, 1);
            }
            arg0->unk54 = func_800F10B4(arg0->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
            func_800EFD3C(sp44);
            func_800F3214(sp6C, sp44, sp68->color, arg0->unk54);
            break;
    }
    arg0->rotation[2] = func_800136E4(arg0->rotation[2] + sp54 * ((LightActorData *)arg0->actorData)->speed * arg0->unk54);
    if (arg0->unk78 && !_subaddiezone_entrypoint_1(arg0)) {
        sp50 = 0;
    }
    for (i = 0; i < 2; i++) {
        sp68->angles[i] = func_800136E4(sp68->angles[i] + sp54 * ((LightActorData *)arg0->actorData)->speed * arg0->unk54);
        func_800EEC30(sp58, sp68->angles[i], arg0->rotation[1] + 90.0f, arg0->scale * 500.0f);
        func_800EF04C(sp58, arg0->position);
        func_800EF1B8(sp58, arg0->rotation[1], arg0->scale * 300.0f);
        if (sp50) {
            func_800C8CB8(sp68->lights[i], sp58);
            func_800C8E84(sp68->lights[i], sp6C);
        }
    }
    if (arg0->unk7C_12 && func_801065A4(arg0)) {
        _glid_entrypoint_0(func_801065A4(arg0), 1, &_chfactorylight_entrypoint_1, (BtIntPtr)arg0->unk0);
    }
    if (func_800EA05C() == 0x10D && (arg0->unk70_10 == 3 || arg0->unk70_10 == 1) && func_800D9154(&((LightActorData *)arg0->actorData)->timer, 1.3f)) {
        func_800C4140(((u16)(u32)(func_800F1214(arg0->unk54, 0.9f, 1.1f) * 1023.0f) << 21) + 0x1F4566, arg0->position, 0x138800FA);
    }
}

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

s32 func_8080057C_chfactorylight(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800C8FE0(s32, s32);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_808008E4_chfactorylight(Actor *);
    struct LightActorFlags {
        u8 pad[0x7C];
        u32 upper : 16;
        u32 initialized : 1;
        u32 lower : 15;
    };
    void *data;
    s32 i;
    u8 *ptr;
    s32 enabled;

    switch (arg1) {
        case 0xA:
            if (arg2 != 0) {
                enabled = 1;
            } else {
                enabled = 0;
            }
            data = func_80100094(arg0, 0);
            if (!((struct LightActorFlags *)arg0)->initialized) {
                func_808008E4_chfactorylight(arg0);
                ((struct LightActorFlags *)arg0)->initialized = 1;
            }
            if (func_800EA05C() == 0x10D) {
                func_80101FDC(arg0, enabled ? 3 : 2);
                arg0->unk58 = 5.0f;
                ((f32 *)arg0->actorData)[3] = 1.3f;
            } else {
                func_80101FDC(arg0, enabled ? 1 : 2);
            }
            for (i = 0, ptr = data; i != 8; i += 4, ptr += 4) {
                func_800C8FE0(*(s32 *)ptr, enabled);
            }
            break;
        case 0x95:
            func_808008E4_chfactorylight(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

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

void func_80800830_chfactorylight(Actor *arg0) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80103014(u8 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EE7F8(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], 100.0f);
    func_800EE7F8(sp30, arg0->position);
    func_800EF1B8(sp30, arg0->rotation[1], -200.0f);
    if (func_800BEF00(sp3C, sp30, sp24, arg0->unk14) != 0) {
        func_800EE7F8(arg0->position, sp30);
        func_800EF1B8(arg0->position, arg0->rotation[1], arg0->scale * 5.0f);
        func_80103014((u8 *)arg0);
    }
}

void func_808008E4_chfactorylight(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    void func_800C8FE0(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DC128(s32, s32);
    s32 func_800EA05C(void);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    struct LightData {
        s32 handles[2];
        f32 angles[2];
        u32 color[3];
    };
    struct LightActorData {
        f32 values[8];
    };
    struct LightData *sp94;
    f32 temp_f20;
    f32 sp84[3];
    u32 *temp_s6;
    s32 i;
    s32 index;

    sp94 = func_80100094(arg0, 0);
    index = arg0->unk74_7 - 50;
    if (index < 0 || index >= 8) {
        index = 0;
    }
    arg0->unk6C_0 = index;
    ((struct LightActorData *)arg0->actorData)->values[7] = func_800DC128(200, 300);
    temp_s6 = sp94->color;
    func_80800778_chfactorylight(arg0, (s32 *)temp_s6);
    for (i = 0; i != 2; i++) {
        sp94->handles[i] = func_800C8A98();
        temp_f20 = (f32)i * 180.0f;
        sp94->angles[i] = temp_f20;
        func_800C8E84(sp94->handles[i], temp_s6);
        func_800EEC30(sp84, temp_f20, arg0->rotation[1] + 90.0f, arg0->scale * 500.0f);
        func_800EF04C(sp84, arg0->position);
        func_800EF1B8(sp84, arg0->rotation[1], arg0->scale * 300.0f);
        func_800C8CB8(sp94->handles[i], sp84);
        func_800C8E54(sp94->handles[i], arg0->scale * 350.0f, arg0->scale * 800.0f);
    }
    if (func_800EA05C() == 0x10D) {
        if (func_800DA298(0x1BD) != 0) {
            func_80101FDC(arg0, 1);
            func_800C8FE0(sp94->handles[0], 1);
            func_800C8FE0(sp94->handles[1], 1);
            ((struct LightActorData *)arg0->actorData)->values[3] = 1.3f;
        } else {
            func_80101FDC(arg0, 2);
            func_800C8FE0(sp94->handles[0], 0);
            func_800C8FE0(sp94->handles[1], 0);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ch/factory/light.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800B90_chfactorylight [1] BT_DATA(4, overlays_ch_factory_light, 0x0) = { { 675, 935, 1859, 1, 0, (void (*)(struct Actor *))func_80800038_chfactorylight, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808006B8_chfactorylight, 0, 0, 0, 0, 0, 23552, (void (*)(struct Actor *))func_80800408_chfactorylight, 0, 28, 0, (void (*)(struct Actor *))func_8080000C_chfactorylight, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_8080057C_chfactorylight, 0 } };
