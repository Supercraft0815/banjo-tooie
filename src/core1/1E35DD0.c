#include "common.h"

void func_8001E2A0()
{
    func_8001DA60(func_80014F00());
}

void func_8001E2C8(void) {
    extern s32 D_8007E950;
    void func_8001D37C(BtIntPtr arg0, ...);
    void func_8001D96C();

    func_8001D96C();
    func_8001D37C("\nFault: CPU exception in thread %d!\n", D_8007E950);
    func_8001E2A0();
}

void func_8001E304(void) {
    void _gzreg_entrypoint_1(void);
    void func_8001D37C(BtIntPtr arg0, ...);
    void func_8001D96C();
    void func_8001D9CC(u16 arg0, u16 arg1);

    func_8001D96C();
    func_8001D37C("\nFault: WATCH GFX!\n");
    func_8001D9CC(0, 0xA);
    _gzreg_entrypoint_1();
    func_8001E2A0();
}

void func_8001E34C(void) {
    void func_8001D37C(BtIntPtr arg0, ...);
    void func_8001D96C();

    func_8001D96C();
    func_8001D37C("\nWe seem to be stuck in an infinite loop!\n");
    func_8001E2A0();
}

void func_8001E380()
{
    func_8001E2A0();
}

void func_8001E3A0(void) {
    extern s32 D_8007E948;
    s32 func_8001211C(void);
    void func_8001D37C(BtIntPtr arg0, ...);

    func_8001D37C("\n[%d] Crash of unknown origin! (type = %d)\n", func_8001211C(), D_8007E948);
    func_8001E2A0();
}

void func_8001E3E0(void) {
    s32 func_8001211C(void);
    void func_8001D37C(BtIntPtr arg0, ...);

    func_8001D37C("\n[%d] Out of Memory!\n", func_8001211C());
    func_8001E2A0();
}

void func_8001E418(void) {
    void func_8001D37C(BtIntPtr arg0, ...);
    void func_8001D96C();

    func_8001D96C();
    func_8001D37C("\nFault: Halt!\n");
    func_8001E2A0();
}

void func_8001E44C(void) {
    void func_8001D3D8(s16 arg0, s16 arg1, const char *arg2, ...);
    void func_8001D96C();

    extern s32 D_8007E950;
    func_8001D96C();
    func_8001D3D8(0x11, 0x18, "Error: Software lock in thread %d!\n", D_8007E950);
    func_8001E2A0();
}

void func_8001E490(void) {
    osDestroyThread(NULL);
}

void func_8001E4B0(void) {
    extern s32 D_8007E948;
    void func_8001E380(void);

    switch (D_8007E948) {
    case 0:
        func_8001E2C8();
        break;
    case 1:
        func_8001E304();
        break;
    case 2:
        func_8001E34C();
        break;
    case 3:
        func_8001E380();
        break;
    case 4:
        func_8001E418();
        break;
    case 5:
        func_8001E3E0();
        break;
    case 6:
        func_8001E44C();
        break;
    case 7:
        func_8001E490();
        break;
    default:
        func_8001E3A0();
        break;
    }
}

void func_8001E578(s32 arg0) { extern s32 D_8007E94C, D_8007E958; OSThread *func_8001DDA4(s32); void func_8001E7B4(s32); void func_8001E4B0(void); void _gzpublic_entrypoint_0(struct unkD_8007E94C* arg0); func_8001E7B4(1); osSetThreadPri(func_8001DDA4(D_8007E958), 0); osSetThreadPri(func_8001DDA4(7), 0x5B); func_8001E4B0(); _gzpublic_entrypoint_0(D_8007E94C); }

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

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s16 D_8007DB80 BT_DATA(16, bss_core1bss1_2_cic_tail, 0x0);
OSThread D_8007E788 BT_DATA(8, bss_core1bss1_2_cic_tail, 0xC08);
__OSThreadOddFpStorage D_8007E938 BT_DATA(8, bss_core1bss1_2_cic_tail, 0xDB8);
s32 D_8007E948 BT_DATA(4, bss_core1bss1_2_cic_tail, 0xDC8);
s32 D_8007E94C BT_DATA(4, bss_core1bss1_2_cic_tail, 0xDCC);
s32 D_8007E950 BT_DATA(4, bss_core1bss1_2_cic_tail, 0xDD0);
s32 D_8007E95C [ 13 ] BT_DATA(4, bss_core1bss1_2_cic_tail, 0xDDC);
#endif
