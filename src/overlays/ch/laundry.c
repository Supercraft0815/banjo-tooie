#include "common.h"

OSThread *chlaundry_entrypoint_0(void)
{
    extern ActorData D_80800400_chlaundry[];

    return (OSThread *) D_80800400_chlaundry;
}

/* extern */

f32 func_8080000C_chlaundry(Actor *arg0) {
    s32 func_800A940C(s32);
    f32 func_800C5190(s32);
    void *func_80100094(Actor *, u32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800C5190(func_800A940C(*(u8 *) func_80100094(arg0, 0)));
    var_f2 = temp_f0;
    if (temp_f0 > 2.0f) {
        var_f2 = 2.0f;
    }
    return var_f2;
}

void func_80800058_chlaundry(Actor *arg0, f32 arg1) {
    s32 _glhittableDll_entrypoint_1(BtIntPtr arg0, BtIntPtr arg1);
    s32 func_800AF5A0(s16 *);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    u8 *func_800CD820(u8 *, f32 *, f32 *, f32);
    f32 func_800D8FF8(void);
    void *func_800EC3E8(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F13C4(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010AA78(s32 *);
    s32 func_8010B990(Actor *, s32);
    extern s32 D_80800488_chlaundry[];
    struct LaundryData {
        s8 unk0;
        s8 unk1;
        f32 unk4;
        f32 unk8;
        f32 unkC[3];
        f32 unk18;
    };
    struct LaundryProp {
        u8 pad[10];
        BT_BITFIELD_ORDER(u8 frame : 5, u8 flags : 3);
        BT_BITFIELD_ORDER(u8 flags : 3, u8 frame : 5);
    };
    struct LaundryMarker {
        u32 pad[8];
        s16 unk20;
    };
    f32 sp4C;
    u8 *collision;
    s32 hit;
    s32 flags;
    struct LaundryData *data;

    data = func_80100094(arg0, 0);
    if (data->unk4 < 2.5f) {
        func_800BABB8(func_800B5BE4(0x19), arg0->position, NULL, 1.0f, D_80800488_chlaundry);
    }
    sp4C = func_800D8FF8() * 24.0f + data->unk18;
    data->unk18 = func_800F13C4(sp4C, (f32)func_800AF5A0(func_800EC3E8((u8 *)arg0->unk0)));
    ((struct LaundryProp *)arg0->unk0->unk0)->frame = (s32)data->unk18;
    ((struct LaundryMarker *)arg0->unk0)->unk20 = 0;
    func_8010A590(arg0);
    collision = func_800CD820((u8 *)arg0->unk0, data->unkC, arg0->position, 40.0f);
    hit = (BtIntPtr)collision != 0;
    if (collision != NULL) {
        _glhittableDll_entrypoint_1(arg0->unk0, collision);
    }
    func_8010A570(arg0);
    func_800EE7F8(data->unkC, arg0->position);
    flags = func_8010B990(arg0, 0x100004);
    if (flags == 0x20) {
        func_8010AA78((s32 *)arg0->position);
    }
    if (hit || flags == 0x20 || func_8080000C_chlaundry(arg0) * 4.0f < data->unk4) {
        data->unk1 = 1;
    }
}

/* extern */

void func_80800218_chlaundry(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80800058_chlaundry(Actor *, f32);
    void func_808003A0_chlaundry(u8 *volatile);
    f32 sp24;
    f32 sp20;
    struct {
        u8 unk0;
        u8 unk1;
        f32 unk4;
    } *sp1C;

    sp1C = func_80100094(arg0, 0);
    sp24 = sp1C->unk4;
    sp20 = func_800D8FF8();
    func_80800058_chlaundry(arg0, sp20);
    sp1C->unk4 = sp24 + sp20;
    if (sp1C->unk1 != 0) {
        func_808003A0_chlaundry((u8 *)arg0);
        func_800FFAB0(arg0);
    }
}

s32 func_80800288_chlaundry(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
Actor *chlaundry_entrypoint_1(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE904(s32[3], f32[3]);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80108454(s32, s32 *, u32);
    extern s32 D_80800448_chlaundry[16];
    struct LaundryData {
        s8 unk0;
        s8 unk1;
        f32 unk4;
        f32 unk8;
        f32 unkC[3];
        f32 unk18;
    };
    struct LaundryActorData {
        f32 unk0[4];
        f32 unk10[3];
        f32 unk1C;
    };
    Actor *actor;
    f32 sp40[3];
    s32 sp34[3];
    struct LaundryData *sp30;

    func_800FAB50(arg0, arg1, sp40, 0x024200A1, 15.0f);
    func_800EE904(sp34, arg1);
    actor = func_80108454(0x162, sp34, 0);
    sp30 = func_80100094(actor, 0);
    func_800EE7F8(&sp30->unkC[0], &actor->position[0]);
    sp30->unk0 = arg3;
    sp30->unk1 = 0;
    sp30->unk4 = 0.0f;
    actor->scale = 0.5f;
    ((struct LaundryActorData *)&actor->actorData[0])->unk1C = -800.0f;
    sp30->unk8 = -22000.0f;
    func_800EE7F8(&((struct LaundryActorData *)&actor->actorData[0])->unk10[0], arg2);
    sp30->unk18 = 0.0f;
    func_800BABB8(func_800B5BE4(0x19), &actor->position[0], NULL, 1.0f, D_80800448_chlaundry);
    return actor;
}

void func_808003A0_chlaundry(u8 *volatile arg0) { s32 func_8010D930(s32, s32, f32 *, s32 *); extern s32 D_8080048C_chlaundry[9]; u8 *sp1C; sp1C = arg0 + 4; func_8010D930(0, -1, (f32 *)sp1C, D_8080048C_chlaundry); _fxsparkle_entrypoint_1((BtIntPtr)sp1C, 0xD); }
/* data_to_c.py: from asm/data/overlays/ch/laundry.data.s */
void func_80105834(Actor*);
void _subaddiedraw25d_entrypoint_2();
void func_80107C2C();
ActorData D_80800400_chlaundry [1] BT_DATA(4, overlays_ch_laundry, 0x0) = { { 628, 354, 2513, 1, 0, (void (*)(struct Actor *))func_80800218_chlaundry, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_subaddiedraw25d_entrypoint_2, 0, 1065353216, 0, 0, 0, 4, 0, 0, 28, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_80800288_chlaundry, 0 } };
s32 D_80800448_chlaundry[16] BT_DATA(4, overlays_ch_laundry, 0x48) = { 1903068, 2158792, -934281172, -1310690, -1310700, 3276820, 2228275, 4194636, 25165862, 0, -3276800, 50, 1376281, 1966123, 11731123, 0 };
s32 D_80800488_chlaundry [1] BT_DATA(4, overlays_ch_laundry, 0x88) = { 18481152 };
s32 D_8080048C_chlaundry[9] BT_DATA(4, overlays_ch_laundry, 0x8C) = { 1246239, 1456792, 852211, 18415617, 65541000, 0, 0, 0, 0 };
