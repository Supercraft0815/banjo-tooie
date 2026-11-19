void func_800C7230(MapPropAction *);
void func_800C725C(MapPropAction *);
void func_800C7290(MapPropAction *);
void func_800C72C0(MapPropAction *);
void func_800C72E4(MapPropAction *);
void func_800C72EC(MapPropAction *);
void func_800C7310(MapPropAction *);

MapPropAction D_8011A8A0[5] BT_DATA(4, map_prop_actions, 0) = {
    {0x251, NULL, func_800C72C0, func_800C72E4, NULL},
    {0x216, NULL, func_800C72EC, func_800C7310, NULL},
    {0x254, NULL, func_800C7290, NULL, NULL},
    {0x253, NULL, func_800C7230, NULL, NULL},
    {0x252, NULL, func_800C725C, NULL, NULL},
};

struct { u8 active; u8 padding[11]; } D_8011A904 BT_DATA(4, map_prop_actions, 0x64) = {1};
s16 D_8011A910[9] BT_DATA(4, map_prop_actions, 0x70) = {0x0, 0x0, 0x20, 0x1F, 0x64, 0x65, 0x66, 0x7E, 0x82};
