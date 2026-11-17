#include "common.h"

void func_80800000_chtimetable(BtIntPtr arg0, s32 arg1, f32 *arg2) {
    Prop* _gccubesearch_entrypoint_1(u32, f32[3]);
    void _gspropctrl_entrypoint_11(Prop*, f32[3]);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg1 + 0x51F, arg0 + 4), arg2);
    arg2[2] = -1100.0f;
    arg2[1] = -50.0f;
}

/* extern */

void func_80800058_chtimetable(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.75f);
    func_80800000_chtimetable((BtIntPtr) arg0, 0, (f32 *)((s8 *)arg0 + 0x28));
    func_80800000_chtimetable((BtIntPtr) arg0, 1, (f32 *)((s8 *)arg0 + 0x18));
}    typedef struct { s32 unk0; u8 pad4[0x10]; s32 unk14; u8 pad18[0x10]; s32 unk28; u8 pad2C[0x10]; s32 unk3C; } Objtimetable_func_808000B0_chtimetable_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

s32 func_808000B0_chtimetable(s32 arg0) {
    extern s32 D_80800730_chtimetable;
    extern s32 D_80800744_chtimetable;
    extern s32 D_80800758_chtimetable;
    extern s32 D_8080076C_chtimetable;
    s32 *var_v0;
    s32 var_v1;

    if (arg0 == D_80800730_chtimetable) {
        return 0;
    }
    if (arg0 == D_80800744_chtimetable) {
        return 1;
    }
    var_v0 = &D_8080076C_chtimetable;
    var_v1 = 3;
    if (arg0 == D_80800758_chtimetable) {
        return 2;
    }
loop_7:
    if (arg0 == (((Objtimetable_func_808000B0_chtimetable_var_v0 *)var_v0)->unk0)) {
        return var_v1;
    }
    if (arg0 == (((Objtimetable_func_808000B0_chtimetable_var_v0 *)var_v0)->unk14)) {
        return var_v1 + 1;
    }
    if (arg0 == (((Objtimetable_func_808000B0_chtimetable_var_v0 *)var_v0)->unk28)) {
        return var_v1 + 2;
    }
    if (arg0 == (((Objtimetable_func_808000B0_chtimetable_var_v0 *)var_v0)->unk3C)) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x14;
    if (var_v1 == 0xB) {
        return -1;
    }
    goto loop_7;
}

s32 func_8080016C_chtimetable(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    extern s32 D_80800730_chtimetable;
    struct TimetableEntry {
        s32 unk0;
        s32 flag;
        s32 unk8;
        s32 unkC;
        s32 prerequisite;
    };
    s32 index;

    if (func_800DA298(0x86) == 0) {
        return 0;
    }
    if (arg2 == 0x12A && func_800DA298(0x171) == 0) {
        return 0;
    }
    index = func_808000B0_chtimetable(arg2);
    if (((struct TimetableEntry *)&D_80800730_chtimetable)[index].prerequisite != -1) {
        if (func_800DA298(((struct TimetableEntry *)&D_80800730_chtimetable)[index].prerequisite) == 0) {
            return 0;
        }
    }
    if (func_800DA298(((struct TimetableEntry *)&D_80800730_chtimetable)[index].flag) != 0) {
        return 0;
    }
    return 1;
}

void func_8080025C_chtimetable(BtIntPtr arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_0(void);
    void _glcutDll_entrypoint_10(u32);
    void _glcutDll_entrypoint_16(void);
    void _glcutDll_entrypoint_22(u32);
    void _glcutDll_entrypoint_7(u32);
    void func_800DA544(GameFlag);
    s32 func_808000B0_chtimetable(s32);
    extern s32 D_8080073C_chtimetable;
    func_800DA544(*(s32 *)((s8 *)&D_8080073C_chtimetable + func_808000B0_chtimetable(arg2) * 0x14));
    func_800DA544(0x6B7);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(arg1);
    _glcutDll_entrypoint_10(arg2);
    _glcutDll_entrypoint_22(0x72);
    _glcutDll_entrypoint_16();
}

#ifdef BT_NATIVE
s32 func_808002D4_chtimetable(s32 bt_a0) {
#else
s32 func_808002D4_chtimetable() {
#endif
    s32 func_808000B0_chtimetable();
    extern s32 D_80800738_chtimetable;
#ifdef BT_NATIVE
    return *((s32 *)((s8 *)&D_80800738_chtimetable + (((s32 (*)())func_808000B0_chtimetable)() * 20)));
#else
    return *((s32 *)((s8 *)&D_80800738_chtimetable + (func_808000B0_chtimetable() * 20)));
#endif
}    typedef struct { s32 unk0; } Objtimetable_func_80800308_chtimetable_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

s32 func_80800308_chtimetable(void)
{
  s32 func_800DA298(s32);
  extern s32 D_80800730_chtimetable;
  s8 *new_var;
  extern s32 D_8080080C_chtimetable;
  s8 *var_s0;
  new_var = (s8 *) (&D_80800730_chtimetable);
 do { var_s0 = new_var; loop_1: if (func_800DA298(*((s32 *) (var_s0 + 4))) != 0) { return *&((Objtimetable_func_80800308_chtimetable_var_s0 *)var_s0)->unk0; } } while (0); var_s0 += 0x14;
  if (var_s0 == ((s8 *) (&D_8080080C_chtimetable)))
  {
    return -1;
  }
  goto loop_1;
}

/* extern */

s32 func_80800364_chtimetable(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_80800308_chtimetable();
    s32 sp24;
    s32 map;
    arg2 |= 6;
    if (arg1 == 0) {
        if (func_800DA298(0x95) != 0) {
            sp24 = func_80800308_chtimetable();
            map = func_800EA05C();
            if (sp24 == map) {
                arg1 = 0xCF4;
            } else {
                arg1 = func_808002D4_chtimetable(sp24);
            }
        } else {
            arg1 = 0xCF3;
        }
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x42);
    arg0->unk74_30 = 1;
    return 1;
}

/* extern */

void func_80800404_chtimetable(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_5(f32 *, u32, u32, u32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    int func_800EFED0(f32 *, f32 *, f32 *);
    void func_8010D254(f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    if (!arg0->unk74_30) {
        func_8010D254(sp3C);
        func_800EFA4C(sp30, -500.0f, 0.0f, -700.0f);
        func_800EFA4C(sp24, 0.0f, 1500.0f, 700.0f);
        func_800EF04C(sp30, (f32 *)&arg0->actorData[4]);
        func_800EF04C(sp24, (f32 *)&arg0->actorData[4]);
        if (func_800EFED0(sp30, sp24, sp3C) != 0) {
            if (!arg0->unk64_20) {
                func_80800364_chtimetable(arg0, 0xD07, 1);
                arg0->unk64_20 = 1;
            }
        } else {
            arg0->unk64_20 = 0;
        }
        func_800EFA4C(sp30, 0.0f, 0.0f, -700.0f);
        func_800EFA4C(sp24, 500.0f, 1500.0f, 700.0f);
        func_800EF04C(sp30, (f32 *)arg0->actorData);
        func_800EF04C(sp24, (f32 *)arg0->actorData);
        if (func_800EFED0(sp30, sp24, sp3C) != 0) {
            if (!arg0->unk64_19) {
                func_80800364_chtimetable(arg0, 0xD07, 1);
                arg0->unk64_19 = 1;
            }
        } else {
            arg0->unk64_19 = 0;
        }
    }
    if ((arg0->unk70_10 == 1) && (_subaddiedialog_entrypoint_5(arg0->position, 0xFA, 0x3C, 0) != 0)) {
        func_80800364_chtimetable(arg0, 0, 9);
    }
}

s32 func_808005B8_chtimetable(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void func_800C0850(void);
    s32 func_800EA05C();
    extern s32 D_808007BC_chtimetable;
    s32 pad;
    s32 sp18;

    switch (arg1) {                                 /* switch 1; irregular */
    case 0x2E:                                      /* switch 1 */
        arg0->unk74_30 = 0;
        switch (((s16 *)&arg2)[0]) {                 /* switch 2 */
        case 0xD06:                                 /* switch 2 */
            if (((s16 *)&arg2)[1] == 1) {
                sp18 = func_80800308_chtimetable();
                func_8080025C_chtimetable((BtIntPtr) arg0, sp18, func_800EA05C());
            }
            break;
        case 0xCF5:                                 /* switch 2 */
        case 0xCF6:                                 /* switch 2 */
        case 0xCF7:                                 /* switch 2 */
        case 0xCF8:                                 /* switch 2 */
        case 0xCF9:                                 /* switch 2 */
        case 0xCFA:                                 /* switch 2 */
        case 0xCFB:                                 /* switch 2 */
            sp18 = func_80800308_chtimetable();
            if (func_8080016C_chtimetable((BtIntPtr) arg0, sp18, func_800EA05C()) != 0) {
                func_80800364_chtimetable(arg0, 0xD06, 0x48);
            } else {
            case 0xCF4:                             /* switch 2 */
                func_800C0850();
            }
            break;
        }
        break;
    case 0x52:                                      /* switch 1 */
        _gcdialogcamera_entrypoint_3(&D_808007BC_chtimetable, arg0->scale);
        return 1;
    default:                                        /* switch 1 */
        return 0;
    }
    return 1;
}

OSThread *chtimetable_entrypoint_0(void)
{
    extern u8 D_808007CC_chtimetable[];

    return (OSThread *) D_808007CC_chtimetable;
}
