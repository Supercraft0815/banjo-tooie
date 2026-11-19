#include "common.h"

void func_800F5A2C(BtIntPtr, s32, f32 *);

void func_80800000_chwandglow(Actor *arg0, s32 arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF410(s32);
    void func_800DF830(s32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    u8 *func_801039E4(Unk80132ED0 *);
    f32 vectors[3][3];

    func_800F5A00(arg0->unk6C_0, vectors[2]);
    func_800F5A2C(arg0->unk6C_0, 6, vectors[0]);
    if (func_800EECE0(vectors[2], vectors[0]) == 0) {
        func_800EE7F8(arg0->position, vectors[0]);
    }
    func_800EFA4C(vectors[1], 0.0f, 0.0f, 0.0f);
    func_800DF410((s32)func_800F10B4(((f32 *)arg0->actorData)[5], 0.0f, 1.0f, 0.0f, 255.0f));
    func_800DF830(2);
    func_800DE448(arg0->position, vectors[1], arg0->scale, NULL, func_801039E4(arg0->unk0));
}    typedef struct { s32 unk0; u8 pad4[0x2C]; s32 (*unk30)(s32, s32, void *); u8 pad34[0x38]; s32 unk6C; } Objwandglow_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808000E8_chwandglow(void *arg0) {
    (((Objwandglow_arg0 *)arg0)->unk30)((((Objwandglow_arg0 *)arg0)->unk0), (((Objwandglow_arg0 *)arg0)->unk6C) & 0x1FF, arg0);
}

BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s32) func_8080011C_chwandglow(BtIntPtr arg0, s32 arg1) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp;
    struct StateBits {
        u8 pad[0x72];
        BT_BITFIELD_ORDER(u8 state : 6, u8 other : 2);
        BT_BITFIELD_ORDER(u8 other : 2, u8 state : 6);
    };

    switch (arg1) {
    case 2:
        *(f32 *)(arg0 + 0x28) = 0.4f;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    case 3:
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        *(f32 *)(arg0 + 0x38) = 1.0f;
        break;
    case 4:
        *(f32 *)(arg0 + 0x38) = 1.0f;
        temp = func_800F10B4(*(f32 *)(arg0 + 0x2C), 0.0f, 1.0f, 0.0f, 0.3f);
        *(f32 *)(arg0 + 0x28) = temp;
        if (temp == 0.0f) {
            *(f32 *)(arg0 + 0x28) += 0.01f;
        }
        break;
    case 5:
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    }
    ((struct StateBits *)arg0)->state = arg1; BT_NATIVE_ONLY(return 0;)
}

void func_80800218_chwandglow(BtIntPtr arg0) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800D9078(f32 *arg0);
    int func_800FFA88();
    struct StateBits {
        u8 pad[0x72];
        BT_BITFIELD_ORDER(u16 state : 6, u16 other : 10);
        BT_BITFIELD_ORDER(u16 other : 10, u16 state : 6);
    };

    switch (((struct StateBits *)arg0)->state) {
    case 2:
        *(f32 *)(arg0 + 0x2C) = func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 0.4f, 1, 0.0f);
        if (func_800D9078((f32 *)(arg0 + 0x28))) {
            func_8080011C_chwandglow(arg0, 3);
        }
        return;
    case 3:
        if (*(f32 *)(arg0 + 0x38) == 1.0f) {
            *(f32 *)(arg0 + 0x38) = 0.75f;
            return;
        } else {
            *(f32 *)(arg0 + 0x38) = 1.0f;
        }
        return;
    case 4:
        *(f32 *)(arg0 + 0x2C) = func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 0.3f, 0.0f, 1);
        if (func_800D9078((f32 *)(arg0 + 0x28))) {
            func_8080011C_chwandglow(arg0, 5);
        }
        break;
    case 5:
        func_800FFA88(*(s32 *)arg0);
        break;
    }
}

/* extern */

BtIntPtr chwandglow_entrypoint_0(s32 arg0, s32 arg1) {
    Actor *actor;
    f32 sp18[3];

    func_800F5A2C(arg0, 6, sp18);
    actor = func_80108474(0x164, sp18, 0);
    actor->unk6C_0 = arg0;
    actor->actorData[6] = arg1;
    func_8080011C_chwandglow((BtIntPtr) actor, 2);
    return (BtIntPtr)actor->unk0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) chwandglow_entrypoint_1(BT_NATIVE_ONLY(s32 bt_a0))
{
    BT_NATIVE_ONLY(return (s32)func_800FFA88(bt_a0);) BT_IDO_ONLY(func_800FFA88();)
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) chwandglow_entrypoint_2(BT_PARAM_OR_VOID(BT_NATIVE_ONLY(s32 bt_a0))) {
    s32 func_8080011C_chwandglow(BtIntPtr, s32);
    BtIntPtr func_80106790();
    BT_NATIVE_ONLY(return func_8080011C_chwandglow(func_80106790(bt_a0), 4);) BT_IDO_ONLY(func_8080011C_chwandglow(func_80106790(), 4);)
}

OSThread *chwandglow_entrypoint_3(void)
{
    extern ActorData D_80800410_chwandglow[];

    return (OSThread *) D_80800410_chwandglow;
}
/* data_to_c.py: from asm/data/overlays/ch/wandglow.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800410_chwandglow [1] BT_DATA(4, overlays_ch_wandglow, 0x0) = { { 630, 356, 1718, 1, 0, (void (*)(struct Actor *))func_80800218_chwandglow, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800000_chwandglow, 131072000, 0, 0, 0, 2, 4, (void (*)(struct Actor *))func_808000E8_chwandglow, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
