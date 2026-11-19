#include "common.h"
#ifdef BT_NATIVE
s16 D_8012AE70 BT_DATA(4, bss_core2bss1_1, 0x390);
BtIntPtr D_8012AE74 BT_DATA(4, bss_core2bss1_1, 0x394);
#endif

void func_800CB840(s32 arg0, BtIntPtr arg1) {
    BT_IDO_ONLY(extern s32 D_8012AE70;)
    BT_DATA_FIELD(D_8012AE70, (*(s16 *)((s8 *)(&D_8012AE70) + (0)))) = arg0;
    BT_DATA_FIELD(D_8012AE74, (*(s32 *)((s8 *)(&D_8012AE70) + (4)))) = arg1;
}

s16 func_800CB854(BtIntPtr *arg0) {
    BT_IDO_ONLY(extern s32 D_8012AE70;)
    BT_IDO_ONLY(extern s32 D_8012AE74;)
    if (arg0 != NULL) {
        *arg0 = D_8012AE74;
    }
    return BT_DATA_FIELD(D_8012AE70, *(s16 *)&D_8012AE70);
}

void func_800CB870(void) {
    BT_IDO_ONLY(extern s32 D_8012AE70;)
    BT_DATA_FIELD(D_8012AE70, (*(s16 *)((s8 *)(&D_8012AE70) + (0)))) = 0;
    BT_DATA_FIELD(D_8012AE74, (*(s32 *)((s8 *)(&D_8012AE70) + (4)))) = 0;
}
