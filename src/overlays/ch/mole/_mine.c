#include "ch/mole.h"

extern MoveData D_808000C0_chmole_mine[];
extern D_808000D0 D_808000E0_chmole_mine;

void func_80800000_chmole_mine(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_mine);
}

void func_80800024_chmole_mine(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_mine(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_mine);
}

void* chmole_mine_entrypoint_0()
{
	return &D_808000E0_chmole_mine;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_mine.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_mine [2] BT_DATA(4, overlays_ch_mole__mine, 0x0) = { { 1, 0xD4E, 3404, 0xD4D, 25, 0xFF, 0x55, 0xC, 0 }, { 257, 0xD51, 3407, 0xD50, 26, 0xFF, 0x5F, 0xD, 0 } };
D_808000D0 D_808000E0_chmole_mine BT_DATA(4, overlays_ch_mole__mine, 0x20) = { 0x2EA01A8, 1, 0, (unsigned long *)func_80800090_chmole_mine, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_mine, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_mine, 0, 0 };
