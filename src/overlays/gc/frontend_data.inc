/* data_to_c.py: from asm/data/overlays/gc/frontend.data.s */
GCFrontendCommand D_80800840_gcfrontend[3] BT_DATA(4, overlays_gc_frontend,
                                                   0x0) = {{1, 0}, {6, 50}, {5, 0}};
GCFrontendCommand D_8080084C_gcfrontend[1] BT_DATA(4, overlays_gc_frontend, 0xC) = {{3, 8}};
GCFrontendCommand D_80800850_gcfrontend[7] BT_DATA(4, overlays_gc_frontend, 0x10) = {
    {5, 2}, {4, 87}, {4, 233}, {4, 232}, {4, 43}, {4, 44}, {4, 47}};
GCFrontendCommand D_8080086C_gcfrontend[2] BT_DATA(4, overlays_gc_frontend, 0x2C) = {{5, 2},
                                                                                     {3, 12}};
GCFrontendCommand D_80800874_gcfrontend[2] BT_DATA(4, overlays_gc_frontend, 0x34) = {{5, 2},
                                                                                     {3, 6}};
GCFrontendCommand D_8080087C_gcfrontend[2] BT_DATA(4, overlays_gc_frontend, 0x3C) = {{5, 3},
                                                                                     {3, 9}};
GCFrontendCommand D_80800884_gcfrontend[1] BT_DATA(4, overlays_gc_frontend, 0x44) = {{3, 11}};
GCFrontendCommand D_80800888_gcfrontend[3] BT_DATA(4, overlays_gc_frontend,
                                                   0x48) = {{5, 2}, {6, 40}, {3, 11}};
GCFrontendCommand D_80800894_gcfrontend[2] BT_DATA(4, overlays_gc_frontend, 0x54) = {{5, 2},
                                                                                     {4, 87}};
GCFrontendCommand D_8080089C_gcfrontend[6] BT_DATA(4, overlays_gc_frontend, 0x5C) = {
    {4, 179}, {4, 148}, {4, 235}, {4, 234}, {4, 236}, {4, 178}};
GCFrontendCommand D_808008B4_gcfrontend[2] BT_DATA(4, overlays_gc_frontend, 0x74) = {{5, 2},
                                                                                     {7, 1410}};
GCFrontendCommand D_808008BC_gcfrontend[3] BT_DATA(4, overlays_gc_frontend,
                                                   0x7C) = {{5, 2}, {4, 1410}, {4, 1411}};
GCFrontendCommand D_808008C8_gcfrontend[3] BT_DATA(4, overlays_gc_frontend,
                                                   0x88) = {{5, 2}, {6, 18}, {6, 6}};
GCFrontendCommand D_808008D4_gcfrontend[3] BT_DATA(4, overlays_gc_frontend,
                                                   0x94) = {{3, 11}, {6, 40}, {6, 6}};
GCFrontendCommand D_808008E0_gcfrontend[7] BT_DATA(4, overlays_gc_frontend, 0xA0) = {
    {2, 64}, {2, 65}, {2, 66}, {2, 67}, {2, 68}, {2, 70}, {2, 71}};
GCFrontendScript D_808008FC_gcfrontend[4] BT_DATA(4, overlays_gc_frontend, 0xBC) = {
    {7, (GCFrontendCommand *)D_808008E0_gcfrontend},
    {2, (GCFrontendCommand *)D_8080087C_gcfrontend},
    {3, (GCFrontendCommand *)D_80800840_gcfrontend},
    {7, (GCFrontendCommand *)D_80800850_gcfrontend}};
GCFrontendScene D_8080091C_gcfrontend[6] BT_DATA(4, overlays_gc_frontend, 0xDC) = {
    {161, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 1, {0, 0}},
    {398, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 1, {0, 0}},
    {404, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 1, {0, 0}},
    {401, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 1, {0, 0}},
    {412, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {413, 0, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}}};
GCFrontendScene D_8080097C_gcfrontend[13] BT_DATA(4, overlays_gc_frontend, 0x13C) = {
    {321, 3, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {347, 3, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {350, 3, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {378, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 0, 0, {0, 0}},
    {209, 1, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {249, 2, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {252, 1, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {275, 4, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {272, 2, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {300, 2, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {299, 2, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {319, 2, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}},
    {349, 6, {7, (GCFrontendCommand *)D_80800850_gcfrontend}, 0, 0, {0, 0}}};
GCFrontendScene D_80800A4C_gcfrontend[23] BT_DATA(4, overlays_gc_frontend, 0x20C) = {
    {198, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {200, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {201, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {220, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 0, 0, {0, 0}},
    {222, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {223, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {224, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {229, 1, {1, (GCFrontendCommand *)D_80800884_gcfrontend}, 0, 0, {0, 0}},
    {228, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {292, 8, {6, (GCFrontendCommand *)D_8080089C_gcfrontend}, 0, 0, {0, 0}},
    {385, 1, {2, (GCFrontendCommand *)D_8080086C_gcfrontend}, 0, 0, {0, 0}},
    {291, 1, {2, (GCFrontendCommand *)D_80800894_gcfrontend}, 0, 0, {0, 0}},
    {354, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 0, 0, {0, 0}},
    {266, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {302, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {303, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {304, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {317, 2, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {311, 3, {3, (GCFrontendCommand *)D_80800888_gcfrontend}, 0, 0, {0, 0}},
    {313, 1, {2, (GCFrontendCommand *)D_80800874_gcfrontend}, 0, 0, {0, 0}},
    {351, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {351, 1, {2, (GCFrontendCommand *)D_808008B4_gcfrontend}, 0, 0, {0, 0}},
    {351, 1, {3, (GCFrontendCommand *)D_808008BC_gcfrontend}, 0, 0, {0, 0}}};
GCFrontendScene D_80800BBC_gcfrontend[14] BT_DATA(4, overlays_gc_frontend, 0x37C) = {
    {358, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 1, 0, {0, 0}},
    {383, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {357, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 1, 0, {0, 0}},
    {390, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {380, 1, {3, (GCFrontendCommand *)D_808008D4_gcfrontend}, 0, 0, {0, 0}},
    {379, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 0, 0, {0, 0}},
    {386, 1, {2, (GCFrontendCommand *)D_8080086C_gcfrontend}, 2, 0, {0, 0}},
    {387, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 0, 0, {0, 0}},
    {356, 1, {2, (GCFrontendCommand *)D_8080087C_gcfrontend}, 1, 0, {0, 0}},
    {381, 1, {3, (GCFrontendCommand *)D_808008C8_gcfrontend}, 0, 0, {0, 0}},
    {384, 1, {1, (GCFrontendCommand *)D_8080084C_gcfrontend}, 0, 0, {0, 0}},
    {389, 1, {3, (GCFrontendCommand *)D_80800888_gcfrontend}, 0, 0, {0, 0}},
    {392, 1, {2, (GCFrontendCommand *)D_80800874_gcfrontend}, 2, 0, {0, 0}},
    {393, 1, {3, (GCFrontendCommand *)D_80800840_gcfrontend}, 3, 0, {0, 0}}};
GCFrontendScene D_80800C9C_gcfrontend[7] BT_DATA(4, overlays_gc_frontend, 0x45C) = {
    {344, 0, {0, 0}, 0, 0, {0, 0}}, {161, 0, {0, 0}, 0, 0, {0, 0}}, {175, 4, {0, 0}, 0, 0, {0, 0}},
    {322, 3, {0, 0}, 0, 0, {0, 0}}, {322, 1, {0, 0}, 0, 0, {0, 0}}, {404, 0, {0, 0}, 0, 0, {0, 0}},
    {395, 0, {0, 0}, 0, 0, {0, 0}}};
s16 D_80800D0C_gcfrontend[13] BT_DATA(4, overlays_gc_frontend, 0x4CC) = {
    171, 171, 171, 178, 66, 58, 180, 87, 181, 117, 118, 119, 34};
s16 D_80800D28_gcfrontend[14] BT_DATA(4, overlays_gc_frontend, 0x4E8) = {
    178, 96, 63, 120, 13, 12, 3, 179, 163, 163, 96, 106, 153, 34};
s16 D_80800D44_gcfrontend[23] BT_DATA(4, overlays_gc_frontend, 0x504) = {
    96,  96,  96, 63, 120, 120, 120, 13,  12, 65, 3, 179,
    163, 163, 96, 96, 96,  34,  106, 153, 34, 34, 34};
s16 D_80800D74_gcfrontend[6] BT_DATA(4, overlays_gc_frontend, 0x534) = {12, 174, 15, 34, 111, 13};
GCFrontendRange D_80800D80_gcfrontend[4] BT_DATA(4, overlays_gc_frontend, 0x540) = {
    {0x60, 0x17, 3043, (GCFrontendScene *)D_80800A4C_gcfrontend, (short *)D_80800D44_gcfrontend},
    {0x20, 0xD, 3016, (GCFrontendScene *)D_8080097C_gcfrontend, (short *)D_80800D0C_gcfrontend},
    {0x80, 6, 3066, (GCFrontendScene *)D_8080091C_gcfrontend, (short *)D_80800D74_gcfrontend},
    {0x40, 0xE, 3029, (GCFrontendScene *)D_80800BBC_gcfrontend, (short *)D_80800D28_gcfrontend}};
s16 D_80800DB0_gcfrontend[16][4] BT_DATA(4, overlays_gc_frontend, 0x570) = {
    {32, 193, 0, 0},  {33, 442, 0, 0},  {34, 183, 0, 0},   {35, 136, 0, 0},
    {36, 377, 0, 0},  {37, 383, 0, 0},  {38, 431, 0, 0},   {39, 370, 0, 0},
    {40, 372, 0, 0},  {41, 467, 0, 0},  {42, 468, 0, 0},   {43, 1032, 0, 0},
    {44, 68, 410, 1}, {104, 430, 0, 0}, {105, 1048, 0, 0}, {107, 880, 0, 0}};
