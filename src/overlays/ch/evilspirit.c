#include "common.h"

OSThread *chevilspirit_entrypoint_0(void)
{
    extern u8 D_80802270_chevilspirit[];

    return (OSThread *) D_80802270_chevilspirit;
}

void func_8080000C_chevilspirit(Actor *arg0) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C(void);
    s32 func_800EA068(s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    u32 func_8010A828(Actor *, u32);
    s32 func_80800F8C_chevilspirit(Actor *);
    void func_80801344_chevilspirit(u8 *);
    u8 *link;

    link = func_80100094(arg0, 0);
    if (func_80800F8C_chevilspirit(arg0) != 0) {
        _subaddieDll_entrypoint_0(arg0);
        func_8010A828(arg0, 9);
    }
    func_80801344_chevilspirit((u8 *)arg0);
    func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
    arg0->unk58 = func_800DC178(5.0f, 8.0f);
    _subaddielink_entrypoint_0(link);
    arg0->actorData[3] = 0;
    if (func_800EA068(0x10) != 0) {
        if ((func_800EA05C() == 0x141) && (func_800DA298(0x38) == 0)) {
            func_80102424(arg0, 2);
            arg0->unk58 = 3.0f;
            return;
        }
        func_80102424(arg0, 3);
        arg0->unk58 = 2.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800104_chevilspirit.s")

void func_808005B4_chevilspirit(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    }
}

s32 func_808005EC_chevilspirit(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    void func_80801C04_chevilspirit(Actor *);
    void func_80801F1C_chevilspirit(Actor *, s32, s32);
    void func_80802024_chevilspirit(Actor *, s32, s32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    extern s32 D_808021D0_chevilspirit[];
    void *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x2E:
            func_80801F1C_chevilspirit(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x2F:
            func_80802024_chevilspirit(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x95:
            func_80801C04_chevilspirit(arg0);
            break;
        case 0x1F:
            func_801015D0(arg0);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, (u8 *)data + 0x40, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808021D0_chevilspirit, arg0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800718_chevilspirit(Actor *arg0, s32 arg1) {
    s32 func_800EB854(void);
    void func_801017D0(Actor *);
    s32 func_80101808(Actor *, void (*)(Actor *));
    void func_808007B4_chevilspirit(Actor *, s32);
    s32 saved;
    s32 state;
    Unk80132ED0 *marker;
    struct Flags {
        u32 other : 31;
        u32 enabled : 1;
    };

    state = func_800EB854();
    switch (state) {
        case 0:
        case 2:
            marker = arg0->unk0;
            saved = ((struct Flags *)&marker->unk10)->enabled;
            ((struct Flags *)&marker->unk10)->enabled = 0;
            func_80101808(arg0, func_801017D0);
            marker = arg0->unk0;
            ((struct Flags *)&marker->unk10)->enabled = saved;
            break;
        case 3:
            func_808007B4_chevilspirit(arg0, arg1);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808007B4_chevilspirit.s")

void func_80800A4C_chevilspirit(Actor *arg0, Gfx **arg1, s32 *arg2, f32 *arg3, Actor *arg4, f32 arg5, u8 *arg6) {
    f32 func_800136E4(f32);
    f32 func_80013788(void);
    f32 func_800137F4(f32);
    f32 func_80013B70(f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 sqrtf(f32);
    void func_80800BFC_chevilspirit(Actor *, Gfx **, s32 *, s16 *, u8 *);
    f32 delta[3];
    f32 distance;
    f32 angle;
    s16 offset[2];

    func_800EFB24(delta, arg3, arg4->position);
    delta[1] = 0.0f;
    distance = delta[0] * delta[0] + delta[2] * delta[2];
    if (!(distance >= 4000000.0f)) {
        distance = sqrtf(distance);
        angle = func_80013B70(delta[0], delta[2], distance);
        angle = func_800136E4(angle - arg5);
        arg6[3] = (u32)func_800F10B4(distance, 1600.0f, 2000.0f, 255.0f, 0.0f);
        if (arg6[3]) {
            distance *= 0.025f;
            offset[0] = (s32)(-func_800137F4(angle) * distance);
            offset[1] = (s32)(-func_80013788() * distance);
            func_80800BFC_chevilspirit(arg0, arg1, arg2, offset, arg6);
        }
    }
}

void func_80800BFC_chevilspirit(Actor *arg0, Gfx **arg1, s32 *arg2, s16 *arg3, u8 *arg4) {
    s32 x;
    s32 y;
    s32 alpha;

    x = (arg2[0] + arg3[0]) & 0xFFFC;
    y = (arg2[1] + arg3[1]) & 0xFFFC;
    gDPPipeSync((*arg1)++);
    alpha = (arg4[3] * arg0->alpha) >> 8;
    gDPSetFogColor((*arg1)++, arg4[0] >> 2, arg4[1] >> 2, arg4[2] >> 2, (alpha >> 1) + (alpha >> 2));
    gSPTextureRectangle((*arg1)++, x - 8, y - 8, x + 8, y + 8, 0, 0, 0, 256, 256);
    gDPPipeSync((*arg1)++);
    gDPSetFogColor((*arg1)++, arg4[0], arg4[1], arg4[2], alpha);
    gSPTextureRectangle((*arg1)++, x - 4, y - 4, x + 4, y + 4, 0, 0, 0, 256, 256);
}

void func_80800E20_chevilspirit(Actor *arg0, Gfx **arg1, s32 *arg2)
{
  s32 y;
  s32 x;
  if (((arg0->unk70_10 != 1) && (arg0->unk70_10 != 2)) && (arg0->unk70_10 != 3))
  {
    x = arg2[0] & (~3);
    y = arg2[1] & (~3);
    gDPPipeSync((*arg1)++);
    gDPSetFogColor((*arg1)++, 255, 255, 255, (arg0->alpha << 7) >> 8);
    gSPTextureRectangle((*arg1)++, x - 4, y, x + 8, y + 4, 0, 0, 0, 256, 256);
    gSPTextureRectangle((*arg1)++, x, y - 4, x + 4, y + 8, 0, 0, 0, 256, 256);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800F8C_chevilspirit.s")

int func_80800FF8_chevilspirit(s32 arg0) {
    s32 func_800EA05C();
    extern u16 D_808022E4_chevilspirit;
    extern u16 D_808022E8_chevilspirit;
    u16 *ptr;
    s32 map;

    map = func_800EA05C();
    ptr = &D_808022E4_chevilspirit; loop_1: if (map == *ptr) {
            return 1;
        }
        ptr++;
        if (ptr == &D_808022E8_chevilspirit) {
            return 0;
        }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_8080104C_chevilspirit.s")

void func_808012CC_chevilspirit(Actor *arg0) {
    s32 func_8001210C(s32);
    s32 func_800C954C(void);
    void func_80102424(Actor *, s32);
    s32 func_8080104C_chevilspirit();
    s32 func_80801988_chevilspirit();
    s32 func_80801EC4_chevilspirit(s32);
    s32 temp_v0;

    if ((func_8001210C(3) == 0) && (func_800C954C() == 0) && (func_80801EC4_chevilspirit(arg0) != 0)) {
        temp_v0 = func_8080104C_chevilspirit(arg0, 0);
        if ((temp_v0 != 0) && (func_80801988_chevilspirit(arg0, temp_v0, 0) != 0)) {
            func_80102424(arg0, 5);
        }
    }
}

/* extern */

void func_80801344_chevilspirit(u8 *arg0) {
    void func_8008FE94();
    f32 func_80090010();
    void func_808013DC_chevilspirit(void *);
    func_8008FE94(5, arg0 + 0x18, arg0);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x1C))) + 100.0f);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80090010();
    func_808013DC_chevilspirit(arg0);
}

/* extern */

void func_80801398_chevilspirit(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_808013DC_chevilspirit(void *);
    s32 func_80801458_chevilspirit();
    Actor *_subaddielink_entrypoint_4(u8 *);
    if (_subaddielink_entrypoint_4(func_80100094(arg0, 0U)) != 0) {
        func_80801458_chevilspirit(arg0);
        func_808013DC_chevilspirit((u8 *) arg0);
    }
}

void func_808013DC_chevilspirit(void *arg0) {
    void func_80102BF8(void *, f32, f32, f32);
    Actor *actor = arg0;
    struct { f32 position[3]; } *data = (void *) actor->actorData;

    actor->position[0] += 0.3f * (data->position[0] - actor->position[0]);
    actor->position[1] += 0.3f * (data->position[1] - actor->position[1]);
    actor->position[2] += 0.3f * (data->position[2] - actor->position[2]);
    func_80102BF8(arg0, 0.2f, 15.0f, 1200.0f);
}

s32 func_80801458_chevilspirit(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_80101038(f32 *);
    void func_8010105C(f32);
    f32 func_80101068(void);
    s32 func_8010108C(Actor *, s32, s32);
    f32 func_8010CD28(Actor *);
    Actor *actor;
    u8 *link;

    link = func_80100094(arg0, 0);
    actor = _subaddielink_entrypoint_4(link);
    func_8010105C(func_8010CD28(arg0));
    if (func_8010108C(actor, 0x97, 0) <= 0) {
        f32 *data;
        func_800EE7F8((f32 *)arg0->actorData, actor->position);
        data = (f32 *)arg0->actorData;
        data[1] += actor->scale * (u16)actor->pad68 + data[5];
    } else {
        f32 *volatile position;
        func_80101038(position = (f32 *)arg0->actorData);
        func_800EF334(position, actor->scale);
        func_800EF04C(position, actor->position);
    }
    arg0->unk54 = func_80101068();
}

void func_80801534_chevilspirit(Actor *arg0) {
    void func_8008FE94(s32, f32 *);
    void func_80102424(Actor *, s32);
    s32 func_808015E0_chevilspirit(Actor *, f32);
    void func_80802090_chevilspirit(Actor *, s32 *);
    extern u16 D_808022E8_chevilspirit;
    func_8008FE94(5, (f32 *) arg0->actorData);
    ((f32 *) arg0->actorData)[1] += 100.0f;
    if (func_808015E0_chevilspirit(arg0, 25.0f) != 0) {
        void *sound_data = &D_808022E8_chevilspirit;
        func_80802090_chevilspirit(arg0, sound_data);
        func_80102424(arg0, 1);
    }
}

/* extern */

void func_808015A4_chevilspirit(Actor *arg0) {
    void func_80102424(Actor *, s32);
    s32 func_80801458_chevilspirit();
    s32 func_808015E0_chevilspirit(Actor *, f32);
    func_80801458_chevilspirit();
    if (func_808015E0_chevilspirit(arg0, 100.0f) != 0) {
        func_80102424(arg0, 6);
    }
}

s32 func_808015E0_chevilspirit(Actor *arg0, f32 arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 angles[2];

    if (func_800EEB40(arg0->position, (f32 *) arg0->actorData) < arg1 * arg1) {
        return 1;
    }
    func_800F18FC(arg0->position, (f32 *) arg0->actorData, angles);
    func_800EF214(arg0->position, angles[0], angles[1], arg1);
    arg0->unk54 = angles[1];
    func_80102BF8(arg0, 0.2f, 15.0f, 1200.0f);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801684_chevilspirit.s")

s32 func_80801840_chevilspirit(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 _subaddielink_entrypoint_2(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *actor;

    if (_subaddielink_entrypoint_2(func_80100094(arg0, 0)) == 0) {
        return 0;
    }
    actor = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
    if (!actor->unk64_24) {
        actor->unk64_29 = 0;
        _subaddielink_entrypoint_0(func_80100094(arg0, 0));
        func_8010108C(actor, 2, 0);
        return 0;
    }
    return 1;
}

s32 func_808018DC_chevilspirit(Actor *arg0) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_800BDC5C(void);
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_8010D254(f32 *);
    s32 func_80801A6C_chevilspirit(Actor *, s32);
    Actor *sp2C;
    f32 sp20[3];
    sp2C = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
    func_8010D254(sp20);
    if (func_800EEB40(sp20, sp2C->position) >
        (func_800BDC5C() + 300.0f) * (func_800BDC5C() + 300.0f)) {
        return func_80801A6C_chevilspirit(arg0, 1);
    }
    return 1;
}

s32 func_80801988_chevilspirit(Actor *arg0, Unk80132ED0 *arg1, s32 arg2) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80801A6C_chevilspirit(Actor *, s32);
    void func_80802090_chevilspirit(Actor *, s32 *);
    extern s32 D_808021E0_chevilspirit;
    struct SpiritFlags {
        u8 pad[0x64];
        u8 pad64_30 : 2;
        u8 unk64_29 : 1;
        u8 unk64_27 : 2;
        u8 pad64_24 : 3;
    };
    Actor *other;

    other = func_80106790(arg1);
    if (arg1 == *(Unk80132ED0 **)func_80100094(arg0, 0)) {
        return 1;
    }
    if (func_80801A6C_chevilspirit(arg0, 2) == 0) {
        return 0;
    }
    _subaddielink_entrypoint_1(func_80100094(arg0, 0), arg1);
    arg0->actorData[6] = 0;
    ((f32 *)arg0->actorData)[5] = 0.0f;
    ((struct SpiritFlags *)other)->unk64_29 = 1;
    ((struct SpiritFlags *)other)->unk64_27 = 1;
    if (arg2 == 0) {
        func_80802090_chevilspirit(arg0, &D_808021E0_chevilspirit);
    }
    func_8010108C(other, 1, 0);
    return 1;
}

s32 func_80801A6C_chevilspirit(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 func_8010108C(Actor *, s32, s32);
    s32 func_80801840_chevilspirit();
    Actor *sp1C;

    if (func_80801840_chevilspirit() != 0) {
        sp1C = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
        if (func_8010108C(sp1C, 0x46, arg1) > 0) {
            return 0;
        }
        sp1C->unk64_29 = 0;
        func_8010108C(sp1C, 2, 0);
        _subaddielink_entrypoint_0(func_80100094(arg0, 0));
    }
    return 1;
}

void func_80801B00_chevilspirit(s32 arg0, Actor *arg1, s32 arg2) {
    s32 _subaddievolume_entrypoint_0(Actor *, f32 *, s32, s32, s32);
    s32 func_8001210C(s32);
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808022F4_chevilspirit;
    f32 sp4C[15][3];
    f32 *var_s1;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    temp_s0 = ((u32)(u16)arg1->unk0->unk10 >> 1) & 3;
    if (func_8001210C(3) == temp_s0) {
        temp_v0 = _subaddievolume_entrypoint_0(arg1, sp4C[0], 1, 0xF, arg0 + 0x30);
        if (temp_v0 > 0) {
            temp_v0_2 = func_800B53A4(temp_v0);
            func_800BA3FC(temp_v0_2, arg2);
            func_800BABB8(temp_v0_2, NULL, 0, 1.0f, &D_808022F4_chevilspirit);
            var_s0 = 0;
            if (temp_v0 > 0) {
                var_s1 = sp4C[0];
                do {
                    func_800BABB8(temp_v0_2, var_s1, 0, 1.0f, NULL);
                    func_800BA22C(temp_v0_2, 1);
                    var_s0 += 1;
                    var_s1 += 3;
                } while (var_s0 != temp_v0);
            }
        }
    }
}

void func_80801C04_chevilspirit(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddielink_entrypoint_3(u8 *);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_12(u32 *, s32 *);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s8 func_800BF8E4(void);
    s32 func_800C8A98(void);
    void func_800C8E54(s32, f32, f32);
    s32 func_800D3934(void);
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_80801E18_chevilspirit(void *);
    extern s32 D_808021D0_chevilspirit[];
    u8 *link;
    f32 marker[6];
    u32 *game;

    link = func_80100094(arg0, 0);
    _susubgame_entrypoint_0(arg0, (u32 *)(link + 0x40), 0);
    game = (u32 *)(link + 0x40);
    _susubgame_entrypoint_12(game, D_808021D0_chevilspirit);
    if (_subaddielink_entrypoint_3(func_80100094(arg0, 0)) == 0) {
        if (arg0->unk70_10 != 1 && arg0->unk70_10 != 2 && arg0->unk70_10 != 3) {
            func_80102424(arg0, 8);
        }
    }
    if (func_800EA05C() == 0xAF) {
        _subaddiemarker_entrypoint_1(arg0, 0x154, 0x32, marker, 1);
        if (func_800D3934() == 0) {
            if (func_800DA298(0x3B) != 0) {
                func_800FFAB0(arg0);
                return;
            }
            func_800EE7F8(arg0->position, marker);
            arg0->rotation[1] = marker[4];
            func_80103140(arg0, 0x90E, arg0->unk0->unk16);
            func_80102424(arg0, 0xD);
        } else if (func_800DA298(0xCA) == 0) {
            func_800EE7F8(arg0->position, marker);
            arg0->rotation[1] = marker[4];
            func_80103140(arg0, 0x90E, arg0->unk0->unk16);
            func_80102424(arg0, 9);
            func_800F82D4(func_800F54E4(), 1);
            _susubgame_entrypoint_6(arg0, game, 8, 0x20, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x15C5, 6, arg0->position, 0xBB);
        }
    }
    if (func_800BF8E4() != 0 && func_80800FF8_chevilspirit((s32)arg0) == 0) {
        ((f32 *)arg0->actorData)[7] = 0.0f;
        arg0->actorData[3] = func_800C8A98();
        func_800C8E54(arg0->actorData[3], 150.0f, 450.0f);
        func_80801E18_chevilspirit(arg0);
    } else {
        arg0->actorData[3] = 0;
    }
}

void func_80801E18_chevilspirit(void *arg0) {
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E84(s32, u32[3]);
    f32 func_800D8FF8(void);
    f32 func_800F0F9C(f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    f32 func_800F3780(f32, u8 *, s16);
    void func_80103DFC(Actor *, f32 *);
    extern u32 D_80802320_chevilspirit[3];
    extern u32 D_8080232C_chevilspirit[3];
    extern u8 D_80802338_chevilspirit[3];
    u32 sp3C[3];
    f32 sp30[3];
    f32 delta;
    f32 sp28;

    if ((*(s32 *)((s8 *)(arg0) + (0x24))) != 0) {
        sp28 = func_800F3780(func_800F0F9C((*(f32 *)((s8 *)(arg0) + (0x34))), 0.5f), D_80802338_chevilspirit, 3);
        func_80103DFC(arg0, sp30);
        func_800F3214(sp3C, D_80802320_chevilspirit, D_8080232C_chevilspirit, sp28);
        func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x24))), sp30);
        func_800C8E84((*(s32 *)((s8 *)(arg0) + (0x24))), sp3C);
        delta = func_800D8FF8();
        (*(f32 *)((s8 *)(arg0) + (0x34))) += delta;
    }
}

/* extern */

s32 func_80801EC4_chevilspirit(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F6D24(s32);
    s32 func_800F8004(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6D24(temp_v0) != 0) {
        return 0;
    }
    if (func_800F8004(sp1C) != 0) {
        return 0;
    }
    return 1;
}

void func_80801F1C_chevilspirit(Actor *arg0, s32 arg1, s32 arg2) {
    void _plcamera_entrypoint_8(s32);
    s32 _subaddiefade_entrypoint_5();
    s32 _susubgame_entrypoint_4(void *, void *);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    s32 func_800F54E4();
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80802090_chevilspirit(Actor *, s32 *);
    extern s32 D_80802350_chevilspirit;
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x15C5:
        func_80802090_chevilspirit(arg0, &D_80802350_chevilspirit);
        func_80102424(arg0, 0xA);
        _subaddiefade_entrypoint_5(arg0);
        return;
    case 0x15CB:
        func_80102424(arg0, 8);
        _susubgame_entrypoint_4(arg0, sp24 + 0x40);
        func_800F82D4(func_800F54E4(), 0);
        _plcamera_entrypoint_8(func_800F54E4());
        func_800DA544(0xCA);
        return;
    case 0x15C6:
    case 0x15C7:
    case 0x15C8:
    case 0x15C9:
        func_80102424(arg0, 0xD);
        arg0->unk58 = func_800DC178(5.0f, 8.0f);
        break;
    }
}

/* extern */

void func_80802024_chevilspirit(Actor *arg0, s32 arg1, s32 arg2) {
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    u32 func_800C07F4(void);
    void *func_80100094(Actor *, u32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    if ((func_800C07F4() == 0) && (arg1 == 0x15C5) && (arg2 == 1)) {
        _susubgame_entrypoint_6(arg0, sp24 + 0x40, 5, 0x20, 0);
    }
}

/* extern */

void func_80802090_chevilspirit(Actor *arg0, s32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 *sp20 = arg0->position;
    if (arg0->unk5F == 0) {
        arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        func_800C330C(arg0->unk5F, 3);
    }
    func_800C3058(arg0->unk5F, 0x55F0);
    func_800C31DC(arg0->unk5F, 1.0f);
    func_800C4350(arg0->unk5F, sp20, arg1);
    func_800C3BDC(arg0->unk5F);
}

/* extern */

void func_80802118_chevilspirit(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}
