#include "common.h"

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}    typedef struct { u8 pad0[0x18]; f32 unk18; } Objflameline_baflameline_entrypoint_1_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */ typedef struct { u8 pad0[0x84]; f32 * unk84; } Objflameline_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void baflameline_entrypoint_1(void *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA77C(BtIntPtr, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFE50(f32[3], f32[3], f32[3], f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_808006F0_baflameline[];
    f32 t;
    f32 sp90[3];
    f32 sp84[3];
    BtIntPtr temp_s1;
    s32 var_s0;
    void *temp_v1;

    temp_s1 = func_800B53A4(0xE);
    temp_v1 = *(void **)((s8 *)arg0 + 0x84);
    func_800EFA20(sp90, (s8 *)temp_v1 + 0xC, ((Objflameline_baflameline_entrypoint_1_temp_v1 *)temp_v1)->unk18);
    func_800EF04C(sp90, ((Objflameline_arg0 *)arg0)->unk84);
    for (var_s0 = 0; var_s0 != 7; var_s0++) {
        t = func_800F10B4(((f32)var_s0 + 0.5f) / 7.0f, 0.0f, 1.0f, 0.2f, 1.0f);
        func_800EFE50(sp84, ((Objflameline_arg0 *)arg0)->unk84, sp90, t);
        func_800BA77C(temp_s1, 0, 0, (s16)(s32)func_800DC178(0.0f, 359.0f));
        func_800BABB8(temp_s1, sp84, NULL, 1, D_808006F0_baflameline);
    }
}

void func_80800184_baflameline(void *arg0, f32 arg1[3]) { void func_800BA77C(BtIntPtr, s16, s16, s16); void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16); BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]); f32 func_800DC178(f32, f32); void func_800EFA20(void *, void *, f32); extern s32 D_80800738_baflameline[]; f32 sp34[3]; func_800EFA20(sp34, (s8 *)*(void **)((s8 *)arg0 + 0x84) + 0xC, *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x18) / 0.3f); sp34[1] -= (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x18) / 0.3f) * 0.1f; func_800BA77C(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), 0, 0, (s16)(s32)func_800DC178(0.0f, 359.0f)); func_800BA930(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), (s16)sp34[0], (s16)sp34[1], (s16)sp34[2], (s16)sp34[0], (s16)sp34[1], (s16)sp34[2]); func_800BABB8(*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x84) + 0x1C), arg1, NULL, 1.0f, D_80800738_baflameline); }    typedef struct { u8 pad0[0x1C]; s32 unk1C; u8 pad20[0x4]; s32 unk24; } Objflameline_baflameline_entrypoint_2_var_v0; /* offsets.py genstruct: fields from raw offsets on var_v0; rename once understood */

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) baflameline_entrypoint_2(void *arg0) {
    s32 func_800B5450(s32, void *);
    s32 func_800C2FDC(u8, void *);
    s32 func_800C8B84(s32, void *);
    s32 temp_a0;
    void *var_v0;

    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x20))), arg0);
    var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    temp_a0 = (((Objflameline_baflameline_entrypoint_2_var_v0 *)var_v0)->unk24);
    if (temp_a0 != 0) {
        func_800C8B84(temp_a0, arg0);
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
        var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    }
    BT_NATIVE_ONLY(return) func_800B5450((((Objflameline_baflameline_entrypoint_2_var_v0 *)var_v0)->unk1C), arg0);
}

void baflameline_entrypoint_3(u8 *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800B5534(s8 *arg0);
    s8 func_800BF8E4(void);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_800C8A98();
    void func_800C8F64(s32 id,s32 mask);
    void func_800C8FE0(s32 id,s32 enabled);
    void func_800EFD24(f32 vec[3]);
    extern s32 D_80800784_baflameline[5];
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))));
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))) + 0xC);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x18))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))) = func_800B53A4(0x28);
    func_800B5534((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))));
    if (func_800BF8E4() > 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = func_800C8A98();
        func_800C8F64((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0xB);
        func_800C8FE0((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0);
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
    }
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x20))) = func_800C4350(0, 0, D_80800784_baflameline);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) baflameline_entrypoint_4(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32 BT_PASS2(, s32));
    BT_IDO_ONLY(func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))));) BT_NATIVE_ONLY(return func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))), bt_a1);)
}

/* extern */

void baflameline_entrypoint_5(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32 BT_PASS2(, s32));
    void func_800EF2A0(f32 vec[3]);
    BT_IDO_ONLY(func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);) BT_NATIVE_ONLY(func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC, bt_a1);)
    func_800EF2A0((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
}

void baflameline_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 132) + 24) = arg1;
}

void baflameline_entrypoint_7(void *arg0) {
    s32 func_8001210C(s32);
    void func_8008EEC4(void *, f32 *, f32, s32);
    void func_800C3058(u8, s32);
    void func_800C35E8(u8, f32 *);
    void func_800C3BDC(u8);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    void func_800C8FE0(s32 id,s32 enabled);
    f32 func_800DC178(f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern u32 D_80800798_baflameline[][3];
    f32 end[3];
    f32 pos[3];
    f32 half;
    s32 i;
    f32 *state;

    state = ((Objflameline_arg0 *)arg0)->unk84;
    if (0.0f == state[6]) {
        if (*(s32 *)(state + 9) != 0) {
            func_800C8FE0(*(s32 *)(state + 9), 0);
        }
    } else {
        func_800EFA20(end, state + 3, state[6]);
        func_800EF04C(end, ((Objflameline_arg0 *)arg0)->unk84);
        func_800C3058(*((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x20),
            (s32)func_800F10B4((((Objflameline_arg0 *)arg0)->unk84)[6], 0.0f, 300.0f, 5000.0f, 32000.0f));
        func_800C35E8(*((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x20), end);
        func_800C3BDC(*((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x20));
        state = ((Objflameline_arg0 *)arg0)->unk84;
        if (*(s32 *)(state + 9) != 0) {
            half = state[6] * 0.5f;
            func_800EFE50(pos, state, end, 0.5);
            func_800C8FE0(*(s32 *)((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x24), 1);
            func_800C8CB8(*(s32 *)((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x24), pos);
            state = ((Objflameline_arg0 *)arg0)->unk84;
            func_800C8E54(*(s32 *)(state + 9), half, state[6]);
            func_800C8E84(*(s32 *)((u8 *)*&((Objflameline_arg0 *)arg0)->unk84 + 0x24), D_80800798_baflameline[func_8001210C(1)]);
        }
        for (i = 0; i < 2; i++) {
            func_800EFE50(pos, ((Objflameline_arg0 *)arg0)->unk84, end, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(arg0, pos);
            func_800EFE50(pos, ((Objflameline_arg0 *)arg0)->unk84, end, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(arg0, pos);
        }
        for (i = 0; i != 3; i++) {
            func_800EFE50(pos, ((Objflameline_arg0 *)arg0)->unk84, end, ((f32)i + 0.5f) / 3.0f);
            func_8008EEC4(arg0, pos, 45.0f, 0x26D);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ba/flameline.data.s */
s32 D_808006F0_baflameline [18] BT_DATA(4, overlays_ba_flameline, 0x0) = { 1903068, 2949100, 2031596, 1310800, 1310734, 327685, 1376258, 6684704, 675358770, 2228300, 4981043, 23461910, 268435480, 3, 0, 2818611, 65405210, 0 };
s32 D_80800738_baflameline [19] BT_DATA(4, overlays_ba_flameline, 0x48) = { 1903054, 1376258, 11403286, 268435470, 327685, 2490368, 65436, 0, 6553650, 131096, 0, 391452501, 2228288, 4194457, 10027051, 4980812, 1769822, 22937882, 0 };
s32 D_80800784_baflameline[5] BT_DATA(4, overlays_ba_flameline, 0x94) = { 33947667, 75694107, 1463792, 655616, 0 };
u32 D_80800798_baflameline [2] [ 3 ] BT_DATA(4, overlays_ba_flameline, 0xA8) = { { 0xFF, 0xFF, 0x40 }, { 0xFF, 0x40, 0x20 } };
