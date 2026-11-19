#include "common.h"

typedef struct {
    u8 active;
    s16 color[4];
    f32 start;
    f32 end;
} FogEntry;

typedef struct {
    u8 count;
    u8 color_sent;
    FogEntry entries[2];
    s16 color[4];
} FogState;

typedef struct {
    s16 *layers;
    s32 count;
} FogLayers;

#ifdef BT_NATIVE
FogState D_8012B320;
FogLayers D_8012B360;
_Static_assert(sizeof(FogEntry) == 0x14 && sizeof(FogState) == 0x34, "fog layout");
#else
extern FogState D_8012B320;
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EAC200_native.inc"
#else
#include "fog_configs.inc"
typedef struct { u8 pad0[0x4]; s8 unk4; u8 pad5[0x1]; s16 unk6; s16 unk8; s16 unkA; s16 unkC; u8 padE[0x2]; f32 unk10; f32 unk14; } Obj1EAC200_func_800D2910_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; u8 unkC; u8 unkD; u8 unkE; u8 unkF; } Obj1EAC200_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_800D2910(s32 arg0, u8 *arg1) {
#ifdef BT_NATIVE
    NativeFogConfig *config = (NativeFogConfig *)arg1;
    FogEntry *entry = &D_8012B320.entries[arg0];
    s32 i;

    entry->active = 1;
    for (i = 0; i < 4; i++) {
        entry->color[i] = config->color[i];
    }
    entry->start = config->start;
    entry->end = config->end;
#else
    u8 *temp_v0;

    temp_v0 = (u8 *)&D_8012B320 + (arg0 * 0x14);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unk4) = 1;
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unk6) = (s16) (((Obj1EAC200_arg1 *)arg1)->unkC);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unk8) = (s16) (((Obj1EAC200_arg1 *)arg1)->unkD);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unkA) = (s16) (((Obj1EAC200_arg1 *)arg1)->unkE);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unkC) = (s16) (((Obj1EAC200_arg1 *)arg1)->unkF);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unk10) = (f32) (((Obj1EAC200_arg1 *)arg1)->unk4);
    (((Obj1EAC200_func_800D2910_temp_v0 *)temp_v0)->unk14) = (f32) (((Obj1EAC200_arg1 *)arg1)->unk8);
#endif
    D_8012B320.count += 1;
}

void func_800D2970(void) {
    D_8012B320.entries[1].active = 0;
    D_8012B320.entries[0].active = 0;
    D_8012B320.color_sent = 0;
    D_8012B320.count = 0;
}

void func_800D298C(void) {
    s32 func_800EA05C();

    NativeFogConfig *var_s0;
    int temp_v0;

    var_s0 = D_8011B530;
    temp_v0 = func_800EA05C();
    D_8012B320.color_sent = D_8012B320.count = 0;
    D_8012B320.entries[0].active = D_8012B320.entries[1].active = 0;
    while (var_s0->map != -1) {
            if (temp_v0 == var_s0->map) {
                if (var_s0->flags & 1) {
                    func_800D2910(0, (u8 *)var_s0);
                }
                if (var_s0->flags & 2) {
                    func_800D2910(1, (u8 *)var_s0);
                }
            }
            var_s0++;
    }
}

void func_800D2A44(Gfx **arg0) {
    s32 func_800A89F8();
    s32 func_800A93E4(s32);
    s32 func_800A9478(s32);
    void func_800E3CB8(f32 *, f32 *);
    s32 func_800F0D90(s32, s32, s32);
    s32 func_800F6BE4(s32);
    s32 func_8010FFD8(s32);
    void func_800D2CC4(void);
    f32 near;
    f32 far;
    f32 first;
    f32 pad;
    s32 index;
    s32 camera;
    s32 visible;
    f32 scale;
    s32 mult;
    s32 offset;
    f32 start;
    f32 end;
    Gfx *gfx;

    if (D_8012B320.count != 0) {
        camera = func_800A9478(func_800A89F8());
        if (func_800F6BE4(camera) != 0) {
            visible = func_8010FFD8(func_800A93E4(camera));
        } else {
            visible = 1;
        }
        if (D_8012B320.entries[1].active && visible) {
            index = 1;
        } else if (D_8012B320.entries[0].active && !visible) {
            index = 0;
        } else {
            return;
        }
        func_800E3CB8(&near, &far);
        scale = far - near;
        if (far != near) {
            D_8012B320.color[0] = D_8012B320.entries[index].color[0];
            D_8012B320.color[1] = D_8012B320.entries[index].color[1];
            D_8012B320.color[2] = D_8012B320.entries[index].color[2];
            D_8012B320.color[3] = D_8012B320.entries[index].color[3];
            start = D_8012B320.entries[index].start;
            end = D_8012B320.entries[index].end;
            offset = 0;
            if (far < start) {
                mult = 0;
            } else {
                scale = (2.0f * far) / scale;
                first = (1.0f - near / start) * scale - 1.0f;
                scale = 1.0f / ((1.0f - near / end) * scale - 1.0f - first);
                mult = (s32)(256.0f * scale);
                offset = (s32)(-256.0f * first * scale);
            }
            gfx = (*arg0)++;
            gfx->words.w0 = 0xDB080000;
            gfx->words.w1 = ((func_800F0D90(mult, -0x7FFF, 0x7FFF) & 0xFFFF) << 16) | (func_800F0D90(offset, -0x7FFF, 0x7FFF) & 0xFFFF);
            func_800D2CC4();
        }
    }
}

void func_800D2C54(Gfx **arg0) {
    if (D_8012B320.color_sent) return;
    gDPSetFogColor((*arg0)++,
        D_8012B320.color[0],
        D_8012B320.color[1],
        D_8012B320.color[2],
        D_8012B320.color[3]);
    D_8012B320.color_sent = 1;
}

void func_800D2CC4(void) {
    BT_IDO_ONLY(extern u8 D_8012B321;)

    BT_DATA_FIELD(D_8012B320.color_sent, D_8012B321) = 0;
}    typedef struct { s32 unk0; s32 unk4; } Obj1EAC200_D_8012B360; /* offsets.py genstruct: fields from raw offsets on &D_8012B360; rename once understood */

void func_800D2CD0(void) {
    void func_800BE58C(s32 *, s32 *);
    void func_800BE52C(s32 *, s32 *);
    Prop *func_800E9D68(s16 *);
    s32 func_800E9DC4(s16 *);
    void *heap_alloc(s32);
    BT_IDO_ONLY(extern s32 D_8012B360;)
    s32 pos[3];
    s32 dimensions[3];
    s32 strides[3];
    s32 base;
    s32 end;
    s16 *cell;
    register s32 i;

    func_800BE58C(dimensions, strides);
    BT_DATA_FIELD(D_8012B360.count, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk4) = dimensions[1];
    BT_DATA_FIELD(D_8012B360.layers, D_8012B360) = BT_IDO_ONLY((s32))heap_alloc(BT_DATA_FIELD(D_8012B360.count, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk4) * 2);
    for (i = 0; i < BT_DATA_FIELD(D_8012B360.count, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk4); i++) {
        BT_DATA_FIELD(D_8012B360.layers[i], *(s16 *)(D_8012B360 + (i << 1))) = 0;
    }
    func_800BE52C(&base, &end);
    for (pos[1] = 0; pos[1] < dimensions[1]; pos[1]++) {
        for (pos[0] = 0; pos[0] < dimensions[0]; pos[0]++) {
            for (pos[2] = 0; pos[2] < dimensions[2]; pos[2]++) {
                cell = ((s16 (*)[4])((u32)(strides[1] * pos[2] * 8 + base) + pos[0] * 8))[strides[0] * pos[1]];
                if (func_800E9D68(cell)) {
                    BT_DATA_FIELD(D_8012B360.layers[pos[1]], *(s16 *)((pos[1] << 1) + D_8012B360)) += func_800E9DC4(cell);
                }
            }
        }
    }
}

void func_800D2E4C(void) {
    BT_NATIVE_ONLY(void heap_free(void *);) BT_IDO_ONLY(s32 heap_free(s32);)
    BT_IDO_ONLY(extern s32 D_8012B360;)
    if (BT_DATA_FIELD(D_8012B360.layers, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk0) != 0) {
        heap_free(BT_DATA_FIELD(D_8012B360.layers, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk0));
        BT_DATA_FIELD(D_8012B360.layers, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk0) = 0;
    }
    BT_DATA_FIELD(D_8012B360.count, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk4) = 0;
}

s32 func_800D2E90(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_8012B360;)
    if ((arg0 < 0) || (arg0 >= BT_DATA_FIELD(D_8012B360.count, ((Obj1EAC200_D_8012B360 *)&D_8012B360)->unk4))) {
        return 0;
    }
    return BT_DATA_FIELD(D_8012B360.layers[arg0], *((s16 *)D_8012B360 + arg0)) ? 1 : 0;
}

void func_800D2EE4(void) {
    BT_NATIVE_ONLY(void *defrag(void *);) BT_IDO_ONLY(s32 defrag(s32);)
    BT_IDO_ONLY(extern s32 D_8012B360;)
    if (BT_DATA_FIELD(D_8012B360.layers, D_8012B360) != 0) {
        BT_DATA_FIELD(D_8012B360.layers, D_8012B360) = defrag(BT_DATA_FIELD(D_8012B360.layers, D_8012B360));
    }
}
#endif
