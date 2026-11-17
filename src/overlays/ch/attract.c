#include "common.h"

OSThread *chattract_entrypoint_0(void)
{
    extern u8 D_808004F4_chattract[];

    return (OSThread *) D_808004F4_chattract;
}

void func_8080000C_chattract(s32 arg0) 
{
}
void func_80800014_chattract(Actor *arg0) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void _subaddiefade_entrypoint_2(void *arg0);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddiefade_entrypoint_5(void *arg0);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    struct AttractState {
        u8 pad[0x78];
        u16 rest : 14;
        u16 state : 2;
    };
    struct AttractEntry {
        u16 animation;
        u8 fade;
        u8 pad3;
        f32 unk4;
        f32 unk8;
        f32 scale;
        s16 x;
        s16 y;
        f32 unk14;
        u8 flags;
        u8 pad19[3];
    };
    extern f32 D_8080046C_chattract[][7];
    extern u8 D_8080046A_chattract[][28];
    extern f32 D_80800470_chattract[][7];
    struct AttractEntry *entry;

    if (arg0->unk54 != 0.0f) {
        arg0->rotation[1] += arg0->unk54 * func_800D8FF8();
    }
    if (arg0->unk79_4 != 0) {
        if (!((struct AttractState *)arg0)->state && func_800D9078(&arg0->unk58)) {
            if (D_8080046A_chattract[arg0->unk74_7][0] != 0) {
                _subaddiefade_entrypoint_2(arg0);
            } else {
                _subaddiefade_entrypoint_1(arg0, 255);
            }
            arg0->unk58 = D_8080046C_chattract[arg0->unk74_7][0];
            arg0->unk79_4 = 0;
            func_80102424(arg0, arg0->unk70_10);
        }
    } else if (!((struct AttractState *)arg0)->state && func_800D9078(&arg0->unk58)) {
        entry = (struct AttractEntry *)((s32)arg0->unk74_7 * (s32)sizeof(struct AttractEntry) + (BtIntPtr)(&D_8080046C_chattract[0][0] - 1));
        if (entry->unk8 != 0.0f) {
            if (entry->pad3 != 0) {
                _subaddiefade_entrypoint_5(arg0);
            } else {
                _subaddiefade_entrypoint_1(arg0, 0);
            }
            arg0->unk58 = D_80800470_chattract[arg0->unk74_7][0];
            arg0->unk79_4 = 1;
        } else if (entry->pad3 != 0) {
            _subaddiefade_entrypoint_3(arg0);
        } else {
            func_800FFAB0(arg0);
        }
    }
}

void func_80800204_chattract(Actor *arg0, BtIntPtr arg1) {
    void func_800DF410(s32);
    void func_800DF47C(s32 (*)(Actor *), Actor *);
    void func_800DF4CC(f32 *);
    void * func_800DF944(void *a0, f32 *coords, f32 a2, f32 a3, f32 *a4, s32 a5, void *a6);
    void func_800EFA4C(f32 *, f32, f32, f32);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp3C[3];
    if (arg0->rotation[1]) {
        func_800EFA4C(sp3C, 0.0f, arg0->rotation[1], 0.0f);
        func_800DF4CC(sp3C);
    }
    func_800DF410(arg0->alpha);
    func_800DF47C(&func_801015D0, arg0);
    func_800DF944(arg1, arg0->position, 0.0f, arg0->scale, 0, 1, func_8010347C(arg0->unk0));
}

s32 func_808002AC_chattract(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddiefade_entrypoint_2(void *arg0);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    struct AttractFlags {
        u8 pad[0x7A];
        u8 value : 2;
        u8 rest : 6;
    };
    struct AttractEntry {
        u16 animation;
        u8 fade;
        u8 pad3;
        f32 unk4;
        f32 unk8;
        f32 scale;
        s16 x;
        s16 y;
        f32 unk14;
        u8 flags;
        u8 pad19[3];
    };
    extern struct AttractEntry D_80800468_chattract[];
    struct AttractEntry *entry;

    if (arg1 == 0x95) {
        entry = &D_80800468_chattract[arg0->unk74_7];
        func_80103140(arg0, entry->animation, 0);
        func_80102424(arg0, arg0->unk74_7);
        arg0->unk58 = entry->unk4;
        arg0->scale = entry->scale;
        ((struct AttractFlags *)arg0)->value = entry->flags;
        if (entry->fade != 0) {
            _subaddiefade_entrypoint_2(arg0);
        }
        arg0->position[0] = entry->x;
        arg0->position[1] = entry->y;
        arg0->unk54 = entry->unk14;
        arg0->unk79_4 = 0;
        return 1;
    }
    return 0;
}

void chattract_entrypoint_1(s32 arg0) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
#ifdef BT_NATIVE
    void chattract_entrypoint_2(s32 arg0);
#else
    extern s32 _chattract_entrypoint_2;
#endif
    _chbaddiesetup_entrypoint_1(&_chattract_entrypoint_2, arg0);
}

void chattract_entrypoint_2(s32 arg0) {
    void func_800EC828(void);
    Actor *func_80108454(s32, s32 *, u32);
    extern s32 B_80800540_chattract;
    Actor *temp_v0;
    Unk80132ED0 *temp_v0_2;

    temp_v0 = func_80108454(0x4B5, &B_80800540_chattract, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk74_7 = arg0 + 1;
        temp_v0_2 = temp_v0->unk0;
        (*(u16 *)((s8 *)(temp_v0_2) + (0x12))) = (u16) (((*(u16 *)((s8 *)(temp_v0_2) + (0x12))) & 1) | 2);
        func_800EC828();
    }
}
