#ifndef __NC_BA_DIE_H__
#define __NC_BA_DIE_H__

#include "common.h"
#include "player.h"
#include "core2/1EEBA50.h"

#ifdef BT_NATIVE
void _ncbadie_entrypoint_3(void *arg0, f32 arg1);
#else
extern void _ncbadie_entrypoint_3(PlayerState *, f32);
#endif

#endif // __NC_BA_DIE_H__
