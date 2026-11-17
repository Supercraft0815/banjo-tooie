#include "core2/1EA9160.h"
#include "gameflags.h"

extern s32 D_8011AE60;    typedef struct { s32 unk0; } Obj1EA9160_D_8011AE60; /* offsets.py genstruct: fields from raw offsets on &D_8011AE60; rename once understood */

void func_800CF870(s32 arg0) {
    ((Obj1EA9160_D_8011AE60 *)&D_8011AE60)->unk0 = arg0;
}

s32 func_800CF87C()
{
    return D_8011AE60;
}

s32 func_800CF888(s32 arg0, s32 arg1) {
    extern s16 D_8011AE64[][2];
    extern s16 D_8011AE6C[][2];
    s32 i;

    i = 0;
    do {
        if (arg0 == D_8011AE64[i][0] && arg1 == D_8011AE64[i][1]) {
            return 1;
        }
        i++;
    } while (D_8011AE6C != &D_8011AE64[i]);
    return 0;
}

s32 func_800CF8D0(s32 arg0, s32 arg1) {
    extern s16 D_8011AE6C[][2];
    extern s16 D_8011AE74[][2];
    s32 i;

    i = 0;
    do {
        if (arg0 == D_8011AE6C[i][0] && arg1 == D_8011AE6C[i][1]) {
            return 1;
        }
        i++;
    } while (D_8011AE74 != &D_8011AE6C[i]);
    return 0;
}

s32 func_800CF918(s32 arg0, s32 arg1) {
    extern s16 D_8011AE74[][2];
    extern s16 D_8011AE76;
    extern s16 D_8011AE84[][8];
    s16 (*entry)[8];
    s32 i;

    i = 1;
    if (arg0 == D_8011AE74[0][0] && arg1 == D_8011AE76) {
        return 0;
    }
    i = 1;
    entry = D_8011AE84;
loop:
        if (arg0 == entry[0][0] && arg1 == entry[0][1]) {
            return i;
        }
        if (arg0 == entry[1][0] && arg1 == entry[1][1]) {
            return i + 1;
        }
        if (arg0 == entry[2][0] && arg1 == entry[2][1]) {
            return i + 2;
        }
        if (arg0 == entry[3][0] && arg1 == entry[3][1]) {
            return i + 3;
        }
        i += 4;
        entry += 4;
    if (i != 9) {
        goto loop;
    }
    return -1;
}

void func_800CF9E4(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8F64(s32, s32);
    extern s16 D_8011AE74[][2];
    struct LightEntry {
        s16 id[2];
        f32 position[2];
        u8 color[3];
        u8 flags;
    };
    s32 index;
    u32 rgb[3];
    struct LightEntry *entry;

    index = func_800CF918(arg0, arg1);
    for (arg1 = 0; arg1 < 3; arg1++) {
        rgb[arg1] = ((struct LightEntry *)D_8011AE74)[index].color[arg1];
    }
    entry = (struct LightEntry *)(index * 0x10 + (u8 *)D_8011AE74);
    func_800C8D4C(arg2, entry->position);
    func_800C8E84(arg2, rgb);
    func_800C8F64(arg2, entry->flags);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CFA70(s32 arg0, s32 arg1)
{
    BT_NATIVE_ONLY(return) func_800CF918(arg0, arg1);
}

s32 func_800CFA90(void) {
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    s32 func_800DA564(GameFlag, s32);
    void func_800DA7A8(GameFlag, s32, s32);
    s32 func_800DA9E4(GameFlag, s32);
    s32 func_800DC128(s32, s32);
    void func_800DC324(s32);
    void func_800DC330(void);
    void func_800DC354(void);
    extern u8 D_8011AB40[];
    s32 counts[9];
    s32 *ptr;
    s32 value;
    s32 idx;

    if (func_800DA9E4(0x6A0, 1) != 0) {
        return 0;
    }
    if (func_800DA298(0x379) == 0) {
        idx = func_800DC128(0, 0x21);
        func_800DA7A8(0x37A, idx, 5);
        func_800DA544(0x379);
    } else {
        idx = func_800DA564(0x37A, 5);
    }
    func_800DC330();
    func_800DC324(idx);
    for (value = 0; &counts[value] < counts + 9; value++) {
        counts[value] = 0;
    }

    for (idx = 0; idx < 45; idx++) {
        value = func_800DC128(0, 9);
        ptr = &counts[value];
        while (*ptr > value) {
            value = func_800DC128(0, 9);
            ptr = &counts[value];
        }
        counts[value]++;
        ((u8 (*)[3])D_8011AB40)[idx][1] = value;
    }
    func_800DC354();
    return 1;
}

void func_800CFBC8(Actor *arg0, u32 arg1, s32 arg2, s32 arg3) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 func_8010108C(Actor *, s32, BtIntPtr);

    func_8010108C(arg0, 0x13, arg1);
    if (func_800CF888(arg1, arg2) != 0) {
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    if (func_800CF8D0(arg1, arg2) != 0) {
        func_8010108C(arg0, 0x12, 1);
    }
    if (func_800CF918(arg1, arg2) != -1) {
        func_8010108C(arg0, 0x55, 1);
    }
}

s32 func_800CFC5C(s32 arg0) {
    if ((arg0 -= D_8011AE60) >= 0 && arg0 < 0xA) {
        return arg0;
    }
    return -1;
}

u32 func_800CFC8C(s32 arg0, s32 arg1) {
    extern u8 D_8011AB40[];
    extern u8 D_8011ABC8[];
    extern u8 D_8011AC7C[];
    extern u8 D_8011ACB0[];
    extern u8 D_8011ACD4[];
    extern u8 D_8011AD08[];
    s32 _chnests_entrypoint_13(s32);
    s32 i;
    u32 count = 0;

    switch (arg0) {
        case 0:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011AB40[i * 3 - 3]) {
                    count++;
                }
            }
            return count;
        case 1:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011ABC8[i * 2 - 2]) {
                    count++;
                }
            }
            return count;
        case 2:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011AC7C[i * 2 - 2]) {
                    count++;
                }
            }
            return count;
        case 3:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011ACB0[i * 2 - 2]) {
                    count++;
                }
            }
            return count;
        case 4:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011ACD4[i * 2 - 2]) {
                    count++;
                }
            }
            return count;
        case 5:
            return func_800D0894(arg0) - func_800D0820(arg0) + 1;
        case 6:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (arg1 == D_8011AD08[i * 2 - 2]) {
                    count += _chnests_entrypoint_13(D_8011AD08[i * 2 - 1] ? 0x1DA : 0x1D9);
                }
            }
            return count;
        case 7:
            return func_800D0894(arg0) - func_800D0820(arg0) + 1;
        case 8:
            return func_800D0894(arg0) - func_800D0820(arg0) + 1;
    }
    return -1;
}

s32 func_800CFFBC(u32 arg0, s32 arg1) {
    if (((s32) arg0 >= func_800D0820(arg1)) && (func_800D0894(arg1) >= (s32) arg0)) {
        return 1;
    }
    return 0;
}

s32 func_800D0018(s32 arg0, s32 arg1) {
    extern u8 D_8011AB3D[][3];
    extern u8 D_8011ABC6[][2];
    extern u8 D_8011AC7A[][2];
    extern u8 D_8011ACAE[][2];
    extern u8 D_8011ACD2[][2];
    extern u8 D_8011AD08[];
    s32 _chnests_entrypoint_13(s32);
    s32 i;
    s32 count = 0;

    switch (arg0) {
        case 0:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011AB3D[i][0]) {
                    count++;
                }
            }
            return count;
        case 1:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011ABC6[i][0]) {
                    count++;
                }
            }
            return count;
        case 2:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011AC7A[i][0]) {
                    count++;
                }
            }
            return count;
        case 3:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011ACAE[i][0]) {
                    count++;
                }
            }
            return count;
        case 4:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011ACD2[i][0]) {
                    count++;
                }
            }
            return count;
        case 6:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0) && arg1 == D_8011AD08[i * 2 - 2]) {
                    count += _chnests_entrypoint_13(D_8011AD08[i * 2 - 1] ? 0x1DA : 0x1D9);
                }
            }
            return count;
        default:
            for (i = func_800D0820(arg0); i <= func_800D0894(arg0); i++) {
                if (func_800D0B68(i, arg0)) {
                    count++;
                }
            }
            return count;
    }
    return count;
}

s32 func_800D035C(s32 a0) {
    s32 _chnests_entrypoint_13(s32);
    extern u8 D_8011AD08[];
    s32 i;
    s32 count;

    count = 0;
    if (a0 == 6) {
        i = func_800D0820(a0);
        if (func_800D0894(a0) >= i) {
            do {
                if (func_800D0B68(i, a0) != 0) {
                    count += _chnests_entrypoint_13(D_8011AD08[i * 2 - 1] ? 0x1DA : 0x1D9);
                }
                i++;
            } while (func_800D0894(a0) >= i);
        }
    } else {
        i = func_800D0820(a0);
        if (func_800D0894(a0) >= i) {
            do {
                if (func_800D0B68(i, a0) != 0) {
                    count++;
                }
                i++;
            } while (func_800D0894(a0) >= i);
        }
    }
    return count;
}

/* extern */

s32 func_800D046C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800DAC78(u8 *, s32);
    return func_800DAC78(arg0, func_800D0A80(arg1, arg2));
}

s32 func_800D04A0(BtIntPtr arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    var_s0 = func_800D0820(arg1);
    if (func_800D0894(arg1) >= var_s0) {
        do {
            if (func_800D046C(arg0, var_s0, arg1) == 1) {
                var_s2 += 1;
            }
            var_s0 += 1;
        } while (func_800D0894(arg1) >= var_s0);
    }
    return var_s2;
}

void func_800D053C(u32 arg0, u32 arg1) { s32 func_800CFC5C(s32); s32 func_800EA05C(); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14) = func_800EA05C(); } } }

void func_800D0594(s32 arg0, s32 arg1, s32 arg2) { s32 func_800CFC5C(s32); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14) = *(s16 *)((u8 *)&arg2 + 2); } } }

void func_800D05E4(s32 arg0, s32 arg1, BtIntPtr arg2) { s32 func_800CFC5C(s32); extern s32 D_8012B18C[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s32 *)((u8 *)D_8012B18C + temp_v0 * 0x14) = arg2; } } }

 Unk80132ED0 *func_800D0634(u32 arg0, u32 arg1) { extern s32 D_8012B18C[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { return *(Unk80132ED0 **)((u8 *)D_8012B18C + temp_v0 * 0x14); } } return 0; }

s16 func_800D0684(s32 arg0, s32 arg1) { s32 func_800CFC5C(s32); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { return *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14); } } return 0; }

s32 func_800D06D4(s32 itemIndex, s32 itemType) {
    extern u8 D_8011ABC6[][2];
    extern u8 D_8011AB3D[][3];
    extern u8 D_8011ACD2[][2];
    extern u8 D_8011ACAE[][2];
    extern u8 D_8011AC7A[][2];
    switch (itemType) {
        case 1: return D_8011ABC6[itemIndex][0];
        case 0: return D_8011AB3D[itemIndex][0];
        case 4: return D_8011ACD2[itemIndex][0];
        case 3: return D_8011ACAE[itemIndex][0];
        case 2: return D_8011AC7A[itemIndex][0];
        case 5: return 0x10;
        case 6: return -1;
    }
    return -1;
}

void func_800D0778(s32 arg0, s32 arg1, f32 *arg2) { s32 func_800CFC5C(s32); extern f32 D_8012B180[][5]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { func_800EE7F8(D_8012B180[temp_v0], arg2); } } }

void func_800D07CC(s32 arg0, s32 arg1, f32 *arg2) { s32 func_800CFC5C(s32); extern f32 D_8012B180[][5]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { func_800EE7F8(arg2, D_8012B180[temp_v0]); } } }

s32 func_800D0820(s32 itemType) {
    s32 result = -1;
    switch (itemType) {
        case 0: return -result;
        case 1: return -result;
        case 2: return -result;
        case 3: return -result;
        case 4: return -result;
        case 5: return -result;
        case 6: return -result;
        case 7: return -result;
        case 8: return -result;
    }
    return result;
}

s32 func_800D0894(s32 itemType) {
    switch (itemType) {
        case 0: return 45;
        case 1: return 90;
        case 2: return 25;
        case 3: return 17;
        case 4: return 25;
        case 5: return 25;
        case 6: return 153;
        case 7: return 30;
        case 8: return 4;
    }
    return -1;
}

s32 func_800D0908(s32 itemIndex, s32 itemType) {
    extern GameFlag D_8011AF28[];
    extern u8 D_8011AB3F[];
    extern u8 D_8011ABC7[];
    extern u8 D_8011ACD3[];
    extern u8 D_8011AC7B[];
    extern u8 D_8011ACAF[];
    extern u8 D_8011AE3B[];
    extern u8 D_8011AE5B[];
    switch (itemType) {
        case 0:
            if (D_8011AB3F[itemIndex * 3]) {
                return D_8011AF28[itemType] + D_8011AB3F[itemIndex * 3] - 1;
            }
            break;
        case 1:
            if (D_8011ABC7[itemIndex * 2]) {
                return D_8011AF28[itemType] + D_8011ABC7[itemIndex * 2] - 1;
            }
            break;
        case 4:
            if (D_8011ACD3[itemIndex * 2]) {
                return D_8011AF28[itemType] + D_8011ACD3[itemIndex * 2] - 1;
            }
            break;
        case 2:
            if (D_8011AC7B[itemIndex * 2]) {
                return D_8011AF28[itemType] + D_8011AC7B[itemIndex * 2] - 1;
            }
            break;
        case 3:
            if (D_8011ACAF[itemIndex * 2]) {
                return D_8011AF28[itemType] + D_8011ACAF[itemIndex * 2] - 1;
            }
            break;
        case 7:
            if (D_8011AE3B[itemIndex]) {
                return D_8011AF28[itemType] + D_8011AE3B[itemIndex] - 1;
            }
            break;
        case 8:
            if (D_8011AE5B[itemIndex]) {
                return D_8011AF28[itemType] + D_8011AE5B[itemIndex] - 1;
            }
            break;
    }
    return 0;
}

s32 func_800D0A80(s32 arg0, s32 arg1) {
    extern s32 D_8011AF04[];
    return D_8011AF04[arg1] + arg0 - 1;
}

/* extern */

s32 func_800D0A9C(u32 arg0, u32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C();
    s32 func_800DA298(GameFlag);
    s32 temp_v0;

    temp_v0 = func_800D0908((s32) arg0, (s32) arg1);
    if (temp_v0 == 0) {
        return 1;
    }
    return ((func_800DA298(temp_v0) != 0) || (_glcutDll_entrypoint_20() != 0) || (func_800D395C() != 0)) ? 1 : 0;
}

/* extern */

void func_800D0B08(s32 arg0, s32 arg1) {
    void func_800DA544(GameFlag);
    s32 temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != 0) {
        func_800DA544(temp_v0);
    }
}

/* extern */

void func_800D0B38(s32 arg0, s32 arg1) {
    s32 func_800DA524(s32);
    s32 temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != 0) {
        func_800DA524(temp_v0);
    }
}

/* extern */

s32 func_800D0B68(u32 arg0, u32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C();
    s32 func_800DA298(GameFlag);
    s32 temp_v0;

    temp_v0 = func_800D0A80((s32) arg0, (s32) arg1);
    if (temp_v0 == 0) {
        return -1;
    }
    return ((func_800DA298(temp_v0) != 0) || (_glcutDll_entrypoint_20() != 0) || (func_800D395C() != 0)) ? 1 : 0;
}

/* extern */

void func_800D0BD4(s32 arg0, u32 arg1) {
    s32 func_800D24E8(s32, s32, s32);
    void func_800DA544(GameFlag);
    s32 func_80101238(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D0A80(arg0, (s32) arg1);
    if (temp_v0 != 0) {
        func_800DA544(temp_v0);
        if (arg1 != 0) {
            if (arg1 != 1) {
                if (arg1 == 6) {
                    func_800D24E8(0xD0, func_800D035C(6), 0);
                }
            } else {
                func_800D24E8(0xD6, func_800D035C(1), 0);
                goto block_6;
            }
        } else {
block_6:
            func_80101238(0xB7, (arg0 << 0x10) | (arg1 & 0xFFFF));
        }
    }
}

/* extern */

void func_800D0C78(u32 arg0, u32 arg1, u32 arg2) {
    s32 func_800FC660(s32);
    if (arg1 == 1) {
        func_800D0B08((s32) arg0, (s32) arg1);
        func_800D0BD4((s32) arg0, arg1);
        if (arg2 == 0) {
            func_800FC660(5);
        }
    }
}

u8 func_800D0CC8(s32 arg0) {
    extern u8 D_8011AB3E[];
    return D_8011AB3E[arg0 * 3];
}

Actor *func_800D0CE0(s32 arg0, f32 *arg1, s32 arg2, s32 *arg3) {
    Actor *func_80108474(u32, f32 *, s32);
    *arg3 = 0;
    switch (arg2) {
        case 0:
            return _chbounce_entrypoint_7(0x1C, arg1, arg0);
        case 1:
            return _chbounce_entrypoint_7(0x1D, arg1, arg0);
        case 4:
            return _chbounce_entrypoint_7(0x1E, arg1, arg0);
        case 3:
            *arg3 = 1;
        case 2:
            return func_80108474(arg0, arg1, 0);
        case 5:
            return _chbounce_entrypoint_7(0x1F, arg1, arg0);
        case 6:
            return _chbounce_entrypoint_7(0x20, arg1, arg0);
    }
    return NULL;
}

typedef struct {
    u32 fields[6];
    u32 reserved : 15;
    u32 enabled : 1;
    u32 remaining : 16;
} SpawnMarker;

BtIntPtr func_800D0DAC(s32 arg0, f32 *arg1, s32 arg2, SpawnMarker *arg3) {
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 itemType;
    s32 itemIndex;
    Actor *actor;
    s32 existing;

    itemIndex = (u16)(arg0 >> 16);
    itemType = (u16)arg0;
    switch (itemType) {
        case 1:
            actor = func_800D0CE0(0x21F, arg1, arg2, &existing);
            if (!existing) {
                func_8010108C(actor, 0x14, 1);
            }
            func_800D05E4(itemIndex, itemType, (BtIntPtr)actor->unk0);
            break;
        case 0:
            actor = func_800D0CE0(0x1F4, arg1, arg2, &existing);
            if (!existing) {
                func_8010108C(actor, 0x14, 1);
            }
            break;
        case 4:
            actor = func_800D0CE0(0x136, arg1, arg2, &existing);
            if (!existing) {
                func_8010108C(actor, 0x14, 1);
            }
            break;
        case 2:
            actor = func_800D0CE0(0x220, arg1, arg2, &existing);
            break;
        case 3:
            actor = func_800D0CE0(0x21B, arg1, arg2, &existing);
            break;
        case 7:
            actor = func_800D0CE0(0x4E5, arg1, arg2, &existing);
            break;
        case 8:
            actor = func_800D0CE0(0x3C6, arg1, arg2, &existing);
            break;
        default:
            break;
    }
    func_800CFBC8(actor, itemIndex, itemType, 0);
    if (arg3 && arg3->enabled) {
        func_80101074(actor->unk0);
        func_8010114C((BtIntPtr)arg3, 0xD, arg0);
    }
    return (BtIntPtr)actor->unk0;
}

void func_800D0F9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, BtIntPtr arg5)
{
    f32 temp;
    f32 sp18[3];
    sp18[0] = (f32)arg1;
    sp18[1] = (f32)arg2;
    sp18[2] = (f32)arg3;
    func_800D0DAC(arg0, sp18, arg4, (SpawnMarker *)arg5);
}

void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((func_800D0A9C(arg0, arg1) == 0) && (func_800D0B68(arg0, arg1) == 0))
    {
        func_800D0B08(arg0, arg1);
        func_800D053C(arg0, arg1);
        if (arg2 != NULL)
        {
            func_800EE904(sp44, arg2);
        }
        else
        {
            func_800D07CC(arg0, arg1, sp34);
            func_800EE904(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&func_800D0F9C, (arg0 << 0x10) | (arg1 & 0xFFFF), sp44[0], sp44[1], sp44[2], arg3, arg4);
    }
}

BtIntPtr func_800D10D4(u32 arg0, u32 arg1, f32 *arg2, s32 arg3, BtIntPtr arg4) {
    f32 sp20[4];

    if (func_800D0A9C(arg0, arg1) != 0) {
        return 0;
    }
    if (func_800D0B68(arg0, arg1) != 0) {
        return 0;
    }
    func_800D0B08(arg0, arg1);
    func_800D053C(arg0, arg1);
    if (arg2 != NULL) {
        return func_800D0DAC((arg0 << 16) | (arg1 & 0xFFFF), arg2, arg3, (SpawnMarker *)arg4);
    }
    func_800D07CC(arg0, arg1, sp20);
    return func_800D0DAC((arg0 << 16) | (arg1 & 0xFFFF), sp20, arg3, (SpawnMarker *)arg4);
}

/* extern */

void func_800D119C(u32 arg0, u32 arg1) {
    s32 func_800FFA88(BtIntPtr);
    if ((func_800D0B68(arg0, arg1) == 0) && (func_800D0A9C(arg0, arg1) != 0)) {
        if (arg1 == 1) {
            func_800FFA88(func_800D0634(arg0, 1U));
            func_800D05E4((s32) arg0, 1, 0);
        }
        func_800D0B38(arg0, arg1);
    }
}

/* extern */

void func_800D1218(u32 arg0, u32 arg1, f32 *arg2) {
    BtIntPtr func_80106790(BtIntPtr);
    BtIntPtr temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) {
        func_800EE7F8(arg2, func_80106790(temp_v0) + 4);
    }
}

void func_800D1254(u32 arg0, u32 arg1, f32 *arg2) {
    s32 func_80103014(BtIntPtr);
    BtIntPtr func_80106790(BtIntPtr);
    s32 sp18[2];
    BtIntPtr temp_v0;
    BtIntPtr temp_v0_2;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) {
        temp_v0_2 = func_80106790(temp_v0);
        sp18[0] = temp_v0_2;
        func_800EE7F8(temp_v0_2 + 4, arg2);
        func_80103014(sp18[0]);
    }
}

s32 func_800D129C(u32 arg0) {
    extern u8 D_8011AB40[];
    s32 var_s1;
    s32 var_s2;
    u8 *var_s0;

    var_s2 = 0;
    var_s1 = func_800D0820(0);
    if (func_800D0894(0) >= var_s1) {
        var_s0 = (var_s1 * 3) + D_8011AB40;
        do {
            if (arg0 == var_s0[-2]) {
                var_s2 += 1;
            }
            var_s1 += 1;
            var_s0 += 3;
        } while (func_800D0894(0) >= var_s1);
    }
    return var_s2;
}

u32 func_800D1338(u32 JinjoColor) {
    extern u8 D_8011AB40[];
    s32 var_s0;
    u32 var_s2;
    u8 *var_s1;

    var_s2 = 0;
    var_s0 = func_800D0820(0);
    if (func_800D0894(0) >= var_s0) {
        var_s1 = (var_s0 * 3) + D_8011AB40;
        do {
            if ((JinjoColor == (*(u8 *)((s8 *)(var_s1) + (-2)))) && (func_800D0B68((u32) var_s0, 0U) != 0)) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 3;
        } while (func_800D0894(0) >= var_s0);
    }
    return var_s2;
}

s32 func_800D13E8(s32 arg0, s32 arg1) {
    extern u8 D_8011AD08[];
    s32 var_s1;
    u8 *var_s0;

    if (arg0 == 6) {
        var_s1 = func_800D0820(arg0);
        if (func_800D0894(arg0) >= var_s1) {
            var_s0 = (var_s1 * 2) + D_8011AD08;
loop_3:
            if (arg1 == var_s0[-2]) {
                return var_s1 - 1;
            }
            var_s0 += 2;
            var_s1 += 1;
            if (func_800D0894(arg0) < var_s1) {
                goto block_6;
            }
            goto loop_3;
        }
    }
block_6:
    return 0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B18C [ 1 ] BT_DATA(4, bss_core2bss1_1_counter_tail, 0xC);
s16 D_8012B190 [ 96 ] BT_DATA(4, bss_core2bss1_1_counter_tail, 0x10);
#endif
