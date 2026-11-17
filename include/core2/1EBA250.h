#ifndef __CORE2_1EBA250_H__
#define __CORE2_1EBA250_H__

#include <ultra64.h>

typedef struct {
    f32 unk0;
    f32 unk4[3];
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
} Unkfunc_800E0960_2;

typedef struct {
    Unkfunc_800E0960_2* unk0;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 padB;
    f32 unkC;
    s32 unk10[4];
} Unkfunc_800E0960_1;

Unkfunc_800E0960_1 *func_800E0A28(s16);
void func_800E0ACC(Unkfunc_800E0960_1 *);
void func_800E0AF0(Unkfunc_800E0960_1 *, f32);
void func_800E0AFC(Unkfunc_800E0960_1 *, u8, f32, f32, f32, f32);
void func_800E0B8C(Unkfunc_800E0960_1 *, u8, f32, f32, f32, f32);
#ifdef BT_NATIVE
void *func_800E0960(s32);
s16 func_800E09B8(s32);
void func_800E0A50(void *);
void func_800E0A70(s16);
Unkfunc_800E0960_1 *func_800E0A98(Unkfunc_800E0960_1 *);
void func_800E0AC0(Unkfunc_800E0960_1 *);
void func_800E0C20(Unkfunc_800E0960_1 *,u8,f32,f32,f32,f32);
void func_800E0CB4(Unkfunc_800E0960_1 *,u8,f32[4]);
void func_800E0E94(Unkfunc_800E0960_1 *,u8,f32[3]);
void func_800E0FE8(Unkfunc_800E0960_1 *,u8,f32[3]);
#endif

#endif // __CORE2_1EBA250_H__
