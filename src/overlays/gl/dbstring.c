#include "common.h"

/* extern */

BtIntPtr gldbstring_entrypoint_0(BtIntPtr arg0, s32 arg1) {
    BtIntPtr func_800D674C(s32);
    void func_800D70D0(s32 arg0);
    void func_800D71F4(s32 arg0);
    arg0 = func_800D674C(arg1);
    func_800D70D0(1);
    func_800D71F4(1);
    return arg0 + 1;
}

/* extern */

u32 *gldbstring_entrypoint_1(u32 *arg0, s16 arg1) {
    s32 _gldialog_entrypoint_0(void);
    u8 *table;
    u8 *text;
    s32 offset;
    s32 language;
    s32 i;
    s32 count;
    s32 id;
    s32 length;

    arg1 = arg1;
    language = _gldialog_entrypoint_0();
    table = (u8 *)arg0 + language * 2;
    offset = table[0];
    offset += table[1] << 8;
    text = (u8 *)arg0 + offset;
    count = text[-1];
    for (i = 0; i < count; i++) {
        id = text[0];
        length = text[1];
        text += 2;
        if (arg1 + 0x80 == id) {
            return (u32 *)text;
        }
        text += length;
    }
    return NULL;
}

void gldbstring_entrypoint_2(s32 arg0) {
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D721C(s32, s32);
    func_800D721C(arg0, 0);
    func_800D70F8(arg0, 0);
    func_800D6CEC(arg0);
}
