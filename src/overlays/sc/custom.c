#include "common.h"

s32 func_80800000_sccustom(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _scinfobar_entrypoint_11(s32);
    f32 _scinfobar_entrypoint_18(s32);
    s32 _scinfobar_entrypoint_15(s32);
    s32 _scinfobar_entrypoint_17(s32);
    s32 func_800B8C50(void);
    void func_800B8CBC(u8, u8, u8);
    void func_800B8C8C(s32);
    void func_800B7F14(s32);
    void func_800B811C(s32);
    void func_800B8DEC(s32, s32, s32, u8);
    s32 func_800E7188(u8 *);
    s32 distance;
    f32 scale;
    s32 direction;
    s32 pulse;
    s32 alpha;
    s32 last;
    s32 i;
    f32 limit;
    f32 progress;
    f32 spacing;
    f32 offset;
    u8 character;
    u8 color;

    distance = _scinfobar_entrypoint_11(arg1);
    scale = _scinfobar_entrypoint_18(arg1);
    direction = _scinfobar_entrypoint_15(arg1);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(arg1)) {
        case 0:
            break;
        case 1:
            func_800B8CBC(128, 128, 128);
            break;
        case 2:
            pulse = (func_8001211C() << 5) & 511;
            if (pulse >= 256) {
                pulse = 512 - pulse;
            }
            pulse = (s32)(pulse * 0.5f);
            color = pulse + 127;
            func_800B8CBC(color, color, color);
            break;
    }
    progress = (f32)distance;
    limit = 24.0f * scale + 4.0f;
    if (progress < limit) {
        alpha = (s32)((1.0f - ((limit - progress) / limit)) * 255.0f);
    } else {
        alpha = 255;
    }
    last = func_800E7188(arg4) - 1;
    func_800B8C8C(alpha);
    func_800B7F14(arg0);
    i = last;
    if (i >= 0) {
      spacing = 8.0f;
      do {
        offset = (f32)i;
        offset = spacing * offset;
        offset = limit + offset;
        if (progress < offset) {
            offset = progress;
        }
        if (direction == 2) {
            offset = -offset;
            character = *(u8 *)((last - i) + arg4);
        } else {
            character = *(u8 *)(arg4 + i);
        }
        func_800B8DEC(arg0, (s32)((f32)arg2 + offset), arg3, character);
        i--;
      } while (i >= 0);
    }
    func_800B811C(arg0);
}

s32 func_80800264_sccustom(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _scinfobar_entrypoint_11(s32);
    f32 _scinfobar_entrypoint_18(s32);
    s32 _scinfobar_entrypoint_15(s32);
    s32 _scinfobar_entrypoint_17(s32);
    s32 func_800B8C50(void);
    void func_800B8CBC(u8, u8, u8);
    void func_800B8C8C(s32);
    void func_800B7F14(s32);
    void func_800B811C(s32);
    void func_800B8DEC(s32, s32, s32, u8);
    s32 func_800E7188(u8 *);
    s32 distance;
    f32 scale;
    s32 direction;
    s32 pulse;
    s32 alpha;
    s32 last;
    s32 i;
    f32 limit;
    f32 progress;
    f32 spacing;
    f32 offset;
    u8 character;
    u8 color;

    distance = _scinfobar_entrypoint_11(arg1);
    scale = _scinfobar_entrypoint_18(arg1);
    direction = _scinfobar_entrypoint_15(arg1);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(arg1)) {
        case 0:
            break;
        case 1:
            func_800B8CBC(128, 128, 128);
            break;
        case 2:
            pulse = (func_8001211C() << 5) & 511;
            if (pulse >= 256) {
                pulse = 512 - pulse;
            }
            pulse = (s32)(pulse * 0.5f);
            color = pulse + 127;
            func_800B8CBC(color, color, color);
            break;
    }
    progress = (f32)distance;
    limit = 24.0f * scale + 4.0f;
    if (progress < limit) {
        alpha = (s32)((1.0f - ((limit - progress) / limit)) * 255.0f);
    } else {
        alpha = 255;
    }
    last = func_800E7188(arg4) - 1;
    func_800B8C8C(alpha);
    func_800B7F14(arg0);
    i = last;
    if (i >= 0) {
      spacing = 10.0f;
      do {
        offset = (f32)i;
        offset = spacing * offset;
        offset = limit + offset;
        if (progress < offset) {
            offset = progress;
        }
        if (direction == 2) {
            offset = -offset;
            character = *(u8 *)((last - i) + arg4);
        } else {
            character = *(u8 *)(arg4 + i);
        }
        func_800B8DEC(arg0, (s32)((f32)arg2 + offset), arg3, character);
        i--;
      } while (i >= 0);
    }
    func_800B811C(arg0);
}

s32 func_808004C8_sccustom(s32 arg0) {
    s32 _scinfobar_entrypoint_19(s32);
    s32 func_800E6DB4(s32 *, s32);
    s32 func_800E73D4(s32 *);
    extern s32 B_80800930_sccustom;
    func_800E73D4(&B_80800930_sccustom);
    func_800E6DB4(&B_80800930_sccustom, _scinfobar_entrypoint_19(arg0));
    return (s32) &B_80800930_sccustom;
}

s32 *func_8080050C_sccustom(s32 arg0, u8 arg1) {
    s32 _scinfobar_entrypoint_19(s32);
    s32 _scinfobar_entrypoint_20(s32);
    s32 func_800E6A58(s32 *, u8);
    s32 func_800E6DB4(s32 *, s32);
    s32 func_800E73D4(s32 *);
    extern s32 B_80800940_sccustom;
    func_800E73D4(&B_80800940_sccustom);
    func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_19(arg0));
    func_800E6A58(&B_80800940_sccustom, arg1);
    func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_20(arg0));
    return &B_80800940_sccustom;
}

/* extern */

void sccustom_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom(s32, s32, s32, s32, s32);
    s32 func_808004C8_sccustom(s32);
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_808004C8_sccustom(arg1));
}

void sccustom_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _scinfobar_entrypoint_19(s32);
    extern u8 *D_80800920_sccustom;
    if (_scinfobar_entrypoint_19(arg1) == 0x3E7) {
        func_80800264_sccustom(arg0, arg1, arg2, arg3, D_80800920_sccustom);
        return;
    }
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_808004C8_sccustom(arg1));
}

/* extern */

void sccustom_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _scinfobar_entrypoint_19(s32);
    s32 _scinfobar_entrypoint_20(s32);
    s32 _scinfobar_entrypoint_5(s32, s32);
    s32 sp2C;

    sp2C = _scinfobar_entrypoint_19(arg1);
    if (_scinfobar_entrypoint_20(arg1) == sp2C) {
        _scinfobar_entrypoint_5(arg1, 1);
    }
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_8080050C_sccustom(arg1, 0x2FU));
}

/* extern */

s32 func_808006C4_sccustom(s32 arg0, s32 arg1) {
    f32 _scinfobar_entrypoint_18(s32);
    s32 func_800E7188(u8 *);
    int sp1C;
    f32 temp_f0;
    int var_v1;

    sp1C = func_800E7188(arg1);
    temp_f0 = _scinfobar_entrypoint_18(arg0);
    var_v1 = sp1C;
    if (var_v1 < 3) {
        var_v1 = 3;
    }
    var_v1--;
    return (s32) ((24.0f * temp_f0) + 4.0f + (8.0f * (f32) var_v1));
}

/* extern */

void sccustom_entrypoint_3(s32 arg0) {
    s32 func_808004C8_sccustom();
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_808004C8_sccustom());
}

s32 sccustom_entrypoint_4(s32 arg0) {
    f32 _scinfobar_entrypoint_18(s32);
    s32 _scinfobar_entrypoint_19(s32);
    s32 func_800E7188(u8 *);
    s32 func_808006C4_sccustom(s32, s32);
    extern u8 *D_80800920_sccustom;
    int sp1C;
    f32 temp_f0;
    int var_v1;

    if (_scinfobar_entrypoint_19(arg0) == 0x3E7) {
        sp1C = func_800E7188(D_80800920_sccustom);
        temp_f0 = _scinfobar_entrypoint_18(arg0);
        var_v1 = sp1C;
        if (var_v1 < 3) {
            var_v1 = 3;
        }
        var_v1--;
        return (s32) ((24.0f * temp_f0) + 4.0f + (10.0f * (f32) var_v1));
    }
    return func_808006C4_sccustom(arg0, func_808004C8_sccustom(arg0));
}

void sccustom_entrypoint_5(s32 arg0) {
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_8080050C_sccustom(arg0, 0x2FU));
}

s32 func_8080084C_sccustom(s32 arg0) {
    s32 _scinfobar_entrypoint_19(s32);
    s32 func_800DB8BC(s32 *, s32);
    s32 func_800E73D4(s32 *);
    extern s32 B_80800950_sccustom;
    func_800E73D4(&B_80800950_sccustom);
    func_800DB8BC(&B_80800950_sccustom, _scinfobar_entrypoint_19(arg0));
    return (s32) &B_80800950_sccustom;
}

/* extern */

void sccustom_entrypoint_6(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom(s32, s32, s32, s32, s32);
    s32 func_8080084C_sccustom(s32);
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_8080084C_sccustom(arg1));
}

/* extern */

void sccustom_entrypoint_7(s32 arg0) {
    s32 func_8080084C_sccustom();
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_8080084C_sccustom());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/R_80800910_sccustom.s")
