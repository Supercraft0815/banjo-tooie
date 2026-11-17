#include "common.h"

struct player_state_s;

s32 basnowball_entrypoint_0() 
{
    return 0x30;
}    typedef struct { u8 pad0[0x2D]; u8 unk2D; } Objsnowll_func_80800008_basnowball_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */ typedef struct { u8 pad0[0x110]; void * unk110; } Objsnowll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800008_basnowball(void *arg0, s32 arg1) {
    void baflag_clear(void *, s32);
    void baflag_set(void *, s32);
    void func_800FC660(u32);
    void func_800FC74C(u32);
    void *var_v0;

    var_v0 = (((Objsnowll_arg0 *)arg0)->unk110);
    if ((((Objsnowll_func_80800008_basnowball_var_v0 *)var_v0)->unk2D) == 2) {
        baflag_clear(arg0, 0x3C);
        func_800FC74C(0x1C);
        var_v0 = (((Objsnowll_arg0 *)arg0)->unk110);
    }
    (*(s8 *)((s8 *)(var_v0) + (0x2D))) = (s8) arg1;
    if (arg1 == 2) {
        baflag_set(arg0, 0x3C);
        func_800FC660(0x1C);
    }
}

f32 func_80800084_basnowball(s32 arg0) {
    extern f32 D_80801020_basnowball[];
    return ((f32 *)&D_80801020_basnowball)[arg0];
}

s32 func_80800098_basnowball(BtIntPtr arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    extern f32 D_80801038_basnowball[];
    f32 *temp_v0;

    temp_v0 = (f32 *)((u8 *)D_80801038_basnowball + arg1 * 8);
    *arg2 = temp_v0[0];
    *arg3 = temp_v0[1]; BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_808000C0_basnowball(BtIntPtr arg0) {
    void func_8009590C(struct player_state_s *, f32);
    void func_800959C8(struct player_state_s *, f32, f32);
    s32 func_800A1718();
    s32 func_80800098_basnowball(BtIntPtr, s32, f32 *, f32 *);
    f32 sp24;
    f32 sp20;

    func_80800098_basnowball(arg0, func_800A1718(), &sp24, &sp20);
    func_800959C8(arg0, sp24, sp20);
    func_8009590C(arg0, sp24);
}

void func_80800110_basnowball(BtIntPtr arg0) {
    s32 func_800A1718();
    void func_800A4D6C(u8 *, f32, f32);
    extern s32 D_80801068_basnowball[12];
    u8 *temp_v1;

    temp_v1 = ((u8 *)D_80801068_basnowball) + (func_800A1718() * 8);
    func_800A4D6C((u8 *)arg0, (*(f32 *)(temp_v1 + 0)), (*(f32 *)(temp_v1 + 4)));
}    typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x4]; u8 unk14; } Objsnowll_func_80800150_basnowball_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

/* extern */

void func_80800150_basnowball(BtIntPtr arg0, s32 arg1) {
    f32 func_800F0E00(f32, f32);
    void *var_v0;

    var_v0 = (((Objsnowll_arg0 *)arg0)->unk110);
    if (arg1 != (((Objsnowll_func_80800150_basnowball_var_v0 *)var_v0)->unk14)) {
        if ((arg1 != 1) && (arg1 == 2)) {
            (*(f32 *)((s8 *)((((Objsnowll_arg0 *)arg0)->unk110)) + (0x10))) = func_800F0E00((((Objsnowll_func_80800150_basnowball_var_v0 *)var_v0)->unkC), 300.0f);
            var_v0 = (((Objsnowll_arg0 *)arg0)->unk110);
        }
        (*(s8 *)((s8 *)(var_v0) + (0x14))) = (s8) arg1;
    }
}

void func_808001B8_basnowball(void *arg0, s32 arg1) {
    void _bawobble_entrypoint_1(void *);
    void _bawobble_entrypoint_4(void *, f32, f32);
    void _bawobble_entrypoint_5(void *, f32, f32);
    void _bawobble_entrypoint_6(void *);
    void _bawobble_entrypoint_7(void *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_800A1718();
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 pitch;
    u8 *data;

    data = *(u8 **)((u8 *)arg0 + 0x110);
    switch (data[0x28]) {
        case 0:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x24) = func_80800084_basnowball(func_800A1718(arg0));
            data = *(u8 **)((u8 *)arg0 + 0x110);
            break;
        case 2:
            _bawobble_entrypoint_7(arg0);
            func_8009E55C(arg0, 0, *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x1C) * 50.0f);
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110)) = 0.0f;
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 4) = 7.5f;
            data = *(u8 **)((u8 *)arg0 + 0x110);
            break;
    }
    data[0x28] = arg1;
    switch (arg1) {
        case 1:
            data = *(u8 **)((u8 *)arg0 + 0x110);
            *(f32 *)(data + 0x1C) = *(f32 *)(data + 0x24);
            break;
        case 2:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x18) = 1.0f;
            data = *(u8 **)((u8 *)arg0 + 0x110);
            *(f32 *)(data + 0x20) = *(f32 *)(data + 0x1C);
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x24) = func_80800084_basnowball(func_800A1718(arg0));
            _bawobble_entrypoint_1(arg0);
            _bawobble_entrypoint_4(arg0, 0.2f, 0.2f);
            pitch = func_800F10B4(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x24), 1.0, 3.0, 0.0, -0.5) + 1.2f;
            data = *(u8 **)((u8 *)arg0 + 0x110);
            if (*(f32 *)(data + 0x20) < *(f32 *)(data + 0x24)) {
                _bawobble_entrypoint_5(arg0, 1.0f + 0.0f, 1.2);
                func_8009DB04(arg0, 0x65A, pitch, 0x36B0);
            } else {
                _bawobble_entrypoint_5(arg0, 1.0f + 0.0f, 0.8f);
                func_8009DB04(arg0, 0x65B, pitch, 0x36B0);
            }
            _bawobble_entrypoint_6(arg0);
            func_808000C0_basnowball((BtIntPtr)arg0);
            func_80800110_basnowball((BtIntPtr)arg0);
            break;
    }
}

/* extern */

void basnowball_entrypoint_1(void *arg0) {
    void _bawobble_entrypoint_2(void *self);
    void baflag_clear(void *, s32);
    void func_80093230(struct player_state_s *, f32);
    void func_8009590C(struct player_state_s *, f32);
    void func_80095A40(struct player_state_s *);
    void func_8009E474(struct player_state_s *);
    void func_800A4D6C(u8 *, f32, f32);
    func_80800008_basnowball(arg0, 0);
    func_8009E474(arg0);
    baflag_clear(arg0, 0x3C);
    func_80093230(arg0, 1.0f);
    func_80095A40(arg0);
    func_8009590C(arg0, 0.0f);
    _bawobble_entrypoint_2(arg0);
    func_800A4D6C(arg0, 1.0f, 1.0f);
}

void basnowball_entrypoint_2(void *arg0) {
    s32 _bawobble_entrypoint_3();
    void func_80093230(struct player_state_s *, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E55C(struct player_state_s *, s32, f32);

    _bawobble_entrypoint_3();
    *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0) = 0.0f;
    *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 4) = 7.5f;
    *(s8 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x2D) = 0;
    *(s8 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x2C) = 0;
    func_80800008_basnowball(arg0, 1);
    *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0xC) = 0.0f;
    *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 8) = 0.0f;
    *(s8 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x14) = 0;
    func_80800150_basnowball((BtIntPtr)arg0, 2);
    *(s8 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x28) = 0;
    func_808001B8_basnowball(arg0, 1);
    func_80093230(arg0, *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x1C));
    func_8009E4AC(arg0);
    func_8009E55C(arg0, 0, *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x1C) * 50.0f);
    func_8009E55C(arg0, 1, 0.0f);
    func_808000C0_basnowball((BtIntPtr)arg0);
    func_80800110_basnowball((BtIntPtr)arg0);
}

f32 basnowball_entrypoint_3(void *arg0) {
    return *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 8);
}

f32 basnowball_entrypoint_4(void *arg0) {
    return *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 28);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) basnowball_entrypoint_5(BT_PARAM_OR_VOID(BT_NATIVE_ONLY(s32 bt_a0))) {
    s32 func_800A1718();
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    BT_NATIVE_ONLY(return) func_800F10B4((f32) func_800A1718(BT_NATIVE_ONLY(bt_a0)), 1.0f, 5.0f, 0.0f, 1.0f);
}

/* extern */

s32 basnowball_entrypoint_6(BT_PARAM_OR_VOID(BT_NATIVE_ONLY(s32 bt_a0))) {
    s32 func_800A1718();
    return func_800A1718(BT_NATIVE_ONLY(bt_a0)) >= 5;
}

void basnowball_entrypoint_7(void *arg0) {
    (*(s8 *)((s8 *)((((Objsnowll_arg0 *)arg0)->unk110)) + (0x2C))) = 1;
}

/* extern */

void basnowball_entrypoint_8(BtIntPtr arg0, s32 arg1) {
    void func_80800150_basnowball(BtIntPtr, s32);
    if (arg1 != 0) {
        func_80800150_basnowball(arg0, 2);
        return;
    }
    func_80800150_basnowball(arg0, 1);
}

void basnowball_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 12) = arg1;
}

typedef struct
{
  f32 x;
  f32 z;
  f32 rotation;
} SnowballParticle;

void basnowball_entrypoint_10(void *arg0)
{
  void func_8009C128(struct player_state_s *, f32 [3]);
  BtIntPtr func_800B5BE4(s32);
  void func_800BA22C(BtIntPtr, s32);
  void func_800BA75C(BtIntPtr, f32 [3]);
  void func_800BA77C(BtIntPtr, s16, s16, s16);
  void func_800BA7C4(void *, f32, f32);
  void func_800BA7FC(void *, f32, f32);
  void func_800BA8F8(void *, f32, f32);
  BtIntPtr func_800BABB8(BtIntPtr, f32 [3], f32 [3], f32, s32 []);
  void func_800EE7F8(f32 *, f32 *);
  extern s32 D_80801098_basnowball[];
  extern SnowballParticle D_808010C0_basnowball[];
  extern SnowballParticle D_808010F0_basnowball[];
  f32 startScale;
  f32 endScale;
  f32 lifetime;
  f32 scale;
  f32 position[3];
  f32 offset[3];
  s32 i;
  BtIntPtr emitter;
  BtIntPtr particle;
  emitter = func_800B5BE4(7);
  scale = *((f32 *) (((u8 *) (((Objsnowll_arg0 *)arg0)->unk110)) + 0x1C));
  func_8009C128(arg0, position);
  position[1] += 50.0f * scale;
  particle = func_800BABB8(emitter, position, 0, 1.0f, D_80801098_basnowball);
  startScale = 0.5f * scale;
  func_800BA7C4((void *) particle, startScale, startScale);
  endScale = 1.1f * scale;
  func_800BA7FC((void *) particle, endScale, endScale);
  lifetime = (0.175f * scale) + 0.6f;
  func_800BA8F8((void *) particle, lifetime, lifetime);
  i = 0;
  do
  {
    func_800EE7F8(offset, position);
    offset[0] += D_808010C0_basnowball[i].x * scale;
    offset[2] += D_808010C0_basnowball[i].z * scale;
    func_800BA75C(particle, offset);
    func_800BA77C(particle, 0, 0, (s16) ((s32) D_808010C0_basnowball[i].rotation));
    func_800BA22C(particle, 1);
    i++;
  }
  while (D_808010F0_basnowball != &D_808010C0_basnowball[i]);
}

void func_808007CC_basnowball(struct player_state_s *arg0) {
    f32 func_800136E4(f32);
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 func_800A1718(void *);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA7C4(void *, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 yaw_get(struct player_state_s *);
    extern SnowballParticle D_808010F0_basnowball[];
    f32 temp_f24;
    f32 spA0;
    f32 temp_f20;
    f32 sp98;
    f32 temp_f0;
    f32 sp88[3];
    f32 sp7C[3];
    BtIntPtr temp_s3;
    s32 var_s0;

    temp_s3 = func_800B5BE4(9);
    func_8009C128(arg0, sp7C);
    sp98 = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x110) + 0x1C) * 58.0f;
    sp7C[1] += sp98;
    temp_f0 = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x110) + 0x1C) * 0.15f + 0.3f;
    func_800BA7C4((void *)temp_s3, temp_f0, temp_f0);
    spA0 = yaw_get(arg0) + 90;
    temp_f24 = func_800A1718(arg0) + 1;
    for (var_s0 = 0; var_s0 < temp_f24; var_s0++) {
        func_800EE7F8(sp88, sp7C);
        temp_f20 = func_800DC178(0, 90.0f);
        func_800EF214(sp88, temp_f20, func_800136E4(func_800DC178(0, 180.0f) + spA0), sp98);
        func_800BABB8(temp_s3, sp88, 0, 1.0f, (s32 *)D_808010F0_basnowball);
    }
}

void func_808007CC_basnowball();

void func_8080099C_basnowball(void *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA730(void *, s16, s16, s16, s16);
    void func_800BA77C(BtIntPtr, s16, s16, s16);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    extern s32 D_8080110C_basnowball[13];
    f32 temp_f2;
    BtIntPtr temp_s0;
    f32 sp4C;
    f32 sp48;
    f32 sp3C[3];

    temp_s0 = func_800B5BE4(7);
    func_8009C128(arg0, sp3C);
    temp_f2 = (*(f32 *)((s8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x1C) * 30.0f) + 5.0f;
    sp48 = (*(f32 *)((s8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x1C) * 100.0f) + 200.0f;
    sp4C = (*(f32 *)((s8 *)*&((Objsnowll_arg0 *)arg0)->unk110 + 0x1C) * 0.5f) + 0.6f;
    func_800BA730((void *)temp_s0, (s16) (s32) temp_f2, (s16) (s32) (temp_f2 + 10.0f), 0x41, 0x3C);
    func_800BA930(temp_s0, -0xA, (s16) (s32) sp48, -0xA, 0xA, (s32) (sp48 + 50.0f), 0xA);
    func_800BA7FC((void *)temp_s0, sp4C, sp4C);
    func_800BA77C(temp_s0, 0, 0, (s16) (s32) func_800DC178(0.0f, 359.0f));
    func_800BABB8(temp_s0, sp3C, 0, 1.0f, D_8080110C_basnowball);
}

void basnowball_entrypoint_11(s32 arg0)
{
    func_800F796C(arg0,0x3);
}

void basnowball_entrypoint_12(void *arg0) {
    typedef struct {
        f32 distance;
        f32 timer;
        f32 angle;
        f32 speed;
        f32 turnSpeed;
        u8 turnState;
        u8 pad15[3];
        f32 transitionTimer;
        f32 scale;
        f32 targetScale;
        f32 startScale;
        u8 state;
        u8 pad29[3];
        u8 active;
        u8 mode;
    } Snowball;
    typedef struct {
        u8 pad0[0x110];
        Snowball *snow;
        u8 pad114[0x70];
        s32 id;
    } SnowPlayer;
    f32 func_800D8FF8(void);
    s32 func_800EA068(s32);
    s32 func_8008DE50();
    s32 func_800A1760(void *);
    void func_8009919C(void *, BtIntPtr, s32);
    s32 func_800A1718(void *);
    s32 func_800A17A8(BtIntPtr, s32);
    s32 func_800958A4(void *, s32, s32);
    void func_80096394(void *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800FC660(u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8009E55C(struct player_state_s *, s32, f32);
    f32 func_800136E4(f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F0E00(f32, f32);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_80093230(struct player_state_s *, f32);
    extern void _basnowball_entrypoint_11(s32);
    f32 dt;
    void *model;
    f32 position[4];
    f32 scale;
    s32 size;
    s32 width;
    s32 height;
    s32 change;
    f32 oldAngle;
    s32 pad[2];

    dt = func_800D8FF8();
    if (func_800EA068(1) && !func_8009E674(arg0, 0x10)) {
        size = func_800A1718(arg0);
        if (size > 0 && ((SnowPlayer *)arg0)->snow->state == 1) {
            ((SnowPlayer *)arg0)->snow->timer -= dt;
            if (((SnowPlayer *)arg0)->snow->timer < 0.0f) {
                if (size == 1) {
                    func_8009919C(arg0, (BtIntPtr)_basnowball_entrypoint_11, ((SnowPlayer *)arg0)->id);
                } else {
                    ((SnowPlayer *)arg0)->snow->timer = 7.5f;
                    func_800A17A8((BtIntPtr)arg0, -1);
                }
            }
        }
    } else if (func_8008DE50(arg0) && player_isStable(arg0) && ((SnowPlayer *)arg0)->snow->speed > 100.0f) {
        func_8080099C_basnowball(arg0);
        if (func_800A1718(arg0) < func_800A1760(arg0) && ((SnowPlayer *)arg0)->snow->state == 1) {
            func_80096394(arg0, position);
            ((SnowPlayer *)arg0)->snow->distance += func_800EEF94(position);
            if (((SnowPlayer *)arg0)->snow->distance > 1000.0f) {
                ((SnowPlayer *)arg0)->snow->distance = 0.0f;
                func_800A17A8((BtIntPtr)arg0, 1);
                func_800FC660(8);
            }
        }
    }
    switch (((SnowPlayer *)arg0)->snow->state) {
    case 1:
        size = func_800A1718(arg0);
        scale = func_80800084_basnowball(size);
        if (scale != ((SnowPlayer *)arg0)->snow->scale) {
            func_80800098_basnowball((BtIntPtr)arg0, size, &width, &height);
            change = 0;
            if (scale < ((SnowPlayer *)arg0)->snow->scale) {
                change = 1;
            } else if (!func_800958A4(arg0, width, height)) {
                change = 1;
            }
            if (change) {
                func_808001B8_basnowball(arg0, 2);
            }
        }
        break;
    case 2:
        ((SnowPlayer *)arg0)->snow->scale = func_800F10B4(((SnowPlayer *)arg0)->snow->transitionTimer, 0.0f, 1.0f, ((SnowPlayer *)arg0)->snow->startScale, ((SnowPlayer *)arg0)->snow->targetScale);
        func_8009E55C(arg0, 0, ((SnowPlayer *)arg0)->snow->scale * 50.0f);
        if (func_800D9078(&((SnowPlayer *)arg0)->snow->transitionTimer)) {
            func_808001B8_basnowball(arg0, 1);
        }
        break;
    }
    switch (((SnowPlayer *)arg0)->snow->turnState) {
    case 1:
        ((SnowPlayer *)arg0)->snow->angle = func_800136E4(((SnowPlayer *)arg0)->snow->angle + (((SnowPlayer *)arg0)->snow->speed / ((SnowPlayer *)arg0)->snow->scale) * dt);
        break;
    case 2:
        oldAngle = ((SnowPlayer *)arg0)->snow->angle;
        if (((SnowPlayer *)arg0)->snow->angle != 0.0f) {
            scale = func_800F0E00(func_800F13F0(((SnowPlayer *)arg0)->snow->turnSpeed / ((SnowPlayer *)arg0)->snow->scale, (360.0f - oldAngle) * 7.0f) * dt, 1.5f);
            ((SnowPlayer *)arg0)->snow->angle = func_800136E4(((SnowPlayer *)arg0)->snow->angle + scale);
            if (((SnowPlayer *)arg0)->snow->angle < oldAngle) {
                ((SnowPlayer *)arg0)->snow->angle = 0.0f;
            }
        }
        break;
    }
    model = func_80092AD8(arg0);
    func_800E0AF0(model, 1.0f);
    func_800E0AFC(model, 0x43, 1.0f, ((SnowPlayer *)arg0)->snow->angle, 0.0f, 0.0f);
    func_80093230(arg0, ((SnowPlayer *)arg0)->snow->scale);
    _bawobble_entrypoint_8(arg0);
    if (((SnowPlayer *)arg0)->snow->mode == 2) {
        if (!((SnowPlayer *)arg0)->snow->active) {
            func_80800008_basnowball(arg0, 1);
        } else {
            func_808007CC_basnowball(arg0);
            ((SnowPlayer *)arg0)->snow->active = 0;
        }
    } else if (((SnowPlayer *)arg0)->snow->active) {
        func_80800008_basnowball(arg0, 2);
        ((SnowPlayer *)arg0)->snow->active = 0;
    }
}
/* data_to_c.py: from asm/data/overlays/ba/snowll.data.s */
f32 D_80801020_basnowball [6] BT_DATA(4, overlays_ba_snowll, 0x0) = { 1.0f, 1.0f, 1.5f, 2.0f, 2.5f, 3.0f };
f32 D_80801038_basnowball [12] BT_DATA(4, overlays_ba_snowll, 0x18) = { 83.0f, 46.0f, 83.0f, 46.0f, 114.0f, 66.0f, 150.0f, 88.0f, 190.0f, 105.0f, 230.0f, 125.0f };
s32 D_80801068_basnowball[12] BT_DATA(4, overlays_ba_snowll, 0x48) = { 1065353216, 1065353216, 1065353216, 1065353216, 1067030938, 1065772646, 1068708659, 1066192077, 1070386381, 1066611507, 1072064102, 1067030938 };
s32 D_80801098_basnowball [10] BT_DATA(4, overlays_ba_snowll, 0x78) = { 3407901, 164167712, -421068801, 2949080, 3342296, 2621540, 2621461, 1310822, 1445888, 0 };
SnowballParticle D_808010C0_basnowball [4] BT_DATA(4, overlays_ba_snowll, 0xA0) = { { -44.0f, 0.0f, 0.0f }, { 44.0f, 0.0f, 90.0f }, { 0.0f, -44.0f, 180.0f }, { 0.0f, 44.0f, 270.0f } };
SnowballParticle D_808010F0_basnowball [2] BT_DATA(4, overlays_ba_snowll, 0xD0) = { { 2.666779e-39f, 1.92858e-39f, 6.97955e-39f }, { 6.42858e-40f, 3.948998e-39f, 4.684005e-39f } };
u8 D_808010F0_basnowball__gap[4] BT_DATA(4, overlays_ba_snowll, 0xE8) = { 0 };
s32 D_8080110C_basnowball[13] BT_DATA(4, overlays_ba_snowll, 0xEC) = { 1903049, 2156262, -65515, 1638476, 1833808, -78643164, 4980838, 2818137, 6357274, 0, 0, 0, 0 };
