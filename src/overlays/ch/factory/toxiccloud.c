#include "common.h"

extern u32 D_80801420_chfactorytoxiccloud[];
extern u32 D_8080144C_chfactorytoxiccloud[];
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80800000_chfactorytoxiccloud(Actor *arg0);
void func_808001B8_chfactorytoxiccloud(Actor *arg0);
void func_80800C7C_chfactorytoxiccloud();
void func_808011A0_chfactorytoxiccloud();

u32 D_80801420_chfactorytoxiccloud[] = {
    0x00020000, 0x00060000, 0x00060000, 0x00000000,
    0x00070000,
};

u32 D_80801434_chfactorytoxiccloud[] = {
    0x00000003, 0x3FC00000, 0x00010000, 0x00000001,
    0x3F99999A, 0x02030000,
};

u32 D_8080144C_chfactorytoxiccloud[] = {
    0x00000000, 0x00000000, 0x3F800000, 0x02690001,
    0x40000000, 0x02690001, 0x3F800000, 0x02690001,
    0x3F800000, 0x02690001, 0x3F800000, 0x02690021,
    0x3F800000, 0x02690001, 0x3F800000, 0x02690001,
};

u32 D_8080148C_chfactorytoxiccloud[] = {
    0x001D09D0, 0x00160008, 0x00180000, 0x000F0000,
    0x0023000E, 0x00000032, 0x002B00C0, 0x01000022,
    0x00660080, 0x01800200, 0x00150073, 0x00990020,
    0x0AFF033C, 0x002CFFCE, 0xFFCEFFCE, 0x00320000,
    0x00320000,
};

u32 D_808014D0_chfactorytoxiccloud[] = {
    0x00000000, 0xC2B40000, 0x00000000, 0x00000000,
    0x00000000, 0x42B40000, 0x42340000, 0xC2340000,
    0x42B40000, 0x00000000, 0x42340000, 0x42340000,
    0xC2340000, 0xC2340000, 0xC2B40000, 0x00000000,
    0xC2340000, 0x42340000,
};

u32 D_80801518_chfactorytoxiccloud[] = {
    0x001D09D0, 0x00160008, 0x00180000, 0x000F0000,
    0x0023000E, 0x00000032, 0x002B00F5, 0x018C0022,
    0x003300C0, 0x02330280, 0x00150059, 0x00990020,
    0x0AFF0350, 0x002CFF9C, 0x0064FF9C, 0x006400C8,
    0x00640000,
};

u32 D_8080155C_chfactorytoxiccloud[] = {
    0x00000000, 0x42C80000, 0x00000000,
};

u32 D_80801568_chfactorytoxiccloud[] = {
    0x011603FF, 0x07090002, (u32)D_8080144C_chfactorytoxiccloud, (u32)func_808001B8_chfactorytoxiccloud,
    (u32)func_80105834, (u32)func_80800C7C_chfactorytoxiccloud, 0x0FA00000, 0x00000000,
    0x00000000, 0x00A20261, 0x00000000, (u32)func_80108ED0,
    0x01440000, (u32)func_80800000_chfactorytoxiccloud, (u32)func_80107C2C, 0x8020540D,
    (u32)func_808011A0_chfactorytoxiccloud, (u32)D_80801420_chfactorytoxiccloud,
};

void func_80800000_chfactorytoxiccloud(Actor *arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_80800A34_chfactorytoxiccloud(s32, void *);
    void func_80800FCC_chfactorytoxiccloud(Actor *, s32);
    s32 offset;
    u8 *data;
    u8 *entry;

    data = func_80100094(arg0, 0);
    if (arg0->unk7A_5) {
        arg0->scale = 1.0f;
        _subaddiefade_entrypoint_1((s32)arg0, 0xFF);
        *(f32 *)&arg0->actorData[3] = 600.0f;
    } else {
        func_80102424(arg0, 1);
        arg0->unk58 = 0.0f;
        _subaddiefade_entrypoint_1((s32)arg0, 0);
        arg0->unk64_16 = 0;
        arg0->scale = 0.0f;
        func_8010A570(arg0);
    }
    arg0->unk64_24 = 1;
    func_80800FCC_chfactorytoxiccloud(arg0, 1);
    for (offset = 0, entry = data; offset != 0x144; offset += 0x24, entry += 0x24) {
        func_80800A34_chfactorytoxiccloud((s32)arg0, entry);
    }
}

/* extern */

s32 func_808000F0_chfactorytoxiccloud(void *arg0, void *arg1) {
    union CloudActor {
        Actor actor;
        struct {
            u8 pad[0x70];
            u32 first : 7;
            u32 unused : 9;
            u32 state : 6;
            u32 second : 6;
            u32 tail : 4;
        } data;
    };
    s32 func_800CC338(s32 *, s32, s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    int func_80800BF8_chfactorytoxiccloud();
    u32 temp_t9;

    if (func_800CC338(arg1, ((union CloudActor *)arg0)->data.first - 1, ((union CloudActor *)arg0)->data.second - 1) == -1) {
        return 0;
    }
    if (func_80800BF8_chfactorytoxiccloud(arg0, arg1) == 0) {
        return 0;
    }
    temp_t9 = ((Actor *)arg0)->unk70_10;
    if (temp_t9 == 5) {
        return 0;
    }
    if (temp_t9 == 1) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x1601) == 0) {
        return 0;
    }
    return 1;
}

void func_808001B8_chfactorytoxiccloud(Actor *arg0) {
    union CloudActor {
        Actor actor;
        struct {
            u8 pad[0x70];
            u32 first : 7;
            u32 unused : 9;
            u32 state : 6;
            u32 second : 6;
            u32 tail : 4;
            u32 pad74;
            u32 pad78 : 29;
            u32 inactive : 1;
            u32 tail78 : 2;
        } data;
    };
    struct CloudData {
        f32 origin[3];
        f32 speed;
        f32 ceiling;
        f32 unused[2];
        f32 floor;
    };
    struct CloudParticle {
        f32 interval;
        f32 timer;
        s32 index;
        f32 rest[6];
    };
    s32 _subaddieDll_entrypoint_11(void *, s32, s32);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800CC338(s32 *, s32, s32);
    void func_800CF2D4(s32);
    void func_800CF494(void);
    f32 func_800D8FF8(void);
    int func_800D91EC(f32 *, f32);
    f32 func_800DC0C0(void);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800F54E4(void);
    f32 func_800F5F24(u32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102BAC(Actor *, f32, f32, f32);
    void func_8010A590(Actor *);
    void func_80800A34_chfactorytoxiccloud(s32, void *);
    void func_80800AD8_chfactorytoxiccloud(s32, f32 *volatile);
    void func_80800FCC_chfactorytoxiccloud(Actor *, s32);
    void func_808010B8_chfactorytoxiccloud(void *);
    s32 func_80801164_chfactorytoxiccloud(Actor *, s32, s32);
    s32 func_808012C4_chfactorytoxiccloud(Actor *);
    f32 position[3];
    f32 scale;
    s32 i;
    f32 yaw;
    f32 fraction;
    f32 difference[3];
    struct CloudParticle *entry;
    s32 offset;
    struct CloudParticle *particle;
    f32 distance;

    func_80800AD8_chfactorytoxiccloud((s32)arg0, position);
    i = 4;
    if (func_808000F0_chfactorytoxiccloud(arg0, position)) {
        func_80102424(arg0, i);
    } else if (arg0->unk64_19) {
        func_800CF494();
        arg0->unk64_19 = 0;
    }
    if (!((union CloudActor *)arg0)->data.inactive) {
        switch (arg0->unk70_10) {
        case 1:
            if (func_800D91EC(&arg0->unk58, 0.3f)) {
                _subaddiefade_entrypoint_1((s32)arg0, 255);
                arg0->scale = 1.0f;
                if (arg0->unk64_29) {
                    func_80102424(arg0, 3);
                } else {
                    func_80102424(arg0, 2);
                }
            } else {
                scale = func_800F10B4(arg0->unk58, 0.0f, 0.3f, 0.0f, 1.0f);
                _subaddiefade_entrypoint_1((s32)arg0, (u16)(255.0f * scale));
                arg0->scale = scale;
                arg0->unk64_16 = 1;
                func_8010A590(arg0);
                arg0->position[1] += 10.0f;
            }
            break;
        case 2:
            if (arg0->unk64_29) {
                func_808010B8_chfactorytoxiccloud(arg0);
            } else {
                ((struct CloudData *)arg0->actorData)->speed = func_800F15F8(((struct CloudData *)arg0->actorData)->speed, 150.0f, func_800D8FF8() * 200.0f);
                func_80102BAC(arg0, 0.5f, 0.05f, 5.0f);
                if ((func_80801164_chfactorytoxiccloud(arg0, 0x125, 4) & 4) || func_800DC0C0() < 0.004f) {
                    yaw = func_800DC0C0() * 360.0f;
                    for (i = 0; i != 6; i++) {
                        if (_subaddieDll_entrypoint_11(arg0, (s32)yaw, (s32)((struct CloudData *)arg0->actorData)->speed)) {
                            arg0->unk54 = yaw;
                            break;
                        }
                    }
                }
                if (func_800CC338(position, ((union CloudActor *)arg0)->data.first - 1, ((union CloudActor *)arg0)->data.second - 1) != -1 && func_808012C4_chfactorytoxiccloud(arg0)) {
                    func_80102424(arg0, 3);
                }
            }
            func_80800FCC_chfactorytoxiccloud(arg0, 0);
            arg0->position[1] = func_800F15F8(arg0->position[1], ((struct CloudData *)arg0->actorData)->floor + 120.0f, func_800D8FF8() * 100.0f);
            if (((struct CloudData *)arg0->actorData)->ceiling < arg0->position[1]) {
                arg0->position[1] = ((struct CloudData *)arg0->actorData)->ceiling;
            }
            break;
        case 3:
            if (arg0->unk64_29) {
                func_808010B8_chfactorytoxiccloud(arg0);
            } else {
                arg0->unk54 = func_800F1DF4(arg0->position, position);
                func_80102BAC(arg0, 1.0f, 0.1f, 10.0f);
                ((struct CloudData *)arg0->actorData)->speed = func_800F15F8(((struct CloudData *)arg0->actorData)->speed, 600.0f, func_800D8FF8() * 500.0f);
                if (func_80801164_chfactorytoxiccloud(arg0, 0x125, 4) & 4) {
                    func_80102424(arg0, 2);
                }
                if (func_800CC338(position, ((union CloudActor *)arg0)->data.first - 1, ((union CloudActor *)arg0)->data.second - 1) == -1 || !func_808012C4_chfactorytoxiccloud(arg0)) {
                    func_80102424(arg0, 2);
                }
            }
            func_80800FCC_chfactorytoxiccloud(arg0, 0);
            if (((struct CloudData *)arg0->actorData)->floor < position[1] && position[1] < ((struct CloudData *)arg0->actorData)->ceiling) {
                arg0->position[1] = func_800F15F8(arg0->position[1], position[1], func_800D8FF8() * 100.0f);
            } else {
                arg0->position[1] = func_800F15F8(arg0->position[1], ((struct CloudData *)arg0->actorData)->floor + 120.0f, func_800D8FF8() * 100.0f);
                if (((struct CloudData *)arg0->actorData)->ceiling < arg0->position[1]) {
                    arg0->position[1] = ((struct CloudData *)arg0->actorData)->ceiling;
                }
            }
            break;
        case 4:
            if (arg0->unk64_29) {
                func_808010B8_chfactorytoxiccloud(arg0);
            } else {
                distance = func_800EEAD4(position, arg0->position);
                fraction = distance / func_800D8FF8() / 600.0f;
                ((struct CloudData *)arg0->actorData)->speed = func_800EFB8C(arg0->position, position) / func_800D8FF8();
                if (((struct CloudData *)arg0->actorData)->speed > 600.0f) {
                    ((struct CloudData *)arg0->actorData)->speed = 600.0f;
                }
                if (fraction > 1.0f) {
                    func_800EFB24(difference, position, arg0->position);
                    func_800EF334(difference, 1.0f / fraction);
                    func_800EF04C(arg0->position, difference);
                } else {
                    arg0->position[0] = position[0];
                    arg0->position[2] = position[2];
                }
                arg0->unk54 = func_800F5F24(func_800F54E4());
                func_80102BAC(arg0, 1.0f, 0.1f, 10.0f);
            }
            func_80102424(arg0, 3);
            if (!arg0->unk64_19) {
                func_800CF2D4(4);
                arg0->unk64_19 = 1;
            }
            func_80800FCC_chfactorytoxiccloud(arg0, 0);
            if (((struct CloudData *)arg0->actorData)->floor < position[1] && position[1] < ((struct CloudData *)arg0->actorData)->ceiling) {
                arg0->position[1] = func_800F15F8(arg0->position[1], position[1], func_800D8FF8() * 100.0f);
            } else {
                arg0->position[1] = func_800F15F8(arg0->position[1], ((struct CloudData *)arg0->actorData)->floor + 120.0f, func_800D8FF8() * 100.0f);
                if (((struct CloudData *)arg0->actorData)->ceiling < arg0->position[1]) {
                    arg0->position[1] = ((struct CloudData *)arg0->actorData)->ceiling;
                }
            }
            break;
        case 5:
            if (!((union CloudActor *)arg0)->data.inactive) {
                func_80102424(arg0, 2);
            }
            break;
        }
        if (arg0->unk70_10 != 5 && arg0->unk7C_12) {
            particle = func_80100094(arg0, 0);
            for (offset = 0; offset < 9; offset++) {
                entry = &particle[offset];
                if (func_800D91EC(&entry->timer, entry->interval)) {
                    if (func_800DC0C0() < 0.5f) {
                        func_800BBCB8(arg0->position, NULL, arg0->scale, 1, ((s32 *)D_8080148C_chfactorytoxiccloud));
                    }
                    func_80800A34_chfactorytoxiccloud((s32)arg0, entry);
                }
            }
        }
    }
}

/* extern */

void func_80800A34_chfactorytoxiccloud(s32 arg0, void *arg1) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_800DC178(0.5f, 1.0f);
    (*(f32 *)((s8 *)(arg1) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg1) + (0xC))) = (f32) (func_800DC178(0.4f, 0.5f) + 0.2f);
    (*(f32 *)((s8 *)(arg1) + (0x10))) = (f32) (func_800DC178(0.7f, 0.9f) + 0.2f);
    (*(s32 *)((s8 *)(arg1) + (8))) = func_800DC128(0, 0x10);
}

/* extern */

void func_80800AD8_chfactorytoxiccloud(s32 arg0, f32 *volatile arg1) {
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void func_800F5A2C(s32, s32, f32 *);
    f32 func_800F5F24(u32);
    f32 sp34[3];
    f32 sp28[3];
    s32 temp_v0;

    temp_v0 = func_800F5410(func_800F54E4());
    if ((temp_v0 == 1) || (temp_v0 == 0xA) || (temp_v0 == 0xB)) {
        func_800F5A2C(func_800F54E4(), 5, sp34);
        func_800F5A2C(func_800F54E4(), 2, sp28);
        func_800EFE50(arg1, sp34, sp28, 0.5f);
        func_800EEB9C(sp34, func_800F5F24(func_800F54E4()), 20.0f);
        sp34[1] += 20.0f;
        func_800EF04C(arg1, sp34);
        return;
    }
    func_800F5A00(func_800F54E4(), arg1);
    func_800EF1B8(arg1, func_800F5F24(func_800F54E4()), 30.0f);
    arg1[1] += 140.0f;
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x64];
        u32 pad64_30 : 2;
        u32 unk64_29 : 1;
        u32 pad64_0 : 29;
    } flags;
} ToxicCloudActor;

int func_80800BF8_chfactorytoxiccloud(ToxicCloudActor *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    f32 temp_f2;
    f32 var_f12;

    if (arg0->flags.unk64_29) {
        var_f12 = 6.0f;
    } else {
        var_f12 = 2.0f;
    }
    temp_f2 = var_f12 * 25.0f;
    return func_800EEB40(arg1, (f32 *)arg0->actor.actorData) < (temp_f2 * temp_f2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800C7C_chfactorytoxiccloud.s")

/* extern */

void func_80800FCC_chfactorytoxiccloud(Actor *arg0, s32 arg1) {
    s32 func_8001210C(s32);
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void *func_800CC63C(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    struct {
        f32 position[3];
        s16 unkC;
        s16 height;
    } *node;

    typedef union {
        Actor actor;
        struct {
            u8 pad0[0x70];
            u32 first : 7;
            u32 pad70 : 15;
            u32 second : 6;
            u32 tail : 4;
        } indices;
    } Cloud;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    if ((func_8001210C(3) == 0) || (arg1 != 0)) {
        func_800EE7F8(sp40, arg0->position);
        sp40[1] += 400.0f;
        func_800EE7F8(sp34, arg0->position);
        sp34[1] -= 1000.0f;
        if (func_800BEF00(sp40, sp34, sp28, 0) != 0) {
            ((f32 *)arg0->actorData)[7] = sp34[1];
        } else {
            ((f32 *)arg0->actorData)[7] = arg0->position[1];
        }
        node = func_800CC63C(((Cloud *)arg0)->indices.first - 1, ((Cloud *)arg0)->indices.second - 1);
        ((f32 *)arg0->actorData)[4] = node->position[1] + (f32)node->height - 25.0f;
    }
}

/* extern */

void func_808010B8_chfactorytoxiccloud(void *arg0) {
    f32 _subaddiejoy_entrypoint_3();
    f32 func_80013728(f32);
    void func_80102BAC(Actor *, f32, f32, f32);
    s32 func_8010BA80(void *, s32, s32);
    f32 mlAbsF(f32);
    f32 sp24;

    sp24 = _subaddiejoy_entrypoint_3() * 650.0f;
    func_80102BAC(arg0, 1.5f, 1.0f, 25.0f);
    if (mlAbsF(func_80013728((*(f32 *)((s8 *)(arg0) + (0x54))) - (*(f32 *)((s8 *)(arg0) + (0x48))))) < 90.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = sp24;
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) (sp24 / 10.0f);
    }
    func_8010BA80(arg0, 0x200026, 0x20);
}

/* extern */

s32 func_80801164_chfactorytoxiccloud(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_8010BA80(void *, s32, s32);
    f32 sp1C;
    s32 result;

    sp1C = (*(f32 *)((s8 *)(arg0) + (0x48)));
    (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x54)));
    result = func_8010BA80(arg0, arg1, arg2);
    (*(f32 *)((s8 *)(arg0) + (0x48))) = sp1C;
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808011A0_chfactorytoxiccloud.s")

s32 func_808012C4_chfactorytoxiccloud(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u8 pad[0x78];
            u32 head : 29;
            u32 inactive : 1;
            u32 tail : 2;
        } flags;
    } Cloud;
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    f32 func_800EEB40(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    u8 *actors[10];
    f32 distance;
    s32 count;
    s32 i;
    s32 result;
    f32 position[3];
    u8 **iter;
    Actor *other;

    count = _subaddiefind_entrypoint_4(0x3FF, actors, 10);
    if (count >= 2) {
        result = 1;
        func_800F5A00(func_800F54E4(), position);
        distance = func_800EEB40(arg0->position, position);
        i = 0;
        if (count > 0) {
            iter = actors;
            do {
                other = (Actor *)*iter;
                if (!((Cloud *)other)->flags.inactive && arg0 != other) {
                    result &= distance < func_800EEB40(other->position, position);
                    if (!result) {
                        return 0;
                    }
                }
                i++;
                iter++;
            } while (i != count);
        }
        return result;
    }
    return 1;
}

OSThread *chfactorytoxiccloud_entrypoint_0(void)
{
    return (OSThread *) ((u8 *)D_80801568_chfactorytoxiccloud);
}
