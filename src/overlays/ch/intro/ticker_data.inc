/* data_to_c.py: from asm/data/overlays/ch/intro/ticker.data.s */
void func_80105834(Actor *);
void func_8010A730();
void func_80107C2C();
struct TickerMusic D_80800830_chintroticker[15] BT_DATA(4, overlays_ch_intro_ticker, 0x0) = {
    {398, -1, 135, 0},  {396, 135, 136, 0}, {399, 136, 137, 0}, {400, 137, 138, 0},
    {382, 138, 139, 0}, {397, 139, 140, 0}, {404, -1, 142, 0},  {407, 142, 143, 0},
    {408, 143, 144, 0}, {409, 144, 145, 0}, {405, 145, 147, 0}, {403, 147, 148, 0},
    {402, 148, 149, 0}, {401, -1, 152, 0},  {406, 152, 153, 0}};
s32 D_808008A8_chintroticker[6] BT_DATA(4, overlays_ch_intro_ticker, 0x78) = {0,   0,   128,
                                                                              129, 130, 131};
s32 D_808008C0_chintroticker BT_DATA(4, overlays_ch_intro_ticker, 0x90) = 161;
IntroTickerMap D_808008C4_chintroticker[28] BT_DATA(4, overlays_ch_intro_ticker, 0x94) = {
    {161, 168}, {168, 162}, {162, 169}, {169, 163}, {163, 170}, {170, 164}, {164, 171},
    {171, 165}, {165, 172}, {172, 166}, {166, 167}, {167, -2},  {398, 396}, {396, 399},
    {399, 400}, {400, 382}, {382, 397}, {397, -3},  {404, 407}, {407, 408}, {408, 409},
    {409, 405}, {405, 403}, {403, 402}, {402, -4},  {401, 406}, {406, -5},  {395, -1}};
ActorData D_80800934_chintroticker[1] BT_DATA(4, overlays_ch_intro_ticker, 0x104) = {
    {709,
     884,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_808005AC_chintroticker,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8010A730,
     0,
     0,
     0,
     0,
     8,
     4,
     (void (*)(struct Actor *))func_808003BC_chintroticker,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_808002DC_chintroticker,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     514,
     0,
     0}};
