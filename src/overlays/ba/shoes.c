#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif
typedef struct player_state_s PlayerState;

s32 bashoes_entrypoint_0() 
{
    return 0x18;
}

u32 bashoes_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 4);
}    typedef struct { u8 pad0[0x10C]; void * unk10C; } Objshoes_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

u32 bashoes_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 16);
}

void func_80800020_bashoes(void *arg0) {
    void bastatetimer_set(void *, s32, f32);
    s32 func_800EA068(s32);
    void func_800FC660(u32);
    void func_800C77DC(s32);

    bastatetimer_set(arg0, 3, **(f32 **)((u8 *)arg0 + 0x10C));
    if (func_800EA068(0x800) != 0) {
        if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 4) == 3) {
            func_800FC660(0x2B);
        }
    } else {
        switch (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 4)) {
            case 3:
                func_800C77DC(3);
                break;
            case 4:
                func_800C77DC(6);
                break;
            case 5:
                func_800C77DC(5);
                break;
        }
    }
}

/* extern */

void func_808000D4_bashoes(void *arg0, s32 arg1) {
    void _baalarm_free();
    void bastatetimer_set(void *, s32, f32);
    void func_800A0DB8(void *, s32);
    void func_800C77DC(s32);
    _baalarm_free();
    func_800A0DB8(arg0, 1);
    if (arg1 != 0) {
        func_800C77DC(1);
        bastatetimer_set(arg0, 3, 0.0f);
    }
}

/* extern */

void func_80800128_bashoes(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _baalarm_new();
    void baflag_clear(void *self, s32 id);
    void func_800A0DB8(void *, s32);
    void func_80800020_bashoes(void *);
    _baalarm_new();
    baflag_clear(arg0, arg1);
    func_800A0DB8(arg0, arg2);
    if (arg3 != 0) {
        func_80800020_bashoes(arg0);
    }
}

void func_80800180_bashoes(PlayerState *arg0, s32 arg1) {
    void _baalarm_entrypoint_3(PlayerState *, f32, f32);
    void baflag_clear(void *self, s32 id);
    int baflag_isFalse(PlayerState *, s32);
    int baflag_isTrue(PlayerState *, s32);
    f32 bastatetimer_get(PlayerState *, int);
    f32 bastatetimer_getPrevious(PlayerState *, int);
    s32 bastatetimer_isDone(BtIntPtr, s32);
    void bastatetimer_set(void *, s32, f32);
    void func_8009DE38(PlayerState *, s32, f32);
    int func_800A3274(PlayerState *);
    f32 previous;
    f32 current;
    s32 sound;

    previous = bastatetimer_getPrevious(arg0, 3);
    current = bastatetimer_get(arg0, 3);
    if (*((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 5) == 0) {
        _baalarm_entrypoint_3(arg0, previous, current);
        if (current == 0.0f && previous != current && baflag_isFalse(arg0, 0x14)) {
            if (func_800A3274(arg0) == 0xB) {
                sound = 0x459D;
            } else {
                sound = 0x3EB;
            }
            func_8009DE38(arg0, sound, 1.0f);
        }
    }
    if (baflag_isTrue(arg0, arg1)) {
        baflag_clear(arg0, arg1);
        func_80800020_bashoes(arg0);
        bastatetimer_set(arg0, 3, **(f32 **)((u8 *)arg0 + 0x10C));
    }
    if (bastatetimer_isDone(arg0, 3) &&
        *((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 5) == 0) {
        bashoes_entrypoint_6(arg0, 2);
    }
}

void bashoes_entrypoint_3(BtIntPtr arg0)
{
    bashoes_entrypoint_6(arg0,0);
}

void bashoes_entrypoint_4(void *arg0) {
    s32 func_8008DAA8(void *);
    u32 func_8009EA4C(void);
    u32 func_8009EA70(void);
    u32 temp_v0;

    *(s8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 0x10) = 0;
    *(f32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 0x14) = 0.0f;
    *(s8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 5) = 0;
    *(s32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 8) = 0;
    *(s8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 4) = 0;
    if (func_8008DAA8(arg0) && func_8009EA4C() == 2) {
        temp_v0 = func_8009EA70();
        if (temp_v0 != 0) {
            bashoes_entrypoint_6(arg0, temp_v0);
            return;
        }
        bashoes_entrypoint_6(arg0, 1);
        return;
    }
    bashoes_entrypoint_6(arg0, 1);
}

void bashoes_entrypoint_5(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 5) = arg1;
}    typedef struct { u8 pad0[0x4]; u8 unk4; } Objshoes_bashoes_entrypoint_6_shoes; /* offsets.py genstruct: fields from raw offsets on shoes; rename once understood */

BT_IDO_ONLY(int) BT_NATIVE_ONLY(int) bashoes_entrypoint_6(void *arg0, s32 arg1) {
    void func_8009ADF0(void *, s32, s32);
    void (*callback)(void *, s32, s32);
    s32 old_state;
    void *shoes;

    shoes = *(void **)((u8 *)arg0 + 0x10C);
    old_state = ((Objshoes_bashoes_entrypoint_6_shoes *)shoes)->unk4;
    switch (old_state) {
        case 3:
            func_808000D4_bashoes(arg0, arg1);
            shoes = *(void **)((u8 *)arg0 + 0x10C);
            break;
        case 4:
            func_808000D4_bashoes(arg0, arg1);
            shoes = *(void **)((u8 *)arg0 + 0x10C);
            break;
        case 5:
            func_808000D4_bashoes(arg0, arg1);
            shoes = *(void **)((u8 *)arg0 + 0x10C);
            break;
    }
    ((Objshoes_bashoes_entrypoint_6_shoes *)shoes)->unk4 = arg1;
    switch (arg1) {
        case 1:
            func_8009ADF0(arg0, 0xD, 0);
            break;
        case 2:
            func_8009ADF0(arg0, 0xD, 1);
            break;
        case 3:
            func_8009ADF0(arg0, 0xD, 1);
            func_80800128_bashoes((BtIntPtr)arg0, 0x10, 2, old_state);
            break;
        case 4:
            func_8009ADF0(arg0, 0xD, 1);
            func_80800128_bashoes((BtIntPtr)arg0, 0x37, 3, old_state);
            break;
        case 5:
            func_8009ADF0(arg0, 0xD, 1);
            func_80800128_bashoes((BtIntPtr)arg0, 0x38, 4, old_state);
            break;
    }
    callback = *(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 8);
    if (callback != NULL) {
        callback(arg0, old_state, arg1);
    } BT_NATIVE_ONLY(return 0;)
}

void bashoes_entrypoint_7(void *arg0, BtIntPtr arg1) {
    *(s32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 8) = arg1;
}

void bashoes_entrypoint_8(void *arg0, BtIntPtr arg1) {
    *(s32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 12) = arg1;
}

s32 bashoes_entrypoint_9(void *arg0) {
    return (*(f32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 0x14)) > 0.0f ? 1 : 0;
}

void bashoes_entrypoint_10(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 20) = arg1;
}

void bashoes_entrypoint_11(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 16) = arg1;
}

void bashoes_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objshoes_arg0 *)arg0)->unk10C + 0) = arg1;
}

void bashoes_entrypoint_13(PlayerState *arg0) {
    int baflag_isTrue(PlayerState *, s32);
    s32 func_800D9078(f32 *);
    void (*callback)(PlayerState *, s32);
    u8 *data;

    data = *(u8 **)((u8 *)arg0 + 0x10C);
    callback = *(void (**)(PlayerState *, s32))(data + 0xC);
    if (callback != NULL) {
        callback(arg0, data[4]);
        data = *(u8 **)((u8 *)arg0 + 0x10C);
    }
    switch (data[4]) {
    case 1:
        break;
    case 2:
        if (baflag_isTrue(arg0, 0x10)) {
            bashoes_entrypoint_6(arg0, 3);
            return;
        }
        if (baflag_isTrue(arg0, 0x37)) {
            bashoes_entrypoint_6(arg0, 4);
            return;
        }
        if (baflag_isTrue(arg0, 0x38)) {
            bashoes_entrypoint_6(arg0, 5);
            return;
        }
        break;
    case 3:
        func_80800180_bashoes(arg0, 0x10);
        if (baflag_isTrue(arg0, 0x37)) {
            bashoes_entrypoint_6(arg0, 4);
            return;
        }
        if (baflag_isTrue(arg0, 0x38)) {
            bashoes_entrypoint_6(arg0, 5);
            return;
        }
        break;
    case 4:
        func_800D9078((f32 *)(data + 0x14));
        func_80800180_bashoes(arg0, 0x37);
        if (baflag_isTrue(arg0, 0x10)) {
            bashoes_entrypoint_6(arg0, 3);
            return;
        }
        if (baflag_isTrue(arg0, 0x38)) {
            bashoes_entrypoint_6(arg0, 5);
            return;
        }
        break;
    case 5:
        func_80800180_bashoes(arg0, 0x38);
        if (baflag_isTrue(arg0, 0x10)) {
            bashoes_entrypoint_6(arg0, 3);
            return;
        }
        if (baflag_isTrue(arg0, 0x37)) {
            bashoes_entrypoint_6(arg0, 4);
        }
        break;
    }
}

void bashoes_entrypoint_14(void *arg0) {
    u8 func_800F6B34(void);
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_8009E69C(arg0, 0x80);
    temp_v0 = func_800F6B34();
    if ((sp1C == 0) && (temp_v0 == 0)) {
        bashoes_entrypoint_6(arg0, 1);
    }
}

void bashoes_entrypoint_15(PlayerState *arg0) {
    int baflag_isTrue(PlayerState *, s32);
    if (func_8009E6C4(arg0, 0x80) == 0) {
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 8) = 0;
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 12) = 0;
        if (bashoes_entrypoint_1(arg0) == 1) {
            if (baflag_isTrue(arg0, 0x10)) {
                bashoes_entrypoint_6(arg0, 3);
                return;
            }
            if (baflag_isTrue(arg0, 0x37)) {
                bashoes_entrypoint_6(arg0, 4);
                return;
            }
            if (baflag_isTrue(arg0, 0x38)) {
                bashoes_entrypoint_6(arg0, 5);
                return;
            }
            bashoes_entrypoint_6(arg0, 2);
        }
    }
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(BtIntPtr) bashoes_entrypoint_16(BtIntPtr arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, s32 *, s32 *, s32, s32 *);)
    extern s32 D_80800AD0_bashoes[31];
    s32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_800B53A4(6);
    func_8009C128(arg0, &sp24);
    BT_NATIVE_ONLY(return) func_800BABB8(sp20, BT_NATIVE_ONLY((f32 *))(&sp24), BT_NATIVE_ONLY((f32 *))(&sp24), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800AD0_bashoes);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(BtIntPtr) bashoes_entrypoint_17(BtIntPtr arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, s32 *, s32 *, s32, s32 *);)
    extern s32 D_80800B4C_bashoes[17];
    s32 sp24[3];
    BtIntPtr sp20;

    sp20 = func_800B53A4(30);
    func_8009C128(arg0, &sp24);
    BT_NATIVE_ONLY(return) func_800BABB8(sp20, BT_NATIVE_ONLY((f32 *))(&sp24), BT_NATIVE_ONLY((f32 *))(&sp24), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800B4C_bashoes);
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objshoes_bashoes_entrypoint_18_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

void bashoes_entrypoint_18(BtIntPtr arg0) {
    s32 func_80092E08(BtIntPtr, s32 *);
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, s32 *, s32 *, s32, s32 *);)
    extern s32 D_80800B90_bashoes[17];
    f32 sp28;
    s32 sp24[2];
    BtIntPtr sp20;

    sp20 = func_800B53A4(0xA);
    func_80092E08(arg0, sp24);
    ((Objshoes_bashoes_entrypoint_18_sp24 *)sp24)->unk4 -= 30.0f;
    func_800BABB8(sp20, BT_NATIVE_ONLY((f32 *))(sp24), BT_NATIVE_ONLY((f32 *))(sp24), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800B90_bashoes);
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objshoes_bashoes_entrypoint_19_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

void bashoes_entrypoint_19(BtIntPtr arg0) {
    s32 func_80092E2C(BtIntPtr, s32 *);
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, s32 *, s32 *, s32, s32 *);)
    extern s32 D_80800B90_bashoes[17];
    f32 sp28;
    s32 sp24[2];
    BtIntPtr sp20;

    sp20 = func_800B53A4(0xA);
    func_80092E2C(arg0, sp24);
    ((Objshoes_bashoes_entrypoint_19_sp24 *)sp24)->unk4 -= 30.0f;
    func_800BABB8(sp20, BT_NATIVE_ONLY((f32 *))(sp24), BT_NATIVE_ONLY((f32 *))(sp24), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800B90_bashoes);
}

void bashoes_entrypoint_20(PlayerState *arg0) {
    f32 func_80090010(void);
    f32 func_8009BB5C(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EFCD8(f32[3], f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_80800BD4_bashoes[19];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    func_8009C128(arg0, sp30);
    sp28 = func_800F10B4(func_8009BB5C(arg0), 0.0f, 1000.0f, 10.0f, 50.0f);
    func_800EFCD8(sp3C, func_80090010(), sp28);
    sp3C[1] = 0.0f;
    sp30[0] += sp3C[0];
    sp30[1] += sp3C[1];
    sp30[2] += sp3C[2];
    sp30[1] += 6.0f;
    func_800BBCB8(sp30, 0, 1.0f, 1, D_80800BD4_bashoes);
}
/* data_to_c.py: from asm/data/overlays/ba/shoes.data.s */
s32 D_80800AD0_bashoes[31] BT_DATA(4, overlays_ba_shoes, 0x0) = { 1903071, 671219734, 35651605, 1638428, 917524, 1310754, 5832806, 2490406, 2556304, 26215200, 52428843, 3342400, 1834808, 13107482, 1342308366, 1572888, 2818124, 4980770, 4194380, 1310740, 1769672, 26214938, -1274937330, 2097184, 2818150, 6684706, 2490406, 655370, 1769872, 65536794, 0 };
s32 D_80800B4C_bashoes[17] BT_DATA(4, overlays_ba_shoes, 0x7C) = { 1903071, -939393002, 35651605, 1638451, 3080147, 480, -1310361, 38010907, -65471464, 2228300, 5832716, 1507367, 26214800, 52429600, 2818163, 9182746, 0 };
s32 D_80800B90_bashoes[17] BT_DATA(4, overlays_ba_shoes, 0xC0) = { 1903071, -939393002, 35651605, 1638428, 3080162, 300, -1965721, 19660827, -32702964, 2228288, 4194316, 786471, 26214800, 52429600, 2818142, 6162970, 0 };
s32 D_80800BD4_bashoes[19] BT_DATA(4, overlays_ba_shoes, 0x104) = { 1903070, 1376281, 1835018, -786432, -786420, 131084, 1834608, -52428766, 4980825, 1638425, 2949100, 3342316, 1310970, 1310759, 26214800, 52429600, 2818150, 8388608, 0 };
