#include "common.h"

void func_800A5DB0(Actor *arg0) {
    void *func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, void *);
    void func_800DF830(s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F1988(f32 *, f32 *, f32 *);
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F554C(s32);
    void func_800F5680(s32, f32 *);

    f32 pad;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp48;
    f32 sp44;
    f32 sp38[3];
    f32 sp34;

    func_800EE7F8(sp58, arg0->position);
    sp44 = ((f32 *)arg0->actorData)[3];
    sp34 = func_800F10B4(sp58[1] - sp44, 0.0f, 300.0f, 0.43f, 0.28f);
    sp48 = BT_IDO_ONLY(func_800F554C(arg0->unk74_7)) BT_NATIVE_ONLY(((union { s32 i; f32 f; }){ .i = func_800F554C(arg0->unk74_7) }).f) * (sp34 * arg0->unk58);
    sp58[1] = sp44;
    func_800F5680(arg0->unk74_7, sp38);
    func_800F1988(sp38, &arg0->rotation[0], &arg0->rotation[1]);
    sp4C[0] = arg0->rotation[0];
    sp4C[1] = arg0->rotation[1];
    sp4C[2] = 0.0;
    func_800EF334(sp38, 0.0f);
    func_800EE780(arg0->position, sp58, sp38);
    func_800DF830(3);
    func_800DE448(arg0->position, sp4C, sp48, NULL, func_800D674C(0x637));
}

void func_800A5EC4(Gfx **arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    extern Gfx D_8011A2F8[];
    extern Gfx D_8011A350[];
    Gfx *gfx = *arg0;
    s32 rows;
    s32 end;

    if (arg4 != 0) {
        arg4 = (arg4 + 15) & 0xFFF0;
        if (arg5 != 0) {
            rows = 0x1000 / arg4;
            gSPDisplayList(gfx++, D_8011A2F8 - 0x10000000);
            gDPSetBlendColor(gfx++, 0, 0, 0, 1);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (arg6 << 7) / 255);
if (!arg1) {}
            end = arg3 + arg5;
            gDPSetTextureImage(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, 304, osVirtualToPhysical(arg1));
            gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, (arg4 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, (arg4 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            for (; arg3 < end; arg3 += rows) {
                if (end - arg3 < rows) {
                    rows = end - arg3;
                }
                gDPLoadSync(gfx++); gDPLoadTile(gfx++, G_TX_LOADTILE, arg2 << 2, arg3 << 2, (arg2 + arg4 - 1) << 2, (arg3 + rows - 1) << 2); gDPSetTileSize(gfx++, G_TX_RENDERTILE, arg2 << 2, arg3 << 2, (arg2 + arg4 - 1) << 2, (arg3 + rows - 1) << 2);
                {
                    Gfx *rect = gfx++; rect->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL((arg2 + arg4) * 4, 12, 12) | _SHIFTL((arg3 + rows) * 4, 0, 12);
                    rect->words.w1 = _SHIFTL(G_TX_RENDERTILE, 24, 3) | _SHIFTL(arg2 * 4, 12, 12) | _SHIFTL(arg3 * 4, 0, 12);
                    gImmp1(gfx++, G_RDPHALF_1, _SHIFTL(arg2 << 5, 16, 16) | _SHIFTL(arg3 << 5, 0, 16));
                    gImmp1(gfx++, G_RDPHALF_2, _SHIFTL(0x400, 16, 16) | _SHIFTL(0x400, 0, 16));
                }
            }
            gSPDisplayList(gfx++, D_8011A350 - 0x10000000);
            *arg0 = gfx;
        }
    }
}

void func_800A61D4(void) {
    typedef struct { s32 color[4]; } Color;
    void func_800DF580(void *arg0, void *arg1);
    void func_800DF830(s32 arg0);
    extern Color D_8011A380;
    extern Color D_8011A390;
    Color sp28 = D_8011A380;
    Color sp18 = D_8011A390;
    func_800DF580(&sp28, &sp18);
    func_800DF830(3);
}

void func_800A6250(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    typedef struct player_state_s PlayerState;
    typedef struct { f32 m[4][4]; } MtxF;
    PlayerState *func_800F53D0(BtIntPtr);
    void *func_80092B04(PlayerState *, s32);
    f32 func_80092BE8(PlayerState *);
    f32 func_8009BFCC(PlayerState *);
    void mlMtxGet(MtxF *);
    void mlMtxRotYaw(f32);
    void mlMtxRotPitch(f32);
    void mlMtxRotRoll(f32);
    void *_babackpack_entrypoint_1(PlayerState *);
    void _babackpack_entrypoint_2(PlayerState *);
    f32 _babackpack_get_scale(PlayerState *);
    s32 _bapreload_entrypoint_1(s32, s32 *);
    f32 baroll_get(PlayerState *);
    f32 func_80013A7C(f32);
    BtIntPtr func_8001575C(void);
    s32 func_80019CD4(void);
    BtIntPtr func_8008CA74(PlayerState *);
    u32 func_80092738(s32 *);
    f32 func_80092BDC(PlayerState *);
    s32 func_80092E80(PlayerState *);
    void func_800A06E8(BtIntPtr);
    void func_800A5EC4();
    void func_800A61D4(void);
    Gfx **func_800A7180(void);
    void func_800AE708(s32, u8 *, s32 *, u8 *);
    f32 func_800B2354(void *);
    u8 *func_800B27E0(u8 *);
    void *func_800B2840(void *);
    void *func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, void *);
    void *func_800DF330(void);
    void func_800DF41C(BtIntPtr);
    void func_800DF540(MtxF *);
    void func_800DF72C(BtIntPtr);
    void func_800E4190(f32 *, f32 *, s32 *);
    void func_800E7CF4(Gfx **);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800F23D0(MtxF *, f32 *, f32 *);
    void func_800F254C(MtxF *, f32 *, f32);
    void func_800F274C(MtxF *);
    void func_800F27D4(f32 [4][4], f32 [4][4], f32 [4][4]);
    s32 func_800F5410(BtIntPtr);

    MtxF projection;
    MtxF rotation;
    PlayerState *player;
    u8 *model;
    u8 *originalModel;
    s32 modelId;
    s32 cached;
    register f32 dot;

    player = func_800F53D0(arg0->unk74_7);
    modelId = func_800F5410(arg0->unk74_7);
    model = func_800D674C(_bapreload_entrypoint_1(modelId, &cached));
    originalModel = func_80092B04(player, 0);
    func_800F274C(&projection);
    dot = func_800EEAA4(arg3, arg2);
    if (dot < 0.01f) {
        return;
    }
    if (dot < 0.4f) {
        f32 axis[3];
        f32 angle;
        MtxF correction;

        angle = func_80013A7C(0.4f);
        func_800EE97C(axis, arg2, arg3);
        func_800F254C(&correction, axis, angle);
        func_800F23D0(&correction, arg3, arg2);
        dot = func_800EEAA4(arg3, arg2);
    }
    dot = 1.0f / dot;
    projection.m[0][0] = 1.0f - arg2[0] * arg3[0] * dot;
    projection.m[0][1] = -arg2[0] * arg3[1] * dot;
    projection.m[0][2] = -arg2[0] * arg3[2] * dot;
    projection.m[1][0] = -arg2[1] * arg3[0] * dot;
    projection.m[1][1] = 1.0f - arg2[1] * arg3[1] * dot;
    projection.m[1][2] = -arg2[1] * arg3[2] * dot;
    projection.m[2][0] = -arg2[2] * arg3[0] * dot;
    projection.m[2][1] = -arg2[2] * arg3[1] * dot;
    projection.m[2][2] = 1.0f - arg2[2] * arg3[2] * dot;
    func_80019CD4();
    mlMtxRotYaw(func_80092BE8(player));
    mlMtxRotPitch(func_8009BFCC(player));
    mlMtxRotRoll(baroll_get(player));
    mlMtxGet(&rotation);
    func_800F27D4(rotation.m, projection.m, projection.m);
    if (model != originalModel) {
        if (cached) {
            func_800DF41C(func_8008CA74(player));
        } else {
            s32 *cache;
            u8 *originalSkeleton;
            u8 *skeleton;

            cache = func_800DF330();
            originalSkeleton = func_800B27E0(originalModel);
            skeleton = func_800B27E0(model);
            if (*cache) {
                func_800AE708(func_80092E80(player), originalSkeleton, cache, skeleton);
                func_800DF72C(*cache);
            }
        }
    } else {
        func_800DF72C(func_80092E80(player));
    }
    func_800A06E8((BtIntPtr)player);
    func_800DF540(&projection);
    func_800A61D4();
    {
        Gfx **buffers;
        s32 x, y, z;

        buffers = func_800A7180();
        gDPPipeSync((*buffers)++);
        gDPSetColorImage((*buffers)++, G_IM_FMT_CI, G_IM_SIZ_8b, 304, (u32)func_8001575C() + 0x80000000);
        gDPPipelineMode((*buffers)++, G_PM_NPRIMITIVE);
        gDPSetCycleType((*buffers)++, G_CYC_FILL);
        gDPSetFillColor((*buffers)++, 0xFFFEFFFE);
        gDPSetRenderMode((*buffers)++, G_RM_NOOP, G_RM_NOOP2);
        gDPFillRectangle((*buffers)++, 0, 0, 303, 227);
    func_800DE448(arg1, 0, func_80092BDC(player), 0, model);
    if (func_80092738((s32 *)player)) {

        _babackpack_entrypoint_2(player);
        func_800DF540(&projection);
        func_800A61D4();
        func_800DE448(arg1, 0, _babackpack_get_scale(player), 0, _babackpack_entrypoint_1(player));
    }
    {
        Gfx **buffers;
        f32 radius;
        f32 corners[8][3];
        f32 screen[8][2];
        f32 coordinate;
        f32 minimum[2];
        f32 maximum[2];

        buffers = func_800A7180();
        gDPPipeSync((*buffers)++);
        func_800E7CF4(buffers);
        radius = func_800B2354(func_800B2840(model)) * func_80092BDC(player);
        {
        int index;
        f32 limit;
        s32 minimumPixel[2];
        s32 maximumPixel[2];
        s32 stackPadding; /* Preserve IDO's original local-stack layout. */
        s32 visible;

        for (x = 0; x < 2; x++) {
            for (y = 0; y < 2; y++) {
                for (z = 0; z < 2; z++) {
                    index = x * 4 + y * 2 + z;
                    corners[index][0] = (x ? -1.0f : 1.0f) * radius;
                    corners[index][1] = (y ? 0.0f : 1.0f) * radius;
                    corners[index][2] = (z ? -1.0f : 1.0f) * radius;
                }
            }
        }
        for (y = 0; y < 8; y++) {
            func_800F23D0(&projection, corners[y], corners[y]);
            func_800EF04C(corners[y], arg1);
        }
        for (y = 0; y < 8; y++) {
            func_800E4190(corners[y], screen[y], &visible);
            if (!visible) {
                return;
            }
        }
        maximum[0] = screen[0][0];
        minimum[0] = screen[0][0];
        minimum[1] = maximum[1] = screen[0][1];
        for (y = 1; y != 8; y++) {
            coordinate = screen[y][0];
            if (coordinate < minimum[0]) {
                minimum[0] = coordinate;
            } else if (maximum[0] < coordinate) {
                maximum[0] = coordinate;
            }
            coordinate = screen[y][1];
            if (coordinate < minimum[1]) {
                minimum[1] = coordinate;
            } else if (maximum[1] < coordinate) {
                maximum[1] = coordinate;
            }
        }
        limit = 304.0f;
        if (minimum[0] < 0) minimum[0] = 0;
        if (minimum[0] > limit) minimum[0] = limit;
        if (maximum[0] < 0) maximum[0] = 0;
        if (maximum[0] > limit) maximum[0] = limit;
        limit = 228.0f;
        if (minimum[1] < 0) minimum[1] = 0;
        if (minimum[1] > limit) minimum[1] = limit;
        if (maximum[1] < 0) maximum[1] = 0;
        if (maximum[1] > limit) maximum[1] = limit;
        minimumPixel[0] = minimum[0];
        minimumPixel[1] = minimum[1];
        maximumPixel[0] = maximum[0];
        maximumPixel[1] = maximum[1];
        func_800A5EC4(buffers, func_8001575C(), minimumPixel[0], minimumPixel[1], maximumPixel[0] - minimumPixel[0], maximumPixel[1] - minimumPixel[1], arg4);
        }
    }
    }
}

s32 func_800A69F0(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    void func_800A6250(Actor *, f32 *, f32 *, f32 *, s32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800F5680(s32, f32 *);
    f32 mlAbsF(f32);


    f32 sp3C[3];
    f32 sp38;
    f32 sp2C[3];

    func_800EE7F8(arg1, arg0->position);
    sp38 = *(f32 *)&arg0->actorData[3];
    if ((mlAbsF(arg1[1] - sp38) < 0.1f) || (0.99f < arg2[1])) {
        func_800F5680(arg0->unk74_7, sp3C);
        arg1[1] = sp38;
        func_800A6250(arg0, arg1, sp3C, arg2, arg3);
        goto block_6;
    }
    func_800EE7F8(sp2C, arg1);
    func_800EF174(arg1, arg2, -2000.0f);
    if (func_800C6A7C(sp2C, arg1, sp3C, 0x20020) == 0) {
        return 1;
    }
    func_800A6250(arg0, arg1, sp3C, arg2, arg3);
block_6:
    arg0->unk7C_12 = 1;
    return 1;
}

void func_800A6B24(Actor *arg0) {
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800(BtIntPtr, f32 *);
    void func_800C8898(s32, f32 *);
    u8 func_800C89A8(s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    f32 func_800F5BC4(BtIntPtr, f32 *);
    f32 sqrtf(f32);
    s32 light;
    f32 radius;
    f32 spBC[3];
    f32 distance;
    f32 scale;
    f32 fade;
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    s32 alpha;
    s32 count;

    if (!(arg0->position[1] - *(f32 *)&arg0->actorData[3] > 2000.0f)) {
    radius = func_800F5BC4(arg0->unk74_7, spBC);
    func_800EF04C(spBC, arg0->position);
    count = 0;
    for (light = func_800C8760(0, 1); light != 0 && count < 2; light = func_800C878C(light, 0, 1)) {
            alpha = 255;
            if (!(func_800C89A8(light) & 8)) {
                func_800C8800(light, sp98);
                func_800C8898(light, sp8C);
                func_800EFB24(spA4, sp98, spBC);
                distance = sqrtf(spA4[0] * spA4[0] + spA4[1] * spA4[1] + spA4[2] * spA4[2]);
                if (distance == 0.0f) {
                    continue;
                }
                if (sp8C[1] + radius <= distance) {
                    continue;
                }
                {
                    scale = -1.0f / distance;
                    distance -= radius;
                    spA4[0] = -(spA4[0] * scale);
                    spA4[2] = -(spA4[2] * scale);
                    spA4[1] *= -scale;
                    if (sp8C[0] < distance) {
                        fade = 1.0f - (distance - sp8C[0]) * sp8C[2];
                        alpha = (s32)(255.0f * fade);
                    }
                    func_800A69F0(arg0, sp98, spA4, alpha);
                    count++;
                }
            }

    }
    if (count == 0) {
        f32 sp78[3];
        f32 sp6C[3];
        func_800EFD24(sp78);
        func_800EFA4C(sp6C, 0, 1.0f, 0);
        func_800A69F0(arg0, sp78, sp6C, 255);
    }
    }
}

void func_800A6DAC(Actor *arg0, s32 arg1) {
    s32 _plsu_entrypoint_1(s32);
    s32 func_800F5410(BtIntPtr);
    s32 func_800F55FC(BtIntPtr);
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F5628(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F65D0(BtIntPtr);
    int func_800F6640(s32);
    s32 func_800F6E80(s32);
    s32 func_800F8B88(void);

    if (func_800F6438(arg0->unk74_7) &&
        func_800F6640(arg0->unk74_7) &&
        func_800F6E80(arg0->unk74_7) &&
        !(func_800F55FC(arg0->unk74_7) & 0x80000000) &&
        (func_800F65D0(arg0->unk74_7) ||
         (arg0->unk74_30 &&
          (func_800F8B88() < 2 ||
           (func_800F5410(arg0->unk74_7) == 0xB &&
            _plsu_entrypoint_1(0x11) != -1))))) {
        func_800F5A00(arg0->unk74_7, arg0->position);
        *(BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) *)&arg0->actorData[3] = func_800F5628(arg0->unk74_7);
        if (arg0->unk64_20) {
            func_800A5DB0(arg0);
            return;
        }
        func_800A6B24(arg0);
    }
}

void func_800A6EF4(Actor *arg0) {
    s32 func_800A946C(void);
    s32 func_800A9C98(void);
    u32 func_800A9CD0(void);
    u32 func_800BCC84(void);
    s32 func_800D3948(void);
    s32 func_800EA05C();
    void func_8010A800(Actor *, s32);
    extern s16 D_8011A2E0[];
    s32 i;
    s32 sp20;

    sp20 = func_800EA05C();
    func_8010A800(arg0, 5);
    arg0->unk74_29 = 0;
    arg0->unk58 = 1.0f;
    for (i = 0; D_8011A2E0[i] != -1; i++) {
        if (sp20 == D_8011A2E0[i]) {
            arg0->unk74_29 = 1;
            break;
        }
    }
    if (((func_800A9C98() != 0) && (func_800A9CD0() != 2)) || (func_800BCC84() != 0) || (func_800D3948() != 0) || (func_800A946C() >= 2)) {
        arg0->unk74_29 = 1;
    }
}

/* extern */

void func_800A6FF0(Actor *arg0) {
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F5628(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F8874(s32);
    func_800F5A00(arg0->unk74_7, arg0->position);
    *(BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) *)&arg0->actorData[3] = func_800F5628(arg0->unk74_7);
    arg0->unk64_20 = arg0->unk74_29;
    arg0->unk74_30 = func_800F8874(arg0->unk74_7);
}    typedef struct { u8 pad0[0x76]; u16 unk76; } Obj1E7F6A0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800A7088(void *arg0) {
    s32 func_800F7364(u32);
    func_800F7364((u32) (((Obj1E7F6A0_arg0 *)arg0)->unk76) >> 7);
}

void func_800A70B0(BT_NATIVE_ONLY(Unk80132ED0 *bt_a0))
{
    func_800FFA88(BT_NATIVE_ONLY(bt_a0));
}

void func_800A70D0(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    struct Fields {
        u8 pad[0x76];
        BT_BITFIELD_ORDER(u16 value : 9, u16 low : 7);
        BT_BITFIELD_ORDER(u16 low : 7, u16 value : 9);
    };
    struct Fields *actor;

    actor = (struct Fields *)func_80106790(arg0);
    actor->value = arg1;
}

void func_800A7108(Unk80132ED0 *arg0, f32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    func_80106790(arg0)->unk58 = arg1;
}

void func_800A7130(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    struct Fields { u8 pad[0x65]; BT_BITFIELD_ORDER(u8 other : 7, u8 bit : 1); BT_BITFIELD_ORDER(u8 bit : 1, u8 other : 7); } *actor;
    actor = (struct Fields *)func_80106790(arg0);
    actor->bit = arg1;
}

void * func_800A7168(void) {
    extern u8 D_8011A3A0;
    return &D_8011A3A0;
}
