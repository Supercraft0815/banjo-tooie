// Keep the host oracle's ILP32 layout assumptions tied to the game's actual types.
#include <stddef.h>
#include "common.h"
#include "vector.h"
#include "overlays/ba/playerstate.h"
#include "overlays/bs/state.h"

_Static_assert(sizeof(void *) == 4, "trace requires ILP32 guest pointers");
_Static_assert(sizeof(Actor) == 0x9C, "trace actor stride");
_Static_assert(offsetof(Actor, unk0) == 0, "trace actor marker");
_Static_assert(offsetof(Actor, position) == 4, "trace actor position");
_Static_assert(offsetof(Actor, unk14) == 0x14, "trace actor state");
_Static_assert(offsetof(Actor, scale) == 0x38, "trace actor scale");
_Static_assert(offsetof(Actor, rotation) == 0x44, "trace actor rotation");
_Static_assert(offsetof(Actor, pad5C) == 0x5C, "trace actor health and flags");
_Static_assert(offsetof(Unk80132ED0, unk14) == 0x14, "trace actor id");
_Static_assert(offsetof(PlayerState, state) == 0x120, "trace player state pointer");
_Static_assert(offsetof(BanjoState, previous) == 0, "trace previous state");
_Static_assert(offsetof(BanjoState, current) == 4, "trace current state");
_Static_assert(offsetof(BanjoState, next) == 8, "trace next state");
_Static_assert(offsetof(Vector, element_size) == 0, "trace actor element size");
_Static_assert(offsetof(Vector, begin) == 4, "trace actor begin");
_Static_assert(offsetof(Vector, end) == 8, "trace actor end");
