#include "ch/mayaentrydoor.h"

extern BtUIntPtr D_808000E0_chmayaentrydoor[20];

void func_80800000_chmayaentrydoor(Unk80800000MayaEntryDoor* arg0)
{
    s32 sp2C;
    if ((_glcutDll_entrypoint_19(0x67) == 0) && (_sujiggy_entrypoint_20(0) != 0))
    {
        func_800DA544(FLAG_392_PROGRESS_OPENED_WORLD_MT);
    }
    
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7A) == 0))
    {
        sp2C = -1;
        func_80101FDC(arg0, 4U);
    }
    else
    {
        sp2C = 0x392;
    }
    _chdoormake_entrypoint_3(arg0, 0, 90.0f, arg0->unk38 * 220.0f, 1, sp2C);
    _chdoormake_entrypoint_8(arg0, 0xD);
    _chdoormake_entrypoint_5(arg0, 0);
}

void* chmayaentrydoor_entrypoint_0(void) {
    return D_808000E0_chmayaentrydoor;
}
/* data_to_c.py: from asm/data/overlays/ch/mayaentrydoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
BtUIntPtr D_808000E0_chmayaentrydoor[20] BT_DATA(4, overlays_ch_mayaentrydoor, 0x0) = { 0xAC0391, 0x9670001, 0, (BtUIntPtr)_chdoor_entrypoint_0, (BtUIntPtr)func_80105834, (BtUIntPtr)func_80101870, 0, 0, 0x3920000, 0xC00, 0, 0, 0, (BtUIntPtr)func_80800000_chmayaentrydoor, (BtUIntPtr)func_80107C2C, 0x80002402, (BtUIntPtr)_chdoor_entrypoint_1, 0, 0, 0 };
