#include "common.h"

void func_80800000_cadbio(s32 arg0) {
    s32 _cadbfunc_entrypoint_1(f32 *);
    s32 _cadbfunc_entrypoint_3(f32 *);
    s32 _cadbfunc_entrypoint_5(f32 *);
    s32 _cadbfunc_entrypoint_7(f32, f32);
    s32 _cadbfunc_entrypoint_9(f32, f32);
    s32 _cadbfunc_entrypoint_11(f32);
    s32 _cadbfunc_entrypoint_13(f32);
    s32 _cadbfunc_entrypoint_15(f32);
    s32 _cadbfunc_entrypoint_17(s16);
    s32 _cadbfunc_entrypoint_19(f32);
    s32 _cadbfunc_entrypoint_21(f32);
    s32 _cadbfunc_entrypoint_23(s32);
    s32 _cadbfunc_entrypoint_25(s32);
    s32 _cadbfunc_entrypoint_27(s32);
    s32 _cadbfunc_entrypoint_31(s32);
    s32 _cadbfunc_entrypoint_33(f32);
    void _cadbfunc_entrypoint_35(s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    s32 _gsmaker_entrypoint_19(s32, s32, f32 *);
    s32 _gsmaker_entrypoint_20(s32, s32, f32 *, s32);
    s32 _gsmaker_entrypoint_21(s32, s32, s32 *);
    s32 _gsmaker_entrypoint_24(s32, s32, s16 *);
    void func_800A58A8(s32, s32);
    f32 sp3C[3];
    f32 sp38;
    s16 sp36;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (_gsmaker_entrypoint_16(arg0, 0) == 0) {
        do {
            if (_gsmaker_entrypoint_21(arg0, 1, &sp28) == 0) {
                if (_gsmaker_entrypoint_21(arg0, 2, &sp2C) != 0) {
                    func_800A58A8(sp28, sp2C);
                } else if (_gsmaker_entrypoint_20(arg0, 3, sp3C, 3) != 0) {
                    if (_cadbfunc_entrypoint_1(sp3C) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 4, sp3C, 3) != 0) {
                    if (_cadbfunc_entrypoint_3(sp3C) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 5, sp3C, 3) != 0) {
                    if (_cadbfunc_entrypoint_5(sp3C) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 6, sp3C, 2) != 0) {
                    if (_cadbfunc_entrypoint_7(sp3C[0], sp3C[1]) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 7, sp3C, 2) != 0) {
                    if (_cadbfunc_entrypoint_9(sp3C[0], sp3C[1]) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 8, &sp38, 1) != 0) {
                    if (_cadbfunc_entrypoint_11(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 9, &sp38, 1) != 0) {
                    if (_cadbfunc_entrypoint_13(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 0x11, &sp38, 1) != 0) {
                    if (_cadbfunc_entrypoint_15(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_24(arg0, 0xA, &sp36) != 0) {
                    if (_cadbfunc_entrypoint_17(sp36) == 0) {
                    }
                } else if (_gsmaker_entrypoint_19(arg0, 0xB, &sp38) != 0) {
                    if (_cadbfunc_entrypoint_19(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_19(arg0, 0xC, &sp38) != 0) {
                    if (_cadbfunc_entrypoint_21(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_21(arg0, 0xD, &sp30) != 0) {
                    if (_cadbfunc_entrypoint_31(sp30) == 0) {
                    }
                } else if (_gsmaker_entrypoint_21(arg0, 0xE, &sp30) != 0) {
                    if (_cadbfunc_entrypoint_23(sp30) == 0) {
                    }
                } else if (_gsmaker_entrypoint_21(arg0, 0xF, &sp30) != 0) {
                    if (_cadbfunc_entrypoint_25(sp30) == 0) {
                    }
                } else if (_gsmaker_entrypoint_21(arg0, 0x10, &sp30) != 0) {
                    if (_cadbfunc_entrypoint_27(sp30) == 0) {
                    }
                } else if (_gsmaker_entrypoint_20(arg0, 0x12, &sp38, 1) != 0) {
                    if (_cadbfunc_entrypoint_33(sp38) == 0) {
                    }
                } else if (_gsmaker_entrypoint_21(arg0, 0x13, &sp30) != 0) {
                    _cadbfunc_entrypoint_35(sp30);
                }
            }
        } while (_gsmaker_entrypoint_16(arg0, 0) == 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbio/cadbio_entrypoint_0.s")
