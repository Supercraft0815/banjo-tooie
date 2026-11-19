/* Code-length alphabet in dynamic Huffman blocks. */
u8 D_801231F0[19] BT_DATA(4, inflate_tables, 0x0) = {
    16, 17, 18, 0, 8, 7, 9, 6,
    10, 5, 11, 4, 12, 3, 13, 2,
    14, 1, 15,
};

/* Length base and extra bits for literal/length codes 257 through 287. */
u16 D_80123204[31] BT_DATA(4, inflate_tables, 0x14) = {
    3, 4, 5, 6, 7, 8, 9, 10,
    11, 13, 15, 17, 19, 23, 27, 31,
    35, 43, 51, 59, 67, 83, 99, 115,
    131, 163, 195, 227, 258, 0, 0,
};

u8 D_80123244[31] BT_DATA(4, inflate_tables, 0x54) = {
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 4,
    5, 5, 5, 5, 0, 99, 99,
};

/* Distance base and extra bits for distance codes 0 through 29. */
u16 D_80123264[30] BT_DATA(4, inflate_tables, 0x74) = {
    1, 2, 3, 4, 5, 7, 9, 13,
    17, 25, 33, 49, 65, 97, 129, 193,
    257, 385, 513, 769, 1025, 1537, 2049, 3073,
    4097, 6145, 8193, 12289, 16385, 24577,
};

u8 D_801232A0[30] BT_DATA(4, inflate_tables, 0xB0) = {
    0, 0, 0, 0, 1, 1, 2, 2,
    3, 3, 4, 4, 5, 5, 6, 6,
    7, 7, 8, 8, 9, 9, 10, 10,
    11, 11, 12, 12, 13, 13,
};

/* Low-bit masks for widths 0 through 16. */
u16 D_801232C0[17] BT_DATA(4, inflate_tables, 0xD0) = {
    0x0000, 0x0001, 0x0003, 0x0007, 0x000F, 0x001F, 0x003F, 0x007F,
    0x00FF, 0x01FF, 0x03FF, 0x07FF, 0x0FFF, 0x1FFF, 0x3FFF, 0x7FFF,
    0xFFFF,
};
