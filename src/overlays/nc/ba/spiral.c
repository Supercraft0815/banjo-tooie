#include "core2/camera_state_callbacks.h"
#include "nc/ba/spiral.h"

s32 ncbaspiral_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}    typedef struct { u8 pad0[0x48]; s32 * unk48; } Objspiral_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void ncbaspiral_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *camera) BT_IDO_ONLY(void *arg0)) {
    BT_NATIVE_ONLY(void * arg0 = (void *)camera;)
    void func_800EFD24(f32 vec[3]);
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(BtIntPtr, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_800EFD24((s32 *)((s8 *)(((Objspiral_arg0 *)arg0)->unk48) + 4));
    *(((Objspiral_arg0 *)arg0)->unk48) = -1;
}

void ncbaspiral_entrypoint_2(struct player_state_s *arg0) {
}
/* extern */

void ncbaspiral_entrypoint_3(PlayerState *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    void func_80112D08(void *, s32, f32, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80115358(void *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(Actor *, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp24[2];
    f32 sp20;

    func_80800028_ncbaspiral(arg0, sp54);
    func_801107F0(arg0, sp3C);
    func_800EFB24(sp48, sp3C, sp54);
    sp2C = func_800EEF94(sp48);
    func_800F1A88(sp48, sp24);
    sp2C = func_80115358(arg0, sp2C);
    sp24[0] = func_80115750(arg0, sp24[0]);
    func_800F1E6C(*(f32 **)((s8 *)arg0 + 0x48) + 1, sp54, &sp20);
    func_80112D08(arg0, 5, sp20 - 10.0f, sp20 + 10.0f);
    sp24[1] = func_80112C3C(arg0, sp24[1]);
    func_800EEBF0(sp48, sp24, sp2C);
    func_800EE780(sp3C, sp54, sp48);
    if ((func_80111CC8(arg0, sp3C) != 0) && ((func_801138A0(arg0) != 0) || (func_80115580(arg0, sp54) != 0)) && (func_801138F4(arg0) != 0)) {
        func_80110F44(arg0);
    }
    func_80800008_ncbaspiral(arg0, sp54);
    func_80110A68(arg0, sp30, sp54);
    func_80110790(arg0, sp30);
}

/* extern */

void ncbaspiral_entrypoint_4(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32 *);
    func_800EE7F8(((Objspiral_arg0 *)arg0)->unk48 + 1);
    *(((Objspiral_arg0 *)arg0)->unk48) = -1;
}

/* extern */

void ncbaspiral_entrypoint_5(void *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_24(s32 *arg0);
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    u8 *func_800A5800(s32 id);
    void func_801107B0(void *, f32 *);
    s32 sp2C;
    f32 sp1C[4];

    if (arg1 != *(((Objspiral_arg0 *)arg0)->unk48)) {
        func_800A5800(arg1);
        _cadbfunc_entrypoint_24(&sp2C);
        func_801107B0(arg0, sp1C);
        _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(sp2C + 0x1D1, sp1C), (f32 *)((((Objspiral_arg0 *)arg0)->unk48) + 1));
        *(((Objspiral_arg0 *)arg0)->unk48) = arg1;
    }
}
