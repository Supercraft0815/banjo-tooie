#ifndef __CH_DOUBLOON_H__
#define __CH_DOUBLOON_H__

#include "common.h"

#ifdef BT_NATIVE
s32 _chdoubloon_entrypoint_1(Actor *arg0);
#else
void _chdoubloon_entrypoint_1(s32);
#endif

#endif