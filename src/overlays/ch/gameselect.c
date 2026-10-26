#include "common.h"

s32 func_800D9078(f32 *);

typedef struct {
    s32 (*init)(Actor *);
    u8 pad4[0x24];
    void (*callback)(Actor *, s32 *);
    u8 pad2C[8];
} GameSelectInitTable;


typedef struct { u8 data[0x260]; } OptionState;
u32 _gcnewoption_entrypoint_37(OptionState *, u32);

OSThread *chgameselect_entrypoint_0(void)
{
    extern u8 D_80807FD8_chgameselect[];

    return (OSThread *) D_80807FD8_chgameselect;
}

void func_8080000C_chgameselect(Actor *arg0) {
    void func_80016BDC(s32);
    void _gcfrontend_entrypoint_0(void);
    void func_800AA00C(void);
    u32 func_800AA0B8(void);
    s32 func_800D395C(void);
    void func_80108B04(Actor *, u32);
    void func_80803638_chgameselect(void);
    void *heap_alloc(s32);
    s32 temp_s0;
    s32 i;

    func_80016BDC(4);
    temp_s0 = func_800D395C();
    _gcfrontend_entrypoint_0();
    if (func_800AA0B8()) {
        arg0->unk79_4 = 5;
        arg0->unk6C_0 = 5;
    } else if (temp_s0 != 0) {
        arg0->unk79_4 = 7;
        arg0->unk6C_0 = 7;
        func_800AA00C();
    } else {
        arg0->unk79_4 = 0;
        arg0->unk6C_0 = 1;
        func_800AA00C();
    }
    func_80803638_chgameselect();
    func_80108B04(arg0, 0x4AB);
    i = 0;
    do {
        func_80108B04(arg0, i);
        i++;
    } while (i != 8);
    func_80108B04(arg0, 0x4AA);
    func_80108B04(arg0, 0x4A9);
    func_80108B04(arg0, 0x4AC);
    func_80108B04(arg0, 0x4B9);
    arg0->actorData[7] = 0;
    arg0->unk58 = 0.1f;
    *(void **)&arg0->unk50 = heap_alloc(0x100);
}

void func_8080015C_chgameselect(Actor *arg0) {
    s32 func_80803E40_chgameselect(void);
    s32 _gcstatusDll_entrypoint_10(void);
    void _gcstatusDll_entrypoint_2(s32);
    void func_80803C80_chgameselect(void);
    void func_808016E8_chgameselect(Unk80132ED0 *, s32);
    void func_80800478_chgameselect(s32, s32);
    extern s32 D_8011A3F0;
    s32 file;

    switch (arg0->unk70_10) {
        case 1:
            file = func_80803E40_chgameselect();
            if (file != 0) {
                if (_gcstatusDll_entrypoint_10() != file) {
                    _gcstatusDll_entrypoint_2(file);
                }
            }
            break;
        case 9:
            if (func_800D9078(&arg0->unk58) != 0) {
                if (D_8011A3F0 != 0) {
                    func_80803C80_chgameselect();
                }
                func_808016E8_chgameselect((Unk80132ED0 *)arg0->actorData[4], arg0->unk79_4);
                func_80800478_chgameselect((s32)arg0, arg0->unk6C_0);
            }
            break;
    }
}

s32 func_80800228_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void func_808005D4_chgameselect(Actor *, s32);
    void func_808006A0_chgameselect(Actor *, s32);
    void func_8080086C_chgameselect(Actor *, s32);
    void func_808020CC_chgameselect(Actor *, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    s32 func_80803D60_chgameselect(s32);
    void func_808065F4_chgameselect(Actor *);
    extern f32 B_80808578_chgameselect[3];
    Actor *child;

    switch (arg1) {
        case 0x95:
            func_80803D00_chgameselect(0, 0);
            break;
        case 0x3D:
            if (arg2 >= 9) {
                child = func_80108528(arg2, B_80808578_chgameselect, 0, &arg0);
                child->unk79_4 = arg0->unk79_4;
                switch (arg2) {
                    default:
                        arg0->unk3C = child->unk0;
                        break;
                    case 0x4AB:
                        arg0->actorData[4] = (u32)child->unk0;
                        child->scale = arg0->scale;
                        break;
                    case 0x4AA:
                        arg0->actorData[5] = (u32)child->unk0;
                        break;
                    case 0x4A9:
                        arg0->actorData[3] = (u32)child->unk0;
                        child->unk64_20 = 1;
                        break;
                    case 0x4AC:
                        arg0->actorData[6] = (u32)child->unk0;
                        break;
                    case 0x1E8:
                        arg0->actorData[7] = (u32)child->unk0;
                        break;
                }
            } else {
                child = func_80108528(0x4A8, B_80808578_chgameselect, 0, &arg0);
                child->unk79_4 = arg2;
                func_808020CC_chgameselect(child, func_80803D60_chgameselect(arg2));
            }
            child->unk3C = arg0->unk0;
            break;
        case 0xA:
            func_808005D4_chgameselect(arg0, arg2);
            break;
        case 7:
            func_808006A0_chgameselect(arg0, arg2);
            break;
        case 8:
            func_8080086C_chgameselect(arg0, arg2);
            break;
        case 0x23:
            if (arg0->unk70_10 == 5) {
                func_808065F4_chgameselect(arg0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800440_chgameselect(void *arg0) {
    void func_808036D8_chgameselect(void);
    void *mem;

    func_808036D8_chgameselect();
    mem = *(void **)((u8 *)arg0 + 0x50);
    if (mem != NULL) {
        heap_free(mem);
    }
}

void func_80800478_chgameselect(s32 arg0, s32 arg1) {
    typedef struct {
        void (*callback)(void);
        u8 pad4[0x30];
    } GameSelectExit;
    extern GameSelectInitTable D_80807DD0_chgameselect[];
    extern GameSelectExit D_80807DD4_chgameselect[];
    void func_80101FDC(Actor *, u32);
    s32 func_80801658_chgameselect(s32, s32);
    void func_80801714_chgameselect(Unk80132ED0 *, s32);
    s32 func_8080218C_chgameselect(s32, s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80802780_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    s32 func_80803DCC_chgameselect(s32);
    typedef struct {
        s32 count;
        s32 first;
        void *second;
    } GameSelectData;
    s32 option;
    void (*exitCallback)(void);
    Actor *actor = (Actor *)arg0;
    GameSelectData *data;

    option = -1;
    if (arg1 != actor->unk70_10) { exitCallback = D_80807DD4_chgameselect[actor->unk70_10].callback;
        if (exitCallback != NULL) {
            exitCallback();
        }
        func_80101FDC(actor, arg1);
        data = (GameSelectData *)actor->actorData;
        data->count = 0;
        data->second = (void *)-1; data->first = -1;
        if (D_80807DD0_chgameselect[actor->unk70_10].init != NULL) {
            option = D_80807DD0_chgameselect[actor->unk70_10].init(actor);
        }
        if (actor->unk70_10 != 1) {
            if (actor->unk70_10 == 8) {
                func_80802780_chgameselect(actor->actorData[3], 0);
                func_8080218C_chgameselect(actor->unk79_4, 1);
                func_80801658_chgameselect(actor->actorData[4], 1);
                func_80801714_chgameselect((Unk80132ED0 *)actor->actorData[4], 0);
            }
        } else {
                option = func_80803DCC_chgameselect(actor->unk79_4);
                func_80803D00_chgameselect(0, 1);
        }
        if (option != -1) {
            func_808026C8_chgameselect((Unk80132ED0 *)actor->actorData[5], option);
        }
    }
}

void func_808005D4_chgameselect(Actor *arg0, s32 arg1) {
    extern s32 D_80807DB0_chgameselect[];
    void func_80802640_chgameselect(Unk80132ED0 *, s32, s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    void func_80803678_chgameselect();
    void func_808036B8_chgameselect();
    s32 func_80803DCC_chgameselect(s32);
    u32 state;
    u32 option;

    arg0->unk79_4 = arg1;
    state = arg0->unk70_10;
    if (state == 1 || state == 9) {
        option = arg0->unk79_4;
        if (option == 0 || option == 1 || option == 2) {
            func_80803678_chgameselect(option);
        } else {
            func_808036B8_chgameselect(option);
        }
        func_80802640_chgameselect((Unk80132ED0 *)arg0->actorData[5],
            *(s16 *)&D_80807DB0_chgameselect[(u32)arg0->unk79_4], 0);
        func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5],
            func_80803DCC_chgameselect(arg0->unk79_4));
    }
}

void func_808006A0_chgameselect(Actor *arg0, s32 arg1) {
    typedef struct {
        s32 (*callback)(Actor *, s32, s32 *);
        s32 pad[12];
    } StateCallback;
    extern StateCallback D_80807DD8_chgameselect[];
    extern s16 D_80807DB2_chgameselect[][2];
    void func_80800478_chgameselect(s32, s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80803718_chgameselect(void);
    s32 func_808036F8_chgameselect();
    s32 func_80803D60_chgameselect(s32);
    s32 func_80803E40_chgameselect(void);
    void func_80803C60_chgameselect(void);
    s32 next = -1;
    s32 changed = 0;
    s32 (*callback)(Actor *, s32, s32 *);

    callback = D_80807DD8_chgameselect[arg0->unk70_10].callback;
    if (callback != NULL) {
        changed = callback(arg0, arg1, &next);
    }
    if (arg0->unk70_10 == 1) {
        switch (arg1) {
        case 3:
            if (func_80803718_chgameselect() == 0) {
                next = 5;
            } else if (func_808036F8_chgameselect(0) != 0 &&
                       func_808036F8_chgameselect(1) != 0 &&
                       func_808036F8_chgameselect(2) != 0) {
                next = 7;
            }
            break;
        case 4:
            if (func_80803718_chgameselect() == 0) {
                next = 4;
            }
            break;
        case 5:
            if (func_80803D60_chgameselect(arg1) == 0) {
                next = 0;
            } else if (func_80803E40_chgameselect() < 2) {
                next = 0x23;
            }
            break;
        case 7:
            if (func_80803D60_chgameselect(arg1) == 0) {
                next = 0;
            }
            break;
        }
        if (next != -1) {
            changed = 1;
        } else {
            func_80800478_chgameselect(arg0,
                D_80807DB2_chgameselect[arg0->unk79_4][0]);
        }
    }
    if (changed != 0) {
        func_80803C60_chgameselect();
    }
    if (next != -1) {
        func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], next);
    }
}

/* extern */

void func_8080086C_chgameselect(Actor *arg0, s32 arg1) {
    void func_80800478_chgameselect(s32, s32);
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

void func_80800944_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        void (*callback)();
        u8 pad4[0x30];
    } GameSelectCallback;
    extern GameSelectCallback D_80807DE4_chgameselect[];
    void (*temp_v0)();
    Actor *original;

    temp_v0 = D_80807DE4_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        original = arg0;
        arg0 = (Actor *)((u32)arg0 ^ 0);
        temp_v0(original, arg1, arg2);
    }
    if (arg0 == NULL) {
        return;
    }
}

void func_80800998_chgameselect(Actor *arg0, void *arg1, s32 arg2) {
    typedef struct {
        void (*callback)();
        u8 pad4[0x30];
    } GameSelectCallback;
    extern GameSelectCallback D_80807DE8_chgameselect[];
    void (*temp_v0)();
    Actor *original;

    temp_v0 = D_80807DE8_chgameselect[arg0->unk70_10].callback;
    if (temp_v0 != NULL) {
        original = arg0;
        arg0 = (Actor *)((u32)arg0 ^ 0);
        temp_v0(original, arg1, arg2);
    }
    if (arg0 == NULL) {
        return;
    }
}

void func_808009EC_chgameselect(Actor *arg0) {
    typedef struct {
        void (*callback)(void);
        u8 pad4[0x30];
    } GameSelectCallback;
    void func_80800478_chgameselect(s32, s32);
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

void func_80800AEC_chgameselect(Unk80132ED0 *arg0, void *arg1, s32 arg2, s32 arg3) {
    typedef struct {
        void (*callback)(Actor *, void *, s32, s32);
        u8 pad4[0x30];
    } GameSelectCallback;
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800944_chgameselect();
    void func_80800998_chgameselect();
    extern GameSelectCallback D_80807DDC_chgameselect[];
    extern GameSelectCallback D_80807DF0_chgameselect[];
    extern GameSelectCallback D_80807DF4_chgameselect[];
    Actor *actor;

    actor = func_80106790(arg0);
    switch (arg3) {
    case 0:
        D_80807DDC_chgameselect[actor->unk70_10].callback(actor, arg1, arg2, arg3);
        break;
    case 3:
        func_80800998_chgameselect(actor, arg1, arg2, arg3);
        break;
    case 2:
        func_808009EC_chgameselect(actor);
        break;
    case 4:
        func_808008D0_chgameselect(actor, arg1, arg2);
        break;
    case 5:
        func_80800944_chgameselect(actor, arg1, arg2, arg3);
        break;
    case 6:
        func_80800A9C_chgameselect(actor);
        break;
    case 7:
        func_80800A4C_chgameselect(actor);
        break;
    case 0xFF:
        D_80807DF0_chgameselect[actor->unk70_10].callback(actor, arg1, arg2, arg3);
        break;
    case 0xFC:
    case 0xFD:
    case 0xFE:
        D_80807DF4_chgameselect[actor->unk70_10].callback(actor, arg1, arg2, arg3);
        break;
    }
}

void func_80800CA0_chgameselect(Unk80132ED0 *arg0) {
    typedef struct {
        u8 pad0[0x28];
        void (*callback)(Actor *, s32 *);
        u8 pad2C[8];
    } GameSelectCallback;
    Actor *func_80106790(Unk80132ED0 *);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    extern GameSelectInitTable D_80807DD0_chgameselect[];
    s32 sp1C;
    Actor *actor;

    sp1C = -1;
    actor = func_80106790(arg0);
    if (D_80807DD0_chgameselect[actor->unk70_10].callback != NULL) {
        D_80807DD0_chgameselect[actor->unk70_10].callback(actor, &sp1C);
    }
    if (sp1C != -1) {
        func_808026C8_chgameselect((Unk80132ED0 *)actor->actorData[5], sp1C);
    }
}

s32 func_80800D3C_chgameselect(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(arg0)->unk70_10 != 9;
}

OSThread *chgameselect_entrypoint_1(void)
{
    extern u8 D_80808038_chgameselect[];

    return (OSThread *) D_80808038_chgameselect;
}

typedef struct {
        u8 pad0[0x34];
        f32 fade;
} GameSelectInitActorFields;
typedef struct {
        u8 pad0[0xC8];
        f32 direction[3];
        f32 distance;
} GameSelectInitData;

void func_80800D74_chgameselect(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EFD24(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EF2A0(f32 *);
    void func_808015DC_chgameselect(Unk80132ED0 *, s32);
    void *volatile data;
    f32 *direction;

    data = func_80100094(arg0, 0);
    func_800EFD24(&arg0->position[0]);
    arg0->rotation[0] = 45.0f;
    arg0->rotation[2] = 45.0f;
    arg0->rotation[1] = 60.0f;
    func_808015DC_chgameselect(arg0->unk0, 0);
    arg0->unk64_20 = 0;
    ((GameSelectInitActorFields *)arg0)->fade = 1.0f;
    direction = &((GameSelectInitData *)data)->direction[0];
    func_800EFA4C(direction, 0.0f, 0.0f, 1.0f);
    func_800EF2A0(direction);
    ((GameSelectInitData *)data)->distance = 200.0f;
}

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

s32 func_808011B4_chgameselect(void *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x74];
        u32 pad74 : 10;
        u32 flag21 : 1;
        u32 pad74low : 21;
    } SelectEventActor;
    typedef struct {
        f32 positions[8][3];
        f32 entries[8][3];
        u8 enabled[8];
        f32 direction[3];
        f32 distance;
    } SelectData;
    void *func_80100094(Actor *, u32);
    void func_80101038(f32 *);
    void func_8080145C_chgameselect(f32 *, f32, f32 *, f32 *);
    SelectData *data;
    SelectData *data2;
    SelectData *cursor;
    f32 *position;
    f32 *position2;
    s32 offset;
    s32 i;

    switch (arg1) {
        default:
            return 0;
        case 35:
            data = func_80100094(arg0, 0);
            for (i = 0, cursor = data; i < 8; i++) {
                if (cursor->enabled[0]) {
                    position = data->positions[i];
                    func_8080145C_chgameselect(data->direction, data->distance,
                        position + 24, position);
                }
                cursor = (SelectData *)((u8 *)cursor + 1);
            }
            ((Actor *)arg0)->unk6C_0 = 1;
            break;
        case 49:
            if (((SelectEventActor *)arg0)->flag21) {
                data2 = func_80100094(arg0, 0);
                offset = arg2 * 12;
                func_80101038((f32 *)((u8 *)data2 + offset));
                data2->enabled[arg2] = 1;
                position2 = (f32 *)((u8 *)data2 + offset);
                func_8080145C_chgameselect(data2->direction, data2->distance,
                    position2 + 24, position2);
                return 1;
            } else {
                return 0;
            }
    }
    return 1;
}

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

void func_808015DC_chgameselect(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 _subaddiefade_entrypoint_12(Actor *, s32, s32, s32);
    Actor *actor;

    actor = func_80106790(arg0);
    switch (arg1) {
        case 1:
            _subaddiefade_entrypoint_12(actor, 0xFF, 0, 0);
            break;
        case 2:
            _subaddiefade_entrypoint_12(actor, 0, 0xFF, 0);
            break;
        default:
            _subaddiefade_entrypoint_12(actor, 0xFF, 0xFF, 0xFF);
            break;
    }
}

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

void func_8080179C_chgameselect(Actor *arg0) {
    void func_800C3F48(u32);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    extern f32 D_80808110_chgameselect[][11];
    extern u16 D_80808270_chgameselect[];
    extern u8 D_80808280_chgameselect[];
    extern f32 D_80808288_chgameselect[];

    switch (arg0->unk79_4) {
        case 4:
            if (func_80101E4C(arg0, D_80808288_chgameselect)) {
                func_800C3F48((((u32)(func_800DC178(0.7f, 0.8f) * 1023.0f) & 0x7FF) << 21) + 0xFA4D5);
            }
            break;
        case 6:
            if (func_80101E14(arg0, 0.77f)) {
                func_800C3F48((((u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) & 0x7FF) << 21) + 0xDACD5);
            }
            break;
    }
    if (func_80101E4C(arg0, D_80808110_chgameselect[arg0->unk79_4])) {
        func_800C3F48((D_80808270_chgameselect[arg0->unk79_4] & 0x7FF)
            + (((D_80808280_chgameselect[arg0->unk79_4] * 1000 >> 5) & 0x3FF) << 11)
            + (((u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) & 0x7FF) << 21));
    }
}

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

s32 func_80801BA8_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    extern u16 D_808080A8_chgameselect[][2];
    extern s16 D_808080AA_chgameselect[][2];
    s32 _gcfrontend_entrypoint_1(s32);
    s32 _gcfrontend_entrypoint_2(void);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void *func_8008AEDC(void *);
    void func_8008B304(s32);
    void func_8008C200(s16, s32, s32);
    u8 *func_800B27E0(u8 *);
    void func_80102424(Actor *, s32);
    s32 func_801032B0(Actor *, u16, u16);
    u8 *func_801039E4(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    void func_80801D74_chgameselect(Actor *, s32);
    void func_80802070_chgameselect(Actor *, s32);
    void func_808020CC_chgameselect(Actor *, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    struct anctrl_s *control;
    u8 *model;
    s16 *values;
    s32 index;
    switch (arg1) {
    case 0x95:
        func_801032B0(arg0, D_808080A8_chgameselect[arg0->unk79_4][0], 0);
        control = func_80104248(arg0);
        func_8008B304(control);
        model = func_800B27E0(func_801039E4(arg0->unk0));
        func_8008C200(*(s16 *)&arg0->unk0->unk10, model, func_8008AEDC(control));
        func_80102424(arg0, 2);
        switch (arg0->unk79_4) {
        case 5:
            if (!_gcfrontend_entrypoint_1(3)) {
                _subaddiefade_entrypoint_1(arg0, 100);
            }
            break;
        case 7:
            if (!_gcfrontend_entrypoint_2()) {
                _subaddiefade_entrypoint_1(arg0, 100);
            }
            break;
        }
        break;
    case 10:
        func_80802070_chgameselect(arg0, arg2 == arg0->unk79_4 ? 1 : 0);
        if (arg2 == arg0->unk79_4) {
            index = D_808080AA_chgameselect[arg2][0];
            if (index >= 0) {
                func_80803D00_chgameselect(index, 2);
            }
        }
        break;
    case 31:
        func_80801D74_chgameselect(arg0, arg2);
        break;
    case 33:
        values = (s16 *)&arg2;
        if (arg0->unk79_4 == values[0]) {
            func_808020CC_chgameselect(arg0, values[1]);
            break;
        }
    default:
        return 0;
    }
    return 1;
}

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
    void *heap_alloc(s32);
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0xC8, 0xC, 2, 0, 0);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    _gczoombox_entrypoint_19(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = heap_alloc(0x40);
    (*(s32 *)((s8 *)(arg0) + (0x34))) = heap_alloc(0x40);
}

void func_80802248_chgameselect(Actor *arg0) {
    int _gczoombox_entrypoint_10();
    s32 _gczoombox_entrypoint_11(s32);
    void _gczoombox_entrypoint_12();
    void _gczoombox_entrypoint_15();
    void _gczoombox_entrypoint_16(s32);
    void _gczoombox_entrypoint_17();
    void _gczoombox_entrypoint_18();
    int _gczoombox_entrypoint_32();
    s32 _gczoombox_entrypoint_4();
    int _gczoombox_entrypoint_7();
    int _gczoombox_entrypoint_8();
    s32 _gczoombox_entrypoint_9(s32);
    void func_800DB8BC(char *, s32);
    void func_800E6A58(char *, char);
    void func_800E73D4(s8 *);
    s32 func_80803738_chgameselect(s32, s32 *, s32 *);
    void func_80803E94_chgameselect(char *, s32, s32, s32, s32 *);
    extern char *B_80808558_chgameselect[];
    s32 state = 0;
    s32 time;
    s32 count;
    s32 value;

    if (arg0->unk64_20) {
        switch (arg0->unk79_4) {
            case 0:
            case 1:
            case 2:
                state = arg0->unk79_4 + 1;
                break;
        }
    }
    if (arg0->actorData[0]) {
        _gczoombox_entrypoint_18(arg0->actorData[4]);
        _gczoombox_entrypoint_16(arg0->actorData[4]);
        _gczoombox_entrypoint_9(arg0->actorData[4]);
        _gczoombox_entrypoint_11(arg0->actorData[4]);
    } else if (state) {
        if (state != (s32)arg0->actorData[5]) {
            _gczoombox_entrypoint_18(arg0->actorData[4]);
            _gczoombox_entrypoint_16(arg0->actorData[4]);
            _gczoombox_entrypoint_9(arg0->actorData[4]);
            _gczoombox_entrypoint_11(arg0->actorData[4]);
            func_800E73D4((s8 *)arg0->actorData[3]);
            func_800E73D4((s8 *)arg0->actorData[7]);
            value = arg0->unk79_4 + 1;
            if (func_80803738_chgameselect(arg0->unk79_4, &time, &count)) {
                func_80803E94_chgameselect((char *)arg0->actorData[3], 0x18F3, 1, 1, &value);
                func_800DB8BC((char *)arg0->actorData[3], time);
                func_800E6A58((char *)arg0->actorData[3], ',');
                value = count;
                if (count == 1) {
                    func_80803E94_chgameselect((char *)arg0->actorData[7], 0x18F3, 3, 1, &value);
                } else {
                    func_80803E94_chgameselect((char *)arg0->actorData[7], 0x18F3, 2, 1, &value);
                }
            } else {
                func_80803E94_chgameselect((char *)arg0->actorData[3], 0x18F3, 0, 1, &value);
            }
            _gczoombox_entrypoint_32(arg0->actorData[4]);
            if (*(u8 *)arg0->actorData[7]) {
                B_80808558_chgameselect[0] = (char *)arg0->actorData[3];
                B_80808558_chgameselect[1] = (char *)arg0->actorData[7];
                _gczoombox_entrypoint_7(arg0->actorData[4], 2, B_80808558_chgameselect);
            } else {
                _gczoombox_entrypoint_8(arg0->actorData[4], (char *)arg0->actorData[3]);
            }
        }
    } else {
        _gczoombox_entrypoint_15(arg0->actorData[4]);
        _gczoombox_entrypoint_17(arg0->actorData[4]);
        _gczoombox_entrypoint_12(arg0->actorData[4]);
        _gczoombox_entrypoint_10(arg0->actorData[4]);
    }
    arg0->actorData[5] = state;
    _gczoombox_entrypoint_4(arg0->actorData[4]);
}

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
    void func_80800CA0_chgameselect();
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
    s32 _gczoombox_entrypoint_2();
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

void func_80802640_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    int _gczoombox_entrypoint_32();
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    void _gldbstring_entrypoint_2(s32);
    Actor *actor;
    s32 textId;
    s32 *textIdSource = &arg1;

    actor = func_80106790(arg0);
    textId = *textIdSource;
    if (textId != actor->actorData[0]) {
        if (actor->actorData[6] != 0) {
            _gldbstring_entrypoint_2(actor->actorData[0]);
            textId = *textIdSource;
            actor->actorData[6] = 0;
        }
        actor->actorData[0] = textId;
        if (textId != 0) {
            *(u32 **)&actor->actorData[6] = _gldbstring_entrypoint_0(*(u32 **)&actor->actorData[6], textId);
        }
        actor->actorData[1] = -1;
        _gczoombox_entrypoint_32(actor->actorData[4]);
    }
}

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
void func_808027DC_chgameselect(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _gcnewoption_entrypoint_0(s32);
    s32 _gcnewoption_entrypoint_17();
    s32 _gcnewoption_entrypoint_45(s32);
    s32 _gcnewoption_entrypoint_48(s32);
    s32 func_80015FA0(s32);
    s32 func_80016B54(s32, s32);
    void func_80803604_chgameselect(s32, s32, s32, s32);
    void func_80803C60_chgameselect(void);
    void func_80803CE0_chgameselect(void);
    s32 pad[4];
    OptionState *option;
    s8 *entries;
    s32 i;
    s8 selected;

    option = func_80100094(arg0, 0);
    if (option != NULL) {
        if (arg0->unk64_20 && _gcnewoption_entrypoint_48((s32)option)) {
            func_80800AEC_chgameselect(arg0->unk3C, option, -1, 0xFF);
        }
        switch (arg0->unk70_10) {
            case 2:
                entries = func_80100094(arg0, 1);
                selected = (_gcnewoption_entrypoint_45((s32)option) * 6 + entries)[3];
                if (selected >= 0) {
                    func_808026C8_chgameselect((Unk80132ED0 *)func_80106790(arg0->unk3C)->actorData[3], selected);
                }
                break;
            case 3:
                if (func_80015FA0(0) == 1) {
                    for (i = 0; i < (s32)arg0->actorData[5]; i++) {
                        if (_gcnewoption_entrypoint_17(option, i)) {
                            break;
                        }
                    }
                    if (i < (s32)arg0->actorData[5]) {
                        _gcnewoption_entrypoint_37(option, 0);
                    } else {
                        func_80803C60_chgameselect();
                    }
                } else if (func_80016B54(0, 0) == 1) {
                    for (i = 0; i < (s32)arg0->actorData[5]; i++) {
                        func_80803604_chgameselect((s32)option, i, 0, 0);
                    }
                    func_80803CE0_chgameselect();
                }
                break;
        }
        _gcnewoption_entrypoint_0((s32)option);
    }
}

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

s32 func_80802A0C_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    void func_808030EC_chgameselect(Actor *, void *, s32, s32);
    void func_808034BC_chgameselect(Actor *, void *, s32, s32);
    void func_80800AEC_chgameselect(Unk80132ED0 *, void *, s32, s32);

    if (arg1 == 0x20) {
        switch (arg0->unk70_10) {
            case 2:
                func_808030EC_chgameselect(arg0, func_80101080(), *(s16 *)&arg2, *((s16 *)&arg2 + 1));
                break;
            case 3:
                func_808034BC_chgameselect(arg0, func_80101080(), *(s16 *)&arg2, *((s16 *)&arg2 + 1));
                break;
            default:
                func_80800AEC_chgameselect(arg0->unk3C, func_80101080(), *(s16 *)&arg2, *((s16 *)&arg2 + 1));
                break;
        }
    } else {
        return 0;
    }
    return 1;
}

void func_80802AD4_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void _gcnewoption_entrypoint_4(Actor *, u32, u32 *, u32, s32);
    void _gcnewoption_entrypoint_36(OptionState *);
    void _gcnewoption_entrypoint_8(OptionState *, u32);
    void _gcnewoption_entrypoint_9(OptionState *, u32);
    void _gcnewoption_entrypoint_10(OptionState *, u8);
    void _gcnewoption_entrypoint_40(OptionState *, s32, s32, u8, f32, f32);
    void _gcnewoption_entrypoint_42(OptionState *, f32);
    void _gcnewoption_entrypoint_11(OptionState *);
    extern u32 _gcnewoption_entrypoint_35;
    Actor *actor;
    OptionState *option;
    s32 count;
    u32 visible;
    u8 mode;

    actor = func_80106790(arg0);
    _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_35, 0, arg1);
    option = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(option);
    count = arg4;
    if (count <= 0) {
        count = 5;
    }
    if (arg2 < count) {
        visible = arg2;
    } else {
        visible = count;
    }
    _gcnewoption_entrypoint_8(option, visible);
    _gcnewoption_entrypoint_9(option, arg2);
    if (arg3 != 0) {
        mode = 2;
    } else {
        mode = 3;
    }
    _gcnewoption_entrypoint_10(option, mode);
    _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(option, 0.1f);
    _gcnewoption_entrypoint_11(option);
    func_80101FDC(actor, 1);
}

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
    void func_80802640_chgameselect(Unk80132ED0 *, s32, s32);
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

void func_80802E38_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void _gcnewoption_entrypoint_4(Actor *, u32, u32 *, u32, s32);
    void _gcnewoption_entrypoint_36(OptionState *);
    void _gcnewoption_entrypoint_8(OptionState *, u32);
    void _gcnewoption_entrypoint_9(OptionState *, u32);
    void _gcnewoption_entrypoint_10(OptionState *, u8);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    void _gcnewoption_entrypoint_40(OptionState *, s32, s32, u8, f32, f32);
    void _gcnewoption_entrypoint_42(OptionState *, f32);
    void _gcnewoption_entrypoint_11(OptionState *);
    extern u32 _gcnewoption_entrypoint_35;
    Actor *actor;
    OptionState *option;
    s16 *entry;
    s32 i;

    actor = func_80106790(arg0);
    _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_35, 0, arg1);
    option = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(option);
    if (arg3 <= 0) {
        arg3 = 5;
    }
    _gcnewoption_entrypoint_8(option, (s32)actor->actorData[5] < arg3 ? (s32)actor->actorData[5] : arg3);
    _gcnewoption_entrypoint_9(option, actor->actorData[5]);
    _gcnewoption_entrypoint_10(option, 0);
    i = 0;
    actor->actorData[6] = arg2;
    entry = func_80100094(actor, 1);
    for (; i < (s32)actor->actorData[5]; i++, entry += 3) {
        _gcnewoption_entrypoint_31(option, i, entry[2]);
    }
    _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(option, 0.1f);
    _gcnewoption_entrypoint_11(option);
}

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
    void func_80802640_chgameselect(Unk80132ED0 *, s32, s32);
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

void func_80803048_chgameselect(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    void _gcnewoption_entrypoint_41(OptionState *, s32);
    void func_8080401C_chgameselect(s32, s32, s32);
    s32 var_s0;
    u8 *var_s1;

    var_s1 = func_80100094(arg0, 1U);
    var_s0 = 0;
    if ((s32)arg0->actorData[5] > 0) {
        do {
            _gcnewoption_entrypoint_12(arg1, var_s0, var_s1[1]);
            if (*(s8 *)(var_s1 + 2) >= 0) {
                func_8080401C_chgameselect(arg1, var_s0, 0);
            }
            var_s0 += 1;
            var_s1 += 6;
        } while (var_s0 < (s32)arg0->actorData[5]);
    }
    _gcnewoption_entrypoint_41(arg1, arg0->actorData[6]);
}

void func_808030EC_chgameselect(Actor *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _gcnewoption_entrypoint_19(OptionState *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_80803C60_chgameselect(void);
    void func_80800AEC_chgameselect(Unk80132ED0 *, void *, s32, s32);
    s32 sp2C;
    s32 sp28;
    Actor *sp24;
    s32 sp20;

    switch (arg3) {
    case 0:
        func_80803048_chgameselect(arg0, arg1);
        return;
    case 3:
        if (_gcnewoption_entrypoint_19(arg1, arg2) != 0) {
            func_80803C60_chgameselect();
            sp24 = func_80106790(arg0->unk3C);
            func_808026C8_chgameselect(sp24->actorData[5], ((s8 *)func_80100094(arg0, 1U))[arg2 * 6 + 2]);
            return;
        }
    case 2:
        sp2C = ((u8 *)func_80100094(arg0, 1U))[arg2 * 6];
        func_80802FE4_chgameselect(arg0);
        func_80800AEC_chgameselect(arg0->unk3C, NULL, sp2C, arg3);
        return;
    }
}

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

void func_808032CC_chgameselect(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void _gcnewoption_entrypoint_4(Actor *, u32, u32 *, u32, s32);
    void _gcnewoption_entrypoint_36(OptionState *);
    void _gcnewoption_entrypoint_8(OptionState *, u32);
    void _gcnewoption_entrypoint_9(OptionState *, u32);
    void _gcnewoption_entrypoint_10(OptionState *, u8);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    void _gcnewoption_entrypoint_40(OptionState *, s32, s32, u8, f32, f32);
    void _gcnewoption_entrypoint_42(OptionState *, f32);
    void _gcnewoption_entrypoint_11(OptionState *);
    extern u32 _gcnewoption_entrypoint_35;
    Actor *actor;
    OptionState *option;
    s16 *entry;
    s32 i;

    actor = func_80106790(arg0);
    _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_35, 0, arg1);
    option = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(option);
    if (arg3 <= 0) {
        arg3 = 5;
    }
    _gcnewoption_entrypoint_8(option, (s32)actor->actorData[5] < arg3 ? (s32)actor->actorData[5] : arg3);
    _gcnewoption_entrypoint_9(option, actor->actorData[5]);
    _gcnewoption_entrypoint_10(option, 2);
    i = 0;
    actor->actorData[6] = arg2;
    entry = func_80100094(actor, 1);
    for (; i < (s32)actor->actorData[5]; i++, entry += 3) {
        _gcnewoption_entrypoint_31(option, i, entry[2]);
    }
    _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(option, 0.1f);
    _gcnewoption_entrypoint_11(option);
}

void func_80803420_chgameselect(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    void _gcnewoption_entrypoint_41(OptionState *, s32);
    void func_80803604_chgameselect(s32, s32, s32, s32);
    s32 var_s0;
    u8 *var_s1;

    var_s1 = func_80100094(arg0, 1U);
    var_s0 = 0;
    if ((s32)arg0->actorData[5] > 0) {
        do {
            _gcnewoption_entrypoint_12(arg1, var_s0, var_s1[1]);
            func_80803604_chgameselect(arg1, var_s0, *(s8 *)(var_s1 + 3), 0);
            var_s0 += 1;
            var_s1 += 6;
        } while (var_s0 < (s32)arg0->actorData[5]);
    }
    _gcnewoption_entrypoint_41(arg1, arg0->actorData[6]);
}

void func_808034BC_chgameselect(Actor *arg0, void *arg1, s32 arg2, s32 arg3) { s32 _gcnewoption_entrypoint_17(); s32 _gcnewoption_entrypoint_20(); void *func_80100094(Actor *, u32); void func_80803604_chgameselect(s32, s32, s32, s32); u8 *sp28[2]; s32 var_a3; s32 var_s0; u8 *var_s1; var_s0 = arg2; switch (arg3) { case 0: func_80803420_chgameselect(arg0, arg1); return; case 4: func_80803604_chgameselect(arg1, var_s0, _gcnewoption_entrypoint_20(arg1, var_s0), 1); return; case 5: _gcnewoption_entrypoint_37(arg1, 1U); return; case 2: case 3: sp28[0] = func_80100094(arg0, 1); func_80800AEC_chgameselect(arg0->unk3C, arg1, -1, 0xFC); var_s0 = 0; var_s1 = sp28[0]; if ((s32)arg0->actorData[5] > 0) { do { if (_gcnewoption_entrypoint_17(arg1, var_s0) != 0) { var_a3 = 0xFE; } else { var_a3 = 0xFD; } func_80800AEC_chgameselect(arg0->unk3C, arg1, *var_s1, var_a3); var_s0 += 1; var_s1 += 6; } while (var_s0 < (s32)arg0->actorData[5]); } func_80802FE4_chgameselect(arg0); func_80800AEC_chgameselect(arg0->unk3C, NULL, -1, arg3); default: return; } }

void func_80803604_chgameselect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_8080407C_chgameselect(s32, s32, s32);
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

s32 func_808036F8_chgameselect()
{
    return _glsavegame_entrypoint_2();
}

s32 func_80803718_chgameselect()
{
    return _glsavegame_entrypoint_3();
}

s32 func_80803738_chgameselect(s32 arg0, s32 *arg1, s32 *arg2) {
    u8 *_glsavegame_entrypoint_4(s32);
    s32 func_800DB7C0(u8 *);
    s32 func_800D04A0(s32, s32);
    u8 *save;

    if (func_808036F8_chgameselect() != 0) {
        save = _glsavegame_entrypoint_4(arg0);
        *arg1 = func_800DB7C0(save);
        *arg2 = func_800D04A0(save, 1);
        return *arg1 < 0 ? 0 : 1;
    }
    return 0;
}

s32 func_808037C0_chgameselect(s32 arg0) {
    u8 *_glsavegame_entrypoint_4(s32);
    s32 func_800D046C(u8 *, s32, s32);
    s32 func_800DAC78(u8 *, s32);
    s32 func_800DB83C(u8 *, s32);
    u8 *save;
    s32 flag441;
    s32 flag5A;
    s32 flag360;

    if (func_808036F8_chgameselect() != 0) {
        save = _glsavegame_entrypoint_4(arg0);
        flag441 = func_800DAC78(save, 0x441);
        flag5A = func_800D046C(save, 0x5A, 1);
        flag360 = func_800DAC78(save, 0x360);
        if ((flag441 == 0) && (flag5A != 0) && (flag360 == 0)) {
            return 0xA4;
        }
        if ((flag441 != 0) && (flag360 != 0)) {
            return 0xA5;
        }
        return func_800DB83C(save, 0x1A) > 0 ? 0xA3 : 0xA2;
    }
    return 0xA1;
}

void func_80803888_chgameselect(s32 arg0, u32 arg1, u32 arg2) {
    void func_80016BDC(s32);
    void func_800C9E20(f32, u32 *, u32, u32);
    void func_80800478_chgameselect(s32, s32);
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
    void func_80800478_chgameselect(s32, s32);
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

s32 _gcstatusDll_entrypoint_15(void);
void func_80803AB0_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_14(void);
    s32 _gcstatusDll_entrypoint_6(s32, s32);
    s32 i;
    s32 status;

    switch (_gcstatusDll_entrypoint_14()) {
        case 4:
        case 6:
            break;
        case 5:
            for (i = 0; i != 4; i++) {
                if (_gcstatusDll_entrypoint_15() == i) {
                    status = 5;
                } else {
                    status = 4;
                }
                _gcstatusDll_entrypoint_6(i, status);
            }
            break;
        default:
            func_80803940_chgameselect();
            break;
    }
}

void func_80803B3C_chgameselect(s32 arg0) {
    s32 _gcstatusDll_entrypoint_10(void);
    void func_80016BDC(s32);
    void func_800C9DAC(f32, void *);
    void func_80800478_chgameselect(s32, s32);
    extern void func_800AA1A0(void);
    func_80016BDC(_gcstatusDll_entrypoint_10());
    func_800C9DAC(1.5f, func_800AA1A0);
    func_80800478_chgameselect(arg0, 8);
}

struct Entry { s32 id; void (*callback)(void *); };
void func_80803B84_chgameselect(s32 arg0) { s32 func_800AA120(void); extern struct Entry D_80808370_chgameselect[]; extern struct Entry D_808083A0_chgameselect[]; struct Entry *var_v1; struct Entry *end; s32 temp_v0; temp_v0 = func_800AA120(); end = D_808083A0_chgameselect; var_v1 = D_80808370_chgameselect; loop_1: if (temp_v0 == var_v1->id) { var_v1->callback(end); } else { var_v1++; if (var_v1 != end) { goto loop_1; } } func_80803B3C_chgameselect(arg0); }

void func_80803BE8_chgameselect(Actor *arg0) { void func_800AA054(s32); void func_800AA074(); s32 func_800AA120(void); extern struct Entry D_808083A0_chgameselect[]; extern struct Entry D_808083C8_chgameselect[]; struct Entry *var_v1; struct Entry *end; s32 temp_v0;  func_800AA074(); func_800AA054(*(s32 *)&arg0->unk54); temp_v0 = func_800AA120(); end = D_808083C8_chgameselect; var_v1 = D_808083A0_chgameselect; loop_1: if (temp_v0 == var_v1->id) { var_v1->callback(end); } else { var_v1++; if (var_v1 != end) { goto loop_1; } } func_80803B3C_chgameselect(arg0); }

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

s32 func_80803D60_chgameselect(s32 arg0) {
    s32 _gcfrontend_entrypoint_1(s32);
    s32 _gcfrontend_entrypoint_2(void);
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        func_808036F8_chgameselect();
        return;
    case 5:
        return _gcfrontend_entrypoint_1(3);
    case 7:
        return _gcfrontend_entrypoint_2();
    default:
        return 1;
    }
}

s32 func_80803DCC_chgameselect(s32 arg0) {
    s32 _gcfrontend_entrypoint_1(s32);
    s32 _gcfrontend_entrypoint_2(void);
    switch (arg0) {
    case 5:
        return _gcfrontend_entrypoint_1(3) ? 1 : 0;
    case 7:
        return _gcfrontend_entrypoint_2() ? 1 : 0;
    default:
        return 0;
    }
}

s32 func_80803E40_chgameselect(void) {
    s32 func_80016800(s32);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!func_80016800(i)) return i;
    }
    return i;
}

void func_80803E94_chgameselect(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void func_800E6DB4(char *, s32);
    s32 value;
    s32 index;
    char *text;
    char *dest;
    char *src;
    u8 ch;

    text = (char *)_gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, arg1), arg2);
    src = text;
    dest = arg0;
    index = 0;
    if (*text != 0) {
        do {
            *dest = 0;
            ch = *src;
            if (ch == 0x7E) {
                value = arg4[index];
                index++;
                dest = arg0;
                func_800E6DB4(arg0, value);
                while (*dest != 0) {
                    dest++;
                }
            } else {
                *dest = ch;
                dest++;
            }
            src++;
        } while (*src != 0);
    }
    *dest = 0;
    _gldbstring_entrypoint_2(arg1);
}

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

void func_8080401C_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_13(s32, s32, s32 *);
    s32 _gcnewoption_entrypoint_19(OptionState *, s32);
    s32 _gcnewoption_entrypoint_23(s32, s32);
    extern struct Entry D_808083C8_chgameselect[];
    if (_gcnewoption_entrypoint_19(arg0, arg1) == 0) {
        _gcnewoption_entrypoint_23(arg0, arg1);
        _gcnewoption_entrypoint_13(arg0, arg1, &D_808083C8_chgameselect[0].id);
        if (arg2 != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

void func_8080407C_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_13(s32, s32, s32 *);
    s32 _gcnewoption_entrypoint_17();
    s32 _gcnewoption_entrypoint_21(s32, s32);
    extern s32 D_808083D0_chgameselect;
    if (_gcnewoption_entrypoint_17() == 0) {
        _gcnewoption_entrypoint_21(arg0, arg1);
        _gcnewoption_entrypoint_13(arg0, arg1, &D_808083D0_chgameselect);
        if (arg2 != 0) {
            func_80803CC0_chgameselect();
        }
    }
}

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

s32 func_8080413C_chgameselect(Actor *arg0) { void func_800DA3B8(s32, s32); func_8080218C_chgameselect(arg0->unk79_4, 1); func_80801658_chgameselect(arg0->actorData[4], 1); func_80803D00_chgameselect(arg0->unk79_4 + 8, 1); func_800DA3B8(0xD69, func_80803718_chgameselect()); func_80803888_chgameselect((s32)arg0, func_808037C0_chgameselect(arg0->unk79_4), 0); return -1; }

/* extern */

s32 func_808041C8_chgameselect(void *arg0) {
    void func_808015DC_chgameselect(Unk80132ED0 *, s32);
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
    void func_808015DC_chgameselect(Unk80132ED0 *, s32);
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

int func_808042A8_chgameselect(Actor *arg0, s32 arg1, s32 *arg2) {
    typedef struct {
    s32 state;
    s32 first;
    s32 second;
    s32 unused;
    Unk80132ED0 *marker;
    } GameSelectData;
    s32 result;
    s32 state;
    result = 0;
    state = ((GameSelectData *)arg0->actorData)->state;
    switch (state) {
    case 0:
    if (func_808036F8_chgameselect(arg1) != 0) {
    *arg2 = 2;
    ((GameSelectData *)arg0->actorData)->state = 1;
    ((GameSelectData *)arg0->actorData)->first = arg1;
    func_80801758_chgameselect(((GameSelectData *)arg0->actorData)->marker, arg1);
    func_8080218C_chgameselect(arg1, 0);
    } else {
    *arg2 = 6;
    result = 1;
    } break;
    case 1:
    if (func_808036F8_chgameselect(arg1) != 0) {
    *arg2 = 8;
    result = 1;
    } else {
    *arg2 = 3;
    ((GameSelectData *)arg0->actorData)->state = 2;
    ((GameSelectData *)arg0->actorData)->second = arg1;
    func_80801658_chgameselect((s32)((GameSelectData *)arg0->actorData)->marker, 1);
    arg0->unk64_20 = 1;
    } break;
    case 2:
    if (!arg0->unk64_20) {
    *arg2 = 4;
    ((GameSelectData *)arg0->actorData)->state = 3;
    func_80803698_chgameselect(((GameSelectData *)arg0->actorData)->second, ((GameSelectData *)arg0->actorData)->first);
    func_80801714_chgameselect(((GameSelectData *)arg0->actorData)->marker, 1);
    }
    break;
    default:
    break;
    }
    return result;
    }

void func_80804404_chgameselect(u8 *arg0, s32 arg1) {
    void func_80800478_chgameselect();

    if (*(s32 *)(arg0 + 0x18) >= 3) {
        func_80800478_chgameselect(arg0, 1);
    } else {
        arg0[0x65] &= ~0x10;
    }
}

/* extern */

s32 func_8080444C_chgameselect(void *arg0) {
    void func_808015DC_chgameselect(Unk80132ED0 *, s32);
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
    void func_808015DC_chgameselect(Unk80132ED0 *, s32);
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

s32 func_8080450C_chgameselect(Actor *arg0, s32 arg1, s32 *arg2) {
    s32 result = 0;

    switch (arg0->actorData[0]) {
        case 0:
            if (func_808036F8_chgameselect(arg1) != 0) {
                *arg2 = 2;
                arg0->actorData[0] = 1;
                arg0->actorData[1] = arg1;
                func_80801658_chgameselect(arg0->actorData[4], 1);
                arg0->unk64_20 = 1;
            } else {
                *arg2 = 5;
                result = 1;
            }
            break;
        case 1:
            if (!arg0->unk64_20) {
                *arg2 = 3;
                arg0->actorData[0] = 2;
                func_80803658_chgameselect(arg0->actorData[1]);
                func_80801714_chgameselect((Unk80132ED0 *)arg0->actorData[4], 1);
            }
            break;
    }
    return result;
}

/* extern */

void func_808045E4_chgameselect(u8 *arg0, s32 arg1) {
    void func_80800478_chgameselect(s32, s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) >= 2) {
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
}

s32 func_8080462C_chgameselect(u8 *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    void func_80802AD4_chgameselect(Unk80132ED0 *, s32, s32, s32, s32);
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

s32 _gcnewoption_entrypoint_20(s32, s32, s32, u8 *);
s32 func_80804750_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80803C80_chgameselect(void);
    void func_8080499C_chgameselect(s32, s32);
    void func_80804A38_chgameselect(void *);
    void func_80108B04(Actor *, u32);
    s32 temp_v0;
    s32 sp20;
    s32 var_s0;

    temp_v0 = arg0->actorData[0];
    var_s0 = -1;
    if (temp_v0 == -2) {
        func_80804A38_chgameselect(arg0);
    } else if (temp_v0 != 0) {
        s32 _gcnewoption_entrypoint_20();
        sp20 = _gcnewoption_entrypoint_20(arg1, arg2);
        func_80803C80_chgameselect();
        func_8080499C_chgameselect(arg2, sp20);
        if (arg2 == 1) {
            var_s0 = sp20 != 0 ? 6 : 7;
            arg0->actorData[0] = -2;
        } else {
            func_80804A38_chgameselect(arg0);
        }
    } else if (temp_v0 == 0) {
        func_80802C10_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
        switch (arg2) {
        case 0:
            var_s0 = 2;
            arg0->actorData[0] = -1;
            func_80108B04(arg0, 0x1E8);
            break;
        case 1:
            var_s0 = 3;
            arg0->actorData[0] = 2;
            break;
        case 2:
            var_s0 = 4;
            arg0->actorData[0] = 4;
            break;
        }
    }
    return var_s0;
}

void func_80804878_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void _glglobalsettings_entrypoint_6(s32, s32);
    s32 func_80804948_chgameselect(s32);
    void func_808049E8_chgameselect(s32, s32, s32);
    void func_80804A38_chgameselect(void *);

    if (arg0->actorData[0] != 0) {
        func_80804A38_chgameselect(arg0);
        if (arg2 == 0) {
            _glglobalsettings_entrypoint_6(0, 0);
            return;
        }
        func_808049E8_chgameselect(arg1, arg2, func_80804948_chgameselect(arg2));
        return;
    }
    func_80802C7C_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
}

void func_808048F8_chgameselect(u8 *arg0, s32 *arg1) {
    s32 func_80802C48_chgameselect(Unk80132ED0 *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) < -1) {
        func_80802C48_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))));
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
        *arg1 = 1;
    }
}

s32 func_80804948_chgameselect(s32 arg0) {
    s32 _glglobalsettings_entrypoint_3();
    s32 _glglobalsettings_entrypoint_7();
    switch (arg0) {
        case 1:
            return _glglobalsettings_entrypoint_3();
        case 2:
            return _glglobalsettings_entrypoint_7();
        default:
            return 0;
    }
}

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
    void func_80804C30_chgameselect(void *, s32);
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
    void func_80804C30_chgameselect(void *, s32);
    void func_80800478_chgameselect(s32, s32);
    if (arg2 < 3) {
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
    func_80804C30_chgameselect(arg0, ((Actor *)arg0)->actorData[0]);
}

void func_80804C30_chgameselect(void *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_1(s32);
    void func_80802E38_chgameselect(Unk80132ED0 *, s32, s32, s32);
    extern s32 D_80807DB0_chgameselect[];
    typedef struct { s16 unk0; s16 id; s16 value; } SelectEntry;
    extern SelectEntry D_808083E8_chgameselect[];
    s32 i;
    s32 count;
    s32 selected;

    count = 0;
    selected = 0;
    func_80802D40_chgameselect((Unk80132ED0 *)((Actor *)arg0)->actorData[6], 3, 0);
    for (i = 0; i != 3; i++) {
        if (_gcfrontend_entrypoint_1(D_808083E8_chgameselect[i].id)) { func_80802DB4_chgameselect((Unk80132ED0 *)((Actor *)arg0)->actorData[6], i, i + 10, -1, -1, D_808083E8_chgameselect[i].value);
            if (arg1 == D_808083E8_chgameselect[i].id) {
                selected = count;
            }
            count++;
        }
    }
    func_80802E38_chgameselect((Unk80132ED0 *)((Actor *)arg0)->actorData[6], *(s16 *)&D_80807DB0_chgameselect[(u32)((Actor *)arg0)->unk79_4], selected, 0);
    func_808026C8_chgameselect((Unk80132ED0 *)((Actor *)arg0)->actorData[5], 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804D30_chgameselect.s")

s32 func_80804E34_chgameselect(u8 *arg0) {
    s32 _gcstatusDll_entrypoint_17();
    s32 _gcstatusDll_entrypoint_18(void);
    u32 func_800AA0B8(void);
    void func_80805310_chgameselect(u8 *);
    void func_808065C0_chgameselect(s32);

    func_80801658_chgameselect(((Actor *)arg0)->actorData[4], 1);
    if (_gcstatusDll_entrypoint_18() == 10) {
        ((Actor *)arg0)->actorData[2] = 0;
    } else if (_gcstatusDll_entrypoint_18() == 20) {
        ((Actor *)arg0)->actorData[2] = 1;
    } else if (_gcstatusDll_entrypoint_17() == 5) {
        ((Actor *)arg0)->actorData[2] = 2;
    } else if (_gcstatusDll_entrypoint_17() == 10) {
        ((Actor *)arg0)->actorData[2] = 3;
    } else {
        ((Actor *)arg0)->actorData[2] = 0;
    }
    ((Actor *)arg0)->unk64_20 = 0;
    if (func_800AA0B8()) {
        func_808065C0_chgameselect((s32)arg0);
    } else {
        func_80805310_chgameselect(arg0);
        func_80803D00_chgameselect(4, 1);
    }
    return -1;
}

/* extern */

void func_80804F14_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
}

void func_80804F38_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcstatusDll_entrypoint_2(s32);
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_10(void);
    s32 _gcstatusDll_entrypoint_14();
    s32 _gcfrontend_entrypoint_6(s32);
    s32 func_808068E8_chgameselect(void);
    void func_808069C8_chgameselect(s32);
    s32 func_80806A30_chgameselect(void);
    void func_80806A88_chgameselect();
    void func_80805474_chgameselect(s32, s32);
    void func_80805BFC_chgameselect(Actor *, s32);
    void func_80806408_chgameselect(Actor *);
    void func_80806540_chgameselect(s32);
    void func_80805CD8_chgameselect(Actor *, s32);
    void func_8080537C_chgameselect(Actor *, s32, s32);
    void func_80805F30_chgameselect(s32, s32);
    void func_80805FCC_chgameselect(s32, s32);
    void func_80806744_chgameselect(void *);
    void func_808061A8_chgameselect(Actor *);
    void func_80806834_chgameselect(void *);
    s32 func_80805ECC_chgameselect(s32 *, s32);
    void func_80806068_chgameselect(void *, s32, s32);
    void func_808051B4_chgameselect(Actor *, s32, s32);

    switch (arg0->actorData[0]) {
    case 0:
        func_80802BE8_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
        _gcstatusDll_entrypoint_2(arg2 + 2);
        func_808069C8_chgameselect(func_808068E8_chgameselect());
        func_80806A88_chgameselect(func_80806A30_chgameselect());
        if (_gcstatusDll_entrypoint_10() < 3 && _gcstatusDll_entrypoint_14() == 4) {
            _gcstatusDll_entrypoint_4(1);
        }
        func_80805474_chgameselect((s32)arg0, 0);
        return;
    case 1:
        switch (arg2) {
        case 0:
            func_80805BFC_chgameselect(arg0, 0);
            return;
        case 1:
            func_80806408_chgameselect(arg0);
            return;
        case 2:
            func_80806540_chgameselect((s32)arg0);
            return;
        }
        return;
    case 2:
        *(s32 *)&arg0->unk54 = arg2;
        switch (_gcfrontend_entrypoint_6(arg2)) {
        case 1:
            func_80805CD8_chgameselect(arg0, 0);
            return;
        case 2:
            func_8080537C_chgameselect(arg0, 10, 0);
            return;
        case 3:
            func_8080537C_chgameselect(arg0, 11, 0);
            return;
        }
        func_80803BE8_chgameselect(arg0);
        return;
    case 10:
        func_80805F30_chgameselect((s32)arg0, arg2);
        func_80803BE8_chgameselect(arg0);
        return;
    case 11:
        func_80805FCC_chgameselect((s32)arg0, arg2);
        func_80803BE8_chgameselect(arg0);
        return;
    case 8:
        func_80806744_chgameselect(arg0);
        return;
    case 3:
        switch (arg2) {
        case 0:
            func_808061A8_chgameselect(arg0);
            return;
        case 2:
            func_80806834_chgameselect(arg0);
            return;
        }
        func_8080537C_chgameselect(arg0, arg2 + 4, func_80805ECC_chgameselect((s32 *)arg0, arg2));
        return;
    case 5:
    case 6:
    case 7:
        func_80806068_chgameselect(arg0, arg0->actorData[0] - 4, arg2);
        func_808051B4_chgameselect(arg0, arg1, arg2);
        return;
    default:
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
}

void func_808051B4_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800478_chgameselect(s32, s32);
    void func_80805310_chgameselect(u8 *);
    void func_80805474_chgameselect(s32, s32);
    void func_80805BFC_chgameselect(Actor *, s32);
    void func_80805CD8_chgameselect(Actor *, s32);
    void func_80806370_chgameselect(Actor *, s32);
    void func_808068AC_chgameselect(void *, s32);

    switch (arg0->actorData[0]) {
    case 0:
        func_80802BE8_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    case 1:
        func_80805310_chgameselect((u8 *)arg0);
        return;
    case 2:
        func_80805474_chgameselect((s32)arg0, 0);
        return;
    case 8:
        func_80805474_chgameselect((s32)arg0, 1);
        return;
    case 3:
        if (arg0->unk64_20) {
            func_80803BE8_chgameselect(arg0);
            return;
        }
        func_80805BFC_chgameselect(arg0, 0);
        return;
    case 10:
    case 11:
        func_80805BFC_chgameselect(arg0, 0);
        return;
    case 5:
        func_80805CD8_chgameselect(arg0, 1);
        return;
    case 6:
        func_808068AC_chgameselect(arg0, arg1);
        func_80805CD8_chgameselect(arg0, 2);
        return;
    case 7:
        func_80805CD8_chgameselect(arg0, 3);
        return;
    case 4:
        func_80806370_chgameselect(arg0, arg1);
        func_80805CD8_chgameselect(arg0, 0);
        return;
    default:
        func_80800478_chgameselect((s32)arg0, 1);
        return;
    }
}

void func_80805310_chgameselect(u8 *arg0) {
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    void func_80802AD4_chgameselect(Unk80132ED0 *, s32, s32, s32, s32);
    void func_80802D04_chgameselect(Unk80132ED0 *, s32);
    extern s32 D_80807DB0_chgameselect[];
    func_80802AD4_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), *(s16 *)&D_80807DB0_chgameselect[(u32)((Actor *)arg0)->unk79_4], 3, 1, 0);
    func_80802D04_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x30))), 1);
    func_808026C8_chgameselect((*(Unk80132ED0 **)((s8 *)(arg0) + (0x2C))), 2);
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
}

void func_8080537C_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80802E38_chgameselect(Unk80132ED0 *, s32, s32, s32);
    extern u8 D_80808424_chgameselect[];
    s32 i;
    s32 offset;
    s8 firstOffset;
    u8 *items;
    u8 item;
    u8 *entry;

    entry = D_80808424_chgameselect + arg1 * 12;
    func_80802D40_chgameselect((Unk80132ED0 *)arg0->actorData[6], (s32) entry[0], (s32) *(s16 *)(entry + 6));
    i = 0;
    if ((s32)entry[0] > 0) {
loop:
        {
firstOffset = *(s8 *)(entry + 3); offset = firstOffset >= 0 ? firstOffset + i : -1; items = *(u8 **)(entry + 8); item = items != NULL ? items[i] : 0x9D; func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], i, entry[1] + i, -1, offset, item); i++;
        }
        if (i < (s32)entry[0]) goto loop;
    }
    func_80802E38_chgameselect((Unk80132ED0 *)arg0->actorData[6], (s32) *(s16 *)(entry + 4), arg2, 4);
    func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], (s32) entry[2]);
    arg0->actorData[0] = arg1;
}

void func_80805474_chgameselect(s32 arg0,s32 arg1)
{
    func_8080537C_chgameselect(arg0,0x1,arg1);
}

void func_80805498_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    void _gcnewoption_entrypoint_41(OptionState *, s32);
    s32 _gcstatusDll_entrypoint_10(void);
    void func_80805BA0_chgameselect(s32, s32, s32);
    s32 func_80805ECC_chgameselect(s32 *, s32);
    void func_80806218_chgameselect(s32, s32, s32, s32);
    s32 func_808062A8_chgameselect();
    s32 func_808068E8_chgameselect(void);
    s32 func_80806A30_chgameselect(void);
    void func_80806AF4_chgameselect(s32, s32, s32);
    extern u8 D_808083FC_chgameselect[];
    extern u8 D_8080840C_chgameselect[];
    s32 i;
    s32 count;
    s32 selected;
    u8 *icons;

    selected = arg0->actorData[0];
    switch (selected) {
    case 0:
        i = 0;
        icons = D_808083FC_chgameselect;
        do {
            _gcnewoption_entrypoint_12(arg1, i, i + 12);
            _gcnewoption_entrypoint_31(arg1, i, *icons);
            func_80805BA0_chgameselect(arg1, i, 0);
            i++;
            icons++;
        } while (i != 3);
        selected = _gcstatusDll_entrypoint_10() >= 2 ? _gcstatusDll_entrypoint_10() - 2 : 0;
        _gcnewoption_entrypoint_41((OptionState *)arg1, selected);
        break;
    case 4:
        count = _gcstatusDll_entrypoint_10();
        for (i = 0; i < count; i++) {
            func_80806218_chgameselect(arg1, i, func_808062A8_chgameselect(i), 0);
        }
        break;
    case 6:
        _gcnewoption_entrypoint_12(arg1, 0, 0);
        _gcnewoption_entrypoint_12(arg1, 1, 1);
        _gcnewoption_entrypoint_12(arg1, 2, 2);
        func_80806AF4_chgameselect(arg1, 4, func_80806A30_chgameselect());
        if (_gcstatusDll_entrypoint_10() < 3) {
            _gcnewoption_entrypoint_12(arg1, 3, 12);
            func_8080401C_chgameselect(arg1, 3, 0);
        } else {
            func_80806AF4_chgameselect(arg1, 3, func_808068E8_chgameselect());
        }
        icons = D_8080840C_chgameselect;
        i = 0;
        do {
            _gcnewoption_entrypoint_31(arg1, i, *icons);
            i++;
            icons++;
        } while (i != 5);
        _gcnewoption_entrypoint_41((OptionState *)arg1, func_80805ECC_chgameselect((s32 *)arg0, 2));
        break;
    }
}

void func_8080569C_chgameselect(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 state[4];
        f32 timer[4];
    } SelectControllers;
    void _gcnewoption_entrypoint_43(s32, s32, s32);
    s32 _gcnewoption_entrypoint_45(s32);
    s32 _gcstatusDll_entrypoint_10(void);
    void func_80015E80(s32, void *);
    s32 func_80015FA0(s32);
    void func_80016068(u32, f32 *);
    s32 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    void func_80805BA0_chgameselect(s32, s32, s32);
    void func_808062EC_chgameselect();
    SelectControllers *data;
    s32 count;
    s32 buttons[6];
    f32 stick[2];
    s32 i;

    switch (arg0->actorData[0]) {
    case 0:
        for (i = 0; i < 3; i++) {
            func_80805BA0_chgameselect(arg1, i, 1);
        }
        break;
    case 4:
        count = _gcstatusDll_entrypoint_10();
        data = func_80100094(arg0, 1);
        for (i = 0; i < count; i++) {
            func_80016068(i, stick);
            func_80015E80(i, buttons);
            switch (data->state[i]) {
            case 1:
                if (func_800D9078(&data->timer[i])) {
                    data->state[i] = 0;
                }
                break;
            case 0:
                if (buttons[0] == 1) {
                    data->state[i] = 2;
                    _gcnewoption_entrypoint_43(arg1, i, 1);
                    func_80803CC0_chgameselect();
                } else if (stick[0] > 0.8f) {
                    func_808062EC_chgameselect(arg1, i, 1);
                    data->state[i] = 1;
                    data->timer[i] = 0.5f;
                } else if (stick[0] < -0.8f) {
                    func_808062EC_chgameselect(arg1, i, -1);
                    data->state[i] = 1;
                    data->timer[i] = 0.5f;
                }
                break;
            case 2:
                if (buttons[1] == 1) {
                    data->state[i] = 0;
                    _gcnewoption_entrypoint_43(arg1, i, 0);
                    func_80803CE0_chgameselect();
                }
                break;
            }
        }
        for (i = 0; i < count; i++) {
            if (data->state[i] != 2) {
                break;
            }
        }
        if (i == count && func_80802F8C_chgameselect((Unk80132ED0 *)arg0->actorData[6])) {
            arg0->unk64_20 = 1;
        }
        break;
    case 6:
        func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[3], _gcnewoption_entrypoint_45(arg1) + 30);
        break;
    default:
        if (func_80015FA0(0) && func_80802F8C_chgameselect((Unk80132ED0 *)arg0->actorData[6])) {
            arg0->unk64_20 = 1;
        }
        break;
    }
}

s32 func_8080595C_chgameselect(Actor *arg0, OptionState *arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_19(OptionState *, s32);
    s32 _gcnewoption_entrypoint_20();
    void func_80803C60_chgameselect(void);
    void func_80803C80_chgameselect(void);
    void func_808069C8_chgameselect(s32);
    void func_80806A88_chgameselect();
    s32 temp;

    switch (arg0->actorData[0]) {
    case 0:
        if (_gcnewoption_entrypoint_19(arg1, arg2) != 0) {
            func_80803C60_chgameselect();
            return arg2 + 0x23;
        }
        func_80802CC0_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
        break;
    case 6:
        if (arg2 == 3 || arg2 == 4) {
            if (arg0->actorData[1] != -1) {
                temp = _gcnewoption_entrypoint_20(arg1, arg2);
                if (arg2 == 3) {
                    func_808069C8_chgameselect(temp);
                } else {
                    func_80806A88_chgameselect(temp);
                }
                arg0->actorData[1] = -1;
            } else {
                if (_gcnewoption_entrypoint_19(arg1, arg2) != 0) {
                    func_80803C60_chgameselect();
                    return 0x1E;
                }
                func_80802C10_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
                arg0->actorData[1] = arg2;
                return arg2 == 3 ? 0x1F : 0x20;
            }
        }
        func_80802CC0_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
        func_80803C80_chgameselect();
        break;
    }
    return -1;
}

void func_80805AC0_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    s32 func_80802C48_chgameselect(Unk80132ED0 *);
    void func_80802C7C_chgameselect(Unk80132ED0 *);
    s32 func_808068E8_chgameselect(void);
    s32 func_80806A30_chgameselect(void);
    void func_80806AF4_chgameselect(s32, s32, s32);
    s32 state;
    s32 temp;
    Actor *actor;

    actor = arg0;
    state = actor->actorData[0];
    switch (state) {
    case 0:
        func_80802C7C_chgameselect((Unk80132ED0 *)actor->actorData[6]);
        return;
    case 6:
        temp = actor->actorData[1];
        if (temp != -1 && arg2 == temp) {
            func_80802C48_chgameselect((Unk80132ED0 *)actor->actorData[6]);
            func_808026C8_chgameselect((Unk80132ED0 *)actor->actorData[5], 9);
            actor->actorData[1] = -1;
            if (arg2 == 3) {
                state = func_808068E8_chgameselect();
            } else {
                state = func_80806A30_chgameselect();
            }
            func_80806AF4_chgameselect(arg1, arg2, state);
            return;
        }
        func_80802C7C_chgameselect((Unk80132ED0 *)actor->actorData[6]);
        return;
    }
}

/* extern */

void func_80805BA0_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80803E40_chgameselect();
    void func_8080401C_chgameselect(s32, s32, s32);
    void func_8080407C_chgameselect(s32, s32, s32);
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

void func_80805CD8_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_14();
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 func_80805ECC_chgameselect(s32 *, s32);
    void func_80806068_chgameselect(void *, s32, s32);
    s32 func_808068E8_chgameselect(void);
    s32 func_80806A30_chgameselect(void);
    void func_80802E38_chgameselect(Unk80132ED0 *, s32, s32, s32);
    extern u8 D_80808404_chgameselect;
    extern u8 D_80808405_chgameselect;
    extern u8 D_80808406_chgameselect;
    extern u8 D_80808407_chgameselect;
    s32 flag;
    s32 value;
    s32 selection;

    flag = 0;
    func_80806068_chgameselect(arg0, 1, arg0->actorData[2]);
    if (_gcstatusDll_entrypoint_14() == 6) {
        _gcstatusDll_entrypoint_4(1);
    }
    func_80806068_chgameselect(arg0, 2, _gcstatusDll_entrypoint_14() - 1);
    value = func_80805ECC_chgameselect((s32 *)arg0, 2);
    if (value == 2 || value == 4) {
        flag = 1;
    }
    switch (value) {
    default:
        selection = value + 5;
        break;
    case 3:
        selection = func_808068E8_chgameselect() + 10;
        break;
    case 4:
        selection = func_80806A30_chgameselect() + 20;
        break;
    }
    func_80802D40_chgameselect((Unk80132ED0 *)arg0->actorData[6], 4, 0);
    func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], 0, 0, -1, -1, D_80808404_chgameselect);
    value = func_80805ECC_chgameselect((s32 *)arg0, 1);
    func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], 1, value + 0x23, flag ? 0x26 : -1, -1, D_80808405_chgameselect);
    func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], 2, selection, -1, -1, D_80808406_chgameselect);
    value = func_80805ECC_chgameselect((s32 *)arg0, 3);
    func_80802DB4_chgameselect((Unk80132ED0 *)arg0->actorData[6], 3, value + 0x1B, flag ? 0x27 : -1, -1, D_80808407_chgameselect);
    func_80802E38_chgameselect((Unk80132ED0 *)arg0->actorData[6], 0x18F4, arg1, 4);
    func_808026C8_chgameselect((Unk80132ED0 *)arg0->actorData[5], 6);
    arg0->actorData[0] = 3;
    func_80802D04_chgameselect((Unk80132ED0 *)arg0->actorData[6], 1);
}

s32 func_80805ECC_chgameselect(s32 *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_14();
    s32 _gcstatusDll_entrypoint_19(void);

    switch (arg1) {
    case 1:
        return arg0[8];
    case 2:
        return _gcstatusDll_entrypoint_14() - 1;
    case 3:
        return _gcstatusDll_entrypoint_19() - 2;
    default:
        return 0;
    }
}

void func_80805F30_chgameselect(s32 arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    switch (arg1) {
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
        _gcstatusDll_entrypoint_7(2);
        break;
    case 3:
        _gcstatusDll_entrypoint_8(0);
        _gcstatusDll_entrypoint_7(5);
        break;
    }
}

void func_80805FCC_chgameselect(s32 arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    switch (arg1) {
    case 0:
        _gcstatusDll_entrypoint_8(15);
        _gcstatusDll_entrypoint_7(0);
        break;
    case 1:
        _gcstatusDll_entrypoint_8(30);
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
}

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
    void func_80802AD4_chgameselect(Unk80132ED0 *, s32, s32, s32, s32);
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

void func_80806370_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_10(void);
    s32 _gcnewoption_entrypoint_20();
    u32 *func_80100074(Actor *, u32, u32);
    s32 count;
    s32 i;

    count = _gcstatusDll_entrypoint_10();
    i = 0;
    arg0->unk64_20 = 0;
    if (count > 0) {
        do {
            func_808062CC_chgameselect(i, _gcnewoption_entrypoint_20(arg1, i));
            i++;
        } while (i < count);
    }
    func_80802BE8_chgameselect((Unk80132ED0 *)arg0->actorData[6]);
    func_80100074(arg0, 1, 0);
}

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
    void func_80806744_chgameselect(void *);
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
    void func_80108B04(Actor *, u32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_80803D00_chgameselect(7, 1);
    func_80108B04(arg0, 0x4B6);
}

void func_808065F4_chgameselect(Actor *arg0) {
    void func_800AA00C(void);
    void func_800AA074(void);
    s32 func_800AA0D0(void);
    s32 func_800AA240(void);
    s32 func_808066CC_chgameselect(void);
    void func_80806744_chgameselect(void *);
    extern s32 D_80807DB0_chgameselect[];
    s32 count;
    s32 state;

    func_80802640_chgameselect((Unk80132ED0 *)arg0->actorData[5],
        *(s16 *)&D_80807DB0_chgameselect[(u32)arg0->unk79_4], 0);
    if (func_800AA240() != 0) {
        count = func_800AA0D0();
        if (count == 1) {
            state = 0;
            func_800AA074();
        } else {
            if (func_808066CC_chgameselect() == count) {
                state = 2;
                func_800AA074();
            } else {
                state = 1;
            }
        }
        func_800AA00C();
        func_80805474_chgameselect((s32)arg0, state);
        func_80803D00_chgameselect(4, 1);
    } else {
        func_80806744_chgameselect(arg0);
    }
}

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

void func_80806744_chgameselect(void *arg0) {
    s32 _gcfrontend_entrypoint_5(s32);
    s32 func_800AA0C4(void);
    s32 func_800AA0D0(void);
    s32 func_800AA120(void);
    void func_800E6A58(char *, char);
    extern s16 B_80808550_chgameselect[];
    struct Fields {
        u8 pad0[0x18];
        s32 state;
        u8 pad1[0x10];
        Unk80132ED0 *text;
        u8 pad2[0x20];
        char *buffer;
    };
    s32 count;
    s32 total;

    count = func_800AA0C4() + 1;
    B_80808550_chgameselect[0] = 0x18F2;
    if (func_800AA0D0() == count + 1) {
        B_80808550_chgameselect[1] = 0x27;
    } else {
        B_80808550_chgameselect[1] = count;
    }
    B_80808550_chgameselect[2] = 0x18E4;
    total = func_800AA120();
    B_80808550_chgameselect[3] = total - _gcfrontend_entrypoint_5(3);
    func_80803F90_chgameselect(((struct Fields *)arg0)->buffer, 2, B_80808550_chgameselect);
    func_800E6A58(((struct Fields *)arg0)->buffer, 0x21);
    func_80802730_chgameselect(((struct Fields *)arg0)->text, (s32) ((struct Fields *)arg0)->buffer);
    ((struct Fields *)arg0)->state = 9;
}

/* extern */

void func_80806800_chgameselect(void *arg0, s32 arg1) {
    void func_80803B84_chgameselect();
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) == 9) {
        func_80803B84_chgameselect();
    }
}

/* extern */

void func_80806834_chgameselect(void *arg0) {
    void func_80802640_chgameselect(Unk80132ED0 *, s32, s32);
    void func_808026C8_chgameselect(Unk80132ED0 *, s32);
    void func_80802AD4_chgameselect(Unk80132ED0 *, s32, s32, s32, s32);
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
    void func_80802640_chgameselect(Unk80132ED0 *, s32, s32);
    func_80802BE8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    func_80802640_chgameselect((*(s32 *)((s8 *)(arg0) + (0x24))), 0, 0);
}

s32 func_808068E8_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_10(void);
    s32 _gcstatusDll_entrypoint_16(s32);
    s32 _gcstatusDll_entrypoint_6(s32, s32);
    s32 func_80806AA8_chgameselect(void);
    s32 pad0;
    s32 pad1;
    s32 pad2;
    s32 limit;
    s32 count;
    s32 status;
    s32 i;
    s32 mask;

    mask = 0;
    count = _gcstatusDll_entrypoint_10();
    limit = func_80806AA8_chgameselect();
    for (i = 0; i < count; i++) {
        status = _gcstatusDll_entrypoint_16(i);
        if (status < 4) {
            break;
        }
        if (status == 4) {
            mask |= 1 << i;
        }
    }
    if (i < count) {
        _gcstatusDll_entrypoint_6(0, 4);
        _gcstatusDll_entrypoint_6(1, 5);
        _gcstatusDll_entrypoint_6(2, 5);
        _gcstatusDll_entrypoint_6(3, 5);
        mask = 1;
    }
    if (mask <= 0) {
        mask = 1;
    } else if (limit < mask) {
        mask = limit;
    }
    return mask - 1;
}

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

s32 func_80806AD4_chgameselect(void)
{
    return _gcstatusDll_entrypoint_10();
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

void func_80806B5C_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_20();
    s32 option;
    s32 count;

    option = _gcnewoption_entrypoint_20(arg1, arg2) + 1;
    if (arg2 == 3) {
        count = func_80806AA8_chgameselect();
    } else {
        count = func_80806AD4_chgameselect();
    }
    if (option >= count) {
        option = 0;
    }
    func_80806AF4_chgameselect(arg1, arg2, option);
}

void func_80806BD4_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_20();
    s32 option;
    s32 count;

    option = _gcnewoption_entrypoint_20(arg1, arg2) - 1;
    if (arg2 == 3) {
        count = func_80806AA8_chgameselect();
    } else {
        count = func_80806AD4_chgameselect();
    }
    if (option < 0) {
        option = count - 1;
    }
    func_80806AF4_chgameselect(arg1, arg2, option);
}

OSThread *chgameselect_entrypoint_6(void)
{
    extern u8 D_808084B4_chgameselect[];

    return (OSThread *) D_808084B4_chgameselect;
}

void func_80806C54_chgameselect(Actor *arg0) {
    s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
    s32 _gczoombox_entrypoint_26(s32, s32, f32, f32, s32);
    void func_800C9F48(f32, u8 *, s32);
    void *func_80100094(Actor *, u32);
    void *heap_alloc(s32);
    void func_808073AC_chgameselect(Actor *);
    struct {
        s32 boxes[4];
        void *buffers[4];
        void *buffer;
        s16 unk24;
        s16 unk26;
    } *data, *entry;
    s32 i;
    s32 y;
    s32 box;

    data = func_80100094(arg0, 0);
    arg0->unk6C_0 = _gcstatusDll_entrypoint_10();
    i = 0;
    y = 0x42;
    entry = data;
    if (arg0->unk6C_0) {
      do {
        box = _gczoombox_entrypoint_5(y, 0xC, 2, 0, 0);
        entry->boxes[0] = box;
        _gczoombox_entrypoint_26(box, 0x41, 0.8f, 1.0f, 0);
        func_800C9F48((f32)i * 0.1f, arg0->unk0, i);
        entry->buffers[0] = heap_alloc(0x100);
        i++;
        y += 0x26;
        entry = (void *)((u8 *)entry + sizeof(s32));
      } while ((u32)i < arg0->unk6C_0);
    }
    data->buffer = heap_alloc(0x100);
    data->unk26 = 0;
    data->unk24 = data->unk26;
    func_808073AC_chgameselect(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806D98_chgameselect.s")

void func_80806FAC_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gczoombox_entrypoint_2();
    void *func_80100094(Actor *, u32);
    s32 *entry;
    s32 *data;
    u32 i;

    i = 0;
    data = func_80100094(arg0, 0);
    i = 0;
    entry = data;
    for (; i < arg0->unk6C_0; i++, entry++) {
        _gczoombox_entrypoint_2(*entry, arg1);
    }
}

void func_80807030_chgameselect(Actor *arg0) {
    s32 _gczoombox_entrypoint_0(s32);
    void *func_80100094(Actor *, u32);
    s32 pad;
    u8 *sp28;
    s32 temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    s32 var_s1;
    u8 *temp_v0;
    u8 *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    sp28 = temp_v0;
    var_s1 = 0;
    var_s0 = temp_v0;
    do {
        temp_a0 = *(s32 *)var_s0;
        if (temp_a0 != 0) {
            _gczoombox_entrypoint_0(temp_a0);
        }
        temp_a0_2 = *(void **)(var_s0 + 0x10);
        if (temp_a0_2 != NULL) {
            heap_free(temp_a0_2);
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 0x10);
    temp_a0_3 = *(void **)(sp28 + 0x20);
    if (temp_a0_3 != NULL) {
        heap_free(temp_a0_3);
    }
}

s32 func_808070C0_chgameselect(Actor *arg0, s32 arg1, s32 arg2) {
    void _gczoombox_entrypoint_18();
    void _gczoombox_entrypoint_16(s32);
    s32 _gczoombox_entrypoint_9(s32);
    s32 _gczoombox_entrypoint_11(s32);
    void *func_80100094(Actor *, u32);
    s32 *data;

    if (arg1 == 0x22) {
        data = func_80100094(arg0, 0);
        _gczoombox_entrypoint_18(data[arg2]);
        _gczoombox_entrypoint_16(data[arg2]);
        _gczoombox_entrypoint_9(data[arg2]);
        _gczoombox_entrypoint_11(data[arg2]);
        arg1 = 1;
    } else {
        return 0;
    }
    return arg1;
}

void func_8080714C_chgameselect(Actor *arg0, s32 (*arg1)(s32), s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    typedef struct {
        s32 entries[4];
        char *texts[4];
        char *buffer;
        s16 winner;
    } GameSelectScoreData;
    void *func_80100094(Actor *, u32);
    u32 func_800AA194(void);
    void func_800AA220(s32, s32);
    void _sumultiscore_entrypoint_0(s32 *, s32 *, s32);
    void _sumultiscore_entrypoint_1(s32 *, s32 *, s32);
    int _gczoombox_entrypoint_8();
    void _gczoombox_entrypoint_27(s32, s16 *);
    extern s32 B_80808560_chgameselect[];
    extern s16 D_808084FC_chgameselect[];
    s32 i;
    GameSelectScoreData *data;
    s32 scores[4];
    s32 players[4];

    data = func_80100094(arg0, 0);
    for (i = 0; i < arg0->unk6C_0; i++) {
        scores[i] = arg1(i);
        players[i] = i + 1;
    }
    if (arg6 || !func_800AA194()) {
        _sumultiscore_entrypoint_0(scores, players, arg0->unk6C_0);
    } else {
        _sumultiscore_entrypoint_1(scores, players, arg0->unk6C_0);
    }
    for (i = 0; i < arg0->unk6C_0; i++) {
        B_80808560_chgameselect[0] = players[i];
        B_80808560_chgameselect[1] = scores[i];
        if (i > 0 && scores[i] == scores[i - 1]) {
            B_80808560_chgameselect[2] = B_80808560_chgameselect[2];
        } else {
            B_80808560_chgameselect[2] = 4 - i;
        }
        if (scores[i] == scores[0]) {
            data->winner = i + 1;
        }
        if (arg5 && !arg0->unk64_19) {
            func_800AA220(players[i] - 1, B_80808560_chgameselect[2]);
        }
        func_80803E94_chgameselect(data->texts[i], 0x18F3,
            B_80808560_chgameselect[arg2] == 1 ? arg4 : arg3, 3, B_80808560_chgameselect);
        _gczoombox_entrypoint_8(data->entries[i], data->texts[i]);
        _gczoombox_entrypoint_27(data->entries[i], D_808084FC_chgameselect);
    }
    if (arg5) {
        arg0->unk64_19 = 1;
    }
}

void func_808073AC_chgameselect(Actor *arg0) {
    typedef struct {
        s32 entries[8];
        char *buffer;
    } GameSelectTextData;
    s32 _gcfrontend_entrypoint_5(s32);
    s32 func_800AA0D0(void);
    s32 func_800AA148(void);
    s32 func_800AA180(s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080714C_chgameselect(Actor *, s32 (*)(s32), s32, s32, s32, s32, s32);
    extern s16 B_80808570_chgameselect[4];
    Unk80132ED0 *sp3C;
    GameSelectTextData *sp38;
    s32 sp34;

    sp3C = (Unk80132ED0 *)func_80106790(arg0->unk3C)->actorData[5];
    sp38 = func_80100094(arg0, 0);
    if (func_800AA0D0() == 1) {
        func_8080714C_chgameselect(arg0, func_800AA180, 1, 0x1E, 0x1F, 0, 0);
    } else {
        func_8080714C_chgameselect(arg0, func_800AA180, 2, 0x20, 0x21, 1, 0);
    }
    B_80808570_chgameselect[0] = 0x18E4;
    sp34 = func_800AA148();
    B_80808570_chgameselect[1] = sp34 - _gcfrontend_entrypoint_5(3);
    B_80808570_chgameselect[2] = 0x18F3;
    B_80808570_chgameselect[3] = 0x14;
    func_80803F90_chgameselect(sp38->buffer, 2, B_80808570_chgameselect);
    func_80802730_chgameselect(sp3C, (s32)sp38->buffer);
    arg0->unk64_20 = 0;
}

void func_808074C8_chgameselect(Actor *arg0) {
    typedef struct {
        s32 entries[8];
        char *buffer;
    } GameSelectTextData;
    s32 func_800AA0C4(void);
    s32 func_800AA0D0(void);
    s32 func_800AA16C(s32);
    s32 func_800AA240(void);
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_8080714C_chgameselect(Actor *, s32 (*)(s32), s32, s32, s32, s32, s32);
    extern s32 B_80808588_chgameselect[2];
    GameSelectTextData *sp30[2];
    Unk80132ED0 *temp_s0;

    temp_s0 = (Unk80132ED0 *)func_80106790(arg0->unk3C)->actorData[5];
    func_8080714C_chgameselect(arg0, func_800AA16C, 1, 0x1E, 0x1F, 0, 1);
    if (func_800AA240() != 0) {
        func_80802640_chgameselect(temp_s0, 0x18F3, 0);
        func_808026C8_chgameselect(temp_s0, 0x16);
    } else {
        sp30[0] = func_80100094(arg0, 0);
        B_80808588_chgameselect[0] = func_800AA0C4() + 1;
        B_80808588_chgameselect[1] = func_800AA0D0();
        func_80803E94_chgameselect(sp30[0]->buffer, 0x18F3, 0x15, 2, B_80808588_chgameselect);
        func_80802640_chgameselect(temp_s0, 0, 0);
        func_80802730_chgameselect(temp_s0, (s32)sp30[0]->buffer);
    }
    arg0->unk64_20 = 1;
}

void func_808075D0_chgameselect(Actor *arg0, s32 arg1) {
    typedef struct {
        s32 entries[9];
        s16 count;
        s16 initialized;
    } GameSelectZoomData;
    s32 _gczoombox_entrypoint_11(s32);
    void _gczoombox_entrypoint_12();
    void _gczoombox_entrypoint_17();
    void _gczoombox_entrypoint_18();
    void _gczoombox_entrypoint_34();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_800AA240(void);
    u32 i;
    GameSelectZoomData *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 5:
        if (func_800AA240() && data->initialized == 0) {
            func_80803CA0_chgameselect();
            data->initialized = 1;
        }
    case 2:
        arg0->unk58 = 7.5f;
        break;
    case 3:
        i = 0;
        if (arg0->unk6C_0) {
            do {
            _gczoombox_entrypoint_17(data->entries[i]);
            _gczoombox_entrypoint_12(data->entries[i]);
                i++;
            } while (i < arg0->unk6C_0);
        }
        if (arg0->unk70_10 == 2) {
            func_808074C8_chgameselect(arg0);
        } else if (arg0->unk70_10 == 5) {
            func_808073AC_chgameselect(arg0);
        }
        break;
    case 4:
        i = 0;
        if (arg0->unk6C_0) {
            do {
            _gczoombox_entrypoint_18(data->entries[i]);
            _gczoombox_entrypoint_11(data->entries[i]);
                i++;
            } while (i < arg0->unk6C_0);
        }
        break;
    case 6:
        i = 0;
        if (arg0->unk6C_0) {
            do {
            _gczoombox_entrypoint_34(data->entries[i]);
                i++;
            } while (i < arg0->unk6C_0);
        }
        break;
    }
    func_80101FDC(arg0, arg1);
}

s32 func_80807790_chgameselect(Actor *arg0, s32 arg1) {
    s32 _gczoombox_entrypoint_3();
    void *func_80100094(Actor *, u32);
    s32 *entry;
    s32 *data;
    u32 i;

    i = 0;
    data = func_80100094(arg0, 0);
    i = 0;
    entry = data;
    for (; i < arg0->unk6C_0; i++, entry++) {
        if (_gczoombox_entrypoint_3(*entry) != arg1) {
            return 0;
        }
    }
    return 1;
}

void func_80807824_chgameselect(Actor *arg0) {
    typedef struct {
        s32 entries[9];
        s16 count;
    } GameSelectZoomData;
    void *func_80100094(Actor *, u32);
    s32 func_8001211C(void);
    void _gczoombox_entrypoint_27(s32, s16 *);
    extern s16 B_80808590_chgameselect[];
    GameSelectZoomData *data;
    s32 *entry;
    s32 phase;
    s32 brightness;
    s16 color;
    s32 i;

    data = func_80100094(arg0, 0);
    phase = (func_8001211C() << 5) & 0x1FF;
    brightness = phase;
    if (phase >= 0x100) {
        brightness = 0x200 - phase;
    }
    color = brightness / 2 + 0x7F;
    B_80808590_chgameselect[2] = color;
    B_80808590_chgameselect[1] = color;
    B_80808590_chgameselect[0] = color;
    i = 0;
    entry = data->entries;
    if (data->count > 0) {
        do {
            _gczoombox_entrypoint_27(*entry, B_80808590_chgameselect);
            i++;
            entry++;
        } while (i < data->count);
    }
}

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

s32 func_80807A10_chgameselect(arg0, arg1, arg2) {
    s32 _cadbfunc_entrypoint_0(s32 *);
    s32 _cadbfunc_entrypoint_2(s32 *);
    s32 func_800A5800(s32);
    void func_800E39A8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EFE50(f32 *, void *, void *, f32);
    void func_80101FDC(Actor *, u32);
    void func_800F16AC(u8 *, f32 *, f32 *, f32);
    f32 distance;
    f32 position[3];
    f32 rotation[3];

    func_800E39A8(((Actor *)arg0)->position, ((Actor *)arg0)->rotation);
    func_800A5800(arg1);
    _cadbfunc_entrypoint_0((s32 *)((Actor *)arg0)->actorData);
    _cadbfunc_entrypoint_2((s32 *)&((Actor *)arg0)->actorData[4]);
    distance = func_800EEAD4(((Actor *)arg0)->position, (f32 *)((Actor *)arg0)->actorData);
    switch (arg2) {
    case 0:
        ((f32 *)((Actor *)arg0)->actorData)[7] = 1;
        ((Actor *)arg0)->unk6C_0 = arg1;
        ((Actor *)arg0)->unk64_20 = 0;
        ((f32 *)((Actor *)arg0)->actorData)[3] = 1.0f;
        break;
    case 1:
        ((f32 *)((Actor *)arg0)->actorData)[7] = 0.0f;
        ((Actor *)arg0)->unk6C_0 = arg1;
        ((Actor *)arg0)->unk64_20 = 0;
        ((f32 *)((Actor *)arg0)->actorData)[3] = 1.0f;
        break;
    case 2:
        func_800A5800(((Actor *)arg0)->unk6C_0);
        _cadbfunc_entrypoint_0((s32 *)position);
        _cadbfunc_entrypoint_2((s32 *)rotation);
        func_800EFE50((f32 *)((Actor *)arg0)->actorData, position, (f32 *)((Actor *)arg0)->actorData, 0.3f);
        func_800F16AC((u8 *)&((Actor *)arg0)->actorData[4], rotation, (f32 *)&((Actor *)arg0)->actorData[4], 0.3f);
        ((f32 *)((Actor *)arg0)->actorData)[7] = 0.0f;
        if (((Actor *)arg0)->unk64_20) {
            distance = func_800EEAD4(((Actor *)arg0)->position, (f32 *)((Actor *)arg0)->actorData);
            ((f32 *)((Actor *)arg0)->actorData)[3] = 320.0f / distance;
        } else {
            ((f32 *)((Actor *)arg0)->actorData)[3] = 1.6666666f;
        }
        ((Actor *)arg0)->unk64_20 = 1;
        break;
    case 3:
        ((f32 *)((Actor *)arg0)->actorData)[7] = 0.0f;
        ((Actor *)arg0)->unk6C_0 = arg1;
        ((f32 *)((Actor *)arg0)->actorData)[3] = 1.6666666f;
        ((Actor *)arg0)->unk64_20 = 0;
        break;
    }
    if (distance < 0.01f) {
        func_80101FDC((Actor *)arg0, 1);
    } else {
        func_80101FDC((Actor *)arg0, 2);
    }
}
