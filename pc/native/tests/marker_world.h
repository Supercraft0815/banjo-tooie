#ifndef BT_TEST_MARKER_WORLD_H
#define BT_TEST_MARKER_WORLD_H
#include "native_world_grid.h"
/* Grid dimensions and external world callbacks are fixtures; lookup/storage are real C. */
extern NativeWorldCell *marker_world[3];
extern int marker_world_updates;
void marker_world_reset(void);
void marker_world_cleanup(void);
#endif
