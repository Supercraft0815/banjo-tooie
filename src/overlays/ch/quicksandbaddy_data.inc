/* data_to_c.py: from asm/data/overlays/ch/quicksandbaddy.data.s */
extern ActorAnimationEntry D_808012A0_chquicksandbaddy[];
void func_80105834(Actor *);
void func_80101870();
void func_80107C2C();
ActorAnimationEntry D_808012A0_chquicksandbaddy[8] BT_DATA(4, overlays_ch_quicksandbaddy, 0x0) = {
    {0.0f, 0, 0},        {0.0f, 0, 0}, {0.0f, 0, 0},        {0.0f, 0, 0},
    {4.5f, 0x1E4, 0x4A}, {0.0f, 0, 0}, {4.5f, 0x1E4, 0x4A}, {4.5f, 0x1E4, 0xA}};
u32 D_808012E0_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0x40) = {0x13049C, 0xA0100,
                                                                                   0x167530, 0};
u32 D_808012F0_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0x50) = {0x1305D1, 0xA0166,
                                                                                   0x167D00, 0};
u32 D_80801300_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0x60) = {0x13049E, 0xA0099,
                                                                                   0x1661A8, 0};
u32 D_80801310_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0x70) = {0x3E2E147B, 0x3E947AE1,
                                                                                   0x3EE147AE, 0xBF800000};
f32 D_80801320_chquicksandbaddy[10][2] BT_DATA(4, overlays_ch_quicksandbaddy, 0x80) = {
    {0.0f, 1.0f},  {0.4f, 0.95f}, {0.8f, 0.9f},  {1.2f, 0.85f}, {1.6f, 0.8f},
    {2.0f, 0.75f}, {2.4f, 0.7f},  {2.5f, -2.0f}, {2.8f, 0.65f}, {5.5f, -1.0f}};
s32 D_80801370_chquicksandbaddy[8] BT_DATA(4, overlays_ch_quicksandbaddy, 0xD0) = {
    1903067, 1445889, 2818688, 50331669, 4194496, 2228352, 8388992, 33554432};
u8 D_80801390_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0xF0) = {0, 0, 0, 140};
s32 D_80801394_chquicksandbaddy[16] BT_DATA(4, overlays_ch_quicksandbaddy, 0xF4) = {
    1903065,  1834008, -58982355, 19661200, 1445888, 2293790, 1376268, 15073323,
    67109888, 3080320, 8388608,   3342425,  153,     3276790, 7,       65536};
u8 D_808013D4_chquicksandbaddy[4] BT_DATA(4, overlays_ch_quicksandbaddy, 0x134) = {0, 0, 0, 255};
ActorData D_808013D8_chquicksandbaddy[1] BT_DATA(4, overlays_ch_quicksandbaddy, 0x138) = {
    {344,
     495,
     1646,
     1,
     (void *)D_808012A0_chquicksandbaddy,
     (void (*)(struct Actor *))func_80800140_chquicksandbaddy,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     524288000,
     0,
     0,
     0,
     0,
     33,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800000_chquicksandbaddy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     25602,
     0,
     0}};
