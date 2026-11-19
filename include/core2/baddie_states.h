#ifndef CORE2_BADDIE_STATES_H
#define CORE2_BADDIE_STATES_H

#include "types.h"

typedef struct {
    s16 state;
    s16 flags;
} BaddieState;

extern BaddieState D_80124550[12];

#endif
