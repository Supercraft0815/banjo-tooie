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

/* extern */

void func_801017D0(Actor *arg0) {
    s32 func_8010108C(Actor *, s32, s32);
    s32 func_801039E4(s32);
    s32 sp18[2];
    s32 temp_v0;

    temp_v0 = func_801039E4((s32)arg0->unk0);
    sp18[0] = temp_v0;
    func_8010108C(arg0, 0x1F, sp18[0]);
}

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

void func_801018A4(Actor *arg0, s32 arg1) {
    func_80101970(arg0);
    func_80101808(arg0, (s32 (*)(Actor *)) func_801017D0);
}

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

int func_80101970(Actor *arg0) {
    typedef struct {
        u8 pad0[0x70];
        u32 pad70_21 : 11;
        u32 flag70_20 : 1;
        u32 pad70_0 : 20;
        u8 pad74[0x20];
        u32 pad94_31 : 1;
        u32 flag94_30 : 1;
        u32 pad94_0 : 30;
    } ActorRenderFlags;
    typedef struct {
        u8 pad0[0x1A];
        u16 unk1A;
    } RenderSettings;
    s32 func_800D2F20(void);
    f32 func_800DF428(f32);
    void func_800DF440(s32);
    void func_800DF470(s32);
    s32 func_800EA068(s32);
    void *func_80100368(void *);
    extern f32 D_80126430;
    f32 value;
    f32 fallback;

    func_800DF470(((ActorRenderFlags *)arg0)->flag70_20);
    value = (u32)((RenderSettings *)func_80100368(arg0))->unk1A;
    if (value != 0.0f) {
        func_800DF428(value);
    } else if (!(arg0->unk0->unk10 & 1)) {
        if (func_800EA068(0x200)) {
            fallback = D_80126430;
        } else {
            fallback = func_800D2F20();
        }
        func_800DF428(fallback);
    }
    if (((ActorRenderFlags *)arg0)->flag94_30) {
        func_800DF440(0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101A50.s")

/* extern */

void func_80101BA0(s32 arg0) {
    s32 func_800DF744(s32, s32);
    func_800DF744(1, 4);
    func_800DF744(2, 4);
}
