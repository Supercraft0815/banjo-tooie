#include "core2/actor_animation_entry.h"

typedef struct { f32 position[3]; } WeldarVector;

extern ActorAnimationEntry D_808045F0_chweldarboss[52];
void func_8080030C_chweldarboss(Actor *);
void func_80105834(Actor *);
void func_80801944_chweldarboss(Actor *, void *);
void func_808002BC_chweldarboss(Actor *);
OSThread *func_80108ED0(void);
void func_80800018_chweldarboss(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808014CC_chweldarboss(Actor *, s32, s32);
void func_80803EA4_chweldarboss(Actor *);
void func_8080412C_chweldarboss(Actor *, void *);
void func_80803E50_chweldarboss(Actor *);
u32 func_808040F4_chweldarboss(BtIntPtr, s32, s32);

u32 D_80804790_chweldarboss[] = {
    0x00000000, 0x00000000, 0x3E23D70A, 0x037A0001,
    0x3E23D70A, 0x037A0001, 0x3E23D70A, 0x037A0001,
    0x3E23D70A, 0x037A0001,
};

s32 D_808047B8_chweldarboss[] = {
    0x0013041D, 0x000D00C0, 0x00D90000,
};

BtFnWord D_808047C4_chweldarboss[] = {
    0x02F80465, 0x08170001, (BtFnWord)D_808045F0_chweldarboss, (BtFnWord)func_8080030C_chweldarboss,
    (BtFnWord)func_80105834, (BtFnWord)func_80801944_chweldarboss, 0x00000000, 0x00000000,
    0x00000000, 0x00000568, (BtFnWord)func_808002BC_chweldarboss, (BtFnWord)func_80108ED0,
    0x00B80000, (BtFnWord)func_80800018_chweldarboss, (BtFnWord)func_80107C2C, 0x82010480,
    (BtFnWord)func_808014CC_chweldarboss, 0x00000000,
};

BtFnWord D_8080480C_chweldarboss[] = {
    0x01580468, 0x086B0001, (BtFnWord)D_80804790_chweldarboss, (BtFnWord)func_80803EA4_chweldarboss,
    (BtFnWord)func_80105834, (BtFnWord)func_8080412C_chweldarboss, 0x00000000, 0x00000000,
    0x00000000, 0x00020400, 0x00000000, 0x00000000,
    0x00100000, (BtFnWord)func_80803E50_chweldarboss, (BtFnWord)func_80107C2C, 0x80000402,
    (BtFnWord)func_808040F4_chweldarboss, 0x00000000,
};

s32 D_80804854_chweldarboss[] = {
    0x0013061C, 0x0018000D, 0x00F3010C, 0x00020000,
};

s32 D_80804864_chweldarboss[] = {
    0x00130612, 0x0018000A, 0x00C00002, 0x00000000,
};

s32 D_80804874_chweldarboss[] = {
    0x00130413, 0x00180002, 0x00000000,
};

s32 D_80804880_chweldarboss[] = {
    0x001D078F, 0x00150019, 0x00660016, 0x12000032,
    0x0002001E, 0x001E001E, 0x00180000, 0x00000F00,
    0x0F000022, 0x01000100, 0x04000400, 0x002B0100,
    0x01000000,
};

s32 D_808048B4_chweldarboss[] = {
    0x001D09DD, 0x002B0800, 0x0A000022, 0x04000500,
    0x08800A00, 0x00150000, 0x00660019, 0x00000007,
    0x002D0064, 0x00C80020, 0xC0C0C080, 0x000B003C,
    0x007800B4, 0xFF4C0000,
};

WeldarVector D_808048EC_chweldarboss = {{-1800.0f, 1200.0f, -2200.0f}};

u8 D_808048F8_chweldarboss[] = {
    0x00, 0x13, 0x04, 0xFE,
    0x00, 0x18, 0x00, 0x02,
    0x00, 0x0A, 0x00, 0x8C,
    0x00, 0x00, 0x00, 0x00,
};

u32 D_80804908_chweldarboss[] = {
    0x00130606, 0x000A0133, 0x00163E80, 0x00020000,
};

u32 D_80804918_chweldarboss[] = {
    0x001304A4, 0x000D00AE, 0x00B80002, 0x00000000,
};

u32 D_80804928_chweldarboss[] = {
    0x001D09E2, 0x00160200, 0x00050000, 0x00040099,
    0x00070004, 0x00150000, 0x00CC002B, 0x01800200,
    0x0022004C, 0x00590026, 0x0033002D, 0x00FA0190,
    0x000AFF9C, 0x000AFF9C, 0x0064000A, 0x0064001B,
    0xF9C0FB50, 0x00000000,
};

u32 D_80804970_chweldarboss[] = {
    0x00130609, 0x000D00F3, 0x010C0002, 0x00000000,
};

u32 D_80804980_chweldarboss[] = {
    0x0013060A, 0x000D00F3, 0x010C0002, 0x00000000,
};

u32 D_80804990_chweldarboss[] = {
    0x00130608, 0x000D00F3, 0x010C0002, 0x00166D60,
    0x00000000,
};

u32 D_808049A4_chweldarboss[] = {
    0x00130607, 0x000D00F3, 0x010C0002, 0x00180000,
};

s32 D_808049B4_chweldarboss[] = {
    0x001D09DD, 0x00168000, 0x002D0258, 0x03200113,
    0x002200F3, 0x010C0040, 0x00590015, 0x00260099,
    0x002B004C, 0x00660000,
};

s32 D_808049DC_chweldarboss[] = {
    0x0013060B, 0x000D00F3, 0x010C0002, 0x00180000,
};

u32 D_808049EC_chweldarboss[] = {
    0x001304A0, 0x000D0099, 0x00A60002, 0x00000000,
};

s32 D_808049FC_chweldarboss[] = {
    0x001304A0, 0x000D0099, 0x00A60016, 0x6D600002,
    0x00000000,
};

s32 D_80804A10_chweldarboss[] = {
    0x001D09DD, 0x002B0180, 0x02000022, 0x01800200,
    0x03800400, 0x00150000, 0x00990027, 0xFF9CFF9C,
    0x00640064, 0x00190000, 0x0007002D, 0x00FA015E,
    0x0020C0C0, 0xC0C0011A, 0x00000000,
};

u8 D_80804A4C_chweldarboss[] = {
    0x3E, 0x4C, 0xCC, 0xCD,
    0x00, 0x00, 0x00, 0x00,
    0x3E, 0xCC, 0xCC, 0xCD,
    0x3F, 0x80, 0x00, 0x00,
    0x3F, 0x26, 0x66, 0x66,
    0x00, 0x00, 0x00, 0x00,
};

u8 D_80804A64_chweldarboss[] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x3E, 0xCC, 0xCC, 0xCD,
    0x3F, 0x80, 0x00, 0x00,
    0x3F, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

u8 D_80804A7C_chweldarboss[] = {
    0x00, 0x00, 0x00, 0x00,
    0x3F, 0x80, 0x00, 0x00,
    0x3E, 0xCC, 0xCC, 0xCD,
    0x00, 0x00, 0x00, 0x00,
    0x3F, 0x40, 0x00, 0x00,
    0x3F, 0x80, 0x00, 0x00,
};

u8 D_80804A94_chweldarboss[] = {
    0x00, 0x13, 0x04, 0x9C,
    0x00, 0x18, 0x00, 0x0D,
    0x00, 0x66, 0x00, 0x80,
    0x00, 0x02, 0x00, 0x00,
};

u8 D_80804AA4_chweldarboss[] = {
    0x00, 0x13, 0x06, 0x1C,
    0x00, 0x18, 0x00, 0x0D,
    0x00, 0xF3, 0x01, 0x0C,
    0x00, 0x02, 0x00, 0x00,
};

s32 D_80804AB4_chweldarboss[] = {
    0x001304A9, 0x00020000,
};

u32 D_80804ABC_chweldarboss[] = {
    0x00000080, 0x000000C0, 0x000000FF,
};

u32 D_80804AC8_chweldarboss[] = {
    0x000000FF, 0x000000FF, 0x000000FF, 0x00000000,
    0x00000000, 0x00000000,
};

OSThread *chweldarboss_entrypoint_0(void)
{


    return (OSThread *) D_808047C4_chweldarboss;
}

OSThread *chweldarboss_entrypoint_1(void)
{


    return (OSThread *) D_8080480C_chweldarboss;
}

void func_80800018_chweldarboss(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        u8 padC[0xC];
        f32 unk18[3];
        u8 pad24[0xC];
        u8 unk30[8];
        f32 unk38[3];
        u8 pad44[0x1D];
        u8 unk61;
        u8 pad62[6];
        u8 unk68[6];
        u8 pad6E;
        s8 unk6F;
        u8 pad70[6];
        s16 unk76;
        s16 unk78;
        u8 pad7A[0x32];
        s16 unkAC;
        u8 padAE[6];
        f32 unkB4;
    } WeldarLocal;
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _plcamera_entrypoint_8(BT_IDO_ONLY(s32 *) BT_NATIVE_ONLY(u32) arg0);
    void _subaddielink_entrypoint_0(void *arg0);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void func_800BF744(s32, s32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(BtIntPtr);
    u32 func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    f32 func_80102D78(Actor *, f32 *);
    void func_80108B04(Actor *, u32);
    void func_80109EEC(s16 *, s32);
    void func_80801AA0_chweldarboss(Actor *, s32);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    WeldarLocal *local;
    BtIntPtr map;
    s32 i;
    BtIntPtr map2;

    local = func_80100094(arg0, 0);
    if (_glcutDll_entrypoint_19(0x8A)) {
        func_800FFAB0(arg0);
        return;
    }
    if (!_glcutDll_entrypoint_20()) {
        if (func_800DA298(0x18C)) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x174)) {
            map2 = func_800F54E4();
            if (func_800F6438(map2) && !func_800F64A4(map2, 1)) {
                func_800FFAB0(arg0);
                return;
            }
        }
    }
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x32, local->unk0, 1);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, local->unk18, 1);
    arg0->rotation[1] = func_80102D78(arg0, local->unk0);
    func_800EE7F8(local->unk38, arg0->position);
    _subaddielink_entrypoint_0(local->unk30);
    func_80108B04(arg0, 0);
    func_80109EEC((s16 *)arg0, 0x40);
    local->unkAC = 1;
    func_800BF744(3, 0);
    for (i = 0; i < 6; i++) {
        local->unk68[i] = 1;
    }
    local->unk6F = 6;
    local->unk76 = -1;
    local->unk78 = -1;
    local->unkB4 = 0.25f;
    map = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(arg0->position, local->unk0);
        func_80102424(arg0, 0x33);
        arg0->pad7A_7 = 1;
        return;
    }
    if (func_800DA298(0x174)) {
        func_800EE7F8(arg0->position, local->unk0);
        func_800F608C(map, 1);
        func_800F8294(map, local->unk18);
        func_800F497C(map);
        _plcamera_entrypoint_8(BT_NATIVE_ONLY((u32)) map);
        func_80801AA0_chweldarboss(arg0, 6);
        func_80802214_chweldarboss(arg0, 0x1356, 0xF);
        func_80803CF0_chweldarboss(arg0, 0x11, 0x30);
        local->unk61 = 1;
        arg0->pad7A_7 = 1;
        return;
    }
    if (func_800D395C()) {
        func_80801AA0_chweldarboss(arg0, 2);
        return;
    }
    _chintrotext_entrypoint_2(1);
    arg0->unk64_16 = 0;
}    typedef struct { u8 pad0[0xB0]; u8 unkB0; u8 unkB1; u8 unkB2; } Objweldarboss_func_808002BC_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_808002BC_chweldarboss(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB0) = _subaddieaudioloop_entrypoint_3((((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB0));
    (((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB1) = _subaddieaudioloop_entrypoint_3((((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB1));
    (((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB2) = _subaddieaudioloop_entrypoint_3((((Objweldarboss_func_808002BC_chweldarboss_temp_v0 *)temp_v0)->unkB2));
}

void func_8080030C_chweldarboss(Actor *arg0)
{
    typedef struct {
        f32 unk0[3];
        u8 padC[0x38];
        f32 unk44[3];
        u8 pad50[0xC];
        f32 unk5C;
        u8 pad60[2];
        u8 unk62;
        u8 unk63;
        u8 pad64[3];
        s8 unk67;
        u8 pad68[6];
        s8 unk6E;
        u8 pad6F;
        u8 unk70;
        u8 pad71[3];
        s16 unk74;
        s16 unk76;
        s16 unk78;
        u8 pad7A[2];
        u8 unk7C;
        u8 pad7D[0x37];
        f32 unkB4;
    } WeldarData;
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    s32 _subaddiefind_entrypoint_9(s32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800D8FF8(void);
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s32) func_800D9078(f32*);
    s32 func_800D90A4(f32*);
    s32 func_800DA298(s32 index);
    void func_800DA544(s32);
    void func_800EE7F8(f32[3], f32[3]);
    f32 func_800EF030(f32 *);
    void func_800EF1B8(f32*, f32, f32);
    f32 func_800EFC7C(f32 *, f32 *);
    s32 func_800F0064(f32 *, f32, f32 *);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F1DF4(f32[3], f32[3]);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32[3]);
    s32 func_800F64A4(BtIntPtr characterIndex, s32 transformationType);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor*);
    s32 func_80101E14(Actor*, f32);
    void func_80102B2C(Actor*, f32);
    s32 func_80102CF4(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_80108B04(Actor*, u32);
    void func_8010A570(Actor*);
    void func_8010A590(Actor *);
    s32 func_8010CA74(f32 *, s32);
    f32 func_8010CD50(Actor*, BtUIntPtr);
    void func_80801AA0_chweldarboss(Actor *, s32);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    void func_808023F8_chweldarboss(Actor *);
    void func_8080247C_chweldarboss(Actor *);
    void func_808026BC_chweldarboss(Actor *);
    void func_80802B1C_chweldarboss(Actor *);
    f32 func_80802C9C_chweldarboss(Actor *, s32);
    void func_80802D2C_chweldarboss(Actor *, s32, s32);
    void func_80802E80_chweldarboss(Actor *);
    void func_80802F14_chweldarboss(Actor *, s32);
    void func_80802FE4_chweldarboss(Actor *, s32);
    void func_808032A8_chweldarboss(Actor *);
    s32 func_808033D8_chweldarboss(Actor *);
    void func_808034A0_chweldarboss(Actor *);
    void func_80803528_chweldarboss(Actor *, f32 *);
    void func_808035D0_chweldarboss(Actor *);
    void func_80803624_chweldarboss(Actor *);
    void func_8080367C_chweldarboss(Actor *);
    void func_80803770_chweldarboss(Actor *);
    int func_80803B48_chweldarboss(BtIntPtr);
    void func_80803C18_chweldarboss(Actor *);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    void func_80803D64_chweldarboss(Actor *);
    BtIntPtr func_80803D98_chweldarboss(BtIntPtr);
    extern f32 B_80804AE0_chweldarboss[3];

    extern void _chbaddiesetup_entrypoint_10(void);

    WeldarData *sp94;
    s32 sp90;
    f32 sp84[3];
    f32 sp80;
    s32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    BtIntPtr sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp40[3];
    /* Keep these temporaries in order for the original IDO stack layout. */
    f32 deltaMovement;
    s32 count2;
    f32 value;
    s32 count1;
    f32 angle;

    sp94 = func_80100094(arg0, 0U);
    sp90 = 0;
    sp94->unk78 = func_80803D98_chweldarboss((BtIntPtr)arg0);
    func_8080367C_chweldarboss(arg0);
    func_800F5A00((s32) sp94->unk78, sp84);
    switch (arg0->unk70_10) {
    case 1:
        if (func_8010CA74(arg0->position, 0x1B58) != 0) {
            sp5C = func_800F54E4();
            if (func_80803B48_chweldarboss(sp5C) != 0) {
                sp5C = func_800F54E4();
                if (func_800F64A4(sp5C, 1) != 0) {
                    func_80801AA0_chweldarboss(arg0, 2);
                }
            }
        }
        break;
    case 2:
        if (sp94->unk70 == 0) {
            sp94->unk70 = 1U;
            func_80101180(0x431, 8, 0);
        }
        break;
    case 3:
        value = func_80802C9C_chweldarboss(arg0, 0);
        sp80 = value * 500.0f;
        value = func_800D8FF8();
        deltaMovement = value * sp80;
        func_800EF1B8(arg0->position, arg0->rotation[1], deltaMovement);
        if (func_800D9078(&sp94->unkB4) != 0) {
            func_80802214_chweldarboss(arg0, 0x1366, 0x44);
        }
        if (func_800F0064(arg0->position, 200.0f, sp94->unk0) != 0) {
            func_80801AA0_chweldarboss(arg0, 4);
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 5);
        }
        break;
    case 5:
        if (func_800DA298(0x6AD) == 0) {
            func_80802214_chweldarboss(arg0, 0x1355, 6);
            func_80801AA0_chweldarboss(arg0, 6);
        }
        break;
    case 7:
        sp7C = func_800F0064(arg0->position, 200.0f, B_80804AE0_chweldarboss);
        func_80802F14_chweldarboss(arg0, 0);
        if (sp7C == 0) {
            sp78 = func_800D8FF8();
            value = func_80802C9C_chweldarboss(arg0, 1);
            sp74 = value * 700.0f;
            value = func_80802C9C_chweldarboss(arg0, 2);
            sp70 = value * 100.0f;
            arg0->unk54 = func_80102D78(arg0, B_80804AE0_chweldarboss);
            func_80102B2C(arg0, sp70 * sp78);
            func_800EF1B8(arg0->position, arg0->rotation[1], sp74 * sp78);
        } else if (func_80101E14(arg0, 0.999f) != 0) {
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
        }
        break;
    case 8:
        sp6C = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp68 = value * 100.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp68 * sp6C);
        func_80802F14_chweldarboss(arg0, 0);
        if ((func_80102CF4(arg0, 10.0f) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_80801AA0_chweldarboss(arg0, 9);
        }
        break;
    case 9:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101E14(arg0, 0.3f) != 0) {
            func_80108B04(arg0, 1U);
        }
        if (func_80101DDC(arg0) != 0) {
            sp94->unk63 -= 1;
            if (sp94->unk63 == 0) {
                func_80801AA0_chweldarboss(arg0, 0xA);
            } else {
                func_80801AA0_chweldarboss(arg0, 8);
            }
        }
        break;
    case 10:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0xB);
        }
        break;
    case 11:
        func_80802D2C_chweldarboss(arg0, 0x10, 0xC);
        break;
    case 12:
        func_80802FE4_chweldarboss(arg0, 0xD);
        break;
    case 13:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
        }
        break;
    case 14:
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk7C == 0) {
                sp94->unk7C = 1U;
                func_80803CF0_chweldarboss(arg0, 0x22, 0x30);
                func_80802214_chweldarboss(arg0, 0x1359, 6);
                func_80801AA0_chweldarboss(arg0, 0xF);
            } else {
                func_80803D64_chweldarboss(arg0);
                func_80801AA0_chweldarboss(arg0, 0x12);
                sp94->unk63 = 3U;
            }
        }
        break;
    case 16:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x11);
        }
        break;
    case 17:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
            sp94->unk76 = -1;
        }
        break;
    case 18:
        sp64 = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp60 = value * 100.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp60 * sp64);
        func_80802F14_chweldarboss(arg0, 0);
        if ((func_80102CF4(arg0, 10.0f) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_80801AA0_chweldarboss(arg0, 0x13);
        }
        break;
    case 19:
        if (func_80101E14(arg0, 0.3f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, sp94->unk44, D_80804854_chweldarboss);
            func_80108B04(arg0, 2U);
            sp94->unk63 = (u8) (sp94->unk63 - 1);
        }
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk63 == 0) {
                func_80801AA0_chweldarboss(arg0, 0x14);
            } else {
                func_80801AA0_chweldarboss(arg0, 0x12);
            }
        }
        break;
    case 20:
        count1 = _subaddiefind_entrypoint_9(0x43F);
        count2 = _subaddiefind_entrypoint_9(0x43E);
        sp5C = _subaddiefind_entrypoint_9(0x440) + count2 + count1;
        func_80802F14_chweldarboss(arg0, 0);
        if (sp5C == 0) {
            func_80801AA0_chweldarboss(arg0, 0x15);
        }
        break;
    case 21:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x16);
        }
        break;
    case 22:
        func_80802D2C_chweldarboss(arg0, 0x1A, 0x17);
        break;
    case 23:
        func_80802FE4_chweldarboss(arg0, 0x18);
        break;
    case 24:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x12);
            sp94->unk63 = 3U;
        }
        break;
    case 25:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1C);
        }
        break;
    case 26:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1B);
        }
        break;
    case 27:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x12);
            sp94->unk63 = 3U;
            sp94->unk76 = -1;
        }
        break;
    case 28:
        func_80802F14_chweldarboss(arg0, 0);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, (u32 *) D_808047B8_chweldarboss, 0.15f);
        if (func_80101E14(arg0, 0.85f) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1D);
            sp94->unk5C = 3000.0f;
        }
        break;
    case 29:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if ((sp94->unk74 == 0) && (arg0->position[1] > 2750.0f)) {
            if (func_800EF030(sp84) > 360000.0f) {
                sp58 = func_800F1DF4(sp84, B_80804AE0_chweldarboss);
                arg0->position[0] = sp84[0];
                arg0->position[2] = sp84[2];
                func_800EF1B8(arg0->position, sp58, 600.0f);
            }
            sp94->unk74 = 1;
            func_80803D64_chweldarboss(arg0);
        }
        if (sp94->unk74 != 0) {
            if (func_800EFC7C(sp84, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, sp84);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        if (sp94->unk5C < 0.0f) {
            func_80801AA0_chweldarboss(arg0, 0x1E);
            func_8010A570(arg0);
        }
        break;
    case 30:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if (arg0->position[1] > 1500.0f) {
            if (func_800EFC7C(sp84, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, sp84);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        func_80803528_chweldarboss(arg0, sp84);
        if (arg0->position[1] < 0.0f) {
            arg0->position[1] = 0.0f;
            func_80802B1C_chweldarboss(arg0);
            func_808035D0_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x1F);
            func_8010A590(arg0);
        }
        break;
    case 31:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x20);
            arg0->unk58 = 10.0f;
        }
        break;
    case 32:
        sp54 = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 1);
        sp50 = value * 1400.0f;
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp4C = value * 160.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp4C * sp54);
        func_800EF1B8(arg0->position, arg0->rotation[1], sp50 * sp54);
        arg0->position[0] = func_800F0D50(arg0->position[0], -2000.0f, 2000.0f);
        arg0->position[2] = func_800F0D50(arg0->position[2], -2000.0f, 2000.0f);
        sp90 = 1;
        func_80802F14_chweldarboss(arg0, 0);
        if (func_800D90A4(&arg0->unk58) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x21);
        }
        break;
    case 33:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, (u32 *) D_808047B8_chweldarboss, 0.15f);
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101E14(arg0, 0.85f) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x22);
            sp94->unk5C = 3000.0f;
        }
        break;
    case 34:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if (func_800EFC7C(B_80804AE0_chweldarboss, arg0->position) > 2500.0f) {
            angle = func_80102D78(arg0, B_80804AE0_chweldarboss);
            value = func_800D8FF8();
            func_800EF1B8(arg0->position, angle, value * 600.0f);
        }
        if (sp94->unk5C < 0.0f) {
            func_80801AA0_chweldarboss(arg0, 0x23);
            func_8010A570(arg0);
        }
        break;
    case 35:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if ((sp94->unk74 == 0) && (arg0->position[1] < 3000.0f)) {
            _subaddieaudioquick_entrypoint_2(arg0, sp94->unk44, D_80804864_chweldarboss);
            sp94->unk74 = 1;
            func_80803CF0_chweldarboss(arg0, 0x3C, 0x30);
        }
        if (arg0->position[1] > 1500.0f) {
            if (func_800EFC7C(B_80804AE0_chweldarboss, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, B_80804AE0_chweldarboss);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        func_80803528_chweldarboss(arg0, sp84);
        if (arg0->position[1] < 0.0f) {
            arg0->position[1] = 0.0f;
            func_80802B1C_chweldarboss(arg0);
            func_808035D0_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x24);
            func_8010A590(arg0);
        }
        break;
    case 36:
        if (func_80101DDC(arg0) != 0) {
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x25);
        }
        break;
    case 37:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x26);
        }
        break;
    case 38:
        func_80802D2C_chweldarboss(arg0, 0x2A, 0x27);
        break;
    case 39:
        func_80802FE4_chweldarboss(arg0, 0x28);
        break;
    case 40:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1C);
        }
        break;
    case 41:
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk62 == 0) {
                func_80801AA0_chweldarboss(arg0, 0x2C);
            } else {
                sp94->unk67 = 1;
                func_80801AA0_chweldarboss(arg0, 0x2D);
            }
        }
        break;
    case 42:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x2B);
        }
        break;
    case 43:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80801AA0_chweldarboss(arg0, 0x1C);
            sp94->unk76 = -1;
        }
        break;
    case 45:
        func_80803624_chweldarboss(arg0);
        break;
    case 46:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800EE7F8(sp40, arg0->position);
            sp40[1] += 300.0f;
            sp94->unk6E = 0;
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, *(s32 *)&sp40[0], *(s32 *)&sp40[1], *(s32 *)&sp40[2], *(s32 *)&arg0->rotation[1]);
            func_800BBCB8(sp40, sp40, 3.0f, 1, D_80804880_chweldarboss);
            func_800BBCB8(sp40, sp40, 1.0f, 6, D_808048B4_chweldarboss);
            _chexploder_entrypoint_5(arg0, 0x86F, arg0->position, arg0->rotation[1], arg0->scale, 3);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804874_chweldarboss);
        }
        func_80803624_chweldarboss(arg0);
        break;
    case 47:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800DA544(0x18C);
            func_80101180(0x345, 5, 0);
        }
        break;
    case 48:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x31);
        }
        break;
    }
    func_808023F8_chweldarboss(arg0);
    func_8080247C_chweldarboss(arg0);
    func_808026BC_chweldarboss(arg0);
    func_80803770_chweldarboss(arg0);
    func_80803C18_chweldarboss(arg0);
    func_808034A0_chweldarboss(arg0);
    if (sp90 != 0) {
        _sudeflect_entrypoint_1(arg0->position, 600.0f, 0.0f, 600.0f, 4);
    }
}

s32 func_808014CC_chweldarboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x30];
        u8 link[0x14];
        u8 pad44[0x1D];
        u8 unk61;
        u8 pad62[4];
        u8 unk66;
        u8 pad67;
        u8 unk68[6];
    } WeldarData;
    typedef struct {
        u8 pad0[0x18];
        BT_BITFIELD_ORDER(u32 pad18_16 : 16, u32 pad18_0 : 5);
        u32 id : 11;
        BT_BITFIELD_ORDER(u32 pad18_0 : 5, u32 pad18_16 : 16);
        u8 pad1C[8];
        BT_BITFIELD_ORDER(u32 unk24_22 : 10, u32 pad24_0 : 22);
        BT_BITFIELD_ORDER(u32 pad24_0 : 22, u32 unk24_22 : 10);
    } HitData;

    void *func_80100094(Actor *, u32);
    void func_80801F30_chweldarboss(Actor *, s32, s32);
    s32 func_80802100_chweldarboss(Actor *, s32);
    void func_8080227C_chweldarboss(Actor *, s32);
    void func_80801AA0_chweldarboss(Actor *, s32);
    s32 func_80803DD8_chweldarboss(Actor *);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    s32 _sueggmisc_entrypoint_0();
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void _chexploder_entrypoint_15(Actor *, u32, f32);
    void _chexploder_entrypoint_13(Actor *, u32);
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    void _chexploder_entrypoint_8(Actor *, f32, f32);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_80101010(f32 *);
    s32 _subaddielink_entrypoint_3(u8 *);
    u32 func_800FDC28(u32);
    s32 func_800D395C(void);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    void func_8080373C_chweldarboss(Actor *);
    void func_80803D64_chweldarboss(Actor *);
    WeldarData *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x2E:
        func_80801F30_chweldarboss(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0xB:
        return func_80802100_chweldarboss(arg0, arg2);
    case 0x3D:
        func_8080227C_chweldarboss(arg0, arg2);
        break;
    case 0x3F: {
        HitData *hit = *(HitData **)&arg2;
        if (hit->unk24_22 == 0) {
            switch (arg0->unk70_10) {
            case 11: case 12: case 16: case 22: case 23:
            case 26: case 38: case 39: case 42:
                break;
            case 32:
                func_80801AA0_chweldarboss(arg0, 0x21);
            default:
                func_800F79DC(hit->id, 7, (BtIntPtr)arg0->unk0);
                break;
            }
        }
        break;
    }
    case 0x40: {
        Actor *other = *(Actor **)&arg2;
        if (func_80803DD8_chweldarboss(arg0) && _sueggmisc_entrypoint_0(other)) {
            func_8010114C((BtIntPtr)other, 0x2C, 0);
        }
        break;
    }
    case 0x90: {
        s32 id;
        Actor *exploder = func_80106790(func_80101080());
        id = arg2;
        switch (id) {
        case 0x86E:
            _chexploder_entrypoint_15(exploder, 2, 1.0f);
            _chexploder_entrypoint_13(exploder, 1);
            break;
        case 0x86F:
            arg0->unk64_16 = 0;
            _chexploder_entrypoint_6(exploder, 1000.0f, 1200.0f);
            break;
        case 0x870:
            _chexploder_entrypoint_6(exploder, 3000.0f, 3000.0f);
            _chexploder_entrypoint_8(exploder, 450.0f, 450.0f);
            _chexploder_entrypoint_9(exploder, 1, 1);
            _chexploder_entrypoint_9(exploder, 2, 1);
            _chexploder_entrypoint_13(exploder, 11);
            _chexploder_entrypoint_8(exploder, 320.0f, 320.0f);
            break;
        }
        break;
    }
    case 0x8D: {
        Actor *other = func_80106790(func_80101080());
        switch (arg2) {
        case 0x86E: {
            f32 position[3];
            f32 angle;
            angle = func_800F1DF4(arg0->position, other->position);
            func_800EE7F8(position, other->position);
            func_800EF1B8(position, angle, -200.0f);
            func_80101010(position);
            data->unk68[data->unk66] = 0;
            data->unk66++;
            goto handled;
        }
        case 0x870: {
            WeldarVector target = D_808048EC_chweldarboss;
            f32 rotation[2];
            f32 position[3];
            func_800F18FC(other->position, target.position, rotation);
            func_800EE7F8(position, other->position);
            func_800EF214(position, -rotation[0], rotation[1], -500.0f);
            position[1] -= 200.0f;
            func_80101010(position);
            return 1;
        }
        }
        return 0;
    }
    case 7:
        func_80801AA0_chweldarboss(arg0, 0x30);
        break;
    case 0x95:
        _subaddielink_entrypoint_3(data->link);
        if (data->unk61) {
            func_800FDC28(1);
            data->unk61 = 0;
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_80802214_chweldarboss(arg0, 0xCEB, 0x4E);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_8080373C_chweldarboss(arg0);
        func_80801AA0_chweldarboss(arg0, 0x32);
        func_80803D64_chweldarboss(arg0);
        break;
    default:
        return 0;
    }
handled:
    return 1;
}

void func_80801944_chweldarboss(Actor *arg0, void *arg1) {
    typedef struct {
        u8 pad0[0x30];
        u8 link[0x14];
        f32 unk44[3];
        f32 unk50[3];
        u8 pad5C[0xC];
        u8 unk68[6];
        u8 unk6E;
        u8 pad6F[0x15];
        s32 unk84;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    BT_IDO_ONLY(u8 func_800D731C(s32);) BT_NATIVE_ONLY(s32 func_800D731C(s32);)
    s32 func_800DBE60(u8, s32, s32);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void _subaddieDll_entrypoint_7(Actor *, s32);
    void func_80101870(Actor *, void *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    WeldarData *data;
    Actor *linked;
    f32 savedPosition[3];
    s32 sound;
    f32 rotation[3];
    s32 i;

    data = func_80100094(arg0, 0);
    sound = func_800D731C(arg0->unk0->unk14);
    if (sound != 0) {
        func_800DBE60(sound, 0, data->unk84);
    }
    for (i = 0; i != 6; i++) {
        func_800DF744(i + 3, data->unk68[i]);
    }
    if (data->unk6E != 0) {
        func_800EE7F8(savedPosition, arg0->position);
        _subaddieDll_entrypoint_7(arg0, 15);
    }
    func_80101870(arg0, arg1);
    if (data->unk6E != 0) {
        func_800EE7F8(arg0->position, savedPosition);
    }
    if (arg0->unk7C_12) {
        linked = _subaddielink_entrypoint_4(data->link);
        _subaddieskeleton_entrypoint_2(arg0->unk0, 5, data->unk44);
        _subaddieskeleton_entrypoint_2(arg0->unk0, 6, data->unk50);
        if (linked != NULL) {
            func_800EE7F8(linked->position, data->unk44);
            func_800F18FC(data->unk44, data->unk50, rotation);
            linked->rotation[0] = 90.0f - rotation[0];
            linked->rotation[1] = rotation[1];
        }
    }
}

void func_80801AA0_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x60];
        s8 unk60;
        u8 pad61[0xD];
        s8 unk6E;
        u8 pad6F;
        u8 unk70;
        u8 pad71[3];
        s16 unk74;
        s16 unk76;
        u8 pad78[2];
        u8 unk7A;
        u8 unk7B;
        u8 pad7C;
        u8 unk7D;
        u8 unk7E;
        u8 unk7F;
        u8 pad80[0x32];
        u8 unkB2;
        u8 padB3;
        f32 unkB4;
    } WeldarData;
    void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    void _gcfrontend_entrypoint_10(void);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BF744(s32, s32);
    s32 func_800D395C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F4FC4(void);
    s32 func_800F8150(BtUIntPtr, s32);
    void func_800F82D4(BtIntPtr, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    f32 func_80803378_chweldarboss(Actor *);
    void func_8080340C_chweldarboss(Actor *);
    void func_80803460_chweldarboss(Actor *);
    void func_8080373C_chweldarboss(Actor *);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    void func_80803D64_chweldarboss(Actor *);

    WeldarData *data;
    s32 update;
    f32 position[3];

    data = func_80100094(arg0, 0);
    update = 0;
    func_80102424(arg0, arg1);
    func_80803460_chweldarboss(arg0);
    switch (arg1) {
    case 2:
        func_80803CF0_chweldarboss(arg0, 0x1D, 0x30);
        data->unk70 = 0;
        break;
    case 3:
        arg0->unk64_16 = 1;
        data->unkB4 = 4.0f;
        func_800BF744(1, 1);
        func_800FDC28(1);
        func_80803CF0_chweldarboss(arg0, 0, 0x30);
        func_80101180(0x341, 7, 0);
        break;
    case 4:
        arg0->pad7A_7 = 1;
        func_80101180(0x341, 8, 0);
        func_80803CF0_chweldarboss(arg0, 0xB, 0x30);
        break;
    case 5:
        _chintrotext_entrypoint_1(0x18B9, 6, 1, 0);
        break;
    case 8:
        update = 1;
        if (data->unk7A == 0) {
            data->unk7A = 1;
            func_80802214_chweldarboss(arg0, 0x1357, 0x44);
        }
        break;
    case 7:
    case 9:
    case 13:
    case 19:
    case 21:
    case 24:
    case 37:
    case 40:
        update = 1;
        break;
    case 12:
    case 23:
    case 39:
        update = 1;
        arg0->unk58 = func_80803378_chweldarboss(arg0);
        data->unkB2 = _subaddieaudioloop_entrypoint_3(data->unkB2);
        break;
    case 10:
        update = 1;
        if (data->unk7B == 0) {
            data->unk7B = 1;
            func_80802214_chweldarboss(arg0, 0x1358, 0x44);
        }
        break;
    case 14:
    case 25:
    case 41:
        func_80803CF0_chweldarboss(arg0, 0x1B, 0x438);
        break;
    case 11:
    case 22:
    case 38:
        update = 1;
        arg0->unk58 = 8.0f;
        break;
    case 16:
    case 26:
    case 42:
        data->unkB2 = _subaddieaudioloop_entrypoint_3(data->unkB2);
        func_800F82D4(data->unk76, 2);
        func_800F8150(data->unk76, 0);
        func_800F4FC4();
        data->unk60 = 1;
        func_80803CF0_chweldarboss(arg0, 0x19, 0x428);
        break;
    case 17:
    case 27:
    case 43:
        arg0->unk58 = 1.4f;
        break;
    case 28:
        if (data->unk7E == 0) {
            data->unk7E = 1;
            func_80802214_chweldarboss(arg0, 0x135B, 0x44);
        }
        func_80803CF0_chweldarboss(arg0, 0x39, 0x10);
        data->unk74 = 0;
        break;
    case 35:
        data->unk74 = 0;
        break;
    case 32:
        if (data->unk7F == 0) {
            data->unk7F = 1;
            func_80802214_chweldarboss(arg0, 0x135C, 0x44);
        }
        break;
    case 18:
        update = 1;
        if (data->unk7D == 0) {
            data->unk7D = 1;
            func_80802214_chweldarboss(arg0, 0x135A, 0x44);
        }
        break;
    case 44:
        func_80802214_chweldarboss(arg0, 0x135E, 6);
        func_80803CF0_chweldarboss(arg0, 0x22, 0x30);
        break;
    case 45:
        data->unk6E = 1;
        func_800FDC28(0);
        func_8080373C_chweldarboss(arg0);
        func_80802214_chweldarboss(arg0, 0x135D, 0xE);
        func_80803CF0_chweldarboss(arg0, 0x22, 0x30);
        break;
    case 46:
        arg0->unk58 = 1.0f;
        func_80803CF0_chweldarboss(arg0, 0x12, 0x430);
        break;
    case 47:
        func_800EE7F8(position, arg0->position);
        position[1] += 800.0f;
        _subaddieaudioquick_entrypoint_2(arg0, position, D_808048F8_chweldarboss);
        arg0->unk58 = 0.9f;
        _chexploder_entrypoint_5(arg0, 0x870, position, arg0->rotation[1], arg0->scale, 0x100);
        func_80803CF0_chweldarboss(arg0, 0x29, 0x30);
        break;
    case 48:
        arg0->unk58 = 4.0f;
        break;
    case 49:
        if (func_800D395C() != 0) {
            func_80803D64_chweldarboss(arg0);
            _gcfrontend_entrypoint_10();
        } else {
            func_80803CF0_chweldarboss(arg0, 0x1D, 0x30);
            func_80101180(0x431, 7, 0);
        }
        break;
    }
    if (update != 0) {
        func_8080340C_chweldarboss(arg0);
    }
}

void func_80801F30_chweldarboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x63];
        s8 unk63;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    void func_800DA544(s32);
    s32 _gcfrontend_entrypoint_9(s32);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    u32 func_800FDC28(u32);
    void func_800BF744(s32, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void func_800FFAB0(Actor *);
    void func_80803D64_chweldarboss(Actor *);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    void func_808036C8_chweldarboss(Actor *);
    s32 func_808033D8_chweldarboss(Actor *);
    WeldarData *data;
    s32 iterator;
    Actor *actor;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x1355:
    case 0x1356:
        func_800DA544(0x174);
        _gcfrontend_entrypoint_9(0x28);
        func_80803D64_chweldarboss(arg0);
        func_80801AA0_chweldarboss(arg0, 7);
        func_800FDC28(7);
        func_800BF744(1, 0);
        actor = _subaddiefind_entrypoint_2(0x3A7, &iterator);
        while (actor != NULL) {
            if (actor->position[2] < -2600.0f) {
                func_800FFAB0(actor);
            }
            actor = _subaddiefind_entrypoint_3(0x3A7, &iterator);
        }
        break;
    case 0x135D:
        func_80801AA0_chweldarboss(arg0, 0x2E);
        break;
    case 0x135E:
        func_808036C8_chweldarboss(arg0);
        func_80802214_chweldarboss(arg0, 0x135F, 6);
        func_80803CF0_chweldarboss(arg0, 0x1F, 0x30);
        break;
    case 0x135F:
        func_80803D64_chweldarboss(arg0);
        func_80801AA0_chweldarboss(arg0, 8);
        data->unk63 = func_808033D8_chweldarboss(arg0);
        break;
    case 0x1359:
        if (arg0->unk70_10 == 0xF) {
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x12);
            data->unk63 = 3;
        }
        break;
    case 0xCEB:
        if (arg2 > 0) {
            _gcfrontend_entrypoint_11();
        } else {
            _gcfrontend_entrypoint_10();
        }
        break;
    }
}

s32 func_80802100_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x30];
        u8 unk30[0x42];
        s16 unk72;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800FFAB0(Actor *);
#ifndef BT_NATIVE
    void func_800DA544(GameFlag);
#endif
    void _glcutDll_entrypoint_6(u32, u32);
    void func_80801AA0_chweldarboss(Actor *, s32);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    void func_80803D64_chweldarboss(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    WeldarData *data;
    s32 result;

    data = func_80100094(arg0, 0);
    result = 3;
    switch (arg1) {
    case 0x1D:
        if (arg0->unk70_10 == 2) {
            func_80801AA0_chweldarboss(arg0, 3);
        } else {
            func_800FFAB0(_subaddielink_entrypoint_4(data->unk30));
            func_800FFAB0(arg0);
            func_80803D64_chweldarboss(arg0);
            func_800DA544(0x9C9);
            _glcutDll_entrypoint_6(0x10F, 0x45);
        }
        result = 4;
        break;
    case 0x12:
        func_80801AA0_chweldarboss(arg0, 0x2F);
        result = 4;
        break;
    case 0x39:
        data->unk72 = 0;
        break;
    case 0x29:
        func_80803CF0_chweldarboss(arg0, 0x32, 0x30);
        func_80101180(0x46A, 0xA, 0);
        result = 4;
        break;
    }
    return result;
}

void func_80802214_chweldarboss(Actor *arg0, s32 arg1, s32 arg2) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, s16);)
    s32 func_800C064C(void);
    s32 func_800C067C(s32 arg0);
    if ((arg1 == 0x1359) && (func_800C064C() == 0x1358)) {
        func_800C067C(0x1358);
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, (u32) arg1, (u32) arg2, arg0->position, 0xB5U);
}

void func_8080227C_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x30];
        u8 unk30[0x14];
        f32 unk44[3];
        u8 pad50[0x28];
        s16 unk78;
    } WeldarData;
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    s32 func_800DC128(s32, s32);
    void func_800F5A00(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80100120(Actor *);
    void func_80101010(f32 *);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void func_8010D09C(BtIntPtr, f32 *, f32);
    WeldarData *data;
    Actor *sp38;
    Actor *sp34;
    f32 sp28[3];
    Actor *sp24;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0:
            sp38 = func_80108528(0x468, arg0->position, 0, &arg0);
            _subaddielink_entrypoint_1(data->unk30, sp38->unk0);
            sp38->unk3C = arg0->unk0;
            break;
        case 1:
            sp34 = func_80108528(0x124, data->unk44, 0, &arg0);
            func_8010D09C(data->unk78, (f32 *)sp34->actorData, 0.8f);
            sp34->unk3C = arg0->unk0;
            break;
        case 2:
            sp24 = func_80108528(func_800DC128(0, 3) + 0x43E, data->unk44, (s32)arg0->rotation[1], &arg0);
            func_80100120(sp24);
            func_800F5A00(data->unk78, sp28);
            sp28[1] = 0.0f;
            func_80101010(sp28);
            func_8010108C(sp24, 0x8E, (BtIntPtr)arg0->unk0);
            break;
    }
}

void func_808023BC_chweldarboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_808041C4_chweldarboss(Actor *, s32);
    Actor *temp_v0;

    temp_v0 = _subaddielink_entrypoint_4((u8 *)func_80100094(arg0, 0U) + 0x30);
    if (temp_v0 != NULL) {
        func_808041C4_chweldarboss(temp_v0, arg1);
    }
}

void func_808023F8_chweldarboss(Actor *arg0) {
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 sp2C[3];
    f32 scale;

    if (arg0->unk64_16) {
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] = 0.0f;
        scale = func_800F10B4(arg0->position[1], 0.0f, 3000.0f, 5.0f, 1.4f) * arg0->scale;
        _chbadshad_entrypoint_1(arg0, sp2C, scale);
    }
}

void func_8080247C_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x30];
        u8 link[0x37];
        u8 unk67;
        u8 pad68[0x48];
        u8 unkB0;
    } WeldarAudioData;
    typedef struct {
        f32 unk0[2];
        f32 unk8;
    } LinkedAudioData;
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800C31DC(u8, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    extern u32 D_80804908_chweldarboss[];
    WeldarAudioData *sp34;
    Actor *sp30;
    LinkedAudioData *sp2C;
    union { s32 word; u8 bytes[4]; } sp28;

    sp34 = func_80100094(arg0, 0);
    sp30 = _subaddielink_entrypoint_4(sp34->link);
    sp2C = func_80100094(sp30, 0);
    sp28.word = 0;
    if (sp30 != NULL) {
        switch (func_801022E4(arg0)) {
        case 0x36F:
            if (sp34->unk67 == 0 &&
                (func_80102320(arg0, 0.02f, 0.13f) ||
                 func_80102320(arg0, 0.26f, 0.55f))) {
                sp28.word = 1;
            }
            func_808023BC_chweldarboss(arg0, sp28.word ? 2 : 4);
            break;
        case 0x373:
            if (func_80101E14(arg0, 0.53f)) {
                func_808023BC_chweldarboss(arg0, 2);
            }
            if (func_80101E14(arg0, 0.75f)) {
                func_808023BC_chweldarboss(arg0, 4);
            }
            sp28.word = func_80102320(arg0, 0.53f, 0.75f);
            break;
        case 0x372:
            if (func_80101E14(arg0, 0.7f)) {
                func_808023BC_chweldarboss(arg0, 2);
            }
            sp28.word = func_80101F24(arg0) > 0.7f;
            break;
        default:
            func_808023BC_chweldarboss(arg0, 4);
            break;
        }
        if (sp2C->unk8 > 0.0f) {
            sp28.word = 1;
        }
        sp34->unkB0 = _subaddieaudioloop_entrypoint_7(sp34->unkB0, sp30->position, sp28.word, (s32 *)D_80804908_chweldarboss, arg0->unk70_0);
        if (sp34->unkB0) {
            func_800C31DC(sp34->unkB0, func_800F12D4(sp2C->unk8, 0.0f, 1.0f, 1.2f, 0.8f));
        }
    }
}

void func_808026BC_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x44];
        f32 unk44[3];
        u8 pad50[0x16];
        u8 unk66;
        u8 pad67[8];
        u8 unk6F;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_8001210C(s32);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E1540(s32);
    void func_800E1378(s32);
    void func_800E13F0(s32, f32);
    void func_800E1410(s32, f32, f32);
    void func_800187B4(s32, f32, f32, f32);
    void func_80802ABC_chweldarboss(Actor *, f32);
    WeldarData *sp6C;
    f32 sp60[3];
    f32 sp54[3];
    s32 effect;
    f32 sp44[3];
    s32 joint;
    f32 sp34[3];
    union { f32 value; s32 word; } sp30;

    sp6C = func_80100094(arg0, 0);
    switch (func_801022E4(arg0)) {
    case 0x371:
        _subaddieaudioquick_entrypoint_3(arg0, sp6C->unk44, D_80804980_chweldarboss, 0.22f);
        _subaddieaudioquick_entrypoint_3(arg0, sp6C->unk44, D_80804970_chweldarboss, 0.24f);
        if (func_80102320(arg0, 0.2f, 0.4f) && !func_8001210C(1)) {
            func_800EE7F8(sp54, sp6C->unk44);
            sp54[1] = 0.0f;
            func_800EE7F8(sp60, sp54);
            func_800EF1B8(sp60, arg0->rotation[1], -100.0f);

            func_800BBCB8(sp54, sp60, arg0->scale * 0.6f, 2, (s32 *)D_80804928_chweldarboss);
        }
        if (func_80102320(arg0, 0.24f, 0.64f) && func_8001210C(1)) {
            func_800BBCB8(arg0->position, sp6C->unk44, arg0->scale, 3, (s32 *)D_80804928_chweldarboss);
        }
        if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80804990_chweldarboss, 0.34f)) {
            effect = func_800E1540(2);
            func_800E1378(effect);
            func_800E13F0(effect, 10.0f);
            func_800E1410(effect, -8.0f, 1.8f);
            func_800187B4(0, 1.0f, 0.4f, 0.8f);
        }
        break;
    case 0x372:
        func_80802ABC_chweldarboss(arg0, 0.5f);
        break;
    case 0x375:
        func_80802ABC_chweldarboss(arg0, 0.75f);
        break;
    case 0x3E7:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80804918_chweldarboss, 0.15f);
        break;
    case 0x373:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80804918_chweldarboss, 0.08f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808049A4_chweldarboss, 0.5f);
        if (func_80101E14(arg0, 0.6f)) {
            sp6C->unk6F--;
            joint = sp6C->unk66;
            if (_subaddieskeleton_entrypoint_2(arg0->unk0, joint + 7, sp44)) {
                sp30.value = func_800F1DF4(arg0->position, sp44);
                func_800EE7F8(sp34, sp44);
                func_800EF1B8(sp34, sp30.value, -200.0f);
                _chexploder_entrypoint_5(arg0, 0x86E, sp44, sp30.value, arg0->scale, 2);
            }
        }
        break;
    case 0x374:
        break;
    }
}

void func_808029D8_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x44];
        f32 unk44[3];
        u8 pad50[0x62];
        u8 unkB2;
    } WeldarData;
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);

    WeldarData *sp3C;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    sp3C = func_80100094(arg0, 0);
    sp2C = func_800DC178(300.0f, 1000.0f);
    sp28 = func_800F10B4(sp2C, 300.0f, 1000.0f, 1.0f, 1.5f);
    func_800EEB9C(sp30, arg0->rotation[1], sp2C);
    func_800EF04C(sp30, sp3C->unk44);
    func_800BBCB8(sp30, sp3C->unk44, sp28, 1, D_808049B4_chweldarboss);
    sp3C->unkB2 = _subaddieaudioloop_entrypoint_7(sp3C->unkB2, sp3C->unk44, 1, D_808049DC_chweldarboss, arg0->unk70_0);
}

void func_80802ABC_chweldarboss(Actor *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);

    if (_subaddieaudioquick_entrypoint_3(arg0, &arg0->position[0], D_808049EC_chweldarboss, arg1) != 0) {
        func_800E15CC(0, 10.0f, 0.8f);
        func_80018820(0, 0.8f, 0.3f);
    }
}

void func_80802B1C_chweldarboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);

    BtIntPtr particles;
    f32 position[3];
    s32 i;

    particles = func_800B53A4(8);
    for (i = 0; i != 8; i++) {
        func_800EEB9C(position, (f32)i * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(position, arg0->position);
        position[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(particles, position, arg0->position, 1.0f, D_80804A10_chweldarboss);
    }
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808049FC_chweldarboss);
    func_800E15CC(0, 30.0f, 0.9f);
    func_80018820(0, 1.8f, 0.75f);
}

f32 func_80802C9C_chweldarboss(Actor *arg0, s32 arg1) {
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);

    f32 progress;

    progress = func_80101F24(arg0);
    switch (arg1) {
        case 0:
            return func_800F3780(progress, D_80804A4C_chweldarboss, 3);
        case 1:
            return func_800F3780(progress, D_80804A64_chweldarboss, 3);
        case 2:
            return func_800F3780(progress, D_80804A7C_chweldarboss, 3);
        default:
            return 0.0f;
    }
}

void func_80802D2C_chweldarboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x44];
        f32 position[3];
        u8 pad50[0x28];
        s16 unk78;
    } WeldarData;
    f32 func_800D8FF8(void);
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s32) func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102B2C(Actor *, f32);
    f32 func_8010CD50(Actor *, BtUIntPtr);
    s32 func_8010D490(f32 *, f32 *, f32, f32, s32);
    void func_80802E80_chweldarboss(Actor *);
    void func_80803080_chweldarboss(Actor *, s32);
    s32 func_80803184_chweldarboss(Actor *, s32);
    WeldarData *sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    s32 index;

    sp54 = func_80100094(arg0, 0);
    sp50 = func_800D9078(&arg0->unk58);
    sp4C = func_800D8FF8();
    arg0->unk54 = func_8010CD50(arg0, sp54->unk78);
    func_80102B2C(arg0, 120.0f * sp4C);
    func_808029D8_chweldarboss(arg0);
    func_80802E80_chweldarboss(arg0);
    if (arg0->unk7C_12) {
        func_800EEB9C(sp40, arg0->rotation[1], 100.0f);
        func_800EE7F8(sp34, sp54->position);
        func_800EF1B8(sp34, arg0->rotation[1], -300.0f);
        index = func_8010D490(sp34, sp40, 2300.0f, 600.0f, -1);
        if (index != -1) {
            func_80803080_chweldarboss(arg0, index);
        }
        switch (func_80803184_chweldarboss(arg0, index)) {
            case 1:
                func_80801AA0_chweldarboss(arg0, arg1);
                break;
            case 2:
                return;
        }
    }
    if (sp50 != 0) {
        func_80801AA0_chweldarboss(arg0, arg2);
    }
}

void func_80802E80_chweldarboss(Actor *arg0) {
    void func_80802F14_chweldarboss(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    f32 sp24[3];

    func_80802F14_chweldarboss(arg0, 1);
    func_800EE7F8(sp24, arg0->position);
    func_800EF1B8(sp24, arg0->rotation[1], 250.0f);
    _sudeflect_entrypoint_1(sp24, 500.0f, -100.0f, 300.0f, 2);
    func_800EF1B8(sp24, arg0->rotation[1], 300.0f);
    _sudeflect_entrypoint_1(sp24, 500.0f, -100.0f, 200.0f, 2);
}

void func_80802F14_chweldarboss(Actor *arg0, s32 arg1) {
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F682C(s32);
    int func_800F6AA4(BtIntPtr);
    s32 var_s0;
    s32 limit;

    var_s0 = 0;
    limit = 8;
    do {
        if ((func_800F6438(var_s0) != 0) && ((arg1 != 0) || (func_800F682C(var_s0) == 0) || (func_800F6AA4(var_s0) != 0))) {
            func_800F4EC8(var_s0, (BtIntPtr)arg0->position, 600.0f, -100.0f, 300.0f);
        }
        var_s0 += 1;
    } while (var_s0 != limit);
}

void func_80802FE4_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x78];
        s16 unk78;
    } WeldarData;
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102B2C(Actor *, f32);
    f32 func_8010CD50(Actor *, BtUIntPtr);
    void func_80801AA0_chweldarboss(Actor *, s32);
    WeldarData *sp2C;
    s32 sp28;
    f32 sp24;

    sp2C = func_80100094(arg0, 0);
    sp28 = func_800D90A4(&arg0->unk58);
    sp24 = func_800D8FF8();
    arg0->unk54 = func_8010CD50(arg0, sp2C->unk78);
    func_80102B2C(arg0, 120.0f * sp24);
    func_80802E80_chweldarboss(arg0);
    if (sp28 != 0) {
        func_80801AA0_chweldarboss(arg0, arg1);
    }
}

void func_80803080_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x44];
        f32 position[3];
    } WeldarData;
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5D9C(BtIntPtr, f32 *);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F6590(BtIntPtr);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    WeldarData *data;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    s32 *index = &arg1;
    f32 sp30;
    f32 sp2C;

    data = func_80100094(arg0, 0);
    if ((func_800F6478(arg1) != 0) && (func_800F6590(arg1) == 0)) {
        func_800F5A00(arg1, sp38);
        func_800EE7F8(sp50, data->position);
        func_800EF1B8(sp50, arg0->rotation[1], -600.0f);
        sp30 = func_800F10B4(func_800EEAD4(sp38, data->position), 100.0f, 3000.0f, 550.0f, 350.0f);
        func_800F5D9C(arg1, sp44);
        sp2C = func_800F1DF4(data->position, sp38);
        func_800EF1B8(sp44, sp2C, -(func_800D8FF8() * sp30));
        func_800F8418(arg1, sp44);
    }
}

s32 func_80803184_chweldarboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x44];
        f32 position[3];
        u8 pad50[0x26];
        s16 unk76;
        s16 unk78;
    } WeldarData;
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_800F0008(f32 *, f32, f32 *, f32);
    u32 func_800F54E4(void);
    f32 func_800F5BF0(BtIntPtr, f32 *);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F7B9C(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80803DD8_chweldarboss(Actor *);

    WeldarData *data;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;

    data = func_80100094(arg0, 0);
    if (arg1 == -1) {
        return 0;
    }
    if (func_800F6478(arg1) == 0) {
        return 0;
    }
    sp28 = func_800F5BF0(arg1, sp2C);
    func_800EE7F8(sp38, data->position);
    func_800EF1B8(sp38, arg0->rotation[1], 100.0f);
    if (func_800F0008(sp2C, sp28, sp38, 175.0f) != 0) {
        if (func_800F64A4(arg1, 0x10000) != 0) {
            func_800F7B9C(arg1, 0x86);
            data->unk78 = func_800F54E4();
            func_80803DD8_chweldarboss(arg0);
            return 2;
        }
        _subaddieaudioquick_entrypoint_2(arg0, data->position, D_80804A94_chweldarboss);
        func_80018820(0, 1.2f, 0.4f);
        data->unk76 = arg1;
        return 1;
    }
    return 0;
}

void func_808032A8_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x44];
        f32 unk44[3];
        u8 pad50[0x10];
        u8 unk60;
        u8 pad61[0x15];
        s16 unk76;
    } WeldarData;
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_800F7CF4(BtIntPtr, s32, void *);
    s32 func_800F8150(BtUIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);

    s32 pad3C;
    f32 sp30[3];
    f32 sp24[3];
    WeldarData *data;

    data = func_80100094(arg0, 0);
    if (data->unk60 != 0) {
        func_800EE7F8(sp30, data->unk44);
        sp30[1] -= 200.0f;
        func_800F8294(data->unk76, sp30);
        if (func_80101E14(arg0, 0.7f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, sp30, D_80804AA4_chweldarboss);
            func_800EE7F8(sp24, arg0->position);
            func_800EF1B8(sp24, arg0->rotation[1], 700.0f);
            func_800F7CF4(data->unk76, 0x92, sp24);
            func_800F8150(data->unk76, 1);
            data->unk60 = 0;
        }
    }
}

f32 func_80803378_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x6F];
        u8 unk6F;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    WeldarData *data;

    data = func_80100094(arg0, 0);
    return func_800F10B4(data->unk6F, 1.0f, 6.0f, 0.0f, 3.0f);
}

s32 func_808033D8_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    return ((u8 *)func_80100094(arg0, 0))[0x62] == 0 ? 5 : 8;
}    typedef struct { u8 pad0[0x64]; u8 unk64; u8 pad65[0x13]; s16 unk78; } Objweldarboss_func_8080340C_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x64]; s8 unk64; } Objweldarboss_func_8080340C_chweldarboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_8080340C_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808034A0_chweldarboss(Actor *);
    BT_IDO_ONLY(s32 func_800F4AF4(s16, s32);) BT_NATIVE_ONLY(s32 func_800F4AF4(s32, s32);)
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objweldarboss_func_8080340C_chweldarboss_temp_v0 *)temp_v0)->unk64) == 0) {
        sp1C = temp_v0;
        func_800F4AF4((((Objweldarboss_func_8080340C_chweldarboss_temp_v0 *)temp_v0)->unk78), 0x14);
        (((Objweldarboss_func_8080340C_chweldarboss_sp1C *)sp1C)->unk64) = 1;
    }
    func_808034A0_chweldarboss(arg0);
}    typedef struct { u8 pad0[0x64]; u8 unk64; u8 pad65[0x13]; s16 unk78; } Objweldarboss_func_80803460_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80803460_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800F4B20(BtUIntPtr);
    u8 *temp_v0;
    u8 pad[1];

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objweldarboss_func_80803460_chweldarboss_temp_v0 *)temp_v0)->unk64) != 0) {
        func_800F4B20((((Objweldarboss_func_80803460_chweldarboss_temp_v0 *)temp_v0)->unk78));
        (*(s8 *)((s8 *)(temp_v0) + (0x64))) = 0;
    }
}

void func_808034A0_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x64];
        u8 unk64;
        u8 pad65[0x13];
        s16 unk78;
    } WeldarCameraData;
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void _plcamera_entrypoint_9(BtIntPtr, f32 *, f32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32));
    BtIntPtr func_80110014(s32 *);
    void func_80116088(u8 *, BtIntPtr);
    WeldarCameraData *sp34;
    f32 sp28[3];
    s32 pad[2];

    sp34 = func_80100094(arg0, 0U);
    if (sp34->unk64 != 0) {
        func_800EE7F8(sp28, arg0->position);
        sp28[1] += 700.0f;
        _plcamera_entrypoint_9(sp34->unk78, sp28, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(sp34->unk78)), sp28);
    }
}

void func_80803528_chweldarboss(Actor *arg0, f32 *arg1) {
    typedef struct {
        u8 pad0[0x65];
        u8 unk65;
        u8 pad66[0x12];
        s16 unk78;
    } WeldarTriggerData;
    void *func_80100094(Actor *, u32);
    f32 func_800EFC7C(f32 *, f32 *);
    void func_800F82D4(BtIntPtr, s32);
    int func_80803B48_chweldarboss(BtIntPtr);
    WeldarTriggerData *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (sp1C->unk65 == 0 && arg0->position[1] < 300.0f) {
        if (func_800EFC7C(arg1, arg0->position) < 40000.0f &&
            func_80803B48_chweldarboss(sp1C->unk78) != 0) {
            sp1C->unk65 = 1;
            func_800F82D4(sp1C->unk78, 2);
        }
    }
}    typedef struct { u8 pad0[0x65]; u8 unk65; u8 pad66[0x12]; s16 unk78; } Objweldarboss_func_808035D0_chweldarboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_808035D0_chweldarboss(Actor *arg0) {
    void func_800F7B9C(BtIntPtr, u32);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    s32 sp18;
    sp1C = func_80100094(arg0, 0U);
    if ((((Objweldarboss_func_808035D0_chweldarboss_sp1C *)sp1C)->unk65) != 0) {
        sp18 = (((Objweldarboss_func_808035D0_chweldarboss_sp1C *)sp1C)->unk78);
        func_800F82D4(sp18, 0);
        func_800F7B9C(sp18, 0x5AU);
        (*(s8 *)((s8 *)(sp1C) + (0x65))) = 0;
    }
}    typedef struct { u8 pad0[0x6E]; u8 unk6E; u8 pad6F[0x42]; u8 unkB1; } Objweldarboss_func_80803624_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0xB1]; s8 unkB1; } Objweldarboss_func_80803624_chweldarboss_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

void func_80803624_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);

    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    (((Objweldarboss_func_80803624_chweldarboss_sp24 *)sp24)->unkB1) = _subaddieaudioloop_entrypoint_7((((Objweldarboss_func_80803624_chweldarboss_temp_v0 *)temp_v0)->unkB1), arg0->position, (((Objweldarboss_func_80803624_chweldarboss_temp_v0 *)temp_v0)->unk6E), D_80804AB4_chweldarboss, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1);
}

void func_8080367C_chweldarboss(Actor *arg0) {
    BT_IDO_ONLY(void func_800D2498(u32 itemDisplayUI, u32 value,u32 a2);) BT_NATIVE_ONLY(s32 func_800D2498(u32, s32, u32);)
    void *func_80100094(Actor *, u32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if (((s32) temp_t6 >= 7) && ((s32) temp_t6 < 0x2D)) {
        func_800D2498(0xFDU, (u32) (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x6F))), 0U);
    }
}    typedef struct { u8 pad0[0x62]; s8 unk62; u8 pad63[0x45]; f32 unkA8; s16 unkAC; } Objweldarboss_func_808036C8_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_808036C8_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _mlwave_entrypoint_0(void *arg0, f32 arg1, f32 arg2);
    void _mlwave_entrypoint_7(void *, f32);
    void func_800BF744(s32, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (((Objweldarboss_func_808036C8_chweldarboss_temp_v0 *)temp_v0)->unk62) = 1;
    (((Objweldarboss_func_808036C8_chweldarboss_temp_v0 *)temp_v0)->unkAC) = 2;
    (((Objweldarboss_func_808036C8_chweldarboss_temp_v0 *)temp_v0)->unkA8) = 10.0f;
    _mlwave_entrypoint_0(temp_v0 + 0x88, 300.0f, 300.0f);
    _mlwave_entrypoint_7(sp1C + 0x88, 0.25f);
    func_800BF744(3, 1);
}    typedef struct { u8 pad0[0xA8]; f32 unkA8; s16 unkAC; } Objweldarboss_func_8080373C_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8080373C_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objweldarboss_func_8080373C_chweldarboss_temp_v0 *)temp_v0)->unkAC) = 4;
    (((Objweldarboss_func_8080373C_chweldarboss_temp_v0 *)temp_v0)->unkA8) = 2.0f;
}

void func_80803770_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800D90A4(f32 *);
    s32 _mlwave_entrypoint_1(u8 *);
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    s32 _mlwave_entrypoint_8(u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800BF744(s32, s32);
    BtIntPtr func_800BEA88(s32);
    s32 func_808038F8_chweldarboss(Actor *);
    s32 _glid_entrypoint_0(BtIntPtr, s32, s32 *, BtIntPtr);
#ifdef BT_NATIVE
    void chweldarboss_entrypoint_2(s32 arg0, s32 arg1, BtUIntPtr arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chweldarboss_entrypoint_2;
#endif
    s32 pad;
    s32 update;
    BtIntPtr timer2;
    s32 timer4;
    u8 *data;

    data = func_80100094(arg0, 0U);
    update = 0;
    switch (*(s16 *)(data + 0xAC)) {
        case 1:
            break;
        case 2:
            timer2 = func_800D90A4((f32 *)(data + 0xA8));
            _mlwave_entrypoint_1(data + 0x88);
            *(s16 *)(data + 0xAE) = (s32)_mlwave_entrypoint_5(data + 0x88, 0, 255.0f);
            if (timer2 && _mlwave_entrypoint_8(data + 0x88, 0.75f)) {
                *(s16 *)(data + 0xAE) = 255;
                *(s16 *)(data + 0xAC) = 3;
            }
            update = 1;
            break;
        case 3:
            if (func_800D90A4((f32 *)(data + 0xA4))) {
                func_808038F8_chweldarboss(arg0);
            }
            break;
        case 4:
            timer4 = func_800D90A4((f32 *)(data + 0xA8));
            *(s16 *)(data + 0xAE) = (s32)func_800F10B4(*(f32 *)(data + 0xA8), 0.0f, 2.0f, 0, 255.0f);
            if (timer4) {
                *(s16 *)(data + 0xAC) = 1;
                func_800BF744(3, 0);
            }
            update = 1;
            break;
    }
    if (update) {
        timer2 = func_800BEA88(0);
        if (timer2) {
            _glid_entrypoint_0(timer2, 1, &_chweldarboss_entrypoint_2, (BtIntPtr)arg0->unk0);
        }
    }
}

s32 func_808038F8_chweldarboss(Actor *arg0) {
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_800F6438(BtUIntPtr);
    int func_800F6AA4(BtIntPtr);
    int func_80803B48_chweldarboss(BtIntPtr);
    s32 func_800F796C(BtIntPtr, s32);
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    s32 pad;
    f32 pos[3];
    f32 x;
    s32 i;
    s32 cell[2];
    int count;
    u8 *data;
    f32 hit[3];

    data = func_80100094(arg0, 0U);
    count = 0;
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i) && func_80803B48_chweldarboss(i) && !func_800F6AA4(i)) {
            func_800F5A00(i, pos);
            if (pos[0] > 0.0f) {
                cell[0] = (s32)(pos[0] / 800.0f);
            } else {
                cell[0] = (s32)(pos[0] / 800.0f + -1.0f);
            }
            if (pos[2] > 0.0f) {
                cell[1] = (s32)(pos[2] / 800.0f);
            } else {
                cell[1] = (s32)(pos[2] / 800.0f + -1.0f);
            }
            x = pos[0] - (f32)(cell[0] * 800);
            if (x < 50.0f || x > 750.0f ||
                pos[2] - (f32)(cell[1] * 800) < 50.0f || pos[2] - (f32)(cell[1] * 800) > 750.0f) {
                func_800F796C(i, 0xD);
                func_800EE7F8(hit, pos);
                hit[1] += 20.0f;
                _chelectricfence_entrypoint_1(arg0, hit);
                count += 1;
                *(f32 *)(data + 0xA4) = 2.0f;
            }
        }
    }
    return count;
}

/* extern */

int func_80803B48_chweldarboss(BtIntPtr arg0) {
    BT_IDO_ONLY(f32 func_800F5628(BtIntPtr);) BT_NATIVE_ONLY(s32 func_800F5628(BtIntPtr);)
    s32 func_800F6478(BtIntPtr);
    s32 func_800F6C5C(BtIntPtr);

    if ((func_800F6478(arg0) == 0) || (func_800F6C5C(arg0) == 0)) {
        return 0;
    }
    return BT_IDO_ONLY(func_800F5628(arg0)) BT_NATIVE_ONLY(((union { s32 i; f32 f; }){ .i = func_800F5628(arg0) }).f) < 50.0f;
}

void chweldarboss_entrypoint_2(s32 arg0, s32 arg1, BtUIntPtr arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor* func_80106790(Unk80132ED0 *);
    BtUIntPtr temp_a0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((s8 *)(func_80100094(func_80106790(arg4), 0U)) + (0xAF)));
    temp_a0 = (arg3 * 0x10) + arg2;
    if (arg2 < temp_a0) {
        do {
            arg2 += 0x10;
            (*(u8 *)((s8 *)(arg2) + (-1))) = temp_v1;
        } while (arg2 < temp_a0);
    }
}

void func_80803C18_chweldarboss(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        u8 padC[0x24];
        u8 unk30[0x50];
        f32 unk80;
        s32 unk84;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    s32 pad34;
    Actor *sp30;
    s32 pad2C;
    s32 sp28;
    WeldarData *data;
    WeldarData *linkedData;

    data = func_80100094(arg0, 0U);
    sp30 = _subaddielink_entrypoint_4(data->unk30);
    data->unk80 += func_800D8FF8() * 22.0f;
    if (sp30 != NULL) {
        linkedData = func_80100094(sp30, 0U);
        if (sp30->unk70_10 == 1) {
            data->unk84 = 5;
            return;
        }
        sp28 = (s32)func_800F10B4(linkedData->unk0[2], 0.0f, 1.0f, 4.0f, 0.0f);
        data->unk84 = (s32)func_800F13C4(data->unk80, 2.0f) + sp28;
    }
}    typedef struct { u8 pad0[0x72]; s16 unk72; } Objweldarboss_func_80803CF0_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x72]; s16 unk72; } Objweldarboss_func_80803CF0_chweldarboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80803CF0_chweldarboss(Actor *arg0, s32 arg1, s32 arg2)
{
  void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
  void _capod_entrypoint_14(void);
  void *func_80100094(Actor *, u32);
  u8 *sp1C;
  u8 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  sp1C = temp_v0;
  arg2 = arg2;
  if ((((Objweldarboss_func_80803CF0_chweldarboss_temp_v0 *)temp_v0)->unk72) != 0)
  {
    _capod_entrypoint_14();
    arg2 = arg2 | 0x2000;
  }
  _capod_entrypoint_13(arg0->unk0, NULL, (u32) arg1, (u32) arg2);
  ((Objweldarboss_func_80803CF0_chweldarboss_sp1C *)sp1C)->unk72 = 1;
}    typedef struct { u8 pad0[0x72]; s16 unk72; } Objweldarboss_func_80803D64_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80803D64_chweldarboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objweldarboss_func_80803D64_chweldarboss_temp_v0 *)temp_v0)->unk72) != 0) {
        (((Objweldarboss_func_80803D64_chweldarboss_temp_v0 *)temp_v0)->unk72) = 0;
        _capod_entrypoint_14();
    }
}

/* extern */

BtIntPtr func_80803D98_chweldarboss(BtIntPtr arg0) {
    u32 func_800F54E4(void);
    BtIntPtr func_8010D290(s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_8010D290(0x10000);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

s32 func_80803DD8_chweldarboss(Actor *arg0) {
    void func_80801AA0_chweldarboss(Actor *, s32);
    s32 result = 0;

    switch (arg0->unk70_10) {
        case 11:
        case 12:
            func_80801AA0_chweldarboss(arg0, 14);
            result = 1;
            break;
        case 22:
        case 23:
            func_80801AA0_chweldarboss(arg0, 25);
            result = 1;
            break;
        case 38:
        case 39:
            func_80801AA0_chweldarboss(arg0, 41);
            result = 1;
            break;
    }
    return result;
}    typedef struct { u8 pad0[0x8]; f32 unk8; } Objweldarboss_func_80803E50_chweldarboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80803E50_chweldarboss(Actor *arg0) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_808041C4_chweldarboss(Actor *, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (((Objweldarboss_func_80803E50_chweldarboss_temp_v0 *)temp_v0)->unk8) = 0.0f;
    func_808041C4_chweldarboss(arg0, 1);
    _subaddielink_entrypoint_1(sp1C, arg0->unk3C);
    arg0->unk3C = NULL;
}

void func_80803EA4_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[8];
        f32 amount;
        s32 light;
    } WeldarLightData;
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    s32 func_800C8FE0(s32, s32);
    void func_800C8E54(s32, f32, f32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_8001210C(s32);
    void func_808041C4_chweldarboss(Actor *, s32);

    WeldarLightData *data;
    s32 light;
    f32 position[3];
    f32 inner;
    f32 outer;
    f32 delta;
    f32 distance;

    data = func_80100094(arg0, 0U);
    light = data->light;
    delta = func_800D8FF8();
    switch (arg0->unk70_10) {
        case 1:
            arg0->unk64_16 = 0;
            break;
        case 2:
            arg0->unk64_16 = 1;
            data->amount = func_800F15F8(data->amount, 1.0f, delta * 1.4f);
            if (data->amount == 1.0f) {
                func_808041C4_chweldarboss(arg0, 3);
            }
            break;
        case 3:
            arg0->unk64_16 = 1;
            break;
        case 4:
            arg0->unk64_16 = 1;
            data->amount = func_800F15F8(data->amount, 0.0f, delta * 1.6f);
            if (data->amount == 0.0f) {
                func_808041C4_chweldarboss(arg0, 1);
            }
            break;
    }
    distance = func_800F12D4(data->amount, 0.0f, 1.0f, 400.0f, 700.0f);
    func_800EE7F8(position, arg0->position);
    func_800EF214(position, 90.0f - arg0->rotation[0], arg0->rotation[1], distance);
    inner = func_800F12D4(data->amount, 0.0f, 1.0f, 200.0f, 600.0f);
    outer = func_800F12D4(data->amount, 0.0f, 1.0f, 400.0f, 1000.0f);
    func_800C8FE0(light, arg0->unk64_16);
    func_800C8E54(light, inner, outer);
    func_800C8CB8(light, position);
    func_800C8E84(light, func_8001210C(1) ? D_80804AC8_chweldarboss : D_80804ABC_chweldarboss);
}

u32 func_808040F4_chweldarboss(BtIntPtr unused, s32 arg1, s32 arg2) {
    void func_80804230_chweldarboss(Actor *);

    if (arg1 == 0x95) {
        func_80804230_chweldarboss((Actor *) unused);
        return 1;
    }
    return 0;
}

void func_8080412C_chweldarboss(Actor *arg0, void *arg1) {
    void func_800DF500(f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101870(Actor *, void *);
    u8 *sp24;
    f32 sp20;
    f32 temp_f0;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    sp20 = func_800F12D4(*(f32 *)(temp_v0 + 8), 0.0f, 1.0f, 0.4f, 1.4f);
    temp_f0 = func_800F12D4(*(f32 *)(sp24 + 8), 0.0f, 1.0f, 0.8f, 1.2f);
    func_800DF500(temp_f0, sp20, temp_f0);
    func_80101870(arg0, arg1);
}

void func_808041C4_chweldarboss(Actor *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);
    switch (arg1) {
        case 2:
            if (arg0->unk70_10 == 3) {
                return;
            }
            break;
        case 4:
            if (arg0->unk70_10 == 1) {
                return;
            }
            break;
    }
    func_80102424(arg0, arg1);
}    typedef struct { u8 pad0[0xC]; s32 unkC; } Objweldarboss_func_80804230_chweldarboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_80804230_chweldarboss(Actor *arg0) {
    s32 func_800C8A98(void);
    s32 func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    u8 *sp1C;
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    _subaddielink_entrypoint_3(temp_v0);
    temp_v0_2 = func_800C8A98();
    (((Objweldarboss_func_80804230_chweldarboss_sp1C *)sp1C)->unkC) = temp_v0_2;
    func_800C8FE0(temp_v0_2, 0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_80804AE0_chweldarboss [ 3 ] BT_DATA(16, bss_ch_weldarboss, 0x0);
#endif
