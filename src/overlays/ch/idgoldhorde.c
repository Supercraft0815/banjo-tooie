#include "common.h"

OSThread *chidgoldhorde_entrypoint_0(void)
{
    extern ActorData D_808001F0_chidgoldhorde[];

    return (OSThread *) D_808001F0_chidgoldhorde;
}

/* extern */

void func_8080000C_chidgoldhorde(Actor *arg0) {
    s16 _glidmake_entrypoint_3(s32 *arg0, s32 arg1);
    void *func_800BEA88(s32 i);
    void *func_80100094(Actor *, u32);
    struct {
        s16 unk0;
        s16 unk2;
        s32 unk4;
        f32 unk8;
    } *sp24;
    s32 pad[2];

    sp24 = func_80100094(arg0, 0);
    sp24->unk2 = _glidmake_entrypoint_3(func_800BEA88(0),
        (sp24->unk0 = arg0->unk74_7, sp24->unk0));
    sp24->unk8 = arg0->rotation[1] * 0.0027777778f;
    arg0->unk64_16 = 0;
}

void chidgoldhorde_entrypoint_1(s16 *arg0, s32 arg1, Unk80132ED0 *arg2, s8 *arg3) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        f32 unk8;
    } *data;
    s32 i;
    f32 sp34[3];
    f32 sp28[3];

    data = func_80100094(func_80106790(arg2), 0);
    if (data->unk4++ == data->unk6) {
        func_800EE88C(sp34, arg0);
        for (i = 0; i < 3; i++) {
            sp28[i] = arg3[i] * 0.39370078f;
        }
        func_800EF04C(sp34, sp28);
        _fxsparkle_entrypoint_1(sp34, 9);
    }
}

void func_8080015C_chidgoldhorde(Actor *arg0) {
    void _glid_entrypoint_3(u8 *arg0, s32 arg1, s32 (*arg2)(u8 *, u8 *, s32, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
#ifndef BT_NATIVE
    extern s32 _chidgoldhorde_entrypoint_1;
#endif
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        f32 unk8;
    } *temp_s0;
    BtIntPtr sp20;

    temp_s0 = func_80100094(arg0, 0);
    if (func_800DC0C0() < temp_s0->unk8) {
        sp20 = func_800BEA88(0);
        temp_s0->unk4 = 0;
        temp_s0->unk6 = func_800DC128(0, temp_s0->unk2);
        _glid_entrypoint_3(sp20, temp_s0->unk0, &_chidgoldhorde_entrypoint_1, arg0->unk0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/idgoldhorde.data.s */
void func_80102EC0();
void func_8010A730();
void func_80107C2C();
ActorData D_808001F0_chidgoldhorde [1] BT_DATA(4, overlays_ch_idgoldhorde, 0x0) = { { 344, 445, 0, 1, 0, (void (*)(struct Actor *))func_8080015C_chidgoldhorde, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 12, 0, (void (*)(struct Actor *))func_8080000C_chidgoldhorde, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8706, 0, 0 } };
