#include "common.h"

void func_80800000_chstoneballcontrol(Unk80132ED0 **arg0, u32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2 | 0xE, (f32 *)((s8 *)arg0 + 4), 0x33);
}

f32 func_80800040_chstoneballcontrol(void *arg0) {
    void *func_80100094(Actor *, u32);
    extern f32 D_80804FFC_chstoneballcontrol[];
    return D_80804FFC_chstoneballcontrol[*((u8 *)func_80100094(arg0, 0) + 0x14)];
}

/* extern */

f32 func_80800070_chstoneballcontrol(void) {
    f32 func_80800040_chstoneballcontrol();
    return func_80800040_chstoneballcontrol() * 0.75f;
}

/* extern */

f32 func_8080009C_chstoneballcontrol() {
    f32 func_80800040_chstoneballcontrol();
    return func_80800040_chstoneballcontrol() * 0.33f;
}

/* extern */

f32 func_808000C8_chstoneballcontrol(void *arg0) {
    return func_80800040_chstoneballcontrol(arg0) * 0.05f;
}

f32 func_808000F4_chstoneballcontrol(void *arg0)
{
    return func_808000C8_chstoneballcontrol(arg0);
}

s32 func_80800114_chstoneballcontrol(s32 arg0, s32 arg1) {
    extern s32 D_80805038_chstoneballcontrol[][4];
    return D_80805038_chstoneballcontrol[arg0][arg1];
}

s32 func_80800130_chstoneballcontrol(s32 arg0) {
    extern s32 D_80805088_chstoneballcontrol[];
    return ((s32 *)&D_80805088_chstoneballcontrol)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800144_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800210_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800360_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080079C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800908_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800B4C_chstoneballcontrol.s")

void func_80800BCC_chstoneballcontrol(u8 *arg0, s32 arg1) {
    typedef struct { f32 v[3]; } Vec3;
    f32 func_800DC178(f32, f32);
    s32 func_800EE780(u8 *, u8 *, s32 *);
    s32 func_800EFCD8(s32 *, f32, s32);
    f32 func_80102D78(u8 *);
    s32 func_80800B4C_chstoneballcontrol(u8 *, s32);
    f32 func_8080009C_chstoneballcontrol();
    extern Vec3 D_808050B0_chstoneballcontrol;
    Vec3 sp2C = D_808050B0_chstoneballcontrol;
    f32 var_f2;
    f32 sp24;

    if (arg1 == 0) {
        var_f2 = (*(f32 *)((s8 *)(arg0) + (0x48))) + func_800DC178(110.0f, 250.0f);
    } else {
        sp24 = func_80102D78(arg0);
        var_f2 = func_800DC178(110.0f, 250.0f) + sp24;
    }
    func_800EFCD8((s32 *)&sp2C, var_f2, 0x43FA0000);
    func_800EE780(arg0 + 0x18, arg0 + 4, (s32 *)&sp2C);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_8080009C_chstoneballcontrol(arg0);
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = -720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = -720.0f;
    }
    (*(f32 *)((s8 *)(arg0) + (0x34))) = func_800DC178(0.25f, 1.0f);
    func_80800B4C_chstoneballcontrol(arg0, 7);
}

/* extern */

void func_80800D20_chstoneballcontrol(u8 *arg0) {
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    s32 func_80800B4C_chstoneballcontrol(u8 *, s32);
    Actor *actor = (Actor *)arg0;
    ((f32 *)actor->actorData)[3] = func_8080009C_chstoneballcontrol();
    ((f32 *)actor->actorData)[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        ((f32 *)actor->actorData)[7] = -((f32 *)actor->actorData)[7];
    }
    func_80800B4C_chstoneballcontrol(arg0, 9);
    actor->unk64_20 = 1;
}

void func_80800DB4_chstoneballcontrol(void *arg0, f32 *arg1) {
    s32 _sukickball_entrypoint_6(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    int func_800F0064(f32 *, f32, f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F7B9C(s32, u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct {
        u8 pad[0x3A];
        u8 count;
    } *data;
    f32 position[4];
    s32 i;
    Actor *actor;

    data = func_80100094(arg0, 0);
    for (i = 0; i < data->count; i++) {
        if (_sukickball_entrypoint_6(arg0, i)) {
            func_800F5A00(i, position);
            if (func_800F0064(position, 200.0f, arg1)) {
                func_800F7B9C(i, 0x38);
            }
        } else {
            actor = func_80106790(_sukickball_entrypoint_8(arg0, i));
            if (func_800F0064(actor->position, 200.0f, arg1)) {
                func_80800D20_chstoneballcontrol((u8 *)actor);
            }
        }
    }
}

void func_80800EBC_chstoneballcontrol(s32 arg0, s32 arg1) {
    struct player_state_s;
    struct player_state_s *func_800F53D0(s32);
    void func_800F82D4(s32, s32);
    void _baattach_entrypoint_6(struct player_state_s *, s32, s32, s32);
    switch (arg1) {
        case 0:
            func_800F82D4(arg0, 0);
            break;
        case 1:
            func_800F82D4(arg0, 2);
            _baattach_entrypoint_6(func_800F53D0(arg0), 3, 0, 0);
            break;
    }
}

/* extern */

void func_80800F24_chstoneballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_800D395C(void);
    if ((arg1 != 0) || (func_800D395C() != 0)) {
        arg0->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18AF, arg2 + 0xF, 0, 0);
        return;
    }
    arg0->unk64_19 = 0;
    _chintrotext_entrypoint_2(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800F9C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080120C_chstoneballcontrol.s")

void func_8080128C_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[0x10];
        s32 words[9];
        u8 bytes[6];
        u8 count;
    } *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_v1 = 0; var_v1 < temp_v0->count; var_v1++) {
        temp_v0->bytes[var_v1] = 0;
        temp_v0->words[var_v1] = 0;
    }
}

void func_808012E0_chstoneballcontrol(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad0[0x64];
        u8 unused : 7;
        u8 active : 1;
        u8 pad1[9];
        u16 high : 7;
        u16 state : 9;
    };
    struct Fields *p = arg0;
    p->state = arg1;
    if (arg1 == 2) {
        p->active = 1;
    } else {
        p->active = 0;
    }
}

s32 func_80801320_chstoneballcontrol(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801330_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080145C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801638_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801734_chstoneballcontrol.s")

void func_808017AC_chstoneballcontrol(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800B4C_chstoneballcontrol(u8 *, s32);
    void *actor;

    actor = func_80106790(arg0);
    switch (arg1) {
        case 0:
            func_80800B4C_chstoneballcontrol(actor, 2);
            return;
        case 1:
            func_80800B4C_chstoneballcontrol(actor, 0xB);
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801808_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801884_chstoneballcontrol.s")

OSThread *chstoneballcontrol_entrypoint_0(void)
{
    extern u8 D_808050D4_chstoneballcontrol[];

    return (OSThread *) D_808050D4_chstoneballcontrol;
}

void func_80801944_chstoneballcontrol(u8 *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_3(Actor *);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800F4F98(s32, void *);
    void *func_80100094(Actor *, u32);
    s32 func_80101FDC(u8 *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808024F8_chstoneballcontrol(Actor *);
    void func_80802588_chstoneballcontrol(Actor *volatile, volatile s32);
    extern u8 D_8080511C_chstoneballcontrol[];
    u8 *data;
    s32 linked;
    u32 kind;
    u32 state;

    data = func_80100094(arg0, 0);
    state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
    if (state == 2 && arg1 != state) {
        linked = *(s32 *)(arg0 + 0x3C);
        if (linked != 0) {
            if (_sukickball_entrypoint_6(func_80106790(linked), data[0x20])) {
                func_800F4F98(data[0x20], *(void **)arg0);
            }
            _sukickball_entrypoint_11(func_80106790(*(s32 *)(arg0 + 0x3C)), data[0x20]);
            state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
        }
    }
    if (state == 3 && arg1 == 2 && (*(u32 *)(*(u8 **)arg0 + 0x24) >> 22) == 0x253) {
        *(f32 *)(data + 0x14) = 20.0f;
        *(f32 *)(data + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(arg0);
        func_808024F8_chstoneballcontrol(arg0);
        arg1 = 4;
    }
    func_80101FDC(arg0, arg1);
    if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 6) {
        func_808024F8_chstoneballcontrol(arg0);
        _subaddiefade_entrypoint_3(arg0);
        func_800B4470(arg0 + 4, 0, D_8080511C_chstoneballcontrol, 1, 0.75f, 0.0f, 0x7D, 0xFA, 0);
        kind = *(u32 *)(*(u8 **)arg0 + 0x24) >> 22;
        if (kind != 0x254) {
            if (kind == 0x267) {
                func_80802588_chstoneballcontrol(arg0, 1);
            }
        } else {
            func_80802588_chstoneballcontrol(arg0, 2);
        }
    }
}

void func_80801B00_chstoneballcontrol(u8 *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    *(s8 *)(data + 0x20) = 0x7F;
    *(f32 *)(data + 4) = 0.0f;
    *(f32 *)data = 0.0;
    *(f32 *)(arg0 + 0x24) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801B44_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801BE0_chstoneballcontrol.s")

/* extern */

void func_808023AC_chstoneballcontrol(u8 *volatile arg0) {
    s32 func_800EA05C();
    s32 func_808026A0_chstoneballcontrol();
    void func_8080282C_chstoneballcontrol(u8 *, s32);
    s32 sp1C[1];
    s32 map;
    s32 kind;
    u8 *data;

    sp1C[0] = func_808026A0_chstoneballcontrol();
    map = func_800EA05C();
    data = arg0;
    kind = sp1C[0];
    if (map != 0xBB) {
        *(f32 *)(data + 8) = 30.0f;
    } else {
        *(f32 *)(data + 8) = -320.0f;
    }
    if (kind != -1) {
        func_8080282C_chstoneballcontrol(data, kind);
    }
}

void func_80802418_chstoneballcontrol(Actor *arg0) {
    arg0->position[1] -= 5.0f;
    arg0->alpha = (u32)arg0->alpha * 0.7f;
    arg0->scale *= 0.95f;
}

void func_808024F8_chstoneballcontrol(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802648_chstoneballcontrol(f32 *);
    void func_80802F14_chstoneballcontrol(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    extern s32 D_80804FD4_chstoneballcontrol;
    Actor *sp24;

    sp24 = func_80106790(arg0->unk3C);
    if ((arg0->unk0->unk24 >> 22) == 0x253) {
        func_80802648_chstoneballcontrol(arg0->position);
        func_80802F14_chstoneballcontrol(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804FD4_chstoneballcontrol);
        _subaddiefade_entrypoint_3(arg0);
        func_80801944_chstoneballcontrol(arg0, 4);
        func_80800DB4_chstoneballcontrol(sp24, arg0->position);
    }
}

void func_80802588_chstoneballcontrol(Actor *volatile arg0, volatile s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80805134_chstoneballcontrol;
    extern s32 D_80804FE8_chstoneballcontrol;
    s32 emitter;
    s32 model;
    f32 *position;

    position = arg0->position;
    emitter = func_800BABB8(0, position, NULL, 1.0f, &D_80805134_chstoneballcontrol);
    model = (arg1 == 1) ? 0x679 : 0x67A;
    func_800BA670(emitter, model);
    func_800BA22C(emitter, 0xA);
    _subaddieaudioquick_entrypoint_2(arg0, position, &D_80804FE8_chstoneballcontrol);
}

void func_80802614_chstoneballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_80805178_chstoneballcontrol;
    func_800BBCB8(arg0, 0, 1.0f, 2, &D_80805178_chstoneballcontrol);
}

void func_80802648_chstoneballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_808051C0_chstoneballcontrol;
    extern s32 D_80805210_chstoneballcontrol;
    func_800BBCB8(arg0, 0, 1.0f, 0xA, &D_808051C0_chstoneballcontrol);
    func_800BBCB8(arg0, 0, 1.0f, 5, &D_80805210_chstoneballcontrol);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808026A0_chstoneballcontrol.s")

void func_8080282C_chstoneballcontrol(u8 *arg0, s32 arg1) {
    s32 func_800EA05C();
    void func_80802FBC_chstoneballcontrol(u8 *, s32);

    if (func_800EA05C() != 0xBB) {
        switch (arg1) {
        case 0:
            if ((*(f32 *)(arg0 + 0xC) > -183.0f) && (*(f32 *)(arg0 + 0xC) < 183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 4) > 720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 0);
                }
                if (*(f32 *)(arg0 + 4) > 801.0f) {
                    *(f32 *)(arg0 + 4) = 846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 4) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 1:
            if ((*(f32 *)(arg0 + 4) < 183.0f) && (*(f32 *)(arg0 + 4) > -183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 0xC) > 720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 1);
                }
                if (*(f32 *)(arg0 + 0xC) > 801.0f) {
                    *(f32 *)(arg0 + 0xC) = 846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 2:
            if ((*(f32 *)(arg0 + 0xC) < 183.0f) && (*(f32 *)(arg0 + 0xC) > -183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 4) < -720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 2);
                }
                if (*(f32 *)(arg0 + 4) < -801.0f) {
                    *(f32 *)(arg0 + 4) = -846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 4) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 3:
            if ((*(f32 *)(arg0 + 4) > -183.0f) && (*(f32 *)(arg0 + 4) < 183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 0xC) < -720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 3);
                }
                if (*(f32 *)(arg0 + 0xC) < -801.0f) {
                    *(f32 *)(arg0 + 0xC) = -846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        }
    } else {
        if ((*(f32 *)(arg0 + 4) > -1145.0f) || (*(f32 *)(arg0 + 4) < -3255.0f) ||
            (*(f32 *)(arg0 + 0xC) > -745.0f) || (*(f32 *)(arg0 + 0xC) < -1255.0f)) {
            *(f32 *)(arg0 + 0x24) = 0.0f;
            func_80801944_chstoneballcontrol(arg0, 6);
        }
    }
}

void func_80802C30_chstoneballcontrol(s32 *arg0) {
    typedef struct { u8 pad[0x1A]; u16 index; u8 pad1[8]; u32 id:10; u32 flags:22; } Marker;
    typedef struct { Marker *marker; s32 unk4; u32 flags; } Entry;
    s32 *func_800BE3F8(void *);
    Entry *func_800E9E88(s32);
    Entry *func_800E9EB4(s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802D9C_chstoneballcontrol(s32 *, u8 *);
    void func_80802E30_chstoneballcontrol(Actor *, u32);
    void func_80802EA0_chstoneballcontrol(s32 *, u8 *);
    s32 *list;
    Entry *entry;
    Entry *end;
    Marker *marker;

    list = func_800BE3F8(arg0 + 1);
    while (*list != 0) {
        entry = func_800E9E88(*list);
        end = func_800E9EB4(*list);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                marker = entry->marker;
                if (marker != (Marker *)*arg0) {
                    if (marker->id == 0x267 || marker->id == 0x253 || marker->id == 0x254) {
                        func_80802D9C_chstoneballcontrol(arg0, func_80106790((s32)marker));
                    }
                    if (marker->id == 0) {
                        func_80802E30_chstoneballcontrol(arg0, (u32)marker->index >> 5);
                    }
                    if (marker->id == 0x237) {
                        func_80802EA0_chstoneballcontrol(arg0, func_80106790((s32)marker));
                    }
                }
            }
        }
        list++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802D9C_chstoneballcontrol.s")

void func_80802E30_chstoneballcontrol(Actor *arg0, u32 arg1) {
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_13(f32 *, f32 *, f32);
    void func_800F5A00(s32, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *parent;
    f32 sp18[3];

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 2 && _sukickball_entrypoint_12((u8 *)parent, arg1)) {
        func_800F5A00(arg1, sp18);
        _sukickball_entrypoint_13(sp18, arg0->position, 60.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802EA0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802F14_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802FBC_chstoneballcontrol.s")

void chstoneballcontrol_entrypoint_1(Unk80132ED0 *arg0, s32 arg1, u32 arg2, s32 arg3) {
    typedef struct { f32 unknown; f32 timer; } ControlData;
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80803538_chstoneballcontrol(u8 *);
    void *actor;
    ControlData *data;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    if (arg1 != 1) {
        if (arg1 == 3) {
            func_80801944_chstoneballcontrol(actor, 1);
        }
    } else {
        data->timer = func_800D8FF8() * arg2;
        func_80803538_chstoneballcontrol(actor);
    }
}

void func_80803148_chstoneballcontrol(u8 *arg0) {
    typedef struct { f32 v[4]; } Distances;
    typedef struct { f32 v[3]; } Position;
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    typedef struct { u8 pad[0x3A]; u8 count; } ParentData;
    typedef struct { u8 pad[0x24]; u32 id:10; u32 flags:22; } MarkerState;
    typedef struct { u8 pad[0x70]; u32 upper:16; u32 state:6; u32 flags:10; } ActorState;
    extern Distances D_808052B0_chstoneballcontrol;
    extern Position D_808052C0_chstoneballcontrol;
    extern void _chstoneballcontrol_entrypoint_1(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    void _sukickball_entrypoint_10(u8 *, s32, s32);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800F4950(s32, void *, void (*)(void));
    void func_800F4F98(s32, void *);
    s32 func_800F5410(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6C5C(s32);
    BallData *data = func_80100094(arg0, 0);
    f32 distances[4];
    u8 *parent;
    ParentData *parentData;
    f32 closest;
    s32 selected;
    s32 i;

    *(Distances *)distances = D_808052B0_chstoneballcontrol;
    parent = func_80106790(*(s32 *)(arg0 + 0x3C));
    parentData = func_80100094(parent, 0);
    if ((((ActorState *)parent)->state == 4 ||
         ((ActorState *)parent)->state == 7) &&
        (0.0f == data->timer || ((ActorState *)arg0)->state == 1)) {
        selected = 0x7F;
        closest = 10000000.0f;
        for (i = 0; i < parentData->count; i++) {
            if ((((ActorState *)arg0)->state != 2 || i != data->owner) &&
                !_sukickball_entrypoint_12(parent, i)) {
                f32 position[3];
                *(Position *)position = D_808052C0_chstoneballcontrol;
                if (_sukickball_entrypoint_6(parent, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, position);
                        if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                            distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                        }
                    }
                } else {
                    func_800EE7F8(position, func_80106790(_sukickball_entrypoint_8(parent, i))->position);
                    if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                        distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                    }
                }
            }
        }
        for (i = 0; i < parentData->count; i++) {
            if (((ActorState *)arg0)->state == 2 && i == data->owner) {
                continue;
            }
            if (distances[i] < closest) {
                closest = distances[i];
                selected = i;
            }
        }
        if (selected != 0x7F) {
            if (data->owner != 0x7F) {
                if (_sukickball_entrypoint_7(parent, data->owner)) {
                    _sukickball_entrypoint_11(parent, data->owner);
                } else {
                    func_800F4F98(data->owner, *(void **)arg0);
                    _sukickball_entrypoint_11(parent, data->owner);
                }
            }
            data->owner = selected;
            data->timer = 1.5f;
            if (_sukickball_entrypoint_6(parent, data->owner)) {
                func_800F4950(data->owner, *(void **)arg0, _chstoneballcontrol_entrypoint_1);
            } else {
                u8 *player = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                player[0x65] &= ~0x10;
            }
            switch ((*(MarkerState **)arg0)->id) {
                case 0x267:
                    _sukickball_entrypoint_10(parent, data->owner, 1);
                    break;
                case 0x253:
                    _sukickball_entrypoint_10(parent, data->owner, 3);
                    break;
                case 0x254:
                    _sukickball_entrypoint_10(parent, data->owner, 2);
                    break;
            }
            func_80801944_chstoneballcontrol(arg0, 2);
            *(f32 *)(arg0 + 0x24) = 0.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803538_chstoneballcontrol.s")

void func_8080367C_chstoneballcontrol(s32 arg0)
{
    func_80801944_chstoneballcontrol(arg0,0);
}

OSThread *chstoneballcontrol_entrypoint_2(void)
{
    extern u8 D_808052CC_chstoneballcontrol[];

    return (OSThread *) D_808052CC_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_3(void)
{
    extern u8 D_80805314_chstoneballcontrol[];

    return (OSThread *) D_80805314_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_4(void)
{
    extern u8 D_8080535C_chstoneballcontrol[];

    return (OSThread *) D_8080535C_chstoneballcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808036C0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803724_chstoneballcontrol.s")

s32 func_80803FF4_chstoneballcontrol(s32 arg0, s32 arg1) {
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    s32 choice = arg0;

    switch (arg1) {
        case 0:
            if (func_800DC298(0.1499938965f)) {
                return 0;
            }
            break;
        case 1:
            if (func_800DC298(0.2249908447f)) {
                return 0;
            }
            break;
        case 2:
            if (func_800DC298(0.299987793f)) {
                return 0;
            }
            break;
    }
    while (choice == arg0) {
        choice = func_800DC128(1, 4);
    }
    return choice;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808040B8_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080419C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804218_chstoneballcontrol.s")

void func_80804304_chstoneballcontrol(u8 *arg0) {
    typedef struct { f32 v[3]; } Vec3;
    typedef struct { u8 high:3; u8 active:1; u8 low:4; } BallFlags;
    extern Vec3 D_8080541C_chstoneballcontrol;
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_13(f32 *, f32 *, f32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800EEF94(f32 *);
    s32 func_800EF1B8(f32 *, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_800F52B8(s32, Unk80132ED0 *);
    void func_800F5A00(s32, f32 *);
    void func_800F5D70(s32, f32 *);
    void func_800F7700(s32, s32, f32 *);
    s32 func_800F8294(s32, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_80102D78();
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800B4C_chstoneballcontrol(u8 *, s32);
    s32 i;
    u8 *parent;
    u8 *other;
    u8 *parentData;
    f32 *selfPosition;
    f32 position[3];
    f32 selfSpeed;
    f32 speed;
    f32 velocity[3];

    other = NULL;
    parentData = func_80100094(func_80106790(*(s32 *)(arg0 + 0x3C)), 0);
    for (i = 0; i < parentData[0x3A]; i++) {
        selfPosition = (f32 *)(arg0 + 4);
        if (i != (*(s32 *)(arg0 + 0x6C) & 0x1FF)) {
            parent = func_80106790(*(s32 *)(arg0 + 0x3C));
            if (_sukickball_entrypoint_7(parent, i)) {
                other = func_80106790(_sukickball_entrypoint_8(parent, i));
                position[0] = *(f32 *)(other + 4);
                position[1] = *(f32 *)(other + 8);
                position[2] = *(f32 *)(other + 0xC);
            } else {
                func_800F5A00(i, position);
            }
            if (func_800EFFB4(selfPosition, 90.0f, position)) {
                selfSpeed = func_800EEF94((f32 *)(arg0 + 0x28));
                if (_sukickball_entrypoint_6(parent, i)) {
                    func_800F5D70(i, velocity);
                    speed = func_800EEF94(velocity) * func_800D8FF8();
                } else {
                    speed = func_800EEF94((f32 *)(other + 0x28)) * func_800D8FF8();
                }
                if (speed < selfSpeed) {
                    if (_sukickball_entrypoint_6(parent, i)) {
                        _sukickball_entrypoint_13(selfPosition, position, 60.0f);
                        func_800F8294(i, position);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            Vec3 impulse = D_8080541C_chstoneballcontrol;
                            f32 playerPosition[3];
                            func_800F5A00(i, playerPosition);
                            func_800EF1B8((f32 *)&impulse, func_80102D78(arg0, playerPosition), 150.0f);
                            func_800F7700(i, 3, selfPosition);
                        }
                    } else {
                        f32 *otherPosition = (f32 *)(other + 4);
                        _sukickball_entrypoint_13(selfPosition, otherPosition, 60.0f);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            *(f32 *)(other + 0x58) = 1.5f;
                            ((BallFlags *)(other + 0x65))->active = 1;
                            func_80800B4C_chstoneballcontrol(other, 12);
                            *(f32 *)(other + 0x24) = *(f32 *)(arg0 + 0x24) * 0.75f;
                            *(f32 *)(other + 0x54) = func_80102D78(arg0, otherPosition);
                            *(f32 *)(arg0 + 0x24) *= 0.5f;
                        }
                    }
                } else {
                    _sukickball_entrypoint_13(position, selfPosition, 60.0f);
                    if (func_800DC0C0() < 0.5f && !_sukickball_entrypoint_12(parent, *(s32 *)(arg0 + 0x6C) & 0x1FF)) {
                        func_80800BCC_chstoneballcontrol(arg0, (s32)position);
                    }
                    if (_sukickball_entrypoint_6(parent, i) && func_800F52B8(i, *(Unk80132ED0 **)arg0) == 2) {
                        f32 secondPosition[3];
                        func_800F5A00(i, secondPosition);
                        *(f32 *)(arg0 + 0x54) = func_800F1DF4(secondPosition, selfPosition);
                        func_80800B4C_chstoneballcontrol(arg0, 12);
                        *(f32 *)(arg0 + 0x24) = (speed * 0.75f) / func_800D8FF8();
                    }
                    *(f32 *)(arg0 + 0x58) = 1.5f;
                    ((BallFlags *)(arg0 + 0x65))->active = 1;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808046C4_chstoneballcontrol.s")

void func_808047E8_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800BD09C();
    void **data = func_80100094(arg0, 0);
    func_800BD09C(*data);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804810_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804B60_chstoneballcontrol.s")

void func_80804D40_chstoneballcontrol(void *arg0) {
    if ((*(f32 *)((s8 *)(arg0) + (0x24))) < func_80800040_chstoneballcontrol(arg0)) {
        *(f32 *)((s8 *)arg0 + 0x24) += func_808000C8_chstoneballcontrol(arg0);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_80800040_chstoneballcontrol(arg0);
}

void func_80804DA0_chstoneballcontrol(void *arg0) {
    if (func_8080009C_chstoneballcontrol(arg0) < *(f32 *)((s8 *)arg0 + 0x24)) {
        *(f32 *)((s8 *)arg0 + 0x24) -= func_808000F4_chstoneballcontrol(arg0);
    }
}

OSThread *chstoneballcontrol_entrypoint_5(void)
{
    extern u8 D_80805434_chstoneballcontrol[];

    return (OSThread *) D_80805434_chstoneballcontrol;
}
