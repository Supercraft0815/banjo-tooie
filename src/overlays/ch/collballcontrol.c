#include "common.h"

void func_80800000_chcollballcontrol(Unk80132ED0 **arg0, u32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2 | 0xE, (f32 *)((s8 *)arg0 + 4), 0x33);
}

f32 func_80800040_chcollballcontrol(void *arg0) {
    void *func_80100094(void *, s32);
    extern f32 D_80804CB4_chcollballcontrol[];
    return D_80804CB4_chcollballcontrol[*((u8 *)func_80100094(arg0, 0) + 0x14)];
}

/* extern */

f32 func_80800070_chcollballcontrol(void) {
    f32 func_80800040_chcollballcontrol();
    return func_80800040_chcollballcontrol() * 0.75f;
}

/* extern */

f32 func_8080009C_chcollballcontrol(void) {
    f32 func_80800040_chcollballcontrol();
    return func_80800040_chcollballcontrol() * 0.33f;
}

/* extern */

f32 func_808000C8_chcollballcontrol(void) {
    f32 func_80800040_chcollballcontrol();
    return func_80800040_chcollballcontrol() * 0.05f;
}

void func_808000F4_chcollballcontrol()
{
    func_808000C8_chcollballcontrol();
}

s32 func_80800114_chcollballcontrol(s32 arg0, s32 arg1) {
    extern s32 D_80804CF0_chcollballcontrol;
    return *(s32 *) ((u8 *) &D_80804CF0_chcollballcontrol + (arg0 * 24) + (arg1 * 4));
}

s32 func_80800138_chcollballcontrol(s32 arg0) {
    extern s32 D_80804D68_chcollballcontrol[];
    return ((s32 *)&D_80804D68_chcollballcontrol)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_8080014C_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808001B8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808002B8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808006FC_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808008FC_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80800B5C_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80800BF0_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80800CF8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80800D60_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80800DD8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801038_chcollballcontrol.s")

void func_808010B8_chcollballcontrol(void *arg0, s32 arg1) {
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

s32 func_808010F8_chcollballcontrol(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801108_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808011E8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801350_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801500_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801578_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808015D4_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801650_chcollballcontrol.s")

OSThread *chcollballcontrol_entrypoint_0(void)
{
    extern u8 D_80804DA8_chcollballcontrol[];

    return (OSThread *) D_80804DA8_chcollballcontrol;
}

void func_80801764_chcollballcontrol(u8 *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_3(u8 *);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800F4F98(s32, void *);
    void *func_80100094(void *, s32);
    s32 func_80101FDC(u8 *, s32);
    u8 *func_80106790(s32);
    void func_808021D4_chcollballcontrol(u8 *);
    void func_80802264_chcollballcontrol(u8 *, s32);
    extern u8 D_80804DF0_chcollballcontrol[];
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
    if (state == 3 && arg1 == 2 && (*(u32 *)(*(u8 **)arg0 + 0x24) >> 22) == 0x42) {
        *(f32 *)(data + 0x14) = 20.0f;
        *(f32 *)(data + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(arg0);
        func_808021D4_chcollballcontrol(arg0);
        arg1 = 4;
    }
    func_80101FDC(arg0, arg1);
    if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 6) {
        func_808021D4_chcollballcontrol(arg0);
        _subaddiefade_entrypoint_3(arg0);
        func_800B4470(arg0 + 4, 0, D_80804DF0_chcollballcontrol, 1, 0.75f, 0.0f, 0x7D, 0xFA, 0);
        kind = *(u32 *)(*(u8 **)arg0 + 0x24) >> 22;
        if (kind != 0x43) {
            if (kind == 0x44) {
                func_80802264_chcollballcontrol(arg0, 1);
            }
        } else {
            func_80802264_chcollballcontrol(arg0, 2);
        }
    }
}

void func_80801920_chcollballcontrol(u8 *arg0) {
    void *func_80100094(void *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    *(s8 *)(data + 0x20) = 0x7F;
    *(f32 *)(data + 4) = 0.0f;
    *(f32 *)data = 0.0;
    *(f32 *)(arg0 + 0x24) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801964_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80801A20_chcollballcontrol.s")

/* extern */

void func_808020B0_chcollballcontrol(void *arg0) {
    s32 func_8080237C_chcollballcontrol();
    s32 func_808023FC_chcollballcontrol(void *, s32);
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = func_8080237C_chcollballcontrol();
    temp_a1 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = 30.0f;
    if (temp_v0 != -1) {
        func_808023FC_chcollballcontrol(arg0, temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808020F4_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808021D4_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80802264_chcollballcontrol.s")

void func_808022F0_chcollballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_80804E4C_chcollballcontrol;
    func_800BBCB8(arg0, 0, 1.0f, 2, &D_80804E4C_chcollballcontrol);
}

void func_80802324_chcollballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_80804E94_chcollballcontrol;
    extern s32 D_80804EE4_chcollballcontrol;
    func_800BBCB8(arg0, 0, 1.0f, 0xA, &D_80804E94_chcollballcontrol);
    func_800BBCB8(arg0, 0, 1.0f, 5, &D_80804EE4_chcollballcontrol);
}

s32 func_8080237C_chcollballcontrol(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (4)));
    if (temp_f0 < -675.0f) {
        return 2;
    }
    if (temp_f0 > 675.0f) {
        return 0;
    }
    temp_f0_2 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    if (temp_f0_2 < -675.0f) {
        return 3;
    }
    if (temp_f0_2 > 675.0f) {
        return 1;
    }
    return -1;
}

s32 func_808023FC_chcollballcontrol(void *ptr, s32 arg1) {
    void func_80802AF8_chcollballcontrol(u8 *, s32);
    u8 *arg0 = ptr;

    switch (arg1) {
        case 0:
            if (*(f32 *)(arg0 + 0xC) > -183.0f && *(f32 *)(arg0 + 0xC) < 183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 4) > 720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 0);
                }
                if (*(f32 *)(arg0 + 4) > 801.0f) {
                    *(f32 *)(arg0 + 4) = 846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 4) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 1:
            if (*(f32 *)(arg0 + 4) < 183.0f && *(f32 *)(arg0 + 4) > -183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 0xC) > 720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 1);
                }
                if (*(f32 *)(arg0 + 0xC) > 801.0f) {
                    *(f32 *)(arg0 + 0xC) = 846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 2:
            if (*(f32 *)(arg0 + 0xC) < 183.0f && *(f32 *)(arg0 + 0xC) > -183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 4) < -720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 2);
                }
                if (*(f32 *)(arg0 + 4) < -801.0f) {
                    *(f32 *)(arg0 + 4) = -846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 4) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 3:
            if (*(f32 *)(arg0 + 4) > -183.0f && *(f32 *)(arg0 + 4) < 183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 0xC) < -720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 3);
                }
                if (*(f32 *)(arg0 + 0xC) < -801.0f) {
                    *(f32 *)(arg0 + 0xC) = -846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
    }
}

void func_80802764_chcollballcontrol(s32 *arg0) {
    typedef struct { u8 pad[0x1A]; u16 index; u8 pad1[8]; u32 id:10; u32 flags:22; } Marker;
    typedef struct { Marker *marker; s32 unk4; u32 flags; } Entry;
    s32 *func_800BE3F8(void *);
    Entry *func_800E9E88(s32);
    Entry *func_800E9EB4(s32);
    u8 *func_80106790(s32);
    void func_808028D0_chcollballcontrol(s32 *, u8 *);
    void func_80802964_chcollballcontrol(s32 *, u32);
    void func_808029D8_chcollballcontrol(s32 *, u8 *);
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
                    if (marker->id == 0x44 || marker->id == 0x42 || marker->id == 0x43) {
                        func_808028D0_chcollballcontrol(arg0, func_80106790((s32)marker));
                    }
                    if (marker->id == 0) {
                        func_80802964_chcollballcontrol(arg0, (u32)marker->index >> 5);
                    }
                    if (marker->id == 0x40) {
                        func_808029D8_chcollballcontrol(arg0, func_80106790((s32)marker));
                    }
                }
            }
        }
        list++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808028D0_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80802964_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808029D8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80802A50_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80802AF8_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/chcollballcontrol_entrypoint_1.s")

void func_80802CE0_chcollballcontrol(u8 *arg0) {
    typedef struct { f32 v[4]; } Distances;
    typedef struct { f32 v[3]; } Position;
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    typedef struct { u8 pad[0x3A]; u8 count; } ParentData;
    typedef struct { u8 pad[0x24]; u32 id:10; u32 flags:22; } MarkerState;
    typedef struct { u8 pad[0x70]; u32 upper:16; u32 state:6; u32 flags:10; } ActorState;
    extern Distances D_80804F3C_chcollballcontrol;
    extern Position D_80804F4C_chcollballcontrol;
    extern void _chcollballcontrol_entrypoint_1(void);
    void *func_80100094(void *, s32);
    u8 *func_80106790(s32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    s32 _sukickball_entrypoint_8(u8 *, s32);
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

    *(Distances *)distances = D_80804F3C_chcollballcontrol;
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
                *(Position *)position = D_80804F4C_chcollballcontrol;
                if (_sukickball_entrypoint_6(parent, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, position);
                        if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                            distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                        }
                    }
                } else {
                    func_800EE7F8(position, (f32 *)(func_80106790(_sukickball_entrypoint_8(parent, i)) + 4));
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
                func_800F4950(data->owner, *(void **)arg0, _chcollballcontrol_entrypoint_1);
            } else {
                u8 *player = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                player[0x65] &= ~0x10;
            }
            switch ((*(MarkerState **)arg0)->id) {
                case 0x44:
                    _sukickball_entrypoint_10(parent, data->owner, 1);
                    break;
                case 0x42:
                    _sukickball_entrypoint_10(parent, data->owner, 3);
                    break;
                case 0x43:
                    _sukickball_entrypoint_10(parent, data->owner, 2);
                    break;
            }
            func_80801764_chcollballcontrol(arg0, 2);
            *(f32 *)(arg0 + 0x24) = 0.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808030D0_chcollballcontrol.s")

void func_80803208_chcollballcontrol(s32 arg0)
{
    func_80801764_chcollballcontrol(arg0,0);
}

OSThread *chcollballcontrol_entrypoint_2(void)
{
    extern u8 D_80804F58_chcollballcontrol[];

    return (OSThread *) D_80804F58_chcollballcontrol;
}

OSThread *chcollballcontrol_entrypoint_3(void)
{
    extern u8 D_80804FA0_chcollballcontrol[];

    return (OSThread *) D_80804FA0_chcollballcontrol;
}

OSThread *chcollballcontrol_entrypoint_4(void)
{
    extern u8 D_80804FE8_chcollballcontrol[];

    return (OSThread *) D_80804FE8_chcollballcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_8080324C_chcollballcontrol.s")

void func_808032CC_chcollballcontrol(u8 *arg0, s32 arg1) {
    typedef struct { f32 v[3]; } Vec3;
    f32 func_800DC178(f32, f32);
    s32 func_800EE780(u8 *, u8 *, s32 *);
    s32 func_800EFCD8(s32 *, f32, s32);
    f32 func_80102D78(u8 *);
    s32 func_8080324C_chcollballcontrol(u8 *, s32);
    f32 func_8080009C_chcollballcontrol();
    extern Vec3 D_80805098_chcollballcontrol;
    Vec3 sp2C = D_80805098_chcollballcontrol;
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
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_8080009C_chcollballcontrol(arg0);
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
    func_8080324C_chcollballcontrol(arg0, 7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803420_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803484_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803D54_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803E18_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803EF4_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80803F70_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_8080405C_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80804420_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_808044F4_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_8080451C_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_8080486C_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80804A48_chcollballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/collballcontrol/func_80804AA8_chcollballcontrol.s")

OSThread *chcollballcontrol_entrypoint_5(void)
{
    extern u8 D_808050CC_chcollballcontrol[];

    return (OSThread *) D_808050CC_chcollballcontrol;
}
