#include "common.h"

void func_80026330(u8 *arg0, s32 arg1) {
    struct { s16 type; u8 pad[6]; u8 first, second, unused, high, middle, low; } evt;
    void func_80026500(void *, void *, s32, s32);
    evt.type = 7;
    evt.first = 0xFF;
    evt.second = 0x51;
    evt.high = (arg1 & 0xFF0000) >> 16;
    evt.middle = (arg1 & 0xFF00) >> 8;
    evt.low = arg1 & 0xFF;
    func_80026500(arg0 + 0x48, &evt, 0, 0);
}
