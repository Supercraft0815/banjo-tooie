#include "common.h"

void func_80800000_chtimetable(s32 arg0, s32 arg1, f32 *arg2) {
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
    func_80800000_chtimetable((s32) arg0, 0, (f32 *)((s8 *)arg0 + 0x28));
    func_80800000_chtimetable((s32) arg0, 1, (f32 *)((s8 *)arg0 + 0x18));
}

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
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0)))) {
        return var_v1;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0x14)))) {
        return var_v1 + 1;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0x28)))) {
        return var_v1 + 2;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0x3C)))) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x14;
    if (var_v1 == 0xB) {
        return -1;
    }
    goto loop_7;
}

s32 func_8080016C_chtimetable(s32 arg0, s32 arg1, s32 arg2) {
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

void func_8080025C_chtimetable(s32 arg0, s32 arg1, s32 arg2) {
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

s32 func_808002D4_chtimetable() {
    s32 func_808000B0_chtimetable();
    extern s32 D_80800738_chtimetable;
    return *((s32 *)((s8 *)&D_80800738_chtimetable + (func_808000B0_chtimetable() * 20)));
}

s32 func_80800308_chtimetable(void)
{
  s32 func_800DA298(s32);
  extern s32 D_80800730_chtimetable;
  s8 *new_var;
  extern s32 D_8080080C_chtimetable;
  s8 *var_s0;
  new_var = (s8 *) (&D_80800730_chtimetable);
 do { var_s0 = new_var; loop_1: if (func_800DA298(*((s32 *) (var_s0 + 4))) != 0) { return *((s32 *) (((s8 *) var_s0) + 0)); } } while (0); var_s0 += 0x14;
  if (var_s0 == ((s8 *) (&D_8080080C_chtimetable)))
  {
    return -1;
  }
  goto loop_1;
}

/* extern */

s32 func_80800364_chtimetable(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800404_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_808005B8_chtimetable.s")

OSThread *chtimetable_entrypoint_0(void)
{
    extern u8 D_808007CC_chtimetable[];

    return (OSThread *) D_808007CC_chtimetable;
}
