/* data_to_c.py: from asm/data/overlays/ch/captainblubber.data.s */
extern ActorAnimationEntry D_80801650_chcaptainblubber[];
void func_80101870();
void func_80107C2C();
ActorAnimationEntry D_80801650_chcaptainblubber[14] BT_DATA(4, overlays_ch_captainblubber, 0x0) = {
    {0.0f, 0, 0},        {9.5f, 0x159, 1},    {9.5f, 0x159, 1},     {9.5f, 0x159, 1},    {9.5f, 0x159, 1},
    {9.5f, 0x159, 1},    {1.2f, 0x1C0, 0x42}, {1.2f, 0x15A, 0x241}, {0.7f, 0x1BF, 0x41}, {1.2f, 0x15A, 0x42},
    {0.7f, 0x1BF, 0x41}, {1.2f, 0x15A, 0x41}, {3.5f, 0x17B, 0x142}, {2.0f, 0x16D, 0x142}};
s32 D_808016C0_chcaptainblubber[3] BT_DATA(4, overlays_ch_captainblubber, 0x70) = {1135607808, 0,
                                                                                   -1009483776};
f32 D_808016CC_chcaptainblubber[3] BT_DATA(4, overlays_ch_captainblubber, 0x7C) = {636.0f, 0.0f, -340.0f};
s32 D_808016D8_chcaptainblubber[4] BT_DATA(4, overlays_ch_captainblubber, 0x88) = {1133248512, 1123024896,
                                                                                   1126170624, 1125515264};
Times4 D_808016E8_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber,
                                           0x98) = {{0.72f, 0.775f, 0.83f, -1.0f}};
Times3 D_808016F8_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber, 0xA8) = {{0.24f, 0.7f, -1.0f}};
Times3 D_80801704_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber, 0xB4) = {{0.43f, 0.98f, -1.0f}};
Times3 D_80801710_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber, 0xC0) = {{0.42f, 0.92f, -1.0f}};
Times7 D_8080171C_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber,
                                           0xCC) = {{0.06f, 0.15f, 0.24f, 0.33f, 0.42f, 0.51f, -1.0f}};
Times3 D_80801738_chcaptainblubber BT_DATA(4, overlays_ch_captainblubber, 0xE8) = {{0.66f, 0.77f, -1.0f}};
s32 D_80801744_chcaptainblubber[10] BT_DATA(4, overlays_ch_captainblubber, 0xF4) = {
    1903049, 2818304, 25165858, 8388864, 33554944, 1376307, 3342361, 7, 2122852, 1350041600};
ActorData D_8080176C_chcaptainblubber[1] BT_DATA(4, overlays_ch_captainblubber, 0x11C) = {
    {300,
     660,
     1755,
     1,
     (void *)D_80801650_chcaptainblubber,
     0,
     (void (*)(struct Actor *))func_808001F0_chcaptainblubber,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     16,
     288,
     (void (*)(struct Actor *))func_808014C8_chcaptainblubber,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_808000CC_chcaptainblubber,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32256,
     1154,
     (void (*)(struct Actor *, long, long))func_80800580_chcaptainblubber,
     0}};
