#include "common.h"

/* extern */

void func_80800000_chfantasyeyeball(Actor *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 func_800D0B68(u32, u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_808010B0_chfantasyeyeball(Actor *, f32 *, f32 *);
    if (func_800D0B68(0x4C, 1) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (!(arg0->unk74_7 - 0x32) && (func_800D0B68(0x4C, 1) == 0)) {
        arg0->unk64_20 = 1;
    } else {
        arg0->unk64_20 = 0;
    }
    func_808010B0_chfantasyeyeball(arg0, &arg0->actorData[2], &arg0->actorData[4]);
    func_808010B0_chfantasyeyeball(arg0, &arg0->actorData[0], &arg0->actorData[1]);
    arg0->unk64_19 = 0;
    _subaddielink_entrypoint_0(func_80100094(arg0, 0));
    ((f32 *)arg0->actorData)[6] = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808000D8_chfantasyeyeball.s")

s32 func_80800950_chfantasyeyeball(Actor *arg0, s32 arg1, Actor *arg2, Actor *arg3) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_800C3F48(u32);
    void func_800C4140(s32, f32 *, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800F78_chfantasyeyeball(Actor *, Actor *);
    s32 func_80800FEC_chfantasyeyeball(Actor *);
    void func_80801290_chfantasyeyeball(Actor *, s32, s32);
    f32 func_808016B4_chfantasyeyeball(s32);
    Unk80132ED0 *marker;

    if (arg2) {}
    if (arg3) {}
    switch (arg1) {
    case 2:
        if (func_800DA298(0x6EC) == 0) {
            func_80801290_chfantasyeyeball(arg0, 0x40800000, 0);
        }
        if (func_800DA298(0x6D4) == 0) {
            func_800DA544(0x6D4);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x141A, 0xF, arg0->position, 0x22);
        }
        break;
    case 3:
        ((f32 *)arg0->actorData)[3] = func_808016B4_chfantasyeyeball((s32)arg0);
        break;
    case 7:
    case 10:
        if (arg0->unk64_20 && func_800DA298(0x6D5) == 0) {
            func_800DA544(0x6D5);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x141B, 0xF, arg0->position, 0x22);
        }
        func_800C4140(0xB31B5DB8, arg0->position, 0x1B5801F4);
        if (arg0->unk64_20) {
            func_80800FEC_chfantasyeyeball(arg0);
            func_80801290_chfantasyeyeball(arg0, 0x402D4FDF, 0);
        }
        break;
    case 8:
    case 11:
        func_800C3F48(0x4CBB5CEE);
        break;
    case 6:
        func_800C3F48(0x4CBB5CED);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_80801290_chfantasyeyeball(arg0, 0x3FC00000, 1);
        break;
    case 9:
    case 12:
        if (arg0->unk64_20) {
            marker = ((Unk80132ED0 **)arg0->actorData)[7];
            if (marker != NULL) {
                func_80800F78_chfantasyeyeball(arg0, func_80106790(marker));
            } else if (func_800DA298(0x6BD) == 0) {
                func_800DA544(0x6BD);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x141C, 0xF, arg0->position, 0x22);
            }
        }
        arg0->unk64_19 = 0;
        ((f32 *)arg0->actorData)[5] = 1.5f;
        break;
    }
    func_80102424(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_80800B68_chfantasyeyeball.s")

/* extern */

void func_80800F78_chfantasyeyeball(Actor *arg0, Actor *arg1) {
    void* func_80100094(Actor*, u32);
    s32 _subaddielink_entrypoint_5(u8 *, u8 *);
    s32 func_80800950_chfantasyeyeball(Actor *, s32, Actor *, Actor *);
    void *sp18[2];

    arg0->unk64_20 = 0;
    arg1->unk64_20 = 1;
    func_80800950_chfantasyeyeball(arg1, 6, arg1, arg0);
    sp18[0] = func_80100094(arg0, 0U);
    _subaddielink_entrypoint_5(sp18[0], func_80100094(arg1, 0U));
}

s32 func_80800FEC_chfantasyeyeball(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    u8 *actors[15];
    s32 count;
    s32 index;
    s32 minimum;
    s32 best;
    s32 value;
    Actor *actor;

    count = _subaddiefind_entrypoint_4(0x482, actors, 15);
    best = -1;
    minimum = 255;
    index = 0;
    if (count > 0) {
        do {
            actor = (Actor *)actors[index];
            if ((s32)actor->unk70_10 < 7 && arg0 != actor) {
                value = actor->unk74_7;
                if (value < minimum) {
                    best = index;
                    minimum = value;
                }
            }
            index++;
        } while (index < count);
    }
    if (best == -1) {
        arg0->actorData[7] = 0;
        return 0;
    }
    arg0->actorData[7] = (u32)((Actor *)actors[best])->unk0;
    return 1;
}

/* extern */

void func_808010B0_chfantasyeyeball(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    f32 func_800DC0C0(void);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp64[3];
    f32 temp_f20;
    f32 sp54[3];

    temp_f20 = func_800DC0C0() * 360.0f;
    *arg1 = (func_800DC0C0() * 20.0f) + 20;
    *arg2 = temp_f20;
    for (; *arg2 < temp_f20 + 360.0f; *arg2 += 30.0f) {
        func_800EEC30(sp54, *arg1, *arg2, 2500.0f);
        func_800EF04C(sp54, arg0->position);
        if (func_800BEF00(arg0->position, sp54, sp64, 0) == 0) {
            break;
        }
    }
}

/* extern */

void func_808011D0_chfantasyeyeball(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800E39D8(s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EEC30(sp30, arg1, arg2, (500.0f * arg3) + 2000.0f);
    func_800EF04C(sp30, arg0->position);
    func_800EFA4C(sp24, arg0->position[0], arg0->position[1] + arg0->scale * 224.0f, arg0->position[2]);
    func_800A516C(sp3C, sp24, sp30);
    func_800E39D8(sp30, sp3C);
}

void func_80801290_chfantasyeyeball(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800A50B0(s32);
    u32 func_800F54E4(void);
    s32 func_800F7B9C(s32, s32);
    s32 func_800F82D4(s32, s32);

    _subaddieDll_entrypoint_4(arg0, 1);
    arg0->unk58 = 2.708f;
    arg0->unk64_19 = 1;
    if (arg2 == 0) {
        func_800F7B9C(func_800F54E4(), 0x6B);
        func_800A50B0(1);
        func_800F82D4(func_800F54E4(), 2);
    }
}

/* extern */

void func_80801314_chfantasyeyeball(void *arg0) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800A50B0(s32);
    u32 func_800F54E4(void);
    s32 func_800F7B9C(s32, s32);
    s32 func_800F82D4(s32, s32);
    func_800F82D4(func_800F54E4(), 0);
    _subaddieDll_entrypoint_4(arg0, 0);
    func_800F7B9C(func_800F54E4(), 0x6C);
    func_800A50B0(2);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFF7);
}

/* extern */

void func_80801378_chfantasyeyeball(Actor *arg0) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_800D0B68(u32, u32);
    void *func_80100094(Actor *, u32);
    void func_8010C964(u8 *);
    void func_80801740_chfantasyeyeball(Actor *, f32 *);
    void *sp1C;
    Actor *temp_v0;

    if ((func_800D0B68(0x4C, 1) == 0) && arg0->unk7C_12) {
        temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
        if (temp_v0 != NULL) {
            sp1C = temp_v0;
            func_80801740_chfantasyeyeball(arg0, temp_v0->position);
            temp_v0 = sp1C;
            temp_v0->position[1] -= 48.0f;
            func_8010C964(sp1C);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/eyeball/func_808013F8_chfantasyeyeball.s")

f32 func_808016B4_chfantasyeyeball(s32 arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    u8 *found[10];
    s32 count;
    s32 i;

    count = 0;
    for (i = _subaddiefind_entrypoint_4(0x482, found, 10) - 1; i >= 0; i--) {
        if ((s32)((Actor *)found[i])->unk70_10 < 7) {
            count++;
        }
    }
    return (f32)count * 0.5f;
}

/* extern */

void func_80801740_chfantasyeyeball(Actor *arg0, f32 *arg1) {
    void _subaddieskeleton_entrypoint_1(Actor *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_1(arg0, 4, arg1);
    } else {
        func_800EE7F8(arg1, arg0->position);
        arg1[1] += arg0->scale * 224.0f;
    }
}

/* extern */

s32 func_808017B4_chfantasyeyeball(void) {
    s32 func_8010C754();
    s32 func_8010D248();
    f32 temp_f0;

    temp_f0 = (f32) func_8010C754();
    if ((temp_f0 > 5000.0f) || (temp_f0 < 500.0f)) {
        return 0;
    }
    return func_8010D248();
}

OSThread *chfantasyeyeball_entrypoint_0(void)
{
    extern u8 D_80801F28_chfantasyeyeball[];

    return (OSThread *) D_80801F28_chfantasyeyeball;
}

void func_8080182C_chfantasyeyeball(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_80013970(f32);
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 *func_800BF340(f32[3], f32[3], f32[3], s32, f32);
    f32 func_800D8FF8(void);
    int func_800D91EC(f32 *, f32);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32[3], f32[3], f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80801BC4_chfantasyeyeball(Actor *, f32 *);
    extern s32 D_80801F70_chfantasyeyeball[];
    extern u32 D_80801FB0_chfantasyeyeball[];
    typedef struct {
    f32 position[3];
    f32 timer;
    f32 velocity[3];
    f32 amplitude;
   
    }
    EyeballData;
    f32 sp4C[3];
    f32 sp40[3];
    s32 sp3C;
    if (func_800D91EC(&((EyeballData *)arg0->actorData)->timer, 5.0f)) {
    func_80801BC4_chfantasyeyeball(arg0, NULL);
    return;
   
    }
    func_800EE7F8(sp4C, arg0->position);
    if (((EyeballData *)arg0->actorData)->timer <= arg0->unk58) {
    func_800EF174(((EyeballData *)arg0->actorData)->position, ((EyeballData *)arg0->actorData)->velocity, func_800D8FF8());
    func_800EFA4C(arg0->position, ((EyeballData *)arg0->actorData)->position[0], ((EyeballData *)arg0->actorData)->position[1] + (func_80013970(func_800F10B4(((EyeballData *)arg0->actorData)->timer, 0.0f, arg0->unk58, 0.0f, 180.0f)) * ((EyeballData *)arg0->actorData)->amplitude), ((EyeballData *)arg0->actorData)->position[2]);
   
    }
    else {
    ((EyeballData *)arg0->actorData)->velocity[1] += -2000.0f * func_800D8FF8();
    func_800EF174(arg0->position, ((EyeballData *)arg0->actorData)->velocity, func_800D8FF8());
   
    }
    if (func_800BF340(sp4C, arg0->position, sp40, 0x20020, arg0->scale * 33.0f)) {
    func_800EFB24(((EyeballData *)arg0->actorData)->position, arg0->position, sp4C);
    func_800EFDE8(((EyeballData *)arg0->actorData)->position, (u8 *)((EyeballData *)arg0->actorData)->position, sp40);
    func_800EFB24(((EyeballData *)arg0->actorData)->position, arg0->position, ((EyeballData *)arg0->actorData)->position);
    func_80801BC4_chfantasyeyeball(arg0, ((EyeballData *)arg0->actorData)->position);
    return;
   
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80801FB0_chfantasyeyeball);
    sp3C = func_800B53A4(1);
    func_800BA3FC(sp3C, func_800DC128(0, 9) + 0x9DF);
    func_800BABB8(sp3C, arg0->position, NULL, 1.0f, D_80801F70_chfantasyeyeball);
    arg0->rotation[0] += arg0->unk50 * func_800D8FF8();
    arg0->rotation[1] += arg0->unk54 * func_800D8FF8();
    }

s32 func_80801A50_chfantasyeyeball(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    void _chskeletonexplode_entrypoint_3(Actor *, s32, s32);
    void _chskeletonexplode_entrypoint_4(Actor *, s32);
    f32 func_800DC178(f32, f32);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80801BC4_chfantasyeyeball(Actor *, f32 *);
    f32 sp2C[3];
    Actor *sp28;

    switch (arg1) {
    case 0x3E:
        func_800F5A00(func_800F54E4(), sp2C);
        func_80801BC4_chfantasyeyeball(arg0, sp2C);
        return 1;
    case 0x3F:
        if (((u16 *)&(*(Unk80132ED0 **)&arg2)->unk18)[0] & 1) {
            func_80801BC4_chfantasyeyeball(arg0, func_80106790(*(Unk80132ED0 **)&arg2)->position);
            return 1;
        }
        func_80801BC4_chfantasyeyeball(arg0, NULL);
        return 1;
    case 0xF:
        sp28 = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(sp28, 3, 2);
        _chskeletonexplode_entrypoint_4(sp28, 6);
        func_800FFA88(arg0->unk0);
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 1);
        return 1;
    case 0x95:
        arg0->unk54 = func_800DC178(180.0f, 360.0f);
        arg0->unk50 = func_800DC178(180.0f, 360.0f);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        ((f32 *)arg0->actorData)[3] = 0.0f;
        return 1;
    default:
        return 0;
    }
}

void func_80801BC4_chfantasyeyeball(Actor *arg0, f32 *arg1) {
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4140(s32, f32 *, s32);
    extern s32 D_80801FC0_chfantasyeyeball;
    s32 temp_v0;
    f32 *var_a2;
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 8; var_s0++) {
        var_a2 = arg1 != NULL ? arg1 : arg0->position;
        temp_v0 = func_800BABB8(0, arg0->position, var_a2, 1.0f, &D_80801FC0_chfantasyeyeball);
        func_800BA3FC(temp_v0, var_s0 + 0x9DF);
        func_800BA22C(temp_v0, 3);
    }
    if (arg1 != NULL) {
        var_a2 = arg1;
    } else {
        var_a2 = arg0->position;
    }
    _chskeletonexplode_entrypoint_7(arg0, var_a2);
    func_800C4140(0x7FFF441F, arg0->position, 0x04B000FA);
}

OSThread *chfantasyeyeball_entrypoint_1(void)
{
    extern u8 D_80802008_chfantasyeyeball[];

    return (OSThread *) D_80802008_chfantasyeyeball;
}
