#include "common.h"

Acmd *func_800295D0(s32 arg0, Acmd *arg1) {
    Acmd *func_8002C230(s32, Acmd *);
    extern s32 *D_800411F4;
    Acmd *cursor;
    Acmd *command;
    Acmd *save;

    cursor = arg1;
    cursor = func_8002C230(arg0, cursor);
    command = cursor++;
    command->words.w0 = 0x0D000000;
    save = cursor++;
    save->words.w0 = 0x062E0000;
    save->words.w1 = D_800411F4[18];
    return cursor;
}
