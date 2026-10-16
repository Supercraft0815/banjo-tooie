#include <ultra64.h>
#include "gfx.h"
#include "core2/1E99980.h"

extern s32 D_801288B0;
extern s32 D_80128AF4;

int func_800C0090(void *caller, s32 arg1) {
    typedef struct { u8 pad[0x12]; u16 unk12_15:15; u16 unk12_0:1; } Marker;
    return (arg1 == -1) ? 0 : ((Marker *)caller)->unk12_15 == arg1;
}

void func_800C00BC()
{
    _gcdialogDll_entrypoint_0(&D_801288B0);
}

/* extern */

void func_800C00E0(void) {
    void func_800C0658(void);
    void _gcdialogexec_entrypoint_7(s32 *);
    s32 func_800FECB8(s32);
    if (func_800C0638() != 0) {
        func_800FECB8(0);
    }
    func_800C0658();
    _gcdialogexec_entrypoint_7(&D_801288B0);
    (*(s8 *)((s8 *)(&D_801288B0) + (0x15C))) = 0;
    (*(s8 *)((s8 *)(&D_801288B0) + (0x180))) = 0;
}

void func_800C0130(s32 arg0) {
    s32 _gczoombox_entrypoint_2(s32, s32);
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
    s32 _gcdialogcamera_entrypoint_10(s32 *, s16, s32);
    _gcdialogcamera_entrypoint_10(&D_801288B0, arg0, arg1);
}

/* Single line: IDO schedules this prologue by source line. */
void func_800C01D8(s32 arg0, s32 arg1) { s32 _gcdialogexec_entrypoint_5(s32 *, s32, s32); _gcdialogexec_entrypoint_5(&D_801288B0, arg0, arg1); }

int func_800C0208(void) {
    extern s32 D_80128A18;
    void *caller = *(void **)((s8 *)&D_801288B0 + 0x168);
    if (caller == NULL) {
        return 0;
    }
    if (func_800C0090(caller, *(s32 *)((s8 *)&D_801288B0 + 0x16C))) {
        return D_80128A18;
    }
    return 0;
}

s16 func_800C0258(void) {
    return ((s16 *)&D_801288B0)[((u32)*(u16 *)((s8 *)&D_801288B0 + 0x15E) >> 15) + 0x8C] + 12;
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
    }
}

void func_800C0308(void) {
    s32 _gczoombox_entrypoint_38(s32, s16);
    extern s8 D_8011A7C0[];
    struct DialogFlags {
        u32 unused:18;
        u32 queued:1;
        u32 decremented:1;
        u32 rest:12;
    };
    s32 y_position_change;

    if (((struct DialogFlags *)((s8 *)&D_801288B0 + 0x15C))->decremented) {
        (*(s8 *)((s8 *)&D_801288B0 + 0x166))++;
        y_position_change = D_8011A7C0[*(s8 *)((s8 *)&D_801288B0 + 0x166)];
        if (*(s32 *)((s8 *)&D_801288B0 + 0x120) != 0) {
            *(s16 *)((s8 *)&D_801288B0 + 0x128) -= y_position_change;
            _gczoombox_entrypoint_38(*(s32 *)((s8 *)&D_801288B0 + 0x120), *(s16 *)((s8 *)&D_801288B0 + 0x128));
        }
        if (*(s32 *)((s8 *)&D_801288B0 + 0x124) != 0) {
            *(s16 *)((s8 *)&D_801288B0 + 0x12A) += y_position_change;
            _gczoombox_entrypoint_38(*(s32 *)((s8 *)&D_801288B0 + 0x124), *(s16 *)((s8 *)&D_801288B0 + 0x12A));
        }
        if (*(s8 *)((s8 *)&D_801288B0 + 0x166) == 12) {
            ((struct DialogFlags *)((s8 *)&D_801288B0 + 0x15C))->queued = 0;
        }
    } else {
        (*(s8 *)((s8 *)&D_801288B0 + 0x166))--;
        y_position_change = D_8011A7C0[*(s8 *)((s8 *)&D_801288B0 + 0x166)];
        if (*(s32 *)((s8 *)&D_801288B0 + 0x120) != 0) {
            *(s16 *)((s8 *)&D_801288B0 + 0x128) += y_position_change;
            _gczoombox_entrypoint_38(*(s32 *)((s8 *)&D_801288B0 + 0x120), *(s16 *)((s8 *)&D_801288B0 + 0x128));
        }
        if (*(s32 *)((s8 *)&D_801288B0 + 0x124) != 0) {
            *(s16 *)((s8 *)&D_801288B0 + 0x12A) -= y_position_change;
            _gczoombox_entrypoint_38(*(s32 *)((s8 *)&D_801288B0 + 0x124), *(s16 *)((s8 *)&D_801288B0 + 0x12A));
        }
        if (*(s8 *)((s8 *)&D_801288B0 + 0x166) == 0) {
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
        u32 unused:18;
        u32 queued:1;
        u32 decremented:1;
        u32 rest:12;
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

s32 func_800C04C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _gcdialogexec_entrypoint_3(s32 *, s32, s32, s32, s32, s32);
    extern u8 D_80128A30;
    s32 var_v1;

    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_3(&D_801288B0, arg0, arg1, arg2, arg3, arg4);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

u32 func_800C0534(u32 arg0, u32 arg1, f32 *arg2, Unk80132ED0 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 _gcdialogexec_entrypoint_0(s32 *, s32, s32, f32 *, Unk80132ED0 *, s32, s32, s32, s32);
    extern u8 D_80128A30;
    u32 var_v1;

    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_0(&D_801288B0, arg0, arg1, arg2, arg3, arg4, arg5, arg6, (s16) arg7);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

 s32 func_800C05B8(s32 arg0, s32 arg1, f32 *arg2, Unk80132ED0 *arg3, s32 arg4, s32 arg5, s16 arg6) {
    s32 _gcdialogexec_entrypoint_0(s32 *, s32, s32, f32 *, Unk80132ED0 *, s32, s32, s32, s32);
    extern u8 D_80128A30;
    s32 var_v1;
    if (D_80128A30 != 0) {
        var_v1 = _gcdialogexec_entrypoint_0(&D_801288B0, arg0, arg1, arg2, arg3, arg4, arg5, 0, arg6);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_800C0638(void) {
    extern s16 D_80128A12;
    return (D_80128A12 + 1) != 0;
}

s32 func_800C064C(void) {
    extern s16 D_80128A12;
    return *(s16 *)((u8 *)&D_80128A12 + 0);
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
        u8 reserved : 2;
        u8 queue : 1;
        u8 decrement : 1;
        u8 flags : 4;
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
        u8 reserved : 2;
        u8 queue : 1;
        u8 decrement : 1;
        u8 flags : 4;
        u8 pad15F[7];
        s8 index;
    } DialogFlags;
    DialogFlags *g;
    if (!func_800C0638()) return;
    g = (DialogFlags *)&D_801288B0;
    g->queue = 1;
    g->decrement = 1;
    g->index--;
}

void func_800C075C(void) {
    s32 defrag(s32); s32 func_800C7150(s32); extern s32 D_801288B8; s32 *var_s0; s32 temp_a0; s32 temp_a0_2; var_s0 = &D_801288B8 - 2; do { temp_a0 = *(s32 *)((s8 *)var_s0 + 0x120); if (temp_a0 != 0) { *(s32 *)((s8 *)var_s0 + 0x120) = func_800C7150(temp_a0); } if (*(s32 *)((s8 *)&D_801288B0 + 0x12C) != 0) { *(s32 *)((s8 *)&D_801288B0 + 0x12C) = func_800C7150(*(s32 *)((s8 *)&D_801288B0 + 0x12C)); } temp_a0_2 = *(s32 *)((s8 *)var_s0 + 0x104); if (temp_a0_2 != 0) { *(s32 *)((s8 *)var_s0 + 0x104) = defrag(temp_a0_2); } var_s0++; } while (var_s0 != &D_801288B8); }

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
        u8 upper : 4;
        u8 enabled : 1;
        u8 lower : 3;
    };
    ((struct Flags *)&D_801288B0)->enabled = arg0;
}

/* extern */

void func_800C0850(void) {
    s32 _gcdialogexec_entrypoint_6(s32 *, s32);
    (*(u8 *)((s8 *)(&D_801288B0) + (0x11C))) = (u8) ((*(u8 *)((s8 *)(&D_801288B0) + (0x11C))) & 0xFF3F);
    (*(u8 *)((s8 *)(&D_801288B0) + (0x11D))) = (u8) ((*(u8 *)((s8 *)(&D_801288B0) + (0x11D))) & 0xFF3F);
    _gcdialogexec_entrypoint_6(&D_801288B0, 6);
}

void func_800C0890(s32 arg0, s32 arg1) {
    s32 _gcdialogexec_entrypoint_9(s32 *, s32, s32);
    extern s32 D_801288B0;
    _gcdialogexec_entrypoint_9(&D_801288B0, arg0, arg1);
}

void func_800C08C0(void) {
    s32 defrag(s32);
    extern s32 D_80128AF0;
    if (D_80128AF0 != 0) {
        D_80128AF0 = defrag(D_80128AF0);
    }
}

void func_800C08F8(void) {
    s32 _gcnewpause_entrypoint_0(s32);
    extern s32 D_80128AF0;
    D_80128AF0 = _gcnewpause_entrypoint_0(D_80128AF4);
}

void func_800C0920(void) {
    s32 _gcnewpause_entrypoint_1(s32);
    extern s32 D_80128AF0;
    _gcnewpause_entrypoint_1(D_80128AF0);
    D_80128AF0 = 0;
}

s32 func_800C0948(void) {
    s32 _gcnewpause_entrypoint_2(s32);
    extern s32 D_80128AF0;
    s32 var_v1;

    if (D_80128AF0 != 0) {
        var_v1 = _gcnewpause_entrypoint_2(D_80128AF0);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0984.s")

void func_800C0A2C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0A34.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0BC0.s")
#endif

void func_800C0F8C(s32 arg0) {
    s32 func_800EA34C(s32);
    s32 func_80014F00();
    s32 func_8001A0A8();
    s32 func_800C0BC0(s32, s32, s32);
    extern s32 D_80128B00;
    s32 unused;
    s32 sp18;

    func_800EA34C(0);
    D_80128B00 = 2;
    sp18 = func_8001A0A8();
    func_800C0BC0(arg0, sp18, func_80014F00());
}

void func_800C0FD8(s32 arg0) {
    s32 func_80014F00();
    s32 func_8001A0A8();
    s32 func_800C0BC0(s32, s32, s32);
    s32 func_800D6E54(s32);
    void func_800FFD10(s32);
    extern s32 D_80128B00;
    s32 unused;
    s32 sp18;

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

void func_800C1044(s32 arg0) {
    s32 func_800EA34C(s32);
    func_800EA34C(1);
}
