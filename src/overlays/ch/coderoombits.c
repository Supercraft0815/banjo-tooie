#include "common.h"

OSThread *chcoderoombits_entrypoint_0(void)
{
    extern u8 D_80801170_chcoderoombits[];

    return (OSThread *) D_80801170_chcoderoombits;
}

void func_8080000C_chcoderoombits(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_12(u32 *, s32 *);
    extern s32 D_80801308_chcoderoombits;
    u32 *sp1C;
    u32 *temp_v0;

    temp_v0 = func_80100074(arg0, 0U, 0x182U);
    sp1C = temp_v0;
    _susubgame_entrypoint_0(arg0, temp_v0, 1);
    _susubgame_entrypoint_12(sp1C, &D_80801308_chcoderoombits);
}

struct player_state_s;

void func_80800058_chcoderoombits(Actor *arg0) {
    typedef struct player_state_s PlayerState;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void func_800946C4(PlayerState *, s32);
    s32 func_800C064C(void);
    int func_800C6E38(s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4A00(s32, s32);
    void func_800F4A8C(s32, f32 *, f32);
    s32 func_800F52B8(s32, Unk80132ED0 *);
    PlayerState *func_800F53D0(s32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5C94(s32);
    s32 func_800F6478(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_800F6C5C(s32);
    s32 func_800F7F98(s32, u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_8010C9B0(f32 *, s32);
    void func_808004B8_chcoderoombits(Actor *);
    void func_80800BF4_chcoderoombits(Actor *);
    extern s32 func_8010D5DC;
    f32 sp34[3];
    struct { u8 pad[0x18]; u8 flag; } *sp30;
    s32 sp2C;
    s32 sp28;

    sp30 = func_80100094(arg0, 0U);
    sp2C = func_800F54E4();
    func_800F5A00(sp2C, sp34);
    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(0x6A) == 0) {
                if (func_8010C9B0(arg0->position, 0x15E) != 0 && func_800F64A4(sp2C, 0x201) != 0) {
                    if (func_800C6E38(0x16) != 0) {
                        sp28 = 0x1140;
                    } else {
                        sp28 = 0x115C;
                    }
                    _susubgame_entrypoint_5(arg0, sp30, 4, 0, 0);
                    _subaddiedialog_entrypoint_11(arg0->unk0, sp28, 0xE, arg0->position, 0);
                    func_800DA544(0x6A);
                }
            } else if (func_800C6E38(0x16) != 0 && func_800F6478(sp2C) != 0) {
                if (func_800EEAD4(arg0->position, sp34) > 100.0f) {
                    sp30->flag = 0;
                } else if (sp30->flag == 0 && func_800F6C5C(sp2C) != 0 && func_800F64A4(sp2C, 0x201) != 0 && func_800F52B8(sp2C, NULL) != 6) {
                    func_800F497C(sp2C);
                    func_800F49D4(sp2C, &func_8010D5DC, arg0->unk0);
                    func_800F4A8C(sp2C, arg0->position, 0.6f);
                    func_800F4A00(sp2C, 0);
                    func_800F7F98(sp2C, 1);
                    func_808004B8_chcoderoombits(arg0);
                    func_80101FDC(arg0, 2);
                    sp30->flag = 1;
                }
            }
            break;
        case 2:
            if (func_800F5C94(sp2C) == 4) {
                if (func_800DA298(0x6B) == 0) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1141, 6, NULL, 0);
                    func_800DA544(0x6B);
                    func_80101FDC(arg0, 3);
                } else {
                    func_80101FDC(arg0, 4);
                    func_800F7F98(sp2C, 0);
                }
            }
            break;
        case 3:
            break;
        case 4:
            if (func_800F5C94(sp2C) != 4) {
                func_80101FDC(arg0, 1);
                func_800946C4(func_800F53D0(sp2C), 0);
            }
            break;
        case 5:
            if (func_800C064C() == -1) {
                func_80101FDC(arg0, 4);
            }
            break;
    }
    func_80800BF4_chcoderoombits(arg0);
}

s32 func_8080033C_chcoderoombits(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct player_state_s PlayerState;
    void func_800946C4(PlayerState *, s32);
    s32 *func_800BEC10(void);
    void func_800DBEFC(s32 *, s32, f32 *);
    PlayerState *func_800F53D0(s32);
    u32 func_800F54E4(void);
    s32 func_800F7CF4(s32, s32, void *);
    void func_80101FDC(Actor *, u32);
    void func_8080040C_chcoderoombits(Actor *, s32, s32);
    void func_808004B8_chcoderoombits(Actor *);
    f32 sp24[3];

    switch (arg1) {
        case 0x2E:
            func_8080040C_chcoderoombits(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x32:
            func_800DBEFC(func_800BEC10(), 4, sp24);
            func_800F7CF4(func_800F54E4(), 0x39, sp24);
            func_800946C4(func_800F53D0(func_800F54E4()), 1);
            break;
        case 0x95:
            func_808004B8_chcoderoombits(arg0);
            func_80101FDC(arg0, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_8080040C_chcoderoombits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _susubgame_entrypoint_4(void *, s32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
        case 0x1140:
        case 0x115C:
            _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0));
            break;
        case 0x1141:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(arg0, 4);
            break;
        case 0x115B:
            break;
        default:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(arg0, 4);
            break;
    }
}

struct CodeRoomBit { u8 * unk0; u16 unk4; u16 unk6; u16 unk8; u8 flag; };
extern struct CodeRoomBit D_808011F4_chcoderoombits[];
void *func_80100094(Actor *, u32);
void func_80800E28_chcoderoombits(Actor *);

void func_808004B8_chcoderoombits(Actor *arg0) {
    void *sp1C;
    struct CodeRoomBit *bit;
    s16 *room;

    sp1C = func_80100094(arg0, 0U);
    room = (s16 *)func_80100094(arg0, 0U) + 0xAA;
    bit = D_808011F4_chcoderoombits;
    if (bit->unk0 != 0) {
        do {
            *room = 0;
            bit++;
            room++;
        } while (bit->unk0 != 0);
    }
    *(u8 *)((u8 *)sp1C + 0x19) = 0;
    func_80800E28_chcoderoombits(arg0);
}

s32 func_8080052C_chcoderoombits(Actor *arg0, u8 *arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void func_800FC660(u32);
    s32 func_8080077C_chcoderoombits(Actor *, struct CodeRoomBit *);
    s32 func_80800B40_chcoderoombits(s32, void *);
    void func_8080091C_chcoderoombits(Actor *);
    void func_80800998_chcoderoombits(Actor *);
    void func_80800D90_chcoderoombits(Actor *, s32);
    struct CodeProgress { s16 count; };
    struct RoomData { u8 pad[0x19]; u8 flag; u8 pad1A[0x13A]; struct CodeProgress progress[23]; };
    struct CodeProgress *progress;
    s16 index;
    s32 played;
    s32 normal;
    s32 special;
    struct CodeRoomBit *bit;
    s32 oldFlag;
    struct RoomData *data;

    progress = ((struct RoomData *)func_80100094(arg0, 0))->progress;
    normal = 0;
    special = 0;
    played = 0;
    data = func_80100094(arg0, 0);
    bit = D_808011F4_chcoderoombits;
    if (bit->unk0 != 0) {
        do {
            if (func_80800B40_chcoderoombits((s32)arg0, bit) != 0) {
                goto next;
            }
            {
                index = progress->count;
                if (arg1[0] != ((u8 *)bit->unk0)[index]) {
                    progress->count = 0;
                    goto next;
                }
                if (bit->flag != 0 && data->flag == 0) {
                    progress->count = 0;
                    goto next;
                }
                if (bit->flag == 0 && data->flag != 0) {
                    progress->count = 0;
                    goto next;
                }
                if (bit->flag != 0) {
                    special = 1;
                } else {
                    normal = 1;
                }
                /* Keep the update and test together for IDO scheduling. */
                progress->count = index + 1; if (*(u8 *)(bit->unk0 + progress->count) == 0) {
                    func_808004B8_chcoderoombits(arg0);
                    return func_8080077C_chcoderoombits(arg0, bit);
                }
                if (bit->flag == 0 && played == 0) {
                    played = 1;
                    func_80800D90_chcoderoombits(arg0, arg1[1] - 1);
                    func_800FC660(0xE);
                }
            }
    next:
            bit++;
            progress++;
        } while (bit->unk0 != 0);
    }
    oldFlag = data->flag;
    if (special == 0 && normal != 0 && data->flag != 0) {
        func_8080091C_chcoderoombits(arg0);
    }
    if (special != 0 && normal == 0) {
        func_80800998_chcoderoombits(arg0);
        func_80800E28_chcoderoombits(arg0);
    }
    if (normal == 0 && special == 0) {
        func_808004B8_chcoderoombits(arg0);
        if (oldFlag == 0) {
            func_800FC660(0xF);
            if (func_800DA298(0x668) == 0) {
                func_800DA544(0x668);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x115A, 6, NULL, 0);
                func_800F7F98(func_800F54E4(), 1);
                return 1;
            }
        }
    }
    return 0;
}

s32 func_8080077C_chcoderoombits(Actor *arg0, struct CodeRoomBit *arg1) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D3F2C(s32);
    s32 func_800DA544(s32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void func_800FC660(u32);
    s32 func_80800FDC_chcoderoombits(void);
    struct { u8 pad[0x19]; u8 flag; } *data;
    s32 i;

    data = func_80100094(arg0, 0);
    if (arg1 == D_808011F4_chcoderoombits) {
        func_800FC660(0xE);
        data->flag = 1;
        return 0;
    }
    func_800FC660(0x10);
    switch (arg1->unk4) {
        case 1:
            func_800D3F2C(arg1->unk6);
            break;
        case 2:
            _gcfrontend_entrypoint_9(arg1->unk6);
            break;
        case 3:
            for (i = 0x20; i < 0x2D; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            for (i = 0x60; i < 0x77; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            for (i = 0x80; i != 0x86; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            func_800DA544(0xC08);
            func_800DA544(0xC09);
            func_800DA544(0xC0A);
            func_800DA544(0xC0C);
            break;
    }
    if (arg1->unk8 != 0) {
        if (func_80800FDC_chcoderoombits() == 1 && arg1->flag == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x115B, 6, NULL, 0);
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, arg1->unk8, 6, NULL, 0);
        func_800F7F98(func_800F54E4(), 1);
    }
    return 1;
}

void func_8080091C_chcoderoombits(Actor *arg0) {
    void *data;
    s16 *room;
    struct CodeRoomBit *bit;

    room = (s16 *)func_80100094(arg0, 0U) + 0xAA;
    data = func_80100094(arg0, 0U);
    bit = D_808011F4_chcoderoombits;
    *room = 0;
    *(u8 *)((u8 *)data + 0x19) = 0;
    if (bit->unk0 != 0) {
        do {
            if (bit->flag != 0) {
                *room = 0;
            }
            bit++;
            room++;
        } while (bit->unk0 != 0);
    }
}

void func_80800998_chcoderoombits(Actor *arg0) {
    struct CodeRoomBit *bit;
    s16 *room;

    room = (s16 *)func_80100094(arg0, 0) + 0xAA;
    bit = D_808011F4_chcoderoombits;
    if (bit->unk0 != 0) {
        do {
            if (bit->flag == 0) {
                *room = 0;
            }
            bit++;
            room += 1;
        } while (bit->unk0 != 0);
    }
}

void chcoderoombits_entrypoint_1(s32 arg0, Unk80132ED0 *arg1) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 *func_800BEC10(void);
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800EC398(Unk80132ED0 *, f32 *);
    void func_80101FDC(Actor *, u32);
    s32 func_8080052C_chcoderoombits(Actor *arg0, u8 *arg1);
    extern struct { u8 unk0; u8 unk1; } D_808011B8_chcoderoombits[5][6];
    f32 origin[3];
    f32 position[3];
    int x;
    int y;
    Actor *found;
    Actor *actor;

    found = _subaddiefind_entrypoint_2(0x3CE, 0);
    actor = found;
    if (actor->unk70_10 == 4) {
        func_800DBEFC(func_800BEC10(), 4, origin);
        origin[0] -= 510.0f;
        origin[1] -= 425.0f;
        func_800EC398(arg1, position);
        x = (int)((position[0] - origin[0]) * 0.005882353f);
        y = (int)((position[1] - origin[1]) * 0.005882353f);
        if (x >= 0 && x < 6 && y >= 0 && y < 5) {
          if (D_808011B8_chcoderoombits[y][x].unk0 != 0xFF && func_8080052C_chcoderoombits(actor, &D_808011B8_chcoderoombits[y][x])) {
            func_80101FDC(actor, 5);
            func_808004B8_chcoderoombits(actor);
          }
        }
    }
}

s32 func_80800B40_chcoderoombits(s32 arg0, void *arg1) {
    s32 func_800D3EC8(s32);
    s32 func_800D3E6C(s32);
    s32 _gcfrontend_entrypoint_3(s32);
    s32 func_800DA298(s32);
    struct { s32 unk0; u16 unk4; u16 unk6; u8 unk8[2]; u8 flag; } *bit;

    bit = arg1;
    switch (bit->unk4) {
        case 1:
            if (bit->flag != 0) {
                if (func_800D3EC8(bit->unk6) == 0) {
                    return 1;
                }
            } else {
                if (func_800D3E6C(bit->unk6) == 0) {
                    return 1;
                }
            }
            break;
        case 2:
            if (_gcfrontend_entrypoint_3(bit->unk6) != 0) {
                return 1;
            }
            break;
        case 3:
            if (func_800DA298(0xC0C) != 0) {
                return 1;
            }
            break;
    }
    return 0;
}

void func_80800BF4_chcoderoombits(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800BEA88(s32);
    int func_800D91EC(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    extern s32 _chcoderoombits_entrypoint_2[];
    struct {
        u8 pad[0x1C];
        struct { f32 value; f32 fraction; s32 state; } bits[26];
    } *data;
    Unk80132ED0 *marker;
    s32 id;
    s32 i;

    data = func_80100094(arg0, 0);
    marker = arg0->unk0;
    id = func_800BEA88(0);
    for (i = 0; i != 26; i++) {
        switch (data->bits[i].state) {
            case 0:
                data->bits[i].value = 0.0f;
                break;
            case 1:
                if (func_800D91EC(&data->bits[i].fraction, 0.2f)) {
                    data->bits[i].state = 2;
                }
                data->bits[i].value = func_800F10B4(data->bits[i].fraction, 0.0f, 0.2f, 0.0f, 1.0f);
                break;
            case 2:
                data->bits[i].value = 1.0f;
                break;
            case 3:
                if (func_800D91EC(&data->bits[i].fraction, 0.6f)) {
                    data->bits[i].state = 0;
                }
                data->bits[i].value = func_800F10B4(data->bits[i].fraction, 0.0f, 0.6f, 1.0f, 0.0f);
                break;
        }
        if (id != 0) {
            _glid_entrypoint_0(id, i + 1, _chcoderoombits_entrypoint_2, (s32)marker);
        }
    }
}

/* extern */

void func_80800D90_chcoderoombits(Actor *arg0, s32 arg1) {
    s32 temp_v1;
    struct {
        u8 pad[0x20];
        struct { f32 fraction; s32 state; f32 unk8; } bits[1];
    } *data;
    f32 fraction;

    data = func_80100094(arg0, 0);
    temp_v1 = data->bits[arg1].state;
    switch (temp_v1) {
        case 1:
        case 2:
            break;
        case 3:
            data->bits[arg1].state = 1;
            fraction = (0.6f - data->bits[arg1].fraction) / 0.6f;
            data->bits[arg1].fraction = fraction * 0.2f;
            break;
        case 0:
        data->bits[arg1].state = 1;
        data->bits[arg1].fraction = 0.0f;
            break;
    }
}

void func_80800E28_chcoderoombits(Actor *actor) {
    struct Item { s32 value; f32 time; s32 state; };
    struct CodeData { u8 prefix[0x1C]; struct Item items[26]; };
    struct CodeData *data;
    f32 phase;
    s32 i;
    data = func_80100094(actor, 0);
    for (i = 0; i < 26; i++) {
        switch (data->items[i].state) {
        case 0: break;
        case 1:
            phase = (0.2f - data->items[i].time) / 0.2f;
            data->items[i].state = (s32)(phase * 0.6f);
            break;
        case 2:
            data->items[i].state = 3;
            data->items[i].time = 0.0f;
            break;
        case 3: break;
        }
    }
}

void chcoderoombits_entrypoint_2(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    void func_800F2EA0(void *, void *);
    void func_800F3320(void *, void *, void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80801318_chcoderoombits;
    Vtx *temp_s2;
    typedef struct {
        u8 pad[0x10];
        struct { s32 value; s32 pad[2]; } entries[1];
    } CodeRoomData;
    CodeRoomData *data;
    Actor *actor;
    f32 sp28[1];

    actor = func_80106790(arg4);
    data = func_80100094(actor, 0);
    func_800F3320(sp28, arg1->v.cn, &D_80801318_chcoderoombits, data->entries[arg0].value);
    temp_s2 = arg1 + arg3;
    if (arg1 < temp_s2) {
        do {
            func_800F2EA0(arg2->v.cn, sp28);
            arg1++;
            arg2++;
        } while (arg1 < temp_s2);
    }
}

s32 func_80800FDC_chcoderoombits(void) {
    s32 func_800D3E14(s32);
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s0 = 1;
    var_s2 = 0xD;

    do {
        if (func_800D3E14(var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != var_s2);
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801040_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801048_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801054_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080105C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801068_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801074_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080107C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801088_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801090_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080109C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010A8_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010B4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010C0_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010CC_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010D4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010E0_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010EC_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010F4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801100_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801108_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080111C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801128_chcoderoombits.s")
