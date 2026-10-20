#include "common.h"

void subaddieitem_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    u8 *temp_a0;

    (*(s8 *)((s8 *)(arg0) + (0))) = 0;
    (*(s16 *)((s8 *)(arg0) + (4))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (6))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg3;
    (*(s8 *)((s8 *)(arg0) + (2))) = 0;
    (*(s8 *)((s8 *)(arg0) + (3))) = 0;
    temp_a0 = arg0 + 8;
    (*(f32 *)(temp_a0 + 8)) = 0.0f;
    _subaddielink_entrypoint_0(temp_a0, (u8 *) arg1);
}

void subaddieitem_entrypoint_1(s8 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

/* extern */

void subaddieitem_entrypoint_2(u8 *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    s32 func_80090658(s32, u8 *);
    func_80090658(1, arg0);
    (*(s8 *)((s8 *)(arg0) + (3))) = 1;
    (*(s8 *)((s8 *)(arg0) + (0))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = 0.0f;
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
    s32 func_80090768(f32 *);
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
    void func_800D175C(s32, s32);
    s32 func_800D1B34(s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, s32);
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
