#include "core2/1E6B900.h"

s32 func_80092010(void)
{
	return 0x118;
}    typedef struct { u8 pad0[0x28]; f32 unk28; u8 pad2C[0x98]; u8 unkC4; u8 padC5[0x3]; f32 unkC8; } Obj1E6B900_func_80092018_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

/* extern */

void func_80092018(u8 *arg0) {
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void * func_80019CD4(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void mlMtxGet(void *);
    void mlMtxRotPitch(f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 var_f0;
    u8 *temp_s0;

    temp_s0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    if ((((Obj1E6B900_func_80092018_temp_s0 *)temp_s0)->unkC4) != 0) {
        var_f0 = (((Obj1E6B900_func_80092018_temp_s0 *)temp_s0)->unkC8);
    } else {
        var_f0 = (((Obj1E6B900_func_80092018_temp_s0 *)temp_s0)->unk28);
    }
    func_800EFA4C(sp34, *(f32 *)(temp_s0 + 0x20), var_f0, *(f32 *)(temp_s0 + 0x24));
    temp_s0 = *(u8 **)(arg0 + 0x50);
    func_800EE780(sp28, (f32 *)(temp_s0 + 0x2C), (f32 *)(temp_s0 + 0x44));
    func_80019CD4();
    temp_s0 = *(u8 **)(arg0 + 0x50);
    func_80019750((f32 *)(temp_s0 + 0x44), sp34, *(f32 *)(temp_s0 + 0x1C), sp28);
    temp_s0 = *(u8 **)(arg0 + 0x50);
    if (*(u8 *)(temp_s0 + 0xC4) != 0) {
        mlMtxRotPitch(*(f32 *)(temp_s0 + 0x28));
        temp_s0 = *(u8 **)(arg0 + 0x50);
    }
    mlMtxGet(temp_s0 + 0xCC);
}

void func_800920C8(void *arg0) {
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80093504();
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    func_80093504(arg0, temp_v0 + 0x64, temp_v0 + 0x50);
}

void func_800920F0(PlayerState *arg0) {
    f32 yaw_get(PlayerState *);
    f32 func_800136E4(f32);
    u8 temp_v0;

    temp_v0 = (*(u8 **)((u8 *)arg0 + 0x50))[0x15];
    switch (temp_v0) {
        case 2:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28) = func_800136E4(yaw_get(arg0) + 180.0f);
            break;
        default:
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28) = yaw_get(arg0);
            break;
        case 3:
            break;
    }
}

void func_8009216C(PlayerState *arg0, f32 arg1[3], f32 arg2[3]) {
    f32 baroll_get(PlayerState *);
    f32 func_8009BFCC(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u8 *temp_v0;

    func_800920F0(arg0);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x24) = baroll_get(arg0);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x20) = func_8009BFCC(arg0);
    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    func_800EFA4C(arg2, *(f32 *)(temp_v0 + 0x20), *(f32 *)(temp_v0 + 0x28), *(f32 *)(temp_v0 + 0x24));
    func_8009C128(arg0, arg1);
}

void func_800921E0(PlayerState *player, s32 id, f32 dst[3]) {
    void func_8009C2A0(BtIntPtr arg0, s32 arg1, BtIntPtr arg2);
    int func_800EEEA8(f32[3]);
    void func_8009C128(PlayerState *, f32[3]);
    func_8009C2A0((void *)((s32 **)player)[20][1], id, dst);
    if (func_800EEEA8(dst)) {
        func_8009C128(player, dst);
    }
}    typedef struct { u8 pad0[0x50]; void * unk50; u8 pad54[0x10]; void * unk64; u8 pad68[0x11C]; s32 unk184; } Obj1E6B900_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80092224(void *arg0) {
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x1A))) = 1;
}

void func_80092234(void *arg0) {
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x1A))) = 1;
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x16))) = 1;
}

s32 func_8009224C(u8 **arg0) {
    return arg0[20][26];
}

s32 func_80092258(void *arg0) {
    f32 _bainvisible_entrypoint_2(void *arg0, s32 arg1);
    s32 func_80093DF4(void *, s32);
    s32 func_8009AD78(void *, s32);
    int func_800A4C68(void *);
    s32 func_800A89F8();
    s32 pad;
    u8 sp33;
    s32 sp2C;
    f32 var_f20;
    u8 *temp_v0;

    temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
    if (temp_v0[0x88] != 0) {
        var_f20 = (f32)(s32)temp_v0[0x8C];
    } else {
        var_f20 = (f32)(s32)temp_v0[0x14];
    }
    if (func_8009AD78(arg0, 0xC) != 0) {
        sp33 = 0;
        if (func_80093DF4(arg0, 2) != 0) {
            sp2C = func_800A89F8();
            if (func_800A4C68(arg0) == sp2C) {
                sp33 = 1;
            }
        }
        var_f20 *= _bainvisible_entrypoint_2(arg0, sp33);
    }
    return (u32)var_f20 & 0xFF;
}

s32 func_8009239C(u8 **arg0) {
    return arg0[20][25];
}    typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0xE]; u8 unk16; } Obj1E6B900_func_800923A8_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */ typedef struct { u8 pad0[0x88]; u8 unk88; u8 unk89; u8 unk8A; u8 unk8B; } Obj1E6B900_func_800923A8_temp_v0_3; /* offsets.py genstruct: fields from raw offsets on temp_v0_3; rename once understood */

/* extern */

void func_800923A8(void *arg0, s32 arg1) {
    s32 func_80092258();
    void func_800A2540(void *arg0, s32 arg1);
    void func_800DF464(f32);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF738(BtIntPtr);
    void func_800DF830(s32);
    u8 sp1F;
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

#ifdef BT_NATIVE
    temp_v0 = ((s32 (*)())func_80092258)();
#else
    temp_v0 = func_80092258();
#endif
    sp1F = temp_v0;
    func_800A2540(arg0, temp_v0);
    func_800DF464(2.0f);
    if (arg1 != 0) {
        temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x50)));
        if ((((Obj1E6B900_func_800923A8_temp_v0_2 *)temp_v0_2)->unk16) == 0) {
            func_800DF738((((Obj1E6B900_func_800923A8_temp_v0_2 *)temp_v0_2)->unk4));
        }
    }
    func_800DF830(1);
    temp_v0_3 = (*(void **)((s8 *)(arg0) + (0x50)));
    if ((((Obj1E6B900_func_800923A8_temp_v0_3 *)temp_v0_3)->unk88) != 0) {
        func_800DF5D8((((Obj1E6B900_func_800923A8_temp_v0_3 *)temp_v0_3)->unk89), (((Obj1E6B900_func_800923A8_temp_v0_3 *)temp_v0_3)->unk8A), (((Obj1E6B900_func_800923A8_temp_v0_3 *)temp_v0_3)->unk8B), sp1F);
    }
}

typedef struct {
    u32 *unk0;
    u32 *unk4;
    u32 *unk8;
    u32 unkC;
    u32 unk10;
    u16 unk14;
    u16 unk16;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
} Unk80132ED0;

struct anctrl_s;
struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
void func_800A7108(Unk80132ED0 *, f32);

void _babackpack_entrypoint_3(PlayerState *, f32 *, f32 *, f32, f32 *);
void *func_8008AEDC(void *);
void func_8008C200(s16, BtIntPtr, BtIntPtr);
void func_8008CA98(PlayerState *);
void func_80093AB8(void *, Gfx **);
void func_80094070(u8 *, f32 *);
void func_800A06E8(BtIntPtr);
int func_800A4C68(void *);
void func_800A7130(Unk80132ED0 *, s32);
s32 func_800A89F8(void);
void *func_800AE080(s16);
void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
void func_800DF440(s32);
void func_800DF47C(s32, BtIntPtr);
void func_800DF4CC(BtIntPtr);
void func_800DF720(BtIntPtr);
void func_800DF72C(BtIntPtr);
void func_800DF818(BtIntPtr);
s32 func_800E3E8C(f32 *, f32);
void func_800EE7F8(f32 *, f32 *);
void func_800EF04C(f32 *, f32 *);
void func_800EFA4C(f32 *, f32, f32, f32);
BtIntPtr func_80100A74(s16, s32);
BtIntPtr func_80100AC4(s16);

void func_80092444(PlayerState *arg0, Gfx **arg1) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    f32 sp44[3];
    u8 *temp_v0;
    BtIntPtr sp3C;

    if ((*(u8 **)((u8 *)arg0 + 0x50))[0xA2] != 0) {
        func_80093AB8(arg0, arg1);
        return;
    }
    if ((func_800A89F8() != func_800A4C68(arg0)) || ((*(u8 **)((u8 *)arg0 + 0x50))[0x18] != 0)) {
        if ((*(u8 **)((u8 *)arg0 + 0x50))[0x17] != 0) {
            temp_v0 = (*(u8 **)((u8 *)arg0 + 0x50)) + 0x78;
            if (*(Unk80132ED0 **)((*(u8 **)((u8 *)arg0 + 0x50)) + 0x84) != NULL) {
                if (temp_v0[4] != 0) {
                    temp_v0[4] = 0;
                    func_800A7108(*(Unk80132ED0 **)(temp_v0 + 0xC), *(f32 *)temp_v0);
                } else if (temp_v0[9] != 0) {
                    temp_v0[9] = 0;
                    func_800A7130(*(Unk80132ED0 **)(temp_v0 + 0xC), temp_v0[8]);
                }
            }
            sp50 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x1C);
            func_8009216C(arg0, sp60, sp6C);
            func_80094070((u8 *)arg0, sp60);
            func_800EE7F8(sp54, (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x2C));
            func_800EF04C(sp60, (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x44));
            func_800EF04C(sp54, (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x44));
            if (func_800E3E8C(sp60, *(f32 *)((*(u8 **)((u8 *)arg0 + 0x50)) + 0x1C) * *(f32 *)((*(u8 **)((u8 *)arg0 + 0x50)) + 0x74)) &&
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC) != 0) {
                sp3C = func_80092B04(arg0, 1);
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x10] == 0) {
                    func_8008CA98(arg0);
                    func_8008C200(**(s16 **)((u8 *)arg0 + 0x50), (BtIntPtr)func_800B27E0((u8 *)sp3C), (BtIntPtr)func_8008AEDC(baanim_getAnimCtrlPtr(arg0)));
                    (*(u8 **)((u8 *)arg0 + 0x50))[0x13] ^= 1;
                }
                (*(u8 **)((u8 *)arg0 + 0x50))[0x10] = 1;
                func_800A06E8((BtIntPtr)arg0);
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0xC4] != 0) {
                    func_800EFA4C(sp44, 0.0f, sp6C[1], 0.0f);
                    sp6C[1] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC8);
                    func_800DF4CC((BtIntPtr)sp44);
                }
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x12] != 0) {
                    func_800DF818(func_80100A74((s16)(*(u8 **)((u8 *)arg0 + 0x50))[0x12], 0));
                }
                func_800DF72C((BtIntPtr)func_800AE080(**(s16 **)((u8 *)arg0 + 0x50)));
                func_800DF47C((BtIntPtr)func_80092234, (BtIntPtr)arg0);
                func_800923A8(arg0, 1);
                func_800DF720(func_80100AC4((*(u8 **)((u8 *)arg0 + 0x50))[0x12]));
                func_800DF440(0);
                func_800DE448(sp60, sp6C, sp50, sp54, sp3C);
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x11] != 0) {
                    func_800923A8(arg0, 0);
                    _babackpack_entrypoint_3(arg0, sp60, sp6C, sp50, sp54);
                }
            }
        }
    }
}

void func_8009272C(s32 *arg0, s32 arg1) {
    ((u8 *)arg0[20])[17] = arg1;
}

u32 func_80092738(s32 *arg0) {
    return ((u8 *)arg0[20])[17];
}

void func_80092744(s32 *arg0, s32 arg1) {
    ((u8 *)arg0[20])[0x88] = arg1;
}

void func_80092750(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x89))) = arg1;
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x8A))) = arg2;
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x8B))) = arg3;
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x8C))) = (s8) arg4;
}

/* extern */

void func_80092778(PlayerState *arg0) {
    void _bapreload_entrypoint_0(void *arg0, s32 arg1, s16 *arg2, s16 *arg3);
    void func_80092EC8(PlayerState *, s32);
    void func_8009312C(PlayerState *, s32);
    s32 func_800A3274();
    s16 sp1E;
    s16 sp1C;

    _bapreload_entrypoint_0(arg0, func_800A3274(), &sp1E, &sp1C);
    func_80092EC8(arg0, sp1E);
    func_8009312C(arg0, sp1C);
}

/* extern */

void func_800927C4(u32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    typedef struct Actor {
        Unk80132ED0 *unk0;
    } Actor;
    void func_800A70D0(Unk80132ED0 *, s32);
    void func_800A7108(Unk80132ED0 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6BE4(BtIntPtr);
    Actor *func_80108474(u32, f32 *, s32);
    struct unknown50_s {
        u8 pad0[0x78];
        f32 unk78;
        u8 pad7C[8];
        Unk80132ED0 *unk84;
    };
    f32 sp28[4];
    PlayerState *temp_s0;
    struct unknown50_s *temp_v0;

    if (func_800F6BE4(arg4) != 0) {
        temp_s0 = func_800F53D0(arg4);
        func_800EFA4C(sp28, arg1, arg2, arg3);
        (*(struct unknown50_s **)&temp_s0->pad48[8])->unk84 = func_80108474(arg0, sp28, 0)->unk0;
        func_800A70D0((*(struct unknown50_s **)&temp_s0->pad48[8])->unk84, temp_s0->unk184);
        temp_v0 = *(struct unknown50_s **)&temp_s0->pad48[8];
        func_800A7108(temp_v0->unk84, temp_v0->unk78);
    }
}

void func_80092864(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x78))) = arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x7C))) = 1;
}

void func_80092880(PlayerState *arg0, s32 arg1) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x80))) = (s8) arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x81))) = 1;
}

void func_80092898(PlayerState *arg0) {
    void _babackpack_entrypoint_9(PlayerState *);
    s16 func_800AE020(void);
    void *func_800AE080(s16);
    void func_800AE6FC(s16 *, s16);
    u8 *func_800DBFF8(void);
    s16 func_800E09B8(s32);
    void func_800EFD24(f32 *);
    void func_800936E8(void *, s32);
    void func_80093700(void *, s32);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    void func_80093230(PlayerState *, f32);
    void func_800931AC(PlayerState *, s32);
    s32 pad;
    s16 *sp20;
    f32 temp_f0;
    u8 *temp_v0;

    _babackpack_entrypoint_9(arg0);
    (*(u8 **)&arg0->pad48[8])[0x11] = 0;
    (*(u8 **)&arg0->pad48[8])[0x14] = 0xFF;
    (*(u8 **)&arg0->pad48[8])[0x10] = 0;
    (*(u8 **)&arg0->pad48[8])[0x16] = 0;
    (*(u8 **)&arg0->pad48[8])[0x12] = 0;
    (*(u8 **)&arg0->pad48[8])[0x13] = 0;
    *(s16 *)(*(u8 **)&arg0->pad48[8] + 0xC) = 0;
    (*(u8 **)&arg0->pad48[8])[0xA2] = 0;
    *(s16 *)(*(u8 **)&arg0->pad48[8] + 0x9C) = 0;
    func_800936E8(arg0, 0);
    func_80093700(arg0, 1);
    **(s16 **)&arg0->pad48[8] = func_800AE020();
    sp20 = func_800AE080(**(s16 **)&arg0->pad48[8]);
    func_800AE6FC(sp20, func_800E09B8(0xA));
    (*(u8 **)&arg0->pad48[8])[0x88] = 0;
    *(u8 **)(*(u8 **)&arg0->pad48[8] + 4) = func_800DBFF8();
    *(void **)(*(u8 **)&arg0->pad48[8] + 0x84) = NULL;
    (*(u8 **)&arg0->pad48[8])[0x7C] = 0;
    (*(u8 **)&arg0->pad48[8])[0x81] = 0;
    func_800EFD24((f32 *)(*(u8 **)&arg0->pad48[8] + 0x2C));
    func_800EFD24((f32 *)(*(u8 **)&arg0->pad48[8] + 0x38));
    func_800EFD24((f32 *)(*(u8 **)&arg0->pad48[8] + 0x44));
    *(f32 *)(*(u8 **)&arg0->pad48[8] + 0x20) = 0.0f;
    temp_v0 = *(u8 **)&arg0->pad48[8];
    temp_f0 = *(f32 *)(temp_v0 + 0x20);
    *(f32 *)(temp_v0 + 0x24) = temp_f0;
    *(f32 *)(*(u8 **)&arg0->pad48[8] + 0x28) = temp_f0;
    func_80093370(arg0, 1);
    func_8009337C(arg0, 1);
    func_80093230(arg0, 1.0f);
    (*(u8 **)&arg0->pad48[8])[0x15] = 0;
    func_800931AC(arg0, 1);
    func_80092778(arg0);
    func_80092864(arg0, 1.0f);
}

void func_80092A1C(PlayerState *arg0) {
    void func_80092EC8(PlayerState *, s32);
    void func_8009359C(void *, s32);
    void func_800ADFE0(s16);
    void func_800DBFD8(void *);
    void func_800A70B0(void *);
    void _babackpack_entrypoint_8(PlayerState *);
    void *temp_a0;

    func_80092EC8(arg0, 0);
    func_8009359C(arg0, 0);
    func_800ADFE0(**(s16 **)&arg0->pad48[8]);
    **(s16 **)&arg0->pad48[8] = 0;
    func_800DBFD8((*(void ***)&arg0->pad48[8])[1]);
    (*(void ***)&arg0->pad48[8])[1] = NULL;
    temp_a0 = (*(void ***)&arg0->pad48[8])[0x21];
    if (temp_a0 != NULL) {
        func_800A70B0(temp_a0);
    }
    (*(void ***)&arg0->pad48[8])[0x21] = NULL;
    _babackpack_entrypoint_8(arg0);
}

void func_80092AA4(PlayerState* arg0)
{
    (*(s32 **)((u8 *)arg0 + 0x50))[0x21] = 0;
}

void func_80092AB0(PlayerState* arg0)
{
    func_800E0ACC(func_80092AD8(arg0));
}

/* extern */

Unkfunc_800E0960_1 *func_80092AD8(PlayerState *arg0) {
    void *func_800AE080(s16);
    Unkfunc_800E0960_1 *func_800AE6BC(BtIntPtr);
    return func_800AE6BC(func_800AE080(*(*(s16 **)((s8 *)(arg0) + (0x50)))));
}

BtIntPtr func_80092B04(PlayerState *arg0, s32 arg1) {
    s32 func_80093F7C(u8 *, s32);
    BtIntPtr func_800D674C(s32);
    void func_800D62E4(s32);
    BtIntPtr result;
    s16 asset;
    PlayerState *self = arg0;

    asset = (*(s16 **)((u8 *)self + 0x50))[6];
    if (asset == 0x607) {
        return func_80093F7C((u8 *)arg0, arg1);
    }
    result = func_800D674C(asset);
    if (arg1 == 0) {
        func_800D62E4((*(s16 **)((u8 *)self + 0x50))[6]);
    }
    return result;
}

s32 func_80092B80(PlayerState *arg0)
{
    return (*(s16 **)((u8 *)arg0 + 0x50))[6];
}

f32 func_80092B8C(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg1, (u8 *)(*(u32 *)((u8 *)arg0 + 0x50)) + 0x64);
    return *(f32 *)((u8 *)(*(u32 *)((u8 *)arg0 + 0x50)) + 0x70);
}

u32 func_80092BC4(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x50))[0xC4];
}

f32 func_80092BD0(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC8);
}

f32 func_80092BDC(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x1C);
}

f32 func_80092BE8(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x28);
}

f32 func_80092BF4(PlayerState *arg0)
{
    return *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x30);
}

void func_80092C00(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0, 0x1, arg1);
}

void func_80092C24(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0,0x2,arg1);
}

void func_80092C48(PlayerState* arg0,f32* arg1)
{
    func_800921E0(arg0,0x7,arg1);
}

void func_80092C6C(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x6,arg1);
}

/* extern */

void func_80092C90(void *arg0, f32 arg1[3], s32 arg2) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800DBEFC(s32 *, s32, f32[3]);
    int func_800EEEA8(f32[3]);
    func_800DBEFC((*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
    if (func_800EEEA8(arg1) != 0) {
        func_8009C128(arg0, arg1);
    }
}

/* extern */

int func_80092CDC(void *arg0, f32 arg1[3], s32 arg2) {
    void func_800DBEFC(s32 *, s32, f32[3]);
    int func_800EEF24(f32[3]);
    func_800DBEFC((*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (4))), arg2, arg1);
    return func_800EEF24(arg1);
}

void func_80092D18(void *arg0, BtIntPtr arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, *(u8 **)((u8 *)arg0 + 0x50) + 0x44);
}

void func_80092D44(PlayerState *player, f32 dst[3]) {
    void func_800921E0(PlayerState *, s32, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 tmp2[3];
    f32 tmp1[3];
    func_800921E0(player, 4, tmp1);
    func_800921E0(player, 3, tmp2);
    func_800EE780(dst, tmp1, tmp2);
    func_800EF334(dst, 0.5f);
}

void func_80092D9C(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x3,arg1);
}

void func_80092DC0(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x4,arg1);
}

void func_80092DE4(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x8,arg1);
}

void func_80092E08(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x9,arg1);
}

void func_80092E2C(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0xA,arg1);
}

u32 func_80092E50(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x15);
}

void func_80092E5C(BtIntPtr arg0,BtIntPtr arg1)
{
    func_800921E0(arg0,0x5,arg1);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(void *) func_80092E80(void *arg0) {
    void *func_800AE080(s16);
    BT_NATIVE_ONLY(return) func_800AE080(*(*(s16 **)((s8 *)(arg0) + (0x50))));
}

u32 func_80092EA4(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x17);
}

u32 func_80092EB0(u32 *arg0)
{
    return *((u8 *) arg0[20] + 0x18);
}

void func_80092EBC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 20) = arg1;
}

void func_80092EC8(PlayerState *arg0, s32 arg1) {
    void func_80093FD4(BtIntPtr, s32);
    u32 func_800A25D0(void *);
    void func_800ADD80(s16, u8 *);
    f32 func_800B2354(void *);
    void func_800B237C(void *, f32 *, f32 *);
    u8 *func_800B26F0(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s16 func_80100D24(BtIntPtr, s32, s32, s32, s32, s32);
    void func_80100E18(s16);
    BtIntPtr sp2C;
    s32 flag;
    f32 scale;
    s32 old;
    u8 handle;
    u8 *data;

    data = *(u8 **)((u8 *)arg0 + 0x50);
    old = *(s16 *)(data + 0xC);
    if (arg1 != old) {
        if (old != 0) {
            func_800D70F8(old, 0);
            func_800D6CEC(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC));
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xE) = 0;
            data = *(u8 **)((u8 *)arg0 + 0x50);
        }
        handle = *(u8 *)(data + 0x12);
        if (handle != 0) {
            func_80100E18((s16)handle);
            *(u8 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x12) = 0;
            data = *(u8 **)((u8 *)arg0 + 0x50);
        }
        *(s16 *)(data + 0xC) = arg1;
        func_80093FD4((BtIntPtr)arg0, arg1);
        if (arg1 != 0) {
            sp2C = func_80092B04(arg0, 0);
            func_800D70F8(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC), 1);
            func_800ADD80(*(s16 *)*(u8 **)((u8 *)arg0 + 0x50), func_800B27E0((u8 *)sp2C));
            if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x12) == 0) {
                if (func_800B26F0((u8 *)sp2C) != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
                *(u8 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x12) = func_80100D24(sp2C, *(s16 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xC), flag, func_800A25D0(arg0), 0, 0);
            }
            func_800B237C((void *)func_800B2840(sp2C), (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x50), (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x5C));
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x58) = 0.0f;
            data = *(u8 **)((u8 *)arg0 + 0x50);
            *(f32 *)(data + 0x50) = *(f32 *)(data + 0x58);
            data = *(u8 **)((u8 *)arg0 + 0x50);
            func_800EE7F8((f32 *)(data + 0x64), (f32 *)(data + 0x50));
            data = *(u8 **)((u8 *)arg0 + 0x50);
            *(f32 *)(data + 0x70) = *(f32 *)(data + 0x5C);
            scale = func_800B2354((void *)func_800B2840(sp2C));
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x74) = scale;
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x60) = scale;
        }
    }
}

void func_80093070(PlayerState *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    struct VertexListView;
    u32 func_800A25D0(void *);
    void func_800B25D8(struct VertexListView *, struct VertexListView *, s32);
    BtIntPtr func_800B2840(BtIntPtr);
    BtIntPtr func_800D674C(s32);
    BtIntPtr func_80100A74(s16, s32);
    s16 func_80100D24(BtIntPtr, s32, s32, s32, s32, s32);
    void func_80100E18(s16);
    BtIntPtr sp34;
    BtIntPtr sp30;
    BtIntPtr sp2C;
    s32 sp20;
    s32 var_a3;
    s32 temp_v0;
    u8 temp_v1;

    sp34 = func_800D674C(arg2);
    sp30 = func_800D674C(arg1);
    temp_v0 = func_800A25D0(arg0);
    var_a3 = temp_v0;
    temp_v1 = *arg3;
    if (temp_v1 != 0) {
        sp20 = temp_v0;
        func_80100E18((s16)temp_v1);
        var_a3 = sp20;
    }
    *arg3 = func_80100D24(sp34, arg2, 1, var_a3, 0, 0);
    sp2C = func_800B2840(sp34);
    func_800B25D8(func_80100A74(*arg3, 0), sp2C, sp30);
}    typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; } Obj1E6B900_func_8009312C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009312C(PlayerState *arg0, s32 arg1) {
    void func_80093070(PlayerState *, s32, s32, u8 *);
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg1 != 0) {
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        if (arg1 != (((Obj1E6B900_func_8009312C_temp_v0 *)temp_v0)->unkE)) {
            (((Obj1E6B900_func_8009312C_temp_v0 *)temp_v0)->unkE) = arg1;
            temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
            func_80093070(arg0, arg1, (((Obj1E6B900_func_8009312C_temp_v0 *)temp_v0)->unkC), temp_v0 + 0x12);
        }
    }
}    typedef struct { u8 pad0[0x9C]; s16 unk9C; s16 unk9E; } Obj1E6B900_func_8009316C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009316C(PlayerState *arg0, s32 arg1) {
    void func_80093070(PlayerState *, s32, s32, u8 *);
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg1 != 0) {
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        if (arg1 != (((Obj1E6B900_func_8009316C_temp_v0 *)temp_v0)->unk9E)) {
            (((Obj1E6B900_func_8009316C_temp_v0 *)temp_v0)->unk9E) = arg1;
            temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
            func_80093070(arg0, arg1, (((Obj1E6B900_func_8009316C_temp_v0 *)temp_v0)->unk9C), temp_v0 + 0xA0);
        }
    }
}    typedef struct { u8 pad0[0x15]; u8 unk15; } Obj1E6B900_func_800931AC_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

/* extern */

void func_800931AC(PlayerState *arg0, s32 arg1) {
    f32 func_800136E4(f32);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 temp_v1;
    s32 temp_a0;
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    temp_a0 = 2;
    temp_v1 = (((Obj1E6B900_func_800931AC_var_v0 *)var_v0)->unk15);
    if ((arg1 != temp_v1) && ((arg1 == temp_a0) || (temp_a0 == temp_v1))) {
        yaw_setIdeal(arg0, func_800136E4(yaw_get(arg0) + 180.0f));
        yaw_applyIdeal(arg0);
        var_v0 = (*(void **)((s8 *)(arg0) + (0x50)));
    }
    (*(s8 *)((s8 *)(var_v0) + (0x15))) = (s8) arg1;
} 

/* extern */

void func_80093230(PlayerState *arg0, f32 arg1) {
    void func_800EF334(f32 *, f32);
    u8 *temp_v0;

    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x1C))) = arg1;
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    (*(f32 *)((s8 *)(temp_v0) + (0x70))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x1C))) * (*(f32 *)((s8 *)(temp_v0) + (0x5C))));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    (*(f32 *)((s8 *)(temp_v0) + (0x74))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x1C))) * (*(f32 *)((s8 *)(temp_v0) + (0x60))));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
    func_800EF334((f32 *)(temp_v0 + 0x64), (*(f32 *)((s8 *)(temp_v0) + (0x1C))));
}

/* extern */

void func_8009328C(PlayerState *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x28))) = func_800136E4(arg1);
}

void func_800932BC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 200) = arg1;
}

void func_800932CC(PlayerState *arg0, s32 arg1)
{
    u8 *temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);

    if (arg1 != temp_v0[0xC4]) {
        if (arg1 != 0) {
            *(f32 *)(temp_v0 + 0xC8) = 0.0f;
            temp_v0 = *(u8 **)((u8 *)arg0 + 0x50);
        }
        temp_v0[0xC4] = arg1;
    }
}

void func_80093300(void *arg0, f32 arg1) {
    void func_8009332C(void *arg0, f32 arg1);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x50) + 0x30) = arg1;
    func_8009332C(arg0, arg1);
}

void func_8009332C(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 60) = arg1;
}

/* extern */

void func_8009333C(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, f32 *bt_a1)) {
    void func_800EE7F8();
#ifdef BT_NATIVE
    ((void (*)())func_800EE7F8)(BT_PASS2(((*(s32 *)((s8 *)(arg0) + (0x50))) + 0x44), bt_a1));
#else
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x50))) + 0x44);
#endif
}

void func_80093360(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x50)))) + (0x48))) = arg1;
}

void func_80093370(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 23) = arg1;
}

void func_8009337C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 24) = arg1;
}

void func_80093388(void *arg0) {
    f32 mlAbsF(f32);

    f32 difference;
    f32 step;

    difference = *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x3C)
               - *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x30);
    step = mlAbsF(difference);
    if (step < 0.01f) {
        *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x30) =
            *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x3C);
    } else {
        if (step > 5.0f) {
            step = 1.0f;
        }
        if (difference > 0.0f) {
            *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x30) += step;
        } else {
            *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x30) -= step;
        }
    }
}

void func_80093448(void *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    union {
        f32 f[3];
        s32 i[3];
    } position;

    if (*(s32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 0x84) == 0) {
        func_8009C128(arg0, position.f);
        _chbaddiesetup_entrypoint_5(func_800927C4, 0x215,
            position.i[0], position.i[1], position.i[2],
            ((Obj1E6B900_arg0 *)arg0)->unk184);
    }
    func_80093388(arg0);
    func_80092018(arg0);
    func_800920C8(arg0);
}

/* extern */

void func_800934C4(void *arg0) {
    s32 func_800DC060(s32);
    s32 temp;

    temp = *(s32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 4);
    if (temp != 0) {
        *(s32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 4) = func_800DC060(temp);
    }
}

/* extern */

#ifdef BT_NATIVE
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80093504(void *arg0, s32 bt_a1, s32 bt_a2) {
#else
void func_80093504(void *arg0) {
#endif
    s32 func_800F23D0(s32);
    BT_NATIVE_ONLY(return) func_800F23D0((*(s32 *)((s8 *)(arg0) + (0x50))) + 0xCC);
}    typedef struct { u8 pad0[0xA1]; u8 unkA1; u8 padA2[0x3]; u8 unkA5; } Obj1E6B900_func_80093528_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80093528(void *arg0) {
    s32 func_800DBEB0(s32, void *);
    u8 temp_v1;
    void *temp_v0;

    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x1A))) = 0;
    func_800DBEB0((*(s32 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (4))), arg0);
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x16))) = 0;
    (*(u8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0xA5))) = 0U;
    temp_v0 = (((Obj1E6B900_arg0 *)arg0)->unk50);
    temp_v1 = (((Obj1E6B900_func_80093528_temp_v0 *)temp_v0)->unkA5);
    (((Obj1E6B900_func_80093528_temp_v0 *)temp_v0)->unkA1) = temp_v1;
    (*(u8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x10))) = temp_v1;
}    typedef struct { u8 pad0[0x8]; s32 unk8; u8 padC[0x88]; s32 unk94; } Obj1E6B900_func_80093584_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80093584(void *arg0) {
    void *temp_v0;

    (*(s32 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x94))) = 0;
    temp_v0 = (((Obj1E6B900_arg0 *)arg0)->unk50);
    (((Obj1E6B900_func_80093584_temp_v0 *)temp_v0)->unk8) = (s32) (((Obj1E6B900_func_80093584_temp_v0 *)temp_v0)->unk94);
}

void func_8009359C(void *arg0, s32 arg1) {
    BtIntPtr func_80093738(void *);
    u32 func_800A25D0(void *);
    void func_800ADFE0(s16);
    s16 func_800AE020(void);
    void *func_800AE080(s16);
    void func_800AE6FC(s16 *, s16);
    u8 *func_800B26F0(u8 *);
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s16 func_800E09B8(s32);
    s16 func_80100D24(BtIntPtr, s32, s32, s32, s32, s32);
    void func_80100E18(s16);
    BtIntPtr sp34;
    s32 sp2C;
    s32 var_a2;
    s32 old;
    u8 handle;
    u8 *state;
    s16 *list;

    state = *(u8 **)((u8 *)arg0 + 0x50);
    old = *(s16 *)(state + 0x9C);
    state += 0x90;
    if (arg1 != old) {
        if (old != 0) {
            handle = state[0x10];
            if (handle != 0) {
                func_80100E18(handle);
                state[0x10] = 0;
            }
            func_800ADFE0(*(s16 *)state);
            *(s16 *)state = 0;
            func_800D70F8(*(s16 *)(state + 0xC), 0);
            func_800D6CEC(*(s16 *)(state + 0xC));
            *(s16 *)(state + 0xC) = 0;
            *(s16 *)(state + 0xE) = 0;
        }
        if (arg1 == 0) {
            state[0x12] = 0;
            return;
        }
        *(s16 *)(state + 0xC) = arg1;
        sp34 = func_80093738(arg0);
        func_800D70F8(*(s16 *)(state + 0xC), 1);
        if (func_800B26F0(sp34) != 0) {
            var_a2 = 1;
        } else {
            var_a2 = 0;
        }
        sp2C = func_800A25D0(arg0);
        state[0x10] = func_80100D24(sp34, *(s16 *)(state + 0xC), var_a2, sp2C, 0, 0);
        *(s16 *)state = func_800AE020();
        list = func_800AE080(*(s16 *)state);
        func_800AE6FC(list, func_800E09B8(0xC));
    }
}

void func_800936CC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 162) = arg1;
}

void func_800936D8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 152) = arg1;
}

void func_800936E8(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 163) = arg1;
}

u32 func_800936F4(void *arg0) {
    return *(u8 *)((u8 *)*&((Obj1E6B900_arg0 *)arg0)->unk50 + 163);
}

void func_80093700(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 80) + 25) = arg1;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(Unkfunc_800E0960_1 *) func_8009370C(u8 *arg0) {
    void *func_800AE080(s16);
    Unkfunc_800E0960_1 *func_800AE6BC(BtIntPtr);
    BT_NATIVE_ONLY(return) func_800AE6BC(func_800AE080((*(s16 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x90)))));
}

/* extern */

BtIntPtr func_80093738(void *arg0) {
    BtIntPtr func_800D674C(s32);
    return func_800D674C((*(s16 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0x9C))));
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Obj1E6B900_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

s32 func_8009375C(u8 *arg0, Gfx **arg1, s32 arg2) {
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    struct anctrl_s *func_8008D04C(PlayerState *);
    void *func_8008AEDC(void *);
    void func_8008C200(s16, BtIntPtr, BtIntPtr);
    void *func_800AE080(s16);
    void func_800AE598(s32 *, s32 *);
    struct anctrl_s *sp2C;
    s16 sp2A;
    BtIntPtr sp24;
    s32 sp20;
    u8 *temp_s0;

    sp20 = ((Obj1E6B900_arg1 *)arg1)->unk4 + 0x40;
    switch (arg2) {
    case 0:
        sp24 = func_80092B04((PlayerState *)arg0, 0);
        sp2A = *(s16 *)(*(u8 **)(arg0 + 0x50));
        sp2C = baanim_getAnimCtrlPtr((PlayerState *)arg0);
        *(s8 *)(*(u8 **)(arg0 + 0x50) + 0x10) = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x50) + 8) = sp20;
        break;
    case 1:
        sp24 = func_80093738(arg0);
        sp2A = *(s16 *)(*(u8 **)(arg0 + 0x50) + 0x90);
        sp2C = func_8008D04C((PlayerState *)arg0);
        *(s8 *)(*(u8 **)(arg0 + 0x50) + 0xA1) = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x94) = sp20;
        break;
    }
    temp_s0 = func_800B27E0((u8 *)sp24);
    func_8008C200(sp2A, (BtIntPtr)temp_s0, (BtIntPtr)func_8008AEDC(sp2C));
    BT_NATIVE_ONLY(void *bt_result;) func_800AE598((s32 *)BT_IDO_ONLY(func_800AE080(sp2A)) BT_NATIVE_ONLY((bt_result = func_800AE080(sp2A))), &((Obj1E6B900_arg1 *)arg1)->unk4); BT_NATIVE_ONLY(return (s32)bt_result;)
}

s32 func_80093864(u8 *arg0, Gfx **arg1, s32 arg2) {
    void func_800A06E8(BtIntPtr);
    void func_800A0714(BtIntPtr, s32);
    s32 func_800A946C(void);
    void *func_800AE080(s16);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF3E0(void);
    void func_800DF440(s32);
    void func_800DF47C(s32, BtIntPtr);
    void func_800DF574(s32);
    void func_800DF714(s32);
    void func_800DF720(BtIntPtr);
    void func_800DF72C(BtIntPtr);
    void func_800DF818(BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    BtIntPtr func_80100A74(s16, s32);
    BtIntPtr func_80100AC4(s16);
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;
    BtIntPtr sp3C;
    void *sp38;
    u8 temp_v1;
    u8 temp_v1_2;

    switch (arg2) {
    case 0:
        func_8009216C((PlayerState *)arg0, sp50, sp5C);
        sp40 = *(f32 *)(*(u8 **)(arg0 + 0x50) + 0x1C);
        sp3C = func_80092B04((PlayerState *)arg0, 1);
        sp38 = func_800AE080(*(s16 *)(*(u8 **)(arg0 + 0x50)));
        if (sp3C != 0) {
            temp_v1 = *(u8 *)(*(u8 **)(arg0 + 0x50) + 0x12);
            if (temp_v1 != 0) {
                func_800DF720(func_80100AC4((s16)temp_v1));
                func_800DF818(func_80100A74(*(u8 *)(*(u8 **)(arg0 + 0x50) + 0x12), 0));
            }
            func_800DF714(*(s32 *)(*(u8 **)(arg0 + 0x50) + 8));
            func_800DF72C((BtIntPtr)sp38);
            func_800A06E8((BtIntPtr)arg0);
            func_800DF47C((BtIntPtr)func_80092234, (BtIntPtr)arg0);
            func_800DF440(0);
            if (func_800A946C() == 1) {
                func_800DF574(1);
            }
        }
        break;
    case 1:
        sp40 = *(f32 *)(*(u8 **)(arg0 + 0x50) + 0x98);
        sp3C = func_80093738(arg0);
        sp38 = func_800AE080(*(s16 *)(*(u8 **)(arg0 + 0x50) + 0x90));
        func_800EE7F8(sp50, (f32 *)(*(u8 **)(arg0 + 0x50) + 0xAC));
        func_800EE7F8(sp5C, (f32 *)(*(u8 **)(arg0 + 0x50) + 0xB8));
        if (sp3C != 0) {
            temp_v1_2 = *(u8 *)(*(u8 **)(arg0 + 0x50) + 0xA0);
            if (temp_v1_2 != 0) {
                func_800DF720(func_80100AC4((s16)temp_v1_2));
                func_800DF818(func_80100A74(*(u8 *)(*(u8 **)(arg0 + 0x50) + 0xA0), 0));
            }
            func_800DF714(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x94));
            func_800DF72C((BtIntPtr)sp38);
            func_800DF3E0();
            func_800DF47C((BtIntPtr)func_80092224, (BtIntPtr)arg0);
            func_800A0714((BtIntPtr)arg0, *(s16 *)(*(u8 **)(arg0 + 0x50) + 0x9C));
        }
        break;
    }
    func_800EE7F8(sp44, (f32 *)(*(u8 **)(arg0 + 0x50) + 0x2C));
    func_800EF04C(sp50, (f32 *)(*(u8 **)(arg0 + 0x50) + 0x44));
    func_800EF04C(sp44, (f32 *)(*(u8 **)(arg0 + 0x50) + 0x44));
    if (sp3C != 0) {
        func_800923A8(arg0, arg2 == 0);
        func_800DE448(sp50, sp5C, sp40, sp44, sp3C);
    }
    BT_NATIVE_ONLY(return 0;) }

void func_80093AB8(void *arg0, Gfx **arg1) {
    void _bsfirstp_entrypoint_1(u8 *, s32);
    s32 _dbzone_entrypoint_4(s32, f32 *, u8 *);
    s32 _glzone_entrypoint_6(s32, u8 *, s32);
    void func_8008CA98(PlayerState *);
    void func_8008D058(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    int func_800A4C68(void *);
    s32 func_800A89F8(void);
    s32 func_800BEC1C(void);
    s32 func_800BEC28(s32);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 sp44;
    s32 sp40;
    f32 sp34[3];
    s32 count;
    struct ZoneCount { u8 pad[0xA4]; unsigned int count : 8; };
    s32 sp2C;

    if ((*(u8 **)((u8 *)arg0 + 0x50))[0x17] != 0) {
        sp44 = func_800A89F8();
        switch ((*(u8 **)((u8 *)arg0 + 0x50))[0xA2]) {
        case 1:
            sp40 = 3;
            break;
        case 2:
        case 3:
            switch ((*(u8 **)((u8 *)arg0 + 0x50))[0x19]) {
            case 0:
                sp40 = 3;
                break;
            case 1:
                sp40 = 3;
                if (func_800A4C68(arg0) == sp44) {
                    if ((*(u8 **)((u8 *)arg0 + 0x50))[0xA3] != 0) {
                        sp40 = 1;
                    } else if ((*(u8 **)((u8 *)arg0 + 0x50))[0x18] == 0) {
                        sp40 = 0;
                    }
                }
                break;
            }
            break;
        }
        switch (sp40) {
        case 0:
            return;
        case 1:
            break;
        case 3:
            func_8009C128(arg0, sp34);
            if (!func_800E3E8C(sp34,
                *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x1C) *
                *(f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x74))) {
                return;
            }
            sp2C = func_800BEC1C();
            if (sp2C != 0) {
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0xA5] == 0) {
                    (*(u8 **)((u8 *)arg0 + 0x50))[0xA5] = 1;
                    func_800EF04C(sp34, (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0x64));
                    (*(u8 **)((u8 *)arg0 + 0x50))[0xA4] = _dbzone_entrypoint_4(
                        func_800BEC28(0), sp34, *(u8 **)((u8 *)arg0 + 0x50) + 0xA6);
                }
                if ((*(struct ZoneCount **)((u8 *)arg0 + 0x50))->count != 0 &&
                    !_glzone_entrypoint_6(sp2C, *(u8 **)((u8 *)arg0 + 0x50) + 0xA6,
                        (*(struct ZoneCount **)((u8 *)arg0 + 0x50))->count)) {
                    return;
                }
            }
        }
        switch ((*(u8 **)((u8 *)arg0 + 0x50))[0xA2]) {
        case 1:
            if ((*(u8 **)((u8 *)arg0 + 0x50))[0x18] != 0 || func_800A4C68(arg0) != sp44) {
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x10] == 0) {
                    func_8008CA98(arg0);
                    func_8009375C(arg0, arg1, 0);
                }
                func_80093864(arg0, arg1, 0);
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0xA3] != 0) {
                    func_8009216C(arg0, (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xAC),
                        (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + 0xB8));
                    if ((*(u8 **)((u8 *)arg0 + 0x50))[0xA1] == 0) {
                        func_8008D058(arg0);
                        func_8009375C(arg0, arg1, 1);
                    }
                    func_80093864(arg0, arg1, 1);
                }
            }
            break;
        case 2:
            if (sp40 == 3) {
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x10] == 0) {
                    _bsfirstp_entrypoint_1(arg0, 0);
                    func_8009375C(arg0, arg1, 0);
                }
                func_80093864(arg0, arg1, 0);
            }
            break;
        case 3:
            if (sp40 == 3) {
                if ((*(u8 **)((u8 *)arg0 + 0x50))[0x10] == 0) {
                    _bsfirstp_entrypoint_1(arg0, 0);
                    func_8009375C(arg0, arg1, 0);
                }
                func_80093864(arg0, arg1, 0);
            }
            break;
        }
    }
}

s32 func_80093DF4(void *arg0, s32 arg1) {
    return arg1 == (*(u8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk50)) + (0xA2))) ? 1 : 0;
}

/* extern */

void func_80093E18(u8 *arg0, BT_IDO_ONLY(Gfx **arg1) BT_PASS2(Gfx **arg1, BtIntPtr bt_a2)) {
    s32 pad;
    s32 _bsfirstp_entrypoint_0(u8 *, u8 *, u8 *);
    void _bsfirstp_entrypoint_1(u8 *, s32);
    s32 func_8009375C(u8 *, Gfx **, s32);
    s32 func_80093864(u8 *, Gfx **, s32);
    BtIntPtr func_800A5090(void *);
    s32 func_800A88C4(s32, BT_IDO_ONLY(BtIntPtr) BT_PASS2(BtIntPtr, BtIntPtr));
    s32 func_800A89F8();
    void func_800E44FC(Gfx **);
    s32 sp28;
    s32 sp24;
    u8 *temp_v0;

    sp24 = func_800A89F8();
    sp28 = func_800A88C4(sp24, BT_IDO_ONLY(func_800A5090(arg0)) BT_PASS2(func_800A5090(arg0), bt_a2));
    func_800E44FC(arg1);
    if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0xA1))) == 0) {
        _bsfirstp_entrypoint_1(arg0, 1);
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x50)));
        _bsfirstp_entrypoint_0(arg0, temp_v0 + 0xAC, temp_v0 + 0xB8);
        func_8009375C(arg0, arg1, 1);
    }
    func_80093864(arg0, arg1, 1);
    func_800A88C4(sp24, BT_IDO_ONLY(sp28) BT_PASS2(sp28, bt_a2));
    func_800E44FC(arg1);
}

/* extern */

f32 func_80093ECC(u8 *arg0, f32 *arg1, BtIntPtr arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32[3], f32[3]);
    void func_8009216C(PlayerState *, f32 *, f32 *);
    u8 *self = arg0;
    func_8009216C(self, arg1, arg2);
    func_800EE7F8(arg3, (f32 *)(*(u8 **)(self + 0x50) + 0x2C));
    func_800EF04C(arg1, (f32 *)(*(u8 **)(self + 0x50) + 0x44));
    func_800EF04C(arg3, (f32 *)(*(u8 **)(self + 0x50) + 0x44));
    return *(f32 *)(*(u8 **)(self + 0x50) + 0x1C);
}

s32 func_80093F30(s32 arg0) {
    s32 func_8009EA2C(void);
    extern s32 D_80117DD8[][4];
    extern s32 D_80117DDC[][4];
    if (func_8009EA2C() != 0) {
        return D_80117DDC[arg0][0];
    }
    return D_80117DD8[arg0][0];
}

/* extern */

s32 func_80093F7C(u8 *arg0, s32 arg1) {
    BtIntPtr func_800D674C(s32);
    void func_800D62E4(s32);
    struct { s32 pad; s32 value; } sp1C;
    s32 var_v1;

    sp1C.value = func_800D674C((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x10C))));
    var_v1 = sp1C.value;
    if (arg1 == 0) {
        func_800D62E4((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x10C))));
        var_v1 = sp1C.value;
    }
    return var_v1;
}

void func_80093FD4(BtIntPtr arg0, s32 arg1) {
    void func_800941C8(u8 *, s32);
    s32 func_800EA05C();
    extern s16 D_80117DF0[][2];
    s32 temp_v0;
    s32 var_a1;

    if (arg1 == 0x607) {
        temp_v0 = func_800EA05C();
        for (var_a1 = 0; D_80117DF0[var_a1][0] != -1; var_a1++) {
            if (temp_v0 == D_80117DF0[var_a1][0]) {
                break;
            }
        }
        func_800941C8(arg0, func_80093F30(D_80117DF0[var_a1][1]));
        return;
    }
    func_800941C8(arg0, 0);
}

void func_80094070(u8 *arg0, f32 *arg1) {
    s32 func_800D90A4(f32 *);
    void func_800E3980(f32 *);
    s32 func_800E488C(s32);
    s32 func_800E4BB8();
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800941C8(u8 *, s32);
    s32 func_800942D0(u8 *, s32);
    extern f32 D_80117DD0[][4];
    f32 distance;
    f32 sp30[3];
    s32 i;
    s32 sp28;

    if (*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x10C) != 0 && func_800D90A4((f32 *)(*(u8 **)(arg0 + 0x50) + 0x114)) != 0) {
        func_800E3980(sp30);
        distance = func_800EEAD4(arg1, sp30);
        for (i = 0; i < 2; i++) {
            if (distance < D_80117DD0[i][0]) {
                break;
            }
        }
        i--;
        sp28 = func_80093F30(i);
            if (sp28 != *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x10C)) {
            if (func_800942D0(arg0, i) != 0) {
                if (*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) != 0 && sp28 != *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110)) {
                    func_800E4BB8(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110));
                }
                *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) = sp28;
                if (func_800E488C(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110)) != 0) {
                    func_800941C8(arg0, *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110));
                }
            } else {
                if (*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) != 0) {
                    func_800E4BB8(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110));
                    *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) = 0;
                }
            }
        } else {
            if (*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) != 0) {
                func_800E4BB8(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110));
                *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) = 0;
            }
        }
    }
}

void func_800941C8(u8 *arg0, s32 arg1) {
    u32 func_800A25D0(void *);
    u8 *func_800B26F0(u8 *);
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s16 func_80100D24(BtIntPtr, s32, s32, s32, s32, s32);
    void func_80100E18(s16);
    s32 var_a2;
    s32 temp_a2;
    BtIntPtr sp2C;
    s32 sp34;
    u8 temp_v0;
    u8 *var_v1;

    var_v1 = *(u8 **)(arg0 + 0x50);
    temp_a2 = *(s32 *)(var_v1 + 0x10C);
    if (temp_a2 != 0) {
        func_800D70F8(temp_a2, 0);
        func_800D6CEC(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x10C));
        var_v1 = *(u8 **)(arg0 + 0x50);
    }
    temp_v0 = *(u8 *)(var_v1 + 0x12);
    if (temp_v0 != 0) {
        func_80100E18((s16)temp_v0);
        *(u8 *)(*(u8 **)(arg0 + 0x50) + 0x12) = 0;
        var_v1 = *(u8 **)(arg0 + 0x50);
    }
    *(s32 *)(var_v1 + 0x10C) = arg1;
    *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x110) = 0;
    if (arg1 != 0) {
        *(f32 *)(*(u8 **)(arg0 + 0x50) + 0x114) = 0.0f;
        sp2C = func_80093F7C(arg0, 0);
        func_800D70F8(*(s32 *)(*(u8 **)(arg0 + 0x50) + 0x10C), 1);
        if (func_800B26F0((u8 *)sp2C) != 0) {
            var_a2 = 1;
        } else {
            var_a2 = 0;
        }
        sp34 = var_a2;
        *(u8 *)(*(u8 **)(arg0 + 0x50) + 0x12) = func_80100D24(sp2C, *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x10C), var_a2, func_800A25D0(arg0), 0, 0);
    }
}

s32 func_800942D0(u8 *arg0, s32 arg1) {
    s32 func_8001BDAC(s32 *, s32);
    extern s32 D_80117DD4[][4];
    s32 sp1C;

    func_8001BDAC(&sp1C, 1);
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x50)))) + (0x110))) != 0) {
        sp1C += D_80117DD4[arg1][0];
    }
    return sp1C >= 0x32001;
}

s32 func_80094340(void)
{
	return 0x4;
}

s32 func_80094348(void *arg0, s32 arg1) {
    return ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (2))) & arg1) ? 1 : 0;
}

void func_80094370(BtIntPtr arg0)
{
    func_800946C4(arg0,0);
}

void func_80094390(PlayerState *arg0) {
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(PlayerState *, s32);
    void func_80094430(PlayerState *, f32);
    void func_8009E9F0(f32);
    s32 func_800C0638(void);
    s32 func_800C954C(void);
    s32 func_800D2498(u32, s32, u32);
    int func_800F6774(BtUIntPtr);
    s32 func_80101180(s32, s32, BtIntPtr);

    if ((func_800C954C() == 0) && (func_800F6774(arg0->unk184) != 0) && (_batimer_decrement(arg0, 0xD) != 0)) {
        func_8009E9F0(0.0f);
        func_80094430(arg0, 0.0f);
        func_80101180(0x1CD, 0x76, 0);
    }
    if (func_800C0638() == 0) {
        func_800D2498(0x105, (s32) _batimer_get(arg0, 0xD), 0);
    }
}

void func_80094430(PlayerState *arg0, f32 arg1) {
    void _batimer_set(PlayerState *, s32, f32);
    if (arg1 != 0.0f) {
        func_800946C4(arg0, 2);
    } else {
        func_80094370((BtIntPtr) arg0);
    }
    if (arg1 > 0.0f) {
        func_800947EC(arg0, 0x10, 1);
        _batimer_set(arg0, 0xD, arg1);
        return;
    }
    func_800947EC(arg0, 0x10, 0);
    _batimer_set(arg0, 0xD, 0.0f);
}

s32 func_800944E0(PlayerState *arg0, s32 arg1) {
    extern u8 D_80117E3C[];
    return D_80117E3C[arg1 * 2];
}

s32 func_800944F8(PlayerState *arg0, s32 arg1) {
    extern u8 D_80117E3D[];
    return D_80117E3D[arg1 * 2];
}

s32 func_80094510(PlayerState *arg0) {
    extern u8 *D_80117E30[];
    u8 *p = *(u8 **)((u8 *)arg0 + 0x64);
    return *(p[1] + D_80117E30[p[0]]);
}

/* extern */

void func_80094538(PlayerState *arg0) {
    f32 _batimer_get(PlayerState *, s32);
    void func_8009E9E4(s32 arg0);
    void func_8009E9F0(f32);
    func_8009E9E4(func_80094510(arg0));
    func_8009E9F0(_batimer_get(arg0, 0xD));
}

s32 func_80094574(void *arg0, s32 arg1) {
    s32 _gcegg_entrypoint_6(s32);
    s32 current;
    u8 *state;

    (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
    current = func_80094510(arg0);
    while (current != 0) {
        if (_gcegg_entrypoint_6(current) != 0 && current == arg1) {
            BT_IDO_ONLY(return;) BT_NATIVE_ONLY(return 0;)
        }
        state = *(u8 **)((u8 *)arg0 + 0x64);
        state[1]++;
        current = func_80094510(arg0);
    }
    (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
    current = func_80094510(arg0);
    while (current != 0) {
        if (_gcegg_entrypoint_6(current) != 0) {
            BT_IDO_ONLY(return;) BT_NATIVE_ONLY(return 0;)
        }
        state = *(u8 **)((u8 *)arg0 + 0x64);
        state[1]++;
        current = func_80094510(arg0);
    }
    (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
BT_NATIVE_ONLY(return 0;) }

/* extern */

void func_80094644(void *arg0) {
    void func_80094430(PlayerState *, f32);
    s32 func_80094574(void *, s32);
    s32 func_8009E964();
    f32 func_8009E970();
    s32 temp_f4;

    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk64)) + (2))) = 0;
    func_80094370((BtIntPtr) arg0);
    func_80094574(arg0, func_8009E964());
    temp_f4 = (s32) func_8009E970();
    if (temp_f4 != 0) {
        func_80094430(arg0, (f32) temp_f4);
    }
    (*(s8 *)((s8 *)((((Obj1E6B900_arg0 *)arg0)->unk64)) + (3))) = 0;
}

void func_800946C4(PlayerState *arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            func_800947EC(arg0, 1, 0);
            func_800947EC(arg0, 2, 0);
            func_800947EC(arg0, 4, 0);
            func_800947EC(arg0, 8, 0);
            break;
        case 1:
            func_800947EC(arg0, 1, 1);
            func_800947EC(arg0, 2, 1);
            func_800947EC(arg0, 4, 1);
            func_800947EC(arg0, 8, 0);
            break;
        case 2:
            func_800947EC(arg0, 1, 1);
            func_800947EC(arg0, 2, 1);
            func_800947EC(arg0, 4, 1);
            func_800947EC(arg0, 8, 0);
            break;
    }
    (*(u8 **)((u8 *)arg0 + 0x64))[0] = arg1;
    (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
}    typedef struct { u8 pad0[0x2]; u8 unk2; } Obj1E6B900_func_800947EC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x2]; u8 unk2; } Obj1E6B900_func_800947EC_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void func_800947EC(PlayerState *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x64)));
        (((Obj1E6B900_func_800947EC_temp_v0 *)temp_v0)->unk2) = (u8) ((((Obj1E6B900_func_800947EC_temp_v0 *)temp_v0)->unk2) | arg1);
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x64)));
    (((Obj1E6B900_func_800947EC_temp_v0_2 *)temp_v0_2)->unk2) = (u8) ((((Obj1E6B900_func_800947EC_temp_v0_2 *)temp_v0_2)->unk2) & ~arg1);
}

/* extern */

void func_80094824(PlayerState *arg0) {
    s32 bainput_func_80097C7C();
    s32 func_80094A10(PlayerState *);
    void func_80094C88(void *);
    void func_80094D04(void *);
    if (bainput_func_80097C7C() != 0) {
        func_80094A10(arg0);
        func_80094C88(arg0);
    }
    func_80094D04(arg0);
}

s32 func_80094864(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 bainput_func_80097C7C();
    void func_800D1824(s32);
    int func_800F6774(BtUIntPtr);
    void func_80094C88(void *);
    s32 func_80094DA8(void *);
    void func_80094E40(s32);
    s32 sp24;
    u8 state;

    if (func_800F6774(*(u32 *)((s8 *)arg0 + 0x184)) != 0) {
        if (func_80094348(arg0, 0x10) != 0) {
            func_80094390(arg0);
        }
        if (func_80094348(arg0, 8) != 0) {
            sp24 = _gcegg_entrypoint_5(func_80094510(arg0));
            if (func_80094348(arg0, 4) == 0) {
                func_800D1824(sp24);
            }
        }
        if (func_80094348(arg0, 1) == 0) {
            state = (*(u8 **)((s8 *)arg0 + 0x64))[3];
            switch (state) {
                case 0:
                    if (bainput_func_80097C7C(arg0) != 0) {
                        (*(u8 **)((s8 *)arg0 + 0x64))[3] = 1;
                        func_80094E40(func_80094510(arg0));
                        func_80094C88(arg0);
                    }
                    break;
                case 1:
                    func_80094824(arg0);
                    if (func_80094DA8(arg0) != 0) {
                        (*(u8 **)((s8 *)arg0 + 0x64))[3] = 2;
                        func_80094C88(arg0);
                    }
                    break;
                case 2:
                    func_80094824(arg0);
                    if (func_80094DA8(arg0) == 0) {
                        (*(u8 **)((s8 *)arg0 + 0x64))[3] = 0;
                    }
                    break;
            }
        }
    }
BT_NATIVE_ONLY(return 0;) }

/* extern */

int func_800949BC(PlayerState *arg0) {
    s32 func_8009E674(PlayerState *, s32);
    s32 _baeggfire_entrypoint_8(PlayerState *);
    s32 _bafpctrl_entrypoint_5(PlayerState *);
    s32 temp_t6;
    s32 temp_t7;
    s32 var_v0;

    return func_8009E674(arg0, 0x80000) != 0 ||
           (_bafpctrl_entrypoint_5(arg0) != 0 && _baeggfire_entrypoint_8(arg0) != 0);
}

s32 func_80094A10(PlayerState *arg0) {
    s32 _gcegg_entrypoint_6(s32);
    void func_80094E40(s32);
    s32 result;
    s32 previous;
    s32 current;
    u8 *state;

    previous = func_80094510(arg0);
    if (func_800949BC(arg0) != 0) {
        return previous;
    }
    do {
        state = *(u8 **)((u8 *)arg0 + 0x64);
        state[1]++;
        result = func_80094510(arg0);
        current = result;
        if (result == 0) {
            (*(u8 **)((u8 *)arg0 + 0x64))[1] = 0;
            current = func_80094510(arg0);
        }
    } while (_gcegg_entrypoint_6(current) == 0);
    if (current != previous) {
        func_80094E40(current);
    }
    return current;
}

/* extern */

void func_80094AB4(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    u8 func_80094C64(void *, s32);
    void func_800D1824(s32);
    s32 temp_v0;
    s32 sp1C;

    if (func_80094348(arg0, 2) == 0) {
        temp_v0 = func_80094C64(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (1))));
        if (temp_v0 != 0) {
            sp1C = temp_v0;
            if (_gcegg_entrypoint_6(temp_v0) != 0) {
                func_800D1824(_gcegg_entrypoint_5(sp1C));
            }
        }
    }
}

s32 func_80094B14(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _plsu_entrypoint_1(s32);
    int baflag_isTrue(PlayerState *, s32);
    void func_800D1824(s32);
    s32 func_800D1C38(s32);
    void func_800FC660(u32);
    s32 sp1C;

    sp1C = _gcegg_entrypoint_5(func_80094510(arg0));
    if ((baflag_isTrue(arg0, 0x34) != 0) ||
        ((func_80094348(arg0, 4) == 0) && (func_800D1C38(sp1C) != 0))) {
        func_800D1824(sp1C);
        func_800FC660(0xF);
        return 0;
    }
    if ((func_80094510(arg0) == 5) && (_plsu_entrypoint_1(0x11) != -1)) {
        return 0;
    }
    return 1;
}

/* extern */

s32 func_80094BC0(PlayerState *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    if (func_80094348(arg0, 4) != 0) {
        return 1;
    }
    return func_800D1A04(_gcegg_entrypoint_5(func_80094510(arg0)));
}

/* extern */

void func_80094C0C(PlayerState *arg0, s32 arg1) {
    s32 _gcegg_entrypoint_5(s32);
    s32 func_8009EA2C(void);
    void func_800D1804(s32);
    if ((func_80094348(arg0, 4) == 0) && ((arg1 != 2) || (func_8009EA2C() == 0))) {
        func_800D1804(_gcegg_entrypoint_5(arg1));
    }
}

u8 func_80094C64(void *arg0, s32 arg1) {
    extern u8 *D_80117E30[];
    return D_80117E30[**(u8 **)((u8 *)arg0 + 0x64)][arg1];
}

void func_80094C88(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    void func_800D1824(s32);
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if (_gcegg_entrypoint_6(var_s0) != 0) {
                func_800D1824(_gcegg_entrypoint_5(var_s0));
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
}

void func_80094D04(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    s32 func_800D1C5C(u32);
    s32 func_800D27C8(s32);
    void func_800FAA34(s32);
    s32 temp_v0_3;
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if ((var_s1 != (*(u8 **)((u8 *)arg0 + 0x64))[1]) && (_gcegg_entrypoint_6(var_s0) != 0)) {
                temp_v0_3 = func_800D27C8(func_800D1C5C(_gcegg_entrypoint_5(var_s0)));
                if (temp_v0_3 >= 0) {
                    func_800FAA34(temp_v0_3);
                }
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
}

s32 func_80094DA8(void *arg0) {
    s32 _gcegg_entrypoint_5(s32);
    s32 _gcegg_entrypoint_6(s32);
    s32 func_800D1C5C(u32);
    int func_800D27F4(s32);
    s32 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s1 = 0;
    temp_v0 = func_80094C64(arg0, 0);
    var_s0 = temp_v0;
    if (temp_v0 != 0) {
        do {
            if ((_gcegg_entrypoint_6(var_s0) != 0) && (func_800D27F4(func_800D1C5C(_gcegg_entrypoint_5(var_s0))) == 0)) {
                return 0;
            }
            var_s1 += 1;
            temp_v0_2 = func_80094C64(arg0, var_s1);
            var_s0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
    return 1;
}

/* extern */

void func_80094E40(s32 arg0) {
    s32 _gcegg_entrypoint_2(s32);
    void func_800FC660(u32);
    func_800FC660(_gcegg_entrypoint_2(arg0));
}
