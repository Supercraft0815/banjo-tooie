#include "ch/nicecavemenguard.h"

void func_80102EC0(s32);
void func_801018A4(Actor *, BtIntPtr);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_808000D4_chnicecavemenguard(Actor *arg0);
void func_80800388_chnicecavemenguard(Actor* arg0);
void func_8080000C_chnicecavemenguard(Actor *arg0);
s32 func_808003A8_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2);
struct AudioValues { u32 values[3]; };

s32 D_808008C0_chnicecavemenguard[] = {
    0x00000201, 0x17E50100, 0x00000401, 0x17E60200,
    0x00000400, 0x181B0100, 0x00000200, 0x181C0200,
    0xFFFEDFFF, 0x120E0300
};

u32 D_808008E8_chnicecavemenguard[] = {
    0x00000000, 0x00000000, 0x40A00000, 0x02ED0001,
    0x40A00000, 0x02ED0001, 0x40800000, 0x02EE0002,
    0x3FB33333, 0x02EF0002, 0x3F28F5C3, 0x02F00001,
    0x40800000, 0x02EE0001
};

BtFnWord D_80800920_chnicecavemenguard[] = {
    0x030E03A5, 0x07EE0001, (BtFnWord)D_808008E8_chnicecavemenguard, (BtFnWord)func_80102EC0,
    (BtFnWord)func_808000D4_chnicecavemenguard, (BtFnWord)func_801018A4, 0x05DC0000, 0x3FC00000,
    0x018607E7, 0x40840124, (BtFnWord)func_80800388_chnicecavemenguard, 0x00000000,
    0x00000000, (BtFnWord)func_8080000C_chnicecavemenguard, (BtFnWord)func_80107C2C, 0x84101412,
    (BtFnWord)func_808003A8_chnicecavemenguard, 0x00000000
};

s32 D_80800968_chnicecavemenguard[] = {
    0x03230000, 0x015E0096, 0x0000000C, 0x023C0200
};

f32 D_80800978_chnicecavemenguard[] = {
    -300.0f, -100.0f, -350.0f
};

f32 D_80800984_chnicecavemenguard[] = {
    300.0f, 450.0f, 150.0f
};

u32 D_80800990_chnicecavemenguard[] = {
    0x00130417, 0x000D00C0, 0x00D90000
};

u32 D_8080099C_chnicecavemenguard[] = {
    0x3F23D70A, 0x3F3AE148, 0x3F51EB85, 0xBF800000
};

f32 D_808009AC_chnicecavemenguard[] = {
    0.0f, 0.230000004f, 0.319999993f, 0.419999987f
};

f32 D_808009BC_chnicecavemenguard[] = {
    0.899999976f, 1.10000002f, 1.04999995f, 1.0f
};

s16 D_808009CC_chnicecavemenguard[] = {
    1470, 1468, 1469, 1469
};

s16 D_808009D4_chnicecavemenguard[] = {
    32000, 22000, 22000, 22000
};

s32 D_808009DC_chnicecavemenguard[] = {
    0x03060001, 0x00C80BB8, 0x00070000
};

u32 D_808009E8_chnicecavemenguard[] = {
    0x001305B6, 0x00180000
};

struct AudioValues D_808009F0_chnicecavemenguard = {{0x3D75C28F, 0x3F0F5C29, 0xBF800000}};

u32 D_808009FC_chnicecavemenguard[] = {
    0x00130404, 0x000D00F3, 0x010C0016, 0x36B00000,
    0x00000000
};

void *func_80100094(Actor *, u32);

OSThread *chnicecavemenguard_entrypoint_0(void)
{
    return (OSThread *) D_80800920_chnicecavemenguard;
}

void func_8080000C_chnicecavemenguard(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    void func_80105BAC(Actor *);
    f32 *position[1];

    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 6);
        goto initialize;
    }
    if (func_800DA298(0x186) != 0) {
        func_800FFAB0(arg0);
        return;
    }
initialize:
    func_80102FDC(arg0, arg0->scale * 1.25f);
    position[0] = (f32 *)arg0->actorData;
    func_800EE7F8(position[0], arg0->position);
    func_800EF1B8(position[0], arg0->rotation[1] + 180.0f, 150.0f);
    func_80105A9C(arg0, 400.0f);
    func_80105BAC(arg0);
}

void func_808000D4_chnicecavemenguard(Actor *arg0) {
    typedef struct {
        /* 0x00 */ u32 TransformationType;
        /* 0x04 */ s16 unk4;
        /* 0x06 */ u8 unk6;
        /* 0x07 */ u8 unk7;
    }subaddiedialog_UnkStruct1;
    typedef struct {
        /* 0x00 */ u16 DialogFlag;//Dialog Flag
        /* 0x02 */ u16 unk2;
        /* 0x04 */ u16 unk4;
        /* 0x06 */ s16 unk6;
        /* 0x08 */ u16 unk8;
        /* 0x0A */ u16 unkA;
        /* 0x0C */ u8 unkC;
        /* 0x0D */ u8 unkD;
        /* 0x0E */ u8 unkE;

    }subaddiedialog_UnkStruct2;
    s32 _capod_entrypoint_14(void);
    void _subaddieaudioloop_entrypoint_2(void *arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, subaddiedialog_UnkStruct2 *, subaddiedialog_UnkStruct1 *, s32);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    s32 _sudeflect_entrypoint_3(BtIntPtr arg0, BtIntPtr arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _sudeflect_entrypoint_4(s32 arg0, f32 *arg1);
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    void func_800DA544(s32 index);
    s32 func_800F4F34(BtUIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    s32 func_800F7F98(BtIntPtr arg0, u32 arg1);
    s32 func_80101DDC(Actor *arg0);
    void func_80102424(Actor *arg0, s32 arg1);
    void func_80105854(Actor *arg0);
    s32 func_80105A5C(Actor *arg0);
    void func_80800600_chnicecavemenguard(BtIntPtr arg0);
    void func_80800608_chnicecavemenguard(Actor *arg0);
    void func_80800730_chnicecavemenguard(Actor *arg0);
    void func_8080075C_chnicecavemenguard(Actor *arg0);
    s32 active = 0;
    BtUIntPtr player;
    void *expression;

    player = func_800F54E4();
    func_800F7B9C(player, 0x7E);
    if (func_80100094(arg0, 1) != NULL) { expression = func_80100094(arg0, 1); _suexpression_entrypoint_10(expression, arg0->unk0, 0); }
    switch (arg0->unk70_10) {
    case 1:
        active = 1;
        func_80800600_chnicecavemenguard((BtIntPtr)arg0);
        if (func_800F64A4(func_800F54E4(), 0x60000) == 0) {
            _subaddiedialog_entrypoint_8(arg0, arg0->position, (subaddiedialog_UnkStruct2 *)D_80800968_chnicecavemenguard, (subaddiedialog_UnkStruct1 *)D_808008C0_chnicecavemenguard, 5);
        }
        break;
    case 2:
        active = 1;
        func_80800600_chnicecavemenguard((BtIntPtr)arg0);
        break;
    case 3:
        active = 1;
        func_80800608_chnicecavemenguard(arg0);
        if (func_80101DDC(arg0) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E7, 7, arg0->position, 0x96);
            func_80102424(arg0, 2);
        }
        break;
    case 4:
        func_80800730_chnicecavemenguard(arg0);
        if (func_80101DDC(arg0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E8, 4, arg0->position, 0x96);
            func_80102424(arg0, 5);
        }
        break;
    case 5:
        func_8080075C_chnicecavemenguard(arg0);
        func_80105854(arg0);
        func_800F4F34(func_800F54E4(), arg0->position, 80.0, 100.0);
        if (func_80105A5C(arg0) != 0) {
            func_800DA544(0x186);
            _capod_entrypoint_14();
            func_800F7F98(func_800F54E4(), 0);
        }
        break;
    case 6:
        func_80800608_chnicecavemenguard(arg0);
        break;
    }
    if (arg0->unk70_10 != 5) {
        if (_sudeflect_entrypoint_0(arg0->position, 100.0, 180.0, 10) & 2) {
            _sudeflect_entrypoint_4(9, arg0->position);
        }
    }
    if (active && (_sudeflect_entrypoint_3((BtIntPtr)arg0->actorData, (BtIntPtr)arg0->rotation, (BtIntPtr)D_80800978_chnicecavemenguard, (BtIntPtr)D_80800984_chnicecavemenguard, 2) & 2)) {
        _sudeflect_entrypoint_4(9, arg0->position);
    }
}

void func_80800388_chnicecavemenguard(Actor* arg0)
{
    func_8080080C_chnicecavemenguard(arg0);
}

s32 func_808003A8_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    u32 func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void func_80102424(Actor *, s32);
    void func_808004FC_chnicecavemenguard(void *);
    void func_808005D4_chnicecavemenguard(Actor *, s32, s32);
    void func_808007A8_chnicecavemenguard(Actor *);

    switch (arg1) {
    case 46:
        func_808005D4_chnicecavemenguard(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 29:
    case 30:
        if (func_800F52B8(func_800F54E4(), arg0->unk0) == 0x18 && arg0->unk70_10 == 1) {
            func_80102424(arg0, 3);
        }
        break;
    case 27:
        if (func_800F52B8(func_800F54E4(), arg0->unk0) == 0x17 && arg0->unk70_10 == 1) {
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x20);
            func_800F7F98(func_800F54E4(), 1);
            func_80102424(arg0, 4);
        }
        break;
    case 41:
        func_808007A8_chnicecavemenguard(arg0);
        break;
    case 42:
        func_8080080C_chnicecavemenguard(arg0);
        break;
    case 31:
        func_808004FC_chnicecavemenguard(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808004FC_chnicecavemenguard(void *arg0)
{
  void func_800DF744(s32 index,s32 value);
  s32 func_801015D0();
  f32 func_80101F24(void *);
  u32 temp_t6;
  func_801015D0();
  func_800DF744(5, 1);
  func_800DF744(6, 1);
  func_800DF744(8, 3);
  temp_t6 = (u16) (*((u16 *) (((s8 *) arg0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  if (temp_t6 != 4)
  {
    if (temp_t6 == 5)
    {
      func_800DF744(4, 0);
      func_800DF744(7, 0);
      return;
    }
    goto block_5;
  }
  if (func_80101F24(arg0) > 0.26f)
  {
    func_800DF744(4, 0);
    func_800DF744(7, 1);
    return;
  }
  block_5:
  func_800DF744(4, 1);

  func_800DF744(7, 0);
}

void func_808005D4_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if (arg1 != 0x17E8) {
        func_80102424(arg0, 1);
    }
}

void func_80800600_chnicecavemenguard(BtIntPtr arg0) 
{
}
void func_80800608_chnicecavemenguard(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 i;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, D_808009DC_chnicecavemenguard);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(arg0, D_808009AC_chnicecavemenguard[i]) != 0) {
            func_800C301C(arg0->unk5F, D_808009CC_chnicecavemenguard[i]);
            func_800C31DC(arg0->unk5F, D_808009BC_chnicecavemenguard[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(arg0->unk5F, D_808009D4_chnicecavemenguard[i]);
            func_800C3BDC(arg0->unk5F);
            break;
        }
    }
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800990_chnicecavemenguard, D_8080099C_chnicecavemenguard);
}

void func_80800730_chnicecavemenguard(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808009E8_chnicecavemenguard, 0.0f);
}

void func_8080075C_chnicecavemenguard(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    extern struct AudioValues D_808009F0_chnicecavemenguard;
    struct AudioValues sp1C;

    sp1C = D_808009F0_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_808009FC_chnicecavemenguard, sp1C.values);
}

/* extern */

void func_808007A8_chnicecavemenguard(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    BtIntPtr temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x96);
        temp_v0 = func_80100094(arg0, 1U);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x320);
    }
}

void func_8080080C_chnicecavemenguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
