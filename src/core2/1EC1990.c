#include "common.h"

void func_800E80A0(void) {
    extern s32 D_8012D5F0;
    extern s32 D_8012D5F4;
    if (D_8012D5F4 == NULL) {
        D_8012D5F0 = (s32)heap_alloc(0xA040);
        D_8012D5F4 = D_8012D5F0;
        while ((s32)D_8012D5F0 & 0x3F) D_8012D5F0 += 2;
    }
}

void func_800E8104(void) {
    s32 func_800A9800();
    s32 heap_free(s32);
    extern s32 D_8012D5F4;
    if (D_8012D5F4 != 0) {
        heap_free(D_8012D5F4);
        D_8012D5F4 = 0;
    }
    func_800A9800();
}

void func_800E8144(void) {
    void func_800A9828(s32 arg0, s32 arg1, s32 arg2);
    extern s32 D_8012D5F0;
    extern s32 D_8012D5F4;
    if (D_8012D5F4 != 0) {
        func_800A9828(D_8012D5F0, 0xA0, 0x80);
    }
}

void func_800E817C(BtIntPtr arg0) {
    void func_800A8B24(BtIntPtr arg0, s32 arg1);
    s32 func_800A9800();
    void func_800E7C28(Gfx** gfx);
    void func_800E7CF4(Gfx** gfx);
    void func_800E7D4C(Gfx** gfx);
    extern s32 D_8012D5F4;
    if (D_8012D5F4 != 0) {
        func_800A9800();
        func_800E7C28(arg0);
        func_800E7CF4(arg0);
        func_800E7D4C(arg0);
        func_800A8B24(arg0, 0);
    }
}

s32 func_800E81D0(void) {
    extern s32 D_8012D5F0;

    return D_8012D5F0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012D5F0 BT_DATA(4, bss_core2bss2_1, 0xCB0);
s32 D_8012D5F4 BT_DATA(4, bss_core2bss2_1, 0xCB4);
#endif
