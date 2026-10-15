#include "common.h"

OSThread *chnewshovel_entrypoint_0(void)
{
    extern u8 D_80800FB4_chnewshovel[];

    return (OSThread *) D_80800FB4_chnewshovel;
}

/* extern */

void func_8080000C_chnewshovel(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    s32 func_808007F8_chnewshovel(Actor *, s32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    func_808007F8_chnewshovel(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_8080004C_chnewshovel.s")

void func_80800310_chnewshovel(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800330_chnewshovel.s")

void func_80800570_chnewshovel(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32, s32, s32 *, s32);
    s32 _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
    s32 func_80101E14(s32, s32);
    s32 func_801022E4();
    s32 func_80800CC4_chnewshovel(s32);
    s32 func_80800D18_chnewshovel(s32);
    extern s32 D_80801008_chnewshovel;
    extern s32 D_80801018_chnewshovel;
    extern s32 D_80801024_chnewshovel;
    s32 temp_v0;

    temp_v0 = func_801022E4();
    if (temp_v0 != 0x1BA) {
        if (temp_v0 == 0x1BB) {
            _subaddieaudioquick_entrypoint_4(arg0, arg0 + 4, &D_80801008_chnewshovel, &D_80801018_chnewshovel);
            if (func_80101E14(arg0, 0x3F333333) != 0) {
                func_80800CC4_chnewshovel(arg0);
                func_80800D18_chnewshovel(arg0);
            }
        }
    } else {
        _subaddieaudioquick_entrypoint_3(arg0, arg0 + 4, &D_80801024_chnewshovel, 0x3ECCCCCD);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800610_chnewshovel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_808006B0_chnewshovel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_808007F8_chnewshovel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800930_chnewshovel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800A50_chnewshovel.s")

/* extern */

s32 func_80800B5C_chnewshovel(s32 arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80107B70(s32, f32 *);
    f32 sp1C[3];

    if (func_80107B70(arg0, sp1C) != 0) {
        return func_800EEB40((f32 *)(arg0 + 4), sp1C) < 10000.0f;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800BC0_chnewshovel.s")

/* extern */

int func_80800C58_chnewshovel(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u32 header[25];
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
        } flags;
    } NewShovelActor;
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80800BC0_chnewshovel(Actor *);
    NewShovelActor *actor = (NewShovelActor *)arg0;
    f32 *temp_a1;

    temp_a1 = (f32 *)actor->actor.actorData;
    if (actor->flags.unk64_29) {
        return func_80800BC0_chnewshovel(&actor->actor);
    }
    if (func_800EEB40(actor->actor.position, temp_a1) > 40000.0f) {
        return 0;
    }
    return 1;
}

s32 func_80800CC4_chnewshovel(s32 arg0) {
    s32 func_800DC298(f32);
    extern s32 D_80801064_chnewshovel;
    func_800C4B7C(func_800DC298(0.5f) ? 0x517 : 0x518);
    _subaddieaudioquick_entrypoint_2((Actor *) arg0, (f32 *) (arg0 + 4), &D_80801064_chnewshovel);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newshovel/func_80800D18_chnewshovel.s")

s32 func_80800DC8_chnewshovel(s32 arg0) {
    s32 func_80101074(s32 *);
    extern s32 D_808010B0_chnewshovel;
    func_80101074(&D_808010B0_chnewshovel);
    return 2;
}
