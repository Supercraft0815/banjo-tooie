#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103140.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103328.s")

/* extern */

s32 func_8010347C(Unk80132ED0 *arg0) {
    void func_800DF7F8(s32, f32, f32);
    s32 func_80103328();
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;

    sp1C = func_80106790(arg0);
    func_80103328(sp1C);
    func_800DF7F8(arg0->unk14, (f32)(u32)((u16 *)&sp1C->pad68)[0], (f32)(u32)((u16 *)&sp1C->pad68)[1]);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103508.s")

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

void func_80103930(s32 arg0) 
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

s32 func_80103964(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a1);
}

s32 func_801039A4(u8 *arg0) {
    s32 func_800D6B0C(s32);
    s32 temp_a1;

    temp_a1 = *(u16 *)(arg0 + 0x14);
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return func_800D6B0C(temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_801039E4.s")

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

void func_80103D24(Actor *arg0) {
    s32 func_80103BF0(Actor*, u32, u32);
    func_80103BF0(arg0, 1, 0);
}

/* extern */

void func_80103D48(void **arg0) {
    s32 func_800D70F8(u16, s32);
    func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 1);
}

/* extern */

void func_80103D70(void **arg0) {
    s32 func_800D70F8(u16, s32);
    func_800D70F8((*(u16 *)((s8 *)(*arg0) + (0x14))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103D98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDCA30/func_80103DFC.s")

/* extern */

f32 func_80103EAC(Actor *arg0) {
    s32 func_80103328();
    func_80103328(arg0);
    return arg0->scale * (u32)(u16)arg0->pad60;
}

/* extern */

f32 func_80103EF4(Actor *arg0) {
    s32 func_80103328();
    func_80103328();
    return (f32) ((*(s16 *)((s8 *)(arg0) + (0x8A))) - (*(s16 *)((s8 *)(arg0) + (0x88)))) * arg0->scale;
}

/* extern */

f32 func_80103F38(Actor *arg0, f32 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    s32 func_80103328();

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
    s32 func_80103328();
    func_80103328(arg0);
    return (f32) (u32) (u16) arg0->pad68 * arg0->scale;
}

/* extern */

s32 func_80104004(Actor *arg0, f32 *arg1, f32 *arg2) {
    void func_800B2198(void *, void *, void *);
    s32 func_800B2840(s32);
    s32 func_800D62E4(s32);
    void func_800EE84C(f32 *, s32 *);
    void func_800EF334(f32 *, f32);
    s32 func_801039E4(Unk80132ED0 *);
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

void func_801040A8(void **arg0) {
    s32 func_800AE080(s16);
    func_800AE080((*(s16 *)((s8 *)(*arg0) + (0x10))));
}
