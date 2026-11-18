/* data_to_c.py: from asm/data/overlays/ch/squits.data.s */
void func_80105834(Actor *);
void func_80101870();
void func_80107C2C();
SquitsSound D_808005B0_chsquits[4] BT_DATA(4, overlays_ch_squits,
                                           0x0) = {{1067, 22000, 0.8f, 0.3f},
                                                   {1067, 22000, 0.6f, 0.8f},
                                                   {1367, 22000, 1.2f, 3.0f},
                                                   {1252, 22000, 1.3f, 4.2f}};
SquitsSound D_808005E0_chsquits[2] BT_DATA(4, overlays_ch_squits, 0x30) = {
    {1067, 22000, 0.65f, 0.3f}, {1252, 22000, 1.3f, 1.0f}};
SquitsSound D_808005F8_chsquits[3] BT_DATA(4, overlays_ch_squits, 0x48) = {
    {1369, 22000, 1.4f, 0.0f}, {1067, 22000, 0.7f, 0.6f}, {1067, 22000, 0.4f, 3.8f}};
SquitsSound D_8080061C_chsquits[10] BT_DATA(4, overlays_ch_squits, 0x6C) = {
    {1067, 22000, 1.6f, 0.2f}, {1067, 22000, 1.4f, 0.4f},  {1067, 22000, 1.2f, 0.6f},
    {1067, 22000, 1.6f, 0.8f}, {1067, 22000, 1.7f, 1.0f},  {1067, 22000, 1.8f, 1.2f},
    {1067, 22000, 1.2f, 1.4f}, {1067, 32000, 0.35f, 1.6f}, {1033, 22000, 0.85f, 2.4f},
    {1252, 22000, 1.3f, 3.2f}};
SquitsSequence D_80800694_chsquits[4] BT_DATA(4, overlays_ch_squits, 0xE4) = {
    {(SquitsSound *)D_808005B0_chsquits, 4, 8.0f},
    {(SquitsSound *)D_808005E0_chsquits, 2, 6.0f},
    {(SquitsSound *)D_808005F8_chsquits, 3, 6.0f},
    {(SquitsSound *)D_8080061C_chsquits, 10, 8.0f}};
s16 D_808006C4_chsquits[10] BT_DATA(4, overlays_ch_squits, 0x114) = {4970, 4971, 4972, 4973, 4974,
                                                                     4975, 4983, 4984, 4985, 4986};
ActorData D_808006D8_chsquits[1] BT_DATA(4, overlays_ch_squits, 0x128) = {
    {344,
     1257,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80800054_chsquits,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chsquits,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1538,
     (void (*)(struct Actor *, long, long))func_80800108_chsquits,
     0}};
s16 D_80800720_chsquits[7] BT_DATA(4, overlays_ch_squits, 0x170) = {0x21,  0x1e,  0x1d, 0x1,
                                                                    0x1f4, 0x5dc, 0};
