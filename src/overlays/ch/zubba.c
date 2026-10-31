#include "common.h"

OSThread *chzubba_entrypoint_0(void)
{
    extern u8 D_80800178_chzubba[];

    return (OSThread *) D_80800178_chzubba;
}

/* extern */

void func_8080000C_chzubba(s32 arg0) {
    s32 _sucoasterfly_entrypoint_1(s32, s32);
    s32 func_8010A3E8(s32, s32);
    _sucoasterfly_entrypoint_1(arg0, 0);
    func_8010A3E8(arg0, 0x3F266666);
}

void func_80800040_chzubba(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_5(Actor *, f32 *, u32, s32, u32 *);
    void _sucoasterfly_entrypoint_3(Actor *);
    extern u32 D_808001C0_chzubba;
    u32 var_a2;

    _sucoasterfly_entrypoint_3(arg0);
    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        var_a2 = 1;
        break;
    default:
        var_a2 = 0;
        break;
    }
    /* Keep this condition: IDO otherwise moves the default assignment. */
    if ((func_80800040_chzubba && func_80800040_chzubba) && func_80800040_chzubba) {}
    if (arg0) {}
    _subaddieaudioloop_entrypoint_5(arg0, arg0->position, var_a2, -1, &D_808001C0_chzubba);
}
