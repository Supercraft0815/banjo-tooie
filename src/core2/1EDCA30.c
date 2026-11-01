#include "common.h"

s32 func_80103140(Actor *arg0, u32 arg1, u16 arg2) {
    s32 func_800D58FC(s32);
    void func_800D62E4(s32);
    void func_80103328(Actor *);
    void func_8010381C(Actor *);
    void func_80103938(void *);
    void func_80104328();
    void func_80103930(void *);
    u8 *func_801039E4(Unk80132ED0 *);
    struct ActorFlags {
        u8 pad0[0x70];
        u32 pad70_4 : 28;
        u32 active : 1;
        u32 pad70_0 : 3;
    };
    struct ModelFlags {
        u32 pad0[2];
        u32 pad8_2 : 30;
        u32 hidden : 1;
        u32 pad8_0 : 1;
    };
    u16 newId;
    u32 sp38;
    s32 sp34;
    Unk80132ED0 *temp_v0;
    u16 old;
    s32 sp28[1];
    s32 savedId[1];

    temp_v0 = arg0->unk0;
    old = temp_v0->unk14;
    newId = ((u16 *)&arg1)[1];
    if ((newId == old) && (arg2 == temp_v0->unk16)) {
        return old;
    }
    sp38 = ((struct ActorFlags *)arg0)->active;
    savedId[0] = newId;
    sp28[0] = old;
    func_8010381C(arg0);
    func_80103938(arg0);
    arg0->pad74_31 = 0;
    arg0->unk0->unkC = 0;
    temp_v0 = arg0->unk0;
    ((s16 *)&arg0->pad68)[0] = 0;
    ((s16 *)&arg0->pad68)[1] = 0;
    ((s16 *)&arg0->pad60)[1] = 0;
    ((u16 *)&temp_v0->unk18)[0] &= 0x1F;
    if (((s16 *)&arg0->pad8C)[0] != 0) {
        func_80104328(arg0);
    }
    sp34 = func_800D58FC(savedId[0]);
    arg0->unk0->unk14 = ((u16 *)&arg1)[1];
    arg0->unk0->unk16 = arg2;
    if (sp34 == 0) {
        ((struct ModelFlags *)arg0->unk0->unk0)->hidden = 1;
    } else {
        ((struct ModelFlags *)arg0->unk0->unk0)->hidden = 0;
    }
    if (sp34 == 0) {
        func_80103328(arg0);
    }
    func_80103930(arg0);
    if (sp38 && !((struct ActorFlags *)arg0)->active && sp34 == 0) {
        func_801039E4(arg0->unk0);
        func_800D62E4(arg0->unk0->unk14);
    }
    return sp28[0];
}

/* extern */

s32 func_801032B0(Actor *arg0, u16 arg1, u16 arg2) {
    s32 func_80103140(Actor *, u32, u16);
    void func_80104328(s32);
    s32 var_v1;
    s32 sp18;

    sp18 = ((s16 *)&arg0->pad8C)[0];
    ((s16 *)&arg0->pad8C)[0] = 0;
    var_v1 = func_80103140(arg0, arg1, arg2);
    if (((s16 *)&arg0->pad8C)[0] != 0) {
        func_80104328((s32) arg0);
    }
    ((s16 *)&arg0->pad8C)[0] = sp18;
    return var_v1;
}

void func_80103328(Actor *arg0) {
    void func_800B2198(void *, void *, void *);
    s32 func_800B2248(void *);
    void func_800B237C(void *, f32 *, f32 *);
    s32 func_800B2840(s32);
    void func_800D62E4(s32);
    void func_800EE940(s16 *, f32 *);
    u8 *func_80103964(u8 *);
    typedef struct {
        u16 radius : 11;
        u16 flags : 5;
    } RadiusFlags;
    s32 min[3];
    s32 max[3];
    f32 center[3];
    u16 *list;
    f32 norm;
    u8 *model;

    if (((u16 *)&arg0->pad68)[0] == 0) {
        if ((model = func_80103964((u8 *)arg0->unk0)) != NULL) {
            func_800D62E4(arg0->unk0->unk14);
            list = (u16 *)func_800B2840((s32)model);
            ((u16 *)&arg0->pad68)[0] = list[9];
            ((u16 *)&arg0->pad68)[1] = list[10];
            ((s16 *)&arg0->pad60)[1] = func_800B2248(list);
            func_800B2198(list, min, max);
            ((s16 *)&arg0->pad88)[0] = min[1];
            ((s16 *)&arg0->pad88)[1] = max[1];
            func_800B237C(list, center, &norm);
            func_800EE940(&((s16 *)&arg0->unk0->unk1C)[1], center);
            ((RadiusFlags *)&arg0->unk0->unk18)->radius = (u32)norm;
        }
    }
}

/* extern */

s32 func_8010347C(Unk80132ED0 *arg0) {
    void func_800DF7F8(s32, f32, f32);
    void func_80103328(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;

    sp1C = func_80106790(arg0);
    func_80103328(sp1C);
    func_800DF7F8(arg0->unk14, (f32)(u32)((u16 *)&sp1C->pad68)[0], (f32)(u32)((u16 *)&sp1C->pad68)[1]);
    return 0;
}

void func_80103508(u8 *arg0) {
    struct VertexListView;
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    s16 func_800AE020(void);
    void func_800B25D8(struct VertexListView *, struct VertexListView *, s32);
    s32 func_800B2840(s32);
    void *func_800D674C(s32);
    s32 func_800D6CEC(s32);
    s16 func_800D88F8(void);
    u8 *func_800DBFF8(void);
    void *func_80100368(void *);
    s16 func_80100D24(s32, s32, s32, s32, s32, s32);
    s32 func_8010108C(Actor *, s32, s32);
    void func_80102424(Actor *, s32);
    s32 func_80102FA0(Actor *, s32);
    u8 *func_801039A4(u8 *);
    u8 *func_801039E4(Unk80132ED0 *);
    s32 func_80103C94(Actor *);
    s32 func_80103D24(Actor *);
    void func_80104460(u8 *);
    void func_80105DFC(Actor *);
    Actor *sp5C;
    Unk80132ED0 *sp58;
    void *sp54;
    s32 sp50;
    s32 var_a3;
    s32 var_a2;
    s32 sp3C[3];
    struct {
        u8 pad0[0x70];
        u32 pad70_25 : 7;
        u32 mode2 : 1;
        u32 pad70_22 : 2;
        u32 mode1 : 1;
        u32 pad70_4 : 17;
        u32 active : 1;
        u32 pad70_0 : 3;
        u32 pad74_24 : 8;
        u32 hasResource : 1;
        u32 pad74_0 : 23;
        u8 pad78[3];
        u8 mode : 2;
        u8 pad7B : 6;
        u8 pad7C[0x1A];
        u16 fade : 1;
        u16 pad96 : 15;
    } *flags = (void *)arg0;
    s32 vertices;

    if (!flags->active) {
        sp58 = ((Actor *)arg0)->unk0;
        sp5C = func_80100368(arg0);
        sp50 = (s32)func_801039A4((u8 *)sp58);
        if (sp50 == 0) {
            sp50 = (s32)func_801039E4(sp58);
        }
        func_80103328(arg0);
        sp54 = sp58->unk16 ? func_800D674C(sp58->unk16) : NULL;
        if (flags->mode) {
            var_a3 = 1;
        } else {
            var_a3 = 0;
        }
        var_a2 = flags->mode2 ? 2 : (flags->mode1 ? 1 : 0);
        if ((var_a3 || var_a2) && ((s16 *)&((Actor *)arg0)->pad60)[0] == 0) {
            if (flags->fade) {
                _subaddiefade_entrypoint_9(arg0, sp3C);
            }
            ((s16 *)&((Actor *)arg0)->pad60)[0] = func_80100D24(sp50, sp58->unk14, var_a2, var_a3, sp58->unk16, (s32)(flags->fade ? sp3C : NULL));
        }
        if (sp54 && var_a2 >= 2) {
            vertices = func_80103D24((Actor *)arg0);
            func_800B25D8((struct VertexListView *)vertices, (struct VertexListView *)func_800B2840(sp50), (s32)sp54);
        }
        if (sp54) {
            vertices = func_80103C94((Actor *)arg0);
            func_800B25D8((struct VertexListView *)vertices, (struct VertexListView *)func_800B2840(sp50), (s32)sp54);
            func_800D6CEC(sp58->unk16);
        }
        if (sp58->unk4 == NULL && func_80102FA0(sp5C, 0x40)) {
            sp58->unk4 = (u32 *)func_800DBFF8();
        }
        if (((s16 *)&((Actor *)arg0)->pad90)[0] == 0 && func_80102FA0(sp5C, 0x1000)) {
            func_80105DFC(arg0);
        }
        if (((s16 *)&sp58->unk10)[0] == 0 && func_80102FA0(sp5C, 0x20)) {
            ((s16 *)&sp58->unk10)[0] = func_800AE020();
        }
        if (((u16 *)&((Actor *)arg0)->pad80)[0] == 0 && func_80102FA0(sp5C, 0x4000)) {
            ((u16 *)&((Actor *)arg0)->pad80)[0] = func_800D88F8();
        }
        if (((s16 *)&((Actor *)arg0)->pad8C)[0] == 0 && flags->hasResource) {
            func_80102424(arg0, ((Actor *)arg0)->unk70_10);
        }
        if (((s16 *)&((Actor *)arg0)->pad8C)[1] == 0 && func_80102FA0(sp5C, 0x40000)) {
            func_80104460((u8 *)arg0);
        }
        flags->active = 1;
        func_8010108C(arg0, 0x29, sp50);
    }
}

/* extern */

void func_8010381C(Actor *arg0) {
    void func_800ADFE0(s16);
    void func_800D8954(s16);
    void func_800DBFD8(void *);
    void func_80100E18(s16);
    s32 func_8010108C();
    void func_80104328(s32);
    void func_80104504(void *);
    void func_80106138(Actor *);
    Unk80132ED0 *var_v0;
    struct {
        u8 pad0[0x70];
        u32 pad70_4 : 28;
        u32 active : 1;
        u32 pad70_0 : 3;
        u32 pad74_24 : 8;
        u32 hasResource : 1;
        u32 pad74_0 : 23;
    } *flags = (void *)arg0;
    u16 temp_v0;

    var_v0 = arg0->unk0;
    if (flags->active) {
        if (((s16 *)&arg0->pad60)[0] != 0) {
            func_80100E18(((s16 *)&arg0->pad60)[0]);
            ((s16 *)&arg0->pad60)[0] = 0;
        }
        if (var_v0->unk4 != 0) {
            func_800DBFD8(var_v0->unk4);
            var_v0->unk4 = 0;
        }
        if (((s16 *)&arg0->pad90)[0] != 0) {
            func_80106138(arg0);
        }
        if (((s16 *)&var_v0->unk10)[0] != 0) {
            func_800ADFE0(((s16 *)&var_v0->unk10)[0]);
            ((s16 *)&var_v0->unk10)[0] = 0;
        }
        temp_v0 = ((u16 *)&arg0->pad80)[0];
        if (temp_v0 != 0) {
            func_800D8954((s16)temp_v0);
            ((u16 *)&arg0->pad80)[0] = 0;
        }
        if ((flags->hasResource) && ((s16 *)&arg0->pad8C)[0] != 0) {
            func_80104328((s32)arg0);
        }
        if (((s16 *)&arg0->pad8C)[1] != 0) {
            func_80104504(arg0);
        }
        flags->active = 0;
        func_8010108C(arg0, 0x2A, 0);
    }
}

void func_80103930(void *arg0) 
{
}
/* extern */

void func_80103938(void *arg0) {
    void func_80104504();
    if ((*(s16 *)((s8 *)(arg0) + (0x8E))) != 0) {
        func_80104504();
    }
}

/* extern */

u8 *func_80103964(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return func_800D674C(temp_a1);
}

u8 *func_801039A4(u8 *arg0) {
    void *func_800D6B0C(s32);
    s32 temp_a1;

    temp_a1 = *(u16 *)(arg0 + 0x14);
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return func_800D6B0C(temp_a1);
}

u8 *func_801039E4(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80103D48(void **);
    s32 func_80103D70(void **);
    void func_80103508(u8 *);
    u8 *func_800B2824(u8 *);
    void _subaddiecustomhits_entrypoint_0(Actor *, void *);
    extern u8 _subaddiecustomhits_entrypoint_1;
    u8 *sp24;
    Actor *actor;
    typedef struct {
        u32 pad0[2];
        u32 pad8_2 : 30;
        u32 unk8_1 : 1;
        u32 pad8_0 : 1;
    } HitData;

    sp24 = func_80103964(arg0);
    if (sp24 == NULL) {
        return NULL;
    }
    actor = func_80106790(arg0);
    func_80103D48(actor);
    func_80103508(actor);
    if (!actor->pad74_31 && arg0->unkC == 0) {
        if (((HitData *)arg0->unk0)->unk8_1 && func_800B2824(sp24) != NULL) {
            _subaddiecustomhits_entrypoint_0(actor, &_subaddiecustomhits_entrypoint_1);
        }
        actor->pad74_31 = 1;
    }
    func_80103D70(actor);
    return sp24;
}

void func_80103AA0(u8 *arg0)
{
    func_801039A4(arg0);
}

/* extern */

s32 func_80103AC0(Actor *arg0) {
    s32 func_800D6C34(u16);
    return func_800D6C34((*(u16 *)((s8 *)(arg0->unk0) + (0x14))));
}

/* extern */

s32 func_80103AE4(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a1);
}

/* extern */

int func_80103B24(u8 *arg0, s32 arg1, u8 *arg2) {
    struct ModelActor {
        u8 pad0[0x60];
        s16 id;
        u8 pad62[0xE];
        u32 pad70_25 : 7;
        u32 flag24 : 1;
        u32 flag23 : 1;
        u32 pad70_22 : 1;
        u32 flag21 : 1;
        u32 pad70_0 : 21;
    } *actor = (struct ModelActor *)arg0;
    s32 func_800B2840(s32);
    s32 func_80100A74(s16, s32);
    s16 id;

    if (arg2 == 0) {
        return 0;
    }
    if (actor->flag24) {
        id = actor->id;
        if (id != 0) {
            return func_80100A74(id, actor->flag23 ^ arg1);
        }
    }
    if (actor->flag21) {
        id = actor->id;
        if (id != 0) {
            return func_80100A74(id, 0);
        }
    }
    return func_800B2840((s32)arg2);
}

void func_80103BBC(Actor *arg0) {
    int func_80103B24(u8 *, s32, u8 *);
    func_80103B24(arg0, 0, func_801039A4(arg0->unk0));
}

/* extern */

s32 func_80103BF0(Actor *arg0, u32 arg1, u32 arg2) {
    struct ModelActor {
        u8 *unk0;
        u8 pad4[0x5C];
        s16 id;
        u8 pad62[0xE];
        u32 pad70_25 : 7;
        u32 flag24 : 1;
        u32 flag23 : 1;
        u32 pad70_22 : 1;
        u32 flag21 : 1;
        u32 pad70_0 : 21;
    } *actor = (struct ModelActor *)arg0;
    s32 func_800B2840(s32);
    s32 func_80100A74(s16, s32);

    if (arg2 == 0) {
        arg2 = func_80103964(actor->unk0);
    }
    if (arg2 == 0) {
        return 0;
    }
    if (actor->flag24) {
        return func_80100A74(actor->id, actor->flag23 ^ arg1);
    }
    if (actor->flag21) {
        return func_80100A74(actor->id, 0);
    }
    return func_800B2840(arg2);
}

s32 func_80103C94(Actor *arg0) {
    s32 func_80103BF0(Actor*, u32, u32);
    return func_80103BF0(arg0, 0U, 0U);
}

s32 func_80103CB8(Actor *arg0, u32 arg1) {
    s32 func_80103BF0(Actor*, u32, u32);
    return func_80103BF0(arg0, 0U, arg1);
}

s32 func_80103CDC(u8 *arg0, u8 *arg1) {
    int func_80103B24(u8 *, s32, u8 *);
    return func_80103B24(arg0, 0, arg1);
}

void func_80103D00(s32 arg0,s32 arg1)
{
    func_80103B24(arg0,0x1,arg1);
}

s32 func_80103D24(Actor *arg0) {
    s32 func_80103BF0(Actor*, u32, u32);
    func_80103BF0(arg0, 1, 0);
}

/* extern */

void func_80103D48(void **arg0) {
    s32 func_800D70F8(s32, s32);
    func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 1);
}

/* extern */

s32 func_80103D70(void **arg0) {
    s32 func_800D70F8(s32, s32);
    return func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 0);
}

u8 *func_80103D98(Unk80132ED0 *arg0) {
    s32 func_800AE0E8(s16);
    void func_800D62E4(s32);
    u8 *func_800B2824(u8 *);
    u8 *value;

    if (func_800AE0E8(*(s16 *)&arg0->unk10) == 0) {
        return NULL;
    }
    value = func_801039A4(arg0);
    if (value == NULL) {
        return NULL;
    }
    func_800D62E4(arg0->unk14);
    return func_800B2824(value);
}

void func_80103DFC(Actor *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80103328(Actor *);
    s16 temp_v0;

    if ((u16)arg0->unk0->unk14 == 0xFFFF) {
        func_800EE7F8(arg1, arg0->position);
        return;
    }
    func_80103328(arg0);
    func_800EE7F8(arg1, arg0->position);
    temp_v0 = ((s16 *)&arg0->pad88)[0];
    arg1[1] += arg0->scale * ((f32)temp_v0 + (f32)(((s16 *)&arg0->pad88)[1] - temp_v0) * 0.5f);
}

/* extern */

f32 func_80103EAC(Actor *arg0) {
    void func_80103328(Actor *);
    func_80103328(arg0);
    return arg0->scale * (u32)(u16)arg0->pad60;
}

/* extern */

f32 func_80103EF4(Actor *arg0) {
    void func_80103328(Actor *);
    func_80103328(arg0);
    return (f32) ((*(s16 *)((s8 *)(arg0) + (0x8A))) - (*(s16 *)((s8 *)(arg0) + (0x88)))) * arg0->scale;
}

/* extern */

f32 func_80103F38(Actor *arg0, f32 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_80103328(Actor *);

    func_80103328(arg0);
    if (arg1 != 0) {
        func_800EE88C(arg1, (s16 *)&arg0->unk0->unk1C + 1);
        func_800EF334(arg1, arg0->scale);
        func_800EF04C(arg1, arg0->position);
    }
    return (f32)(u32)*(u16 *)&arg0->pad68 * arg0->scale;
}

/* extern */

f32 func_80103FB8(Actor *arg0) {
    void func_80103328(Actor *);
    func_80103328(arg0);
    return (f32) (u32) (u16) arg0->pad68 * arg0->scale;
}

/* extern */

s32 func_80104004(Actor *arg0, f32 *arg1, f32 *arg2) {
    void func_800B2198(void *, void *, void *);
    s32 func_800B2840(s32);
    void func_800D62E4(s32);
    void func_800EE84C(f32 *, s32 *);
    void func_800EF334(f32 *, f32);
    u8 *func_801039E4(Unk80132ED0 *);
    s32 sp2C[3];
    s32 sp20[3];
    s32 vertices;
    s32 temp_v0;

    if ((temp_v0 = func_801039E4(arg0->unk0)) == 0) {
        return 0;
    }
    (void)func_800D62E4(arg0->unk0->unk14);
    vertices = func_800B2840(temp_v0);
    func_800B2198((void *)vertices, sp2C, sp20);
    func_800EE84C(arg1, sp2C);
    func_800EE84C(arg2, sp20);
    func_800EF334(arg1, arg0->scale);
    func_800EF334(arg2, arg0->scale);
    return 1;
}

/* extern */

void *func_801040A8(Actor *arg0) {
    void *func_800AE080(s16);
    return func_800AE080(*(s16 *)&arg0->unk0->unk10);
}
