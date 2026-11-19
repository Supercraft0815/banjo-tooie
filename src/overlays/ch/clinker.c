#include "common.h"

void func_80800088_chclinker(Actor *arg0);
void func_80105834(Actor *);
void func_80800368_chclinker(Actor *arg0, u8 *arg1);
OSThread *func_80108ED0(void);
void func_80800000_chclinker(Actor *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808002B0_chclinker(Actor *arg0, s32 arg1, s32 arg2);
void func_808007BC_chclinker(Actor *arg0);
void func_80101870(Actor *, void *);
void func_808008C0_chclinker(BtIntPtr arg0);
void func_80800574_chclinker(s32 arg0);
s32 func_80800E1C_chclinker(Actor *arg0, unsigned int arg1, s32 arg2);
void func_8080112C_chclinker(Actor *arg0);
void func_80801004_chclinker(s32 arg0);
void func_80800FFC_chclinker(s32 arg0);
s32 func_808011A8_chclinker(Actor *arg0, s32 arg1, u32 arg2);

u32 D_808013F0_chclinker[] = {
    0x00000000, 0x00000000, 0x3FA66666, 0x031B0000,
    0x3FA66666, 0x031B0000
};

s32 D_80801408_chclinker[] = {
    0x0013063D, 0x0001012C, 0x07D00016, 0x6D600000
};

s32 D_80801418_chclinker[] = {
    0x001D09C9, 0x001F8040, 0x00000018, 0x00000000,
    0x0F000F00, 0x00160010, 0x002501C0, 0x01C0002B,
    0x01330135, 0x00150000, 0x00660000
};

s32 D_80801444_chclinker[] = {
    0x0810001D, 0x084E0001, 0x0000FF6A, 0x00000000,
    0xFED40000, 0x000B0001, 0x0001001E, 0xFFE20016,
    0x04000027, 0xFE0CFE0C, 0x01F401F4, 0x00240100,
    0x02000015, 0x000000C2, 0x002B00C2, 0x01400004,
    0x00660007, 0x00020000
};

s32 D_8080148C_chclinker[] = {
    0x0410001D, 0x084E0001, 0x0000FF38, 0x00000000,
    0xFE700000, 0x000B0001, 0x0001001E, 0xFFE20016,
    0x04000027, 0xFF06FF06, 0x00FA00FA, 0x00240080,
    0x00C00015, 0x000000C2, 0x002B0100, 0x01820004,
    0x00660007, 0x00020000
};

BtFnWord D_808014D4_chclinker[] = {
    0x016C02C1, 0x084D0001, (BtFnWord)D_808013F0_chclinker, (BtFnWord)func_80800088_chclinker,
    (BtFnWord)func_80105834, (BtFnWord)func_80800368_chclinker, 0x05DC0000, 0x00000000,
    0x00000000, 0x00000100, 0x00000000, (BtFnWord)func_80108ED0,
    0x000C0000, (BtFnWord)func_80800000_chclinker, (BtFnWord)func_80107C2C, 0x80002400,
    (BtFnWord)func_808002B0_chclinker, 0x00000000
};

s32 D_8080151C_chclinker[] = {
    0x0013067B, 0x0001012C, 0x03E8000D, 0x00F3010C,
    0x00164E20, 0x00000000
};

s32 D_80801534_chclinker[] = {
    0x0013067C, 0x0001012C, 0x03E8000D, 0x00F3010C,
    0x00164E20, 0x00000000
};

u8 D_8080154C_chclinker[] = { 0x04, 0x05, 0x00, 0x00 };

BtFnWord D_80801550_chclinker[] = {
    0x015802BF, 0x00000001, 0x00000000, (BtFnWord)func_808007BC_chclinker,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (BtFnWord)func_808008C0_chclinker, 0x00000000,
    0x001C0000, (BtFnWord)func_80800574_chclinker, (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_80800E1C_chclinker, 0x00000000
};

BtFnWord D_80801598_chclinker[] = {
    0x015802C0, 0x00000001, 0x00000000, (BtFnWord)func_8080112C_chclinker,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (BtFnWord)func_80801004_chclinker, 0x00000000,
    0x00000000, (BtFnWord)func_80800FFC_chclinker, (BtFnWord)func_80107C2C, 0x80000202,
    (BtFnWord)func_808011A8_chclinker, 0x00000000
};

s32 func_800D395C(void);
s16 func_800D211C(s32);

void func_80800000_chclinker(Actor *arg0) {
    s32 func_800D0A9C(u32, u32);
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void func_808003A8_chclinker(Actor *);
    struct {
        s32 unk0;
        s32 disabled;
    } *sp1C;
    s32 sp18;
    s32 temp_t7;

    sp1C = func_80100094(arg0, 0);
    func_808003A8_chclinker(arg0);
    sp18 = func_800D395C();
    temp_t7 = func_800D0A9C(0x35, 1) == 0;
    if ((sp18 != 0) || (temp_t7 != 0)) {
        sp1C->disabled = 1;
    } else {
        sp1C->disabled = 0;
        func_8010A570(arg0);
        func_80103110(arg0, 0);
    }
}

void func_80800088_chclinker(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808005BC_chclinker(Unk80132ED0 *, Actor *);
    void func_808000F4_chclinker(Actor *);
    Unk80132ED0 **data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
            func_808005BC_chclinker(*data, arg0);
            break;
        case 2:
            func_808000F4_chclinker(arg0);
            break;
    }
}

void func_808000F4_chclinker(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800D9078(f32 *);
    struct {
        s32 unk0;
        s32 disabled;
        s32 state;
    } *sp3C;
    BtIntPtr sp38;

    sp3C = func_80100094(arg0, 0);
    switch (sp3C->state) {
        case 0:
            func_800C4AF0(arg0->position, D_80801408_chclinker);
            func_800BBCB8(arg0->position, NULL, 1.0f, 1, D_80801418_chclinker);
            sp38 = func_800BABB8(0, arg0->position, NULL, 1.0f, D_80801444_chclinker);
            func_800BA994((u8 *)sp38, -30, arg0->rotation[1] - 45.0f, 450, 30, arg0->rotation[1] + 45.0f, 600);
            func_800BA22C(sp38, 8);
            sp38 = func_800BABB8(0, arg0->position, NULL, 1.0f, D_8080148C_chclinker);
            func_800BA994((u8 *)sp38, -30, arg0->rotation[1] - 45.0f, 100, 30, arg0->rotation[1] + 45.0f, 200);
            func_800BA22C(sp38, 4);
            arg0->unk58 = 0.1f;
            sp3C->state = 1;
            break;
        case 1:
            if (func_800D9078(&arg0->unk58)) {
                sp3C->disabled = 0;
                func_80103110(arg0, 0);
            }
            break;
    }
}

/* extern */

s32 func_808002B0_chclinker(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800304_chclinker(Actor *, u32);
    if (arg1 == 0x40) {
        func_80101180(0x2BF, 0x4F, 0);
        func_80800304_chclinker(arg0, 2);
    } else {
        return 0;
    }
    return 1;
}    typedef struct { u8 pad0[0x8]; s32 unk8; } Objclinker_func_80800304_chclinker_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80800304_chclinker(Actor *arg0, u32 arg1) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    void* func_80100094(Actor*, u32);
    void func_80101FDC(Actor*, u32);
    void func_8010A570(Actor*);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (arg1 == 2) {
        func_8010A570(arg0);
        _subaddieDll_entrypoint_4(arg0, 1U);
        (((Objclinker_func_80800304_chclinker_sp1C *)sp1C)->unk8) = 0;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800368_chclinker(Actor *arg0, u8 *arg1) {
    void func_800DF744(s32, s32);
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))));
    func_80101870(arg0, arg1);
}

/* extern */

void func_808003A8_chclinker(Actor *arg0) {
    void _subaddiezone_entrypoint_0(void *);
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
        func_800EF1B8(arg0->position, arg0->rotation[1], 5.0f);
        func_80103014((u8 *)arg0);
        _subaddiezone_entrypoint_0(arg0);
    }
}

OSThread *chclinker_entrypoint_0(void)
{

    return (OSThread *) D_808014D4_chclinker;
}

s32 func_8080045C_chclinker(Actor **arg0)
{
  s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
  Actor *func_801085CC(s32, s16 *, u32);
  Actor *func_80106790(Unk80132ED0 *);
  void *func_80100094(Actor *, u32);
  Actor *actor;
  Unk80132ED0 *marker;
  Prop *props[40];
  s32 count;
  s32 i;
  Prop **cursor;
  Prop **end;
  s32 result;
  actor = *arg0;
  marker = actor->unk0;
  count = _gccubesearch_entrypoint_9(0x2BA, props, 40);
  i = 0;
  if (count > 0)
  {
    do
    {
      actor = func_801085CC(0x2C1, props[i]->position, props[i]->FlagOrRotation);
      actor->scale = props[i]->unkC_0 * 0.01f;
      *((Unk80132ED0 **) func_80100094(actor, 0)) = marker;
      i++;
    }
    while (i < count);
  }
  actor = func_80106790(marker);
  *((s32 *) func_80100094(actor, 0)) = count;
  *arg0 = actor;
  return (count) ? (1) : (0);
}

/* extern */

void func_80800574_chclinker(s32 arg0) {
    void _susubgame_entrypoint_11(s32 arg0);
    _susubgame_entrypoint_11(0);
}

void func_80800598_chclinker(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0x18))) = 0;
}

void func_808005BC_chclinker(Unk80132ED0 *arg0, Actor *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010C710(Actor *);
    s32 pad;
    struct {
        s32 unk0;
        s32 disabled;
        Unk80132ED0 *markers[2];
        f32 distances[2];
        s32 count;
    } *data;
    s32 distance;
    s32 index;
    s32 i;

    data = func_80100094(func_80106790(arg0), 0);
    distance = func_8010C710(arg1);
    index = 0;
    for (i = 0; i < data->count; i++) {
        if (data->distances[i] < (f32)distance) {
            index = i + 1;
        }
    }
    switch (index) {
        case 0:
            data->markers[1] = data->markers[0];
            data->distances[1] = data->distances[0];
        case 1:
            data->markers[index] = arg1->unk0;
            data->distances[index] = (f32)distance;
            data->count++;
            if (data->count >= 3) {
                data->count = 2;
            }
            break;
    }
}

void func_808006A4_chclinker(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80101E14(Actor *, f32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    struct {
        s32 unk0;
        s32 disabled;
        Unk80132ED0 *markers[2];
        f32 distances[2];
        s32 count;
    } *data;
    Actor *actor;
    s32 i;

    data = func_80100094(arg0, 0);
    for (i = 0; i < data->count; i++) {
        actor = func_80106790(data->markers[i]);
        if (func_80101E14(actor, 0.25f)) {
            func_8010D930(D_8080154C_chclinker[i], 0, actor->position, D_8080151C_chclinker);
        }
        if (func_80101E14(actor, 0.8f)) {
            func_8010D930(D_8080154C_chclinker[i], 0, actor->position, D_80801534_chclinker);
        }
    }
    data->count = 0;
}

void func_808007BC_chclinker(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAD0(s32);
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D24E8(s32, s32, u32);
    f32 func_800D8FF8(void);
    f32 func_800F13F0(f32, f32);
    int func_808008E0_chclinker(Actor *, s32);
    struct {
        s32 unk0;
        f32 unk4;
    } *data;

    data = func_80100094(arg0, 0);
    func_808006A4_chclinker(arg0);
    switch (arg0->unk70_10) {
        case 2:
            func_800D24E8(0x103, data->unk0, 0);
            if (func_800CEAD0(0)) {
                func_808008E0_chclinker(arg0, 3);
            }
            break;
        case 3:
            func_800D24E8(0x103, data->unk0, 0);
            break;
        case 6:
            data->unk4 = func_800F13F0(func_800D8FF8() + data->unk4, 999.0f);
            func_800D24E8(0x103, data->unk0, 0);
            func_800D2498(0xCC, (s32)data->unk4, 0);
            break;
        case 7:
            break;
    }
}

void func_808008C0_chclinker(BtIntPtr arg0)
{
    func_808008E0_chclinker(arg0,0x5);
}

u32 func_800F54E4(void);
s32 func_800F7F98(BtIntPtr, u32);
s32 func_80800BDC_chclinker(Actor *, s32);    typedef struct { u8 pad0[0x4]; f32 unk4; } Objclinker_func_808008E0_chclinker_data; /* offsets.py genstruct: fields from raw offsets on data; rename once understood */

int func_808008E0_chclinker(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_800CE8D8(s32 arg0, f32 arg1, s32 arg2);
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D2054(s32, s32, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800FC63C(u32, u32);
    void *data;
    BtIntPtr player;
    s32 pad0;
    s32 pad1;
    s32 message;

    data = func_80100094(arg0, 0);
    if (arg1 != ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10)) {
        switch (arg1) {
        case 2:
            _gcfrontend_entrypoint_9(0x6C);
            func_800D2498(0x103, *(s32 *)data, 0);
            func_800CE8D8(0, (f32)((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7),
                         (u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7);
            func_800CE88C(0, 1);
            break;
        case 4:
            func_800FC63C(0x10, -1);
            func_80800BDC_chclinker(arg0, 0x1372);
            if (func_800CEAA8(0) != 0) {
                func_800CE88C(0, 0);
            }
            if (*(s32 *)((u8 *)arg0 + 0x3C) != 0) {
                func_8010114C(*(s32 *)((u8 *)arg0 + 0x3C), 0x4F, 0);
                *(s32 *)((u8 *)arg0 + 0x3C) = 0;
            }
            break;
        case 5:
            func_800D284C(0x103);
            if (func_800D395C() != 0) {
                func_800D284C(0xCC);
            } else {
                if (func_800CEAA8(0) != 0) {
                    func_800CE88C(0, 0);
                }
                func_800D284C(0xCC);
            }
            break;
        case 3:
            func_80108B04(arg0, 0);
            func_80800BDC_chclinker(arg0, 0x1371);
            break;
        case 9:
            player = func_800F54E4();
            func_800F49D4(player, 0, 0);
            func_800F7B9C(player, 0x8F);
            func_800F7B9C(player, 0x62);
            func_800F7C58(player, 0x61, 0);
            func_80800BDC_chclinker(arg0, func_800D211C(0x94) ? 0x137C : 0xCEC);
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 6:
            ((Objclinker_func_808008E0_chclinker_data *)data)->unk4 = 0.0f;
            func_800D2498(0x103, *(s32 *)data, 0);
            func_800D2498(0xCC, (s32)*&((Objclinker_func_808008E0_chclinker_data *)data)->unk4, 0);
            break;
        case 7:
            switch (func_800D2054(1, 0x94, (s32)*&((Objclinker_func_808008E0_chclinker_data *)data)->unk4)) {
            case -1:
                message = 0x137F;
                break;
            case 0:
                message = 0x137E;
                break;
            case 1:
                message = 0x137D;
                break;
            }
            func_800FC63C(0x10, -1);
            func_80800BDC_chclinker(arg0, message);
            break;
        case 8:
            func_80800BDC_chclinker(arg0, 0xCEB);
            break;
        }
        func_80101FDC(arg0, arg1);
    }
    BT_NATIVE_ONLY(return 0;)}

s32 func_80800BDC_chclinker(Actor *arg0, s32 arg1) {
    u32 func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void _chmrtannoy_entrypoint_0(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 dialog;

    switch (arg1) {
        default:
        case 0x1372:
            dialog = 0x22;
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 0x1371:
            dialog = 0x23;
            break;
        case 0x1373:
            dialog = 7;
            break;
        case 0xCEC:
        case 0x137C:
            dialog = 0x23;
            break;
        case 0xCEB:
            dialog = 0x144;
            break;
    }
    _chmrtannoy_entrypoint_0();
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, dialog, arg0->position, 0xA3);
    return 1;
}

s32 func_80800C9C_chclinker(Actor *arg0, s32 arg1, s32 arg2) { void *func_80100094(Actor *, u32); s16 func_800D211C(s32); struct { s32 unk0; f32 value; } *data; data = func_80100094(arg0, 0); switch (arg1) { case 0x137C: return func_800D211C(0x94); case 0x137D: case 0x137E: case 0x137F: return (s32)data->value; default: return 0; } }

void func_80800D24_chclinker(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _glcutDll_entrypoint_6(u32, u32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);

    switch (func_800C064C()) {
        case 0x1371:
            break;
        case 0x1372:
            _glcutDll_entrypoint_6(0x187, 0x87);
            break;
        case 0x137C:
            func_80800BDC_chclinker(arg0, 0xCEC);
            break;
        case 0xCEC:
            func_800F7F98(func_800F54E4(), 0);
            func_808008E0_chclinker(arg0, 6);
            break;
        case 0x137D:
        case 0x137E:
        case 0x137F:
            func_808008E0_chclinker(arg0, 8);
            break;
        case 0xCEB:
            if (arg2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
    }
}

s32 func_80800E1C_chclinker(Actor *arg0, unsigned int arg1, s32 arg2) {
    s32 func_800D0A9C(u32 arg0, u32 arg1);
    void func_800FC63C(u32 track_id, u32 volume);
    void * func_80100094(Actor *arg0, u32 arg1);
    Actor * func_801084B0(BtIntPtr arg0, Actor **arg1);
    s32 *data;
    const s16 *payload = (const s16 *)&arg2;
    data = func_80100094(arg0, 0);
    switch ((s32)arg1) {
        case 0x49:
        if (func_8080045C_chclinker(&arg0)) {
            func_80100094(arg0, 0);
            func_80800598_chclinker(arg0);
            if (func_800D395C()) {
                func_808008E0_chclinker(arg0, 9);
            }
            else if (!func_800D0A9C(0x35, 1)) {
                func_808008E0_chclinker(arg0, 2);
            }
        }
        break;
        case 0x4F:
        if (--*data) {
            func_800FC63C(0xE, -1);
        }
        else {
            func_808008E0_chclinker(arg0, func_800D395C() ? 7 : 4);
        }
        break;
        case 0x3D:
        arg0->unk3C = func_801084B0(0x178, &arg0)->unk0;
        break;
        case 0x30:
        return func_80800C9C_chclinker(arg0, payload[0], payload[1]);
        case 0x2E:
        func_80800D24_chclinker(arg0, payload[0], payload[1]);
        break;
        case 0x9F:
        func_808008E0_chclinker(arg0, 5);
        break;
        case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_808008E0_chclinker(arg0, 8);
        break;
        default:
        return 0;
    }
    return 1;
}

OSThread *chclinker_entrypoint_1(void)
{

    return (OSThread *) D_80801550_chclinker;
}

void func_80800FFC_chclinker(s32 arg0) 
{
}
void func_80801004_chclinker(s32 arg0) 
{
}
void func_8080100C_chclinker(Actor *arg0, volatile s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    int func_800C6E38(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA090(void);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    s32 func_800F5410(BtIntPtr);
    u32 func_800F54E4(void);
    void func_80101FDC(Actor *, u32);
    void _bsfirstp_entrypoint_18(s32 arg0, s32 arg1);
    Actor **actor = &arg0;

    if (_glcutDll_entrypoint_19(0x87) != 0) {
        _capod_entrypoint_13((*actor)->unk0, NULL, 1, 0x900);
        func_80101FDC(*actor, 3);
        (*actor)->unk58 = 0.15f;
        return;
    }
    switch (func_800EA090()) {
    case 1:
        if (func_800C6E38(0x15) != 0 && func_800F5410(0) == 1 && func_800DA9E4(0x6BA, 1) == 0) {
            func_80101FDC(*actor, 2);
            _capod_entrypoint_13((*actor)->unk0, NULL, 5, 0x2020);
            func_800F49D4(func_800F54E4(), &_bsfirstp_entrypoint_18, 0);
        }
        return;
    case 2:
        func_80101FDC(*actor, 4);
        _capod_entrypoint_13((*actor)->unk0, NULL, 3, 0x2000);
        break;
    }
}

void func_8080112C_chclinker(Actor *arg0) {
    s32 func_800D9078(f32 *);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800D1000(0x35, 1, NULL, 1, 0);
            func_80101FDC(arg0, 1);
        }
    case 2:
    case 4:
        return;
    }
}

s32 func_808011A8_chclinker(Actor *arg0, s32 arg1, u32 arg2) {
    s32 _capod_entrypoint_14(void);
    s32 func_800D0A9C(u32, u32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
    case 0x49:
        func_8080100C_chclinker(arg0, arg2);
        return 1;
    case 0xB:
        if (arg0->unk70_10 == 4) {
            func_800F7F98(func_800F54E4(), 0);
            func_800F7B9C(func_800F54E4(), 0x73);
            func_80101FDC(arg0, 1);
            if (func_800D0A9C(0x35, 1) == 0) {
                func_80800BDC_chclinker(arg0, 0x1373);
            }
        }
        return 3;
    case 0x2E:
        func_800F7F98(func_800F54E4(), 0);
        return 1;
    case 0x77:
        if (arg0->unk70_10 == 2) {
            func_800F7B9C(arg2, 0x73);
            func_80101FDC(arg0, 1);
            _capod_entrypoint_14();
            func_800F7B9C(func_800F54E4(), 0x99);
            return 1;
        }
        break;
    }
    return 0;
}

OSThread *chclinker_entrypoint_2(void)
{

    return (OSThread *) D_80801598_chclinker;
}
