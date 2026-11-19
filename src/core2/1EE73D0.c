#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif

typedef struct {
    f32 duration;
    BT_BITFIELD_ORDER(u16 unk4_2 : 14, u16 type : 2);
    BT_BITFIELD_ORDER(u16 type : 2, u16 unk4_2 : 14);
    u16 unk6;
} AnimationEntry;

void func_8010DAE0(BtIntPtr arg0, s32 arg1) {
    typedef struct anctrl_s AnimCtrl;
    typedef enum asset_e AssetId;
    void anctrl_reset(AnimCtrl *);
    void anctrl_setDuration(AnimCtrl *, f32);
    void anctrl_setIndex(AnimCtrl *, AssetId);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_start(AnimCtrl *);
    void func_8008B10C(AnimCtrl *, f32);
    void func_8008B188(AnimCtrl *, s32);
    void func_8008B4A8(AnimCtrl *, s32);
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    typedef AnimationEntry Entry;
    extern Entry D_80124740[];
    s32 flags;

    flags = D_80124740[arg1].unk6;
    anctrl_reset((AnimCtrl *)arg0);
    anctrl_setIndex((AnimCtrl *)arg0, (*(u32 *)((u8 *)&D_80124740[arg1] + 4) >> 18));
    anctrl_setDuration((AnimCtrl *)arg0, D_80124740[arg1].duration);
    if (flags & 1) {
        anctrl_setPlaybackType((AnimCtrl *)arg0, 2);
        func_8008B4A8((AnimCtrl *)arg0, (flags & 0x100) ? 0 : 1);
    }
    if (flags & 2) {
        anctrl_setPlaybackType((AnimCtrl *)arg0, 1);
    }
    if (flags & 4) {
        anctrl_setPlaybackType((AnimCtrl *)arg0, 3);
    }
    if (flags & 8) {
        func_8008B188((AnimCtrl *)arg0, 1);
    }
    if (flags & 0x10) {
        func_8008B188((AnimCtrl *)arg0, 0);
    }
    if (flags & 0x800) {
        func_8008B188((AnimCtrl *)arg0, func_800DC298(0.5f) ? 1 : 0);
    }
    if (flags & 0x40) {
        func_8008B10C((AnimCtrl *)arg0, 0.0f);
    }
    if (flags & 0x80) {
        func_8008B10C((AnimCtrl *)arg0, 0.999f);
    }
    if (flags & 0x400) {
        func_8008B10C((AnimCtrl *)arg0, func_800DC0C0());
    }
    anctrl_start((AnimCtrl *)arg0);
}

/* extern */

void func_8010DC50(s32 arg0) {
    void *func_80104148(s32);
    void * func_80104268(s16 *handle);
    s16 func_800AE020();
    void func_8010DAE0(BtIntPtr, s32);
    s16 *ptr;
    ptr = func_80104148(arg0);
    if (*((u8 *)ptr + 4) == 0) {
        func_8010DAE0(func_80104268((BtIntPtr)((u8 *)ptr + 2)), arg0);
        *ptr = func_800AE020();
    }
    *((u8 *)ptr + 4) = *((u8 *)ptr + 4) + 1;
}

void func_8010DCB4(s32 arg0) {
    void *func_80104148(s32);
    void func_801042D8(s16 *handle);
    void func_800ADFE0(s16);
    void func_80100E18(s16);
    s16 *ptr;
    s16 temp_a0;
    s32 count;

    ptr = func_80104148(arg0);
    count = *((u8 *)ptr + 4);
    if ((s32)count > 0) {
        *((u8 *)ptr + 4) = count - 1;
        if (*((u8 *)ptr + 4) == 0) {
            func_801042D8((BtIntPtr)((u8 *)ptr + 2));
            func_800ADFE0(ptr[0]);
            temp_a0 = ptr[4];
            ptr[0] = 0;
            if (temp_a0 != 0) {
                func_80100E18(temp_a0);
                ptr[4] = 0;
            }
        }
    }
}

void func_8010DD20(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    typedef struct {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u32 pad74_28 : 4, u32 pad74_0 : 27);
        u32 render : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 27, u32 pad74_28 : 4);
    } RenderActor;
    typedef struct {
        s16 unk0, unk2;
        u8 unk4, unk5, unk6, unk7;
        s16 unk8;
        s32 unkC, unk10;
    } State;
    typedef AnimationEntry Entry;
    extern Entry D_80124740[];
    State *state;
    BtIntPtr control;
    Gfx **buffers;
    void *func_80104148(s32);
    s32 func_801015D0(Actor *);
    void * func_80104200(s16 handle);
    void func_8008B304(BtIntPtr);
    u8 *func_800B27E0(u8 *);
    void *func_8008AEDC(void *);
    void func_8008C200(s16, BtIntPtr, BtIntPtr);
    Gfx **func_800A7180(void);
    void *func_800AE080(s16);
    void func_800AE598(s32 *, s32 *);
    void func_800DF72C(BtIntPtr);
    s16 func_80100D24(void *model,s32 asset,s32 buffers,s32 packed,s32 palette,s32 *color);
    BtIntPtr func_80100A74(s16, s32);
    void func_800DF818(BtIntPtr);
    void func_800DF714(Mtx *matrices);

    state = func_80104148(arg1);
    func_801015D0(arg0);
    if (((RenderActor *)arg0)->render) {
        control = func_80104200(state->unk2);
        if (control != 0 && state->unk0 != 0) {
            if (state->unk5 == 0) {
                func_8008B304(control);
                func_8008C200(state->unk0, (BtIntPtr)func_800B27E0((u8 *)arg2), (BtIntPtr)func_8008AEDC((void *)control));
                if (D_80124740[arg1].type == 2) {
                    buffers = func_800A7180();
                    state->unk10 = (BtIntPtr)((u8 *)buffers[1] + 0x40);
                    control = (BtIntPtr)func_800AE080(state->unk0);
                    func_800AE598((s32 *)control, (s32 *)(buffers + 1));
                }
            }
            control = (BtIntPtr)func_800AE080(state->unk0);
            func_800DF72C(control);
            switch (D_80124740[arg1].type) {
            case 1:
                if (state->unk8 == 0) {
                    state->unk8 = func_80100D24((BtIntPtr)arg2, arg0->unk0->unk14, 2, 0, arg0->unk0->unk16, 0);
                    state->unkC = arg2->unk28;
                }
                control = func_80100A74(state->unk8, state->unk6);
                func_800DF818(control);
                if (state->unk5 != 0) { arg2->unk28 = 0; } else { arg2->unk28 = state->unkC; }
                break;
            case 2:
                func_800DF714(state->unk10);
                break;
            }
        }
        state->unk5 = 1;
    }
}    typedef struct { u8 pad0[0x5]; s8 unk5; } Obj1EE73D0_func_8010DEFC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8010DEFC(void) {
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        var_s0 += 1;
        (((Obj1EE73D0_func_8010DEFC_temp_v0 *)temp_v0)->unk5) = 0;
    } while (var_s0 != 0xB);
}    typedef struct { u8 pad0[0x2]; s16 unk2; } Obj1EE73D0_func_8010DF3C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8010DF3C(void) {
    void func_8008ADE4(void *this);
    void *func_80104148(s32);
    void * func_80104200(s16 handle);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if ((((Obj1EE73D0_func_8010DF3C_temp_v0 *)temp_v0)->unk2) != 0) {
            func_8008ADE4(func_80104200((((Obj1EE73D0_func_8010DF3C_temp_v0 *)temp_v0)->unk2)));
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}    typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 pad5[0x3]; s16 unk8; } Obj1EE73D0_func_8010DF98_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8010DF98(void) {
    void func_800ADFE0(s16);
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if (((((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk4) != 0) || ((((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk2) != 0) || ((((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk8) != 0)) {
            (((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk4) = 0U;
            (((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk2) = 0;
            (((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk8) = 0;
        }
        if ((((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk0) != 0) {
            func_800ADFE0((((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk0));
            (((Obj1EE73D0_func_8010DF98_temp_v0 *)temp_v0)->unk0) = 0;
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}
