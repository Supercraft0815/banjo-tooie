#include "common.h"

void func_80800000_bsbbilldrill(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x168) = 0;
}

void func_80800008_bsbbilldrill(void *arg0) {
    s32 func_8001210C(s32);
    void func_8009C128(void *, f32[3]);
    s8 func_800BF8E4(void);
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8F64(s32, s32);
    extern s32 D_80800AB0_bsbbilldrill[][3];
    f32 sp24[3];

    if (func_800BF8E4() > 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x168))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (0x168))) = func_800C8A98();
            func_800C8E54((*(s32 *)((s8 *)(arg0) + (0x168))), 80.0f, 350.0f);
            func_800C8F64((*(s32 *)((s8 *)(arg0) + (0x168))), 0xB);
        }
        func_8009C128(arg0, sp24);
        sp24[1] -= 10.0f;
        func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x168))), sp24);
        func_800C8E84((*(s32 *)((s8 *)(arg0) + (0x168))), D_80800AB0_bsbbilldrill[func_8001210C(1)]);
    }
}

void func_808000C0_bsbbilldrill(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x168)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x168))) = _chlightfader_entrypoint_1(temp_a3, 0.6f, 2);
    }
}

/* extern */

void func_80800100_bsbbilldrill(void *arg0) {
    f32 func_80092BF4(void *);
    void func_80093300(void *, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_80092BF4(arg0);
    var_f2 = temp_f0;
    if (temp_f0 == 0.0f) {
        var_f2 = 8.0f;
    }
    var_f2 = -var_f2;
    func_80093300(arg0, var_f2);
}

s32 func_80800158_bsbbilldrill(f32 arg0[3]) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800AC8_bsbbilldrill;
    return func_800BABB8(func_800B5BE4(9), arg0, NULL, 1.0f, &D_80800AC8_bsbbilldrill);
}

void func_8080019C_bsbbilldrill(void *arg0) {
    void func_8009C128(void *, f32[3]);
    void func_800BA22C(s32, s32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    f32 func_800DC0C0(void);
    f32 position[3];
    f32 scale;
    s32 emitter;

    if (func_800DC0C0() <= 0.2f) {
        scale = 0.15f;
    } else {
        scale = 0.09f;
    }
    func_8009C128(arg0, position);
    position[1] -= 80.0f;
    emitter = func_80800158_bsbbilldrill(position);
    func_800BA7C4((void *)emitter, scale, scale);
    func_800BA7FC((void *)emitter, scale, scale);
    func_800BA22C(emitter, 2);
}

/* extern */

void func_80800250_bsbbilldrill(void *arg0) {
    void func_800BA22C(s32, s32);
    s32 _fxdlsmoke_entrypoint_0(f32 *);
    void func_8009C128(void *, f32[3]);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    sp1C[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(sp1C), 1);
}

/* extern */

void func_80800298_bsbbilldrill(s32 arg0) {
    s32 _bswalk_entrypoint_1();
    f32 baphysics_get_target_horizontal_velocity(s32);
    s32 baphysics_set_target_horizontal_velocity(s32, f32);
    _bswalk_entrypoint_1();
    baphysics_set_target_horizontal_velocity(arg0, baphysics_get_target_horizontal_velocity(arg0) * 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_808002DC_bsbbilldrill.s")

/* extern */

void func_808005C0_bsbbilldrill(u8 *arg0) {
    f32 func_800D8FF8(void);
    s32 func_8009328C(u8 *, f32);
    f32 delta = func_800D8FF8();
    f32 *velocity = (f32 *) (arg0 + 0x170);
    f32 *position = (f32 *) (arg0 + 0x16C);
    *position += *velocity * delta;
    func_8009328C(arg0, *position);
}

/* extern */

void bsbbilldrill_entrypoint_0(void *arg0) {
    typedef struct player_state_s PlayerState;
    void baflag_clear(PlayerState *, int);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_reset_terminal_velocity(PlayerState *);
    void func_800931AC(PlayerState *, s32);
    void func_80093300(void *, f32);
    void func_80098520(void *, f32);
    void func_8009E474(PlayerState *);
    void func_800A0CF4(PlayerState *, s32);
    func_800931AC(arg0, 1);
    func_80093300(arg0, 0.0f);
    func_80098520(arg0, 1.0f);
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
    func_800A0CF4(arg0, 0);
    baflag_clear(arg0, 0x22);
    baflag_clear(arg0, 0x26);
    func_8009E474(arg0);
    func_808000C0_bsbbilldrill(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_2.s")

s32 bsbbilldrill_entrypoint_3(s32 arg0) {
    extern s32 D_80800B68_bsbbilldrill[];
    return ((s32 *)&D_80800B68_bsbbilldrill)[arg0];
}
