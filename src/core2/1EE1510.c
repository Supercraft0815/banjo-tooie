#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_actor.h"
#include "native_spline.h"
#include "native_spawn_queue.h"
#define HOST(native, original) (native)
#define AF(actor, field, original) (((Actor *)(actor))->field)
#define AW(actor, field, member, original) (((NativeActorBits32 *)&((Actor *)(actor))->field)->member)
#define AH(actor, member, original) (((NativeActorBits16 *)&((Actor *)(actor))->flags7A)->member)
#define MW(marker, field, member, original) (((NativeActorBits32 *)&((Unk80132ED0 *)(marker))->field)->member)
#else
#define HOST(native, original) (original)
#define AF(actor, field, original) (original)
#define AW(actor, field, member, original) (original)
#define AH(actor, member, original) (original)
#define MW(marker, field, member, original) (original)
#endif
#include "actor_hit_default.inc"
OSThread *func_80107C20(void)
{







    return (OSThread *)&D_80124580;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Actor *func_80107C2C(s32 *arg0, s32 arg1, ActorData *arg2, NativeActorFactory arg3, Prop *arg4)
#else
void *func_80107C2C(s32 *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4)
#endif
{
    struct Marker {
        u8 pad0[8];
        OSThread *(*callback)(void);
        u8 padC[0xC];
        BT_BITFIELD_ORDER(u32 pad18 : 15, u32 pad1A : 16);
        u32 flag19_0 : 1;
        BT_BITFIELD_ORDER(u32 pad1A : 16, u32 pad18 : 15);
        u8 pad1C[0xC];
        BT_BITFIELD_ORDER(u32 pad28 : 22, u32 pad2A : 9);
        u32 flag2A_1 : 1;
        BT_BITFIELD_ORDER(u32 pad2A : 9, u32 pad28 : 22);
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
        BT_BITFIELD_ORDER(u32 flag64_7 : 1, u32 pad66 : 16);
        BT_BITFIELD_ORDER(u32 flag64_6 : 1, u32 flag65_0 : 1);
        BT_BITFIELD_ORDER(u32 pad64 : 4, u32 pad65_1 : 1);
        BT_BITFIELD_ORDER(u32 flag64_1 : 1, u32 flag65_2 : 1);
        BT_BITFIELD_ORDER(u32 flag64_0 : 1, u32 pad65 : 5);
        BT_BITFIELD_ORDER(u32 pad65 : 5, u32 flag64_0 : 1);
        BT_BITFIELD_ORDER(u32 flag65_2 : 1, u32 flag64_1 : 1);
        BT_BITFIELD_ORDER(u32 pad65_1 : 1, u32 pad64 : 4);
        BT_BITFIELD_ORDER(u32 flag65_0 : 1, u32 flag64_6 : 1);
        BT_BITFIELD_ORDER(u32 pad66 : 16, u32 flag64_7 : 1);
        u32 pad68;
        BT_BITFIELD_ORDER(u32 field6C_21 : 11, u32 pad6C : 9);
        u32 field6C_9 : 12;
        BT_BITFIELD_ORDER(u32 pad6C : 9, u32 field6C_21 : 11);
        BT_BITFIELD_ORDER(u32 pad70 : 7, char : 0);
        BT_BITFIELD_ORDER(u32 flag70_0 : 1, u16 flag73_0 : 1);
        BT_BITFIELD_ORDER(u32 pad71 : 1, u16 pad73 : 1);
        BT_BITFIELD_ORDER(u32 flag71_6 : 1, u16 flag73_2 : 1);
        BT_BITFIELD_ORDER(u32 flag71_5 : 1, u16 pad72 : 7);
        BT_BITFIELD_ORDER(u32 flag71_4 : 1, u16 state : 6);
        BT_BITFIELD_ORDER(u32 flag71_3 : 1, u32 flag71_0 : 1);
        BT_BITFIELD_ORDER(u32 flag71_2 : 1, u32 flag71_1 : 1);
        BT_BITFIELD_ORDER(u32 flag71_1 : 1, u32 flag71_2 : 1);
        BT_BITFIELD_ORDER(u32 flag71_0 : 1, u32 flag71_3 : 1);
        BT_BITFIELD_ORDER(u16 state : 6, u32 flag71_4 : 1);
        BT_BITFIELD_ORDER(u16 pad72 : 7, u32 flag71_5 : 1);
        BT_BITFIELD_ORDER(u16 flag73_2 : 1, u32 flag71_6 : 1);
        BT_BITFIELD_ORDER(u16 pad73 : 1, u32 pad71 : 1);
        BT_BITFIELD_ORDER(u16 flag73_0 : 1, u32 flag70_0 : 1);
        BT_BITFIELD_ORDER(u32 pad74 : 3, u32 pad70 : 7);
        BT_BITFIELD_ORDER(u32 flag74_4 : 1, char : 0);
        BT_BITFIELD_ORDER(u32 flag74_3 : 1, u32 field77 : 4);
        BT_BITFIELD_ORDER(u32 flag74_2 : 1, u32 pad77 : 1);
        BT_BITFIELD_ORDER(u32 pad74_0 : 2, u32 flag77_5 : 1);
        BT_BITFIELD_ORDER(u32 flag75_7 : 1, u32 pad76 : 10);
        BT_BITFIELD_ORDER(u32 pad75 : 2, u16 flag75_0 : 1);
        BT_BITFIELD_ORDER(u32 flag75_4 : 1, u32 flag75_1 : 1);
        BT_BITFIELD_ORDER(u32 flag75_3 : 1, u32 pad75_2 : 1);
        BT_BITFIELD_ORDER(u32 pad75_2 : 1, u32 flag75_3 : 1);
        BT_BITFIELD_ORDER(u32 flag75_1 : 1, u32 flag75_4 : 1);
        BT_BITFIELD_ORDER(u16 flag75_0 : 1, u32 pad75 : 2);
        BT_BITFIELD_ORDER(u32 pad76 : 10, u32 flag75_7 : 1);
        BT_BITFIELD_ORDER(u32 flag77_5 : 1, u32 pad74_0 : 2);
        BT_BITFIELD_ORDER(u32 pad77 : 1, u32 flag74_2 : 1);
        BT_BITFIELD_ORDER(u32 field77 : 4, u32 flag74_3 : 1);
        BT_BITFIELD_ORDER(u32 pad78 : 12, u32 flag74_4 : 1);
        BT_BITFIELD_ORDER(u32 flag79_3 : 1, u32 pad74 : 3);
        BT_BITFIELD_ORDER(u32 pad79 : 3, char : 0);
        BT_BITFIELD_ORDER(u32 field7A : 2, u32 pad7B : 1);
        BT_BITFIELD_ORDER(u32 pad7A : 12, u32 flag7B_1 : 1);
        BT_BITFIELD_ORDER(u32 flag7B_1 : 1, u32 pad7A : 12);
        BT_BITFIELD_ORDER(u32 pad7B : 1, u32 field7A : 2; u32 pad79 : 3; u32 flag79_3 : 1; u32 pad78 : 12);
        u16 unk7C;
        BT_BITFIELD_ORDER(u16 pad7E : 1, u16 pad7F : 13);
        BT_BITFIELD_ORDER(u16 flag7E_6 : 1, u16 flag7E_5 : 1);
        BT_BITFIELD_ORDER(u16 flag7E_5 : 1, u16 flag7E_6 : 1);
        BT_BITFIELD_ORDER(u16 pad7F : 13, u16 pad7E : 1);
        u8 pad80[0x14];
        BT_BITFIELD_ORDER(u32 flag94_7 : 1, u32 pad97 : 14);
        BT_BITFIELD_ORDER(u32 flag94_6 : 1, u32 flag96_6 : 1);
        BT_BITFIELD_ORDER(u32 pad94 : 12, u32 pad96 : 1);
        BT_BITFIELD_ORDER(u32 flag95_1 : 1, u32 flag95_0 : 1);
        BT_BITFIELD_ORDER(u32 flag95_0 : 1, u32 flag95_1 : 1);
        BT_BITFIELD_ORDER(u32 pad96 : 1, u32 pad94 : 12);
        BT_BITFIELD_ORDER(u32 flag96_6 : 1, u32 flag94_6 : 1);
        BT_BITFIELD_ORDER(u32 pad97 : 14, u32 flag94_7 : 1);
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
        BT_BITFIELD_ORDER(u32 field10 : 11, u32 pad13 : 1);
        BT_BITFIELD_ORDER(u32 pad10 : 19, u32 flag10 : 1);
        BT_BITFIELD_ORDER(u32 flag10 : 1, u32 pad10 : 19);
        BT_BITFIELD_ORDER(u32 pad13 : 1, u32 field10 : 11);
    };
    void *func_80106668(s32 *);
    u32 *func_80100074(void *, u32, u32);
    s32 func_800D738C(BtIntPtr);
    void *func_800EBED4(s32 *, s32, s32, s32);
    void func_800EC340(void *, s32);
    void func_800EC360(void *, s32);
    void func_800EC368(void *, s32);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_80102FA0(void *, s32);
#endif
    void _subaddieDll_entrypoint_1(Actor *arg0);
    void func_8010A800(void *, s32);
    void func_8010A63C(void *);
    void func_80108658(void *, s32, s32, void *);
    void func_800F31FC(u8 *, s32, s32, s32, s32);
    void func_80102424(void *, s32);
    void func_80103930(void *);
    void func_8010A3E8(void *, f32);
    BtIntPtr func_80106E88(Actor *arg0);
    void func_80104F2C(void *, s32, s32);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    void *func_800BEC1C(void);
#else
    s32 func_800BEC1C(void);
#endif
    void _subaddiezone_entrypoint_0(void *);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    Actor *actor;
#else
    struct Fields *actor;
#endif
    s32 index;
    s32 i;

    actor = func_80106668(&index);
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!actor) return NULL;
#endif
    AF(actor, factory, actor->unk10) = arg3;
    AF(actor, unk70_10, actor->state) = HOST(arg2->unk6, ((struct Info *)arg2)->unk6);
    actor->position[0] = arg0[0];
    actor->position[1] = arg0[1];
    actor->position[2] = arg0[2];
    AF(actor, rotation[1], actor->unk48) = arg1;
    actor->unk54 = arg1;
    AW(actor, flags64, b16, actor->flag65_0) = 1;
    AF(actor, scale, actor->unk38) = 1.0f;
    AF(actor, unk6C_9, actor->field6C_9) = HOST(arg2->unk2, ((struct Info *)arg2)->unk2);
    AW(actor, flags74, low4, actor->field77) = 0;
    HOST(*(f32 *)&actor->actorData[7], actor->unk34) = 0.0f;
    AH(actor, high2, actor->field7A) = 1;
    AW(actor, flags64, b18, actor->flag65_2) = 1;
    AW(actor, flags7C, high16, actor->unk7C) = HOST((u32)arg2->unk18 >> 16, ((struct Info *)arg2)->unk18);
    if (HOST(arg2->shadow_scale, ((struct Info *)arg2)->unk1C)) {
        AW(actor, flags74, b20, actor->flag75_4) = 1;
    } else {
        AW(actor, flags74, b20, actor->flag75_4) = 0;
    }
    AW(actor, pad94, b16, actor->flag95_0) = AW(actor, flags74, b20, actor->flag75_4);
    func_80100074(actor, 0, HOST((u16)arg2->unk30, ((struct Info *)arg2)->unk30));
    func_80100074(actor, 1, HOST((u16)arg2->unk32, ((struct Info *)arg2)->unk32));
    if (HOST((u16)arg2->unk4, ((struct Info *)arg2)->unk4) == 0xFFFF) {
        AF(actor, unk0, actor->marker) = func_800EBED4(arg0, 1, HOST(arg2->unk0, ((struct Info *)arg2)->unk0), (HOST(((u32)(u16)arg2->unk24 << 16) | (u16)arg2->unk26, ((struct Info *)arg2)->flags) & 0x400) ? 1 : 0);
    } else {
        AF(actor, unk0, actor->marker) = func_800EBED4(arg0, (func_800D738C(HOST((u16)arg2->unk4, ((struct Info *)arg2)->unk4)) == 7) ? 0 : 1, HOST(arg2->unk0, ((struct Info *)arg2)->unk0), (HOST(((u32)(u16)arg2->unk24 << 16) | (u16)arg2->unk26, ((struct Info *)arg2)->flags) & 0x400) ? 1 : 0);
    }
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
    if (!AF(actor, unk0, actor->marker)) {
        func_80100074(actor, 0, 0);
        func_80100074(actor, 1, 0);
        func_801066C0(index);
        return NULL;
    }
#endif
    MW(actor->unk0, unk18, b16, actor->marker->flag19_0) = 1;
    if (HOST(arg2->marker_callback, ((struct Info *)arg2)->callback) != NULL) {
        AF(actor, unk0->callback, actor->marker->callback) = HOST(arg2->marker_callback, ((struct Info *)arg2)->callback);
    } else {
        AF(actor, unk0->callback, actor->marker->callback) = func_80107C20;
    }
    func_800EC340(AF(actor, unk0, actor->marker), index);
    func_800EC360(AF(actor, unk0, actor->marker), HOST((u16)arg2->unk4, ((struct Info *)arg2)->unk4));
    func_800EC368(AF(actor, unk0, actor->marker), HOST(arg2->unk22, ((struct Info *)arg2)->unk22));
    AW(actor, flags74, b16, actor->flag75_0) = 1;
    AW(actor, flags74, b19, actor->flag75_3) = AW(actor, flags74, b16, actor->flag75_0);
    if (func_80102FA0(arg2, 1)) _subaddieDll_entrypoint_1(actor);
    if (func_80102FA0(arg2, 0x800000)) AW(actor, flags70, b21, actor->flag71_5) = 1;
    if (func_80102FA0(arg2, 8)) AW(actor, flags70, b24, actor->flag70_0) = 1;
    if (func_80102FA0(arg2, 0x100)) AW(actor, flags74, low4, actor->field77) = 1;
    if (func_80102FA0(arg2, 0x200000)) AW(actor, flags64, b25, actor->flag64_1) = 1;
    if (func_80102FA0(arg2, 0x4000000)) AW(actor, flags70, b22, actor->flag71_6) = 1;
    if (!func_80102FA0(arg2, 4)) AW(actor, flags74, b17, actor->flag75_1) = 1;
    if (!func_80102FA0(arg2, 0x100000)) AW(actor, flags70, b20, actor->flag71_4) = 1;
    if (func_80102FA0(arg2, 0x8000000)) AW(actor, flags70, b18, actor->flag71_2) = 1;
    if (func_80102FA0(arg2, 0x80000002)) MW(actor->unk0, unk28, b9, actor->marker->flag2A_1) = 0;
    if (func_80102FA0(arg2, 0x80000004)) AW(actor, flags64, b31, actor->flag64_7) = 1;
    if (func_80102FA0(arg2, 0x80000008)) AW(actor, flags64, b30, actor->flag64_6) = 1;
    if (func_80102FA0(arg2, 0x80000400)) AW(actor, flags70, b17, actor->flag71_1) = 1;
    if (func_80102FA0(arg2, 0x80001000)) AW(actor, flags70, b16, actor->flag71_0) = 1;
    if (func_80102FA0(arg2, 0x80002000)) AW(actor, flags74, b5, actor->flag77_5) = 1;
    if (func_80102FA0(arg2, 0x80004000)) AW(actor, flags7C, b13, actor->flag7E_5) = 1;
    if (func_80102FA0(arg2, 0x80000100)) AW(actor, flags74, b26, actor->flag74_2) = 1;
    if (func_80102FA0(arg2, 0x80100000)) AW(actor, flags74, b23, actor->flag75_7) = 1;
    if (func_80102FA0(arg2, 0x80000001)) AW(actor, flags64, b24, actor->flag64_0) = 1;
    if (func_80102FA0(arg2, 0x80000010)) AH(actor, b1, actor->flag7B_1) = 1;
    if (func_80102FA0(arg2, 0x80400000)) AW(actor, pad94, b31, actor->flag94_7) = 1;
    if (func_80102FA0(arg2, 0x80800000)) AW(actor, pad94, b30, actor->flag94_6) = 1;
    if (func_80102FA0(arg2, 0x80000040)) AW(actor, flags70, b2, actor->flag73_2) = 1;
    if (func_80102FA0(arg2, 0x80040000)) AF(actor, unk79_3, actor->flag79_3) = 1;
    if (func_80102FA0(arg2, 0x80200000)) AW(actor, pad94, b17, actor->flag95_1) = 1;
    if (func_80102FA0(arg2, 0x84000000)) AW(actor, pad94, b14, actor->flag96_6) = 1;
    if (func_80102FA0(arg2, 0x80000080)) AW(actor, flags70, b19, actor->flag71_3) = 1;
    if (func_80102FA0(arg2, 0x82000000)) AW(actor, pad94, b16, actor->flag95_0) = 0;
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
        AW(actor, flags7C, b14, actor->flag7E_6) = 0;
    } else {
        AW(actor, flags7C, b14, actor->flag7E_6) = 1;
    }
    if (func_80102FA0(arg2, 0x80000200)) {
        AW(actor, flags64, b16, actor->flag65_0) = 0;
    } else {
        AW(actor, flags64, b16, actor->flag65_0) = 1;
    }
    if (arg4 != NULL) {
        AF(actor, pad6C_21, actor->field6C_21) = HOST(arg4->unk10 >> 5, ((struct PropFields *)arg4)->field10);
        AW(actor, flags70, b0, actor->flag73_0) = HOST((arg4->unk12 >> 1) & 1, ((struct PropFields *)arg4)->flag10);
    }
    func_80108658(actor, HOST(((u32)(u16)arg2->unk24 << 16) | (u16)arg2->unk26, ((struct Info *)arg2)->flags), HOST(((u32)(u16)arg2->unk3C << 16) | (u16)arg2->unk3E, ((struct Info *)arg2)->unk3C), arg4);
    actor->unk14 = 0x4A0021;
    i = 0;
    do {
        ++i;
        HOST(actor->health, actor->unk5C)[i - 1] = 99;
    } while (i != 3);
    func_800F31FC(HOST(actor->color, actor->color), 255, 255, 255, 255);
    if (HOST(arg2->unk40_func, ((struct Info *)arg2)->unk40) != 0) {
        AW(actor, flags74, b28, actor->flag74_4) = 1;
    } else {
        AW(actor, flags74, b28, actor->flag74_4) = 0;
    }
    AW(actor, flags74, b27, actor->flag74_3) = 1;
    func_80102424(actor, AF(actor, unk70_10, actor->state));
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

#ifdef BT_NATIVE /* IDO passes three consecutive stack words starting at a scalar. */
Actor *func_801084B0(BtIntPtr arg0, Actor **arg1) {
    void func_800EE904(s32 [3], f32 [3]);
    Actor *func_80108C90(s32, s32 *, u32, Prop *);
    s32 position[3];
    Unk80132ED0 *marker = (*arg1)->unk0;
    func_800EE904(position, (*arg1)->position);
    Actor *spawned = func_80108C90(arg0, position, (u32)(s32)(*arg1)->rotation[1], NULL);
    *arg1 = func_80106790(marker);
    return spawned;
}
#else
Actor *func_801084B0(s32 arg0, Actor **arg1) { void func_800EE904(s32 dst[3], f32 src[3]); Actor* func_80108C90(s32, s32*, u32, Prop*); Actor *sp2C; Unk80132ED0 *sp28; s32 pad[2]; s32 sp1C; sp28 = (*arg1)->unk0; func_800EE904(&sp1C, (*arg1)->position); sp2C = func_80108C90(arg0, &sp1C, (u32) (s32) (*arg1)->rotation[1], NULL); *arg1 = func_80106790(sp28); return sp2C; }
#endif

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

Actor *func_8010856C(s32 arg0, f32 *arg1, f32 *arg2) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    Actor *func_80108DC0(s32, s32 *, u32, s32, s32, Prop *);
    s32 sp20[3];
    Actor *actor;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
    func_800EE904(sp20, arg1);
    actor = func_80108DC0(arg0, sp20, (s32)arg2[1], 0, 0, 0);
    if (!actor) return NULL;
#else
    func_800EE904((s32 *)((u8 *)sp20 BT_IDO_ONLY(- 4)), arg1);
    actor = func_80108DC0(arg0, (s32 *)((u8 *)sp20 BT_IDO_ONLY(- 4)), (s32)arg2[1], 0, 0, 0);
#endif
    actor->rotation[0] = arg2[0];
    return actor;
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Obj1EE1510_func_801085CC_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

Actor *func_801085CC(s32 arg0, s16 *arg1, u32 arg2) {
    Actor* func_80108C90(s32, s32*, u32, Prop*);
    s32 sp24[3];
    s16 *var_v1;
    s32 *var_v0;
    s32 *end;
#ifdef BT_NATIVE // ILP32 too: the N64 loop ends at &arg0, the home slot IDO puts right after sp24
    for (s32 i = 0; i < 3; ++i) sp24[i] = arg1[i];
    return func_80108C90(arg0, sp24, arg2, NULL);
#else
    end = &arg0; var_v0 = sp24; var_v1 = arg1; for (;;) { *var_v0 = *var_v1; var_v0 = &((Obj1EE1510_func_801085CC_var_v0 *)var_v0)->unk4; var_v1++; if (var_v0 == end) break; } func_80108C90(arg0, sp24, arg2, NULL);
#endif
}

/* extern */

s32 func_80108618(Actor *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    if (func_800DA298(arg1) != 0) {
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

/* extern */

void func_80108658(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    void func_8010381C(Actor *);
    struct ActorFlags {
        u8 pad0[0x70];
        BT_BITFIELD_ORDER(u32 pad70_25 : 7, u32 pad70_0 : 3);
        BT_BITFIELD_ORDER(u32 flag70_24 : 1, u32 flag70_3 : 1);
        BT_BITFIELD_ORDER(u32 pad70_22 : 2, u32 pad70_4 : 17);
        u32 flag70_21 : 1;
        BT_BITFIELD_ORDER(u32 pad70_4 : 17, u32 pad70_22 : 2);
        BT_BITFIELD_ORDER(u32 flag70_3 : 1, u32 flag70_24 : 1);
        BT_BITFIELD_ORDER(u32 pad70_0 : 3, u32 pad70_25 : 7);
        union {
            struct {
                BT_BITFIELD_ORDER(u8 pad74_26 : 6, u8 pad74_24 : 1);
                u8 flag74_25 : 1;
                BT_BITFIELD_ORDER(u8 pad74_24 : 1, u8 pad74_26 : 6);
                u8 pad75[2];
                BT_BITFIELD_ORDER(u8 pad74_7 : 1, u8 pad74_0 : 6);
                u8 flag74_6 : 1;
                BT_BITFIELD_ORDER(u8 pad74_0 : 6, u8 pad74_7 : 1);
            } bytes;
            struct {
                BT_BITFIELD_ORDER(u32 pad74_7 : 25, u32 pad74_0 : 6);
                u32 flag74_6 : 1;
                BT_BITFIELD_ORDER(u32 pad74_0 : 6, u32 pad74_7 : 25);
            } word;
        } flags74;
        u16 pad78;
        BT_BITFIELD_ORDER(u16 pad7A_8 : 8, u16 pad7A_0 : 6);
        u16 flag7A_6 : 2;
        BT_BITFIELD_ORDER(u16 pad7A_0 : 6, u16 pad7A_8 : 8);
        u8 pad7C[0x18];
        BT_BITFIELD_ORDER(u32 pad94_16 : 16, u32 pad96_0 : 15);
        u32 flag96_15 : 1;
        BT_BITFIELD_ORDER(u32 pad96_0 : 15, u32 pad94_16 : 16);
    } *actor = arg0;
    struct PropFlags {
        u8 pad0[0x10];
        BT_BITFIELD_ORDER(u32 pad10_5 : 27, u32 pad10_0 : 2);
        BT_BITFIELD_ORDER(u32 flag10_4 : 1, u32 flag10_2 : 2);
        BT_BITFIELD_ORDER(u32 flag10_2 : 2, u32 flag10_4 : 1);
        BT_BITFIELD_ORDER(u32 pad10_0 : 2, u32 pad10_5 : 27);
    } *prop = arg3;

    AF(arg0, pad7A_7, actor->flag7A_6) = AW(arg0, flags74, b6, actor->flags74.bytes.flag74_6) = AW(arg0, flags74, b25, actor->flags74.bytes.flag74_25) = AW(arg0, pad94, b15, actor->flag96_15) = 0;
    if (arg1 & 0x10000000) {
        AF(arg0, pad7A_7, actor->flag7A_6) += 1;
        if (!AW(arg0, flags70, b21, actor->flag70_21) && !AW(arg0, flags70, b24, actor->flag70_24)) {
            AW(arg0, flags70, b21, actor->flag70_21) = 1;
        }
    }
    if (arg1 & 0x20000000) {
        AF(arg0, pad7A_7, actor->flag7A_6) += 2;
        if (!AW(arg0, flags70, b21, actor->flag70_21) && !AW(arg0, flags70, b24, actor->flag70_24)) {
            AW(arg0, flags70, b21, actor->flag70_21) = 1;
        }
    }
    if (arg1 & 0x2000) {
        if (!AF(arg0, pad7A_7, actor->flag7A_6)) {
            AF(arg0, pad7A_7, actor->flag7A_6) = 1;
        }
        AW(arg0, flags74, b6, actor->flags74.bytes.flag74_6) = 1;
    }
    if ((arg2 & 0x80010000) == 0x80010000) {
        AW(arg0, flags74, b25, actor->flags74.bytes.flag74_25) = 1;
    }
    if ((arg2 & 0x80080000) == 0x80080000) {
        AW(arg0, pad94, b15, actor->flag96_15) = 1;
    }
    if (prop != NULL) {
        if (arg1 & 0x30002000) {
            if (HOST((((Prop *)arg3)->unk12 >> 2) & 3, prop->flag10_2)) {
            }
        } else {
            AF(arg0, pad7A_7, actor->flag7A_6) = HOST((((Prop *)arg3)->unk12 >> 2) & 3, prop->flag10_2);
            AW(arg0, flags74, b6, actor->flags74.bytes.flag74_6) = HOST((((Prop *)arg3)->unk12 >> 4) & 1, prop->flag10_4);
            if ((AF(arg0, pad7A_7, actor->flag7A_6) || AW(arg0, flags74, b6, actor->flags74.word.flag74_6)) && !AW(arg0, flags70, b21, actor->flag70_21) && !AW(arg0, flags70, b24, actor->flag70_24)) {
                AW(arg0, flags70, b21, actor->flag70_21) = 1;
            }
        }
    }
    if (AF(arg0, pad7A_7, actor->flag7A_6) && AW(arg0, flags70, b3, actor->flag70_3)) {
        func_8010381C(arg0);
    }
}

void func_801088A8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s8 func_800BF8E4(void);
    void func_80108658(void *, s32, s32, void *);
    struct ActorFlags {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u8 pad74_26 : 6, u8 pad74_24 : 1);
        u8 flag74_25 : 1;
        BT_BITFIELD_ORDER(u8 pad74_24 : 1, u8 pad74_26 : 6);
        u8 pad75[2];
        BT_BITFIELD_ORDER(u8 pad74_7 : 1, u8 pad74_0 : 6);
        u8 flag74_6 : 1;
        BT_BITFIELD_ORDER(u8 pad74_0 : 6, u8 pad74_7 : 1);
        u16 pad78;
        BT_BITFIELD_ORDER(u16 pad7A_8 : 8, u16 pad7A_0 : 6);
        u16 flag7A_6 : 2;
        BT_BITFIELD_ORDER(u16 pad7A_0 : 6, u16 pad7A_8 : 8);
        u8 pad7C[0x18];
        union {
            u16 value : 16;
            struct {
                BT_BITFIELD_ORDER(u32 pad94_16 : 16, u32 pad96_0 : 15);
                u32 flag96_15 : 1;
                BT_BITFIELD_ORDER(u32 pad96_0 : 15, u32 pad94_16 : 16);
            } bits;
        } flags96;
    } *actor = arg0;

    AF(arg0, pad7A_7, actor->flag7A_6) = AW(arg0, flags74, b6, actor->flag74_6) = AW(arg0, flags74, b25, actor->flag74_25) = AW(arg0, pad94, b15, actor->flags96.bits.flag96_15) = 0;
    if (func_800BF8E4() != 0) {
        func_80108658(arg0, arg1, arg2, arg3);
    }
}

void func_80108944(Actor *arg0, Actor *arg1) {
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void func_80108658(void *, s32, s32, void *);
    struct Flags {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u32 pad74_7 : 25, u32 pad74_0 : 6);
        u32 flag74_6 : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 6, u32 pad74_7 : 25);
        union {
            struct {
                BT_BITFIELD_ORDER(u32 pad78_2 : 30, u32 pad78_0 : 1);
                u32 flag78_1 : 1;
                BT_BITFIELD_ORDER(u32 pad78_0 : 1, u32 pad78_2 : 30);
            } word;
            struct {
                u16 pad78;
                BT_BITFIELD_ORDER(u16 pad7A_8 : 8, u16 pad7A_0 : 1);
                BT_BITFIELD_ORDER(u16 flag7A_6 : 2, u16 flag7A_1 : 1);
                u16 pad7A_2 : 4;
                BT_BITFIELD_ORDER(u16 flag7A_1 : 1, u16 flag7A_6 : 2);
                BT_BITFIELD_ORDER(u16 pad7A_0 : 1, u16 pad7A_8 : 8);
            } half;
        } flags78;
        u8 pad7C[0x18];
        BT_BITFIELD_ORDER(u32 pad94_16 : 16, u32 pad96_0 : 15);
        u32 flag96_15 : 1;
        BT_BITFIELD_ORDER(u32 pad96_0 : 15, u32 pad94_16 : 16);
    };
    s32 flags;
    s32 sp30 = 0;
    s32 sp24[3];

    flags = 0;

    switch (AF(arg1, pad7A_7, ((struct Flags *)arg1)->flags78.half.flag7A_6)) {
        case 1: flags = 0x10000000; break;
        case 2: flags = 0x20000000; break;
        case 3: flags = 0x30000000; break;
    }
    if (AW(arg1, flags74, b6, ((struct Flags *)arg1)->flag74_6)) {
        flags |= 0x2000;
    }
    if (AH(arg1, b1, ((struct Flags *)arg1)->flags78.word.flag78_1)) {
        AH(arg0, b1, ((struct Flags *)arg0)->flags78.half.flag7A_1) = 1;
        _subaddiefade_entrypoint_9(arg1, sp24);
        _subaddiefade_entrypoint_11(arg0, sp24);
    }
    if (AW(arg1, pad94, b15, ((struct Flags *)arg1)->flag96_15)) {
        sp30 = 0x80080000;
    }
    func_80108658(arg0, flags, sp30, NULL);
}                 typedef struct { s32 unk0; s32 unk4; s32 unk8; } Obj1EE1510_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
static void native_actor_spawn_queued(uintptr_t id, uintptr_t x, uintptr_t y, uintptr_t z, uintptr_t yaw, uintptr_t flags) {
    func_80108A8C((u32)id, (s32)x, (s32)y, (s32)z, (s32)yaw, (s32)flags);
}
#endif

void func_80108A30(s32 arg0, void *arg1, f32 arg2, s32 arg3) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 _chbaddiesetup_entrypoint_6(void (*)(u32, s32, s32, s32, s32, s32), s32, s32, s32, s32, s32, s32);
#endif
    void func_80108A8C(u32, s32, s32, s32, s32, s32);
    _chbaddiesetup_entrypoint_6(HOST(native_actor_spawn_queued, &func_80108A8C), arg0, (((Obj1EE1510_arg1 *)arg1)->unk0), (((Obj1EE1510_arg1 *)arg1)->unk4), (((Obj1EE1510_arg1 *)arg1)->unk8), *(s32 *)&arg2, arg3);
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
}    typedef struct { u8 pad0[0x12]; u16 unk12; } Obj1EE1510_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_80108B04(Actor *arg0, u32 arg1) {
    Unk80132ED0 *marker = arg0->unk0;
    if (marker) _chbaddiesetup_entrypoint_3(func_80108B44, (uintptr_t)marker, arg1, (marker->unk10 >> 1) & 0x7FFF);
}
#else
void func_80108B04(s32 *arg0, s32 arg1) {
    void _chbaddiesetup_entrypoint_3(void *, s32, s32, s32);
    void func_80108B44(u8 *, s32, s32);
    struct Marker { u8 pad0[0x12]; BT_BITFIELD_ORDER(u16 unk12 : 15, u16 : 1; u16 unk12 : 15); };

    _chbaddiesetup_entrypoint_3(func_80108B44, arg0[0], arg1, (*(struct Marker **) arg0)->unk12);
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_80108B44(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2) {
    intptr_t func_8010114C(Unk80132ED0 *, s32, uintptr_t);
    Unk80132ED0 *marker = (Unk80132ED0 *)arg0;
    if (func_801069A4(marker) && arg2 == ((marker->unk10 >> 1) & 0x7FFF)) {
        func_8010114C(marker, 0x3D, arg1);
    }
}
#else
void func_80108B44(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(s32, s32, s32);
    s32 func_801069A4();
    if ((arg2 == ((u32) (((Obj1EE1510_arg0 *)arg0)->unk12) >> 1)) && (func_801069A4() != 0)) {
        func_8010114C((s32) arg0, 0x3D, arg1);
    }
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_80108B8C(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2) {
    intptr_t func_8010114C(Unk80132ED0 *, s32, uintptr_t);
    Unk80132ED0 *marker = (Unk80132ED0 *)arg0;
    if (func_801069A4(marker) && arg2 == ((marker->unk10 >> 1) & 0x7FFF)) {
        func_8010114C(marker, 0x59, arg1);
    }
}
#else
void func_80108B8C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(s32, s32, s32);
    s32 func_801069A4();
    if ((arg2 == ((u32) (((Obj1EE1510_arg0 *)arg0)->unk12) >> 1)) && (func_801069A4() != 0)) {
        func_8010114C((s32) arg0, 0x59, arg1);
    }
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_80108BD4(Actor *arg0, u32 arg1) {
    Unk80132ED0 *marker = arg0->unk0;
    if (marker) _chbaddiesetup_entrypoint_3(func_80108B8C, (uintptr_t)marker, arg1, (marker->unk10 >> 1) & 0x7FFF);
}
#else
void func_80108BD4(s32 *arg0, s32 arg1) {
    void _chbaddiesetup_entrypoint_3(void *, s32, s32, s32);
    struct Marker { u8 pad0[0x12]; BT_BITFIELD_ORDER(u16 unk12 : 15, u16 : 1; u16 unk12 : 15); };

    _chbaddiesetup_entrypoint_3(func_80108B8C, arg0[0], arg1, (*(struct Marker **) arg0)->unk12);
}
#endif

void func_80108C14(void) {
    void func_800819B4(void *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void *func_80100368(void *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
#endif
    struct ActorSettings {
        u8 pad[0x20];
        BT_BITFIELD_ORDER(u32 flag : 16, u32 : 16; u32 flag : 16);
    };
    s32 index;
    Actor *actor;
    struct ActorSettings *settings;

    actor = (Actor *)func_801067C4(&index);
    if (actor != NULL) {
        do {
            settings = func_80100368(actor);
            if (HOST((u16)((ActorData *)settings)->unk20, settings->flag) != 0 && func_800DA298(HOST((u16)((ActorData *)settings)->unk20, settings->flag)) != 0) {
                func_800FFAB0(actor);
                func_800819B4(actor->pointerToSyscallEntry);
            }
            actor = (Actor *)func_8010682C(&index);
        } while (actor != NULL);
    }
}

Actor *func_80108C90(s32 arg0, s32 *arg1, u32 arg2, Prop *arg3) {
    typedef ActorData *(*ActorFactory)(void);
    typedef Actor *(*ActorSpawn)(s32 *, u32, ActorData *, ActorFactory, Prop *);
    BtIntPtr _gemarkersDll_entrypoint_0(s32 arg0);
    ActorFactory factory;
    ActorData *data;

    factory = (ActorFactory)_gemarkersDll_entrypoint_0(arg0);
    if (factory == NULL) {
        return NULL;
    }
    data = factory();
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (!data || !data->unk38_func) return NULL;
    return data->unk38_func(arg1, (s32)arg2, data, factory, arg3);
#else
    return ((ActorSpawn)data->unk38_func)(arg1, arg2, data, factory, arg3);
#endif
}

void *func_80108CF4(s32 arg0)
{
#if defined(BT_NATIVE) && !defined(BT_ILP32)
  void *_gccubesearch_entrypoint_17(s32, void *);
#else
  s32 _gccubesearch_entrypoint_17(s32, s32);
#endif
  struct CubeSearchNode
  {
    u32 unk0;
    u32 flags;
    u32 unk8;
    u32 unkC;
#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 unk10low : 10;
    u32 next : 11;
    u32 unk10 : 11;
#else
    u32 unk10 : 11;
    u32 next : 11;
    u32 unk10low : 10;
#endif
  };
  s32 pad;
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
  u32 remaining = 2048;
#endif
  u32 sp20;
  struct CubeSearchNode *node;
  struct CubeSearchNode *result;
  node = (struct CubeSearchNode *) _gccubesearch_entrypoint_17(arg0, 0);
  sp20 = 1;
  if ((node != NULL) && (node->next != (((node->flags & 1) == 1) * 0)))
  {
    do
    {
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
      if (!remaining--) return NULL;
#endif
      sp20 = 0;
      node = (struct CubeSearchNode *) _gccubesearch_entrypoint_17(node->next, 0);
    }
    while (((node != NULL) && ((node->flags & 1) == 1)) && (node->next != 0));
  }
  if (((sp20 == 1) || (node == NULL)) || ((node->flags & 1) == 1))
  {
    result = NULL;
  }
  else
  {
    result = node;
  }
  return result;
}

Actor *func_80108DC0(s32 arg0, s32 *arg1, u32 arg2, s32 arg3, s32 arg4, Prop *arg5) {
    typedef struct {
        s16 unk0;
        BT_BITFIELD_ORDER(s16 pad2_11 : 5, s16 pad2_0 : 1);
        s16 unk2_1 : 10;
        BT_BITFIELD_ORDER(s16 pad2_0 : 1, s16 pad2_11 : 5);
        u8 pad4[8];
        f32 unkC;
    } Entry;
    typedef struct {
        u8 pad0[0x77];
        BT_BITFIELD_ORDER(u8 pad77_5 : 3, u8 pad77_0 : 4);
        u8 hasSpline : 1;
        BT_BITFIELD_ORDER(u8 pad77_0 : 4, u8 pad77_5 : 3);
    } ActorSplineFlags;
    Actor *func_80108C90(s32, s32 *, u32, Prop *);
    void *func_8010556C(Actor *);
    void *func_800D7520(s32);
    f32 func_800C82CC(void *, f32 *);
    void _gspropctrl_entrypoint_9(void *, s32 *);
    s32 _glsplinefind_entrypoint_4(s32 *, s32 *);
    s32 _glsplinefind_entrypoint_2(s32 *);
    Actor *actor;
    s32 found;
    void *node;
    s32 position[3];
    f32 point[3];
    Entry *entry;

    actor = func_80108C90(arg0, arg1, arg2, arg5);
    if (actor != NULL) {
        node = func_80108CF4(arg3);
        if (node != NULL) {
            _gspropctrl_entrypoint_9(node, position);
            found = _glsplinefind_entrypoint_4(arg1, position);
        } else {
            found = _glsplinefind_entrypoint_2(arg1);
        }
        if (found >= 0) {
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
            if (found >= 0x200) return actor;
#endif
            entry = func_8010556C(actor);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
            if (!entry) return actor;
            ((NativeActorPathState *)entry)->first = (((NativeActorPathState *)entry)->first & ~0x7FEu) | ((u32)found << 1);
#else
            entry->unk2_1 = found;
#endif
            point[0] = arg1[0];
            point[1] = arg1[1];
            point[2] = arg1[2];
            HOST(((NativeActorPathState *)entry)->time, entry->unkC) = func_800C82CC(func_800D7520(found), point);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
            actor->pad74_0 |= 16;
#else
            ((ActorSplineFlags *)actor)->hasSpline = 1;
#endif
        }
    }
    return actor;
}
