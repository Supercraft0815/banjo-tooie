#include "athlete_tables.h"

/* data_to_c.py: from asm/data/overlays/ch/fantasy/athlete.data.s */
ActorAnimationEntry D_80803030_chfantasyathlete[36] BT_DATA(4, overlays_ch_fantasy_athlete, 0x0) = {
    {0.0f, 0, 0},     {5.7f, 0x3F9, 9}, {5.7f, 0x3F9, 9}, {5.7f, 0x3F9, 9}, {4.4f, 0x3FE, 9},
    {1.0f, 0x3FA, 9}, {1.0f, 0x3FA, 9}, {2.2f, 0x3FC, 9}, {1.0f, 0x3FB, 9}, {1.0f, 0x3FB, 9},
    {1.0f, 0x3FB, 9}, {1.0f, 0x3FB, 9}, {1.0f, 0x3FC, 9}, {1.0f, 0x3FB, 9}, {2.6f, 0x3FF, 9},
    {2.6f, 0x400, 9}, {2.6f, 0x3FF, 9}, {2.6f, 0x3FF, 9}, {2.6f, 0x3FF, 9}, {1.0f, 0x3FC, 9},
    {1.0f, 0x3FC, 9}, {2.2f, 0x3FA, 9}, {5.7f, 0x3F9, 9}, {5.7f, 0x3F9, 9}, {5.7f, 0x3F9, 9},
    {5.7f, 0x3F9, 9}, {5.7f, 0x3FA, 9}, {5.7f, 0x3F9, 9}, {2.6f, 0x3FD, 9}, {4.4f, 0x3FE, 9},
    {5.7f, 0x3F9, 9}, {2.6f, 0x3FD, 9}, {5.7f, 0x3F9, 9}, {1.0f, 0x3FA, 9}, {2.6f, 0x3FD, 0x4A},
    {5.7f, 0x3F9, 9}};
f32 D_80803150_chfantasyathlete[3] BT_DATA(4, overlays_ch_fantasy_athlete,
                                           0x120) = {13950.0f, 4045.0f, -13990.0f};
struct AthleteCurve6 D_8080315C_chfantasyathlete BT_DATA(4, overlays_ch_fantasy_athlete, 0x12C) = {
    {{0.0f, 0.4f}, {0.2f, 1.0f}, {0.3f, 1.0f}, {0.5f, 0.4f}, {0.7f, 1.0f}, {0.8f, 1.0f}}};
AthleteCurveTail D_8080318C_chfantasyathlete BT_DATA(4, overlays_ch_fantasy_athlete, 0x15C) = {
#ifdef BT_NATIVE
    .curve = {{
#else
    {
#endif
        0.16f, 0.0f, 0.2f, 0.75f, 0.43f, 1.0f, 0.7f, 0.75f, 0.64f,
#ifdef BT_NATIVE
        0.0f}}
#else
    }
#endif
};
