#ifndef __NC_BA_FLY_H__
#define __NC_BA_FLY_H__

#include "common.h"
#include "player.h"
#include "core2/1EEBA50.h"

#ifdef BT_NATIVE
void _ncbafly_entrypoint_5(s32 arg0);
#else
extern void _ncbafly_entrypoint_5(s32, s32);
#endif

#endif
