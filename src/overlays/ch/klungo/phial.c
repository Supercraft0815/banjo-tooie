#include "common.h"

OSThread *chklungophial_entrypoint_0(void)
{
    extern u8 D_80800C30_chklungophial[];

    return (OSThread *) D_80800C30_chklungophial;
}

OSThread *chklungophial_entrypoint_1(void)
{
    extern u8 D_80800C78_chklungophial[];

    return (OSThread *) D_80800C78_chklungophial;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800018_chklungophial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800204_chklungophial.s")

/* extern */

s32 func_8080038C_chklungophial(s32 arg0, s32 arg1, volatile s32 arg2) {
    s32 func_808003C8_chklungophial(s32, s32);
    int ret;
    if (arg1 == 0x40) {
        func_808003C8_chklungophial(arg0, 0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_808003C8_chklungophial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_808006B4_chklungophial.s")

void func_80800820_chklungophial(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800828_chklungophial.s")

s32 func_80800980_chklungophial(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor*, u32);
    switch (arg1) {
        case 0x4F:
            func_80101FDC(arg0, 2U);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_808009BC_chklungophial(Actor *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    void func_800E24D8(s32);
    void func_800E2530(f32);
    void func_800E2588(u32);
    s32 func_800E2594(s32, s32);
    s32 func_800E2720(s32, s32, s32, f32 *, f32 *, s32);
    void func_800E2A14(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    struct PhialEntry {
        f32 position[3];
        f32 scale;
        f32 elapsed;
        f32 duration;
        f32 speed;
        f32 height;
        f32 angle;
    };
    struct PhialData {
        s32 count;
        struct PhialEntry entries[50];
    } *temp_v0;
    f32 temp_f0;
    s32 temp_s1;
    s32 var_s1;
    f32 sp4C[3];
    struct PhialEntry *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    var_s0 = temp_v0->entries;
    arg0->unk7C_12 = 1;
    if (temp_v0->count != 0) {
        temp_s1 = func_800D674C(0x9CF);
        func_800E2588(1);
        func_800E2594(arg1, temp_s1);
        func_800E24D8(1);
        var_s1 = 0;
        if (temp_v0->count > 0) {
            do {
                if (var_s0->duration == 0.0f) {
                    temp_f0 = var_s0->speed;
                    func_800EFA4C(sp4C, temp_f0, temp_f0, temp_f0);
                    func_800E2530(var_s0->angle);
                    func_800E2720(arg1, (s32) var_s0->elapsed, 0, var_s0->position, sp4C, 0xFF);
                }
                var_s1 += 1;
                var_s0++;
            } while (var_s1 < temp_v0->count);
        }
        func_800E2A14(arg1);
    }
}

/* extern */

s32 func_80800AEC_chklungophial(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct PhialEntry {
        f32 position[3];
        f32 scale;
        f32 elapsed;
        f32 duration;
        f32 speed;
        f32 height;
        f32 angle;
    };
    struct PhialData {
        s32 count;
        struct PhialEntry entries[50];
    } *temp_v0;
    struct PhialEntry *temp_s0;

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0->count == 0x32) {
        return 0;
    }
    temp_s0 = &temp_v0->entries[temp_v0->count];
    bzero(temp_s0, 0x24);
    func_800EE7F8(temp_s0->position, arg1);
    temp_s0->scale = func_800DC178(0.55f, 1.25f);
    temp_s0->elapsed = 0.0f;
    temp_s0->duration = arg2;
    temp_s0->speed = func_800DC178(0.85f, 1.15f);
    temp_s0->height = func_800DC178(40.0f, 80.0f);
    temp_s0->angle = func_800DC178(0.0f, 359.0f);
    temp_v0->count += 1;
    return 1;
}
