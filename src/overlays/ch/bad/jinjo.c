#include "common.h"

OSThread *chbadjinjo_entrypoint_0(void)
{
    extern ActorData D_80801288_chbadjinjo[];

    return (OSThread *) D_80801288_chbadjinjo;
}

void func_8080000C_chbadjinjo(BtIntPtr arg0, f32 arg1[3], s32 arg2) {
    void func_800BA3FC(BtIntPtr, s32);
    void func_800BA450(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA594(void *, f32, f32);
    void func_800BA5A8(s16 *, s32);
    void func_800BA75C(BtIntPtr, f32[3]);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA834(BtIntPtr, s16, s16, s16, s16, s16, s16);
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

void func_8080010C_chbadjinjo(BtIntPtr arg0, f32 arg1, s32 arg2) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    void func_8080000C_chbadjinjo(BtIntPtr, f32[3], s32);
    BtIntPtr sp2C;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(0xA);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, arg0, arg2);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + arg1), 0x15E, -5, (s32) (60.0f + arg1), 0x1C2);
    func_800BA22C(sp2C, 0xA);
}

void func_808001B0_chbadjinjo(Actor *arg0, f32 *arg1, f32 arg2, s32 arg3) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    int func_800DC298(f32);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    extern s32 D_808012D0_chbadjinjo[3];
    BtIntPtr sp2C;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(4);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, arg1, arg3);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + arg2), 0x32, -5, (s32) (60.0f + arg2), 0x96);
    func_800BA22C(sp2C, 4);
    if (func_800DC298(0.1f) != 0) {
        func_80801090_chbadjinjo(arg0, D_808012D0_chbadjinjo);
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
}    typedef struct { u8 pad0[0x24]; s8 unk24; } Objjinjo_func_80800358_chbadjinjo_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

/* extern */

void func_80800358_chbadjinjo(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
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
    (((Objjinjo_func_80800358_chbadjinjo_sp24 *)sp24)->unk24) = func_800DC128(0, 9);
    (*(f32 *)((s8 *)(arg0) + (0x30))) = func_80800278_chbadjinjo();
}
typedef struct { f32 v[3]; } JinjoVector;
void func_808003EC_chbadjinjo(Actor *arg0)
{
  typedef struct 
  {
    u8 pad0[0x1C];
    f32 timer;
    f32 timer2;
    u8 index;
  } JinjoData;




  s32 func_8001210C(s32);
  f32 func_800D8FF8(void);
  void func_800EF04C(f32 *, f32 *);
  f32 func_800F2094(f32, f32);
  void *func_80100094(Actor *, u32);
  s32 func_8010C9B0(f32 *, s32);
  f32 func_8010CD28(Actor *);
  void func_80800E28_chbadjinjo(Actor *, s32);
  extern s32 D_808012D0_chbadjinjo[3];
  extern s32 D_808012DC_chbadjinjo[3];
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
      func_8080010C_chbadjinjo((BtIntPtr) nearPos.v, func_8010CD28(arg0), nearData->index);
      func_80801090_chbadjinjo(arg0, D_808012D0_chbadjinjo);
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
      func_80801090_chbadjinjo(arg0, D_808012DC_chbadjinjo);
    }
  }
}
typedef struct Vec3s32 { f32 x, y, z; } Vec3s32;
void func_8080059C_chbadjinjo(Actor *arg0) {



    typedef struct {
        u8 pad0[6];
        u16 route;
        u32 unk8;
        u32 current;
        f32 position[3];
        f32 timer;
        f32 timer2;
    } JinjoRoute;
    typedef struct {
        u8 pad0[0x24];
        BT_BITFIELD_ORDER(u32 id : 10, u32 flags : 22);
        BT_BITFIELD_ORDER(u32 flags : 22, u32 id : 10);
    } JinjoMarker;
    typedef struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 29, u32 pad78_0 : 2);
        u32 inactive : 1;
        BT_BITFIELD_ORDER(u32 pad78_0 : 2, u32 pad78 : 29);
        u8 pad7C[0x10];
        s16 animation;
    } JinjoFlags;
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddiefade_entrypoint_3(Actor *);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    s32 func_800901CC(f32 *, f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    f32 func_800F3780(f32, u8 *, s16);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    void func_80102424(Actor *, s32);
    void func_801026CC(Actor *, Vec3s32, f32);
    void func_80102BF8(Actor *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_80105230(Actor *arg0, f32 *arg1);
    s32 func_80107070(Actor *, s32);
    s32 func_8010C3A8(Actor *arg0, u32 arg1, f32 arg2);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D254(f32 *);
    void func_8010D690(Actor *);
    void func_80800E28_chbadjinjo(Actor *, s32);
    s32 func_80800F7C_chbadjinjo(Actor *);
    void func_80801054_chbadjinjo(Actor *, s32 *, f32);
    void func_80801118_chbadjinjo(void *);
    extern s32 D_80801308_chbadjinjo[7];
    extern s32 D_80801324_chbadjinjo[3];
    extern u8 D_80801348_chbadjinjo[];
    extern Vec3s32 D_80801370_chbadjinjo;
    extern f32 D_8080137C_chbadjinjo[];
    JinjoRoute *sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp3C[3];
    f32 dt;
    f32 sp34;

    sp54 = func_80100094(arg0, 0);
    sp50 = 1.0f;
    dt = func_800D8FF8();
    if (((JinjoFlags *)arg0)->inactive) {
        func_80801118_chbadjinjo(arg0);
        return;
    }
    if (sp54->timer2 > 0.0f) {
        sp54->timer2 -= dt;
        ((JinjoMarker *)arg0->unk0)->id = 0x232;
    } else {
        ((JinjoMarker *)arg0->unk0)->id = 0x231;
    }
    func_800D9078(&arg0->unk58);
    func_8010D254(sp3C);
    func_800F1E6C(arg0->position, sp3C, &sp4C);
    sp48 = func_800F1DCC(arg0->rotation[1], sp4C);
    if (((JinjoFlags *)arg0)->animation != 0) {
        sp50 = func_800F3780(func_80101F24(arg0), D_80801348_chbadjinjo, 5);
    }
    switch (arg0->unk70_10) {
    case 1:
        if (func_800DC0C0() < 0.015f) {
            if (func_800901CC(arg0->position, 55.0f)) {
                func_80102424(arg0, 3);
            } else {
                func_80102424(arg0, 2);
            }
        }
        if (func_80800F7C_chbadjinjo(arg0)) {
            func_80800E28_chbadjinjo(arg0, 5);
        }
        break;
    case 2:
        func_80801054_chbadjinjo(arg0, D_80801308_chbadjinjo, 0.2f);
        if (func_80101E14(arg0, 0.999f)) {
            func_80800E28_chbadjinjo(arg0, 1);
        }
        break;
    case 3:
        func_80801054_chbadjinjo(arg0, D_80801324_chbadjinjo, 0.2f);
        if (func_80101E14(arg0, 0.999f)) {
            func_80800E28_chbadjinjo(arg0, 1);
        }
        break;
    case 4:
        func_80105230(arg0, D_8080137C_chbadjinjo);
        if (func_80101E14(arg0, 0.999f)) {
            func_80800E28_chbadjinjo(arg0, 1);
        } else if (sp48 >= 0.0f) {
            arg0->rotation[1] -= 80.0f * func_800D8FF8();
        } else {
            arg0->rotation[1] += 80.0f * func_800D8FF8();
        }
        break;
    case 5:
        func_8010D254((f32 *)arg0->actorData);
        if (arg0->unk64_29) {
            sp34 = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
            ((f32 *)arg0->actorData)[3] = ((f32 *)arg0->actorData)[5];
            func_80102BF8(arg0, 0.2f, 8.0f, 500.0f);
            func_8010C3A8(arg0, 0x205015, sp34 * sp50);
            if (_subaddiejoy_entrypoint_9(arg0, NULL, 0) < 0.05f) {
                func_80800E28_chbadjinjo(arg0, 1);
            }
            func_808003EC_chbadjinjo(arg0);
        } else {
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                _subaddierouteDll_entrypoint_7(arg0, sp54, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
                sp54->current = sp54->route;
            }
            _subaddierouteDll_entrypoint_5(arg0, sp54, sp54->current, 0.15f, 8.0f, 200.0f);
            ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], func_800D8FF8() * 400.0f);
            func_801026CC(arg0, D_80801370_chbadjinjo, ((f32 *)arg0->actorData)[3]);
            func_8010C3A8(arg0, 0x305115, sp50);
            func_808003EC_chbadjinjo(arg0);
            if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) && (!func_8010C9B0(arg0->position, 1000) || !func_8010C500(arg0))) {
                func_80800E28_chbadjinjo(arg0, 6);
            }
        }
        break;
    case 6:
        if (func_80800F7C_chbadjinjo(arg0)) {
            func_80800E28_chbadjinjo(arg0, 5);
        }
        if (_subaddierouteDll_entrypoint_4(arg0)) {
            arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            _subaddierouteDll_entrypoint_7(arg0, sp54, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
            sp54->current = sp54->route;
        }
        _subaddierouteDll_entrypoint_5(arg0, sp54, sp54->current, 0.15f, 8.0f, 200.0f);
        ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], func_800D8FF8() * 400.0f);
        func_801026CC(arg0, D_80801370_chbadjinjo, ((f32 *)arg0->actorData)[3]);
        func_8010C3A8(arg0, 0x305115, sp50);
        if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) && func_800EFFB4(arg0->position, 100.0f, sp54->position)) {
            func_80800E28_chbadjinjo(arg0, 1);
        }
        break;
    case 7:
        if (func_80101DDC(arg0)) {
            _subaddieDll_entrypoint_4(arg0, 0);
            if (!func_80107070(arg0, 2)) {
                _subaddiefade_entrypoint_3(arg0);
            }
        }
        break;
    }
    if (func_801022E4(arg0) == 0x1AD) {
        func_80105230(arg0, NULL);
    }
    if (!arg0->unk64_29 && (s32)arg0->unk70_10 < 4 && (sp48 > 45.0f || sp48 < -45.0f)) {
        func_80102424(arg0, 4);
    }
    if ((s32)arg0->unk70_10 < 8) {
        func_8010D690(arg0);
    }
    func_80801118_chbadjinjo(arg0);
}

s32 func_80800C90_chbadjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80101074(void *);
    s32 func_801015D0(Actor *);
    s32 func_80103140(Actor *, u32, u16);
    s32 func_80107070(Actor *, s32);
    void func_80800E28_chbadjinjo(Actor *, s32);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    extern s32 D_8080124C_chbadjinjo[15];
    extern s32 D_808012E8_chbadjinjo[4];
    void *sp1C;

    switch (arg1) {
    case 0x95:
        sp1C = func_80100094(arg0, 0);
        _subaddierouteDll_entrypoint_1(arg0);
        func_80103140(arg0, 0x643, *((u8 *)sp1C + 0x24) + 0xC31);
        break;
    case 0x40:
        func_80801090_chbadjinjo(arg0, D_808012E8_chbadjinjo);
        func_80800E28_chbadjinjo(arg0, 7);
        break;
    case 1:
        func_80800E28_chbadjinjo(arg0, 5);
        break;
    case 2:
        if (_subaddieDll_entrypoint_3(arg0) == 0) {
            if (func_80107070(arg0, 1) == 0) {
                _subaddiefade_entrypoint_3(arg0);
            }
        } else {
            func_80800E28_chbadjinjo(arg0, 6);
        }
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 2);
        break;
    case 0x38:
        func_80101074(D_8080124C_chbadjinjo);
        return 5;
    case 0x4D:
        if (func_80107070(arg0, 3) == 0) {
            return 0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800DF0_chbadjinjo(s32 arg0) 
{
}
s16 func_80800DF8_chbadjinjo(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    extern s16 D_80801384_chbadjinjo[];
    return D_80801384_chbadjinjo[*((u8 *)func_80100094(arg0, 0U) + 0x24)];
}    typedef struct { u8 pad0[0x10]; f32 unk10; } Objjinjo_func_80800E28_chbadjinjo_sp2C; /* offsets.py genstruct: fields from raw offsets on sp2C; rename once understood */

void func_80800E28_chbadjinjo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_800DA9E4(s32, s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_80801090_chbadjinjo(Actor *, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A570(Actor *);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    extern s32 D_808012F8_chbadjinjo[4];
    typedef struct {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 flag31 : 1, u32 pad64 : 30);
        u32 flag30 : 1;
        BT_BITFIELD_ORDER(u32 pad64 : 30, u32 flag31 : 1);
        u32 pad68;
        u32 pad6C;
        BT_BITFIELD_ORDER(u32 state : 7, u32 pad73 : 4);
        BT_BITFIELD_ORDER(u32 pad70 : 15, u32 previousState : 6);
        BT_BITFIELD_ORDER(u32 previousState : 6, u32 pad70 : 15);
        BT_BITFIELD_ORDER(u32 pad73 : 4, u32 state : 7);
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
        func_80801090_chbadjinjo(arg0, D_808012F8_chbadjinjo);
        ((f32 *)arg0->actorData)[5] = ((f32 *)arg0->actorData)[6];
        break;
    case 6:
        func_800EE7F8((f32 *)arg0->actorData, &((Objjinjo_func_80800E28_chbadjinjo_sp2C *)sp2C)->unk10);
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
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
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

    temp_a1 = (((Actor *)arg0)->unk5F);
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((((Actor *)arg0)->unk5F));
        (((Actor *)arg0)->unk5F) = 0U;
    }
}
/* data_to_c.py: from asm/data/overlays/ch/bad/jinjo.data.s */
extern u8 D_808011F4_chbadjinjo[];
void func_80105834(Actor*);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
extern u8 D_808011E0_chbadjinjo[];
u8 D_808011E0_chbadjinjo[20] BT_DATA(4, overlays_ch_bad_jinjo, 0x0) = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00 };
u8 D_808011F4_chbadjinjo[88] BT_DATA(4, overlays_ch_bad_jinjo, 0x14) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x44, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x42, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x42, 0x3F, 0x40, 0x00, 0x00, 0x00, 0x31, 0x00, 0x42, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xAD, 0x04, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xAD, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x01 };
s32 D_8080124C_chbadjinjo[15] BT_DATA(4, overlays_ch_bad_jinjo, 0x6C) = { 42, 1066192077, 16580608, 30, 1061158912, 35389440, 16, 1061158912, 34471936, 20, 1061158912, 35127296, 6, 1061158912, 34209792 };
ActorData D_80801288_chbadjinjo [1] BT_DATA(4, overlays_ch_bad_jinjo, 0xA8) = { { 561, 412, 1603, 1, (void *)D_808011F4_chbadjinjo, (void (*)(struct Actor *))func_8080059C_chbadjinjo, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 131072000, 1061997773, 0, 0, 644, 801, (void (*)(struct Actor *))func_80800DF0_chbadjinjo, (BtIntPtr)func_80108ED0, 40, 0, (void (*)(struct Actor *))func_80800358_chbadjinjo, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32718, 20493, (void (*)(struct Actor *, long, long))func_80800C90_chbadjinjo, (BtIntPtr)D_808011E0_chbadjinjo } };
s32 D_808012D0_chbadjinjo[3] BT_DATA(4, overlays_ch_bad_jinjo, 0xF0) = { 1246384, 1463792, 0 };
s32 D_808012DC_chbadjinjo[3] BT_DATA(4, overlays_ch_bad_jinjo, 0xFC) = { 1246383, 1463792, 0 };
s32 D_808012E8_chbadjinjo[4] BT_DATA(4, overlays_ch_bad_jinjo, 0x108) = { 1246740, 655846, 1463792, 0 };
s32 D_808012F8_chbadjinjo[4] BT_DATA(4, overlays_ch_bad_jinjo, 0x118) = { 1246386, 655744, 1463792, 0 };
s32 D_80801308_chbadjinjo[7] BT_DATA(4, overlays_ch_bad_jinjo, 0x128) = { 1246223, 1463792, 0, 1246266, 655744, 1474559, 0 };
s32 D_80801324_chbadjinjo[3] BT_DATA(4, overlays_ch_bad_jinjo, 0x144) = { 1246234, 1463792, 0 };
JinjoVector D_80801330_chbadjinjo BT_DATA(4, overlays_ch_bad_jinjo, 0x150) = { { 0.0f, 75.0f, 0.0f } };
JinjoVector D_8080133C_chbadjinjo BT_DATA(4, overlays_ch_bad_jinjo, 0x15C) = { { 0.0f, 75.0f, 0.0f } };
u8 D_80801348_chbadjinjo [40] BT_DATA(4, overlays_ch_bad_jinjo, 0x168) = { 0, 0, 0, 0, 0x3F, 0x59, 0x99, 0x9A, 0x3E, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0, 0, 0, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x40, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x59, 0x99, 0x9A };
Vec3s32 D_80801370_chbadjinjo BT_DATA(4, overlays_ch_bad_jinjo, 0x190) = { 0.9f, -0.002f, 0.3f };
f32 D_8080137C_chbadjinjo [2] BT_DATA(4, overlays_ch_bad_jinjo, 0x19C) = { 0.6f, -1.0f };
s16 D_80801384_chbadjinjo [14] BT_DATA(4, overlays_ch_bad_jinjo, 0x1A4) = { 43, 44, 45, 46, 134, 135, 136, 137, 138, 0, 0, 0, 0, 0 };
