#include "common.h"

s32 basub_entrypoint_0() 
{
    return 0x6C;
}

void func_80800008_basub(u8 *arg0, s32 arg1) {
    void func_80800834_basub(u8 *arg0);

    switch (arg1) {
        case 1:
            if ((*(u8 **)(arg0 + 0x130))[0x5D] == 2) {
                (*(u8 **)(arg0 + 0x130))[0x5E] = 0;
                *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) =
                    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x60) -
                    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x64);
            }
            break;
        case 2:
            if ((*(u8 **)(arg0 + 0x130))[0x5D] == 1) {
                (*(u8 **)(arg0 + 0x130))[0x5C] = (*(u8 **)(arg0 + 0x130))[0x5F] - 1;
            } else {
                (*(u8 **)(arg0 + 0x130))[0x5C]--;
            }
            *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) +=
                *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x64);
            func_80800834_basub(arg0);
            break;
    }
    (*(u8 **)(arg0 + 0x130))[0x5D] = arg1;
} typedef struct { u8 pad0[0x130]; union { u8 * unk130; void * unk130_voidp; }; u8 pad134[0x50]; s32 unk184; } Objsub_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808000CC_basub(u8 *arg0) {
    (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130)) + (0x58))) = 0.0f;
    (*(s8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130)) + (0x5E))) = 0;
    (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130)) + (0x54))) = 0.0f;
    (*(s8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130)) + (0x5D))) = 0;
    func_80800008_basub(arg0, 1);
}

void func_80800110_basub(u8 *arg0) {
    f32 func_800D8FF8(void);
    f32 delta;

    delta = func_800D8FF8();
    if (*(f32 *)(*(u8 **)(arg0 + 0x130) + 0x58) > 0.0f) {
        *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x58) -= delta;
        if (*(f32 *)(*(u8 **)(arg0 + 0x130) + 0x58) <= 0.0f) {
            (*(u8 **)(arg0 + 0x130))[0x5E] = 0;
        }
    }
    switch ((*(u8 **)(arg0 + 0x130))[0x5D]) {
        case 1:
            if (*(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) > 0.0f) {
                *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) -= delta;
            }
            if (*(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) <= 0 &&
                (*(u8 **)(arg0 + 0x130))[0x5E] != 0) {
                func_80800008_basub(arg0, 2);
            }
            break;
        case 2:
            *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) -= delta;
            if (*(f32 *)(*(u8 **)(arg0 + 0x130) + 0x54) <= 0) {
                if ((*(u8 **)(arg0 + 0x130))[0x5C] != 0) {
                    if ((*(u8 **)(arg0 + 0x130))[0x5E] != 0) {
                        func_80800008_basub(arg0, 2);
                    } else {
                        func_80800008_basub(arg0, 1);
                    }
                } else {
                    func_80800008_basub(arg0, 1);
                }
            }
            break;
    }
}

void func_80800254_basub(u8 *arg0, BtIntPtr arg1) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if ((*(s32 **)(arg0 + 0x130))[i + 11] == 0) {
            (*(s32 **)(arg0 + 0x130))[i + 11] = arg1;
            (*(s32 **)(arg0 + 0x130))[10]++;
            return;
        }
    }
}

void func_80800358_basub(u8 *arg0, BtIntPtr arg1) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if ((*(s32 **)(arg0 + 0x130))[i + 11] == arg1) {
            (*(s32 **)(arg0 + 0x130))[i + 11] = 0;
            (*(s32 **)(arg0 + 0x130))[10]--;
            return;
        }
    }
}

/* extern */

void func_80800458_basub(void *arg0, s32 arg1) {
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 temp_a0;
    BtIntPtr var_s0;

    var_s0 = 0;
    do {
        temp_a0 = (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x130))) + var_s0)) + (0x2C)));
        if (temp_a0 != 0) {
            func_8010114C(temp_a0, arg1, (((Objsub_arg0 *)arg0)->unk184));
        }
        var_s0 += 4;
    } while (var_s0 != 0x28);
}

void func_808004C8_basub(u8 *arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        (*(s32 **)(arg0 + 0x130))[i + 11] = 0;
    }
    (*(s32 **)(arg0 + 0x130))[10] = 0;
}

void basub_entrypoint_1(BtIntPtr arg0)
{
    func_80800458_basub(arg0,0x5);
}    typedef struct { f32 unk0; f32 unk4; } Objsub_basub_entrypoint_2_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

f32 basub_entrypoint_2(void *arg0) {
    void *temp_v0;

    temp_v0 = (((Objsub_arg0 *)arg0)->unk130_voidp);
    if ((((Objsub_basub_entrypoint_2_temp_v0 *)temp_v0)->unk4) > 0.0f) {
        return (((Objsub_basub_entrypoint_2_temp_v0 *)temp_v0)->unk0);
    }
    return 0.0f;
}    typedef struct { f32 unk0; f32 unk4; f32 unk8; } Objsub_basub_entrypoint_3_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void basub_entrypoint_3(u8 *arg0, f32 arg1, f32 arg2) {
    u8 *temp_v0;

    temp_v0 = (((Objsub_arg0 *)arg0)->unk130);
    if (!((((Objsub_basub_entrypoint_3_temp_v0 *)temp_v0)->unk4) > 0.0f)) {
        (((Objsub_basub_entrypoint_3_temp_v0 *)temp_v0)->unk0) = arg1;
        (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130)) + (4))) = arg2;
        temp_v0 = (((Objsub_arg0 *)arg0)->unk130);
        (((Objsub_basub_entrypoint_3_temp_v0 *)temp_v0)->unk8) = (f32) (((Objsub_basub_entrypoint_3_temp_v0 *)temp_v0)->unk4);
    }
}

/* extern */

struct player_state_s;
void basub_entrypoint_4(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 _chping_entrypoint_0(s32);
    struct player_state_s *func_800F53D0();
    _chping_entrypoint_0((*(s32 *)((s8 *)(func_800F53D0(BT_NATIVE_ONLY(bt_a0))) + (0x184))));
}    typedef struct { u8 pad0[0x1C]; f32 unk1C; } Objsub_basub_entrypoint_5_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void basub_entrypoint_5(void *arg0) {
    struct player_state_s;
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
#ifndef BT_NATIVE
    extern s32 _basub_entrypoint_4;
#endif
    void *temp_v0;

    temp_v0 = (((Objsub_arg0 *)arg0)->unk130_voidp);
    if ((((Objsub_basub_entrypoint_5_temp_v0 *)temp_v0)->unk1C) == 0.0f) {
        (((Objsub_basub_entrypoint_5_temp_v0 *)temp_v0)->unk1C) = 3.0f;
        func_8009DB04(arg0, 0x52A, 1.0f, 0x7FFF);
        _chbaddiesetup_entrypoint_1(&_basub_entrypoint_4, (((Objsub_arg0 *)arg0)->unk184));
    }
}

void basub_entrypoint_6(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    void func_8008F880(Unk80132ED0 *, f32 *);
    struct player_state_s *func_800F53D0(BtIntPtr);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800C10_basub[5];
    f32 sp24[3];
    void *sp20;

    sp20 = func_800F53D0(arg2);
    switch (arg1) {
        case 0x78:
            break;
        case 5:
            func_8008F880(arg0, sp24);
            func_8010D930(6, -1, sp24, D_80800C10_basub);
            break;
    }
    func_80800358_basub(sp20, arg0);
}    typedef struct { u8 pad0[0x5E]; u8 unk5E; } Objsub_basub_entrypoint_7_sub; /* offsets.py genstruct: fields from raw offsets on sub; rename once understood */ typedef struct { u8 pad0[0x130]; void * unk130; u8 pad134[0x50]; s32 unk184; } Objsub_basub_entrypoint_7_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

void basub_entrypoint_7(s32 arg0, f32 arg1) {
    void _baeggcursor_entrypoint_8(void *arg0);
    void _baeggfire_entrypoint_3(struct player_state_s *, f32 *, f32 *);
    Unk80132ED0 *_chtorpedo_entrypoint_0(f32 *arg0, f32 *arg1, f32 *arg2, s32 (*arg3)(Unk80132ED0 *, s32, s32), s32 arg4, f32 arg5);
    int func_80092CDC(void *, f32[3], s32);
    u32 func_80092EB0(u32 *);
    f32 func_800964DC(struct player_state_s *);
    f32 func_8009BFCC(struct player_state_s *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF368(f32 *, f32);
    void func_800F3BD0(void *self, s32 arg1, f32 dst[3]);
    struct player_state_s *func_800F53D0(BtIntPtr);
    f32 yaw_get(struct player_state_s *);
#ifndef BT_NATIVE
    extern s32 _basub_entrypoint_6;
#endif
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    s32 sp40;
    s32 ready;
    void *self;
    void *sub;
    f32 pitch;

    self = func_800F53D0(arg0);
    sp40 = func_80092CDC(self, sp50, 5);
    ready = func_80092EB0(self);
    if (sp40 && ready) {
        func_800F3BD0(self, 5, sp5C);
        pitch = func_8009BFCC(self);
        func_800EEC30(sp44, -pitch, yaw_get(self), *(f32 *)((u8 *)*&((Objsub_basub_entrypoint_7_self *)self)->unk130 + 0x68));
    } else {
        _baeggfire_entrypoint_3(self, sp5C, sp44);
        func_800EF368(sp44, 100.0f);
        func_800EE780(sp50, sp5C, sp44);
        func_800EF368(sp44, *(f32 *)((u8 *)*&((Objsub_basub_entrypoint_7_self *)self)->unk130 + 0x68));
        _baeggcursor_entrypoint_8(self);
    }
    sub = ((Objsub_basub_entrypoint_7_self *)self)->unk130;
    (((Objsub_basub_entrypoint_7_sub *)sub)->unk5E)--;
    func_80800254_basub(self, _chtorpedo_entrypoint_0(sp50, sp5C, sp44, &_basub_entrypoint_6, ((Objsub_basub_entrypoint_7_self *)self)->unk184, func_800964DC(self)));
}    typedef struct { u8 pad0[0x28]; s32 unk28; u8 pad2C[0x32]; u8 unk5E; } Objsub_basub_entrypoint_8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void basub_entrypoint_8(void *arg0, s32 arg1) {
    u8 temp_v1;
    void *temp_v0;

    temp_v0 = (((Objsub_arg0 *)arg0)->unk130_voidp);
    temp_v1 = (((Objsub_basub_entrypoint_8_temp_v0 *)temp_v0)->unk5E);
    if (((((Objsub_basub_entrypoint_8_temp_v0 *)temp_v0)->unk28) + temp_v1) < 0xA) {
        (((Objsub_basub_entrypoint_8_temp_v0 *)temp_v0)->unk5E) = (u8) (temp_v1 + 1);
        (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x58))) = 0.35f;
    }
}

void func_8009C128(u8 *, f32 *);

void func_80800834_basub(u8 *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800C24_basub[3];
#ifndef BT_NATIVE
    extern s32 _basub_entrypoint_7;
#endif
    f32 sp24;
    f32 sp18[3];

    sp24 = 0.0f;
    func_8009C128(arg0, sp18);
    func_8010D930(0xB, -1, sp18, D_80800C24_basub);
    _chbaddiesetup_entrypoint_2(&_basub_entrypoint_7, *(Unk80132ED0 **)((s8 *)arg0 + 0x184), *(s32 *)&sp24);
}

/* extern */

void basub_entrypoint_9(void *arg0) {
    void _bawobble_entrypoint_2(void *self);
    s32 func_800C2FDC(u8);
    func_80800458_basub(arg0, 0x2C);
    func_800C2FDC((*(u8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0xC))));
    (*(s8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0xC))) = 0;
    _bawobble_entrypoint_2(arg0);
}

void basub_entrypoint_10(u8 *arg0) {
    struct player_state_s;
    s32 _bawobble_entrypoint_3();
    s32 func_8009D454(struct player_state_s *, volatile u8, s32 *);
    void basub_entrypoint_15(void *, s32);
    extern s32 D_80800C30_basub[8];

    _bawobble_entrypoint_3();
    func_808000CC_basub(arg0);
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0) = 0.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 4) = *(f32 *)(*(u8 **)(arg0 + 0x130) + 8) = 0.0f;
    *(s8 *)(*(u8 **)(arg0 + 0x130) + 0xC) = func_8009D454(arg0, 0, D_80800C30_basub);
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x10) = 1.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x14) = *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x18) = 0;
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x1C) = 0.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x20) = 0.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x130) + 0x24) = 0.0f;
    func_808004C8_basub(arg0);
    basub_entrypoint_15(arg0, 0);
}

void basub_entrypoint_11(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objsub_arg0 *)arg0)->unk130_voidp + 16) = arg1;
}

void basub_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objsub_arg0 *)arg0)->unk130_voidp + 24) = arg1;
}

void basub_entrypoint_13(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objsub_arg0 *)arg0)->unk130_voidp + 36) = arg1;
}

void basub_entrypoint_14(u8 *arg0) {
    void *func_80092AD8(u8 *);
    void func_8009C128(u8 *, f32 *);
    void func_800C31DC(u8, f32);
    void func_800C33DC(u8, s32);
    void func_800C35E8(u8, f32 *);
    void func_800C368C(u8, s32);
    void func_800C3BDC(u8);
    f32 func_800D8FF8(void);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    s32 func_800F1574(f32 *, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 dt;
    u8 *data;
    f32 position[3];
    void *model;
    f32 timer;
    f32 step;

    dt = func_800D8FF8();
    model = func_80092AD8(arg0);
    func_800E0AF0(model, 1.0f);
    func_800F1574((f32 *)(((Objsub_arg0 *)arg0)->unk130 + 4), dt);
    data = ((Objsub_arg0 *)arg0)->unk130;
    timer = *(f32 *)(data + 0x1C);
    if (dt < timer) {
        step = dt;
    } else {
        step = timer;
    }
    *(f32 *)(data + 0x1C) = timer - step;
    data = ((Objsub_arg0 *)arg0)->unk130;
    *(f32 *)(data + 0x20) += *(f32 *)(data + 0x24) * dt;
    func_800E0AFC(model, 0x2A, 1.0f, 0.0f, 0.0f,
                  *(f32 *)(((Objsub_arg0 *)arg0)->unk130 + 0x20));
    data = ((Objsub_arg0 *)arg0)->unk130;
    *(f32 *)(((Objsub_arg0 *)arg0)->unk130 + 0x14) =
        func_800F15F8(*(f32 *)(data + 0x14), *(f32 *)(data + 0x18), 450.0f * dt);
    func_800E0AFC(model, 0x41, 1.0f,
                  *(f32 *)(((Objsub_arg0 *)arg0)->unk130 + 0x14), 0.0f, 0.0f);
    func_800E0AFC(model, 0x43, 1.0f,
                  *(f32 *)(((Objsub_arg0 *)arg0)->unk130 + 0x14), 0.0f, 0.0f);
    func_8009C128(arg0, position);
    func_800C35E8(*(u8 *)(((Objsub_arg0 *)arg0)->unk130 + 0xC), position);
    func_800C33DC(*(u8 *)(((Objsub_arg0 *)arg0)->unk130 + 0xC), 0);
    func_800C368C(*(u8 *)(((Objsub_arg0 *)arg0)->unk130 + 0xC), 0);
    data = ((Objsub_arg0 *)arg0)->unk130;
    func_800C31DC(*(u8 *)(data + 0xC), *(f32 *)(data + 0x10));
    func_800C3BDC(*(u8 *)(((Objsub_arg0 *)arg0)->unk130 + 0xC));
    func_80800110_basub((u8 *)arg0);
}

void basub_entrypoint_15(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x68))) = 3000.0f;
        (*(s8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x5F))) = 6;
        (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x60))) = 0.8f;
        (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x64))) = 0.28f;
        return;
    }
    (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x68))) = 1500.0f;
    (*(s8 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x5F))) = 3;
    (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x60))) = 0.8f;
    (*(f32 *)((s8 *)((((Objsub_arg0 *)arg0)->unk130_voidp)) + (0x64))) = 0.28f;
}
/* data_to_c.py: from asm/data/overlays/ba/sub.data.s */
s32 D_80800C10_basub[5] BT_DATA(4, overlays_ba_sub, 0x0) = { 1246227, 1474559, 65836, 360448017, 0 };
s32 D_80800C24_basub[3] BT_DATA(4, overlays_ba_sub, 0x14) = { 1246505, 1474559, 1114112 };
s32 D_80800C30_basub[8] BT_DATA(4, overlays_ba_sub, 0x20) = { 33947667, 86507547, 1463792, 655616, 1114112, 0, 0, 0 };
