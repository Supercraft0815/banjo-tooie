/* A matching controller sequence latches the flag during the first 600 input polls. */
s32 D_8011A3F0 BT_DATA(4, controller_sequence, 0) = 0;
s32 D_8011A3F4 BT_DATA(4, controller_sequence, 4) = 600;
s32 D_8011A3F8[8] BT_DATA(4, controller_sequence, 8) = {2, 9, 1, 5, 0, 1, 6, -1};
s32 D_8011A418 BT_DATA(4, controller_sequence, 40) = 0;
