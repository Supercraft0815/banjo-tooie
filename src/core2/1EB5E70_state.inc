#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EB5E70_state_native.inc"
#else
s32 func_800DF324()
{
    return D_8012C824;
}

void * func_800DF330(void) {
    extern u8 D_8012C840;
    return &D_8012C840;
}

s32 func_800DF33C(s32 arg0) {
    return ((s32 *)&D_8012C850)[arg0];
}

s32 func_800DF350()
{
    return D_8012C940;
}

void func_800DF35C(void) {
#ifndef BT_NATIVE
    void func_800ADF5C(void *);
#endif
    void func_8010E390(void);
    extern u8 D_8012C840;
    func_800ADF5C(*(s32 *)&D_8012C840);
    *(s32 *)&D_8012C840 = 0;
    func_8010E390();
}

void func_800DF38C(void) {
    BT_IDO_ONLY(extern f32 D_8012CE48[3];)
    extern u8 D_8012C840;
#ifndef BT_NATIVE
    s32 func_800ADF98(void);
#endif
    s32 func_8010E334(void);
    void func_800EFD24(f32 *);
    LookAtBuffer *buffer;
    void func_800DE318(void);
    func_800DE318();
    buffer = &D_8012CA40;
    buffer->current = buffer->buffer;
    buffer->end = buffer->current + 32;
    func_800EFD24(BT_DATA_FIELD(D_8012CA40.position, D_8012CE48));
    *(s32 *)&D_8012C840 = func_800ADF98();
    func_8010E334();
}

void func_800DF3E0(void) {
    s32 i;
    for(i = 0; i < 0x3C; i++){
        D_8012C850[i] = 0;
    }
}

void func_800DF410(s32 arg0) {
    extern s32 D_8012C9A4;
    *(s32 *)((u8 *)&D_8012C9A4 + 0) = arg0;
}

void func_800DF41C(s32 arg0) {
    *(s32 *)((u8 *)&D_8012C824 + 0) = arg0;
}

f32 func_800DF428(f32 arg0) {
    extern f32 D_8012C82C;
    f32 temp_f2;

    temp_f2 = D_8012C82C;
    D_8012C82C = arg0;
    return temp_f2;
}

void func_800DF440(s32 arg0) {
    extern s32 D_8012C828;
    if (arg0 != 0) {
        D_8012C828 = 1;
        return;
    }
    D_8012C828 = 0;
}

void func_800DF464(f32 arg0) {
    extern f32 D_8012C830;
    *(f32 *)((u8 *)&D_8012C830 + 0) = arg0;
}

void func_800DF470(s32 arg0) {
    extern s32 D_8012C834;
    *(s32 *)((u8 *)&D_8012C834 + 0) = arg0;
}

void func_800DF47C(s32 arg0, s32 arg1) {
    extern s32 D_8012C9A8;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (0))) = arg0;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (4))) = arg1;
}

void func_800DF490(s32 arg0, s32 arg1) {
    extern s32 D_8012C9A8;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (8))) = arg0;
    (*(s32 *)((s8 *)(&D_8012C9A8) + (0xC))) = arg1;
}

void func_800DF4A4(s32 arg0)
{

    BT_DATA_FIELD(D_8012C948.display_list, D_8012C960) = (DisplayListView *)arg0;
}

void func_800DF4B0(s32 arg0) {
    extern GeoCommandFunction *D_80123198[];
    D_8012CF8C = D_80123198[arg0];
}

void func_800DF4CC(s32 arg0) {
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9BC;
    D_8012C9B8 = 1;
    func_800EE7F8((f32 *)&D_8012C9BC, (f32 *)arg0);
}

void func_800DF500(f32 arg0, f32 arg1, f32 arg2) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9BC;
    D_8012C9B8 = 2;
    func_800EFA4C((f32 *)&D_8012C9BC, arg0, arg1, arg2);
}

void func_800DF540(s32 arg0) {
    s32 func_800F293C(s32 *, s32);
    extern s32 D_8012C9B8;
    extern s32 D_8012C9C8;
    D_8012C9B8 = 3;
    func_800F293C(&D_8012C9C8, arg0);
}

void func_800DF574(s32 arg0) {
    extern s16 D_8012CA38;
    *(s16 *)((u8 *)&D_8012CA38 + 0) = arg0;
}

void func_800DF580(void *arg0, void *arg1) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    D_8012C83C = 1;
    (*(s32 *)((s8 *)(&D_8012C988) + (0x10))) = (s32) (*(s32 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x14))) = (s32) (*(s32 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x18))) = (s32) (*(s32 *)((s8 *)(arg0) + (8)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0x1C))) = (s32) (*(s32 *)((s8 *)(arg0) + (0xC)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(&D_8012C988) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(&D_8012C988) + (8))) = (s32) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s32 *)((s8 *)(&D_8012C988) + (0xC))) = (s32) (*(s32 *)((s8 *)(arg1) + (0xC)));
}

void func_800DF5D8(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    D_8012C83C = 2;
    if ((s32) arg0 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x10))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x10))) = arg0;
    }
    if ((s32) arg1 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x14))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x14))) = arg1;
    }
    if ((s32) arg2 >= 0x100) {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x18))) = 0xFFU;
    } else {
        (*(u32 *)((s8 *)(&D_8012C988) + (0x18))) = arg2;
    }
    func_800DF410(arg3);
}

void func_800DF660(s32 arg0, s32 arg1, BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) arg2, s32 arg3) {
    extern s32 D_8012C838;
    extern s32 D_8012CA08; BT_NATIVE_ONLY(extern void *D_8012CA0C;) BT_NATIVE_ONLY(extern u8 D_8012CA11;)
    if ((arg1 == 0) && (arg2 == 0)) {
        D_8012C838 = 0;
        return;
    }
    D_8012C838 = 1;
    BT_DATA_FIELD(D_8012CA08, (*(s32 *)((s8 *)(&D_8012CA08) + (0)))) = arg1;
    BT_DATA_FIELD(D_8012CA0C, (*(s32 *)((s8 *)(&D_8012CA08) + (4)))) = arg2;
    BT_DATA_FIELD(D_8012CA11, (*(s8 *)((s8 *)(&D_8012CA08) + (9)))) = (s8) arg0;
    func_800DF410(arg3);
}

void func_800DF6BC(s32 arg0, s32 arg1) {
    extern s32 D_8012C83C;
    extern s32 D_8012C988;
    s32 var_v0;

    D_8012C83C = 3;
    if (arg0 >= 0x100) {
        var_v0 = 0xFF;
    } else {
        var_v0 = arg0;
    }
    (*(s32 *)((s8 *)(&D_8012C988) + (0xC))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (8))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (4))) = var_v0;
    (*(s32 *)((s8 *)(&D_8012C988) + (0))) = var_v0;
    func_800DF410(arg1);
}

void func_800DF714(BT_NATIVE_ONLY(Mtx *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C980;)

    BT_DATA_FIELD(D_8012C948.matrices, D_8012C980) = arg0;
}

void func_800DF720(BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C974;)

    BT_DATA_FIELD(D_8012C948.colors, D_8012C974) = arg0;
}

void func_800DF72C(BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C968;)

    BT_DATA_FIELD(D_8012C948.animation, D_8012C968) = arg0;
}

void func_800DF738(s32 arg0)
{
    extern s32 D_8012C844;

    D_8012C844 = arg0;
}

void func_800DF744(s32 arg0, s32 arg1) {
    D_8012C850[arg0] = arg1;
}

void func_800DF758(s32 *arg0) {
    s32 i;

    for (i = 1; i < 60; i++) {
        D_8012C850[i] = arg0[i];
    }
}

void func_800DF7C4(s32 arg0, s32 arg1) {
    D_8012C850[arg0] = -arg1;
}

void func_800DF7DC(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C95C;)

    BT_DATA_FIELD(D_8012C948.textures, D_8012C95C) = arg0;
}

void func_800DF7E8(u8 arg0) {
    BT_IDO_ONLY(extern s8 D_8012C96C;)
    BT_DATA_FIELD(D_8012C948.texture_animation, D_8012C96C) = arg0;
}

void func_800DF7F8(s32 arg0, f32 arg1, f32 arg2) {
    extern s32 D_8012CA18;
    (*(s32 *)((s8 *)(&D_8012CA18) + (0))) = arg0;
    (*(f32 *)((s8 *)(&D_8012CA18) + (4))) = arg1;
    (*(f32 *)((s8 *)(&D_8012CA18) + (8))) = arg2;
}

void func_800DF818(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C964;)

    BT_DATA_FIELD(D_8012C948.vertices, D_8012C964) = arg0;
}

void func_800DF824(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) arg0)
{
    BT_IDO_ONLY(extern s32 D_8012C978;)

    BT_DATA_FIELD(D_8012C948.normals, D_8012C978) = arg0;
}

void func_800DF830(s32 arg0)
{
    extern s32 D_8012CA28;

    D_8012CA28 = arg0;
}

void func_800DF83C(s32 arg0)
{
    extern s32 D_8012C848;

    D_8012C848 = arg0;
}

void func_800DF848(BT_NATIVE_ONLY(Gfx *) BT_IDO_ONLY(s32) arg0, BT_NATIVE_ONLY(Gfx *) BT_IDO_ONLY(s32) arg1) {
    extern s32 D_80122DC8[];
    extern s32 D_8012CA28;
    D_8012CA28 = 4;
    BT_DATA_FIELD(model_material_modes[D_8012CA28].opaque, D_80122DC8[D_8012CA28 * 2]) = arg0;
    BT_DATA_FIELD(model_material_modes[D_8012CA28].translucent, D_80122DC8[D_8012CA28 * 2 + 1]) = arg1;
}

void func_800DF874(void) {
    extern u8 D_8012C840;
    u8 *temp = *(u8 **) &D_8012C840;
    if (temp != 0) {
        *(s32 *) &D_8012C840 = func_800AE5F0(temp);
    }
    (void) func_8010E358();
}

s32 func_800DF8B4(s32 *arg0) {
    return arg0[7];
}

s32 func_800DF8BC(s32 *arg0) {
    return arg0[11];
}

f32 func_800DF8C4(f32 *arg0) {
    return arg0[0];
}

s32 func_800DF8CC(s32 *arg0) {
    return arg0[12];
}

int func_800DF8D4(s32 *arg0) {
    return arg0[8] != 0 && arg0[13] == 0;
}

s32 func_800DF8F8(s32 *arg0) {
    return arg0[1];
}

/* extern */

void func_800DF900(u8 *arg0) {
    void mlMtx_push_translation(f32 x, f32 y, f32 z);
    s32 func_8001980C(s32, s32, s32, s32);
    mlMtx_push_translation(0.0f, 0.0f, 0.0f);
    func_8001980C((*(s32 *)((s8 *)(arg0) + (4))), (*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (0xC))));
}

#endif
