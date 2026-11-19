#include <ultra64.h>
#include "bt_data.h"

s32 D_80004240 BT_DATA(4, boot_inflate_state, 0) = 0;
s32 D_80004244 BT_DATA(4, boot_inflate_state, 4) = 0;

/* The boot inflater addresses these consecutive Huffman tables from assembly. */
typedef struct {
    u16 maskBits[17];
    u16 lengthBase[31];
    u16 distanceBase[30];
    u8 codeLengthOrder[19];
    u8 lengthExtraBits[31];
    u8 distanceExtraBits[30];
} BootInflateTables;

const BootInflateTables boot_inflate_tables BT_DATA(2, boot_inflate, 0) = {
    {
        0, 1, 3, 7, 15, 31, 63, 127,
        255, 511, 1023, 2047, 4095, 8191, 16383, 32767,
        65535,
    },
    {
        3, 4, 5, 6, 7, 8, 9, 10,
        11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115,
        131, 163, 195, 227, 258, 0, 0,
    },
    {
        1, 2, 3, 4, 5, 7, 9, 13,
        17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073,
        4097, 6145, 8193, 12289, 16385, 24577,
    },
    {
        16, 17, 18, 0, 8, 7, 9, 6,
        10, 5, 11, 4, 12, 3, 13, 2,
        14, 1, 15,
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4,
        5, 5, 5, 5, 0, 99, 99,
    },
    {
        0, 0, 0, 0, 1, 1, 2, 2,
        3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10,
        11, 11, 12, 12, 13, 13,
    },
};
