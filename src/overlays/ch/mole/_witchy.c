#include "ch/mole.h"

extern MoveData D_808000C0_chmole_witchy[];
extern D_808000D0 D_808000F0_chmole_witchy;

void func_80800000_chmole_witchy(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_witchy);
}

void func_80800024_chmole_witchy(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_witchy(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_witchy);
}

void* chmole_witchy_entrypoint_0()
{
	return &D_808000F0_chmole_witchy;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_witchy.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_witchy [3] BT_DATA(4, overlays_ch_mole__witchy, 0x0) = { { 1, 0xD63, 3428, 0xD65, 27, 0xFF, 0xB4, 5, 0 }, { 1, 0xD66, 3431, 0xD68, 28, 0xFF, 0xA0, 6, 0 }, { 512, 0xD69, 3434, 0xD6B, 41, 0xFF, 0xAA, 7, 0 } };
D_808000D0 D_808000F0_chmole_witchy BT_DATA(4, overlays_ch_mole__witchy, 0x30) = { 0x2EA0182, 1, 0, (unsigned long *)func_80800090_chmole_witchy, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_witchy, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_witchy, 0, 0 };
