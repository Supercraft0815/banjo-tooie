typedef struct { s16 hudItem, playWarning; u16 pauseFlags; } HudTimerPolicy;
typedef struct { s16 commands[8]; u32 padding[2]; } HudTimerSound;
typedef struct {
    f32 secondsPerUnit;
    s16 soundId, volume;
    f32 pitch;
    s16 expiryEffect, mode;
    f32 effectDuration;
} AirTimerSetting;

HudTimerPolicy D_8011AA30[9] BT_DATA(4, air_timer_settings, 0) = {
    {0x0CC, 0, 0xF},
    {0x0CD, 0, 0xC},
    {0x0CE, 0, 0xC},
    {0x0C9, 0, 0xC},
    {0x0F4, 0, 0x4},
    {0x0F6, 0, 0x4},
    {0x104, 0, 0x4},
    {0x117, 0, 0x0},
    {0x0CC, 0, 0x0},
};

HudTimerSound D_8011AA68 BT_DATA(4, air_timer_settings, 0x38) = {
    {
        518,
        19, 1044,
        27,
        2,
        22, 32767,
        0,
    },
    {0, 0}
};

AirTimerSetting D_8011AA80[9] BT_DATA(4, air_timer_settings, 0x50) = {
    {0.1f, 0x3E9, 18000, 1.2f, 0, 0, 0.0f},
    {1e+01f, 0x046, 28000, -1.0f, 17, 0, 2.0f},
    {6.0f, 0x046, 28000, -1.0f, 69, 1, 2.0f},
    {3.0f, 0x046, 28000, -1.0f, 69, 1, 2.0f},
    {0.5f, 0x046, 28000, -1.0f, 69, 1, 1.0f},
    {15.0f, 0x046, 28000, -1.0f, 69, 1, 3.0f},
    {12.0f, 0x046, 28000, -1.0f, 69, 1, 3.0f},
    {2.0f, 0x046, 28000, -1.0f, 69, 1, 2.0f},
    {6.0f, 0x046, 28000, -1.0f, 69, 1, 3.0f},
};
