/* data_to_c.py: from asm/data/overlays/ch/octopus.data.s */
extern ActorAnimationEntry D_808008CC_choctopus[];
void func_80105834(Actor *);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
s16 D_808008C0_choctopus[6] BT_DATA(4, overlays_ch_octopus, 0x0) = {19, 1323, 2, 24, 0, 0};
ActorAnimationEntry D_808008CC_choctopus[5] BT_DATA(4, overlays_ch_octopus, 0xC) = {
    {0.0f, 0, 0}, {1.0f, 0x172, 1}, {1.0f, 0x172, 1}, {1.0f, 0x172, 0x20}, {1.0f, 0x172, 1}};
ActorData D_808008F4_choctopus[1] BT_DATA(4, overlays_ch_octopus, 0x34) = {
    {753,
     862,
     1744,
     1,
     (void *)D_808008CC_choctopus,
     (void (*)(struct Actor *))func_80800054_choctopus,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     5500,
     0,
     0,
     0,
     0,
     1320,
     (void (*)(struct Actor *))func_80800210_choctopus,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_choctopus,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32720,
     9218,
     (void (*)(struct Actor *, long, long))func_80800348_choctopus,
     0}};
s16 D_8080093C_choctopus[10] BT_DATA(4, overlays_ch_octopus, 0x7C) = {19,    1580, 10,   102,  22,
                                                                      30000, 1,    1500, 4500, 0};
s32 D_80800950_choctopus[4][3] BT_DATA(4, overlays_ch_octopus, 0x90) = {
    {52, 131, 66}, {59, 178, 158}, {76, 125, 150}, {113, 117, 122}};
s32 D_80800980_choctopus[3] BT_DATA(4, overlays_ch_octopus, 0xC0) = {32, 128, 255};
s16 D_8080098C_choctopus[6] BT_DATA(4, overlays_ch_octopus, 0xCC) = {19, 1188, 2, 10, 204, 0};
BtFnWord D_80800998_choctopus[4] BT_DATA(4, overlays_ch_octopus,
                                         0xD8) = {0, 0, 0, (BtFnWord)func_80800540_choctopus};
