#ifndef BT_BS_SCRIPT_H
#define BT_BS_SCRIPT_H

struct player_state_s;

typedef enum {
    BS_SCRIPT_TYPE_0,
    BS_SCRIPT_TYPE_1_INIT,
    BS_SCRIPT_TYPE_2_UPDATE,
    BS_SCRIPT_TYPE_3
} BsScriptType;

typedef void (*BsScript)(struct player_state_s *);

#endif
