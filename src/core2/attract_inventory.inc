/* Attract mode initializes seven inventory counters and sets two game flags. */
u8 D_8011A470[7] BT_DATA(4, attract_inventory, 0) = {0x40, 0x41, 0x42, 0x43, 0x44, 0x46, 0x47};
s16 D_8011A478[2] BT_DATA(4, attract_inventory, 8) = {0x035, 0x59C};
