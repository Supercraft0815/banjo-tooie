#include "core2/1E9A960.h"

typedef struct {
    u8 pad0[0xC];
    f32 fade_inner_radius_sqr;
    f32 fade_outer_radius_sqr;
    u8 pad14[0x4C];
    u8 unk60;
    u8 unk61;
    u8 pad62[0xA];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    u8 pad78;
    u8 unk79;
} SoundSourceView;

/* extern */

void func_800C1070(f32 *arg0, f32 *arg1) {
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    void func_800E3980(f32 *);
    s32 func_800EA068(s32);
    s32 func_800F5310();
    s32 func_800F5EF8(s32);
    s32 func_8010FFA8(s32);
    void func_8010FFB0(s32, f32 *, f32 *);
    s32 temp_v0;
    s32 sp28;
    f32 sp1C[3];

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            _plsu_entrypoint_0(arg0, arg1);
            return;
        }
        temp_v0 = func_800F5EF8(_plsu_entrypoint_0(arg0, arg1));
        sp28 = temp_v0;
        if (func_8010FFA8(temp_v0) != 2) {
            func_8010FFB0(sp28, arg0, sp1C);
        }
    } else {
        func_800E3980(arg0);
    }
}

s32 func_800C1104(u16 *arg0) {
    s32 func_800A5490(void);
    s32 func_800EA068(s32);
    s32 func_800F5310();
    s32 func_800F5D18(s32);
    s32 func_800F5EF8(s32);
    s32 func_8010FFA8(s32);
    s32 func_8010FFD8(s32);
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    f32 sp24[3];
    s32 pad;
    s32 sp1C;
    s32 sp18;

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            sp1C = _plsu_entrypoint_0(sp24, arg0);
            if (func_800F5D18(sp1C) == 2) {
                return 1;
            }
            return 0;
        }
        sp1C = _plsu_entrypoint_0(sp24, arg0);
        sp18 = func_800F5EF8(sp1C);
        if (func_8010FFA8(sp18) == 2) {
            if (func_800F5D18(sp1C) == 2) {
                return 1;
            }
            return 0;
        }
        if (func_8010FFD8(sp18) != 0) {
            return 1;
        }
        return 0;
    } else if (func_800A5490() != 0) {
        return 1;
    }
    return 0;
}

void func_800C11F8(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char value : 3;
        unsigned char rest : 5;
    };
    ((struct Flags *)arg0)->value = arg1;
}

void func_800C1210(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char first : 3;
        unsigned char value : 3;
        unsigned char last : 2;
    };
    ((struct Flags *)arg0)->value = arg1;
}

s32 func_800C122C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern f32 D_8011A870;
    extern f32 D_8011A874;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f0;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;

    if (arg3 != 0) {
        if ((arg1 == 0) || (arg2 == 0)) {
            return arg0;
        }
        return arg0 + 0x80;
    }
    if ((arg1 == 0) || (arg2 == 0)) {
        temp_f0 = ((f32) arg0 + (D_8011A870 * 127.0f)) * D_8011A874;
        if (temp_f0 > 127.0f) {
            var_f2_2 = 127.0f;
        } else {
            var_f2_2 = temp_f0;
        }
        if (var_f2_2 < 0.0f) {
            temp_f0 = 0.0f;
        } else {
            if (temp_f0 > 127.0f) {
                var_f2 = 127.0f;
            } else {
                var_f2 = temp_f0;
            }
            temp_f0 = var_f2;
        }
        return (s32) temp_f0;
    }
    temp_f0_2 = ((f32) arg0 + (D_8011A870 * 127.0f)) * D_8011A874;
    if (temp_f0_2 > 127.0f) {
        var_f2_3 = 127.0f;
    } else {
        var_f2_3 = temp_f0_2;
    }
    if (var_f2_3 < 0.0f) {
        var_f0 = 0.0f;
    } else {
        if (temp_f0_2 > 127.0f) {
            var_f2_4 = 127.0f;
        } else {
            var_f2_4 = temp_f0_2;
        }
        var_f0 = var_f2_4;
    }
    return (s32) (var_f0 + 128.0f);
}

void func_800C13A0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) | arg1);
}

void func_800C13B0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) & ~arg1);
}

u32 func_800C13C4(u16 *arg0, u32 arg1)
{
    return (u32) arg0[0x3E] & arg1;
}

s32 func_800C13D0(void *arg0, s32 arg1) {
    return ((*(u16 *)((s8 *)(arg0) + (0x7C))) & arg1) == 0;
}

void func_800C13E4(void) {
    extern s32 D_80128B90;
    int i;
    for (i = 0; i < 60; i++) {
        *((u8 *)&D_80128B90 + i * 0x80 + 0x78) = 0;
    }
}

void *func_800C1414(u8 arg0) {
    extern s32 D_80128B90;
    s32 index = arg0;
    s32 *base = &D_80128B90;
    return (void *)((u8 *)base + (index << 7));
}

u8 *func_800C1430(s32 arg0) {
    extern s32 D_80128B10;
    return (u8 *) &D_80128B10 + ((arg0 << 3) - 8);
}

s32 func_800C1448(s32 arg0) {
    extern s64 D_80128B08;
    return *(s32 *)((u8 *)&D_80128B08 + (arg0 << 3));
}

u8 func_800C145C(void) {
    extern s32 D_80128B90;
    int i;
    for (i = 1; i < 60; i++) {
        if (!*((u8 *)&D_80128B90 + i * 0x80 + 0x78)) {
            *((u8 *)&D_80128B90 + i * 0x80 + 0x78) = 1;
            return i;
        }
    }
    return 0;
}

void func_800C1568(s32 arg0) {
    extern s32 D_80128B0C;
    *((s32 *)((u8 *)&D_80128B0C + (arg0 << 3))) = 0;
}

void func_800C157C(void) {
    extern s32 D_80128B10;
    extern s32 D_80128B90;
    u32 end;
    s32 *var_v1;

    end = (u32)&D_80128B90;
    for (var_v1 = &D_80128B10; ; ) {
    var_v1 += 8;
    ((s32 *)var_v1)[-6] = 0;
    ((s32 *)var_v1)[-5] = 0;
    ((s32 *)var_v1)[-4] = 0;
    ((s32 *)var_v1)[-3] = 0;
    ((s32 *)var_v1)[-2] = 0;
    ((s32 *)var_v1)[-1] = 0;
    ((s32 *)var_v1)[-8] = 0;
    ((s32 *)var_v1)[-7] = 0;
        if ((u32)var_v1 == end) {
            break;
        }
    }
}

s32 func_800C15BC(void) {
    extern s32 D_80128B10;
    s32 count;
    s32 i;

    do {
        count = 0;
        for (i = 0; i < 16; i++) {
            if ((&D_80128B10)[i * 2 + 1] != 0) {
                count++;
            } else if ((&D_80128B10)[i * 2] == 0) {
                (&D_80128B10)[i * 2 + 1] = 1;
                return i + 1;
            }
        }
    } while (count < 16);
    return 0;
}

void func_800C16A4(u8 index) {
    extern u8 D_80128C08[][0x80];
    SoundSourceView *ptr = func_800C1414(index);
    if (ptr->unk79) {
        func_800C1568(ptr->unk79);
        ptr->unk79 = 0;
    }
    D_80128C08[index][0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C16F8.s")

/* extern */

void func_800C1860(void *arg0) {
    void func_800DC4D4(s32);

    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x78))) << 0x13) >> 0x1D) == 1) {
        func_800C13B0(arg0, 0x20);
        func_800C1210(arg0, 2);
        if (*(u8 *)((s8 *)arg0 + 0x79)) {
            func_800DC4D4(func_800C1448(*(u8 *)((s8 *)arg0 + 0x79)));
        }
    }
}

void func_800C18C8(s32 index, s32 a, s32 b, s32 c, s32 d) {
    s32 func_800C122C(s32, s32, s32, s32);
    s32 func_800DC48C(s32, s32);
    s32 parameters;
    s32 source;
    if (index) {
        source = func_800C1448(index);
        parameters = func_800C122C(a, b, c, d);
        func_800DC48C(source, parameters);
    }
}

/* extern */

void func_800C191C(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC4B0(s32, s32);
    if (arg0 != 0) {
        func_800DC4B0(func_800C1448(), arg1);
    }
}

/* extern */

void func_800C1950(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC42C(s32, s32);
    if (arg0 != 0) {
        func_800DC42C(func_800C1448(), arg1);
    }
}

void func_800C1984(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C1448(s32);
    void func_800DC454(s32, u16);
    extern f32 D_8011A878;

    if (arg0 != 0) {
        if (arg2 == 0) {
            arg1 = (s32) ((f32) arg1 * D_8011A878);
        }
        func_800DC454(func_800C1448(arg0), (u16) arg1);
    }
}

/* extern */

s32 func_800C19E4(void *arg0, s32 arg1) {
    f32 func_800EEFD4(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 temp_f0;
    f32 temp_f12;
    s32 var_v1;

    func_800C1070(sp3C, arg0);
    func_800EFB24(sp30, arg0, sp3C);
    temp_f0 = func_800EEFD4(sp30);
    temp_f12 = *(f32 *)((s8 *)arg0 + 0xC);
    if (temp_f0 < temp_f12) {
        var_v1 = arg1;
    } else {
        if (temp_f0 < (*(f32 *)((s8 *)(arg0) + (0x10)))) {
            var_v1 = (int)(((*(f32 *)((s8 *)arg0 + 0x10) - temp_f0) / (*(f32 *)((s8 *)arg0 + 0x10) - temp_f12)) * (f32)(int)(arg1 - *(s16 *)((s8 *)arg0 + 0x18)) + (f32)*(s16 *)((s8 *)arg0 + 0x18));
        } else {
            var_v1 = (s32) (*(s16 *)((s8 *)(arg0) + (0x18)));
        }
    }
    return var_v1;
}

void func_800C1AA4(u16 *arg0) {
    void func_800E3980(f32 *);
    void func_800E3A58(f32 *);
    void func_800EF7B0(f32 *, f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    int func_800F1EA4(f32 *, f32 *);
    f32 sp5C[3];
    f32 sp50[3];
    s32 pan;
    f32 current;
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    func_800E3980(sp5C);
    func_800EFB24(sp50, arg0, sp5C);
    if (sp50[0] * sp50[0] + sp50[1] * sp50[1] + sp50[2] * sp50[2] < 10.0f) {
        *(f32 *)((s8 *)arg0 + 0x14) = 64.0f;
    } else {
        *(u8 *)((s8 *)arg0 + 0x1C) = *(u8 *)((s8 *)arg0 + 0x1D);
        if (*(u8 *)((s8 *)arg0 + 0x1C) == 0) {
            func_800E3A58(sp2C);
            sp2C[1] = -sp2C[1];
            sp2C[0] = -sp2C[0];
            sp2C[2] = -sp2C[2];
            func_800EF7B0(sp38, sp2C, sp50[0], sp50[1], sp50[2]);
            func_800F1EA4(sp38, &sp44);
            sp44 = 180.0f - sp44;
            if (sp44 < -90.0f) {
                sp44 = -180.0f - sp44;
                if (*(u8 *)((s8 *)arg0 + 0x1B)) {
                    *(u8 *)((s8 *)arg0 + 0x1C) = 1;
                }
            } else {
                if (sp44 > 90.0f) {
                    sp44 = 180.0f - sp44;
                    if (*(u8 *)((s8 *)arg0 + 0x1B)) {
                        *(u8 *)((s8 *)arg0 + 0x1C) = 1;
                    }
                }
            }
        }
        func_800C18C8(*(u8 *)((s8 *)arg0 + 0x79), *(u8 *)((s8 *)arg0 + 0x60), *(u8 *)((s8 *)arg0 + 0x1B), *(u8 *)((s8 *)arg0 + 0x1C), func_800C13C4(arg0, 0x400));
        current = sp44 * 0.7f + 64.0f;
        pan = (s32)current;
        if (*(u8 *)((s8 *)arg0 + 0x1A)) {
            *(f32 *)((s8 *)arg0 + 0x14) += 0.07f * ((f32)pan - *(f32 *)((s8 *)arg0 + 0x14));
        } else {
            *(f32 *)((s8 *)arg0 + 0x14) = (f32)pan;
        }
    }
    func_800C191C(*(u8 *)((s8 *)arg0 + 0x79), (s32)*(f32 *)((s8 *)arg0 + 0x14));
}

/* extern */

s32 func_800C1CCC(u16 *arg0, s32 arg1) {
    s32 func_800C1104(u16 *);
    s32 sp24;

    if (func_800C13C4(arg0, 0x40U) != 0) {
        sp24 = func_800C1104(arg0);
        if (func_800C13C4(arg0, 0x80U) != 0) {
            if (sp24 == 1) {
                arg1 *= *(f32 *)((s8 *)arg0 + 0x74);
            }
        } else if (sp24 == 0) {
            arg1 *= *(f32 *)((s8 *)arg0 + 0x70);
        }
    }
    return arg1;
}

s32 func_800C1D80(u8 index) {
    s16 func_800A8184(void);
    s32 func_800EA05C(void);
    s32 func_800EA068(s32);
    s32 result;
    s32 volume;
    u16 *source;
    s32 differentMap;

    result = 0;
    source = func_800C1414(index);
    if (((*(u32 *)((s8 *)source + 0x78) << 19) >> 29) == 1 &&
        *(u8 *)((s8 *)source + 0x79) != 0) {
        differentMap = func_800EA05C() != *(s16 *)((s8 *)source + 0x5E);
        if (func_800C13C4(source, 4)) {
            func_800C1950(*(u8 *)((s8 *)source + 0x79), *(s32 *)((s8 *)source + 0x6C));
        }
        if (func_800C13C4(source, 0x10) && !*(u8 *)((s8 *)source + 0x1B)) {
            func_800C18C8(*(u8 *)((s8 *)source + 0x79), *(u8 *)((s8 *)source + 0x60),
                *(u8 *)((s8 *)source + 0x1B), *(u8 *)((s8 *)source + 0x1C), func_800C13C4(source, 0x400));
        }
        if (func_800C13C4(source, 2)) {
            if (differentMap) {
                func_800C1984(*(u8 *)((s8 *)source + 0x79), *(s16 *)((s8 *)source + 0x5C), func_800C13C4(source, 0x200));
            } else {
                if (*(u8 *)((s8 *)source + 0x63)) {
                    volume = func_800C19E4(source, *(s16 *)((s8 *)source + 0x5A));
                } else {
                    volume = *(s16 *)((s8 *)source + 0x5A);
                }
                if (volume < 100) {
                    result = 1;
                }
                volume = func_800C1CCC(source, volume);
                *(s16 *)((s8 *)source + 0x5C) = volume;
                func_800C1984(*(u8 *)((s8 *)source + 0x79), volume, func_800C13C4(source, 0x200));
                if (!func_800EA068(0x20)) {
                    func_800C1AA4(source);
                }
            }
        } else {
            if (func_800C13C4(source, 0x100)) {
                func_800C191C(*(u8 *)((s8 *)source + 0x79), *(u8 *)((s8 *)source + 0x61));
            }
            if (differentMap) {
                func_800C1984(*(u8 *)((s8 *)source + 0x79), *(s16 *)((s8 *)source + 0x5C), func_800C13C4(source, 0x200));
            } else if (func_800C13C4(source, 8)) {
                volume = func_800C1CCC(source, *(s16 *)((s8 *)source + 0x5A));
                *(s16 *)((s8 *)source + 0x5C) = volume;
                if (volume < 100) {
                    result = 1;
                }
                func_800C1984(*(u8 *)((s8 *)source + 0x79), volume, func_800C13C4(source, 0x200));
            }
        }
        func_800C13B0(source, 4);
        func_800C13B0(source, 8);
        func_800C13B0(source, 0x10);
    }
    if (func_800A8184() == 4) {
        result++;
    }
    return result;
}

void func_800C2000(u8 index) {
    typedef struct {
        u8 pad0[0x28];
        f32 unk28, unk2C, unk30, unk34, unk38, unk3C;
        f32 attack, decay, sustain;
        s16 minimum, maximum;
        f32 variation, elapsed;
        s16 sound, volume, limit, map;
        u8 pad60[0xC];
        f32 pitch;
        u8 pad70[8];
        u32 unk78:8;
        u32 handle:8;
        u32 mode:3;
        u32 state:3;
        u32 pitchMode:4;
        u32 fading:1;
        u32 expiring:1;
        u32 envelope:1;
        u32 unk7B2:1;
        u32 freeOnEnd:1;
        u32 unk7B0:1;
        u16 flags;
    } Source;
    f32 func_800D8FF8(void);
    s32 func_800EA05C(void);
    s32 func_800F0E28(s32, s32);
    s32 func_800F1418(s32, s32);
    f32 func_800DC264(f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F0E00(f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800C1D80(u8);
    s32 func_800C42E0(s32);
    s32 func_800C15BC(void);
    void func_800C16F8(void *, s32);
    void func_800C1860(void *);
    s32 unused;
    s32 playing;
    f32 dt;
    s32 slot;
    Source *source;
    f32 end;
    f32 time[2];

    dt = func_800D8FF8();
    source = func_800C1414(index);
    source->elapsed += dt;
    if (source->fading) {
        if (source->decay == 0.0f) {
            source->volume = 0;
        } else {
            source->volume -= source->maximum / source->decay * dt;
            source->volume = func_800F0E28(0, source->volume);
            if (func_800EA05C() != source->map) {
                source->limit = func_800F1418(source->limit, source->volume);
            }
        }
        if (source->volume <= 0) {
            func_800C2FDC(index);
            return;
        }
        func_800C13A0(source, 8);
    } else if (source->envelope) {
        if (source->elapsed < source->attack) {
            source->volume = source->elapsed / source->attack * (source->minimum + source->maximum) / 2;
        } else if (source->elapsed <= source->attack + source->sustain) {
            if (source->volume < source->minimum || source->maximum < source->volume) {
                source->volume = (source->minimum + source->maximum) / 2;
            }
            source->volume += func_800DC264(-1.0f, 1.0f) * source->variation;
            source->volume = source->volume > source->maximum ? source->maximum : source->volume;
            source->volume = source->volume < source->minimum ? source->minimum : source->volume;
        } else {
            source->volume = (1.0f - (source->elapsed - source->attack - source->sustain) / source->decay) * (source->minimum + source->maximum) / 2;
        }
        if (func_800EA05C() != source->map) {
            source->limit = func_800F1418(source->limit, source->volume);
        }
        func_800C13A0(source, 8);
    }
    if (source->expiring && source->elapsed >= source->attack + source->sustain + source->decay) {
        if (source->freeOnEnd) {
            func_800C2FDC(index);
            return;
        }
        func_800C1860(source);
    }
    if (source->handle && source->state == 1 && func_800C1448(source->handle)) {
        switch (source->pitchMode) {
            case 0:
                break;
            case 1:
                source->pitch += source->unk28 * dt;
                if (source->unk28 > 0.0f) {
                    source->pitch = func_800F13F0(source->pitch, source->unk2C);
                } else {
                    source->pitch = func_800F0E00(source->pitch, source->unk2C);
                }
                func_800C13A0(source, 4);
                break;
            case 2:
                source->pitch += func_800DC264(-source->unk30, source->unk30) * dt;
                source->pitch = func_800F0D50(source->pitch, source->unk2C, source->unk28);
                func_800C13A0(source, 4);
                break;
            case 3:
                source->pitch = func_800F10B4(source->elapsed, source->unk28, source->unk2C, source->unk30, source->unk34);
                func_800C13A0(source, 4);
                break;
            case 4: {
                time[1] = source->elapsed;
                if (time[1] < source->unk28) {
                    source->pitch = func_800F10B4(time[1], 0.0f, source->unk28, source->unk34, source->unk38);
                } else {
                    end = source->unk28 + source->unk2C;
                    if (time[1] < end) {
                        source->pitch = source->unk38;
                    } else {
                        source->pitch = func_800F10B4(time[1] - end, 0.0f, source->unk30, source->unk38, source->unk3C);
                    }
                }
                func_800C13A0(source, 4);
                break;
            }
        }
    }
    switch (source->mode) {
        case 1:
            if (source->state == 0 || (source->state == 1 && !source->handle)) {
                func_800C2FDC(index);
                return;
            }
            break;
        case 2:
            if (source->state == 1 && func_800C13D0(source, 1)) {
                func_800C3CE8(index);
            } else {
                func_800C13B0(source, 1);
            }
            break;
        case 3:
            break;
    }
    playing = func_800C1D80(index);
    if (source->state == 1 && func_800C42E0(source->sound)) {
        if (func_800C13C4((u16 *)source, 0x20)) {
            if (!playing) {
                slot = func_800C15BC();
                osSetThreadPri(NULL, 0x33);
                func_800C16F8(source, slot);
                func_800C13B0(source, 0x20);
                func_800C1D80(index);
                osSetThreadPri(NULL, 0x14);
            }
        } else if (playing) {
            func_800C1860(source);
            func_800C1210(source, 1);
            func_800C13A0(source, 0x20);
        }
    }
    if (source->handle && !func_800C1448(source->handle)) {
        func_800C1568(source->handle);
        source->handle = 0;
    }
}

s32 func_800C269C(u8 arg0) {
    u8 *source = func_800C1414(arg0);

    if ((*(u32 *)(source + 0x78) << 19 >> 29) != 3)
        return 0;
    if (!source[0x79])
        return 1;
    if (func_800C1448(source[0x79]))
        return 0;
    return 1;
}

void func_800C2718(void) {
    s32 func_800C0638();
    void func_800C2000(u8);
    f32 func_800D8FF8();
    extern f32 D_8011A878;
    extern s32 D_80128C10;
    u8 *var_s2;
    s32 temp_s0;
    s32 var_s1;

    if (func_800C0638() != 0) {
        D_8011A878 -= func_800D8FF8();
        if (D_8011A878 < 0.5f) {
            D_8011A878 = 0.5f;
        }
    } else {
        D_8011A878 += func_800D8FF8();
        if (D_8011A878 > 1.0f) {
            D_8011A878 = 1.0f;
        }
    }
    var_s2 = (u8 *)&D_80128C10;
    var_s1 = 1;
    do {
        if ((*(u8 *)((s8 *)(var_s2) + (0x78))) != 0) {
            if ((*(u32 *)(var_s2 + 0x78) << 19 >> 29) != 3) {
                func_800C2000(var_s1);
            }
            temp_s0 = var_s1 & 0xFF;
            if (func_800C269C(temp_s0 & 0xFF) != 0) {
                func_800C16A4(temp_s0 & 0xFF);
            }
        }
        var_s1 += 1;
        var_s2 += 0x80;
    } while (var_s1 != 0x3C);
}

void func_800C2840(s32 uid, f32 volume, s32 sampleRate, s32 arg3, s32 arg4){
    u8 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C32C4(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C36F4(u8, s32);
    void func_800C3BDC(u8);

    s32 indx = func_800C2E04();
    if(indx){
        func_800C301C(indx, uid);
        func_800C3058(indx, sampleRate);
        func_800C31DC(indx, volume);
        func_800C32C4(indx, arg3);
        func_800C330C(indx, 1);
        func_800C3418(indx, arg4);
        func_800C36F4(indx, 0);
        func_800C3BDC(indx);
    }
}

void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

void func_800C2900(void) {
    extern s32 D_80128B90;
    int i;
    int busy;

    for (i = 1; i < 60; i++) {
        if (((u8 *)&D_80128B90)[i * 0x80 + 0x78])
            func_800C2FDC(i);
    }
    do {
        busy = 0;
        func_800C2718();
        for (i = 1; i < 60; i++) {
            if (((u8 *)&D_80128B90)[i * 0x80 + 0x78])
                busy++;
        }
    } while (busy);
}

void func_800C2A08(void) {
    void func_800C4308(f32, f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    func_800C28D8();
    func_800C4308(0.0f, 1.0f);
    func_800C4B64(1.0f);
    func_800C4B70(22000);
    func_800C4B7C(-1);
}

void func_800C2A5C(s32 arg0, s32 arg1) {
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

void func_800C2AB8(void) {
    s32 func_800C269C(u8);
    void func_800C2B80(void);
    extern s32 D_80128C10;
    s8 *var_s1;
    s32 temp_s0;
    s32 var_s2;
    s32 var_s3;

    func_800C2B80();
    do {
        var_s1 = (s8 *)&D_80128C10;
        var_s2 = 1;
        var_s3 = 0;
loop_2:
        if ((*(u8 *)((s8 *)(var_s1) + (0x78))) != 0) {
            temp_s0 = var_s2 & 0xFF;
            if ((*(u32 *)(var_s1 + 0x78) << 0x13 >> 0x1D) == 3) {
                if (func_800C269C(temp_s0 & 0xFF) != 0) {
                    func_800C16A4(temp_s0 & 0xFF);
                } else {
                    var_s3 += 1;
                }
            }
        }
        var_s2 += 1;
        var_s1 += 0x80;
        if (var_s2 != 0x3C) {
            goto loop_2;
        }
    } while (var_s3 != 0);
}

void func_800C2B80(void) {
    extern s32 D_80128C10;
    s8 *ptr;
    u32 index;
    u8 count;

    ptr = (s8 *)&D_80128C10;
    for (index = 1; index < 0x3C; index++, ptr += 0x80) {
        if (*(u8 *)(ptr + 0x78) == 0) continue;
        if ((*(u32 *)(ptr + 0x78) << 19 >> 29) == 3) continue;
            count = *(u8 *)(ptr + 0x62);
            if (count != 0xFF) {
                if (count == 0) {
                    func_800C2FDC(index);
                } else {
                    count--;
                    *(u8 *)(ptr + 0x62) = count;
                    if (!(count & 0xFF)) {
                        *(f32 *)(ptr + 0x54) = 0.0f;
                        ((struct { u32 pad : 26; u32 flag : 1; u32 rest : 5; } *)(ptr + 0x78))->flag = 1;
                    }
                }
            }
    }
}

s32 func_800C2C4C(u8 index) {
    s32 func_800EA05C(void);
    void func_800EFD24(f32 *);
    void func_800C3418(u8, s32);
    void func_800C3798(u8, f32, f32);
    struct Source {
        f32 position[3];
        f32 inner, outer, distance;
        s16 count;
        u8 byte1A, byte1B, byte1C, byte1D;
        u8 padding[0x22];
        f32 value40, value44, value48;
        s16 value4C, value4E;
        f32 value50, value54;
        s16 sound, rate, value5C, map;
        u8 byte60, byte61, byte62, byte63;
        void *callback;
        f32 value68, value6C;
        u32 unused[2];
        u32 high : 8;
        u32 byte79 : 8;
        u32 high6 : 6;
        u32 mode : 4;
        u32 flag5 : 1;
        u32 flag4 : 1;
        u32 flag3 : 1;
        u32 flag2 : 1;
        u32 flag1 : 1;
        u32 low : 1;
    };
    struct Source *source;

    source = func_800C1414(index);
    source->callback = 0;
    source->sound = -1;
    source->value5C = 0;
    source->rate = 22000;
    source->byte60 = 0;
    source->byte61 = 0x3F;
    source->byte79 = 0;
    source->byte62 = 0xFF;
    source->value6C = 1.0f;
    source->map = func_800EA05C();
    source->byte63 = 1;
    source->mode = 0;
    source->flag4 = 0;
    source->value48 = 3.0f;
    source->flag1 = 1;
    source->flag3 = 0;
    source->flag5 = 0;
    source->flag2 = 0;
    source->value40 = 1.0f;
    source->value44 = 1.0f;
    source->value54 = 0.0f;
    func_800C1210(source, 0);
    func_800C11F8(source, 0);
    func_800C13A0(source, 1);
    func_800C13A0(source, 4);
    func_800C13A0(source, 8);
    func_800C13A0(source, 0x10);
    source->inner = 62500.0f;
    source->outer = 1440000.0f;
    source->count = 10;
    source->byte1A = 0;
    source->byte1B = 0;
    source->byte1C = 0;
    source->byte1D = 0;
    source->distance = 64.0f;
    func_800EFD24(source->position);
    func_800C13B0(source, 2);
    func_800C13B0(source, 0x20);
    func_800C13B0(source, 0x200);
    func_800C13B0(source, 0x400);
    func_800C3418(index, 2);
    func_800C3798(index, 0.2f, 0.1f);
}

u8 func_800C2E04(void) {
    u8 func_800C145C(void);
    s32 func_800C2C4C(u8);
    u8 index = func_800C145C();
    if (index == 0) return 0;
    func_800C2C4C(index);
    return index;
}

void func_800C2E40(u8 index) {
    s32 func_800EA05C(void);
    void func_800EFD24(f32 *);
    void func_800C3418(u8, s32);
    void func_800C3798(u8, f32, f32);
    struct Source {
        f32 position[3];
        f32 inner, outer, distance;
        s16 count;
        u8 byte1A, byte1B;
        u8 padding[0x24];
        f32 value40, value44, value48;
        s16 value4C, value4E;
        f32 value50, value54;
        s16 sound, rate, value5C, map;
        u8 byte60, byte61, byte62, byte63;
        void *callback;
        f32 value68, value6C;
        u32 unused[2];
        u32 high : 22;
        u32 mode : 4;
        u32 flag5 : 1;
        u32 flag4 : 1;
        u32 flag3 : 1;
        u32 flag2 : 1;
        u32 flag1 : 1;
        u32 low : 1;
    };
    struct Source *source;

    func_800C3CE8(index);
    source = func_800C1414(index);
    source->callback = 0;
    source->sound = -1;
    source->value5C = 0;
    source->rate = 22000;
    source->byte60 = 0;
    source->byte61 = 0x3F;
    source->byte62 = 0xFF;
    source->value6C = 1.0f;
    source->map = func_800EA05C();
    source->byte63 = 1;
    source->mode = 0;
    source->flag4 = 0;
    source->value48 = 3.0f;
    source->flag1 = 1;
    source->flag3 = 0;
    source->flag5 = 0;
    source->flag2 = 0;
    source->value40 = 1.0f;
    source->value44 = 1.0f;
    source->value54 = 0.0f;
    func_800C1210(source, 0);
    func_800C11F8(source, 0);
    func_800C13A0(source, 1);
    func_800C13A0(source, 4);
    func_800C13A0(source, 8);
    func_800C13A0(source, 0x10);
    source->inner = 62500.0f;
    source->outer = 1440000.0f;
    source->count = 10;
    source->byte1A = 0;
    source->byte1B = 0;
    source->distance = 64.0f;
    func_800EFD24(source->position);
    func_800C13B0(source, 2);
    func_800C13B0(source, 0x20);
    func_800C3418(index, 2);
    func_800C3798(index, 0.2f, 0.1f);
}

s32 func_800C2FDC(u8 index) {
    void *ptr = func_800C1414(index);
    func_800C3CE8(index);
    func_800C1210(ptr, 3);
    return 0;
}

void func_800C301C(u8 id, s32 arg1) {
    if (id != 0) {
        (*(s16 *)((s8 *)(func_800C1414(id)) + (0x58))) = (s16) arg1;
    }
}

void func_800C3058(u8 index, s32 sample_rate) {
    struct Flags { u8 padding[0x78]; u32 high : 28; u32 varying_rate : 1; u32 low : 3; };
    u8 *source;
    if (index) {
        source = func_800C1414(index);
        *(s16 *)(source + 0x5A) = sample_rate;
        if (((struct Flags *)source)->varying_rate == 0) {
            *(s16 *)(source + 0x4C) = sample_rate;
            *(s16 *)(source + 0x4E) = sample_rate;
            *(f32 *)(source + 0x50) = 0.0f;
        }
        func_800C13A0(source, 8);
    }
}

void func_800C30B8(u8 index, s32 arg1, f32 position[3], f32 min_dist, f32 max_dist) {
    void func_800C1070(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800C3058(u8, s32);
    f32 pos[3];
    f32 distance;
    f32 scale;
    func_800C1070(pos, position);
    distance = func_800EEAD4(position, pos);
    if (max_dist <= distance) scale = 0.0f;
    else {
        if (min_dist <= distance) scale = 1.0f - (distance - min_dist) / (max_dist - min_dist);
        else scale = 1.0f;
    }
    func_800C3058(index, (s32)arg1 * scale);
}

/* extern */

void func_800C316C(u8 arg0, s32 arg1, s32 arg2, f32 arg3) { struct Flags { u8 pad[0x7B]; unsigned char first : 4; unsigned char flag : 1; unsigned char last : 3; }; void *temp_v0; if (arg0 != 0) { temp_v0 = func_800C1414(arg0); ((struct Flags *)temp_v0)->flag = 1; (*(s16 *)((s8 *)(temp_v0) + (0x4C))) = (s16) arg1; (*(s16 *)((s8 *)(temp_v0) + (0x4E))) = (s16) arg2; (*(f32 *)((s8 *)(temp_v0) + (0x50))) = arg3; (*(s16 *)((s8 *)(temp_v0) + (0x5A))) = 0; func_800C13A0(temp_v0, 8); } }

void func_800C31DC(u8 index, f32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk6C = value;
        func_800C13A0(ptr, 4);
    }
}

void func_800C3224(u8 index, f32 lower, f32 upper, f32 step) {
    f32 func_800C395C(u8);
    f32 func_800DC264(f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 rate = func_800C395C(index);
    if (rate < lower) {
        rate += step;
    } else if (upper < rate) {
        rate -= step;
    } else {
        rate += func_800DC264(-step, step);
        rate = func_800F0D50(rate, lower, upper);
    }
    func_800C31DC(index, rate);
}

void func_800C32C4(u8 index, s32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk60 = value;
        func_800C13A0(ptr, 16);
    }
}

void func_800C330C(u8 id, s32 arg1) {
    extern void func_800C11F8(void *, s32);
    extern void *func_800C1414(u8);

    if (id != 0) {
        func_800C11F8(func_800C1414(id), arg1);
    }
}

void func_800C334C(u8 index, s32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk61 = value;
        func_800C13A0(ptr, 256);
    }
}

void func_800C3394(u8 arg0, s32 arg1, s32 arg2) {
    void *ptr;
    if (arg0 != 0) {
        ptr = func_800C1414(arg0);
        (*(s32 *)((s8 *)ptr + 0x64)) = arg1;
        (*(s32 *)((s8 *)ptr + 0x68)) = arg2;
    }
}
void func_800C33DC(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x1B))) = (s8) arg1;
    }
}

void func_800C3418(u8 indx, s32 arg1){

    void *temp_v0;
    if(indx){
        temp_v0 = func_800C1414(indx);
        switch(arg1){
            case 0:
                func_800C13B0(temp_v0, 0x40);
                func_800C13B0(temp_v0, 0x80);
                break;
            case 1:
                func_800C13A0(temp_v0, 0x40);
                func_800C13B0(temp_v0, 0x80);
                break;
            case 2:
                func_800C13A0(temp_v0, 0x40);
                func_800C13A0(temp_v0, 0x80);
                break;
        }
    }
}

void func_800C34CC(u8 index, s32 enabled) {
    void *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13B0(ptr, 512); }
        else { func_800C13A0(ptr, 512); }
    }
}

void func_800C3528(u8 index, s32 enabled) {
    void *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13A0(ptr, 1024); }
        else { func_800C13B0(ptr, 1024); }
    }
}

void func_800C3584(u8 index, f32 min, f32 max) {
    void func_800C368C(u8, s32);
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->fade_inner_radius_sqr = min * min;
        ptr->fade_outer_radius_sqr = max * max;
        func_800C368C(index, 1);
    }
}

void func_800C35E8(u8 index, f32 position[3]) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800C368C(u8, s32);
    s32 func_800EA05C(void);
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        func_800EE7F8((f32 *)ptr, position);
        func_800C368C(index, 1);
        *(s16 *)(ptr + 0x5E) = func_800EA05C();
    }
}

void func_800C3648(u8 index, s32 arg1) {
    s32 func_800EA05C(void);
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(s16 *)(ptr + 0x5E) = func_800EA05C();
    }
}

/* extern */

void func_800C368C(u8 arg0, s32 arg1) {
    void *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        if (arg1) { func_800C13A0(ptr, 2); }
        else { func_800C13B0(ptr, 2); }
        func_800C33DC(arg0, arg1);
    }
}

void func_800C36F4(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x62))) = (s8) arg1;
    }
}

void func_800C3730(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(u16 *)(ptr + 0x7A) = (*(u16 *)(ptr + 0x7A) & 0xFC3F) | 0x40;
        *(f32 *)(ptr + 0x28) = arg3;
        *(f32 *)(ptr + 0x2C) = arg2;
        func_800C31DC(index, arg1);
    }
}

void func_800C3798(u8 index, f32 arg1, f32 arg2) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk70 = arg1;
        ptr->unk74 = arg2;
    }
}

void func_800C37E0(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(u16 *)(ptr + 0x7A) = (*(u16 *)(ptr + 0x7A) & 0xFC3F) | 0x80;
        *(f32 *)(ptr + 0x30) = arg3;
        *(f32 *)(ptr + 0x2C) = arg1;
        *(f32 *)(ptr + 0x28) = arg2;
        func_800C31DC(index, (arg1 + arg2) * 0.5f);
    }
}

void func_800C3868(u8 index, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(u16 *)(ptr + 0x7A) = (*(u16 *)(ptr + 0x7A) & 0xFC3F) | 0xC0;
        *(f32 *)(ptr + 0x28) = arg1;
        *(f32 *)(ptr + 0x2C) = arg2;
        *(f32 *)(ptr + 0x30) = arg3;
        *(f32 *)(ptr + 0x34) = arg4;
        func_800C31DC(index, arg3);
    }
}

s16 func_800C38E4(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x58)));
}

s16 func_800C3920(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x5A)));
}

f32 func_800C395C(u8 index) {
    SoundSourceView *ptr;
    if (!index) return 1.0f;
    else {
        ptr = func_800C1414(index);
        return ptr->unk6C;
    }
}

s32 func_800C39A0(u8 id) {
    u16 *p = (u16 *) ((u8 *) func_800C1414(id) + 0x7A);
    return ((u32) *p) >> 13;
}

/* extern */

s32 func_800C39D0(u16 *arg0) {
    s32 func_800C19E4(void *, s32);
    s32 var_v1;

    if (func_800C13C4(arg0, 0x800U) != 0) {
        return 1;
    }
    if (((*(u8 *)((s8 *)(arg0) + (0x63))) != 0) && (func_800C13C4(arg0, 2U) != 0)) {
        var_v1 = func_800C19E4(arg0, (*(s16 *)((s8 *)(arg0) + (0x5A))));
    } else {
        var_v1 = (*(s16 *)((s8 *)(arg0) + (0x5A)));
    }
    return var_v1 >= 0x65;
}

/* extern */

void func_800C3A40(u8 arg0, f32 arg1, f32 arg2, f32 arg3) { struct Flags { u8 padding[0x78]; u32 high : 28; u32 varying_rate : 1; u32 low : 3; }; struct ByteFlags { u8 padding[0x7B]; unsigned char high : 3; unsigned char flag4 : 1; unsigned char flag3 : 1; unsigned char mid : 1; unsigned char flag1 : 1; unsigned char low : 1; }; struct Source { u8 pad[0x40]; f32 inner, outer, volume; s16 start, end; f32 step, timer; s16 unk58, sample_rate; }; struct Source *ptr; s16 rate;
    if (arg0) {
        ptr = func_800C1414(arg0);
        ((struct ByteFlags *)ptr)->flag4 = 1;
        ((struct ByteFlags *)ptr)->flag1 = 1;
        ptr->inner = arg1;
        ptr->outer = arg3;
        ptr->volume = arg2;
        ptr->timer = 0.0f;
        if (((struct Flags *)ptr)->varying_rate == 0) {
            rate = ptr->sample_rate;
            ((struct ByteFlags *)ptr)->flag3 = 1;
            ptr->sample_rate = 0;
            ptr->start = rate;
            ptr->end = rate;
            ptr->step = 0.0;
        }
    }
}

/* extern */

void func_800C3AE0(u8 arg0, f32 arg1) {
    struct Flags { u8 padding[0x78]; u32 high : 28; u32 varying_rate : 1; u32 low : 3; };
    struct Source { u8 pad[0x4C]; s16 start, end; f32 step, timer; s16 unk58, sample_rate; };
    struct Source *ptr;

    if (arg0) {
        ptr = func_800C1414(arg0);
        if (((struct Flags *)ptr)->varying_rate) {
            ptr->start = (s32)(ptr->start * arg1);
            ptr->end = (s32)(ptr->end * arg1);
        } else {
            ptr->sample_rate = (s32)(ptr->sample_rate * arg1);
        }
    }
}

/* extern */

void func_800C3B8C(u8 arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7B];
        unsigned char first : 6;
        unsigned char value : 1;
        unsigned char last : 1;
    };
    struct Flags *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        ptr->value = arg1;
    }
}

void func_800C3BDC(u8 id) {
    void func_800C16F8(void *, s32);
    s32 func_800C1D80(u8);
    s32 func_800C42E0(s32);
    void func_800FEC60(u32);
    struct Source {
        u8 pad[0x58];
        s16 uid;
        u8 pad5A[0x1E];
        u32 first : 16;
        u32 mode : 3;
        u32 state : 3;
        u32 middle : 7;
        u32 flag : 1;
        u32 last : 2;
    } *source;
    s32 priority;

    if (!id)
        return;
    source = func_800C1414(id);
    if (source->flag) {
        func_800FEC60(4);
    }
    if (func_800C39D0((void *)source) || func_800C42E0(source->uid)) {
        switch (source->mode) {
            case 2:
                func_800C13A0(source, 1);
                if (source->state == 1) {
                    return;
                }
                break;
            default:
                if (source->state == 1) {
                    func_800C3CE8(id);
                }
                break;
        }
        priority = func_800C15BC();
        osSetThreadPri(NULL, 0x33);
        func_800C16F8(source, priority);
        func_800C1D80(id);
        osSetThreadPri(NULL, 0x14);
    }
}

/* extern */

void func_800C3CE8(u8 id) {
    void func_800C1860(void *);
    void func_800FECB8(u32);
    struct Source {
        u8 pad[0x64];
        void (*callback)(u8, s32, void *);
        s32 callback_arg;
        u8 pad6C[0xC];
        u32 first : 19;
        u32 state : 3;
        u32 middle : 7;
        u32 flag : 1;
        u32 last : 2;
    } *source;

    if (id) {
        source = func_800C1414(id);
        if (source->state == 1) {
            func_800C1860(source);
            if (source->flag) {
                func_800FECB8(4);
            }
            if (source->callback) {
                source->callback(id, source->callback_arg, source);
            }
        }
    }
}

int func_800C3D78(u8 id) {
    struct Source {
        u8 pad[0x78];
        u32 first : 19;
        u32 state : 3;
        u32 rest : 10;
    } *source;

    if (!id) {
        return 0;
    }
    source = func_800C1414(id);
    return id && source->state == 1
        && *((u8 *)source + 0x79)
        && func_800C1448(*((u8 *)source + 0x79));
}

s32 func_800C3E00(s32 arg0) {
    int func_800C3D78(u8);
    extern s32 D_80128C10;
    s32 var_s0;
    s8 *var_s1;

    var_s0 = 1; var_s1 = (s8 *)&D_80128C10;
loop_1:
    if (((*(u8 *)((s8 *)(var_s1) + (0x78))) != 0) && (func_800C3D78(var_s0) != 0) && (arg0 == (*(s16 *)((s8 *)(var_s1) + (0x58))))) {
        return 1;
    }
    var_s0 += 1;
    var_s1 += 0x80;
    if (var_s0 == 0x3C) {
        return 0;
    }
    goto loop_1;
}

void func_800C3E88(s32 uid){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, 22000, 0, 2);
}

void func_800C3EB8(s32 uid){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, 22000, 0, 0);
}

void func_800C3EE4(s32 uid, s32 sampleRate){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, sampleRate, 0, 2);
}

void func_800C3F14(s32 uid, f32 arg1){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, arg1, 22000, 0, 2);
}

void func_800C3F48(u32 arg0) {
    func_800C2840(arg0 & 0x7FF, (f32) ((arg0 >> 0x15) & 0x7FF) / 1024, (arg0 >> 6) & 0x7FE0, 0, 2);
}

void func_800C3FC0(s32 uid, f32 pitch, s32 arg2){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, pitch, arg2, 0, 2);
}

void func_800C3FF0(s32 uid, f32 arg1, s32 arg2){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, arg1, arg2, 0, 0);
}

void func_800C401C(s32 arg0, f32 arg1, u32 arg2, f32 *arg3, f32 arg4, f32 arg5, s32 arg6) {
    f32 func_800EEAD4(f32 *, f32 *);
    u8 index;
    f32 position[3];

    func_800C1070(position, arg3);
    if (!(arg5 <= func_800EEAD4(position, arg3))) {
        index = func_800C2E04();
        if (index) {
            func_800C3418(index, arg6);
            func_800C301C(index, arg0);
            func_800C3058(index, arg2);
            func_800C31DC(index, arg1);
            func_800C3584(index, arg4, arg5);
            func_800C35E8(index, arg3);
            func_800C330C(index, 1);
            func_800C33DC(index, 1);
            func_800C36F4(index, 0);
            func_800C3BDC(index);
        }
    }
}

void func_800C4104(s32 arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);
    func_800C401C(arg0, arg1, arg2, (f32 *)arg3, arg4, arg5, 2);
}

void func_800C4140(u32 arg0, f32 *arg1, u32 arg2) {
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);
    func_800C401C(arg0 & 0x7FF, (f32)((arg0 >> 21) & 0x7FF) / 1024,
        (arg0 >> 6) & 0x7FE0, arg1, (f32)(arg2 & 0xFFFF),
        (f32)((arg2 >> 16) & 0xFFFF), 2);
}

void func_800C4208(s32 uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);

    func_800C401C(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 1);
}

void func_800C4244(s32 uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);

    func_800C401C(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 0);
}

void func_800C427C()
{
    func_800C2718();
}

u8 func_800C429C(s32 uid, s32 arg1){
    u8 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);

    u8 indx = func_800C2E04();
    func_800C301C(indx, uid);
    func_800C330C(indx, arg1);
    return indx;
}

/* extern */

s32 func_800C42E0(s32 arg0) {
    s32 func_800DC548(s32, s32, s32);
    return func_800DC548(0, arg0 - 0x3E9, arg0);
}

void func_800C4308(f32 arg0, f32 arg1) {
    extern f32 D_8011A870;
    extern f32 D_8011A874;
    D_8011A870 = arg0;
    D_8011A874 = arg1;
}

void func_800C431C(u8 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x63))) = (s8) arg1;
}

u8 func_800C4350(u8 index, f32 *position, s32 *command_list) { s16 *commands = (s16 *)command_list;
    struct Source {
        f32 position[3];
        f32 near_squared;
        f32 far_squared;
        u8 pad14[6];
        s8 unk1A;
        s8 positioned;
        s8 unk1C;
        s8 unk1D;
        u8 pad1E[10];
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        f32 unk34;
        f32 unk38;
        f32 unk3C;
        u8 pad40[24];
        s16 unk58;
        u8 pad5A[4];
        s16 map;
        s8 unk60;
        s8 unk61;
        s8 unk62;
        s8 unk63;
        void (*callback)(u8, s32);
        s32 callback_arg;
        f32 unk6C;
        f32 unk70;
        f32 unk74;
        unsigned int unused78 : 19;
        unsigned int state : 3;
        unsigned int mode : 4;
        unsigned int unused7B : 3;
        unsigned int flag : 1;
        unsigned int unused7B2 : 2;
    };
    extern f32 D_8012A990;
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EA05C(void);
    void func_800C1860(void *);
    void func_800C2E40(u8);
    void func_800C316C(u8, s32, s32, f32);
    void func_800C3A40(u8, f32, f32, f32);
    f32 func_800DC264(f32, f32);
    s32 func_800DC214(s32, s32);
    void *source;
    s32 start = 0;
    s32 command;
    s32 value;
    s32 value2;
    f32 a, b, c, d, e, f;

    command_list = 0;
    if ((u8)index == 0) {
        if ((index = func_800C2E04()) == 0) {
            return 0;
        }
        source = func_800C1414(index);
    } else {
        source = func_800C1414(index);
    }
    if (position != 0) {
        func_800EE7F8((f32 *)source, position);
        func_800C13A0(source, 2);
        (*(s8 *)((u8 *)source + 0x1b)) = 1;
        (*(s16 *)((u8 *)source + 0x5e)) = func_800EA05C();
    }
    if (commands == 0) {
        if ((u8)index != 0) {
            func_800C3BDC(index);
        }
        return (u8)index;
    }
    while (command = *(s16 *)commands, commands = (s16 *)((s16 *)commands + 1), command != 0) {
        switch (command & 0xFF) {
        case 1:
            a = ((s16 *)commands)[0];
            b = ((s16 *)commands)[1];
            if (position != 0) {
                (*(f32 *)((u8 *)source + 0xc)) = a * a;
                (*(f32 *)((u8 *)source + 0x10)) = b * b;
                (*(s8 *)((u8 *)source + 0x1b)) = 1;
                func_800C13A0(source, 2);
            }
            commands = (s16 *)((s16 *)commands + 2);
            break;
        case 2:
            (*(s8 *)((u8 *)source + 0x63)) = (command & 0xFF00) >> 8;
            break;
        case 32:
            if ((command & 0xFF00) >> 8) {
                func_800C13B0(source, 0x200);
            } else {
                func_800C13A0(source, 0x200);
            }
            break;
        case 34:
            if ((command & 0xFF00) >> 8) {
                func_800C13B0(source, 0x400);
            } else {
                func_800C13A0(source, 0x400);
            }
            break;
        case 36:
            if ((command & 0xFF00) >> 8) {
                func_800C13A0(source, 0x800);
            } else {
                func_800C13B0(source, 0x800);
            }
            break;
        case 3:
            return (u8)index;
        case 4:
            func_800C2FDC(index);
            return 0;
        case 5:
            (*(s8 *)((u8 *)source + 0x60)) = (command & 0xFF00) >> 8;
            func_800C13A0(source, 0x10);
            break;
        case 6:
            func_800C11F8(source, (command & 0xFF00) >> 8);
            break;
        case 7:
            (*(s8 *)((u8 *)source + 0x62)) = (command & 0xFF00) >> 8;
            break;
        case 8:
            (*(s8 *)((u8 *)source + 0x61)) = (command & 0xFF00) >> 8;
            func_800C13A0(source, 0x100);
            break;
        case 9:
            if ((u8)((command & 0xFF00) >> 8)) {
                (*(s8 *)((u8 *)source + 0x1a)) = 1;
            } else {
                (*(s8 *)((u8 *)source + 0x1a)) = 0;
            }
            break;
        case 10:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x6c)) = a;
            func_800C13A0(source, 4);
            break;
        case 11:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x6c)) = a;
            (*(f32 *)((u8 *)source + 0x2c)) = b;
            (*(f32 *)((u8 *)source + 0x28)) = c;
            ((struct Source *)source)->mode = 1;
            func_800C13A0(source, 4);
            break;
        case 12:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            d = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x28)) = a;
            (*(f32 *)((u8 *)source + 0x2c)) = b;
            (*(f32 *)((u8 *)source + 0x30)) = c;
            (*(f32 *)((u8 *)source + 0x34)) = d;
            ((struct Source *)source)->mode = 3;
            func_800C13A0(source, 4);
            break;
        case 13: {
            f32 minimum, maximum;
            minimum = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            maximum = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x6c)) = func_800DC264(minimum, maximum);
            func_800C13A0(source, 4);
            break;
        }
        case 29:
            a = D_8012A990;
            (*(f32 *)((u8 *)source + 0x6c)) = a;
            func_800C13A0(source, 4);
            break;
        case 14:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x2c)) = a;
            (*(f32 *)((u8 *)source + 0x28)) = b;
            (*(f32 *)((u8 *)source + 0x30)) = c;
            (*(f32 *)((u8 *)source + 0x6c)) = (a + b) * 0.5f;
            ((struct Source *)source)->mode = 2;
            func_800C13A0(source, 4);
            break;
        case 15:
            func_800C11F8(source, 1);
            start = 1;
            (*(s8 *)((u8 *)source + 0x62)) = 0;
            break;
        case 16:
            func_800C2E40(index);
            break;
        case 17:
            start = 1;
            break;
        case 18:
            start = 0;
            if (((struct Source *)source)->state == 1) {
                func_800C1860(source);
                if ((*(void (**)(u8, s32))((u8 *)source + 0x64)) != 0) {
                    (*(void (**)(u8, s32))((u8 *)source + 0x64))(index, (*(s32 *)((u8 *)source + 0x68)));
                }
            }
            break;
        case 19: {
            s32 duration = *(s16 *)commands;
            commands = (s16 *)((s16 *)commands + 1);
            (*(s16 *)((u8 *)source + 0x58)) = duration;
            break;
        }
        case 20:
            value = (command & 0xFF00) >> 8;
            if (position != 0) {
                (*(s8 *)((u8 *)source + 0x1b)) = value;
                if (value != 0) {
                    func_800C13A0(source, 2);
                } else {
                    func_800C13B0(source, 2);
                }
            }
            break;
        case 21:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            func_800C3A40(index, a, b, c);
            break;
        case 31:
            (*(s8 *)((u8 *)source + 0x1d)) = 1;
            break;
        case 22:
            func_800C3058(index, *commands++);
            break;
        case 23:
            value = *(s16 *)commands;
            commands = (s16 *)((s16 *)commands + 1);
            value2 = *(s16 *)commands;
            commands = (s16 *)((s16 *)commands + 1);
            a = *(s16 *)commands;
            commands = (s16 *)((s16 *)commands + 1);
            func_800C316C(index, value, value2, a);
            break;
        case 24:
            func_800C3058(index, 0x7FFF);
            break;
        case 25:
            func_800C3058(index, func_800DC214(((s16 *)commands)[0], ((s16 *)commands)[1]));
            commands = (s16 *)((s16 *)commands + 2);
            break;
        case 30:
            func_800C3058(index, *(s16 *)((u8 *)&D_8012A990 + 4));
            break;
        case 26:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x70)) = a;
            (*(f32 *)((u8 *)source + 0x74)) = b;
            break;
        case 27:
            func_800C3418(index, (command & 0xFF00) >> 8);
            break;
        case 28:
            ((struct Source *)source)->flag = 1;
            break;
        case 33:
            func_800C301C(index, *(s16 *)((u8 *)&D_8012A990 + 6));
            break;
        case 35:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            d = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            e = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            f = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            (*(f32 *)((u8 *)source + 0x28)) = a;
            (*(f32 *)((u8 *)source + 0x2c)) = b;
            (*(f32 *)((u8 *)source + 0x30)) = c;
            (*(f32 *)((u8 *)source + 0x34)) = d;
            (*(f32 *)((u8 *)source + 0x38)) = e;
            (*(f32 *)((u8 *)source + 0x3c)) = f;
            ((struct Source *)source)->mode = 4;
            func_800C13A0(source, 4);
            break;
        }
    }
    if (start != 0) {
        func_800C3BDC(index);
    }
    return (u8)index;
}

/* extern */

void func_800C4AF0(f32 *arg0, void *arg1) {
    void func_800C33DC(u8, s32);
    void func_800C36F4(u8, s32);
    u8 func_800C4350(u8, f32[3], s32 *);
    u8 temp_s0;

    if (temp_s0 = func_800C4350(0, arg0, arg1)) {
        if (arg0 == NULL) {
            func_800C33DC(temp_s0, 0);
        }
        func_800C330C(temp_s0, 1);
        func_800C36F4(temp_s0, 0);
        func_800C3BDC(temp_s0);
    }
}

void func_800C4B64(f32 arg0) {
    extern f32 D_8012A990;
    *(f32 *)((u8 *)&D_8012A990 + 0) = arg0;
}

void func_800C4B70(s32 arg0) {
    extern s16 D_8012A994;
    *(s16 *)((u8 *)&D_8012A994 + 0) = arg0;
}

void func_800C4B7C(s32 arg0) {
    extern s16 D_8012A996;
    *(s16 *)((u8 *)&D_8012A996 + 0) = arg0;
}
