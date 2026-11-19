#include <ultra64.h>
#include "gfx.h"
#include "core2/1E99980.h"

typedef struct PauseState PauseState;

extern s32 D_801288B0;
extern s32 D_80128AF4;

int func_800C0090(void *caller, s32 arg1) {
    typedef struct { u8 pad[0x12]; BT_BITFIELD_ORDER(u16 unk12_15:15, u16 unk12_0 : 1); BT_BITFIELD_ORDER(u16 unk12_0:1, u16 unk12_15 : 15); } Marker;
    return (arg1 == -1) ? 0 : ((Marker *)caller)->unk12_15 == arg1;
}

void func_800C00BC()
{
    _gcdialogDll_entrypoint_0(&D_801288B0);
}    typedef struct { u8 pad0[0x11C]; u8 unk11C; u8 unk11D; u8 pad11E[0x2]; s32 unk120; s32 unk124; s16 unk128; s16 unk12A; s32 unk12C; u8 pad130[0x2E]; u16 unk15E; u8 pad160[0x6]; s8 unk166; u8 pad167[0x1]; void * unk168; s32 unk16C; u8 pad170[0x10]; s8 unk180; } Obj1E99980_D_801288B0; /* offsets.py genstruct: fields from raw offsets on &D_801288B0; rename once understood */

/* extern */

void func_800C00E0(void) {
    void func_800C0658(void);
    void _gcdialogexec_entrypoint_7(s32 *);
    void func_800FECB8(u32 arg0);
    if (func_800C0638() != 0) {
        func_800FECB8(0);
    }
    func_800C0658();
    _gcdialogexec_entrypoint_7(&D_801288B0);
    (*(s8 *)((s8 *)(&D_801288B0) + (0x15C))) = 0;
    (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk180) = 0;
}

void func_800C0130(BtIntPtr arg0) {
    s32 _gczoombox_entrypoint_2(s32, BtIntPtr);
    extern s32 D_801288B8;
    extern s32 D_801289DC;
    s32 *var_s0;
    s32 temp_a0;

    var_s0 = &D_801288B0; do {
        temp_a0 = var_s0[0x48];
        if (temp_a0 != 0) {
            _gczoombox_entrypoint_2(temp_a0, arg0);
        }
        var_s0++;
    } while (var_s0 != &D_801288B8);
    if (D_801289DC != 0) {
        _gczoombox_entrypoint_2(D_801289DC, arg0);
    }
}

/* extern */

void func_800C01A8(s16 arg0, s32 arg1) {
    void _gcdialogcamera_entrypoint_10(void *arg0, s32 arg1, s32 arg2);
    _gcdialogcamera_entrypoint_10(&D_801288B0, arg0, arg1);
}

/* Single line: IDO schedules this prologue by source line. */
void func_800C01D8(s32 arg0, s32 arg1) { void _gcdialogexec_entrypoint_5(); _gcdialogexec_entrypoint_5(&D_801288B0, arg0, arg1); }

int func_800C0208(void) {
    extern s32 D_80128A18;
    void *caller = ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk168;
    if (caller == NULL) {
        return 0;
    }
    if (func_800C0090(caller, ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk16C)) {
        return D_80128A18;
    }
    return 0;
}

s16 func_800C0258(void) {
    return ((s16 *)&D_801288B0)[((u32)*&((Obj1E99980_D_801288B0 *)&D_801288B0)->unk15E >> 15) + 0x8C] + 12;
}

s32 func_800C0284(void) {
    s32 _gcdialogexec_entrypoint_10(s32 *);
    s32 _gczoombox_entrypoint_4(s32);
    extern s32 D_801288B8;
    extern s32 D_801289DC;
    extern s32 D_80128A0C;
    s32 *var_s0;
    s32 temp_a0;

    if (*(u8 *)&D_80128A0C != 0) {
        _gcdialogexec_entrypoint_10(&D_801288B0);
    }
    var_s0 = &D_801288B0; do {
        temp_a0 = var_s0[0x48];
        if (temp_a0 != 0) {
            _gczoombox_entrypoint_4(temp_a0);
        }
        var_s0++;
    } while (var_s0 != &D_801288B8);
    if (D_801289DC != 0) {
        _gczoombox_entrypoint_4(D_801289DC);
    } BT_NATIVE_ONLY(return 0;)
}

void func_800C0308(void) {
    BT_IDO_ONLY(s32 _gczoombox_entrypoint_38(s32, s16);) BT_NATIVE_ONLY(void _gczoombox_entrypoint_38(u8 *, s32);)
    extern s8 D_8011A7C0[];
    struct DialogFlags {
        BT_BITFIELD_ORDER(u32 unused:18, u32 rest : 12);
        BT_BITFIELD_ORDER(u32 queued:1, u32 decremented : 1);
        BT_BITFIELD_ORDER(u32 decremented:1, u32 queued : 1);
        BT_BITFIELD_ORDER(u32 rest:12, u32 unused : 18);
    };
    s32 y_position_change;

    if (((struct DialogFlags *)((s8 *)&D_801288B0 + 0x15C))->decremented) {
        (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166)++;
        y_position_change = D_8011A7C0[((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166];
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk120 != 0) {
            ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk128 -= y_position_change;
            _gczoombox_entrypoint_38(((Obj1E99980_D_801288B0 *)&D_801288B0)->unk120, ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk128);
        }
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk124 != 0) {
            ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12A += y_position_change;
            _gczoombox_entrypoint_38(((Obj1E99980_D_801288B0 *)&D_801288B0)->unk124, ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12A);
        }
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166 == 12) {
            ((struct DialogFlags *)((s8 *)&D_801288B0 + 0x15C))->queued = 0;
        }
    } else {
        (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166)--;
        y_position_change = D_8011A7C0[((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166];
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk120 != 0) {
            ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk128 += y_position_change;
            _gczoombox_entrypoint_38(((Obj1E99980_D_801288B0 *)&D_801288B0)->unk120, ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk128);
        }
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk124 != 0) {
            ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12A -= y_position_change;
            _gczoombox_entrypoint_38(((Obj1E99980_D_801288B0 *)&D_801288B0)->unk124, ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12A);
        }
        if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk166 == 0) {
            ((struct DialogFlags *)((s8 *)&D_801288B0 + 0x15C))->queued = 0;
        }
    }
}

void func_800C0438(void) {
    s32 _gcdialogexec_entrypoint_1(s32 *);
    int func_800A819C(void);
    s32 func_800C0284();
    extern s32 D_80128A0C;
    extern u8 D_80128A11;
    struct DialogFlags {
        BT_BITFIELD_ORDER(u32 unused:18, u32 rest : 12);
        BT_BITFIELD_ORDER(u32 queued:1, u32 decremented : 1);
        BT_BITFIELD_ORDER(u32 decremented:1, u32 queued : 1);
        BT_BITFIELD_ORDER(u32 rest:12, u32 unused : 18);
    };
    if (((struct DialogFlags *)&D_80128A0C)->queued) {
        func_800C0308();
    }
    if ((func_800A819C() != 0) && !((struct DialogFlags *)&D_80128A0C)->queued) {
        if ((func_800C0638() == 0) && ((s32) ((u32) D_80128A11 >> 4) > 0)) {
            _gcdialogexec_entrypoint_1(&D_801288B0);
            return;
        }
        func_800C0284();
    }
}

s32 func_800C04C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, BtIntPtr arg4) {
    s32 _gcdialogexec_entrypoint_3(s32 *, s32, s32, s32, s32, BtIntPtr);
    extern u8 D_80128A30;
    s32 var_v1;

    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_3(&D_801288B0, arg0, arg1, arg2, arg3, arg4);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

u32 func_800C0534(u32 arg0, u32 arg1, f32 *arg2, Unk80132ED0 *arg3, BtIntPtr arg4, BtIntPtr arg5, BtIntPtr arg6, s32 arg7) {
    BT_IDO_ONLY(s32 _gcdialogexec_entrypoint_0(s32 *, s32, s32, f32 *, Unk80132ED0 *, BtIntPtr, BtIntPtr, BtIntPtr, s32);) BT_NATIVE_ONLY(s32 _gcdialogexec_entrypoint_0(void *, s32, s32, f32 *, void *, void *, void *, void *, s16);)
    extern u8 D_80128A30;
    u32 var_v1;

    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_0(&D_801288B0, arg0, arg1, arg2, arg3, BT_NATIVE_ONLY((void *)) arg4, BT_NATIVE_ONLY((void *)) arg5, BT_NATIVE_ONLY((void *)) arg6, (s16) arg7);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

 s32 func_800C05B8(s32 arg0, s32 arg1, f32 *arg2, Unk80132ED0 *arg3, BtIntPtr arg4, s32 arg5, s16 arg6) {
    BT_IDO_ONLY(s32 _gcdialogexec_entrypoint_0(s32 *, s32, s32, f32 *, Unk80132ED0 *, BtIntPtr, BtIntPtr, BtIntPtr, s32);) BT_NATIVE_ONLY(s32 _gcdialogexec_entrypoint_0(void *, s32, s32, f32 *, void *, void *, void *, void *, s16);)
    extern u8 D_80128A30;
    s32 var_v1;
    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_0(&D_801288B0, arg0, arg1, arg2, arg3, BT_NATIVE_ONLY((void *)) arg4, BT_NATIVE_ONLY((void *)) (BtIntPtr) arg5, 0, arg6);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_800C0638(void) {
    extern s16 D_80128A12;
    return (D_80128A12 + 1) != 0;
}    typedef struct { s16 unk0; } Obj1E99980_D_80128A12; /* offsets.py genstruct: fields from raw offsets on &D_80128A12; rename once understood */

s32 func_800C064C(void) {
    extern s16 D_80128A12;
    return *&((Obj1E99980_D_80128A12 *)&D_80128A12)->unk0;
}

void func_800C0658()
{
    _gcdialogexec_entrypoint_2(&D_801288B0);
}

/* extern */

s32 func_800C067C(s32 arg0) {
    s32 _gcdialogexec_entrypoint_6(s32 *, s32);
    if (func_800C064C() != arg0) {
        return 0;
    }
    _gcdialogexec_entrypoint_6(&D_801288B0, 6);
    return 1;
}

void func_800C06C4(void) {
    typedef struct {
        u8 pad0[0x15E];
        BT_BITFIELD_ORDER(u8 reserved : 2, u8 flags : 4);
        BT_BITFIELD_ORDER(u8 queue : 1, u8 decrement : 1);
        BT_BITFIELD_ORDER(u8 decrement : 1, u8 queue : 1);
        BT_BITFIELD_ORDER(u8 flags : 4, u8 reserved : 2);
        u8 pad15F[7];
        s8 index;
    } DialogFlags;
    DialogFlags *g;
    if (!func_800C0638()) return;
    g = (DialogFlags *)&D_801288B0;
    g->queue = 1;
    g->decrement = 0;
    g->index++;
}

void func_800C0710(void) {
    typedef struct {
        u8 pad0[0x15E];
        BT_BITFIELD_ORDER(u8 reserved : 2, u8 flags : 4);
        BT_BITFIELD_ORDER(u8 queue : 1, u8 decrement : 1);
        BT_BITFIELD_ORDER(u8 decrement : 1, u8 queue : 1);
        BT_BITFIELD_ORDER(u8 flags : 4, u8 reserved : 2);
        u8 pad15F[7];
        s8 index;
    } DialogFlags;
    DialogFlags *g;
    if (!func_800C0638()) return;
    g = (DialogFlags *)&D_801288B0;
    g->queue = 1;
    g->decrement = 1;
    g->index--;
}    typedef struct { u8 pad0[0x104]; BtIntPtr unk104; u8 pad108[0x18]; s32 unk120; } Obj1E99980_func_800C075C_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void func_800C075C(void) {
    void *defrag(void *); s32 func_800C7150(s32); extern s32 D_801288B8; s32 *var_s0; s32 temp_a0; BtIntPtr temp_a0_2; var_s0 = &D_801288B8 - 2; do { temp_a0 = ((Obj1E99980_func_800C075C_var_s0 *)var_s0)->unk120; if (temp_a0 != 0) { ((Obj1E99980_func_800C075C_var_s0 *)var_s0)->unk120 = func_800C7150(temp_a0); } if (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12C != 0) { ((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12C = func_800C7150(((Obj1E99980_D_801288B0 *)&D_801288B0)->unk12C); } temp_a0_2 = ((Obj1E99980_func_800C075C_var_s0 *)var_s0)->unk104; if (temp_a0_2 != 0) { ((Obj1E99980_func_800C075C_var_s0 *)var_s0)->unk104 = defrag(temp_a0_2); } var_s0++; } while (var_s0 != &D_801288B8); }

u32 func_800C07F4(void) {
    extern s32 D_80128A0C;
    return (u32) (D_80128A0C << 0x15) >> 0x1F;
}

void func_800C0808()
{
    _gcdialogexec_entrypoint_8(&D_801288B0);
}

void func_800C082C(s32 arg0) {
    struct Flags {
        u8 pad[0x15E];
        BT_BITFIELD_ORDER(u8 upper : 4, u8 lower : 3);
        u8 enabled : 1;
        BT_BITFIELD_ORDER(u8 lower : 3, u8 upper : 4);
    };
    ((struct Flags *)&D_801288B0)->enabled = arg0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800C0850(void) {
    s32 _gcdialogexec_entrypoint_6(s32 *, s32);
    (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk11C) = (u8) ((((Obj1E99980_D_801288B0 *)&D_801288B0)->unk11C) & 0xFF3F);
    (((Obj1E99980_D_801288B0 *)&D_801288B0)->unk11D) = (u8) ((((Obj1E99980_D_801288B0 *)&D_801288B0)->unk11D) & 0xFF3F);
    BT_NATIVE_ONLY(return) _gcdialogexec_entrypoint_6(&D_801288B0, 6);
}

void func_800C0890(s32 arg0, s32 arg1) {
    void _gcdialogexec_entrypoint_9(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 D_801288B0;
    _gcdialogexec_entrypoint_9(&D_801288B0, arg0, arg1);
}

void func_800C08C0(void) {
    void *defrag(void *);
    extern PauseState *D_80128AF0;
    if (D_80128AF0 != 0) {
        D_80128AF0 = defrag(D_80128AF0);
    }
}

void func_800C08F8(void) {
    PauseState *_gcnewpause_entrypoint_0(u32);
    extern PauseState *D_80128AF0;
    D_80128AF0 = _gcnewpause_entrypoint_0(D_80128AF4);
}

void func_800C0920(void) {
    void _gcnewpause_entrypoint_1(PauseState *);
    extern PauseState *D_80128AF0;
    _gcnewpause_entrypoint_1(D_80128AF0);
    D_80128AF0 = 0;
}

s32 func_800C0948(void) {
    u32 _gcnewpause_entrypoint_2(PauseState *);
    extern PauseState *D_80128AF0;
    s32 var_v1;

    if (D_80128AF0 != 0) {
        var_v1 = _gcnewpause_entrypoint_2(D_80128AF0);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800C0984(BtIntPtr arg0) {
    void _gcnewpause_entrypoint_3(BtUIntPtr, PauseState *);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) func_800A8178(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) func_800A8184(void);
    void func_800C0F8C(BtIntPtr);
    void func_800C0FD8(BtIntPtr);
    void func_800C1044(BtIntPtr);
    void func_800D58CC(void);
    extern s32 D_8011A7D0;
    extern PauseState *D_80128AF0;

    if (func_800A8184() != 4) {
        if (D_8011A7D0 == 0) {
            func_800C1044(arg0);
        }
        D_8011A7D0 = 1;
        return;
    }
    if (func_800A8178() == 0) {
        if (D_8011A7D0 != 0) {
            func_800D58CC();
            func_800C0F8C(arg0);
            D_8011A7D0 = 0;
        } else {
            func_800C0FD8(arg0);
        }
        if (D_80128AF0 != 0) {
            _gcnewpause_entrypoint_3(arg0, D_80128AF0);
        }
    }
}

void func_800C0A2C(void) {
}

s32 func_800C0A34(void) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    s32 func_80015FA0(s32);
    s32 func_800C9510();
    s32 func_800C95D4();
    s32 func_800D3948();
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    u32 func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    int func_800F6774(BtUIntPtr);
    extern u8 D_8012762C;
    s32 temp_s2;
    s32 temp_t6;
    BtUIntPtr temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;

    var_s1 = D_8012762C;
    var_s1 = var_s1 != 0;
    if (var_s1 != 0) {
        var_s1 = func_800C95D4() != 0;
        if (var_s1 != 0) {
            var_s1 = func_800C9510() == 0;
            if (var_s1 != 0) {
                var_s1 = func_800C0638() == 0;
            }
        }
    }
    var_s0 = var_s1;
    if (func_800D3948() == 0) {
        temp_v0 = func_800F54E4();
        var_s1 = func_800F6438(temp_v0) != 0;
        if (var_s1 != 0) {
            var_s1 = func_800DB9B0() == 0;
        }
        var_s0 &= var_s1;
        if (var_s0 && (func_800F6774(temp_v0) != 0) && (func_80015FA0(0) == 1)) {
            D_80128AF4 = 0;
            return 1;
        }
        goto block_21;
    }
    if (var_s1 != 0) {
        temp_s2 = _gcstatusDll_entrypoint_11();
        var_s1 = func_800DA298(0x6B6) != 0;
        if (var_s1 != 0) {
            var_s1 = func_800DA298(0x6E3) == 0;
        }
        var_s0 = 0;
        if (temp_s2 > 0) {
loop_15:
            if ((func_80015FA0(var_s0) == 1) && ((var_s1 != 0) || ((func_800F6438(var_s0) != 0) && (func_800F6774(var_s0) != 0)))) {
                D_80128AF4 = var_s0;
                return 1;
            }
            var_s0 += 1;
            if (var_s0 == temp_s2) {
                goto block_21;
            }
            goto loop_15;
        }
        goto block_21;
    }
block_21:
    return 0;
}

s32 func_800C0BB4()
{
    return D_80128AF4;
}

// Probably a file split here based on bk decomp and bss (D_80128AF4)

extern Gfx D_8011A7E0[];
extern Gfx D_8011A840[];

#define ROUND_UP_DIVIDE(x, y) (((x) + (y) - 1) / (y))

#if 0
// Scratch: https://decomp.me/scratch/iFD8T
// Much higher percent scratch with expanded macros: https://decomp.me/scratch/cyGKA

// copy_framebuffer
void func_800C0BC0(Gfx** gfx, void* destination, void* source) {
    s32 row;
    s32 col;
    Gfx* cur_gfx = *gfx;
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(destination));
    
    for (row = 0; row < ROUND_UP_DIVIDE(SCREEN_HEIGHT, 32); row++) {
        for (col = 0; col < ROUND_UP_DIVIDE(SCREEN_WIDTH, 32); col++) {
            gDPLoadTextureTile(cur_gfx++, osVirtualToPhysical(source), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                (col * 32), (row * 32), ((col + 1) * 32 - 1), ((row + 1) * 32 - 1), 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(cur_gfx++,
                (col * 32) * 4, (row * 32) * 4,
                ((col + 1) * 32) * 4, ((row + 1) * 32) * 4,
                0,
                (col * 32) << 5, (row * 32) << 5,
                1 << 10, 1 << 10);
        }
    }
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(func_80014F00()));
    
    *gfx = cur_gfx;
}
#else
s32 func_800C0BC0(BtIntPtr gfx, BtIntPtr destination, BtIntPtr source) {
    BtIntPtr func_80014F00(void);
    s32 row; BT_NATIVE_ONLY(u32 result;)
    s32 col;
    Gfx* cur_gfx = *(Gfx**)gfx;
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(destination));
    for (row = 0; row < ROUND_UP_DIVIDE(SCREEN_HEIGHT, 32); row++) {
        for (col = 0; col < ROUND_UP_DIVIDE(SCREEN_WIDTH, 32); col++) {
// as1 schedules a block by source line number, so the order of these lines decides the match.
#line 1000
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xFD100000 | (SCREEN_WIDTH - 1);
                g->words.w1 = osVirtualToPhysical((void*)source);
            }
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xF5100000 | _SHIFTL((((((col + 1) * 32 - 1) - col * 32 + 1) * 2 + 7) >> 3), 9, 9);
                g->words.w1 = 0x07080200;
            }
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xE6000000;
                g->words.w1 = 0;
            }
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xF4000000 | _SHIFTL((col * 32) << 2, 12, 12) | _SHIFTL((row * 32) << 2, 0, 12);
                g->words.w1 = 0x07000000 | _SHIFTL(((col + 1) * 32 - 1) << 2, 12, 12) | _SHIFTL(((row + 1) * 32 - 1) << 2, 0, 12); } { Gfx* g = cur_gfx++;
                g->words.w0 = 0xE7000000;
                g->words.w1 = 0; } { Gfx* g = cur_gfx++;
                g->words.w1 = 0x00080200;
            {
                Gfx* tile = cur_gfx++;
#line 1019
                Gfx* rectangle = cur_gfx++;
#line 1025
                g->words.w0 = 0xF5100000 | _SHIFTL((((((col + 1) * 32 - 1) - col * 32 + 1) * 2 + 7) >> 3), 9, 9);
                tile->words.w0 = 0xF2000000 | _SHIFTL((col * 32) << 2, 12, 12) | _SHIFTL((row * 32) << 2, 0, 12);
                tile->words.w1 = _SHIFTL(((col + 1) * 32 - 1) << 2, 12, 12) | _SHIFTL(((row + 1) * 32 - 1) << 2, 0, 12);
#line 1020
                rectangle->words.w0 = 0xE4000000 | _SHIFTL(MAX((s16)(((col + 1) * 32) * 4), 0), 12, 12) | _SHIFTL(MAX((s16)(((row + 1) * 32) * 4), 0), 0, 12);
#line 1029
                rectangle->words.w1 = _SHIFTL(MAX((s16)((col * 32) * 4), 0), 12, 12) | _SHIFTL(MAX((s16)((row * 32) * 4), 0), 0, 12);
            }
            }
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xE1000000;
                g->words.w1 = _SHIFTL(((col * 32) << 5) - (((s16)((col * 32) * 4) < 0) ? MIN(((s16)((col * 32) * 4) * (s16)(1 << 10)) >> 7, 0) : 0), 16, 16) |
                    _SHIFTL(((row * 32) << 5) - ((((row * 32) * 4) < 0) ? MIN(((s16)((row * 32) * 4) * (s16)(1 << 10)) >> 7, 0) : 0), 0, 16);
            }
            {
                Gfx* g = cur_gfx++;
                g->words.w0 = 0xF1000000; g->words.w1 = 0x04000400;
            }
        }
    }
    BT_ILP32_ONLY(gDPNoOpTag(cur_gfx++, 0x42544350);) gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(func_80014F00())); BT_NATIVE_ONLY(result = cur_gfx[-1].words.w1;)
    *(Gfx**)gfx = cur_gfx; BT_NATIVE_ONLY(return result;)
}
#line 556
#endif

void func_800C0F8C(BtIntPtr arg0) {
    void func_800EA34C(s32 arg0);
    BtIntPtr func_80014F00();
    s32 func_8001A0A8();
    s32 func_800C0BC0(BtIntPtr, BtIntPtr, BtIntPtr);
    extern s32 D_80128B00;
    s32 unused;
    s32 sp18;

    func_800EA34C(0);
    D_80128B00 = 2;
    sp18 = func_8001A0A8();
    func_800C0BC0(arg0, sp18, func_80014F00());
}

void func_800C0FD8(BtIntPtr arg0) {
    BtIntPtr func_80014F00();
    s32 func_8001A0A8();
    s32 func_800C0BC0(BtIntPtr, BtIntPtr, BtIntPtr);
    s32 func_800D6E54(s32);
    void func_800FFD10(s32);
    extern s32 D_80128B00;
    s32 unused;
    BtIntPtr sp18;

    if (D_80128B00 == 0) {
        func_800D6E54(2);
        func_800FFD10(2);
    } else {
        D_80128B00 -= 1;
    }
    sp18 = func_80014F00();
    func_800C0BC0(arg0, sp18, func_8001A0A8());
}

/* extern */

void func_800C1044(BtIntPtr arg0) {
    void func_800EA34C(s32 arg0);
    func_800EA34C(1);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_801288B0 BT_DATA(4, bss_core2bss1_0_2, 0x1110);
s32 D_801288B8 BT_DATA(4, bss_core2bss1_0_2, 0x1118);
s32 D_801289DC BT_DATA(4, bss_core2bss1_0_2, 0x123C);
s32 D_80128A0C BT_DATA(4, bss_core2bss1_0_2, 0x126C);
u8 D_80128A11 BT_DATA(4, bss_core2bss1_0_2, 0x1271);
s16 D_80128A12 BT_DATA(4, bss_core2bss1_0_2, 0x1272);
s32 D_80128A18 BT_DATA(4, bss_core2bss1_0_2, 0x1278);
u8 D_80128A30 BT_DATA(4, bss_core2bss1_0_2, 0x1290);
PauseState * D_80128AF0 BT_DATA(4, bss_core2bss1_0_2, 0x1350);
s32 D_80128AF4 BT_DATA(4, bss_core2bss1_0_2, 0x1354);
s32 D_80128B00 BT_DATA(4, bss_core2bss1_0_2, 0x1360);
#endif
