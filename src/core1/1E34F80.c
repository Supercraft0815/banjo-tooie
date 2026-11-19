#include "common.h"
#include "core1/core1_runtime_data.h"
u16 func_8001D450(u16 arg0) {
    u16 r = ((arg0 & 0xF800) / 2) & 0xF800;
    u16 g = ((arg0 & 0x7C0) / 2) & 0x7C0;
    u16 b = ((arg0 & 0x3E) / 2) & 0x3E;
    return r | g | b | 1;
}

u8 func_8001D4C4(u8 arg0, u8 arg1, f32 arg2) {
    f32 start = arg0;
    return ((f32)arg1 - start) * arg2 + start;
}

void func_8001D5C4(u16 *arg0, u8 *arg1) {
    u16 r = (*arg0 >> 8) & 0xF8;
    u16 g = (*arg0 >> 3) & 0xF8;
    u16 b = (*arg0 << 2) & 0xF8;
    f32 blend;

    if (arg1[3] != 0) {
        blend = (u32)arg1[3] * 0.00390625f;
        r = func_8001D4C4(r, arg1[0], blend) & 0xF8;
        g = func_8001D4C4(g, arg1[1], blend) & 0xF8;
        b = func_8001D4C4(b, arg1[2], blend) & 0xF8;
    }
    *arg0 = (r << 8) | (g << 3) | (b >> 2) | 1;
}

void func_8001D6C0(u16 *arg0, int arg1, int arg2, u8 arg3) {
    u16 func_8001D450(u16);
    BT_IDO_ONLY(extern u16 D_8003F778[];)
    int sp40;
    int var_s0;
    int var_s6;
    int var_s7;

    arg2++;
    arg1 += 2;
    arg0 += ((arg2 * 0x850) + (arg1 * 5) + 0x260);
    sp40 = ((arg3 * 5) - 0xA0) << 1;
    for (var_s6 = 0, var_s7 = 0; var_s6 != 0x850; var_s6 += 0x130, var_s7 += 0x1DC) {
        osInvalDCache((var_s6 + arg0), 5);
        for (var_s0 = 0; var_s0 != 0xA; var_s0 += 2) {
            u16 temp_v0;
            temp_v0 = *(u16 *)((u8 *)(D_8003F778 + var_s7) + sp40 + var_s0); if (temp_v0 != 0x11) { *(u16 *)((u8 *)(var_s6 + arg0) + var_s0) = temp_v0; } else { *(u16 *)((u8 *)(var_s6 + arg0) + var_s0) = func_8001D450(*(u16 *)((u8 *)(var_s6 + arg0) + var_s0)); }
        }
        osWritebackDCache((var_s6 + arg0), 5);
    }
}    typedef struct { u8 pad0[0x690]; s32 unk690; s32 unk694; s32 unk698; s32 unk69C; s32 unk6A0; } Obj1E34F80_D_8007D170; /* offsets.py genstruct: fields from raw offsets on &D_8007D170; rename once understood */

void func_8001D800(u8 arg0) { void bzero(void *, int); extern s32 D_8007D170; s32 row; u8 (*new_var)[56]; loop: switch (arg0) { case 9: ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690 = ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690) + 7) & (~7); if ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690) >= 0x38) { arg0 = 10; goto loop; } break; case 10: ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690 = 0; (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694)++; if ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694) >= 30) { ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694 -= 30; ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk698 = 1; } if (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk698) { row = ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694; if (row) { } new_var = (u8 (*)[56]) (&D_8007D170); (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk69C)--; if ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk69C) < 0) { ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk69C += 30; } bzero(new_var[row], 56); } break; case 12: bzero(&D_8007D170, 0x690); case 13: ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690 = 0; ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694 = 0; ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk69C = 0; ((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk698 = 0; break; default: if ((arg0 >= 0x20) && (arg0 < 0x7F)) { ((u8 (*)[56]) (&D_8007D170))[((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk694][((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690] = arg0; (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690)++; if ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk690) >= (((0xFFFF & ((((56 & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF)) & 0xFFFF) & 0xFFFF)) { arg0 = 10; goto loop; } } break; }
}

void func_8001D96C()
{
    func_8001D800(0xC);
}

void func_8001D98C(u16 arg0) {
    extern s32 D_8007D800;

    if (arg0 < 0x38) {
        D_8007D800 = arg0;
    }
}

void func_8001D9AC(u16 arg0) {
    extern s32 D_8007D804;

    if (arg0 < 0x1E) {
        D_8007D804 = arg0;
    }
}

void func_8001D9CC(u16 arg0, u16 arg1) {
    func_8001D98C(arg0);
    func_8001D9AC(arg1);
}

void func_8001DA00(u8 *arg0, s32 arg1) {
    extern s32 D_8007D810;
    D_8007D810 = 0;
    while (arg1--) {
        func_8001D800(*arg0++);
    }
}

void func_8001DA58(void) {
}

void func_8001DA60(u16 *arg0) { u32 func_80014EC8(); BtIntPtr func_80014ED4(void); extern s32 D_8007D170; extern s32 D_8007D80C; extern s32 D_8007D810; s32 row; s32 column; s32 leading; s32 line; u16 *buffer; u8 *text; u8 *character; s32 value;  buffer = arg0; if (D_8007D810 == 0) { if (arg0 == NULL) { buffer = func_80014ED4(); } osInvalDCache(buffer, func_80014EC8()); text = (u8 *)&D_8007D170; line = 0; do { leading = 1; row = (line + D_8007D80C) % 30; column = 0; character = text; do { value = *character; if (leading != 0) { if (value != 0 && value != 0x20) { leading = 0; goto draw; } } else { draw: if (value != 0) { func_8001D6C0(buffer, column, row, value); } } column++; character++; } while (column != 0x38); line++; text += 0x38; } while (line != 30); osWritebackDCache(buffer, func_80014EC8()); } }

/* extern */

void func_8001DB90(u16 *arg0, int arg1, u32 arg2, u8 *arg3) {
    void func_8001D5C4(u16 *, u8 *);
    int var_s0;
    int var_s4;
    u16 *temp_s1;

    arg1 += 2;
    arg2++;
    arg0 += (arg2 * 0x850) + (arg1 * 5) + 0x260;
    for (var_s4 = 0; var_s4 != 0x850; var_s4 += 0x130) {
        temp_s1 = arg0 + var_s4;
        osInvalDCache(temp_s1, 5);
        for (var_s0 = 0; var_s0 != 5; var_s0++) {
            func_8001D5C4(temp_s1 + var_s0, arg3);
            osWritebackDCache(temp_s1, 5);
        }
    }
}

void func_8001DC6C(void) {
    extern s32 D_8007D170;
    if ((((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk6A0) != 0) {
        (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk6A0) = 0;
        return;
    }
    (((Obj1E34F80_D_8007D170 *)&D_8007D170)->unk6A0) = 1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8007D170 BT_DATA(4, bss_core1bss1_2, 0xA70);
s32 D_8007D800 BT_DATA(4, bss_core1bss1_2, 0x1100);
s32 D_8007D804 BT_DATA(4, bss_core1bss1_2, 0x1104);
s32 D_8007D80C BT_DATA(4, bss_core1bss1_2, 0x110C);
s32 D_8007D810 BT_DATA(4, bss_core1bss1_2, 0x1110);
#endif
