#include "common.h"

typedef struct { u8 pad0[0x188]; union { void * unk188; s32 * unk188_s32p; }; } Objvanish_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_bsdronevanish(void *arg0, s32 arg1) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void func_80093370(void *, s32);
    void func_800FC618(s32, s32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);

    switch (arg1) {
        case 1:
            _batimer_set(arg0, 0, 0.3f);
            break;
        case 2:
            func_800FC618(0x1C, -1);
            func_800FCA90(0x1C);
            _batimer_set(arg0, 0, 0.4f);
            break;
        case 3:
            func_80093370(arg0, 0);
            func_800FCAE0(0x1C, 0, 0x7D0);
            _batimer_set(arg0, 0, 2.0f);
            break;
    }
    *(s8 *)((s8 *)*&((Objvanish_arg0 *)arg0)->unk188 + 0x18) = arg1;
}

void func_808000CC_bsdronevanish(void *arg0) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800F3BB0(struct player_state_s *, f32[3]);
    extern s32 D_80800560_bsdronevanish[3];
    extern s32 D_8080056C_bsdronevanish[3];
    f32 pos[3];

    func_800F3BB0(arg0, pos);
    func_800BABB8((((Objvanish_arg0 *)arg0)->unk188_s32p)[1], pos, NULL, 1.0f, D_80800560_bsdronevanish);
    func_800BABB8((((Objvanish_arg0 *)arg0)->unk188_s32p)[0], pos, NULL, 1.0f, D_80800560_bsdronevanish);
    pos[1] += 130.0f;
    func_800BABB8((((Objvanish_arg0 *)arg0)->unk188_s32p)[1], pos, NULL, 1.0f, D_8080056C_bsdronevanish);
    func_800BABB8((((Objvanish_arg0 *)arg0)->unk188_s32p)[0], pos, NULL, 1.0f, D_8080056C_bsdronevanish);
}

void func_8080019C_bsdronevanish(s32 arg0, s32 arg1) {
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800578_bsdronevanish[10];
    func_800BABB8(arg0, NULL, NULL, 1.0f, D_80800578_bsdronevanish);
    func_800BA3FC(arg0, arg1);
}

/* extern */

void func_808001E4_bsdronevanish(void *arg0) {
    void func_800B5450(void *arg0);
    func_800B5450((*(s32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188_s32p)) + (4))));
    func_800B5450(*(((Objvanish_arg0 *)arg0)->unk188_s32p));
}

/* extern */

void func_8080021C_bsdronevanish(void *arg0) {
    BtIntPtr func_800B53A4(s32);
    (*(f32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0xC))) = 1.0f;
    (*(s32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0))), 0x9E5);
    (*(s32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (4))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (4))), 0x9E2);
}    typedef struct { u8 pad0[0x8]; f32 unk8; f32 unkC; f32 unk10; } Objvanish_func_808002A4_bsdronevanish_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_808002A4_bsdronevanish(void *arg0) {
    f32 func_800D8FF8(void);
    void func_808000CC_bsdronevanish(void *);
    f32 delta;
    void *temp_v0;

    delta = func_800D8FF8();
    temp_v0 = (((Objvanish_arg0 *)arg0)->unk188);
    (((Objvanish_func_808002A4_bsdronevanish_temp_v0 *)temp_v0)->unk10) = (f32) ((((Objvanish_func_808002A4_bsdronevanish_temp_v0 *)temp_v0)->unk10) - delta);
    if ((*(f32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0x10))) < 0.0f) {
        do {
            func_808000CC_bsdronevanish(arg0);
            temp_v0 = (((Objvanish_arg0 *)arg0)->unk188);
            (((Objvanish_func_808002A4_bsdronevanish_temp_v0 *)temp_v0)->unk8) += 0.02f * (((Objvanish_func_808002A4_bsdronevanish_temp_v0 *)temp_v0)->unkC);
            temp_v0 = (((Objvanish_arg0 *)arg0)->unk188);
            (((Objvanish_func_808002A4_bsdronevanish_temp_v0 *)temp_v0)->unk10) += 0.02f;
        } while ((*(f32 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0x10))) < 0.0f);
    }
}

/* extern */

void bsdronevanish_entrypoint_0(void *arg0) {
    void _badata_entrypoint_3(void *self, void *assetId, f32 *arg2);
    void _bastatemem_entrypoint_0(void *, s32);
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 func_800961AC(void *, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    void func_80800000_bsdronevanish(void *, s32);
    s32 sp2C;
    s32 sp28;

    _bastatemem_entrypoint_0(arg0, 0x1C);
    _badata_entrypoint_3(arg0, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp2C);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_800961AC(arg0, 6);
    func_8080021C_bsdronevanish(arg0);
    (*(s8 *)((s8 *)((((Objvanish_arg0 *)arg0)->unk188)) + (0x18))) = 0;
    func_80800000_bsdronevanish(arg0, 1);
}

void bsdronevanish_entrypoint_1(void *arg0) {
    s32 _badata_entrypoint_34(BtIntPtr);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    s32 bs_setState(BtIntPtr, s32);
    void func_80092EBC(void *, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 sp2C;
    s32 sp28;
    u8 state;

    sp2C = 0;
    state = *(u8 *)((s8 *)(((Objvanish_arg0 *)arg0)->unk188) + 0x18);
    switch (state) {
    case 1:
        func_808002A4_bsdronevanish(arg0);
        if (_batimer_decrement(arg0, 0)) {
            func_80800000_bsdronevanish(arg0, 2);
        }
        break;
    case 2:
        func_808002A4_bsdronevanish(arg0);
        sp28 = _batimer_decrement(arg0, 0);
        func_80092EBC(arg0, (s32)func_800F10B4(_batimer_get(arg0, 0), 0.0f, 0.4f, 0.0f, 255.0f));
        if (sp28) {
            func_80800000_bsdronevanish(arg0, 3);
        }
        break;
    case 3:
        if (_batimer_decrement(arg0, 0)) {
            sp2C = _badata_entrypoint_34((BtIntPtr)arg0);
        }
        break;
    }
    bs_setState((BtIntPtr)arg0, sp2C);
}

/* extern */

void bsdronevanish_entrypoint_2(void *arg0) {
    void _bastatemem_entrypoint_1(void *arg0);
    s32 func_80092778(void *);
    s32 func_800961AC(void *, s32);
    func_808001E4_bsdronevanish(arg0);
    func_800961AC(arg0, 1);
    func_80092778(arg0);
    _bastatemem_entrypoint_1(arg0);
}
/* data_to_c.py: from asm/data/overlays/bs/drone/vanish.data.s */
s32 D_80800560_bsdronevanish[3] BT_DATA(4, overlays_bs_drone_vanish, 0x0) = { 1770172, 78643482, 0 };
s32 D_8080056C_bsdronevanish[3] BT_DATA(4, overlays_bs_drone_vanish, 0xC) = { 1834308, -78642918, 0 };
s32 D_80800578_bsdronevanish[10] BT_DATA(4, overlays_bs_drone_vanish, 0x18) = { 2686997, 4980940, 720851, 65491, 2949120, 2949154, 2490424, 458764, 2818188, 9175040 };
