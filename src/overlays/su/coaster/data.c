#include "common.h"

#include "coaster_track_lookup.inc"

void *sucoasterdata_entrypoint_1(s32 arg0) {
    extern s32 D_808003C0_sucoasterdata[23];
    return BT_DATA_FIELD(&coasterTracks[arg0], (u8 *)D_808003C0_sucoasterdata + arg0 * 0x5C);
}

s32 sucoasterdata_entrypoint_2(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x3C;
    case 1:
        return 0x3C;
    case 2:
        return 0x5A;
    case 3:
        return 0x78;
    case 4:
        return 0x32;
    case 5:
        return 0x78;
    case 6:
        return 0x50;
    case 7:
        return 0x28;
    case 8:
        return 0x78;
    default:
        return 0;
    }
}

s32 sucoasterdata_entrypoint_3(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0xF0;
    case 1:
        return 0xD2;
    case 2:
        return 0xB4;
    case 3:
        return 0x12C;
    case 4:
        return 0x78;
    case 5:
        return 0x12C;
    case 6:
        return 0xC8;
    case 7:
        return 0xAA;
    case 8:
        return 0xC8;
    default:
        return 0;
    }
}

s32 sucoasterdata_entrypoint_4(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x140;
    case 1:
        return 0x12C;
    case 2:
        return 0x154;
    case 3:
        return 0x168;
    case 4:
        return 0x190;
    case 5:
        return 0x17C;
    case 6:
        return 0x1A4;
    case 7:
        return 0x1B8;
    case 8:
        return 0x1CC;
    default:
        return 0;
    }
}

s32 *sucoasterdata_entrypoint_5(u32 arg0, s32 arg1, s32 *arg2) {
    extern s32 D_808006FC_sucoasterdata[21];
    extern s32 D_80800750_sucoasterdata[21];
    extern s32 D_808007A4_sucoasterdata[21];
    extern s32 D_808007F8_sucoasterdata[21];
    extern s32 D_8080084C_sucoasterdata[21];
    extern s32 D_808008A0_sucoasterdata[21];
    extern s32 D_808008F4_sucoasterdata[21];
    extern s32 D_80800948_sucoasterdata[18];
    extern s32 D_80800990_sucoasterdata[24];

    switch (arg0) {
    case 0:
        *arg2 = 7;
        return D_8080084C_sucoasterdata;
    case 1:
        *arg2 = 7;
        return D_80800990_sucoasterdata;
    case 3:
        switch (arg1) {
        case 0x327:
            *arg2 = 7;
            return D_808006FC_sucoasterdata;
        case 0x328:
            *arg2 = 7;
            return D_80800750_sucoasterdata;
        case 0x329:
            *arg2 = 7;
            return D_808007A4_sucoasterdata;
        case 0x32A:
            *arg2 = 7;
            return D_808007F8_sucoasterdata;
        }
        break;
    case 5:
        *arg2 = 7;
        return D_808008A0_sucoasterdata;
    case 6:
        *arg2 = 7;
        return D_808008F4_sucoasterdata;
    case 7:
        *arg2 = 6;
        return D_80800948_sucoasterdata;
    }
    *arg2 = 0;
    return 0;
}
/* data_to_c.py: from asm/data/overlays/su/coaster/data.data.s */
#include "coaster_tracks.inc"

s32 D_808006FC_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x33C) = { 42, 1072064102, 36372480, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_80800750_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x390) = { 18, 1074580685, 36372480, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_808007A4_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x3E4) = { 18, 1074580685, 36438016, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_808007F8_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x438) = { 18, 1075838976, 16515072, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_8080084C_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x48C) = { 44, 1061997773, 36306944, 30, 1061997773, 35389440, 16, 1061997773, 34471936, 20, 1060320051, 33488896, 6, 1060320051, 33488896, 1, 1067030938, 1179648, 68, 1064514355, 16580608 };
s32 D_808008A0_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x4E0) = { 42, 1065353216, 1179648, 30, 1065353216, 35389440, 16, 1065353216, 34471936, 20, 1065353216, 35127296, 6, 1065353216, 34209792, 3, 1061997773, 17956864, 44, 1066192077, 19595264 };
s32 D_808008F4_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x534) = { 42, 1068708659, 2818048, 30, 1068708659, 35389440, 16, 1068708659, 34471936, 20, 1068708659, 35127296, 6, 1068708659, 34209792, 3, 1074161254, 17956864, 46, 1075419546, 36503552 };
s32 D_80800948_sucoasterdata[18] BT_DATA(4, overlays_su_coaster_data, 0x588) = { 18, 1070386381, 16515072, 30, 1067869798, 18612224, 16, 1067869798, 17694720, 20, 1065353216, 35127296, 6, 1065353216, 34209792, 1, 1069547520, 17956864 };
s32 D_80800990_sucoasterdata[24] BT_DATA(4, overlays_su_coaster_data, 0x5D0) = { 3, 1072064102, 2752512, 30, 1065353216, 1835008, 16, 1065353216, 917504, 28, 1065353216, 1966080, 14, 1065353216, 1048576, 20, 1060320051, 1572864, 6, 1060320051, 655360, 0, 0, 0 };
