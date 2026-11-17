#include "common.h"

/* extern */

typedef struct { u8 pad0[0x2]; s16 unk2; s16 unk4; u8 pad6[0x2]; void * unk8; u32 unkC; s32 unk10; s32 unk14; u8 pad18[0x18]; f32 unk30; f32 unk34; s32 unk38; u8 pad3C[0x2]; u8 unk3E; u8 pad3F[0x1]; s8 unk40; u8 unk41; u8 unk42; u8 unk43; } Objpod_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_ncpod(void *arg0) {
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    if ((((Objpod_arg0 *)arg0)->unk42) == 0) {
        (((Objpod_arg0 *)arg0)->unk42) = 1U;
        func_800F82D4((((Objpod_arg0 *)arg0)->unk38), 2);
    }
}

/* extern */

void func_80800038_ncpod(void *arg0) {
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    if ((((Objpod_arg0 *)arg0)->unk42) != 0) {
        (((Objpod_arg0 *)arg0)->unk42) = 0U;
        func_800F82D4((((Objpod_arg0 *)arg0)->unk38), 0);
    }
}

/* extern */

void func_8080006C_ncpod(void *arg0) {
    void _glcutDll_entrypoint_6(u32 arg0, u32 arg1);
    s32 func_800EA05C();
    if (!((((Objpod_arg0 *)arg0)->unk10) & 0x800)) {
        (*(s8 *)((s8 *)(arg0) + (0x43))) = 1;
        _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
    }
}

/* extern */

void func_808000AC_ncpod(void *arg0) {
    void _glcutDll_entrypoint_17(void);
    if ((((Objpod_arg0 *)arg0)->unk43) != 0) {
        _glcutDll_entrypoint_17();
        (((Objpod_arg0 *)arg0)->unk43) = 0U;
    }
}    typedef struct { s16 unk0; s16 unk2; s16 unk4; u8 pad6[0x2]; s32 unk8; s32 unkC; s32 unk10; s32 unk14; f32 unk18; u8 pad1C[0x8]; f32 unk24; u8 pad28[0x8]; f32 unk30; f32 unk34; s32 unk38; s16 unk3C; s8 unk3E; u8 pad3F[0x1]; s8 unk40; s8 unk41; s8 unk42; s8 unk43; f32 unk44; f32 unk48; } Objpod_ncpod_entrypoint_0_state; /* offsets.py genstruct: fields from raw offsets on state; rename once understood */

s16 ncpod_entrypoint_0(s32 arg0) {
    s16 func_8001B668(s32, s32);
    void *ncpod_entrypoint_2(s16);
    s32 func_800A940C(s32);
    void func_800EFD24(f32 *);
    s32 func_80015184();
    f32 func_800C517C(s32);
    f32 func_800C5190(s32);
    s16 handle;
    s32 pad;
    s32 data;
    s32 pad2;
    s16 allocated;
    void *state;

    allocated = func_8001B668(0, 0x4C);
    handle = allocated;
    state = ncpod_entrypoint_2(allocated);
    data = func_800A940C(arg0);
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk0 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk2 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk4 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk8 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unkC = -1;
    func_800EFD24(&((Objpod_ncpod_entrypoint_0_state *)state)->unk18);
    func_800EFD24(&((Objpod_ncpod_entrypoint_0_state *)state)->unk24);
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk34 = 1.0f;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk30 = 40.0f;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk14 = func_80015184();
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk3E = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk42 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk40 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk43 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk3C = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk38 = arg0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk10 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk41 = 0;
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk44 = func_800C517C(data);
    ((Objpod_ncpod_entrypoint_0_state *)state)->unk48 = func_800C5190(data);
    return handle;
}    typedef struct { u8 pad0[0x10]; s32 unk10; s32 unk14; u8 pad18[0x20]; s32 unk38; u8 pad3C[0x2]; u8 unk3E; u8 pad3F[0x5]; f32 unk44; f32 unk48; } Objpod_ncpod_entrypoint_1_state; /* offsets.py genstruct: fields from raw offsets on state; rename once understood */

void ncpod_entrypoint_1(s16 arg0) {
    void *ncpod_entrypoint_2(s16);
    s32 ncpod_entrypoint_12(void *, s32);
    void ncpod_entrypoint_15(void *, s32, s32);
    void func_80015178(s32);
    void func_8001B754(s16);
    s32 func_800A940C(s32);
    void func_800C5148(s32, f32);
    void func_800C51A4(s32, f32);
    void *state;
    s32 data;
    f32 value;
    f32 value2;
    s32 flags;
    s32 enabled;

    state = ncpod_entrypoint_2(arg0);
    data = func_800A940C(((Objpod_ncpod_entrypoint_1_state *)state)->unk38);
    ncpod_entrypoint_12(state, 0);
    if (((Objpod_ncpod_entrypoint_1_state *)state)->unk3E != 0) {
        enabled = (((Objpod_ncpod_entrypoint_1_state *)state)->unk10 & 0x4000) ? 0 : 1;
        ncpod_entrypoint_15(state, 0, enabled);
    }
    flags = ((Objpod_ncpod_entrypoint_1_state *)state)->unk10;
    if (!(flags & 0x8000)) {
        if (flags & 0x80000) {
            value = 40.0f;
        } else {
            value = ((Objpod_ncpod_entrypoint_1_state *)state)->unk44;
        }
        func_800C5148(data, value);
        if (((Objpod_ncpod_entrypoint_1_state *)state)->unk10 & 0x80000) {
            value2 = 1.0f;
        } else {
            value2 = ((Objpod_ncpod_entrypoint_1_state *)state)->unk48;
        }
        func_800C51A4(data, value2);
    }
    func_80015178(((Objpod_ncpod_entrypoint_1_state *)state)->unk14);
    func_808000AC_ncpod(state);
    func_8001B754(arg0);
}

/* extern */

void *ncpod_entrypoint_2(s16 arg0) {
    void *func_8001B798(s16);
    return func_8001B798(arg0);
}

void ncpod_entrypoint_3(s16 *arg0, s32 arg1) {
    arg0[30] = arg1;
}

s32 ncpod_entrypoint_4(s32 *arg0) {
    return arg0[14];
}

s32 func_808002E8_ncpod(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}    typedef struct { u8 pad0[0x2]; s16 unk2; u8 pad4[0x4]; void * unk8; s32 unkC; u8 pad10[0x2]; u16 unk12; u8 pad14[0x28]; s16 unk3C; } Objpod_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

s32 func_80800314_ncpod(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3, BtIntPtr arg4) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    s32 _ncpoducam_entrypoint_5(s16 *arg0);
    void _glcutDll_entrypoint_17(void);
    s32 _gcdialogcamera_entrypoint_1(s32, s32, BtIntPtr);
    s32 ncpod_entrypoint_17(BtIntPtr, s32);
    s32 flags;

    switch (((Objpod_arg1 *)arg1)->unk3C) {
    case 1:
        flags = _ncpoducam_entrypoint_5(_ncpoducam_entrypoint_1(((Objpod_arg1 *)arg1)->unk2));
        if (arg2 == 11) {
            if (flags & 0x100) {
                _glcutDll_entrypoint_17();
            }
            if (!(flags & 0x20)) {
                return ncpod_entrypoint_17(arg0, 0);
            }
            return 3;
        }
        break;
    case 6:
        return _gcdialogcamera_entrypoint_1(arg2, arg3, arg4);
    case 0:
    case 11:
    default:
        break;
    }
    return -1;
}

s32 ncpod_entrypoint_5(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3, BtIntPtr arg4) {
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 result;

    if (func_808002E8_ncpod(((Objpod_arg1 *)arg1)->unk8, ((Objpod_arg1 *)arg1)->unkC)) {
        result = -1;
        if (*(u16 *)((u8 *)*&((Objpod_arg1 *)arg1)->unk8 + 0x18) & 1) {
            func_80101074((void *)arg4);
            result = func_8010114C(*(s32 *)((u8 *)arg1 + 8), arg2, arg3);
            switch (result) {
            case 4:
                return 4;
            case 5:
                return result;
            default:
                result = func_80800314_ncpod(arg0, arg1, arg2, arg3, arg4);
                if (result == 4) {
                    return 4;
                }
                return result;
            }
        }
    } else {
        return func_80800314_ncpod(arg0, arg1, arg2, arg3, arg4);
    }
    return result;
}

/* extern */

s32 ncpod_entrypoint_6(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_808002E8_ncpod(void *, s32);
    if ((func_808002E8_ncpod((((Objpod_arg1 *)arg1)->unk8), (((Objpod_arg1 *)arg1)->unkC)) != 0) && ((*(u16 *)((s8 *)((((Objpod_arg1 *)arg1)->unk8)) + (0x18))) & 1)) {
        func_80101074((void *)arg4);
        return func_8010114C((*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
    return -1;
}

void ncpod_entrypoint_7(void *arg0, void *arg1) {
    (((Objpod_arg0 *)arg0)->unk8) = arg1;
    (((Objpod_arg0 *)arg0)->unkC) = (u32) (((Objpod_arg1 *)arg1)->unk12) >> 1;
}

void ncpod_entrypoint_8(u8 *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg0 + 0x18, arg1);
    func_800EE7F8(arg0 + 0x24, arg2);
    (((Objpod_arg0 *)arg0)->unk40) = 1;
}

void ncpod_entrypoint_9(void *arg0, f32 arg1) {
    ((Objpod_arg0 *)arg0)->unk30 = arg1;
}

f32 ncpod_entrypoint_10(f32 *arg0) {
    return arg0[12];
}

void ncpod_entrypoint_11(void *arg0, f32 arg1) {
    ((Objpod_arg0 *)arg0)->unk34 = arg1;
}

s32 ncpod_entrypoint_12(void *arg0, s32 arg1)
{
  s16 _ncpoddialog_entrypoint_2(void);
  void _ncpoddialog_entrypoint_3(s16);
  unsigned char new_var3;
  s16 _ncpodfixpos_entrypoint_0(void);
  u8 *new_var2;
  void _ncpodfixpos_entrypoint_1(s16);
  s16 _ncpoducam_entrypoint_0(void);
  void _ncpoducam_entrypoint_6(s16);
  u8 *new_var;
  switch (((Objpod_arg0 *)arg0)->unk41)
  {
    case 1:
      _ncpoddialog_entrypoint_3(*((s16 *) arg0));
      *((s16 *) arg0) = 0;
      break;

    case 2:
      _ncpoducam_entrypoint_6(((Objpod_arg0 *)arg0)->unk2);
      ((Objpod_arg0 *)arg0)->unk2 = 0;
      break;

    case 3:
      _ncpodfixpos_entrypoint_1(((Objpod_arg0 *)arg0)->unk4);
      new_var2 = ((u8 *) arg0) + 4;
      *((s16 *) new_var2) = 0;
      break;

  }

  new_var3 = arg1;
  switch (((Objpod_arg0 *)arg0)->unk41 = new_var3)
  {
    case 1:
      *((s16 *) arg0) = _ncpoddialog_entrypoint_2();
      break;

    case 2:
      ((Objpod_arg0 *)arg0)->unk2 = _ncpoducam_entrypoint_0();
      break;

    case 3:
      new_var = ((u8 *) arg0) + 4;
      *((s16 *) new_var) = _ncpodfixpos_entrypoint_0();
      break;

  }
  BT_NATIVE_ONLY(return 0;)
}

u32 ncpod_entrypoint_13(u8 *arg0) {
    return arg0[65];
}

void ncpod_entrypoint_14(s16 arg0, void *arg1) {
    s32 _ncpoddialog_entrypoint_1(s16 arg0, BtIntPtr arg1);
    s32 _ncpoducam_entrypoint_7(s16, void *);
    s32 _ncpodfixpos_entrypoint_6(s16 arg0, BtIntPtr arg1);
    s32 func_800A940C(s32);
    void func_8010FE14(s32 *, f32 *, f32 *);
    void func_800C5148(s32, f32);
    void func_800C51A4(s32, f32);
    s32 pad[2];
    s32 camera;
    f32 scale;
    s32 result;
    u8 *pod;

    pod = ncpod_entrypoint_2(arg0);
    result = 2;
    switch (pod[0x41]) {
        case 0:
            break;
        case 1:
            result = _ncpoddialog_entrypoint_1(*(s16 *)(pod + 0), arg1);
            break;
        case 2:
            result = _ncpoducam_entrypoint_7(*(s16 *)(pod + 2), arg1);
            break;
        case 3:
            result = _ncpodfixpos_entrypoint_6(*(s16 *)(pod + 4), arg1);
            break;
    }
    if (result != 4 && pod[0x40] != 0) {
        camera = func_800A940C(*(s32 *)(pod + 0x38));
        func_8010FE14(arg1, (f32 *)(pod + 0x18), (f32 *)(pod + 0x24));
        func_800C5148(camera, *(f32 *)(pod + 0x30));
        if (*(f32 *)(pod + 0x30) == 40.0f && *(f32 *)(pod + 0x34) != 1.0f) {
            func_800C51A4(camera, *(f32 *)(pod + 0x34));
        } else {
            func_800C51A4(camera, 1.0f);
        }
    }
}

void func_808007D8_ncpod(void *arg0, s32 arg1) {
    void func_80015178(s32);
    void ncpod_entrypoint_15(void *, s32, s32);
    s32 mode;
    s32 active;
    s32 active2;

    if (arg1 & 0x10) {
        func_80800000_ncpod(arg0);
    } else {
        func_80800038_ncpod(arg0);
    }
    if (arg1 & 0x60000) {
        if (arg1 & 0x40000) {
            mode = 4;
        } else if (arg1 & 0x20000) {
            mode = 3;
        } else {
            mode = ((Objpod_arg0 *)arg0)->unk14;
        }
        func_80015178(mode);
    }
    if (arg1 & 4) {
        if (arg1 & 0x4000) {
            active = 0;
        } else {
            active = 1;
        }
        ncpod_entrypoint_15(arg0, 0, active);
        return;
    }
    if (arg1 & 0x2000) {
        active2 = 0;
    } else {
        active2 = 1;
    }
    ncpod_entrypoint_15(arg0, 1, active2);
}

/* extern */

void ncpod_entrypoint_15(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800A940C(s32);
    s32 func_800C52F4(s32, s32);
    s32 func_800C53EC(s32, s32);
    s32 index;

    if (arg1 == ((Objpod_arg0 *)arg0)->unk3E) {
        return;
    }
        if (arg1 != 0) {
            index = func_800A940C(((Objpod_arg0 *)arg0)->unk38);
            func_800C52F4(index, arg2 ? 2 : 0);
        } else {
            index = func_800A940C(((Objpod_arg0 *)arg0)->unk38);
            func_800C53EC(index, arg2 ? 2 : 0);
        }
        ((Objpod_arg0 *)arg0)->unk3E = arg1;
}

s32 ncpod_entrypoint_16(void *arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void func_8010F9C0(BtIntPtr, s32);
    s32 func_8010FAE4(s16 *);
    void *func_80110024(s16 *);
    void ncpod_entrypoint_19(void *, s32);
    void *sp1C;
    void *temp_v0;

    if (func_8010FAE4(arg0) == 8) {
        return 0;
    }
    func_8010F9C0(arg0, 8);
    temp_v0 = func_80110024(arg0);
    sp1C = temp_v0;
    ncpod_entrypoint_3(temp_v0, arg2);
    if (arg1 != 0) {
        ncpod_entrypoint_7(sp1C, arg1);
    }
    ncpod_entrypoint_19(sp1C, arg3);
    func_8080006C_ncpod(sp1C);
    return 1;
}

s32 ncpod_entrypoint_17(BtIntPtr arg0, s32 arg1) {
    void func_80015178(s32);
    s32 func_800A940C(s32);
    void func_800C5148(s32, f32);
    void func_800C51A4(s32, f32);
    void func_8010F9C0(BtIntPtr, s32);
    void func_8010FD88(u8 *);
    BtIntPtr func_80110014(s32 *);
    void *func_80110024(s16 *);
    void func_801108A0(void *);
    void func_80110928(void *);
    s32 pad;
    s32 index;
    f32 value;
    f32 value2;
    s32 flags;
    s32 flags2;
    s32 enabled;
    s32 mode;
    u8 *pod;

    pod = func_80110024(arg0);
    index = func_800A940C(*(s32 *)(pod + 0x38));
    ncpod_entrypoint_12(pod, 0);
    if (arg1 == 0) {
        flags = *(s32 *)(pod + 0x10);
        if (!(flags & 0x8000)) {
            enabled = (flags & 0x4000) ? 0 : 1;
            ncpod_entrypoint_15(pod, 0, enabled);
            if (*(s32 *)(pod + 0x10) & 0x80000) {
                value = 40.0f;
            } else {
                value = *(f32 *)(pod + 0x44);
            }
            func_800C5148(index, value);
            if (*(s32 *)(pod + 0x10) & 0x80000) {
                value2 = 1.0f;
            } else {
                value2 = *(f32 *)(pod + 0x48);
            }
            func_800C51A4(index, value2);
        }
    }
    if (*(s32 *)(pod + 0x10) & 0x10) {
        func_80800038_ncpod(pod);
    }
    func_808000AC_ncpod(pod);
    if (arg1 != 0) {
        *(s32 *)(pod + 0x10) |= 0x8000;
    }
    func_80015178(*(s32 *)(pod + 0x14));
    flags2 = *(s32 *)(pod + 0x10);
    if (flags2 & 0x200) {
        mode = 0x200;
    } else {
        mode = (flags2 & 0x10000) ? 0x10000 : 0;
    }
    func_8010F9C0(arg0, 2);
    if (mode == 0x200) {
        func_801108A0(func_80110014(arg0));
    } else if (mode == 0x10000) {
        func_80110928(func_80110014(arg0));
    }
    if (arg1 == 0) {
        func_8010FD88(arg0);
    }
    return 4;
}    typedef struct { u8 pad0[0x3C]; s16 unk3C; } Objpod_ncpod_entrypoint_18_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s16 ncpod_entrypoint_18(BT_PARAM_OR_VOID(s16 *bt_a0)) {
    void *func_80110024();
    void *temp_v0;

    temp_v0 = func_80110024(BT_NATIVE_ONLY(bt_a0));
    if (temp_v0 == NULL) {
        return -1;
    }
    return (((Objpod_ncpod_entrypoint_18_temp_v0 *)temp_v0)->unk3C);
}

/* extern */

void ncpod_entrypoint_19(void *arg0, s32 arg1) {
    func_808007D8_ncpod(arg0, arg1);
    (((Objpod_arg0 *)arg0)->unk10) = arg1;
}    typedef struct { u8 pad0[0x2]; s16 unk2; } Objpod_ncpod_entrypoint_20_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

s32 ncpod_entrypoint_20(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    void _ncpoducam_entrypoint_2(u8 *arg0, s16 *arg1, s32 arg2);
    void _ncpoducam_entrypoint_3(void *arg0, void *arg1);
    void _ncpoducam_entrypoint_4(s16 *arg0, s32 arg1);
    void func_8010FD88(u8 *);
    void *func_80110024();
    s32 ncpod_entrypoint_12(void *, s32);
    void *sp1C;
    BtIntPtr sp18;
    BtIntPtr temp_v0_2;
    void *temp_v0;

    temp_v0 = func_80110024();
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 2);
    temp_v0_2 = _ncpoducam_entrypoint_1((((Objpod_ncpod_entrypoint_20_sp1C *)sp1C)->unk2));
    sp18 = temp_v0_2;
    _ncpoducam_entrypoint_4(temp_v0_2, arg3);
    ncpod_entrypoint_19(sp1C, arg3);
    if (arg1 != 0) {
        _ncpoducam_entrypoint_3(sp18, arg1);
    }
    _ncpoducam_entrypoint_2(sp18, arg0, arg2);
    func_8010FD88(arg0);
    return 4;
}

void ncpod_entrypoint_21(s16 *arg0, s32 arg1, s32 arg2) {
    void *_ncpoddialog_entrypoint_0(s16 arg0);
    void _ncpoddialog_entrypoint_9(void *arg0, s16 *arg1, int arg2, s32 arg3);
    void *func_80110024(s16 *);
    _ncpoddialog_entrypoint_9(_ncpoddialog_entrypoint_0(*(s16 *)func_80110024(arg0)), arg0, arg1, arg2);
}

/* extern */

void ncpod_entrypoint_22(s16 *arg0, s32 arg1, BtIntPtr arg2) {
    void *_ncpoddialog_entrypoint_0(s16 arg0);
    void _ncpoddialog_entrypoint_4(u8 *arg0, s32 arg1, f32 *arg2);
    _ncpoddialog_entrypoint_4(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_23(s16 *arg0, s32 arg1, BtIntPtr arg2) {
    void *_ncpoddialog_entrypoint_0(s16 arg0);
    void _ncpoddialog_entrypoint_5(u8 *arg0, s32 arg1, f32 *arg2);
    _ncpoddialog_entrypoint_5(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_24(s16 *arg0, s32 arg1, BtIntPtr arg2) {
    void *_ncpoddialog_entrypoint_0(s16 arg0);
    void _ncpoddialog_entrypoint_6(BtIntPtr arg0, s32 arg1, f32 *arg2);
    _ncpoddialog_entrypoint_6(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_25(s16 *arg0, s32 arg1) {
    void *_ncpoddialog_entrypoint_0(s16 arg0);
    void _ncpoddialog_entrypoint_7(void *arg0, s32 arg1);
    _ncpoddialog_entrypoint_7(_ncpoddialog_entrypoint_0(*arg0), arg1);
}    typedef struct { u8 pad0[0x2]; s16 unk2; } Objpod_ncpod_entrypoint_26_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

s32 ncpod_entrypoint_26(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    void _ncpoducam_entrypoint_2(u8 *arg0, s16 *arg1, s32 arg2);
    void _ncpoducam_entrypoint_3(void *arg0, void *arg1);
    void _ncpoducam_entrypoint_4(s16 *arg0, s32 arg1);
    void func_8010FD88(u8 *);
    void *func_80110024(s16 *);
    s32 ncpod_entrypoint_12(void *, s32);
    s32 ncpod_entrypoint_16(void *, BtIntPtr, s32, s32);
    void ncpod_entrypoint_7(void *, void *);
    void *sp1C;
    BtIntPtr sp18;
    BtIntPtr temp_v0_2;
    void *temp_v0;

    if (ncpod_entrypoint_16(arg0, 0, 1, arg4) == 0) {
        return 0;
    }
    temp_v0 = func_80110024(arg0);
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 2);
    if (arg2 != 0) {
        ncpod_entrypoint_7(sp1C, arg2);
    } else if (arg1 != 0) {
        ncpod_entrypoint_7(sp1C, arg1);
    }
    temp_v0_2 = _ncpoducam_entrypoint_1((((Objpod_ncpod_entrypoint_26_sp1C *)sp1C)->unk2));
    sp18 = temp_v0_2;
    if (arg1 != 0) {
        _ncpoducam_entrypoint_3(sp18, arg1);
    }
    _ncpoducam_entrypoint_4(sp18, arg4);
    _ncpoducam_entrypoint_2(sp18, arg0, arg3);
    func_8010FD88(arg0);
    return 1;
}

/* extern */

s32 ncpod_entrypoint_27(s32 arg0, s32 arg1) {
    void func_8010F9C0(BtIntPtr, s32);
    void *func_80110024();
    s32 ncpod_entrypoint_17(BtIntPtr, s32);
    s32 sp18;
    s32 temp_v0;

    func_80110024();
    temp_v0 = ncpod_entrypoint_17(arg0, arg1);
    sp18 = temp_v0;
    func_8010F9C0(arg0, 2);
    return temp_v0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) ncpod_entrypoint_28(s16 *arg0, s32 arg1) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    s32 _ncpoducam_entrypoint_8(void *arg0, s32 arg1);
    void *func_80110024(s16 *);
    BT_NATIVE_ONLY(return) _ncpoducam_entrypoint_8(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) ncpod_entrypoint_29(s16 *arg0, s32 arg1) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    s32 _ncpoducam_entrypoint_9(void *arg0, volatile s32 arg1);
    void *func_80110024(s16 *);
    BT_NATIVE_ONLY(return) _ncpoducam_entrypoint_9(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) ncpod_entrypoint_30(BT_PARAM_OR_VOID(s16 *bt_a0)) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    f32 _ncpoducam_entrypoint_10(void *arg0);
    void *func_80110024();
    BT_NATIVE_ONLY(return) _ncpoducam_entrypoint_10(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(BT_NATIVE_ONLY(bt_a0))) + (2)))));
}

/* extern */

void ncpod_entrypoint_31(s16 *arg0, BtIntPtr arg1) {
    void * _ncpoducam_entrypoint_1(s16 arg0);
    s32 _ncpoducam_entrypoint_11(BtIntPtr, BtIntPtr);
    void *func_80110024(s16 *);
    _ncpoducam_entrypoint_11(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}    typedef struct { u8 pad0[0x4]; s16 unk4; } Objpod_ncpod_entrypoint_32_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

s32 ncpod_entrypoint_32(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void *_ncpodfixpos_entrypoint_2(s16 arg0);
    void _ncpodfixpos_entrypoint_3(u8 *arg0, BtIntPtr arg1, s32 arg2);
    void _ncpodfixpos_entrypoint_4(u8 *arg0, u8 *arg1);
    void _ncpodfixpos_entrypoint_5(s16 *arg0, s32 arg1);
    void *func_80110024();
    s32 ncpod_entrypoint_12(void *, s32);
    void *sp1C;
    BtIntPtr sp18;
    BtIntPtr temp_v0_2;
    void *temp_v0;

    temp_v0 = func_80110024();
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 3);
    temp_v0_2 = _ncpodfixpos_entrypoint_2((((Objpod_ncpod_entrypoint_32_sp1C *)sp1C)->unk4));
    sp18 = temp_v0_2;
    _ncpodfixpos_entrypoint_5(temp_v0_2, arg3);
    if (arg1 != 0) {
        _ncpodfixpos_entrypoint_4(sp18, arg1);
    }
    _ncpodfixpos_entrypoint_3(sp18, arg0, arg2);
    return 4;
}    typedef struct { u8 pad0[0x4]; s16 unk4; } Objpod_ncpod_entrypoint_33_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

s32 ncpod_entrypoint_33(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    void *_ncpodfixpos_entrypoint_2(s16 arg0);
    void _ncpodfixpos_entrypoint_3(u8 *arg0, BtIntPtr arg1, s32 arg2);
    void _ncpodfixpos_entrypoint_4(u8 *arg0, u8 *arg1);
    void _ncpodfixpos_entrypoint_5(s16 *arg0, s32 arg1);
    void func_8010FD88(u8 *);
    void *func_80110024(s16 *);
    s32 ncpod_entrypoint_12(void *, s32);
    s32 ncpod_entrypoint_16(void *, BtIntPtr, s32, s32);
    void ncpod_entrypoint_7(void *, void *);
    void *sp1C;
    BtIntPtr sp18;
    BtIntPtr temp_v0_2;
    void *temp_v0;

    if (ncpod_entrypoint_16(arg0, 0, 0xB, arg4) == 0) {
        return 0;
    }
    temp_v0 = func_80110024(arg0);
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 3);
    if (arg2 != 0) {
        ncpod_entrypoint_7(sp1C, arg2);
    } else if (arg1 != 0) {
        ncpod_entrypoint_7(sp1C, arg1);
    }
    temp_v0_2 = _ncpodfixpos_entrypoint_2((((Objpod_ncpod_entrypoint_33_sp1C *)sp1C)->unk4));
    sp18 = temp_v0_2;
    _ncpodfixpos_entrypoint_5(temp_v0_2, arg4);
    if (arg1 != 0) {
        _ncpodfixpos_entrypoint_4(sp18, arg1);
    }
    _ncpodfixpos_entrypoint_3(sp18, arg0, arg3);
    func_8010FD88(arg0);
    return 1;
}
