#ifndef NATIVE_SI_H
#define NATIVE_SI_H

#include <ultra64.h>

// Controller 1 state from the host input layer (N64 button bits, stick -80..80).
void bt_si_set_pad(u16 buttons, s8 stick_x, s8 stick_y);

#endif
