/* Three Evil Mumbo actor descriptors and their shared audio position. */
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80101870(Actor *, void *);

ActorData D_808044F0_chevilmumbo[1] BT_DATA(4, tail_ch_evilmumbo, 0x0) = {{
    92, 893, 1693, 1, NULL,
    (void (*)(Actor *))func_808030AC_chevilmumbo, (void (*)(Actor *))func_80105834, (void (*)(s32, s32))func_808035A8_chevilmumbo,
    0, 0, 0, 0, 2, 4100,
    (void (*)(Actor *))func_80803358_chevilmumbo, (BtIntPtr)func_80108ED0, 0, 0,
    (void (*)(Actor *))func_80803388_chevilmumbo,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, s32, void *, s32, void *))func_80107C2C),
    0, 0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808034C8_chevilmumbo, (void (*)(Actor *, s32, s32))func_808034C8_chevilmumbo), 0
 }};

f32 D_80804538_chevilmumbo[3] BT_DATA(4, tail_ch_evilmumbo, 0x48) = {661.0f, 0.0f, 3.1e+02f};

ActorData D_80804544_chevilmumbo[1] BT_DATA(4, tail_ch_evilmumbo, 0x54) = {{
    93, 894, 2083, 1, NULL,
    (void (*)(Actor *))func_80803700_chevilmumbo, (void (*)(Actor *))func_80105834, (void (*)(s32, s32))func_80101870,
    0, 0, 0, 0, 0, 3076,
    (void (*)(Actor *))func_80803918_chevilmumbo, 0, 0, 0,
    (void (*)(Actor *))func_80803920_chevilmumbo,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, s32, void *, s32, void *))func_80107C2C),
    -32768, 2,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_8080395C_chevilmumbo, (void (*)(Actor *, s32, s32))func_8080395C_chevilmumbo), 0
 }};

ActorData D_8080458C_chevilmumbo[1] BT_DATA(4, tail_ch_evilmumbo, 0x9C) = {{
    344, 896, 1718, 1, NULL,
    (void (*)(Actor *))func_80803B50_chevilmumbo, (void (*)(Actor *))func_80105834, (void (*)(s32, s32))func_8080398C_chevilmumbo,
    0x07D00000, 0, 0, 0, 2, 4,
    (void (*)(Actor *))func_80803B48_chevilmumbo, 0, 0, 0,
    (void (*)(Actor *))func_80803B28_chevilmumbo,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, s32, void *, s32, void *))func_80107C2C),
    -32768, 2,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80803C88_chevilmumbo, (void (*)(Actor *, s32, s32))func_80803C88_chevilmumbo), 0
 }};
