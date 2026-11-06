#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif

typedef struct {
    f32 duration;
    u16 unk4_2 : 14;
    u16 type : 2;
    u16 unk6;
} AnimationEntry;

void func_8010DAE0(s32 arg0, s32 arg1) {
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
    s32 func_80104268(s32);
    s16 func_800AE020();
    void func_8010DAE0(s32, s32);
    s16 *ptr;
    ptr = func_80104148(arg0);
    if (*((u8 *)ptr + 4) == 0) {
        func_8010DAE0(func_80104268((s32)((u8 *)ptr + 2)), arg0);
        *ptr = func_800AE020();
    }
    *((u8 *)ptr + 4) = *((u8 *)ptr + 4) + 1;
}

void func_8010DCB4(s32 arg0) {
    void *func_80104148(s32);
    s32 func_801042D8(s32);
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
            func_801042D8((s32)((u8 *)ptr + 2));
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
        u32 pad74_28 : 4;
        u32 render : 1;
        u32 pad74_0 : 27;
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
    s32 control;
    Gfx **buffers;
    void *func_80104148(s32);
    s32 func_801015D0(Actor *);
    s32 func_80104200(s16);
    void func_8008B304(s32);
    u8 *func_800B27E0(u8 *);
    void *func_8008AEDC(void *);
    void func_8008C200(s16, s32, s32);
    Gfx **func_800A7180(void);
    void *func_800AE080(s16);
    void func_800AE598(s32 *, s32 *);
    void func_800DF72C(s32);
    s16 func_80100D24(s32, s32, s32, s32, s32, s32);
    s32 func_80100A74(s16, s32);
    void func_800DF818(s32);
    void func_800DF714(s32);

    state = func_80104148(arg1);
    func_801015D0(arg0);
    if (((RenderActor *)arg0)->render) {
        control = func_80104200(state->unk2);
        if (control != 0 && state->unk0 != 0) {
            if (state->unk5 == 0) {
                func_8008B304(control);
                func_8008C200(state->unk0, (s32)func_800B27E0((u8 *)arg2), (s32)func_8008AEDC((void *)control));
                if (D_80124740[arg1].type == 2) {
                    buffers = func_800A7180();
                    state->unk10 = (s32)((u8 *)buffers[1] + 0x40);
                    control = (s32)func_800AE080(state->unk0);
                    func_800AE598((s32 *)control, (s32 *)(buffers + 1));
                }
            }
            control = (s32)func_800AE080(state->unk0);
            func_800DF72C(control);
            switch (D_80124740[arg1].type) {
            case 1:
                if (state->unk8 == 0) {
                    state->unk8 = func_80100D24((s32)arg2, arg0->unk0->unk14, 2, 0, arg0->unk0->unk16, 0);
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
}

/* extern */

void func_8010DEFC(void) {
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        var_s0 += 1;
        (*(s8 *)((s8 *)(temp_v0) + (5))) = 0;
    } while (var_s0 != 0xB);
}

/* extern */

void func_8010DF3C(void) {
    s32 func_8008ADE4(s32);
    void *func_80104148(s32);
    s32 func_80104200(s16);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) {
            func_8008ADE4(func_80104200((*(s16 *)((s8 *)(temp_v0) + (2)))));
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}

/* extern */

void func_8010DF98(void) {
    void func_800ADFE0(s16);
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if (((*(u8 *)((s8 *)(temp_v0) + (4))) != 0) || ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) || ((*(s16 *)((s8 *)(temp_v0) + (8))) != 0)) {
            (*(u8 *)((s8 *)(temp_v0) + (4))) = 0U;
            (*(s16 *)((s8 *)(temp_v0) + (2))) = 0;
            (*(s16 *)((s8 *)(temp_v0) + (8))) = 0;
        }
        if ((*(s16 *)((s8 *)(temp_v0) + (0))) != 0) {
            func_800ADFE0((*(s16 *)((s8 *)(temp_v0) + (0))));
            (*(s16 *)((s8 *)(temp_v0) + (0))) = 0;
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}
