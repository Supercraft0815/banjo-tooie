#include "common.h"

u8 *func_80800000_fxfontstring(u8 *arg0) {
    if (*arg0 != 0) {
        do {
            arg0++;
        } while (*arg0 != 0);
    }
    return arg0;
}

/* extern */

void fxfontstring_entrypoint_0(u8 *arg0, s32 arg1) { u8 *p; p = func_80800000_fxfontstring(arg0); *p++ = 0xFD; if (arg1 != 0) { *p = 0x68; } else { *p = 0x6C; } p++; *p = 0; }

/* extern */

void fxfontstring_entrypoint_1(u8 *arg0, s32 arg1) {
    u8 *p;
    s32 value;

    p = func_80800000_fxfontstring(arg0);
    *p++ = 0xFD;
    *p++ = 0x61;
    if (arg1 <= 0) {
        *p = 1;
    } else {
        value = arg1 >= 0x100 ? 0xFF : arg1;
        *p = value;
    }
    p++;
    *p = 0;
}

/* extern */

void fxfontstring_entrypoint_2(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;
    s32 value;

    p = func_80800000_fxfontstring(arg0);
    *p++ = 0xFD;
    *p++ = 0x63;
    if (arg1 <= 0) {
        *p = 1;
    } else {
        value = arg1 >= 0x100 ? 0xFF : arg1;
        *p = value;
    }
    p++;
    if (arg2 <= 0) {
        *p = 1;
    } else {
        value = arg2 >= 0x100 ? 0xFF : arg2;
        *p = value;
    }
    p++;
    if (arg3 <= 0) {
        *p = 1;
    } else {
        value = arg3 >= 0x100 ? 0xFF : arg3;
        *p = value;
    }
    p++;
    *p++ = 0;
}

/* extern */

void fxfontstring_entrypoint_3(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    p = func_80800000_fxfontstring(arg0);
    p[0] = 0xFD;
    p[1] = 0x69;
    p[2] = arg1 & 0xFF;
    p[3] = (arg1 >> 8) & 0xFF;
    p[4] = arg2 + 1;
    p[5] = 0;
}
