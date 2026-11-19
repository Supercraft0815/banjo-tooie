#include "common.h"

OSThread *chboggykidshome_entrypoint_0(void)
{
    extern ActorData D_80800468_chboggykidshome[];

    return (OSThread *) D_80800468_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_1(void)
{
    extern ActorData D_808004B0_chboggykidshome[];

    return (OSThread *) D_808004B0_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_2(void)
{
    extern ActorData D_808004F8_chboggykidshome[];

    return (OSThread *) D_808004F8_chboggykidshome;
}

/* extern */

void func_80800024_chboggykidshome(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *actor);
    if ((func_800DA298(0x1CD) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
    }
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objkidshome_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { s32 unk0; } Objkidshome_func_80800068_chboggykidshome_new_var; /* offsets.py genstruct: fields from raw offsets on new_var; rename once understood */

void func_80800068_chboggykidshome(u8 *arg0)
{
  s32 _sudeflect_entrypoint_0(u8 *, s32, s32, s32);
  s32 _suexpression_entrypoint_10(BtIntPtr, BtIntPtr, BtIntPtr);
  BtIntPtr _suexpression_entrypoint_20(u8 *);
  u8 *new_var;
  void func_80800214_chboggykidshome();
  void func_80800300_chboggykidshome(Actor *);
  if (((((u16) (((Objkidshome_arg0 *)arg0)->unk72)) & 0xFFFFFFFF) >> 0xA) == 1)
  {
    if (1)
    {
      func_80800214_chboggykidshome();
    }
  }
  _sudeflect_entrypoint_0(arg0 + 4, 0x42C80000, 0x42480000, 0xA);
  if (1)
  {
    new_var = arg0;
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), ((Objkidshome_func_80800068_chboggykidshome_new_var *)new_var)->unk0, 0);
    func_80800300_chboggykidshome(arg0);
  }
}

void func_808000DC_chboggykidshome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808000FC_chboggykidshome(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);)
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 func_808002C0_chboggykidshome(void *);
    void func_80102424(Actor *, s32);
    extern s32 D_80800540_chboggykidshome[4];
    extern s32 D_80800550_chboggykidshome[4];
    extern s32 D_80800560_chboggykidshome[4];
    void *expression;
    u32 id;

    switch (arg1) {
    case 0x2E:
        func_80102424(arg0, 1);
        break;
    case 0x95:
        expression = BT_NATIVE_ONLY((BtIntPtr)) _suexpression_entrypoint_7(arg0, 1, (s16)func_808002C0_chboggykidshome(arg0));
        _suexpression_entrypoint_12(expression, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(expression, 1000);
        break;
    case 0x52:
        id = arg0->unk6C_9;
        if (id != 0x34E) {
            if (id != 0x3E4) {
                if (id == 0x41D) {
                    _gcdialogcamera_entrypoint_3(D_80800540_chboggykidshome, arg0->scale);
                }
            } else {
                _gcdialogcamera_entrypoint_3(D_80800550_chboggykidshome, arg0->scale);
            }
        } else {
            _gcdialogcamera_entrypoint_3(D_80800560_chboggykidshome, arg0->scale);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800214_chboggykidshome(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    extern s32 D_808003C0_chboggykidshome[10];
    extern s32 D_808003E8_chboggykidshome[8];
    extern s32 D_80800408_chboggykidshome[6];
    extern s32 D_80800570_chboggykidshome[4];
    extern s32 D_80800580_chboggykidshome[4];
    extern s32 D_80800590_chboggykidshome[4];
    u32 id;

    id = arg0->unk6C_9;
    if (id != 0x34E) {
        if (id != 0x3E4) {
            if (id == 0x41D) {
                _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, D_80800570_chboggykidshome, D_808003C0_chboggykidshome, 5);
            }
        } else {
            _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, D_80800580_chboggykidshome, D_808003E8_chboggykidshome, 4);
        }
    } else {
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, D_80800590_chboggykidshome, D_80800408_chboggykidshome, 3);
    }
}

s32 func_808002C0_chboggykidshome(void *arg0) {
    u32 temp_v0;

    temp_v0 = (u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14;
    if (temp_v0 == 0x41D) {
        return 0x3B;
    }
    if (temp_v0 == 0x3E4) {
        return 0x3C;
    }
    return 0x3D;
}

void func_80800300_chboggykidshome(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B7C(s32);
    s32 func_800DC128(s32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_801022E4(Actor *);
    extern s16 D_808005A0_chboggykidshome[];
    extern f32 D_808005AC_chboggykidshome[];
    extern s32 D_808005BC_chboggykidshome[4];
    extern s32 D_808005CC_chboggykidshome[7];
    extern s32 D_808005E8_chboggykidshome[6];
    if (func_801022E4(arg0) == 0x246) {
        if (func_80101E14(arg0, 0.0f) != 0) {
            func_800C4B7C(D_808005A0_chboggykidshome[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808005BC_chboggykidshome);
        }
        if (func_80101E14(arg0, 0.5f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808005CC_chboggykidshome);
        }
        if (func_80101E4C(arg0, D_808005AC_chboggykidshome) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808005E8_chboggykidshome);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ch/boggy/kidshome.data.s */
extern u8 D_80800420_chboggykidshome[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_80800438_chboggykidshome[];
extern u8 D_80800450_chboggykidshome[];
s32 D_808003C0_chboggykidshome[10] BT_DATA(4, overlays_ch_boggy_kidshome, 0x0) = { 1537, 313852160, 1, 313917952, 512, 313917952, 1024, 313917952, -73729, 302711552 };
s32 D_808003E8_chboggykidshome[8] BT_DATA(4, overlays_ch_boggy_kidshome, 0x28) = { 513, 313983232, 1537, 314049024, 1024, 313983232, -73729, 302711552 };
s32 D_80800408_chboggykidshome[6] BT_DATA(4, overlays_ch_boggy_kidshome, 0x48) = { 1537, 314114304, 1537, 314180096, -73729, 302711552 };
u8 D_80800420_chboggykidshome[24] BT_DATA(4, overlays_ch_boggy_kidshome, 0x60) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x89, 0x99, 0x9A, 0x02, 0x42, 0x00, 0x00, 0x40, 0x89, 0x99, 0x9A, 0x02, 0x42, 0x00, 0x00 };
u8 D_80800438_chboggykidshome[24] BT_DATA(4, overlays_ch_boggy_kidshome, 0x78) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x13, 0x33, 0x33, 0x02, 0x44, 0x00, 0x00, 0x40, 0x13, 0x33, 0x33, 0x02, 0x44, 0x00, 0x00 };
u8 D_80800450_chboggykidshome[24] BT_DATA(4, overlays_ch_boggy_kidshome, 0x90) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x9C, 0xCC, 0xCD, 0x02, 0x46, 0x00, 0x00, 0x40, 0x9C, 0xCC, 0xCD, 0x02, 0x46, 0x00, 0x00 };
ActorData D_80800468_chboggykidshome [1] BT_DATA(4, overlays_ch_boggy_kidshome, 0xA8) = { { 344, 1053, 1881, 1, (void *)D_80800420_chboggykidshome, (void (*)(struct Actor *))func_80800068_chboggykidshome, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1065353216, 0, 0, 0, 288, (void (*)(struct Actor *))func_808000DC_chboggykidshome, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chboggykidshome, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808000FC_chboggykidshome, 0 } };
ActorData D_808004B0_chboggykidshome [1] BT_DATA(4, overlays_ch_boggy_kidshome, 0xF0) = { { 344, 996, 1882, 1, (void *)D_80800438_chboggykidshome, (void (*)(struct Actor *))func_80800068_chboggykidshome, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1065353216, 0, 0, 0, 296, (void (*)(struct Actor *))func_808000DC_chboggykidshome, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chboggykidshome, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808000FC_chboggykidshome, 0 } };
ActorData D_808004F8_chboggykidshome [1] BT_DATA(4, overlays_ch_boggy_kidshome, 0x138) = { { 344, 846, 1883, 1, (void *)D_80800450_chboggykidshome, (void (*)(struct Actor *))func_80800068_chboggykidshome, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1073741824, 0, 0, 0, 288, (void (*)(struct Actor *))func_808000DC_chboggykidshome, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chboggykidshome, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808000FC_chboggykidshome, 0 } };
s32 D_80800540_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x180) = { 1126170624, 1124859904, 1124859904, 1116471296 };
s32 D_80800550_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x190) = { 1126170624, 1124859904, 1124859904, 1116471296 };
s32 D_80800560_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1A0) = { 1127481344, 1124859904, 1124859904, 1117782016 };
s32 D_80800570_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1B0) = { 12058624, 19660859, 12, 104595968 };
s32 D_80800580_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1C0) = { 12124160, 19660860, 12, 104595968 };
s32 D_80800590_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1D0) = { 12189696, 19660861, 12, 104595968 };
s16 D_808005A0_chboggykidshome [6] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1E0) = { 1344, 1067, 1368, 1369, 1367, 0 };
f32 D_808005AC_chboggykidshome [4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1EC) = { 0.6f, 0.72f, 0.86f, -1.0f };
s32 D_808005BC_chboggykidshome[4] BT_DATA(4, overlays_ch_boggy_kidshome, 0x1FC) = { 2162701, 14221555, 1658400, 1572864000 };
s32 D_808005CC_chboggykidshome[7] BT_DATA(4, overlays_ch_boggy_kidshome, 0x20C) = { 1246342, 852160, 14221337, 1835040000, 1376268, 13369395, 0 };
s32 D_808005E8_chboggykidshome[6] BT_DATA(4, overlays_ch_boggy_kidshome, 0x228) = { 1246666, 852185, 15925272, 0, 0, 0 };
