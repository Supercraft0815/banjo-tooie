/* Jolly Roger actors, conversation modes, synchronized sounds and particle commands. */
void _chdoor_entrypoint_0(BtIntPtr);
OSThread *func_80108ED0(void);

ActorData D_808013A0_chjollyroger[1] BT_DATA(4, tail_ch_jollyroger, 0x0) = {{
    756, 865, 1752, 1, (void *)D_80801318_chjollyroger,
    (void (*)(Actor *))func_80800930_chjollyroger, (void (*)(Actor *))func_80800930_chjollyroger, (void (*)(s32, s32))func_80101870,
    0, 0x3FC00000, 0, 0, 4, 288,
    (void (*)(Actor *))func_80800DB8_chjollyroger, 0, 0, 0,
    (void (*)(Actor *))func_80800AEC_chjollyroger,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, s32, void *, s32, void *))func_80107C2C),
    -32768, 1282,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80800BA0_chjollyroger, (void (*)(Actor *, s32, s32))func_80800BA0_chjollyroger), 0
 }};

ActorData D_808013E8_chjollyroger[1] BT_DATA(4, tail_ch_jollyroger, 0x48) = {{
    412, 874, 1891, 1, NULL,
    (void (*)(Actor *))_chdoor_entrypoint_0, (void (*)(Actor *))func_80105834, (void (*)(s32, s32))func_80101870,
    0, 0, 65, 0, 0, 0,
    NULL, (BtIntPtr)func_80108ED0, 0, 0,
    (void (*)(Actor *))func_8080103C_chjollyroger,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, s32, void *, s32, void *))func_80107C2C),
    -32760, 11264,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808010A0_chjollyroger, (void (*)(Actor *, s32, s32))func_808010A0_chjollyroger), 0
 }};

s16 D_80801430_chjollyroger[6] BT_DATA(4, tail_ch_jollyroger, 0x90) = {19, 1105, 13, 243, 268, 0};

f32 D_8080143C_chjollyroger[3] BT_DATA(4, tail_ch_jollyroger, 0x9C) = {0.11f, 0.95f, -1.0f};

subaddiedialog_UnkStruct2 D_80801448_chjollyroger BT_DATA(4, tail_ch_jollyroger, 0xA8) = {195, 0, 500, 85, 0, 14, 6, 60, 0};

subaddiedialog_UnkStruct2 D_80801458_chjollyroger BT_DATA(4, tail_ch_jollyroger, 0xB8) = {196, 0, 580, 86, 0, 14, 6, 60, 6};

s16 jollyRogerParticleCommands[32] BT_DATA(4, tail_ch_jollyroger, 0xC8) = {
    784,
    29, 2525,
    43, 2048, 2560,
    34, 512, 640, 1536, 2048,
    21, 0, 38,
    25, 0, 7,
    45, 50, 80,
    32, -8537, 29120,
    10, -50, 25, -50, 50, 40, 50,
    794,
    0,
};
