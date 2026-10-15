#include "common.h"

/* extern */

s32 ncstart_entrypoint_0(s32 arg0, f32 *arg1, f32 *arg2) {
    Prop *_gccubesearch_entrypoint_14(s32, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    f32 func_800136E4(f32);
    s32 func_800A9C98(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    Prop *temp_v0;
    s32 var_a3;

    var_a3 = 0x29;
    if (func_800A9C98() != 0) {
        if ((arg0 > 0) && (arg0 < 9)) {
            var_a3 = arg0 + 0xAD;
        }
    } else if ((arg0 > 0) && (arg0 < 0x29)) {
        var_a3 = arg0 + 0x29;
    }
    temp_v0 = _gccubesearch_entrypoint_14(var_a3, 0);
    if (temp_v0 != 0) {
        _gspropctrl_entrypoint_11(temp_v0, arg1);
        func_800EFA4C(arg2, 0.0f, func_800136E4((f32) _gspropctrl_entrypoint_12(temp_v0) - 180.0f), 0.0f);
        return 1;
    }
    return 0;
}
