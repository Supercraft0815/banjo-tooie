#include "common.h"

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
    s32 func_800946C4(s32, s32);
    s32 func_800DA524(s32);
    s32 func_800F53D0(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80800094_chhoopswoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_8080016C_chhoopswoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80800320_chhoopswoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_808004BC_chhoopswoop.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_808006A0_chhoopswoop.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80801130_chhoopswoop.s")

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
    s32 _subaddiemulti_entrypoint_2();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hoopswoop/func_80801DCC_chhoopswoop.s")
