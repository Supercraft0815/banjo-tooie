/* data_to_c.py: from asm/data/overlays/ch/intro/text.data.s */
void func_80105834(Actor *);
void func_80107C2C();
struct IntroTextStyle D_808007A0_chintrotext[3] BT_DATA(4, overlays_ch_intro_text, 0x0) = {
    {0.4f, 2.4f, 0.6f, 25}, {0.4f, 2.4f, 0.6f, 25}, {2.5f, 3.5f, 2.5f, 20}};
ActorData D_808007D0_chintrotext[1] BT_DATA(4, overlays_ch_intro_text, 0x30) = {
    {789,
     944,
     -1,
     1,
     0,
     (void (*)(struct Actor *))func_80800154_chintrotext,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808003EC_chintrotext,
     0,
     0,
     0,
     0,
     2112,
     1028,
     (void (*)(struct Actor *))func_80800130_chintrotext,
     0,
     0,
     64,
     (void (*)(struct Actor *))func_8080000C_chintrotext,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     0,
     0}};
