#include "core2/reflection_planes.h"
#include "bt_data.h"

ReflectionPlane D_8011A760[3] BT_DATA(4, dialog_render, 0) = {
    {0x151, 0x861, 255, 1, {0, 0, 0}, {0, 1, 0}},
    {0x103, 0x860, 255, 0, {1050, 0, 0}, {-1, 0, 0}},
    {0x15E, 0x857, 255, 1, {0, 0, 0}, {0, 1, 0}},
};

s8 D_8011A7C0[16] BT_DATA(1, dialog_render, 0x60) =
    {1, 30, 20, 15, 11, 8, 6, 4, 3, 2, -1, -1};
s32 D_8011A7D0 BT_DATA(4, dialog_render, 0x70) = 1;
u32 dialog_render_padding[3] BT_DATA(4, dialog_render, 0x74) = {0};

/* RDP state at the beginning and end of the dialog overlay. */
Gfx D_8011A7E0[12] BT_DATA(8, dialog_render, 0x80) = {
    {{0xE7000000, 0x00000000}},
    {{0xD9C0FFFA, 0x00000000}},
    {{0xD9FFFFFF, 0x00200004}},
    {{0xD7000002, 0xFFFFFFFF}},
    {{0xE200001C, 0x0F0A4000}},
    {{0xE3000A01, 0x00000000}},
    {{0xFC157E2A, 0xFFFFF3F9}},
    {{0xE3001201, 0x00000000}},
    {{0xE3000C00, 0x00000000}},
    {{0xFA000000, 0x000000FF}},
    {{0xE3001801, 0x000000C0}},
    {{0xDF000000, 0x00000000}},
};
Gfx D_8011A840[6] BT_DATA(8, dialog_render, 0xE0) = {
    {{0xE7000000, 0x00000000}},
    {{0xE3001201, 0x00002000}},
    {{0xE3000C00, 0x00080000}},
    {{0xE3001801, 0x00000000}},
    {{0xDF000000, 0x00000000}},
    {{0x00000000, 0x00000000}},
};

f32 D_8011A870 BT_DATA(4, dialog_render, 0x110) = 0.0f;
f32 D_8011A874 BT_DATA(4, dialog_render, 0x114) = 1.0f;
f32 D_8011A878 BT_DATA(4, dialog_render, 0x118) = 1.0f;
