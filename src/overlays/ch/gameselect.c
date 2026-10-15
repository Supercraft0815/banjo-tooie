#include "common.h"

typedef struct { u8 data[0x260]; } OptionState;
u32 _gcnewoption_entrypoint_37(OptionState *, u32);

OSThread *chgameselect_entrypoint_0(void)
{
    extern u8 D_80807FD8_chgameselect[];

    return (OSThread *) D_80807FD8_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080000C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080015C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800228_chgameselect.s")

void func_80800440_chgameselect(void *arg0) {
    void func_808036D8_chgameselect(void);
    void *mem;

    func_808036D8_chgameselect();
    mem = *(void **)((u8 *)arg0 + 0x50);
    if (mem != NULL) {
        heap_free(mem);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800478_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808005D4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808006A0_chgameselect.s")

/* extern */

void func_8080086C_chgameselect(Actor *arg0, s32 arg1) {
    s32 func_80800478_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    switch (arg0->unk70_10) {
    case 1:
        func_80803D00_chgameselect(0, 3);
        return;
    default:
    case 3:
    case 4:
        func_80800478_chgameselect(arg0, 1);
        /* fallthrough */
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return;
    }
}

void func_808008D0_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        s32 (*callback)(Actor *, s32, s32);
        u8 pad4[0x30];
    } GameSelectCallback;
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    extern GameSelectCallback D_80807DE0_chgameselect[];
    s32 (*temp_v0)(Actor *, s32, s32);
    s32 var_a3;
    Actor **actor = &arg0;

    var_a3 = -1;
    temp_v0 = D_80807DE0_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        var_a3 = temp_v0(arg0, arg1, arg2);
    }
    if (var_a3 != -1) {
        func_808026C8_chgameselect((Unk80132ED0 *)(*actor)->actorData[5], var_a3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800944_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800998_chgameselect.s")

void func_808009EC_chgameselect(Actor *arg0) {
    typedef struct {
        void (*callback)(void);
        u8 pad4[0x30];
    } GameSelectCallback;
    s32 func_80800478_chgameselect(s32, s32);
    extern GameSelectCallback D_80807DEC_chgameselect[];
    void (*temp_v0)(void);

    temp_v0 = D_80807DEC_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        temp_v0();
        return;
    }
    func_80800478_chgameselect(arg0, 1);
}

void func_80800A4C_chgameselect(Actor *arg0) {
    typedef struct {
        void (*callback)(void);
        u8 pad4[0x30];
    } GameSelectCallback;
    extern GameSelectCallback D_80807DFC_chgameselect[];
    void (*temp_v0)(void);

    temp_v0 = D_80807DFC_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        temp_v0();
    }
}

void func_80800A9C_chgameselect(Actor *arg0) {
    typedef struct {
        void (*callback)(void);
        u8 pad4[0x30];
    } GameSelectCallback;
    extern GameSelectCallback D_80807E00_chgameselect[];
    void (*temp_v0)(void);

    temp_v0 = D_80807E00_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        temp_v0();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800AEC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800CA0_chgameselect.s")

s32 func_80800D3C_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(arg0)->unk70_10 != 9;
}

OSThread *chgameselect_entrypoint_1(void)
{
    extern u8 D_80808038_chgameselect[];

    return (OSThread *) D_80808038_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800D74_chgameselect.s")

void func_80800E24_chgameselect(void *arg0) {
    typedef struct {
        u8 pad0[0x34];
        f32 fade;
        u8 pad38[4];
        Unk80132ED0 *handle;
        u8 pad40[0x18];
        f32 timer;
        u8 pad5C[8];
        u32 pad64 : 11;
        u32 flag20 : 1;
        u32 flag19 : 1;
        u32 pad64low : 19;
        u32 pad68;
        u32 pad6C : 23;
        u32 state : 9;
        u8 pad70[9];
        u8 selection : 4;
        u8 pad79 : 4;
        u8 pad7A[2];
        u32 pad7C : 19;
        u32 flag12 : 1;
        u32 pad7Clow : 12;
    } SelectActor;
    typedef struct {
        u8 pad0[0x60];
        f32 entries[8][3];
        u8 enabled[8];
    } SelectData;
    void func_80016068(u32, f32 *);
    s32 func_80016B30(s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(Unk80132ED0 *, s32, s32);
    s32 func_80800D3C_chgameselect(Unk80132ED0 *);
    void func_80801338_chgameselect(void *, s32);
    void func_808013C8_chgameselect(void *, s32);
    s32 func_808014F0_chgameselect(void *, void *);
    f32 mlAbsF(f32);
    SelectData *data;
    f32 delta;
    f32 vertical;
    f32 horizontal;
    f32 magnitude;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    if (func_80800D3C_chgameselect(((SelectActor *)arg0)->handle)) {
        if (((SelectActor *)arg0)->timer >= 0.0f) {
            ((SelectActor *)arg0)->timer -= delta;
        }
        if (!((SelectActor *)arg0)->flag19 && ((SelectActor *)arg0)->timer <= 0.0f) {
            func_80016068(0, &horizontal);
            magnitude = mlAbsF(horizontal);
            if (mlAbsF(vertical) < magnitude) {
                vertical = 0.0f;
            } else {
                horizontal = 0.0f;
            }
            if (horizontal < -0.1f && (((SelectActor *)arg0)->selection & 3)) {
                func_80801338_chgameselect(arg0, -1);
            } else if (horizontal > 0.1f && (((SelectActor *)arg0)->selection & 3) != 3) {
                func_80801338_chgameselect(arg0, 1);
            }
            if (vertical < -0.1f && (((SelectActor *)arg0)->selection & 4) != 4) {
                func_808013C8_chgameselect(arg0, ((SelectActor *)arg0)->selection + 4);
            } else if (vertical > 0.1f && (((SelectActor *)arg0)->selection & 4)) {
                func_808013C8_chgameselect(arg0, ((SelectActor *)arg0)->selection - 4);
            }
        }
        if (func_800DA298(0x64A)) {
            if (func_80016B30(0, 1) == 1) {
                func_8010114C(((SelectActor *)arg0)->handle, 8, ((SelectActor *)arg0)->selection);
            } else if (func_80016B30(0, 0) == 1) {
                func_8010114C(((SelectActor *)arg0)->handle, 7, ((SelectActor *)arg0)->selection);
            }
        }
        if (((SelectActor *)arg0)->state == 1 && ((SelectActor *)arg0)->flag12) {
            if (data->enabled[((SelectActor *)arg0)->selection] &&
                func_808014F0_chgameselect(arg0, data->entries[((SelectActor *)arg0)->selection])) {
                ((SelectActor *)arg0)->timer = 0.0f;
            }
        }
        if (((SelectActor *)arg0)->flag19 && !((SelectActor *)arg0)->flag20) {
            if (((SelectActor *)arg0)->fade > 0.0f) {
                delta = func_800D8FF8();
                ((SelectActor *)arg0)->fade = ((SelectActor *)arg0)->fade - 1 * delta;
                if (((SelectActor *)arg0)->fade < 0.0f) {
                    ((SelectActor *)arg0)->fade = 0.0f;
                }
            }
        } else if (((SelectActor *)arg0)->fade < 1.0f) {
            delta = func_800D8FF8();
            ((SelectActor *)arg0)->fade = ((SelectActor *)arg0)->fade + 1 * delta;
            if (((SelectActor *)arg0)->fade > 1.0f) {
                ((SelectActor *)arg0)->fade = 1.0f;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808011B4_chgameselect.s")

void func_808012E4_chgameselect(Actor *arg0, u8 *arg1) {
    void _subaddiefade_entrypoint_8(Actor*, s32);
    void func_80101870(Actor* arg0, void* arg1);
    s32 temp_f10;

    temp_f10 = (s32) (*(f32 *) ((s8 *) arg0 + 0x34) * 255.0f);
    if (temp_f10 != 0) {
        _subaddiefade_entrypoint_8(arg0, temp_f10);
        func_80101870(arg0, arg1);
    }
}

/* extern */

void func_80801338_chgameselect(void *arg0, s32 arg1) {
    void func_808013C8_chgameselect(void *, s32);
    s32 temp_v1;
    s32 var_a2;
    s32 var_a3;

    temp_v1 = ((Actor *)arg0)->actorData[0];
    var_a2 = ((Actor *)arg0)->unk79_4 + arg1;
    var_a3 = ((Actor *)arg0)->unk79_4 & 3;
    if ((temp_v1 != 0) && ((var_a2 + 1) == temp_v1)) {
        var_a3 = var_a2 & 3;
        if (arg1 == 0) {
            arg1 = var_a2 == 0 ? 1 : -1;
        }
        var_a2 += arg1;
    }
    if ((arg1 < 0) && (var_a3 != 0)) {
        func_808013C8_chgameselect(arg0, var_a2);
        return;
    }
    if ((arg1 > 0) && (var_a3 != 3)) {
        func_808013C8_chgameselect(arg0, var_a2);
    }
}

/* extern */

void func_808013C8_chgameselect(void *arg0, s32 arg1) {
    s32 func_80101238(s32, s32);
    void func_80102424(Actor *, s32);

    if (!((Actor *)arg0)->unk64_20 || (arg1 < 3)) {
        ((Actor *)arg0)->unk79_4 = arg1;
        func_80101238(0xA, ((Actor *)arg0)->unk79_4);
        ((Actor *)arg0)->unk6C_0 = 1;
        func_80102424(arg0, 1);
        ((Actor *)arg0)->unk58 = 0.5f;
    }
}

/* extern */

void func_8080145C_chgameselect(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    void func_800E3980(f32 *);
    void func_800EE7B4(f32[3], f32[3], f32[3], f32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF3DC(f32[3], f32[3]);
    f32 sp1C[3];
    f32 temp_f0;

    func_800E3980(sp1C);
    func_800EF3DC(sp1C, arg3);
    temp_f0 = func_800EEAA4(sp1C, arg0);
    if (temp_f0 != 0.0f) {
        temp_f0 = (arg1 - func_800EEAA4(arg3, arg0)) / temp_f0;
        func_800EE7B4(arg2, arg3, sp1C, temp_f0);
    }
}

/* extern */

s32 func_808014F0_chgameselect(void *arg0, void *arg1) {
    void _subaddieskeleton_entrypoint_1(Actor *, s32, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EF174(f32[3], f32[3], f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 sp3C[3];
    f32 sp30[3];
    s32 var_v1;
    f32 sp28;

    _subaddieskeleton_entrypoint_1(arg0, 5, sp30);
    func_800EFB24(sp3C, arg1, sp30);
    sp28 = func_800EEF94(sp3C);
    if (sp28 != 0.0f) {
        func_800EF174((f32 *)arg0 + 1, sp3C, func_800FF060(sp28, (f32 *)arg0 + 9, 4000.0f, -4000.0f, 3000.0f, func_800D8FF8()) / sp28);
    }
    if (sp28 == 0.0f || ((f32 *)arg0)[9] < 0.01f) { var_v1 = 1; } else { var_v1 = 0; } return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808015DC_chgameselect.s")

 s32 func_80801658_chgameselect(s32 arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    struct Fields { u8 pad[0x65]; u8 rest : 4; u8 bit : 1; u8 low : 3; };
    actor = func_80106790((Unk80132ED0 *)arg0);
    if (arg1 != 0) {
        ((struct Fields *)actor)->bit = 1;
    } else {
        ((struct Fields *)actor)->bit = 0;
    }
}

s32 func_808016A0_chgameselect(s32 arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    struct Fields { u8 pad[0x65]; u8 rest : 3; u8 bit : 1; u8 low : 4; };
    actor = func_80106790((Unk80132ED0 *)arg0);
    if (arg1 != 0) {
        ((struct Fields *)actor)->bit = 1;
    } else {
        ((struct Fields *)actor)->bit = 0;
    }
}

void func_808016E8_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_808013C8_chgameselect(void *, s32);
    func_808013C8_chgameselect(func_80106790(arg0), arg1);
}

void func_80801714_chgameselect(Unk80132ED0 *arg0, s32 arg1) { Actor *func_80106790(Unk80132ED0 *); void func_80102424(Actor *, s32); void func_80803C80_chgameselect(void); Actor *sp1C; sp1C = func_80106790(arg0); func_80102424(sp1C, 2); sp1C->unk64_19 = 1; func_80803C80_chgameselect(); }

void func_80801758_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80801338_chgameselect(void *, s32);
    Actor *actor;

    actor = func_80106790(arg0);
    actor->actorData[0] = arg1 + 1;
    func_80801338_chgameselect(actor, 0);
}

OSThread *chgameselect_entrypoint_2(void)
{
    extern u8 D_808080C8_chgameselect[];

    return (OSThread *) D_808080C8_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080179C_chgameselect.s")

/* extern */

s32 func_80101180(s32, s32, s32);

void func_80801AC4_chgameselect(Actor *arg0) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void func_800B237C(void *, f32[3], f32 *);
    void func_80101010(s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80103C94(Actor *);
    void func_8080179C_chgameselect(Actor *);
    s32 temp_v0;
    f32 sp28[3];
    f32 sp24;

    if (!arg0->unk64_20) {
        temp_v0 = func_80103C94(arg0);
        if (temp_v0 != 0) {
            func_800B237C(temp_v0, sp28, &sp24);
            func_80101010(sp28);
            if (func_80101180(0x4AB, 0x31, arg0->unk79_4) != 0) {
                arg0->unk64_20 = 1;
            }
        }
    }
    if (_subaddiefade_entrypoint_0(arg0) < 0x64) {
        _subaddiefade_entrypoint_1(arg0, 0x64);
    }
    if ((arg0->unk70_10 != 2) && (arg0->unk70_10 != 3) && (arg0->unk70_10 == 4) && (func_80101DDC(arg0) != 0)) {
        func_80102424(arg0, 2);
    }
    func_8080179C_chgameselect(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801BA8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801D74_chgameselect.s")

/* extern */

void func_80802070_chgameselect(Actor *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);
    if (arg1 != 0) {
        if (arg0->unk70_10 != 3) {
            func_80102424(arg0, 3);
        }
    } else if (arg0->unk70_10 == 3) {
        func_80102424(arg0, 4);
    }
}

/* extern */

void func_808020CC_chgameselect(Actor *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_4(Actor *);
    s32 _subaddiefade_entrypoint_5();
    u32 temp_t0;
    u32 temp_t9;

    if (arg1 != arg0->unk64_19) {
        if (arg1 != 0) {
            temp_t9 = arg0->unk79_4;
            if ((temp_t9 != 0) && (temp_t9 != 1) && (temp_t9 != 2)) {
                _subaddiefade_entrypoint_4(arg0);
            }
        } else {
            temp_t0 = arg0->unk79_4;
            if ((temp_t0 != 0) && (temp_t0 != 1) && (temp_t0 != 2)) {
                _subaddiefade_entrypoint_5(arg0);
            }
        }
        arg0->unk64_19 = arg1;
    }
}

s32 func_8080218C_chgameselect(s32 arg0, s32 arg1) {
    union {
        s32 word;
        struct {
            s16 id;
            volatile s16 flag;
        } parts;
    } sp1C;

    sp1C.parts.id = arg0;
    if (arg1 != 0) {
        sp1C.parts.flag = 1;
    } else {
        sp1C.parts.flag = 0;
    }
    return func_80101180(0x4A8, 0x21, sp1C.word);
}

OSThread *chgameselect_entrypoint_3(void)
{
    extern u8 D_80808298_chgameselect[];

    return (OSThread *) D_80808298_chgameselect;
}

OSThread *chgameselect_entrypoint_4(void)
{
    extern u8 D_808082E0_chgameselect[];

    return (OSThread *) D_808082E0_chgameselect;
}

/* extern */

void func_808021E4_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_19(s32);
    s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
    s32 heap_alloc(s32);
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0xC8, 0xC, 2, 0, 0);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    _gczoombox_entrypoint_19(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = heap_alloc(0x40);
    (*(s32 *)((s8 *)(arg0) + (0x34))) = heap_alloc(0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802248_chgameselect.s")

void func_80802620_chgameselect(void *arg0);

void func_80802480_chgameselect(void *arg0) {
    void *temp_a0;
    void *temp_a1;

    temp_a1 = *(void **)((u8 *)arg0 + 0x24);
    if (temp_a1 != NULL) {
        heap_free(temp_a1);
    }
    temp_a0 = *(void **)((u8 *)arg0 + 0x34);
    if (temp_a0 != NULL) {
        heap_free(temp_a0);
    }
    func_80802620_chgameselect(arg0);
}

/* extern */

void func_808024D4_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_11(s32);
    s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
    s32 _gczoombox_entrypoint_9(s32);
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0x1C, 0xD, 2, 1, 0);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    _gczoombox_entrypoint_9(temp_v0);
    _gczoombox_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0x28))));
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = -1;
}

/* extern */

void func_80802530_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_3(s32, void *);
    s32 _gczoombox_entrypoint_4(s32, void *);
    s32 func_80800CA0_chgameselect(s32, void *);
    s32 temp_v0;

    _gczoombox_entrypoint_4((*(s32 *)((s8 *)(arg0) + (0x28))), arg0);
    temp_v0 = _gczoombox_entrypoint_3((*(s32 *)((s8 *)(arg0) + (0x28))), arg0);
    if (temp_v0 != (*(s32 *)((s8 *)(arg0) + (0x20)))) {
        (*(s32 *)((s8 *)(arg0) + (0x20))) = temp_v0;
        if (temp_v0 == 3) {
            func_80800CA0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x3C))), arg0);
        }
    }
}

void _gldbstring_entrypoint_2(s32 a0);

void func_80802588_chgameselect(void *arg0) {
    if ((*(s32 *)((s8 *)arg0 + 0x30)) != 0) {
        _gldbstring_entrypoint_2(*(s32 *)((s8 *)arg0 + 0x18));
        (*(s32 *)((s8 *)arg0 + 0x30)) = 0;
    }
    func_80802620_chgameselect(arg0);
}

/* extern */

void func_808025CC_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_2(s32);
    _gczoombox_entrypoint_2((*(s32 *)((s8 *)(arg0) + (0x28))));
}

s32 func_808025EC_chgameselect(void *arg0, s32 arg1, s32 arg2) {
    struct Fields {
        u8 pad[0x79];
        u8 high : 4;
        u8 low : 4;
    };
    s32 result = 1;
    if (arg1 == 0xA) {
        ((struct Fields *)arg0)->high = arg2;
    } else {
        return 0;
    }
    return result;
}

/* extern */

void func_80802620_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_0(s32);
    _gczoombox_entrypoint_0((*(s32 *)((s8 *)(arg0) + (0x28))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802640_chgameselect.s")

void func_808026C8_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_8();
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    Actor *actor;

    actor = func_80106790(arg0);
    if (arg1 != actor->actorData[1]) {
        actor->actorData[1] = arg1;
        _gczoombox_entrypoint_32(actor->actorData[4]);
        _gczoombox_entrypoint_8(actor->actorData[4], _gldbstring_entrypoint_1(*(u32 **)((s8 *)actor + 0x30), *(s16 *)((s8 *)actor + 0x1E)));
        actor->actorData[2] = -1;
    }
}

void func_80802730_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_8();
    Actor *actor;

    actor = func_80106790(arg0);
    actor->actorData[1] = -1;
    _gczoombox_entrypoint_32(actor->actorData[4]);
    _gczoombox_entrypoint_8(actor->actorData[4], arg1);
    actor->actorData[2] = -1;
}

s32 func_80802780_chgameselect(s32 arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    struct Fields { u8 pad[0x65]; u8 rest : 3; u8 bit : 1; u8 low : 4; };
    actor = func_80106790((Unk80132ED0 *)arg0);
    if (arg1 != 0) {
        ((struct Fields *)actor)->bit = 1;
    } else {
        ((struct Fields *)actor)->bit = 0;
    }
}

OSThread *chgameselect_entrypoint_5(void)
{
    extern u8 D_80808328_chgameselect[];

    return (OSThread *) D_80808328_chgameselect;
}

void func_808027D4_chgameselect(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808027DC_chgameselect.s")

/* extern */

void func_80802994_chgameselect(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _gcnewoption_entrypoint_1(u8 *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_1(func_80100094(arg0, 0U), arg1);
    }
}

/* extern */

void func_808029D8_chgameselect(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _gcnewoption_entrypoint_6(Actor *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802A0C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802AD4_chgameselect.s")

void func_80802BE8_chgameselect(Unk80132ED0 *arg0)
{
    Actor *func_80106790(Unk80132ED0 *);
    func_808029D8_chgameselect(func_80106790(arg0));
}

void func_80802C10_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    _gcnewoption_entrypoint_38(func_80100094(func_80106790(arg0), 0U), 1U);
}

s32 func_80802C48_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    return _gcnewoption_entrypoint_39(func_80100094(func_80106790(arg0), 0U));
}

void func_80802C7C_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    void *func_80100094(Actor *, u32);

    actor = func_80106790(arg0);
    *(u8 *)((s8 *)actor + 0x65) = (u8) (*(u8 *)((s8 *)actor + 0x65) & ~0x10);
    _gcnewoption_entrypoint_37(func_80100094(actor, 0), 1);
}

void func_80802CC0_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    void *func_80100094(Actor *, u32);

    actor = func_80106790(arg0);
    *(u8 *)((s8 *)actor + 0x65) = (u8) (*(u8 *)((s8 *)actor + 0x65) & ~0x10);
    _gcnewoption_entrypoint_37(func_80100094(actor, 0), 0);
}

void func_80802D04_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    actor->unk64_20 = arg1;
}

void func_80802D40_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80802640_chgameselect(s32, s32, s32);
    u32 *func_80100074(Actor *, u32, u32);
    void func_80101FDC(Actor *, u32);
    Actor *actor;

    actor = func_80106790(arg0);
    actor->actorData[4] = arg1;
    actor->actorData[5] = 0;
    func_80802640_chgameselect(func_80106790(actor->unk3C)->actorData[3], arg2, 0);
    func_80100074(actor, 1U, actor->actorData[4] * 6);
    func_80101FDC(actor, 2U);
}

void func_80802DB4_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    u8 *entry;

    actor = func_80106790(arg0);
    entry = (u8 *)func_80100094(actor, 1U) + actor->actorData[5] * 6;
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
    *(s16 *)(entry + 4) = arg5;
    actor->actorData[5]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802E38_chgameselect.s")

s32 func_80802F8C_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    s32 result;

    actor = func_80106790(arg0);
    result = _gcnewoption_entrypoint_37(func_80100094(actor, 0U), 1);
    if (result != 0) {
        actor->unk64_20 = 0;
    }
    return result;
}

void func_80802FE4_chgameselect(Actor *arg0) {
    s32 func_80802640_chgameselect(s32, s32, s32);
    u32 *func_80100074(Actor *, u32, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _gcnewoption_entrypoint_6(Actor *, s32);
    func_80100074(arg0, 1U, 0U);
    arg0->actorData[5] = 0;
    arg0->actorData[4] = 0;
    arg0->unk64_20 = 0;
    _gcnewoption_entrypoint_6(arg0, 0);
    func_80802640_chgameselect(func_80106790(arg0->unk3C)->actorData[3], 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803048_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808030EC_chgameselect.s")

void func_808031F4_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    u32 *func_80100074(Actor *, u32, u32);
    void func_80101FDC(Actor *, u32);
    Actor *sp1C;

    sp1C = func_80106790(arg0);
    sp1C->actorData[5] = 0;
    sp1C->actorData[4] = arg1;
    func_80100074(sp1C, 1, arg1 * 6);
    func_80101FDC(sp1C, 3);
}

void func_80803248_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    u8 *entry;

    actor = func_80106790(arg0);
    entry = (u8 *)func_80100094(actor, 1U) + actor->actorData[5] * 6;
    entry[0] = arg1;
    entry[1] = arg2;
    *(s8 *)(entry + 2) = -1;
    entry[3] = arg3;
    *(s16 *)(entry + 4) = arg4;
    actor->actorData[5]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808032CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803420_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808034BC_chgameselect.s")

void func_80803604_chgameselect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_8080407C_chgameselect(s32, s32, s32);
    void func_808040DC_chgameselect(s32, s32, s32);
    if (arg2 != 0) {
        func_8080407C_chgameselect(arg0, arg1, arg3);
        return;
    }
    func_808040DC_chgameselect(arg0, arg1, arg3);
}

void func_80803638_chgameselect()
{
    _glsavegame_entrypoint_0();
}

void func_80803658_chgameselect()
{
    _glsavegame_entrypoint_9();
}

void func_80803678_chgameselect()
{
    func_800D37C0();
}

void func_80803698_chgameselect()
{
    _glsavegame_entrypoint_10();
}

void func_808036B8_chgameselect()
{
    func_800D37D4();
}

void func_808036D8_chgameselect()
{
    _glsavegame_entrypoint_1();
}

void func_808036F8_chgameselect()
{
    _glsavegame_entrypoint_2();
}

void func_80803718_chgameselect()
{
    _glsavegame_entrypoint_3();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803738_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808037C0_chgameselect.s")

void func_80803888_chgameselect(s32 arg0, u32 arg1, u32 arg2) {
    void func_80016BDC(s32);
    void func_800C9E20(f32, u32 *, u32, u32);
    s32 func_80800478_chgameselect(s32, s32);
    extern u32 _gcfrontend_entrypoint_8;
    s32 var_a0;

    if (arg2 != 0) {
        var_a0 = 2;
    } else {
        var_a0 = 1;
    }
    func_80016BDC(var_a0);
    func_800C9E20(1.5f, &_gcfrontend_entrypoint_8, arg1, arg2);
    func_80800478_chgameselect(arg0, 8);
}

void func_808038EC_chgameselect(s32 arg0, u32 arg1, u32 arg2) {
    void func_800C9E20(f32 timerLength, u32* callback, u32 callbackArg0, u32 callbackArg1);
    void func_80016BDC(s32);
    s32 func_80800478_chgameselect(s32, s32);
    extern u32 _gcfrontend_entrypoint_7;
    func_80016BDC(1);
    func_800C9E20(1.5f, &_gcfrontend_entrypoint_7, arg1, arg2);
    func_80800478_chgameselect(arg0, 8);
}

s32 func_80803940_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_6(s32, s32);
    _gcstatusDll_entrypoint_6(0, 0);
    _gcstatusDll_entrypoint_6(1, 1);
    _gcstatusDll_entrypoint_6(2, 2);
    return _gcstatusDll_entrypoint_6(3, 3);
}

s32 func_80803988_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_3(s32, s32);
    _gcstatusDll_entrypoint_3(0, 1);
    _gcstatusDll_entrypoint_3(1, 1);
    _gcstatusDll_entrypoint_3(2, 1);
    return _gcstatusDll_entrypoint_3(3, 1);
}

/* extern */

void func_808039D0_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 _gcstatusDll_entrypoint_9(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(2);
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(2);
    _gcstatusDll_entrypoint_9(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A18_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(6);
    _gcstatusDll_entrypoint_8(0xA);
    _gcstatusDll_entrypoint_7(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A58_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(6);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A88_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803AB0_chgameselect.s")

void func_80803B3C_chgameselect(s32 arg0) {
    s32 _gcstatusDll_entrypoint_10(void);
    void func_80016BDC(s32);
    void func_800C9DAC(f32, void *);
    s32 func_80800478_chgameselect(s32, s32);
    extern void func_800AA1A0(void);
    func_80016BDC(_gcstatusDll_entrypoint_10());
    func_800C9DAC(1.5f, func_800AA1A0);
    func_80800478_chgameselect(arg0, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803B84_chgameselect.s")

void func_80803BE8_chgameselect(Actor *arg0) { void func_800AA054(s32); void func_800AA074(); s32 func_800AA120(void); struct Entry { s32 id; void (*callback)(void *); }; extern struct Entry D_808083A0_chgameselect[]; extern struct Entry D_808083C8_chgameselect[]; struct Entry *var_v1; struct Entry *end; s32 temp_v0;  func_800AA074(); func_800AA054(*(s32 *)&arg0->unk54); temp_v0 = func_800AA120(); end = D_808083C8_chgameselect; var_v1 = D_808083A0_chgameselect; loop_1: if (temp_v0 == var_v1->id) { var_v1->callback(end); } else { var_v1++; if (var_v1 != end) { goto loop_1; } } func_80803B3C_chgameselect(arg0); }

void func_80803C60_chgameselect()
{
    func_800FC660(0xF);
}

void func_80803C80_chgameselect()
{
    func_800FC660(0xE);
}

void func_80803CA0_chgameselect()
{
    func_800FC660(0x10);
}

void func_80803CC0_chgameselect()
{
    func_800FC660(0x96);
}

void func_80803CE0_chgameselect()
{
    func_800FC660(0x97);
}

s32 func_80803D00_chgameselect(s32 arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(s32 *);
    s32 _cadbfunc_entrypoint_2(s32 *);
    s32 func_800A5800(s32);
    void func_800E39D8(s32 arg0, s32 arg1);
    union {
        s32 word;
        struct {
            s16 flag;
            s16 id;
        } parts;
    } sp34;
    s32 sp28[3];
    s32 sp1C[3];

    sp34.parts.flag = arg1;
    sp34.parts.id = arg0;
    if (func_80101180(0x4B9, 0x21, sp34.word) == 0) {
        func_800A5800(arg0);
        _cadbfunc_entrypoint_0(sp28);
        _cadbfunc_entrypoint_2(sp1C);
        func_800E39D8((s32) sp28, (s32) sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803D60_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803DCC_chgameselect.s")

s32 func_80803E40_chgameselect(void) {
    s32 func_80016800(s32);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!func_80016800(i)) return i;
    }
    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803E94_chgameselect.s")

/* extern */

void func_80803F90_chgameselect(char *arg0, s32 arg1, s16 *arg2) {
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void func_800E6A10(char *, const char *);
    void func_800E73D4(s8 *);
    u32 *temp_v0;
    s32 var_s1;
    s16 *var_s0;

    func_800E73D4(arg0);
    var_s1 = 0;
    if (arg1 > 0) {
        var_s0 = arg2;
        do {
            temp_v0 = _gldbstring_entrypoint_0(0, var_s0[0]);
            if (temp_v0 != 0) {
                func_800E6A10(arg0, (const char *)_gldbstring_entrypoint_1(temp_v0, var_s0[1]));
            }
            _gldbstring_entrypoint_2(var_s0[0]);
            var_s1 += 1;
            var_s0 += 2;
        } while (var_s1 != arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080401C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080407C_chgameselect.s")

void func_808040DC_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_13(s32, s32, s32 *);
    s32 _gcnewoption_entrypoint_18();
    s32 _gcnewoption_entrypoint_22(s32, s32);
    extern s32 D_808083D8_chgameselect;
    if (_gcnewoption_entrypoint_18() == 0) {
        _gcnewoption_entrypoint_22(arg0, arg1);
        _gcnewoption_entrypoint_13(arg0, arg1, &D_808083D8_chgameselect);
        if (arg2 != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080413C_chgameselect.s")

/* extern */

s32 func_808041C8_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    void func_808016E8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 2);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016E8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x28))), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

/* extern */

void func_80804220_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    void func_808016E8_chgameselect(Unk80132ED0 *, s32);
    void func_80801758_chgameselect(Unk80132ED0 *, s32);
    s32 func_8080218C_chgameselect(s32, s32);
    s32 func_80803D60_chgameselect(s32);
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C)))));
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x20))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x20)))));
    func_80801758_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x28))), -1);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016E8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x28))), 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808042A8_chgameselect.s")

void func_80804404_chgameselect(u8 *arg0, s32 arg1) {
    s32 func_80800478_chgameselect();

    if (*(s32 *)(arg0 + 0x18) >= 3) {
        func_80800478_chgameselect(arg0, 1);
    } else {
        arg0[0x65] &= ~0x10;
    }
}

/* extern */

s32 func_8080444C_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    void func_808016E8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016E8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x28))), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

/* extern */

void func_808044A4_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    void func_808016E8_chgameselect(Unk80132ED0 *, s32);
    s32 func_8080218C_chgameselect(s32, s32);
    s32 func_80803D60_chgameselect(s32);
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C)))));
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016E8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x28))), 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080450C_chgameselect.s")

/* extern */

void func_808045E4_chgameselect(u8 *arg0, s32 arg1) {
    s32 func_80800478_chgameselect(s32, s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) >= 2) {
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
}

s32 func_8080462C_chgameselect(u8 *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_80802AD4_chgameselect(s32, s32, s32, s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    extern s32 D_80807DB0_chgameselect[];
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_80802AD4_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), *(s16 *)&D_80807DB0_chgameselect[(u32)((Actor *)arg0)->unk79_4], 3, 1, 0);
    func_80803D00_chgameselect(5, 1);
    return 1;
}

/* extern */

void func_80804694_chgameselect(void *arg0) {
    s32 _glglobalsettings_entrypoint_2();
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_80802BE8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    _glglobalsettings_entrypoint_2();
}

void func_808046D0_chgameselect(s32 arg0, s32 arg1) {
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    s32 func_80804948_chgameselect(s32);
    void func_808049E8_chgameselect(s32, s32, s32);
    extern s16 D_808083E0_chgameselect;
    s16 *var_s1;
    s32 var_s0;

    var_s1 = &D_808083E0_chgameselect;
    var_s0 = 0;
    do {
        func_808049E8_chgameselect(arg1, var_s0, func_80804948_chgameselect(var_s0));
        _gcnewoption_entrypoint_31(arg1, var_s0, *var_s1);
        var_s0 += 1;
        var_s1++;
    } while (var_s0 != 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804750_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804878_chgameselect.s")

void func_808048F8_chgameselect(u8 *arg0, s32 *arg1) {
    s32 func_80802C48_chgameselect(Unk80132ED0 *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) < -1) {
        func_80802C48_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))));
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
        *arg1 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804948_chgameselect.s")

void func_8080499C_chgameselect(s32 arg0, s32 arg1) {
    void _glglobalsettings_entrypoint_4(s32);
    void _glglobalsettings_entrypoint_8(s32);
    switch (arg0) {
        case 1:
            _glglobalsettings_entrypoint_4(arg1);
            break;
        case 2:
            _glglobalsettings_entrypoint_8(arg1);
            break;
    }
}

/* extern */

void func_808049E8_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_24(s32, s32, s32);
    _gcnewoption_entrypoint_24(arg0, arg1, arg2);
    _gcnewoption_entrypoint_12(arg0, arg1, (s16) ((arg1 * 5) + arg2 + 0xA));
}

/* extern */

void func_80804A38_chgameselect(void *arg0) {
    s32 func_800FFA88(s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80802C48_chgameselect(Unk80132ED0 *);
    s32 temp_a0;

    func_80802C48_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))));
    func_808026C8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x2C))), 1);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x34)));
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    if (temp_a0 != 0) {
        func_800FFA88(temp_a0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

void func_80804A8C_chgameselect(u8 *arg0, s32 arg1, s32 arg2)
{
  s32 _gcnewoption_entrypoint_20(s32, s32, s32, u8 *);
  s32 var_a2;
  s32 *option;
  if ((*((s32 *) (((s8 *) arg0) + 0x18))) > 0)
  {
    option = &arg2;
    var_a2 = _gcnewoption_entrypoint_20(arg1, (unsigned long long) (*option), *option, arg0) + 1;
    if (var_a2 >= (*((s32 *) (((s8 *) arg0) + 0x18))))
    {
      var_a2 = 0;
    }
    func_808049E8_chgameselect(arg1, arg2, var_a2);
  }
}

/* extern */

void func_80804AF0_chgameselect(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_20(s32, s32, s32, u8 *);
    s32 var_a2;

    if ((*(s32 *)((s8 *)(arg0) + (0x18))) > 0) {
        var_a2 = _gcnewoption_entrypoint_20(arg1, arg2, arg2, arg0) - 1;
        if (var_a2 < 0) {
            var_a2 = (*(s32 *)((s8 *)(arg0) + (0x18))) - 1;
        }
        func_808049E8_chgameselect(arg1, arg2, var_a2);
    }
}

/* extern */

s32 func_80804B4C_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    s32 func_80804C30_chgameselect(void *, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_80803D00_chgameselect(6, 1);
    func_80804C30_chgameselect(arg0, 0);
    return -1;
}

/* extern */

void func_80804B90_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
}

/* extern */

void func_80804BB4_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80804D30_chgameselect(s32, s32);
    if (arg2 < 3) {
        func_80804D30_chgameselect(arg0, arg2);
        return;
    }
    func_808038EC_chgameselect(arg0, arg2, 1);
}

/* extern */

void func_80804BF4_chgameselect(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80804C30_chgameselect(void *, s32);
    s32 func_80800478_chgameselect(s32, s32);
    if (arg2 < 3) {
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
    func_80804C30_chgameselect(arg0, ((Actor *)arg0)->actorData[0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804C30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804D30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804E34_chgameselect.s")

/* extern */

void func_80804F14_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804F38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808051B4_chgameselect.s")

void func_80805310_chgameselect(u8 *arg0) {
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80802AD4_chgameselect(s32, s32, s32, s32, s32);
    void func_80802D04_chgameselect(Unk80132ED0 *, s32);
    extern s32 D_80807DB0_chgameselect[];
    func_80802AD4_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), *(s16 *)&D_80807DB0_chgameselect[(u32)((Actor *)arg0)->unk79_4], 3, 1, 0);
    func_80802D04_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))), 1);
    func_808026C8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x2C))), 2);
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080537C_chgameselect.s")

void func_80805474_chgameselect(s32 arg0,s32 arg1)
{
    func_8080537C_chgameselect(arg0,0x1,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805498_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080569C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080595C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805AC0_chgameselect.s")

/* extern */

void func_80805BA0_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80803E40_chgameselect();
    s32 func_8080401C_chgameselect(s32, s32, s32);
    s32 func_8080407C_chgameselect(s32, s32, s32);
    if (func_80803E40_chgameselect() >= (arg1 + 2)) {
        func_8080407C_chgameselect(arg0, arg1, arg2);
        return;
    }
    func_8080401C_chgameselect(arg0, arg1, arg2);
}

/* extern */

void func_80805BFC_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_14(s32);
    s32 _gcfrontend_entrypoint_3(s32);
    s32 _gcfrontend_entrypoint_4(s32);
    s32 _gcfrontend_entrypoint_5(s32);
    void func_80802E38_chgameselect(Unk80132ED0 *, s32, s32, s32);
    s32 sp30[2];
    s32 temp_s2;
    s32 var_s0;
    s32 var_s1;

    temp_s2 = _gcfrontend_entrypoint_4(3);
    sp30[0] = _gcfrontend_entrypoint_5(3);
    func_80802D40_chgameselect((Unk80132ED0 *)arg0->actorData[6], temp_s2, 0);
    var_s1 = 0;
    if (temp_s2 > 0) {
        var_s0 = sp30[0];
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], var_s0, var_s1, -1, -1, _gcfrontend_entrypoint_14(var_s0));
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s2);
    }
    func_80802E38_chgameselect((Unk80132ED0 *)arg0->actorData[6], 0x18E4, arg1, 0);
    func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], 4);
    arg0->actorData[0] = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805CD8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805ECC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805F30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805FCC_chgameselect.s")

void func_80806068_chgameselect(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 _gcstatusDll_entrypoint_9(s32);
    s32 _gcstatusDll_entrypoint_19(void);

    switch (arg1) {
    case 1:
        *(s32 *)((u8 *)arg0 + 0x20) = arg2;
        switch (arg2) {
        case 0:
            _gcstatusDll_entrypoint_8(10);
            _gcstatusDll_entrypoint_7(0);
            break;
        case 1:
            _gcstatusDll_entrypoint_8(20);
            _gcstatusDll_entrypoint_7(0);
            break;
        case 2:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(5);
            break;
        case 3:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(10);
            break;
        }
        break;
    case 2:
        _gcstatusDll_entrypoint_4(arg2 + 1);
        switch (arg2) {
        case 2:
        case 4:
            func_80806068_chgameselect(arg0, 1, 2);
            _gcstatusDll_entrypoint_9(0);
            break;
        case 3:
        default:
            if (_gcstatusDll_entrypoint_19() == 0) {
                _gcstatusDll_entrypoint_9(2);
            }
            break;
        }
        break;
    case 3:
        _gcstatusDll_entrypoint_9(arg2 + 2);
        break;
    }
}

void func_808061A8_chgameselect(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_10(void);
    s32 func_80802AD4_chgameselect(s32, s32, s32, s32, s32);
    u32 *func_80100074(Actor *, u32, u32);

    func_80802AD4_chgameselect(arg0->actorData[6], 0x18EF, _gcstatusDll_entrypoint_10(), 0, 0);
    func_80802D04_chgameselect((Unk80132ED0 *)arg0->actorData[6], 1);
    func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], 7);
    arg0->actorData[0] = 4;
    func_80100074(arg0, 1U, 0x14U);
}

void func_80806218_chgameselect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_24(s32, s32, s32);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    s32 _gczoomboxdata_entrypoint_0(s16);
    extern u8 D_8080841C_chgameselect[];

    _gcnewoption_entrypoint_24(arg0, arg1, arg2);
    _gcnewoption_entrypoint_12(arg0, arg1, (s16) ((arg1 * 0xA) + arg2));
    _gcnewoption_entrypoint_31(arg0, arg1, D_8080841C_chgameselect[arg2]);
    if (arg3 != 0) {
        _gczoomboxdata_entrypoint_0(D_8080841C_chgameselect[arg2]);
    }
}

/* extern */

s32 func_808062A8_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_13();
    return _gcstatusDll_entrypoint_13() + (-1);
}

void func_808062CC_chgameselect(s32 arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_3(s32, s32);
    _gcstatusDll_entrypoint_3(arg0, arg1 + 1);
}

/* extern */

void func_808062EC_chgameselect(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 _gcnewoption_entrypoint_20(s32, s32, s32, u8 *);
    s32 func_800DA298(s32);
    s32 var_a2;

    var_a2 = _gcnewoption_entrypoint_20(arg0, arg1, arg2, arg3) + arg2;
    if (var_a2 == 2) {
        if (func_800DA298(0xC0B) == 0) {
            var_a2 += arg2;
        }
    }
    if (var_a2 >= 5) {
        var_a2 = 0;
    } else if (var_a2 < 0) {
        var_a2 = 4;
    }
    func_80806218_chgameselect(arg0, arg1, var_a2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806370_chgameselect.s")

/* extern */

void func_80806408_chgameselect(Actor *arg0) {
    s32 _gcfrontend_entrypoint_14(s32);
    s32 _gcfrontend_entrypoint_3(s32);
    s32 _gcfrontend_entrypoint_4(s32);
    s32 _gcfrontend_entrypoint_5(s32);
    s32 func_800AA274(s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    void func_808032CC_chgameselect(Unk80132ED0 *, s32, s32, s32);
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 var_s0;
    s32 var_s1;

    temp_s3 = _gcfrontend_entrypoint_4(3);
    temp_s2 = _gcfrontend_entrypoint_5(3);
    func_808031F4_chgameselect((Unk80132ED0 *)arg0->actorData[6], temp_s3);
    var_s1 = 0;
    if (temp_s3 > 0) {
        var_s0 = temp_s2;
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                temp_s2_2 = func_800AA274(var_s0);
                func_80803248_chgameselect((Unk80132ED0 *)arg0->actorData[6], var_s0, var_s1, temp_s2_2, _gcfrontend_entrypoint_14(var_s0));
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s3);
    }
    func_808032CC_chgameselect((Unk80132ED0 *)arg0->actorData[6], 0x18E4, 0, 0);
    func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], 5);
    arg0->actorData[0] = 8;
}

/* extern */

void func_808064E8_chgameselect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800AA054(s32);
    void func_800AA074();
    if (arg3 != 0xFC) {
        if ((arg3 != 0xFD) && (arg3 == 0xFE)) {
            func_800AA054(arg2);
        }
    } else {
        func_800AA074(arg2);
    }
}

/* extern */

void func_80806540_chgameselect(s32 arg0) {
    s32 _gcfrontend_entrypoint_3(s32);
    s32 _gcfrontend_entrypoint_4(s32);
    s32 _gcfrontend_entrypoint_5(s32);
    void func_800AA054(s32);
    void func_800AA074();
    s32 func_80806744_chgameselect(s32);
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_800AA074();
    temp_s2 = _gcfrontend_entrypoint_4(3);
    temp_v0 = _gcfrontend_entrypoint_5(3);
    var_s1 = 0;
    if (temp_s2 > 0) {
        var_s0 = temp_v0;
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                func_800AA054(var_s0);
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s2);
    }
    func_80806744_chgameselect(arg0);
}

/* extern */

void func_808065C0_chgameselect(s32 arg0) {
    s32 func_80108B04(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_80803D00_chgameselect(7, 1);
    func_80108B04(arg0, 0x4B6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808065F4_chgameselect.s")

/* extern */

s32 func_808066CC_chgameselect(void) {
    s32 _gcfrontend_entrypoint_3(s32);
    s32 _gcfrontend_entrypoint_4(s32);
    s32 _gcfrontend_entrypoint_5(s32);
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 0;
    temp_s3 = _gcfrontend_entrypoint_4(3);
    temp_v0 = _gcfrontend_entrypoint_5(3);
    var_s1 = 0;
    if (temp_s3 > 0) {
        var_s0 = temp_v0;
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                var_s2 += 1;
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s3);
    }
    return var_s2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806744_chgameselect.s")

/* extern */

void func_80806800_chgameselect(void *arg0, s32 arg1) {
    s32 func_80803B84_chgameselect();
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) == 9) {
        func_80803B84_chgameselect();
    }
}

/* extern */

void func_80806834_chgameselect(void *arg0) {
    s32 func_80802640_chgameselect(s32, s32, s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80802AD4_chgameselect(s32, s32, s32, s32, s32);
    void func_80802D04_chgameselect(Unk80132ED0 *, s32);
    func_80802AD4_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), 0x18F0, 5, 1, 4);
    func_80802D04_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))), 1);
    func_808026C8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x2C))), 9);
    func_80802640_chgameselect((*(s32 *)((s8 *)(arg0) + (0x24))), 0x18F0, 0);
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 6;
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = -1;
}

/* extern */

void func_808068AC_chgameselect(void *arg0, s32 arg1) {
    s32 func_80802640_chgameselect(s32, s32, s32);
    func_80802BE8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    func_80802640_chgameselect((*(s32 *)((s8 *)(arg0) + (0x24))), 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808068E8_chgameselect.s")

void func_808069C8_chgameselect(s32 arg0)
{
  s32 _gcstatusDll_entrypoint_6(s32, s32);
  s32 var_s1;
  s32 var_s2;
  s32 var_s0;
  var_s0 = 0;
  var_s1 = 4;
  var_s2 = (arg0 + 1) ^ 0;
  do
  {
    _gcstatusDll_entrypoint_6(var_s0, ((1 << var_s0) & var_s2) ? (4) : (5));
    var_s0 = var_s0 + 1;
  }
  while (var_s0 != 4);
}

 s32 _gcstatusDll_entrypoint_10(void);

s32 func_80806A30_chgameselect(void) {
    s32 var_v1;

    var_v1 = _gcstatusDll_entrypoint_15();
    if (var_v1 < 0) {
        var_v1 = 0;
    } else {
        if (var_v1 >= _gcstatusDll_entrypoint_10()) {
            var_v1 = _gcstatusDll_entrypoint_10() - 1;
        }
    }
    return var_v1;
}

void func_80806A88_chgameselect()
{
    _gcstatusDll_entrypoint_5();
}

s32 func_80806AA8_chgameselect(void) {
    return (1 << (_gcstatusDll_entrypoint_10() + 0x1F)) - 1;
}

void func_80806AD4_chgameselect()
{
    _gcstatusDll_entrypoint_10();
}

/* extern */

void func_80806AF4_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_24(s32, s32, s32);
    s32 sp1C;
    s32 var_v0;

    if (arg1 == 3) {
        sp1C = 5;
    } else {
        sp1C = 0xF;
    }
    _gcnewoption_entrypoint_24(arg0, arg1, arg2);
    _gcnewoption_entrypoint_12(arg0, arg1, (s16) (sp1C + arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806B5C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806BD4_chgameselect.s")

OSThread *chgameselect_entrypoint_6(void)
{
    extern u8 D_808084B4_chgameselect[];

    return (OSThread *) D_808084B4_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806C54_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806D98_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806FAC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807030_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808070C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080714C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808073AC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808074C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808075D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807790_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807824_chgameselect.s")

OSThread *chgameselect_entrypoint_7(void)
{
    extern u8 D_80808504_chgameselect[];

    return (OSThread *) D_80808504_chgameselect;
}

void func_808078F0_chgameselect(void *arg0) {
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
}

/* extern */

void func_80807900_chgameselect(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800E39D8(s32, s32);
    void func_800EFE50(f32 *, void *, void *, f32);
    void func_800F16AC(u8 *, f32 *, f32 *, f32);
    void func_80101FDC(Actor *, u32);
    f32 sp34[3];
    u8 sp28[12];

    if (arg0->unk70_10 == 2) {
        ((f32 *)arg0->actorData)[7] += ((f32 *)arg0->actorData)[3] * func_800D8FF8();
        if (((f32 *)arg0->actorData)[7] >= 1.0f) {
            ((f32 *)arg0->actorData)[7] = 1.0f;
            func_80101FDC(arg0, 1);
        }
        func_800EFE50(sp34, arg0->position, arg0->actorData, ((f32 *)arg0->actorData)[7]);
        func_800F16AC(sp28, arg0->rotation, &((f32 *)arg0->actorData)[4], ((f32 *)arg0->actorData)[7]);
        func_800E39D8(sp34, sp28);
        func_80101180(0x4AB, 0x23, 0);
    }
}

void func_808079C8_chgameselect(s32 arg0) 
{
}
/* extern */

s32 func_808079D0_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80807A10_chgameselect(s32, s16, s16);
    switch (arg1) {
    case 0x21:
        func_80807A10_chgameselect(arg0, ((s16 *)&arg2)[1], ((s16 *)&arg2)[0]);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807A10_chgameselect.s")
