.include "macro.inc"

.section .bss

dlabel D_8012B420
    /* 8012B420 */ .space 0x10

dlabel D_8012B430
    /* 8012B430 */ .space 0x01

dlabel D_8012B431
    /* 8012B431 */ .space 0x01

dlabel D_8012B432
    /* 8012B432 */ .space 0x0E

dlabel D_8012B440
    /* 8012B440 */ .space 0x04

dlabel D_8012B444
    /* 8012B444 */ .space 0x04

dlabel D_8012B448
    /* 8012B448 */ .space 0x08

dlabel D_8012B450
    /* 8012B450 */ .space 0x208

dlabel D_8012B658
    /* 8012B658 */ .space 0x88

dlabel D_8012B6E0
    /* 8012B6E0 */ .space 0x104

dlabel D_8012B7E4
    /* 8012B7E4 */ .space 0x01

dlabel D_8012B7E5
    /* 8012B7E5 */ .space 0x01

dlabel D_8012B7E6
    /* 8012B7E6 */ .space 0x02

dlabel D_8012B7E8
    /* 8012B7E8 */ .space 0x08

dlabel D_8012B7F0
    /* 8012B7F0 */ .space 0x04

dlabel D_8012B7F4
    /* 8012B7F4 */ .space 0x04

dlabel D_8012B7F8
    /* 8012B7F8 */ .space 0x08

dlabel D_8012B800
    /* 8012B800 */ .space 0x660

/* The original high-nibble lookup starts ten bytes into the first record. */
.globl D_8012B80A
D_8012B80A = D_8012B800 + 0xA

dlabel D_8012BE60
    /* 8012BE60 */ .space 0x02

dlabel D_8012BE62
    /* 8012BE62 */ .space 0x02

dlabel D_8012BE64
    /* 8012BE64 */ .space 0x0B

dlabel D_8012BE6F
    /* 8012BE6F */ .space 0x01

dlabel D_8012BE70
    /* 8012BE70 */ .space 0x1B0

dlabel D_8012C020
    /* 8012C020 */ .space 0x10

dlabel D_8012C030
    /* 8012C030 */ .space 0x730

dlabel D_8012C760
    /* 8012C760 */ .space 0x04

dlabel D_8012C764
    /* 8012C764 */ .space 0x04

dlabel D_8012C768
    /* 8012C768 */ .space 0x08
