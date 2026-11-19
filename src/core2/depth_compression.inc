/* RDP Z exponent to mantissa shift and base for an 18-bit linear depth. */
s32 D_801234C0[8][2] BT_DATA(4, depth_compression, 0) = {
    {6, 0x00000}, {5, 0x20000}, {4, 0x30000}, {3, 0x38000},
    {2, 0x3C000}, {1, 0x3E000}, {0, 0x3F000}, {0, 0x3F800},
};
