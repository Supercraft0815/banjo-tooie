#include "common.h"

void func_80800000_chicekeydoor(u8 *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _subaddieDll_entrypoint_4(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(u8 *, s32);
    s32 func_800C4140(s32, u8 *, s32);
    s32 func_800D1804(s32);
    s32 func_800D1824(s32);
    s32 func_800D90A4(u8 *);
    s32 func_800DA544(s32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800F54E4();
    s32 func_800F82D4(s32, s32);
    s32 func_800FC660(s32);
    s32 func_80101FDC(u8 *, s32);
    u8 *func_80106790(s32);
    s32 func_80108B04(u8 *, s32);
    s32 func_8010C500(u8 *);
    s32 func_80800640_chicekeydoor(u8 *, u8 *);
    extern s32 D_80800920_chicekeydoor;
    extern s32 func_8010D5DC;
    s32 marker;
    u8 *sp38;
    f32 sp34;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
    case 8:
        break;
    case 2:
        if (func_8010C500(arg0) != 0) {
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(&func_8010D5DC, (*(s32 *)((s8 *)(arg0) + (0))));
            func_8008F938(1);
            func_8008F990(arg0 + 0x18, 0x43FA0000);
            func_80101FDC(arg0, 3);
            return;
        }
    default:
        return;
    case 3:
        func_800D1824(0x53);
        return;
    case 4:
        if (func_800D90A4(arg0 + 0x58) != 0) {
            func_80108B04(arg0, 0);
            (*(f32 *)((s8 *)(arg0) + (0x58))) = 5.0f;
            _capod_entrypoint_13(*(s32 *)arg0, *(s32 *)arg0, 0x1F, 0x10);
            func_800FC660(0xE);
            func_800D1804(0x53);
            func_80101FDC(arg0, 5);
        }
        func_800D1824(0x53);
        return;
    case 5:
        if ((*(s32 *)(arg0 + 0x3C) != 0) && (func_80800640_chicekeydoor(arg0, func_80106790(*(s32 *)(arg0 + 0x3C))) != 0)) {
            func_800C4140(0x7FFB5D6D, arg0 + 4, 0x04B000FA);
            (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.0f;
            func_80101FDC(arg0, 6);
        }
        func_800D1824(0x53);
        return;
    case 6:
        marker = *(s32 *)(arg0 + 0x3C);
        if (marker != 0) {
            sp38 = func_80106790(marker);
            if (func_800D90A4(arg0 + 0x58) != 0) {
                func_800EFB24(sp38 + 0x28, sp38 + 4, arg0 + 4);
                (*(f32 *)((s8 *)(arg0) + (0x58))) = 4.0f;
                (*(f32 *)((s8 *)(sp38) + (0x44))) = 90.0f;
                func_800C4140(0x7FFB5C56, arg0 + 4, 0x04B000FA);
                func_80101FDC(arg0, 7);
            } else {
                (*(f32 *)((s8 *)(sp38) + (0x44))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x58))), 1.0f, 0.0f, 0.0f, 90.0f);
            }
        }
        func_800D1824(0x53);
        return;
    case 7:
        if (func_800D90A4(arg0 + 0x58) != 0) {
            (*(f32 *)((s8 *)(arg0) + (0x48))) = -90.0f;
            func_800F82D4(func_800F54E4(), 0);
            func_800DA544(0x3E2);
            _subaddieaudioloop_entrypoint_2(arg0);
            func_800C4140(0x7FFB5CC7, arg0 + 4, 0x04B000FA);
            _subaddieDll_entrypoint_4(arg0, 0);
            func_80101FDC(arg0, 8);
        } else {
            sp34 = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x58))), 4.0f, 0.0f, 0.0f, 1.0f);
            _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_80800920_chicekeydoor);
            (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) (sp34 * -90.0f);
        }
        func_800D1824(0x53);
        break;
    }
}

/* extern */

s32 func_80800318_chicekeydoor(Actor *arg0, s32 arg1, s32 arg2) {
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _glsplinefind_entrypoint_3(f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _subaddieDll_entrypoint_4(u8 *, s32);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    s32 func_800D1A04(s32);
    void *func_800D7520(s32);
    s32 func_800DA298(s32);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_800F54E4();
    void func_800F5A00(s32, f32 *);
    void func_800F8300();
    s32 func_80101FDC(u8 *, s32);
    void func_80103110(void *, s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    s32 func_80108B04(u8 *, s32);
    void func_8010A570(Actor *);
    f32 sp34[3];
    Prop *sp30;
    f32 sp24[3];
    Actor *temp_v0_2;

    switch (arg1) {
    case 0x32:
        func_800F5A00(func_800F54E4(), sp34);
        func_800EF1B8(sp34, ((f32 *)arg0->actorData)[3], 200.0f);
        func_800F8300(func_800F54E4(), 2, sp34);
        func_80101FDC(arg0, 4);
        arg0->unk58 = 1.0f;
        _subaddieDll_entrypoint_4(arg0, 1);
        break;
    case 0x95:
        if (func_800DA298(0x3E2) != 0) {
            arg0->rotation[1] = -90.0f;
            func_80108B04(arg0, 1);
            func_80101FDC(arg0, 8);
        } else if (func_800D1A04(0x53) != 0) {
            sp30 = _gccubesearch_entrypoint_0(0x299, arg0);
            _gspropctrl_entrypoint_11(sp30, (f32 *)arg0->actorData);
            ((f32 *)arg0->actorData)[3] = (f32) _gspropctrl_entrypoint_12(sp30);
            _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x511, arg0), sp24);
            ((f32 *)arg0->actorData)[7] = (f32) _glsplinefind_entrypoint_3(sp24);
            func_80101FDC(arg0, 2);
        } else {
            func_80103110(arg0, 0);
            func_80101FDC(arg0, 1);
        }
        break;
    case 0x3D:
        temp_v0_2 = func_80108528(0x513, arg0->position, 0, &arg0);
        temp_v0_2->unk3C = arg0->unk0;
        arg0->unk3C = temp_v0_2->unk0;
        switch (arg2) {
        case 0:
            func_800C7A68(func_800D7520((s32) ((f32 *)arg0->actorData)[7]), 0.0f, temp_v0_2->position);
            temp_v0_2->scale = 0.1f;
            break;
        case 1:
            temp_v0_2->scale = 1.0f;
            break;
        }
        func_8010A570(temp_v0_2);
        temp_v0_2->unk64_16 = 0;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_8080057C_chicekeydoor.s")

OSThread *chicekeydoor_entrypoint_0(void)
{
    extern u8 D_80800930_chicekeydoor[];

    return (OSThread *) D_80800930_chicekeydoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_80800640_chicekeydoor.s")
