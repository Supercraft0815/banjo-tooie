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
    s32 func_800E7188(s32);
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
    s32 func_800E7188(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_808004C8_sccustom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_8080050C_sccustom.s")

/* extern */

void sccustom_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom(s32, s32, s32, s32, s32);
    s32 func_808004C8_sccustom(s32);
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_808004C8_sccustom(arg1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_808006C4_sccustom.s")

/* extern */

void sccustom_entrypoint_3(s32 arg0) {
    s32 func_808004C8_sccustom();
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_808004C8_sccustom());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_8080084C_sccustom.s")

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
