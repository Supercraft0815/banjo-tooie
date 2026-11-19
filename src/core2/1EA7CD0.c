#include "1EA78C0_types.h"
struct CounterState {
    s16 counters[4];
    s16 aux;
    s16 result;
    u8 flag;
    u8 pad[3];
    f32 value;
    u8 rest[12];
};
struct CounterState D_8012B160_storage;
void *func_800CE3E0(s32 arg0) {
    extern s32 D_8012B030;
    return (void *) ((arg0 << 5) + (BtIntPtr) &D_8012B030);
}
#include "air_timer_settings.inc"
void func_800CE3F4(u8 *arg0, s32 arg1) { extern HudTimerPolicy D_8011AA30[9];
    func_800D2498(D_8011AA30[arg1].hudItem, *(s16 *)(arg0 + 0xA), 0U);
}

/* extern */

s32 func_800CE438(u8 *arg0, s32 arg1) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    (*(f32 *)(arg0 + 0)) = func_800F10B4((f32) (*(s16 *)(arg0 + 0xA)), 0.0f, (f32) (*(s16 *)(arg0 + 0x10)), 0.0f, (*(f32 *)(arg0 + 0xC)));
    func_800CE3F4(arg0, arg1); BT_NATIVE_ONLY(return 0;)
}

void func_800CE49C(u8 *arg0, s32 arg1, s32 arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    (*(s16 *)(arg0 + 0xA)) = (s32) (func_800F10B4(*(f32 *)arg0, 0.0f, *(f32 *)(arg0 + 0xC), 1.0f, (f32) *(s16 *)(arg0 + 0x10) + 1.0f) - 0.0001f);
    if (arg2 != 0) {
        func_800CE3F4(arg0, arg1);
    }
}    typedef struct { f32 unk0; f32 unk4; s16 unk8; s16 unkA; u8 padC[0x6]; s8 unk12; s8 unk13; s8 unk14; s8 unk15; s8 unk16; u8 pad17[0x1]; s32 unk18; s32 unk1C; } Obj1EA78C0_func_800CE524_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800CE524(void) {
    void *func_800CE3E0(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_800CE3E0(var_s0);
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk8) = 0;
        var_s0 += 1;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk0) = 0.0f;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk4) = 0.0f;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk16) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk15) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk14) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk12) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk13) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk18) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk1C) = 0;
        (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unkA) = (s16) (((Obj1EA78C0_func_800CE524_temp_v0 *)temp_v0)->unk8);
    } while (var_s0 != 9);
}

s32 func_800CE59C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    BT_IDO_ONLY(extern u16 D_8011AA34[][3];)
    u16 temp_v0;

    temp_v0 = BT_DATA_FIELD(D_8011AA30[arg0].pauseFlags, D_8011AA34[arg0][0]);
    if ((arg1 != 0) && (temp_v0 & 4)) {
        return 0;
    }
    if ((arg2 != 0) && (temp_v0 & 1)) {
        return 0;
    }
    if ((arg3 != 0) && (temp_v0 & 2)) {
        return 0;
    }
    if ((arg4 != 0) && (temp_v0 & 8)) {
        return 0;
    }
    return 1;
}

s32 func_800CE628(void) {
    f32 func_800D9004(void);
    int func_800DB9B0(void);
    s32 func_800EA09C(void);
    u32 func_800F54E4(void);
    s32 func_800F68B8(BtIntPtr);
    s32 func_800F6D24(BtIntPtr);
    int func_800F8004(BtIntPtr);
    void func_800CEC94(u8 *, s32, s32);
    extern HudTimerPolicy D_8011AA30[9];
    void (*callback)(s32, s32);
    HudTimerPolicy *entry;
    f32 previous;
    f32 delta;
    s32 callback_arg;
    BtIntPtr player;
    s32 state;
    s32 flag1;
    s32 flag2;
    s32 flag3;
    s32 active;
    s32 i;
    u8 *timer;

    if (func_800EA09C() == 2) {
        player = func_800F54E4();
        delta = func_800D9004();
        state = func_800DB9B0();
        flag1 = func_800F6D24(player);
        flag2 = func_800F8004(player);
        flag3 = func_800F68B8(player);
        entry = D_8011AA30;
        i = 0;
        do {
            timer = func_800CE3E0(i);
            active = func_800CE59C(i, state, flag1, flag2, flag3);
            if ((*(s8 *)(timer + 0x12) > 0) && (timer[0x13] == 0) && (timer[0x14] == 0) && active) {
                *(f32 *)(timer + 4) = *(f32 *)timer;
                *(s16 *)(timer + 8) = *(s16 *)(timer + 0xA);
                *(f32 *)timer = *(f32 *)(timer + 4) - delta;
                if (*(volatile f32 *)timer < 0.0f) {
                    *(f32 *)timer = 0.0f;
                    if (*(void (**)(s32, s32))(timer + 0x18) != NULL) {
                        callback = *(void (**)(s32, s32))(timer + 0x18);
                        callback_arg = *(s32 *)(timer + 0x1C);
                        *(void (**)(s32, s32))(timer + 0x18) = NULL;
                        *(s32 *)(timer + 0x1C) = 0;
                        callback(i, callback_arg);
                    }
                    *(s8 *)(timer + 0x12) = 0;
                }
                func_800CE49C(timer, i, 1);
            }
            if (entry->playWarning != 0) {
                func_800CEC94(timer, i, active);
            }
            i++;
            entry++;
            timer[0x14] = 0;
        } while (i != 9);
    } BT_NATIVE_ONLY(return 0;)
}    typedef struct { u8 pad0[0x120]; u8 unk120; u8 unk121; } Obj1EA78C0_D_8012B030; /* offsets.py genstruct: fields from raw offsets on &D_8012B030; rename once understood */

void func_800CE7DC(void) {
    s32 func_800C2FDC(u8);
    void func_800FC74C(u32 track_id);
    extern s32 D_8012B030;
    if ((((Obj1EA78C0_D_8012B030 *)&D_8012B030)->unk120) != 0) {
        func_800C2FDC((((Obj1EA78C0_D_8012B030 *)&D_8012B030)->unk120));
        (((Obj1EA78C0_D_8012B030 *)&D_8012B030)->unk120) = 0U;
    }
    if ((((Obj1EA78C0_D_8012B030 *)&D_8012B030)->unk121) != 0) {
        func_800FC74C(0x92);
        (((Obj1EA78C0_D_8012B030 *)&D_8012B030)->unk121) = 0U;
    }
}

BtIntPtr func_800CE83C(s32 arg0, s32 arg1) {
    void *func_800CE3E0(s32);
    s8 *ptr;

    ptr = func_800CE3E0(arg0);
    ptr[0x13] = arg1;
    return (BtIntPtr) ptr;
}

/* extern */

#ifdef BT_NATIVE
void func_800CE864(s32 bt_a0) {
#else
void func_800CE864() {
#endif
    void *func_800CE3E0();
#ifdef BT_NATIVE
    (*(s8 *)((s8 *)(((void * (*)())func_800CE3E0)()) + (0x14))) = 1;
#else
    (*(s8 *)((s8 *)(func_800CE3E0()) + (0x14))) = 1;
#endif
}    typedef struct { u8 pad0[0x12]; s8 unk12; } Obj1EA78C0_func_800CE88C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800CE88C(s32 arg0, s32 arg1) { void *temp_v0; s8 temp_v1; temp_v0 = func_800CE3E0(arg0); if (arg1 != 0) { ((Obj1EA78C0_func_800CE88C_temp_v0 *)temp_v0)->unk12 = ((Obj1EA78C0_func_800CE88C_temp_v0 *)temp_v0)->unk12 + 1; } else { temp_v1 = ((Obj1EA78C0_func_800CE88C_temp_v0 *)temp_v0)->unk12; if (temp_v1 != 0) *&((Obj1EA78C0_func_800CE88C_temp_v0 *)temp_v0)->unk12 = temp_v1 - 1; } }    typedef struct { f32 unk0; f32 unk4; s16 unk8; s16 unkA; f32 unkC; s16 unk10; u8 pad12[0x3]; s8 unk15; u8 pad16[0x2]; s32 unk18; } Obj1EA78C0_func_800CE8D8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800CE8D8(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800CE3E0(s32);
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk15) = 0;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk18) = 0;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk10) = (s16) arg2;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unkA) = (s16) arg2;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk8) = (s16) arg2;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unkC) = arg1;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk4) = arg1;
    (((Obj1EA78C0_func_800CE8D8_temp_v0 *)temp_v0)->unk0) = arg1;
}    typedef struct { u8 pad0[0x18]; BtIntPtr unk18; BtIntPtr unk1C; } Obj1EA78C0_func_800CE928_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800CE928(s32 arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (((Obj1EA78C0_func_800CE928_temp_v0 *)temp_v0)->unk18) = arg1;
    (((Obj1EA78C0_func_800CE928_temp_v0 *)temp_v0)->unk1C) = arg2;
}

/* extern */

s32 func_800CE95C(BT_NATIVE_ONLY(s32 bt_a0)) {
    void *func_800CE3E0();
#ifdef BT_NATIVE
    return (*(s32 *)((s8 *)(((void * (*)())func_800CE3E0)()) + (0x18)));
#else
    return (*(s32 *)((s8 *)(func_800CE3E0()) + (0x18)));
#endif
}    typedef struct { f32 unk0; f32 unk4; u8 pad8[0x4]; f32 unkC; } Obj1EA78C0_func_800CE980_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800CE980(s32 arg0, f32 arg1, s32 arg2) {
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    if ((((Obj1EA78C0_func_800CE980_temp_v0 *)temp_v0)->unkC) < arg1) {
        (((Obj1EA78C0_func_800CE980_temp_v0 *)temp_v0)->unkC) = arg1;
    }
    (((Obj1EA78C0_func_800CE980_temp_v0 *)temp_v0)->unk4) = arg1;
    (((Obj1EA78C0_func_800CE980_temp_v0 *)temp_v0)->unk0) = arg1;
    func_800CE49C(temp_v0, arg0, arg2 == 0);
}    typedef struct { u8 pad0[0x8]; s16 unk8; s16 unkA; u8 padC[0x4]; s16 unk10; } Obj1EA78C0_func_800CE9E8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_800CE9E8(s32 arg0, s32 arg1) {
    void *func_800CE3E0();
    s32 func_800CE438();
    u8 *temp_v0;

#ifdef BT_NATIVE
    temp_v0 = ((void * (*)())func_800CE3E0)();
#else
    temp_v0 = func_800CE3E0();
#endif
    if ((((Obj1EA78C0_func_800CE9E8_temp_v0 *)temp_v0)->unk10) < arg1) {
        (((Obj1EA78C0_func_800CE9E8_temp_v0 *)temp_v0)->unk10) = (s16) arg1;
    }
    (((Obj1EA78C0_func_800CE9E8_temp_v0 *)temp_v0)->unk8) = (s16) arg1;
    (((Obj1EA78C0_func_800CE9E8_temp_v0 *)temp_v0)->unkA) = (s16) arg1;
#ifdef BT_NATIVE
    return ((s32 (*)())func_800CE438)(temp_v0, arg0, arg1);
#else
    return func_800CE438(temp_v0, arg0, arg1);
#endif
}

void func_800CEA38(s32 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800CE3E0(arg0)) + (0x15))) = (s8) arg1;
}

f32 func_800CEA60(s32 arg0) {
    return *(f32 *) func_800CE3E0(arg0);
}

s16 func_800CEA84(s32 arg0) {
    return (*(s16 *)((s8 *)(func_800CE3E0(arg0)) + (0xA)));
}

/* extern */

s32 func_800CEAA8(s32 arg0) {
    void *func_800CE3E0(s32);
    return (*(s8 *)((s8 *)(func_800CE3E0(arg0)) + (0x12))) > 0;
}

s32 func_800CEAD0(s32 arg0) {
    return func_800CEA60(arg0) == 0.0f;
}

s32 func_800CEB08(void *arg0, f32 arg1) {
    if (((((Obj1EA78C0_arg0 *)arg0)->unk12) != 0) && (arg1 <= (((Obj1EA78C0_arg0 *)arg0)->unk4)) && ((*(f32 *)((s8 *)(arg0) + (0))) < arg1)) {
        return 1;
    }
    return 0;
}

s32 func_800CEB54(s32 arg0, f32 arg1) {
    BT_NATIVE_ONLY(return) func_800CEB08(func_800CE3E0(arg0), arg1);
}    typedef struct { u8 pad0[0x8]; s16 unk8; s16 unkA; u8 padC[0x6]; s8 unk12; } Obj1EA78C0_func_800CEB80_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_800CEB80(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    if (((((Obj1EA78C0_func_800CEB80_temp_v0 *)temp_v0)->unk12) != 0) && (arg1 < (((Obj1EA78C0_func_800CEB80_temp_v0 *)temp_v0)->unk8)) && (arg1 >= (((Obj1EA78C0_func_800CEB80_temp_v0 *)temp_v0)->unkA))) {
        return 1;
    }
    return 0;
}

void func_800CEBD8(s32 arg0, s32 arg1) {
    int func_800D284C(s32);
    int func_800DB9B0(void);
    u32 func_800F54E4(void);
    s32 func_800F68B8(BtIntPtr);
    s32 func_800F6D24(BtIntPtr);
    int func_800F8004(BtIntPtr);
    extern HudTimerPolicy D_8011AA30[9];
    BtIntPtr sp34;
    s32 pad30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 pad20;

    sp34 = func_800F54E4();
    if (arg1 != 0) {
        sp24 = func_800DB9B0();
        sp28 = func_800F6D24(sp34);
        sp2C = func_800F8004(sp34);
        if (func_800CE59C(arg0, sp24, sp28, sp2C, func_800F68B8(sp34)) != 0) {
            func_800CE3F4(func_800CE3E0(arg0), arg0);
            return;
        }
    }
    func_800D284C(D_8011AA30[arg0].hudItem);
}

void func_800CEC94(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800C2FDC(u8);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    void func_800FC6B0(u32);
    void func_800FC74C(u32 track_id);
    void func_800FCD14(s32, s32);
    extern HudTimerSound D_8011AA68;
    extern s32 D_8012B030;
    s32 active;
    s32 music;
    s32 sound;

    music = *(f32 *)arg0 > 1.0f && *(f32 *)arg0 < 5.0f;
    sound = *(f32 *)arg0 > 0.0f && *(f32 *)arg0 < 1.0f;
    active = *(s8 *)(arg0 + 0x12) > 0 && !arg0[0x13] && !arg0[0x14] && (!arg2 || arg0[0x15]);
    if (!active) {
        sound = 0;
        music = 0;
    }
    if (music || sound || arg0[0x16]) {
        if (music) {
            if (!((u8 *)&D_8012B030)[0x121]) {
                func_800FC6B0(0x92);
                ((u8 *)&D_8012B030)[0x121] = 1;
            }
            func_800FCD14(0x92, (s32)(((*(f32 *)arg0 - 1.0f) * 200000.0f) / (5.0f - 1.0f) + 200000.0f));
        } else if (((u8 *)&D_8012B030)[0x121]) {
            func_800FC74C(0x92);
            ((u8 *)&D_8012B030)[0x121] = 0;
        }
        if (sound) {
            if (!((u8 *)&D_8012B030)[0x120]) {
                ((u8 *)&D_8012B030)[0x120] = func_800C4350(0, 0, (s32 *)D_8011AA68.commands);
            }
            func_800C3BDC(((u8 *)&D_8012B030)[0x120]);
        } else if (((u8 *)&D_8012B030)[0x120]) {
            func_800C2FDC(((u8 *)&D_8012B030)[0x120]);
            ((u8 *)&D_8012B030)[0x120] = 0;
        }
        arg0[0x16] = music || sound;
    }
}

f32 func_800CEF00(s32 arg0) {
    extern AirTimerSetting D_8011AA80[9];
    extern s32 func_800CF6D0(void);
    return D_8011AA80[arg0].secondsPerUnit * (f32) func_800CF6D0();
}

f32 func_800CEF48(s32 arg0) {
    BT_IDO_ONLY(extern s16 D_8011AA8E;)
    return (f32) BT_DATA_FIELD(D_8011AA80[arg0].mode, *(s16 *) ((u8 *) &D_8011AA8E + arg0 * 20));
}

void func_800CEF6C(void) {
    extern f32 D_8012B170;
    D_8012B170 = 0.0f;
}

void func_800CEF7C(void)
{
  extern s32 func_800CF6D0(void);
  f32 sp1C[3];
  s32 i;
  sp1C[0] = func_800CEF00(0);
  func_800CE8D8(1, sp1C[0], func_800CF6D0());
  if (D_8012B160_storage.value != 0.0f)
  {
    func_800CE980(1, D_8012B160_storage.value, 1);
  }
  for(i=0;i<4;i++) {
    D_8012B160_storage.counters[i]=9;
  }
  D_8012B160_storage.aux = 0;
  D_8012B160_storage.result = func_800CEA84(1);
  D_8012B160_storage.flag = 0;
}

s32 func_800CF01C(void) {
    void func_800C3FF0(s32, f32, s32);
    f32 func_800D8FF8(void);
    void func_800FC63C(u32, u32);
    s32 func_800CF580(void);
    s16 func_800CF640(void);
    extern AirTimerSetting D_8011AA80[9];
    extern s16 D_8012B168;
    extern s16 D_8012B16A;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 temp_f0;
    s32 temp_a0;
    s32 temp_a2;
    AirTimerSetting *temp_v1;

    sp24 = func_800CEAA8(1) + D_8012B168;
    sp1C = func_800CEA60(1);
    sp18 = func_800CEF00(0);
    if (func_800CF580() == 0) {
        func_800CE864(1);
        return;
    }
    if ((sp24 == 0) && (sp1C < sp18)) {
        sp1C += func_800D8FF8();
        if (sp18 < sp1C) {
            sp1C = sp18;
        }
        func_800CE980(1, sp1C, 0);
    }
    sp20 = func_800CEA84(1);
    if (sp20 != D_8012B16A) {
        temp_v1 = &D_8011AA80[func_800CF640()];
        temp_f0 = temp_v1->pitch;
        temp_a0 = temp_v1->soundId;
        temp_a2 = temp_v1->volume;
        if (temp_f0 >= 0.0f) {
            func_800C3FF0(temp_a0, temp_f0, temp_a2);
        } else {
            func_800FC63C(temp_a0, temp_a2);
        }
        D_8012B16A = sp20;
    } BT_NATIVE_ONLY(return 0;)
}    typedef struct { u8 pad0[0xC]; s8 unkC; u8 padD[0x7]; f32 unk14; f32 unk18; s32 unk1C; } Obj1EA78C0_D_8012B160; /* offsets.py genstruct: fields from raw offsets on &D_8012B160; rename once understood */

void func_800CF160(f32 arg0, s32 arg1) {
    extern s32 D_8012B160;
    (((Obj1EA78C0_D_8012B160 *)&D_8012B160)->unkC) = 1;
    (((Obj1EA78C0_D_8012B160 *)&D_8012B160)->unk14) = arg0;
    (((Obj1EA78C0_D_8012B160 *)&D_8012B160)->unk1C) = arg1;
    (((Obj1EA78C0_D_8012B160 *)&D_8012B160)->unk18) = 0.0f;
}

void func_800CF184(void)
{
    extern u8 D_8012B16C;

    D_8012B16C = 0;
}

void func_800CF190(void) {
    void func_8008FBC0(void);
    void func_8008FBE0(u32);
    s32 func_8008FC00(void);
    s32 func_800CF580(void);
    f32 func_800CF67C(void);
    s32 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    void func_800F7B9C(BtIntPtr, u32);
    extern f32 D_8012B174;
    extern s32 D_8012B160;
    extern f32 D_8012B178;
    extern s32 D_8012B17C;

    if (func_800CF67C() != 0.0f) {
        func_800CF184();
        return;
    }
    if (func_800CF580() != 0) {
        func_800CF7F4(1U);
        func_8008FBE0(1);
        func_800D9078(&D_8012B178);
        if (D_8012B178 <= 0.0f) {
            ((Obj1EA78C0_D_8012B160 *)&D_8012B160)->unk18 = D_8012B174;
            func_8008FBC0();
            if (func_8008FC00() == 0) {
                func_800F7B9C(func_800F54E4(), D_8012B17C);
                func_800CF184();
            }
        }
    }
}

void func_800CF264(void) {
    s32 func_800CF01C();
    void func_800CF190(void);
    s32 func_800EA09C();
    extern u8 D_8012B16C;
    if (func_800EA09C() == 2) {
        func_800CF01C();
        if (D_8012B16C != 0) {
            func_800CF190();
        }
    }
}

void func_800CF2B0(void) {
    f32 func_800CEA60(s32);
    extern f32 D_8012B170;
    D_8012B170 = func_800CEA60(1);
}

void func_800CF2D4(s32 arg0) {
    s32 func_800D3E40(s32);
    u32 func_800F54E4(void);
    s32 func_800F6604(BtIntPtr);
    void func_800F7B9C(BtIntPtr, u32);
    f32 func_800CF67C(void);
    s32 func_800CF6D0(void);
    void func_800CF734(s32, s32);
    extern s32 D_8012B160;
    s32 pad;
    f32 sp20;
    f32 sp1C;

    if (func_800D3E40(9) == 0) {
        ((s16 *)&D_8012B160)[func_800CEAA8(1)] = arg0;
        sp20 = func_800CF67C();
        sp1C = func_800CEF00(arg0);
        func_800CE8D8(1, sp1C, func_800CF6D0());
        func_800CE980(1, sp20 * sp1C, 0);
        func_800CE928(1, (BtIntPtr) func_800CF734, 0);
        func_800CE88C(1, 1);
        if (func_800F6604(func_800F54E4()) != 0) {
            if (func_800CEF48(arg0) == 0.0f) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }
        } else if (func_800CEF48(arg0) != 0.0f) {
            func_800F7B9C(func_800F54E4(), 0x56);
        }
    }
}

void func_800CF40C(s32 arg0) {
    s16 func_800CF640(void);
    s32 func_800CF6D0(void);
    f32 sp1C;
    f32 sp18;

    sp1C = func_800CEA60(1);
    sp18 = func_800CEF00(func_800CF640());
    sp1C += ((f32) arg0 * sp18) / (f32) func_800CF6D0();
    if (sp18 < sp1C) {
        sp1C = sp18;
    }
    func_800CE980(1, sp1C, 0);
}

void func_800CF494(void) {
    s32 func_800D3E40(s32);
    u32 func_800F54E4(void);
    s32 func_800F6604(BtIntPtr);
    void func_800F7B9C(BtIntPtr, u32);
    s16 func_800CF640(void);
    f32 func_800CF67C(void);
    s32 func_800CF6D0(void);
    extern s32 D_8012B160;
    s32 pad;
    f32 sp20;
    f32 sp1C;
    s32 temp_a0;
    s32 temp_v0;

    if (func_800D3E40(9) == 0) {
        temp_v0 = func_800CEAA8(1);
        temp_a0 = temp_v0;
        if (((s16 *)&D_8012B160)[4] != 0) {
            ((s16 *)&D_8012B160)[4]--;
            return;
        }
        if (temp_v0 > 0) {
            ((s16 *)&D_8012B160)[temp_a0] = 9;
            sp20 = func_800CF67C();
            func_800CE88C(1, 0);
            sp1C = func_800CEF00(func_800CF640());
            func_800CE8D8(1, sp1C, func_800CF6D0());
            func_800CE980(1, sp20 * sp1C, 0);
            if (func_800F6604(func_800F54E4()) != 0) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }
        }
    }
}

/* extern */

s32 func_800CF580(void) {
    s32 func_800A9C98();
    s32 func_800D3E40(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F6BE4(BtIntPtr);
    s32 func_800F6D24(BtIntPtr);
    u8 func_800F8B88(void);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    if (func_800A9C98() != 0) {
        return 0;
    }
    if (func_800D3E40(9) != 0) {
        return 0;
    }
    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6BE4(temp_v0) == 0) {
        return 0;
    }
    if (func_800F6D24(sp1C) != 0) {
        return 0;
    }
    if (func_800F64A4(sp1C, 0x1A000) != 0) {
        return 0;
    }
    if (func_800F8B88() == 3) {
        return 0;
    }
    return 1;
}

s16 func_800CF640(void) {
    s32 func_800CEAA8();
    extern s32 D_8012B15E;
    s16 var_v1;
    s32 temp_v0;

    temp_v0 = func_800CEAA8(1);
    if (temp_v0 != 0) {
        var_v1 = BT_DATA_FIELD(D_8012B160_storage.counters[0], ((s16 *)&D_8012B15E)[temp_v0]);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

f32 func_800CF67C(void) {
    f32 func_800CEF00(s32);
    f32 sp18[2];

    sp18[0] = func_800CEA60(1);
    return sp18[0] / func_800CEF00(func_800CF640());
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s16) func_800CF6B0()
{
    BT_NATIVE_ONLY(return) func_800CEA84(0x1);
}

/* extern */

s32 func_800CF6D0(void) {
    s32 func_800DA298(s32);
    s32 var_v1;

    if (func_800DA298(0x1BF) != 0) {
        var_v1 = 0xA;
    } else {
        var_v1 = 6;
    }
    return var_v1;
}

/* extern */

void func_800CF700(void) {
    s32 func_800CE9E8(s32, s32);
    void func_800DA544(s32 index);
    func_800DA544(0x1BF);
    func_800CE9E8(1, func_800CF6D0());
}

void func_800CF734(s32 arg0, s32 arg1) {
    extern AirTimerSetting D_8011AA80[9];
    extern s16 D_8012B168;
    s32 index;
    s32 count;
    s32 i;
    AirTimerSetting *entry;

    index = func_800CF640();
    if (D_8011AA80[index].effectDuration > 0.0f) {
        entry = &D_8011AA80[index];
        func_800CF160(entry->effectDuration, entry->expiryEffect);
    }
    count = func_800CEAA8(1);
    i = 0;
    if (count > 0) {
        do {
            func_800CF494();
            i++;
        } while (i < count);
    }
    D_8012B168 = count;
    func_800CE928(1, (BtIntPtr)func_800CF734, 0);
}

/* extern */

void func_800CF7F4(u32 a0) {
    s32 func_800A16A4();
    void func_800CEBD8(s32, s32);
    s32 func_800CF580();
    if (((func_800CF580() != 0) && (func_800A16A4() == 0)) || (a0 == 0)) {
        func_800CEBD8(1, a0);
    }
}

/* extern */

void func_800CF840(s32 arg0) {
    BtIntPtr func_800CE83C(s32, s32);
    func_800CE83C(1, arg0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B020 BT_DATA(4, bss_core2bss1_1, 0x540);
s32 D_8012B030 BT_DATA(4, bss_core2bss1_1, 0x550);
s32 D_8012B15E BT_DATA(4, bss_core2bss1_1, 0x67E);
#endif
