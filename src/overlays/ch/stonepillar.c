#include "common.h"

OSThread *chstonepillar_entrypoint_0(void)
{
    extern ActorData D_808013F0_chstonepillar[];

    return (OSThread *) D_808013F0_chstonepillar;
}

OSThread *chstonepillar_entrypoint_1(void)
{
    extern ActorData D_80801438_chstonepillar[];

    return (OSThread *) D_80801438_chstonepillar;
}

void func_80800018_chstonepillar(Actor *arg0)
{
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80800474_chstonepillar(Actor *);
    s32 func_80800870_chstonepillar(Actor *);
    void func_80800ADC_chstonepillar(Actor *, s32);
    s32 func_80800B58_chstonepillar(Actor *);
    void func_80800FE0_chstonepillar(Actor *);
    s32 func_8080112C_chstonepillar(Actor *);
    void func_80801174_chstonepillar(Actor *);
    void func_808011CC_chstonepillar(Actor *, u32, f32, f32);
    s32 func_80801238_chstonepillar(Actor *);
    void func_80801374_chstonepillar(Actor *, s32);
    struct PillarData {
        u8 unk0[0x18];
        f32 position[3];
        f32 unk24;
        s32 unk28;
        s16 index;
        s8 unk2E;
        s8 unk2F;
    };
    struct PillarData *sp2C;
    u32 sp28;
    u32 sp24;

    sp2C = func_80100094(arg0, 0);
    sp28 = arg0->unk70_10;
    func_80800FE0_chstonepillar(arg0);
    if (sp2C->index == 4 || func_800D0B68(8, 1) != 0) {
        if (_glcutDll_entrypoint_19(0xB) != 0 && sp28 == 3) {
            func_80800ADC_chstonepillar(arg0, 0);
        }
    } else if (func_800DA298(0x9D7) != 0 || func_8080112C_chstonepillar(arg0) != 0) {
        func_80801374_chstonepillar(arg0, 2);
        switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(0x9D7) != 0 && sp2C->index == 0) {
                func_80801174_chstonepillar(arg0);
                func_80800B58_chstonepillar(arg0);
                sp2C->unk24 = 0.5f;
                func_800DA524(0x9D7);
                if (func_800DA298(0x9D9) == 0) {
                    sp24 = 0x810;
                    if (_glcutDll_entrypoint_19(0xB) != 0) {
                        sp24 = 0x910;
                    }
                    _capod_entrypoint_13(arg0->unk0, NULL, 0xC, sp24);
                    func_800DA544(0x9D9);
                }
            } else if (func_80800474_chstonepillar(arg0) != 0) {
                func_808011CC_chstonepillar(arg0, 2, 1.0f, 1.0f);
            }
            break;
        case 2:
            if (func_80801238_chstonepillar(arg0) == 0) {
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            if (func_80800870_chstonepillar(arg0) == 0) {
                func_80800ADC_chstonepillar(arg0, 1);
            }
            break;
        }
    }
}

void func_808001FC_chstonepillar(Actor *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3))
{
    void func_80800EE0_chstonepillar(Actor *);
    _subaddiefade_entrypoint_14();
    func_80800EE0_chstonepillar(arg0);
}
void func_80800224_chstonepillar(Actor *arg0) {
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80800C10_chstonepillar(f32 *);
    void func_80800DA4_chstonepillar(BtIntPtr);
    void func_80800E30_chstonepillar(Actor *);
    void func_80800FE0_chstonepillar(Actor *);
    s32 func_8080112C_chstonepillar(Actor *);
    s32 func_80801238_chstonepillar(Actor *);
    void func_80801374_chstonepillar(Actor *, s32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_80800FE0_chstonepillar(arg0);
    func_80801374_chstonepillar(arg0, 2);
    if (arg0->unk70_10 == 2) {
        func_80800C10_chstonepillar(arg0->position);
        if (func_80801238_chstonepillar(arg0) == 0) {
            func_80101FDC(arg0, 1);
            if (func_800D0B68(8, 1) == 0) {
                if (func_800DA298(0x9D8) == 0 && *(s16 *)(sp24 + 0x2C) == 0) {
                    func_800DA544(0x9D8);
                }
                if (func_800DA298(0x9D8) != 0) {
                    if (func_8080112C_chstonepillar(arg0) != 0 && *(s16 *)(sp24 + 0x2C) != 4) {
                        func_80800E30_chstonepillar(arg0);
                    }
                } else {
                    func_80800DA4_chstonepillar((BtIntPtr)arg0);
                }
            }
        }
    }
}

s32 func_8080031C_chstonepillar(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_19(u32);
    void *func_80100094(Actor *, u32);
    void func_808006AC_chstonepillar(Unk80132ED0 **);
    void func_80800704_chstonepillar(Actor *);
    u8 *sp1C;
    s32 *value = &arg2;

    if (arg1 == 0x95) {
        sp1C = func_80100094(arg0, 0);
        func_80800704_chstonepillar(arg0);
        if (_glcutDll_entrypoint_19(0xB) != 0 && *(s16 *)(sp1C + 0x2C) == 0) {
            func_808006AC_chstonepillar(&arg0->unk0);
        }
    } else {
        return 0;
    }
    return 1;
}

s32 func_80800390_chstonepillar(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800CC8_chstonepillar(Actor *, s32);
    void func_80800C44_chstonepillar(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x3F:
            func_80800CC8_chstonepillar(arg0, arg2);
            break;
        case 0x95:
            func_80800C44_chstonepillar(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003F4_chstonepillar(Actor *arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    s32 func_80101808(Actor* arg0, void (*arg1)(Actor*));
    s32 var_s0;

    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800DF744(var_s0 + 1, 0);
    }
    func_800DF744(((u8 *)func_80100094(arg0, 0))[0x2E] + 1, 1);
    func_80101808(arg0, func_801015D0);
}

s32 func_80800474_chstonepillar(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800EFB8C(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8080112C_chstonepillar(Actor *);
    f32 *data;
    f32 distance;

    data = func_80100094(arg0, 0);
    if ((func_8080112C_chstonepillar(arg0) == 0) || (func_800DA298(0x9D5) == 0)) {
        return 0;
    }
    distance = func_800EFB8C(arg0->position, &data[3]);
    data[12] = func_80102D78(arg0, &data[3]);
    data[13] = (0.3f * distance) / 0.5f;
    data[14] = 822.00006f;
    return 1;
}

void func_80800520_chstonepillar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80800EE0_chstonepillar(Actor *);
    void func_808005B4_chstonepillar(Actor *, s32, f32 *);
    struct PillarData {
        f32 positions[2][3];
        u8 pad18[0x10];
        s32 index;
    };
    struct PillarData *data;

    func_80800EE0_chstonepillar(arg0);
    data = func_80100094(arg0, 0);
    func_808005B4_chstonepillar(arg0, data->index, data->positions[0]);
    func_808005B4_chstonepillar(arg0, data->index + 1, data->positions[1]);
    arg0->position[1] -= (f32)data->index * 200.0f;
    *(f32 *)&arg0->actorData[1] = arg0->position[1];
}

void func_808005B4_chstonepillar(Actor *arg0, s32 arg1, f32 *arg2) {
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_80103EF4(Actor *);
    struct PillarData {
        u8 unk0[0x18];
        f32 position[3];
        u8 unk24[8];
        s16 index;
    };
    Actor *actor;
    struct PillarData *data;
    s32 iterator;
    f32 height;

    height = func_80103EF4(arg0);
    actor = _subaddiefind_entrypoint_2(0x12E, &iterator);
    if (actor != NULL) {
        do {
            data = func_80100094(actor, 0);
            if (arg1 == data->index) {
                func_800EE7F8(arg2, data->position);
                arg2[1] += height - (f32)arg1 * 200.0f;
                return;
            }
            actor = _subaddiefind_entrypoint_3(0x12E, &iterator);
        } while (actor != NULL);
    }
    data = func_80100094(arg0, 0);
    func_800EE7F8(arg2, data->position);
    arg2[1] += height - (f32)arg1 * 200.0f;
}

void func_808006AC_chstonepillar(Unk80132ED0 **arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    extern s16 D_80801480_chstonepillar[];
    if (func_800DA298(0x9D5) != 0) {
        _capod_entrypoint_13(*arg0, NULL, D_80801480_chstonepillar[func_800DA564(0x9CD, 3)], 0x810U);
    }
}

void func_80800704_chstonepillar(Actor *arg0) {
    s32 func_800D0B68(u32, u32);
    void func_800D1254(u32, u32, f32 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_808007C8_chstonepillar(Actor *);
    void func_80801174_chstonepillar(Actor *);
    u8 *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    data[0x2F] = 0;
    func_808007C8_chstonepillar(arg0);
    func_80101FDC(arg0, 1);
    if (func_800D0B68(8, 1) != 0) {
        *(s16 *)(data + 0x2C) = -1;
        return;
    }
    if (*(s16 *)(data + 0x2C) == 0) {
        func_808005B4_chstonepillar(arg0, func_800DA564(0x9CD, 3), position);
        func_800D1254(8, 1, position);
        if (func_800DA298(0x9D7) != 0) {
            func_80801174_chstonepillar(arg0);
            func_800DA544(0x9D7);
        }
    }
}

void func_808007C8_chstonepillar(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    Actor *actor;
    f32 *data;
    f32 *other;
    s32 iterator;

    data = func_80100094(arg0, 0);
    actor = _subaddiefind_entrypoint_2(arg0->unk6C_9, &iterator);
    if (actor != NULL) {
        do {
            if (actor != arg0) {
                other = func_80100094(actor, 0);
                if (((s16 *)other)[0x16] == ((s16 *)data)[0x16] + 1) {
                    func_800EE7F8(data + 3, other);
                }
            }
            actor = _subaddiefind_entrypoint_3(arg0->unk6C_9, &iterator);
        } while (actor != NULL);
    }
}

s32 func_80800870_chstonepillar(Actor *arg0) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void func_800D1218(u32, u32, f32 *);
    void func_800D1254(u32, u32, f32 *);
    f32 func_800D8FF8(void);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_8080148C_chstonepillar[3];
    struct PillarData {
        f32 position[3];
        f32 destination[3];
        u8 unknown[0x17];
        u8 bounced;
        f32 angle;
        f32 speed;
        f32 velocity;
    } *data;
    f32 dt;
    f32 position[3];
    f32 acceleration;

    dt = func_800D8FF8();
    data = func_80100094(arg0, 0);
    func_800D1218(8, 1, position);
    _fxsparkle_entrypoint_1(position, 0x12);
    if (data->bounced == 0) {
        if (position[1] < data->destination[1]) {
            position[1] = data->destination[1];
            data->velocity *= -0.54f;
            data->speed *= 0.08f;
            func_800D1254(8, 1, position);
            data->bounced = 1;
            func_8010D930(3, 0, position, D_8080148C_chstonepillar);
            return 1;
        } else {
            acceleration = data->velocity;
            data->velocity -= 1200.0f * dt;
            position[1] += data->velocity * dt;
            if (acceleration >= 0.0f && data->velocity < 0.0f) {
                data->angle = func_800F1DF4(position, data->destination);
            }
            func_800EF1B8(position, data->angle, data->speed * dt);
        }
    } else {
        acceleration = 1200.0f * dt;
        data->velocity -= acceleration;
        position[1] += data->velocity * dt;
        func_800EF1B8(position, data->angle, data->speed * dt);
        if (data->velocity < 0.0f) {
            if (position[1] < data->destination[1]) {
                position[1] = data->destination[1];
                data->velocity *= -0.6f;
                func_8010D930(3, 0, position, D_8080148C_chstonepillar);
                if (data->velocity < 2.0f * acceleration) {
                    func_800D1254(8, 1, position);
                    return 0;
                }
            }
        }
    }
    func_800D1254(8, 1, position);
    return 1;
}

void func_80800ADC_chstonepillar(Actor *arg0, s32 arg1) {
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(u32);
    void func_800DA524(s32 index);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s16 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_800DA524(0x9D5);
    if (arg1 != 0) {
        func_800DA7A8(0x9CD, sp1C[0x16] + 1, 3);
    }
    func_80101FDC(arg0, 1);
    if (_glcutDll_entrypoint_19(0xB) != 0) {
        _glcutDll_entrypoint_17();
    }
}

s32 func_80800B58_chstonepillar(Actor *arg0) {
    s32 *_fxgenlist_entrypoint_0(void);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1218(u32, u32, f32 *);
    void func_800D1254(u32, u32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800BDC_chstonepillar(f32 *);
    f32 position[3];
    f32 *saved;

    saved = func_80100094(arg0, 0);
    func_800D1218(8, 1, position);
    func_800BBCB8(position, position, 1.0f, 0xE, _fxgenlist_entrypoint_0());
    position[1] += 40.0f;
    func_80800BDC_chstonepillar(position);
    func_800D1254(8, 1, saved);
    return 0;
}

void func_80800BDC_chstonepillar(f32 *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80801498_chstonepillar[8];
    func_800BBCB8(arg0, 0, 1.0f, 1, D_80801498_chstonepillar);
}

void func_80800C10_chstonepillar(f32 *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808014B8_chstonepillar[14];
    func_800BBCB8(arg0, arg0, 1.0f, 3, D_808014B8_chstonepillar);
}

void func_80800C44_chstonepillar(Actor *arg0) {
    f32 func_800136E4(f32);
    s32 func_800D0B68(u32, u32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    arg0->rotation[1] = func_800136E4((f32)(3 - *(s16 *)(data + 0x2C)) * 72.0f);
    if (func_800D0B68(8, 1) != 0) {
        *(s16 *)(data + 0x2C) = -1;
    }
    func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
}

void func_80800CC8_chstonepillar(Actor *arg0, s32 arg1) {
    void func_800C3F48(u32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    int func_80800DD8_chstonepillar(Actor *);
    void func_808011CC_chstonepillar(Actor *, u32, f32, f32);
    u8 *data;

    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 != 2) {
        if (*(s16 *)(data + 0x2C) == 0 && func_800DA298(0x9D6) == 0 && func_800D0B68(8, 1) == 0) {
            func_800CE8D8(0, 45.0f, 0x2D);
            func_800CE88C(0, 1);
            func_800DA544(0x9D6);
        }
        if (func_80800DD8_chstonepillar(arg0) != 0) {
            func_800F7F98(func_800F54E4(), 1);
        }
        func_800C3F48(0x7FF57C16);
        func_808011CC_chstonepillar(arg0, 2U, 1.0f, 1.0f);
    }
}

/* extern */

void func_80800DA4_chstonepillar(BtIntPtr arg0) {
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    if (func_800DA298(0x9D8) == 0) {
        func_800DA544(0x9D8);
    }
}

/* extern */

int func_80800DD8_chstonepillar(Actor *arg0) {
    s32 func_800DA298(s32);
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;
    int temp_v1;
    int value;

    sp1C = func_80100094(arg0, 0U);
    value = func_800DA564(0x9CD, 3);
    temp_v1 = *(s16 *)(sp1C + 0x2C);
    return value == temp_v1 &&
        func_800DA298(temp_v1 + 0x65C) == 0;
}

void func_80800E30_chstonepillar(Actor *arg0) {
    void _glcutDll_entrypoint_6(u32, u32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6CC8(BtIntPtr);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if (func_80800DD8_chstonepillar(arg0) == 0) {
        func_800DA524(0x9D5);
        func_800DA7A8(0x9CD, *(s16 *)(sp1C + 0x2C) + 1, 3);
        return;
    }
    func_800F7F98(func_800F54E4(), 0);
    if (func_800F6CC8(func_800F54E4()) == 0) {
        func_800DA544(0x9D5);
        func_800DA544(*(s16 *)(sp1C + 0x2C) + 0x65C);
        _glcutDll_entrypoint_6(0xB9, 0xB);
    }
}

void func_80800EE0_chstonepillar(Actor *arg0) {
    f32 func_800136E4(f32);
    s32 func_800D0B68(u32, u32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct PillarData {
        u8 unk0[0x18];
        f32 position[3];
        f32 unk24;
        s32 unk28;
        s16 index;
        s8 unk2E;
        s8 unk2F;
    };
    struct PillarData *sp1C;

    sp1C = func_80100094(arg0, 0);
    sp1C->index = (s32)arg0->rotation[1] - 1;
    sp1C->unk2F = 0;
    sp1C->unk24 = 0.0f;
    sp1C->unk28 = sp1C->index;
    sp1C->unk2E = (s32)arg0->rotation[1] - 1;
    if ((arg0->unk0->unk24 >> 22) == 0x19F) {
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] - (f32)sp1C->index * 18.0f);
    } else {
        arg0->rotation[1] = 0.0f;
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EE7F8(sp1C->position, arg0->position);
    if (func_800D0B68(8, 1) != 0) {
        sp1C->index = -1;
    }
}

void func_80800FE0_chstonepillar(Actor *arg0) {
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    void func_800FC660(u32);
    void func_808010CC_chstonepillar(BtIntPtr);
    s32 func_8080112C_chstonepillar(Actor *);
    void func_80801174_chstonepillar(Actor *);

    if ((func_800DA298(0x9D6) != 0) && (func_800DA298(0x9D7) == 0) && (func_8080112C_chstonepillar(arg0) != 0) && ((func_800CEAD0(0) != 0) || (func_800D0B68(8, 1) != 0))) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        func_800DA544(0x9D7);
        if (func_800DA298(0x9D9) != 0) {
            func_80801174_chstonepillar(arg0);
            if ((arg0->unk0->unk24 >> 22) != 0x19F) {
                func_800DA524(0x9D7);
            }
        }
        if (func_800D0B68(8, 1) == 0) {
            func_808010CC_chstonepillar((BtIntPtr)arg0);
            func_800FC660(0x17);
        }
    }
}

/* extern */

void func_808010CC_chstonepillar(BtIntPtr arg0) {
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6CC8(BtIntPtr);
    if ((func_800DA298(0x9D9) == 0) && (func_800EA05C() != 0xB9) && (func_800F6CC8(func_800F54E4()) == 0)) {
        _glcutDll_entrypoint_6(0xB9, 0xB);
    }
}    typedef struct { u8 pad0[0x2C]; s16 unk2C; } Objstonepillar_func_8080112C_chstonepillar_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

s32 func_8080112C_chstonepillar(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_800DA564(0x9CD, 3) == (((Objstonepillar_func_8080112C_chstonepillar_sp1C *)sp1C)->unk2C)) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80801174_chstonepillar(Actor *arg0) {
    void func_800DA524(s32 index);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    void func_80101FDC(Actor *, u32);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA524(0x9D6);
    func_800DA524(0x9D5);
    func_80101FDC(arg0, 1);
}

void func_808011CC_chstonepillar(Actor *arg0, u32 arg1, f32 arg2, f32 arg3) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80018820(s32, f32, f32);
    f32 *data;

    if (arg1 != arg0->unk70_10) {
        func_80101FDC(arg0, arg1);
        data = func_80100094(arg0, 0);
        data[9] = arg2;
        arg0->unk58 = 0.3f;
        func_80018820(0, 3.0f, arg3);
    }
}

s32 func_80801238_chstonepillar(Actor *arg0) {
    s32 func_800D0B68(u32, u32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    struct PillarData {
        u8 unk0[0x18];
        f32 position[3];
        f32 unk24;
        s32 unk28;
        s16 index;
        s8 unk2E;
        s8 unk2F;
    };
    f32 position[3];
    struct PillarData *data;

    data = func_80100094(arg0, 0);
    if (func_800D9078(&arg0->unk58) != 0 &&
        (arg0->unk0->unk24 >> 22) != 0x19F &&
        func_800D0B68(8, 1) == 0 && data->index != 4 &&
        func_8080112C_chstonepillar(arg0) != 0) {
        func_800FC660(0xE);
    }
    if (data->unk24 > 0.0f) {
        data->unk24 -= func_800D8FF8();
        func_800EE7F8(position, (f32 *)arg0->actorData);
        position[0] += func_800DC178(-7.5f, 7.5f);
        position[2] += func_800DC178(-7.5f, 7.5f);
        func_800EE7F8(arg0->position, position);
        return 1;
    }
    func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
    return 0;
}

void func_80801374_chstonepillar(Actor *arg0, s32 arg1)
{
  s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
  extern u32 D_808014F0_chstonepillar[4];
  u32 temp_a2;
  temp_a2 = arg1 == ((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA);
  if ((temp_a2 != 0) || ((temp_a2 == 0) && (arg0->unk5F != 0)))
  {
    _subaddieaudioloop_entrypoint_4(arg0, NULL, temp_a2, D_808014F0_chstonepillar);
  }
}
/* data_to_c.py: from asm/data/overlays/ch/stonepillar.data.s */
void func_80105834(Actor*);
void func_80107C2C();
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
ActorData D_808013F0_chstonepillar [1] BT_DATA(4, overlays_ch_stonepillar, 0x0) = { { 415, 302, 1609, 1, 0, (void (*)(struct Actor *))func_80800018_chstonepillar, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808003F4_chstonepillar, 0, 0, 0, 0, 0, 3074, 0, 0, 60, 0, (void (*)(struct Actor *))func_80800520_chstonepillar, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8194, (void (*)(struct Actor *, long, long))func_8080031C_chstonepillar, 0 } };
ActorData D_80801438_chstonepillar [1] BT_DATA(4, overlays_ch_stonepillar, 0x48) = { { 416, 303, 1610, 1, 0, (void (*)(struct Actor *))func_80800224_chstonepillar, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 60, 0, (void (*)(struct Actor *))func_808001FC_chstonepillar, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 8192, (void (*)(struct Actor *, long, long))func_80800390_chstonepillar, 0 } };
s16 D_80801480_chstonepillar [6] BT_DATA(4, overlays_ch_stonepillar, 0x90) = { 4, 6, 8, 10, 0, 0 };
s32 D_8080148C_chstonepillar[3] BT_DATA(4, overlays_ch_stonepillar, 0x9C) = { 1246185, 1459792, 131072 };
s32 D_80801498_chstonepillar[8] BT_DATA(4, overlays_ch_stonepillar, 0xA8) = { 1903049, 1376294, 13369368, 0, 234884608, 2294016, 2818304, 16777216 };
s32 D_808014B8_chstonepillar[14] BT_DATA(4, overlays_ch_stonepillar, 0xC8) = { 1903049, 2293952, 2125412, 1354760213, 2490572, 1572864, 3584, 234881067, 4980864, 721076, 13107200, 45, 11469050, 0 };
u32 D_808014F0_chstonepillar[4] BT_DATA(4, overlays_ch_stonepillar, 0x100) = { 0x1304A9, 0x167D00, 0x140000, 0 };
