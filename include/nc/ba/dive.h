#ifndef __NC_BA_DIVE_H__
#define __NC_BA_DIVE_H__

#include "common.h"
#include "player.h"
#include "core2/1EEBA50.h"

#ifdef BT_NATIVE
void _ncbadive_entrypoint_4(void *arg0 BT_PASS2(, s32 bt_a0));
#else
extern void _ncbadive_entrypoint_4(s32, f32 *);
#endif

#endif // __NC_BA_DIVE_H__
