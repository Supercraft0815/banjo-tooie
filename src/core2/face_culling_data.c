#include <ultra64.h>
#include "bt_data.h"

Gfx D_801233C0[11] BT_DATA(8, face_culling, 0) = {
    {{0xD9C0F9FA, 0x00000000}},
    {{0xD9FFFFFF, 0x00200005}},
    {{0xD7000000, 0x00000000}},
    {{0xE7000000, 0x00000000}},
    {{0xE3000A01, 0x00000000}},
    {{0xE3000800, 0x00000000}},
    {{0xFCFFFFFF, 0xFFFE793C}},
    {{0xE2001E01, 0x00000000}},
    {{0xE3001801, 0x000000C0}},
    {{0xE200001C, 0x00507858}},
    {{0xDF000000, 0x00000000}},
};
Gfx D_80123418[2] BT_DATA(8, face_culling, 0x58) = {
    gsSPSetGeometryMode(G_CULL_BACK), gsSPEndDisplayList(),
};
Gfx D_80123428[2] BT_DATA(8, face_culling, 0x68) = {
    gsSPSetGeometryMode(G_CULL_FRONT), gsSPEndDisplayList(),
};
Gfx face_culling_padding BT_DATA(8, face_culling, 0x78) = {{0, 0}};
Gfx face_overlay_setup[11] BT_DATA(8, face_culling, 0x80) = {
    {{0xE7000000, 0x00000000}},
    {{0xD9C0FFFA, 0x00000000}},
    {{0xD9FFFFFF, 0x00200004}},
    {{0xD7000002, 0xFFFFFFFF}},
    {{0xE200001C, 0x0F0A4000}},
    {{0xE3000A01, 0x00000000}},
    {{0xFC157E2A, 0xFFFFF3F9}},
    {{0xE3001201, 0x00000000}},
    {{0xE3000C00, 0x00000000}},
    {{0xFA000000, 0x00000078}},
    {{0xDF000000, 0x00000000}},
};
Gfx face_overlay_restore[5] BT_DATA(8, face_culling, 0xD8) = {
    {{0xE7000000, 0x00000000}},
    {{0xE3001201, 0x00002000}},
    {{0xE3000C00, 0x00080000}},
    {{0xDF000000, 0x00000000}},
    {{0x00000000, 0x00000000}},
};
