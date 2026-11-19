#include "bs.h"

typedef struct {
    s16 stateId;
    s16 category;
    u32 flags;
    BsScript (*provider)(BsScriptType);
} PlayerStateEntry;

#define BS_STATE(id, category, flags, provider) extern BsScript provider(BsScriptType);
#define BS_STATE_EMPTY(id, category, flags)
#include "player_state_rows.inc"
#undef BS_STATE
#undef BS_STATE_EMPTY

PlayerStateEntry playerStates[] BT_DATA(4, player_state_dispatch, 0) = {
#define BS_STATE(id, category, flags, provider) {id, category, flags, provider},
#define BS_STATE_EMPTY(id, category, flags) {id, category, flags, NULL},
#include "player_state_rows.inc"
#undef BS_STATE
#undef BS_STATE_EMPTY
};
