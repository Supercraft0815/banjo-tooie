#include "gc/level.h"

static GameFlag last_flag;

s32 func_800DA298(GameFlag flag) {
    last_flag = flag;
    return flag == FLAG_1E9_PROGRESS_VIEW_TOTALS_MENU_HFP;
}

int main(void) {
    u32 (*query)(u32) = _gclevel_entrypoint_3;
    if (query(0x17) != 1 || last_flag != FLAG_1E9_PROGRESS_VIEW_TOTALS_MENU_HFP) return 1;
    if (query(0x18) != 0 || last_flag != FLAG_1EA_PROGRESS_VIEW_TOTALS_MENU_CCL) return 2;
    if (query(0x10) != 0 || last_flag != FLAG_1E3_PROGRESS_VIEW_TOTALS_MENU_MT) return 3;
    if (query(0x7FFF) != 1 || last_flag != FLAG_1E3_PROGRESS_VIEW_TOTALS_MENU_MT) return 4;
    return 0;
}
