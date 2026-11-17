#include "common.h"

s32 sucoasterdata_entrypoint_0(void **arg0) { extern s32 D_808003C0_sucoasterdata[23]; extern s32 D_8080041C_sucoasterdata[184]; u8 *var_a0; s32 var_v1; u32 temp_t7; temp_t7 = *(u32 *)((u8 *)*arg0 + 0x24) >> 22; var_v1 = 1; if (temp_t7 == *(u16 *)D_808003C0_sucoasterdata) { return 0; } var_a0 = (u8 *)D_8080041C_sucoasterdata; loop_3: if (temp_t7 == *(u16 *)var_a0) { return var_v1; } if (temp_t7 == *(u16 *)(var_a0 + 0x5C)) { return var_v1 + 1; } if (temp_t7 == *(u16 *)(var_a0 + 0xB8)) { return var_v1 + 2; } if (temp_t7 == *(u16 *)(var_a0 + 0x114)) { return var_v1 + 3; } var_v1 += 4; var_a0 += 0x170; if (var_v1 == 9) { return 0; } goto loop_3; }

void *sucoasterdata_entrypoint_1(s32 arg0) {
    extern s32 D_808003C0_sucoasterdata[23];
    return (u8 *)D_808003C0_sucoasterdata + arg0 * 0x5C;
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
s32 D_808003C0_sucoasterdata[23] BT_DATA(4, overlays_su_coaster_data, 0x0) = { 22675646, 79392096, 15073331, 67071328, 16777344, 79523168, 11730969, 79523168, 13369369, 71527776, 28508160, 28000, 16777216, 28000, 16777216, 65536, 8192, 0, -65396, 1039516303, 524488, 5242930, 0 };
s32 D_8080041C_sucoasterdata[184] BT_DATA(4, overlays_su_coaster_data, 0x5C) = { 27394239, 79588704, 16777241, 67059328, 16777331, 79588704, 15073356, 79850848, 16777241, 71527776, 28508160, 68566656, 16777369, 28000, 16777216, 65536, 0, 2, -65456, 1039516303, 524438, 3932210, 65536, 27328704, 28000, 16777241, 67059328, 16777318, 80768352, 15073280, 80768352, 16777241, 71527776, 28508160, 28000, 16777216, 28000, 16777216, 65536, 0, 0, -65436, 1039516303, 524488, 5242945, 65536, 26214593, 83452328, 28508211, 28000, 16777216, 83386792, 25952281, 83386792, 28508185, 71527776, 28508160, 68566656, 16777346, 28000, 16777216, 65536, 32768, 2, -65336, 1039516303, 524488, 6553670, 131072, 50200664, 97480032, 10027059, 96234848, 8388710, 84962656, 10027033, 83062112, 8388608, 71527776, 28508160, 28000, 16777216, 28000, 16777216, 196608, 262144, 0, -65386, 1039516303, 524488, 6553670, 0, 53149890, 98918824, 26804275, 67059328, 16777344, 88760744, 20971545, 88760744, 23461913, 71527776, 28508160, 28000, 16777216, 28000, 16777216, 65536, 0, 0, -65396, 1039516303, 524488, 4587590, 131072, 52822211, 99180968, 20119603, 67059328, 16777318, 99246504, 15073305, 99312040, 15073305, 71527776, 28508160, 96556528, 13369492, 28000, 16777216, 65536, 0, 2, -65386, 1039516303, 524488, 6553700, 131072, 11141316, 102200624, 14221363, 67059328, 16777344, 102266160, 15073305, 102331696, 15073305, 71527776, 28508160, 28000, 16777216, 99380576, 13369446, 65536, 0, 0, -65416, 1039516303, 524438, 6553670, 327680, 49742021, 25000, 16777267, 67059328, 16777344, 99446112, 16777292, 99511648, 16777267, 71527776, 28508160, 28000, 16777216, 28000, 16777216, 65536, 0, 0, -65376, 1039516303, 524488, 4587590, 131072 };
s32 D_808006FC_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x33C) = { 42, 1072064102, 36372480, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_80800750_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x390) = { 18, 1074580685, 36372480, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_808007A4_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x3E4) = { 18, 1074580685, 36438016, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_808007F8_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x438) = { 18, 1075838976, 16515072, 30, 1069547520, 35389440, 16, 1069547520, 34471936, 20, 1072483533, 35127296, 6, 1072483533, 34209792, 3, 1074580685, 17956864, 68, 1070386381, 38207488 };
s32 D_8080084C_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x48C) = { 44, 1061997773, 36306944, 30, 1061997773, 35389440, 16, 1061997773, 34471936, 20, 1060320051, 33488896, 6, 1060320051, 33488896, 1, 1067030938, 1179648, 68, 1064514355, 16580608 };
s32 D_808008A0_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x4E0) = { 42, 1065353216, 1179648, 30, 1065353216, 35389440, 16, 1065353216, 34471936, 20, 1065353216, 35127296, 6, 1065353216, 34209792, 3, 1061997773, 17956864, 44, 1066192077, 19595264 };
s32 D_808008F4_sucoasterdata[21] BT_DATA(4, overlays_su_coaster_data, 0x534) = { 42, 1068708659, 2818048, 30, 1068708659, 35389440, 16, 1068708659, 34471936, 20, 1068708659, 35127296, 6, 1068708659, 34209792, 3, 1074161254, 17956864, 46, 1075419546, 36503552 };
s32 D_80800948_sucoasterdata[18] BT_DATA(4, overlays_su_coaster_data, 0x588) = { 18, 1070386381, 16515072, 30, 1067869798, 18612224, 16, 1067869798, 17694720, 20, 1065353216, 35127296, 6, 1065353216, 34209792, 1, 1069547520, 17956864 };
s32 D_80800990_sucoasterdata[24] BT_DATA(4, overlays_su_coaster_data, 0x5D0) = { 3, 1072064102, 2752512, 30, 1065353216, 1835008, 16, 1065353216, 917504, 28, 1065353216, 1966080, 14, 1065353216, 1048576, 20, 1060320051, 1572864, 6, 1060320051, 655360, 0, 0, 0 };
