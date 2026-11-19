#include "common.h"

OSThread *chbilldrillboulder_entrypoint_0(void)
{
    extern ActorData D_80800540_chbilldrillboulder[];

    return (OSThread *) D_80800540_chbilldrillboulder;
}

OSThread *chbilldrillboulder_entrypoint_1(void)
{
    extern ActorData D_80800588_chbilldrillboulder[];

    return (OSThread *) D_80800588_chbilldrillboulder;
}

OSThread *chbilldrillboulder_entrypoint_2(void)
{
    extern ActorData D_808005D0_chbilldrillboulder[];

    return (OSThread *) D_808005D0_chbilldrillboulder;
}

void func_80800024_chbilldrillboulder(Actor *arg0) {
    s32 func_808004D4_chbilldrillboulder(void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F77E8(BtIntPtr, f32 *);
    s32 func_800F7F98(BtIntPtr, u32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    s32 _capod_entrypoint_21(Unk80132ED0 *, BtIntPtr, s32, s32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    f32 func_80103EF4(Actor *);
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    extern s32 _chbaddiesetup_entrypoint_9;
    extern s32 D_80800618_chbilldrillboulder[];
    extern s32 D_80800684_chbilldrillboulder[];
    extern s32 D_808006F0_chbilldrillboulder[];
    s32 flag;
    s32 isSmall;
    s32 pad;
    f32 position[3];
    s32 type;
    f32 spawnPosition[3];

    flag = func_808004D4_chbilldrillboulder(arg0);
    isSmall = arg0->unk6C_9 == 0x322;
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale,
        isSmall ? D_80800684_chbilldrillboulder : D_80800618_chbilldrillboulder);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808006F0_chbilldrillboulder);
    if (flag != 0) {
        func_800DA544(flag);
        if (flag == 0x514) {
            if (arg0->unk64_20) {
                func_800EE7F8(position, arg0->position);
                func_800EF1B8(position, arg0->rotation[1] - 70.0f, 450.0f);
                func_800F77E8(func_800F54E4(), position);
            }
            func_800F7F98(func_800F54E4(), 1);
            _capod_entrypoint_21(_subaddiefind_entrypoint_2(0x117, 0)->unk0, 0, 0x1D, 0);
            func_800DA544(0x5B);
        }
    }
    if (arg0->unk6C_9 == 0x3CF) {
        type = -1;
        switch (arg0->unk74_7) {
            case 0x33:
                func_800D1000(arg0->unk6C_0, 4, arg0->position, 0, 0);
                break;
            case 0x34: type = 2; break;
            case 0x35: type = 0x15; break;
            case 0x36: type = 0x16; break;
            case 0x37: type = 0x17; break;
            case 0x38:
                func_800D1000(arg0->unk6C_0, 2, arg0->position, 0, 0);
                break;
        }
        if (type != -1) {
            func_800EE7F8(spawnPosition, arg0->position);
            spawnPosition[1] += 0.5f * func_80103EF4(arg0);
            _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_9, type,
                ((s32 *)spawnPosition)[0], ((s32 *)spawnPosition)[1], ((s32 *)spawnPosition)[2]);
        }
    }
}

void func_8080026C_chbilldrillboulder(Actor *arg0)
{
  void _chexploder_entrypoint_3(void *, void *, u32);
  f32 *new_var;
  s32 _subaddieDll_entrypoint_6(Actor *, s32);
  void func_8010A570(Actor *);
 if ((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) { new_var = arg0->position; func_8010A570(arg0);
    _chexploder_entrypoint_3(arg0, new_var, 2U);
  }
}

void func_808002C4_chbilldrillboulder(Actor *arg0) {
    s32 func_808004D4_chbilldrillboulder(void *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 func_800D0A9C(u32, u32);
    s32 flag;

    flag = func_808004D4_chbilldrillboulder(arg0);
    if (flag != 0 && func_800DA298(flag) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (arg0->unk6C_9 == 0x3CF) {
        switch (arg0->unk74_7 - 0x32) {
        case 1:
            arg0->unk6C_0 = _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x201, arg0));
            if (func_800D0A9C(arg0->unk6C_0, 4) != 0) {
                func_800FFAB0(arg0);
                return;
            }
            break;
        case 6:
            arg0->unk6C_0 = _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x1F7, arg0));
            if (func_800D0A9C(arg0->unk6C_0, 2) != 0) {
                func_800FFAB0(arg0);
            }
            break;
        }
    }
}

s32 func_808003F0_chbilldrillboulder(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _subaddieDll_entrypoint_5(Actor *arg0, Unk80132ED0 *arg1);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void func_80800024_chbilldrillboulder(Actor *);
    BtIntPtr temp;

    switch (arg1) {
    case 0x3F:
        temp = arg2;
        if (arg0->unk70_10 != 2 && _subaddieDll_entrypoint_5(arg0, temp) != 0) {
            arg0->unk64_20 = 1;
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
        }
        break;
    case 0x40:
        func_8010A570(arg0);
        _chexploder_entrypoint_3(arg0, arg0->position, 2);
        break;
    case 0x90:
        func_80800024_chbilldrillboulder(arg0);
        func_800FFAB0(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808004D4_chbilldrillboulder(void *arg0) {
    s32 temp_v1;

    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14) == 0x3CF) {
        return 0;
    }
    temp_v1 = ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x33;
    if ((temp_v1 < 0) || (temp_v1 >= 0x1E)) {
        return 0;
    }
    return temp_v1 + 0x514;
}
/* data_to_c.py: from asm/data/overlays/ch/billdrillboulder.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800540_chbilldrillboulder [1] BT_DATA(4, overlays_ch_billdrillboulder, 0x0) = { { 343, 271, 1666, 1, 0, (void (*)(struct Actor *))func_8080026C_chbilldrillboulder, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808002C4_chbilldrillboulder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_808003F0_chbilldrillboulder, 0 } };
ActorData D_80800588_chbilldrillboulder [1] BT_DATA(4, overlays_ch_billdrillboulder, 0x48) = { { 343, 802, 1939, 1, 0, (void (*)(struct Actor *))func_8080026C_chbilldrillboulder, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808002C4_chbilldrillboulder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_808003F0_chbilldrillboulder, 0 } };
ActorData D_808005D0_chbilldrillboulder [1] BT_DATA(4, overlays_ch_billdrillboulder, 0x90) = { { 343, 975, 1666, 1, 0, (void (*)(struct Actor *))func_8080026C_chbilldrillboulder, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808002C4_chbilldrillboulder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_808003F0_chbilldrillboulder, 0 } };
s32 D_80800618_chbilldrillboulder [27] BT_DATA(4, overlays_ch_billdrillboulder, 0xD8) = { 68157469, 165478443, 46924646, 1376256, 10027042, 25166336, 75499008, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 68816656, 1902240, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4919066, 0 };
s32 D_80800684_chbilldrillboulder [27] BT_DATA(4, overlays_ch_billdrillboulder, 0x144) = { 68157469, 165478443, 46924646, 1376256, 10027042, 25166336, 75499008, 1638400, 458797, 3276900, 2146496, -1065353206, -6553575, -6553500, 4915300, 68816656, 1902169, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4919066, 0 };
s32 D_808006F0_chbilldrillboulder [8] BT_DATA(4, overlays_ch_billdrillboulder, 0x1B0) = { 1246227, 655590, 1469792, 66786, 163840000, 0, 0, 0 };
