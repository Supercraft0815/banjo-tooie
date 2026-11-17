#include "ch/terryteeth.h"

extern s32 D_80800150_chterryteeth[16];
extern s32 D_80800190_chterryteeth[5];
extern BtUIntPtr D_808001A4_chterryteeth[19];

void func_80800000_chterryteeth(Actor* arg0)
{
    if (_sujiggy_entrypoint_20(4U) != 0)
    {
        func_800DA544(FLAG_396_PROGRESS_OPENED_WORLD_TDL);
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7EU) == 0))
    {
        func_800FFAB0(arg0);
    }
}

s32 func_8080006C_chterryteeth(Actor* arg0, s32 arg1, s32 arg2) 
{
    Actor* temp_v0;

    switch (arg1)
    {

    case 0x7:
        _chexploder_entrypoint_3(arg0, arg0->position, 8U);
        break;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6U);
        _chexploder_entrypoint_15(temp_v0, 2U, 1.0f);
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800150_chterryteeth);
        func_800C4AF0(arg0->position, D_80800190_chterryteeth);
        func_800DA544(FLAG_396_PROGRESS_OPENED_WORLD_TDL);
        break;
    default:
        return 0;
    }
    return 1;
}

void* chterryteeth_entrypoint_0(void) 
{
    return D_808001A4_chterryteeth;
}
/* data_to_c.py: from asm/data/overlays/ch/terryteeth.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_80800150_chterryteeth[16] BT_DATA(4, overlays_ch_terryteeth, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102367232 };
s32 D_80800190_chterryteeth[5] BT_DATA(4, overlays_ch_terryteeth, 0x40) = { 1246227, 655590, 1469792, 72036, 425984000 };
BtUIntPtr D_808001A4_chterryteeth[19] BT_DATA(4, overlays_ch_terryteeth, 0x54) = { 0xAC0396, 0x9700001, 0, 0, (BtUIntPtr)func_80105834, (BtUIntPtr)func_80101870, 0, 0, 0x3960000, 0x20C00, 0, 0, 0, (BtUIntPtr)func_80800000_chterryteeth, (BtUIntPtr)func_80107C2C, 0x80002402, (BtUIntPtr)func_8080006C_chterryteeth, 0, 0 };
