#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_camera_db.h"

void func_80800000_cadbio(GsFile *file) {
    s32 id=-1,type,value,count;
    s16 half;
    f32 values[3];
    u8 tag;
    int selected=0;
    if(!file) return;
    while(!file->failed) {
        if(file->last_expected>=0) {tag=file->last_expected;file->last_expected=-1;}
        else gsmaker_entrypoint_7(file,&tag);
        if(file->failed) return;
        if(!tag) {if(id>=0 && !selected)file->failed=1;return;}
        if(tag==1) {
            gsmaker_entrypoint_11(file,&id);
            if(file->failed) return;
            if(id<0 || id>=func_800A58F0()) {file->failed=1;return;}
            selected=0;
        } else if(tag==2) {
            gsmaker_entrypoint_11(file,&type);
            if(file->failed) return;
            if(id<0 || !cadbmgrDll_entrypoint_2(D_80119540,type,id)) {file->failed=1;return;}
            selected=1;
        } else {
            if(!selected) {file->failed=1;return;}
            if((tag>=3 && tag<=9) || tag==11 || tag==12 || tag==17 || tag==18) {
                count=tag<=5 ? 3 : tag<=7 ? 2 : 1;
                gsmaker_entrypoint_10(file,values,count);if(file->failed)return;
                switch(tag) {
                case 3:_cadbfunc_entrypoint_1(values);break;
                case 4:_cadbfunc_entrypoint_3(values);break;
                case 5:_cadbfunc_entrypoint_5(values);break;
                case 6:_cadbfunc_entrypoint_7(values[0],values[1]);break;
                case 7:_cadbfunc_entrypoint_9(values[0],values[1]);break;
                case 8:_cadbfunc_entrypoint_11(values[0]);break;
                case 9:_cadbfunc_entrypoint_13(values[0]);break;
                case 11:_cadbfunc_entrypoint_19(values[0]);break;
                case 12:_cadbfunc_entrypoint_21(values[0]);break;
                case 17:_cadbfunc_entrypoint_15(values[0]);break;
                case 18:_cadbfunc_entrypoint_33(values[0]);break;
                }
            } else if(tag==10) {
                gsmaker_entrypoint_14(file,&half);if(file->failed)return;
                _cadbfunc_entrypoint_17(half);
            } else if((tag>=13 && tag<=16) || tag==19) {
                gsmaker_entrypoint_11(file,&value);if(file->failed)return;
                switch(tag) {
                case 13:_cadbfunc_entrypoint_31(value);break;
                case 14:_cadbfunc_entrypoint_23(value);break;
                case 15:_cadbfunc_entrypoint_25(value);break;
                case 16:_cadbfunc_entrypoint_27(value);break;
                case 19:_cadbfunc_entrypoint_35(value);break;
                }
            } else {file->failed=1;return;}
        }
    }
}

void cadbio_entrypoint_0(GsFile *file) {
    s32 maximum=0x7D;
    if(!file || file->failed) return;
    func_800A5630();
    _gsmaker_entrypoint_21(file,0x14,&maximum);
    if(file->failed) return;
    func_800A5608(maximum);
    if(!D_80119540) {file->failed=1;return;}
    while(!file->failed && !_gsmaker_entrypoint_16(file,0)) func_80800000_cadbio(file);
    if(file->failed) func_800A5630();
}
#else
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

/* extern */

void cadbio_entrypoint_0(s32 arg0) {
    s32 _gsmaker_entrypoint_16(s32, s32);
    s32 _gsmaker_entrypoint_21(s32, s32, s32 *);
    void func_800A5608(s32);
    void func_800A5630();
    s32 sp24;

    func_800A5630();
    if (_gsmaker_entrypoint_21(arg0, 0x14, &sp24) == 0) {
        sp24 = 0x7D;
    }
    func_800A5608(sp24);
    if (_gsmaker_entrypoint_16(arg0, 0) == 0) {
        do {
            func_80800000_cadbio(arg0);
        } while (_gsmaker_entrypoint_16(arg0, 0) == 0);
    }
}

#endif
