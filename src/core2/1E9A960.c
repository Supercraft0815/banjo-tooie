#include "core2/1E9A960.h"
BT_NATIVE_ONLY(extern s16 D_8012A994;) BT_NATIVE_ONLY(extern s16 D_8012A996;)

/* One entry of the sound source pool (60 entries at D_80128B90, see func_800C1414). */
typedef struct sfx_source_s {
    /* 0x00 */ f32 position[3];
    /* 0x0C */ f32 near_sqr; // full volume inside this squared distance
    /* 0x10 */ f32 far_sqr; // far_volume beyond this squared distance
    /* 0x14 */ f32 pan;
    /* 0x18 */ s16 far_volume;
    /* 0x1A */ u8 smooth_pan;
    /* 0x1B */ u8 positioned;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    u8 pad1E[2];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ f32 unk28; // 0x28..0x3C: pitch curve parameters, see pitch_mode
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 attack;
    /* 0x44 */ f32 decay;
    /* 0x48 */ f32 sustain;
    /* 0x4C */ s16 volume_min;
    /* 0x4E */ s16 volume_max;
    /* 0x50 */ f32 variation;
    /* 0x54 */ f32 elapsed;
    /* 0x58 */ s16 sfx_id;
    /* 0x5A */ s16 volume;
    /* 0x5C */ s16 current_volume;
    /* 0x5E */ s16 map;
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 lifetime; // frames left, 0xFF = unlimited
    /* 0x63 */ u8 use_falloff;
    /* 0x64 */ void (*callback)(u8, s32, void *);
    /* 0x68 */ s32 callback_arg;
    /* 0x6C */ f32 pitch;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ f32 unk74;
    /* 0x78 */ BT_BITFIELD_ORDER(u32 busy : 8, u32 unk7B0 : 1);
    /* 0x79 */ BT_BITFIELD_ORDER(u32 handle : 8, u32 free_on_end : 1);
    /* 0x7A */ BT_BITFIELD_ORDER(u32 mode : 3, u32 unk7B2 : 1);
    BT_BITFIELD_ORDER(u32 state : 3, u32 envelope : 1);
    BT_BITFIELD_ORDER(u32 pitch_mode : 4, u32 expiring : 1);
    u32 fading : 1;
    BT_BITFIELD_ORDER(u32 expiring : 1, u32 pitch_mode : 4);
    BT_BITFIELD_ORDER(u32 envelope : 1, u32 state : 3);
    BT_BITFIELD_ORDER(u32 unk7B2 : 1, u32 mode : 3);
    BT_BITFIELD_ORDER(u32 free_on_end : 1, u32 handle : 8);
    BT_BITFIELD_ORDER(u32 unk7B0 : 1, u32 busy : 8);
    /* 0x7C */ u16 flags;
} SfxSource;


#ifdef BT_NATIVE
#include <stddef.h>
typedef struct {
    s32 value;
    s32 occupied;
} SfxHandleSlot;
typedef struct {
    SfxHandleSlot slots[17];
} SfxHandleTable;
typedef struct {
    SfxHandleTable handles;
    SfxSource sources[60];
} SfxState;
#ifdef BT_ILP32
_Static_assert(sizeof(SfxHandleSlot) == 8, "O32 sound handle slot");
_Static_assert(sizeof(SfxHandleTable) == 0x88, "O32 sound handle table");
_Static_assert(sizeof(SfxSource) == 0x80, "O32 sound source stride");
_Static_assert(offsetof(SfxState, sources) == 0x88, "O32 sound source pool offset");
_Static_assert(sizeof(SfxState) == 0x1E88, "O32 sound owner extent");
_Static_assert(offsetof(SfxSource, flags) == 0x7C, "sound source trailing flags");
#endif
static SfxState sfx_state BT_DATA(4, bss_core2bss1_0_2, 0x1368);
#define sfx_handle_table (sfx_state.handles)
#define sfx_sources (sfx_state.sources)
#define D_80128B08 (sfx_handle_table.slots[0])
#define D_80128B0C (sfx_handle_table.slots[0].occupied)
#define D_80128B10 (sfx_handle_table.slots[1].value)
#define D_80128B90 (sfx_sources[0])
#define D_80128C10 (sfx_sources[1])
#define D_80128C08 ((u8 (*)[0x80])((u8 *)&sfx_sources[0] + 0x78))
#endif

/* extern */

void func_800C1070(f32 *arg0, f32 *arg1) {
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    void func_800E3980(f32 *);
    s32 func_800EA068(s32);
    s32 func_800F5310();
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32));
    s32 func_8010FFA8(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16 *));
    void func_8010FFB0(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 **), f32 *, f32 *);
    BtIntPtr temp_v0;
    BtIntPtr sp28;
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
    s32 func_800F5D18(BtIntPtr);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32));
    s32 func_8010FFA8(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16 *));
    s32 func_8010FFD8(BtIntPtr);
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    f32 sp24[3];
    s32 pad;
    s32 sp1C;
    BtIntPtr sp18;

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

void func_800C11F8(SfxSource *arg0, s32 arg1) {
    arg0->mode = arg1;
}

void func_800C1210(SfxSource *arg0, s32 arg1) {
    arg0->state = arg1;
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

void func_800C13A0(SfxSource *arg0, s32 arg1) {
    arg0->flags = (u16) (arg0->flags | arg1);
}

void func_800C13B0(SfxSource *arg0, s32 arg1) {
    arg0->flags = (u16) (arg0->flags & ~arg1);
}

u32 func_800C13C4(SfxSource *arg0, u32 arg1)
{
    return (u32) arg0->flags & arg1;
}

s32 func_800C13D0(SfxSource *arg0, s32 arg1) {
    return (arg0->flags & arg1) == 0;
}

void func_800C13E4(void) {
    #ifndef BT_NATIVE
extern s32 D_80128B90;
#endif
    int i;
    for (i = 0; i < 60; i++) {
        ((SfxSource *)&D_80128B90)[i].busy = 0;
    }
}

SfxSource *func_800C1414(u8 arg0) {
    #ifndef BT_NATIVE
extern s32 D_80128B90;
#endif
    s32 index = arg0;
#ifdef BT_NATIVE
    return &sfx_sources[index];
#else
    s32 *base = &D_80128B90;
    return (SfxSource *)((u8 *)base + (index << 7));
#endif
}

u8 *func_800C1430(s32 arg0) {
    #ifndef BT_NATIVE
extern s32 D_80128B10;
#endif
    return (u8 *) &D_80128B10 + ((arg0 << 3) - 8);
}

s32 func_800C1448(s32 arg0) {
    #ifndef BT_NATIVE
extern s64 D_80128B08;
#endif
    return *(s32 *)((u8 *)&D_80128B08 + (arg0 << 3));
}

u8 func_800C145C(void) {
    #ifndef BT_NATIVE
extern s32 D_80128B90;
#endif
    int i;
    for (i = 1; i < 60; i++) {
        if (!((SfxSource *)&D_80128B90)[i].busy) {
            ((SfxSource *)&D_80128B90)[i].busy = 1;
            return i;
        }
    }
    return 0;
}

void func_800C1568(s32 arg0) {
    #ifndef BT_NATIVE
extern s32 D_80128B0C;
#endif
    *((s32 *)((u8 *)&D_80128B0C + (arg0 << 3))) = 0;
}

void func_800C157C(void) {
    #ifndef BT_NATIVE
extern s32 D_80128B10;
#endif
    #ifndef BT_NATIVE
extern s32 D_80128B90;
#endif
    BtUIntPtr end;
    s32 *var_v1;

    end = (BtUIntPtr)&D_80128B90;
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
        if ((BtUIntPtr)var_v1 == end) {
            break;
        }
    }
}

s32 func_800C15BC(void) {
    #ifndef BT_NATIVE
extern s32 D_80128B10;
#endif
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
    #ifndef BT_NATIVE
extern u8 D_80128C08[][0x80];
#endif
    SfxSource *ptr = func_800C1414(index);
    if (ptr->handle) {
        func_800C1568(ptr->handle);
        ptr->handle = 0;
    }
#ifdef BT_NATIVE
    ptr->busy = 0;
#else
    D_80128C08[index][0] = 0;
#endif
}

void func_800C16F8(SfxSource *arg0, s32 arg1) {
    s32 func_800CBBE0(s32);
    s32 func_800CBC00(s32);
    s32 func_800CCEF4(BtIntPtr, s32 *, s32 *, s32, s32);
    void func_800DC3D4(s32, f32, u16, u8, u8, BtIntPtr);
    SfxSource *source = arg0;
    u32 parameters;
    s32 kind;
    if (arg1) {
        if (source->handle) {
            func_800C1568(source->handle);
        }
        source->handle = arg1 & 0xFF;
        func_800C1210(source, 1);
        func_800C13A0(source, 4);
        func_800C13A0(source, 8);
        func_800C13A0(source, 0x10);
        source->unk20 = -1;
        source->unk24 = -1;
        if (func_800CCEF4((BtIntPtr)source, &source->unk20,
                         &source->unk24, 0, 0)
            && func_800CBC00(source->unk20)) {
            kind = func_800CBBE0(source->unk20);
            switch (kind) {
                case 2: source->unk60 = 25; break;
                case 3: source->unk60 = 20; break;
                case 4: source->unk60 = 15; break;
                case 5: source->unk60 = 10; break;
                case 6: source->unk60 = 5; break;
            }
        }
        parameters = func_800C122C(source->unk60, *(&source->positioned),
                                   *(&source->unk1C), func_800C13C4(arg0, 0x400));
        func_800DC3D4(source->sfx_id - 0x3E9,
                     source->pitch, *(u16 *)&source->volume,
                     source->unk61, parameters, (BtIntPtr)func_800C1430(source->handle));
    }
}

/* extern */

void func_800C1860(SfxSource *arg0) {
    void func_800DC4D4(s32);

    if (arg0->state == 1) {
        func_800C13B0(arg0, 0x20);
        func_800C1210(arg0, 2);
        if (arg0->handle) {
            func_800DC4D4(func_800C1448(arg0->handle));
        }
    }
}

void func_800C18C8(s32 index, s32 a, s32 b, s32 c, s32 d) {
    s32 func_800C122C(s32, s32, s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800DC48C(s32, s32);
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
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800DC4B0(s32, s32);
    if (arg0 != 0) {
#ifdef BT_NATIVE
        func_800DC4B0(func_800C1448(arg0), arg1);
#else
        func_800DC4B0(func_800C1448(), arg1);
#endif
    }
}

/* extern */

void func_800C1950(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800DC42C(s32, s32);
    if (arg0 != 0) {
#ifdef BT_NATIVE
        func_800DC42C(func_800C1448(arg0), arg1);
#else
        func_800DC42C(func_800C1448(), arg1);
#endif
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

s32 func_800C19E4(SfxSource *arg0, s32 arg1) {
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
    temp_f12 = arg0->near_sqr;
    if (temp_f0 < temp_f12) {
        var_v1 = arg1;
    } else {
        if (temp_f0 < arg0->far_sqr) {
            var_v1 = (int)((f32)arg0->far_volume + ((arg0->far_sqr - temp_f0) / (arg0->far_sqr - temp_f12)) * (f32)(int)(arg1 - arg0->far_volume));
        } else {
            var_v1 = (s32) arg0->far_volume;
        }
    }
    return var_v1;
}

void func_800C1AA4(SfxSource *arg0) {
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
        arg0->pan = 64.0f;
    } else {
        arg0->unk1C = arg0->unk1D;
        if (arg0->unk1C == 0) {
            func_800E3A58(sp2C);
            sp2C[1] = -sp2C[1];
            sp2C[0] = -sp2C[0];
            sp2C[2] = -sp2C[2];
            func_800EF7B0(sp38, sp2C, sp50[0], sp50[1], sp50[2]);
            func_800F1EA4(sp38, &sp44);
            sp44 = 180.0f - sp44;
            if (sp44 < -90.0f) {
                sp44 = -180.0f - sp44;
                if (arg0->positioned) {
                    arg0->unk1C = 1;
                }
            } else {
                if (sp44 > 90.0f) {
                    sp44 = 180.0f - sp44;
                    if (arg0->positioned) {
                        arg0->unk1C = 1;
                    }
                }
            }
        }
        func_800C18C8(arg0->handle, arg0->unk60, arg0->positioned, arg0->unk1C, func_800C13C4(arg0, 0x400));
        current = sp44 * 0.7f + 64.0f;
        pan = (s32)current;
        if (arg0->smooth_pan) {
            arg0->pan += 0.07f * ((f32)pan - arg0->pan);
        } else {
            arg0->pan = (f32)pan;
        }
    }
    func_800C191C(arg0->handle, (s32)arg0->pan);
}

/* extern */

s32 func_800C1CCC(SfxSource *arg0, s32 arg1) {
    s32 func_800C1104(u16 *);
    s32 sp24;

    if (func_800C13C4(arg0, 0x40U) != 0) {
        sp24 = func_800C1104(arg0);
        if (func_800C13C4(arg0, 0x80U) != 0) {
            if (sp24 == 1) {
                arg1 *= arg0->unk74;
            }
        } else if (sp24 == 0) {
            arg1 *= arg0->unk70;
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
    SfxSource *source;
    s32 differentMap;

    result = 0;
    source = func_800C1414(index);
    if (source->state == 1 &&
        source->handle != 0) {
        differentMap = func_800EA05C() != source->map;
        if (func_800C13C4(source, 4)) {
            func_800C1950(source->handle, *(s32 *)&source->pitch);
        }
        if (func_800C13C4(source, 0x10) && !source->positioned) {
            func_800C18C8(source->handle, source->unk60,
                source->positioned, source->unk1C, func_800C13C4(source, 0x400));
        }
        if (func_800C13C4(source, 2)) {
            if (differentMap) {
                func_800C1984(source->handle, source->current_volume, func_800C13C4(source, 0x200));
            } else {
                if (source->use_falloff) {
                    volume = func_800C19E4(source, source->volume);
                } else {
                    volume = source->volume;
                }
                if (volume < 100) {
                    result = 1;
                }
                volume = func_800C1CCC(source, volume);
                source->current_volume = volume;
                func_800C1984(source->handle, volume, func_800C13C4(source, 0x200));
                if (!func_800EA068(0x20)) {
                    func_800C1AA4(source);
                }
            }
        } else {
            if (func_800C13C4(source, 0x100)) {
                func_800C191C(source->handle, source->unk61);
            }
            if (differentMap) {
                func_800C1984(source->handle, source->current_volume, func_800C13C4(source, 0x200));
            } else if (func_800C13C4(source, 8)) {
                volume = func_800C1CCC(source, source->volume);
                source->current_volume = volume;
                if (volume < 100) {
                    result = 1;
                }
                func_800C1984(source->handle, volume, func_800C13C4(source, 0x200));
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
    void func_800C16F8(SfxSource *, s32);
    void func_800C1860(SfxSource *);
    s32 unused;
    s32 playing;
    f32 dt;
    s32 slot;
    SfxSource *source;
    f32 end;
    f32 time[2];

    dt = func_800D8FF8();
    source = func_800C1414(index);
    source->elapsed += dt;
    if (source->fading) {
        if (source->decay == 0.0f) {
            source->volume = 0;
        } else {
            source->volume -= source->volume_max / source->decay * dt;
            source->volume = func_800F0E28(0, source->volume);
            if (func_800EA05C() != source->map) {
                source->current_volume = func_800F1418(source->current_volume, source->volume);
            }
        }
        if (source->volume <= 0) {
            func_800C2FDC(index);
            return;
        }
        func_800C13A0(source, 8);
    } else if (source->envelope) {
        if (source->elapsed < source->attack) {
            source->volume = source->elapsed / source->attack * (source->volume_min + source->volume_max) / 2;
        } else if (source->elapsed <= source->attack + source->sustain) {
            if (source->volume < source->volume_min || source->volume_max < source->volume) {
                source->volume = (source->volume_min + source->volume_max) / 2;
            }
            source->volume += func_800DC264(-1.0f, 1.0f) * source->variation;
            source->volume = source->volume > source->volume_max ? source->volume_max : source->volume;
            source->volume = source->volume < source->volume_min ? source->volume_min : source->volume;
        } else {
            source->volume = (1.0f - (source->elapsed - source->attack - source->sustain) / source->decay) * (source->volume_min + source->volume_max) / 2;
        }
        if (func_800EA05C() != source->map) {
            source->current_volume = func_800F1418(source->current_volume, source->volume);
        }
        func_800C13A0(source, 8);
    }
    if (source->expiring && source->elapsed >= source->attack + source->sustain + source->decay) {
        if (source->free_on_end) {
            func_800C2FDC(index);
            return;
        }
        func_800C1860(source);
    }
    if (source->handle && source->state == 1 && func_800C1448(source->handle)) {
        switch (source->pitch_mode) {
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
    if (source->state == 1 && func_800C42E0(source->sfx_id)) {
        if (func_800C13C4(source, 0x20)) {
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
    SfxSource *source = func_800C1414(arg0);

    if (source->state != 3)
        return 0;
    if (!source->handle)
        return 1;
    if (func_800C1448(source->handle))
        return 0;
    return 1;
}

void func_800C2718(void) {
    s32 func_800C0638();
    void func_800C2000(u8);
    f32 func_800D8FF8();
    extern f32 D_8011A878;
    #ifndef BT_NATIVE
extern s32 D_80128C10;
#endif
    SfxSource *var_s2;
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
    var_s2 = (SfxSource *)&D_80128C10;
    var_s1 = 1;
    do {
        if (var_s2->busy != 0) {
            if (var_s2->state != 3) {
                func_800C2000(var_s1);
            }
            temp_s0 = var_s1 & 0xFF;
            if (func_800C269C(temp_s0 & 0xFF) != 0) {
                func_800C16A4(temp_s0 & 0xFF);
            }
        }
        var_s1 += 1;
        var_s2++;
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
    #ifndef BT_NATIVE
extern s32 D_80128B90;
#endif
    int i;
    int busy;

    for (i = 1; i < 60; i++) {
        if (((SfxSource *)&D_80128B90)[i].busy)
            func_800C2FDC(i);
    }
    do {
        busy = 0;
        func_800C2718();
        for (i = 1; i < 60; i++) {
            if (((SfxSource *)&D_80128B90)[i].busy)
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
    #ifndef BT_NATIVE
extern s32 D_80128C10;
#endif
    SfxSource *var_s1;
    s32 temp_s0;
    s32 var_s2;
    s32 var_s3;

    func_800C2B80();
    do {
        var_s1 = (SfxSource *)&D_80128C10;
        var_s2 = 1;
        var_s3 = 0;
loop_2:
        if (var_s1->busy != 0) {
            temp_s0 = var_s2 & 0xFF;
            if (var_s1->state == 3) {
                if (func_800C269C(temp_s0 & 0xFF) != 0) {
                    func_800C16A4(temp_s0 & 0xFF);
                } else {
                    var_s3 += 1;
                }
            }
        }
        var_s2 += 1;
        var_s1++;
        if (var_s2 != 0x3C) {
            goto loop_2;
        }
    } while (var_s3 != 0);
}

void func_800C2B80(void) {
    #ifndef BT_NATIVE
extern s32 D_80128C10;
#endif
    SfxSource *ptr;
    u32 index;
    u8 count;

    ptr = (SfxSource *)&D_80128C10;
    for (index = 1; index < 0x3C; index++, ptr++) {
        if (ptr->busy == 0) continue;
        if (ptr->state == 3) continue;
            count = ptr->lifetime;
            if (count != 0xFF) {
                if (count == 0) {
                    func_800C2FDC(index);
                } else {
                    count--;
                    ptr->lifetime = count;
                    if (!(count & 0xFF)) {
                        ptr->elapsed = 0.0f;
                        ptr->fading = 1;
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
    SfxSource *source; BT_NATIVE_ONLY(s32 map;)

    source = func_800C1414(index);
    source->callback = 0;
    source->sfx_id = -1;
    source->current_volume = 0;
    source->volume = 22000;
    source->unk60 = 0;
    source->unk61 = 0x3F;
    source->handle = 0;
    source->lifetime = 0xFF;
    source->pitch = 1.0f;
    source->map = BT_NATIVE_ONLY(map =) func_800EA05C();
    source->use_falloff = 1;
    source->pitch_mode = 0;
    source->expiring = 0;
    source->sustain = 3.0f;
    source->free_on_end = 1;
    source->envelope = 0;
    source->fading = 0;
    source->unk7B2 = 0;
    source->attack = 1.0f;
    source->decay = 1.0f;
    source->elapsed = 0.0f;
    func_800C1210(source, 0);
    func_800C11F8(source, 0);
    func_800C13A0(source, 1);
    func_800C13A0(source, 4);
    func_800C13A0(source, 8);
    func_800C13A0(source, 0x10);
    source->near_sqr = 62500.0f;
    source->far_sqr = 1440000.0f;
    source->far_volume = 10;
    source->smooth_pan = 0;
    source->positioned = 0;
    source->unk1C = 0;
    source->unk1D = 0;
    source->pan = 64.0f;
    func_800EFD24(source->position);
    func_800C13B0(source, 2);
    func_800C13B0(source, 0x20);
    func_800C13B0(source, 0x200);
    func_800C13B0(source, 0x400);
    func_800C3418(index, 2);
    func_800C3798(index, 0.2f, 0.1f); BT_NATIVE_ONLY(return map;)
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
    SfxSource *source;

    func_800C3CE8(index);
    source = func_800C1414(index);
    source->callback = 0;
    source->sfx_id = -1;
    source->current_volume = 0;
    source->volume = 22000;
    source->unk60 = 0;
    source->unk61 = 0x3F;
    source->lifetime = 0xFF;
    source->pitch = 1.0f;
    source->map = func_800EA05C();
    source->use_falloff = 1;
    source->pitch_mode = 0;
    source->expiring = 0;
    source->sustain = 3.0f;
    source->free_on_end = 1;
    source->envelope = 0;
    source->fading = 0;
    source->unk7B2 = 0;
    source->attack = 1.0f;
    source->decay = 1.0f;
    source->elapsed = 0.0f;
    func_800C1210(source, 0);
    func_800C11F8(source, 0);
    func_800C13A0(source, 1);
    func_800C13A0(source, 4);
    func_800C13A0(source, 8);
    func_800C13A0(source, 0x10);
    source->near_sqr = 62500.0f;
    source->far_sqr = 1440000.0f;
    source->far_volume = 10;
    source->smooth_pan = 0;
    source->positioned = 0;
    source->pan = 64.0f;
    func_800EFD24(source->position);
    func_800C13B0(source, 2);
    func_800C13B0(source, 0x20);
    func_800C3418(index, 2);
    func_800C3798(index, 0.2f, 0.1f);
}

s32 func_800C2FDC(u8 index) {
    SfxSource *ptr = func_800C1414(index);
    func_800C3CE8(index);
    func_800C1210(ptr, 3);
    return 0;
}

void func_800C301C(u8 id, s32 arg1) {
    if (id != 0) {
        func_800C1414(id)->sfx_id = (s16) arg1;
    }
}

void func_800C3058(u8 index, s32 sample_rate) {
    SfxSource *source;
    if (index) {
        source = func_800C1414(index);
        source->volume = sample_rate;
        if (source->envelope == 0) {
            source->volume_min = sample_rate;
            source->volume_max = sample_rate;
            source->variation = 0.0f;
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

void func_800C316C(u8 arg0, s32 arg1, s32 arg2, f32 arg3) {SfxSource *temp_v0; if (arg0 != 0) { temp_v0 = func_800C1414(arg0); temp_v0->envelope = 1; temp_v0->volume_min = (s16) arg1; temp_v0->volume_max = (s16) arg2; temp_v0->variation = arg3; temp_v0->volume = 0; func_800C13A0(temp_v0, 8); } }

void func_800C31DC(u8 index, f32 value) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->pitch = value;
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
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk60 = value;
        func_800C13A0(ptr, 16);
    }
}

void func_800C330C(u8 id, s32 arg1) {
    extern void func_800C11F8(SfxSource *, s32);
    extern SfxSource *func_800C1414(u8);

    if (id != 0) {
        func_800C11F8(func_800C1414(id), arg1);
    }
}

void func_800C334C(u8 index, s32 value) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk61 = value;
        func_800C13A0(ptr, 256);
    }
}

void func_800C3394(u8 arg0, void (*callback)(u8, s32, void *), s32 arg2) {
    SfxSource *ptr;
    if (arg0 != 0) {
        ptr = func_800C1414(arg0);
        ptr->callback = callback;
        ptr->callback_arg = arg2;
    }
}
void func_800C33DC(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_800C1414(arg0)->positioned = (s8) arg1;
    }
}

void func_800C3418(u8 indx, s32 arg1){

    SfxSource *temp_v0;
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
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13B0(ptr, 512); }
        else { func_800C13A0(ptr, 512); }
    }
}

void func_800C3528(u8 index, s32 enabled) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13A0(ptr, 1024); }
        else { func_800C13B0(ptr, 1024); }
    }
}

void func_800C3584(u8 index, f32 min, f32 max) {
    void func_800C368C(u8, s32);
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->near_sqr = min * min;
        ptr->far_sqr = max * max;
        func_800C368C(index, 1);
    }
}

void func_800C35E8(u8 index, f32 position[3]) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800C368C(u8, s32);
    s32 func_800EA05C(void);
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        func_800EE7F8((f32 *)ptr, position);
        func_800C368C(index, 1);
        ptr->map = func_800EA05C();
    }
}

void func_800C3648(u8 index, s32 arg1) {
    s32 func_800EA05C(void);
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->map = func_800EA05C();
    }
}

/* extern */

void func_800C368C(u8 arg0, s32 arg1) {
    SfxSource *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        if (arg1) { func_800C13A0(ptr, 2); }
        else { func_800C13B0(ptr, 2); }
        func_800C33DC(arg0, arg1);
    }
}

void func_800C36F4(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_800C1414(arg0)->lifetime = (s8) arg1;
    }
}

void func_800C3730(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->pitch_mode = 1;
        ptr->unk28 = arg3;
        ptr->unk2C = arg2;
        func_800C31DC(index, arg1);
    }
}

void func_800C3798(u8 index, f32 arg1, f32 arg2) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk70 = arg1;
        ptr->unk74 = arg2;
    }
}

void func_800C37E0(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->pitch_mode = 2;
        ptr->unk30 = arg3;
        ptr->unk2C = arg1;
        ptr->unk28 = arg2;
        func_800C31DC(index, (arg1 + arg2) * 0.5f);
    }
}

void func_800C3868(u8 index, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    SfxSource *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->pitch_mode = 3;
        ptr->unk28 = arg1;
        ptr->unk2C = arg2;
        ptr->unk30 = arg3;
        ptr->unk34 = arg4;
        func_800C31DC(index, arg3);
    }
}

s16 func_800C38E4(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_800C1414(arg0)->sfx_id;
}

s16 func_800C3920(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_800C1414(arg0)->volume;
}

f32 func_800C395C(u8 index) {
    SfxSource *ptr;
    if (!index) return 1.0f;
    else {
        ptr = func_800C1414(index);
        return ptr->pitch;
    }
}

s32 func_800C39A0(u8 id) {
    return func_800C1414(id)->mode;
}

/* extern */

s32 func_800C39D0(SfxSource *arg0) {
    s32 func_800C19E4(SfxSource *, s32);
    s32 var_v1;

    if (func_800C13C4(arg0, 0x800U) != 0) {
        return 1;
    }
    if ((arg0->use_falloff != 0) && (func_800C13C4(arg0, 2U) != 0)) {
        var_v1 = func_800C19E4(arg0, arg0->volume);
    } else {
        var_v1 = arg0->volume;
    }
    return var_v1 >= 0x65;
}

/* extern */

void func_800C3A40(u8 arg0, f32 arg1, f32 arg2, f32 arg3) {SfxSource *ptr; s16 rate;
    if (arg0) {
        ptr = func_800C1414(arg0);
        ptr->expiring = 1;
        ptr->free_on_end = 1;
        ptr->attack = arg1;
        ptr->decay = arg3;
        ptr->sustain = arg2;
        ptr->elapsed = 0.0f;
        if (ptr->envelope == 0) {
            rate = ptr->volume;
            ptr->envelope = 1;
            ptr->volume = 0;
            ptr->volume_min = rate;
            ptr->volume_max = rate;
            ptr->variation = 0.0;
        }
    }
}

/* extern */

void func_800C3AE0(u8 arg0, f32 arg1) {
    SfxSource *ptr;

    if (arg0) {
        ptr = func_800C1414(arg0);
        if (ptr->envelope) {
            ptr->volume_min = (s32)(ptr->volume_min * arg1);
            ptr->volume_max = (s32)(ptr->volume_max * arg1);
        } else {
            ptr->volume = (s32)(ptr->volume * arg1);
        }
    }
}

/* extern */

void func_800C3B8C(u8 arg0, s32 arg1) {
    SfxSource *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        ptr->free_on_end = arg1;
    }
}

void func_800C3BDC(u8 id) {
    void func_800C16F8(SfxSource *, s32);
    s32 func_800C1D80(u8);
    s32 func_800C42E0(s32);
    void func_800FEC60(u32);
    SfxSource *source;
    s32 priority;

    if (!id)
        return;
    source = func_800C1414(id);
    if (source->unk7B2) {
        func_800FEC60(4);
    }
    if (func_800C39D0(source) || func_800C42E0(source->sfx_id)) {
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
    void func_800C1860(SfxSource *);
    void func_800FECB8(u32);
    SfxSource *source;

    if (id) {
        source = func_800C1414(id);
        if (source->state == 1) {
            func_800C1860(source);
            if (source->unk7B2) {
                func_800FECB8(4);
            }
            if (source->callback) {
                source->callback(id, source->callback_arg, source);
            }
        }
    }
}

int func_800C3D78(u8 id) {
    SfxSource *source;

    if (!id) {
        return 0;
    }
    source = func_800C1414(id);
#ifdef BT_NATIVE
    return id && source->state == 1
        && source->handle
        && func_800C1448(source->handle);
#else
    return id && source->state == 1
        && *(&source->handle)
        && func_800C1448(*(&source->handle));
#endif
}

s32 func_800C3E00(s32 arg0) {
    int func_800C3D78(u8);
    #ifndef BT_NATIVE
extern s32 D_80128C10;
#endif
    s32 var_s0;
    SfxSource *var_s1;

    var_s0 = 1; var_s1 = (SfxSource *)&D_80128C10;
loop_1:
    if ((var_s1->busy != 0) && (func_800C3D78(var_s0) != 0) && (arg0 == var_s1->sfx_id)) {
        return 1;
    }
    var_s0 += 1;
    var_s1++;
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

void func_800C4104(s32 arg0, f32 arg1, s32 arg2, BtIntPtr arg3, f32 arg4, f32 arg5) {
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
    func_800C1414(arg0)->use_falloff = (s8) arg1;
}    typedef struct { f32 unk0; s16 unk4; s16 unk6; } Obj1E9A960_D_8012A990; /* offsets.py genstruct: fields from raw offsets on &D_8012A990; rename once understood */

u8 func_800C4350(u8 index, f32 *position, s32 *command_list) { s16 *commands = (s16 *)command_list;
    extern f32 D_8012A990;
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EA05C(void);
    void func_800C1860(SfxSource *);
    void func_800C2E40(u8);
    void func_800C316C(u8, s32, s32, f32);
    void func_800C3A40(u8, f32, f32, f32);
    f32 func_800DC264(f32, f32);
    s32 func_800DC214(s32, s32);
    SfxSource *source;
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
        source->positioned = 1;
        source->map = func_800EA05C();
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
                source->near_sqr = a * a;
                source->far_sqr = b * b;
                source->positioned = 1;
                func_800C13A0(source, 2);
            }
            commands = (s16 *)((s16 *)commands + 2);
            break;
        case 2:
            source->use_falloff = (command & 0xFF00) >> 8;
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
            source->unk60 = (command & 0xFF00) >> 8;
            func_800C13A0(source, 0x10);
            break;
        case 6:
            func_800C11F8(source, (command & 0xFF00) >> 8);
            break;
        case 7:
            source->lifetime = (command & 0xFF00) >> 8;
            break;
        case 8:
            source->unk61 = (command & 0xFF00) >> 8;
            func_800C13A0(source, 0x100);
            break;
        case 9:
            if ((u8)((command & 0xFF00) >> 8)) {
                source->smooth_pan = 1;
            } else {
                source->smooth_pan = 0;
            }
            break;
        case 10:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            source->pitch = a;
            func_800C13A0(source, 4);
            break;
        case 11:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            source->pitch = a;
            source->unk2C = b;
            source->unk28 = c;
            source->pitch_mode = 1;
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
            source->unk28 = a;
            source->unk2C = b;
            source->unk30 = c;
            source->unk34 = d;
            source->pitch_mode = 3;
            func_800C13A0(source, 4);
            break;
        case 13: {
            f32 minimum, maximum;
            minimum = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            maximum = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            source->pitch = func_800DC264(minimum, maximum);
            func_800C13A0(source, 4);
            break;
        }
        case 29:
            a = D_8012A990;
            source->pitch = a;
            func_800C13A0(source, 4);
            break;
        case 14:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            c = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            source->unk2C = a;
            source->unk28 = b;
            source->unk30 = c;
            source->pitch = (a + b) * 0.5f;
            source->pitch_mode = 2;
            func_800C13A0(source, 4);
            break;
        case 15:
            func_800C11F8(source, 1);
            start = 1;
            source->lifetime = 0;
            break;
        case 16:
            func_800C2E40(index);
            break;
        case 17:
            start = 1;
            break;
        case 18:
            start = 0;
            if (source->state == 1) {
                func_800C1860(source);
                if (source->callback != NULL) {
                    (*(void (**)(u8, s32))&source->callback)(index, source->callback_arg);
                }
            }
            break;
        case 19: {
            s32 duration = *(s16 *)commands;
            commands = (s16 *)((s16 *)commands + 1);
            source->sfx_id = duration;
            break;
        }
        case 20:
            value = (command & 0xFF00) >> 8;
            if (position != 0) {
                source->positioned = value;
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
            *(s8 *)&source->unk1D = 1;
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
            func_800C3058(index, BT_DATA_FIELD(D_8012A994, ((Obj1E9A960_D_8012A990 *)&D_8012A990)->unk4));
            break;
        case 26:
            a = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            b = *(s16 *)commands * (1.0f / 256.0f);
            commands = (s16 *)((s16 *)commands + 1);
            source->unk70 = a;
            source->unk74 = b;
            break;
        case 27:
            func_800C3418(index, (command & 0xFF00) >> 8);
            break;
        case 28:
            source->unk7B2 = 1;
            break;
        case 33:
            func_800C301C(index, BT_DATA_FIELD(D_8012A996, ((Obj1E9A960_D_8012A990 *)&D_8012A990)->unk6));
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
            source->unk28 = a;
            source->unk2C = b;
            source->unk30 = c;
            source->unk34 = d;
            source->unk38 = e;
            source->unk3C = f;
            source->pitch_mode = 4;
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
    ((Obj1E9A960_D_8012A990 *)&D_8012A990)->unk0 = arg0;
}    typedef struct { s16 unk0; } Obj1E9A960_D_8012A994; /* offsets.py genstruct: fields from raw offsets on &D_8012A994; rename once understood */

void func_800C4B70(s32 arg0) {
    extern s16 D_8012A994;
    ((Obj1E9A960_D_8012A994 *)&D_8012A994)->unk0 = arg0;
}    typedef struct { s16 unk0; } Obj1E9A960_D_8012A996; /* offsets.py genstruct: fields from raw offsets on &D_8012A996; rename once understood */

void func_800C4B7C(s32 arg0) {
    extern s16 D_8012A996;
    ((Obj1E9A960_D_8012A996 *)&D_8012A996)->unk0 = arg0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"

f32 D_8012A990 BT_DATA(4, bss_core2bss1_0_2, 0x31F0);
s16 D_8012A994 BT_DATA(4, bss_core2bss1_0_2, 0x31F4);
s16 D_8012A996 BT_DATA(4, bss_core2bss1_0_2, 0x31F6);
#endif
