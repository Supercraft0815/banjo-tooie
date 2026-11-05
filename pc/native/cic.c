#include "native_cic.h"
#include "../common/cic6105.h"

void native_cic_response(const u8 challenge[16], u8 response[16]) {
    u8 input[30], output[30];
    s32 i;
    for (i = 0; i < 15; ++i) {
        input[i * 2] = challenge[i] >> 4;
        input[i * 2 + 1] = challenge[i] & 15;
    }
    bt_cic6105(input, output, 30);
    for (i = 0; i < 15; ++i) response[i] = output[i * 2] << 4 | output[i * 2 + 1];
    response[15] = 0;
}
