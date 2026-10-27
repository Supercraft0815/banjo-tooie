#include "common.h"

s32 func_80800000_chfaircoinbox(u8 *arg0) {
    struct CoinboxData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };
    extern s16 D_80800488_chfaircoinbox[3];
    return D_80800488_chfaircoinbox[((struct CoinboxData *)arg0)->index - 0x32];
}

void func_8080001C_chfaircoinbox(u8 *arg0) {
    struct CoinboxData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };
    s32 func_800DA544(s32);
    extern s32 D_80800470_chfaircoinbox[3][2];
    func_800DA544(D_80800470_chfaircoinbox[((struct CoinboxData *)arg0)->index - 0x32][1]);
}

s32 func_80800050_chfaircoinbox(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    extern s32 D_80800470_chfaircoinbox[][2];
    s32 index;
    index = ((Actor *)arg0)->unk74_7 - 0x32;
    arg0 = (s32)D_80800470_chfaircoinbox[index];
    if (func_800DA298(((s32 *)arg0)[1]) != 0) {
        func_800DA544(((s32 *)arg0)[0]);
    }
    return ((s32 *)arg0)[0];
}

void func_808000A4_chfaircoinbox(Actor *arg0, u32 arg1) {
    void func_800904F4(s32, Unk80132ED0 *);
    void func_80090708(s32);
    void func_800C01A8(s16, s32);
    void func_800FC660(u32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    s32 index;

    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            func_800904F4(0x46, arg0->unk0);
            break;
        case 3:
            func_800C01A8(0x64, 0);
            func_8080001C_chfaircoinbox((u8 *)arg0);
            func_80090708(0);
            func_800FC660(0x10);
            index = arg0->unk74_7 - 0x32;
            switch (index) {
                case 0:
                    func_80101180(0x340, 0xA, 0);
                    break;
                case 1:
                    func_80101180(0x307, 0xA, 0);
                    break;
            }
            break;
    }
}

void func_8080016C_chfaircoinbox(s32 arg0) 
{
}
/* extern */

void func_80800174_chfaircoinbox(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_8010A63C();
    s32 func_80800050_chfaircoinbox(s32);
    void func_808000A4_chfaircoinbox(Actor *, u32);
    func_8010A63C();
    if (func_800DA298(func_80800050_chfaircoinbox(arg0)) != 0) {
        func_808000A4_chfaircoinbox((Actor *)arg0, 4);
        return;
    }
    func_808000A4_chfaircoinbox((Actor *)arg0, 1);
}

void func_808001C8_chfaircoinbox(Actor *arg0) {
    s32 func_8008FB10(s32, f32, f32, f32);
    s32 func_800DA298(GameFlag);
    void func_808002CC_chfaircoinbox(Actor *);

    func_8008FB10((s32)arg0->position, 120.0f, 0.0f, 92.0f);
    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(func_80800050_chfaircoinbox((s32)arg0)) != 0) {
                func_808000A4_chfaircoinbox(arg0, 3);
                return;
            }
            func_808002CC_chfaircoinbox(arg0);
        case 2:
        case 3:
        case 4:
            return;
    }
}

void func_80800264_chfaircoinbox(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090708(s32);
    switch (arg1) {
    case 0x10B4:
        func_80090708(0);
        return;
    case 0x10B5:
    case 0x10B6:
    case 0x10B7:
        func_808000A4_chfaircoinbox(arg0, 2U);
        return;
    case 0x10B8:
        func_808000A4_chfaircoinbox(arg0, 3U);
    default:
        return;
    }
}

void func_808002CC_chfaircoinbox(Actor *arg0) {
    typedef struct {
        u16 unk0;
        u16 unk2;
        u16 unk4;
        u16 unk6;
        u32 unk8;
        u16 unkC;
        u16 unkE;
        s16 unk10;
        u16 unk12;
        u16 unk14;
        u8 unk16;
        u8 unk17;
        u8 unk18;
    } DialogRecord;
    u32 _subaddiedialog_entrypoint_7(Actor *, f32 *, DialogRecord *);
    void func_80090734(s32, f32 *);
    s32 func_800DA298(GameFlag);
    extern DialogRecord D_80800490_chfaircoinbox;
    extern s32 D_808004AC_chfaircoinbox[];
    u32 result;

    D_80800490_chfaircoinbox.unk4 = D_808004AC_chfaircoinbox[arg0->unk74_7 - 0x32];
    result = func_80800000_chfaircoinbox((u8 *)arg0);
    D_80800490_chfaircoinbox.unk0 = result;
    if (!func_800DA298((u16)result)) {
        if ((result = _subaddiedialog_entrypoint_7(arg0, arg0->position, &D_80800490_chfaircoinbox)) != 0) {
            /* Preserve IDO's redundant comparison; both paths play the sound. */
            if (result == 0x10B5) {
            } else {
                if ((result && result) && result) {
                }
            }
            func_80090734(1, arg0->position);
        }
    }
}

/* extern */

s32 chfaircoinbox_entrypoint_0(Unk80132ED0 *arg0, f32 *arg1) {
    s32 func_800EE7F8(s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    func_800EE7F8((s32) arg1, (s32) ((u8 *) func_80106790(arg0) + 4));
    return 1;
}

/* extern */
void chfaircoinbox_entrypoint_1(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *actor;

    actor = func_80106790(arg0);
    _subaddiedialog_entrypoint_11((Unk80132ED0 *) actor->unk0, 0x10B8, 4, (f32 *) ((u8 *) actor + 4), 0x8C);
}

s32 func_808003C4_chfaircoinbox(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    extern u32 D_808004B8_chfaircoinbox;
    s16 *data = (s16 *)&arg2;
    switch (arg1) {
        case 0x2E:
            func_80800264_chfaircoinbox(arg0, data[0], data[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_808004B8_chfaircoinbox, arg0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chfaircoinbox_entrypoint_2(void)
{
    extern u8 D_808004C8_chfaircoinbox[];

    return (OSThread *) D_808004C8_chfaircoinbox;
}
