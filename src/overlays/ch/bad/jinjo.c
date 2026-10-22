#include "common.h"

OSThread *chbadjinjo_entrypoint_0(void)
{
    extern u8 D_80801288_chbadjinjo[];

    return (OSThread *) D_80801288_chbadjinjo;
}

void func_8080000C_chbadjinjo(s32 arg0, f32 arg1[3], s32 arg2) {
    void func_800BA3FC(s32, s32);
    void func_800BA450(s32, s16, s16, s16, s16, s16, s16);
    void func_800BA594(void *, f32, f32);
    void func_800BA5A8(s16 *, s32);
    void func_800BA75C(s32, f32[3]);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA834(s32, s16, s16, s16, s16, s16, s16);
    void func_800BA8F8(void *, f32, f32);

    func_800BA3FC(arg0, 0x9EA);
    func_800BA450(arg0, 0, -250, 0, 0, -250, 0);
    func_800BA594(arg0, 0.4f, 0.8f);
    func_800BA75C(arg0, arg1);
    func_800BA7FC(arg0, 0.03f, 0.03f);
    func_800BA834(arg0, 0, 0, 200, 0, 0, 240);
    func_800BA8F8(arg0, 0.7f, 0.7f);
    func_800BA5A8(arg0, 0x1000);
    func_800BA7C4(arg0, 0.5f, 0.5f);
}

/* extern */

void func_8080010C_chbadjinjo(s32 arg0, f32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    void func_8080000C_chbadjinjo(s32, f32[3], s32);
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = func_800B53A4(0xA);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, arg0, arg2);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + arg1), 0x15E, -5, (s32) (60.0f + arg1), 0x1C2);
    func_800BA22C(sp2C, 0xA);
}

void func_808001B0_chbadjinjo(Actor *arg0, f32 *arg1, f32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    int func_800DC298(f32);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    extern s32 D_808012D0_chbadjinjo;
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = func_800B53A4(4);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, arg1, arg3);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + arg2), 0x32, -5, (s32) (60.0f + arg2), 0x96);
    func_800BA22C(sp2C, 4);
    if (func_800DC298(0.1f) != 0) {
        func_80801090_chbadjinjo(arg0, &D_808012D0_chbadjinjo);
    }
}

f32 func_80800278_chbadjinjo(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 450.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 600.0f;
    default:
        return 0.0f;
    }
}

/* extern */

void func_80800358_chbadjinjo(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 func_800D395C(void);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    f32 func_80800278_chbadjinjo(void);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    if (func_800D395C() != 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddierouteDll_entrypoint_3(arg0, sp24, arg0->position);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
    func_800EE7F8((f32 *)(sp24 + 0x10), arg0->position);
    (*(s8 *)((s8 *)(sp24) + (0x24))) = func_800DC128(0, 9);
    (*(f32 *)((s8 *)(arg0) + (0x30))) = func_80800278_chbadjinjo();
}

void func_808003EC_chbadjinjo(Actor *arg0)
{
  typedef struct 
  {
    u8 pad0[0x1C];
    f32 timer;
    f32 timer2;
    u8 index;
  } JinjoData;
  typedef struct 
  {
    f32 v[3];
  } JinjoVector;
  s32 func_8001210C(s32);
  f32 func_800D8FF8(void);
  void func_800EF04C(f32 *, f32 *);
  f32 func_800F2094(f32, f32);
  void *func_80100094(Actor *, u32);
  s32 func_8010C9B0(f32 *, s32);
  f32 func_8010CD28(Actor *);
  void func_80800E28_chbadjinjo(Actor *, s32);
  extern s32 D_808012D0_chbadjinjo;
  extern s32 D_808012DC_chbadjinjo;
  extern JinjoVector D_80801330_chbadjinjo;
  void func_80801090_chbadjinjo(Actor *, s32 *);
  extern JinjoVector D_8080133C_chbadjinjo;
  volatile JinjoData *data;
  JinjoData *nearData;
  JinjoVector nearPos;
  JinjoData *farData;
  JinjoVector farPos;
  data = func_80100094(arg0, 0);
  if (data->timer > 0.0f)
  {
    data->timer -= func_800D8FF8();
    return;
  }
  data->timer = 0.5f;
  if (!arg0)
  {
  }
  if (!(func_800F2094(arg0->rotation[1], func_8010CD28(arg0)) > 120.0f))
  {
    if (func_8010C9B0(arg0->position, 250))
    {
      nearData = func_80100094(arg0, 0);
      nearPos = D_80801330_chbadjinjo;
      func_800EF04C(nearPos.v, arg0->position);
      func_8080010C_chbadjinjo((s32) nearPos.v, func_8010CD28(arg0), nearData->index);
      func_80801090_chbadjinjo(arg0, &D_808012D0_chbadjinjo);
      arg0->unk58 = 0.5f;
      nearData->timer2 = 0.5f;
      func_80800E28_chbadjinjo(arg0, 6);
      return;
    }
    farData = func_80100094(arg0, 0);
    farPos = D_8080133C_chbadjinjo;
    func_800EF04C(farPos.v, arg0->position);
    func_808001B0_chbadjinjo(arg0, farPos.v, arg0->rotation[1], farData->index);
    if (func_8001210C(7))
    {
      func_80801090_chbadjinjo(arg0, &D_808012DC_chbadjinjo);
    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080059C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800C90_chbadjinjo.s")

void func_80800DF0_chbadjinjo(s32 arg0) 
{
}
s16 func_80800DF8_chbadjinjo(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    extern s16 D_80801384_chbadjinjo[];
    return D_80801384_chbadjinjo[*((u8 *)func_80100094(arg0, 0U) + 0x24)];
}

void func_80800E28_chbadjinjo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_800DA9E4(s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A570(Actor *);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    extern s32 D_808012F8_chbadjinjo;
    typedef struct {
        u8 pad0[0x64];
        u32 flag31 : 1;
        u32 flag30 : 1;
        u32 pad64 : 30;
        u32 pad68;
        u32 pad6C;
        u32 state : 7;
        u32 pad70 : 15;
        u32 previousState : 6;
        u32 pad73 : 4;
    } JinjoFlags;
    void *sp2C;

    sp2C = func_80100094(arg0, 0);
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 1:
        break;
    case 5:
        if (func_800DA9E4(0x57, 1) == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCE8, 3, arg0->position, func_80800DF8_chbadjinjo(arg0));
        }
        func_80801090_chbadjinjo(arg0, &D_808012F8_chbadjinjo);
        ((f32 *)arg0->actorData)[5] = ((f32 *)arg0->actorData)[6];
        break;
    case 6:
        func_800EE7F8((f32 *)arg0->actorData, (f32 *)((u8 *)sp2C + 0x10));
        ((f32 *)arg0->actorData)[5] *= 0.5f;
        break;
    case 7:
        ((JinjoFlags *)arg0)->previousState = 0;
        arg0->unk70_25 = ((JinjoFlags *)arg0)->previousState;
        ((JinjoFlags *)arg0)->flag30 = 0;
        ((JinjoFlags *)arg0)->flag31 = ((JinjoFlags *)arg0)->flag30;
        func_8010A570(arg0);
        _subaddieDll_entrypoint_4(arg0, 1);
        break;
    }
}

/* extern */

s32 func_80800F7C_chbadjinjo(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if (arg0->unk64_29) {
        if (_subaddiejoy_entrypoint_9(arg0, 0, 0) > 0.1f) {
            return 1;
        }
        return 0;
    }
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010C9B0(arg0->position, 0x3E8) != 0) && (_suchase_entrypoint_1(arg0) != 0) && (func_8010C500(arg0) != 0)) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80801054_chbadjinjo(Actor *arg0, s32 *arg1, f32 arg2) {
    s32 func_80101E14(Actor*, f32);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    if (func_80101E14(arg0, arg2) != 0) {
        func_80801090_chbadjinjo(arg0, arg1);
    }
}

void func_80801090_chbadjinjo(Actor *arg0, s32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 *sp20 = arg0->position;
    if (arg0->unk5F == 0) {
        arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        func_800C330C(arg0->unk5F, 3);
    }
    func_800C3058(arg0->unk5F, 0x55F0);
    func_800C31DC(arg0->unk5F, 1.0f);
    func_800C4350(arg0->unk5F, sp20, arg1);
    func_800C3BDC(arg0->unk5F);
}

/* extern */

void func_80801118_chbadjinjo(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}
