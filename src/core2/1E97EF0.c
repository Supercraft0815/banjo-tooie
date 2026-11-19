#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1E97EF0_native.inc"
#else
#include "1E97EF0_data.h"

struct Entry { s32 value; u8 padding[40]; };
BT_IDO_ONLY(extern struct Entry D_801285B4[];)

BT_IDO_ONLY(extern s32 D_801285B0;)
BT_IDO_ONLY(extern s32 *D_80128728;)
BT_IDO_ONLY(extern s32 D_8012872C;)
BT_IDO_ONLY(extern s32 D_80128760;)


f32 func_800BE600(f32 arg0[3], s32 arg1) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    f32 func_800DC178(f32, f32);
    s32 phi_s2;
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    s32 temp_s1;
    s32 phi_s1;

    sp64[0] = arg0[0];
    sp64[1] = arg0[1];
    sp64[2] = arg0[2];
    sp64[1] += 200.0f;
    sp58[0] = arg0[0];
    sp58[1] = arg0[1];
    sp58[2] = arg0[2];
    sp58[1] -= 2000.0f;
    if (func_800BEF00(sp64, sp58, sp70, arg1)) {
        return sp58[1];
    }
    phi_s2 = 150;
    phi_s1 = 1000;
    do {
        sp64[0] = arg0[0];
        sp64[1] = arg0[1];
        sp64[2] = arg0[2];
        sp64[0] += func_800DC178(-1.0f, 1.0f);
        sp64[1] += (f32) phi_s2;
        sp64[2] += func_800DC178(-1.0f, 1.0f);
        sp58[0] = arg0[0];
        sp58[1] = arg0[1];
        sp58[2] = arg0[2];
        sp58[0] += func_800DC178(-1.0f, 1.0f);
        sp58[1] -= (f32) phi_s1;
        sp58[2] += func_800DC178(-1.0f, 1.0f);
        if (func_800BEF00(sp64, sp58, sp70, arg1)) {
            return sp58[1];
        }
        phi_s1 += 2000;
        phi_s2 += 300;
    } while (phi_s1 != 51000);
    return 0.0f;
}

BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s32) func_800BE7F8(s32 arg0, s32 arg1) {
    s32 _glid_entrypoint_5(s32, s32);
    s32 _glid_entrypoint_6(s32, s32);
    s32 _vpmodule_entrypoint_3(s32, s32, s32);
    void func_800BF774(void);
    void *func_800BF704(void);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    f32 func_800DF428(f32);
    void func_800DF440(s32);
    void func_800DF4B0(s32);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF738(s32);
    void func_800DF7DC(s32);
    void func_800DF7E8(u8);
    void func_800DF818(s32);
    void func_800DF830(s32);
    void func_800DF83C(s32);
    s32 func_800EA340(void);

    struct RenderEntry {
        s32 unk0, handle, unk8, model;
        s32 vertices[2];
        s32 unk18, unk1C, unk20, texture;
        u8 cache, index, unk2A, enabled;
    };
    struct RenderState { u8 pad[0x85]; u8 red, green, blue; };
    struct RenderEntry *entry;
    union { u32 address; struct RenderState *state; } base;
    s32 mode;

    entry = (struct RenderEntry *)&MAP_COLLISION_BITS + arg1;
    if (entry->model != 0 && entry->enabled != 0) {
        func_800BF774();
        func_800DF738((s32)D_80128728);
        if (entry == (struct RenderEntry *)&MAP_COLLISION_BITS) {
            func_800DF83C(D_8012872C);
        }
        if (entry != (struct RenderEntry *)&MAP_COLLISION_BITS) {
            mode = 2;
        } else {
            mode = 1;
        }
        func_800DF830(mode);
        if (entry->cache != 0) {
            func_800DF7E8(entry->cache);
        }
        base.address = (u32)&MAP_COLLISION_BITS;
        func_800DF5D8(base.state->red, base.state->green, base.state->blue, 255);
        func_800DF7DC(entry->texture);
        func_800DF818(entry->vertices[entry->index]);
        func_800DF428(29999.0f);
        func_800DF440(0);
        func_800DF4B0(1);
        func_800DE448(0, 0, 1.0f, 0, entry->model);
        if (entry->unk1C != 0) {
            _vpmodule_entrypoint_3(entry->unk1C, entry->unk18, entry->vertices[entry->index]);
        }
        if (entry->vertices[1] != 0 && func_800EA340() != 0) {
            if (entry->handle != 0) {
                _glid_entrypoint_6(entry->handle, entry->vertices[entry->index]);
            }
            entry->index ^= 1;
            if (entry->handle != 0) {
                _glid_entrypoint_5(entry->handle, entry->vertices[entry->index]);
            }
        }
    }
    BT_NATIVE_ONLY(return 0;) } typedef struct { void * unk0; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0x8]; s32 unk18; s32 unk1C; u8 pad20[0x9]; u8 unk29; u8 unk2A; u8 pad2B[0x1]; union { s32 unk2C; u16 * unk2C_u16p; }; s32 unk30; s32 unk34; s32 unk38; u8 pad3C[0x8]; s32 unk44; s32 unk48; u8 pad4C[0x9]; u8 unk55; u8 unk56; u8 pad57[0x3]; u16 unk5A; u16 unk5C; u8 pad5E[0xA]; s32 unk68; u8 pad6C[0xB]; u8 unk77; u8 pad78[0xC]; s8 unk84; s8 unk85; s8 unk86; s8 unk87; s32 unk88; u8 pad8C[0xEC]; s32 unk178; s32 unk17C; u8 pad180[0x30]; s32 unk1B0; } Obj1E97EF0_D_801285B0; /* offsets.py genstruct: fields from raw offsets on &MAP_COLLISION_BITS; rename once understood */

/* extern */

void func_800BE9B0(void) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) _gcmapsects_entrypoint_17(s32 *);
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        _gcmapsects_entrypoint_17(&MAP_COLLISION_BITS);
    }
}

/* extern */

void func_800BE9E4(s32 arg0) {
    s32 _gcmapsects_entrypoint_18(s32 *, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s32) func_800BE7F8(s32, s32);
    func_800BE7F8(arg0, 0);
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        _gcmapsects_entrypoint_18(&MAP_COLLISION_BITS, arg0);
    }
}

/* extern */

void func_800BEA24(s32 arg0) {
    s32 _gcmapsects_entrypoint_19(s32 *, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s32) func_800BE7F8(s32, s32);
    func_800BE7F8(arg0, 1);
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        _gcmapsects_entrypoint_19(&MAP_COLLISION_BITS, arg0);
    }
}

void func_800BEA64(f32 *arg0) {
    func_800BE600(arg0, 0x20020);
}

s32 func_800BEA88(s32 arg0) {
#if defined(BT_NATIVE) && defined(BT_ILP32)
    return (s32)(u32)native_map.layers[arg0].instances;
#else
    return D_801285B4[arg0].value;
#endif
}

/* extern */

s32 func_800BEAAC(s32 arg0, s32 arg1) {
    BT_IDO_ONLY(extern u8 D_80128627;)
    s32 _gcmapsects_entrypoint_6(s32 *, s32, s32);
    if (D_80128627 != 0) {
        return _gcmapsects_entrypoint_6(&MAP_COLLISION_BITS, arg0, arg1);
    }
    return 0;
}

/* extern */

void func_800BEAF4(void) {
    s32 _gcmapsects_entrypoint_8(s32 *);
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        _gcmapsects_entrypoint_8(&MAP_COLLISION_BITS);
    }
}

s32 func_800BEB28(s32 arg0) {
#if defined(BT_NATIVE) && defined(BT_ILP32)
    return (s32)(u32)native_map.layers[arg0].model;
#else
    BT_IDO_ONLY(extern struct Entry D_801285BC[];)
    return D_801285BC[arg0].value;
#endif
}

s32 func_800BEB4C()
{
    return D_80128760;
}    typedef struct { s32 unk0; } Obj1E97EF0_D_80128760; /* offsets.py genstruct: fields from raw offsets on &D_80128760; rename once understood */

void func_800BEB58(s32 arg0) {
    ((Obj1E97EF0_D_80128760 *)&D_80128760)->unk0 = arg0;
}

s32 func_800BEB64(s32 arg0) {
    struct Entry {
        s32 pad[4];
        s32 values[6];
        u8 pad28;
        u8 index;
        u8 pad2A[2];
    } *entry;

    entry = &((struct Entry *)&MAP_COLLISION_BITS)[arg0];
    return entry->values[entry->index];
}

s32 func_800BEB98(s32 arg0) {
#if defined(BT_NATIVE) && defined(BT_ILP32)
    return native_map.layers[arg0].vertices[1] != 0 ? 2 : 1;
#else
    struct Entry { s32 value; s32 pad[10]; };
    BT_IDO_ONLY(extern struct Entry D_801285C4[];)
    return D_801285C4[arg0].value != 0 ? 2 : 1;
#endif
}

u8 *func_800BEBD4(s32 arg0) {
    u8 *func_800B27A0(u8 *arg0);
#if defined(BT_NATIVE) && defined(BT_ILP32)
    return func_800B27A0(native_map.layers[arg0].model);
#else
    return func_800B27A0(*(u8 **)((u8 *)&MAP_COLLISION_BITS + 0xC + arg0 * 44));
#endif
}

s32 *func_800BEC10(void)
{
    return D_80128728;
}

s32 func_800BEC1C()
{
    return D_8012872C;
}

s32 func_800BEC28(s32 arg0) {
#if defined(BT_NATIVE) && defined(BT_ILP32)
    return (s32)(u32)native_map.layers[arg0].zones;
#else
    struct Entry { s32 value; u8 padding[40]; };
    BT_IDO_ONLY(extern struct Entry D_801285D0[];)
    return D_801285D0[arg0].value;
#endif
}

#include "1E97EF0_bounds.inc"

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) func_800BED50(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_800BE600(arg0,0x1F00);
}

/* extern */

s32 func_800BED70(f32 *arg0, f32 *arg1, s16 (**arg2)[3], s32 arg3, f32 arg4) {
    s32 _gcmapsects_entrypoint_20(s32 *, f32 *, f32 *, s16 (**)[3], s32, f32);
    s32 func_800AD2C8(void *, void *, f32 *, f32 *, f32 *, s16 (**)[3], s32, f32);
    void func_800EFD24(f32 *);
    f32 sp34[3];
    s32 temp_v0;

    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A) != 0) {
        func_800EFD24(sp34);
        temp_v0 = func_800AD2C8((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk0), ((void **)&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4], arg0, arg1, sp34, arg2, arg3, arg4);
        if (temp_v0 != 0) {
            return temp_v0;
        }
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        return _gcmapsects_entrypoint_20(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3, arg4);
    }
    return 0;
}

/* extern */

s32 func_800BEE40(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    s32 _gcmapsects_entrypoint_21(s32 *, f32 *, f32 *, f32 *, f32);
    s32 func_800AD894(void *, void *, f32 *, f32 *, f32 *, f32 *, f32);
    void func_800EFD24(f32 *);
    f32 sp30[4];

    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A) != 0) {
        func_800EFD24(sp30);
        if (func_800AD894((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk0), ((void **)&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4], arg0, arg1, arg2, sp30, arg3) != 0) {
            return 1;
        }
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        return _gcmapsects_entrypoint_21(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3);
    }
    return 0;
}

s32 *func_800BEF00(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    s32 _gcmapsects_entrypoint_22(s32 *, f32 *, f32 *, f32 *, s32);
    s32 func_800AB0BC(s32, s32, f32 *, f32 *, f32 *, s32);
    s32 result;
    s32 hit;

    result = 0;
    ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = 0;
    if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk56 != 0) {
        if ((arg3 & 0x1F00) != 0x1F00) {
            if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) {
                result = _gcmapsects_entrypoint_22(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3);
            }
            if (result == 0 && ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A != 0) {
                result = func_800AB0BC(MAP_COLLISION_BITS,
                    (&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4],
                    arg0, arg1, arg2, arg3);
            }
        }
        hit = func_800AB0BC(((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2C,
            (&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk55 + 15],
            arg0, arg1, arg2, arg3);
        if (hit != 0) {
            ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk38;
            return (s32 *)hit;
        }
        if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) {
            hit = _gcmapsects_entrypoint_22(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3);
            if (hit != 0) {
                return (s32 *)hit;
            }
        }
        if (result != 0) {
            ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unkC;
        }
        return (s32 *)result;
    } else {
        if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) {
            result = _gcmapsects_entrypoint_22(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3);
        }
        if (result == 0 && ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A != 0) {
            result = func_800AB0BC(MAP_COLLISION_BITS,
                (&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4],
                arg0, arg1, arg2, arg3);
        }
        if (result != 0) {
            ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unkC;
            return (s32 *)result;
        }
    }
    return NULL;
}

s32 func_800BF0E0(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3, s32 arg4, s32 arg5) {
    s32 _gcmapsects_entrypoint_23(s32 *, f32 *, f32 *, f32, f32 *, s32, s32);
    s32 func_800AC638(s32, s32, f32 *, f32 *, f32, f32 *, s32, s32);
    s32 result;
    s32 hit;

    result = 0;
    ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = 0;
    if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) {
        result = _gcmapsects_entrypoint_23(&MAP_COLLISION_BITS, arg0, arg1, arg2, arg3, arg4, arg5);
    }
    if (result == 0 && ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A != 0) {
        result = func_800AC638(MAP_COLLISION_BITS,
            (&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4],
            arg0, arg1, arg2, arg3, arg4, arg5);
    }
    if (result != 0) {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unkC;
    }
    if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk56 == 0) {
        return result;
    }
    hit = func_800AC638(((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2C,
        (&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk55 + 15],
        arg0, arg1, arg2, arg3, arg4, arg5);
    if (hit != 0) {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk38;
        return hit;
    }
    return result;
}

void *func_800BF228(f32 *position, f32 radius, f32 *normal, u32 flag_filter) {
    void *_gcmapsects_entrypoint_26(s32 *, f32 *, f32, f32 *, u32);
    void *func_800AC978(u16 *, u16 *, f32 *, f32, f32 *, u32);
    void *result;
    void *hit;

    result = 0;
    ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = 0;
    if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) {
        result = _gcmapsects_entrypoint_26(&MAP_COLLISION_BITS, position, radius, normal, flag_filter);
    }
    if (result == 0 && ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2A != 0) {
        result = func_800AC978(*(u16 **)&MAP_COLLISION_BITS,
            ((u16 **)&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk29 + 4],
            position, radius, normal, flag_filter);
    }
    if (result != 0) {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unkC;
    }
    if (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk56 == 0) {
        return result;
    }
    hit = func_800AC978(((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk2C_u16p,
        ((u16 **)&MAP_COLLISION_BITS)[((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk55 + 15],
        position, radius, normal, flag_filter);
    if (hit != 0) {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1B0 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk38;
        return hit;
    }
    return result;
}

s32 *func_800BF340(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 arg3, f32 arg4) {
    s32 *func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    s32 *sp24;

    func_800EE7F8(sp28, arg1);
    func_800EFB24(sp34, sp28, arg0);
    func_800EF368(sp34, arg4);
    func_800EF04C(sp28, sp34);
    sp24 = func_800BEF00(arg0, sp28, arg2, arg3);
    if (sp24 == NULL) {
        return NULL;
    }
    func_800EF3DC(sp28, sp34);
    func_800EE7F8(arg1, sp28);
    return sp24;
}

int func_800BF3E4(void) {
    return (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk5A != 0 ||
            ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77 != 0) &&
           ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk5C != 0;
}

void func_800BF420()
{
    _gcmapDll_entrypoint_4(&MAP_COLLISION_BITS);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800BF444(void) {
    BT_IDO_ONLY(s32 _gcmapDll_entrypoint_3(s32 *);)
    s32 func_800C6A28(s32 *(*)(f32 *, f32 *, f32 *, s32), s32 (*)(f32 *, f32 *, f32, f32 *, s32, s32), void *(*)(f32 *, f32, f32 *, u32), s32 (*)());
    s32 *func_800BEF00(f32[3], f32[3], f32[3], s32);
    _gcmapDll_entrypoint_3(&MAP_COLLISION_BITS);
    BT_NATIVE_ONLY(return) func_800C6A28(&func_800BEF00, &func_800BF0E0, &func_800BF228, func_800BEB4C);
}

void func_800BF48C(s32 arg0, s32 arg1, s32 arg2) {
    (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk85) = arg0;
    (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk86) = arg1;
    (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk87) = arg2;
}    typedef struct { s32 unk0; u8 pad4[0x26]; s8 unk2A; } Obj1E97EF0_func_800BF4A4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800BF4A4(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (arg0 * 0x2C) + (s8 *)&MAP_COLLISION_BITS;
    if ((((Obj1E97EF0_func_800BF4A4_temp_v0 *)temp_v0)->unk0) != 0) {
        (((Obj1E97EF0_func_800BF4A4_temp_v0 *)temp_v0)->unk2A) = arg1;
    }
}

/* extern */

void func_800BF4DC(s32 arg0, s32 arg1) {
    s32 _idworldmake_entrypoint_5(s32);
    if (arg1 != *(u8 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 0x2B)) {
        if (*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 4) != 0) {
            _idworldmake_entrypoint_5(*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 4));
        }
    }
    *(u8 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 0x2B) = arg1;
}

void func_800BF544(s32 arg0, s32 arg1, s32 arg2) {
    s32 _idworldmake_entrypoint_6(s32, s32, s32);
    s32 temp_a3;

#if defined(BT_NATIVE) && defined(BT_ILP32)
    temp_a3 = (s32)(u32)native_map.layers[arg0].instances;
#else
    temp_a3 = D_801285B4[arg0].value;
#endif
    if (temp_a3 != 0) {
        _idworldmake_entrypoint_6(temp_a3, arg1, arg2);
    }
}

void func_800BF58C(void) {
    s32 defrag(s32);
    s32 func_800DC060(s32);
    BtIntPtr func_800EE5D8(BtIntPtr);
    s32 func_800F9F90(s32, s32);
    BT_IDO_ONLY(extern s32 D_801285B0;)
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk178) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk178) = func_800DC060((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk178));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk17C) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk17C) = defrag((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk17C));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk4) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk4) = func_800EE5D8((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk4));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk30) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk30) = func_800EE5D8((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk30));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1C) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1C) = func_800F9F90((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1C), (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk18));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk48) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk48) = func_800F9F90((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk48), (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk44));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk8) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk8) = defrag((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk8));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk34) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk34) = defrag((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk34));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk68) = defrag((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk68));
    }
}

void func_800BF68C(void) {
    BT_IDO_ONLY(s32 _gcmapDll_entrypoint_1(s32 *);)
    BT_IDO_ONLY(extern s8 D_80128634;)
    _gcmapDll_entrypoint_1(&MAP_COLLISION_BITS);
    D_80128634 = -1;
}

/* extern */

s32 func_800BF6B8(void) {
    s32 _gcmapsects_entrypoint_24(s32 *);
    s32 var_v0;

    var_v0 = 0;
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        if (_gcmapsects_entrypoint_24(&MAP_COLLISION_BITS) != 0) {
            return 2;
        }
        var_v0 = 1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

void * func_800BF704(void) {
    return &MAP_COLLISION_BITS;
}

/* extern */

void func_800BF710(void) {
    s32 _gcmapsects_entrypoint_9(s32 *);
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk77) != 0) {
        _gcmapsects_entrypoint_9(&MAP_COLLISION_BITS);
    }
}

void func_800BF744(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&MAP_COLLISION_BITS)[arg0]) + (0x88))) = arg1;
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk88) < arg0) {
        (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk88) = arg0;
    }
}    typedef struct { u8 pad0[0x88]; s32 unk88; } Obj1E97EF0_func_800BF774_var_s1; /* offsets.py genstruct: fields from raw offsets on var_s1; rename once understood */

void func_800BF774(void) {
    void func_800DF744(s32, s32);
#if defined(BT_NATIVE) && defined(BT_ILP32)
    s32 index;
    for (index = 1; index <= native_map.switches[0]; index++) {
        func_800DF744(index, native_map.switches[index]);
    }
#else
    s32 *var_s1;
    s32 var_s0;
    var_s0 = 1;
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk88) > 0) {
        var_s1 = &D_801285B4;
        do {
            func_800DF744(var_s0, (((Obj1E97EF0_func_800BF774_var_s1 *)var_s1)->unk88));
            var_s0 += 1;
            var_s1 += 1;
        } while ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk88) >= var_s0);
    }
#endif
}
/* extern */

void func_800BF7E0(void) {
    s32 _rtlight_entrypoint_2(s32, s32, u8 *, s32);
    s32 _vpmodule_entrypoint_2(s32, s32);
    s32 func_800BEB64(s32);
    s32 func_800BEB98(s32);
    s32 sp20;
    u8 *sp28;
    s32 sp24;

    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk8) != 0) {
        sp24 = func_800BEB64(0);
        sp28 = func_800BEBD4(0);
        sp20 = func_800BEB98(0);
        _rtlight_entrypoint_2((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk8), sp24, sp28, sp20);
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk34) != 0) {
        sp24 = func_800BEB64(1);
        sp28 = func_800BEBD4(1);
        sp20 = func_800BEB98(1);
        _rtlight_entrypoint_2((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk34), sp24, sp28, sp20);
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1C) != 0) {
        _vpmodule_entrypoint_2((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk1C), (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk18));
    }
    if ((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk48) != 0) {
        _vpmodule_entrypoint_2((((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk48), (((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk44));
    }
}    typedef struct { u8 unk0; } Obj1E97EF0_D_80128627; /* offsets.py genstruct: fields from raw offsets on &D_80128627; rename once understood */

u32 func_800BF8B0(void) {
    BT_IDO_ONLY(extern u8 D_80128627;)
    return *&((Obj1E97EF0_D_80128627 *)&D_80128627)->unk0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800BF8BC(s32 arg0) {
    BT_IDO_ONLY(s32 _gcmapDll_entrypoint_6(s32 *, s32);)
    BT_NATIVE_ONLY(return) _gcmapDll_entrypoint_6(&MAP_COLLISION_BITS, arg0);
}

s8 func_800BF8E4(void)
{
  s32 _dbvpl_entrypoint_0(s32, s32);
  BT_IDO_ONLY(extern s32 D_80128608;)
  BT_IDO_ONLY(extern s8 D_80128634;)
  s32 i;
  s8 var_v1;
  var_v1 = ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk84;
  if (var_v1 == (-1))
  {
    ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk84 = 0;
    var_v1 = 0;
    i = 0;
    do
    {
#if defined(BT_NATIVE) && defined(BT_ILP32)
      if (native_map.layers[i].light != 0) {
        native_map.lighting_type = 1;
      }
      if (native_map.layers[i].module != 0 &&
          _dbvpl_entrypoint_0((s32)(u32)native_map.layers[i].vpl, 0) != 0) {
        native_map.lighting_type = 2;
      }
      i++;
    } while (i < 2);
#else
      if ((*((s32 *) (((s8 *)&MAP_COLLISION_BITS + i * 0x2C) + 8))) != 0)
      {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk84 = 1;
      }
      if (((*((s32 *) (((s8 *)&MAP_COLLISION_BITS + i * 0x2C) + 0x1C))) != 0) && (_dbvpl_entrypoint_0(*((s32 *) (((s8 *)&MAP_COLLISION_BITS + i * 0x2C) + 0x18)), 0) != 0))
      {
        ((Obj1E97EF0_D_801285B0 *)&MAP_COLLISION_BITS)->unk84 = 2;
      }
      i++;
    }
    while ((s8 *)&D_80128608 != (s8 *)&MAP_COLLISION_BITS + i * 0x2C);
#endif
    var_v1 = D_80128634;
  }
  return var_v1;
}

/* extern */

void func_800BF99C(s32 arg0, s32 arg1, s32 arg2) {
    s32 _idworldmake_entrypoint_7(s32, s32, s32);
    s32 _vpmodule_entrypoint_4(s32, s32, s32, s32);
    if (*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 0x1C) != 0) {
        _vpmodule_entrypoint_4(*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 0x1C), *(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 0x18), arg1, arg2);
    }
    if (*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 4) != 0) {
        _idworldmake_entrypoint_7(*(s32 *)((s8 *)&MAP_COLLISION_BITS + arg0 * 0x2C + 4), arg1, arg2);
    }
}

#if defined(BT_NATIVE) && defined(BT_ILP32)
s32 func_800BFA1C(f32 *arg0, s32 *var_a1) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (arg0[i] < (f32)(native_map.combined_minimum[i] - 100)) return 0;
        if ((f32)(native_map.combined_maximum[i] + 100) < arg0[i]) return 0;
    }
    return 1;
}
#else
s32 func_800BFA1C(f32 *arg0, s32 *var_a1) { extern struct Entry D_801285BC[]; s32 *end; s32 i = 0; f32 temp_f0; var_a1 = &MAP_COLLISION_BITS; end = (s32 *)D_801285BC; while (1) { temp_f0 = arg0[i]; if (temp_f0 < (f32)(var_a1[96] - 100)) { return 0; } if ((f32)(var_a1[99] + 100) < temp_f0) { return 0; } var_a1++; i++; if (var_a1 == end) { break; } } return 1; }

#endif

u8 func_800BFAA4(void) {
    return (*(u8 *)((s8 *)(func_800BF704()) + (0x77)));
}

#endif
