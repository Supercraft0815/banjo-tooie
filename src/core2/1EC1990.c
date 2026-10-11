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
    s32 func_800A9828(s32, s32, s32);
    extern s32 D_8012D5F0;
    extern s32 D_8012D5F4;
    if (D_8012D5F4 != 0) {
        func_800A9828(D_8012D5F0, 0xA0, 0x80);
    }
}

void func_800E817C(s32 arg0) {
    s32 func_800A8B24(s32, s32);
    s32 func_800A9800();
    s32 func_800E7C28(s32);
    s32 func_800E7CF4(s32);
    s32 func_800E7D4C(s32);
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
