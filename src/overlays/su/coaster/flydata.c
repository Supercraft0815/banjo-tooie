#include "common.h"

s32 sucoasterflydata_entrypoint_0(void **arg0) {
    extern s32 D_80800290_sucoasterflydata[50];
    u32 id;
    s32 i;

    id = *(u32 *)((u8 *)*arg0 + 0x24) >> 22;
    for (i = 0; i < 5; i++) {
        if (id == *(u16 *)((u8 *)D_80800290_sucoasterflydata + i * 0x28)) {
            return i;
        }
    }
    return 0;
}

void *sucoasterflydata_entrypoint_1(s32 arg0) {
    extern s32 D_80800290_sucoasterflydata[50];
    return (void *) ((arg0 * 5) * 8 + (u8 *) D_80800290_sucoasterflydata);
}

s32 *sucoasterflydata_entrypoint_2(u32 arg0, s32 *arg1) {
    extern s32 D_80800358_sucoasterflydata[21];
    extern s32 D_808003AC_sucoasterflydata[18];
    extern s32 D_808003F4_sucoasterflydata[18];
    extern s32 D_8080043C_sucoasterflydata[21];
    switch (arg0) {
    case 0:
        *arg1 = 7;
        return D_80800358_sucoasterflydata;
    case 1:
    case 2:
        *arg1 = 6;
        return D_808003AC_sucoasterflydata;
    case 3:
        *arg1 = 6;
        return D_808003F4_sucoasterflydata;
    case 4:
        *arg1 = 6;
        return D_8080043C_sucoasterflydata;
    default:
        *arg1 = 0;
        return NULL;
    }
}

s32 sucoasterflydata_entrypoint_3(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x12C;
    case 1:
        return 0xFA;
    case 2:
        return 0xFA;
    case 3:
        return 0x12C;
    case 4:
        return 0x12C;
    default:
        return 0;
    }
}

s32 sucoasterflydata_entrypoint_4(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x190;
    case 1:
        return 0x12C;
    case 2:
        return 0x12C;
    case 3:
        return 0x190;
    case 4:
        return 0x190;
    default:
        return 0;
    }
}

s32 sucoasterflydata_entrypoint_5(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x320;
    case 1:
        return 0x258;
    case 2:
        return 0x258;
    case 3:
        return 0x4B0;
    case 4:
        return 0x3E8;
    default:
        return 0;
    }
}
/* data_to_c.py: from asm/data/overlays/su/coaster/flydata.data.s */
s32 D_80800290_sucoasterflydata[50] BT_DATA(4, overlays_su_coaster_flydata, 0x0) = { 50135225, 67055328, 13369408, 87453024, 13369344, 87518560, 11730944, 87518560, 13369472, 131082, 27525304, 67055328, 20971660, 28000, 16777216, 79850848, 21757952, 79850848, 23462092, 131082, 27590840, 67055328, 20971660, 28000, 16777216, 79850848, 21757952, 79850848, 23462092, 196620, 44695705, 0, 16777472, 87453024, 13369344, 101733872, 16777216, 78861808, 16777420, 131082, 44892346, 12000, 13369408, 88695208, 25165824, 88760744, 24313856, 88760744, 26804339, 131082 };
s32 D_80800358_sucoasterflydata[21] BT_DATA(4, overlays_su_coaster_flydata, 0xC8) = { 18, 1074580685, 36306944, 44, 1070386381, 36569088, 1, 1070386381, 34734080, 22, 1070386381, 35389440, 8, 1070386381, 34471936, 24, 1068708659, 33619968, 10, 1068708659, 33619968 };
s32 D_808003AC_sucoasterflydata[18] BT_DATA(4, overlays_su_coaster_flydata, 0x11C) = { 43, 1075838976, 36438016, 1, 1070386381, 34734080, 22, 1070386381, 35389440, 8, 1070386381, 34471936, 24, 1068708659, 33619968, 10, 1068708659, 33619968 };
s32 D_808003F4_sucoasterflydata[18] BT_DATA(4, overlays_su_coaster_flydata, 0x164) = { 18, 1067030938, 36306944, 30, 1065353216, 1835008, 16, 1065353216, 917504, 20, 1065353216, 1572864, 6, 1065353216, 655360, 51, 1067030938, 37093376 };
s32 D_8080043C_sucoasterflydata[21] BT_DATA(4, overlays_su_coaster_flydata, 0x1AC) = { 42, 1069547520, 2818048, 3, 1065353216, 1179648, 30, 1060320051, 1835008, 16, 1060320051, 917504, 20, 1060320051, 1572864, 6, 1060320051, 655360, 0, 0, 0 };
