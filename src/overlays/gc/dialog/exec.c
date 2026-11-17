#include "common.h"

typedef struct { u8 pad0[0x12]; u16 unk12; u8 pad14[0xEC]; s32 unk100; u8 pad104[0x28]; BtIntPtr unk12C; u8 pad130[0x28]; s8 unk158; u8 pad159[0x1]; u16 unk15A; u8 pad15C[0x4]; s8 unk160; u8 pad161[0x1]; s16 unk162; s16 unk164; u8 pad166[0x2]; void * unk168; s32 unk16C; s32 (*unk170)(void *, s16, s8); u8 pad174[0x8]; s32 unk17C; } Objexec_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ s32 func_80800000_gcdialogexec(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*&((Objexec_arg0 *)arg0)->unk12 >> 1));
}    typedef struct { u8 pad0[0x11C]; s32 unk11C; s32 unk120; } Objexec_func_8080002C_gcdialogexec_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

/* extern */

void func_8080002C_gcdialogexec(u8 *arg0) {
    void _gczoombox_entrypoint_0(void *);
    s32 temp_a0;
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        _gczoombox_entrypoint_0((void *)(((Objexec_func_8080002C_gcdialogexec_var_s0 *)var_s0)->unk120));
        var_s1 += 1;
        var_s0 += 4;
        (((Objexec_func_8080002C_gcdialogexec_var_s0 *)var_s0)->unk11C) = 0;
    } while (var_s1 != 2);
    temp_a0 = (((Objexec_arg0 *)arg0)->unk12C);
    if (temp_a0 != 0) {
        _gczoombox_entrypoint_0((void *)temp_a0);
        (((Objexec_arg0 *)arg0)->unk12C) = 0;
    }
}    typedef struct { u8 pad0[0x114]; u8 unk114; } Objexec_func_808000A0_gcdialogexec_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ typedef struct { u8 pad0[0x100]; s32 unk100; BtIntPtr unk104; } Objexec_func_808000A0_gcdialogexec_var_s1; /* offsets.py genstruct: fields from raw offsets on var_s1; rename once understood */

/* extern */

void func_808000A0_gcdialogexec(u8 *arg0) {
    void _gldialog_entrypoint_5(volatile s32 arg0);
    void heap_free(void *memory);
    s16 temp_a0;
    s32 var_s2;
    s32 var_v0;
    BtIntPtr var_v1;
    u8 *var_s0;
    u8 *var_s1;

    var_s0 = arg0;
    var_s1 = arg0;
    var_s2 = 0;
    do {
        var_v0 = 0;
        var_v1 = 0;
        if ((s32) (((Objexec_func_808000A0_gcdialogexec_var_s0 *)var_s0)->unk114) > 0) {
            do {
                var_v0 += 1;
                (*(s32 *)((s8 *)(((((Objexec_func_808000A0_gcdialogexec_var_s1 *)var_s1)->unk104) + var_v1)) + (4))) = 0;
                var_v1 += 8;
            } while (var_v0 < (s32) (((Objexec_func_808000A0_gcdialogexec_var_s0 *)var_s0)->unk114));
        }
        (((Objexec_func_808000A0_gcdialogexec_var_s0 *)var_s0)->unk114) = 0U;
        heap_free((((Objexec_func_808000A0_gcdialogexec_var_s1 *)var_s1)->unk104));
        var_s2 += 1;
        var_s0 += 1;
        var_s1 += 4;
        (((Objexec_func_808000A0_gcdialogexec_var_s1 *)var_s1)->unk100) = 0;
    } while (var_s2 != 2);
    temp_a0 = (((Objexec_arg0 *)arg0)->unk162);
    if (temp_a0 != -1) {
        _gldialog_entrypoint_5(temp_a0);
    }
    (((Objexec_arg0 *)arg0)->unk100) = 0;
}

void func_80800164_gcdialogexec(u8 *arg0) {
    func_808000A0_gcdialogexec(arg0);
    if (((u32)arg0[0x11C] >> 6) == 0 && ((u32)arg0[0x11D] >> 6) == 0) {
        func_8080002C_gcdialogexec(arg0);
    }
    *(s16 *)(arg0 + 0x162) = -1;
    *(s16 *)(arg0 + 0x15A) = arg0[0x15D] = 0;
    *(s32 *)(arg0 + 0x168) = 0;
    arg0[0x167] = 0;
    *(s32 *)(arg0 + 0x170) = 0;
    *(s32 *)(arg0 + 0x174) = 0;
    *(s32 *)(arg0 + 0x178) = 0;
}    typedef struct { u8 pad0[0x18]; u16 unk18; } Objexec_func_808001DC_gcdialogexec_temp_a0_3; /* offsets.py genstruct: fields from raw offsets on temp_a0_3; rename once understood */

/* extern */

void func_808001DC_gcdialogexec(u8 *arg0) {
    void _subaddiedialog_entrypoint_12(BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800A9C98(void);
    s32 func_800F6438(BtUIntPtr);
    void func_800F82D4(BtIntPtr, s32);
    void func_800FECB8(u32);
    struct DialogFlags {
        u32 : 20;
        u32 suppress : 1;
        u32 : 11;
    };
    s32 (*temp_v0)(void *, s16, s8);
    s16 temp_a1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;

    temp_v0 = (((Objexec_arg0 *)arg0)->unk170);
    temp_a1 = (((Objexec_arg0 *)arg0)->unk162);
    (((Objexec_arg0 *)arg0)->unk164) = temp_a1;
    if (temp_v0 != NULL) {
        temp_a0 = (((Objexec_arg0 *)arg0)->unk168);
        if (temp_a0 == NULL) {
            temp_v0(temp_a0, temp_a1, (((Objexec_arg0 *)arg0)->unk160));
        } else if (func_80800000_gcdialogexec(temp_a0, (((Objexec_arg0 *)arg0)->unk16C)) != 0) {
            (((Objexec_arg0 *)arg0)->unk170)((((Objexec_arg0 *)arg0)->unk168), (((Objexec_arg0 *)arg0)->unk162), (((Objexec_arg0 *)arg0)->unk160));
        }
    }
    temp_a0_2 = (((Objexec_arg0 *)arg0)->unk168);
    if ((temp_a0_2 != NULL) && (func_80800000_gcdialogexec(temp_a0_2, (((Objexec_arg0 *)arg0)->unk16C)) != 0)) {
        temp_a0_3 = (((Objexec_arg0 *)arg0)->unk168);
        if ((((Objexec_func_808001DC_gcdialogexec_temp_a0_3 *)temp_a0_3)->unk18) & 1) {
            _subaddiedialog_entrypoint_12(temp_a0_3, (((Objexec_arg0 *)arg0)->unk162), (((Objexec_arg0 *)arg0)->unk160));
        }
    }
    if (((((Objexec_arg0 *)arg0)->unk15A) & 8) && ((func_800A9C98() == 0) || !((struct DialogFlags *)(arg0 + 0x15C))->suppress) && (func_800F6438((((Objexec_arg0 *)arg0)->unk17C)) != 0)) {
        func_800F82D4((((Objexec_arg0 *)arg0)->unk17C), 0);
    }
    func_800FECB8(0);
    func_80800164_gcdialogexec(arg0);
}

/* extern */

s32 func_808002E4_gcdialogexec(volatile u8 *arg0) {
    s32 _gldialog_entrypoint_1();
    s32 temp_v0;
    volatile s32 sp18 = 0;
    s32 var_a2;
    s32 var_v1;
    volatile u8 *var_a0;
    s32 var_a1;

    temp_v0 = _gldialog_entrypoint_1();
    var_a2 = sp18;
    var_a0 = arg0;
    if (*arg0 != 0) {
        var_a1 = *arg0;
        do {
            var_v1 = temp_v0 ? 0xAE : 0x7E;
            if (var_v1 == var_a1) {
                var_a2 += 1;
            }
            var_a1 = var_a0[1];
            var_a0 += 1;
        } while (var_a1 != 0);
    }
    return var_a2;
}

void func_80800350_gcdialogexec(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    s32 j;
    s32 out;
    s32 i;

    j = 0;
    out = 0;
    for (i = 0; arg1[i] != 0; i++) {
        if (arg1[i] == (arg3 ? 0xAE : 0x7E)) {
            if (arg4) {
                arg0[out++] = 0xFD;
                arg0[out++] = 0x68;
            }
            for (; arg2[j] != 0; j++) {
                arg0[out++] = arg2[j];
                if (arg4 && !arg3 && arg2[j] == ' ') {
                    arg0[out++] = 0xFD;
                    arg0[out++] = 0x68;
                }
            }
            j++;
            if (arg4) {
                arg0[out++] = 0xFD;
                arg0[out++] = 0x6C;
            }
        } else {
            arg0[out++] = arg1[i];
        }
    }
    arg0[out] = 0;
}    typedef struct { u8 pad0[0x18]; u16 unk18; } Objexec_func_80800478_gcdialogexec_caller; /* offsets.py genstruct: fields from raw offsets on caller; rename once understood */

int func_80800478_gcdialogexec(u8 *arg0, s32 arg1) {
    void _subaddiedialog_entrypoint_13(BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 (*callback)(void *, s16, s32);
    void *caller;

    callback = *(s32 (**)(void *, s16, s32))(arg0 + 0x174);
    if (callback != NULL) {
        caller = *(void **)(arg0 + 0x168);
        if (caller == NULL) {
            callback(caller, *(s16 *)(arg0 + 0x162), arg1);
        } else if (func_80800000_gcdialogexec(caller, *(s32 *)(arg0 + 0x16C))) {
            (*(s32 (**)(void *, s16, s32))(arg0 + 0x174))(
                *(void **)(arg0 + 0x168), *(s16 *)(arg0 + 0x162), arg1);
        }
    }
    caller = *(void **)(arg0 + 0x168);
    if (caller != NULL && func_80800000_gcdialogexec(caller, *(s32 *)(arg0 + 0x16C))) {
        caller = *(void **)(arg0 + 0x168);
        if (((Objexec_func_80800478_gcdialogexec_caller *)caller)->unk18 & 1) {
            _subaddiedialog_entrypoint_13(caller, *(s16 *)(arg0 + 0x162), arg1);
        }
    }
BT_NATIVE_ONLY(return 0;) }

void func_8080052C_gcdialogexec(u8 *arg0) {
    int _gczoombox_entrypoint_11();
    s32 _gczoombox_entrypoint_20(s32, f32, s32, s32, f32, s32, s32);
    void _gczoombox_entrypoint_26(void *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4);
    BtIntPtr _gczoombox_entrypoint_5(s32, s32, s32, s32, BtIntPtr);
    int _gczoombox_entrypoint_8();
    void _gczoombox_entrypoint_9(void *);
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void _gldbstring_entrypoint_2(s32);
    void func_800E715C(u8 *, u8 *);
    extern f32 D_80802EA0_gcdialogexec[];
    void func_800C0890(s32, s32);
    u8 *sp30[4];

    if ((((Objexec_arg0 *)arg0)->unk158) >= 0) {
        func_800E715C(sp30[0] = arg0 + 0x130, (u8 *)_gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, 0x1865), (((Objexec_arg0 *)arg0)->unk158)));
        _gldbstring_entrypoint_2(0x1865);
        {
        f32 temp_f0;
        BtIntPtr temp_v0_2;
        temp_v0_2 = _gczoombox_entrypoint_5(0x72, 0x44, 2, 0, (BtIntPtr)func_800C0890);
        (((Objexec_arg0 *)arg0)->unk12C) = temp_v0_2;
        temp_f0 = D_80802EA0_gcdialogexec[*(s8 *)(arg0 + 0x158)];
        _gczoombox_entrypoint_26(temp_v0_2, (s32) ((304.0f - (temp_f0 * 216.0f)) * 0.5f), 1.0f, temp_f0, 0);
        }
        _gczoombox_entrypoint_20((((Objexec_arg0 *)arg0)->unk12C), 100.0f, 0, 2, 0.1f, 0, 0);
        _gczoombox_entrypoint_8((((Objexec_arg0 *)arg0)->unk12C), sp30[0]);
        _gczoombox_entrypoint_9((void *)(((Objexec_arg0 *)arg0)->unk12C));
        _gczoombox_entrypoint_11((((Objexec_arg0 *)arg0)->unk12C));
    }
}

int func_8080064C_gcdialogexec(u8 *arg0) {
    typedef struct {
        s16 code;
        u8 pad[2];
        u8 *text;
    } Entry;
    typedef struct {
        u8 mode:2;
        u8 state:2;
        u8 rest:4;
    } Flags;
    typedef struct {
        u8 pad0[0x104];
        Entry *entries[2];
        u8 *text[2];
        u8 pad114[2];
        u8 index[2];
        s16 code[2];
        Flags flags[2];
        u8 pad11E[2];
        s32 box[2];
        u8 pad128[0x30];
        u8 value;
        u8 pad159[5];
        u16 active:1;
        u16 changed:1;
        u16 rest:14;
    } Dialog;
    typedef struct { u8 pad[0x116]; u8 index[2]; } Indices;
    typedef struct { u8 pad[0x11C]; Flags flags[2]; } FlagArray;
    int _gczoombox_entrypoint_39();
    s32 i;
    s32 code;

        ((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] = ((Entry *)(((s32 *)(arg0 + 0x104))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] + ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] * 8))->code;
        ((u8 * *)(arg0 + 0x10C))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] = ((Entry *)(((s32 *)(arg0 + 0x104))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] + ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] * 8))->text;
    switch (code = ((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]) {
        case -8:
            func_80800478_gcdialogexec(arg0, *((u8 * *)(arg0 + 0x10C))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]);
            ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
            return 1;
        case -9:
            ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
            return *((u8 * *)(arg0 + 0x10C))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] + 1;
        case -2:
            arg0[0x158] = *((u8 * *)(arg0 + 0x10C))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)];
            ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
            return 1;
        case -1:
            return 1;
        default:
            if (!((s32 *)(arg0 + 0x120))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] || _gczoombox_entrypoint_39(((s32 *)(arg0 + 0x120))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)], code) || ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].state) {
                ((Dialog *)arg0)->active = ((u32)*(u16 *)(arg0 + 0x15E) >> 15) ^ 1;
                return 0;
            }
            switch (((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]) {
                case -10:
                case -11:
                    do {
                        ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
                                                ((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] = ((Entry *)(((s32 *)(arg0 + 0x104))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] + ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] * 8))->code;
                    } while (-10 == ((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)] || -11 == ((s16 *)(arg0 + 0x118))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]);
                    return 1;
                case -4:
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].mode = 1;
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].state = 1;
                    ((Dialog *)arg0)->changed = 1;
                    ((Dialog *)arg0)->active = ((u32)*(u16 *)(arg0 + 0x15E) >> 15) ^ 1;
                    return 0;
                case -5:
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].mode = 0;
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].state = 1;
                    ((Dialog *)arg0)->changed = 1;
                    ((Dialog *)arg0)->active = ((u32)*(u16 *)(arg0 + 0x15E) >> 15) ^ 1;
                    return 0;
                case -7:
                    for (i = ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]; ((Entry * *)(arg0 + 0x104))[((u32)*(u16 *)(arg0 + 0x15E) >> 15)][i].code < -5; i++) {}
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].mode = 0;
                    ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
                    ((Dialog *)arg0)->active = ((u32)*(u16 *)(arg0 + 0x15E) >> 15) ^ 1;
                    return 1;
                case -6:
                    ((FlagArray *)arg0)->flags[((u32)*(u16 *)(arg0 + 0x15E) >> 15)].mode = 0;
                    ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
                    ((Dialog *)arg0)->active = ((u32)*(u16 *)(arg0 + 0x15E) >> 15) ^ 1;
                    ((Dialog *)arg0)->changed = 1;
                    return 1;
                default:
                    ((Indices *)arg0)->index[((u32)*(u16 *)(arg0 + 0x15E) >> 15)]++;
                    return 1;
            }
    }
}

void func_80800A50_gcdialogexec(u8 *dialog, s32 state) {
    void _gcdialogcamera_entrypoint_10(void *, s32, s32);
    void _gczoombox_entrypoint_0(void *);
    void _gczoombox_entrypoint_9(void *);
    void _gczoombox_entrypoint_10(void *);
    void _gczoombox_entrypoint_12(void *);
    int _gczoombox_entrypoint_33(u8 *);
    struct DialogState {
        u8 pad[0x15C];
        u32 unused : 30;
        u32 remaining : 2;
    };
    typedef struct {
        u8 state : 2;
        u8 rest : 6;
    } BoxFlags;
    typedef struct {
        u8 prefix[0x11C];
        BoxFlags flags[2];
        u8 unused11E[2];
        u8 *boxes[2];
        u32 unused128;
        u8 *extraBox;
    } DialogBoxes;
    struct DialogActions {
        u8 prefix[0x15E];
        u8 unused : 5;
        u8 finishing : 1;
        u8 rest : 2;
    };
    s32 i;
    s32 result;
    s32 last;
    u8 *box;

    if (dialog[0x15C] != 6 || state != 6) {
        switch (state) {
        case 1:
            for (i = 0; i != 2; i++) {
                box = ((DialogBoxes *)dialog)->boxes[i];
                if (box) {
                    if (((DialogBoxes *)dialog)->flags[i].state == 0) {
                        _gczoombox_entrypoint_9(box);
                    }
                    ((DialogBoxes *)dialog)->flags[i].state = 0;
                }
            }
            *(s8 *)(dialog + 0x158) = -1;
            break;
        case 5:
            for (i = 0; i != 2; i++) {
                box = ((DialogBoxes *)dialog)->boxes[i];
                if (box && ((DialogBoxes *)dialog)->flags[i].state == 0) {
                    _gczoombox_entrypoint_12(box);
                    _gczoombox_entrypoint_10(((DialogBoxes *)dialog)->boxes[i]);
                }
            }
            if (((DialogBoxes *)dialog)->extraBox) {
                _gczoombox_entrypoint_12(((DialogBoxes *)dialog)->extraBox);
                _gczoombox_entrypoint_10(((DialogBoxes *)dialog)->extraBox);
            }
            break;
        case 6:
            last = -1;
            ((struct DialogActions *)dialog)->finishing = 1;
            while ((result = func_8080064C_gcdialogexec(dialog))) {
                if (result >= 2) {
                    last = result - 1;
                }
            }
            while ((result = func_8080064C_gcdialogexec(dialog))) {
                if (result >= 2) {
                    last = result - 1;
                }
            }
            if (last != -1 && !(*(u16 *)(dialog + 0x15A) & 0x200)) {
                _gcdialogcamera_entrypoint_10(dialog, last, 0);
            }
            ((struct DialogState *)dialog)->remaining = 0;
            for (i = 0; i != 2; i++) {
                ((DialogBoxes *)dialog)->flags[i].state = 0;
                box = ((DialogBoxes *)dialog)->boxes[i];
                if (box) {
                    result = _gczoombox_entrypoint_33(box);
                    ((struct DialogState *)dialog)->remaining = ((struct DialogState *)dialog)->remaining + result;
                }
            }
            ((struct DialogActions *)dialog)->finishing = 0;
            break;
        case 7:
            func_808001DC_gcdialogexec(dialog);
            state = 0;
            break;
        case 8:
            for (i = 0; i != 2; i++) {
                if (((DialogBoxes *)dialog)->flags[i].state == 0) {
                    _gczoombox_entrypoint_0(((DialogBoxes *)dialog)->boxes[i]);
                    ((DialogBoxes *)dialog)->boxes[i] = 0;
                }
            }
            func_808001DC_gcdialogexec(dialog);
            break;
        case 10:
            if (((DialogBoxes *)dialog)->extraBox) {
                _gczoombox_entrypoint_12(((DialogBoxes *)dialog)->extraBox);
                _gczoombox_entrypoint_10(((DialogBoxes *)dialog)->extraBox);
            }
            break;
        case 11:
            func_8080052C_gcdialogexec(dialog);
            break;
        }
        dialog[0x15C] = state;
    }
}

int func_80800D30_gcdialogexec(arg0, arg1, arg2) {
    typedef struct {
        u8 pad[0x15C];
        u8 state;
        u8 count;
        u32 unused:8;
        u32 opened:2;
        u32 closed:2;
        u32 finished:2;
        u32 remaining:2;
    } DialogCallback;
    void func_80800A50_gcdialogexec(u8 *, s32);
    u8 *dialog = (u8 *)arg0;
    s32 first;
    s32 second;
    u8 count;
    u32 word;
    u32 finished;

    switch (arg2) {
        case 1:
            ((DialogCallback *)dialog)->opened++;
            break;
        case 3:
            func_80800A50_gcdialogexec(dialog, 2);
            break;
        case 4:
            if (((DialogCallback *)dialog)->state == 6) {
                ((DialogCallback *)dialog)->remaining--;
                if (((DialogCallback *)dialog)->remaining == 0) {
                    first = ((u32)dialog[0x11C] >> 6) ? 1 : 0;
                    second = ((u32)dialog[0x11D] >> 6) ? 1 : 0;
                    func_80800A50_gcdialogexec(dialog, (second + first) ? 8 : 5);
                }
                break;
            }
            second = (((u32)dialog[0x11C] >> 6) ? 1 : 0) + (((u32)dialog[0x11D] >> 6) ? 1 : 0);
            if (second > (s32)((DialogCallback *)dialog)->closed) {
                ((DialogCallback *)dialog)->closed++;
                if (((DialogCallback *)dialog)->closed + ((DialogCallback *)dialog)->finished == ((DialogCallback *)dialog)->count) {
                    func_80800A50_gcdialogexec(dialog, 8);
                }
            }
            break;
        case 6:
            ((DialogCallback *)dialog)->finished++;
            word = *(u32 *)(dialog + 0x15C);
            first = dialog[0x15D];
            finished = (word << 28) >> 30;
            if (first == finished) {
                func_80800A50_gcdialogexec(dialog, 7);
                word = *(u32 *)(dialog + 0x15C);
                first = dialog[0x15D];
                finished = (word << 28) >> 30;
            }
            if (first == ((word << 26) >> 30) + finished) {
                func_80800A50_gcdialogexec(dialog, 8);
            }
            break;
    }
BT_NATIVE_ONLY(return 0;) }

void func_80800F60_gcdialogexec(u8 *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x11C];
        u8 flags[2];
    } DialogFlags;
    void func_80800A50_gcdialogexec(u8 *, s32);
    s32 state;

    switch (arg2) {
        case 3:
            if (arg0[0x15C] == 0xB) {
                func_80800A50_gcdialogexec(arg0, 4);
                return;
            }
        case 1:
        case 4:
            return;
        case 6:
            if (arg0[0x15C] == 0xA) {
                state = ((u32)((DialogFlags *)arg0)->flags[(u32)*(u16 *)(arg0 + 0x15E) >> 15] >> 6) ? 8 : 2;
                func_80800A50_gcdialogexec(arg0, state);
            }
            break;
    }
}

s32 func_80801008_gcdialogexec(s32 arg0) {
    s32 result = 0xC8;
    return arg0 ? 0x1C : result;
}

s32 func_80801020_gcdialogexec(s32 arg0) {
    s32 result = 0;
    return arg0 ? 1 : result;
}

int func_80801038_gcdialogexec(void *arg0, s32 arg1) { BT_NATIVE_ONLY(s32 bt_result = 0;)
    typedef struct {
        s16 id;
        s16 pad;
        u8 *data;
    } Text;
    typedef struct {
        u8 pad[0x100];
        u8 *source;
        Text *text[2];
        u8 pad10C[8];
        u8 count[2];
        u8 pad116[0x51];
        u8 character;
    } Dialog;
    BtIntPtr _gldialog_entrypoint_4(s32 arg0);
    void *heap_alloc(s32);
    s32 code;
    s32 group;
    s32 i;
    u8 *cursor;
    u8 token;
    s32 length;
    Dialog *counts;
    Dialog *arrays;

    ((Dialog *)arg0)->source = _gldialog_entrypoint_4(arg1);
    cursor = ((Dialog *)arg0)->source;
    counts = arg0;
    group = 0;
    arrays = arg0;
    do {
        counts->count[0] = *cursor++;
        arrays->text[0] = heap_alloc(counts->count[0] * 8);
        group += 4;
        for (i = 0; i < counts->count[0]; i++) {
                token = *cursor++;
                code = token;
                if (code > 0 && code < 0x20) {
                    code = -code;
                    if (3 == token) {
                        code = *cursor++ + 0x75;
                    }
                } else {
                    if (token >= 0x80) {
                        code = token - 0x80;
                    } else {
                        code = token;
                    }
                }
                if (code == 0x51 || code == 0x79) {
                    code = ((Dialog *)arg0)->character - 0xC;
                }
                cursor++;
                arrays->text[0][i].id = code;
                length = cursor[-1];
                arrays->text[0][i].data = cursor;
                cursor += length;
        }
        counts = (Dialog *)((u8 *)counts + 1);
        arrays = (Dialog *)((u8 *)arrays + 4);
    } while (group != 8);
BT_NATIVE_ONLY(return bt_result;) }

/* extern */

void func_808011A4_gcdialogexec(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    typedef struct {
        u8 pad[0x120];
        s32 box[2];
    } Dialog;
    s32 _gczoombox_entrypoint_20(s32, f32, s32, s32, f32, s32, s32);
    s32 i;
    f32 box_background_animation_duration = 0.4f;

    for (i = 0; i < 2; i++) {
        if (((Dialog *)arg0)->box[i]) {
            _gczoombox_entrypoint_20(((Dialog *)arg0)->box[i], arg3, arg1, arg2, box_background_animation_duration, arg4, arg5);
        }
    }
}

void func_80801268_gcdialogexec(void *arg0, s32 arg1, s32 arg2, void *arg3, BtIntPtr arg4, BtIntPtr arg5, BtIntPtr arg6, s16 arg7)
{
  typedef struct 
  {
    s16 id;
    s16 pad;
    s32 data;
  } Text;
  typedef struct 
  {
    u8 state : 2;
    u8 unused : 2;
    u8 rest : 4;
  } BoxFlags;
  typedef struct 
  {
    u8 pad[0x12];
    u16 id : 15;
    u16 flag : 1;
  } Marker;
  typedef struct 
  {
    u8 pad0[0x104];
    Text *text[2];
    s32 data[2];
    u8 count[2];
    u8 index[2];
    s16 id[2];
    BoxFlags boxflags[2];
    u8 pad11e[2];
    s32 box[2];
    s16 y[2];
    u8 pad12c[0x2e];
    s16 flags;
    u32 unused15c : 8;
    u32 numBoxes : 8;
    u32 top : 1;
    u32 active : 1;
    u32 unused1 : 2;
    u32 fast : 1;
    u32 unused2 : 1;
    u32 low : 2;
    u32 opened : 2;
    u32 cleared : 2;
    u32 pending : 2;
    u32 other : 2;
    s8 speed;
    u8 pad161;
    s16 textId;
    u8 pad164[3];
    u8 markerArg;
    void *marker;
    s32 markerId;
    s32 callback;
    s32 callback2;
    s32 callback3;
  } Dialog;
  BtIntPtr _gczoombox_entrypoint_5(s32, s32, s32, s32, BtIntPtr);
  void _gczoombox_entrypoint_10(void *);
  int _gczoombox_entrypoint_24(s32, s32);
  int _gczoombox_entrypoint_25(s32, s32);
  int _gczoombox_entrypoint_35(s32, void *, s32, s32);
  s32 func_800A9C98(void);
  int func_80801038_gcdialogexec(void *, s32);
  void func_80800A50_gcdialogexec(u8 *, s32);
  void func_808011A4_gcdialogexec(u8 *, s32, s32, s32, s32, s32);
  extern void func_800C01D8(void);
  Text *text;
  s32 i;
  s32 j;
  s16 initial;
  u8 count;
  ((Dialog *) arg0)->markerArg = arg7;
  func_80801038_gcdialogexec(arg0, arg1);
  ((Dialog *) arg0)->marker = arg3;
  ((Dialog *) arg0)->cleared = 0;
 if (0) { }
  ((Dialog *) arg0)->numBoxes = (((Dialog *) arg0)->pending = (((Dialog *) arg0)->opened = (((Dialog *) arg0)->other = (u8) ((Dialog *) arg0)->cleared)));
  ((Dialog *) arg0)->callback = arg4;
  ((Dialog *) arg0)->callback2 = arg5;
  ((Dialog *) arg0)->callback3 = arg6;
  ((Dialog *) arg0)->markerId = (arg3) ? ((((Marker *) arg3)->id) ? (((Marker *) arg3)->id) : (-1)) : (-1);
  ((Dialog *) arg0)->low = 0;
  for (i = 0; i < 2; i++)
  {
    text = ((Dialog *) arg0)->text[i];
    j = 0;
    initial = text[0].id;
    if (initial < (-5))
    {
      count = ((Dialog *) arg0)->count[i];
      while (j < count)
      {
        if (text[++j].id >= (-5))
        {
          break;
        }
      }

    }
    ((Dialog *) arg0)->id[i] = initial;
    ((Dialog *) arg0)->data[i] = ((Dialog *) arg0)->text[i][0].data;
    ((Dialog *) arg0)->index[i] = 0;
    ((Dialog *) arg0)->y[i] = func_80801008_gcdialogexec(i);
    ((Dialog *) arg0)->boxflags[i].unused = 0;
    if (((Dialog *) arg0)->text[i][j].id >= 0)
    {
      if (((Dialog *) arg0)->boxflags[i].state == 0)
      {
        if (((((Dialog *) arg0)->text[i][j].id + 0xC) != 0x29) && ((((Dialog *) arg0)->text[i][j].id + 0xC) != 0x84))
        {
          ((Dialog *) arg0)->box[i] = _gczoombox_entrypoint_5(((Dialog *) arg0)->y[i], ((Dialog *) arg0)->text[i][j].id + 0xC, 0, func_80801020_gcdialogexec(i), (BtIntPtr) func_800C01D8);
        }
        else
        {
          ((Dialog *) arg0)->box[i] = _gczoombox_entrypoint_5(((Dialog *) arg0)->y[i], ((Dialog *) arg0)->text[i][j].id + 0xC, 0, 1 - func_80801020_gcdialogexec(i), (BtIntPtr) func_800C01D8);
        }
        if (arg2 & 0x100)
        {
          _gczoombox_entrypoint_24(((Dialog *) arg0)->box[i], 0);
        }
        if (arg2 & 0x400)
        {
          _gczoombox_entrypoint_25(((Dialog *) arg0)->box[i], 1);
        }
      }
      else
      {
        if (func_80800000_gcdialogexec(((Dialog *) arg0)->marker, ((Dialog *) arg0)->markerId))
        {
          _gczoombox_entrypoint_35(((Dialog *) arg0)->box[i], ((Dialog *) arg0)->marker, ((Dialog *) arg0)->markerArg, ((Dialog *) arg0)->markerId);
        }
        ((Dialog *) arg0)->opened++;
      }
      ((Dialog *) arg0)->numBoxes++;
    }
    else
      if (((Dialog *) arg0)->text[i][j].id < (-4))
    {
      if (((Dialog *) arg0)->boxflags[i].state != 0)
      {
        _gczoombox_entrypoint_10((void *)((Dialog *) arg0)->box[i]);
        ((Dialog *) arg0)->numBoxes++;
      }
      else
      {
        ((Dialog *) arg0)->box[i] = 0;
      }
      ((Dialog *) arg0)->boxflags[i].state = 0;
    }
    else
      if (((Dialog *) arg0)->boxflags[i].state != 0)
    {
      ((Dialog *) arg0)->numBoxes++;
      ((Dialog *) arg0)->opened++;
    }
  }

  ((Dialog *) arg0)->textId = arg1;
  ((Dialog *) arg0)->flags = arg2;
  if (((Dialog *) arg0)->id[0] < 0)
  {
    ((Dialog *) arg0)->top = 0;
  }
  else
  {
    ((Dialog *) arg0)->top = 1;
  }
  ((Dialog *) arg0)->active = 1;
  if (func_800A9C98() && ((Dialog *) arg0)->fast)
  {
    ((Dialog *) arg0)->speed = 1;
  }
  else
  {
    ((Dialog *) arg0)->speed = -1;
  }
  func_80800A50_gcdialogexec(arg0, (func_800A9C98() && ((Dialog *) arg0)->fast) ? (6) : (1));
  func_808011A4_gcdialogexec(arg0, 5, 2, 0xF, arg2 & 2, arg2 & 0x80);
}

s32 gcdialogexec_entrypoint_0(void *dialog, s32 text, s32 flags, f32 *position, void *actor,
                            void *callback, void *callback2, void *callback3, s16 actorArg) {
    struct Request {
        s16 text;
        s16 flags;
        f32 position[3];
        void *actor;
        s16 actorArg;
        s16 pad16;
        s32 actorId;
        void *callback;
        void *callback2;
        void *callback3;
        s32 camera;
    };
    typedef struct {
        u8 pad[0x11A];
        s16 id;
        u8 pad11C[0x3E];
        u16 flags;
        u32 unused : 20;
        u32 suppress : 1;
        u32 rest : 11;
        u16 speed : 8;
        u16 count : 4;
        u16 index : 4;
        u8 pad162[0x1A];
        s32 camera;
        s32 pad180;
        struct Request requests[4];
    } Dialog;
    typedef struct {
        u8 pad[0x12];
        u16 id : 15;
        u16 flag : 1;
    } Marker;
    s32 func_800A9C98(void);
    s32 func_800C0638(void);
    void func_800C0658(void);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_800EFD24(f32 vec[3]);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5B0C(BtIntPtr dialog);
    void func_800F82D4(BtIntPtr dialog, s32 text);
    void func_800F8300(BtIntPtr dialog, s32 mode, f32 *position);
    void func_800FEC60(u32 dialog);
    s32 replace;

    if (!func_800C0638()) {
        ((Dialog *)dialog)->camera = func_800F54E4();
        func_80801268_gcdialogexec(dialog, text, flags, actor,
                                  (BtIntPtr)callback, (BtIntPtr)callback2, (BtIntPtr)callback3, actorArg);
        if ((flags & 8) && (!func_800A9C98() || !((Dialog *)dialog)->suppress)) {
            if (position) {
                func_800F8300(((Dialog *)dialog)->camera, ((Dialog *)dialog)->id < 0 ? 1 : 3, position);
            } else {
                func_800F82D4(((Dialog *)dialog)->camera, ((Dialog *)dialog)->id < 0 ? 1 : 3);
            }
        }
        func_800FEC60(0);
        return 1;
    }
    replace = flags & 0x20;
    if (replace) {
        if (!(((Dialog *)dialog)->flags & 0x40)) {
            func_800C0658();
        } else {
            ((Dialog *)dialog)->count = 0;
            ((Dialog *)dialog)->index = 0;
        }
    }
    if ((flags & 4) || replace) {
        replace = ((Dialog *)dialog)->index + ((Dialog *)dialog)->count;
        if (replace >= 4) {
            replace -= 4;
        }
        ((Dialog *)dialog)->requests[replace].text = text;
        ((Dialog *)dialog)->requests[replace].flags = flags;
        if (position) {
            func_800EE7F8(((Dialog *)dialog)->requests[replace].position, position);
        } else {
            func_800EFD24(((Dialog *)dialog)->requests[replace].position);
        }
        ((Dialog *)dialog)->requests[replace].actor = actor;
        ((Dialog *)dialog)->requests[replace].actorArg = actorArg;
        ((Dialog *)dialog)->requests[replace].actorId =
            actor ? (((Marker *)actor)->id ? ((Marker *)actor)->id : -1) : -1;
        ((Dialog *)dialog)->requests[replace].callback = callback;
        ((Dialog *)dialog)->requests[replace].callback2 = callback2;
        ((Dialog *)dialog)->requests[replace].callback3 = callback3;
        ((Dialog *)dialog)->requests[replace].camera = func_800F54E4();
        ((Dialog *)dialog)->count++;
        if ((flags & 8) && (!func_800A9C98() || !((Dialog *)dialog)->suppress)) {
            if (!func_800F5B0C(((Dialog *)dialog)->requests[replace].camera)) {
                if (position) {
                    func_800F8300(((Dialog *)dialog)->requests[replace].camera, 2, position);
                } else {
                    func_800F82D4(((Dialog *)dialog)->requests[replace].camera, 2);
                }
            } else {
                func_800F82D4(((Dialog *)dialog)->requests[replace].camera,
                              func_800F5B0C(((Dialog *)dialog)->requests[replace].camera));
            }
        }
        return 1;
    }
    return 0;
}

void gcdialogexec_entrypoint_1(u8 *arg0) {
    typedef struct {
        s16 text;
        u16 flags;
        f32 position[3];
        void *actor;
        s16 id;
        s16 pad;
        s32 callback;
        s32 arg4;
        s32 arg5;
        s32 arg6;
        s32 camera;
    } Request;
    typedef struct {
        u8 pad[0x15C];
        u32 unused : 20;
        u32 suppress : 1;
        u32 rest : 11;
        u16 speed : 8;
        u16 count : 4;
        u16 index : 4;
    } Dialog;
    s32 func_800A9C98(void);
    int func_800EEEA8(f32 vec[3]);
    s32 func_800F6438(BtUIntPtr);
    void func_800F82D4(BtIntPtr, s32);
    void func_800F8300();
    void func_800FEC60(u32);
    Request *request;

    request = &((Request *)(arg0 + 0x184))[((Dialog *)arg0)->index];
    func_80801268_gcdialogexec(arg0, request->text, request->flags,
        request->actor, request->arg4, request->arg5, request->arg6, request->id);
    *(s32 *)(arg0 + 0x16C) = request->callback;
    *(s32 *)(arg0 + 0x17C) = request->camera;
    func_800FEC60(0);
    if ((request->flags & 8) && (!func_800A9C98() || !((Dialog *)arg0)->suppress)) {
        if (func_800F6438(*(s32 *)(arg0 + 0x17C))) {
            func_800F82D4(*(s32 *)(arg0 + 0x17C), 0);
        }
        if (func_800EEEA8(request->position)) {
            if (func_800F6438(*(s32 *)(arg0 + 0x17C))) {
                func_800F82D4(*(s32 *)(arg0 + 0x17C), *(s16 *)(arg0 + 0x11A) < 0 ? 1 : 3);
            }
        } else if (func_800F6438(*(s32 *)(arg0 + 0x17C))) {
            func_800F8300(*(s32 *)(arg0 + 0x17C), *(s16 *)(arg0 + 0x11A) < 0 ? 1 : 3, request->position);
        }
    }
    ((Dialog *)arg0)->index++;
    if (((Dialog *)arg0)->index >= 4) {
        ((Dialog *)arg0)->index -= 4;
    }
    ((Dialog *)arg0)->count--;
}

void gcdialogexec_entrypoint_2(u8 *arg0) {
    typedef struct {
        u8 state : 2;
        u8 rest : 6;
    } BoxFlags;
    typedef struct {
        u8 pad[0x11C];
        BoxFlags boxflags[2];
        u8 pad11E[2];
        u8 *boxes[2];
        u8 pad128[0x34];
        u32 unused : 30;
        u32 pending : 2;
        u8 speed;
        u8 middle : 4;
        u8 low : 4;
    } Dialog;
    int _gczoombox_entrypoint_33(u8 *);
    s32 func_800C0638(void);
    void func_80800A50_gcdialogexec(u8 *, s32);
    s32 i;
    s32 result;

    ((Dialog *)arg0)->boxflags[0].state = 0;
    ((Dialog *)arg0)->boxflags[1].state = 0;
    if (func_800C0638() != 0) {
        func_80800A50_gcdialogexec(arg0, 6);
    } else {
        if (arg0[0x15C] != 6) {
            ((Dialog *)arg0)->pending = 0;
            for (i = 0; i < 2; i++) {
                ((Dialog *)arg0)->boxflags[i].state = 0;
                if (((Dialog *)arg0)->boxes[i] != 0) {
                    result = _gczoombox_entrypoint_33(((Dialog *)arg0)->boxes[i]);
                    ((Dialog *)arg0)->pending = ((Dialog *)arg0)->pending + result;
                }
            }
            if (((Dialog *)arg0)->pending) {
                arg0[0x15C] = 6;
            }
        }
    }
    ((Dialog *)arg0)->middle = 0;
    ((Dialog *)arg0)->low = 0;
}

/* extern */

s32 gcdialogexec_entrypoint_3(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    void func_808011A4_gcdialogexec(u8 *, s32, s32, s32, s32, s32);
    s32 gcdialogexec_entrypoint_0(void *, s32, s32, f32 *, void *, void *, void *, void *, s16);
    gcdialogexec_entrypoint_0(arg0, arg1 + 0xE06, 0x44, 0, 0, 0, 0, arg5, 0);
    func_808011A4_gcdialogexec(arg0, arg3, arg4, arg2, 0, 0);
    return 1;
}

void gcdialogexec_entrypoint_4(u8 *text_id, s32 arg1, s32 pos, s32 marker, s32 callback, s32 arg5) {
    void func_808011A4_gcdialogexec(u8 *, s32, s32, s32, s32, s32);
    func_808011A4_gcdialogexec(text_id, arg1, pos, marker, callback, arg5);
}

void gcdialogexec_entrypoint_5(BT_PASS2(s32 bt_a0, BT_PASS2(s32 bt_a1, s32 bt_a2)))
{
    func_80800D30_gcdialogexec(BT_PASS2(bt_a0, BT_PASS2(bt_a1, bt_a2)));
}

void gcdialogexec_entrypoint_6(u8 *dialog, s32 state)
{
    func_80800A50_gcdialogexec(dialog, state);
}

void gcdialogexec_entrypoint_7(u8 *arg0)
{
    func_80800164_gcdialogexec(arg0);
}

void gcdialogexec_entrypoint_8(BtIntPtr arg0)
{
    func_80800A50_gcdialogexec((u8 *)arg0, 0x2);
}

void gcdialogexec_entrypoint_9(u8 *arg0, s32 arg1, s32 arg2)
{
    func_80800F60_gcdialogexec(arg0, arg1, arg2);
}

int func_80801DB4_gcdialogexec(u8 *arg0) {
    typedef struct {
        s16 code;
        s16 pad;
        u8 *text;
    } DialogEntry;
    typedef struct {
        u8 pad0[0x104];
        u8 *entries[2];
        u8 pad10C[0xA];
        u8 index[2];
        u8 pad118[0x46];
        u16 current : 1;
        u16 unused : 15;
        u8 pad160[2];
        s16 dialogId;
        u8 pad164[4];
        void *caller;
        s32 callerArg;
        u8 pad170[8];
        s32 (*callback)(void *, s16, u8);
    } Dialog;
    s32 _gldialog_entrypoint_1();
    s32 _subaddiedialog_entrypoint_14(void *, s16, s32);
    s32 result = -1;
    s32 flag1;
    s32 flag2;
    Dialog *dialog = (Dialog *)arg0;

    if (dialog->callback != NULL) {
        flag1 = 1;
        if (dialog->caller == NULL) {
            result = dialog->callback(dialog->caller, dialog->dialogId, dialog->index[dialog->current]);
        } else if (func_80800000_gcdialogexec(dialog->caller, dialog->callerArg)) {
            result = dialog->callback(dialog->caller, dialog->dialogId, dialog->index[dialog->current]);
        }
        if (result < 0) {
            result = -1 - result;
            flag1 = 0;
        }
        if (result >= 0 && ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8 + result * 8))[1].code == -10) {
            func_80800350_gcdialogexec(arg0,
                ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8))->text,
                ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8 + result * 8))[1].text,
                _gldialog_entrypoint_1(((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8))->text), flag1);
        } else {
            result = -1;
        }
    }
    if (dialog->caller != NULL && func_80800000_gcdialogexec(dialog->caller, dialog->callerArg)) {
        if (*(u16 *)((u8 *)dialog->caller + 0x18) & 1) {
            flag2 = 1;
            result = _subaddiedialog_entrypoint_14(dialog->caller, dialog->dialogId, dialog->index[dialog->current]);
            if (result < 0) {
                result = -1 - result;
                flag2 = 0;
            }
            if (result >= 0 && ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8 + result * 8))[1].code == -10) {
                func_80800350_gcdialogexec(arg0,
                    ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8))->text,
                    ((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8 + result * 8))[1].text,
                    _gldialog_entrypoint_1(((DialogEntry *)(dialog->entries[dialog->current] + dialog->index[dialog->current] * 8))->text), flag2);
            } else {
                result = -1;
            }
        }
    }
    return result;
}

int func_80802020_gcdialogexec(u8 *arg0) {
    typedef struct {
        s16 code;
        s16 pad;
        u8 *text;
    } DialogEntry;
    typedef struct {
        u8 pad0[0x104];
        u8 *entries[2];
        u8 pad10C[0xA];
        u8 index[2];
        u8 pad118[0x46];
        u16 current : 1;
        u16 unused : 5;
        u16 sequence : 2;
        u16 rest : 8;
        u8 pad160[2];
        s16 dialogId;
        u8 pad164[4];
        void *caller;
        s32 callerArg;
        u8 pad170[8];
        s32 (*callback)(void *, s16, s32);
    } Dialog;
    s32 _gldialog_entrypoint_1();
    s32 _subaddiedialog_entrypoint_14(void *, s16, s32);
    void func_800E6DD8(char *, s32, s32, s32);
    s32 pad;
    s32 count;
    u8 buffer[20];
    s32 format;
    s32 offset;
    s32 i;
    s32 result = -1;

    count = func_808002E4_gcdialogexec(((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text);
    format = _gldialog_entrypoint_1(((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text);
    buffer[0] = 0;
    if (((Dialog *)arg0)->callback != NULL) {
        offset = 0;
        i = 0;
        if (count > 0) {
            do {
                if (((Dialog *)arg0)->caller == NULL) {
                    result = ((Dialog *)arg0)->callback(((Dialog *)arg0)->caller, ((Dialog *)arg0)->dialogId, ((Dialog *)arg0)->sequence++);
                } else if (func_80800000_gcdialogexec(((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerArg)) {
                    result = ((Dialog *)arg0)->callback(((Dialog *)arg0)->caller, ((Dialog *)arg0)->dialogId, ((Dialog *)arg0)->sequence++);
                }
                func_800E6DD8((char *)(buffer + offset), result, 0, format);
                i++;
                while (buffer[offset]) offset++;
                offset++;
                buffer[offset] = 0;
            } while (i != count);
        }
    }
    if (((Dialog *)arg0)->caller != NULL && func_80800000_gcdialogexec(((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerArg)) {
        if (*(u16 *)((u8 *)((Dialog *)arg0)->caller + 0x18) & 1) {
            offset = 0;
            result = 0;
            buffer[0] = 0;
            if (count > 0) {
                do {
                    func_800E6DD8((char *)(buffer + offset), _subaddiedialog_entrypoint_14(((Dialog *)arg0)->caller, ((Dialog *)arg0)->dialogId, ((Dialog *)arg0)->sequence++), 0, format);
                    result++;
                    while (buffer[offset]) offset++;
                offset++;
                buffer[offset] = 0;
                } while (result != count);
            }
        }
    }
    func_80800350_gcdialogexec(arg0,
        ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text,
        buffer,
        _gldialog_entrypoint_1(((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text), 0);
    return 0;
}

void gcdialogexec_entrypoint_10(void *arg0) {
    typedef struct {
        s16 code;
        s16 pad;
        void *text;
    } DialogEntry;
    typedef struct {
        u8 mode : 2;
        u8 busy : 2;
        u8 unused : 4;
    } BoxFlags;
    typedef struct {
        u8 pad0[0x104];
        s32 entries[2];
        u8 *data[2];
        u8 pad114[2];
        u8 index[2];
        s16 code[2];
        BoxFlags boxFlags[2];
        u8 pad11E[2];
        s32 box[2];
        u8 pad128[0x30];
        u8 value;
        u8 pad159;
        u16 flags;
        u8 state;
        u8 count;
        u16 current : 1;
        u16 pending : 1;
        u16 unused15E : 6;
        u32 opened : 2;
        u32 skipped : 2;
        u32 unused15F : 4;
        s8 answer;
        u8 pad161;
        s16 dialogId;
        u8 pad164[3];
        u8 callerId;
        void *caller;
        s32 callerArg;
    } Dialog;
    void func_80015E80(s32, void *);
    void func_80015ECC(s32, void *);
    void func_80015F28(s32, void *);
    void func_80015F5C(s32, void *);
    s32 func_80015F0C(s32, s32);
    int _gcaudiolist_entrypoint_0();
    void _gcdialogcamera_entrypoint_10(void *, s32, s32);
    int _gczoombox_entrypoint_1();
    int _gczoombox_entrypoint_7();
    int _gczoombox_entrypoint_8();
    void _gczoombox_entrypoint_10(void *);
    int _gczoombox_entrypoint_11();
    void _gczoombox_entrypoint_12(void *);
    int _gczoombox_entrypoint_18();
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_35();
    int _gczoombox_entrypoint_37(s32, s16);
    int _gczoombox_entrypoint_39();
    int _subaddiedialog_entrypoint_15();
    int func_80800478_gcdialogexec();
    void func_80800A50_gcdialogexec(u8 *, s32);
    int func_80801DB4_gcdialogexec();
    int func_80802020_gcdialogexec();
    s32 scanCode;
    s32 i;
    s32 result = -1;
    s32 face[6];
    s32 side[3];
    s32 handled;
    void *texts[8];
    s32 scanIndex;

    if (((Dialog *)arg0)->flags & 0x80) {
        func_80015ECC(0, face);
        func_80015F5C(0, side);
    } else {
        func_80015E80(0, face);
        func_80015F28(0, side);
    }
    switch (((Dialog *)arg0)->state) {
    case 1:
        i = 0;
        for (scanIndex = 0; scanIndex < 2; scanIndex++) {
            if (((Dialog *)arg0)->box[scanIndex] == 0) {
                i++;
            }
        }
        if (i == 2) {
            func_80800A50_gcdialogexec(arg0, 7);
        } else if (((Dialog *)arg0)->count == ((u32)((u8 *)arg0)[0x15F] >> 6)) {
            ((Dialog *)arg0)->opened = 0;
            func_80800A50_gcdialogexec(arg0, 2);
        }
        break;
    case 2:
        handled = 0;
        ((Dialog *)arg0)->code[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->code;
        ((Dialog *)arg0)->data[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->text;
        switch (((Dialog *)arg0)->code[((Dialog *)arg0)->current]) {
        case -8:
            func_80800478_gcdialogexec(arg0, *((Dialog *)arg0)->data[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        case -9:
            if (!(((Dialog *)arg0)->flags & 0x200)) {
                _gcdialogcamera_entrypoint_10(arg0, *((Dialog *)arg0)->data[((Dialog *)arg0)->current], 0);
            }
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        case -2:
            ((Dialog *)arg0)->value = *((Dialog *)arg0)->data[((Dialog *)arg0)->current];
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            func_80800A50_gcdialogexec(arg0, 11);
            handled = 1;
            break;
        case -1:
            if (_subaddiedialog_entrypoint_15(((Dialog *)arg0)->caller, ((Dialog *)arg0)->dialogId, ((Dialog *)arg0)->index[((Dialog *)arg0)->current]) == 1) {
                func_80800A50_gcdialogexec(arg0, 9);
            }
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        }
        if (handled) {
            break;
        }
        if (((Dialog *)arg0)->box[((Dialog *)arg0)->current] == 0 || _gczoombox_entrypoint_39(((Dialog *)arg0)->box[((Dialog *)arg0)->current]) || ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy) {
            ((Dialog *)arg0)->current ^= 1;
            break;
        }
        switch (((Dialog *)arg0)->code[((Dialog *)arg0)->current]) {
        case -10:
        case -11:
            do {
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
                ((Dialog *)arg0)->code[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->code;
            } while (((Dialog *)arg0)->code[((Dialog *)arg0)->current] == -10 || ((Dialog *)arg0)->code[((Dialog *)arg0)->current] == -11);
            break;
        case -4:
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current] == 0) {
                ((Dialog *)arg0)->skipped++;
            }
            _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 1;
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy = 1;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -5:
            _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            _gczoombox_entrypoint_10((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy = 1;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -7:
            for (scanIndex = ((Dialog *)arg0)->index[((Dialog *)arg0)->current]; (scanCode = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + scanIndex * 8))->code) < -5; scanIndex++) {}
            if (scanCode >= 0) {
                _gczoombox_entrypoint_37(((Dialog *)arg0)->box[((Dialog *)arg0)->current], scanCode + 12);
            }
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current]) {
                _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            }
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current] == 0 && ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode == 2) {
                _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            }
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -6:
            _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        default:
            if (((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))[1].code == -10) {
                result = func_80801DB4_gcdialogexec(arg0);
            } else if (((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))[1].code == -11) {
                result = func_80802020_gcdialogexec(arg0);
            }
            if (!_gczoombox_entrypoint_1(((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text)) {
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
                break;
            }
            if (func_80800000_gcdialogexec(((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerArg)) {
                _gczoombox_entrypoint_35(((Dialog *)arg0)->box[((Dialog *)arg0)->current], ((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerId, ((Dialog *)arg0)->callerArg);
            }
            if (result == -1) {
                if (_gczoombox_entrypoint_37(((Dialog *)arg0)->box[((Dialog *)arg0)->current], ((Dialog *)arg0)->code[((Dialog *)arg0)->current] + 12)) {
                    _gczoombox_entrypoint_12((void *)((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                    ((Dialog *)arg0)->pending = 1;
                } else {
                    _gczoombox_entrypoint_18(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                }
            }
            if (((Dialog *)arg0)->pending) {
                _gczoombox_entrypoint_11(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                ((Dialog *)arg0)->pending = 0;
            }
            if (result == -1) {
                for (i = ((Dialog *)arg0)->index[((Dialog *)arg0)->current];
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))->code == ((Dialog *)arg0)->code[((Dialog *)arg0)->current] &&
                     i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current] < 8 &&
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))[1].code != -11 &&
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))[1].code != -10;
                     i++) {
                    texts[i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current]] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))->text;
                }
                _gczoombox_entrypoint_32(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                _gczoombox_entrypoint_7(((Dialog *)arg0)->box[((Dialog *)arg0)->current], i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current], texts);
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current] = i;
            } else {
                _gczoombox_entrypoint_32(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                _gczoombox_entrypoint_8(((Dialog *)arg0)->box[((Dialog *)arg0)->current], arg0);
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            }
            func_80800A50_gcdialogexec(arg0, 3);
            break;
        }
        break;
    case 3:
        if ((((Dialog *)arg0)->flags & 1) && face[1] == 1) {
            func_80800A50_gcdialogexec(arg0, 6);
        } else if (!(((Dialog *)arg0)->flags & 0x40)) {
            if ((((Dialog *)arg0)->flags & 0x80) ? func_80015F0C(0, 1) == 1 : func_80015F0C(0, 0) == 1) {
                func_80800A50_gcdialogexec(arg0, 6);
            }
        }
        break;
    case 4:
        if (face[0] == 1) {
            ((Dialog *)arg0)->answer = 1;
            _gcaudiolist_entrypoint_0(6);
        } else if (face[1] == 1) {
            ((Dialog *)arg0)->answer = 0;
            _gcaudiolist_entrypoint_0(7);
        }
        if (((Dialog *)arg0)->answer != -1) {
            func_80800A50_gcdialogexec(arg0, 10);
        }
        break;
    case 7:
        func_80800A50_gcdialogexec(arg0, 0);
        break;
    }
}
/* data_to_c.py: from asm/data/overlays/gc/dialog/exec.data.s */
f32 D_80802EA0_gcdialogexec [4] BT_DATA(4, overlays_gc_dialog_exec, 0x0) = { 0.54f, 0.6f, 0.55f, 0.0f };
