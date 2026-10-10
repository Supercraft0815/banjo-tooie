#include "types.h"
#include "gfx.h"

extern s32 D_80078F88;
extern s32 D_8007913C;
extern OSMesgQueue D_80079010;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014E10.s")

void func_80014E6C(void) {
    s32 func_80014E10(s32, s32);
    extern s32 D_80078F80;
    extern s32 D_80078F84;
    D_80078F80 = func_80014E10(0, 0x21D80);
    D_80078F84 = func_80014E10(1, 0x21D80);
    D_80078F88 = func_80014E10(2, 0x10EC0);
}

// get_framebuffer_size_bytes
u32 func_80014EC8() {
    return FRAMEBUFFER_SIZE_BYTES;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014F00.s")

s32 func_80014F38(void) {
    extern s16 D_80078F60;
    return D_80078F60 ^ 1;
}

s32 func_80014F4C(void) {
    extern s16 D_80078F64;

    return D_80078F64;
}

s16 func_80014F58(void) {
    extern s16 D_80078F60;

    return D_80078F60;
}

typedef struct {
    OSMesgQueue* queue;
    OSMesg mesg;
} ViEventHandler;

extern ViEventHandler D_80078F90[8];

// register_vi_handler
void func_80014F64(OSMesgQueue* queue, OSMesg mesg) {
    s32 i;
    for (i = 0; i < ARRLEN(D_80078F90); i++) {
        if (D_80078F90[i].queue == NULL) {
            D_80078F90[i].queue = queue;
            D_80078F90[i].mesg = mesg;
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80014FE8.s")

void func_80015178(s32 arg0)
{
    D_8007913C = arg0;
}

s32 func_80015184()
{
    return D_8007913C;
}

void func_80015190(void) 
{
    osSendMesg(&D_80079010, NULL, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800151BC.s")

void func_80015410()
{
    func_800151BC(0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001546C.s")

void func_8001559C(s32 arg0) {
    osViBlack((u8) arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800155BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015670.s")

s32 func_8001575C()
{
    return D_80078F88;
}

void func_80015768(void) {
    extern s16 D_80078F62;
    D_80078F62 = 1;
}

void wait_one_frame(void) {
    while (osViGetCurrentLine() < 5) {
    }
    while (osViGetCurrentLine() > 5) { 
    }
}

void set_widescreen(s32 enabled) {
    widescreen_enabled = enabled;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800157EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_800158E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001592C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015B34.s")

void func_80015CC0(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    *arg2 = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
    *arg3 = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
    *arg4 = (s32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015CE8.s")

f32 func_80015D14(void *arg0) {
    extern f32 D_80041710;
    f32 var_f2;

    var_f2 = (f32) (*(s16 *)((s8 *)(arg0) + (8))) / (f32) (*(s16 *)((s8 *)(arg0) + (0xA)));
    if (widescreen_enabled != 0) {
        var_f2 *= D_80041710;
    }
    return var_f2;
}
