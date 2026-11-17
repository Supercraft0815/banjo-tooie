#include "ch/mole.h"

extern MoveData D_808000C0_chmole_lagoon[];
extern D_808000D0 D_808000F0_chmole_lagoon;

void func_80800000_chmole_lagoon(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_lagoon);
}

void func_80800024_chmole_lagoon(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_lagoon(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_lagoon);
}

void* chmole_lagoon_entrypoint_0()
{
	return &D_808000F0_chmole_lagoon;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_lagoon.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_lagoon [3] BT_DATA(4, overlays_ch_mole__lagoon, 0x0) = { { 1, 0xD85, 3459, 0xD84, 30, 0xFF, 0x122, 0x11, 3 }, { 1, 0xD88, 3462, 0xD87, 31, 0xFF, 0x113, 0x12, 0 }, { 1024, 0xD8B, 3465, 0xD8A, 29, 0xFF, 0x109, 0x13, 0 } };
D_808000D0 D_808000F0_chmole_lagoon BT_DATA(4, overlays_ch_mole__lagoon, 0x30) = { 0x2EA0315, 1, 0, (unsigned long *)func_80800090_chmole_lagoon, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_lagoon, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_lagoon, 0, 0 };
