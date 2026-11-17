#include "su/restart.h"

typedef struct {
    s16 respawnMap;
    s16 transformationMap; //Used by Mumbo transformations to tell what level he is in
    u8 transformation;
    u8 entranceId;
} RestartData;

extern RestartData D_808000D0_surestart[];

void surestart_entrypoint_0(s32 arg0)
{
    s32 transformationHome;
    s32 currentMap;
    s32 mapId;
    s32 entranceId;
    s32 i = 0;
    currentMap = func_800EA05C();
    if (arg0 == 1)
    {
        func_8009EBD0();
        return;
    }
    for (i = 0; i < 20; i++)
    {
        if ((arg0 == D_808000D0_surestart[i].transformation) && (transformationHome = D_808000D0_surestart[i].transformationMap, (transformationHome == 0) || (currentMap == transformationHome)))
        {
            mapId = D_808000D0_surestart[i].respawnMap;
            entranceId = D_808000D0_surestart[i].entranceId;
            if ((transformationHome == MAP_13E_CCL_MUMBO) || (transformationHome == MAP_13F_CCL_MINGY_JONGO))
            {
                if (func_800DA298(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                {
                    entranceId = 9;
                }
            }
            func_8009EB24(mapId, entranceId);
            return;
        }
    }
}
/* data_to_c.py: from asm/data/overlays/su/restart.data.s */
RestartData D_808000D0_surestart [20] BT_DATA(4, overlays_su_restart, 0x0) = { { 184, 183, 0xD, 5 }, { 199, 217, 0xD, 8 }, { 231, 374, 0xD, 2 }, { 423, 239, 0xD, 0xE }, { 274, 369, 0xD, 4 }, { 264, 370, 0xD, 0xA }, { 295, 308, 0xD, 3 }, { 310, 318, 0xD, 0x16 }, { 310, 319, 0xD, 0x16 }, { 341, 342, 0xD, 8 }, { 296, 0, 2, 8 }, { 310, 0, 6, 0x19 }, { 262, 0, 7, 0xA }, { 196, 0, 8, 4 }, { 424, 0, 0xC, 0x12 }, { 199, 0, 0xF, 0xE }, { 214, 0, 0x10, 0xA }, { 274, 0, 0x12, 6 }, { 274, 0, 0x13, 0x16 }, { 184, 0, 0xE, 9 } };
u8 D_80800148_surestart[8] BT_DATA(4, overlays_su_restart, 0x78) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
