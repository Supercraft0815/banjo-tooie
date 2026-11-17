#include "ch/mole.h"

extern MoveData D_808000C0_chmole_factory[];
extern D_808000D0 D_808000F0_chmole_factory;

void func_80800000_chmole_factory(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_factory);
}

void func_80800024_chmole_factory(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_factory(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_factory);
}

void* chmole_factory_entrypoint_0()
{
	return &D_808000F0_chmole_factory;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_factory.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_factory [3] BT_DATA(4, overlays_ch_mole__factory, 0x0) = { { 1, 0xD9E, 3484, 0xD9D, 37, 0xFF, 0x1F9, 0x16, 0 }, { 512, 0xDA1, 3487, 0xDA0, 35, 0xFF, 0x20D, 0x17, 0 }, { 1024, 0xDA4, 3490, 0xDA3, 36, 0xFF, 0x221, 0x18, 0 } };
D_808000D0 D_808000F0_chmole_factory BT_DATA(4, overlays_ch_mole__factory, 0x30) = { 0x2EA0185, 1, 0, (unsigned long *)func_80800090_chmole_factory, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_factory, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_factory, 0, 0 };
