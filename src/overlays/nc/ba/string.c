#include "nc/ba/string.h"

s32 ncbastring_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbastring_entrypoint_1(BtIntPtr arg0) {
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(BtIntPtr arg0, s32 arg1);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C((s32 *) arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858((void *) arg0, 1);
    func_80115870((void *) arg0, 5.0f);
}

void ncbastring_entrypoint_2(s32 arg0) 
{
}
void func_8080007C_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void ncbastring_entrypoint_3(PlayerState *arg0) {
    f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(void *, f32);
    void func_80115444(void *, f32 *, f32 *);
    f32 func_80115750(Actor *, f32);
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp2C[2];
    f32 sp28;
    f32 sp24;

    func_8080007C_ncbastring(arg0, sp64);
    func_801107F0(arg0, sp4C);
    if (**(s32 **)((u8 *)arg0 + 0x5C) != 0) {
        sp38 = _ncbawaypoint_entrypoint_3(arg0, sp64, sp4C);
    } else {
        sp38 = 0.0f;
    }
    func_800EFB24(sp58, sp4C, sp64);
    sp34 = func_800EEF94(sp58) + sp38;
    func_800F1A88(sp58, sp2C);
    if (sp38 == 0.0f) {
        func_80113978(arg0, 1, 0);
    }
    sp3C = func_80115358(arg0, sp34);
    sp2C[0] = func_80115750(arg0, sp2C[0]);
    sp2C[1] = func_80112C3C(arg0, sp2C[1]);
    sp3C -= sp38;
    func_800EEBF0(sp58, sp2C, sp3C);
    func_800EE780(sp4C, sp64, sp58);
    if (func_80111CC8(arg0, sp4C) != 0) {
        if (func_801138A0(arg0) == 0) {
            func_80115444(arg0, &sp28, &sp24);
            func_801107F0(arg0, sp4C);
            sp3C = func_800EEAD4(sp4C, sp64);
            sp38 = sp24 * 1.5f;
            if ((sp38 < sp34) && (sp38 < sp3C) && (func_801138F4(arg0) != 0)) {
                func_80110F44(arg0);
            }
        } else if (func_801138F4(arg0) != 0) {
            func_80110F44(arg0);
        }
    }
    func_80800008_ncbastring(arg0, sp64);
    func_80110A68(arg0, sp40, sp64);
    func_80110790(arg0, sp40);
}    typedef struct { f32 unk0; f32 unk4; s8 unk8; } Objstring_ncbastring_entrypoint_4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void ncbastring_entrypoint_4(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_801107F0(void *, f32 *);
    void func_80115444(void *, f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    f32 temp_f0;
    void *temp_v0;

    func_8080007C_ncbastring(arg0, sp4C);
    func_801107F0(arg0, sp40);
    func_800EFB24(sp34, sp40, sp4C);
    temp_f0 = func_800EEF94(sp34);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))) = temp_f0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0))) = temp_f0;
    func_80115444(arg0, &sp30, &sp2C);
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    if ((((Objstring_ncbastring_entrypoint_4_temp_v0 *)temp_v0)->unk0) < sp30) {
        (((Objstring_ncbastring_entrypoint_4_temp_v0 *)temp_v0)->unk8) = 1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))) = sp2C;
        return;
    }
    if (sp2C < (((Objstring_ncbastring_entrypoint_4_temp_v0 *)temp_v0)->unk4)) {
        (((Objstring_ncbastring_entrypoint_4_temp_v0 *)temp_v0)->unk8) = 1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0))) = sp30;
        return;
    }
    (((Objstring_ncbastring_entrypoint_4_temp_v0 *)temp_v0)->unk8) = 0;
}
