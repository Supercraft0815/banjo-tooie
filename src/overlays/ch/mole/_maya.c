#include "ch/mole.h"

extern MoveData D_808001E0_chmole_maya[];
extern D_808000D0 D_80800210_chmole_maya;

void func_80800000_chmole_maya(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808001E0_chmole_maya);
}

void func_80800024_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808001E0_chmole_maya);
}

void* chmole_maya_entrypoint_0()
{
	return &D_80800210_chmole_maya;
}

/* extern */

void func_808000C0_chmole_maya(Actor *arg0) {
    s32 func_8008FA2C(s32, s32);
    if ((func_8010C500(arg0) != 0) && (func_8008FA2C(-1, 0) != 0)) {
        (*(u8 *)((s8 *)(arg0) + (0x7E))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x7E))) & 0xFFBF);
        func_800DA544(FLAG_506_FTT_CS_JAMJARS);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0xDBFU, 0xCU, arg0->position, 0x6FU);
        _capod_entrypoint_13(arg0->unk0, NULL, 0xBU, 0x20U);
    }
}

void func_80800144_chmole_maya(s32 arg0) 
{
}
void func_8080014C_chmole_maya(Actor *arg0) {
    if (func_800DA298(FLAG_506_FTT_CS_JAMJARS) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_80800180_chmole_maya(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0x2E:
        _capod_entrypoint_14();
        func_800FFAB0(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chmole_maya_entrypoint_1(void)
{
    extern u8 D_80800258_chmole_maya[];

    return (OSThread *) D_80800258_chmole_maya;
}
