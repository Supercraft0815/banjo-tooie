/* data_to_c.py: from asm/data/overlays/ch/digger/bossbattery.data.s */
void func_80102EC0();
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
ActorData D_808002F0_chdiggerbossbattery BT_DATA(4, overlays_ch_digger_bossbattery, 0x0) = {
    344,
    1269,
    -1,
    1,
    0,
    (void (*)(struct Actor *))func_80800090_chdiggerbossbattery,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_801018A4,
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
    (void (*)(struct Actor *))func_8080000C_chdiggerbossbattery,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    1024,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80800170_chdiggerbossbattery, (void (*)(struct Actor *, long, long))func_80800170_chdiggerbossbattery),
    0};
DiggerBatteryConfig D_80800338_chdiggerbossbattery BT_DATA(4, overlays_ch_digger_bossbattery,
                                                           0x48) = {
    {19, 1463, 1, 200, 1000, 10, 358, 22, 32000, 0}, {0x909, 0x90A}};
