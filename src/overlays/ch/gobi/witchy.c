#include "common.h"

OSThread *chgobiwitchy_entrypoint_0(void)
{
    extern ActorData D_80800410_chgobiwitchy[];

    return (OSThread *) D_80800410_chgobiwitchy;
}

void func_8080000C_chgobiwitchy(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    s32 _chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3);
    void _chgobicommon_entrypoint_0(Actor *);
    u32 _gclevel_entrypoint_3(u32);
    void _glcutDll_entrypoint_6(u32, u32);
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    BtIntPtr _suexpression_entrypoint_20();
    s32 func_8008FB10(BtIntPtr, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_808002DC_chgobiwitchy(Actor *);

    _suexpression_entrypoint_10(_suexpression_entrypoint_20(), arg0->unk0, 0);
    _chgobicommon_entrypoint_0(arg0);
    func_8008FB10(arg0->position, 240.0f, 0.0f, 150.0f);
    switch (arg0->unk70_10) {
        case 2:
            break;
        case 1:
            func_808002DC_chgobiwitchy(arg0);
            break;
        case 4:
            func_80105834(arg0);
            if (func_80105A5C(arg0)) {
                func_800FFAB0(arg0);
                _capod_entrypoint_14();
                if (_gclevel_entrypoint_3(0x17)) {
                    _glcutDll_entrypoint_6(0x127, 0x47);
                }
            }
            break;
    }
    _chbadshad_entrypoint_2(arg0, 1, arg0->scale * 2.4f, 0);
}

s32 func_80800104_chgobiwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void _suexpression_entrypoint_14(void *, f32, f32);
    void func_8080024C_chgobiwitchy(Actor *, s32, s32);
    extern u32 D_80800458_chgobiwitchy[4];
    void *expression;

    switch (arg1) {
        case 0x2E:
            func_8080024C_chgobiwitchy(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800458_chgobiwitchy, arg0->scale);
            break;
        case 0x95:
            expression = _suexpression_entrypoint_7(arg0, 1, 0x38);
            _suexpression_entrypoint_12(expression, 40.0f, 60.0f);
            _suexpression_entrypoint_14(expression, 1.0f, 1.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808001C8_chgobiwitchy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
/* extern */

void func_808001E8_chgobiwitchy(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    if (func_800DA298(0x97) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_80105A9C(arg0, 500.0f);
    func_80102FDC(arg0, 0.25f);
    ((struct { u8 pad; BT_BITFIELD_ORDER(u8 : 7, u8 flag : 1); BT_BITFIELD_ORDER(u8 flag : 1, u8  : 7); } *)&arg0->pad94)->flag = 1;
}

/* extern */

void func_8080024C_chgobiwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_22();
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    _capod_entrypoint_22();
    if (arg1 == 0x107B) {
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 0.0f, 0.0f);
        func_80101FDC(arg0, 4);
        _capod_entrypoint_13(arg0->unk0, 0, 1, 0x2031);
        return;
    }
    func_80101FDC(arg0, 1);
}

void func_808002DC_chgobiwitchy(Actor *arg0) { s32 _capod_entrypoint_21(Unk80132ED0 *, BtIntPtr, s32, s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, s32 *, s32 *, s32);
    s32 func_800DA298(s32);
    void func_800DA524(GameFlag);
    int func_800DB9B0(void);
    u32 func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_808003C0_chgobiwitchy[10];
    extern s32 D_80800468_chgobiwitchy[6];
    s32 var_v1;

    var_v1 = 0;
    if (func_800DA298(0x97) != 0) {
        if (func_800DB9B0() == 0) {
            func_800F82D4(func_800F54E4(), 0);
            func_800DA524(0x87);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x107B, 0xE, 0, 0x38);
            func_80101FDC(arg0, 3);
            var_v1 = 1;
        }
    } else {
        var_v1 = _subaddiedialog_entrypoint_8(arg0, arg0->position, D_80800468_chgobiwitchy, D_808003C0_chgobiwitchy, 5);
    }
    if (var_v1 != 0) {
        _capod_entrypoint_21(arg0->unk0, 0, 0xA, 0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/gobi/witchy.data.s */
extern u8 D_808003E8_chgobiwitchy[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_808003C0_chgobiwitchy[10] BT_DATA(4, overlays_ch_gobi_witchy, 0x0) = { 1, 276365568, 1537, 276431360, 512, 286654720, 1024, 286720256, -73729, 302711552 };
u8 D_808003E8_chgobiwitchy[40] BT_DATA(4, overlays_ch_gobi_witchy, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x3C, 0xCC, 0xCD, 0x02, 0x21, 0x00, 0x00, 0x41, 0x3C, 0xCC, 0xCD, 0x02, 0x21, 0x00, 0x00, 0x40, 0x90, 0x00, 0x00, 0x02, 0x22, 0x00, 0x00, 0x3F, 0x07, 0xAE, 0x14, 0x02, 0x23, 0x00, 0x00 };
ActorData D_80800410_chgobiwitchy [1] BT_DATA(4, overlays_ch_gobi_witchy, 0x50) = { { 392, 311, 1928, 1, (void *)D_808003E8_chgobiwitchy, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_8080000C_chgobiwitchy, (void (*)(long, long))func_80101870, 0, 1092196762, 0, 0, 16388, 296, (void (*)(struct Actor *))func_808001C8_chgobiwitchy, 0, 0, 0, (void (*)(struct Actor *))func_808001E8_chgobiwitchy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1042, (void (*)(struct Actor *, long, long))func_80800104_chgobiwitchy, 0 } };
u32 D_80800458_chgobiwitchy[4] BT_DATA(4, overlays_ch_gobi_witchy, 0x98) = { 0x43160000, 0x43FA0000, 0x438C0000, 0x42F00000 };
s32 D_80800468_chgobiwitchy[6] BT_DATA(4, overlays_ch_gobi_witchy, 0xA8) = { 8847360, 39321656, 14, 512, 0, 0 };
