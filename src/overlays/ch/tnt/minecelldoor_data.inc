/* data_to_c.py: from asm/data/overlays/ch/tnt/minecelldoor.data.s */
void func_80102EC0();
void func_80105834(Actor *);
void func_80101870();
void func_80107C2C();
TntDoorData D_80800140_chtntminecelldoor BT_DATA(4, overlays_ch_tnt_minecelldoor, 0x0) = {
    {172,
     331,
     1707,
     1,
     0,
     (void (*)(struct Actor *))func_80102EC0,
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
     (void (*)(struct Actor *))func_8080000C_chtntminecelldoor,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     11266,
     (void (*)(struct Actor *, long, long))func_80800034_chtntminecelldoor,
     0},
    {784, 29, 2525, 43,    2048,  2560, 34,  512, 640, 1536, 2048, 21, 0,   38, 25, 0, 7, 45,
     50,  80, 32,   -8537, 29120, 10,   -50, 25,  -50, 50,   40,   50, 794, 0,  0,  0, 0, 0}};
