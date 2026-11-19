#include "common.h"
typedef struct {
    u8 r, g, b, a;
    f32 size;
    f32 position;
    u8 type;
    u8 pad[3];
} Flare;
typedef struct {
    s32 map;
    Flare *flares;
} FlareSet;

s32 chlensflare_entrypoint_0(void) {
    s32 _gcskyDll_entrypoint_3();
    s32 func_800EA05C();
    extern FlareSet D_808008F0_chlensflare[7];
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = func_800EA05C();
    if (_gcskyDll_entrypoint_3() == 0) {
        return 0;
    }
    for (; -1 != D_808008F0_chlensflare[sp1C].map; sp1C++) {
        if (sp18 == D_808008F0_chlensflare[sp1C].map) {
            return 1;
        }
    }
    return 0;
}

void func_80800084_chlensflare(Actor *arg0) {
    typedef struct {
        s32 pad0[3];
        s32 index;
        s32 pad10[3];
        f32 intensity;
    } LensFlareActorData;
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    extern FlareSet D_808008F0_chlensflare[7];
    FlareSet *var_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a1;
    s32 sentinel;

    temp_v0 = func_800EA05C();
    var_v1 = D_808008F0_chlensflare;
    var_a1 = 0;
    sentinel = -1;
loop_1:
    temp_a0 = var_v1->map;
    var_v1++;
    if (sentinel != temp_a0) {
        goto compare;
    }
    func_800FFAB0(arg0);
    return;
compare:
    if (temp_v0 == temp_a0) {
        ((LensFlareActorData *)arg0->actorData)->index = var_a1;
        goto found;
    }
    var_a1 += 1;
    goto loop_1;
found:
    ((LensFlareActorData *)arg0->actorData)->intensity = 1.01f;
}    typedef struct { u8 pad0[0x24]; s32 unk24; u8 pad28[0xC]; f32 unk34; u8 pad38[0x18]; u8 unk50; } Objlensflare_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808000FC_chlensflare(void *arg0, BtIntPtr arg1) {
    typedef struct {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 unused : 11, u32 rest : 20);
        u32 forced : 1;
        BT_BITFIELD_ORDER(u32 rest : 20, u32 unused : 11);
    } FlareActor;
    extern FlareSet D_808008F0_chlensflare[7];
    s32 func_800BFFB4(s32, s32, f32 *);
    BT_IDO_ONLY(void func_800E8830(s32, f32 *);) BT_NATIVE_ONLY(void func_800E8830(u8, f32 *);)
    BT_IDO_ONLY(s32 func_800E88AC(s32, f32 *);) BT_NATIVE_ONLY(s32 func_800E88AC(u8, f32 *);)
    f32 mlAbsF(f32);
    void func_800E40DC(f32, f32, f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    BT_IDO_ONLY(void func_800EFA88(void *, u8, u8, u8);) BT_NATIVE_ONLY(void func_800EFA88(void *, s32, s32, s32);)
    void func_800B99CC(BtIntPtr, s32, f32 *);
    void func_800E24F8(s32, s32, s32);
    void func_800E2530(f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    f32 func_800EEFD4(f32 *);
    void func_800EFA98(f32 *, f32 *, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    BT_IDO_ONLY(void func_800E2720(BtIntPtr, s32, s32, f32 *, f32 *, s32);) BT_NATIVE_ONLY(s32 func_800E2720(u8 *, s32, s32, f32 *, f32 *, s32);)
    void func_800E2A14(BtIntPtr);
    f32 source[3];
    f32 scale[3];
    f32 delta[3];
    f32 screen[2];
    f32 fade;
    s32 i;
    s32 alpha;
    s32 previous;
    f32 color[3];
    f32 point[3];
    f32 size;
    f32 offset[3];
    f32 camera[3];
    Flare *flares;

    if (func_800BFFB4(0, 4, source)) {
        func_800E8830(((Objlensflare_arg0 *)arg0)->unk50, source);
        if (func_800E88AC(((Objlensflare_arg0 *)arg0)->unk50, screen) == 1 ||
            ((FlareActor *)arg0)->forced) {
            fade = (mlAbsF(screen[0] - 152.0f) * mlAbsF(screen[0] - 152.0f) +
                    mlAbsF(screen[1] - 114.0f) * mlAbsF(screen[1] - 114.0f)) / 19602.0f;
            if (((Objlensflare_arg0 *)arg0)->unk34 < fade) {
                ((Objlensflare_arg0 *)arg0)->unk34 *= 1.35f;
                if (((Objlensflare_arg0 *)arg0)->unk34 > fade) {
                    ((Objlensflare_arg0 *)arg0)->unk34 = fade;
                } else {
                    fade = ((Objlensflare_arg0 *)arg0)->unk34;
                }
            } else {
                ((Objlensflare_arg0 *)arg0)->unk34 /= 1.35f;
                if (((Objlensflare_arg0 *)arg0)->unk34 < fade) {
                    ((Objlensflare_arg0 *)arg0)->unk34 = fade;
                } else {
                    fade = ((Objlensflare_arg0 *)arg0)->unk34;
                }
            }
        } else {
            if (((Objlensflare_arg0 *)arg0)->unk34 < 1.01f) {
                ((Objlensflare_arg0 *)arg0)->unk34 *= 1.35f;
            }
            if (((Objlensflare_arg0 *)arg0)->unk34 > 1.0f) {
                ((Objlensflare_arg0 *)arg0)->unk34 = 1.01f;
                return;
            }
            fade = ((Objlensflare_arg0 *)arg0)->unk34;
        }
        if (fade > 1.0f) {
            return;
        }
        screen[0] = 304.0f - screen[0];
        screen[1] = 228.0f - screen[1];
        func_800E40DC(screen[0], screen[1], scale, delta);
        func_800EFB24(delta, scale, source);
        flares = D_808008F0_chlensflare[((Objlensflare_arg0 *)arg0)->unk24].flares;
        for (i = 0; flares[i].type; i++) {}
        if (flares[i].r) {
            func_800EFA88(color, flares[i].r, flares[i].g, flares[i].b);
            func_800B99CC(arg1, (s32)(flares[i].a * (1.0f - fade)), color);
        }
        previous = 0;
        func_800E2588(0);
        func_800E24F8(flares[0].r, flares[0].g, flares[0].b);
        func_800E2594(arg1, func_800D674C(0x9D2));
        for (i = 0; flares[i].type; i++) {
            alpha = flares[i].a * (1.0f - fade);
            if (alpha == previous) {
                alpha++;
            }
            previous = alpha;
            func_800E24F8(flares[i].r, flares[i].g, flares[i].b);
            size = flares[i].size + fade;
            func_800EFA4C(scale, size, size, size);
            func_800EE7F8(point, source);
            func_800EF174(point, delta, flares[i].position);
            func_800E3980(camera);
            func_800EFB24(offset, point, camera);
            if (func_800EEFD4(offset) > 400000000.0f) {
                func_800EFA98(offset, offset, 20000.0f);
                func_800EE780(point, camera, offset);
            }
            switch (flares[i].type) {
                case 1:
                    func_800E2530(0.0f);
                    func_800E2720(arg1, 0, 0, point, scale, alpha);
                    break;
                case 2:
                    func_800E2530(45.0f);
                    func_800E2720(arg1, 0, 0, point, scale, alpha);
                    break;
                case 3:
                    func_800E2720(arg1, 1, 0, point, scale, alpha);
                    break;
            }
        }
        func_800E2A14(arg1);
        ((FlareActor *)arg0)->forced = 0;
    }
}

/* extern */

s32 func_80800634_chlensflare(void *arg0, s32 arg1, s32 arg2) {
    s8 func_800E8714(s32);
    if (arg1 == 0x95) {
        (*(s8 *)((s8 *)(arg0) + (0x50))) = func_800E8714(0);
        return 1;
    }
    return 0;
}

OSThread *chlensflare_entrypoint_1(void)
{
    extern ActorData D_80800928_chlensflare[];
    return (OSThread *) D_80800928_chlensflare;
}
#include "lensflare_data.inc"
