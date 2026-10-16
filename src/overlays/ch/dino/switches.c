#include "common.h"

OSThread *chdinoswitches_entrypoint_0(void)
{
    extern u8 D_80800C30_chdinoswitches[];

    return (OSThread *) D_80800C30_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_1(void)
{
    extern u8 D_80800C78_chdinoswitches[];

    return (OSThread *) D_80800C78_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_2(void)
{
    extern u8 D_80800CC0_chdinoswitches[];

    return (OSThread *) D_80800CC0_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_3(void)
{
    extern u8 D_80800D08_chdinoswitches[];

    return (OSThread *) D_80800D08_chdinoswitches;
}

void func_80800030_chdinoswitches(Actor *arg0) {
    s32 _chswitch_entrypoint_7(Actor *, s32);
    s32 _chswitch_entrypoint_8(Actor *, s32);
    s32 _chswitch_entrypoint_9(Actor *);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80103110(Actor *, u32);
    s32 func_80800108_chdinoswitches(void);
    struct SwitchEntry {
        u16 unk0;
        u16 flag;
        s32 unk4;
        u8 unk8[12];
    };
    extern struct SwitchEntry D_80800B20_chdinoswitches;
    s32 sp24[1];
    struct SwitchEntry *sp20;

    arg0->actorData[0] = sp24[0] = func_80800108_chdinoswitches();
    if (arg0->actorData[0] == 4) {
        if (func_800DA298(0x676U) != 0 || func_800D0B68(0x18, 0) != 0) {
            func_800DA544(0xA10);
        }
    }
    sp20 = &D_80800B20_chdinoswitches + sp24[0];
    _chswitch_entrypoint_7(arg0, sp20->flag);
    _chswitch_entrypoint_8(arg0, sp20->unk4);
    if (arg0->actorData[0] == 4) {
        if (func_800DA298(sp20->flag) != 0) {
            func_80103110(arg0, 0);
        }
    } else {
        _chswitch_entrypoint_9(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800108_chdinoswitches.s")

void func_80800270_chdinoswitches(void *arg0) {
    void func_801032B0(void *, u16, u16);
    extern u8 D_80800B28_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_801032B0(arg0, *(u16 *)(D_80800B28_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808002B0_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808003E8_chdinoswitches.s")

/* extern */

void chdinoswitches_entrypoint_4(s32 arg0, s32 arg1) {
    void _glcutDll_entrypoint_6(u32, u32);
    Actor *_subaddiefind_entrypoint_11(s32, s32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800EA05C();
    s32 func_8010108C();
    s32 func_80101180(s32, s32, s32);
    void func_80103110(Actor *, u32);
    Actor *sp1C;
    Actor *sp18;

    if (func_800EA05C() == 0x112) {
        sp1C = _subaddiefind_entrypoint_11(0x364, 0x35);
        sp18 = _subaddiefind_entrypoint_11(0x433, 0x35);
        func_80101180(0x433, 8, 0);
        func_8010108C(sp1C, 8, 0);
        func_80103110(sp18, 1);
        return;
    }
    if (func_800DA298(0xA3A) == 0) {
        _glcutDll_entrypoint_6(0x112, 0x37);
        return;
    }
    func_800DA524(0xA10);
    func_800DA524(0x676);
}

void func_80800714_chdinoswitches(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80109EEC(s16 *, s32);
    void func_8010A570(Actor *);
    s32 func_80800108_chdinoswitches(void);
    extern u16 D_80800B22_chdinoswitches[][10];
    s32 temp_v0;

    temp_v0 = func_80800108_chdinoswitches();
    arg0->actorData[0] = temp_v0;
    if (func_800DA298(D_80800B22_chdinoswitches[temp_v0][0]) != 0) {
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.3f);
        func_8010A570(arg0);
    }
    if (arg0->actorData[0] == 3) {
        func_80109EEC(arg0, 0x44);
    }
}

void func_808007A0_chdinoswitches(Actor *arg0) {
    void func_800DA544(GameFlag);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80101E14(Actor *, f32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    extern u16 D_80800B22_chdinoswitches[][10];
    s32 temp_a0;

    if (arg0->unk70_10 == 2 && func_80101E14(arg0, 0.3f) != 0) {
        func_800DA544(D_80800B22_chdinoswitches[arg0->actorData[0]][0]);
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.3f);
        func_80103110(arg0, 0);
        temp_a0 = (s32)arg0->unk3C;
        if (temp_a0 != 0) {
            func_8010114C(temp_a0, 7, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800848_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808008F0_chdinoswitches.s")

void func_80800A48_chdinoswitches(void *arg0) {
    void func_80103140(void *, u16, u16);
    extern u8 D_80800B2C_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_80103140(arg0, *(u16 *)(D_80800B2C_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

s32 func_80800A88_chdinoswitches(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);

    switch (arg1) {
        case 0xB:
            if (arg0->actorData[0] == 4 && arg2 == 0x23 && _glcutDll_entrypoint_19(0x37) != 0) {
                _glcutDll_entrypoint_17();
            }
            return 3;
        case 0x95:
            func_80800A48_chdinoswitches(arg0);
        default:
            return _chdoor_entrypoint_1((s32)arg0, arg1, arg2);
    }
}
