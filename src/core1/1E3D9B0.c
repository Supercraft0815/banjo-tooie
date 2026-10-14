#include "common.h"

void func_80025E80(u8 *arg0, void *arg1) {
    struct { s16 type; void *state; s32 pad[2]; } evt;
    void func_80026500(void *, void *, s32, s32);
    evt.type = 0xD;
    evt.state = arg1;
    func_80026500(arg0 + 0x48, &evt, 0, 0);
}

void func_80025ED0(u8 *arg0, s16 arg1) {
    void func_80026500(void *, void *, s32, s32);
    struct { s16 type; s16 pad; s16 value; s16 rest[5]; } evt;
    evt.type = 0xA;
    evt.value = arg1;
    func_80026500(arg0 + 0x48, &evt, 0, 0);
}

void func_80025F20(u8 *arg0) {
    void func_80026500(void *, void *, s32, s32);
    struct { s16 type; s16 padding[7]; } evt;
    evt.type = 0xF;
    func_80026500(arg0 + 0x48, &evt, 0, 0);
}
