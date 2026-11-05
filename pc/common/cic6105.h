#ifndef BT_CIC6105_H
#define BT_CIC6105_H

#include <stdint.h>

// CIC-NUS-6105 challenge/response, as documented by emulators (X-Scale's algorithm).
static inline void bt_cic6105(const uint8_t* challenge, uint8_t* response, int len) {
    static const uint8_t lut0[16] = {0x4, 0x7, 0xA, 0x7, 0xE, 0x5, 0xE, 0x1, 0xC, 0xF, 0x8, 0xF, 0x6, 0x3, 0x6, 0x9};
    static const uint8_t lut1[16] = {0x4, 0x1, 0xA, 0x7, 0xE, 0x5, 0xE, 0x1, 0xC, 0x9, 0x8, 0x5, 0x6, 0x3, 0xC, 0x9};
    uint8_t key = 0xB;
    const uint8_t* lut = lut0;
    for (int i = 0; i < len; i++) {
        response[i] = (key + 5 * challenge[i]) & 0xF;
        key = lut[response[i]];
        int sgn = (response[i] >> 3) & 1;
        int mag = (sgn ? ~response[i] : response[i]) & 7;
        int mod = (mag % 3 == 1) ? sgn : 1 - sgn;
        if (lut == lut1 && (response[i] == 0x1 || response[i] == 0x9)) {
            mod = 1;
        }
        if (lut == lut1 && (response[i] == 0xB || response[i] == 0xE)) {
            mod = 0;
        }
        lut = mod ? lut1 : lut0;
    }
}

#endif
