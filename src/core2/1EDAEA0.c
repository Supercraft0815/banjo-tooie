#include "core2/1EDAEA0.h"


void* func_800DE448(f32*, f32*, f32, f32*, s32);
void func_800DF47C(s32 (*arg0)(Actor*), Actor*);
f32* func_801018D8(Actor*);
f32* func_801027F4(Actor*);
s32 func_801015D0(Actor*);

OSThread *func_801015B0(void)
{
    extern u8 D_80135A90[];

    return (OSThread *) D_80135A90;
}

void func_801015BC(void) {
    extern s16 D_80135A94;
    D_80135A94 = 0;
}

void func_801015C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801015D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801017D0.s")

// the real actor_draw?
void func_80101808(Actor* arg0, s32 (*arg1)(Actor*)) {
    s32 pad[2];
    f32* sp2C;
    f32* sp28;

    func_800DF47C(arg1, arg0);
    sp28 = func_801027F4(arg0);
    sp2C = func_801018D8(arg0);
    func_800DE448(arg0->position, sp28, arg0->scale, sp2C, func_8010347C(arg0->unk0));
}

void func_80101870(Actor* arg0, void* arg1) {
    func_80101970(arg0);
    func_80101808(arg0, func_801015D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801018A4.s")

f32 *func_801018D8(Actor *arg0) {
    f32 *func_80101918(f32);
    f32 *var_v1;

    if ((*(u16 *)((s8 *)(arg0) + 0x94)) & 1) {
        var_v1 = func_80101918(arg0->scale);
    } else {
        var_v1 = NULL;
    }
    return var_v1;
}

f32 *func_80101918(f32 arg0) {
    extern f32 D_801243E0[];
    D_801243E0[1] = -4.0f / arg0;
    return D_801243E0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101A50.s")

/* extern */

void func_80101BA0(s32 arg0) {
    s32 func_800DF744(s32, s32);
    func_800DF744(1, 4);
    func_800DF744(2, 4);
}
