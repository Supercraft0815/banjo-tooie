#include "core2/1ED68A0.h"
#include "music_region_settings.inc"
/* Fourteen music counters and the adjacent state bytes. */
u8 D_80135A10[16];
BT_IDO_ONLY(extern) MusicRegionState D_801359C0;
BT_NATIVE_ONLY(_Static_assert(sizeof(MusicRegionState) == 0x44, "music region state");)

void func_800FCFB0(s32 arg0, s32 arg1, MusicRegionSettings *arg2, s32 arg3, f32 arg4) {
    typedef MusicRegionSettings MusicSettings;



    s32 func_80017764(s32);
    void func_800FC688(s32, s32);
    void func_800FC97C(s32, f32, f32);
    s32 func_800FCCD4(s32);
    s32 func_800FCDE0(s32, s32, f32);
    s32 func_800FCED0(s32, s32, f32);
    BT_IDO_ONLY(extern u8 D_801359D5;)
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;

    if (arg1 == D_80135A20[arg0]) {
        if (arg3) {
            if (((MusicSettings *)arg2)->tempo[1] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[1], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[1], arg4);
        } else {
            if (((MusicSettings *)arg2)->tempo[0] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[0], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[0], arg4);
        }
        D_80135A3C[arg0] = 1;
        return;
    }
    if (D_80135A20[arg0] == 0) {
        D_80135A20[arg0] = arg1;
        if (!func_800FCCD4(arg1)) {
            func_800FC688(arg1, func_80017764(arg1));
            BT_DATA_FIELD(D_801359C0.mixChanged, D_801359D5) = 1;
        }
        if (arg1 == 0x4B) {
            func_800FC97C(arg1, 0.125f, 1.0f);
        } else {
            func_800FC97C(arg1, 0.25f, 1.0f);
        }
        if (arg3) {
            if (((MusicSettings *)arg2)->tempo[1] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[1], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[1], arg4);
        } else {
            if (((MusicSettings *)arg2)->tempo[0] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[0], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[0], arg4);
        }
        D_80135A3C[arg0] = 1;
        D_80135A30[arg0] = arg4;
        if (D_80135A40 == -1) {
            D_80135A40 = 1;
            return;
        }
        D_80135A40++;
    }
}

void func_800FD2A0(f32 *arg0, s32 arg1) {
    BT_IDO_ONLY(extern u8 D_801359D1;) extern u8 D_80135A1E;
    extern MusicRegionSettings *D_80135A04;
    extern f32 D_80135A44;
    extern s32 D_80123F68[], D_80123FC8[];
    extern s32 D_80124004[], D_80124010, D_8012401C[];
    extern s32 D_80124028[], D_80124034[], D_80124040[];
    extern s32 D_801241CC[], D_801241D8[];
    extern f32 D_801241E4[4], D_801241F4[3], D_80124200[3];
    extern f32 D_8012420C[3], D_80124218[3];
    extern f32 D_801261BC, D_801261C0, D_801261C4;
    s32 func_800CBBE0(s32);
    s32 _gcmapsects_entrypoint_7(f32 *);
    f32 func_800D8FF8(void);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800FCFB0(s32, s32, MusicRegionSettings *, s32, f32);
    void func_800FEDC4(s32, s32, f32, f32);
    s32 section;
    f32 volume;

    switch (D_801359C0.areaEnabled) {
        case 1:
            switch (func_800CBBE0(D_801359C0.region)) {
                case 3:
                    if (arg0[0] < D_801241E4[2] ||
                        arg0[2] < D_801241E4[1] ||
                        D_801241E4[0] < arg0[0] ||
                        D_801241E4[3] < arg0[2]) {
                        section = 0;
                    } else {
                        s32 region;
                        region = D_801241E4[0] < arg0[0] + arg0[2] - D_801241E4[1] ? 1 : 2;
                        section = region;
                    }
                    if (section == 2) {
                        D_80135A04 = MUSIC_REGION(19, D_80123F68);
                    }
                    break;
                case 2:
                    if (arg0[1] > 2000.0f) {
                        func_800FCFB0(0, 0x4A, D_80123E84, arg1, 1.75f);
                        D_80135A04 = MUSIC_REGION(27, D_80123FC8);
                    }
                    break;
            }
            break;
        case 7:
            func_800FEDC4(0, 1, 1.0f, 1.75f);
            break;
        case 12:
            func_800FEDC4(0, 2, 1.0f, 1.75f);
            func_800FEDC4(1, 3, 1.0f, 1.75f);
            break;
        case 13:
            func_800FEDC4(0, 2, 0.9f, 1.75f);
            func_800FEDC4(1, 3, 0.9f, 1.75f);
            break;
        case 14:
            volume = func_800F10B4(func_800EEAD4(arg0, D_801241F4), 2500.0f, 3500.0f, 0.8f, 0.0f);
            func_800FEDC4(0, 2, volume, 1.75f);
            func_800FEDC4(1, 3, volume, 1.75f);
            break;
        case 21:
            volume = func_800F10B4(func_800EEAD4(arg0, D_80124200), 2500.0f, 5000.0f, 1.0f, 0.0f);
            func_800FEDC4(0, 4, volume, 1.75f);
            break;
        case 23:
            func_800FEDC4(0, 2, 0.7f, 1.75f);
            func_800FEDC4(1, 3, 0.7f, 1.75f);
            break;
        case 20:
            volume = func_800F10B4(func_800EEAD4(arg0, D_8012420C), 2500.0f, 3500.0f, 0.5f, 0.0f);
            func_800FEDC4(0, 2, volume, 1.75f);
            break;
        case 17:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                BT_DATA_FIELD(D_801359C0.area, D_801359D1) = section;
            }
            switch (D_801359C0.area) {
                case 2:
                case 3:
                case 4:
                    func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
                    D_80135A04 = MUSIC_REGION(33, &D_80124010);
                    break;
            }
            break;
        case 18:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                BT_DATA_FIELD(D_801359C0.area, D_801359D1) = section;
            }
            switch (D_801359C0.area) {
                case 3:
                    if (arg1) {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(32, D_80124004), arg1, 1.75f);
                    }
                    D_80135A04 = MUSIC_REGION(33, &D_80124010);
                    break;
                case 0:
                case 2:
                    func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
                    D_80135A04 = MUSIC_REGION(33, &D_80124010);
                    D_80135A1E = 0;
                    break;
                case 1:
                    if (D_80135A1E) {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(35, D_80124028), arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
                    }
                    D_80135A04 = MUSIC_REGION(33, &D_80124010);
                    break;
            }
            break;
        case 19:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                BT_DATA_FIELD(D_801359C0.area, D_801359D1) = section;
            }
            switch (D_801359C0.area) {
                case 0:
                case 1:
                case 2:
                case 3:
                    if (arg1) {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(35, D_80124028), arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, MUSIC_REGION(32, D_80124004), arg1, 1.75f);
                    }
                    D_80135A04 = MUSIC_REGION(33, &D_80124010);
                    D_80135A1E = 1;
                    break;
            }
            break;
        case 22:
            if (arg1) {
                func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, MUSIC_REGION(32, D_80124004), arg1, 1.75f);
            }
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 5:
            if (!D_801359C0.overrideMode) {
                func_800FCFB0(0, 0x4B, MUSIC_REGION(32, D_80124004), arg1, 1.75f);
            }
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 6:
            func_800FCFB0(0, 0x4B, MUSIC_REGION(37, D_80124040), arg1, 1.75f);
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 8:
            if (func_800DA298(0x9F0)) {
                func_800FCFB0(1, 0x50, D_80123E84, arg1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4F, D_80123E84, arg1, 1.75f);
            }
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 9:
            func_800FCFB0(0, 0x4B, MUSIC_REGION(36, D_80124034), arg1, 1.75f);
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 10:
            func_800FCFB0(0, 0x4B, MUSIC_REGION(34, D_8012401C), arg1, 1.75f);
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 11:
            func_800FCFB0(0, 0x4B, MUSIC_REGION(35, D_80124028), arg1, 1.75f);
            D_80135A04 = MUSIC_REGION(33, &D_80124010);
            break;
        case 15:
            if (func_800DA298(0x360)) {
                f32 current;
                if (func_800EFFB4(arg0, 1750.0f, D_80124218)) {
                    current = D_80135A44;
                    if (current < 0.5f) {
                        D_80135A44 += func_800D8FF8();
                        current = D_80135A44;
                    }
                } else {
                    current = D_80135A44;
                    if (current > 0.0f) {
                        D_80135A44 -= func_800D8FF8();
                        current = D_80135A44;
                    }
                }
                if (current > 0.0f) {
                    if (current >= 0.5f) {
                        D_80135A04 = MUSIC_REGION(70, D_801241CC);
                    } else {
                        D_80135A04 = MUSIC_REGION(71, D_801241D8);
                    }
                }
            }
            break;
        case 16:
            if (D_80135A44 >= 1.0f) {
                func_800FCFB0(0, 0x8D, D_80123E84, arg1, 1.75f);
            }
            D_80135A44 = 1.0f;
            break;
    }
}

void func_800FDBB8(s32 arg0) {
    void func_800FCFB0(s32, s32, MusicRegionSettings *, s32, f32);

    extern s32 D_80124010;
    extern s32 D_80124224[][2];
    BT_IDO_ONLY(extern u8 D_80135A00[];)
    extern MusicRegionSettings *D_80135A04;
    s32 sp20;
    s32 temp_t9;
    s32 *temp_v0;

    temp_t9 = D_80124224[BT_DATA_FIELD(D_801359C0.overrideMode, D_80135A00[0])][0];
    sp20 = temp_t9;
    if (temp_t9 != -1) {
        func_800FCFB0(temp_t9, D_80124224[BT_DATA_FIELD(D_801359C0.overrideMode, D_80135A00[0])][1], D_80123E84, arg0, 0.0f);
        D_80135A04 = MUSIC_REGION(33, &D_80124010);
    }
}

u32 func_800FDC28(u32 arg0) {
    extern u8 D_80135A10[];
    if (arg0 != D_801359C0.overrideMode) {
        D_801359C0.overrideMode = arg0;
        if (!(arg0 & 0xFF)) {
            D_801359C0.changed = 1;
        }
    } BT_NATIVE_ONLY(return 0;)
}

void func_800FDC58(s32 arg0) {
    typedef MusicRegionSettings MusicSettings;



    BT_IDO_ONLY(extern s32 D_801359E8;)
    BT_IDO_ONLY(extern f32 D_801359EC;)
    extern s32 D_80123FC8[], D_80124010, D_801241CC[]; extern MusicRegionSettings *D_80135A04;
    extern s32 D_80124064, D_80124124, D_8012419C;
    extern MusicRegionSettings *D_80135A08;
    extern u8 D_80135A1E;
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern u8 D_80135A3F[];
    extern s32 D_80135A2C[];
    extern s32 D_80135A40;
    extern f32 D_80135A44;
    void func_8008FE68(f32 *);
    s32 func_8008FF94(void);
    s32 func_80090200(void);
    s32 func_800CBBE0(s32);
    s32 func_800CBC00(s32);
    s32 func_800CCEF4(f32 *, s32 *, f32 *, s32, s32);
    f32 func_800D8FF8(void);
    void func_800FC934(s32, f32, f32);
    void func_800FC97C(s32, f32, f32);
    void func_800FCA90(s32);
    void func_800FCAE0(s32, u32, u32);
    s32 func_800FCCD4(s32);
    s32 func_800FCDE0(s32, s32, f32);
    s32 func_800FCED0(s32, s32, f32);
    void func_800FD2A0(f32 *, s32);
    void func_800FDBB8(s32);
    void func_800FE914(s32);
    f32 position[3];
    s32 oldRetry;
    s32 i;
    s32 track;
    s32 region;
    f32 fadeTime;
    s32 fade;

    oldRetry = D_801359C0.retry;
    if (D_801359C0.locked || !D_801359C0.active) {
        return;
    }
    if (D_801359C0.timer > 0.0f) {
        D_801359C0.timer -= func_800D8FF8();
    }
    if (!func_80090200()) {
        return;
    }
    if (func_8008FF94() == 2) {
        arg0 = 1;
    } else {
        arg0 = 0;
    }
    if (!D_801359C0.frozen) {
        if (D_801359C0.settingsIndex != -1) {
            D_80135A04 = &D_80123E84[D_801359C0.settingsIndex];
        } else {
            D_80135A04 = 0;
        }
        func_8008FE68(position);
        for (i = 0; i < 3; i++) {
            D_80135A3C[i] = 0;
        }
        if (func_800CCEF4(position, &BT_DATA_FIELD(D_801359C0.region, D_801359E8), &BT_DATA_FIELD(D_801359C0.distance.value, D_801359EC), 0, 0)) {
            region = func_800CBBE0(D_801359C0.region);
            if (!func_800CBC00(D_801359C0.region)) {
                D_80135A04 = &D_80123E84[region];
            } else {
                switch (func_800CBBE0(D_801359C0.region)) {
                    case 0:
                        func_800FCFB0(0, 0x47, D_80123E84, arg0, 1.75f);
                        D_80135A04 = MUSIC_REGION(27, D_80123FC8);
                        break;
                    case 1:
                        func_800FCFB0(0, 0x4A, D_80123E84, arg0, 1.75f);
                        D_80135A04 = MUSIC_REGION(27, D_80123FC8);
                        break;
                    case 7:
                        D_80135A1E = 1;
                        break;
                    case 8:
                        D_80135A1E = 0;
                        break;
                    case 9:
                        func_800FCFB0(0, 0x4A, D_80123E84, arg0, 1.75f);
                        D_80135A04 = MUSIC_REGION(40, &D_80124064);
                        break;
                    case 12:
                        if (func_800DA298(0x360)) {
                            D_80135A04 = MUSIC_REGION(70, D_801241CC);
                        }
                        break;
                    case 13:
                        D_80135A44 = 0.0f;
                        break;
                    case 14:
                        func_800FCFB0(0, 0x4A, D_80123E84, arg0, 1.75f);
                        break;
                    case 15:
                        func_800FCFB0(0, 0x8D, D_80123E84, arg0, 1.75f);
                        D_80135A04 = MUSIC_REGION(66, &D_8012419C);
                        break;
                    case 16:
                        if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                            func_800FCFB0(0, 0x9A, D_80123E84, arg0, 1.75f);
                            D_80135A04 = MUSIC_REGION(33, &D_80124010);
                        } else {
                            D_80135A04 = MUSIC_REGION(56, &D_80124124);
                        }
                        break;
                    case 17:
                        if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                            func_800FCFB0(0, 0x9A, D_80123E84, arg0, 1.75f);
                            D_80135A04 = MUSIC_REGION(33, &D_80124010);
                        }
                        break;
                }
            }
        }
        if (D_801359C0.areaEnabled) {
            func_800FD2A0(position, arg0);
        }
        func_800FDBB8(arg0);
        if (D_80135A40 > 0) {
            for (i = 0; i < 3; i++) {
                if (D_80135A20[i] && (!D_80135A3C[i] || !func_800FCCD4(D_80135A20[i]))) {
                    fadeTime = 666.0f;
                    func_800FCAE0(D_80135A20[i], 0, (s32)fadeTime);
                    func_800FCA90(D_80135A20[i]);
                    D_80135A20[i] = 0;
                    D_80135A3C[i] = 0;
                    D_80135A30[i] = 0.0f;
                    D_80135A40--;
                }
            }
        }
    }
    func_800FE914(oldRetry);
    if (!D_801359C0.frozen) {
        if (D_80135A04 != D_80135A08 || arg0 != D_801359C0.lastMode || D_801359C0.retry || D_801359C0.changed) {
            if (!D_801359C0.retry) {
                fade = 1;
            } else {
                D_801359C0.retry--;
                fade = 0;
                if (D_801359C0.track != -1) {
                    func_800FC97C(D_801359C0.track, 0.25f, 1.0f);
                }
            }
            D_80135A08 = D_80135A04;
            D_801359C0.lastMode = arg0;
            if (D_80135A04 && D_801359C0.track != -1) {
                if (arg0) {
                    if (!func_800FCDE0(D_801359C0.track, ((MusicSettings *)D_80135A04)->volume[1], (f32)fade)) {
                        D_801359C0.retry = 1;
                    }
                    if (((MusicSettings *)D_80135A04)->tempo[1] != -1) {
                        if (!func_800FCED0(D_801359C0.track, (s32)(D_801359C0.tempoScale * (60000000 / ((MusicSettings *)D_80135A04)->tempo[1])), (f32)fade)) {
                            D_801359C0.retry = 1;
                        }
                    }
                } else {
                    if (!func_800FCDE0(D_801359C0.track, ((MusicSettings *)D_80135A04)->volume[0], (f32)fade)) {
                        D_801359C0.retry = 1;
                    }
                    if (((MusicSettings *)D_80135A04)->tempo[0] != -1) {
                        if (!func_800FCED0(D_801359C0.track, (s32)(D_801359C0.tempoScale * (60000000 / ((MusicSettings *)D_80135A04)->tempo[0])), (f32)fade)) {
                            D_801359C0.retry = 1;
                        }
                    }
                }
            }
            D_801359C0.changed = D_801359C0.retry;
        }
        if (D_801359C0.volumeChanged) {
            track = D_801359C0.track;
            if (D_801359C0.audible) {
                if (track != -1) {
                    func_800FC934(track, D_801359C0.volume, 1.0f);
                }
                for (i = BT_DATA_FIELD(0, -3); i != BT_DATA_FIELD(3, 0); i++) {
                    if (BT_DATA_FIELD(D_80135A20[i], D_80135A2C[i])) {
                        func_800FC934(BT_DATA_FIELD(D_80135A20[i], D_80135A2C[i]), D_801359C0.volume, 1.0f);
                    }
                }
            } else {
                if (track != -1) {
                    func_800FC934(track, 0.0f, 1.0f);
                }
                for (i = BT_DATA_FIELD(0, -3); i != BT_DATA_FIELD(3, 0); i++) {
                    if (BT_DATA_FIELD(D_80135A20[i], D_80135A2C[i])) {
                        func_800FC934(BT_DATA_FIELD(D_80135A20[i], D_80135A2C[i]), 0.0f, 1.0f);
                    }
                }
            }
            D_801359C0.volumeChanged = 0;
        }
    }
}

void func_800FE3EC(void) {
    void func_800FCA90(s32);
    BT_IDO_ONLY(extern s16 D_801359C8;)
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;
    u32 temp_a0;
    s32 var_s1;

    temp_a0 = BT_DATA_FIELD(D_801359C0.track, D_801359C8);
    if (temp_a0 != -1U) {
        func_800FCA90(temp_a0);
    }
    if (D_80135A40 > 0) {
        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            temp_a0 = D_80135A20[var_s1];
            if ((temp_a0 != 0) && (D_80135A3C[var_s1] != 0)) {
                func_800FCA90(temp_a0);
                D_80135A20[var_s1] = 0;
                D_80135A3C[var_s1] = 0;
                D_80135A30[var_s1] = 0.0f;
                D_80135A40 -= 1;
            }
        }
    }
}

s32 func_800FE4E4(void) {
    void func_800C77DC(s32);
    void func_800FC74C(u32);
    BT_IDO_ONLY(extern s16 D_801359C8;)
    BT_IDO_ONLY(extern s8 D_801359D7;)
    BT_IDO_ONLY(extern s8 D_80135A01;)
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;
    u32 temp_a0;
    s32 var_s1;

    if ((u8) BT_DATA_FIELD(D_801359C0.frozen, D_801359D7) != 0) {
        return 0;
    }
    func_800C77DC(1);
    func_800FDC28(0U);
    temp_a0 = BT_DATA_FIELD(D_801359C0.track, D_801359C8);
    if (temp_a0 != -1U) {
        func_800FC74C(temp_a0);
    }
    if (D_80135A40 > 0) {
        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            temp_a0 = D_80135A20[var_s1];
            if ((temp_a0 != 0) && (D_80135A3C[var_s1] != 0)) {
                func_800FC74C(temp_a0);
                D_80135A20[var_s1] = 0;
                D_80135A3C[var_s1] = 0;
                D_80135A30[var_s1] = 0.0f;
                D_80135A40 -= 1;
            }
        }
    }
    BT_DATA_FIELD(D_801359C0.locked, D_80135A01) = 1;
    return 1;
}

void func_800FE614(void)
{
  extern s32 D_80135A20[3];
  extern f32 D_80135A30[3];
  extern u8 D_80135A3C[3];
  extern s32 D_80135A40;
  BT_IDO_ONLY(extern MusicRegionState D_801359C0_storage;)
  MusicRegionState *state;
  unsigned int i;
  state = BT_DATA_FIELD(&D_801359C0, &D_801359C0_storage);
  state->active = 1;
  state->frozen = 0;
  D_80135A40 = -1;
  for (i = 0; i < 2; i++)
  {
    state->instrumentHandles[i] = 0;
    state->instrumentPresets[i] = 0;
  }

  for (i = 0; i < 3; i++)
  {
    D_80135A20[i] = 0;
    D_80135A30[i] = 0.0f;
    D_80135A3C[i] = 0;
  }

 for (i = 0; i < 14; i++) {
    D_80135A10[i] = 0;
  }

  func_800FDC28(0U);
}

void func_800FE6F8(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_801359D6;)
    if ((arg0 == 0) && (BT_DATA_FIELD(D_801359C0.active, D_801359D6) != 0)) {
        func_800FE4E4();
    }
    BT_DATA_FIELD(D_801359C0.active, D_801359D6) = (u8) arg0;
}

void func_800FE734(u32 arg0) {
    BT_IDO_ONLY(extern s8 D_801359D7;)
    BT_DATA_FIELD(D_801359C0.frozen, D_801359D7) = (s8) arg0;
}

void func_800FE740(void) {
    extern u8 D_80135A10[];
    s16 _cothemedll_entrypoint_1(s32);
    BT_NATIVE_ONLY(void _cothemedll_entrypoint_3(MusicRegionState *);) BT_IDO_ONLY(s32 _cothemedll_entrypoint_3(MusicRegionState *, s32);)
    s32 func_800EA05C();
    BT_IDO_ONLY(extern s16 D_801359E2;)
    extern MusicRegionSettings *D_80135A08;
    extern f32 D_80135A0C;
    s32 sp1C[2];
    s32 temp_a1;

    temp_a1 = func_800EA05C();
    if (D_80135A10[6] != 0) {
        D_80135A10[6] = 0U;
    }
    D_80135A08 = 0;
    D_80135A0C = 0.0f;
#ifdef BT_NATIVE
    sp1C[1] = temp_a1;
    _cothemedll_entrypoint_3(&D_801359C0);
#else
    sp1C[1] = temp_a1; _cothemedll_entrypoint_3(&D_801359C0, temp_a1);
#endif
    BT_DATA_FIELD(D_801359C0.settingsIndex, D_801359E2) = _cothemedll_entrypoint_1(sp1C[1]);
}

s32 func_800FE7A8(s32 arg0) { BT_IDO_ONLY(extern s16 D_801359C8;) extern s32 D_80135A20[]; extern u8 D_80135A3C[3]; extern s32 D_80135A40; s32 var_v0; u8 *var_v1; if (arg0 == BT_DATA_FIELD(D_801359C0.track, D_801359C8)) { return 1; } var_v0 = 0; var_v1 = D_80135A3C; if (D_80135A40 > 0) {
        for (; var_v0 < 3; var_v0++, var_v1++) {
            if ((*var_v1 != 0) && (arg0 == D_80135A20[var_v0])) {
                return 1;
            }
        }
    }
    return 0;
}

void func_800FE820(f32 arg0) {
    (D_801359C0.lastMode) = 0xFF;
    (D_801359C0.tempoScale) = (f32) (1.0f / arg0);
}

void func_800FE844(u32 arg0) {
    BT_IDO_ONLY(extern s8 D_801359CE;)
    BT_DATA_FIELD(D_801359C0.mode, D_801359CE) = (s8) arg0;
}

void func_800FE850()
{
    func_800DA544(FLAG2_674_UNK);
}

void func_800FE870()
{
    func_800DA544(FLAG2_675_UNK);
}

u32 func_800FE890(void) {
    BT_IDO_ONLY(extern s8 D_801359CE;)
    return (u8)BT_DATA_FIELD(D_801359C0.mode, D_801359CE);
}

void func_800FE89C(void) {
    BT_IDO_ONLY(extern s8 D_801359CF;)
    BT_DATA_FIELD(D_801359C0.retry, D_801359CF) = 1;
}

void func_800FE8AC(void) {
    BT_IDO_ONLY(extern s8 D_801359D8;)
    BT_DATA_FIELD(D_801359C0.changed, D_801359D8) = 1;
}

void func_800FE8BC(s32 arg0, s32 arg1) {
    void _cothemedll_entrypoint_5(MusicRegionState *arg0, s32 arg1, s32 arg2);
    _cothemedll_entrypoint_5(&D_801359C0, arg0, arg1);
}

void func_800FE8EC(s32 arg0) {
    void _cothemedll_entrypoint_4(MusicRegionState *arg0, s32 arg1);
    _cothemedll_entrypoint_4(&D_801359C0, arg0);
}

void func_800FE914(s32 arg0) {
    typedef f32 FadeTimes[2];
    s32 func_80017764(s32);
    s32 func_800FC4B0(s32, s32, s32, f32);
    void func_800FC688(s32, s32);
    void func_800FCB00(s32, s32, s32, s32);
    s32 func_800FCCD4(s32);
    extern s32 D_80123E60;
    extern s32 D_801242DC[];
    extern FadeTimes D_80124314[];
    BT_IDO_ONLY(extern s16 D_801359C8;) BT_IDO_ONLY(extern s16 D_801359CA;) BT_IDO_ONLY(extern s16 D_801359E4;)
    BT_IDO_ONLY(extern u8 D_801359D5;)
    BT_IDO_ONLY(extern f32 D_801359F0;) extern f32 D_80135A0C;
    extern u8 D_80135A10[];
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;
    register f32 value;
    f32 pairDown;
    f32 pairUp;
    f32 trackFade;
    register f32 previous;
    register f32 duration;
    register f32 fade;
    s32 volume;
    s32 *track;
    register s32 limit;
    s32 result;
    s32 j;
    s32 k;
    s32 i;
    u8 *flag;
    FadeTimes *pair;

    duration = 1.75f;
    volume = BT_DATA_FIELD(D_801359C0.trackVolume, D_801359CA);
    for (i = 0; i < 14; i++) {
        if (D_80135A10[i]) {
            pair = &D_80124314[i];
            
            switch (i) {
            case 3:
                value = BT_DATA_FIELD(D_801359C0.trackVolume, D_801359CA) * BT_DATA_FIELD(D_801359C0.volumeScale, D_801359F0);
                fade = volume;
                if (value < fade) {
                    volume = value;
                }
                break;
            default:
                limit = D_801242DC[i];
                volume = limit < volume ? limit : volume;
                break;
            }
            pairDown = (*pair)[0];
            if (pairDown < duration) {
                duration = pairDown;
            }
            pairUp = (*pair)[1];
            if (D_80135A0C < pairUp) {
                D_80135A0C = pairUp;
            }
        }
    }
    if (BT_DATA_FIELD(D_801359C0.appliedVolume, D_801359E4) < volume) {
        duration = D_80135A0C;
    }
    if (volume != BT_DATA_FIELD(D_801359C0.appliedVolume, D_801359E4) || D_80123E60) {
        if (BT_DATA_FIELD(D_801359C0.track, D_801359C8) != -1) {
            if (!func_800FCCD4(BT_DATA_FIELD(D_801359C0.track, D_801359C8))) {
                func_800FC688(BT_DATA_FIELD(D_801359C0.track, D_801359C8), func_80017764(BT_DATA_FIELD(D_801359C0.track, D_801359C8)));
            }
            result = func_800FC4B0(BT_DATA_FIELD(D_801359C0.track, D_801359C8), -1, volume, arg0 ? 0.0f : duration);
            if (result) {
                func_800FCB00(BT_DATA_FIELD(D_801359C0.track, D_801359C8), volume, result, 0);
            }
        }
        D_80123E60 = 0;
    }
    if (volume != BT_DATA_FIELD(D_801359C0.appliedVolume, D_801359E4) || BT_DATA_FIELD(D_801359C0.mixChanged, D_801359D5) || D_80123E60) {
        if (D_80135A40 > 0) {
            for (j = 0; j < 3; j++) {
                if (D_80135A20[j] && D_80135A3C[j] && func_800FCCD4(D_80135A20[j])) {
                    duration = arg0 ? 0.0f :
                        (duration < D_80135A30[j] ? duration : D_80135A30[j]);
                    result = func_800FC4B0(D_80135A20[j], -1, volume, duration);
                    if (result) {
                        func_800FCB00(D_80135A20[j], volume, result, 0);
                    }
                }
            }
        } else {
            D_80135A0C = 0.0f;
        }
        BT_DATA_FIELD(D_801359C0.mixChanged, D_801359D5) = 0;
    }
    BT_DATA_FIELD(D_801359C0.appliedVolume, D_801359E4) = volume;
    if (&BT_DATA_FIELD(D_801359C0.track, D_801359C8)) {}
}

void func_800FEC1C(f32 arg0) {
    BT_IDO_ONLY(extern f32 D_801359F0;)
    BT_DATA_FIELD(D_801359C0.volumeScale, D_801359F0) = arg0;
}

s32 func_800FEC28(s32 arg0) {
    extern u8 D_8012762C;
    if (arg0 == 0) {
        return D_8012762C == 0xD ? 7 : 0;
    }
    return arg0;
}
void func_800FEC60(u32 arg0) {
    BT_IDO_ONLY(extern f32 D_801359F0;)
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 temp_v0;
    u8 *temp_v1;
    temp_v0 = func_800FEC28((s32)arg0);
    temp_v1 = D_80135A10 + temp_v0;
    *temp_v1 = *temp_v1 + 1;
    if (temp_v0 == 3) {
        BT_DATA_FIELD(D_801359C0.volumeScale, D_801359F0) = 1.0f;
    }
    D_80123E60 = 1;
}

void func_800FECB8(u32 arg0) {
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 i;
    u8 *p;
    p = D_80135A10 + func_800FEC28((s32)arg0);
    *p = *p - 1;
    for (i = 0; i < 14; i++) {}
    D_80123E60 = 1;
}

void func_800FED0C(s32 arg0, s32 arg1) {
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 index;
    u8 *p;
    switch (arg0) {
        case 2:
            index = 12;
            break;
        case 5:
        case 10:
        case 11:
        case 12:
        case 13:
        case 18:
        case 22:
        case 23:
        case 24:
        case 27:
        case 46:
        case 49:
        case 58:
        case 68:
        case 83:
        case 96:
        case 119:
        case 131:
            index = 13;
            break;
        case 43:
        case 104:
            index = 13;
            break;
        case 1:
        default:
            return;
    }
    p = D_80135A10 + index;
    *p = *p + arg1;
    D_80123E60 = 1;
}

void func_800FED70(s32 arg0)
{
    func_800FED0C(arg0,1);
}

s32 func_800FED90(s32 arg0) {
    s32 var_v0;

    func_800FED0C(arg0, -1);
    var_v0 = 2;
    while (var_v0 != 0xE) {
        var_v0 += 4;
    } BT_NATIVE_ONLY(return 0;)
}

void func_800FEDC4(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    u8 func_800C2E04(void);
    s32 func_800C2FDC(u8);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C33DC(u8, s32);
    void func_800C3648(u8, s32);
    void func_800C368C(u8, s32);
    void func_800C36F4(u8, s32);
    void func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    s32 func_800EA05C();
    BT_IDO_ONLY(extern s16 D_80123E5E;)
    extern MusicInstrumentPreset D_80123E64[4];

    if (arg1 == D_801359C0.instrumentPresets[arg0] && arg1 != 0) {
        func_800C3648(D_801359C0.instrumentHandles[arg0], func_800EA05C());
        func_800C3058(D_801359C0.instrumentHandles[arg0], (s32)(BT_DATA_FIELD(D_80123E64[arg1 - 1].volume, *(s16 *)((u8 *)&D_80123E5E + arg1 * 8)) * arg2));
        return;
    }
    if (D_801359C0.instrumentHandles[arg0] != 0) {
        if (arg3 != 0.0f) {
            func_800C3A40(D_801359C0.instrumentHandles[arg0], 0.0f, 0.0f, arg3);
        } else {
            func_800C2FDC(D_801359C0.instrumentHandles[arg0]);
        }
        D_801359C0.instrumentHandles[arg0] = 0;
    }
    if (arg1 != 0) {
        D_801359C0.instrumentHandles[arg0] = func_800C2E04();
        func_800C330C(D_801359C0.instrumentHandles[arg0], 3);
        func_800C301C(D_801359C0.instrumentHandles[arg0], BT_DATA_FIELD(D_80123E64[arg1 - 1].id, *(s16 *)((u8 *)&D_80123E64 + arg1 * 8 - 8)));
        func_800C3058(D_801359C0.instrumentHandles[arg0], (s32)(BT_DATA_FIELD(D_80123E64[arg1 - 1].volume, *(s16 *)((u8 *)&D_80123E64 + arg1 * 8 - 6)) * arg2));
        func_800C31DC(D_801359C0.instrumentHandles[arg0], BT_DATA_FIELD(D_80123E64[arg1 - 1].rate, *(f32 *)((u8 *)&D_80123E64 + arg1 * 8 - 4)));
        func_800C36F4(D_801359C0.instrumentHandles[arg0], 0xFF);
        func_800C368C(D_801359C0.instrumentHandles[arg0], 0);
        func_800C33DC(D_801359C0.instrumentHandles[arg0], 0);
        func_800C3BDC(D_801359C0.instrumentHandles[arg0]);
    }
    D_801359C0.instrumentPresets[arg0] = arg1;
}    typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x2]; s16 unkA; } Obj1ED68A0_func_800FEF94_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { s32 unk0; u8 pad4[0x4]; s16 unk8; } Obj1ED68A0_func_800FEF94_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void func_800FEF94(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s16 *arg4) {

    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (arg1 * 0xC) + (u8 *)&D_80123E84;
        *arg3 = BT_DATA_FIELD(D_80123E84[arg1].volume[1], (((Obj1ED68A0_func_800FEF94_temp_v0 *)temp_v0)->unk4));
        *arg4 = BT_DATA_FIELD(D_80123E84[arg1].tempo[1], (((Obj1ED68A0_func_800FEF94_temp_v0 *)temp_v0)->unkA));
        return;
    }
    temp_v0_2 = (arg1 * 0xC) + (u8 *)&D_80123E84;
    *arg3 = BT_DATA_FIELD(D_80123E84[arg1].volume[0], (((Obj1ED68A0_func_800FEF94_temp_v0_2 *)temp_v0_2)->unk0));
    *arg4 = BT_DATA_FIELD(D_80123E84[arg1].tempo[0], (((Obj1ED68A0_func_800FEF94_temp_v0_2 *)temp_v0_2)->unk8));
}

void func_800FF000(s32 arg0) {
    (D_801359C0.audible) = (s8) arg0;
    (D_801359C0.volume) = 0.2f;
}

void func_800FF01C(f32 arg0) {
    (D_801359C0.audible) = 1;
    (D_801359C0.volumeChanged) = 1;
    (D_801359C0.volume) = arg0;
}

void func_800FF038(s32 arg0) {
    void _cothemedll_entrypoint_2(MusicRegionState *arg0, s32 arg1);
    _cothemedll_entrypoint_2(&D_801359C0, arg0);
}

f32 func_800FF060(f32 arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sqrtf(f32);
    f32 initial;
    f32 velocity;
    f32 distance1;
    f32 distance2;
    f32 distance3;
    f32 distance4;
    f32 time1;
    f32 time2;
    f32 time3;
    f32 time4;
    f32 distance;
    f32 square;
    f32 acceleration;
    f32 braking;
    f32 limit;
    f32 pad;
    f32 direction;
    
    s32 sign;

    if (arg0 < 0.0f) {
        sign = -1;
    } else {
        sign = 1;
    }
    
    acceleration = sign;
    arg0 *= acceleration;
    initial = *arg1 * acceleration;
    if (time2) {}
    if (initial < 0.0f) {
        braking = -arg3;
        if (braking) {}
        direction = acceleration;
        if (braking < arg2) {
            acceleration = arg2;
        } else {
            acceleration = braking;
        }
        time1 = 0.0f - initial / acceleration;
        if (arg5 < time1) {
            time1 = arg5;
        }
        velocity = acceleration * time1 + initial;
        distance1 = (initial + velocity) * time1 * 0.5f;
    } else {
        distance1 = time1 = 0.f;
        velocity = initial;
        direction = acceleration;
    }
    arg0 -= distance1;
    initial = velocity;
    arg5 -= time1;
    square = velocity * velocity;
    distance = (square * 0.5f + arg3 * arg0) / (arg3 - arg2);
    if (distance > 0.0f) {
        limit = (f32) 2.0 * arg2 * distance;
        limit = sqrtf(square + limit);
        velocity = limit;
        if (arg4 <= limit) {
            velocity = arg4;
        }
        if (velocity) {}
        time2 = (velocity - initial) / arg2;
        if (arg5 < time2) {
            time2 = arg5;
        }
        velocity = arg2 * time2 + initial;
        distance2 = (initial + velocity) * 0.5f * time2;
    } else {
        velocity = initial;
        distance2 = time2 = 0.0f;
    }
    if (velocity == 0.0f) {
        *arg1 = 0.0f;
        return direction * distance1;
    }
    arg5 -= time2;
    initial = velocity;
    arg0 -= distance2;
    if (arg5 > 0.0f) {
        acceleration = (0.0f - velocity * velocity) / ((f32) 2.0 * arg3);
        if (acceleration < arg0) {
            time3 = (arg0 - acceleration) / velocity;
            if (arg5 < time3) {
                time3 = arg5;
            }
            distance3 = time3 * velocity;
        } else {
            time3 = distance3 = 0.0f;
        }
    } else {
        time3 = distance3 = 0.0f;
    }
    arg0 -= distance3;
    arg5 -= time3;
    if (arg5 > 0.0f) {
        velocity = arg3 * arg5 + initial;
        time4 = arg5;
        if (velocity < 0.0f) {
            velocity = 0.0f;
            time4 = -initial / arg3;
        }
        distance4 = (initial + velocity) * 0.5f * time4;
    } else {
        distance4 = 0.0f;
    }
    arg0 -= distance4;
    *arg1 = direction * velocity;
    return (distance1 + distance2 + distance3 + distance4) * direction;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
MusicRegionSettings *D_80135A04 BT_DATA(4, bss_core2bss2_2, 0x2B64);
MusicRegionSettings *D_80135A08 BT_DATA(4, bss_core2bss2_2, 0x2B68);
f32 D_80135A0C BT_DATA(4, bss_core2bss2_2, 0x2B6C);
s32 D_80135A20 [ 3 ] BT_DATA(16, bss_core2bss2_2_music_tail, 0x0);
s32 D_80135A2C [ 1 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0xC);
f32 D_80135A30 [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x10);
u8 D_80135A3C [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1C);
u8 D_80135A3F [ 1 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1F);
s32 D_80135A40 BT_DATA(4, bss_core2bss2_2_music_tail, 0x20);
f32 D_80135A44 BT_DATA(4, bss_core2bss2_2_music_tail, 0x24);
#endif
