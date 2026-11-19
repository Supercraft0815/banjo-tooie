#include "gc/level.h"

static GameFlag last_flag;

s32 func_800DA298(GameFlag flag) {
    last_flag = flag;
    return flag == FLAG_1E9_PROGRESS_VIEW_TOTALS_MENU_HFP;
}

void func_8009EB8C(s16, s16);
void func_8009EB24(s16, s16);
void func_8009EBD0(void);
s32 func_8009EC08(s16 *, s16 *);
void func_8009EC3C(void);
u32 func_8009EC7C(void);
s32 func_8009EC88(s32, s32, s32, s32);

static int respawn_stack(void) {
    s16 map = -1, entrance = -1;
    func_8009EC3C();
    if (func_8009EC08(&map, &entrance) || map != -1 || entrance != -1) return 1;
    func_8009EB8C(0x102, 2);
    for (s16 i = 1; i <= 3; i++) func_8009EB24(0x102 + i, 2 + i);
    if (func_8009EC7C() != 4 || !func_8009EC88(0x102, 2, 0x100, 9)) return 2;
    if (func_8009EC88(0x102, 2, 0x101, 8)) return 3;
    for (s16 i = 3; i >= 1; i--) {
        if (!func_8009EC08(&map, &entrance) || map != 0x102 + i || entrance != 2 + i) return 4;
        func_8009EBD0();
    }
    return func_8009EC7C() != 1 || !func_8009EC08(&map, &entrance) || map != 0x100 || entrance != 9;
}

int main(void) {
    u32 (*query)(u32) = _gclevel_entrypoint_3;
    if (query(0x17) != 1 || last_flag != FLAG_1E9_PROGRESS_VIEW_TOTALS_MENU_HFP) return 1;
    if (query(0x18) != 0 || last_flag != FLAG_1EA_PROGRESS_VIEW_TOTALS_MENU_CCL) return 2;
    if (query(0x10) != 0 || last_flag != FLAG_1E3_PROGRESS_VIEW_TOTALS_MENU_MT) return 3;
    if (query(0x7FFF) != 1 || last_flag != FLAG_1E3_PROGRESS_VIEW_TOTALS_MENU_MT) return 4;
    return respawn_stack();
}
