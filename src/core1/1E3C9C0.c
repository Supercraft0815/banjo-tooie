#include "common.h"

void func_80024E90(s32 arg0) {
    void func_80026500(s32, void *, s32, s32);
    struct { s16 type; u8 data[14]; } sp18;

    sp18.type = 0x11;
    func_80026500(arg0 + 0x48, &sp18, 0, 0);
}
