#include "gameflags.h"

typedef void (*AttractCallback)(void);

typedef struct {
    u8 count;
    union {
        void (*zero)(void);
        void (*one)(s32);
        void (*two)(s32, s32);
        void (*three)(u32, u32, u32);
    } callback;
    s32 args[3];
} AttractCommand;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800DA544(GameFlag);
static void attract_set_game_flag(s32 flag) { func_800DA544((GameFlag)flag); }
#define ATTRACT_GAME_FLAG attract_set_game_flag
#else
#define ATTRACT_GAME_FLAG func_800DA544
#endif
