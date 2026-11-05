#ifndef BT_NATIVE_INPUT_H
#define BT_NATIVE_INPUT_H

#include "types.h"

/* Called by the frontend on the game thread, once per input sample.
 * Buttons use libultra masks; stick axes must already be calibrated to [-1, 1]. */
int bt_native_set_controller(u32 controller, u16 buttons, f32 stick_x, f32 stick_y);

#endif
