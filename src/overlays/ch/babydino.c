#include "common.h"

OSThread *chbabydino_entrypoint_0(void)
{
    extern u8 D_80800770_chbabydino[];

    return (OSThread *) D_80800770_chbabydino;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/babydino/func_8080000C_chbabydino.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/babydino/func_8080011C_chbabydino.s")

void func_8080028C_chbabydino(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/babydino/func_808002AC_chbabydino.s")

/* extern */

void func_808003BC_chbabydino(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_22();
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    s32 var_a1;

    if (arg0->unk64_19) {
        _capod_entrypoint_22();
        arg0->unk64_19 = 0;
    }
    if ((arg1 != 0x107E) && (arg1 != 0x1080)) {
        if (func_800DA298(0x588) != 0) {
            var_a1 = 5;
        } else {
            var_a1 = 2;
        }
        func_80102424(arg0, var_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/babydino/func_80800448_chbabydino.s")

/* extern */

s32 func_808005A0_chbabydino(s32 arg0, s32 arg1) {
    s32 func_800FFAB0(s32);
    s32 func_80105834();
    s32 func_80105A5C(s32);
    func_80105834();
    if (func_80105A5C(arg0) != 0) {
        if (arg1 != 0) {
            func_800FFAB0(arg0);
        }
        return 0;
    }
    return 1;
}

s32 func_808005F0_chbabydino(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800EA05C();
    void func_80102424(Actor *, s32);

    switch (func_800EA05C()) {
        case 0xEA:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(arg0, 3);
                _subaddieDll_entrypoint_4(arg0, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1080, 0xC, NULL, 0x39);
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x2821);
                return 1;
            }
            break;
        case 0xEC:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(arg0, 4);
                _subaddieDll_entrypoint_4(arg0, 1);
                _capod_entrypoint_13(arg0->unk0, NULL, 7, 0x2821);
                return 1;
            }
            break;
    }
    return 0;
}
