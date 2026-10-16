#include "common.h"

void func_80800000_chsounder(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    extern s32 D_808000A0_chsounder;
    extern s32 D_808000AC_chsounder;

    switch (arg0->unk74_7) {
    case 0x32:
        _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, 1, -1, &D_808000A0_chsounder);
        return;
    case 0x33:
        _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, 1, -1, &D_808000AC_chsounder);
        return;
    }
}

void func_80800078_chsounder(s32 arg0) 
{
}
void func_80800080_chsounder(s32 arg0) 
{
}
OSThread *chsounder_entrypoint_0(void)
{
    extern u8 D_808000BC_chsounder[];

    return (OSThread *) D_808000BC_chsounder;
}
