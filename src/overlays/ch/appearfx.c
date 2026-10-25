#include "common.h"

OSThread *chappearfx_entrypoint_0(void)
{
    extern u8 D_80800990_chappearfx[];

    return (OSThread *) D_80800990_chappearfx;
}

void func_8080000C_chappearfx(s32 arg0) 
{
}
void func_80800014_chappearfx(Actor *arg0) {
    typedef struct {
        s16 unk0, unk2, unk4, unk6, unk8, unkA;
        f32 unkC;
        s32 unk10;
    } Particle;
    typedef struct {
        s16 count, unk2;
        u16 flags;
        s16 unk6, limit, unkA;
        s8 alpha, active;
        u8 padE[6];
        u8 link[8];
        Particle particles[1];
    } AppearData;
    void *func_80100094(Actor *, u32);
    void func_80800554_chappearfx(Actor *);
    f32 func_800D8FF8(void);
    s32 _subaddielink_entrypoint_2(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FCAE0(u32, u32, u32);
    void func_800FCA90(u32);
    void func_80101FDC(Actor *, u32);
    void rare_memcpy(void *, void *, int);
    s32 pad[3];
    s32 i;
    f32 dt;
    s16 remaining;
    s32 done;
    AppearData *data;
    Particle *particle;
    Particle *particles;
    u8 *link;

    data = func_80100094(arg0, 0);
    if (!func_8001210C(1)) {
        func_80800554_chappearfx(arg0);
    }
    switch (arg0->unk70_10) {
        case 1:
            data->active = 1;
            func_800FCAE0(0x1C, -1, 500);
            if (func_800D9078(&arg0->unk58)) {
                func_80101FDC(arg0, 2);
                arg0->unk58 = 1.2f;
            }
            break;
        case 2:
            done = func_800D9078(&arg0->unk58);
            data->alpha = (u32)func_800F10B4(arg0->unk58, 0.0f, 1.2f, 16.0f, 255.0f);
            if (done) {
                data->active = 0;
                func_800FCAE0(0x1C, 0, 500);
                func_800FCA90(0x1C);
                func_800FFAB0(arg0);
            } else {
                data->active = 1;
                func_800FCAE0(0x1C, -1, 500);
            }
            break;
    }
    link = data->link;
    if ((data->flags & 8) && _subaddielink_entrypoint_2(link)) {
        func_800EE7F8(arg0->position, _subaddielink_entrypoint_4(link)->position);
    }
    particles = data->particles;
    dt = func_800D8FF8();
    particle = particles;
    i = 0;
    if (data->count > 0) {
      do {
        particle->unk8 = (s32)(particle->unk8 + dt * particle->unk2);
        particle->unk6 = (s32)(particle->unk6 + dt * particle->unk0);
        particle->unkC += dt * particle->unkA;
        if (particle->unk8 >= data->limit) {
            data->count--;
            remaining = data->count;
            if (remaining > 0) {
                rare_memcpy(particle, &particles[remaining], sizeof(Particle));
            }
            remaining = data->count;
        } else {
            remaining = data->count;
            particle++;
            i++;
        }
      } while (i < remaining);
    }
}

void func_8080031C_chappearfx(Actor *arg0) {
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0xD))) != 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0xD))) = 0U;
        func_800FCAE0(0x1CU, 0U, 0x1F4U);
        func_800FCA90(0x1CU);
    }
}

/* extern */
s32 func_80800360_chappearfx(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    if (arg1 == 0x95) {
        _subaddielink_entrypoint_3((u8 *)func_80100094(arg0, 0U) + 0x14);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/func_808003A0_chappearfx.s")

void func_80800554_chappearfx(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    typedef struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        s16 unkA;
        f32 unkC;
        f32 unk10;
    } AppearParticle;
    typedef struct {
        s16 count;
        s16 capacity;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        s16 unkA;
        u8 unkC[0x10];
        AppearParticle particles[1];
    } AppearData;
    f32 padding[2];
    f32 sp2C;
    AppearParticle *particle;
    AppearData *data;

    data = func_80100094(arg0, 0);
    if (data->count < data->capacity) {
        particle = &data->particles[data->count];
        particle->unk6 = (s32)func_800DC178(0.0f, 359.0f);
        particle->unk0 = func_800DC128(250, 350);
        sp2C = func_800F10B4(data->unk8 - data->unkA, 0.0f, 500.0f, 30.0f, 350.0f);
        particle->unk2 = (s32)(func_800DC178(0.8f, 1.2f) * sp2C);
        particle->unk8 = data->unkA;
        particle->unk4 = func_800DC298(0.5f);
        particle->unk10 = func_800DC178(0.8f, 1.4f);
        particle->unkC = func_800DC178(0.0f, 360.0f);
        particle->unkA = func_800DC128(-200, 200);
        data->count++;
    }
}

void chappearfx_entrypoint_1(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    extern s32 _chappearfx_entrypoint_3;
    _chbaddiesetup_entrypoint_4(&_chappearfx_entrypoint_3, *arg0, arg1, arg2, arg3);
}

/* extern */

void chappearfx_entrypoint_2(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 chappearfx_entrypoint_3(s32, s32, s32);
    chappearfx_entrypoint_3(*arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/appearfx/chappearfx_entrypoint_3.s")
