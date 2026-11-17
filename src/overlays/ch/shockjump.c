#include "common.h"

OSThread *chshockjump_entrypoint_0(void)
{
    extern ActorData D_808002B0_chshockjump[];

    return (OSThread *) D_808002B0_chshockjump;
}

OSThread *chshockjump_entrypoint_1(void)
{
    extern ActorData D_808002F8_chshockjump[];

    return (OSThread *) D_808002F8_chshockjump;
}

s32 func_80800018_chshockjump(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800F7B9C(BtIntPtr, u32);
    void _chexploder_entrypoint_6(Actor *arg0, f32 arg1, f32 arg2);
    void _chexploder_entrypoint_7(Actor *arg0, f32 arg1, f32 arg2);
    Actor *actor;

    switch (arg1) {
    case 0x90:
        actor = func_80106790(func_80101080());
        _chexploder_entrypoint_6(actor, 400.0f, 600.0f);
        _chexploder_entrypoint_7(actor, -600.0f, -400.0f);
        break;
    case 0x91:
        func_800F7B9C(arg2, 0x49U);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808000AC_chshockjump(s32 arg0, s32 arg1, s32 arg2) {
    void func_800F7B9C(BtIntPtr, u32);
    switch (arg1) {
    case 0x91:
        func_800F7B9C(arg2, 0x4AU);
        break;
    default:
        return 0;
    }
    return 1;
}    typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0xC]; s32 unk48; } Objshockjump_chshockjump_entrypoint_2_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chshockjump_entrypoint_2(Unk80132ED0 *arg0) {
    s32 _chexploder_entrypoint_5(u8 *, s32, u8 *, s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800340_chshockjump[8];
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80106790(arg0);
    sp24 = temp_v0;
    _chexploder_entrypoint_5(temp_v0, 0x756, temp_v0 + 4, (((Objshockjump_chshockjump_entrypoint_2_temp_v0 *)temp_v0)->unk48), (((Objshockjump_chshockjump_entrypoint_2_temp_v0 *)temp_v0)->unk38), 0xC);
    _subaddieaudioquick_entrypoint_2(sp24, sp24 + 4, D_80800340_chshockjump);
}

/* extern */

void func_80800148_chshockjump(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_8(Actor *, s32);
    int func_800C6E38(s32);
    f32 func_800F15F8(f32, f32, f32);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_80101870(void *, BtIntPtr);
    s32 var_a0;
    s32 sp18;
    s32 var_a1;

    sp18 = _subaddiefade_entrypoint_0(arg0);
    var_a0 = arg0->unk6C_9 == 0x210 ? 0xD : 9;
    if ((func_800C6E38(var_a0) != 0) && (func_800F64A4(func_800F54E4(), 0x401) != 0)) {
        var_a1 = (s32) func_800F15F8((f32) sp18, 255.0f, 5.0f);
    } else {
        var_a1 = (s32) func_800F15F8((f32) sp18, 90.0f, 5.0f);
    }
    _subaddiefade_entrypoint_8(arg0, var_a1);
    func_80101870(arg0, arg1);
}

/* extern */

void func_80800228_chshockjump(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    void _subaddiesect_entrypoint_2(Actor *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80102E08(void *);
    u32 func_8010A654(Actor *, s32);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1(arg0);
    arg0->actorData[4] = temp_v0;
    if (temp_v0 == -1) {
        if (arg0->unk74_7 != 0x33) {
            func_80102E08(arg0);
        }
    } else {
        _subaddiesect_entrypoint_2(arg0, arg0->actorData[4], arg0->unk74_7 != 0x33);
    }
    func_8010A654(arg0, func_800DA298(0x661));
}
/* data_to_c.py: from asm/data/overlays/ch/shockjump.data.s */
void func_80102EC0();
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808002B0_chshockjump [1] BT_DATA(4, overlays_ch_shockjump, 0x0) = { { 212, 528, 1589, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800148_chshockjump, 0, 0, 0, 0, 16512, 6144, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800228_chshockjump, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800018_chshockjump, 0 } };
ActorData D_808002F8_chshockjump [1] BT_DATA(4, overlays_ch_shockjump, 0x48) = { { 69, 564, 1590, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800148_chshockjump, 0, 0, 0, 0, 16512, 6144, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800228_chshockjump, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_808000AC_chshockjump, 0 } };
s32 D_80800340_chshockjump[8] BT_DATA(4, overlays_ch_shockjump, 0x90) = { 1246349, 852185, 15925272, 70536, 786432000, 0, 0, 0 };
