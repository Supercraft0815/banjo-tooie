#include "common.h"

OSThread *chgameselect_entrypoint_0(void)
{
    extern u8 D_80807FD8_chgameselect[];

    return (OSThread *) D_80807FD8_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080000C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080015C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800228_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800440_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800478_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808005D4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808006A0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080086C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808008D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800944_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800998_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808009EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800A4C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800A9C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800AEC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800CA0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800D3C_chgameselect.s")

OSThread *chgameselect_entrypoint_1(void)
{
    extern u8 D_80808038_chgameselect[];

    return (OSThread *) D_80808038_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800D74_chgameselect.s")

void func_80800E24_chgameselect(void *arg0) {
    typedef struct {
        u8 pad0[0x34];
        f32 fade;
        u8 pad38[4];
        s32 handle;
        u8 pad40[0x18];
        f32 timer;
        u8 pad5C[8];
        u32 pad64 : 11;
        u32 flag20 : 1;
        u32 flag19 : 1;
        u32 pad64low : 19;
        u32 pad68;
        u32 pad6C : 23;
        u32 state : 9;
        u8 pad70[9];
        u8 selection : 4;
        u8 pad79 : 4;
        u8 pad7A[2];
        u32 pad7C : 19;
        u32 flag12 : 1;
        u32 pad7Clow : 12;
    } SelectActor;
    typedef struct {
        u8 pad0[0x60];
        f32 entries[8][3];
        u8 enabled[8];
    } SelectData;
    void func_80016068(u32, f32 *);
    s32 func_80016B30(s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80800D3C_chgameselect(s32);
    void func_80801338_chgameselect(void *, s32);
    void func_808013C8_chgameselect(void *, s32);
    s32 func_808014F0_chgameselect(void *, void *);
    f32 mlAbsF(f32);
    SelectData *data;
    f32 delta;
    f32 vertical;
    f32 horizontal;
    f32 magnitude;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    if (func_80800D3C_chgameselect(((SelectActor *)arg0)->handle)) {
        if (((SelectActor *)arg0)->timer >= 0.0f) {
            ((SelectActor *)arg0)->timer -= delta;
        }
        if (!((SelectActor *)arg0)->flag19 && ((SelectActor *)arg0)->timer <= 0.0f) {
            func_80016068(0, &horizontal);
            magnitude = mlAbsF(horizontal);
            if (mlAbsF(vertical) < magnitude) {
                vertical = 0.0f;
            } else {
                horizontal = 0.0f;
            }
            if (horizontal < -0.1f && (((SelectActor *)arg0)->selection & 3)) {
                func_80801338_chgameselect(arg0, -1);
            } else if (horizontal > 0.1f && (((SelectActor *)arg0)->selection & 3) != 3) {
                func_80801338_chgameselect(arg0, 1);
            }
            if (vertical < -0.1f && (((SelectActor *)arg0)->selection & 4) != 4) {
                func_808013C8_chgameselect(arg0, ((SelectActor *)arg0)->selection + 4);
            } else if (vertical > 0.1f && (((SelectActor *)arg0)->selection & 4)) {
                func_808013C8_chgameselect(arg0, ((SelectActor *)arg0)->selection - 4);
            }
        }
        if (func_800DA298(0x64A)) {
            if (func_80016B30(0, 1) == 1) {
                func_8010114C(((SelectActor *)arg0)->handle, 8, ((SelectActor *)arg0)->selection);
            } else if (func_80016B30(0, 0) == 1) {
                func_8010114C(((SelectActor *)arg0)->handle, 7, ((SelectActor *)arg0)->selection);
            }
        }
        if (((SelectActor *)arg0)->state == 1 && ((SelectActor *)arg0)->flag12) {
            if (data->enabled[((SelectActor *)arg0)->selection] &&
                func_808014F0_chgameselect(arg0, data->entries[((SelectActor *)arg0)->selection])) {
                ((SelectActor *)arg0)->timer = 0.0f;
            }
        }
        if (((SelectActor *)arg0)->flag19 && !((SelectActor *)arg0)->flag20) {
            if (((SelectActor *)arg0)->fade > 0.0f) {
                delta = func_800D8FF8();
                ((SelectActor *)arg0)->fade = ((SelectActor *)arg0)->fade - 1 * delta;
                if (((SelectActor *)arg0)->fade < 0.0f) {
                    ((SelectActor *)arg0)->fade = 0.0f;
                }
            }
        } else if (((SelectActor *)arg0)->fade < 1.0f) {
            delta = func_800D8FF8();
            ((SelectActor *)arg0)->fade = ((SelectActor *)arg0)->fade + 1 * delta;
            if (((SelectActor *)arg0)->fade > 1.0f) {
                ((SelectActor *)arg0)->fade = 1.0f;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808011B4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808012E4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801338_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808013C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080145C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808014F0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808015DC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801658_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808016A0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808016E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801714_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801758_chgameselect.s")

OSThread *chgameselect_entrypoint_2(void)
{
    extern u8 D_808080C8_chgameselect[];

    return (OSThread *) D_808080C8_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080179C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801AC4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801BA8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801D74_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802070_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808020CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080218C_chgameselect.s")

OSThread *chgameselect_entrypoint_3(void)
{
    extern u8 D_80808298_chgameselect[];

    return (OSThread *) D_80808298_chgameselect;
}

OSThread *chgameselect_entrypoint_4(void)
{
    extern u8 D_808082E0_chgameselect[];

    return (OSThread *) D_808082E0_chgameselect;
}

/* extern */

void func_808021E4_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_19(s32);
    s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
    s32 heap_alloc(s32);
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0xC8, 0xC, 2, 0, 0);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    _gczoombox_entrypoint_19(temp_v0);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = heap_alloc(0x40);
    (*(s32 *)((s8 *)(arg0) + (0x34))) = heap_alloc(0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802248_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802480_chgameselect.s")

/* extern */

void func_808024D4_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_11(s32);
    s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
    s32 _gczoombox_entrypoint_9(s32);
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0x1C, 0xD, 2, 1, 0);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    _gczoombox_entrypoint_9(temp_v0);
    _gczoombox_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0x28))));
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = -1;
}

/* extern */

void func_80802530_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_3(s32, void *);
    s32 _gczoombox_entrypoint_4(s32, void *);
    s32 func_80800CA0_chgameselect(s32, void *);
    s32 temp_v0;

    _gczoombox_entrypoint_4((*(s32 *)((s8 *)(arg0) + (0x28))), arg0);
    temp_v0 = _gczoombox_entrypoint_3((*(s32 *)((s8 *)(arg0) + (0x28))), arg0);
    if (temp_v0 != (*(s32 *)((s8 *)(arg0) + (0x20)))) {
        (*(s32 *)((s8 *)(arg0) + (0x20))) = temp_v0;
        if (temp_v0 == 3) {
            func_80800CA0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x3C))), arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802588_chgameselect.s")

/* extern */

void func_808025CC_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_2(s32);
    _gczoombox_entrypoint_2((*(s32 *)((s8 *)(arg0) + (0x28))));
}

s32 func_808025EC_chgameselect(void *arg0, s32 arg1, s32 arg2) {
    struct Fields {
        u8 pad[0x79];
        u8 high : 4;
        u8 low : 4;
    };
    s32 result = 1;
    if (arg1 == 0xA) {
        ((struct Fields *)arg0)->high = arg2;
    } else {
        return 0;
    }
    return result;
}

/* extern */

void func_80802620_chgameselect(void *arg0) {
    s32 _gczoombox_entrypoint_0(s32);
    _gczoombox_entrypoint_0((*(s32 *)((s8 *)(arg0) + (0x28))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802640_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808026C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802730_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802780_chgameselect.s")

OSThread *chgameselect_entrypoint_5(void)
{
    extern u8 D_80808328_chgameselect[];

    return (OSThread *) D_80808328_chgameselect;
}

void func_808027D4_chgameselect(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808027DC_chgameselect.s")

/* extern */

void func_80802994_chgameselect(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _gcnewoption_entrypoint_1(u8 *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_1(func_80100094(arg0, 0U), arg1);
    }
}

/* extern */

void func_808029D8_chgameselect(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _gcnewoption_entrypoint_6(Actor *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802A0C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802AD4_chgameselect.s")

void func_80802BE8_chgameselect()
{
    func_808029D8_chgameselect(func_80106790());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C10_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C48_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C7C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802CC0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802D04_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802D40_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802DB4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802E38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802F8C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802FE4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803048_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808030EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808031F4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803248_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808032CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803420_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808034BC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803604_chgameselect.s")

void func_80803638_chgameselect()
{
    _glsavegame_entrypoint_0();
}

void func_80803658_chgameselect()
{
    _glsavegame_entrypoint_9();
}

void func_80803678_chgameselect()
{
    func_800D37C0();
}

void func_80803698_chgameselect()
{
    _glsavegame_entrypoint_10();
}

void func_808036B8_chgameselect()
{
    func_800D37D4();
}

void func_808036D8_chgameselect()
{
    _glsavegame_entrypoint_1();
}

void func_808036F8_chgameselect()
{
    _glsavegame_entrypoint_2();
}

void func_80803718_chgameselect()
{
    _glsavegame_entrypoint_3();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803738_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808037C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803888_chgameselect.s")

void func_808038EC_chgameselect(s32 arg0, u32 arg1, u32 arg2) {
    void func_800C9E20(f32 timerLength, u32* callback, u32 callbackArg0, u32 callbackArg1);
    s32 func_80016BDC(s32);
    s32 func_80800478_chgameselect(s32, s32);
    extern u32 _gcfrontend_entrypoint_7;
    func_80016BDC(1);
    func_800C9E20(1.5f, &_gcfrontend_entrypoint_7, arg1, arg2);
    func_80800478_chgameselect(arg0, 8);
}

s32 func_80803940_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_6(s32, s32);
    _gcstatusDll_entrypoint_6(0, 0);
    _gcstatusDll_entrypoint_6(1, 1);
    _gcstatusDll_entrypoint_6(2, 2);
    return _gcstatusDll_entrypoint_6(3, 3);
}

s32 func_80803988_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_3(s32, s32);
    _gcstatusDll_entrypoint_3(0, 1);
    _gcstatusDll_entrypoint_3(1, 1);
    _gcstatusDll_entrypoint_3(2, 1);
    return _gcstatusDll_entrypoint_3(3, 1);
}

/* extern */

void func_808039D0_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 _gcstatusDll_entrypoint_9(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(2);
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(2);
    _gcstatusDll_entrypoint_9(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A18_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(6);
    _gcstatusDll_entrypoint_8(0xA);
    _gcstatusDll_entrypoint_7(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A58_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 func_80803940_chgameselect();
    s32 func_80803988_chgameselect();
    _gcstatusDll_entrypoint_4(6);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

/* extern */

void func_80803A88_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803AB0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803B3C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803B84_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803BE8_chgameselect.s")

void func_80803C60_chgameselect()
{
    func_800FC660(0xF);
}

void func_80803C80_chgameselect()
{
    func_800FC660(0xE);
}

void func_80803CA0_chgameselect()
{
    func_800FC660(0x10);
}

void func_80803CC0_chgameselect()
{
    func_800FC660(0x96);
}

void func_80803CE0_chgameselect()
{
    func_800FC660(0x97);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803D00_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803D60_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803DCC_chgameselect.s")

s32 func_80803E40_chgameselect(void) {
    s32 func_80016800(s32);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!func_80016800(i)) return i;
    }
    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803E94_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803F90_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080401C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080407C_chgameselect.s")

void func_808040DC_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcnewoption_entrypoint_13(s32, s32, s32 *);
    s32 _gcnewoption_entrypoint_18();
    s32 _gcnewoption_entrypoint_22(s32, s32);
    extern s32 D_808083D8_chgameselect;
    if (_gcnewoption_entrypoint_18() == 0) {
        _gcnewoption_entrypoint_22(arg0, arg1);
        _gcnewoption_entrypoint_13(arg0, arg1, &D_808083D8_chgameselect);
        if (arg2 != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080413C_chgameselect.s")

/* extern */

s32 func_808041C8_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    s32 func_808016E8_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 2);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016E8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

/* extern */

void func_80804220_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    s32 func_808016E8_chgameselect(s32, s32);
    s32 func_80801758_chgameselect(s32, s32);
    s32 func_8080218C_chgameselect(s32, s32);
    s32 func_80803D60_chgameselect(s32);
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C)))));
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x20))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x20)))));
    func_80801758_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), -1);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016E8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808042A8_chgameselect.s")

void func_80804404_chgameselect(u8 *arg0, s32 arg1) {
    s32 func_80800478_chgameselect();

    if (*(s32 *)(arg0 + 0x18) >= 3) {
        func_80800478_chgameselect(arg0, 1);
    } else {
        arg0[0x65] &= ~0x10;
    }
}

/* extern */

s32 func_8080444C_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    s32 func_808016E8_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_808016E8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

/* extern */

void func_808044A4_chgameselect(void *arg0) {
    s32 func_808015DC_chgameselect(s32, s32);
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_808016A0_chgameselect(s32, s32);
    s32 func_808016E8_chgameselect(s32, s32);
    s32 func_8080218C_chgameselect(s32, s32);
    s32 func_80803D60_chgameselect(s32);
    func_8080218C_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C))), func_80803D60_chgameselect((*(s32 *)((s8 *)(arg0) + (0x1C)))));
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808015DC_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016A0_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_808016E8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080450C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808045E4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080462C_chgameselect.s")

/* extern */

void func_80804694_chgameselect(void *arg0) {
    s32 _glglobalsettings_entrypoint_2();
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
    func_80802BE8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    _glglobalsettings_entrypoint_2();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808046D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804750_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804878_chgameselect.s")

void func_808048F8_chgameselect(u8 *arg0, s32 *arg1) {
    s32 func_80802C48_chgameselect(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) < -1) {
        func_80802C48_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
        *arg1 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804948_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080499C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808049E8_chgameselect.s")

/* extern */

void func_80804A38_chgameselect(void *arg0) {
    s32 func_800FFA88(s32);
    s32 func_808026C8_chgameselect(s32, s32);
    s32 func_80802C48_chgameselect(s32);
    s32 temp_a0;

    func_80802C48_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    func_808026C8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x2C))), 1);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x34)));
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    if (temp_a0 != 0) {
        func_800FFA88(temp_a0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804A8C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804AF0_chgameselect.s")

/* extern */

s32 func_80804B4C_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    s32 func_80804C30_chgameselect(void *, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 1);
    func_80803D00_chgameselect(6, 1);
    func_80804C30_chgameselect(arg0, 0);
    return -1;
}

/* extern */

void func_80804B90_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804BB4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804BF4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804C30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804D30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804E34_chgameselect.s")

/* extern */

void func_80804F14_chgameselect(void *arg0) {
    s32 func_80801658_chgameselect(s32, s32);
    func_80801658_chgameselect((*(s32 *)((s8 *)(arg0) + (0x28))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804F38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808051B4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805310_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080537C_chgameselect.s")

void func_80805474_chgameselect(s32 arg0,s32 arg1)
{
    func_8080537C_chgameselect(arg0,0x1,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805498_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080569C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080595C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805AC0_chgameselect.s")

/* extern */

void func_80805BA0_chgameselect(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80803E40_chgameselect();
    s32 func_8080401C_chgameselect(s32, s32, s32);
    s32 func_8080407C_chgameselect(s32, s32, s32);
    if (func_80803E40_chgameselect() >= (arg1 + 2)) {
        func_8080407C_chgameselect(arg0, arg1, arg2);
        return;
    }
    func_8080401C_chgameselect(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805BFC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805CD8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805ECC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805F30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805FCC_chgameselect.s")

void func_80806068_chgameselect(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcstatusDll_entrypoint_4(s32);
    s32 _gcstatusDll_entrypoint_7(s32);
    s32 _gcstatusDll_entrypoint_8(s32);
    s32 _gcstatusDll_entrypoint_9(s32);
    s32 _gcstatusDll_entrypoint_19(void);

    switch (arg1) {
    case 1:
        *(s32 *)((u8 *)arg0 + 0x20) = arg2;
        switch (arg2) {
        case 0:
            _gcstatusDll_entrypoint_8(10);
            _gcstatusDll_entrypoint_7(0);
            break;
        case 1:
            _gcstatusDll_entrypoint_8(20);
            _gcstatusDll_entrypoint_7(0);
            break;
        case 2:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(5);
            break;
        case 3:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(10);
            break;
        }
        break;
    case 2:
        _gcstatusDll_entrypoint_4(arg2 + 1);
        switch (arg2) {
        case 2:
        case 4:
            func_80806068_chgameselect(arg0, 1, 2);
            _gcstatusDll_entrypoint_9(0);
            break;
        case 3:
        default:
            if (_gcstatusDll_entrypoint_19() == 0) {
                _gcstatusDll_entrypoint_9(2);
            }
            break;
        }
        break;
    case 3:
        _gcstatusDll_entrypoint_9(arg2 + 2);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808061A8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806218_chgameselect.s")

/* extern */

s32 func_808062A8_chgameselect(void) {
    s32 _gcstatusDll_entrypoint_13();
    return _gcstatusDll_entrypoint_13() + (-1);
}

void func_808062CC_chgameselect(s32 arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_3(s32, s32);
    _gcstatusDll_entrypoint_3(arg0, arg1 + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808062EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806370_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806408_chgameselect.s")

/* extern */

void func_808064E8_chgameselect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800AA054(s32);
    s32 func_800AA074(s32);
    if (arg3 != 0xFC) {
        if ((arg3 != 0xFD) && (arg3 == 0xFE)) {
            func_800AA054(arg2);
        }
    } else {
        func_800AA074(arg2);
    }
}

/* extern */

void func_80806540_chgameselect(s32 arg0) {
    s32 _gcfrontend_entrypoint_3(s32);
    s32 _gcfrontend_entrypoint_4(s32);
    s32 _gcfrontend_entrypoint_5(s32);
    s32 func_800AA054(s32);
    s32 func_800AA074();
    s32 func_80806744_chgameselect(s32);
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_800AA074();
    temp_s2 = _gcfrontend_entrypoint_4(3);
    temp_v0 = _gcfrontend_entrypoint_5(3);
    var_s1 = 0;
    if (temp_s2 > 0) {
        var_s0 = temp_v0;
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                func_800AA054(var_s0);
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s2);
    }
    func_80806744_chgameselect(arg0);
}

/* extern */

void func_808065C0_chgameselect(s32 arg0) {
    s32 func_80108B04(s32, s32);
    s32 func_80803D00_chgameselect(s32, s32);
    func_80803D00_chgameselect(7, 1);
    func_80108B04(arg0, 0x4B6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808065F4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808066CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806744_chgameselect.s")

/* extern */

void func_80806800_chgameselect(void *arg0, s32 arg1) {
    s32 func_80803B84_chgameselect();
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) == 9) {
        func_80803B84_chgameselect();
    }
}

/* extern */

void func_80806834_chgameselect(void *arg0) {
    s32 func_80802640_chgameselect(s32, s32, s32);
    s32 func_808026C8_chgameselect(s32, s32);
    s32 func_80802AD4_chgameselect(s32, s32, s32, s32, s32);
    s32 func_80802D04_chgameselect(s32, s32);
    func_80802AD4_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), 0x18F0, 5, 1, 4);
    func_80802D04_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))), 1);
    func_808026C8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x2C))), 9);
    func_80802640_chgameselect((*(s32 *)((s8 *)(arg0) + (0x24))), 0x18F0, 0);
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 6;
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = -1;
}

/* extern */

void func_808068AC_chgameselect(void *arg0, s32 arg1) {
    s32 func_80802640_chgameselect(s32, s32, s32);
    func_80802BE8_chgameselect((*(s32 *)((s8 *)(arg0) + (0x30))));
    func_80802640_chgameselect((*(s32 *)((s8 *)(arg0) + (0x24))), 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808068E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808069C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806A30_chgameselect.s")

void func_80806A88_chgameselect()
{
    _gcstatusDll_entrypoint_5();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806AA8_chgameselect.s")

void func_80806AD4_chgameselect()
{
    _gcstatusDll_entrypoint_10();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806AF4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806B5C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806BD4_chgameselect.s")

OSThread *chgameselect_entrypoint_6(void)
{
    extern u8 D_808084B4_chgameselect[];

    return (OSThread *) D_808084B4_chgameselect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806C54_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806D98_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806FAC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807030_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808070C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080714C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808073AC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808074C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808075D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807790_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807824_chgameselect.s")

OSThread *chgameselect_entrypoint_7(void)
{
    extern u8 D_80808504_chgameselect[];

    return (OSThread *) D_80808504_chgameselect;
}

void func_808078F0_chgameselect(void *arg0) {
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807900_chgameselect.s")

void func_808079C8_chgameselect(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808079D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807A10_chgameselect.s")
