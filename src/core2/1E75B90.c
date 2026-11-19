#include "common.h"
#include "core2/player_motion_data.h"

void func_8009C2A0(BtIntPtr arg0, s32 arg1, BtIntPtr arg2) {
    void func_800DBEFC(s32 *, s32, BtIntPtr);
    BT_IDO_ONLY(extern s16 D_80117F02[2];)
    func_800DBEFC((s32 *) arg0, BT_DATA_FIELD(player_node_mapping[arg1].node, *(s16 *)((u8 *)D_80117F02 + arg1 * 4)), arg2);
}
