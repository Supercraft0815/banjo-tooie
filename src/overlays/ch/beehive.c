#include "common.h"

void func_80800000_chbeehive(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(Actor *arg0, s32 arg1, s32 arg2);
    void func_800EE7F8(f32 *, f32 *);
    s32 sector;

    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    arg0->unk50 = arg0->rotation[1];
    sector = _subaddiesect_entrypoint_1(arg0);
    arg0->actorData[0] = sector;
    arg0->unk74_7 = arg0->unk74_7 - 50;
    if (sector != -1) {
        _subaddiesect_entrypoint_2(arg0, sector, 0);
    }
}

/* extern */
void func_80800078_chbeehive(Actor *arg0) {
    s32 _subaddiesect_entrypoint_0(Actor*, s32, s32);
    s32 func_80800180_chbeehive(Actor *);
    u32 temp_a1;
    struct {
        BT_BITFIELD_ORDER(u32 upper : 29, u32 lower : 2);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 lower : 2, u32 upper : 29);
    } *flags = (void *)&arg0->unk78;
    if (!flags->active && ((temp_a1 = arg0->actorData[0], (temp_a1 == -1U)) || (_subaddiesect_entrypoint_0(arg0, temp_a1, 11) != 0))) {
        func_80800180_chbeehive(arg0);
    }
}

void func_808000CC_chbeehive(Actor *arg0, s16 **arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_800EE88C(f32 *, s16 *);
    void _chexploder_entrypoint_3(void *, void *, u32);
    extern s32 D_808002F0_chbeehive[4];
    extern s32 D_80800300_chbeehive[4];
    extern s32 D_80800320_chbeehive[17];
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808002F0_chbeehive);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800300_chbeehive);
    func_800BBCB8(arg0->position, NULL, arg0->scale, 1, D_80800320_chbeehive);
    if ((BtIntPtr)arg0->unk3C != 0) {
        func_8010114C((BtIntPtr)arg0->unk3C, 0x53, 0);
    }
    {
        struct { f32 x, y, z; } position;
        func_800EE88C(&position.x, *arg1 + 2);
        position.y = arg0->position[1];
        _chexploder_entrypoint_3(arg0, &position, 0x2C);
    }
}

s32 func_80800180_chbeehive(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_0(u8 arg0, s32 arg1);
    u8 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    void func_800C3CE8(u8);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    extern f32 D_80800364_chbeehive[4];
    struct {
        u8 prefix[0x70];
        BT_BITFIELD_ORDER(u32 unused : 31, u32 active : 1);
        BT_BITFIELD_ORDER(u32 active : 1, u32 unused : 31);
    } *flags = (void *)arg0;
    u8 index;

    if (func_80101E4C(arg0, D_80800364_chbeehive) != 0) {
        index = arg0->unk5F;
        if (index == 0) {
            arg0->unk5F = func_800C2E04();
            func_800C301C(arg0->unk5F, 0x447);
            func_800C3058(arg0->unk5F, 0x2EE0);
            func_800C35E8(arg0->unk5F, arg0->position);
            func_800C3584(arg0->unk5F, 300.0f, 1500.0f);
        }
        index = arg0->unk5F;
        if (index != 0) {
            func_800C3CE8(index);
            func_800C31DC(arg0->unk5F, func_80101F24(arg0) + 0.5f);
            func_800C330C(arg0->unk5F, 3);
            _subaddieaudioquick_entrypoint_0(arg0->unk5F, flags->active);
            func_800C3BDC(arg0->unk5F);
        }
    }
    BT_NATIVE_ONLY(return 0;) return;
}

s32 func_80800268_chbeehive(Actor *arg0, s32 arg1, s16 **arg2) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    switch (arg1) {
        case 0x40:
            func_808000CC_chbeehive(arg0, arg2);
            break;
        case 0x90:
            break;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chbeehive_entrypoint_0(void)
{
    extern ActorData D_80800374_chbeehive[];

    return (OSThread *) D_80800374_chbeehive;
}
/* data_to_c.py: from asm/data/overlays/ch/beehive.data.s */
extern u8 D_80800310_chbeehive[];
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808002F0_chbeehive[4] BT_DATA(4, overlays_ch_beehive, 0x0) = { 1246219, 655616, 1469792, 0 };
s32 D_80800300_chbeehive[4] BT_DATA(4, overlays_ch_beehive, 0x10) = { 1246215, 655616, 1469792, 0 };
u8 D_80800310_chbeehive[16] BT_DATA(4, overlays_ch_beehive, 0x20) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x26, 0x66, 0x66, 0x00, 0x54, 0x00, 0x01 };
s32 D_80800320_chbeehive[17] BT_DATA(4, overlays_ch_beehive, 0x30) = { 1903049, 1442360, 1376275, 6684704, -84215176, 1966090, 1310764, 20, 0, 3276800, 2818355, 23461922, 33555072, 67110016, 1572864, 128, 8388608 };
f32 D_80800364_chbeehive[4] BT_DATA(4, overlays_ch_beehive, 0x74) = { 0.45f, 0.55f, 0.6f, -1.0f };
ActorData D_80800374_chbeehive [1] BT_DATA(4, overlays_ch_beehive, 0x84) = { { 80, 529, 1557, 1, (void *)D_80800310_chbeehive, (void (*)(struct Actor *))func_80800078_chbeehive, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 131072000, 0, 0, 0, 16896, -30456, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chbeehive, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32728, 12308, (void (*)(struct Actor *, long, long))func_80800268_chbeehive, 0 } };
