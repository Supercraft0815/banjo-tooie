#include "common.h"

void func_8001E2A0()
{
    func_8001DA60(func_80014F00());
}

void func_8001E2C8(void) {
    extern s32 D_8007E950;
    s32 func_8001D37C();
    s32 func_8001D96C();
    extern s32 D_80041840;
    func_8001D96C();
    func_8001D37C(&D_80041840, D_8007E950);
    func_8001E2A0();
}

void func_8001E304(void) {
    s32 _gzreg_entrypoint_1();
    s32 func_8001D37C();
    s32 func_8001D96C();
    s32 func_8001D9CC(s32, s32);
    extern s32 D_80041868;
    func_8001D96C();
    func_8001D37C(&D_80041868);
    func_8001D9CC(0, 0xA);
    _gzreg_entrypoint_1();
    func_8001E2A0();
}

void func_8001E34C(void) {
    s32 func_8001D37C();
    s32 func_8001D96C();
    extern s32 D_8004187C;
    func_8001D96C();
    func_8001D37C(&D_8004187C);
    func_8001E2A0();
}

void func_8001E380()
{
    func_8001E2A0();
}

void func_8001E3A0(void) {
    extern s32 D_8007E948;
    s32 func_8001211C(void);
    s32 func_8001D37C(s32 *, s32, s32);
    extern s32 D_800418A8;
    func_8001D37C(&D_800418A8, func_8001211C(), D_8007E948);
    func_8001E2A0();
}

void func_8001E3E0(void) {
    s32 func_8001211C(void);
    s32 func_8001D37C();
    extern s32 D_800418D4;
    func_8001D37C(&D_800418D4, func_8001211C());
    func_8001E2A0();
}

void func_8001E418(void) {
    s32 func_8001D37C();
    s32 func_8001D96C();
    extern s32 D_800418EC;
    func_8001D96C();
    func_8001D37C(&D_800418EC);
    func_8001E2A0();
}

void func_8001E44C(void) {
    s32 func_8001D3D8(s32, s32, s32 *, s32);
    s32 func_8001D96C();
    extern s32 D_800418FC;
    extern s32 D_8007E950;
    func_8001D96C();
    func_8001D3D8(0x11, 0x18, &D_800418FC, D_8007E950);
    func_8001E2A0();
}

void func_8001E490(void) {
    osDestroyThread(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E35DD0/func_8001E4B0.s")

void func_8001E578(s32 arg0) { extern s32 D_8007E94C, D_8007E958; OSThread *func_8001DDA4(s32); void func_8001E7B4(s32); void func_8001E4B0(void); void _gzpublic_entrypoint_0(s32); func_8001E7B4(1); osSetThreadPri(func_8001DDA4(D_8007E958), 0); osSetThreadPri(func_8001DDA4(7), 0x5B); func_8001E4B0(); _gzpublic_entrypoint_0(D_8007E94C); }

void func_8001E5DC(s32 arg0) {
    extern s32 D_8007E948;
    extern s32 D_8011A3F0;
    extern u8 D_80041180[];
    extern OSThread D_8007E788;
    extern __OSThreadOddFpStorage D_8007E938;
    extern OSThread *__osFaultedThread, *__osRunningThread;
    OSThread *func_80012598(void);
    OSThread *func_8001DDA4(s32);
    void func_8001559C(s32);
    void func_8001DCB0(OSThread *, __OSThreadOddFpStorage *, s32, void (*)(void *), void *, void *, OSPri);
    s32 i;
    OSThread *thread;

    if (D_8011A3F0 != 0) {
        func_8001559C(0);
        (&D_8007E948)[4] = osGetThreadId(NULL);
        for (i = 0; i != 10; i++) {
            thread = func_8001DDA4(i);
            if (thread != NULL) {
                (&D_8007E948)[5 + i] = osGetThreadPri(thread);
            } else {
                (&D_8007E948)[5 + i] = 0;
            }
        }
        for (i = 0; i != 10; i++) {
            if (i != (&D_8007E948)[4]) {
                thread = func_8001DDA4(i);
                if (thread != NULL) {
                    osSetThreadPri(thread, D_80041180[i]);
                }
            }
        }
        osSetThreadPri(NULL, 10);
        switch (arg0) {
            default:
                ((OSThread **)(&D_8007E948))[1] = __osRunningThread;
                break;
            case 1:
                ((OSThread **)(&D_8007E948))[1] = func_8001DDA4(6);
                break;
            case 2:
                ((OSThread **)(&D_8007E948))[1] = func_80012598();
                break;
            case 0:
                ((OSThread **)(&D_8007E948))[1] = __osFaultedThread;
                break;
            case 7:
                ((OSThread **)(&D_8007E948))[1] = __osFaultedThread;
                break;
        }
        (&D_8007E948)[2] = osGetThreadId(((OSThread **)(&D_8007E948))[1]);
        (&D_8007E948)[3] = (&D_8007E948)[5 + (&D_8007E948)[2]];
        D_8007E948 = arg0;
        func_8001DCB0(&D_8007E788, &D_8007E938, 9, func_8001E578, NULL, (u8 *)&D_8007E938 - sizeof(OSThread), 0x5A);
        osStartThread(&D_8007E788);
    }
}

s32 func_8001E7A0(s32 arg0) {
    extern s32 D_8007E95C[];
    return ((s32 *)&D_8007E95C)[arg0];
}

void func_8001E7B4(s32 arg0) {
    extern s16 D_8007DB80;

    D_8007DB80 = arg0;
}

s16 func_8001E7C0(void) {
    extern s16 D_8007DB80;

    return D_8007DB80;
}

s32 func_8001E7CC(void) {
    extern s32 D_8007E948;

    return D_8007E948;
}
