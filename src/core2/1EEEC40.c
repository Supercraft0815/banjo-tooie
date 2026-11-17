#include "core2/1EEEC40.h"

s32 func_80115350() 
{
    return 0x1C;
}    typedef struct { u8 pad0[0xC]; f32 unkC; f32 unk10; } Obj1EEEC40_func_80115358_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

f32 func_80115358(void *arg0, f32 arg1) {
    void *temp_v0;
    f32 bound;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x14)));
    bound = ((Obj1EEEC40_func_80115358_temp_v0 *)temp_v0)->unkC;
    if (arg1 < bound) {
        arg1 = bound;
    } else {
        bound = ((Obj1EEEC40_func_80115358_temp_v0 *)temp_v0)->unk10;
        if (bound < arg1) {
            arg1 = bound;
        }
    }
    return arg1;
}    typedef struct { u8 pad0[0x14]; void * unk14; } Obj1EEEC40_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8011539C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_80115428(void *arg0, f32 arg1, f32 arg2);
    f32 sqrtf(f32);

    *(f32 *)((s8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 0) = arg1;
    *(f32 *)((s8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 4) = arg2;
    *(f32 *)((s8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 8) = arg3;
    func_80115428(arg0, sqrtf(arg1 * arg1 + arg3 * arg3),
                  sqrtf(arg2 * arg2 + arg3 * arg3));
}

void func_80115428(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((((Obj1EEEC40_arg0 *)arg0)->unk14)) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((((Obj1EEEC40_arg0 *)arg0)->unk14)) + (0x18))) = arg2;
}

void func_80115444(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0xC)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0x10)));
}

f32 func_80115460(void *arg0) {
    return *(f32 *)((u8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 8);
}

f32 func_8011546C(void *arg0) {
    return *(f32 *)((u8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 0);
}

f32 func_80115478(void *arg0) {
    return *(f32 *)((u8 *)*&((Obj1EEEC40_arg0 *)arg0)->unk14 + 4);
}

void func_80115484(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_801154A4(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_801107F0(void *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 distance;
    f32 limit;

    limit = ((f32 *)arg0->backpack)[5];
    if (((f32 *)arg0->backpack)[3] < limit) {
        func_80115484(arg0, sp38);
        func_801107F0(arg0, sp44);
        func_800EFB24(sp2C, sp44, sp38);
        distance = func_800EEF94(sp2C);
            limit = ((f32 *)arg0->backpack)[5];
        if (limit < distance) {
            ((f32 *)arg0->backpack)[3] = limit;
        } else if (((f32 *)arg0->backpack)[3] < distance) {
            ((f32 *)arg0->backpack)[3] = distance;
        }
    } else {
        ((f32 *)arg0->backpack)[3] = limit;
    }
    ((f32 *)arg0->backpack)[4] =
        ((f32 *)arg0->backpack)[6];
}    typedef struct { u8 pad0[0xC]; f32 unkC; f32 unk10; f32 unk14; f32 unk18; } Obj1EEEC40_func_80115564_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80115564(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x14)));
    (((Obj1EEEC40_func_80115564_temp_v0 *)temp_v0)->unkC) = (f32) (((Obj1EEEC40_func_80115564_temp_v0 *)temp_v0)->unk14);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x14)));
    (((Obj1EEEC40_func_80115564_temp_v0 *)temp_v0)->unk10) = (f32) (((Obj1EEEC40_func_80115564_temp_v0 *)temp_v0)->unk18);
}

/* extern */

int func_80115580(void *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_801107F0(void *, f32 *);
    f32 sp1C[3];

    func_801107F0(arg0, sp1C);
    return func_800EEB40(sp1C, arg1) >
        ((*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x14) + 0x10) * 1.5f) *
         (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x14) + 0x10) * 1.5f));
}

f32 func_801155E8(void *arg0) {
    return (*(f32 *)((s8 *)((((Obj1EEEC40_arg0 *)arg0)->unk14)) + (0x10))) * 1.5f;
}
