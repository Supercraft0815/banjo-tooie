/* data_to_c.py: from asm/data/overlays/bs/firstp.data.s */
void _bsfirstp_entrypoint_26();
void _bsdrone_entrypoint_3();
f32 D_8080A5B0_bsfirstp[2][4] BT_DATA(4, overlays_bs_firstp, 0x0) = {{0.0f, -0.1f, -0.1f, 0.0f},
                                                                     {0.0f, -0.2f, -0.15f, 30.0f}};
f32 D_8080A5D0_bsfirstp[2][12] BT_DATA(4, overlays_bs_firstp, 0x20) = {
    {38.0f, 14.25f, 38.0f, 14.25f, 8.0f, 7.0f, 114.0f, 85.5f, 37.620003f, 28.215002f, 8.0f, 7.0f},
    {76.0f, 14.25f, 76.0f, 14.25f, 8.0f, 7.0f, 114.0f, 85.5f, 37.620003f, 28.215002f, 8.0f, 7.0f}};
s16 D_8080A630_bsfirstp[8] BT_DATA(4, overlays_bs_firstp, 0x80) = {19, 1131,  10, 358,
                                                                   22, 10000, 0,  0};
s16 D_8080A640_bsfirstp[8] BT_DATA(4, overlays_bs_firstp, 0x90) = {19, 1132,  10, 358,
                                                                   22, 10000, 0,  0};
f32 D_8080A650_bsfirstp[6][5] BT_DATA(4, overlays_bs_firstp, 0xA0) = {
    {200.0f, 100.0f, -1200.0f, 0.125f, 1.0f}, {200.0f, 100.0f, -1200.0f, 0.1f, 0.5f},
    {0.0f, 100.0f, -1200.0f, 0.0f, 0.0f},     {200.0f, 300.0f, -1200.0f, 0.1f, 0.5f},
    {300.0f, 300.0f, -1200.0f, 0.2f, 0.5f},   {500.0f, 510.0f, -1200.0f, 0.3f, 0.5f}};
FirstpConfig D_8080A6C8_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x118) = {
    6.667f, 30.0f,     40.0f, 0.0f, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0, 0, 0},
    0,      {0, 0, 0}, 0,     0.0f, {0.0f, 0.0f},       {0.0f, 0.0f},       1.0f,
    0.0f};
FirstpConfig D_8080A714_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x164) = {
    10.0f, 60.0f,     80.0f, 0.009f, {-0.105f, -0.5f, -1.333f}, {22.5f, 0.0f, 0.0f}, {0, 0, 0},
    1,     {0, 0, 0}, 0x2C,  0.33f,  {-30.0f, 40.0f},           {-50.0f, 50.0f},     0.9f,
    60.0f};
FirstpConfig D_8080A760_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x1B0) = {
    10.0f, 60.0f,     80.0f, 0.01f, {-0.08f, -0.59f, -1.4f}, {20.0f, 6.0f, 0.0f}, {0, 0, 0},
    1,     {0, 0, 0}, 0x3A,  0.25f, {-30.0f, 25.0f},         {-50.0f, 60.0f},     0.9f,
    60.0f};
FirstpConfig D_8080A7AC_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x1FC) = {
    10.0f, 60.0f,     45.0f, 0.008f, {-0.08f, -0.59f, -1.4f}, {20.0f, 6.0f, 0.0f}, {0, 0, 0},
    1,     {0, 0, 0}, 0x3A,  0.25f,  {-30.0f, 25.0f},         {-50.0f, 60.0f},     0.7f,
    35.0f};
FirstpConfig D_8080A7F8_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x248) = {
    10.0f, 60.0f,     90.0f, 0.0067f, {0.07f, -0.53f, -1.333f}, {17.5f, 6.0f, 0.0f}, {0, 0, 0},
    1,     {0, 0, 0}, 0x6A,  0.33f,   {-30.0f, 45.0f},          {-60.0f, 60.0f},     1.0f,
    70.0f};
FirstpConfig D_8080A844_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x294) = {
    10.0f, 40.0f,     105.0f, 0.01f, {-0.11f, -0.5f, -1.6f}, {17.5f, 6.0f, 0.0f}, {0, 0, 0},
    1,     {0, 0, 0}, 0x2C,   0.25f, {-45.0f, 30.0f},        {-60.0f, 63.0f},     0.8f,
    80.0f};
FirstpConfig *D_8080A890_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0x2E0) = {
    &D_8080A6C8_bsfirstp, &D_8080A714_bsfirstp, &D_8080A760_bsfirstp,
    &D_8080A7AC_bsfirstp, &D_8080A7F8_bsfirstp, &D_8080A844_bsfirstp};
f32 D_8080A8A8_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x2F8) = {
    20.0f,    0.0f,  20.0f,  40.0f, 80.0f,  25.0f,   60.0f,   30.0f, -2700.0f,
    -5400.0f, 25.0f, 800.0f, 0.25f, 800.0f, 1250.0f, 5000.0f, 0.4f,  0.0f,
    0.0f,     0.0f,  0.0f,   70.0f, -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f, 180.0f, 90.0f, 0.4f,   0.225f,  0.05f,   0.225f};
f32 D_8080A934_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x384) = {
    32.0f,    28.0f,   30.0f,    55.0f, 100.0f, 70.0f,   150.0f,  75.0f, -2700.0f,
    -5400.0f, 25.0f,   600.0f,   0.25f, 600.0f, 1000.0f, 3000.0f, 0.4f,  150.0f,
    3000.0f,  5000.0f, -5000.0f, 70.0f, -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f,   180.0f,   90.0f, 0.4f,   0.225f,  0.05f,   0.225f};
f32 D_8080A9C0_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x410) = {
    38.0f,    32.0f,   30.0f,    55.0f, 100.0f, 60.0f,   150.0f,  75.0f, -2700.0f,
    -5400.0f, 25.0f,   600.0f,   0.25f, 600.0f, 1000.0f, 3000.0f, 0.4f,  150.0f,
    3000.0f,  5000.0f, -5000.0f, 70.0f, -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f,   180.0f,   90.0f, 0.4f,   0.225f,  0.05f,   0.225f};
f32 D_8080AA4C_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x49C) = {
    20.0f,    20.0f,   20.0f,    40.0f,  60.0f,  50.0f,   120.0f,  60.0f, -2700.0f,
    -5400.0f, 25.0f,   800.0f,   0.25f,  800.0f, 1000.0f, 4000.0f, 0.4f,  150.0f,
    3000.0f,  5000.0f, -5000.0f, 70.0f,  -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f,   240.0f,   120.0f, 0.4f,   0.225f,  0.05f,   0.225f};
f32 D_8080AAD8_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x528) = {
    44.0f,    36.0f,   30.0f,    55.0f, 120.0f, 60.0f,   150.0f,  75.0f, -2700.0f,
    -5400.0f, 25.0f,   600.0f,   0.25f, 600.0f, 1000.0f, 3000.0f, 0.4f,  150.0f,
    3000.0f,  5000.0f, -5000.0f, 70.0f, -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f,   180.0f,   90.0f, 0.4f,   0.225f,  0.05f,   0.225f};
f32 D_8080AB64_bsfirstp[35] BT_DATA(4, overlays_bs_firstp, 0x5B4) = {
    65.0f,    55.0f,   40.0f,    80.0f, 150.0f, 100.0f,  140.0f,  70.0f, -2700.0f,
    -5400.0f, 25.0f,   400.0f,   0.25f, 400.0f, 1000.0f, 2000.0f, 0.4f,  150.0f,
    300.0f,   5000.0f, -5000.0f, 70.0f, -45.0f, 60.0f,   60.0f,   0.25f, 0.25f,
    0.15f,    0.15f,   120.0f,   60.0f, 0.4f,   0.225f,  0.05f,   0.225f};
FirstpEquipment D_8080ABF0_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x640) = {
    {D_8080A8A8_bsfirstp, D_8080A934_bsfirstp, D_8080A9C0_bsfirstp, D_8080AA4C_bsfirstp,
     D_8080AAD8_bsfirstp, D_8080AB64_bsfirstp},
    {8, 1, 0, 8, 0, 8, 1, 0, 8, 0, 4, 1, 0, 4, 0, 8, 1, 0, 8, 0, 0x10, 2, 0, 0x10, 0, 0, 0, 0}};
FirstpEggConfig D_8080AC24_bsfirstp[7] BT_DATA(4, overlays_bs_firstp, 0x674) = {
    {0, 7500.0f, 0.1f, 0.2f},     {0, 5000.0f, 0.35f, 0.7f}, {0, 5000.0f, 0.2f, 0.4f},
    {1, 3000.0f, 0.2f, 0.4f},     {1, 3000.0f, 1.0f, 1.0f},  {1, 3000.0f, 0.35f, 0.7f},
    {0, 11250.0f, 0.075f, 0.075f}};
FirstpScores D_8080AC94_bsfirstp BT_DATA(4, overlays_bs_firstp, 0x6E4) = {
    {{{0x30, 0x30}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
     {{0, 0x64}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0xFF}},
     {{0, 0x64}, {0, 0x32}, {0, 0x32}, {0, 0x19}, {0, 0xA}, {0, 0xA}, {1, 0xFF}},
     {{0, 0x64}, {0, 0x32}, {0, 0x32}, {0, 0}, {0, 0}, {0, 0}, {1, 0xFF}},
     {{0, 0x64}, {0, 0x32}, {0, 0}, {0, 0}, {0, 0}, {0, 0xA}, {1, 0xFF}},
     {{0, 0x64}, {0, 0}, {0, 0x32}, {0, 0}, {0, 0xA}, {0, 0}, {1, 0xFF}},
     {{0, 0x64}, {0, 0}, {0, 0x32}, {0, 0x19}, {0, 0}, {0, 0}, {1, 0xFF}}},
    {0, 0}};
Entry D_8080ACF8_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0x748) = {
    {{0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0}},
    {{0x7664, 0x4332, 0x2552, 0x2111, 0x1533, 0x4000, 0}},
    {{0x7223, 0x3332, 0x2312, 0x2111, 0x1133, 0x2000, 0}},
    {{0x7666, 0x6112, 0x2212, 0x2111, 0x1111, 0x2000, 0}},
    {{0x7555, 0x5113, 0x3313, 0x3111, 0x1111, 0x3000, 0}},
    {{0x7444, 0x4113, 0x3313, 0x3111, 0x1111, 0x3000, 0}}};
Entry D_8080AD4C_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0x79C) = {
    {{0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0}},
    {{0x7661, 0x1115, 0x5344, 0x3232, 0x2423, 0x5000, 0}},
    {{0x7331, 0x1112, 0x2233, 0x3132, 0x2213, 0x2000, 0}},
    {{0x7661, 0x1112, 0x2166, 0x2121, 0x1112, 0x2000, 0}},
    {{0x7551, 0x1113, 0x3155, 0x3131, 0x1113, 0x3000, 0}},
    {{0x7441, 0x1113, 0x3144, 0x3131, 0x1113, 0x3000, 0}}};
Entry D_8080ADA0_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0x7F0) = {
    {{0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0}},
    {{0x7556, 0x6344, 0x5211, 0x1332, 0x2412, 0x3000, 0}},
    {{0x7332, 0x2322, 0x3311, 0x1112, 0x2313, 0x2000, 0}},
    {{0x7226, 0x6111, 0x6211, 0x6112, 0x2112, 0x1000, 0}},
    {{0x7335, 0x5111, 0x5311, 0x5113, 0x3113, 0x1000, 0}},
    {{0x7334, 0x4111, 0x4311, 0x4113, 0x3113, 0x1000, 0}}};
s16 D_8080ADF4_bsfirstp[5][4][2] BT_DATA(4, overlays_bs_firstp, 0x844) = {
    {{2434, 3130}, {2434, 3131}, {2434, 3132}, {2434, 3133}},
    {{2436, 3138}, {2436, 3139}, {2436, 3140}, {2436, 3141}},
    {{2438, 3146}, {2438, 3147}, {2438, 3148}, {2438, 3149}},
    {{2440, 3154}, {2440, 3155}, {2440, 3156}, {2440, 3157}},
    {{2445, 3158}, {2445, 3159}, {2445, 3160}, {2445, 3161}}};
s32 D_8080AE44_bsfirstp[5][4][2] BT_DATA(4, overlays_bs_firstp, 0x894) = {
    {{2435, 3134}, {2435, 3135}, {2435, 3136}, {2435, 3137}},
    {{2437, 3142}, {2437, 3143}, {2437, 3144}, {2437, 3145}},
    {{2439, 3150}, {2439, 3151}, {2439, 3152}, {2439, 3153}},
    {{2441, 0}, {2442, 0}, {2443, 0}, {2444, 0}},
    {{2446, 0}, {2447, 0}, {2448, 0}, {2449, 0}}};
FirstpAnimation D_8080AEE4_bsfirstp[10] BT_DATA(4, overlays_bs_firstp, 0x934) = {
    {620, 3, 7.5f}, {792, 0, 4.0f}, {793, 0, 2.9f}, {620, 3, 1.0f}, {793, 0, 2.9f},
    {620, 3, 1.0f}, {793, 0, 2.9f}, {792, 0, 4.0f}, {620, 3, 5.0f}, {0, 1, 0.0f}};
FirstpAnimation D_8080AF34_bsfirstp[3] BT_DATA(4, overlays_bs_firstp, 0x984) = {
    {1151, 3, 7.5f}, {1174, 0, 8.0f}, {0, 1, 0.0f}};
FirstpAnimation D_8080AF4C_bsfirstp[3] BT_DATA(4, overlays_bs_firstp, 0x99C) = {
    {1257, 3, 7.5f}, {1258, 0, 8.0f}, {0, 1, 0.0f}};
FirstpAnimation D_8080AF64_bsfirstp[10] BT_DATA(4, overlays_bs_firstp, 0x9B4) = {
    {1234, 3, 7.5f}, {1233, 0, 4.0f}, {1234, 0, 2.9f}, {1234, 3, 1.0f}, {1234, 0, 2.9f},
    {1234, 3, 1.0f}, {1234, 0, 2.9f}, {1233, 0, 4.0f}, {1234, 3, 5.0f}, {0, 1, 0.0f}};
FirstpAnimation *D_8080AFB4_bsfirstp[6] BT_DATA(4, overlays_bs_firstp,
                                                0xA04) = {0,
                                                          D_8080AEE4_bsfirstp,
                                                          D_8080AF34_bsfirstp,
                                                          D_8080AF34_bsfirstp,
                                                          D_8080AF4C_bsfirstp,
                                                          D_8080AF64_bsfirstp};
FirstpAnimation D_8080AFCC_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0xA1C) = {
    {173, 0, 7.5f},   {626, 0, 1.0f},  {1143, 0, 6.41f},
    {1143, 0, 6.41f}, {1250, 0, 4.8f}, {1238, 0, 3.0f}};
f32 D_8080AFFC_bsfirstp[6][2] BT_DATA(4, overlays_bs_firstp, 0xA4C) = {
    {0.05f, 0.45f}, {0.05f, 0.47f}, {0.05f, 0.47f}, {0.05f, 0.47f}, {0.05f, 0.47f}, {0.05f, 0.47f}};
s16 D_8080B02C_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0xA7C) = {0, 620, 1151, 1151, 1257, 1232};
FirstpAnimationScale D_8080B038_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0xA88) = {
    {167, 0, 1.0f, 0.54f}, {625, 0, 2.0f, 0.6f},  {1144, 0, 2.0f, 0.6f},
    {1144, 0, 2.0f, 0.6f}, {1251, 0, 2.0f, 0.6f}, {1239, 0, 2.0f, 0.6f}};
FirstpAnimationScale D_8080B080_bsfirstp[6] BT_DATA(4, overlays_bs_firstp, 0xAD0) = {
    {166, 0, 0.54f, 0.35f}, {624, 0, 1.0f, 0.44f},  {1145, 0, 1.0f, 0.44f},
    {1145, 0, 1.0f, 0.44f}, {1249, 0, 1.0f, 0.44f}, {1237, 0, 1.0f, 0.44f}};
FirstpAnimation D_8080B0C8_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xB18) = {
    {629, 0, 0.9f}, {1150, 0, 0.64f}, {1150, 0, 0.64f}, {1256, 0, 1.0f}, {1231, 0, 0.9f}};
FirstpAnimation D_8080B0F0_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xB40) = {
    {627, 0, 0.8f}, {1146, 0, 1.25f}, {1146, 0, 1.25f}, {1246, 0, 0.5f}, {1240, 0, 0.8f}};
FirstpAnimation D_8080B118_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xB68) = {
    {1285, 0, 1.2f}, {1341, 0, 1.9f}, {1341, 0, 1.9f}, {1287, 0, 1.5f}, {1283, 0, 1.9f}};
FirstpAnimation D_8080B140_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xB90) = {
    {628, 0, 2.0f}, {1147, 0, 2.29f}, {1147, 0, 2.29f}, {1252, 0, 2.6f}, {1241, 0, 2.0f}};
FirstpAnimation D_8080B168_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xBB8) = {
    {1286, 0, 0.7f}, {1342, 0, 0.7f}, {1342, 0, 0.7f}, {1288, 0, 0.7f}, {1284, 0, 0.9f}};
FirstpAnimation D_8080B190_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xBE0) = {
    {794, 0, 1.1f}, {1148, 0, 2.2f}, {1148, 0, 2.2f}, {1253, 0, 1.2f}, {1242, 0, 1.1f}};
FirstpAnimation D_8080B1B8_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xC08) = {
    {620, 0, 1.0f}, {1151, 0, 1.0f}, {1151, 0, 1.0f}, {1257, 0, 1.0f}, {1232, 0, 1.0f}};
FirstpAnimation D_8080B1E0_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xC30) = {
    {788, 0, 1.0f}, {1186, 0, 1.0f}, {1186, 0, 1.0f}, {1248, 0, 1.0f}, {1236, 0, 1.0f}};
FirstpAnimation D_8080B208_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xC58) = {
    {621, 0, 1.0f}, {1175, 0, 1.0f}, {1175, 0, 1.0f}, {1259, 0, 1.0f}, {1228, 0, 1.0f}};
FirstpAnimation D_8080B230_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xC80) = {
    {789, 0, 0.9f}, {1187, 0, 1.0f}, {1187, 0, 1.0f}, {1247, 0, 1.0f}, {1235, 0, 0.9f}};
FirstpAnimation D_8080B258_bsfirstp[5] BT_DATA(4, overlays_bs_firstp, 0xCA8) = {
    {622, 0, 0.4f}, {1149, 0, 0.25f}, {1149, 0, 0.25f}, {1254, 0, 0.4f}, {1229, 0, 0.4f}};
FirstpSound D_8080B280_bsfirstp[12] BT_DATA(4, overlays_bs_firstp, 0xCD0) = {
    {1189, 32767, 1.0f}, {1086, 32767, 1.0f}, {1424, 32767, 1.0f}, {1431, 32767, 1.0f},
    {1425, 32767, 1.0f}, {1423, 32767, 1.0f}, {1423, 32767, 1.0f}, {1086, 32767, 1.0f},
    {1066, 22000, 1.0f}, {1441, 22000, 1.0f}, {0, 0, 0.0f},        {0, 0, 0.0f}};
FirstpSound D_8080B2E0_bsfirstp[12] BT_DATA(4, overlays_bs_firstp, 0xD30) = {
    {1189, 32767, 1.25f}, {1086, 32767, 1.33f}, {1424, 32767, 1.25f}, {1431, 32767, 1.25f},
    {1425, 32767, 1.25f}, {1423, 32767, 1.25f}, {1423, 32767, 1.25f}, {1086, 32767, 1.25f},
    {1297, 22000, 1.0f},  {1441, 22000, 1.15f}, {1295, 22000, 1.0f},  {1294, 22000, 1.0f}};
FirstpSound D_8080B340_bsfirstp[12] BT_DATA(4, overlays_bs_firstp, 0xD90) = {
    {1189, 32767, 1.25f}, {1086, 32767, 1.33f}, {1424, 32767, 1.25f}, {1431, 32767, 1.25f},
    {1425, 32767, 1.25f}, {1423, 32767, 1.25f}, {1423, 32767, 1.25f}, {1086, 32767, 1.25f},
    {1266, 22000, 1.0f},  {1441, 22000, 1.25f}, {1266, 32767, 1.5f},  {1266, 32767, 0.7f}};
FirstpSound D_8080B3A0_bsfirstp[12] BT_DATA(4, overlays_bs_firstp, 0xDF0) = {
    {1189, 32767, 1.25f}, {1086, 32767, 1.33f}, {1424, 32767, 1.25f}, {1431, 32767, 1.25f},
    {1425, 32767, 1.25f}, {1423, 32767, 1.25f}, {1423, 32767, 1.25f}, {1086, 32767, 1.25f},
    {1676, 32767, 1.0f},  {1441, 22000, 1.3f},  {1677, 32767, 1.0f},  {1667, 32767, 0.8f}};
FirstpSoundSets D_8080B400_bsfirstp BT_DATA(4, overlays_bs_firstp, 0xE50) = {
    {{1189, 32767, 1.25f},
     {1086, 32767, 1.33f},
     {1424, 32767, 1.25f},
     {1431, 32767, 1.25f},
     {1425, 32767, 1.25f},
     {1423, 32767, 1.25f},
     {1423, 32767, 1.25f},
     {1086, 32767, 1.25f},
     {1157, 32767, 1.0f},
     {1441, 22000, 1.2f},
     {1163, 32767, 1.0f},
     {1175, 32767, 1.0f}},
    {D_8080B280_bsfirstp, D_8080B2E0_bsfirstp, D_8080B340_bsfirstp, D_8080B3A0_bsfirstp,
     D_8080B400_bsfirstp.sounds}};
BtFnWord D_8080B474_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xEC4) = {
    (BtFnWord)func_808031D0_bsfirstp, (BtFnWord)func_80803134_bsfirstp,
    (BtFnWord)func_80803204_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
BtFnWord D_8080B484_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xED4) = {
    (BtFnWord)func_80803320_bsfirstp, (BtFnWord)func_808032C0_bsfirstp,
    (BtFnWord)func_80803340_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
BtFnWord D_8080B494_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xEE4) = {
    (BtFnWord)func_80803784_bsfirstp, (BtFnWord)func_808036F0_bsfirstp,
    (BtFnWord)func_808037E4_bsfirstp, (BtFnWord)func_80803828_bsfirstp};
s16 D_8080B4A4_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xEF4) = {19, 1323, 24, 0};
f32 D_8080B4AC_bsfirstp[3] BT_DATA(4, overlays_bs_firstp, 0xEFC) = {-1.75f, 74.0f, 3.8f};
f32 D_8080B4B8_bsfirstp[3] BT_DATA(4, overlays_bs_firstp, 0xF08) = {-0.32f, 34.3f, 1.32f};
f32 D_8080B4C4_bsfirstp[3] BT_DATA(4, overlays_bs_firstp, 0xF14) = {4.1f, 40.0f, 120.0f};
BtFnWord D_8080B4D0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF20) = {
    (BtFnWord)func_80803F6C_bsfirstp, (BtFnWord)func_80803E84_bsfirstp,
    (BtFnWord)func_80803F94_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
BtFnWord D_8080B4E0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF30) = {
    (BtFnWord)func_80804210_bsfirstp, (BtFnWord)func_808041D0_bsfirstp,
    (BtFnWord)func_80804238_bsfirstp, (BtFnWord)func_808058F0_bsfirstp};
BtFnWord D_8080B4F0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF40) = {
    (BtFnWord)func_8080436C_bsfirstp, (BtFnWord)func_8080432C_bsfirstp,
    (BtFnWord)func_80804394_bsfirstp, (BtFnWord)func_808058F0_bsfirstp};
BtFnWord D_8080B500_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF50) = {
    (BtFnWord)func_80804B84_bsfirstp, (BtFnWord)func_80804B10_bsfirstp,
    (BtFnWord)func_80804BA4_bsfirstp, (BtFnWord)func_80804A64_bsfirstp};
BtFnWord D_8080B510_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF60) = {
    (BtFnWord)func_80804D80_bsfirstp, (BtFnWord)func_80804D18_bsfirstp,
    (BtFnWord)func_80804DA0_bsfirstp, (BtFnWord)func_80804A64_bsfirstp};
BtFnWord D_8080B520_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF70) = {
    (BtFnWord)func_80804EB4_bsfirstp, (BtFnWord)func_80804E1C_bsfirstp,
    (BtFnWord)func_80804ED4_bsfirstp, (BtFnWord)func_80804A64_bsfirstp};
BtFnWord D_8080B530_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF80) = {
    (BtFnWord)func_80804FB4_bsfirstp, (BtFnWord)func_80804F28_bsfirstp,
    (BtFnWord)func_80804FD4_bsfirstp, (BtFnWord)func_80804A64_bsfirstp};
BtFnWord D_8080B540_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xF90) = {
    (BtFnWord)func_808050B0_bsfirstp, (BtFnWord)func_80805058_bsfirstp,
    (BtFnWord)func_808050D8_bsfirstp, (BtFnWord)_bsdrone_entrypoint_3};
BtFnWord D_8080B550_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFA0) = {
    (BtFnWord)func_8080519C_bsfirstp, (BtFnWord)func_8080511C_bsfirstp,
    (BtFnWord)func_808051C4_bsfirstp, (BtFnWord)_bsdrone_entrypoint_3};
BtFnWord D_8080B560_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFB0) = {
    (BtFnWord)func_80806CC0_bsfirstp, (BtFnWord)func_80806C58_bsfirstp,
    (BtFnWord)func_80806D64_bsfirstp, (BtFnWord)func_80806D90_bsfirstp};
BtFnWord D_8080B570_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFC0) = {
    (BtFnWord)func_80806E9C_bsfirstp, (BtFnWord)func_80806E0C_bsfirstp,
    (BtFnWord)func_80806EC4_bsfirstp, (BtFnWord)func_80807024_bsfirstp};
BtFnWord D_8080B580_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFD0) = {
    (BtFnWord)func_808071D8_bsfirstp, (BtFnWord)func_80807208_bsfirstp,
    (BtFnWord)func_80807264_bsfirstp, 0};
BtFnWord D_8080B590_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFE0) = {
    (BtFnWord)func_808074D0_bsfirstp, (BtFnWord)func_80807504_bsfirstp,
    (BtFnWord)func_8080762C_bsfirstp, (BtFnWord)func_80807394_bsfirstp};
BtFnWord D_8080B5A0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0xFF0) = {
    (BtFnWord)func_808077AC_bsfirstp, (BtFnWord)func_808077E0_bsfirstp,
    (BtFnWord)func_80807864_bsfirstp, (BtFnWord)func_80807394_bsfirstp};
BtFnWord D_8080B5B0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0x1000) = {
    (BtFnWord)func_808088A4_bsfirstp, (BtFnWord)func_80808848_bsfirstp,
    (BtFnWord)func_808088D0_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
BtFnWord D_8080B5C0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0x1010) = {
    (BtFnWord)func_80808A8C_bsfirstp, (BtFnWord)func_80808A24_bsfirstp,
    (BtFnWord)func_80808AAC_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
BtFnWord D_8080B5D0_bsfirstp[4] BT_DATA(4, overlays_bs_firstp, 0x1020) = {
    (BtFnWord)func_80809384_bsfirstp, (BtFnWord)func_80809334_bsfirstp,
    (BtFnWord)func_808093A4_bsfirstp, (BtFnWord)_bsfirstp_entrypoint_26};
