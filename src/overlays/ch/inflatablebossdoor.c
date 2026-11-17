#include "ch/inflatablebossdoor.h"

extern BtIntPtr D_80800140_chinflatablebossdoor[20];

s32* chinflatablebossdoor_entrypoint_0(void)
{
    return D_80800140_chinflatablebossdoor;
}

void func_8080000C_chinflatablebossdoor(Actor* arg0)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = func_800DA298(FLAG_17F_RETRY_BOSS_MR_PATCH);
    sp30 = func_800F64A4(func_800F54E4(), ALLOW_BK);
    sp2C = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80101FDC(arg0, 1U);
    }
    else if ((sp34 == 0) && (sp2C != 0))
    {
        func_80101FDC(arg0, 4U);
    }
    else if ((sp34 != 0) && (sp30 != 0))
    {
        func_80101FDC(arg0, 1U);
    }
    func_80102FDC(arg0, arg0->scale * 1.4f);
    func_8010A800(arg0, 0);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 600.0f, 0x822, 0x9C) != 0)
    {
        _chdoormake_entrypoint_5(arg0, 4.0f);
        _chdoormake_entrypoint_6(arg0, 0x3F4CCCCD);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/inflatablebossdoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
#ifndef BT_NATIVE
void func_80107C2C();
#endif
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
BtIntPtr D_80800140_chinflatablebossdoor[20] BT_DATA(4, overlays_ch_inflatablebossdoor, 0x0) = { 11273326, 155385857, 0, (BtIntPtr)_chdoor_entrypoint_0, (BtIntPtr)func_80105834, (BtIntPtr)func_80101870, 0, 0, 10223616, 3072, 0, 0, 0, (BtIntPtr)func_8080000C_chinflatablebossdoor, (BtIntPtr)func_80107C2C, -2146948094, (BtIntPtr)_chdoor_entrypoint_1, 0, 0, 0 };
