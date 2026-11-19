/* data_to_c.py: from asm/data/overlays/ch/uffycont.data.s */
void func_80105834(Actor *);
void func_80107C2C();
ChuffyStations D_80800B20_chchuffycont BT_DATA(4, overlays_ch_uffycont,
                                               0x0) = {{{{215, 1261, 1641, -1, 63},
                                                         {236, 1262, 1642, 150, 82},
                                                         {341, 1267, 1740, 1027, 125},
                                                         {276, 1264, 1706, 356, 87},
                                                         {258, 1263, 1705, 355, 163},
                                                         {297, 1266, 1724, 464, 170},
                                                         {298, 1265, 1723, 463, 71}},
                                                        0,
                                                        {19, 1257, 22, 20000, 1, 500, 5000, 0}}};
f32 D_80800B78_chchuffycont[3] BT_DATA(4, overlays_ch_uffycont, 0x58) = {0.0f, 0.0f, -1500.0f};
ActorData D_80800B84_chchuffycont BT_DATA(4, overlays_ch_uffycont, 0x64) = {
    518,
    678,
    2307,
    1,
    0,
    (void (*)(struct Actor *))func_808002C4_chchuffycont,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_80800768_chchuffycont,
    0,
    0,
    0,
    0,
    10,
    6148,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80800440_chchuffycont,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    1026,
    (void (*)(struct Actor *, long, long))func_808001F8_chchuffycont,
    0};
