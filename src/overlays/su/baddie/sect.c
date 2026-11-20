#include "common.h"

/* extern */

s32 subaddiesect_entrypoint_0(Actor *arg0, s32 arg1, s32 arg2) {
    struct SectFlags {
        u8 pad0[0x70];
        BT_BITFIELD_ORDER(u32 pad70_4 : 28, u32 pad70_0 : 3);
        u32 unk70_3 : 1;
        BT_BITFIELD_ORDER(u32 pad70_0 : 3, u32 pad70_4 : 28);
    };
    s32 _gcmapsects_entrypoint_5(s32);
    void _subaddiefade_entrypoint_2(void *arg0);
    void func_8010381C(Actor *);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010A624(Actor *);
    void func_8010A63C(Actor *);
    if (_gcmapsects_entrypoint_5(arg1) == 0) {
        if ((arg2 & 1) && ((struct SectFlags *)arg0)->unk70_3) {
            func_8010381C(arg0);
        }
        if (arg2 & 2) {
            func_8010A570(arg0);
        }
        if (arg2 & 4) {
            func_8010A624(arg0);
        }
        if (arg2 & 8) {
            arg0->unk64_16 = 0;
        }
        return 0;
    }
    if (arg2 & 2) {
        func_8010A590(arg0);
    }
    if (arg2 & 4) {
        func_8010A63C(arg0);
    }
    if (arg2 & 8) {
        if ((arg2 & 0x10) && !arg0->unk64_16) {
            _subaddiefade_entrypoint_2(arg0);
        }
        arg0->unk64_16 = 1;
    }
    return 1;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) subaddiesect_entrypoint_1(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(BtIntPtr) arg0) {
    s32 _gcmapsects_entrypoint_4(f32 *point);
    BT_NATIVE_ONLY(return) _gcmapsects_entrypoint_4(BT_DATA_FIELD(arg0->position, arg0 + 0x4));
}

s32 subaddiesect_entrypoint_2(Actor *arg0, s32 arg1, s32 arg2) {
    s32 *_gcmapsects_entrypoint_25(void *, s32, f32 *, f32 *, f32 *, u32);
    void *func_800BF704(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    void func_801045AC(Actor *, f32 *, f32 *, s32);
    f32 upper[3];
    f32 lower[3];
    f32 normal[3];
    s32 *section;
    f32 rotation[3];

    func_800EE7F8(upper, arg0->position);
    func_800EE7F8(lower, arg0->position);
    upper[1] += 100.0f;
    lower[1] -= 100.0f;
    section = _gcmapsects_entrypoint_25(func_800BF704(), arg1, upper, lower, normal, arg0->unk14);
    if (section != NULL) {
        if (arg2 != 0) {
            arg0->position[1] = lower[1];
            if (func_800F1B78(rotation, normal, arg0->rotation[1], 1.0f)) {
                arg0->rotation[0] = rotation[0];
                arg0->rotation[2] = rotation[2];
            }
        }
        func_801045AC(arg0, normal, lower, section[2]);
        return 1;
    }
    return 0;
}
