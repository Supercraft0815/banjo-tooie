#include "core2/1EE9AB0.h"

void func_801101C0(void) {
    extern s16 (*D_80124950)(void);
    extern s16 D_80137340[25];
    extern s16 D_80137372;
    s16 (**var_s1)(void);
    s16 *var_s0;
    s16 temp_v1;
    s32 var_a0;
    s32 var_v0;
    BtUIntPtr end;

    D_80137372 = 0x98;
    var_s0 = D_80137340; var_s1 = &D_80124950; end = (BtUIntPtr)&D_80137340[25];
    do {
        *var_s0 = (*var_s1)();
        temp_v1 = *var_s0;
        var_a0 = temp_v1 % 4;
        if (var_a0 != 0) {
            var_v0 = 4 - var_a0;
        } else {
            var_v0 = 0;
        }
        var_s0++;
        var_s1++;
        D_80137372 = D_80137372 + temp_v1 + var_v0;
    } while ((BtUIntPtr)var_s0 != end);
}

int func_80110280(s32 *arg0) {
    extern s16 D_80137340[25];
    s32 offset;
    s32 i;
    s32 size;

    offset = 0x98;
    for (i = 0; i < 25; i++) {
        *(s32 *)((s8 *)arg0 + (i << 2)) = (BtIntPtr)((s8 *)arg0 + offset);
        size = D_80137340[i];
        offset += size + (size % 4 ? 4 - (size % 4) : 0);
    }
BT_NATIVE_ONLY(return 0;) }    typedef struct { u8 pad0[0x74]; f32 unk74; u8 pad78[0x8]; f32 unk80; u8 pad84[0x8]; f32 unk8C; } Obj1EE9AB0_func_80110424_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

void *func_80110424(s32 *arg0, s32 arg1) {
    void *heap_alloc(s32);
    void bzero(void *, int);
    int func_80110280(s32 *);
    void func_80110720(s8 *, s32);
    void func_8010FFB0(s32 *, f32 *, f32 *);
    void _ncba1p_entrypoint_1(u8 **arg0);
    void func_80112398(u8 *);
    void _ncbaspline_entrypoint_1(void *arg0);
    void func_8011337C(PlayerState *);
    void func_80111348(s32 *);
    void func_80115FB0(u8 *);
    void func_801125B8(void *);
    void func_80110C88(BtIntPtr);
    void func_800EFD24(f32 *);
    extern s16 D_80137372;
    s32 size;
    s32 *self;

    size = D_80137372;
    self = heap_alloc(size);
    bzero(self, size);
    func_80110280(self);
    ((s32 **)self)[25] = arg0;
    self[26] = arg1;
    func_80110720((s8 *)self, 1);
    func_8010FFB0(((s32 **)self)[25], &((Obj1EE9AB0_func_80110424_self *)self)->unk74, &((Obj1EE9AB0_func_80110424_self *)self)->unk80);
    _ncba1p_entrypoint_1((BtIntPtr)self);
    func_80112398((u8 *)self);
    _ncbaspline_entrypoint_1((BtIntPtr)self);
    func_8011337C((PlayerState *)self);
    func_80111348(self);
    func_80115FB0((u8 *)self);
    func_801125B8(self);
    func_80110C88((BtIntPtr)self);
    self[27] = 0;
    ((u8 *)self)[0x72] = 0;
    ((u8 *)self)[0x71] = 0;
    func_800EFD24(&((Obj1EE9AB0_func_80110424_self *)self)->unk8C);
    return self;
}

void func_801104F4(PlayerState *arg0) {
    s32 func_801106A8(PlayerState *, s32);
    s32 func_80113410();
    void heap_free(void* mem);
    func_801106A8(arg0, 0);
    func_80113410(arg0);
    heap_free(arg0);
}

void func_80110528(PlayerState *arg0) { s32 func_801138A0(void *); s32 func_801138F4(PlayerState *arg0); void func_80112524(PlayerState *, f32 *); void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr); void func_80110790(BtIntPtr, f32 *); f32 sp2C[3]; f32 sp20[3]; if (func_801138A0(arg0) != 0) { func_801138F4(arg0); } func_80112524(arg0, sp2C); func_80110A68((BtIntPtr) arg0, (BtIntPtr) sp20, (BtIntPtr) sp2C); func_80110790((BtIntPtr) arg0, sp20); }

#ifdef BT_NATIVE
// Free camera setting (host camera_stick: x | y << 8, signed bytes, -80..80). Yaw turns the game's
// own camera around its focus at once, with the C-button turn's wall check, so movement follows the
// picture. Pitch only tilts the picture around the focus. Camera modes without C-button turns: off.
static f32 bt_pitch;
static s32 bt_free_camera_allowed(void *camera) {
    extern s16 D_801247A0[];
    return D_801247A0[*(s32 *)((u8 *)camera + 0x6C) * 8 + 6] != 0;
}

static void bt_free_camera_yaw(PlayerState *camera) {
    s32 bt_camera_stick(void);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    int func_800F1EA4(f32 *, f32 *);
    void func_80110770(void *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80112524(PlayerState *, f32 *);
    void func_80112D90(PlayerState *, f32, f32, s32, s32);
    s32 func_8011349C(f32 *, f32 *);
    extern f32 D_80126540;
    f32 focus[3], position[3], offset[3], turned[3], rotation[3], yaw, degrees, *spring;
    s32 x = (s8)bt_camera_stick();

    if (!bt_free_camera_allowed(camera)) {
        bt_pitch = 0.0f;
        return;
    }
    if (x == 0) return;
    degrees = x * (150.0f / 80.0f) * func_800D8FF8();
    func_80112524(camera, focus);
    func_801107F0(camera, position);
    func_800EFB24(offset, position, focus);
    func_800F1EA4(offset, &yaw);
    func_800EF934(turned, offset, degrees * D_80126540);
    func_800EF04C(turned, focus);
    if (!func_8011349C(position, turned)) return;
    func_80110770(camera, turned);
    func_800A516C(rotation, focus, turned);
    func_80110790((BtIntPtr)camera, rotation);
    func_80112D90(camera, func_800136E4(yaw + degrees), 45.0f, 1, 2);
    spring = (f32 *)(*(u8 **)((u8 *)camera + 0x60) + 0x10);  // target, current, velocity
    spring[1] = spring[0];
    spring[2] = 0.0f;
}

static void bt_free_camera_pitch(PlayerState *camera, f32 *position, f32 *rotation) {
    s32 bt_camera_stick(void);
    f32 func_800D8FF8(void);
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_80112524(PlayerState *, f32 *);
    s32 func_8011349C(f32 *, f32 *);
    f32 sqrtf(f32);
    f32 atan2f(f32, f32);
    f32 sinf(f32);
    f32 cosf(f32);
    f32 focus[3], tilted[3], dx, dy, dz, flat, distance, base, lo, hi, free, step;
    s32 y = (s8)(bt_camera_stick() >> 8), i;

    if (!bt_free_camera_allowed(camera)) return;
    bt_pitch -= y * (100.0f / 80.0f) * func_800D8FF8();  // stick up lowers the camera: look up
    if (bt_pitch == 0.0f) return;
    func_80112524(camera, focus);
    dx = position[0] - focus[0];
    dy = position[1] - focus[1];
    dz = position[2] - focus[2];
    flat = sqrtf(dx * dx + dz * dz);
    if (flat < 1.0f) return;
    distance = sqrtf(flat * flat + dy * dy);
    base = atan2f(dy, flat) * (180.0f / 3.14159265f);
    // Clamp the offset itself to elevation -20..80 degrees, so reversing reacts at once (0 always allowed).
    lo = -20.0f - base < 0.0f ? -20.0f - base : 0.0f;
    hi = 80.0f - base > 0.0f ? 80.0f - base : 0.0f;
    bt_pitch = bt_pitch < lo ? lo : bt_pitch > hi ? hi : bt_pitch;
    // Floor or wall between focus and camera: bisect to the largest free offset (0 = game view) and stay there.
    free = 0.0f;
    step = bt_pitch;
    for (i = 0; i < 7; i++) {
        f32 elevation = (free + step) * (3.14159265f / 180.0f) + base * (3.14159265f / 180.0f);
        tilted[0] = focus[0] + dx * (cosf(elevation) * distance / flat);
        tilted[1] = focus[1] + sinf(elevation) * distance;
        tilted[2] = focus[2] + dz * (cosf(elevation) * distance / flat);
        if (func_8011349C(focus, tilted)) {
            free += step;
            if (i == 0) break;
        }
        step *= 0.5f;
    }
    bt_pitch = free;
    if (bt_pitch == 0.0f) return;
    {
        f32 elevation = (bt_pitch + base) * (3.14159265f / 180.0f);
        position[0] = focus[0] + dx * (cosf(elevation) * distance / flat);
        position[1] = focus[1] + sinf(elevation) * distance;
        position[2] = focus[2] + dz * (cosf(elevation) * distance / flat);
    }
    func_800A516C(rotation, focus, position);
}
#endif

void func_80110588(PlayerState *arg0) {
    struct StateCallbacks {
        void (*enter)(PlayerState *, s32);
        void (*update)(PlayerState *);
        void (*exit)();
        void (*unkC)();
    };
    extern s16 D_801247A0[];
    void func_800EE7F8(f32 *, f32 *);
    void func_8010FE14(s32 *, f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_801123D4(PlayerState *);
    void func_80112648(void *);
    void func_80112A84(PlayerState *);
    void func_8011347C(PlayerState *);
    void func_80113D30(PlayerState *);
    void func_80114DD8(void *);
    void func_801154A4(PlayerState *);
    void func_80115A9C(void *);
    void func_80116024();
    void func_8011607C(void *, s32);
    void _ncba1p_entrypoint_3(PlayerState *, f32 *, f32 *);
    void _ncbawaypoint_entrypoint_1(PlayerState *);
    f32 sp34[3];
    f32 sp28[3];
    void (*update)(PlayerState *);

    if (((u8 *)arg0)[0x70] != 0) {
        func_8011607C(arg0, 0);
        if (((u8 *)arg0)[0x72] == 0) {
            func_8011347C(arg0);
            func_801123D4(arg0);
            func_80115A9C(arg0);
            func_80112A84(arg0);
            func_801154A4(arg0);
            func_80112648(arg0);
            func_80114DD8(arg0);
            func_80113D30(arg0);
            update = ((struct StateCallbacks *)D_801247A0)[((s32 *)arg0)[27]].update;
            if (update != NULL) {
                update(arg0);
            }
        }
        BT_NATIVE_ONLY(bt_free_camera_yaw(arg0);)
        func_800EFD24(&arg0->unk8C);
        func_800EE7F8(sp34, (f32 *)((u8 *)arg0 + 0x74));
        func_800EE7F8(sp28, (f32 *)((u8 *)arg0 + 0x80));
        BT_NATIVE_ONLY(if (((u8 *)arg0)[0x71] == 0) bt_free_camera_pitch(arg0, sp34, sp28);)
        if (((u8 *)arg0)[0x71] != 0) {
            _ncba1p_entrypoint_3(arg0, sp34, sp28);
        }
        func_80116024(arg0, sp28);
        func_8010FE14(((s32 **)arg0)[25], sp34, sp28);
        if (*((s32 **)arg0)[23] != 0) {
            _ncbawaypoint_entrypoint_1(arg0);
        }
    }
}

s32 func_801106A0(s32 *arg0) {
    return arg0[27];
}

s32 func_801106A8(PlayerState *arg0, s32 arg1) {
    struct StateCallbacks {
        void (*enter)(PlayerState *, s32);
        void (*unk4)();
        void (*exit)();
        void (*unkC)();
    };
    extern s16 D_801247A0[];
    void (*exit)();
    void (*enter)(PlayerState *, s32);
    s32 oldState;

    oldState = ((s32 *)arg0)[27];
    if (arg1 != oldState) {
        exit = ((struct StateCallbacks *)D_801247A0)[oldState].exit;
        if (exit != NULL) {
            exit();
        }
        enter = ((struct StateCallbacks *)D_801247A0)[arg1].enter;
        if (enter != NULL) {
            enter(arg0, arg1);
        }
        ((s32 *)arg0)[27] = arg1;
    }
    BT_NATIVE_ONLY(return 0;) }

void func_80110720(s8 *arg0, s32 arg1) {
    arg0[112] = arg1;
}

void func_80110728(s8 *arg0, s32 arg1) {
    arg0[113] = arg1;
}

void func_80110730(BtIntPtr arg0, s32 arg1) {
    void func_8011337C(PlayerState *);
    s32 func_80113410();
    (*(s8 *)((s8 *)(arg0) + (0x72))) = arg1;
    func_80113410((void *) arg0);
    if (arg1 == 0) {
        func_8011337C((PlayerState *)arg0);
    }
}

/* extern */

void func_80110770(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8((u8 *)arg0 + 0x74, arg1);
}

/* extern */

void func_80110790(BtIntPtr arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x80, arg1);
}

/* extern */

void func_801107B0(void *arg0, f32 *arg1) {
    void func_800F5A00(BtIntPtr, f32 *);
    func_800F5A00((*(s32 *)((s8 *)(arg0) + (0x68))), arg1);
}    typedef struct { u8 pad0[0x34]; f32 * unk34; u8 pad38[0x2C]; s32 * unk64; s32 unk68; s32 unk6C; } Obj1EE9AB0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_801107D0(void *arg0, f32 *arg1) {
    void func_800F5B38(BtIntPtr, f32 *);
    func_800F5B38((((Obj1EE9AB0_arg0 *)arg0)->unk68), arg1);
}

void func_801107F0(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x74);
}

void func_80110818(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x80);
}

s32 func_80110840(s32 *arg0) {
    return arg0[26];
}

void func_80110848(f32 *arg0, f32 *arg1, f32 *arg2) { void func_800EE7F8(); func_800EE7F8(arg1, arg0 + 29); func_800EE7F8(arg2, arg0 + 32); }

u32 func_80110888(u8 *arg0) {
    return arg0[113];
}

u32 func_80110890(u8 *arg0) {
    return arg0[114];
}

BtIntPtr func_80110898(s32 *arg0) {
    return arg0[25];
}

void func_801108A0(void *arg0) {
    void _ncba1p_entrypoint_1(u8 **arg0);
    void func_8010FFB0(s32 *, f32 *, f32 *);
    void func_80111348(s32 *);
    void func_80112398(u8 *);
    s32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_8010FFB0(*(s32 **)((u8 *)arg0 + 0x64), sp30, sp24);
    func_80110770(arg0, sp30);
    func_80110790((BtIntPtr)arg0, sp24);
    func_80111348(arg0);
    sp3C = func_801106A0(arg0);
    func_801106A8(arg0, 0);
    func_801106A8(arg0, sp3C);
    _ncba1p_entrypoint_1((BtIntPtr)arg0);
    func_80112398(arg0);
}

void func_80110928(void *arg0) {
    void func_800F5B38(BtIntPtr, f32 *);
    f32 func_800136E4(f32);
    void func_80110970(void *, f32);
    f32 rotation[3];

    func_800F5B38(((Obj1EE9AB0_arg0 *)arg0)->unk68, rotation);
    func_80110970(arg0, func_800136E4(rotation[1] + 180.0f));
}

void func_80110970(void *arg0, f32 arg1) {
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_8010FE14(s32 *, f32 *, f32 *);
    BtIntPtr func_8010FF80(s32 *);
    void func_800CA3A4(void *camera, f32 distance);
    f32 position[3];
    f32 rotation[3];
    s32 state;

    state = ((Obj1EE9AB0_arg0 *)arg0)->unk6C;
    if (state == 8 || state == 0x11 || state == 0x13 || state == 2) {
        func_800F5A00(((Obj1EE9AB0_arg0 *)arg0)->unk68, position);
        position[1] += 100.0f;
        func_800EFA4C(rotation, 0.0f, arg1, 0.0f);
        func_8010FE14(((Obj1EE9AB0_arg0 *)arg0)->unk64, position, rotation);
        func_800CA3A4(func_8010FF80(((Obj1EE9AB0_arg0 *)arg0)->unk64), 300.0f);
        func_801108A0(arg0);
    }
}

void func_80110A24(PlayerState *player, f32 position[3], f32 rotation[3]) {
    void func_80112524(PlayerState *, f32 *);
    void func_800A516C(f32 *, f32 *, f32 *);
    f32 pos[3];
    func_80112524(player, pos);
    func_800A516C(position, pos, rotation);
    position[2] = 0.0f;
}

/* extern */

void func_80110A68(BtIntPtr arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void func_800A516C(f32 *, f32 *, f32 *);
    func_800A516C((f32 *)arg1, (f32 *)arg2, (f32 *)(arg0 + 0x74));
}

s32 func_80110A9C(PlayerState *arg0, f32 arg1[3], f32 *arg2) {
    void func_800EFB24(void *, void *, void *);
    s32 func_800F6438(BtUIntPtr);
    int func_800F6640(s32);
    s32 func_800F6690(s32);
    s32 func_800F6BE4(BtIntPtr);
    f32 func_80112550(PlayerState *, f32[3]);
    f32 sqrtf(f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    if (func_800F6BE4(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6438(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6640(*(s32 *)((u8 *)arg0 + 0x68)) == 0 ||
        func_800F6690(*(s32 *)((u8 *)arg0 + 0x68)) == 0) {
        return 0;
    }
    sp24 = func_80112550(arg0, sp34);
    func_800EFB24(sp28, arg1, sp34);
    *arg2 = sqrtf((sp28[0] * sp28[0] + sp28[1] * sp28[1]) + sp28[2] * sp28[2]) - sp24;
    return 1;
}

/* extern */

void func_80110B68(void *arg0, s32 arg1) {
    void func_80093700(void *arg0, s32 arg1);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6BE4(BtIntPtr);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    if (arg1 != 0) {
        if (func_800F6BE4((((Obj1EE9AB0_arg0 *)arg0)->unk68)) != 0) {
            func_800F7B9C((((Obj1EE9AB0_arg0 *)arg0)->unk68), 0x6C);
            func_80093700(func_800F53D0((((Obj1EE9AB0_arg0 *)arg0)->unk68)), 1);
        }
    } else if (func_800F6BE4((((Obj1EE9AB0_arg0 *)arg0)->unk68)) != 0) {
        func_800F7B9C((((Obj1EE9AB0_arg0 *)arg0)->unk68), 0x6B);
        func_80093700(func_800F53D0((((Obj1EE9AB0_arg0 *)arg0)->unk68)), 0);
    }
}

/* extern */

void func_80110BF0(PlayerState *self) {
    void _ncba1p_entrypoint_5(void **arg0, s32 arg1);
    void _ncba1p_entrypoint_6(f32 **arg0, f32 *arg1);
    void _ncba1p_entrypoint_7(void **arg0, void *arg1);
    _ncba1p_entrypoint_5(self, 1);
    _ncba1p_entrypoint_6(self, &self->pad58[0x1C]);
    _ncba1p_entrypoint_7(self, &self->flag);
}

/* extern */

void func_80110C2C(PlayerState *self) {
    s32 _ncba1p_entrypoint_10();
    void _ncba1p_entrypoint_13(f32 **volatile arg0, f32 *arg1, f32 *arg2);
    void _ncba1p_entrypoint_5(void **arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = _ncba1p_entrypoint_10();
    if ((temp_v0 != 0) && (temp_v0 != 3)) {
        if (self->pad58[0x1A] != 0) {
            _ncba1p_entrypoint_13(self, &self->pad58[0x1C], &self->flag);
        }
        _ncba1p_entrypoint_5(self, 3);
    }
}

void func_80110C88(BtIntPtr arg0) { void func_80110CC0(BtIntPtr, s32, s32, s32, f32); func_80110CC0(arg0, 0x44098000, 0x441B0000, 0x43160000, 10.0f); }

/* extern */

void func_80110CC0(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 func_8011539C();
    s32 func_80115D08(BtIntPtr, s32, s32, s32, f32);
    func_8011539C();
    func_80115D08(arg0, arg1, arg2, arg3, arg4);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80110D08(BT_PASS2(void *bt_a0, s32 bt_a1))
{
    BT_NATIVE_ONLY(void func_80115864(void *, s32);) func_80115864(BT_PASS2(bt_a0, bt_a1)); BT_NATIVE_ONLY(return 0;)
}

void func_80110D28(u8 *arg0, s32 arg1) {
    void func_80116050(void *arg0, f32 arg1);
    func_80116050(arg0, (f32) arg1);
}

void func_80110D58(u8 *arg0, f32 arg1) {
    void func_801125D8(void *arg0, f32 arg1);
    func_801125D8(arg0, arg1);
}

void func_80110D80(BT_PASS2(void *bt_a0, s32 bt_a1))
{
    func_8011396C(BT_PASS2(bt_a0, bt_a1));
}

void func_80110DA0(BT_NATIVE_ONLY(void *bt_a0))
{
    func_80115460(BT_NATIVE_ONLY(bt_a0));
}

void func_80110DC0(BT_NATIVE_ONLY(void *bt_a0))
{
    func_8011546C(BT_NATIVE_ONLY(bt_a0));
}

void func_80110DE0(BT_NATIVE_ONLY(void *bt_a0))
{
    func_80115478(BT_NATIVE_ONLY(bt_a0));
}

s32 func_80110E00(PlayerState *arg0, s32 arg1) {
    extern s16 D_801247A0[];
    BT_IDO_ONLY(f32 func_800F5AE0(s32);) BT_NATIVE_ONLY(s32 func_800F5AE0(s32); union { s32 bits; f32 value; } bt_pitch;)
    s32 func_80111154(BtIntPtr, f32);
    s32 func_80111198(BtIntPtr, f32);
    s32 func_801111D0(PlayerState *, f32);
    f32 func_801112B0(void *);
    void func_80114D98(void *, s32);
    f32 func_80115E88(void *);

    func_80114D98(arg0, arg1);
    switch (arg1) {
        case 2:
            switch (((s16 *)((u8 *)D_801247A0 + *(s32 *)((u8 *)arg0 + 0x6C) * 16))[7]) {
                case 1:
                    BT_NATIVE_ONLY(bt_pitch.bits = func_800F5AE0(*(s32 *)((u8 *)arg0 + 0x68));) func_80111198((BtIntPtr)arg0, BT_IDO_ONLY(func_800F5AE0(*(s32 *)((u8 *)arg0 + 0x68))) BT_NATIVE_ONLY(bt_pitch.value));
                    break;
                case 2:
                    func_80111198((BtIntPtr)arg0, func_80115E88(arg0));
                    break;
            }
                return func_80111154((BtIntPtr)arg0, func_801112B0(arg0) + 180.0f);
        case 0:
            return func_801111D0(arg0, -45.0f);
        case 1:
            return func_801111D0(arg0, 45.0f);
    }
    return 0;
}

s32 func_80110EFC(BT_IDO_ONLY(u8 *arg0) BT_PASS2(u8 *arg0, s32 bt_a1)) {
    s32 func_80110E00();
    extern s16 D_801247A0[];
    s32 index;
    index = ((Obj1EE9AB0_arg0 *)arg0)->unk6C;
    if (D_801247A0[index * 8 + 6] != 0) {
#ifdef BT_NATIVE
        return func_80110E00(arg0, bt_a1);
#else
        return func_80110E00();
#endif
    } else {
        return 0;
    }
}


void func_80110F44(void *arg0) {
    void func_800A4EFC(void *, f32);
    f32 func_800EEFFC(void *);
    void func_800EFB24(void *, void *, void *);
    PlayerState *func_800F53D0(BtIntPtr);
    void func_80112524(PlayerState *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_80112524(arg0, sp44);
    func_801107F0(arg0, sp38);
    func_800EFB24(sp2C, sp38, sp44);
    func_800A4EFC(func_800F53D0(func_80110840(arg0)), func_800EEFFC(sp2C));
    if (*(s32 *)((s8 *)arg0 + 0x6C) == 0x11) {
        _ncbastring_entrypoint_4(arg0);
    }
}

/* extern */

s32 *func_80110FCC(s32 *arg0, BtIntPtr arg1) {
    s32 *original;

    original = arg0;
    arg0 = defrag(arg0);
    if (original != arg0) {
        func_80110280(arg0);
    }
    arg0[25] = arg1;
    return arg0;
}

void func_80111018(BtIntPtr arg0, BtIntPtr arg1) {
    void _ncba1p_entrypoint_1(u8 **arg0);
    void func_8011337C(PlayerState *);
    s32 func_80113410();
    void rare_memcpy(void* dst, void* src, int length);
    extern s16 D_80137372;
    func_80113410();
    rare_memcpy(arg0 + 0x98, arg1 + 0x98, D_80137372 - 0x98);
    func_8011337C((PlayerState *)arg0);
    _ncba1p_entrypoint_1(arg0);
}

void func_8011106C(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x8C);
}

/* extern */

void func_80111094(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_800EE780(s32, s32, s32, BtIntPtr);
    func_800EE780(arg1, arg0 + 0x74, arg0 + 0x8C, arg0);
}

void func_801110C4(BtIntPtr arg0, u8 *arg1) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    func_800EFB24(arg0 + 0x8C, arg1, arg0 + 0x74);
}

/* extern */

s32 func_801110EC(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _ncbatarget_entrypoint_4(u8 *, s32);
    s32 _ncbatarget_entrypoint_5();
    switch (*(s32 *)(arg0 + 0x6C)) {
    case 0x14:
        _ncbatarget_entrypoint_5(arg0, arg1);
        _ncbatarget_entrypoint_4(arg0, arg2);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_8011113C(void) {
    return 0;
}

s32 func_80111144(void) {
    return 0;
}

s32 func_8011114C(void) {
    return 0;
}

/* extern */

s32 func_80111154(BtIntPtr arg0, f32 arg1) {
    f32 func_800136E4(f32);
    void func_80112D90(PlayerState *, f32, f32, s32, s32);
    func_80112D90(arg0, func_800136E4(arg1), 75.0f, 2, 2);
    return 1;
}

/* extern */

s32 func_80111198(BtIntPtr arg0, f32 arg1) {
    f32 func_800136E4(f32);
    s32 func_80115DEC(BtIntPtr, f32, s32);
    func_80115DEC(arg0, func_800136E4(arg1), 0x42960000);
    return 1;
}

s32 func_801111D0(PlayerState *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    int func_800F1EA4(f32 *, f32 *);
    f32 func_80112550(PlayerState *, f32[3]);
    void func_80112D90(PlayerState *, f32, f32, s32, s32);
    s32 func_80112E84(void *);
    s32 func_8011349C(f32 *, f32 *);
    extern f32 D_80126540;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    f32 sp20[3];

    func_801107F0(arg0, sp4C);
    func_80112550(arg0, sp34);
    func_800EFB24(sp40, sp4C, sp34);
    func_800F1EA4(sp40, &sp30);
    sp2C = func_800136E4(sp30 + arg1);
    if (func_80112E84(arg0) != 1) {
        func_800EF934(sp20, sp40, arg1 * D_80126540);
        func_800EF04C(sp20, sp34);
        if (func_8011349C(sp4C, sp20) == 0) {
            return 0;
        }
    }
    func_80112D90(arg0, sp2C, 45.0f, 1, 2);
    return 1;
}

/* extern */

f32 func_801112B0(void *arg0) {
    s32 func_80092BC4(BtIntPtr);
    f32 func_80092BD0(BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    f32 func_800F5F24(BtIntPtr);
    BtIntPtr sp1C;
    f32 var_f2;
    BtIntPtr temp_v0;

    temp_v0 = func_800F53D0((*(s32 *)((s8 *)(arg0) + (0x68))));
    sp1C = temp_v0;
    if (func_80092BC4(temp_v0) != 0) {
        var_f2 = func_80092BD0(sp1C) - 180.0f;
    } else {
        var_f2 = func_800F5F24((*(s32 *)((s8 *)(arg0) + (0x68))));
    }
    return var_f2;
}

/* extern */

void func_80111310(s32 *arg0) {
    void func_800A509C(void *arg0);
    PlayerState *func_800F53D0(BtIntPtr);
    func_800A509C(func_800F53D0(func_80110840(arg0)));
}

s32 func_80111340() 
{
    return 0x8C;
}

void func_80111348(s32 *arg0) {
    void func_801113B8(void *);
    void func_80111590(void *, f32, f32, f32, f32);
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    func_801113B8(arg0);
    func_80111590(arg0, 10.0f, 10.0f, 120.0f, 120.0f);
    func_80111B8C(arg0, 1.4f, 14.0f);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
}

/* extern */

void func_801113B8(void *arg0) {
    void func_800EFD24(f32 *);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x10);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x38);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0x34))) + 0x44);
}

/* extern */

void func_80111410(void *arg0, void *arg1, void *arg2, f32 arg3) {
    f32 func_80013728(f32);
    f32 func_800D8FF8(void);
    f32 func_800F212C(f32, f32);
    f32 sqrtf(f32);
    f32 delta[3];
    f32 dt;
    f32 length;
    f32 step[3];
    f32 inverse;

    delta[0] = func_80013728(((f32 *)arg1)[0] - ((f32 *)arg2)[0]);
    delta[1] = func_80013728(((f32 *)arg1)[1] - ((f32 *)arg2)[1]);
    delta[2] = func_80013728(((f32 *)arg1)[2] - ((f32 *)arg2)[2]);
    length = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
    if (length != 0.0f) {
        dt = func_800D8FF8();
        inverse = 1.0f / length;
        step[0] = (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x34) + 8) * dt) * (delta[0] * inverse);
        step[1] = (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x34) + 0xC) * dt) * (delta[1] * inverse);
        step[2] = (arg3 * dt) * (delta[2] * inverse);
        step[0] = func_800F212C(step[0], delta[0]);
        step[1] = func_800F212C(step[1], delta[1]);
        step[2] = func_800F212C(step[2], delta[2]);
        ((f32 *)arg2)[0] += step[0];
        ((f32 *)arg2)[1] += step[1];
        ((f32 *)arg2)[2] += step[2];
    }
}

void func_80111590(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (4))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (8))) = arg3;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0xC))) = arg4;
}

/* extern */

s32 func_801115C8(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 func_800EEAA4(f32 *, f32 *);
    f32 sp1C;
    f32 temp_f0;

    sp1C = func_800EEAA4(arg0, arg2);
    temp_f0 = func_800EEAA4(arg0, arg3);
    if (((sp1C < arg1 && arg1 < temp_f0) || (arg1 < sp1C && temp_f0 < arg1)) && temp_f0 != sp1C) {
        *arg4 = (arg1 - sp1C) / (temp_f0 - sp1C);
        return 1;
    }
    return 0;
}

void func_80111680(f32 *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 arg4, f32 arg5, void *arg6) {
    s32 func_800D8FEC();
    s32 func_800EE780();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    int func_800EEEA8(f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800EF2A0(f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    f32 spFC[3];
    f32 spF0[3];
    f32 spE4[3];
    f32 spD8[3];
    f32 spCC[3];
    f32 spC0[3];
    f32 spB4[3];
    f32 distance = 0.0f;
    s32 spAC;
    f32 change = 0.0f;
    s32 i;
    f32 timestep = 0.0033333334f;
    f32 sp94[3];
    f32 sp90;
    f32 sp8C;
    f32 sp80[3];
    f32 sp74[3];
    s32 sp70 = 0;
    s32 sp6C = 0;
    f32 sp68;

    if (func_800EEAD4(arg0, arg1) < 0.01f) {
        func_800EE7F8(arg1, arg0);
        func_800EFD24(arg3);
    }
    if (func_800EEAD4(arg0, arg6) < 0.01f) {
        func_800EFB24(sp80, arg2, arg0);
        if (func_800EEEA8(sp80)) {
            func_800EFA4C(sp80, 1.0f, 0.0f, 0.0f);
        }
        func_800EFA4C(sp74, 0.0f, 1.0f, 0.0f);
        func_800EE97C(sp94, sp80, sp74);
        func_800EF2A0(sp94);
        sp90 = func_800EEAA4(sp94, arg0);
        func_800EF2A0(sp80);
        sp8C = func_800EEAA4(sp80, arg0);
        sp70 = sp6C = 1;
    }
    spAC = func_800D8FEC() * 5;
    i = 0;
    if (spAC > 0) {
    do {
        func_800EFB24(spFC, arg0, arg1);
        func_800EF334(spFC, arg4);
        func_800EFB24(spF0, spFC, arg3);
        func_800EF334(spF0, arg5);
        func_800EE7F8(spE4, arg3);
        func_800EE7F8(spD8, spE4);
        func_800EF174(spD8, spF0, timestep);
        func_800EE7F8(spCC, arg1);
        func_800EE780(spB4, spE4, spD8);
        func_800EF334(spB4, 0.5f * timestep);
        if (sp70 || sp6C) {
            func_800EE780(spC0, spCC, spB4);
            if (sp70 && func_801115C8(sp94, sp90, arg1, spC0, &sp68)) {
                func_800EF334(spB4, sp68);
                sp70 = 0;
                func_800EF174(spD8, sp94, -func_800EEAA4(spD8, sp94));
            } else if (sp6C && func_801115C8(sp80, sp8C, arg1, spC0, &sp68)) {
                func_800EF334(spB4, sp68);
                sp6C = 0;
                func_800EF174(spD8, sp80, -func_800EEAA4(spD8, sp94));
            }
        }
        func_800EE780(spC0, spCC, spB4);
        change += func_800EEAD4(arg3, spD8) / spAC;
        func_800EE7F8(arg1, spC0);
        func_800EE7F8(arg3, spD8);
        distance += func_800EEF94(spB4);
    } while (++i < spAC);
    }
    func_800EE7F8(arg6, arg0);
}    typedef struct { u8 pad0[0x30]; f32 unk30; f32 unk34; } Obj1EE9AB0_func_80111A38_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80111A38(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    void func_80111680(f32 *, f32 *, f32 *, void *, f32, f32, void *);
    f32 func_80112550(PlayerState *, f32[3]);
    f32 sp2C[3];
    u8 *temp_v0;
    func_80112550(arg0, sp2C);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111680(arg1, arg2, sp2C, temp_v0 + 0x24, (((Obj1EE9AB0_func_80111A38_temp_v0 *)temp_v0)->unk30), (((Obj1EE9AB0_func_80111A38_temp_v0 *)temp_v0)->unk34), temp_v0 + 0x38);
}

void func_80111A98(u8 *arg0) {
    func_801107F0(arg0, (*(s32 *)((s8 *)(arg0) + (0x34))) + 0x5C);
}

/* extern */

void func_80111ABC(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8((((Obj1EE9AB0_arg0 *)arg0)->unk34) + 26, arg1);
}

void func_80111AE0(void *arg0, f32 *arg1) {
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_80110898(arg0);
    func_801107F0(arg0, sp24);
    if (func_8010FFD0(sp20) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp24, arg1);
        func_80110770(arg0, arg1);
        return;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp24);
    func_80110770(arg0, sp24);
}

/* extern */

void func_80111B8C(s32 *arg0, f32 arg1, f32 arg2) {
    f32 func_800A3048(BtIntPtr);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x30))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x34))) = (f32) (arg2 * var_f2);
}

void func_80111C04(void *arg0) {
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    f32 dot;

    func_801107F0(arg0, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 20);
    func_800EFB24(sp28, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 26,
                 (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    func_800EFB24(sp34, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 20,
                 (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    func_800EF2A0(sp28);
    func_800EF2A0(sp34);
    dot = func_800EEAA4(sp28, sp34);
    if (dot < 0.0f || (((Obj1EE9AB0_arg0 *)arg0)->unk34)[29] < 0.0f) {
        func_80110770(arg0, (((Obj1EE9AB0_arg0 *)arg0)->unk34) + 23);
    }
    (((Obj1EE9AB0_arg0 *)arg0)->unk34)[29] = dot;
}

/* extern */

s32 func_80111CC8(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EFD24(f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    BtIntPtr sp24;

    sp24 = func_80110898(arg0);
    func_801107F0(arg0, sp34);
    if (func_8010FFD0(sp24) != 0) {
        func_800EFD24((*(f32 **)((s8 *)arg0 + 0x34)) + 9);
        func_80113640(arg0, sp34, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98(arg0);
    func_80111ABC(arg0, arg1);
    func_80111A38(arg0, arg1, sp34);
    func_8011106C(arg0, sp28);
    func_800EF04C(sp34, sp28);
    func_80110770(arg0, sp34);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

void func_80111DB0(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 sp34[3];
    f32 distance;
    f32 step;
    f32 delta;
    u8 *data;

    func_800EFB24(sp34, arg1, arg2);
    distance = func_800EEF94(sp34);
    if (0.01f < distance) {
        delta = func_800D8FF8();
        data = *(u8 **)(arg0 + 0x34);
        step = func_800FF060(distance, arg3, *(f32 *)(data + 0x80), *(f32 *)(data + 0x84), *(f32 *)(data + 0x7C), delta);
        if (distance < step) {
            step = distance;
            *arg3 = 0.0f;
        }
        func_800EF174(arg2, sp34, step / distance);
    } else {
        *arg3 = 0.0f;
    }
}

/* extern */

void func_80111E88(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 func_800D8FF8();
    f32 var_f20;
    f32 temp_f0;
    f32 targetVelocity;
    f32 acceleration;

    temp_f0 = func_800D8FF8();
    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    targetVelocity = (arg0 - *arg1) * arg3;
    acceleration = (targetVelocity - *arg2) * arg4;
    *arg2 += acceleration * temp_f0;
    var_f20 = *arg1 + (*arg2 * temp_f0);
    if (arg0 < *arg1) {
        if (var_f20 < arg0) {
            var_f20 = arg0;
            *arg2 = 0.0f;
        }
    } else if (arg0 < var_f20) {
        var_f20 = arg0;
        *arg2 = 0.0f;
    }
    *arg1 = var_f20;
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1EE9AB0_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1EE9AB0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ typedef struct { u8 pad0[0x30]; f32 unk30; f32 unk34; } Obj1EE9AB0_func_80111F70_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80111F70(u8 *arg0, u8 *arg1, u8 *arg2, void *arg3, f32 *arg4) {
    void func_80111DB0(u8 *, f32 *, f32 *, f32 *);
    f32 sp24;
    f32 temp_f12;
    u8 *temp_v0;

    sp24 = (((Obj1EE9AB0_arg2 *)arg2)->unk4);
    func_80111DB0(arg0, arg1, arg2, arg3);
    (((Obj1EE9AB0_arg2 *)arg2)->unk4) = sp24;
    temp_f12 = (((Obj1EE9AB0_arg1 *)arg1)->unk4);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111E88(temp_f12, arg2 + 4, arg4, (((Obj1EE9AB0_func_80111F70_temp_v0 *)temp_v0)->unk30), (((Obj1EE9AB0_func_80111F70_temp_v0 *)temp_v0)->unk34));
}

/* extern */

s32 func_80111FD4(void *arg0, f32 *arg1) {
    void func_800EF04C(f32 *, f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80111C04(void *);
    s32 func_8011329C(PlayerState *);
    void func_80113640(BtIntPtr, f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    BtIntPtr sp2C;
    u8 *temp_v0;

    sp2C = func_80110898(arg0);
    func_801107F0(arg0, sp3C);
    if (func_8010FFD0(sp2C) != 0) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x34)))) + (0x78))) = 0.0f;
        func_80113640(arg0, sp3C, arg1);
        func_80110770(arg0, arg1);
        goto block_4;
    }
    func_80111A98((u8 *) arg0);
    func_80111ABC(arg0, arg1);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x34)));
    func_80111F70(arg0, arg1, sp3C, temp_v0 + 0x78, temp_v0 + 0x88);
    func_8011106C(arg0, sp30);
    func_800EF04C(sp3C, sp30);
    func_80110770(arg0, sp3C);
    if (func_8011329C(arg0) != 0) {
        func_80111C04(arg0);
        return 1;
    }
block_4:
    return 0;
}

/* extern */

void func_801120CC(s32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800A3048(BtIntPtr);
    s32 func_800F53E4(s32);
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = func_800F53E4(func_80110840(arg0));
    if (temp_v0 != 0) {
        var_f2 = func_800A3048(temp_v0);
    } else {
        var_f2 = 1.0f;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x7C))) = (f32) (arg1 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x80))) = (f32) (arg2 * var_f2);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x34)))) + (0x84))) = (f32) (arg3 * var_f2);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s16 D_80137340 [ 25 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1920);
s16 D_80137372 BT_DATA(4, bss_core2bss2_2_music_tail, 0x1952);
#endif
