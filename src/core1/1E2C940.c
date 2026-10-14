#include "types.h"
#include "gfx.h"

extern s32 D_80078F88;
extern s32 D_8007913C;
extern OSMesgQueue D_80079010;

s32 func_80014E10(s32 arg0, s32 arg1) {
    extern s32 D_80078F70[];
    void *temp_ptr;
    s32 temp_v0;
    s32 var_v1;

    temp_ptr = heap_alloc_sided(arg1 + 0x40, 1);
    temp_v0 = (s32) temp_ptr;
    D_80078F70[arg0] = temp_v0;
    var_v1 = temp_v0;
    if (temp_v0 & 0x3F) {
        do {
            var_v1 += 1;
        } while (var_v1 & 0x3F);
    }
    return var_v1;
}

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

s32 func_80014ED4(void) {
    extern s32 func_80014F38(void);
    extern s32 D_80078F80;
    return (&D_80078F80)[func_80014F38()];
}

s32 func_80014F00(void) {
    extern s16 D_80078F62;
    extern s16 func_80014F58(void);
    extern s32 D_80078F80;
    return (&D_80078F80)[func_80014F58() ^ D_80078F62];
}

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

void func_80015430(s32 arg0) {
    extern s16 D_80078F60;
    extern s32 D_80078F80;
    D_80078F60 = arg0;
    osViSwapBuffer(((s32 *) &D_80078F80)[D_80078F60]);
}

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

void func_800157EC(s32 *arg0, Gfx **arg1) {
    extern u8 D_800797B8[];
    Gfx *dl;

    dl = (*arg1)++;
    dl->words.w0 = 0xDC080008;
    dl->words.w1 = (u32)(D_800797B8 + ((*arg0 << 4) + 0x80000000));
}

s32 func_80015828(void) {
    extern s16 D_80079778[];
    s32 count;
    for (count = 0; count < 0x20; count++) {
        if (D_80079778[count] == 0) {
            break;
        }
    }
    D_80079778[count] = -1;
    return count;
}

void func_80015860(s32 arg0) {
    extern s16 D_80079778[];
    D_80079778[arg0] = 1;
}

void func_80015878(void) {
    extern s16 D_8003F5E0;
    extern s16 D_80079778[];
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (D_80079778[i] > 0) {
            D_80079778[i] = 0;
        }
    }
    D_8003F5E0 = -1;
}

void func_800158E4(s32 *arg0) { extern s8 D_80079710[]; extern s8 D_80079718[]; func_80015860(*arg0); D_80079710[(s32) ((s8 *) arg0 - D_80079718) / 12] = 0; }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_8001592C.s")

void func_80015A70(s32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    extern u8 D_800797B8[];
    s32 temp_v0;
    void *temp_a0;

    func_80015860(*arg0);
    temp_v0 = func_80015828();
    *arg0 = temp_v0;
    temp_a0 = D_800797B8 + (temp_v0 * 0x10);
    (*(s16 *)((s8 *)(temp_a0) + (4))) = 0x1FF;
    (*(s16 *)((s8 *)(temp_a0) + (6))) = 0;
    (*(s16 *)((s8 *)(temp_a0) + (0xC))) = 0x1FF;
    (*(s16 *)((s8 *)(temp_a0) + (0xE))) = 0;
    (*(s16 *)((s8 *)(temp_a0) + (0))) = (s16) (s32) (arg1 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + (2))) = (s16) (s32) (arg2 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + (8))) = (s16) (s32) (arg3 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + (0xA))) = (s16) (s32) (arg4 * 4.0f);
    osWritebackDCache(temp_a0, 0x200);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2C940/func_80015B34.s")

void func_80015CC0(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    *arg2 = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
    *arg3 = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
    *arg4 = (s32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

void func_80015CE8(void *arg0, void *arg1) {
    f32 func_80015D14(void *);
    void func_800CA510(void *, f32);

    func_800CA510(arg1, func_80015D14(arg0));
}

f32 func_80015D14(void *arg0) {
    extern f32 D_80041710;
    f32 var_f2;

    var_f2 = (f32) (*(s16 *)((s8 *)(arg0) + (8))) / (f32) (*(s16 *)((s8 *)(arg0) + (0xA)));
    if (widescreen_enabled != 0) {
        var_f2 *= D_80041710;
    }
    return var_f2;
}
