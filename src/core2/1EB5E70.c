#include "core2/1EB5E70.h"
#include "model_render_banks.inc"
#ifdef BT_NATIVE
#include "core2/geometry_callbacks.h"
#endif
typedef struct {
    s32 header;
    s32 geometry;
    s16 textures;
    s16 flags;
    s32 display_list;
    s32 vertices;
    s32 unk14;
    s32 animation;
    s32 unk1C;
    s32 zones;
    s32 unk24;
    s32 animated_vertices;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 normals;
} ModelData;

#ifndef BT_NATIVE
typedef struct {
    LookAt buffer[32];
    LookAt *current;
    LookAt *end;
    f32 position[3];
} LookAtBuffer;
#endif

s32 D_8012C850[60];
typedef struct { s32 prim[4]; s32 env[4]; } RenderColorState;
typedef struct { void (*before)(s32); s32 before_arg; void (*after)(s32); s32 after_arg; } RenderCallbackState;
typedef struct { s32 mode; f32 values[3]; } RenderTransformState;
typedef struct { s32 asset_id; f32 center; f32 radius; } RenderAssetDrawState;
#if defined(BT_NATIVE) && defined(BT_ILP32)
_Static_assert(sizeof(RenderColorState) == 0x20, "O32 render colors");
_Static_assert(sizeof(RenderCallbackState) == 0x10, "O32 render callbacks");
_Static_assert(sizeof(RenderTransformState) == 0x10, "O32 render transform");
_Static_assert(sizeof(RenderAssetDrawState) == 0x0C, "O32 asset draw state");
_Static_assert(offsetof(RenderColorState, env[3]) == 0x1C, "O32 environment alpha offset");
_Static_assert(offsetof(RenderCallbackState, after) == 0x08, "O32 callback offset");
_Static_assert(offsetof(RenderTransformState, values) == 0x04, "O32 transform values offset");
_Static_assert(offsetof(RenderAssetDrawState, radius) == 0x08, "O32 radius offset");
#endif


typedef void (*GeoCommandFunction)(BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void *), u8 *);
extern GeoCommandFunction *D_8012CF8C;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
typedef NativeDisplayList DisplayListView;
typedef NativeRenderData RenderData;
#else
typedef struct {
    u32 header[2];
    Gfx commands[1];
} DisplayListView;

typedef struct GeometryRenderData {
    f32 scale;
    f32 *position;
    f32 *rotation;
    f32 *origin;
    f32 *extra_rotation;
    u8 *textures;
    DisplayListView *display_list;
    u8 *vertices;
    u8 *animation;
    u8 texture_animation;
    u8 pad25[3];
    u8 *zones;
    BT_NATIVE_ONLY(void *colors;) BT_IDO_ONLY(s32 unk2C;)
    u8 *normals;
    u8 *animated_vertices;
    Mtx *matrices;
} RenderData;
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define D_8012C948 native_render.data
#define D_8012CA40 native_render.look_at
#elif defined(BT_NATIVE)
RenderData D_8012C948;
LookAtBuffer D_8012CA40;
_Static_assert(sizeof(RenderData) == 0x3C && sizeof(LookAtBuffer) == 0x418, "render settings");
#else
extern RenderData D_8012C948;
extern LookAtBuffer D_8012CA40;
#endif

BT_IDO_ONLY(extern DisplayListView *D_8012C960;)
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define RENDER_COLORS native_render
#define RENDER_BEFORE native_render.before
#define RENDER_BEFORE_ARG native_render.before_arg
#define RENDER_AFTER native_render.after
#define RENDER_AFTER_ARG native_render.after_arg
#define RENDER_TRANSFORM_MODE native_render.transform_mode
#define RENDER_TRANSFORM_VALUES native_render.transform
#define RENDER_ASSET_ID native_render.asset_id
#define RENDER_ENV_ALPHA native_render.env[3]
#elif defined(BT_NATIVE)
extern RenderColorState D_8012C988;
extern RenderCallbackState D_8012C9A8;
extern RenderTransformState D_8012C9B8;
extern RenderAssetDrawState D_8012CA18;
#define RENDER_COLORS D_8012C988
#define RENDER_BEFORE D_8012C9A8.before
#define RENDER_BEFORE_ARG D_8012C9A8.before_arg
#define RENDER_AFTER D_8012C9A8.after
#define RENDER_AFTER_ARG D_8012C9A8.after_arg
#define RENDER_TRANSFORM_MODE D_8012C9B8.mode
#define RENDER_TRANSFORM_VALUES D_8012C9B8.values
#define RENDER_ASSET_ID D_8012CA18.asset_id
#define RENDER_ENV_ALPHA D_8012C988.env[3]
#else
extern s32 D_8012C988, D_8012C9A4, D_8012C9A8, D_8012C9AC;
extern void (*D_8012C9B0)(s32);
extern s32 D_8012C9B4, D_8012C9B8, D_8012C9BC, D_8012CA18;
#define RENDER_COLORS (*(RenderColors *)&D_8012C988)
#define RENDER_BEFORE ((void (*)(s32))D_8012C9A8)
#define RENDER_BEFORE_ARG D_8012C9AC
#define RENDER_AFTER D_8012C9B0
#define RENDER_AFTER_ARG D_8012C9B4
#define RENDER_TRANSFORM_MODE D_8012C9B8
#define RENDER_TRANSFORM_VALUES ((f32 *)&D_8012C9B8 + 1)
#define RENDER_ASSET_ID D_8012CA18
#define RENDER_ENV_ALPHA D_8012C9A4
#endif


extern s32 D_8012C824;
extern s32 D_8012C940;

#include "1EB5E70_geometry.inc"

#include "1EB5E70_reset.inc"

typedef struct {
    Gfx* gfx;
    Mtx* mtx;
} GraphicsBuffers;

GraphicsBuffers* func_800A7180();

void* func_800DE498(GraphicsBuffers*, f32*, f32*, f32, f32*, ModelData*);

// modelRender_draw?
void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, u8* arg4) {
    return func_800DE498(func_800A7180(), position, arg1, scale, arg3, (ModelData *)arg4);
}

// the real modelRender_draw?
// the real modelRender_draw?
// the real modelRender_draw?
// the real modelRender_draw?
void *func_800DE498(GraphicsBuffers *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, ModelData *arg5) {


    typedef struct {
        void (*draw)(RenderData *, s32, s32, void *);
        s32 value;
        void (*finish)(void);
    } RenderCallback;
    typedef struct {
        s32 prim[4];
        s32 env[4];
    } RenderColors;
    typedef struct {
        s32 size;
        s16 count;
        s16 padding;
        u8 data[1][8];
    } TextureData;
    extern s32 D_8012C828, D_8012C834, D_8012C838, D_8012C83C;
    extern f32 D_8012C82C, D_8012C830;
    extern u8 D_8012C840;
    extern s32 D_8012C848;
    extern u8 D_8012CA11;
    extern f32 D_8012CA1C, D_8012CA20;
    extern s32 D_8012CA08, D_8012CA28, D_8012C9C8; BT_NATIVE_ONLY(extern void *D_8012CA0C;) BT_IDO_ONLY(extern s32 D_8012CA0C;)
    extern s32 D_8012CE58;
    extern s32 D_8012CE98;
    extern f32 D_8012CEB8[3];
    extern f32 D_8012CEA8;
    BT_IDO_ONLY(extern s32 (*D_8012CEC4)(MtxF *, s32 *, s16);)
    extern s32 D_8012C820;
    extern Gfx D_80122DB0[], D_80122DF0[], D_80122EB0[], D_80122F70[];
    extern s32 D_80122DC8[], D_80122DCC[];
    BT_IDO_ONLY(extern RenderCallback D_80123030[];) BT_IDO_ONLY(extern RenderCallback D_80123038[];)

    void func_800E39A8(BtIntPtr, BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_800DE318(void);
    void func_800EFD24(f32 *);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    f32 mlAbsF(f32);
    f32 func_800EEF94(f32 *);
    f32 func_800E42C0(void);
    s32 func_800E3E8C(f32 *, f32);
    s32 func_800DB9FC(u8, s32, s32 *);
    void func_80013C80(Mtx *, LookAt *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
    void func_800D2C54(Gfx **);
    u8 *func_800B27E0(u8 *);
#ifndef BT_NATIVE
    void func_800ADCD0(u8 **, u8 *);
#endif
#ifndef BT_NATIVE
    void func_800AE160(u8 **, u8 *, s32);
#endif
    BT_IDO_ONLY(void _dbzone_entrypoint_1(u8 *, void *, f32, f32 *);)
    BT_NATIVE_ONLY(void _dbzone_entrypoint_1(u8 *, f32 *, f32, f32 *);)

#ifndef BT_NATIVE
    void _glzone_entrypoint_2(s32);
#endif
#ifndef BT_NATIVE
    void _dbanim_entrypoint_1(u8 *, u8 *, u8 *, u8 *);
#endif
#ifndef BT_NATIVE
    void _dbanim_entrypoint_0(u8 *, u8 *, u8 *);
#endif
    MtxF *func_80019CD4(void);
    void func_80019750(f32 *, f32 *, f32, f32 *);
#ifndef BT_NATIVE
    void func_800AE598(u8 *, Mtx **);
#endif
#ifndef BT_NATIVE
    BT_IDO_ONLY(void func_8010EF70(RenderData *, s32, s32, void *);) BT_NATIVE_ONLY(void func_8010EF70(RenderData *, s32, void *, const f32 *);)
#endif
    void func_800E4640(Gfx **);
    void func_8010F270(void);
    void mlMtxRotatePYR(f32, f32, f32);
    void mlMtxScale_xyz(f32, f32, f32);
#ifndef BT_NATIVE
    void func_80018C50(void *);
#endif
#ifndef BT_NATIVE
    void mlMtxGet(void *);
#endif
    void mlMtxApply(Mtx *);
    f32 camera_focus[3];
    f32 object_position[3];
    f32 distance;
    f32 local_norm;
    f32 global_norm;
    void *opaque_mode;
    Gfx *gfx;
    u8 *verts;
    s32 alpha;
    f32 tmp_f0;
    void *translucent_mode;

    D_8012C940 = 0;
    func_800E39A8((BtIntPtr)&D_8012CE98, (BtIntPtr)&D_8012CEA8);
    if (arg1 != NULL) {
        func_800EE7F8(object_position, arg1);
    } else {
        func_800EFD24(object_position);
    }
    func_800EFB24((s32 *)camera_focus, (s32 *)object_position, &D_8012CE98);
    if (30000.0f < mlAbsF(camera_focus[0]) ||
        30000.0f < mlAbsF(camera_focus[1]) ||
        30000.0f < mlAbsF(camera_focus[2])) {
        func_800DE318();
        return NULL;
    }
    if (arg5) {
        verts = D_8012C948.vertices ? D_8012C948.vertices : ((u8 *)arg5 + arg5->vertices);
        global_norm = (u32)*(u16 *)(verts + 0x14);
        local_norm = (u32)*(u16 *)(verts + 0x12);
    } else {
        global_norm = D_8012CA20;
        local_norm = D_8012CA1C;
    }
    distance = func_800EEF94(camera_focus);
    if (4000.0f <= distance && D_8012C82C == 30000.0f) {
        if (local_norm * arg3 * D_8012C830 * 50.0f < D_8012C82C) {
            D_8012C82C = local_norm * arg3 * D_8012C830 * 50.0f;
        }
    }
    D_8012C82C *= func_800E42C0();
    if (D_8012C82C <= distance) {
        func_800DE318();
        return NULL;
    }
    D_8012C940 = D_8012C828 ? func_800E3E8C(object_position, global_norm * arg3) : 1;
    if (!D_8012C940) {
        func_800DE318();
        return NULL;
    }
    if (RENDER_BEFORE != NULL) {
        RENDER_BEFORE(RENDER_BEFORE_ARG);
    }
    if (arg5 == 0) {
        arg5 = (ModelData *)func_800D674C(RENDER_ASSET_ID);
        if (arg5 == 0) {
            func_800DE318();
            return NULL;
        }
    }
    if (!D_8012C948.display_list) {
        D_8012C948.display_list = (DisplayListView *)((u8 *)arg5 + arg5->display_list);
    }
    if (!D_8012C948.textures) {
        D_8012C948.textures = ((u8 *)arg5 + arg5->textures);
    }
    if (!D_8012C948.vertices) {
        D_8012C948.vertices = ((u8 *)arg5 + arg5->vertices);
    }
    D_8012C948.zones = arg5->zones == 0 ? NULL : ((u8 *)arg5 + arg5->zones);
    if (!D_8012C948.normals) {
        D_8012C948.normals = arg5->normals == 0 ? NULL : ((u8 *)arg5 + arg5->normals);
    }
    if (D_8012C834) {
        tmp_f0 = D_8012C82C - 700.0f;
        if (tmp_f0 < distance) {
            alpha = (s32)((1.0f - (distance - tmp_f0) / 700.0f) * 256.0f);
            RENDER_COLORS.env[3] = (RENDER_ENV_ALPHA * alpha) / 256;
        }
    }
    gfx = arg0->gfx;
    gSPSegment(gfx++, 1, osVirtualToPhysical((u8 *)D_8012C948.vertices + 0x18));
    gSPSegment(gfx++, 2, osVirtualToPhysical(((TextureData *)D_8012C948.textures)->data[((TextureData *)D_8012C948.textures)->count]));
    if (D_8012C948.texture_animation) {
        s32 i;
        s32 offset;
        for (i = 0; i != 7; i++) {
            if (func_800DB9FC(D_8012C948.texture_animation, i, &offset)) {
                gSPSegment(gfx++, 15 - i, osVirtualToPhysical(((TextureData *)D_8012C948.textures)->data[((TextureData *)D_8012C948.textures)->count] + offset));
            }
        }
    }
    if (RENDER_COLORS.prim[3] && D_8012C83C != 3) {
        RENDER_COLORS.env[3] = RENDER_COLORS.env[3] + (RENDER_COLORS.prim[3] * (255 - RENDER_COLORS.env[3])) / 255;
        RENDER_COLORS.prim[3] = 0;
    }
    gDPPipeSync(gfx++);
    gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetBlendColor(gfx++, 0, 0, 0, 128);
    gDPSetPrimColor(gfx++, 0, 0, RENDER_COLORS.prim[0], RENDER_COLORS.prim[1], RENDER_COLORS.prim[2], RENDER_COLORS.prim[3]);
    gDPSetEnvColor(gfx++, RENDER_COLORS.env[0], RENDER_COLORS.env[1], RENDER_COLORS.env[2], RENDER_COLORS.env[3]);
    if (D_8012CA28) {
        gSPSetGeometryMode(gfx++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(gfx++, G_ZBUFFER);
    }
    if (RENDER_COLORS.env[3] == 255) {
        {
            Gfx *packet = gfx++;
            packet->words.w0 = _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(G_MW_SEGMENT, 16, 8) | (3 * 4);
            opaque_mode = BT_DATA_FIELD(model_material_modes[D_8012CA28].opaque, (void *)D_80122DC8[D_8012CA28 * 2]);
            packet->words.w1 = osVirtualToPhysical(opaque_mode);
        }
    } else {
        {
            Gfx *packet = gfx++;
            packet->words.w0 = _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(G_MW_SEGMENT, 16, 8) | (3 * 4);
            translucent_mode = BT_DATA_FIELD(model_material_modes[D_8012CA28].translucent, (void *)D_80122DCC[D_8012CA28 * 2]);
            packet->words.w1 = osVirtualToPhysical(translucent_mode);
        }
    }
    if (arg5->flags & 2) {
        D_8012C820 = (BtIntPtr)D_80122DF0;
    } else if (arg5->flags & 0x80) {
        D_8012C820 = (BtIntPtr)D_80122EB0;
    } else if (arg5->flags & 0x100) {
        D_8012C820 = (BtIntPtr)D_80122F70;
    } else {
        D_8012C820 = NULL;
    }
    if (D_8012C820) {
        gSPDisplayList(gfx++, (u32)D_8012C820 - 0x80000000);
    }
    if (arg5->flags & 4) {
        if (camera_focus[2] == 0.0f) {
            camera_focus[2] = -0.1f;
        }
        func_80013C80(arg0->mtx, (LookAt *)D_8012CA40.current, D_8012CA40.position[0], D_8012CA40.position[1], D_8012CA40.position[2],
            camera_focus[0], camera_focus[1], camera_focus[2], 0.0f, 1.0f, 0.0f);
        gSPLookAt(gfx++, D_8012CA40.current);
        osWritebackDCache(D_8012CA40.current, 0x20);
        D_8012CA40.current++;
        if (D_8012CA40.current == D_8012CA40.end) {
            D_8012CA40.current = D_8012CA40.buffer;
        }
    }
    if (arg5->flags & 0x20) {
        func_800D2C54(&gfx);
    }
    if (D_8012C948.animation && !arg5->animation) {
        D_8012C948.animation = NULL;
    } else if (!D_8012C948.animation && arg5->animation) {
        if (D_8012C824 == 0) {
            func_800ADCD0((u8 **)&D_8012C840, func_800B27E0((u8 *)arg5));
        } else {
            func_800AE160((u8 **)&D_8012C840, func_800B27E0((u8 *)arg5), D_8012C824);
        }
        D_8012C948.animation = *(u8 **)&D_8012C840;
    }
    if (D_8012C948.zones) {
        _dbzone_entrypoint_1(D_8012C948.zones, BT_NATIVE_ONLY((f32 *))&D_8012CE98, arg3, object_position);
        if (D_8012C848) {
            _glzone_entrypoint_2(D_8012C848);
        }
    }
    if (arg5->animated_vertices && D_8012C948.animation) {
        D_8012C948.animated_vertices = ((u8 *)arg5 + arg5->animated_vertices);
        if (D_8012C948.normals && D_8012C838 == 1 && D_8012CA11 != 2 && D_8012CA11 != 3) {
            _dbanim_entrypoint_1(D_8012C948.animated_vertices, D_8012C948.vertices, D_8012C948.animation, D_8012C948.normals);
        } else {
            _dbanim_entrypoint_0(D_8012C948.animated_vertices, D_8012C948.vertices, D_8012C948.animation);
        }
    }
    func_80019CD4();
    func_80019750(object_position, arg2, arg3, arg4);
    switch (RENDER_TRANSFORM_MODE) {
        case 1:
            mlMtxRotatePYR(RENDER_TRANSFORM_VALUES[0], RENDER_TRANSFORM_VALUES[1], RENDER_TRANSFORM_VALUES[2]);
            break;
        case 2:
            mlMtxScale_xyz(RENDER_TRANSFORM_VALUES[0], RENDER_TRANSFORM_VALUES[1], RENDER_TRANSFORM_VALUES[2]);
            break;
        case 3:
            #if defined(BT_NATIVE) && !defined(BT_ILP32)
            mlMtxApply(&native_render.extra_matrix);
#else
            func_80018C50(&D_8012C9C8);
#endif
            break;
    }
    mlMtxGet(&D_8012CE58);
    mlMtxApply(arg0->mtx);
    if (arg5->flags & 0x40) {
        gSPMatrix(gfx++, (u32)arg0->mtx - 0x80000000, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
        arg0->mtx++;
        if (!D_8012C948.matrices) {
            Mtx *matrices = arg0->mtx;
            func_800AE598(D_8012C948.animation, &arg0->mtx);
            D_8012C948.matrices = matrices + 1;
        }
        gSPSegment(gfx++, 5, osVirtualToPhysical(D_8012C948.matrices));
        if (D_8012C820) {
            gSPSegment(gfx++, 6, osVirtualToPhysical((void *)D_8012C820));
        }
    } else {
        gSPMatrix(gfx++, arg0->mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
        arg0->mtx++;
    }
    D_8012C948.position = object_position;
    D_8012C948.rotation = arg2;
    D_8012C948.scale = arg3;
    D_8012C948.origin = arg4;
    #if defined(BT_NATIVE) && !defined(BT_ILP32)
    D_8012C948.extra_rotation = RENDER_TRANSFORM_MODE == 1 ? RENDER_TRANSFORM_VALUES : NULL;
#elif defined(BT_NATIVE)
    D_8012C948.extra_rotation = RENDER_TRANSFORM_MODE == 1 ? D_8012C9B8.values : NULL;
#else
    D_8012C948.extra_rotation = D_8012C9B8 == 1 ? (f32 *)&D_8012C9BC : NULL;
#endif
    if (arg2) {
        func_800EE7F8(D_8012CEB8, arg2);
    } else {
        func_800EFD24(D_8012CEB8);
    }
    arg0->gfx = gfx;
    if (arg5->flags & 0x10) {
        func_8010EF70(&D_8012C948, 0, 0, &D_8012CE98);
    }
    if (D_8012C838 == 1 BT_NATIVE_ONLY(&& D_8012CA11 < 5)) {
#ifdef BT_NATIVE
        GeometryCallbacks *callbacks = &D_80123030[D_8012CA11];
        callbacks->begin(&D_8012C948, D_8012CA08, D_8012CA0C, (const f32 *)&D_8012CE98);
        D_8012CEC4 = callbacks->vertex;
#else
        if (D_80123030[D_8012CA11].draw) {
            D_80123030[D_8012CA11].draw(&D_8012C948, D_8012CA08, D_8012CA0C, &D_8012CE98);
        }
        D_8012CEC4 = (s32 (*)(MtxF *, s32 *, s16))D_80123030[D_8012CA11].value;
#endif
    }
    func_800DE2A4(BT_IDO_ONLY((BtIntPtr)arg0) BT_NATIVE_ONLY((void *)arg0), ((u8 *)arg5 + arg5->geometry));
    if (arg5->flags & 0x40) {
        func_800E4640(&arg0->gfx);
    } else {
        gSPPopMatrix(arg0->gfx++, G_MTX_MODELVIEW);
    }
    if (arg5->flags & 0x182) {
        gSPDisplayList(arg0->gfx++, OS_K0_TO_PHYSICAL(D_80122DB0));
    }
    if (D_8012C838 == 1 BT_NATIVE_ONLY(&& D_8012CA11 < 5)) {
#ifdef BT_NATIVE
        if (D_80123030[D_8012CA11].finish) D_80123030[D_8012CA11].finish();
#else
        if (D_80123038[D_8012CA11].draw) {
            ((void (*)(void))D_80123038[D_8012CA11].draw)();
        }
#endif
        D_8012CEC4 = 0;
    }
    if (arg5->flags & 0x10) {
        func_8010F270();
    }
    if (RENDER_AFTER) {
        RENDER_AFTER(RENDER_AFTER_ARG);
    }
    if (arg5->flags & 4) {
        LookAt *current = D_8012CA40.current;

        /* IDO retains the original empty reflection branch with this aggregate self-copy. */
        *current = *current;
    }
    func_800DE318();
    return (void *)arg5;
}

#include "1EB5E70_state.inc"

ImageStruct *func_800DF944(void *a0, f32 *coords, f32 a2, f32 a3, f32 *a4, s32 a5, ImageStruct *a6) {
    s32 func_800A89F8();
    f32 func_800A8AF0(s32);
    void func_800E42F0();
    void func_800E4640(Gfx **);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);

    extern s16 widescreen_enabled;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_800E42F0(a0, a5);
    if (coords != NULL) {
        func_800EFA4C(sp44, coords[0] * 4.0f - 608.0f, 456.0f - coords[1] * 4.0f, -10.0f);
    } else {
        func_800EFA4C(sp44, 0.0f, 0.0f, -10.0f);
    }
    if (a5 != 0 && widescreen_enabled != 0) {
        sp44[0] *= func_800A8AF0(func_800A89F8()) / 1.3333334f;
    }
    func_800EFA4C(sp38, 0.0f, 0.0f, a2);
    if (a4 != NULL) {
        func_800EFA4C(sp2C, a4[0], a4[1], 0.0f);
    } else {
        func_800EFD24(sp2C);
    }
    func_800DF830(0);
    func_800DF440(0);
    a6 = func_800DE498(a0, sp44, sp38, 4.0f * a3, sp2C, (ModelData *)a6);
    func_800E4640(a0);
    return a6;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012C820 BT_DATA(4, bss_core2bss2, 0x30);
s32 D_8012C824 BT_DATA(4, bss_core2bss2, 0x34);
s32 D_8012C828 BT_DATA(4, bss_core2bss2, 0x38);
f32 D_8012C82C BT_DATA(4, bss_core2bss2, 0x3C);
f32 D_8012C830 BT_DATA(4, bss_core2bss2, 0x40);
s32 D_8012C834 BT_DATA(4, bss_core2bss2, 0x44);
s32 D_8012C838 BT_DATA(4, bss_core2bss2, 0x48);
s32 D_8012C83C BT_DATA(4, bss_core2bss2, 0x4C);
u8 D_8012C840 BT_DATA(4, bss_core2bss2, 0x50);
s32 D_8012C844 BT_DATA(4, bss_core2bss2, 0x54);
s32 D_8012C848 BT_DATA(4, bss_core2bss2, 0x58);
s32 D_8012C940 BT_DATA(16, bss_core2bss2_1, 0x0);
#if defined(BT_ILP32)
RenderColorState D_8012C988 BT_DATA(4, bss_core2bss2_1, 0x48);
RenderCallbackState D_8012C9A8 BT_DATA(4, bss_core2bss2_1, 0x68);
RenderTransformState D_8012C9B8 BT_DATA(4, bss_core2bss2_1, 0x78);
RenderAssetDrawState D_8012CA18 BT_DATA(4, bss_core2bss2_1, 0xD8);
#endif
s32 D_8012C9C8 BT_DATA(4, bss_core2bss2_1, 0x88);
void *D_8012CA0C BT_DATA(4, bss_core2bss2_1, 0xCC);
s32 D_8012CA08 BT_DATA(4, bss_core2bss2_1, 0xC8);
u8 D_8012CA11 BT_DATA(4, bss_core2bss2_1, 0xD1);
s32 D_8012CA28 BT_DATA(4, bss_core2bss2_1, 0xE8);
s16 D_8012CA38 BT_DATA(4, bss_core2bss2_1, 0xF8);
s32 D_8012CE58 BT_DATA(4, bss_core2bss2_1, 0x518);
s32 D_8012CE98 BT_DATA(4, bss_core2bss2_1, 0x558);
f32 D_8012CEA8 BT_DATA(4, bss_core2bss2_1, 0x568);
f32 D_8012CEAC BT_DATA(4, bss_core2bss2_1, 0x56C);
f32 D_8012CEB8 [ 3 ] BT_DATA(4, bss_core2bss2_1, 0x578);
f32 D_8012CEC8 BT_DATA(4, bss_core2bss2_1, 0x588);
s32 D_8012CED0 BT_DATA(4, bss_core2bss2_1, 0x590);
s32 D_8012CEE0 BT_DATA(4, bss_core2bss2_1, 0x5A0);
s32 D_8012CEF0 BT_DATA(4, bss_core2bss2_1, 0x5B0);
f32 D_8012CEFC BT_DATA(4, bss_core2bss2_1, 0x5BC);
s32 D_8012CF00 BT_DATA(4, bss_core2bss2_1, 0x5C0);
s32 D_8012CF10 BT_DATA(4, bss_core2bss2_1, 0x5D0);
s32 D_8012CF20 BT_DATA(4, bss_core2bss2_1, 0x5E0);
f32 D_8012CF2C BT_DATA(4, bss_core2bss2_1, 0x5EC);
s32 D_8012CF30 BT_DATA(4, bss_core2bss2_1, 0x5F0);
s32 D_8012CF40 BT_DATA(4, bss_core2bss2_1, 0x600);
s32 D_8012CF50 BT_DATA(4, bss_core2bss2_1, 0x610);
f32 D_8012CF60 [ 3 ] BT_DATA(4, bss_core2bss2_1, 0x620);
f32 D_8012CF70 [ 3 ] BT_DATA(4, bss_core2bss2_1, 0x630);
f32 D_8012CF80 [ 3 ] BT_DATA(4, bss_core2bss2_1, 0x640);
GeoCommandFunction * D_8012CF8C BT_DATA(4, bss_core2bss2_1, 0x64C);
#endif
