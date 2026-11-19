#include "core2/1EDAEA0.h"


void* func_800DE448(f32*, f32*, f32, f32*, BtIntPtr);
void func_800DF47C(s32 (*arg0)(Actor*), Actor*);
f32* func_801018D8(Actor*);
f32* func_801027F4(Actor*);
s32 func_801015D0(Actor*);

OSThread *func_801015B0(void)
{
    extern u8 D_80135A90[];

    return (OSThread *) D_80135A90;
}

void func_801015BC(void) {
    extern s16 D_80135A94;
    D_80135A94 = 0;
}

void func_801015C8(void) {
}

s32 func_801015D0(Actor *arg0) {     union RenderActor { Actor actor; struct { u8 pad[0x70]; BT_BITFIELD_ORDER(u32 pad70_25:7, u32 pad70_0 : 21); BT_BITFIELD_ORDER(u32 bit24:1, u32 bit21 : 1); u32 pad70_22:2; BT_BITFIELD_ORDER(u32 bit21:1, u32 bit24 : 1); BT_BITFIELD_ORDER(u32 pad70_0:21, u32 pad70_25 : 7); u32 pad74; u16 pad78; BT_BITFIELD_ORDER(u16 mode:2, u16 pad7A : 14); BT_BITFIELD_ORDER(u16 pad7A:14, u16 mode : 2); } flags; }; BtIntPtr func_801039E4(BtIntPtr);     void func_80103D48(void **);     s32 func_80103D70(void **);     void *func_80104248(Actor *);     void *func_8008AEDC(void *);     BtIntPtr func_8008C27C(void *);     void func_8008B304(BtIntPtr);     BtIntPtr _suexpression_entrypoint_20();     void _suexpression_entrypoint_19(void *, Actor *);     void _suexpression_entrypoint_11(void *, Actor *);     u8 *func_800B27E0(u8 *);     s32 func_8010108C(Actor *, s32, BtIntPtr);     void func_8008C200(s16, BtIntPtr, BtIntPtr);     void *func_800AE080(s16);     void func_800ADD80(s16, u8 *);     void func_800DF410(s32);     void func_800DF41C(BtIntPtr);     void func_800DF72C(BtIntPtr);     void func_800DF738(BtIntPtr);     void func_800DF818(BtIntPtr);     void func_800DF830(s32);     BT_IDO_ONLY(void func_800DF7E8();) BT_NATIVE_ONLY(void func_800DF7E8(u8);)     void * _subaddieskeleton_entrypoint_4(void *arg0);     BtIntPtr func_80103CDC(u8 *, u8 *);     void func_80106A98(Actor *, BtIntPtr);     void func_80101934(Actor *);     s32 func_800D731C(s32);     s32 pad;     Unk80132ED0 *sp38;     BtIntPtr sp34;     BtIntPtr sp30;     void *sp2C;     u8 *sp28;     void *sp24;     s32 result;     s32 cache; s32 texture;      sp30 = func_801039E4((BtIntPtr)arg0->unk0);     func_80103D48((void **)arg0);     sp2C = func_80104248(arg0);     if (sp2C) {         if (!arg0->unk7C_12) {             func_8008B304((BtIntPtr)sp2C);         }         func_800DF41C(func_8008C27C(func_8008AEDC(sp2C)));     }     sp38 = arg0->unk0;     sp34 = _suexpression_entrypoint_20(arg0);     if (sp34) {         _suexpression_entrypoint_19((void *)sp34, arg0);     }     if (*(s16 *)&sp38->unk10) {         sp24 = func_80104248(arg0);         sp28 = func_800B27E0((u8 *)sp30);         func_8010108C(arg0, 0x9C, sp30);         if (sp24) {             if (sp28) {                 if (!arg0->unk7C_12) {                     func_8008C200(*(s16 *)&sp38->unk10, (BtIntPtr)sp28, (BtIntPtr)func_8008AEDC(sp24));                 }                 func_800DF72C((BtIntPtr)func_800AE080(*(s16 *)&sp38->unk10));             }         } else if (sp28) {             func_800ADD80(*(s16 *)&sp38->unk10, sp28);         }     }     if (sp34) {         _suexpression_entrypoint_11((void *)sp34, arg0);     }     func_800DF410(arg0->alpha);     func_800DF830(((union RenderActor *)arg0)->flags.mode);     func_800DF738(_subaddieskeleton_entrypoint_4(arg0));     if (((union RenderActor *)arg0)->flags.bit24 || ((union RenderActor *)arg0)->flags.bit21) {         func_800DF818(func_80103CDC((u8 *)arg0, (u8 *)sp30));     }     func_80106A98(arg0, sp30);     func_80101934(arg0);     cache = func_800D731C(arg0->unk0->unk14);     texture = cache & 0xFF; if (cache) {         func_800DF7E8(texture);     }     result = func_80103D70((void **)arg0);     arg0->unk7C_12 = 1;     return result; }

/* extern */

void func_801017D0(Actor *arg0) {
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    BtIntPtr func_801039E4(BtIntPtr);
    s32 sp18[2];
    BtIntPtr temp_v0;

    temp_v0 = func_801039E4((BtIntPtr)arg0->unk0);
    sp18[0] = temp_v0;
    func_8010108C(arg0, 0x1F, sp18[0]);
}

// the real actor_draw?
s32 func_80101808(Actor* arg0, void (*arg1)(Actor*)) {
    s32 pad[2];
    f32* sp2C;
    f32* sp28;

    func_800DF47C(arg1, arg0);
    sp28 = func_801027F4(arg0);
    sp2C = func_801018D8(arg0);
    BT_NATIVE_ONLY(return (s32)(BtIntPtr)) func_800DE448(arg0->position, sp28, arg0->scale, sp2C, func_8010347C(arg0->unk0));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80101870(Actor* arg0, void* arg1) {
    func_80101970(arg0);
    BT_NATIVE_ONLY(return) func_80101808(arg0, func_801015D0);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_801018A4(Actor *arg0, BtIntPtr arg1) {
    func_80101970(arg0);
    BT_NATIVE_ONLY(return) func_80101808(arg0, (s32 (*)(Actor *)) func_801017D0);
}

f32 *func_801018D8(Actor *arg0) {
    f32 *func_80101918(f32);
    f32 *var_v1;

    if ((*(u16 *)((s8 *)(arg0) + 0x94)) & 1) {
        var_v1 = func_80101918(arg0->scale);
    } else {
        var_v1 = NULL;
    }
    return var_v1;
}

f32 *func_80101918(f32 arg0) {
    extern f32 D_801243E0[];
    D_801243E0[1] = -4.0f / arg0;
    return D_801243E0;
}

void func_80101934(Actor *arg0) {
    union RenderActor {
        Actor actor;
        struct {
            u8 pad[0x74];
            BT_BITFIELD_ORDER(u32 unused : 28, u32 index : 4);
            BT_BITFIELD_ORDER(u32 index : 4, u32 unused : 28);
        } flags;
    };
    extern void (*D_801243E8[])(Actor *);

    if (((union RenderActor *)arg0)->flags.index != 0) {
        D_801243E8[((union RenderActor *)arg0)->flags.index](arg0);
    }
}

int func_80101970(Actor *arg0) {
    typedef struct {
        u8 pad0[0x70];
        BT_BITFIELD_ORDER(u32 pad70_21 : 11, u32 pad70_0 : 20);
        u32 flag70_20 : 1;
        BT_BITFIELD_ORDER(u32 pad70_0 : 20, u32 pad70_21 : 11);
        u8 pad74[0x20];
        BT_BITFIELD_ORDER(u32 pad94_31 : 1, u32 pad94_0 : 30);
        u32 flag94_30 : 1;
        BT_BITFIELD_ORDER(u32 pad94_0 : 30, u32 pad94_31 : 1);
    } ActorRenderFlags;
    typedef struct {
        u8 pad0[0x1A];
        u16 unk1A;
    } RenderSettings;
    s32 func_800D2F20(void);
    f32 func_800DF428(f32);
    void func_800DF440(s32);
    void func_800DF470(s32);
    s32 func_800EA068(s32);
    void *func_80100368(void *);

    f32 value;
    f32 fallback;

    func_800DF470(((ActorRenderFlags *)arg0)->flag70_20);
    value = (u32)((RenderSettings *)func_80100368(arg0))->unk1A;
    if (value != 0.0f) {
        func_800DF428(value);
    } else if (!(arg0->unk0->unk10 & 1)) {
        if (func_800EA068(0x200)) {
            fallback = 29999.0f;
        } else {
            fallback = func_800D2F20();
        }
        func_800DF428(fallback);
    }
    if (((ActorRenderFlags *)arg0)->flag94_30) {
        func_800DF440(0);
    } BT_NATIVE_ONLY(return 0;)
}

void func_80101A50(void *arg0) {
    f32 func_800DC0C0(void);
    void func_800DF744(s32, s32);

    struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 18, u32 pad7B : 9);
        BT_BITFIELD_ORDER(u32 blinkState : 2, u32 blinkFrame : 3);
        BT_BITFIELD_ORDER(u32 blinkFrame : 3, u32 blinkState : 2);
        BT_BITFIELD_ORDER(u32 pad7B : 9, u32 pad78 : 18);
        BT_BITFIELD_ORDER(u32 pad7C : 19, char : 0);
        BT_BITFIELD_ORDER(u32 disabled : 1, u32 pad7F : 12);
        BT_BITFIELD_ORDER(u32 pad7F : 12, u32 disabled : 1; u32 pad7C : 19);
    } *actor = arg0;

    if (!actor->disabled) {
        switch (actor->blinkState) {
            case 0:
                if (func_800DC0C0() < 0.03f) {
                    actor->blinkState = 1;
                }
                break;
            case 1:
                if (actor->blinkFrame == 3) {
                    actor->blinkState = 2;
                } else {
                    actor->blinkFrame++;
                }
                break;
            case 2:
                actor->blinkFrame--;
                if (actor->blinkFrame == 0) {
                    actor->blinkState = 0;
                }
                break;
        }
    }
    func_800DF744(1, actor->blinkFrame + 1);
    func_800DF744(2, actor->blinkFrame + 1);
}

/* extern */

void func_80101BA0(s32 arg0) {
    void func_800DF744(s32, s32);
    func_800DF744(1, 4);
    func_800DF744(2, 4);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80135A90 [ 4 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x70);
s16 D_80135A94 BT_DATA(4, bss_core2bss2_2_music_tail, 0x74);
#endif
