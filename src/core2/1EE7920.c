#include "common.h"
#include "memory.h"
void func_8010E030(void) {

    extern void *D_80127614;
    if (D_80127614 != 0) {
        D_80127614 = defrag(D_80127614);
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
void *D_80127614 BT_DATA(4, bss_core2bss1_0_1, 0x5B4);
#endif
