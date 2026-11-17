// n_aspMain command words. DMEM is 4 KiB and physical audio DMA addresses wrap at 16 MiB.
#ifndef BT_AUDIO_MIXER_H
#define BT_AUDIO_MIXER_H
#include <stdint.h>

enum { BT_AUDIO_DATA_BYTES = 0x740, BT_AUDIO_TEXT_BYTES = 0xf80 };
void bt_rom_audio(int text, uint8_t *bytes);

typedef struct {
    unsigned address, size;
    uint8_t bytes[4096];
} BtMixerWrite;

typedef void (*BtMixerOracle)(unsigned index, uint32_t cmd, uint32_t arg, const uint8_t *dmem,
                              const BtMixerWrite *write);
void bt_mixer_audio(uint32_t task, const uint8_t *boot_data, unsigned boot_size, BtMixerOracle oracle);

#ifdef BT_AUDIO_DEBUG
void bt_audio_oracle(uint32_t task, int check, const uint8_t *boot_data);
#endif
#endif
