#include "common.h"

void func_80800044_chdumbwaiterlift(Actor *arg0);
void func_80105834(Actor *);
void func_8080035C_chdumbwaiterlift(void *arg0, BtIntPtr arg1);
void func_80800268_chdumbwaiterlift(u8 *arg0);
void func_8080000C_chdumbwaiterlift(BtIntPtr arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808002C0_chdumbwaiterlift(Actor *arg0, s32 arg1, s32 arg2);

s16 D_80800BC0_chdumbwaiterlift[][4] = {
    { 257, 15, 2569, 7310 },
    { 262, 15, 2570, 1344 },
    { 264, 9, 2571, 528 },
    { 267, 9, 2572, 772 },
    { 270, 9, 2573, 268 }
};

BtFnWord D_80800BE8_chdumbwaiterlift[] = {
    0x00A603E0, 0x07AB0001, 0x00000000, (BtFnWord)func_80800044_chdumbwaiterlift,
    (BtFnWord)func_80105834, (BtFnWord)func_8080035C_chdumbwaiterlift, 0x01F40000, 0x00000000,
    0x00000000, 0x20000804, (BtFnWord)func_80800268_chdumbwaiterlift, 0x00000000,
    0x00000000, (BtFnWord)func_8080000C_chdumbwaiterlift, (BtFnWord)func_80107C2C, 0x80080412,
    (BtFnWord)func_808002C0_chdumbwaiterlift, 0x00000000
};

u32 D_80800C30_chdumbwaiterlift[] = { 0x001305B9, 0x0002000E, 0x00F3010C, 0x00190000 };

u32 D_80800C40_chdumbwaiterlift[] = { 0x001304C7, 0x00180002, 0x00000000, 0x00000000 };

OSThread *chdumbwaiterlift_entrypoint_0(void)
{
    return (OSThread *) D_80800BE8_chdumbwaiterlift;
}

/* extern */

void func_8080000C_chdumbwaiterlift(BtIntPtr arg0) {
    void func_800EE7F8();
    void func_8010A828(void **, s32);
    func_800EE7F8(arg0 + 0x28, arg0 + 4, arg0);
    func_8010A828(arg0, 2);
}

void func_80800044_chdumbwaiterlift(Actor *arg0) {
    s32 _capod_entrypoint_22(void);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void _gcnewoption_entrypoint_0(void *arg0);
    void _gcnewoption_entrypoint_6(Actor *, s16);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    s32 _subaddieaudioloop_entrypoint_4(Actor *arg0, f32 *arg1, u32 arg2, u32 *arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 func_800D9078(f32 *arg0);
    void func_800DA544(s32 index);
    void func_800EFE50(f32 dst[3], f32 start[3], f32 end[3], f32 t);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    void * func_80100094(Actor *arg0, u32 arg1);
    void func_80101FDC(Actor *arg0, u32 arg1);
    void func_8010A828(void **arg0, s32 arg1);
    void func_80800770_chdumbwaiterlift(Actor *arg0);
    void func_80800804_chdumbwaiterlift(Actor *arg0);
    s32 func_808008B4_chdumbwaiterlift(void);
    u32 moving;
    moving = (arg0->unk70_10 == 2 || arg0->unk70_10 == 6);
    if (moving || (!moving && arg0->unk5F != 0)) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, moving, D_80800C30_chdumbwaiterlift);
    }
    switch (arg0->unk70_10) {
    case 1:
        func_80800770_chdumbwaiterlift(arg0);
        break;
    case 2:
        {
            int sp40;
            f32 factor2;
            sp40 = func_800D9078(&arg0->unk58);
            factor2 = func_800F10B4(arg0->unk58, 0.0f, 3.0f, 1.0f, 0.0f);
            func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4], (f32 *)arg0->actorData, factor2);
            if (sp40) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800C40_chdumbwaiterlift);
                func_80101FDC(arg0, 1);
                _subaddieDll_entrypoint_4(arg0, 0);
                _capod_entrypoint_22();
            }
            break;
        }
    case 3:
        func_80800804_chdumbwaiterlift(arg0);
        break;
    case 4:
        _gcnewoption_entrypoint_0(func_80100094(arg0, 0));
        break;
    case 5:
        _gcnewoption_entrypoint_6(arg0, 0);
        func_80101FDC(arg0, 1);
        func_8010A828((void **)arg0, 2);
        break;
    case 6:
        {
            int sp38;
            f32 factor6;
            sp38 = func_800D9078(&arg0->unk58);
            factor6 = func_800F10B4(arg0->unk58, 0.0f, 3.0f, 1.0f, 0.0f);
            func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4], (f32 *)arg0->actorData, factor6);
            if (sp38) {
                func_800DA544(D_80800BC0_chdumbwaiterlift[func_808008B4_chdumbwaiterlift()][2]);
                _subaddieDll_entrypoint_4(arg0, 0);
                _gcgoto_entrypoint_1(D_80800BC0_chdumbwaiterlift[arg0->unk6C_0][0], D_80800BC0_chdumbwaiterlift[arg0->unk6C_0][1]);
            }
            break;
        }
    }
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objdumbwaiterlift_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800268_chdumbwaiterlift(u8 *arg0)
{
  s32 func_800C53EC(s32, s32);
  void *func_80100094(Actor *, u32);
  void _gcnewoption_entrypoint_6(Actor *, s16);
  if (((((u16) (((Objdumbwaiterlift_arg0 *)arg0)->unk72)) & 0xFFFFFFFFu) >> 0xA) == 6)
  {
    func_800C53EC(0, 0);
  }
  if (func_80100094(arg0, 0) != 0)
  {
    _gcnewoption_entrypoint_6(arg0, 0);
  }
}

s32 func_808002C0_chdumbwaiterlift(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_808003C4_chdumbwaiterlift(Actor *);
    void func_80800608_chdumbwaiterlift(Actor *, void *, s32, s32);
    void func_80800B40_chdumbwaiterlift(Actor *);
    s16 *data = (s16 *)&arg2;

    switch (arg1) {
        case 0x2E:
            func_80800B40_chdumbwaiterlift(arg0);
            func_80101FDC(arg0, 1);
            break;
        case 0x95:
            func_808003C4_chdumbwaiterlift(arg0);
            break;
        case 0x20:
            func_80800608_chdumbwaiterlift(arg0, func_80101080(), data[0], data[1]);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080035C_chdumbwaiterlift(void *arg0, BtIntPtr arg1)
{
  void _gcnewoption_entrypoint_1(u8 *arg0, BtIntPtr arg1);
  s32 func_800EB854();
  void *func_80100094(Actor *, u32);
  void func_80101870(Actor* arg0, void* arg1);
  if (func_800EB854() == 3)
  {
    if (((((u16) (((Objdumbwaiterlift_arg0 *)arg0)->unk72)) & 0xFFFFFFFFu) >> 0xA) == 4)
    {
      _gcnewoption_entrypoint_1(func_80100094(arg0, 0), arg1);
    }
  }
  else
  {
    func_80101870(arg0, arg1);
  }
}

void func_808003C4_chdumbwaiterlift(Actor *arg0) {
    s32 _capod_entrypoint_21(BtIntPtr, BtIntPtr, s32, s32);
    void _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800EA090(void);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800F832C(BtIntPtr, f32 *);
    void func_80101FDC(Actor *, u32);
    s32 func_808008B4_chdumbwaiterlift(void);
    s32 func_8080094C_chdumbwaiterlift(void);
    BtIntPtr sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp34 = func_800F54E4();
    sp30 = func_800EA090();
    sp2C = func_808008B4_chdumbwaiterlift();
    if (sp30 == D_80800BC0_chdumbwaiterlift[sp2C][1]) {
        sp28 = func_8080094C_chdumbwaiterlift();
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        arg0->position[1] += sp28 < sp2C ? -150.0f : 150.0f;
        func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
        arg0->unk58 = 3.0f;
        func_80101FDC(arg0, 2);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_800F608C(sp34, 1);
        func_800F8294(sp34, arg0->position);
        func_800F832C(sp34, arg0->rotation);
        _capod_entrypoint_21(arg0->unk0, 0, ((u8 *)D_80800BC0_chdumbwaiterlift[sp2C])[6], 0x2010);
    }
}

/* extern */

void func_808004E8_chdumbwaiterlift(BtIntPtr arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) _gcnewoption_entrypoint_32(void *arg0, s16 arg1);
    void _gcnewoption_entrypoint_40(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);
    _gcnewoption_entrypoint_14(arg1, 0, 1, 4, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0xA3);
}

void func_80800560_chdumbwaiterlift(BtIntPtr arg0) {
    void _gcnewoption_entrypoint_12(void *a0, u32 optionIndex, s16 textIndex);
    void _gcnewoption_entrypoint_21(BtIntPtr arg0, s32 arg1);
    void _gcnewoption_entrypoint_31(BtIntPtr, s32, s16);
    s32 func_800EA05C();
    s32 var_s0;
    s32 var_s1;
    s16 flag;

    var_s0 = 0;
    for (var_s1 = 0; var_s1 < 5; var_s1++) {
        if (func_800EA05C() != D_80800BC0_chdumbwaiterlift[var_s1][0]) {
            _gcnewoption_entrypoint_12(arg0, var_s0, (s16) (var_s1 + 0xA));
            _gcnewoption_entrypoint_21(arg0, var_s0);
            _gcnewoption_entrypoint_31(arg0, var_s0, flag = ((u8 *)D_80800BC0_chdumbwaiterlift[var_s1])[7]);
            var_s0 += 1;
        }
    }
}

void func_80800608_chdumbwaiterlift(Actor *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _capod_entrypoint_21(BtIntPtr, BtIntPtr, s32, s32);
    void _subaddieDll_entrypoint_4(void *, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
    void func_800F8444(BtIntPtr, f32 *);
    void func_80101FDC(Actor *, u32);
    s32 func_808008B4_chdumbwaiterlift(void);
    s32 func_808009B8_chdumbwaiterlift(s32);
    void func_80800B40_chdumbwaiterlift(Actor *);
    s32 sp34;
    s32 sp30;
    f32 offset;

    switch (arg3) {
        case 0:
            func_80800560_chdumbwaiterlift(arg1);
            return;
        case 2:
            func_80800B40_chdumbwaiterlift(arg0);
            func_80101FDC(arg0, 5);
            return;
        case 3:
            sp34 = func_808009B8_chdumbwaiterlift(arg2);
            sp30 = func_808008B4_chdumbwaiterlift();
            arg0->unk6C_0 = sp34;
            func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
            func_800EE7F8((f32 *)arg0->actorData, arg0->position);
            if (sp34 < sp30) {
                offset = -150.0f;
            } else {
                offset = 150.0f;
            }
            ((f32 *)arg0->actorData)[1] += offset;
            arg0->unk58 = 3.0f;
            func_80101FDC(arg0, 6);
            func_800F8418(func_800F54E4(), arg0->position);
            func_800F8444(func_800F54E4(), arg0->rotation);
            func_80800B40_chdumbwaiterlift(arg0);
            _capod_entrypoint_21(arg0->unk0, 0, ((u8 *)D_80800BC0_chdumbwaiterlift[sp30])[6], 0x2010);
            _subaddieDll_entrypoint_4(arg0, 1);
            return;
    }
}

/* extern */

void func_80800770_chdumbwaiterlift(Actor *arg0) {
    void _chmrtannoy_entrypoint_0(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    void func_80101FDC(Actor *, u32);
    void func_80800A8C_chdumbwaiterlift(Actor *);
    if (_subaddiedialog_entrypoint_4(arg0->position, 0x50, 0) != 0) {
        if (func_80090178(0x40) == 0) {
            _chmrtannoy_entrypoint_0();
            func_80800A8C_chdumbwaiterlift(arg0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x133F, 0xF, NULL, 0xA3);
            func_80101FDC(arg0, 7);
            return;
        }
        func_80101FDC(arg0, 3);
    }
}

void func_80800804_chdumbwaiterlift(Actor *arg0) {
    void _gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _gcnewoption_entrypoint_8(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_9(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_10(void *arg0, s32 arg1);
    void _gcnewoption_entrypoint_11(s16 *arg0);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_8010A828(void **, s32);
    void func_80800A8C_chdumbwaiterlift(Actor *);
    extern s32 _gcnewoption_entrypoint_16;
    extern s32 _gcnewoption_entrypoint_35;
    BtIntPtr option;

    _gcnewoption_entrypoint_4(arg0, 0, &_gcnewoption_entrypoint_16, &_gcnewoption_entrypoint_35, 0x184E);
    option = func_80100094(arg0, 0);
    _gcnewoption_entrypoint_8(option, 4);
    _gcnewoption_entrypoint_9(option, 4);
    _gcnewoption_entrypoint_10(option, 0);
    func_808004E8_chdumbwaiterlift(arg0, option);
    _gcnewoption_entrypoint_11(option);
    func_80101FDC(arg0, 4);
    func_80800A8C_chdumbwaiterlift(arg0);
    func_8010A828(arg0, 0xA);
}

s32 func_808008B4_chdumbwaiterlift(void) {
    s32 func_800EA05C();
    s32 map;
    s32 i;

    map = func_800EA05C();
    for (i = 0; i < 5; i++) {
        if (map == D_80800BC0_chdumbwaiterlift[i][0]) {
            return i;
        }
    }
    return -1;
}

s32 func_8080094C_chdumbwaiterlift(void) {
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s16 (*var_s0)[4];
    s32 var_s1;

    var_s0 = D_80800BC0_chdumbwaiterlift;
    var_s1 = 0;
loop_1:
    if (func_800DA298((*var_s0)[2]) != 0) {
        func_800DA524((*var_s0)[2]);
        return var_s1;
    }
    var_s1 += 1;
    var_s0 += 1;
    if (var_s1 == 5) {
        return -1;
    }
    goto loop_1;
}

s32 func_808009B8_chdumbwaiterlift(s32 arg0) {
    s32 func_800EA05C();
    s32 map;
    s32 count;
    s32 i;

    map = func_800EA05C();
    count = 0;
    for (i = 0; i < 5; i++) {
        if (map != D_80800BC0_chdumbwaiterlift[i][0]) {
            if (arg0 == count) {
                return i;
            }
            count++;
        }
    }
    return -1;
}

/* extern */

void func_80800A8C_chdumbwaiterlift(Actor *arg0) {
    void _capod_entrypoint_11(u32, f32 *);
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_8();
    void _subaddieDll_entrypoint_4(void *, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F8444(BtIntPtr, f32 *);
    f32 sp24[3];

    if (!arg0->unk64_20) {
        func_800EFA4C(sp24, 0.0f, arg0->rotation[1], 0.0f);
        func_800F8444(func_800F54E4(), sp24);
        _capod_entrypoint_2(arg0->unk0, 0x1B, 0x10);
        _capod_entrypoint_8(1);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_11(1, sp24);
        _capod_entrypoint_7(5, 0);
        _subaddieDll_entrypoint_4(arg0, 1);
        arg0->unk64_20 = 1;
    }
}

void func_80800B40_chdumbwaiterlift(Actor *arg0) {
    s32 _capod_entrypoint_3(s32 arg0);
    void _subaddieDll_entrypoint_4(void *, s32);
    if (arg0->unk64_20) {
        _capod_entrypoint_3(0U);
        _subaddieDll_entrypoint_4(arg0, 0U);
        *(volatile u8 *)((s8 *)arg0 + 0x65) = *(volatile u8 *)((s8 *)arg0 + 0x65) & 0xFFEF;
    }
}
