#include "ch/mole.h"

extern MoveData D_808000C0_chmole_cuckoo[];
extern D_808000D0 D_808000D0_chmole_cuckoo;

void func_80800000_chmole_cuckoo(Actor* a0, u32 a1,u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_cuckoo);
}

void func_80800024_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_cuckoo);
}

void* chmole_cuckoo_entrypoint_0()
{
	return &D_808000D0_chmole_cuckoo;
}

/* data_to_c.py: from asm/data/overlays/ch/mole/_cuckoo.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
MoveData D_808000C0_chmole_cuckoo [1] BT_DATA(4, overlays_ch_mole__cuckoo, 0x0) = { { 512, 0xDB5, 3507, 0xDB4, 42, 0xFF, 0x2FD, 0x19, 0 } };
D_808000D0 D_808000D0_chmole_cuckoo BT_DATA(4, overlays_ch_mole__cuckoo, 0x10) = { 0x2EA0376, 1, 0, (unsigned long *)func_80800090_chmole_cuckoo, 0, (unsigned long *)func_8010A730, 0x1F40000, 0, 0, 0x80004, 0, 0, 0, (unsigned long *)func_80800024_chmole_cuckoo, (unsigned long *)func_80107C2C, 0x80002202, (BtUIntPtr)func_80800000_chmole_cuckoo, 0, 0 };
