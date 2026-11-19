#ifndef BA_ANIM_SMOOTH_H
#define BA_ANIM_SMOOTH_H

#include "PR/ultratypes.h"
#include "overlays/ba/assets.h"

struct player_state_s;
void baanim_playForDuration_loopSmooth(struct player_state_s *self, AssetId anim_id, f32 duration);
void baanim_playForDuration_onceSmooth(struct player_state_s *self, AssetId anim_id, f32 duration);

#endif
