#include "common.h"

void func_80025F70(s32 arg0, u8 arg1, u8 arg2) {
    struct Event {
        s16 type;
        union {
            struct {
                s32 value;
                u8 status;
                u8 channel;
                u8 control;
                u8 data;
            } midi;
            s32 raw[3];
        } message;
    } event;
    void func_80026500(void *, void *, s32, s32);

    event.type = 2;
    event.message.midi.value = 0;
    event.message.midi.status = 0xB0;
    event.message.midi.channel = arg1;
    event.message.midi.control = 0x5B;
    event.message.midi.data = arg2;
    func_80026500((u8 *)arg0 + 0x48, &event, 0, 0);
}

/* extern */

void func_80025FE0(void *arg0, f32 arg1, f32 arg2) {
    void func_80026500(void *, void *, s32, s32);
    struct {
        s16 type;
        f32 value1;
        f32 value2;
        f32 unused;
    } event;

    event.type = 0x18;
    event.value1 = arg1;
    event.value2 = arg2;
    func_80026500((u8 *)arg0 + 0x48, &event, 0, 0);
}

/* extern */

s32 func_8002603C(u8 * arg0, u8 arg1, u8 arg2) {
    void func_80026500(void *, void *, s32, s32);
    struct {
        s16 type;
        s32 value;
        u8 status;
        u8 key;
        u8 velocity;
        u8 channel;
        s32 extra;
    } event;

    event.type = 2;
    event.value = 0;
    event.status = 0xB0;
    event.key = arg1;
    event.velocity = 0x5C;
    event.channel = arg2;
    func_80026500(arg0 + 0x48, &event, 0, 0);
}
