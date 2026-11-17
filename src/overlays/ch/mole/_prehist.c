#include "ch/mole.h"

extern MoveData D_808000C0_chmole_prehist[];
extern D_808000D0 D_808000F0_chmole_prehist;

void func_80800000_chmole_prehist(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_prehist);
}

void func_80800024_chmole_prehist(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_prehist(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_prehist);
}

void* chmole_prehist_entrypoint_0()
{
	return &D_808000F0_chmole_prehist;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_prehist.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_prehist [3] BT_DATA(4, overlays_ch_mole__prehist, 0x0) = { { 1, 0xD8F, 3469, 0xD8E, 38, 0xFF, 0x186, 8, 0 }, { 512, 0xD92, 3472, 0xD91, 39, 0xFF, 0x195, 9, 0 }, { 1024, 0xD95, 3475, 0xD94, 40, 0xFF, 0x1A4, 0xA, 0 } };
D_808000D0 D_808000F0_chmole_prehist BT_DATA(4, overlays_ch_mole__prehist, 0x30) = { 0x2EA0186, 1, 0, (unsigned long *)func_80800090_chmole_prehist, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_prehist, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_prehist, 0, 0 };
