#include "common.h"
#include "musicmenu_tables.h"

/* extern */

void func_80800000_chmusicmenu(void *arg0) {
    s32 _capod_entrypoint_21(BtIntPtr, BtIntPtr, s32, s32);
    s32 _capod_entrypoint_22();
    s32 func_800DA298(s32);
    s32 func_80101238(s32, s32);
    s32 temp_a0;
    s32 temp_a0_2;

    if (func_800DA298(0xC0) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
            (((Actor *)arg0)->unk58) = 10.0f;
            _capod_entrypoint_22();
            temp_a0 = (*(s32 *)((s8 *)(arg0) + (0)));
            _capod_entrypoint_21(temp_a0, temp_a0, 0x11, 4);
            (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
            func_80101238(0x6E, 0);
            return;
        }
        (((Actor *)arg0)->unk58) = 15.0f;
        _capod_entrypoint_22();
        temp_a0_2 = (*(s32 *)((s8 *)(arg0) + (0)));
        _capod_entrypoint_21(temp_a0_2, temp_a0_2, 0x12, 4);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 1;
        func_80101238(0x6E, 1);
    }
}

s32 func_808000B4_chmusicmenu(s32 arg0) {
    if (arg0 < 9) {
        return arg0 + 0x1851;
    }
    return arg0 + 0x1860;
}

struct MusicMenuEntry {
    struct MusicMenuTrack *tracks;
    u8 count;
    u8 sound;
    u16 unk6;
};

void func_808000D0_chmusicmenu(Actor *arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_31(BtIntPtr, s32, s16);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) _gcnewoption_entrypoint_32(void *arg0, s16 arg1);
    void _gcnewoption_entrypoint_33(BtIntPtr);
    int func_800DC298(f32);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    struct MusicMenuEntry *entry;
    struct MusicMenuEntry *entry2;
    s32 i;
    s32 j;

    switch (arg0->unk70_10) {
        case 1:
            _gcnewoption_entrypoint_32(arg1, 0x6F);
            for (i = 0; i < 12; i++) {
                entry = &D_808014F4_chmusicmenu[i];
                if (entry->sound == 0x50 && func_800DC298(0.5f)) {
                    _gcnewoption_entrypoint_31(arg1, i, 0x51);
                } else {
                    _gcnewoption_entrypoint_31(arg1, i, entry->sound);
                }
            }
            return;
        case 2:
            _gcnewoption_entrypoint_32(arg1, 0x6F);
            _gcnewoption_entrypoint_33(arg1);
            entry2 = &D_808014F4_chmusicmenu[arg0->actorData[6]];
            j = 0;
            if (entry2->count > 0) {
                do {
                    _gcnewoption_entrypoint_31(arg1, j, entry2->sound);
                    j++;
                    entry2 = &D_808014F4_chmusicmenu[arg0->actorData[6]];
                } while (j < entry2->count);
            }
            return;
    }
}

void func_8080021C_chmusicmenu(Actor *arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_12(void *a0, u32 optionIndex, s16 textIndex);
    void _gcnewoption_entrypoint_13(BtIntPtr arg0, s32 arg1, void *arg2);
    void _gcnewoption_entrypoint_27(BtIntPtr, s32, s32);
    void _gcnewoption_entrypoint_41(BtIntPtr, s32);
    s32 func_800FCF50(s32);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    extern struct MusicMenuColor D_80801554_chmusicmenu;
    extern struct MusicMenuColor D_8080155C_chmusicmenu;
    s32 i;
    struct MusicMenuColor color1;
    struct MusicMenuColor color2;

    switch (arg0->unk70_10) {
        case 1:
            for (i = 0; i < 12; i++) {
                _gcnewoption_entrypoint_12(arg1, i, i + 10);
            }
            if ((s32)arg0->actorData[1] != -1) {
                _gcnewoption_entrypoint_27(arg1, (s32)arg0->actorData[1], 1);
                _gcnewoption_entrypoint_41(arg1, arg0->actorData[1]);
            }
            return;
        case 2:
            color1 = D_80801554_chmusicmenu;
            color2 = D_8080155C_chmusicmenu;
            for (i = 0; i < D_808014F4_chmusicmenu[arg0->actorData[6]].count; i++) {
                _gcnewoption_entrypoint_12(arg1, i, i + 10);
                if (func_800FCF50(D_808014F4_chmusicmenu[arg0->actorData[6]].tracks[i].id)) {
                    _gcnewoption_entrypoint_13(arg1, i, &color1);
                } else {
                    _gcnewoption_entrypoint_13(arg1, i, &color2);
                }
            }
            if (arg0->actorData[1] == arg0->actorData[6]) {
                if ((s32)arg0->actorData[0] != -1) {
                    _gcnewoption_entrypoint_27(arg1, (s32)arg0->actorData[0], 1);
                    _gcnewoption_entrypoint_41(arg1, arg0->actorData[0]);
                }
            }
            break;
    }
}

void func_80800400_chmusicmenu(Actor *arg0) {
    s32 func_800FCDE0(s32, s32, f32);
    s32 func_800FCED0(s32, s32, f32);
    void func_800FEF94(s32, s32, s32, s32 *, s16 *);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    struct MusicMenuActorData {
        s32 selection;
        s32 unk4[2];
        f32 value;
        s32 unk10[2];
        s32 category;
    };
    s32 selection;
    s32 sp38;
    s16 sp36;
    s32 sp30;
    struct MusicMenuTrack *tracks;

    selection = (s32)arg0->actorData[0];
    if (selection >= 0 &&
        (!arg0->unk74_30 || !arg0->unk74_29)) {
        tracks = D_808014F4_chmusicmenu[arg0->actorData[6]].tracks;
        if (tracks[selection].bank != -1) {
            sp38 = -1;
            sp36 = -1;
            sp30 = tracks[arg0->actorData[0]].id;
            func_800FEF94(4, tracks[arg0->actorData[0]].bank, tracks[arg0->actorData[0]].index, &sp38, &sp36);
            if (!arg0->unk74_30) {
                arg0->unk74_30 = func_800FCDE0(sp30, sp38, ((struct MusicMenuActorData *)arg0->actorData)->value);
            }
            if (!arg0->unk74_29) {
                arg0->unk74_29 = func_800FCED0(sp30, 60000000 / sp36, ((struct MusicMenuActorData *)arg0->actorData)->value);
            }
        }
    }
}

void func_80800560_chmusicmenu(Actor *arg0, s32 arg1, f32 arg2) {
    void func_800FC660(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_80800400_chmusicmenu(Actor *);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    struct MusicMenuActorData {
        s32 selection;
        s32 unk4[2];
        f32 value;
        s32 unk10[2];
        s32 category;
    };
    struct MusicMenuTrack *tracks = D_808014F4_chmusicmenu[arg0->actorData[6]].tracks;

    if (arg2 == 0.0f) {
        func_800FC660(tracks[arg0->actorData[0]].id);
    } else {
        func_800FCAE0(tracks[arg0->actorData[0]].id, -1, 0x14D);
    }
    arg0->unk74_30 = 0;
    arg0->unk74_29 = 0;
    ((struct MusicMenuActorData *)arg0->actorData)->value = arg2;
    func_80800400_chmusicmenu(arg0);
}

void func_80800610_chmusicmenu(Actor *arg0) {
    void func_800DA544(GameFlag);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_800FEC60(u32);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    struct MusicMenuActorData {
        s32 selection;
        s32 unk4[2];
        f32 value;
        s32 unk10;
        f32 transition;
        s32 category;
    };
    s16 track;
    struct MusicMenuTrack *tracks;

    if (!arg0->unk64_20) {
        func_800FEC60(5);
        arg0->unk64_20 = 1;
        func_800DA544(0);
    }
    tracks = D_808014F4_chmusicmenu[arg0->actorData[6]].tracks;
    track = tracks[arg0->actorData[0]].id;
    if (arg0->unk74_7) {
        func_800FCAE0((int)arg0->unk74_7, 0, 0x14D);
        func_800FCA90(arg0->unk74_7);
    }
    if (track == (int)arg0->unk74_7) {
        func_80800560_chmusicmenu(arg0, track, 1.5f);
    } else {
        arg0->unk64_19 = 1;
        ((struct MusicMenuActorData *)arg0->actorData)->transition = 2.0f;
    }
    arg0->unk74_7 = track;
}

/* extern */

void func_80800714_chmusicmenu(Actor *arg0) {
    void func_800DA524(s32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_800FE8AC(void);
    void func_800FECB8(u32);
    if (arg0->unk64_20) {
        func_800FECB8(5);
        arg0->unk64_20 = 0;
        func_800FE8AC();
        func_800FCAE0(arg0->unk74_7, 0, 0x14D);
        func_800FCA90(arg0->unk74_7);
        arg0->unk74_7 = 0;
        func_800DA524(0);
    }
}

void func_8080079C_chmusicmenu(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    void _gcnewoption_entrypoint_27(BtIntPtr, s32, s32);
    s32 _gcnewoption_entrypoint_37(BtIntPtr, s32);
    void func_800FC660(u32);
    s32 func_800FCF50(s32);
    BtIntPtr func_80100094(u8 *, s32);
    void func_80800930_chmusicmenu(u8 *, s32);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    Actor *actor = (Actor *)arg0;
    u32 selected;
    s32 index = arg2;

    switch (arg3) {
        case 4:
            if (func_800FCF50(D_808014F4_chmusicmenu[actor->actorData[6]].tracks[index].id)) {
                if (!actor->unk64_19 && index != actor->actorData[0]) {
                    _gcnewoption_entrypoint_27(arg1, index, 1);
                    selected = actor->actorData[0];
                    if (selected != -1U) {
                        _gcnewoption_entrypoint_27(arg1, selected, 0);
                    }
                    actor->actorData[2] = index;
                    actor->actorData[0] = index;
                    actor->actorData[1] = actor->actorData[6];
                    func_80800610_chmusicmenu(actor);
                }
            } else {
                func_800FC660(0xF);
            }
            break;
        case 3:
            actor->actorData[6] = index;
            func_80800930_chmusicmenu(arg0, 2);
            break;
        case 0:
            func_8080021C_chmusicmenu(actor, arg1);
            break;
        case 5:
            if (!actor->unk64_19) {
                _gcnewoption_entrypoint_37(func_80100094(arg0, 1), 1);
            }
            break;
        case 2:
            switch (actor->unk70_10) {
                case 1:
                    func_80800930_chmusicmenu(arg0, 3);
                    break;
                case 2:
                    func_80800930_chmusicmenu(arg0, 1);
                    break;
            }
            break;
    }
}

void func_80800930_chmusicmenu(u8 *arg0, s32 arg1) {
    s32 _capod_entrypoint_21(BtIntPtr, BtIntPtr, s32, s32);
    s32 _capod_entrypoint_22();
    void _gccubesearch_entrypoint_12(BtIntPtr arg0, s32 arg1, BtIntPtr arg2);
    void _gcnewoption_entrypoint_10(void *arg0, s32 arg1);
    void _gcnewoption_entrypoint_11(s16 *arg0);
    void _gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
    void _gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _gcnewoption_entrypoint_40(BtIntPtr, s32, s32, s32, f32, f32);
    void _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
    void _gcnewoption_entrypoint_8(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_9(s16 *arg0, s32 arg1);
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, BtIntPtr);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    BtIntPtr func_800F54E4();
    s32 func_800F82D4(BtIntPtr, s32);
    s32 func_800F8300(BtIntPtr, s32, u8 *);
    BtIntPtr func_80100094(u8 *, s32);
    s32 func_80101238(s32, s32);
    void func_80102424(Actor *, s32);
    void func_808000D0_chmusicmenu(Actor *, BtIntPtr);
    void func_80800714_chmusicmenu(Actor *);
    extern struct MusicMenuEntry D_808014F4_chmusicmenu[12];
    extern s32 _gcnewoption_entrypoint_35;
    extern s32 func_8010D5DC;
    BtIntPtr sp44;
    BtIntPtr sp40;
    s32 sp34[3];
    s32 value;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 2:
            _gcnewoption_entrypoint_6(arg0, 1);
            break;
        case 1:
            _gcnewoption_entrypoint_6(arg0, 1);
            *(s32 *)(arg0 + 0x18) = -1;
            arg0[0x65] &= 0xFFF7;
            if (arg1 == 3) {
                _capod_entrypoint_22();
                func_80101238(0x6E, 0);
            }
            break;
        case 5:
            func_800F8300(func_800F54E4(), 2, arg0 + 4);
            _capod_entrypoint_21(*(s32 *)arg0, *(s32 *)arg0, 0x11, 4);
            *(s32 *)(arg0 + 0x28) = 0;
            *(f32 *)(arg0 + 0x58) = 10.0f;
            break;
    }
    func_80102424(arg0, arg1);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _gcnewoption_entrypoint_4(arg0, 1, &_gcnewoption_entrypoint_35, 0, 0x1850);
            sp44 = func_80100094(arg0, 1);
            _gcnewoption_entrypoint_40(sp44, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_8(sp44, 5);
            _gcnewoption_entrypoint_9(sp44, 0xC);
            _gcnewoption_entrypoint_10(sp44, 0);
            func_808000D0_chmusicmenu(arg0, sp44);
            _gcnewoption_entrypoint_14(sp44, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_11(sp44);
            return;
        case 2:
            _gcnewoption_entrypoint_4(arg0, 1, &_gcnewoption_entrypoint_35, 0, func_808000B4_chmusicmenu(*(s32 *)(arg0 + 0x30)));
            sp40 = func_80100094(arg0, 1);
            _gcnewoption_entrypoint_40(sp40, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            value = D_808014F4_chmusicmenu[*(s32 *)(arg0 + 0x30)].count;
            _gcnewoption_entrypoint_8(sp40, value < 5 ? value : 5);
            _gcnewoption_entrypoint_9(sp40, D_808014F4_chmusicmenu[*(s32 *)(arg0 + 0x30)].count);
            _gcnewoption_entrypoint_10(sp40, 2);
            func_808000D0_chmusicmenu(arg0, sp40);
            _gcnewoption_entrypoint_14(sp40, 0, 1, 3, 4.0f);
            if (*(s32 *)(arg0 + 0x1C) == *(s32 *)(arg0 + 0x30)) {
                value = *(s32 *)(arg0 + 0x20);
                if (value != -1) {
                    *(s32 *)(arg0 + 0x18) = value;
                }
            }
            _gcnewoption_entrypoint_11(sp40);
            return;
        case 4:
            *(s32 *)(arg0 + 0x20) = -1;
            *(s32 *)(arg0 + 0x1C) = -1;
            return;
        case 3:
            func_800F82D4(func_800F54E4(), 0);
            func_80800714_chmusicmenu(arg0);
            *(s32 *)(arg0 + 0x20) = -1;
            *(s32 *)(arg0 + 0x1C) = -1;
            *(s32 *)(arg0 + 0x30) = -1;
            return;
        case 5:
            _gccubesearch_entrypoint_12(sp34, 0x299, arg0 + 4);
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(&func_8010D5DC, *(s32 *)arg0);
            func_8008F938(1);
            func_8008F990(sp34, 0x43C80000);
            return;
    }
}

void func_80800CBC_chmusicmenu(Actor *arg0) {
    s32 func_800D3E40(s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    void func_8010A828(void **, s32);
    extern s16 D_808012A0_chmusicmenu[48];
    s32 var_s0;

    arg0->actorData[6] = -1;
    arg0->unk74_7 = 0;
    arg0->actorData[0] = -1;
    var_s0 = 0;
    func_8010A828(arg0, 9);
    if (func_800D3E40(5) != 0) {
        func_80800930_chmusicmenu(arg0, 4);
    } else if (func_800DA298(0x344) != 0) {
        func_80800930_chmusicmenu(arg0, 6);
    } else {
        func_80800930_chmusicmenu(arg0, 7);
    }
    while (D_808012A0_chmusicmenu[var_s0] != 0x9A) {
        var_s0++;
    }
    func_800DA3B8(var_s0 + 0x53E, func_800DA298(0x43));
}

void func_80800DA4_chmusicmenu(Actor *arg0) {
    void _gcnewoption_entrypoint_0(void *arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_80016B30(s32, s32);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    void func_800DA544();
    s32 func_800FCCD4(s32);
    BtIntPtr func_80100094(u8 *, s32);
    s32 func_8010C500(void *);

    switch (arg0->unk70_10) {
        case 4:
            if (func_8010C500(arg0)) {
                if (!func_800DA298(0x3E1)) {
                    func_80800930_chmusicmenu(arg0, 5);
                    func_800DA544(0x3E1);
                    return;
                }
                if (func_80016B30(0, 1)) {
                    func_80800930_chmusicmenu(arg0, 5);
                    return;
                }
            }
            break;
        case 2:
            if (arg0->unk64_19 && func_800D90A4((f32 *)&arg0->actorData[5])) {
                func_80800560_chmusicmenu(arg0, arg0->unk74_7, 0.0f);
                arg0->unk64_19 = 0;
            }
        case 1:
            if (arg0->unk74_7) {
                if (func_800FCCD4(arg0->unk74_7) && !arg0->unk64_19) {
                    func_80800400_chmusicmenu(arg0);
                }
                if (func_800D90A4(&arg0->unk58)) {
                    func_80800000_chmusicmenu(arg0);
                }
            }
            _gcnewoption_entrypoint_0(func_80100094(arg0, 1));
            return;
        case 3:
            func_80800930_chmusicmenu(arg0, 4);
            return;
        case 7:
            if (func_8010C500(arg0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1048, 0xF, arg0->position, 0x6F);
                func_800DA544(0x344);
                func_80800930_chmusicmenu(arg0, 6);
            }
            break;
    }
}

/* extern */

void func_80800F50_chmusicmenu(u8 *arg0) {
    void _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
    void func_80800714_chmusicmenu(Actor *);
    u32 temp_t6;

    func_80800714_chmusicmenu(arg0);
    temp_t6 = (u32) ((Actor *) arg0)->unk70_10;
    if ((temp_t6 == 1) || (temp_t6 == 2)) {
        _gcnewoption_entrypoint_6(arg0, 1);
    }
}

/* extern */

void func_80800F98_chmusicmenu(Actor *arg0, s32 arg1) {
    void _gcnewoption_entrypoint_1(u8 *arg0, BtIntPtr arg1);
    void func_800DF744(s32, s32);
    s32 func_800EB854(void);
    BtIntPtr func_80100094(u8 *, s32);
    s32 func_80101870(void *, BtIntPtr);
    BtIntPtr temp_v0;

    if (func_800EB854() == 0) {
        if ((s32) arg0->unk70_10 < 6) {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
        } else {
            func_800DF744(1, 1);
            func_800DF744(2, 0);
        }
        func_80101870(arg0, arg1);
        return;
    }
    temp_v0 = func_80100094(arg0, 1);
    if (temp_v0 != 0) {
        _gcnewoption_entrypoint_1(temp_v0, arg1);
    }
}

s32 func_80801040_chmusicmenu(u8 *arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    void func_8080079C_chmusicmenu(u8 *, void *, s32, s32);


    switch (arg1) {
        case 0x20:
            func_8080079C_chmusicmenu(arg0, func_80101080(), *(s16 *)&arg2, *((s16 *)&arg2 + 1));
            return 1;
        case 0x32:
            func_80800930_chmusicmenu(arg0, 1);
            return 1;
        default:
            return 0;
    }
}

OSThread *chmusicmenu_entrypoint_0(void)
{
    extern ActorData D_8080157C_chmusicmenu;


    return (OSThread *)&D_8080157C_chmusicmenu;
}

OSThread *chmusicmenu_entrypoint_1(void)
{
    extern ActorData D_808015C4_chmusicmenu;


    return (OSThread *)&D_808015C4_chmusicmenu;
}

s32 func_808010C4_chmusicmenu(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800D3E40(s32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(GameFlag);
    s32 func_800DC128(s32, s32);
    s32 _glcutDll_entrypoint_20(void);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 choices[14];
    s32 enabled;
    s32 i;
    s32 count;


    switch (arg1) {
    case 0x95:
        if (!func_800D3E40(5) || !func_800DA298(0xC0) || _glcutDll_entrypoint_20()) {
            func_800FFAB0(arg0);
        } else {
            arg0->unk64_16 = 0;
        }
        return 1;
    case 0x6E:
        enabled = (arg0->unk64_16 = arg2);
        if (enabled) {
            count = 0;
            if (arg0->unk74_7 != 0x33) {
                for (i = 0; i < 14; i++) {
                    if (!func_800DA298(i + 1)) {
                        choices[count++] = i;
                    }
                }
                if (count == 0) {
                    for (i = 0; i < 14; i++) {
                        func_800DA524(i + 1);
                    }
                    i = func_800DC128(0, 14);
                } else {
                    i = choices[func_800DC128(0, count)];
                }
                func_800DA544(i + 1);
                func_80102424(arg0, i + 1);
            }
        }
        return 1;
    default:
        return 0;
    }
}

OSThread *chmusicmenu_entrypoint_2(void)
{
    extern ActorData D_8080160C_chmusicmenu;

    return (OSThread *)&D_8080160C_chmusicmenu;
}
#include "musicmenu_data.inc"
