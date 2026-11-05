#include "gc/level.h"

/* Controlled game-flag state and the ten-entry table consumed by the real overlay. */
struct LevelEntry { s16 id; s16 flag; s32 unused; };
struct LevelEntry D_808003D0_gclevel[10] = {
    {0x10, 11, 0}, {0x12, 12, 0}, {0x17, 13, 0}, {0x18, 14, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}
};
static GameFlag last_flag;

s32 func_800DA298(GameFlag flag) {
    last_flag = flag;
    return flag == 13;
}

int main(void) {
    u32 (*query)(u32) = _gclevel_entrypoint_3;
    if (query(0x17) != 1 || last_flag != 13) return 1;
    if (query(0x18) != 0 || last_flag != 14) return 2;
    if (query(0x10) != 0 || last_flag != 11) return 3;
    if (query(0x7FFF) != 1 || last_flag != 11) return 4;
    return 0;
}
