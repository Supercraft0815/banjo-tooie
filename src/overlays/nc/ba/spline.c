#include "common.h"

s32 ncbaspline_entrypoint_0() 
{
    return 0x30;
}

/* extern */

BtIntPtr func_80800008_ncbaspline(void *arg0) {
    BtIntPtr func_800D7520(s32);
    BT_NATIVE_ONLY(return) func_800D7520(*(*(s32 **)((s8 *)(arg0) + (0x44))));
}    typedef struct { u8 pad0[0x44]; u8 * unk44; } Objspline_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080002C_ncbaspline(void *arg0) {
    void func_800EFD24(f32 *);
    *(s32 *)(((Objspline_arg0 *)arg0)->unk44) = -1;
    *(f32 *)(((Objspline_arg0 *)arg0)->unk44 + 4) = 0.0f;
    *(f32 *)(((Objspline_arg0 *)arg0)->unk44 + 8) = 0.0f;
    *(s32 *)(((Objspline_arg0 *)arg0)->unk44 + 0x28) = 0;
    *(u8 *)(((Objspline_arg0 *)arg0)->unk44 + 0x2C) = 0;
    *(u8 *)(((Objspline_arg0 *)arg0)->unk44 + 0x2F) = 0;
    *(u8 *)(((Objspline_arg0 *)arg0)->unk44 + 0x2E) = *(u8 *)(((Objspline_arg0 *)arg0)->unk44 + 0x2F);
    func_800EFD24((f32 *)(((Objspline_arg0 *)arg0)->unk44 + 0xC));
    func_800EFD24((f32 *)(((Objspline_arg0 *)arg0)->unk44 + 0x1C));
    *(f32 *)(((Objspline_arg0 *)arg0)->unk44 + 0x18) = 0.0f;
}

void ncbaspline_entrypoint_1(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void ncbaspline_entrypoint_2(s32 arg0) {
    s32 func_801124D0(BtIntPtr, s32);
    s32 func_80111B8C(s32, s32, s32);
    func_801124D0(arg0, 1);
    func_80111B8C(arg0, 0x40400000, 0x41000000);
}

void ncbaspline_entrypoint_3(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void func_80800130_ncbaspline(BtIntPtr arg0, f32 *arg1) {
    s32 func_80112518();
    s32 func_801124D0(BtIntPtr, s32);
    void func_80112524(void *arg0, f32 *arg1);
    s32 sp1C;

    sp1C = func_80112518();
    func_801124D0(arg0, 0x1);
    func_80112524(arg0, arg1);
    func_801124D0(arg0, sp1C);
}

/* extern */

f32 func_8080017C_ncbaspline(void *arg0, BtIntPtr arg1, BtIntPtr arg2, BtIntPtr arg3) {
    void func_800C7A68(BtIntPtr, f32, void *);
    f32 func_800C7B28(BtIntPtr, f32, f32, s32);
    f32 func_800C82CC(BtIntPtr, BtIntPtr);
    s32 func_800EE780(s32 *, s32 *, s32 *);
    f32 func_800EEAD4(void *, void *);
    s32 func_800EF368(s32 *, s32);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    s32 func_800F018C(s32 *, s32 *, s32 *, BtIntPtr);
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
        return func_800EEAD4(sp4C, arg3);
    }
    func_800C7A68(arg1, temp_f0, sp4C);
    temp_f0_2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x44)))) + (8)));
    if (temp_f0 < temp_f0_2) {
        return func_800C7B28(arg1, temp_f0, temp_f0_2, 0xF);
    }
    return func_800C7B28(arg1, temp_f0_2, temp_f0, 0xF);
}

s32 func_80800318_ncbaspline(void *arg0, f32 *arg1) {
    void func_800C7A68(BtIntPtr, f32, void *);
    f32 func_800C7FD4(BtIntPtr, f32, f32);
    f32 func_800EEAD4(void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    f32 forward[3];
    f32 backward[3];
    f32 position[3];
    f32 forwardDistance;
    f32 backwardDistance;
    f32 forwardPosition;
    f32 backwardPosition;
    f32 velocity;
    f32 direction;
    f32 distance;
    BtIntPtr path;
    struct SplineData { s32 path; f32 velocity; f32 position; u8 pad[0x22]; u8 start; u8 end; };
    struct SplineOwner { u8 pad[0x44]; struct SplineData *data; };

    path = func_80800008_ncbaspline(arg0);
    func_80800130_ncbaspline((BtIntPtr)arg0, position);
    distance = func_8080017C_ncbaspline(arg0, path, (BtIntPtr)position, (BtIntPtr)arg1);
    forwardPosition = func_800C7FD4(path, ((struct SplineOwner *)arg0)->data->position, 1000.0f);
    backwardPosition = func_800C7FD4(path, ((struct SplineOwner *)arg0)->data->position, -1000.0f);
    func_800C7A68(path, forwardPosition, forward);
    func_800C7A68(path, backwardPosition, backward);
    forwardDistance = func_800EEAD4(position, forward);
    backwardDistance = func_800EEAD4(position, backward);
    velocity = 0.0f;
    if (mlAbsF(forwardDistance - backwardDistance) > 3.0f) {
        direction = forwardDistance < backwardDistance ? 1.0f : -1.0f;
        if (distance > 550.0f) {
            velocity = func_800F10B4(distance, 550.0f, 650.0f, 0.0f, 1500.0f) * direction;
        } else if (distance < 500.0f) {
            velocity = func_800F10B4(distance, 400.0f, 500.0f, 1500.0f, 0.0f) * -direction;
        }
        if (mlAbsF(((struct SplineOwner *)arg0)->data->velocity) < mlAbsF(velocity)) {
            ((struct SplineOwner *)arg0)->data->velocity += (velocity - ((struct SplineOwner *)arg0)->data->velocity) * 0.08f;
        } else {
            ((struct SplineOwner *)arg0)->data->velocity = velocity;
        }
        ((struct SplineOwner *)arg0)->data->position = func_800C7FD4(path, ((struct SplineOwner *)arg0)->data->position, ((struct SplineOwner *)arg0)->data->velocity);
        if ((velocity > 0.0f && ((struct SplineOwner *)arg0)->data->position == 1.0f && !((struct SplineOwner *)arg0)->data->end) ||
            (velocity < 0.0f && ((struct SplineOwner *)arg0)->data->position == 0.0f && !((struct SplineOwner *)arg0)->data->start)) {
            return 0;
        }
    } else {
        return 1;
    }
    if (velocity) {
        return 1;
    }
    return 2;
}

void ncbaspline_entrypoint_4(void *arg0) {
    BtIntPtr func_800D7520(s32);
    void func_800C7A68(BtIntPtr, f32, void *);
    f32 func_800D8FF8(void);
    s32 func_800EE780(s32 *, s32 *, s32 *);
    void func_800EF334(f32 *, f32);
    s32 func_800EFB24(s32 *, s32 *, s32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80110770(void *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, f32 *, f32 *);
    void func_80112524(void *arg0, f32 *arg1);
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
}    typedef struct { u8 pad0[0x28]; s32 unk28; } Objspline_ncbaspline_entrypoint_5_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void ncbaspline_entrypoint_5(void *arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x44)));
    if ((((Objspline_ncbaspline_entrypoint_5_temp_v0 *)temp_v0)->unk28) != 0) {
        (((Objspline_ncbaspline_entrypoint_5_temp_v0 *)temp_v0)->unk28) = -1;
    }
}    typedef struct { u8 pad0[0x8]; u16 unk8; } Objspline_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void ncbaspline_entrypoint_6(BtIntPtr arg0, void *arg1, BtIntPtr arg2) {
    s32 func_800D5424(s32 arg0);
    void ncbaspline_entrypoint_7(BtIntPtr, s32);
    ncbaspline_entrypoint_7(arg0, func_800D5424((((Objspline_arg1 *)arg1)->unk8)));
}

void ncbaspline_entrypoint_7(BtIntPtr arg0, s32 arg1) {
    void *_gccubesearch_entrypoint_14(s32, s32 *);
    s32 _glsplinefind_entrypoint_3(f32 *);
    void _gspropctrl_entrypoint_11(void *, void *);
    s32 _gspropctrl_entrypoint_13(Prop *);
    void func_800C7A68(BtIntPtr, f32, void *);
    f32 func_800C82CC(BtIntPtr, BtIntPtr);
    s32 func_800D542C(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE904(s32 *, f32 *);
    s32 func_800F5C94(BtIntPtr);
    void func_800F7E9C(s32, s32);
    f32 func_800FB1EC(struct Unk800C7A68 *, f32, f32 *, s32);
    s32 func_801106A0(s32 *);
    s32 func_801106A8(void *, s32);
    void func_801107B0(void *, f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110840(s32 *);
    s32 func_80800318_ncbaspline(void *, f32 *);
    f32 sp4C[3];
    int sp40[3];
    f32 sp34[3];
    int sp30;
    Prop *saved;
    register Prop *prop;
    struct SplineData {
        int index;
        f32 unk4;
        f32 position;
        f32 origin[3];
        f32 blend;
        f32 unk1C[3];
        int state;
        u8 flag;
        u8 mode;
        u8 flag2E;
        u8 flag2F;
    };
    struct SplineOwner {
        u8 pad[0x44];
        struct SplineData *data;
    };

    if (func_800F5C94(func_80110840((s32 *)arg0)) != 4) {
        sp30 = func_800D542C(arg1);
        if (sp30 != ((struct SplineOwner *)arg0)->data->state &&
            ((struct SplineOwner *)arg0)->data->state != -1) {
            func_801107B0((void *)arg0, sp4C);
            func_800EE904(sp40, sp4C);
            prop = _gccubesearch_entrypoint_14(sp30, sp40);
            if (prop != NULL) {
                saved = prop;
                _gspropctrl_entrypoint_11(prop, sp4C);
                switch (_gspropctrl_entrypoint_13(saved)) {
                    default:
                        ((struct SplineOwner *)arg0)->data->flag2E = 0;
                        ((struct SplineOwner *)arg0)->data->flag2F = 0;
                        break;
                    case 1:
                        ((struct SplineOwner *)arg0)->data->flag2E = 1;
                        ((struct SplineOwner *)arg0)->data->flag2F = 0;
                        break;
                    case 2:
                        ((struct SplineOwner *)arg0)->data->flag2E = 0;
                        ((struct SplineOwner *)arg0)->data->flag2F = 1;
                        break;
                    case 3:
                        ((struct SplineOwner *)arg0)->data->flag2E = 1;
                        ((struct SplineOwner *)arg0)->data->flag2F = 1;
                        break;
                }
                ((struct SplineOwner *)arg0)->data->mode = func_801106A0((s32 *)arg0);
                func_801107F0((void *)arg0, sp34);
                func_800EE7F8(((struct SplineOwner *)arg0)->data->origin, sp34);
                ((struct SplineOwner *)arg0)->data->blend = 0.0f;
                ((struct SplineOwner *)arg0)->data->state = sp30;
                ((struct SplineOwner *)arg0)->data->index = _glsplinefind_entrypoint_3(sp4C);
                ((struct SplineOwner *)arg0)->data->position = func_800C82CC(func_80800008_ncbaspline((void *)arg0), sp34);
                ((struct SplineOwner *)arg0)->data->position = func_800FB1EC((struct Unk800C7A68 *)func_80800008_ncbaspline((void *)arg0), ((struct SplineOwner *)arg0)->data->position, sp34, 0x20020);
                ((struct SplineOwner *)arg0)->data->flag = 1;
                func_800C7A68(func_80800008_ncbaspline((void *)arg0), ((struct SplineOwner *)arg0)->data->position, ((struct SplineOwner *)arg0)->data->unk1C);
                if (func_80800318_ncbaspline((void *)arg0, ((struct SplineOwner *)arg0)->data->unk1C) == 1) {
                    func_801106A8((void *)arg0, 0xE);
                    func_800F7E9C(func_80110840((s32 *)arg0), 1);
                } else {
                    ((struct SplineOwner *)arg0)->data->state = 0;
                }
            }
        }
    }
}

s32 ncbaspline_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x44)))) + (0x28))) < 1;
}
