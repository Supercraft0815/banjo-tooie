/* data_to_c.py: from asm/data/overlays/ch/swit.data.s */
void func_80108F08();
BtFnWord D_80800DB0_chswitch[5] BT_DATA(4, overlays_ch_swit, 0x0) = {
    (BtFnWord)func_80800024_chswitch, 0, (BtFnWord)func_808000B8_chswitch, (BtFnWord)func_80108F08,
    0};
BtFnWord D_80800DC4_chswitch[5] BT_DATA(4, overlays_ch_swit,
                                        0x14) = {(BtFnWord)func_808002B4_chswitch, 0, 0, 0, 0};
BtFnWord D_80800DD8_chswitch[5] BT_DATA(4, overlays_ch_swit,
                                        0x28) = {(BtFnWord)func_8080012C_chswitch, 0, 0, 0, 0};
