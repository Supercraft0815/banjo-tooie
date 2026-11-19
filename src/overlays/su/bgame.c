#include "common.h"

void susubgame_entrypoint_12(void *, void *);     
void susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2) {
    extern s32 D_80800970_susubgame;
    (*(s8 *)(arg1 + 0)) = 0;
    (*(s16 *)(arg1 + 2)) = arg2;
    (*(s8 *)(arg1 + 1)) = 0;
    (*(s16 *)(arg1 + 4)) = 0x15;
    susubgame_entrypoint_12(arg1, &D_80800970_susubgame);
}    typedef struct { f32 unk0; s16 unk4; u8 pad6[0x2]; f32 unk8; f32 unkC; } Objbgame_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void susubgame_entrypoint_1(BtIntPtr arg0, u8 *arg1, s32 arg2) {
    (((Objbgame_arg1 *)arg1)->unk4) = arg2;
}

u8 susubgame_entrypoint_2(BtIntPtr arg0, u8 *arg1) {
    return *arg1;
}

/* extern */

s32 susubgame_entrypoint_3(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 susubgame_entrypoint_5(BtIntPtr, u8 *, s32, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg2, arg3) != 0) {
        if (*arg1 != 2) {
            susubgame_entrypoint_5(arg0, arg1, 5, 1, 0);
        }
        return 2;
    }
    return 1;
}

/* extern */

int susubgame_entrypoint_4(BtIntPtr arg0, u8 *arg1) {
    void _glcutDll_entrypoint_17();
    s32 _ncpod_entrypoint_17(BtIntPtr, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
    if (arg1[0] != 0) {
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_17(func_800A93E4(var_s0), 0);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        arg1[0] = 0;
        if (arg1[1] != 0) {
            arg1[1] = 0;
            _glcutDll_entrypoint_17();
        }
        return 1;
    }
    return 0;
}

s32 susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    typedef struct {
    u8 state;
    u8 unk1;
    s16 flags;
    s16 unk4;
    s16 unk6;
    f32 scale[4];

    }
    SubgameData;
    s32 _ncpod_entrypoint_12(BtIntPtr, s32);
    s32 _ncpod_entrypoint_21(BtIntPtr, s32, s32);
    s32 _ncpod_entrypoint_22();
    s32 _ncpod_entrypoint_23();
    s32 _ncpod_entrypoint_24();
    BtIntPtr func_800A93E4(BtIntPtr);
    s32 func_800D3948(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_8010CD50(Actor *, BtUIntPtr);
    void *func_80110024(s16 *);
    void func_8080078C_susubgame(BtIntPtr, s32);
    void func_80800814_susubgame(s32 *, void *, s32);
    int func_808008DC_susubgame(s32);
    BtIntPtr pod;
    s32 i;
    BtIntPtr handle;
    f32 scale[4];
    f32 rotation[3];
    if (func_800D3948() != 0) {
    arg4 |= 4;

    }
    switch (((SubgameData *)arg1)->state) {
    case 0: func_80800814_susubgame((s32 *)arg0, arg1, arg4);
    case 1: case 3: for (i = 0;
    i < 4;
    i++) {
    scale[i] = ((SubgameData *)arg1)->scale[i] * ((Actor *)arg0)->scale;

    }
    i = 0;
    do {
    if (func_808008DC_susubgame(i) != 0) {
    handle = func_800A93E4(i);
    pod = (BtIntPtr)func_80110024((s16 *)func_800A93E4(i));
    _ncpod_entrypoint_12(pod, 1);
    _ncpod_entrypoint_22(pod, 0, scale);
    _ncpod_entrypoint_23(pod, 0, ((Actor *)arg0)->position);
    if (((SubgameData *)arg1)->flags & 1) {
    func_800EFA4C(rotation, 0.0f, func_8010CD50((Actor *)arg0, i), 0.0f);
    _ncpod_entrypoint_24(pod, 0, rotation);

    }
    else {
    _ncpod_entrypoint_24(pod, 0, ((Actor *)arg0)->rotation);

    }
    func_8080078C_susubgame(handle, i);

    }
    i++;

    }
    while (i < 8);
    ((SubgameData *)arg1)->state = 2;
    case 2: i = 0;
    do {
    if (func_808008DC_susubgame(i) != 0) {
    _ncpod_entrypoint_21(func_800A93E4(i), arg2, arg3);

    }
    i++;

    }
    while (i < 8);
    return;

    } BT_NATIVE_ONLY(return 0;)
    }

void susubgame_entrypoint_6(s32 *arg0, u8 *arg1, s32 arg2, s32 arg3, BtIntPtr arg4) {
    s32 _ncpod_entrypoint_20(BtIntPtr, BtIntPtr, s32, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    void func_80800814_susubgame(s32 *, void *, s32);

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 2:
    case 3:
        *arg1 = 1;
    case 1:
        _ncpod_entrypoint_20(func_800A93E4(func_800F54E4()), arg4, arg2, arg3 | 0x800);
        return;
    }
}

void susubgame_entrypoint_7(s32 *arg0, u8 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 _ncpod_entrypoint_20(BtIntPtr, BtIntPtr, s32, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    void func_80800814_susubgame(s32 *, void *, s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 2:
    case 3:
        *arg1 = 1;
    case 1:
        var_s0 = 0;
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_20(func_800A93E4(var_s0), arg4, arg2[var_s0], arg3 | 0x800);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        return;
    }
}

void susubgame_entrypoint_8(s32 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _ncpod_entrypoint_32(BtIntPtr, BtIntPtr, s32, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    void func_80800814_susubgame(s32 *, void *, s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 1:
    case 2:
        *arg1 = 3;
    case 3:
        var_s0 = 0;
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_32(func_800A93E4(var_s0), arg4, arg2, arg3 | 0x800);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        return;
    }
}

/* extern */

s32 susubgame_entrypoint_9(void) {
    s32 func_800F6F00(s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if ((func_808008DC_susubgame(var_s0) != 0) && (func_800F6F00(var_s0) == 0)) {
        return 0;
    }
    var_s0 += 1;
    if (var_s0 == 8) {
        return 1;
    }
    goto loop_1;
}

s32 susubgame_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800F832C(BtIntPtr, f32 *);
    extern s32 func_8010D5DC;
    f32 sp38[6];
    s32 sp34;
    f32 sp24[4];
    BtIntPtr temp_s0;

    sp34 = func_800DA9E4(arg3, 1) == 0;
    temp_s0 = func_800F54E4();
    if (_subaddiemarker_entrypoint_0(arg0, arg2, sp38, 1) == 0) {
        return 0;
    }
    if (sp34 != 0) {
        func_800F608C(temp_s0, arg1);
        func_800F497C(temp_s0);
        func_800F49A8(temp_s0, 1);
        func_800F49D4(temp_s0, &func_8010D5DC, arg0->unk0);
        func_800F4A58(temp_s0, sp38, 200.0f);
    } else {
        func_800EFA4C(sp24, 0.0f, sp38[4], 0.0f);
        func_800F608C(temp_s0, arg1);
        func_800F8294(temp_s0, sp38);
        func_800F832C(temp_s0, sp24);
        func_800F497C(temp_s0);
    }
    return sp34;
}

/* extern */

void susubgame_entrypoint_11(s32 arg0) {
    void func_800CE88C(s32 arg0, s32 arg1);
    s32 func_800CEAA8();
    if (func_800CEAA8() != 0) {
        func_800CE88C(arg0, 0);
    }
}

/* extern */

void func_8080078C_susubgame(BtIntPtr arg0, s32 arg1) {
    void _gcdialogcamera_entrypoint_7(BtUIntPtr arg0, f32 *arg1);
    s32 _ncpod_entrypoint_22(BtIntPtr, s32, BtIntPtr);
    s32 _ncpod_entrypoint_23(BtIntPtr, s32, BtIntPtr);
    s32 _ncpod_entrypoint_24(BtIntPtr, s32, BtIntPtr);
    BtIntPtr func_800A93E4(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5DC8(BtIntPtr player, f32 rotation[3]);
    void *func_80110024(s16 *);
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp20[4];
    void *sp1C;

    sp1C = func_80110024(func_800A93E4(arg1));
    func_800F5A00(arg1, sp3C);
    func_800F5DC8(arg1, sp30);
    _ncpod_entrypoint_23(sp1C, 1, sp3C);
    _ncpod_entrypoint_24(sp1C, 1, sp30);
    _gcdialogcamera_entrypoint_7(arg1, sp20);
    _ncpod_entrypoint_22(sp1C, 1, sp20);
}

/* extern */

void func_80800814_susubgame(s32 *arg0, void *arg1, s32 arg2) {
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _ncpod_entrypoint_16(BtIntPtr, BtIntPtr, s32, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    s32 func_800EA05C();
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_808008DC_susubgame(var_s0) != 0) {
            _ncpod_entrypoint_16(func_800A93E4(var_s0), *arg0, (((Objbgame_arg1 *)arg1)->unk4), arg2 | 0x800);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
    if (arg2 & 0x800) {
        (*(u8 *)((s8 *)(arg1) + (1))) = 0U;
    } else {
        (*(u8 *)((s8 *)(arg1) + (1))) = 1U;
    }
    if ((*(u8 *)((s8 *)(arg1) + (1))) != 0) {
        _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
    }
}

/* extern */

int func_808008DC_susubgame(s32 arg0) {
    s32 func_800A9420(s32);
    s32 func_800D3948(void);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    if (func_800D3948() != 0) {
        return func_800F6438(arg0) != 0 && func_800A9420(arg0) != 0;
    } else {
        return func_800F54E4() == arg0;
    }
}                  typedef struct { u8 pad0[0x8]; f32 unk8; f32 unkC; f32 unk10; f32 unk14; } Objbgame_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void susubgame_entrypoint_12(void *arg0, void *arg1) {
    (((Objbgame_arg0 *)arg0)->unk8) = (f32) (((Objbgame_arg1 *)arg1)->unk0);
    (((Objbgame_arg0 *)arg0)->unkC) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (((Objbgame_arg0 *)arg0)->unk10) = (f32) (((Objbgame_arg1 *)arg1)->unk8);
    (((Objbgame_arg0 *)arg0)->unk14) = (f32) (((Objbgame_arg1 *)arg1)->unkC);
}
/* data_to_c.py: from asm/data/overlays/su/bgame.data.s */
s32 D_80800970_susubgame BT_DATA(4, overlays_su_bgame, 0x0) = 0;
