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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C00E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0130.s")

/* extern */

void func_800C01A8(s16 arg0, s32 arg1) {
    s32 _gcdialogcamera_entrypoint_10(s32 *, s16, s32);
    _gcdialogcamera_entrypoint_10(&D_801288B0, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C01D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0208.s")

s16 func_800C0258(void) {
    return ((s16 *)&D_801288B0)[((u32)*(u16 *)((s8 *)&D_801288B0 + 0x15E) >> 15) + 0x8C] + 12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0438.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C05B8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C06C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C075C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E99980/func_800C0FD8.s")

/* extern */

void func_800C1044(s32 arg0) {
    s32 func_800EA34C(s32);
    func_800EA34C(1);
}
