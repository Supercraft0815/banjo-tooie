/* data_to_c.py: from asm/data/overlays/ch/klungo/doors.data.s */
void func_80105834(Actor *);
void func_80101870();
void func_80108ED0();
void func_80107C2C();
DoorConfig D_80800490_chklungodoors[3] BT_DATA(4, overlays_ch_klungo_doors, 0x0) = {
    {321, 500, 1.5f, {0x7AE, 0x7AE}, 0x318, 0, 2},
    {347, 500, 1.25f, {0x7AE, 0x7AE}, 0x319, 0, 2},
    {350, 350, 1.0f, {0x94D, 0x94C}, 0x31A, 1, 0xB}};
ActorData D_808004C0_chklungodoors[1] BT_DATA(4, overlays_ch_klungo_doors, 0x30) = {
    {172,
     1055,
     1966,
     4,
     0,
     (void (*)(struct Actor *))func_80800234_chklungodoors,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     3072,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800018_chklungodoors,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     11266,
     (void (*)(struct Actor *, long, long))func_80800300_chklungodoors,
     0}};
ActorData D_80800508_chklungodoors[1] BT_DATA(4, overlays_ch_klungo_doors, 0x78) = {
    {172,
     1056,
     1966,
     1,
     0,
     (void (*)(struct Actor *))func_80800234_chklungodoors,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     3072,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800018_chklungodoors,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     11266,
     (void (*)(struct Actor *, long, long))func_80800300_chklungodoors,
     0}};
u32 D_80800550_chklungodoors[8] BT_DATA(4, overlays_ch_klungo_doors, 0xC0) = {
    0x1305B7, 0x100C8, 0x7D0000A, 0x1660016, 0x7D000000, 0, 0, 0};
