#include "common.h"

s32 ncbaspline_entrypoint_0() 
{
    return 0x30;
}

/* extern */

s32 func_80800008_ncbaspline(void *arg0) {
    s32 func_800D7520(s32);
    func_800D7520(*(*(s32 **)((s8 *)(arg0) + (0x44))));
}

void func_8080002C_ncbaspline(void *arg0) {
    void func_800EFD24(f32 *);
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44)) = -1;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 4) = 0.0f;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 8) = 0.0f;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x28) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2C) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2F) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2E) = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2F);
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0xC));
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x1C));
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x18) = 0.0f;
}

void ncbaspline_entrypoint_1(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void ncbaspline_entrypoint_2(s32 arg0) {
    s32 func_801124D0(s32, s32);
    s32 func_80111B8C(s32, s32, s32);
    func_801124D0(arg0, 1);
    func_80111B8C(arg0, 0x40400000, 0x41000000);
}

void ncbaspline_entrypoint_3(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void func_80800130_ncbaspline(s32 arg0, s32 arg1) {
    s32 func_80112518();
    s32 func_801124D0(s32, s32);
    s32 func_80112524(s32, s32);
    s32 sp1C;

    sp1C = func_80112518();
    func_801124D0(arg0, 0x1);
    func_80112524(arg0, arg1);
    func_801124D0(arg0, sp1C);
}

/* extern */

void func_8080017C_ncbaspline(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800C7A68(s32, f32, s32 *);
    s32 func_800C7B28(s32, f32, f32, s32);
    f32 func_800C82CC(s32, s32);
    s32 func_800EE780(s32 *, s32 *, s32 *);
    s32 func_800EEAD4(s32 *, s32);
    s32 func_800EF368(s32 *, s32);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    s32 func_800F018C(s32 *, s32 *, s32 *, s32);
    s32 sp4C[3];
    s32 sp40[3];
    s32 sp34[3];
    s32 sp28[3];
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = func_800C82CC(arg1, arg2);
    if ((temp_f0 == 0.0f) || (temp_f0 == 1.0f)) {
        func_800C7A68(arg1, temp_f0, sp40);
        if (temp_f0 == 0.0f) {
            func_800C7A68(arg1, temp_f0 + 0.001f, sp34);
        } else {
            func_800C7A68(arg1, temp_f0 - 0.001f, sp34);
        }
        func_800EFB24(sp28, sp34, sp40);
        func_800EF368(sp28, 0x43C80000);
        func_800EE780(sp34, sp28, sp40);
        func_800F018C(sp4C, sp40, sp34, arg2);
        func_800EEAD4(sp4C, arg3);
        return;
    }
    func_800C7A68(arg1, temp_f0, sp4C);
    temp_f0_2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x44)))) + (8)));
    if (temp_f0 < temp_f0_2) {
        func_800C7B28(arg1, temp_f0, temp_f0_2, 0xF);
        return;
    }
    func_800C7B28(arg1, temp_f0_2, temp_f0, 0xF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/func_80800318_ncbaspline.s")

void ncbaspline_entrypoint_4(void *arg0) {
    s32 func_800D7520(s32);
    s32 func_800C7A68(s32, f32, s32 *);
    f32 func_800D8FF8(void);
    s32 func_800EE780(s32 *, s32 *, s32 *);
    void func_800EF334(f32 *, f32);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80110770(void *, f32 *);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, f32 *, f32 *);
    s32 func_80112524();
    s32 func_80800318_ncbaspline(void *, f32 *);
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    struct SplineData {
        s32 index;
        f32 unk4;
        f32 position;
        f32 origin[3];
        f32 blend;
        f32 unk1C[3];
        s32 state;
        u8 flag;
    };
    struct SplineOwner { u8 pad[0x44]; struct SplineData *data; };

    if (((struct SplineOwner *)arg0)->data->index != -1) {
        if (((struct SplineOwner *)arg0)->data->flag == 1) {
            ((struct SplineOwner *)arg0)->data->flag = 2;
        }
        func_801107F0(arg0, sp40);
        if (((struct SplineOwner *)arg0)->data->state == -1 ||
            !func_80800318_ncbaspline(arg0, sp40)) {
            ((struct SplineOwner *)arg0)->data->state = 0;
        } else {
            func_800C7A68(func_80800008_ncbaspline(arg0),
                ((struct SplineOwner *)arg0)->data->position, sp40);
            if (((struct SplineOwner *)arg0)->data->blend < 1.0f) {
                sp4C = func_800F10B4(((struct SplineOwner *)arg0)->data->blend, 0.5f, 1.0f, 0.05f, 0.01f);
                ((struct SplineOwner *)arg0)->data->blend += 30.0f * func_800D8FF8() * sp4C;
                if (((struct SplineOwner *)arg0)->data->blend < 1.0f) {
                    func_800EFB24(sp50, sp40, ((struct SplineOwner *)arg0)->data->origin);
                    func_800EF334(sp50, ((struct SplineOwner *)arg0)->data->blend);
                    func_800EE780(sp40, ((struct SplineOwner *)arg0)->data->origin, sp50);
                }
            }
            func_80110770(arg0, sp40);
            func_80112524(arg0, sp5C);
            func_80110A68(arg0, sp34, sp5C);
            func_80110790(arg0, sp34);
        }
    }
}

void ncbaspline_entrypoint_5(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x44)));
    if ((*(s32 *)((s8 *)(temp_v0) + (0x28))) != 0) {
        (*(s32 *)((s8 *)(temp_v0) + (0x28))) = -1;
    }
}

/* extern */

void ncbaspline_entrypoint_6(s32 arg0, void *arg1, s32 arg2) {
    s32 func_800D5424(u16);
    s32 ncbaspline_entrypoint_7(s32, s32);
    ncbaspline_entrypoint_7(arg0, func_800D5424((*(u16 *)((s8 *)(arg1) + (8)))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/ncbaspline_entrypoint_7.s")

s32 ncbaspline_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x44)))) + (0x28))) < 1;
}
