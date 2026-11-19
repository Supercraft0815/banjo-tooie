#include "common.h"

typedef struct { s8 unk0; s8 unk1; s8 unk2; s8 unk3; s16 unk4; s16 unk6; u8 pad8[0x8]; f32 unk10; } Objitem_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) subaddieitem_entrypoint_0(u8 *arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    u8 *temp_a0;

    (((Objitem_arg0 *)arg0)->unk0) = 0;
    (((Objitem_arg0 *)arg0)->unk4) = arg1;
    (((Objitem_arg0 *)arg0)->unk6) = arg2;
    (((Objitem_arg0 *)arg0)->unk1) = arg3;
    (((Objitem_arg0 *)arg0)->unk2) = 0;
    (((Objitem_arg0 *)arg0)->unk3) = 0;
    temp_a0 = arg0 + 8;
    (*(f32 *)(temp_a0 + 8)) = 0.0f;
    BT_NATIVE_ONLY(return) _subaddielink_entrypoint_0(temp_a0, (u8 *) arg1);
}

void subaddieitem_entrypoint_1(s8 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

/* extern */

void subaddieitem_entrypoint_2(u8 *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    s32 func_80090658(s32, u8 *);
    func_80090658(1, arg0);
    (((Objitem_arg0 *)arg0)->unk3) = 1;
    (((Objitem_arg0 *)arg0)->unk0) = 1;
    (((Objitem_arg0 *)arg0)->unk10) = 0.0f;
    _subaddielink_entrypoint_0(arg0 + 8, arg0);
}

s32 subaddieitem_entrypoint_3(Actor *arg0, void *arg1, u8 *arg2) {
    s32 _subaddielink_entrypoint_0();
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    s32 _subaddielink_entrypoint_2(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    Unk80132ED0 *func_8008FDEC(void);
    s32 func_8008FE14(void);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_80090768(f32 *);
    s32 func_80090658();
    s32 func_80090818(void);
    f32 func_800D8FF8(void);
    void func_80103DFC(Actor *, f32 *);
    void func_80800224_subaddieitem(Actor *, u8 *, Actor *);
    s32 result;
    f32 position[3];

    result = 0;
    *(f32 *)(arg2 + 0x10) += func_800D8FF8();
    switch (arg2[0]) {
        case 1:
            if (func_800902E4(arg0->position, (f32)*(s16 *)(arg2 + 6),
                             *(s16 *)(arg2 + 4), &arg0) &&
                func_8008FE14() == *(s16 *)(arg2 + 4) &&
                func_80090818()) {
                if (arg1 == NULL) {
                    arg1 = position;
                    func_80103DFC(arg0, position);
                }
                _subaddielink_entrypoint_1(arg2 + 8, func_8008FDEC());
                func_80090768(arg1);
                arg2[0] = 2;
            }
            break;
        case 2:
            if (!_subaddielink_entrypoint_2(arg2 + 8)) {
                func_80800224_subaddieitem(arg0, arg2, NULL);
            } else {
                arg1 = _subaddielink_entrypoint_4(arg2 + 8);
                if (!((Actor *)arg1)->unk64_22 && !((Actor *)arg1)->unk64_23) {
                    func_80800224_subaddieitem(arg0, arg2, arg1);
                }
            }
            break;
        case 3:
            if (arg2[3]) {
                func_80090658(0);
                arg2[3] = 0;
            }
            _subaddielink_entrypoint_0(arg2 + 8);
            arg2[0] = 0;
            result = 1;
            break;
    }
    return result;
}

void func_80800224_subaddieitem(Actor *arg0, u8 *arg1, Actor *arg2) {
    s32 _subaddielink_entrypoint_0();
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    s32 func_800D1B34(s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    u32 flags;

    flags = arg1[1];
    if (flags & 2) {
        func_800FC660(0xE);
        flags = arg1[1];
    }
    if ((flags & 1) && arg2 != NULL) {
        func_800FFAB0(arg2);
    }
    _subaddielink_entrypoint_0(arg1 + 8);
    if (arg1[2] != 0) {
        func_800D175C(func_800D1B34(*(s16 *)(arg1 + 4)), -(s32)arg1[2]);
    }
    func_8010108C(arg0, 0x2D, *(s16 *)(arg1 + 4));
    arg1[0] = 3;
}
