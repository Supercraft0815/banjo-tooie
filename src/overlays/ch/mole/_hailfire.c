#include "ch/mole.h"

extern MoveData D_808000C0_chmole_hailfire[];
extern D_808000D0 D_808000E0_chmole_hailfire;

void func_80800000_chmole_hailfire(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_hailfire);
}

void func_80800024_chmole_hailfire(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_hailfire(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_hailfire);
}

void* chmole_hailfire_entrypoint_0()
{
	return &D_808000E0_chmole_hailfire;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_hailfire.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_hailfire [2] BT_DATA(4, overlays_ch_mole__hailfire, 0x0) = { { 512, 0xD98, 3478, 0xD97, 33, 0xFF, 0x280, 0x14, 0 }, { 1024, 0xD9B, 3481, 0xD9A, 34, 0xFF, 0x294, 0x15, 0 } };
D_808000D0 D_808000E0_chmole_hailfire BT_DATA(4, overlays_ch_mole__hailfire, 0x20) = { 0x2EA0184, 1, 0, (unsigned long *)func_80800090_chmole_hailfire, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_hailfire, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_hailfire, 0, 0 };
