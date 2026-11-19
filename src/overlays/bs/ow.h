#include "bs_script.h"
#ifndef __BS_OW_H__
#define __BS_OW_H__
#include "overlays/ba/anim.h"
#include "overlays/ba/bounce.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/bs/state.h"
#include "overlays/bs/walk.h"
#include "core2/1E66990.h"
#include "core2/1E6E870.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

extern BtIntPtr D_80800150_bsow[];

extern void _bsow_entrypoint_0(PlayerState *self);
extern void _bsow_entrypoint_1(PlayerState *self);
extern void _bsow_entrypoint_2(PlayerState *self);
extern BsScript _bsow_entrypoint_3(BsScriptType idx);
#endif // __BS_OW_H__
