#include "common.h"

void gzthread_entrypoint_0(s32 arg0, char *arg1) {
    extern u8 *D_80800380_gzthread[];
    u8 *temp_v0;
    u8 c;

    temp_v0 = D_80800380_gzthread[arg0];
    arg1++;
    c = *temp_v0++;
    arg1[-1] = c;
    while (c != 0) {
        c = *temp_v0;
        arg1++;
        temp_v0++;
        arg1[-1] = c;
    }
}

const char R_808002B0_gzthread[] = "VI";
const char R_808002B4_gzthread[] = "IDLE";
const char R_808002BC_gzthread[] = "TIDY";
const char R_808002C4_gzthread[] = "CIC-6105";
const char R_808002D0_gzthread[] = "AUDIO";
const char R_808002D8_gzthread[] = "SCHEDULER";
const char R_808002E4_gzthread[] = "MAIN";
const char R_808002EC_gzthread[] = "JOY";
const char R_808002F0_gzthread[] = "MOTOR";
const char R_808002F8_gzthread[] = "CRASH";

void gzthread_entrypoint_1(s32 arg0) {
    extern u8 *D_80800380_gzthread[];
    extern u8 D_808003A8_gzthread[];
    BtIntPtr func_80014ED4(void);
    void func_8001D37C(const char *arg0, ...);
    void func_8001D3D8(s16 arg0, s16 arg1, const char *arg2, ...);
    void func_8001D98C(u16 arg0);
    void func_8001DB90(u16 *arg0, int arg1, u32 arg2, u8 *arg3);
    OSThread *func_8001DDA4(s32);
    s32 func_8001E7A0(s32 arg0);
    int i;
    int index;
    s32 row;
    OSThread *thread;
    s32 priority;
    u32 pc;
    u32 sp;
    u8 **name;

    if (arg0 >= 0) {
        row = arg0 + 7;
        i = 0;
        do {
            func_8001DB90(func_80014ED4(), i, row, D_808003A8_gzthread);
            i++;
        } while (i != 9);
    }
    func_8001D3D8(0, 5, "Thread");
    func_8001D3D8(11, -1, "State");
    func_8001D3D8(21, -1, "Pri");
    func_8001D3D8(29, -1, "PC");
    func_8001D3D8(38, -1, "SP");
    func_8001D3D8(47, -1, "Queue\n\n");
    name = D_80800380_gzthread;
    index = 0;
    do {
        thread = func_8001DDA4(index);
        func_8001D3D8(0, -1, "%s", *name);
        func_8001D98C(11);
        if (thread != NULL) {
            priority = func_8001E7A0(index);
            pc = thread->context.pc;
            sp = thread->context.sp;
            switch (thread->state) {
                case 1: func_8001D37C("Stopped"); break;
                case 2: func_8001D37C("Runnable"); break;
                case 4: func_8001D37C("Running"); break;
                case 8: func_8001D37C("Waiting"); break;
            }
            func_8001D3D8(21, -1, "%3d/%2d", priority, thread->priority);
            func_8001D3D8(29, -1, "%08X", pc);
            func_8001D3D8(38, -1, "%08X", sp);
            if (thread->state == 8) {
                func_8001D3D8(47, -1, "%08X\n", thread->queue);
            } else {
                func_8001D37C("\n");
            }
        } else {
            func_8001D37C("(n/a)\n");
        }
        index++;
        name++;
    } while (index != 10);
}
