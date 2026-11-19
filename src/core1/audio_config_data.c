#include "common.h"
#include "core1/audio_config_data.h"

s32 rom_read_word(u32, u32 *);
void func_8001EB10(s32 *);

struct {
    s32 order[13];
    char marker[20];
    s32 (*read_word)(u32, u32 *);
    int (*format)(char *, const char *, ...);
    f32 (*square_root)(f32);
    void (*init_sfx)(s32 *);
    void (*ortho)(Mtx *, f32, f32, f32, f32, f32, f32, f32);
    s32 (*read_eeprom)(OSMesgQueue *, u8, u8 *, int);
    s32 (*write_eeprom)(OSMesgQueue *, u8, u8 *, int);
    s32 padding[3];
} D_8003C9D0 BT_DATA(4, core1_audio_config_data, 0) = {
    {9, 4, 10, 3, 11, 2, 12, 5, 0, 1, 6, 13, -1}, "HjunkDire:667812",
    rom_read_word, sprintf, sqrtf, func_8001EB10, guOrtho, osEepromLongRead, osEepromLongWrite, {0}
};

Core1AudioConfigData core1_audio_config BT_DATA(4, core1_audio_config_data, 0x70) = {
    0,
    {
        /* Custom FX section count, delay length, and eight delay sections. */
        8, 6720,
        0, 192, 9830, -9830, 0, 0, 0, 0,
        192, 392, 9830, -9830, 11140, 0, 0, 0,
        880, 2816, 16384, -16384, 4587, 0, 0, 0,
        1056, 2112, 8192, -8192, 0, 0, 0, 0,
        3528, 6168, 16384, -16384, 4587, 0, 0, 0,
        3704, 5288, 8192, -8192, 0, 0, 0, 0,
        5288, 5952, 8192, -8192, 0, 0, 0, 0,
        0, 6520, 13000, -13000, 0, 380, 10, 0,
        /* The ROM also carries a one-section echo preset after the separator. */
        0, 1, 2640, 0, 2200, 13108, 0, 29493, 0, 0
    },
    NULL, 0, {1, 0, 0}, 0, {0}
};
