#include "core2/1E93440.h"

/* extern */

void func_800B9B50(void *arg0, void *arg1) {
    f32 func_800DC0C0();
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE940(s16 *, f32 *);
    s32 func_800EEDA0(u8 *, u8 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800EF368(f32 *, f32);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 func_800F0E44(s32);
    struct ParticleFlags { u8 pad[0x39]; u8 active:1; u8 rest:7; };
    s32 i;
    f32 spB0[3];
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 zero;
    f32 sp60;
    f32 sp5C;
    s16 temp_a0;
    s32 temp_s0;
    s32 temp_s1;

    for (i = 0; i < 3; i++) {
        ((s16 *)arg1)[i] = func_800DC128(((s16 *)arg0)[0x1A + i], ((s16 *)arg0)[0x1D + i]);
    }
    (*(s8 *)((s8 *)(arg1) + (0x38))) = (s8) (*(u16 *)((s8 *)(arg0) + (0xA8)));
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) == 0.0f) {
        (*(f32 *)((s8 *)(arg1) + (0xC))) = 1.0f;
    } else {
        (*(f32 *)((s8 *)(arg1) + (0xC))) = 0.0;
    }
    (*(s16 *)((s8 *)(arg1) + (0x2C))) = (s16) (s32) (func_800DC178((f32) (*(s16 *)((s8 *)(arg0) + (0x84))), (f32) (*(s16 *)((s8 *)(arg0) + (0x86)))) * 256.0f);
    (*(s16 *)((s8 *)(arg1) + (0x2E))) = (s16) (s32) (func_800DC178((*(f32 *)((s8 *)(arg0) + (0x78))), (*(f32 *)((s8 *)(arg0) + (0x7C)))) * 256.0f);
    switch (*(u8 *)((u8 *)arg0 + 5)) {
    case 0:
        if ((*(u16 *)((s8 *)(arg0) + (0))) & 0x40) {
            func_800EE88C(spB0, (s16 *)((u8 *)arg0 + 0x28));
            func_800EE88C(spA4, (s16 *)((u8 *)arg0 + 0x2E));
            func_800EFE50(sp98, spB0, spA4, func_800DC0C0());
            func_800EE940((s16 *)((u8 *)arg1 + 6), sp98);
        } else {
            for (i = 0; i < 3; i++) {
                ((s16 *)arg1)[3 + i] = ((s16 *)arg0)[9 + i] + func_800DC128(((s16 *)arg0)[0x14 + i], ((s16 *)arg0)[0x17 + i]);
            }
        }
        break;
    case 1:
        func_800EE88C(sp8C, (s16 *)((u8 *)arg0 + 0x12));
        sp60 = (sp5C = func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 359.0f));
        func_800EF214(sp8C, sp5C, sp60, (f32) func_800DC128((*(s16 *)((s8 *)(arg0) + (0x28))), (*(s16 *)((s8 *)(arg0) + (0x2A)))));
        func_800EE940((s16 *)((u8 *)arg1 + 6), sp8C);
        break;
    case 2:
        func_800EE88C(sp80, (s16 *)((u8 *)arg0 + 0x12));
        sp60 = func_800DC178(0.0f, 359.9f);
        func_800EF1B8(sp80, sp60, (f32) func_800DC128((*(s16 *)((s8 *)(arg0) + (0x28))), (*(s16 *)((s8 *)(arg0) + (0x2A)))));
        func_800EE940((s16 *)((u8 *)arg1 + 6), sp80);
        *(s16 *)((u8 *)arg1 + 8) += func_800DC128(*(s16 *)((u8 *)arg0 + 0x2E), *(s16 *)((u8 *)arg0 + 0x2C));
        break;
    }
    (*(s16 *)((s8 *)(arg1) + (0x30))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (0x9A))), (*(s16 *)((s8 *)(arg0) + (0x9C))));
    (*(s16 *)((s8 *)(arg1) + (0x32))) = (s16) (*(s16 *)((s8 *)(arg1) + (0x30)));
    temp_a0 = (*(s16 *)((s8 *)(arg0) + (0x9E)));
    if ((temp_a0 == 0) && ((*(s16 *)((s8 *)(arg0) + (0xA0))) == 0)) {
        (*(s16 *)((s8 *)(arg1) + (0x34))) = 0;
    } else {
        (*(s16 *)((s8 *)(arg1) + (0x34))) = (s16) (func_800DC128(temp_a0, (*(s16 *)((s8 *)(arg0) + (0xA0)))) - (*(s16 *)((s8 *)(arg1) + (0x32))));
    }
    if ((*(u16 *)arg0) & 0x400) {
        for (i = 0; i < 3; i++) {
            ((f32 *)arg1)[4 + i] = func_800DC178(0.0f, 360.0f);
        }
    } else {
        func_800EFA4C((f32 *)((u8 *)arg1 + 0x10), (f32) (*(s16 *)((s8 *)(arg0) + (0x4C))), (f32) (*(s16 *)((s8 *)(arg0) + (0x4E))), (f32) (*(s16 *)((s8 *)(arg0) + (0x50))));
    }
    for (i = 0; i < 3; i++) {
        ((s16 *)arg1)[0x10 + i] = func_800DC128(((s16 *)arg0)[0x20 + i], ((s16 *)arg0)[0x23 + i]);
    }
    (*(f32 *)((s8 *)(arg1) + (0x1C))) = 0.0f;
    (*(s16 *)((s8 *)(arg1) + (0x36))) = (s16) (func_800DC128((*(s16 *)((s8 *)(arg0) + (0xA2))), (*(s16 *)((s8 *)(arg0) + (0xA4)))) + 1);
    switch (*(u8 *)((u8 *)arg0 + 4)) {
    case 0:
        for (i = 0; i < 3; i++) {
            ((s16 *)arg1)[0x13 + i] = func_800DC128(((s16 *)arg0)[0x62 + i], ((s16 *)arg0)[0x65 + i]);
        }
        break;
    case 1:
        temp_s0 = func_800F0E44((*(s16 *)((s8 *)(arg0) + (0xC8))) + func_800DC128(0, func_800F0E44((*(s16 *)((s8 *)(arg0) + (0xCA))) - (*(s16 *)((s8 *)(arg0) + (0xC8))))));
        temp_s1 = func_800F0E44((*(s16 *)((s8 *)(arg0) + (0xC4))) + func_800DC128(0, func_800F0E44((*(s16 *)((s8 *)(arg0) + (0xC6))) - (*(s16 *)((s8 *)(arg0) + (0xC4))))));
        zero = 0.0;
        func_800EF4E4(sp74, (f32) temp_s0, (f32) temp_s1, zero, zero, (f32) func_800DC128((*(s16 *)((s8 *)(arg0) + (0xCC))), (*(s16 *)((s8 *)(arg0) + (0xCE)))));
        func_800EE940((s16 *)((u8 *)arg1 + 0x26), sp74);
        break;
    case 2:
        if (func_800EEDA0((u8 *)arg1 + 6, (u8 *)arg0 + 0xC8) == 0) {
            if ((*(u16 *)((s8 *)(arg0) + (0))) & 0x8000) {
                sp68[0] = (f32) ((*(s16 *)((s8 *)(arg0) + (0xC8))) - (*(s16 *)((s8 *)(arg1) + (6))));
                sp68[1] = (f32) ((*(s16 *)((s8 *)(arg0) + (0xCA))) - (*(s16 *)((s8 *)(arg1) + (8))));
                sp68[2] = (f32) ((*(s16 *)((s8 *)(arg0) + (0xCC))) - (*(s16 *)((s8 *)(arg1) + (0xA))));
            } else {
                sp68[0] = (f32) ((*(s16 *)((s8 *)(arg1) + (6))) - (*(s16 *)((s8 *)(arg0) + (0xC8))));
                sp68[1] = (f32) ((*(s16 *)((s8 *)(arg1) + (8))) - (*(s16 *)((s8 *)(arg0) + (0xCA))));
                sp68[2] = (f32) ((*(s16 *)((s8 *)(arg1) + (0xA))) - (*(s16 *)((s8 *)(arg0) + (0xCC))));
            }
            func_800EF368(sp68, func_800DC178((f32) (*(s16 *)((s8 *)(arg0) + (0xC4))), (f32) (*(s16 *)((s8 *)(arg0) + (0xC6)))));
            func_800EE940((s16 *)((u8 *)arg1 + 0x26), sp68);
        } else {
            (*(s16 *)((s8 *)(arg1) + (0x2A))) = 0;
            (*(s16 *)((s8 *)(arg1) + (0x26))) = (s16) (*(s16 *)((s8 *)(arg1) + (0x2A)));
            (*(s16 *)((s8 *)(arg1) + (0x28))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (0xC4))), (*(s16 *)((s8 *)(arg0) + (0xC6))));
        }
        break;
    }
    ((struct ParticleFlags *)arg1)->active = 1;
    if ((*(u16 *)((s8 *)(arg0) + (0))) & 8) {
        (*(s8 *)((s8 *)(arg0) + (0x52))) = 0;
    }
    if ((*(u16 *)((s8 *)(arg0) + (0))) & 0x10) {
        (*(s8 *)((s8 *)(arg0) + (0x53))) = 0;
    }
}

s32 func_800BA198(void *arg0) {
    s32 temp_v1;

    if (arg0 != NULL) {
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x90)));
        if (temp_v1 != 0) {
            return (s32) (temp_v1 - (*(s32 *)((s8 *)(arg0) + (0x8C)))) / 60;
        }
    }
    return 0;
}

void func_800BA1D0(s32 emitter, f32 position[3], f32 velocity[3], s32 count) {
    void func_800EE940(s16 *, f32 *);
    *(u16 *)emitter |= 0x40;
    func_800EE940((s16 *)(emitter + 0x28), position);
    func_800EE940((s16 *)(emitter + 0x2E), velocity);
    *(u8 *)(emitter + 5) = 0;
    func_800BA22C(emitter, count);
}

void func_800BA22C(s32 arg0, s32 n) {
    typedef u8 Particle[0x3C];
    typedef struct { u8 pad0[0x90]; Particle *end; Particle *capacity; } EmitterView;
    void func_800B9B50(void *, void *);
    EmitterView *this = (EmitterView *)arg0;
    for (; n > 0; n--) {
        if (this->end < this->capacity) func_800B9B50(this, this->end++);
    }
}

int func_800BA28C(void *arg0) {
    return ((*(s32 *)((s8 *)arg0 + 0x90) -
             *(s32 *)((s8 *)arg0 + 0x8C)) / 60 == 0) &&
           (*(u8 *)((s8 *)arg0 + 7) == 2);
}

/* extern */

s32 func_800BA2C4(void *arg0) {
    s32 heap_free();
    heap_free(arg0);
    return 0;
}

void *heap_alloc(s32);
void rare_memset(void *, u8, int);
void func_800BA4C4(void *, f32);
void func_800BA4D0(s16 *, s16);
void func_800BA554(void *, f32, f32);
void func_800BA568(s16 *, s16);
void func_800BA7C4(void *, f32, f32);
void func_800BA894(void *, f32, f32);
void func_800BA8F8(void *, f32, f32);

s16 *func_800BA2E8(s32 arg0) {
    typedef u8 Particle[0x3C];
    typedef struct {
        u8 pad0[7];
        u8 state;
        u8 pad8[0x14];
        f32 scale;
        u8 pad20[0x32];
        u8 flag52;
        u8 flag53;
        u8 pad54[0x2C];
        u8 color[4];
        u8 pad84[8];
        Particle *begin;
        Particle *end;
        Particle *capacity;
        u8 pad98[0x3C];
        Particle particles[1];
    } Emitter;
    Emitter *emitter;

    emitter = heap_alloc(arg0 * sizeof(Particle) + 0xD4);
    rare_memset(emitter, 0, arg0 * sizeof(Particle) + 0xD4);
    emitter->state = 2;
    emitter->color[0] = emitter->color[1] = emitter->color[2] = emitter->color[3] = 0xFF;
    emitter->scale = 1.0f;
    func_800BA4D0((s16 *)emitter, -0x8000);
    func_800BA568((s16 *)emitter, 0x7FFF);
    func_800BA894(emitter, 0.0f, 5.0f);
    func_800BA8F8(emitter, 0.0f, 5.0f);
    func_800BA4C4(emitter, 0.9f);
    func_800BA554(emitter, 1.0f, 1.0f);
    func_800BA7C4(emitter, 1.0f, 1.0f);
    emitter->begin = emitter->particles;
    emitter->end = emitter->begin;
    emitter->capacity = emitter->end + arg0;
    emitter->flag52 = 1;
    emitter->flag53 = 1;
    return (s16 *)emitter;
}

/* extern */

void func_800BA3FC(s32 arg0, s32 arg1) {
    s8 func_800AF5A0(s32);
    s32 func_800D674C(u16);
    s32 func_800D738C(s32);
    if (arg1 != (*(u16 *)((s8 *)(arg0) + (2)))) {
        (*(u16 *)((s8 *)(arg0) + (2))) = (u16) arg1;
        (*(s8 *)((s8 *)(arg0) + (0xA))) = func_800D738C(arg1 & 0xFFFF);
        (*(s8 *)((s8 *)(arg0) + (0xB))) = func_800AF5A0(func_800D674C((*(u16 *)((s8 *)(arg0) + (2)))));
    }
}

void func_800BA450(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x34), arg1, arg2, arg3);
    func_800EFA6C((void *)(arg0 + 0x3A), arg4, arg5, arg6);
}

void func_800BA4B0(s8 *arg0, s32 arg1) {
    arg0[131] = arg1;
}

void func_800BA4B8(s16 *arg0, s32 arg1, s32 arg2) {
    arg0[85] = arg1;
    ((s32 *) arg0)[47] = arg2;
}

void func_800BA4C4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 176) = arg1;
}

void func_800BA4D0(s16 *arg0, s16 arg1) {
    s32 func_800B5698(s16 *);
    void func_800BA54C(s16 *, s32);
    s16 sp1E;
    if (func_800B5698(&sp1E) != 0) {
        if (arg1 < sp1E) {
            arg1 = sp1E;
        }
        if (arg0[84] == 0) {
            func_800BA54C(arg0, 2);
        }
    }
    arg0[86] = arg1;
}

void func_800BA544(s32 *arg0, s32 arg1) {
    arg0[48] = arg1;
}

void func_800BA54C(s16 *arg0, s32 arg1) {
    arg0[84] = arg1;
}

void func_800BA554(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0xB4))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0xB8))) = arg2;
}

void func_800BA568(s16 *arg0, s16 arg1) {
    arg0[87] = arg1;
}

/* extern */

void func_800BA574(s32 arg0) {
    s32 func_800EE814(s32);
    func_800EE814(arg0 + 0xC);
}

void func_800BA594(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = arg2;
}

void func_800BA5A8(s16 *arg0, s32 arg1) {
    arg0[0] = arg1;
}

void func_800BA5B0(s16 *arg0, s32 arg1, s32 arg2) {
    arg0[66] = arg1;
    arg0[67] = arg2;
}

void func_800BA5BC(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x78))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x7C))) = arg2;
}

void func_800BA5D0(void *arg0, s16 arg1) {
    u32 var_v0;

    *(s16 *)((s8 *)arg0 + 0x14) = arg1;
    if (*(u32 *)((s8 *)arg0 + 0x90) > (var_v0 = *(u32 *)((s8 *)arg0 + 0x8C))) {
        do {
            *(s16 *)((s8 *)var_v0 + 8) = arg1;
            var_v0 += 0x3C;
        } while (var_v0 < *(u32 *)((s8 *)arg0 + 0x90));
    }
}

/* extern */

void func_800BA610(s32 arg0, s16 arg1, s16 arg2) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x34), 0, arg1, 0);
    func_800EFA6C((void *)(arg0 + 0x3A), 0, arg2, 0);
}

void func_800BA660(void *arg0, s32 arg1, s16 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x88))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x98))) = arg2;
}

void func_800BA670(s32 arg0, s32 arg1) {
    s32 func_800D738C(s32);
    if (arg1 != (*(u16 *)((s8 *)(arg0) + (2)))) {
        (*(u16 *)((s8 *)(arg0) + (2))) = (u16) arg1;
        (*(s8 *)((s8 *)(arg0) + (0xA))) = func_800D738C(arg1 & 0xFFFF);
    }
}

void func_800BA6B0(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    (*(s8 *)((s8 *)(arg0) + (5))) = 0;
    func_800EFA6C(arg0 + 0x28, arg1, arg2, arg3);
    func_800EFA6C(arg0 + 0x2E, arg4, arg5, arg6);
}

void func_800BA714(void *arg0, s16 arg1, s16 arg2) {
    (*(s8 *)((s8 *)(arg0) + (5))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg2;
}

void func_800BA730(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    (*(s8 *)((s8 *)(arg0) + (5))) = 2;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x2C))) = arg3;
    (*(s16 *)((s8 *)(arg0) + (0x2E))) = arg4;
}

/* extern */

void func_800BA75C(s32 arg0, f32 arg1[3]) {
    void func_800EE940(s16 *, f32 *);
    func_800EE940((s16 *)(arg0 + 0x12), arg1);
}

void func_800BA77C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x4C), arg1, arg2, arg3);
}

void func_800BA7C4(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x9A))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0x9C))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA7FC(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x9E))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0xA0))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA834(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C((void *)(arg0 + 0x40), arg1, arg2, arg3);
    func_800EFA6C((void *)(arg0 + 0x46), arg4, arg5, arg6);
}

void func_800BA894(void *arg0, f32 arg1, f32 arg2)
{
  f32 *new_var;
  f32 func_800DC178(f32, f32);
  f32 temp_f0;
  s8 *new_var3;
  f32 *new_var2;
  new_var2 = (f32 *) (((s8 *) arg0) + 0x58);
  temp_f0 = *((f32 *) (((s8 *) arg0) + 0x20));
  *((f32 *) ((new_var3 = (s8 *) arg0) + 0x54)) = arg1;
 *new_var2 = arg2; if (((*((f32 *) (((s8 *) arg0) + 0x20))) == 0.0f) || (arg2 < temp_f0)) {
    new_var = (f32 *) (((s8 *) arg0) + 0x54);
    *((f32 *) (((s8 *) arg0) + 0x20)) = func_800DC178(*new_var, *new_var2);
  }
}

void func_800BA8F8(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0xA2))) = (s16) (s32) (arg1 * 256.0f);
    (*(s16 *)((s8 *)(arg0) + (0xA4))) = (s16) (s32) (arg2 * 256.0f);
}

void func_800BA930(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    void func_800EFA6C(void *, s16, s16, s16);
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    func_800EFA6C((void *)(arg0 + 0xC4), arg1, arg2, arg3);
    func_800EFA6C((void *)(arg0 + 0xCA), arg4, arg5, arg6);
}

void func_800BA994(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    f32 func_800136E4(f32);
    *(s8 *)(arg0 + 4) = 1;
    *(s16 *)(arg0 + 0xC4) = (s32)func_800136E4((f32)arg2);
    *(s16 *)(arg0 + 0xC6) = (s32)func_800136E4((f32)arg5);
    *(s16 *)(arg0 + 0xC8) = (s32)func_800136E4((f32)arg1);
    *(s16 *)(arg0 + 0xCA) = (s32)func_800136E4((f32)arg4);
    *(s16 *)(arg0 + 0xCC) = arg3;
    *(s16 *)(arg0 + 0xCE) = arg6;
}

void func_800BAA60(u8 *arg0, f32 *arg1, s16 arg2, s16 arg3) {
    void func_800EE940(s16 *, f32 *);
    *(s8 *)(arg0 + 4) = 2;
    *(s16 *)(arg0 + 0xC4) = arg2;
    *(s16 *)(arg0 + 0xC6) = arg3;
    func_800EE940((s16 *)(arg0 + 0xC8), arg1);
}

void func_800BAA9C(void *arg0, f32 arg1) {
    func_800BA7C4(arg0, arg1, arg1);
    func_800BA7FC(arg0, arg1, arg1);
}

void func_800BAAE4(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x6C, arg1, arg2, arg3);
}

void func_800BAB1C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x60, arg1, arg2, arg3);
}

void func_800BAB54(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 92) = arg1;
}

/* extern */

void func_800BAB60(s32 arg0) {
    s32 func_800F2EA0(s32);
    func_800F2EA0(arg0 + 0x80);
}

/* extern */

void func_800BAB80(s32 arg0, f32 *arg1) {
    s32 func_800F2EBC(s32, f32 *);
    func_800F2EBC(arg0 + 0x80, arg1);
}

void func_800BABA0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (7))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = arg1;
}

void func_800BABB0(s32 arg0) 
{
}
/* extern */

s32 func_800BABB8(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, s16 *arg4) {

    s8 func_800AF5A0(s32);
    s32 func_800B53A4(s32);
    void func_800B5534(s8 *);
    s32 func_800D674C(u16);
    s32 func_800D738C(s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800DC298(f32);
    void func_800EE940(s16 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFA6C(void *, s16, s16, s16);
    void func_800F31EC(u8 *, s32, s32, s32);
    void func_800F31FC(u8 *, s32, s32, s32, s32);
    f32 var_f22;
    s16 var_v0;
    s32 sp17C;

    var_f22 = 1.0f;
    sp17C = 0;
    if ((arg0 != 0) && (arg1 != NULL)) {
        func_800EE940((s16 *)(arg0 + 0x12), arg1);
    }
    if (arg4 == NULL) return arg0;
    {
        var_v0 = *arg4;
        arg4++;
        if (var_v0 != 0) {
            do {
                switch (var_v0 & 0xFF) {
                case 0x1: {
                    s32 i;
                    for (i = 0; i < 3; i++, arg4 += 1) {
                        ((s16 *)(arg0 + 52))[i] = (f32)*(s16 *)arg4 * var_f22;
                        ((s16 *)(arg0 + 58))[i] = (f32)*(s16 *)(arg4 + 3) * var_f22;
                    }
                    arg4 += 3;
                    break;
                }
                case 0x2:
                    (*(u8 *)((u8 *)arg0 + (0x83))) = (u8) ((s32) (var_v0 & 0xFF00) >> 8);
                    break;
                case 0x3:
                    (*(s16 *)((u8 *)arg0 + (0xAA))) = (*(s16 *)((u8 *)arg4 + (0)));
                    (*(s32 *)((u8 *)arg0 + (0xBC))) = (s32) (*(s16 *)((u8 *)arg4 + (2)));
                    arg4 += 2;
                    break;
                case 0x4: {
                    f32 x;
                    x = (f32)arg4[0] * 0.00390625f;
                    arg4 += 1;
                    *(f32 *)(arg0 + 0xB0) = x;
                    break;
                }
                case 0x5: {
                    s32 temp_v0_2;
                    temp_v0_2 = (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    (*(s16 *)((u8 *)arg0 + (0xAC))) = temp_v0_2;
                    break;
                }
                case 0x6: {
                    s32 temp_v0_3;
                    temp_v0_3 = (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    (*(s16 *)((u8 *)arg0 + (0xAC))) = (s16) (s32) (arg1[1] + (f32) temp_v0_3);
                    break;
                }
                case 0x7:
                    (*(s16 *)((u8 *)arg0 + (0xA8))) = (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    break;
                case 0x8: {
                    f32 x, y;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    arg4 += 2;
                    *(f32 *)(arg0 + 0xB4) = x;
                    *(f32 *)(arg0 + 0xB8) = y;
                    break;
                }
                case 0x9: {
                    s32 temp_v0_4;
                    temp_v0_4 = (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    (*(s16 *)((u8 *)arg0 + (0xAE))) = temp_v0_4;
                    break;
                }
                case 0xA: {
                    s32 i;
                    for (i = 0; i < 3; i++, arg4 += 1) {
                        ((s16 *)(arg0 + 40))[i] = (f32)*(s16 *)arg4 * arg3;
                        ((s16 *)(arg0 + 46))[i] = (f32)*(s16 *)(arg4 + 3) * arg3;
                    }
                    *(u8 *)(arg0 + 5) = 0;
                    arg4 += 3;
                    break;
                }
                case 0xB:
                    (*(u8 *)((u8 *)arg0 + (5))) = 2;
                    (*(s16 *)((u8 *)arg0 + (0x28))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (0))) * arg3);
                    (*(s16 *)((u8 *)arg0 + (0x2A))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (2))) * arg3);
                    (*(s16 *)((u8 *)arg0 + (0x2C))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (4))) * arg3);
                    (*(s16 *)((u8 *)arg0 + (0x2E))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (6))) * arg3);
                    arg4 += 4;
                    break;
                case 0xC: {
                    f32 x;
                    s16 low, high;
                    x = (f32)arg4[0];
                    *(u8 *)(arg0 + 5) = 0;
                    arg4++;
                    x *= arg3;
                    low = -x;
                    func_800EFA6C((void *)(arg0 + 0x28), low, low, low);
                    high = x;
                    func_800EFA6C((void *)(arg0 + 0x2E), high, high, high);
                    break;
                }
                case 0xD: {
                    /* Preserve the original frame slots whose accesses were optimized out. */
                    s32 stackPadding[8];
                    s16 x, low;
                    x = arg4[0];
                    arg4++;
                    *(u8 *)(arg0 + 5) = 0;
                    x = (s32)((f32)x * arg3);
                    low = -x;
                    func_800EFA6C((void *)(arg0 + 0x28), low, 0, low);
                    func_800EFA6C((void *)(arg0 + 0x2E), x, x, x);
                    break;
                }
                case 0xE:
                    (*(u8 *)((u8 *)arg0 + (5))) = 1;
                    (*(s16 *)((u8 *)arg0 + (0x28))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (0))) * arg3);
                    (*(s16 *)((u8 *)arg0 + (0x2A))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (2))) * arg3);
                    arg4 += 2;
                    break;
                case 0xF:
                    (*(u8 *)((u8 *)arg0 + (7))) = 1;
                    (*(f32 *)((u8 *)arg0 + (0x20))) = func_800DC178((*(f32 *)((u8 *)arg0 + (0x54))), (*(f32 *)((u8 *)arg0 + (0x58))));
                    break;
                case 0x10: {
                    s32 temp_v0_6;
                    temp_v0_6 = func_800B53A4((s32) (var_v0 & 0xFF00) >> 8);
                    arg0 = temp_v0_6;
                    if (arg1 != NULL) {
                        func_800EE940(temp_v0_6 + 0x12, arg1);
                    }
                    break;
                }
                case 0x11: {
                    s32 temp_t0;
                    s32 temp_v0_7;
                    temp_t0 = (s32) (var_v0 & 0xFF00) >> 8;
                    sp17C = temp_t0;
                    temp_v0_7 = func_800B53A4(temp_t0);
                    arg0 = temp_v0_7;
                    if (arg1 != NULL) {
                        func_800EE940(temp_v0_7 + 0x12, arg1);
                    }
                    break;
                }
                case 0x12: {
                    s16 x, y, z;
                    x = arg4[0];
                    y = arg4[1];
                    z = arg4[2];
                    arg4 += 3;
                    func_800EFA6C((void *)(arg0 + 0xC), x, y, z);
                    arg4 += 3;
                    break;
                }
                case 0x13:
                    if (((s32) (var_v0 & 0xFF00) >> 8) != 0) {
                        var_f22 = arg3;
                    } else {
                        var_f22 = 1.0f;
                    }
                    break;
                case 0x14: {
                    (*(s16 *)((u8 *)arg0 + (0))) = 0x586;
                    (*(f32 *)((u8 *)arg0 + (0xB0))) = 0.4f;
                    (*(f32 *)((u8 *)arg0 + (0x18))) = 0.0f;
                    (*(s16 *)((u8 *)arg0 + (0xA8))) = 4;
                    (*(s16 *)((u8 *)arg0 + (0xA2))) = 0x300;
                    (*(s16 *)((u8 *)arg0 + (0xA4))) = 0x400;
                    (*(f32 *)((u8 *)arg0 + (0x1C))) = 0.8f;
                    func_800EFA6C(arg0 + 0x40, 0xC8, 0, 0xC8);
                    func_800EFA6C(arg0 + 0x46, 0x190, 0, 0x190);
                    func_800EFA6C((void *)(arg0 + 0x34), 0, -0x3E8, 0);
                    func_800EFA6C(arg0 + 0x3A, 0, -0x320, 0);
                    break;
                }
                case 0x15: {
                    f32 x, y;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    arg4 += 2;
                    *(f32 *)(arg0 + 0x18) = x;
                    *(f32 *)(arg0 + 0x1C) = y;
                    break;
                }
                case 0x16:
                    (*(s16 *)((u8 *)arg0 + (0))) = (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    break;
                case 0x17: {
                    f32 probability;
                    probability = (f32)*arg4++ * 0.00390625f;
                    if (func_800DC298(probability) != 0) {
                        *(s16 *)(arg0 + 0) = (u16)*(s16 *)(arg0 + 0) | 0x800;
                    }
                    break;
                }
                case 0x18: {
                    s16 x, y;
                    f32 z, w;
                    x = arg4[0];
                    y = arg4[1];
                    z = (f32)arg4[2] * 0.00390625f;
                    w = (f32)arg4[3] * 0.00390625f;
                    arg4 += 4;
                    *(s16 *)(arg0 + 0x86) = y;
                    *(s16 *)(arg0 + 0x84) = x;
                    *(f32 *)(arg0 + 0x78) = z;
                    *(f32 *)(arg0 + 0x7C) = w;
                    break;
                }
                case 0x19: {
                    s16 temp_v0_9;
                    s16 temp_v1;
                    temp_v0_9 = (*(s16 *)((u8 *)arg4 + (0)));
                    temp_v1 = (*(s16 *)((u8 *)arg4 + (2)));
                    arg4 += 2;
                    (*(s16 *)((u8 *)arg0 + (0x86))) = temp_v1;
                    (*(s16 *)((u8 *)arg0 + (0x84))) = temp_v0_9;
                    break;
                }
                case 0x1A:
                    func_800BA22C(arg0, (s32) (var_v0 & 0xFF00) >> 8);
                    break;
                case 0x1B:
                    func_800EFA6C(arg0 + 0x34, 0, (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (0))) * var_f22), 0);
                    func_800EFA6C(arg0 + 0x3A, 0, (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (2))) * var_f22), 0);
                    arg4 += 2;
                    break;
                case 0x1C: {
                    s32 temp_v0_10;
                    temp_v0_10 = func_800BA2E8((s32) (var_v0 & 0xFF00) >> 8);
                    arg0 = temp_v0_10;
                    if (arg1 != NULL) {
                        func_800EE940(temp_v0_10 + 0x12, arg1);
                    }
                    break;
                }
                case 0x1D: {
                    s32 model, kind;
                    model = *arg4++;
                    if (model == *(u16 *)(arg0 + 2)) break;
                    *(u16 *)(arg0 + 2) = model;
                    kind = func_800D738C(model & 0xFFFF);
                    *(u8 *)(arg0 + 0xA) = kind;
                    if ((kind & 0xFF) == 7) {
                        *(u8 *)(arg0 + 0xB) = func_800AF5A0(func_800D674C(*(u16 *)(arg0 + 2)));
                    }
                    break;
                }
                case 0x1E: {
                    f32 random;
                    random = func_800DC178((f32)arg4[0], (f32)arg4[1]);
                    random = arg3 * random;
                    arg4 += 2;
                    *(s16 *)(arg0 + 0x14) += (s16)random;
                    break;
                }
                case 0x1F: {
                    s16 temp_v0_13;
                    s16 temp_v1_2;
                    temp_v0_13 = (*(s16 *)((u8 *)arg4 + (0)));
                    temp_v1_2 = (*(s16 *)((u8 *)arg4 + (2)));
                    arg4 += 2;
                    func_800F31EC(arg0 + 0x80, (u32) (temp_v0_13 & 0xFF00) >> 8, temp_v0_13 & 0xFF, (u32) (temp_v1_2 & 0xFF00) >> 8);
                    break;
                }
                case 0x20: {
                    s16 temp_v0_14;
                    s16 temp_v1_3;
                    temp_v0_14 = (*(s16 *)((u8 *)arg4 + (0)));
                    temp_v1_3 = (*(s16 *)((u8 *)arg4 + (2)));
                    arg4 += 2;
                    func_800F31FC(arg0 + 0x80, (u32) (temp_v0_14 & 0xFF00) >> 8, temp_v0_14 & 0xFF, (u32) (temp_v1_3 & 0xFF00) >> 8, temp_v1_3 & 0xFF);
                    break;
                }
                case 0x21: {
                    s16 temp_a1_2;
                    s16 temp_a2;
                    s16 temp_a3;
                    temp_a1_2 = (*(s16 *)((u8 *)arg4 + (0)));
                    temp_a2 = (*(s16 *)((u8 *)arg4 + (2)));
                    temp_a3 = (*(s16 *)((u8 *)arg4 + (4)));
                    arg4 += 3;
                    func_800EFA6C(arg0 + 0x4C, temp_a1_2, temp_a2, temp_a3);
                    break;
                }
                case 0x22: {
                    f32 x, y, z, w;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    z = (f32)arg4[2] * 0.00390625f;
                    w = (f32)arg4[3] * 0.00390625f;
                    arg4 += 4;
                    *(s16 *)(arg0 + 0x9A) = x * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0x9C) = y * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0x9E) = z * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0xA0) = w * arg3 * 256.0f;
                    break;
                }
                case 0x23: {
                    f32 x;
                    x = (f32)arg4[0] * 0.00390625f;
                    arg4++;
                    x = x * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0x9A) = (s32)x;
                    *(s16 *)(arg0 + 0x9C) = (s32)x;
                    *(s16 *)(arg0 + 0x9E) = (s32)x;
                    *(s16 *)(arg0 + 0xA0) = (s32)x;
                    break;
                }
                case 0x24: {
                    f32 x, y;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    arg4 += 2;
                    *(s16 *)(arg0 + 0x9A) = x * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0x9C) = y * arg3 * 256.0f;
                    break;
                }
                case 0x25: {
                    f32 x, y;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    arg4 += 2;
                    *(s16 *)(arg0 + 0x9E) = x * arg3 * 256.0f;
                    *(s16 *)(arg0 + 0xA0) = y * arg3 * 256.0f;
                    break;
                }
                case 0x26:
                    func_800EFA6C(arg0 + 0x40, (*(s16 *)((u8 *)arg4 + (0))), (*(s16 *)((u8 *)arg4 + (2))), (*(s16 *)((u8 *)arg4 + (4))));
                    func_800EFA6C(arg0 + 0x46, (*(s16 *)((u8 *)arg4 + (6))), (*(s16 *)((u8 *)arg4 + (8))), (*(s16 *)((u8 *)arg4 + (0xA))));
                    arg4 += 6;
                    break;
                case 0x27:
                    func_800EFA6C(arg0 + 0x40, (*(s16 *)((u8 *)arg4 + (0))), 0, (*(s16 *)((u8 *)arg4 + (2))));
                    func_800EFA6C(arg0 + 0x46, (*(s16 *)((u8 *)arg4 + (4))), 0, (*(s16 *)((u8 *)arg4 + (6))));
                    arg4 += 4;
                    break;
                case 0x28: {
                    f32 x;
                    x = (f32)arg4[0] * 0.00390625f;
                    arg4++;
                    func_800BABA0((void *)arg0, x);
                    break;
                }
                case 0x29:
                    func_800B5534((s16 *) arg0);
                    break;
                case 0x2A: {
                    f32 x, y, z, w;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    z = (f32)arg4[2] * 0.00390625f;
                    w = (f32)arg4[3] * 0.00390625f;
                    arg4 += 4;
                    *(f32 *)(arg0 + 0x54) = x;
                    *(f32 *)(arg0 + 0x58) = y;
                    if ((*(f32 *)(arg0 + 0x20) == 0.0f) || (y < *(f32 *)(arg0 + 0x20))) {
                        *(f32 *)(arg0 + 0x20) = func_800DC178(x, y);
                    }
                    *(s16 *)(arg0 + 0xA2) = z * 256.0f;
                    *(s16 *)(arg0 + 0xA4) = w * 256.0f;
                    break;
                }
                case 0x2B: {
                    f32 x, y;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    arg4 += 2;
                    *(s16 *)(arg0 + 0xA2) = x * 256.0f;
                    *(s16 *)(arg0 + 0xA4) = y * 256.0f;
                    break;
                }
                case 0x2C:
                    (*(u8 *)((u8 *)arg0 + (4))) = 0;
                    (*(s16 *)((u8 *)arg0 + (0xC4))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (0))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xC6))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (2))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xC8))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (4))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xCA))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (6))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xCC))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (8))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xCE))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (10))) * var_f22);
                    arg4 += 6;
                    break;
                case 0x2D:
                    (*(u8 *)((u8 *)arg0 + (4))) = 2;
                    (*(s16 *)((u8 *)arg0 + (0xC4))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (0))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xC6))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (2))) * var_f22);
                    arg4 += 2;
                    func_800EE940(arg0 + 0xC8, arg2);
                    break;
                case 0x2E:
                    (*(u8 *)((u8 *)arg0 + (4))) = 1;
                    (*(s16 *)((u8 *)arg0 + (0xC8))) = (*(s16 *)((u8 *)arg4 + (0)));
                    (*(s16 *)((u8 *)arg0 + (0xC4))) = (s16) (*(s16 *)((u8 *)arg4 + (2)));
                    (*(s16 *)((u8 *)arg0 + (0xCC))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (4))) * var_f22);
                    (*(s16 *)((u8 *)arg0 + (0xCA))) = (s16) (*(s16 *)((u8 *)arg4 + (6)));
                    (*(s16 *)((u8 *)arg0 + (0xC6))) = (s16) (*(s16 *)((u8 *)arg4 + (8)));
                    (*(s16 *)((u8 *)arg0 + (0xCE))) = (s16) (s32) ((f32) (*(s16 *)((u8 *)arg4 + (10))) * var_f22);
                    arg4 += 6;
                    break;
                case 0x2F: {
                    f32 x, y, z, a, b, c, d;
                    x = (f32)arg4[0] * 0.00390625f;
                    y = (f32)arg4[1] * 0.00390625f;
                    z = (f32)arg4[2] * 0.00390625f;
                    a = (f32)arg4[3] * 0.00390625f;
                    b = (f32)arg4[4] * 0.00390625f;
                    c = (f32)arg4[5] * 0.00390625f;
                    d = (f32)arg4[6] * 0.00390625f;
                    arg4 += 7;
                    func_800EFA4C((f32 *)(arg0 + 0x6C), x * arg3, y * arg3, z * arg3);
                    func_800EFA4C((f32 *)(arg0 + 0x60), a * arg3, b * arg3, c * arg3);
                    *(f32 *)(arg0 + 0x5C) = d;
                    break;
                }
                case 0x30: {
                    f32 x;
                    x = (f32)arg4[0] * 0.00390625f;
                    arg4 += 1;
                    *(f32 *)(arg0 + 0xD0) = x;
                    break;
                }
                case 0x31: {
                    s32 temp_f4_4;
                    temp_f4_4 = func_800DC128((*(s16 *)((u8 *)arg4 + (0))), (*(s16 *)((u8 *)arg4 + (2))));
                    arg4 += 2;
                    (*(s16 *)((u8 *)arg0 + (0xCA))) = (s16) ((*(s16 *)((u8 *)arg0 + (0xCA))) + (s16) (arg3 * (f32) temp_f4_4));
                    break;
                }
                case 0x32:
                    (*(u8 *)((u8 *)arg0 + (0x52))) = (u8) (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    break;
                case 0x33:
                    (*(u8 *)((u8 *)arg0 + (0x53))) = (u8) (*(s16 *)((u8 *)arg4 + (0)));
                    arg4 += 1;
                    break;
                case 0x34: {
                    s32 i;
                    for (i = 0; i < 4; i++) {
                        ((u8 *)(arg0 + 0x80))[i] = 0xFF;
                    }
                    func_800BA930(arg0, 0, 0, 0, 0, 0, 0);
                    func_800BA450(arg0, 0, 0, 0, 0, 0, 0);
                    func_800BA834(arg0, 0, 0, 0, 0, 0, 0);
                    break;
                }
                }
                var_v0 = *(s16 *)arg4;
                arg4 += 1;
            } while (var_v0 != 0);
        }
        if (sp17C != 0) {
            func_800BA22C(arg0, sp17C);
        }
    }
    return arg0;
}

s32 func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4) {
    s32 func_800B53A4(s32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg3);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, arg1, arg2, arg4);
    func_800BA22C(sp24, arg3);
    return sp24;
}

/* extern */

void func_800BBD18(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 *arg4) {
    s32 func_800B4790(s32);
    if (arg0 != 0) {
        func_800BABB8(arg0, arg1, arg2, arg3, arg4);
        func_800B4790(arg0);
    }
}
