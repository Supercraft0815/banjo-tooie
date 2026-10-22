#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chjiggygamenew_entrypoint_0(void)
{
    extern u8 D_80803D44_chjiggygamenew[];

    return (OSThread *) D_80803D44_chjiggygamenew;
}

/* extern */

s32 func_8080000C_chjiggygamenew() {
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x20)));
}

/* extern */

s32 func_80800030_chjiggygamenew(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790();
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
    Actor *func_80106790();
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
    Actor *func_80106790();
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
    Actor *func_80106790();
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
    Actor *func_80106790();
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sujiggy_entrypoint_21(void);
    u32 _sujiggy_entrypoint_24(void);
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
    Actor *func_80106790();
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
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x28))) == 5;
}

/* extern */

void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2) {
    s32 rom_read_word(s32, u32 *);
    u32 sp1C[1];

    rom_read_word(arg1 - 0x50000000, sp1C);
    arg0[arg2][2] = sp1C[0] & 0xFFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800834_chjiggygamenew.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800CC0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808019E0_chjiggygamenew.s")

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
    s32 func_8080363C_chjiggygamenew();
    extern s32 D_80803DAC_chjiggygamenew[4];
    extern s32 D_80803DBC_chjiggygamenew[4];
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802030_chjiggygamenew.s")

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
    extern f32 D_80803D10_chjiggygamenew[3];
    extern f32 D_80803D1C_chjiggygamenew[3];
    extern f32 D_80803D28_chjiggygamenew;

    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E3BAC(D_80803D10_chjiggygamenew);
    func_800E3C30(D_80803D1C_chjiggygamenew);
    func_800E3CE8();
    func_800E44FC(arg0);
    return D_80803D28_chjiggygamenew;
}

void func_808024C8_chjiggygamenew(s32 arg0)
{
    func_800E4208();
    func_800E44FC(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808024F0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802858_chjiggygamenew.s")

struct JiggyGameMarker {
    u8 pad0[0x12];
    u16 flags;
};
void chjiggygamenew_entrypoint_1(void) {
    void func_800EC828(void);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    extern f32 D_80803DCC_chjiggygamenew[3];
    extern f32 D_80803DD8_chjiggygamenew[3];
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/chjiggygamenew_entrypoint_2.s")

OSThread *chjiggygamenew_entrypoint_3(void)
{
    extern u8 D_80803E50_chjiggygamenew[];

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802F3C_chjiggygamenew.s")

void func_80803564_chjiggygamenew(s32 arg0) 
{
}
/* extern */

void func_8080356C_chjiggygamenew(Unk80132ED0 *arg0) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(arg0), 8);
}

/* extern */

void func_80803598_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(), 7);
}

void func_808035C4_chjiggygamenew(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790();
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(func_80106790(arg0), 0U) + 0xC));
}

void func_808035FC_chjiggygamenew(Actor *arg0, f32 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    u8 *temp_v0;

    temp_v0 = func_80100094(func_80106790((Unk80132ED0 *)arg0), 0U);
    arg1[0] = *(f32 *)((u8 *)temp_v0 + 0x18);
    arg1[1] = *(f32 *)((u8 *)temp_v0 + 0x1C);
}

s32 func_8080363C_chjiggygamenew(void) {
    Actor *func_80106790();
    return ((u32) (*(u16 *)((s8 *)(func_80106790()) + (0x72))) >> 0xA) == 1;
}

void func_80803668_chjiggygamenew(Unk80132ED0 *arg0, void *arg1) {
    void func_800E4140(f32 *, f32 *);
    void func_800E7DE4(void *, s32, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_80101870(Actor *, void *);
    Actor *func_80106790(Unk80132ED0 *);
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
    extern u8 D_80803EBC_chjiggygamenew[];

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
    Actor *func_80106790(Unk80132ED0 *);
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
