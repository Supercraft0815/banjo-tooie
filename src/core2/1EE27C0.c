#include "common.h"

OSThread *func_80108ED0(void)
{
    extern u8 D_801245D0[];

    return (OSThread *) D_801245D0;
}

OSThread *func_80108EDC(void)
{
    extern u8 D_801245E4[];

    return (OSThread *) D_801245E4;
}

OSThread *func_80108EE8(void)
{
    extern u8 D_801245F8[];

    return (OSThread *) D_801245F8;
}

s32 func_80108EF4(void *arg0, s32 arg1) {
    return (*(u16 *)((s8 *)(arg0) + (8))) == 0x23A;
}

void func_80108F08(void *arg0, void *arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x1A];
        u16 player : 11;
        u16 pad1A : 5;
        u8 pad1C[8];
        u32 id : 10;
        u32 pad24 : 22;
    } HitMarker;
    typedef struct {
        u8 pad0[4];
        f32 position[3];
        u8 pad10[0x4C];
        u8 health[3];
        u8 pad5F[5];
        u32 pad64 : 6;
        u32 bounce : 1;
        u32 pad64b : 25;
        u32 pad68;
        u32 pad6C : 11;
        u32 id : 12;
        u32 pad6Cb : 9;
        u32 pad70 : 31;
        u32 flag : 1;
    } HitActor;
    void *func_80106790(s32);
    s32 _glhittableDll_entrypoint_10(s32);
    s32 _glhittableDll_entrypoint_7(s32);
    s32 _glhittableDll_entrypoint_9(s32);
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_8(s32);
    void *func_80100368(void *);
    s32 func_800F70EC(s32);
    s32 func_800F6C1C(s32);
    s32 func_80102FA0(void *, s32);
    void func_800EC398(void *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void _chbounce_entrypoint_3(f32);
    void _chbounce_entrypoint_2(f32);
    void _chbounce_entrypoint_5(s32, void *);
    void func_80109600(void *, void *);
    void _chflamer_entrypoint_1(void *, void *);
    void func_800EC370(void *, s16 *);
    void _chfreezy_entrypoint_1(void *, s16 *);
    s32 func_8010A430(void *);
    f32 func_8010CD28(void *);
    void func_800EE904(s32 *, f32 *);
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800EB860(s32, s32);
    void _chbaddiesetup_entrypoint_10(void);
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    f32 func_800EC708(void *);
    s32 _gccubesearch_entrypoint_16(s32 *, s32 *, s16 **, s32, s32);
    void func_800EB874(void);
    void func_800EB210(void *, void *, s32);
    void func_800C4B7C(s32);
    void func_8010D930(s32, s32, f32 *, void *);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    extern s32 D_8012460C;
    HitActor *actor;
    s32 effect;
    s32 bounce;
    s32 damage;
    s32 part;
    void *flags;
    s32 isPlayer;
    s32 player;
    s32 remaining;
    f32 yaw;
    f32 source[3];
    s16 frozen[3];
    f32 angle;
    f32 position[3];
    s32 cube;
    s16 *node;
    s32 point[3];
    f32 height;
    s32 amount;
    s32 sound;

    actor = func_80106790((s32)arg0);
    effect = _glhittableDll_entrypoint_10(arg2);
    bounce = _glhittableDll_entrypoint_7(arg2);
    damage = _glhittableDll_entrypoint_9(arg2);
    part = _glhittableDll_entrypoint_6(arg2);
    flags = func_80100368(actor);
    isPlayer = ((HitMarker *)arg1)->id == 0;
    if (!isPlayer || ((player = ((HitMarker *)arg1)->player,
                      func_800F70EC(player)) && func_800F6C1C(player)) ||
        !_glhittableDll_entrypoint_8(arg2)) {
        if (part == 0) {
            if (damage == 0 && ((HitMarker *)arg1)->id != 0) {
                return;
            }
            if (damage <= 0) {
                damage = 1;
            }
        }
        if (damage) {
            amount = func_80102FA0(flags, 0x80000020) ? damage : 100 / damage;
            remaining = actor->health[part] - amount;
            amount = remaining < 0 ? 0 : remaining;
            actor->health[part] = amount;
            if ((u8)amount && damage >= 2) {
                bounce /= 2;
            }
        }
        if (bounce) {
            func_800EC398(arg1, source);
            yaw = func_800F1DF4(source, actor->position);
            _chbounce_entrypoint_3(yaw);
            _chbounce_entrypoint_2(yaw);
            if (actor->bounce) {
                _chbounce_entrypoint_5(bounce + 10, actor);
            } else {
                _chbounce_entrypoint_5(bounce + 5, actor);
            }
        }
        if (damage) {
            switch (part) {
                case 2:
                    if (func_80102FA0(flags, 0x02000000)) {
                        func_80109600(actor, arg1);
                    }
                    break;
                case 1:
                    if (func_80102FA0(flags, 0x01000000)) {
                        func_80109600(actor, arg1);
                    }
                    break;
            }
            if (func_80102FA0(flags, 0x80020000) && ((HitMarker *)arg1)->id == 0x26D) {
                _chflamer_entrypoint_1(actor, arg1);
            }
            if (func_80102FA0(flags, 0x200) && ((HitMarker *)arg1)->id == 0x26E) {
                func_800EC370(arg1, frozen);
                _chfreezy_entrypoint_1(actor, frozen);
            }
            if (!actor->health[part] || (part && func_80102FA0(flags, 0x10000))) {
                if (actor->health[part]) {
                    part--;
                }
                if (part != 2) {
                    actor->health[part] = 99;
                }
                if (part == 2 && effect && func_8010A430(actor)) {
                    angle = func_8010CD28(actor) + 180.0f;
                    func_800EE904(point, actor->position);
                    if (*(s32 **)((u8 *)arg0 + 4)) {
                        func_800DBEFC(*(s32 **)((u8 *)arg0 + 4), 14, position);
                    }
                    func_800EB860((s32)func_80108EF4, (s32)actor);
                    if (*(s32 **)((u8 *)arg0 + 4) &&
                        (position[0] != 0.0f || position[1] != 0.0f || position[2] != 0.0f)) {
                        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, effect + 2,
                                                  ((s32 *)position)[0], ((s32 *)position)[1], ((s32 *)position)[2], *(s32 *)&angle);
                    } else if (func_80102FA0(flags, 0x81000000) &&
                               _gccubesearch_entrypoint_16(point, &cube, &node, 3,
                                                          (s32)(func_800EC708(arg0) * 4.0f))) {
                        func_800EE88C(position, node);
                        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, effect + 2,
                                                  ((s32 *)position)[0], ((s32 *)position)[1], ((s32 *)position)[2], *(s32 *)&angle);
                    } else {
                        height = actor->position[1] + func_800EC708(arg0);
                        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, effect + 2,
                                                  ((s32 *)actor->position)[0], *(s32 *)&height, ((s32 *)actor->position)[2], *(s32 *)&angle);
                    }
                    func_800EB874();
                }
                func_800EB210(arg0, arg1, part);
            }
            if (part && bounce) {
                sound = actor->id == 0x31E ? 0x41F : 0x415;
                func_800C4B7C(sound);
                func_8010D930(1, actor->flag, actor->position, &D_8012460C);
                if (func_80102FA0(flags, 0x02000000) || func_80102FA0(flags, 0x01000000)) {
                    _subaddiejoy_entrypoint_10(actor, 1.0f, 0.25f);
                }
            }
        }
    }
}

void func_801094E0(f32 *arg0, f32 arg1) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_8012461C;
    func_800BBCB8(arg0, (s32) arg0, arg1, 3, &D_8012461C);
}

OSThread *func_80109518(void)
{
    extern u8 D_8012464C[];

    return (OSThread *) D_8012464C;
}

s32 func_80109524(s32 arg0) {
    extern s16 D_801245A0[8][8];
    return D_801245A0[arg0][0];
}

/* extern */

void func_80109538(void *arg0, f32 *arg1, void *arg2, s32 arg3) {
    s32 _subaddiecustomhits_entrypoint_4(Actor *, f32 *, s32);
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80109524(s32);
    f32 sp2C[3];
    s32 var_a1;
    s32 sp24;

    if (_subaddiecustomhits_entrypoint_4(arg0, sp2C, 0) == 0) {
        func_800EE7F8(sp2C, arg1);
    }
    arg2 != NULL ? (var_a1 = ((u32) (*(u32 *)((s8 *)(arg2) + 0x24)) >> 0x16) == 0 ? 0 : 1) : (var_a1 = 0);
    if (arg3 != 0) {
        sp24 = func_800B53A4(0xA);
        func_800BA3FC(sp24, func_80109524(var_a1));
        func_800BABB8(sp24, sp2C, sp2C, 1.0f, func_80109518());
    }
    func_801094E0(sp2C, 1.0f);
}

void func_80109600(void *arg0, void *arg1) {
    void func_80103DFC(void *, f32 *);
    void func_80109538(void *, f32 *, void *, s32);
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    func_80109538(arg0, sp1C, arg1, 1);
}

/* extern */

void func_8010963C(void *arg0, f32 *arg1, void *arg2) { void func_80109538(void *, f32 *, void *, s32); func_80109538(arg0, arg1, arg2, 1); }

/* extern */

void func_8010965C(Actor *arg0) {
    s32 _subaddiecustomhits_entrypoint_4(Actor *, f32 *, s32);
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_80109524(s32);
    f32 sp2C[3];
    s32 sp28;

    if (_subaddiecustomhits_entrypoint_4(arg0, sp2C, 0) != 0) {
        sp28 = func_800B53A4(0xA);
        func_800BA3FC(sp28, func_80109524(2));
        func_800BABB8(sp28, sp2C, sp2C, 1.0f, func_80109518());
    }
}

/* extern */

void func_801096C8(Actor *arg0, s32 arg1) {
    void func_80103DFC(void *, f32 *);
    void func_80109538(void *, f32 *, void *, s32);
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    func_80109538(arg0, sp1C, (void *) arg1, 0);
}

/* extern */

void func_80109704(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void func_80109748(s32, s32, s32, s32, f32, s32, s32, s32);
    func_80109748(arg0 + 4, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801098D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801099D0.s")

/* extern */

void func_80109BEC(s32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void func_801099D0(s32, f32, s32, s32, s32, s32);
    func_801099D0(arg0, arg1, arg2, arg3, arg4, arg5);
}

/* extern */

void func_80109C20(s32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    void func_801099D0(s32, f32, s32, s32, s32, s32);
    func_801099D0(arg0, arg1, arg2, arg3, 0, 0);
}

/* extern */

void func_80109C4C(s32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) { struct Flags { u8 pad[0x24]; u32 value : 10; u32 rest : 22; }; s32 temp; u32 saved; void func_801099D0(s32, f32, s32, s32, s32, s32); saved = ((struct Flags *)arg5)->value; ((struct Flags *)arg5)->value = arg6; func_801099D0(arg0, arg1, arg2, arg3, arg4, arg5); ((struct Flags *)arg5)->value = saved; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109CC4.s")

s32 func_80109EE0(void *arg0, s32 arg1) {
    return (*(u16 *)((s8 *)(arg0) + (0x66))) & arg1;
}

void func_80109EEC(s16 *arg0, s32 arg1) {
    arg0[51] = arg1;
}

void func_80109EF4(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x66))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x66))) & ~arg1);
}

void func_80109F08(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x66))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x66))) | arg1);
}

/* extern */

void func_80109F18(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x3E, arg1);
}

/* extern */

void func_80109F40(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x3F, arg1);
}

/* extern */

void func_80109F68(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x40, arg1);
}

/* extern */

void func_80109F90(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x41, arg1);
}

/* extern */

void func_80109FB8(s32 arg0, volatile s32 arg1) {
    void *func_80106790(s32);
    (*(s32 *)((s8 *)(func_80106790(*(s32 *)&arg1)) + (0x3C))) = arg0;
}

void func_80109FE8(void **arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1B];
        u8 other : 7;
        u8 enabled : 1;
    };
    if (arg1 != 0) {
        ((struct Flags *) *arg0)->enabled = 0;
        return;
    }
    ((struct Flags *) *arg0)->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A01C.s")

void func_8010A2FC(Actor *arg0, f32 *arg1, f32 *arg2) {
    void func_800EC75C(Unk80132ED0 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80101080(void);
    s32 func_8010108C(Actor *, s32, s32);
    extern f32 D_801264B4;
    f32 *var_s0;
    f32 temp_f0;
    f32 var_f22;
    f32 sp48[3];
    s32 var_s2;

    var_s2 = func_8010108C(arg0, 0xA2, 0);
    if (var_s2 > 0) {
        var_s0 = func_80101080();
        var_f22 = D_801264B4;
        while (var_s2--) {
            func_800EE7F8(sp48, var_s0);
            temp_f0 = func_800EEB40(sp48, arg2);
            if (temp_f0 < var_f22) {
                func_800EE7F8(arg1, sp48);
                var_f22 = temp_f0;
            }
            var_s0 += 3;
        }
    } else {
        func_800EC75C(arg0->unk0, arg1);
    }
}

void func_8010A3E8(void *arg0, f32 arg1) {
    (*(s16 *)((s8 *)(arg0) + (0x92))) = (s16) (s32) (256.0f * arg1);
}

f32 func_8010A40C(void *arg0) {
    return (f32) (*(s16 *)((s8 *)(arg0) + (0x92))) * 0.00390625f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A430.s")

u32 func_8010A5B0(Actor *, s32);

void func_8010A570(s32 arg0)
{
    func_8010A5B0(arg0,0);
}

void func_8010A590(Actor *arg0)
{
    func_8010A5B0(arg0,1);
}

u32 func_8010A5B0(Actor *arg0, s32 arg1) {
    u32 func_8010A610(void **);
    struct Flags { u8 pad[0x2A]; u8 upper : 6; u8 enabled : 1; u8 lower : 1; };
    u32 result;

    result = func_8010A610((void **)arg0);
    if (arg1 != 0) {
        ((struct Flags *)arg0->unk0)->enabled = 1;
    } else {
        ((struct Flags *)arg0->unk0)->enabled = 0;
    }
    return result;
}

u32 func_8010A610(void **arg0) {
    return (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x16) >> 0x1F;
}

void func_8010A624(void ***arg0) {
    void *temp_v0;

    temp_v0 = **arg0;
    (*(u8 *)((s8 *)(temp_v0) + (0xB))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0xB))) & 0xFFF7);
}

void func_8010A63C(void ***arg0) {
    struct Flags {
        u8 pad[8];
        u32 upper : 28;
        u32 enabled : 1;
        u32 lower : 3;
    } *flags;

    flags = **arg0;
    flags->enabled = 1;
}

u32 func_8010A654(void ***arg0, s32 arg1) {
    struct Flags {
        u8 pad[8];
        u32 upper : 28;
        u32 enabled : 1;
        u32 lower : 3;
    } *ptr = **arg0;
    u32 result = ptr->enabled;

    if (arg1) {
        ptr->enabled = 1;
    } else {
        ptr->enabled = 0;
    }
    return result;
}

u32 func_8010A698(void ***arg0) {
    return (u32) ((*(s32 *)((s8 *)(**arg0) + (8))) << 0x1C) >> 0x1F;
}

/* extern */

s32 func_8010A6B0(Actor *arg0, s32 arg1) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    s32 func_800F4B4C(s32);
    f32 func_800F57F0(s32, f32 *);
    void func_80103DFC(void *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    if (func_800F4B4C(arg1) == 0) {
        return 0;
    }
    func_800F57F0(arg1, sp28);
    func_80103DFC(arg0, sp34);
    if (func_800C6A7C(sp28, sp34, sp1C, 0x4A0021) != 0) {
        return 0;
    }
    return 1;
}
