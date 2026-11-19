#include "common.h"
BT_NATIVE_ONLY(struct player_state_s;)
void bsdronewaitbabykaz_entrypoint_0(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(struct player_state_s *) arg0)
{
}
/* extern */

void bsdronewaitbabykaz_entrypoint_1(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    void _badata_entrypoint_3(void *self, void *assetId, f32 *arg2);
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);) BT_NATIVE_ONLY(void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);)
    BT_IDO_ONLY(s32 func_8009FFD8(BtIntPtr, s32, s32, s32, s32);) BT_NATIVE_ONLY(void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);)
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32) sp24;
    s32 sp20;

    _badata_entrypoint_3(arg0, &sp20, &sp24);
    baanim_playForDuration_loopSmooth(arg0, sp20, sp24);
    func_8009FFD8(arg0, 1, 1, 3, 2);
}

void bsdronewaitbabykaz_entrypoint_2(struct player_state_s *arg0) {
    s32 _plsu_entrypoint_1(s32);
    void func_80099B94(struct player_state_s *);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    void func_800F7B9C(BtIntPtr, u32);
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_8009E6EC(arg0);
    switch (temp_v0) {
    case 0x20:
    case 0x21:
    case 0x24:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
        func_80099B94(arg0);
        temp_v0_2 = _plsu_entrypoint_1(0x11);
        if (temp_v0_2 != -1) {
            func_800F7B9C(temp_v0_2, 0x87);
        }
        func_8009E830(arg0, 2);
        return;
    case 0x6B:
        func_80099B94(arg0);
        return;
    default:
        func_80099B94(arg0);
        break;
    case 0x15:
    case 0x1C:
    case 0x1D:
    case 0x1E:
        break;
    }
}

void bsdronewaitbabykaz_entrypoint_3(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    s32 _badata_entrypoint_34(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(struct player_state_s *));
    s32 _plsu_entrypoint_1(s32);
    BT_IDO_ONLY(s32 bs_setState(BtIntPtr, s32);) BT_NATIVE_ONLY(void bs_setState(struct player_state_s *, s32);)
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_plsu_entrypoint_1(0x11) == -1) {
        var_a1 = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, var_a1);
}
