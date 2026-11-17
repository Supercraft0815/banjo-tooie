#include "common.h"

OSThread *chmricecube_entrypoint_0(void)
{
    extern ActorData D_80800928_chmricecube[];

    return (OSThread *) D_80800928_chmricecube;
}                 typedef struct { u8 pad0[0x2C]; f32 unk2C; u8 pad30[0x18]; f32 unk48; u8 pad4C[0x8]; f32 unk54; u8 pad58[0xC]; s32 unk64; } Objmricecube_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_chmricecube(u8 *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *actor);
    void func_80102424(Actor *actor,s32 state);
    s32 func_8010A5B0(u8 *, s32);
    func_800EE7F8(arg0 + 0x18, arg0 + 4);
    (((Objmricecube_arg0 *)arg0)->unk2C) = 0.0f;
    (((Objmricecube_arg0 *)arg0)->unk54) = (f32) (((Objmricecube_arg0 *)arg0)->unk48);
    func_8010A5B0(arg0, func_800DA298(0x1C9));
    if (_glcutDll_entrypoint_20() != 0) {
        (((Objmricecube_arg0 *)arg0)->unk48) = (f32) ((((Objmricecube_arg0 *)arg0)->unk48) - 180.0f);
        func_80102424(arg0, 6);
        return;
    }
    if (func_800DA298(0x31B) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000AC_chmricecube(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_17(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void func_800C4AF0(f32 *, void *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *arg0);
    void func_800DA544(s32 index);
    void func_800EF1B8(f32 *arg0, f32 arg1, f32 arg2);
    f32 func_800EFC7C(f32 *, f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *actor,s32 state);
    void func_80102FDC(Actor *, f32);
    void func_80800778_chmricecube(BtIntPtr);
    void func_808007B0_chmricecube(Actor *);
    void func_80800850_chmricecube(Actor *);
    extern u32 D_80800970_chmricecube[4];
    extern u32 D_80800980_chmricecube[4];
    extern u32 D_80800990_chmricecube[6];
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;

    switch (arg0->unk70_10) {
    case 1:
        func_80800778_chmricecube((BtIntPtr)arg0);
        return;
    case 2:
        arg0->unk64_19 = 1;
        func_80800850_chmricecube(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80102424((u8 *)arg0, 3);
            return;
        }
    default:
        return;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            arg0->unk64_19 = 0;
            func_80102424((u8 *)arg0, 1);
            return;
        }
        break;
    case 5:
        sp3C = func_800D8FF8();
        *(f32 *)&arg0->actorData[3] = func_800F15F8(*(f32 *)&arg0->actorData[3], 200.0f, sp3C * 150.0f);
        func_800EF1B8(arg0->position, arg0->unk54, -(*(f32 *)&arg0->actorData[3] * sp3C));
        arg0->unk64_19 = 1;
        *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 100.0f, sp3C * 120.0f);
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp3C;
        if (func_800EFC7C(arg0->position, (f32 *)arg0->actorData) > 160000.0f) {
            if (!arg0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800970_chmricecube);
                arg0->unk64_20 = 1;
            }
            *(f32 *)&arg0->actorData[5] += sp3C * 800.0f;
            arg0->position[1] -= sp3C * *(f32 *)&arg0->actorData[5];
            if (arg0->position[1] < (*(f32 *)&arg0->actorData[1] - 8000.0f)) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x127, 0x49);
                return;
            }
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800980_chmricecube);
            return;
        }
        break;
    case 8:
        sp38 = func_800D8FF8();
        *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 100.0f, sp38 * 120.0f);
        *(f32 *)&arg0->actorData[5] += sp38 * 800.0f;
        arg0->position[1] -= sp38 * *(f32 *)&arg0->actorData[5];
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp38;
        if (arg0->position[1] < 600.0f) {
            arg0->position[1] = 600.0f;
            func_800C4AF0(arg0->position, D_80800990_chmricecube);
            func_80102424((u8 *)arg0, 9);
            arg0->unk58 = 4.0f;
            func_80101180(0x439, 0xA, 0x3E7);
            return;
        }
        break;
    case 9:
        sp34 = func_800D9078(&arg0->unk58);
        sp30 = func_800D8FF8();
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 4.0f, 400.0f, 600.0f);
        func_80102FDC(arg0, func_800F12D4(arg0->unk58, 0.0f, 4.0f, 0.5f, 1.0f));
        _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0.0f, 4.0f, 0, 255.0f));
        if (arg0->unk58 > 1.0f) {
            *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 0.0f, sp30 * 40.0f);
            func_808007B0_chmricecube(arg0);
        }
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp30;
        if (sp34 != 0) {
            func_800DA544(0x31B);
            _glcutDll_entrypoint_17();
            return;
        }
        break;
    case 6:
        func_80800850_chmricecube(arg0);
        arg0->unk64_19 = 1;
        if (func_80101DDC(arg0) != 0) {
            func_80102424((u8 *)arg0, 7);
        }
        break;
    }
}

s32 func_8080050C_chmricecube(Actor *arg0, s32 arg1, void *arg2) {
    extern s32 D_808008B0_chmricecube[10];
    extern s32 D_808009A8_chmricecube[4];
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    s32 _glcutDll_entrypoint_19(u32);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    u8 _subaddiedialog_entrypoint_9(void *arg0, s32 arg1, void *arg2, s32 arg3);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *arg0, f32 arg1, f32 arg2);
    void func_800F77E8(BtIntPtr, f32 *);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *actor);
    void func_80102424(Actor *actor,s32 state);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010A624(Actor *);
    s32 dialog;
    f32 sp38[3];
    Unk80132ED0 *sp34;

    switch (arg1) {
    case 0x2E:
        dialog = *(s16 *)&arg2;
        if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, dialog, D_808008B0_chmricecube, 5) == 1) {
            func_8010A590(arg0);
        }
        if (arg0->unk70_10 == 3 || arg0->unk70_10 == 2) {
            func_80102424(arg0, 4);
        }
        break;
    case 0x40:
        sp34 = arg2;
        func_8010A624(arg0);
        func_800EE7F8(sp38, arg0->position);
        func_800EF1B8(sp38, arg0->rotation[1], 300.0f);
        func_800F77E8((u32)(u16)sp34->unk18 >> 5, sp38);
        _capod_entrypoint_13(arg0->unk0, 0, 0, 0x831);
        func_80102424(arg0, 5);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_8010A570(arg0);
        func_800FC660(0xE);
        break;
    case 0x49:
        if (func_800EA05C() == 0x127 && _glcutDll_entrypoint_19(0x49) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x13CC, 4, 0, 0xA9);
            func_80102424(arg0, 8);
            _subaddieDll_entrypoint_4(arg0, 1);
            *(f32 *)&arg0->actorData[6] = 100.0f;
            *(f32 *)&arg0->actorData[5] = 1200.0f;
            _capod_entrypoint_13(arg0->unk0, 0, 0x13, 0x2831);
            break;
        }
        return 0;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808009A8_chmricecube, arg0->scale);
        break;
    case 0x95:
        if (func_800EA05C() == 0x127 && _glcutDll_entrypoint_19(0x49) == 0) {
            func_800FFAB0(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800734_chmricecube(void *arg0, BtIntPtr arg1) {
    void func_800DF744(s32 index,s32 value);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, (u32) ((((Objmricecube_arg0 *)arg0)->unk64) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}

void func_80800778_chmricecube(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    extern s32 D_808008B0_chmricecube[10];
    extern s32 D_808009B8_chmricecube[4];
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, D_808009B8_chmricecube, D_808008B0_chmricecube, 5);
}

void func_808007B0_chmricecube(Actor *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808009C8_chmricecube[14];
    f32 sp34[3];
    f32 sp28[3];

    if (func_800D90A4((f32 *)arg0->actorData + 4) != 0) {
        func_800EE7F8(sp34, arg0->position);
        sp34[1] = 200.0f;
        func_800EE7F8(sp28, arg0->position);
        sp28[1] = 600.0f;
        func_800BBCB8(sp28, sp34, arg0->scale, 5, D_808009C8_chmricecube);
        ((f32 *)arg0->actorData)[4] = func_800DC178(0.1f, 0.15f);
    }
}

void func_80800850_chmricecube(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_80800A00_chmricecube[4];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800A00_chmricecube, 0.1f);
}
/* data_to_c.py: from asm/data/overlays/ch/mricecube.data.s */
extern u8 D_808008D8_chmricecube[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808008B0_chmricecube[10] BT_DATA(4, overlays_ch_mricecube, 0x0) = { 1, 332005632, 1537, 332071424, 512, 340918528, 1024, 340984064, -73729, 302711552 };
u8 D_808008D8_chmricecube[80] BT_DATA(4, overlays_ch_mricecube, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA8, 0x00, 0x44, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA8, 0x00, 0x02, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA9, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA8, 0x00, 0x92, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA8, 0x00, 0x02, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA8, 0x00, 0x02, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA9, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA9, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0xA9, 0x00, 0x01 };
ActorData D_80800928_chmricecube [1] BT_DATA(4, overlays_ch_mricecube, 0x78) = { { 174, 999, 2325, 1, (void *)D_808008D8_chmricecube, (void (*)(struct Actor *))func_808000AC_chmricecube, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800734_chmricecube, 131072000, 0, 0, 0, 2, 2308, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chmricecube, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_8080050C_chmricecube, 0 } };
u32 D_80800970_chmricecube[4] BT_DATA(4, overlays_ch_mricecube, 0xC0) = { 0x130446, 0xA0199, 0x20018, 0 };
u32 D_80800980_chmricecube[4] BT_DATA(4, overlays_ch_mricecube, 0xD0) = { 0x130410, 0xA0133, 0x20018, 0 };
u32 D_80800990_chmricecube[6] BT_DATA(4, overlays_ch_mricecube, 0xE0) = { 0x1304DC, 0xA014C, 0x180015, 0x400, 0x660002, 0 };
s32 D_808009A8_chmricecube[4] BT_DATA(4, overlays_ch_mricecube, 0xF8) = { 1139802112, 1133903872, 1133379584, 1123024896 };
s32 D_808009B8_chmricecube[4] BT_DATA(4, overlays_ch_mricecube, 0x108) = { 29949952, 26214569, 12, 512 };
s32 D_808009C8_chmricecube[14] BT_DATA(4, overlays_ch_mricecube, 0x118) = { 1903069, 1442304, 2949520, 39321611, 15728890, 0, 2228377, 16777984, 58720277, 179, 2818176, 10027038, 6553700, 0 };
u32 D_80800A00_chmricecube[4] BT_DATA(4, overlays_ch_mricecube, 0x150) = { 0x13047F, 0xD00F3, 0x10C0000, 0 };
