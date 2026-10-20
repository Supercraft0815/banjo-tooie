#include "common.h"

typedef struct player_state_s PlayerState;

OSThread *chhoopswoop_entrypoint_0(void)
{
    extern u8 D_80801EC0_chhoopswoop[];

    return (OSThread *) D_80801EC0_chhoopswoop;
}

OSThread *chhoopswoop_entrypoint_1(void)
{
    extern u8 D_80801F08_chhoopswoop[];

    return (OSThread *) D_80801F08_chhoopswoop;
}

OSThread *chhoopswoop_entrypoint_2(void)
{
    extern u8 D_80801F50_chhoopswoop[];

    return (OSThread *) D_80801F50_chhoopswoop;
}

/* extern */

void func_80800024_chhoopswoop(void *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    void func_800946C4(PlayerState *, s32);
    s32 func_800DA524(s32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F54E4();
    s32 func_80800094_chhoopswoop(void *);
    func_800946C4(func_800F53D0(func_800F54E4()), 1);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    func_80800094_chhoopswoop(arg0);
    _susubgame_entrypoint_11(0);
}

s32 func_80800094_chhoopswoop(void *arg0) {
    typedef struct {
        s16 rotation : 15;
        u16 active : 1;
        s16 position[3];
        f32 time;
    } Hoop;
    typedef struct {
        s32 count;
        u8 unk4[0x10];
        Hoop hoops[100];
    } HoopData;
    void *func_80100094(Actor *, u32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void func_800EE814(s16[3], s16[3]);
    Prop *props[100];
    HoopData *data;
    HoopData *cursor;
    Prop **prop;
    s16 *position;
    s32 i;

    data = func_80100094(arg0, 0);
    data->count = _gccubesearch_entrypoint_9(0x154, props, 100);
    i = 0;
    if (data->count > 0) {
        cursor = data;
        position = data->hoops[0].position;
        prop = props;
        do {
            func_800EE814(position, (*prop)->position);
            i++;
            cursor->hoops[0].rotation = (*prop)->FlagOrRotation;
            cursor->hoops[0].time = 0.0f;
            cursor->hoops[0].active = 0;
            cursor = (HoopData *)((u8 *)cursor + sizeof(Hoop));
            position += 6;
            prop++;
        } while (i < data->count);
    }
}

void func_8080016C_chhoopswoop(Actor *arg0) {
    typedef struct {
        s16 rotation : 15;
        u16 active : 1;
        s16 position[3];
        f32 time;
    } UpdateHoop;
    typedef struct {
        s32 count;
        s32 score;
        s32 unk8;
        s32 dialog;
        s32 dialogArg;
        UpdateHoop hoops[100];
        u8 game[0x534];
        f32 timer;
    } UpdateHoopData;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800CEAD0(s32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    int func_800D9154(f32 *, f32);
    f32 func_800DC178(f32, f32);
    s32 func_800F54E4(void);
    void func_800F7ECC(s32, s32, f32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_808007A4_chhoopswoop(void *, s32 *);
    s32 i;
    s32 score;
    UpdateHoopData *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
        case 2:
        case 6:
            break;
        case 3:
            score = data->score;
            func_800D24E8(0xC2, score, 0);
            for (i = 0; i < data->count; i++) {
                func_800D90A4(&data->hoops[i].time);
            }
            if (func_800D9154(&arg0->unk58, func_800DC178(0.5f, 1.0f))) {
                func_80108B04(arg0, -1);
            }
            if (func_800CEAD0(arg0->unk6C_0)) {
                data->dialog = func_808007A4_chhoopswoop(arg0, &data->dialogArg);
                func_800F7ECC(func_800F54E4(), 3, 0.0f);
                func_800F8300(func_800F54E4(), 2, 0);
                data->timer = 3.0f;
                func_80101FDC(arg0, 4);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9() || func_800D9078(&data->timer)) {
                _susubgame_entrypoint_5(arg0, data->game, 5, 1, 0);
                func_80101FDC(arg0, 5);
                _subaddiedialog_entrypoint_11(arg0->unk0, data->dialog, data->dialogArg, NULL, 0x22);
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80800320_chhoopswoop.s")

void func_808004BC_chhoopswoop(Actor *arg0) {
    s32 _chintrotext_entrypoint_2(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_10(Actor *, s32, s32, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_800A16BC(s32);
    s32 func_800BF744(s32, s32);
    s32 func_800D395C(void);
    s32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    u8 *sp2C;

    sp2C = func_80100094(arg0, 0);
    func_800BF744(1, 0);
    func_800BF744(2, 1);
    if (func_800D395C() != 0) {
        func_800A16BC(1);
    }
    if (arg0->unk70_10 == 1) {
        if (_susubgame_entrypoint_10(arg0, 1, 0x320, 0x1AD) != 0) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(arg0, sp2C + 0x4C4, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(arg0, sp2C + 0x4C4, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, arg0->position, 0x22);
            func_800F82D4(func_800F54E4(), 2);
        }
        func_80101FDC(arg0, 2);
        return;
    }
    func_800F8300(func_800F54E4(), 2, 0);
    _susubgame_entrypoint_5(arg0, sp2C + 0x4C4, 5, 1, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
}

void func_80800620_chhoopswoop(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    if (func_800CEAA8(arg0->unk6C_0) != 0) {
        func_800CE88C(arg0->unk6C_0, 0);
    }
    data[0] = data[1] + 0x4C4;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

void func_808006A0_chhoopswoop(Actor *arg0) {
    typedef struct {
        s16 rotation : 15;
        u16 active : 1;
        s16 position[3];
        f32 time;
    } Hoop;
    typedef struct {
        s32 count;
        u8 unk4[0x10];
        Hoop hoops[100];
    } HoopData;
    void *func_80100094(Actor *, u32);
    void _subaddiemulti_entrypoint_2(void);
    void func_80101FDC(Actor *, u32);
    void func_800D2770(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE88C(s32, s32);
    s32 func_800DA524(s32);
    u32 func_800FDC28(u32);
    HoopData *data;
    f32 duration;
    f32 value;
    HoopData *temp;
    HoopData *cursor;
    s32 i;

    data = func_80100094(arg0, 0); value = arg0->unk74_7; duration = value; _subaddiemulti_entrypoint_2();
    i = 0;
    if (data->count > 0) {
        cursor = data;
        do {
            cursor->hoops[0].time = 0.0f;
            i++;
            cursor->hoops[0].active = 0;
            cursor = (HoopData *)((u8 *)cursor + sizeof(Hoop));
        } while (i < data->count);
    }
    func_80101FDC(arg0, 3);
    func_800D2770(0xC2, 0);
    func_800CE8D8(arg0->unk6C_0, duration, (s32)duration);
    func_800CE88C(arg0->unk6C_0, 1);
    func_800DA524(0);
    func_800FDC28(0xC);
}

s32 func_808007A4_chhoopswoop(void *arg0, s32 *arg1) {
    s32 func_800D0A9C(s32, s32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void *data;
    s32 count;
    s32 result;
    s32 available;
    s32 choice;
    s32 completed;
    s32 flag;
    s32 mode;
    s32 state;

    data = func_80100094(arg0, 0);
    count = ((s32 *)data)[1];
    flag = func_800D0A9C(0x15, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x81, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x1E) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0((choice || available) ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x10D1;
    } else if (available) {
        result = 0x10C3;
    } else if (func_800D395C() == 0) {
        if (flag != 0) {
            if (state == 0) {
                result = 0x10F7;
            } else {
                result = 0x10F6;
            }
        } else {
            result = 0x10F5;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80800910_chhoopswoop.s")

s32 func_80800C04_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    s16 func_800D211C(s32);

    switch (arg1) {
        case 0x10C1:
            return arg2 == 0 ? arg0->unk74_7 : 30;
        case 0x10C3:
        case 0x10F6:
            return func_800D211C(0x81);
        case 0x1119:
            return arg2 == 0 ? arg0->unk74_7 : func_800D211C(0x81);
        default:
            return 0;
    }
}

void func_80800C9C_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor *, u32);
    void func_800DA544(GameFlag);

    switch (arg2) {
        case 1:
            func_80108B04(arg0, 1);
            func_800DA544(3);
            break;
        case 2:
            func_80108B04(arg0, 2);
            func_800DA544(2);
            break;
        case 3:
            func_800DA544(1);
            arg0->unk3C = NULL;
            break;
    }
}

void func_80800D28_chhoopswoop(void *arg0, s32 arg1) {
    typedef struct {
        s32 kind : 15;
        u32 used : 1;
        s16 position[3];
        f32 timer;
    } Hoop;
    typedef struct {
        s32 count;
        u8 pad[16];
        Hoop hoops[1];
    } HoopData;
    typedef struct {
        void *marker;
        u8 pad04[4];
        f32 y;
        u8 pad0C[32];
        s32 index;
        u8 pad30[12];
        s32 parent;
        u8 pad40[24];
        f32 scale;
        u8 pad5C[16];
        u32 flags : 23;
        u32 id : 9;
    } HoopActor;
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_800DC128(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void *func_80108474(s32, f32 *, s32);
    s32 _subaddiefade_entrypoint_2();
    f32 func_800DC0C0(void);
    s32 func_800D3948(void);
    void func_80103140(void *, s32, u16);
    void func_80102424(void *, s32);
    s32 func_8010114C(s32, s32, s32);
    f32 position[3];
    f32 random;
    HoopData *data;
    s32 index;
    s32 i;
    s32 found;
    HoopActor *actor;
    s32 height;
    s32 special;
    s32 *actorData;
    s32 model;
    s32 variant;

    special = func_800DA298(0);
    data = func_80100094(arg0, 0);
    index = func_800DC128(0, data->count);
    if (special) {
        func_800EFA4C(position, 1400.0f, 260.0f, -1400.0f);
        index = -1;
    } else {
        found = 0;
        for (i = 0; i < data->count; i++) {
            if (data->hoops[index].timer == 0.0f && !data->hoops[index].used) {
                found = 1;
                break;
            }
            index++;
            if (index >= data->count) {
                index = 0;
            }
        }
        if (!found) {
            return;
        }
        func_800EE88C(position, data->hoops[index].position);
    }
    actor = func_80108474(0x356, position, data->hoops[index].kind);
    actorData = func_80100094(actor, 0);
    _subaddiefade_entrypoint_2(actor);
    random = func_800DC0C0();
    if (random < 0.1666f) {
        variant = 0;
    } else if (random < 0.5f) {
        variant = 1;
    } else {
        variant = 2;
    }
    if (arg1 != -1) {
        variant = arg1;
    }
    actorData[16] = 2 - variant;
    switch (variant) {
        case 0:
            model = func_800D3948() ? 0x958 : 0x878;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 4);
            height = 100;
            actor->scale = 10.0f;
            break;
        case 1:
            model = func_800D3948() ? 0x957 : 0x877;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 3);
            height = 150;
            actor->scale = 10.0f;
            break;
        case 2:
            model = func_800D3948() ? 0x956 : 0x7A1;
            func_80103140(actor, (u16)model, *(u16 *)((u8 *)((HoopActor *)arg0)->marker + 0x16));
            func_80102424(actor, 2);
            height = 200;
            actor->scale = 10.0f;
            break;
    }
    if (!special) {
        actor->y = height + 80.0f;
    }
    actor->parent = (s32)((HoopActor *)arg0)->marker;
    actor->index = index;
    actor->id = ((HoopActor *)arg0)->id;
    if (index != -1) {
        data->hoops[index].used = 1;
    }
    if (special) {
        actor->scale = 60.0f;
        if (((HoopActor *)arg0)->parent) {
            func_8010114C(((HoopActor *)arg0)->parent, 0x4F, 1);
        }
        ((HoopActor *)arg0)->parent = (s32)actor->marker;
    }
}

void func_80801130_chhoopswoop(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_3(s32);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    void func_800946C4(PlayerState *, s32);
    PlayerState *func_800F53D0(s32);
    void *func_80100094(Actor *, u32);
    u8 *data;
    u8 *score;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk6C_0 = 5;
    func_80800094_chhoopswoop(arg0);
    _subaddiemulti_entrypoint_3(0xA);
    score = data + 0x4DC;
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 7, 0, 1);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        func_800946C4(func_800F53D0(i), 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_808011DC_chhoopswoop.s")

void func_808013C4_chhoopswoop(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 _sumultiscore_entrypoint_12(s32, s32, s32);
    _sumultiscore_entrypoint_12((s32)func_80100094(arg0, 0U) + 0x4DC, arg1, 1);
}

s32 func_808013F8_chhoopswoop(void *arg0, s32 arg1, s32 arg2) {
    void func_80801494_chhoopswoop(Actor *, s32, s32);
    s32 func_80801500_chhoopswoop(u8 *, s32, s32);
    void func_8080153C_chhoopswoop(void *);

    switch (arg1) {
    case 0x2E:
        func_80801494_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801500_chhoopswoop(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800D28_chhoopswoop(arg0, -1);
        break;
    case 0x95:
        func_8080153C_chhoopswoop(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801494_chhoopswoop(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _subaddiemulti_entrypoint_2(void);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_808006A0_chhoopswoop(arg0);
        return;
    case 0x10CD:
    case 0x10CE:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801500_chhoopswoop(u8 *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    if (arg1 == 0x10CD) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (8))) + 1;
    }
    return 0;
}

void func_8080153C_chhoopswoop(void *arg0)
{
  s32 _subaddiemulti_entrypoint_1(s32, s32);
  s32 func_800BF544(s32, s32, s32);
  s32 func_800BF744(s32, s32);
  func_800BF744(1, 0);
  func_800BF744(2, 1);
  func_800BF544(0, 0, 0);
  if ((((((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 0xA) == 1)
  {
    _subaddiemulti_entrypoint_1(0, 0);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_808015A4_chhoopswoop.s")

void func_808017C4_chhoopswoop(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_80801D8C_chhoopswoop(u8 *);
    f32 var_f2;

    if (func_800DC298(0.5f) != 0) {
        var_f2 = 1.0f;
    } else {
        var_f2 = -1.0f;
    }
    arg0->unk50 = func_800DC178(50.0f, 100.0f) * var_f2;
    func_80801D8C_chhoopswoop(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80801838_chhoopswoop.s")

s32 func_80801A10_chhoopswoop(u8 *arg0, s32 arg1, s32 arg2)
{
  s32 _subaddiefade_entrypoint_5(u8 *);
  u8 *new_var;
  void func_80101FDC(Actor *, u32);
  s32 func_8010D930(s32, s32, u8 *, s32 *);
  extern s32 D_80801F98_chhoopswoop;
  if (arg1 == 0x4F)
  {
    if (((((((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 0xA) != 5)
    {
      if (arg2 != 0)
      {
        func_8010D930(5, (*((s32 *) (((s8 *) arg0) + 0x70))) & 1, arg0 + 4, &D_80801F98_chhoopswoop);
      }
      _subaddiefade_entrypoint_5(arg0);
      func_80101FDC(new_var = arg0, 5);
    }
    return 1;
  }
  return 0;
}

void func_80801A94_chhoopswoop()
{
    func_80101870();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80801AB4_chhoopswoop.s")

void func_80801D20_chhoopswoop(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801FB0_chhoopswoop;
    s32 sp24;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    temp_a1 = arg0 + 4;
    sp24 = temp_v0;
    func_800BABB8(temp_v0, temp_a1, temp_a1, 0x3F800000, &D_80801FB0_chhoopswoop);
    func_800BA3FC(sp24, arg1);
    func_800BA22C(sp24, arg2);
}

void func_80801D8C_chhoopswoop(u8 *arg0) {
    s32 func_8010D930(s32, s32, u8 *, s32 *);
    extern s32 D_80801FDC_chhoopswoop;
    func_8010D930(4, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1, arg0 + 4, &D_80801FDC_chhoopswoop);
}

void func_80801DCC_chhoopswoop(Actor *arg0) {
    typedef struct {
        s32 kind : 15;
        u32 used : 1;
        s16 position[3];
        f32 timer;
    } Hoop;
    typedef struct {
        s32 count;
        u8 pad[16];
        Hoop hoops[1];
    } HoopData;
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    HoopData *data;

    actor = func_80106790(arg0->unk3C);
    if (arg0->actorData[5] != -1) {
        data = func_80100094(actor, 0);
        data->hoops[arg0->actorData[5]].used = 0;
        data->hoops[arg0->actorData[5]].timer = 5.0f;
    }
}
