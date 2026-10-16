#include "common.h"

OSThread *func_80107C20(void)
{
    extern u8 D_80124580[];

    return (OSThread *) D_80124580;
}

void *func_80107C2C(s32 *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4) {
    struct Marker {
        u8 pad0[8];
        OSThread *(*callback)(void);
        u8 padC[0xC];
        u32 pad18 : 15;
        u32 flag19_0 : 1;
        u32 pad1A : 16;
        u8 pad1C[0xC];
        u32 pad28 : 22;
        u32 flag2A_1 : 1;
        u32 pad2A : 9;
    };
    struct Fields {
        struct Marker *marker;
        f32 position[3];
        s32 unk10;
        s32 unk14;
        u8 pad18[0x1C];
        f32 unk34;
        f32 unk38;
        u8 pad3C[0xC];
        f32 unk48;
        u8 pad4C[8];
        f32 unk54;
        u8 pad58[4];
        u8 unk5C[3];
        u8 pad5F[5];
        u32 flag64_7 : 1;
        u32 flag64_6 : 1;
        u32 pad64 : 4;
        u32 flag64_1 : 1;
        u32 flag64_0 : 1;
        u32 pad65 : 5;
        u32 flag65_2 : 1;
        u32 pad65_1 : 1;
        u32 flag65_0 : 1;
        u32 pad66 : 16;
        u32 pad68;
        u32 field6C_21 : 11;
        u32 field6C_9 : 12;
        u32 pad6C : 9;
        u32 pad70 : 7;
        u32 flag70_0 : 1;
        u32 pad71 : 1;
        u32 flag71_6 : 1;
        u32 flag71_5 : 1;
        u32 flag71_4 : 1;
        u32 flag71_3 : 1;
        u32 flag71_2 : 1;
        u32 flag71_1 : 1;
        u32 flag71_0 : 1;
        u16 state : 6;
        u16 pad72 : 7;
        u16 flag73_2 : 1;
        u16 pad73 : 1;
        u16 flag73_0 : 1;
        u32 pad74 : 3;
        u32 flag74_4 : 1;
        u32 flag74_3 : 1;
        u32 flag74_2 : 1;
        u32 pad74_0 : 2;
        u32 flag75_7 : 1;
        u32 pad75 : 2;
        u32 flag75_4 : 1;
        u32 flag75_3 : 1;
        u32 pad75_2 : 1;
        u32 flag75_1 : 1;
        u16 flag75_0 : 1;
        u32 pad76 : 10;
        u32 flag77_5 : 1;
        u32 pad77 : 1;
        u32 field77 : 4;
        u32 pad78 : 12;
        u32 flag79_3 : 1;
        u32 pad79 : 3;
        u32 field7A : 2;
        u32 pad7A : 12;
        u32 flag7B_1 : 1;
        u32 pad7B : 1;
        u16 unk7C;
        u16 pad7E : 1;
        u16 flag7E_6 : 1;
        u16 flag7E_5 : 1;
        u16 pad7F : 13;
        u8 pad80[0x14];
        u32 flag94_7 : 1;
        u32 flag94_6 : 1;
        u32 pad94 : 12;
        u32 flag95_1 : 1;
        u32 flag95_0 : 1;
        u32 pad96 : 1;
        u32 flag96_6 : 1;
        u32 pad97 : 14;
        u8 color[4];
    };
    struct Info {
        s16 unk0;
        s16 unk2;
        u16 unk4;
        s16 unk6;
        u8 pad8[0x10];
        u16 unk18;
        u16 pad1A;
        f32 unk1C;
        u16 pad20;
        u16 unk22;
        s32 flags;
        u32 pad28;
        OSThread *(*callback)(void);
        u16 unk30;
        u16 unk32;
        u8 pad34[8];
        s32 unk3C;
        s32 unk40;
    };
    struct PropFields {
        u8 pad0[0x10];
        u32 field10 : 11;
        u32 pad10 : 19;
        u32 flag10 : 1;
        u32 pad13 : 1;
    };
    void *func_80106668(s32 *);
    u32 *func_80100074(void *, u32, u32);
    s8 func_800D738C(s32);
    void *func_800EBED4(s32 *, s32, s32, s32);
    void func_800EC340(void *, s32);
    void func_800EC360(void *, s32);
    void func_800EC368(void *, s32);
    s32 func_80102FA0(void *, s32);
    s32 _subaddieDll_entrypoint_1();
    void func_8010A800(void *, s32);
    void func_8010A63C(void *);
    void func_80108658(void *, s32, s32, void *);
    void func_800F31FC(u8 *, s32, s32, s32, s32);
    void func_80102424(void *, s32);
    void func_80103930(void *);
    void func_8010A3E8(void *, f32);
    void func_80106E88(void *);
    void func_80104F2C(void *, s32, s32);
    s32 func_800BEC1C(void);
    void _subaddiezone_entrypoint_0(void *);
    struct Fields *actor;
    s32 index;
    s32 i;

    actor = func_80106668(&index);
    actor->unk10 = arg3;
    actor->state = ((struct Info *)arg2)->unk6;
    actor->position[0] = arg0[0];
    actor->position[1] = arg0[1];
    actor->position[2] = arg0[2];
    actor->unk48 = arg1;
    actor->unk54 = arg1;
    actor->flag65_0 = 1;
    actor->unk38 = 1.0f;
    actor->field6C_9 = ((struct Info *)arg2)->unk2;
    actor->field77 = 0;
    actor->unk34 = 0.0f;
    actor->field7A = 1;
    actor->flag65_2 = 1;
    actor->unk7C = ((struct Info *)arg2)->unk18;
    if (((struct Info *)arg2)->unk1C) {
        actor->flag75_4 = 1;
    } else {
        actor->flag75_4 = 0;
    }
    actor->flag95_0 = actor->flag75_4;
    func_80100074(actor, 0, ((struct Info *)arg2)->unk30);
    func_80100074(actor, 1, ((struct Info *)arg2)->unk32);
    if (((struct Info *)arg2)->unk4 == 0xFFFF) {
        actor->marker = func_800EBED4(arg0, 1, ((struct Info *)arg2)->unk0, (((struct Info *)arg2)->flags & 0x400) ? 1 : 0);
    } else {
        actor->marker = func_800EBED4(arg0, (func_800D738C(((struct Info *)arg2)->unk4) == 7) ? 0 : 1, ((struct Info *)arg2)->unk0, (((struct Info *)arg2)->flags & 0x400) ? 1 : 0);
    }
    actor->marker->flag19_0 = 1;
    if (((struct Info *)arg2)->callback != NULL) {
        actor->marker->callback = ((struct Info *)arg2)->callback;
    } else {
        actor->marker->callback = func_80107C20;
    }
    func_800EC340(actor->marker, index);
    func_800EC360(actor->marker, ((struct Info *)arg2)->unk4);
    func_800EC368(actor->marker, ((struct Info *)arg2)->unk22);
    actor->flag75_0 = 1;
    actor->flag75_3 = actor->flag75_0;
    if (func_80102FA0(arg2, 1)) _subaddieDll_entrypoint_1(actor);
    if (func_80102FA0(arg2, 0x800000)) actor->flag71_5 = 1;
    if (func_80102FA0(arg2, 8)) actor->flag70_0 = 1;
    if (func_80102FA0(arg2, 0x100)) actor->field77 = 1;
    if (func_80102FA0(arg2, 0x200000)) actor->flag64_1 = 1;
    if (func_80102FA0(arg2, 0x4000000)) actor->flag71_6 = 1;
    if (!func_80102FA0(arg2, 4)) actor->flag75_1 = 1;
    if (!func_80102FA0(arg2, 0x100000)) actor->flag71_4 = 1;
    if (func_80102FA0(arg2, 0x8000000)) actor->flag71_2 = 1;
    if (func_80102FA0(arg2, 0x80000002)) actor->marker->flag2A_1 = 0;
    if (func_80102FA0(arg2, 0x80000004)) actor->flag64_7 = 1;
    if (func_80102FA0(arg2, 0x80000008)) actor->flag64_6 = 1;
    if (func_80102FA0(arg2, 0x80000400)) actor->flag71_1 = 1;
    if (func_80102FA0(arg2, 0x80001000)) actor->flag71_0 = 1;
    if (func_80102FA0(arg2, 0x80002000)) actor->flag77_5 = 1;
    if (func_80102FA0(arg2, 0x80004000)) actor->flag7E_5 = 1;
    if (func_80102FA0(arg2, 0x80000100)) actor->flag74_2 = 1;
    if (func_80102FA0(arg2, 0x80100000)) actor->flag75_7 = 1;
    if (func_80102FA0(arg2, 0x80000001)) actor->flag64_0 = 1;
    if (func_80102FA0(arg2, 0x80000010)) actor->flag7B_1 = 1;
    if (func_80102FA0(arg2, 0x80400000)) actor->flag94_7 = 1;
    if (func_80102FA0(arg2, 0x80800000)) actor->flag94_6 = 1;
    if (func_80102FA0(arg2, 0x80000040)) actor->flag73_2 = 1;
    if (func_80102FA0(arg2, 0x80040000)) actor->flag79_3 = 1;
    if (func_80102FA0(arg2, 0x80200000)) actor->flag95_1 = 1;
    if (func_80102FA0(arg2, 0x84000000)) actor->flag96_6 = 1;
    if (func_80102FA0(arg2, 0x80000080)) actor->flag71_3 = 1;
    if (func_80102FA0(arg2, 0x82000000)) actor->flag95_0 = 0;
    func_8010A800(actor, 0);
    if (func_80102FA0(arg2, 0x800)) {
        func_8010A800(actor, 1);
        func_8010A63C(actor);
    }
    if (func_80102FA0(arg2, 0x20000)) {
        func_8010A800(actor, 2);
    } else if (func_80102FA0(arg2, 0x400000)) {
        func_8010A800(actor, 3);
    } else if (func_80102FA0(arg2, 0x80008000)) {
        func_8010A800(actor, 4);
    }
    if (func_80102FA0(arg2, 0x80000800)) {
        actor->flag7E_6 = 0;
    } else {
        actor->flag7E_6 = 1;
    }
    if (func_80102FA0(arg2, 0x80000200)) {
        actor->flag65_0 = 0;
    } else {
        actor->flag65_0 = 1;
    }
    if (arg4 != NULL) {
        actor->field6C_21 = ((struct PropFields *)arg4)->field10;
        actor->flag73_0 = ((struct PropFields *)arg4)->flag10;
    }
    func_80108658(actor, ((struct Info *)arg2)->flags, ((struct Info *)arg2)->unk3C, arg4);
    actor->unk14 = 0x4A0021;
    i = 0;
    do {
        ++i;
        actor->unk5C[i - 1] = 99;
    } while (i != 3);
    func_800F31FC(actor->color, 255, 255, 255, 255);
    if (((struct Info *)arg2)->unk40 != 0) {
        actor->flag74_4 = 1;
    } else {
        actor->flag74_4 = 0;
    }
    actor->flag74_3 = 1;
    func_80102424(actor, actor->state);
    func_80103930(actor);
    func_8010A3E8(actor, 1.0f);
    func_80106E88(actor);
    func_80104F2C(actor, func_80102FA0(arg2, 0x40000000), func_80102FA0(arg2, 0x10));
    if (func_800BEC1C()) _subaddiezone_entrypoint_0(actor);
    return actor;
}

Actor *func_80108454(s32 arg0, s32 *arg1, u32 arg2) {
    Actor*  func_80108C90(s32, s32*, u32, Prop*);
    return func_80108C90(arg0, arg1, arg2, NULL);
}

Actor *func_80108474(u32 arg0, f32 *arg1, s32 arg2) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    Actor*  func_80108C90(s32, s32*, u32, Prop*);
    s32 sp1C[3];

    func_800EE904(sp1C, arg1);
    return func_80108C90((s32) arg0, sp1C, (u32) arg2, NULL);
}

Actor *func_801084B0(s32 arg0, Actor **arg1) { void func_800EE904(s32 dst[3], f32 src[3]); Actor* func_80108C90(s32, s32*, u32, Prop*); Actor *sp2C; Unk80132ED0 *sp28; s32 pad[2]; s32 sp1C; sp28 = (*arg1)->unk0; func_800EE904(&sp1C, (*arg1)->position); sp2C = func_80108C90(arg0, &sp1C, (u32) (s32) (*arg1)->rotation[1], NULL); *arg1 = func_80106790(sp28); return sp2C; }

Actor* func_80108528(s32 arg0, f32 arg1[3], s32 arg2, Actor **arg3) {
    Unk80132ED0 *sp1C;
    Actor *sp18;
    Actor **sp2C;

    sp2C = arg3;
    sp1C = (*arg3)->unk0;
    sp18 = func_80108474(arg0, arg1, arg2);
    *sp2C = func_80106790(sp1C);
    return sp18;
}

/* extern */

void func_8010856C(s32 arg0, f32 *arg1, u8 *arg2) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    u8 *func_80108DC0(s32, s32 *, s32, s32, s32, s32);
    s32 sp20[3];

    func_800EE904((s32 *)((u8 *)sp20 - 4), arg1);
    (*(f32 *)((s8 *)(func_80108DC0(arg0, (s32 *)((u8 *)sp20 - 4), (s32) (*(f32 *)((s8 *)(arg2) + (4))), 0, 0, 0)) + (0x44))) = (f32) (*(f32 *)((s8 *)(arg2) + (0)));
}

void func_801085CC(s32 arg0, s16 *arg1, u32 arg2) {
    Actor* func_80108C90(s32, s32*, u32, Prop*);
    s32 sp24[3];
    s16 *var_v1;
    s32 *var_v0;
    s32 *end;
    end = &arg0; var_v0 = sp24; var_v1 = arg1; for (;;) { *var_v0 = *var_v1; var_v0 = (s32 *)((u8 *)var_v0 + 4); var_v1++; if (var_v0 == end) break; } func_80108C90(arg0, sp24, arg2, NULL);
}

/* extern */

s32 func_80108618(s32 arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if (func_800DA298(arg1) != 0) {
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108658.s")

/* extern */

void func_801088A8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s8 func_800BF8E4(void);
    void func_80108658(void *, s32, s32, void *);
    struct ActorFlags {
        u8 pad0[0x74];
        u8 pad74_26 : 6;
        u8 flag74_25 : 1;
        u8 pad74_24 : 1;
        u8 pad75[2];
        u8 pad74_7 : 1;
        u8 flag74_6 : 1;
        u8 pad74_0 : 6;
        u16 pad78;
        u16 pad7A_8 : 8;
        u16 flag7A_6 : 2;
        u16 pad7A_0 : 6;
        u8 pad7C[0x18];
        union {
            u16 value : 16;
            struct {
                u32 pad94_16 : 16;
                u32 flag96_15 : 1;
                u32 pad96_0 : 15;
            } bits;
        } flags96;
    } *actor = arg0;

    actor->flag7A_6 = actor->flag74_6 = actor->flag74_25 = actor->flags96.bits.flag96_15 = 0;
    if (func_800BF8E4() != 0) {
        func_80108658(arg0, arg1, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108944.s")

void func_80108A30(s32 arg0, void *arg1, f32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(void (*)(u32, s32, s32, s32, s32, s32), s32, s32, s32, s32, s32, s32);
    void func_80108A8C(u32, s32, s32, s32, s32, s32);
    _chbaddiesetup_entrypoint_6(&func_80108A8C, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), *(s32 *)&arg2, arg3);
}

void func_80108A8C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    f32 position[3];
    f32 yaw;
    Actor *actor;
    yaw = *(f32 *)&arg4;
    position[0] = *(f32 *)&arg1;
    position[1] = *(f32 *)&arg2;
    position[2] = *(f32 *)&arg3;
    actor = func_80108474(arg0, position, (s32)yaw);
    if (actor != NULL) {
        actor->rotation[1] = yaw;
        actor->unk74_7 = arg5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B04.s")

/* extern */

void func_80108B44(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(s32, s32, s32);
    s32 func_801069A4();
    if ((arg2 == ((u32) (*(u16 *)((s8 *)(arg0) + (0x12))) >> 1)) && (func_801069A4() != 0)) {
        func_8010114C((s32) arg0, 0x3D, arg1);
    }
}

/* extern */

void func_80108B8C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(s32, s32, s32);
    s32 func_801069A4();
    if ((arg2 == ((u32) (*(u16 *)((s8 *)(arg0) + (0x12))) >> 1)) && (func_801069A4() != 0)) {
        func_8010114C((s32) arg0, 0x59, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108DC0.s")
