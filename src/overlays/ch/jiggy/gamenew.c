#include "common.h"

typedef struct { f32 value; s32 unknown4; s32 unknown8; } JiggyCameraData;
void func_80802030_chjiggygamenew(u8 *);
void func_80102EC0(s32);
void func_808024F0_chjiggygamenew(Actor *, void *);
void func_8080245C_chjiggygamenew(s32);
void func_80801EE8_chjiggygamenew(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80802858_chjiggygamenew(void *, s32, s32);

f32 D_80803D10_chjiggygamenew[3] = {
    222.3800048828125f, 328.8999938964844f, -186.39999389648438f,
};

f32 D_80803D1C_chjiggygamenew[3] = {
    0.0f, 270.0f, 0.0f,
};

JiggyCameraData D_80803D28_chjiggygamenew = {
    0.9969819784164429f, 100, 100,
};

u32 D_80803D34_chjiggygamenew[] = {
    0x00000000, 0x00000000, 0x40000000, 0x03D70044,
};

u32 D_80803D44_chjiggygamenew[] = {
    0x015801DF, 0x08630001, (u32)D_80803D34_chjiggygamenew, (u32)func_80802030_chjiggygamenew,
    (u32)func_80102EC0, (u32)func_808024F0_chjiggygamenew, 0x00000000, 0x00000000,
    0x00000000, 0x00401424, (u32)func_8080245C_chjiggygamenew, 0x00000000,
    0x02780000, (u32)func_80801EE8_chjiggygamenew, (u32)func_80107C2C, 0x80002002,
    (u32)func_80802858_chjiggygamenew, 0x00000000,
};

f32 D_80803D8C_chjiggygamenew[][4] = {
    62.0f, 240.0f, 48.0f, 183.0f,
    85.0f, 220.0f, 48.0f, 183.0f,
};

s32 D_80803DAC_chjiggygamenew[4] = {
    0x000000D8, 0x000000D8, 0x000000D8, 0x000000FF,
};

s32 D_80803DBC_chjiggygamenew[4] = {
    0x000000FF, 0x00000060, 0x00000050, 0x000000FF,
};

f32 D_80803DCC_chjiggygamenew[3] = {
    0.699999988079071f, 0.0f, -0.6000000238418579f,
};

f32 D_80803DD8_chjiggygamenew[3] = {
    530.0f, 328.8999938964844f, -186.39999389648438f,
};

u8 D_80803DE4_chjiggygamenew[10][2] = {
    0xC6, 0x5F, 0xD6, 0x68,
    0xD9, 0x67, 0x96, 0x8D,
    0x88, 0xA5, 0x88, 0xA6,
    0x88, 0xA8, 0x6D, 0xA8,
    0x6B, 0x7D, 0x76, 0x8D,
};

u8 D_80803DF8_chjiggygamenew[7][2] = {
    0x76, 0x5F, 0x94, 0x67,
    0x9F, 0x70, 0x8C, 0xA5,
    0x8C, 0xA6, 0x8C, 0xA8,
    0x95, 0x64,
};

u32 D_80803E08_chjiggygamenew[] = {
    0x00000000, 0x00000000, 0x3F800000, 0x03D00049,
    0x3F800000, 0x03D30049, 0x3ECCCCCD, 0x03D2004A,
    0x3ECCCCCD, 0x03D1004A, 0x3E99999A, 0x03CF0049,
    0x3ECCCCCD, 0x03D5004A, 0x40266666, 0x03D4004A,
    0x40266666, 0x03D6004A,
};

Actor *func_80106790();

void *func_80100094(Actor *, u32);

OSThread *chjiggygamenew_entrypoint_0(void)
{


    return (OSThread *) D_80803D44_chjiggygamenew;
}

/* extern */

s32 func_8080000C_chjiggygamenew() {
    return (*(s32 *)((s8 *)(func_80106790()) + (0x20)));
}

/* extern */

s32 func_80800030_chjiggygamenew(Unk80132ED0 *arg0, s32 arg1) {
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s16 selection;
        s16 slot;
        u16 state;
            s16 pad6;
        f32 timer;
        f32 position[3];
    } JiggyGameEntry;
    typedef struct {
        u8 pad0[0x1F4];
        s8 slots[20];
        s8 extraSlots[20];
    } JiggyGameData;
    Actor *actor;
    s16 (*data)[12];

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    if (arg1 < 20) {
        if (((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].state == 0x6B54 ||
            ((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].state == 0xC) {
            ((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].timer = 0.0f;
            func_808007E4_chjiggygamenew(data, 0x78, ((JiggyGameData *)data)->slots[arg1]);
            actor->actorData[3] = ((JiggyGameData *)data)->slots[arg1];
            ((JiggyGameData *)data)->slots[arg1] = -1;
            return 1;
        }
        return 0;
    }
    arg1 -= 20;
    if (((JiggyGameData *)data)->extraSlots[arg1] != -1) {
        ((JiggyGameEntry *)data)[((JiggyGameData *)data)->extraSlots[arg1]].timer = 0.0f;
        func_808007E4_chjiggygamenew(data, 0xF54, ((JiggyGameData *)data)->extraSlots[arg1]);
        actor->actorData[3] = ((JiggyGameData *)data)->extraSlots[arg1];
        ((JiggyGameData *)data)->extraSlots[arg1] = -1;
        return 2;
    }
    return 0;
}

/* extern */

void func_80800158_chjiggygamenew(Unk80132ED0 *arg0) {
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    void func_808035C4_chjiggygamenew(Unk80132ED0 *, f32 *);
    typedef struct {
        s8 selection;
        s8 slot;
        u8 pad2[6];
        f32 timer;
        f32 position[3];
    } JiggyGameResetEntry;
    typedef struct {
        u8 pad0[0x1F4];
        s8 slots[12];
    } JiggyGameResetData;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    ((JiggyGameResetEntry *)data)[actor->actorData[3]].timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0xEB0, actor->actorData[3]);
    func_808035C4_chjiggygamenew(actor->unk3C, ((JiggyGameResetEntry *)data)[actor->actorData[3]].position);
    index = actor->actorData[3];
    ((JiggyGameResetData *)data)->slots[((JiggyGameResetEntry *)data)[index].slot] = index;
    actor->actorData[3] = -1;
}

s32 func_8080020C_chjiggygamenew(Unk80132ED0 *arg0, s32 arg1)
{
  Actor *func_80106790();
  void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
  void func_808035C4_chjiggygamenew(Unk80132ED0 *, f32 *);
  typedef struct 
  {
    s8 selection;
    u8 pad1[2];
    s8 slot;
    u16 input;
    u16 pad6;
    f32 timer;
    f32 position[3];
  } JiggyGameEntry;
  typedef struct 
  {
    u8 pad0[0x208];
    s8 slots[12];
  } JiggyGameData;
  Actor *actor;
  s16 (*data)[12];
  s8 slot;
  s32 index;
  actor = func_80106790(arg0);
  data = func_80100094(actor, 0);
  ;
  if (((JiggyGameData *) data)->slots[arg1] == (-1))
  {
    index = actor->actorData[3];
    if (arg1 == index)
    {
      if (((JiggyGameEntry *) data[index])->selection == 0)
      {
        ((JiggyGameEntry *) data[index])->timer = 0.0f;
        func_808007E4_chjiggygamenew(data, 0x2E4, actor->actorData[3]);
        func_808035C4_chjiggygamenew(actor->unk3C, ((JiggyGameEntry *) data[(s32) actor->actorData[3]])->position);
        return 1;
      }
    }
    if ((((JiggyGameEntry *) data[arg1])->input != 0x18) && (((JiggyGameData *) data)->slots[arg1] == (-1)))
    {
      ((JiggyGameEntry *) data[index])->timer = 0.0f;
      func_808007E4_chjiggygamenew(data, 0x194, actor->actorData[3]);
      func_808035C4_chjiggygamenew(actor->unk3C, ((JiggyGameEntry *) data[(s32) actor->actorData[3]])->position);
      ((JiggyGameEntry *) data[(s32) actor->actorData[3]])->slot = arg1;
      ((JiggyGameData *) data)->slots[arg1] = actor->actorData[3];
      return 0;
    }
  }
  return -1;
}

/* extern */

void func_80800368_chjiggygamenew(Unk80132ED0 *arg0) {
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s8 selection;
        u8 pad1[3];
        u16 input;
        u16 pad6;
        f32 timer;
        u8 padC[12];
    } JiggyGameEntry;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    index = actor->actorData[3];
    if (((JiggyGameEntry *)data)[index].input != 0x800) {
        if (((JiggyGameEntry *)data)[index].input == 0x1FFF) {
            ((JiggyGameEntry *)data)[index].selection--;
        }
    } else {
        ((JiggyGameEntry *)data)[index].selection++;
    }
    if (((JiggyGameEntry *)data)[index].selection < 0) {
        ((JiggyGameEntry *)data)[index].selection += 4;
    }
    if (((JiggyGameEntry *)data)[index].selection >= 4) {
        ((JiggyGameEntry *)data)[index].selection -= 4;
    }
    ((JiggyGameEntry *)data + index)->timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0x55C, index);
}

/* extern */

void func_80800424_chjiggygamenew(Unk80132ED0 *arg0) {
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s8 selection;
        u8 pad1[3];
        u16 input;
        u16 pad6;
        f32 timer;
        u8 padC[12];
    } JiggyGameEntry;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    index = actor->actorData[3];
    if (((JiggyGameEntry *)data)[index].input != 0x800) {
        if (((JiggyGameEntry *)data)[index].input == 0x1FFF) {
            ((JiggyGameEntry *)data)[index].selection--;
        }
    } else {
        ((JiggyGameEntry *)data)[index].selection++;
    }
    if (((JiggyGameEntry *)data)[index].selection < 0) {
        ((JiggyGameEntry *)data)[index].selection += 4;
    }
    if (((JiggyGameEntry *)data)[index].selection >= 4) {
        ((JiggyGameEntry *)data)[index].selection -= 4;
    }
    ((JiggyGameEntry *)data + index)->timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0x7F4, index);
}

void func_808004E0_chjiggygamenew(Unk80132ED0 *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sujiggy_entrypoint_21(void);
    s32 _sujiggy_entrypoint_24(void);
    void func_800C082C(s32);
    void func_800C9C34(f32, s32, s32, s32);
    void func_800C9DE4(f32, void *, s32);
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    void func_800FC6B0(u32);
    void func_80803598_chjiggygamenew();
    Actor *actor;
    s32 dialog;
    u32 score;

    actor = func_80106790(arg0);
    if (!actor->unk64_20 && func_800CEAA8(4)) {
        func_800CE88C(4, 0);
    }
    func_80803598_chjiggygamenew(actor->unk3C);
    if (_sujiggy_entrypoint_21()) {
        score = _sujiggy_entrypoint_24();
        actor->unk6C_0 = (s32)(((f32 *)actor->actorData)[6] - ((f32 *)actor->actorData)[0]);
        if (score == 0) {
            func_800C9C34(0.25f, 0x83, 0, 0x7D0);
            func_800C9DE4(0.3f, &func_800FC6B0, 0x10);
            dialog = 0x1564;
        } else if (score < actor->unk6C_0) {
            func_800C9C34(0.25f, 0x83, 0, 0x7D0);
            func_800C9DE4(0.3f, &func_800FC6B0, 0x17);
            dialog = 0x1563;
        } else if (score == actor->unk6C_0) {
            func_800C9C34(0.25f, 0x83, 0, 0x7D0);
            func_800C9DE4(0.3f, &func_800FC6B0, 0x17);
            dialog = 0x1562;
        } else {
            func_800C9C34(0.25f, 0x83, 0, 0x7D0);
            func_800C9DE4(0.3f, &func_800FC6B0, 0x10);
            dialog = 0x1561;
        }
    } else {
        func_800C9C34(0.25f, 0x83, 0, 0x7D0);
        func_800C9DE4(0.3f, &func_800FC6B0, 0x10);
        dialog = 0x14FA;
    }
    func_800C082C(0);
    _subaddiedialog_entrypoint_11(actor->unk0, dialog, 0x4C6, NULL, 0x97);
    func_800C082C(1);
    actor->actorData[4] = 6;
}

void func_808006E0_chjiggygamenew(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sujiggy_entrypoint_21(void);
    void func_800C082C(s32);
    void func_800C9C34(f32, s32, s32, s32);
    void func_800C9DE4(f32, void *, s32);
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    void func_800FC6B0(u32);
    void func_8080356C_chjiggygamenew(Unk80132ED0 *);
    void func_80800B88_chjiggygamenew(Actor *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (!actor->unk64_20 && func_800CEAA8(4)) {
        func_800CE88C(4, 0);
    }
    func_8080356C_chjiggygamenew(actor->unk3C);
    func_800C9C34(0.25f, 0x83, 0, 0x7D0);
    func_800C9DE4(0.3f, &func_800FC6B0, 0x17);
    actor->actorData[4] = 6;
    if (_sujiggy_entrypoint_21()) {
        arg2 = 0x155E;
    }
    func_800C082C(0);
    _subaddiedialog_entrypoint_11(actor->unk0, arg2, 0x4C6, NULL, 0x97);
    func_800C082C(1);
    func_80800B88_chjiggygamenew(actor);
}

/* extern */

s32 func_808007BC_chjiggygamenew(void) {
    return (*(s32 *)((s8 *)(func_80106790()) + (0x28))) == 5;
}

/* extern */

void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2) {
    s32 rom_read_word(s32, u32 *);
    u32 sp1C[1];

    rom_read_word(arg1 - 0x50000000, sp1C);
    arg0[arg2][2] = sp1C[0] & 0xFFFF;
}

void func_80800834_chjiggygamenew(Actor *arg0) {
    struct Entry {
        s8 direction;
        s8 piece;
        u8 order;
        u8 pad3;
        s16 image;
        s16 pad6;
        f32 scale;
        u8 padC[12];
    };
    struct Data {
        union {
            struct Entry entries[20];
            s16 raw[20][12];
        } grid;
        u8 pad1E0[20];
        s8 positions[20];
        s8 other[20];
    };
    s32 _sujiggy_entrypoint_6(u32);
    s32 _sujiggy_entrypoint_7(u32);
    f32 func_800DC1AC(void);
    s32 func_800DC214(s32, s32);
    struct Data *data;
    s32 i;
    s32 used[20];
    s32 selected[20];
    s32 index;
    s32 selection;
    s32 directionIndex;
    s32 orderIndex;
    s8 direction;

    data = func_80100094(arg0, 0);
    for (i = 0; i < 20; i++) {
        data->grid.entries[i].piece = -1;
        data->grid.entries[i].direction = 0;
        data->grid.entries[i].order = 0;
        func_808007E4_chjiggygamenew(data->grid.raw, 0x934, i);
        used[i] = 0;
        data->positions[i] = -1;
        data->other[i] = -1;
    }
    for (i = 0; i < 20 - _sujiggy_entrypoint_6(arg0->actorData[5]); i++) {
        do {
            selection = func_800DC214(0, 20);
        } while (used[selection] != 0);
        selected[i] = selection;
        used[selection] = -1;
    }
    for (i = 0; i < 20 - _sujiggy_entrypoint_6(arg0->actorData[5]); i++) {
        do {
            index = func_800DC214(0, 20);
        } while (data->grid.entries[index].piece != -1);
        data->grid.entries[index].piece = selected[i];
        func_808007E4_chjiggygamenew(data->grid.raw, 0xA4, index);
        data->grid.entries[index].scale = 2.0f;
        data->positions[selected[i]] = index;
    }
    for (i = 0; i < _sujiggy_entrypoint_7(arg0->actorData[5]); i++) {
        direction = func_800DC214(1, 3);
        if (!(func_800DC1AC() < 0.5f)) {
            direction = -direction;
        }
        do {
            directionIndex = func_800DC214(0, 20);
        } while (data->grid.entries[directionIndex].direction != 0);
        data->grid.entries[directionIndex].direction = direction;
    }
    for (i = 1; i != 21; i++) {
        do {
            orderIndex = func_800DC214(0, 20);
        } while (data->grid.entries[orderIndex].order != 0);
        data->grid.entries[orderIndex].order = i;
    }
    *(s32 *)&arg0->actorData[3] = -1;
}

/* extern */

void func_80800AF8_chjiggygamenew(Actor *arg0) {
    struct Entry {
        u8 pad0[4];
        u16 unk4;
        u16 pad6;
        f32 unk8;
        u8 padC[12];
    };
    s32 var_s0;
    void *temp_v0;
    struct Entry *var_s1;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        if (var_s1->unk4 == 0x3000) {
            func_808007E4_chjiggygamenew(temp_v0, 0x844, var_s0);
            var_s1->unk8 = 0.0f;
        }
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 0x14);
}

void func_80800B88_chjiggygamenew(Actor *arg0) {
    struct Entry {
        u8 unk0;
        s8 unk1;
        u8 unk2;
        u8 unk3;
        u16 unk4;
        u16 unk6;
        f32 unk8;
        f32 position[3];
    };
    void func_800EE7F8(f32 *, f32 *);
    void func_808035C4_chjiggygamenew(Unk80132ED0 *, f32 *);
    extern f32 D_80803AE0_chjiggygamenew[][3];
    extern f32 D_80803BD0_chjiggygamenew[][3];
    struct Entry *data;
    s32 i;

    data = func_80100094(arg0, 0U);
    i = 0;
    do {
        if (data[i].unk4 != 0x18 && data[i].unk4 != 0x2A1) {
            struct Entry *entry = (void *)((u8 *)data + i * sizeof(struct Entry));
            switch (data[i].unk4) {
                case 0:
                case 0x800:
                case 0x1FFF:
                    func_808035C4_chjiggygamenew(arg0->unk3C, entry->position);
                    break;
                case 0xA000:
                    func_800EE7F8(entry->position, D_80803AE0_chjiggygamenew[entry->unk3]);
                    break;
                default:
                    func_800EE7F8(entry->position, D_80803BD0_chjiggygamenew[entry->unk1]);
                    break;
            }
            func_808007E4_chjiggygamenew((void *)data, 0x9EC, i);
            entry->unk8 = 1.5f;
            return;
        }
        i++;
    } while (i != 20);
}

void func_80800CC0_chjiggygamenew(Actor *arg0) {
    struct Entry {
        s8 unk0;
        s8 unk1;
        u8 unk2;
        u8 unk3;
        u16 unk4;
        u16 unk6;
        f32 unk8;
        f32 position[3];
    };
    f32 func_80013970(f32);
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    void func_800E0ACC(void *);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_800E0B8C(void *, u8, f32, f32, f32, f32);
    void func_800E0C20(void *, u8, f32, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    s32 func_8080363C_chjiggygamenew(Unk80132ED0 *);
    void func_808035C4_chjiggygamenew(Unk80132ED0 *, f32 *);
    extern f32 D_80803AE0_chjiggygamenew[][3];
    extern f32 D_80803BD0_chjiggygamenew[][3];
    extern s32 D_80803CC0_chjiggygamenew[];
    struct Entry *data;
    s32 i;
    void *model;
    f32 scale;
    f32 angle;
    f32 position[3];
    f32 blend;

    data = func_80100094(arg0, 0U);
    model = (void *)func_8010262C(arg0->unk0, 0x3C);
    if (model != NULL) {
        func_800E0ACC(model);
        func_800E0AF0(model, 1.0);
        for (i = 0; i < 20; i++) {
            struct Entry *entry = &data[i];
            f32 previous;
            switch ((s32)entry->unk4) {
                case 0x18:
                    scale = 1.0;
                    angle = 0.0f;
                    blend = 0.0f;
                    func_800EFA4C(position, 0.0f, 0.0f, 0.0f);
                    break;
                case 0x3000:
                    if (func_800D90A4(&entry->unk8)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x844, i);
                    }
                    blend = func_800F12D4(entry->unk8, 2.0f, 0.0f, 0.0f, 1.0);
                    func_800EFB24(position, D_80803BD0_chjiggygamenew[(*entry).unk1], D_80803AE0_chjiggygamenew[i]);
                    position[0] -= func_80013970(blend * 180.0f) * (100.0f + 10.0f * entry->unk2);
                    angle = entry->unk0 * 90.0f;
                    scale = 0.75f;
                    break;
                case 0x6B54:
                    scale = 0.75f;
                    if (arg0->actorData[2] == (*entry).unk1 + 1 && func_8080363C_chjiggygamenew(arg0->unk3C)) {
                        entry->unk8 = 0.0f;
                        func_808007E4_chjiggygamenew((void *)data, 0x12C, i);
                    }
                    func_800EFB24(position, D_80803BD0_chjiggygamenew[(*entry).unk1], D_80803AE0_chjiggygamenew[i]);
                    angle = entry->unk0 * 90.0f;
                    blend = 1.0f;
                    break;
                case 0x2A1: {
                    previous = entry->unk8;
                    if (func_800D90A4(&entry->unk8)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x934, i);
                        func_80800B88_chjiggygamenew(arg0);
                    } else if (previous > 0.75f && entry->unk8 <= 0.75f) {
                        func_80800B88_chjiggygamenew(arg0);
                    }
                    scale = 0.75f;
                    blend = func_800F12D4(entry->unk8, 1.5f, 0.0f, 1.0, 0.0f);
                    func_800EFB24(position, entry->position, D_80803AE0_chjiggygamenew[i]);
                    position[0] -= func_80013970(blend * 180.0f) * 100.0f + func_80013970(blend * 180.0f) * 10.0f * entry->unk2;
                    angle = entry->unk0 * 90.0f;
                    break;
                }
                case 0xC:
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        entry->unk8 = 0.0f;
                        if (arg0->actorData[2] != (*entry).unk1 + 1) {
                            func_808007E4_chjiggygamenew((void *)data, 0x844, i);
                        }
                    }
                    func_800EFB24(position, D_80803BD0_chjiggygamenew[(*entry).unk1], D_80803AE0_chjiggygamenew[i]);
                    angle = entry->unk0 * 90.0f;
                    scale = func_80013970(func_800F10B4(entry->unk8, 0.0f, 0.2f, 0.0f, 1.0) * 360.0f) * 0.1f + 0.75f;
                    blend = 1.0f;
                    break;
                case 0xF018: {
                    f32 target[3];
                    f32 t;
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x470, i);
                    }
                    t = func_800F10B4(entry->unk8, 0.0f, 0.2f, 0.0f, 1.0);
                    func_800EFB24(position, D_80803BD0_chjiggygamenew[(*entry).unk1], D_80803AE0_chjiggygamenew[i]);
                    func_808035C4_chjiggygamenew(arg0->unk3C, target);
                    func_800EFB24(target, target, D_80803AE0_chjiggygamenew[i]);
                    func_800EFE50(position, position, target, t);
                    angle = entry->unk0 * 90.0f;
                    scale = func_800F1214(t, 0.75, 1.1f);
                    blend = 1.0f;
                    break;
                }
                case 0:
                    blend = 1.0f;
                    func_808035C4_chjiggygamenew(arg0->unk3C, position);
                    func_800EFB24(position, position, D_80803AE0_chjiggygamenew[i]);
                    angle = entry->unk0 * 90.0f;
                    scale = 1.1f;
                    break;
                case 0x1FFF: {
                    f32 t;
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        blend = 1.0f;
                        entry->unk8 = 0.0f;
                        func_808007E4_chjiggygamenew((void *)data, 0x470, i);
                        t = 0.0f;
                        entry->unk0--;
                        if (entry->unk0 >= 4) {
                            entry->unk0 -= 4;
                        }
                    } else {
                        blend = 1.0f;
                        t = func_800F10B4(entry->unk8, 0.0f, 0.2f, 0.0f, 1.0);
                    }
                    func_808035C4_chjiggygamenew(arg0->unk3C, position);
                    func_800EFB24(position, position, D_80803AE0_chjiggygamenew[i]);
                    angle = entry->unk0 * 90.0f - 90.0f * t;
                    scale = 1.1f;
                    break;
                }
                case 0x800: {
                    f32 t;
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        blend = 1.0f;
                        func_808007E4_chjiggygamenew((void *)data, 0x470, i);
                        t = 0.0f;
                        entry->unk0++;
                        if (entry->unk0 >= 4) {
                            entry->unk0 -= 4;
                        }
                    } else {
                        blend = 1.0f;
                        t = func_800F10B4(entry->unk8, 0.0f, 0.2f, 0.0f, 1.0);
                    }
                    func_808035C4_chjiggygamenew(arg0->unk3C, position);
                    func_800EFB24(position, position, D_80803AE0_chjiggygamenew[i]);
                    angle = entry->unk0 * 90.0f + 90.0f * t;
                    scale = 1.1f;
                    break;
                }
                case 0x32D4: {
                    f32 target[3];
                    f32 t;
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x844, i);
                    }
                    t = func_800F10B4(entry->unk8, 0.0f, 0.2f, 1.0, 0.0f);
                    func_800EFB24(position, D_80803BD0_chjiggygamenew[(*entry).unk1], D_80803AE0_chjiggygamenew[i]);
                    func_800EFB24(target, entry->position, D_80803AE0_chjiggygamenew[i]);
                    func_800EFE50(position, position, target, t);
                    angle = entry->unk0 * 90.0f;
                    scale = func_800F1214(t, 0.75, 1.1f);
                    blend = 1.0f;
                    break;
                }
                case 0xB825: {
                    f32 target[3];
                    f32 t;
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x19C, i);
                    }
                    t = func_800F10B4(entry->unk8, 0.0f, 0.2f, 0.0f, 1.0);
                    func_800EFB24(target, D_80803AE0_chjiggygamenew[entry->unk3], D_80803AE0_chjiggygamenew[i]);
                    target[0] -= t * 20.0f;
                    func_800EFB24(position, entry->position, D_80803AE0_chjiggygamenew[i]);
                    func_800EFE50(position, position, target, t);
                    angle = entry->unk0 * 90.0f;
                    scale = func_800F1214(t, 1.1f, 1.0);
                    blend = 1.0f;
                    break;
                }
                case 0xA000:
                    blend = 1.0f;
                    func_800EFB24(position, D_80803AE0_chjiggygamenew[entry->unk3], D_80803AE0_chjiggygamenew[i]);
                    position[0] -= 20.0f;
                    angle = entry->unk0 * 90.0f;
                    scale = 1.0;
                    break;
                case 0xB41D: {
                    f32 target[3];
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x470, i);
                    }
                    previous = func_800F10B4(entry->unk8, 0.0f, 0.2f, 1.0, 0.0f);
                    func_800EFB24(target, D_80803AE0_chjiggygamenew[entry->unk3], D_80803AE0_chjiggygamenew[i]);
                    target[0] -= previous * 20.0f;
                    func_808035C4_chjiggygamenew(arg0->unk3C, position);
                    func_800EFB24(position, position, D_80803AE0_chjiggygamenew[i]);
                    func_800EFE50(position, position, target, previous);
                    angle = entry->unk0 * 90.0f;
                    scale = func_800F1214(previous, 1.1f, 1.0);
                    blend = 1.0f;
                    break;
                }
                case 0xE825:
                    if (func_800D91EC(&entry->unk8, 0.2f)) {
                        func_808007E4_chjiggygamenew((void *)data, 0x934, i);
                    }
                    blend = func_800F10B4(entry->unk8, 0.0f, 0.2f, 1.0, 0.0f);
                    func_800EFB24(position, entry->position, D_80803AE0_chjiggygamenew[i]);
                    scale = 1.0;
                    angle = 0.0f;
                    break;
            }
            func_800EF334(position, 0.01f);
            func_800E0C20(model, D_80803CC0_chjiggygamenew[i], blend, position[0], position[1], position[2]);
            func_800E0AFC(model, D_80803CC0_chjiggygamenew[i], blend, angle, 0.0f, 0.0f);
            func_800E0B8C(model, D_80803CC0_chjiggygamenew[i], blend, scale, scale, scale);
        }
    }
}

s32 func_808019E0_chjiggygamenew(Actor *arg0) {
    s32 _glglobalsettings_entrypoint_3();
    void func_808035FC_chjiggygamenew(Actor *, f32 *);
    void func_800E4140(f32 *, f32 *);
    extern f32 D_80803AE0_chjiggygamenew[][3];
    extern f32 D_80803BD0_chjiggygamenew[][3];

    f32 screen[2];
    f32 position[2];
    register f32 x, y;
    f32 dx, dy;
    f32 distance = -1.0f;
    s32 nearest = 0;
    s32 i;
    s32 mode;
    f32 *pos = position;

    func_808035FC_chjiggygamenew(arg0->unk3C, position);
    if (_glglobalsettings_entrypoint_3()) {
        mode = 1;
    } else {
        mode = 0;
    }
    x = pos[0];
    if (D_80803D8C_chjiggygamenew[mode][0] <= x && (y = pos[1], x <= D_80803D8C_chjiggygamenew[mode][1]) &&
        D_80803D8C_chjiggygamenew[mode][2] <= y && y <= D_80803D8C_chjiggygamenew[mode][3]) {
        for (i = 0; i != 20; i++) {
            func_800E4140(D_80803AE0_chjiggygamenew[i], screen);
            if (distance == -1.0f ||
                (x = pos[0], y = pos[1], dy = y - screen[1], dx = x - screen[0], dy * dy + dx * dx < distance)) {
                nearest = i;
            x = pos[0];
            y = pos[1];
                dy = y - screen[1];
                dx = x - screen[0];
                distance = dy * dy + dx * dx;
            }
        }
        return nearest + 21;
    }
    for (i = 0; i != 20; i++) {
        func_800E4140(D_80803BD0_chjiggygamenew[i], screen);
        if (distance == -1.0f ||
            (x = pos[0], y = pos[1], dy = y - screen[1], dx = x - screen[0], dy * dy + dx * dx < distance)) {
            nearest = i;
            x = pos[0];
            y = pos[1];
            dy = y - screen[1];
            dx = x - screen[0];
            distance = dy * dy + dx * dx;
        }
    }
    if (distance < 625.0f) {
        return nearest + 1;
    }
    return 0;
}

/* extern */

int func_80801C20_chjiggygamenew(Actor *arg0) {
    struct Entry { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; };
    struct Entry *entries;
    s32 i;

    entries = func_80100094(arg0, 0U);
    for (i = 0; i < 20; i++) {
        if (entries[i].unk4 != 0x18) {
            return 0;
        }
    }
    return 1;
}

int func_80801CB0_chjiggygamenew(Actor *volatile arg0, s32 arg1, void *arg2) {
    struct Entry { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; };
    u16 temp_v1 = ((struct Entry *)arg2)[arg1].unk4;

    return (temp_v1 == 0x6B54) || (temp_v1 == 0xC);
}

void func_80801CE8_chjiggygamenew(Actor *arg0) {
    struct Entry { u8 unk0; s8 unk1; u8 pad2[0x16]; };
    struct Data { struct Entry entries[20]; u8 active[20]; };
    void func_800EDE54(void *, s32[4], s32[4], f32);
    void *func_8010649C(void *, s32);
    s32 func_8080363C_chjiggygamenew(Unk80132ED0 *);

    void *part;
    s32 selected;
    s32 enabled;
    s32 i;
    u8 old;
    u8 state;
    struct Data *data;

    data = func_80100094(arg0, 0U);
    selected = arg0->actorData[2] - 1;
    enabled = func_8080363C_chjiggygamenew(arg0->unk3C);
    for (i = 0; i < 20; i++) {
        old = data->active[i];
        if (selected == data->entries[i].unk1 && enabled &&
            func_80801CB0_chjiggygamenew(arg0, i, data)) {
            data->active[i] = 1;
        } else {
            data->active[i] = 0;
        }
        if (old != data->active[i]) {
            part = func_8010649C(arg0, i + 0x190);
            state = data->active[i];
            if (state != 0) {
                if (state == 1) {
                    func_800EDE54(part, D_80803DAC_chjiggygamenew, D_80803DBC_chjiggygamenew, 0.1f);
                }
            } else {
                func_800EDE54(part, D_80803DBC_chjiggygamenew, D_80803DAC_chjiggygamenew, 0.3f);
            }
        }
    }
}

/* extern */

void func_80801E4C_chjiggygamenew(Actor *arg0, s32 arg1) {
    struct JiggyGameData {
        f32 timer;
        u32 count;
        u8 pad8[8];
        s32 state;
        s32 jiggy;
        f32 duration;
    };
    f32 _sujiggy_entrypoint_3(s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800DA544(GameFlag);
    f32 temp_f0;

    func_800DA544(0xD49);
    if (arg1 == 0) {
        temp_f0 = _sujiggy_entrypoint_3(((struct JiggyGameData *)arg0->actorData)->jiggy);
        ((struct JiggyGameData *)arg0->actorData)->timer = temp_f0;
        ((struct JiggyGameData *)arg0->actorData)->duration = temp_f0;
        func_800CE8D8(4, temp_f0, (s32) temp_f0);
        func_800CE88C(4, 1);
        ((struct JiggyGameData *)arg0->actorData)->count = osGetCount();
    }
    ((struct JiggyGameData *)arg0->actorData)->state = 5;
    arg0->unk64_20 = arg1;
}

/* extern */

void func_80801EE8_chjiggygamenew(Actor *arg0) {
    struct JiggyGameData {
        f32 timer;
        u32 count;
        u8 pad8[8];
        s32 state;
        s32 jiggy;
        f32 duration;
    };
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void _gldbstring_entrypoint_2(s32);
    s32 _sujiggy_entrypoint_12(void);
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *var_s0;
    u8 *var_v0;
    u8 var_a0;
    u8 *temp_t0;

    ((struct JiggyGameData *)arg0->actorData)->jiggy = _sujiggy_entrypoint_12();
    ((struct JiggyGameData *)arg0->actorData)->state = 1;
    temp_v0 = (u8 *)_gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, 0x186D), (s16)((struct JiggyGameData *)arg0->actorData)->jiggy);
    var_s3 = 0;
    for (var_s4 = 0; temp_v0[var_s3 - 1] != 0 && var_s4 != 3; var_s4++, var_s3++) {
        temp_a1 = (u8 *)func_80100094(arg0, 0) + var_s4 * 0x1E + 0x21C;
        var_s1 = 0;
        while (temp_v0[var_s3] != 0 && temp_v0[var_s3] != 0xA) {
            temp_a1[var_s1] = temp_v0[var_s3];
            var_s3++;
            var_s1++;
        }
        temp_a1[var_s1 + 1] = 0;
    }
    for (; var_s4 < 3; var_s4++) {
        temp_t0 = (u8 *)func_80100094(arg0, 0) + var_s4 * 0x1E;
        temp_t0[0x21C] = 0;
    }
    _gldbstring_entrypoint_2(0x186D);
}

void func_80802030_chjiggygamenew(u8 *arg0) {
    s32 func_800C0638(void);
    s32 _sujiggy_entrypoint_18(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    f32 func_800D8FF8(void);
    s32 _sujiggy_entrypoint_21(void);
    s32 _sujiggy_entrypoint_24(void);
    void func_800C082C(s32);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    void func_800FC6B0(u32);
    void func_800FC74C(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);
    void func_800FCD14(s32, s32);
    void func_800CE980(s32, f32, s32);
    s32 func_80102424(s32, s32);
    void func_80801CE8_chjiggygamenew(Actor *arg0);
    struct GameFlags {
        u32 unused : 11;
        u32 paused : 1;
        u32 rest : 20;
    };
    f32 dt;
    s32 now;
    s32 previous;
    s32 elapsed;

    dt = func_800D8FF8();
    if (*(s16 *)(arg0 + 0x90) != 0) {
        func_80801CE8_chjiggygamenew(arg0);
    }
    *(f32 *)(arg0 + 0x58) += dt;
    switch (*(s32 *)(arg0 + 0x28)) {
        case 1:
            if (*(f32 *)(arg0 + 0x58) > 0.1f) {
                func_800FC6B0(0x31);
                if (func_800FCCD4(0x2E) != 0) {
                    func_800FCAE0(0x2E, 0, 0x1D3);
                    func_800FCA90(0x2E);
                }
                *(s32 *)(arg0 + 0x28) = 2;
                *(f32 *)(arg0 + 0x18) = 2.0f;
                func_80800834_chjiggygamenew(arg0);
            }
            break;
        case 2:
            if (func_800D90A4((f32 *)(arg0 + 0x18)) != 0) {
                func_80800AF8_chjiggygamenew(arg0);
                func_800FC74C(0x31);
                func_800FC6B0(0x83);
                func_800FCA90(0x83);
                if (_sujiggy_entrypoint_21() != 0) {
                    if (func_800DA298(0xD49) == 0) {
                        func_800C082C(0);
                        _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x155F, 0x4C7, 0, 0x97);
                        func_800C082C(1);
                        *(s32 *)(arg0 + 0x28) = 3;
                    } else if (_sujiggy_entrypoint_24() != 0) {
                        func_800C082C(0);
                        _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1560, 0x4C7, 0, 0x97);
                        func_800C082C(1);
                        *(s32 *)(arg0 + 0x28) = 3;
                    } else {
                        func_80801E4C_chjiggygamenew(arg0, 0);
                    }
                } else if (func_800DA298(0xD49) == 0) {
                    func_800C082C(0);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x14F9, 0x4C7, 0, 0x97);
                    func_800C082C(1);
                    *(s32 *)(arg0 + 0x28) = 3;
                } else if (_sujiggy_entrypoint_18() != 0) {
                    func_800C082C(0);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1554, 0x4C7, 0, 0x97);
                    func_800C082C(1);
                    *(s32 *)(arg0 + 0x28) = 3;
                } else {
                    func_80801E4C_chjiggygamenew(arg0, 0);
                }
            }
            break;
        case 4:
            func_800C082C(0);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1555, 0x4C6, 0, 0x97);
            func_800C082C(1);
            *(s32 *)(arg0 + 0x28) = 3;
            break;
        case 5:
            if (func_80801C20_chjiggygamenew(arg0) != 0) {
                func_808004E0_chjiggygamenew(*(s32 *)arg0);
                func_80102424((s32)func_80106790(*(Unk80132ED0 **)(arg0 + 0x3C)), 7);
            } else if (!((struct GameFlags *)(arg0 + 0x64))->paused) {
                now = osGetCount();
                previous = *(s32 *)(arg0 + 0x1C);
                if (now >= previous) {
                    elapsed = now - previous;
                } else {
                    elapsed = 0xFFFFFFFF - previous + now + 1;
                }
                *(f32 *)(arg0 + 0x18) -= ((f32)elapsed * 0.021333333f) / 1000000.0f;
                *(s32 *)(arg0 + 0x1C) = osGetCount();
                if (*(f32 *)(arg0 + 0x58) > 2.0f) {
                    func_800FCD14(0x83, (s32)((131538.0f * *(f32 *)(arg0 + 0x18)) / *(f32 *)(arg0 + 0x30) + 330000.0f));
                }
                if (*(f32 *)(arg0 + 0x18) < -0.1f) {
                    func_808006E0_chjiggygamenew(*(s32 *)arg0, 0xD4B, 0x14FB);
                } else {
                    func_800CE980(4, *(f32 *)(arg0 + 0x18), 0);
                }
            }
            break;
        case 7:
        case 8:
            if (func_80801C20_chjiggygamenew(arg0) != 0 && func_800C0638() == 0) {
                if (*(s32 *)(arg0 + 0x28) == 7) {
                    _sujiggy_entrypoint_11(*(s32 *)(arg0 + 0x2C));
                } else {
                    _sujiggy_entrypoint_10();
                }
                *(s32 *)(arg0 + 0x28) = 6;
            }
            break;
    }
    func_80800CC0_chjiggygamenew(arg0);
}

void func_8080245C_chjiggygamenew(s32 arg0) 
{
}
void func_800E44FC(Gfx **);

f32 func_80802464_chjiggygamenew(Gfx **arg0) {
    void func_800E3BAC(f32 *);
    void func_800E3C30(f32 *);
    void func_800E3C8C(f32, f32);
    void func_800E3CE8(void);
    void func_800E41CC(void);


    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E3BAC(D_80803D10_chjiggygamenew);
    func_800E3C30(D_80803D1C_chjiggygamenew);
    func_800E3CE8();
    func_800E44FC(arg0);
    return D_80803D28_chjiggygamenew.value;
}

void func_808024C8_chjiggygamenew(s32 arg0)
{
    func_800E4208();
    func_800E44FC(arg0);
}
void func_808024F0_chjiggygamenew(Actor *arg0, void *arg1) {
    typedef struct { u8 pad[0x21C]; u8 text[3][30]; } JiggyText;
    typedef struct { f32 timer; unsigned int rest[7]; } JiggyDrawData;
    void _fxkern_entrypoint_1(Gfx **arg0, s32 arg1, u8 *arg2);
    void _fxkern_entrypoint_2(void);
    void _fxkern_entrypoint_3(f32 arg0);
    u32 func_800A9CD0(void);
    void func_800B8C8C(s32 Transparency);
    void func_800B8CE0(s32 color);
    struct ImageStruct;
    struct ImageStruct * func_800D674C(s32 a0);
    void * func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32 arg0);
    s32 func_800E71B8(s32 arg0);
    void func_800E7C28(Gfx** gfx);
    void func_800E7CF4(Gfx** gfx);
    s32 func_800E81D0(void);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    void func_80101870(Actor* arg0, void* arg1);
    void func_80102FDC(void *arg0, f32 arg1);
    void func_80803668_chjiggygamenew(Unk80132ED0 *arg0, void *arg1);
    void func_80803928_chjiggygamenew(Unk80132ED0 *arg0, Gfx **arg1);
    f32 scale;
    f32 position[3];
    f32 rotation[3];
    int segment;

    segment = func_800E81D0();
    if (segment != 0 && func_800A9CD0() == 1) {
        scale = func_80802464_chjiggygamenew(arg1);
        func_800EFA4C(position, 0.0, 0.0, 0.0);
        func_800EFA4C(rotation, 0.0, 0.0, 0.0);
        func_800DF830(1);
        func_800DE498(arg1, position, NULL, 1.0f, rotation, (s32)func_800D674C(0x866));
        func_800DE498(arg1, position, NULL, 1.0f, rotation, (s32)func_800D674C(0x865));
        gDPSetTextureFilter((*(Gfx **)arg1)++, G_TF_POINT);
        gDPSetColorDither((*(Gfx **)arg1)++, G_CD_DISABLE);
        if (arg0->actorData[7] != 0) {
            func_80803928_chjiggygamenew((Unk80132ED0 *)arg0->actorData[7], arg1);
        }
        func_800E7C28(arg1);
        func_800E7CF4(arg1);
        gSPSegment((*(Gfx **)arg1)++, 4, osVirtualToPhysical((void *)segment));
        func_80102FDC(arg0, scale);
        func_80101870(arg0, arg1);
        gDPSetTextureFilter((*(Gfx **)arg1)++, G_TF_BILERP);
        gDPSetColorDither((*(Gfx **)arg1)++, G_CD_MAGICSQ);
        func_80803668_chjiggygamenew(arg0->unk3C, arg1);
        arg0->actorData[2] = func_808019E0_chjiggygamenew(arg0);
        func_808024C8_chjiggygamenew((s32)arg1);
        if (arg0->actorData[4] == 1 || arg0->actorData[4] == 2) {
            int i;
            int count;
            _fxkern_entrypoint_2();
            func_800B8C8C(arg0->actorData[4] == 1 ? 255 : (s32)func_800F10B4(((JiggyDrawData *)arg0->actorData)->timer, 2.0f, 0.0f, 255.0f, 0.0f));
            func_800B8CE0(0xC26);
            _fxkern_entrypoint_3(1.1f);
            for (count = 0, i = 0; i < 3; i++) {
                if (((JiggyText *)func_80100094(arg0, 0))->text[i][0]) {
                    count++;
                }
            }
            for (i = 0; ((JiggyText *)func_80100094(arg0, 0))->text[i][0] && i != 3; i++) {
                _fxkern_entrypoint_1(arg1, 120 - (count / 2) * 25 + i * 25,
                    (u8 *)func_800E71B8((s32)((JiggyText *)func_80100094(arg0, 0))->text[i]));
            }
        }
    }
}

s32 func_80802858_chjiggygamenew(void *arg0, s32 arg1, s32 arg2) {
    typedef struct { s16 id; s16 response; } DialogEvent;
    typedef struct {
        Unk80132ED0 *marker;
        u8 pad4[0x24];
        s32 state;
        s32 count;
        u8 pad30[0x3C];
        u32 unused : 23;
        u32 jiggy : 9;
    } JiggyGame;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sujiggy_entrypoint_19(void);
    s32 _sujiggy_entrypoint_24(void);
    void _sujiggy_entrypoint_25(s32);
    void _sujiggy_entrypoint_9(void);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80800B88_chjiggygamenew(Actor *);
    void func_80801E4C_chjiggygamenew(Actor *arg0, s32 arg1);

    switch (arg1) {
    case 46:
        switch (((DialogEvent *)&arg2)->id) {
        case 0x155F:
        case 0x1560:
        case 0x14F9:
        func_80801E4C_chjiggygamenew(arg0, 0);
        break;
        case 0x1554:
        if (((DialogEvent *)&arg2)->response == 1) {
            if (func_800DA298(0xD74) == 0) {
                _subaddiedialog_entrypoint_11(((JiggyGame *)arg0)->marker, 0x1555, 0x4C7, 0, 0x97);
                func_800DA544(0xD74);
            } else {
                func_80801E4C_chjiggygamenew(arg0, 1);
            }
        } else {
            func_80801E4C_chjiggygamenew(arg0, 0);
        }
        break;
        case 0x1555:
        func_80801E4C_chjiggygamenew(arg0, 1);
        break;
        case 0x14FA:
        _sujiggy_entrypoint_9();
        func_80800B88_chjiggygamenew(arg0);
        case 0x150B:
        case 0x14FB:
        if (((DialogEvent *)&arg2)->response == 1) {
            ((JiggyGame *)arg0)->state = 7;
        } else {
            ((JiggyGame *)arg0)->state = 8;
        }
        break;
        case 0x155E:
        case 0x1561:
        case 0x1562:
        case 0x1563:
        case 0x1564:
        func_80800B88_chjiggygamenew(arg0);
        _sujiggy_entrypoint_25(((JiggyGame *)arg0)->jiggy);
        if (((DialogEvent *)&arg2)->response == 1) {
            ((JiggyGame *)arg0)->state = 7;
        } else {
            ((JiggyGame *)arg0)->state = 8;
        }
        break;
        }
        break;
    case 48:
        switch (((DialogEvent *)&arg2)->id) {
        default:
            break;
        case 0x14FA:
        case 0x14FB:
        case 0x14FC:
            return ((JiggyGame *)arg0)->count + 1;
        case 0x1554:
            return _sujiggy_entrypoint_19();
        case 0x14F9:
            return _sujiggy_entrypoint_24();
        case 0x1564:
        case 0x1561:
            if (((DialogEvent *)&arg2)->response != 0) {
                return _sujiggy_entrypoint_24();
            }
            return ((JiggyGame *)arg0)->jiggy;
        case 0x1563:
            return _sujiggy_entrypoint_24();
        case 0x1560:
        case 0x1562:
            return _sujiggy_entrypoint_24();
        }
        break;
    default:
        return 0;
    }
    return 1;
}

struct JiggyGameMarker {
    u8 pad0[0x12];
    u16 flags;
};
void chjiggygamenew_entrypoint_1(void) {
    void func_800EC828(void);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);

    Actor *sp24;
    register Actor *third;
    Actor *sp1C;

    D_80803DCC_chjiggygamenew[2] = 0.0f;
    D_80803DCC_chjiggygamenew[1] = D_80803DCC_chjiggygamenew[2];
    D_80803DCC_chjiggygamenew[0] = D_80803DCC_chjiggygamenew[2];
    sp24 = func_80108474(0x1DF, D_80803DCC_chjiggygamenew, 0);
    sp1C = func_80108528(0x1E2, D_80803DD8_chjiggygamenew, 0, &sp24);
    sp24->unk3C = sp1C->unk0;
    sp1C->unk3C = sp24->unk0;
    third = func_80108528(0x1DE, sp24->position, 0, &sp24);
    sp24->actorData[7] = (u32)third->unk0;
    third->unk3C = sp24->unk0;
    ((struct JiggyGameMarker *)sp24->unk0)->flags = (((struct JiggyGameMarker *)sp24->unk0)->flags & 1) | 2;
    ((struct JiggyGameMarker *)sp1C->unk0)->flags = (((struct JiggyGameMarker *)sp1C->unk0)->flags & 1) | 2;
    ((struct JiggyGameMarker *)third->unk0)->flags = (((struct JiggyGameMarker *)third->unk0)->flags & 1) | 2;
    func_800EC828();
    func_800EC828();
    func_800EC828();
}

void chjiggygamenew_entrypoint_2(void) {
    s32 func_80014F00(void);
    s32 _glglobalsettings_entrypoint_3(void);

    u16 *buffer;
    s32 i;
    s32 offset;
    s32 offset2;

    buffer = (u16 *)func_80014F00();
    if (_glglobalsettings_entrypoint_3()) {
        for (i = 0; i < 7; i++) {
            offset = D_80803DF8_chjiggygamenew[i][0] + D_80803DF8_chjiggygamenew[i][1] * 0x130;
            buffer[offset] = buffer[offset - 1];
        }
    } else {
        for (i = 0; i < 10; i++) {
            offset2 = D_80803DE4_chjiggygamenew[i][0] + D_80803DE4_chjiggygamenew[i][1] * 0x130;
            buffer[offset2] = buffer[offset2 - 1];
        }
    }
}

OSThread *chjiggygamenew_entrypoint_3(void)
{
    extern u32 D_80803E50_chjiggygamenew[];

    return (OSThread *) D_80803E50_chjiggygamenew;
}

/* extern */

void func_80802E80_chjiggygamenew(Actor *arg0) {
    struct JiggyGameInitData {
        f32 position[3];
        u8 padC[0x1C];
        s32 unk28;
        s32 unk2C;
        f32 unk30;
        f32 unk34;
        s32 buttons;
        f32 unk3C;
        f32 unk40;
    };
    s32 _subaddiefade_entrypoint_1(s32, s32);
    OSContPad *func_800169A8(void);
    void func_800EE7F8(f32 *, f32 *);
    OSContPad *sp24;
    struct JiggyGameInitData *sp20;
    struct JiggyGameInitData *temp_v0;

    sp24 = func_800169A8();
    temp_v0 = func_80100094(arg0, 0);
    sp20 = temp_v0;
    func_800EE7F8(temp_v0->position, arg0->position);
    arg0->scale = 0.18f;
    arg0->rotation[0] = 59.0f;
    arg0->rotation[2] = 63.0f;
    arg0->rotation[1] = -6.0f;
    sp20->unk30 = 1.0f;
    sp20->unk34 = 1.0f;
    sp20->unk28 = -1;
    sp20->unk2C = sp20->unk28;
    sp20->buttons = sp24->button;
    sp20->unk3C = 0.0f;
    sp20->unk40 = 0.0f;
    _subaddiefade_entrypoint_1(arg0, 0xB9);
}

void func_80802F3C_chjiggygamenew(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _sujiggy_entrypoint_21(void);
    s32 func_808007BC_chjiggygamenew();
    s32 func_8080000C_chjiggygamenew();
    f32 func_80015D60(s32, s32, s32);
    OSContPad *func_800169A8(void);
    void func_800C3E88(s32);
    void func_800C3F14(s32, f32);
    void func_800C9E20(f32, u32 *, u32, u32);
    f32 func_800D9004(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800FC63C(u32, u32);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80102424(s32, s32);
    f32 mlAbsF(f32);
    extern u32 D_80803E98_chjiggygamenew[];
    OSContPad *pad;
    f32 dt;
    f32 x;
    f32 y;
    struct GamenewData {
        f32 position[3];
        u8 padC[0x1C];
        s32 selected;
        s32 hovered;
        f32 accelerationX;
        f32 accelerationY;
        s32 buttons;
        f32 previousX;
        f32 previousY;
    };
    struct GamenewData *data;
    s32 unused;
    s32 track;
    s32 result;
    s32 state;
    f32 amount;
    f32 horizontal;
    f32 vertical;
    f32 minimum;
    f32 minimum2;
    f32 minimum3;
    f32 minimum4;
    u32 initialState;
    u32 inputState;
    u32 switchState;
    s32 buttons;
    s32 hovered;
    pad = func_800169A8();
    dt = func_800D9004();
    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 != 7 && arg0->unk70_10 != 8 &&
    func_808007BC_chjiggygamenew((s32)arg0->unk3C)) {
        if (arg0->unk70_10 != 6) {
            x = func_80015D60(pad->stick_x, 7, 0x3B);
            y = func_80015D60(pad->stick_y, 7, 0x3D);
            if (!x || data->previousX * x < 0.0f) {
                data->accelerationX = 1.0;
            } else {
                amount = mlAbsF(x * 0.1f);
                data->accelerationX *= (f32)1.0 + amount;
            }
            if (!y || data->previousY * y < 0.0f) {
                data->accelerationY = 1.0;
            } else {
                amount = mlAbsF(y * 0.1f);
                data->accelerationY *= (f32)1.0 + amount;
            }
            data->previousX = x;
            data->previousY = y;
            *(f32 *)((u8 *)arg0 + 0x1C) += y * dt * 150.0f * data->accelerationY;
            *(f32 *)((u8 *)arg0 + 0x20) += x * dt * 150.0f * data->accelerationX;
            *(f32 *)((u8 *)arg0 + 0x1C) = ((*(f32 *)((u8 *)arg0 + 0x1C) < 110.0f ? *(f32 *)((u8 *)arg0 + 0x1C) : 110.0f) < -100.0f) ? -100.0f : (*(f32 *)((u8 *)arg0 + 0x1C) < 110.0f ? *(f32 *)((u8 *)arg0 + 0x1C) : 110.0f);
            *(f32 *)((u8 *)arg0 + 0x20) = ((*(f32 *)((u8 *)arg0 + 0x20) < 154.0f ? *(f32 *)((u8 *)arg0 + 0x20) : 154.0f) < -135.0f) ? -135.0f : (*(f32 *)((u8 *)arg0 + 0x20) < 154.0f ? *(f32 *)((u8 *)arg0 + 0x20) : 154.0f);
            func_800EE780(arg0->position, data->position, (f32 *)arg0->actorData);
        }
        if ((s32)arg0->unk70_10 >= 2 && (s32)arg0->unk70_10 < 5 && _sujiggy_entrypoint_21()) {
            if ((pad->button & 2) && !(data->buttons & 2)) {
                func_800C3F14(0x487, 0.9f);
                func_80102424((s32)arg0, 3);
                func_80800368_chjiggygamenew((Unk80132ED0 *)arg0->unk3C);
            }
            if ((pad->button & 1) && !(data->buttons & 1)) {
                func_800C3F14(0x487, 1.0f);
                func_80102424((s32)arg0, 4);
                func_80800424_chjiggygamenew((Unk80132ED0 *)arg0->unk3C);
            }
        }
        data->hovered = func_8080000C_chjiggygamenew((s32)arg0->unk3C);
        switch (arg0->unk70_10) {
        case 1:
            if (data->hovered > 0 && data->hovered < 0x29 &&
            (pad->button & 0x8000) && !(data->buttons & 0x8000)) {
                result = func_80800030_chjiggygamenew((Unk80132ED0 *)arg0->unk3C, data->hovered - 1);
                if (result != 0) {
                    data->selected = data->hovered - 1;
                    if (result == 1) {
                        func_800FC660(0x2F);
                    } else {
                        func_800C3E88(0x47F);
                    }
                    func_80102424((s32)arg0, 2);
                    func_80800030_chjiggygamenew((Unk80132ED0 *)arg0->unk3C, data->hovered - 1);
                }
            }
            break;
        case 2:
            if ((pad->button & 0x4000) && !(data->buttons & 0x4000)) {
                func_80102424((s32)arg0, 5);
                func_80800158_chjiggygamenew((Unk80132ED0 *)arg0->unk3C);
                func_800FC660(0x30);
                data->selected = -1;
            } else if (data->hovered >= 0x15 && data->hovered < 0x29 &&
            (pad->button & 0x8000) && !(data->buttons & 0x8000)) {
                result = func_8080020C_chjiggygamenew((Unk80132ED0 *)arg0->unk3C, data->hovered - 0x15);
                if (result == 1) {
                    track = 0xE;
                    data->selected = -1;
                    func_80102424((s32)arg0, 6);
                } else if (result == 0) {
                    track = 0xF;
                    data->selected = -1;
                    func_80102424((s32)arg0, 1);
                } else {
                    track = 0xF;
                }
                func_800C9E20(0.25f, (u32 *)func_800FC63C, track, 0x6590);
            }
            break;
        case 3:
        case 4:
            if (func_80101DDC(arg0)) {
                func_80102424((s32)arg0, 2);
            }
            break;
        case 5:
            func_80102424((s32)arg0, 1);
            if (pad->button) {}
            break;
        case 6:
            _subaddieaudioquick_entrypoint_3(arg0, NULL, D_80803E98_chjiggygamenew, 0.5f);
            if (func_80101DDC(arg0)) {
                func_80102424((s32)arg0, 1);
            }
            break;
        case 7:
        case 8:
        default:
            break;
        }
        data->buttons = pad->button;
    }
}

void func_80803564_chjiggygamenew(s32 arg0) 
{
}
/* extern */

void func_8080356C_chjiggygamenew(Unk80132ED0 *arg0) {
    s32 func_80102424(s32, s32);
    func_80102424(func_80106790(arg0), 8);
}

/* extern */

void func_80803598_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    func_80102424(func_80106790(), 7);
}

void func_808035C4_chjiggygamenew(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(func_80106790(arg0), 0U) + 0xC));
}

void func_808035FC_chjiggygamenew(Actor *arg0, f32 *arg1) {
    u8 *temp_v0;

    temp_v0 = func_80100094(func_80106790((Unk80132ED0 *)arg0), 0U);
    arg1[0] = *(f32 *)((u8 *)temp_v0 + 0x18);
    arg1[1] = *(f32 *)((u8 *)temp_v0 + 0x1C);
}

s32 func_8080363C_chjiggygamenew(Unk80132ED0 *arg0) {
    return ((u32) (*(u16 *)((s8 *)(func_80106790(arg0)) + (0x72))) >> 0xA) == 1;
}

void func_80803668_chjiggygamenew(Unk80132ED0 *arg0, void *arg1) {
    void func_800E4140(f32 *, f32 *);
    void func_800E7DE4(void *, s32, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_80101870(Actor *, void *);
    extern f32 D_80803EA4_chjiggygamenew[];
    extern f32 D_80803EB0_chjiggygamenew[];
    f32 *position;
    Actor *actor;
    f32 *data;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0U);
    position = actor->position;
    func_800E4140(position, data + 8);
    func_800E7DE4(arg1, (s32)(data[8] - actor->scale * 650.0f / 2), (s32)(data[9] - actor->scale * 650.0f / 2), (s32)(actor->scale * 650.0f), (s32)(actor->scale * 650.0f));
    func_80101870(actor, arg1);
    if (actor->unk70_10 == 1) {
        func_800EE7F8(data + 3, D_80803EA4_chjiggygamenew);
    } else {
        func_800EE7F8(data + 3, D_80803EB0_chjiggygamenew);
    }
    func_800EF04C(data + 3, position);
    func_800E4140(data + 3, data + 6);
}

OSThread *chjiggygamenew_entrypoint_4(void)
{
    extern u32 D_80803EBC_chjiggygamenew[];

    return (OSThread *) D_80803EBC_chjiggygamenew;
}

void func_8080377C_chjiggygamenew(Actor *arg0) {
    void func_800EDE54(void *, s32[4], s32[4], f32);
    void *func_8010649C(void *, s32);
    extern s32 D_80803F04_chjiggygamenew[4];
    extern s32 D_80803F14_chjiggygamenew[4];
    s32 i;
    s32 selected;
    u8 *data;
    u8 *entry;
    u8 previous;
    void *part;

    data = func_80100094(arg0, 0U);
    if (arg0->unk7C_12 && ((s16 *)&arg0->pad90)[0] != 0) {
        if (!arg0->unk64_20) {
            for (i = 0; i != 20; i++) {
                func_800EDE54(func_8010649C(arg0, i + 0x190), D_80803F14_chjiggygamenew, D_80803F04_chjiggygamenew, 0.0f);
            }
            arg0->unk64_20 = 1;
        }
        selected = func_8080000C_chjiggygamenew(arg0->unk3C) - 0x15;
        for (i = 0, entry = data; i != 20; i++, entry++) {
            previous = *entry;
            if (i == selected) {
                *entry = 1;
            } else {
                *entry = 0;
            }
            if (previous != *entry) {
                part = func_8010649C(arg0, i + 0x190);
                switch (*entry) {
                    case 1:
                        func_800EDE54(part, D_80803F04_chjiggygamenew, D_80803F14_chjiggygamenew, 0.05f);
                        break;
                    case 0:
                        func_800EDE54(part, D_80803F14_chjiggygamenew, D_80803F04_chjiggygamenew, 0.2f);
                        break;
                }
            }
        }
    }
}

void func_80803928_chjiggygamenew(Unk80132ED0 *arg0, Gfx **arg1) {
    s32 func_800E81D0(void);
    void func_80101870(Actor* arg0, void* arg1);
    Gfx *sp18;
    Gfx *temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_800E81D0();
    if (temp_v0 != 0) {
        temp_v0_2 = (*arg1)++;
        temp_v0_2->words.w0 = 0xDB060010;
        sp18 = temp_v0_2;
        sp18->words.w1 = osVirtualToPhysical((u8 *) temp_v0);
        func_80101870(func_80106790(arg0), arg1);
    }
}

void func_8010A730();
u32 D_80803E50_chjiggygamenew[] = {
    0x015801E2, 0x08620001, (u32)D_80803E08_chjiggygamenew, (u32)func_80802F3C_chjiggygamenew,
    (u32)func_80102EC0, (u32)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00400444, (u32)func_80803564_chjiggygamenew, 0x00000000,
    0x00440000, (u32)func_80802E80_chjiggygamenew, (u32)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};
u32 D_80803E98_chjiggygamenew[] = {
    0x00130448, 0x00165DC0, 0x001B0000,
};
f32 D_80803EA4_chjiggygamenew[] = {
    -10.0f, 15.0f, -35.0f,
};
f32 D_80803EB0_chjiggygamenew[] = {
    -10.0f, 5.0f, -50.0f,
};
u32 D_80803EBC_chjiggygamenew[] = {
    0x015801DE, 0x08640001, 0x00000000, (u32)func_8080377C_chjiggygamenew,
    (u32)func_80102EC0, (u32)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00401404, 0x00000000, 0x00000000,
    0x00140000, 0x00000000, (u32)func_80107C2C, 0x80002002,
    0x00000000, 0x00000000,
};
s32 D_80803F04_chjiggygamenew[4] = {
    0x00000060, 0x00000060, 0x00000060, 0x000000FF,
};
s32 D_80803F14_chjiggygamenew[4] = {
    0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF,
};
