#include "ch/mineentrygrill.h"

extern s32 D_80800140_chmineentrygrille[];
extern u32 D_80800180_chmineentrygrille[5];
extern BtUIntPtr D_80800194_chmineentrygrille[19];

s32 func_80800000_chmineentrygrille(Actor* arg0, s32 arg1, u32 arg2) 
{
    Actor* temp_v0;

    switch (arg1) 
    {
    case 0x7:
        _chexploder_entrypoint_3(arg0, arg0->position, 8);
        //Set Flag True
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        return 1;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6);
        _chexploder_entrypoint_15(temp_v0, 2, 1.0f);

        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800140_chmineentrygrille);
        func_800C4AF0(arg0->position, D_80800180_chmineentrygrille); 
        return 1;
    default:
        return 0;
    }
}

void func_808000C4_chmineentrygrille(BtIntPtr arg0) 
{
    if (_sujiggy_entrypoint_20(1) != 0)
    {
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        func_800FFAB0(arg0);
        return;
    }
    //Check if the cheat is not active and something about cutscenes
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7B) == 0))
    {
        func_800FFAB0(arg0);
    }
}

void* chmineentrygrille_entrypoint_0(void) {
    return D_80800194_chmineentrygrille;
}
/* data_to_c.py: from asm/data/overlays/ch/mine/entrygrille.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_80800140_chmineentrygrille [16] BT_DATA(4, overlays_ch_mine_entrygrille, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102367232 };
u32 D_80800180_chmineentrygrille[5] BT_DATA(4, overlays_ch_mine_entrygrille, 0x40) = { 0x130413, 0xA00E6, 0x166D60, 0x11964, 0x19640000 };
BtUIntPtr D_80800194_chmineentrygrille[19] BT_DATA(4, overlays_ch_mine_entrygrille, 0x54) = { 0xAC0393, 0x9690001, 0, 0, (BtUIntPtr)func_80105834, (BtUIntPtr)func_80101870, 0, 0, 0x3930000, 0x20C00, 0, 0, 0, (BtUIntPtr)func_808000C4_chmineentrygrille, (BtUIntPtr)func_80107C2C, 0x80002802, (BtUIntPtr)func_80800000_chmineentrygrille, 0, 0 };
