#include "common.h"

#ifdef BT_NATIVE
#include "core2/geometry_callbacks.h"

GeometryVertex D_8012CEC4 BT_DATA(4, bss_core2bss2_1, 0x584);
#endif

BT_NATIVE_ONLY(void func_8010EF70(struct GeometryRenderData *, s32, void *, const f32 *);) BT_IDO_ONLY(void func_8010EF70();)
BT_NATIVE_ONLY(void func_8010F070(f32 *, s32 *, s32);) BT_IDO_ONLY(void func_8010F070();)
void func_8010F270(void);
BT_NATIVE_ONLY(void func_8010E2C4(struct GeometryRenderData *, s32, void *, const f32 *);) BT_IDO_ONLY(void func_8010E2C4();)
BT_NATIVE_ONLY(void func_8010E4C4(f32 *, s32 *, s32);) BT_IDO_ONLY(void func_8010E4C4();)
void func_8010E7F4(void);
BT_NATIVE_ONLY(void func_8010EECC(struct GeometryRenderData *, s32, void *, const f32 *);) BT_IDO_ONLY(void func_8010EECC();)
BT_NATIVE_ONLY(void func_8010F950(struct GeometryRenderData *, s32, void *, const f32 *);) BT_IDO_ONLY(void func_8010F950();)
BT_NATIVE_ONLY(void _trangler_entrypoint_0(struct GeometryRenderData *, s32, void *, const f32 *);) BT_IDO_ONLY(void _trangler_entrypoint_0();)

#ifdef BT_NATIVE
GeometryCallbacks D_80123030[5] BT_DATA(4, core2_1EFC920, 0x0) = {
#else
BtFnWord D_80123030[5][3] = {
#endif
    {BT_IDO_ONLY((BtFnWord))func_8010EF70, BT_IDO_ONLY((BtFnWord))func_8010F070, BT_IDO_ONLY((BtFnWord))func_8010F270},
    {BT_IDO_ONLY((BtFnWord))func_8010E2C4, BT_IDO_ONLY((BtFnWord))func_8010E4C4, BT_IDO_ONLY((BtFnWord))func_8010E7F4},
    {BT_IDO_ONLY((BtFnWord))func_8010EECC, 0, 0},
    {BT_IDO_ONLY((BtFnWord))func_8010F950, 0, 0},
    {BT_IDO_ONLY((BtFnWord))_trangler_entrypoint_0, 0, 0},
};

#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef void (*GeometryCommandCallback)(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC634(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC958(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DCF48(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD024(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC61C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD07C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD19C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD1C0(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD214(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD410(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD56C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDC28(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDDC4(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DE03C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DCEC8(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD65C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD728(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC628(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DE0D8(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDB38(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DE1C4(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD998(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC740(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DCB58(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD2E8(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD4AC(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDF14(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DC84C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DCD10(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD37C(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DD504(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDD14(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
void func_800DDFA0(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);

GeometryCommandCallback D_8012306C[25] BT_DATA(4, core2_1EFC920, 0x3C) = {
    func_800DC634, func_800DC958, func_800DCF48, func_800DD024,
    func_800DC61C, func_800DD07C, func_800DD19C, func_800DD1C0,
    func_800DD214, func_800DC61C, func_800DD410, func_800DC61C,
    func_800DD56C, func_800DDC28, func_800DDDC4, func_800DE03C,
    func_800DCEC8, func_800DD65C, func_800DD728, func_800DC628,
    func_800DC628, func_800DE0D8, func_800DDB38, func_800DE1C4,
    func_800DD998,
};
GeometryCommandCallback D_801230D0[25] BT_DATA(4, core2_1EFC920, 0xA0) = {
    func_800DC740, func_800DCB58, func_800DC628, func_800DD024,
    func_800DC61C, func_800DC628, func_800DD19C, func_800DD1C0,
    func_800DD2E8, func_800DC61C, func_800DD4AC, func_800DC61C,
    func_800DD56C, func_800DDC28, func_800DDF14, func_800DE03C,
    func_800DCEC8, func_800DD65C, func_800DC628, func_800DC628,
    func_800DC628, func_800DC628, func_800DC628, func_800DC628,
    func_800DC628,
};
GeometryCommandCallback D_80123134[25] BT_DATA(4, core2_1EFC920, 0x104) = {
    func_800DC84C, func_800DCD10, func_800DC628, func_800DD024,
    func_800DC61C, func_800DC628, func_800DD19C, func_800DD1C0,
    func_800DD37C, func_800DC61C, func_800DD504, func_800DC61C,
    func_800DD56C, func_800DDD14, func_800DDFA0, func_800DC628,
    func_800DCEC8, func_800DD65C, func_800DC628, func_800DC628,
    func_800DC628, func_800DC628, func_800DC628, func_800DC628,
    func_800DC628,
};
GeometryCommandCallback *D_80123198[6] BT_DATA(4, core2_1EFC920, 0x168) = {
    D_8012306C, D_801230D0, D_80123134, 0,
    0, 0,
};
#endif
