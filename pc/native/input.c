#include "native_input.h"
#include "buttons.h"
#include "core1/1E2D890.h"
#include "memory.h"

typedef struct {
    s32 buttons[BUTTON_COUNT];
    f32 stick[2];
} NativeController;

static NativeController controllers[4];
static const NativeController disconnected;
static const u16 masks[BUTTON_COUNT] = {
    START_BUTTON, Z_TRIG, L_TRIG, R_TRIG,
    U_JPAD, D_JPAD, L_JPAD, R_JPAD,
    A_BUTTON, B_BUTTON, L_CBUTTONS, D_CBUTTONS, U_CBUTTONS, R_CBUTTONS
};

int bt_native_set_controller(u32 controller, u16 buttons, f32 stick_x, f32 stick_y) {
    s32 id;
    if (controller >= ARRLEN(controllers) ||
        !(stick_x >= -1.0f && stick_x <= 1.0f) ||
        !(stick_y >= -1.0f && stick_y <= 1.0f)) return 0;
    for (id = 0; id < BUTTON_COUNT; id++)
        controllers[controller].buttons[id] = (buttons & masks[id]) != 0;
    controllers[controller].stick[0] = stick_x;
    controllers[controller].stick[1] = stick_y;
    return 1;
}

static const NativeController *controller_state(u32 controller) {
    return controller < ARRLEN(controllers) ? &controllers[controller] : &disconnected;
}

void func_80015E80(s32 controller, void *buttons) {
    const s32 *source = &controller_state(controller)->buttons[BUTTON_A];
    rare_memcpy(buttons, (void *)source, 6 * sizeof(s32));
}

void func_80015F28(s32 controller, void *buttons) {
    const s32 *source = &controller_state(controller)->buttons[BUTTON_Z];
    rare_memcpy(buttons, (void *)source, 3 * sizeof(s32));
}

s32 func_80015F84(s32 controller) {
    return controller_state(controller)->buttons[BUTTON_START];
}

void func_80015FFC(s32 controller, void *buttons) {
    const s32 *source = &controller_state(controller)->buttons[BUTTON_D_UP];
    rare_memcpy(buttons, (void *)source, 4 * sizeof(s32));
}

void func_80016068(u32 controller, f32 *stick) {
    stick[0] = controller_state(controller)->stick[0];
    stick[1] = controller_state(controller)->stick[1];
}
