#include "common.h"

void func_80026100(void *arg0) {
    s32 sp4;

    (*(s32 *)((s8 *)(arg0) + (0x30))) = -1;
    sp4 = 0;
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x36))) > 0) {
        do {
            (*(u8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x60))) + (sp4 * 0x38))) + (0xA))) = 0xFF;
            (*(u8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x60))) + (sp4 * 0x38))) + (9))) = 0xFF;
        } while (++sp4 < (s32) (*(u8 *)((s8 *)(arg0) + (0x36))));
    }
}

/* extern */

void func_80026188(s32 arg0, s32 arg1) {
    void func_8002ACE0(s32, s32, s32, s32, s32, s32);
    func_8002ACE0(arg0, 0, 0xB0, arg1, 0xFC, 0);
}

/* extern */

void func_800261D0(volatile s32 *arg0, volatile s32 arg1) {
    void func_8002ACE0(s32, s32, s32, s32, s32, s32);
    (*(s32 *)((s8 *)(arg0) + (0x30))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x30))) | (1 << arg1));
    func_8002ACE0(arg0, 0, 0xB0, arg1, 0xFC, 0xFF);
}

/* extern */

void func_80026238(s32 arg0, s32 arg1, volatile u8 arg2, volatile s32 arg3) {
    void func_8002ACE0(s32, s32, s32, s32, s32, s32);
    func_8002ACE0(arg0, 0, 0xB0, arg1, 0xFF, arg2);
}

void func_8002628C(s32 arg0, s32 arg1, u8 arg2) {
    void func_8002ACE0(s32, s32, s32, s32, s32, s32);
    func_8002ACE0(arg0, 0, 0xB0, arg1, 0x41, arg2);
}

/* extern */

void func_800262DC(s32 arg0, s32 arg1, u8 arg2) {
    void func_8002ACE0(s32, s32, s32, s32, s32, s32);
    func_8002ACE0(arg0, 0, 0xB0, arg1, 0xFC, arg2);
}
