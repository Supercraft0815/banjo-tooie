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

void func_80014FE8(void) {
    extern OSViMode D_8003F4E0, D_8003F530;
    extern u8 *D_80078F68;
    extern s16 D_80078F60, D_80078F64;
    extern OSMesgQueue D_80078FD0, D_80079030;
    extern OSMesg D_80078FE8[10], D_80079028[1], D_80079048[60];
    extern volatile s32 D_80079138;
    extern OSThread D_80079140;
    extern __OSThreadOddFpStorage D_800792F0;
    extern s32 D_80079700;
    void func_80015178(s32);
    void func_8001546C(s32);
    void func_8001DCB0(OSThread *, __OSThreadOddFpStorage *, s32, void (*)(void *), void *, void *, OSPri);
    s32 i;

    osCreateViManager(0xFE);
    switch (osTvType) {
        case 0:
        case 1:
            D_80078F68 = &D_8003F4E0;
            break;
        case 2:
            D_80078F68 = &D_8003F530;
            break;
    }
    osViSetMode(D_80078F68);
    osViBlack(1);
    D_80079700 = 1;
    osViSetSpecialFeatures(0x40);
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(0x20);
    osCreateMesgQueue(&D_80078FD0, D_80078FE8, 10);
    osCreateMesgQueue(&D_80079010, D_80079028, 1);
    osCreateMesgQueue(&D_80079030, D_80079048, 60);
    osViSetEvent(&D_80078FD0, NULL, 1);
    D_80078F60 = 0;
    D_80078F64 = 1;
    for (i = 0; i < 8; i++) {
        D_80078F90[i].queue = NULL;
    }
    D_80079138 = 0;
    func_80015178(2);
    func_8001DCB0(&D_80079140, &D_800792F0, 0, func_8001546C, NULL, &D_80079700, 0x50);
    osStartThread(&D_80079140);
}

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

void func_800151BC(s32 arg0) {
    s32 func_80013474(void);
    void func_80013488(void);
    void func_800134C4(void);
    void func_80013500(OSPri);
    s32 func_80081D28(void);
    extern s16 D_80078F60;
    extern s16 D_80078F62;
    extern s16 D_80078F64;
    extern s32 D_80078F80;
    extern OSMesgQueue D_80079030;
    extern volatile s32 D_80079138;
    extern s32 D_80079700;
    extern s32 D_80079704;

    osSetThreadPri(NULL, 0x7F);
    func_80013500(0x23);
    func_80013488();
    if (arg0 != 0) {
        osRecvMesg(&D_80079010, NULL, 1);
    }
    {
    s32 *const waitCount = &D_80079704;
    if (D_80079138 < func_80015184() - *waitCount) {
    wait_for_frame:
        osRecvMesg(&D_80079030, NULL, 1);
        if (D_80079138 < func_80015184() - *waitCount) {
            goto wait_for_frame;
        }
    }
    while (D_80079030.validCount != 0) {
        osRecvMesg(&D_80079030, NULL, 0);
    }
    if (D_80078F62 == 0) {
        if (D_80079700 != 0 && --D_80079700 == 0) {
            osViBlack(0);
        }
        D_80078F60 = func_80014F38();
        osViSwapBuffer(((s32 *) &D_80078F80)[D_80078F60]);
        for (*waitCount = 0; !(osDpGetStatus() & 2) && osViGetCurrentFramebuffer() != osViGetNextFramebuffer(); (*waitCount)++) {
            osRecvMesg(&D_80079030, NULL, 1);
        }
    } else {
        D_80078F62 = 0;
    }
    D_80078F64 = D_80079138;
    D_80079138 = 0;
    func_800134C4();
    osSetThreadPri(NULL, 0x14);
    while (func_80013474() == 0 && func_80081D28() != 0) {
        osYieldThread();
    }
    func_80013500(0xA);
    }
}

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

void func_8001546C(s32 arg0) {
    void func_80014A54(void);
    void func_8001E5DC(s32);
    s16 func_8001E7C0(void);
    extern s32 D_8003F5D0;
    extern OSMesgQueue D_80078FD0;
    extern OSMesgQueue D_80079030;
    extern volatile s32 D_80079138;
    s32 i;
    OSMesg mesg;
    s32 ready;
    s32 state;
    s32 flag;

    while (1) {
        osRecvMesg(&D_80078FD0, &mesg, OS_MESG_BLOCK);
        func_80014A54();
        D_80079138++;
        ready = D_80079138 == 600;
        state = !func_8001E7C0();
        flag = D_8003F5D0;
        if (ready && state && flag != 0) {
            func_8001E5DC(2);
            D_8003F5D0 = 0;
        }
        osSendMesg(&D_80079030, NULL, OS_MESG_NOBLOCK);
        for (i = 0; i < 8; i++) {
            if (D_80078F90[i].queue != NULL) {
                osSendMesg(D_80078F90[i].queue, D_80078F90[i].mesg, OS_MESG_NOBLOCK);
            }
        }
    }
}

void func_8001559C(s32 arg0) {
    osViBlack((u8) arg0);
}

void func_800155BC(void) {
    s32 aligned8_memset(s32 dst, s32 value, s32 size);
    extern s32 D_80078F80;
    extern s32 D_80078F84;

    if (D_80078F80 != 0) {
        aligned8_memset(D_80078F80, 0x10001, 0x21D80);
        osWritebackDCache(D_80078F80, 0x21D80);
    }
    if (D_80078F84 != 0) {
        aligned8_memset(D_80078F84, 0x10001, 0x21D80);
        osWritebackDCache(D_80078F84, 0x21D80);
    }
    if (D_80078F88 != 0) {
        aligned8_memset(D_80078F88, 0x10001, 0x10EC0);
        osWritebackDCache(D_80078F88, 0x10EC0);
    }
}

void func_80015670(s32 arg0, s32 arg1) {
    extern u8 *D_80078F68;
    s32 *sp2C = (s32 *)(D_80078F68 + 0x30);
    s32 *sp28 = (s32 *)(D_80078F68 + 0x44);
    s16 *sp24 = (s16 *)(D_80078F68 + 0x1C);
    u32 temp_v0;
    s16 *sp1C = (s16 *)(D_80078F68 + 0x30);
    s16 *sp18 = (s16 *)(D_80078F68 + 0x32);

    if (arg0 < -0x20) {
        arg0 = -0x20;
    } else if (arg0 >= 0x21) {
        arg0 = 0x20;
    }
    if (arg1 < -0x28) {
        arg1 = -0x28;
    } else if (arg1 >= 0x19) {
        arg1 = 0x18;
    }
    temp_v0 = osSetIntMask(0x80401U);
    sp24[0] = arg0 + 0x80;
    sp24[1] = arg0 + 0x2E0;
    *sp1C = arg1 + 0x30;
    *sp18 = arg1 + 0x1F4;
    *sp28 = *sp2C;
    osSetIntMask(temp_v0);
}

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

void func_800158E4(s32 *arg0) { extern u8 D_80079710[]; extern s8 D_80079718[]; func_80015860(*arg0); D_80079710[(s32) ((s8 *) arg0 - D_80079718) / 12] = 0; }

void *func_8001592C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 D_80079710[];
    extern s8 D_80079718[];
    extern u8 D_800797B8[];
    struct Entry { s32 index; s16 x, y, w, h; };
    struct Vp { s16 d[8]; };
    s32 i;
    struct Vp *v;
    struct Entry *e;

    for (i = 0; i < 8; i++) {
        if (D_80079710[i] == 0) {
            break;
        }
    }
    D_80079710[i] = 1;
    e = (struct Entry *)((s32)D_80079718 + i * 12);
    e->index = func_80015828();
    v = (struct Vp *)(D_800797B8 + e->index * 16);
    e->w = arg2;
    e->x = arg0;
    e->h = arg3;
    e->y = arg1;
    v->d[0] = arg2 * 2;
    v->d[1] = arg3 * 2;
    v->d[2] = 0x1FF;
    v->d[3] = 0;
    v->d[6] = 0x1FF;
    v->d[7] = 0;
    v->d[4] = (s32)(((f32)arg0 + (f32)arg2 * 0.5f) * 4.0f);
    v->d[5] = (s32)(((f32)arg1 + (f32)arg3 * 0.5f) * 4.0f);
    osWritebackDCache(v, 0x200);
    return e;
}


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

void func_80015B34(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern u8 D_800797B8[];
    s32 width;
    s32 height;
    s32 index;
    s32 right;
    s32 bottom;
    s16 *viewport;

    func_80015860(*(s32 *)arg0);
    index = func_80015828();
    *(s32 *)arg0 = index;
    viewport = ((s16 (*)[8])D_800797B8)[*(s32 *)arg0];
    right = arg1 + arg3;
    bottom = arg2 + arg4;
    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 >= 0x131) {
        arg1 = 0x130;
    }
    if (arg2 < 0) {
        arg2 = 0;
    } else if (arg2 >= 0xE5) {
        arg2 = 0xE4;
    }
    if (right < 0) {
        right = 0;
    } else if (right >= 0x131) {
        right = 0x130;
    }
    width = right - arg1;
    if (bottom < 0) {
        bottom = 0;
    } else if (bottom >= 0xE5) {
        bottom = 0xE4;
    }
    height = bottom - arg2;
    ((s16 *)arg0)[4] = width;
    ((s16 *)arg0)[5] = height;
    ((s16 *)arg0)[2] = arg1;
    ((s16 *)arg0)[3] = arg2;
    viewport[0] = width * 2;
    viewport[1] = height * 2;
    viewport[2] = 0x1FF;
    viewport[3] = 0;
    viewport[6] = 0x1FF;
    viewport[7] = 0;
    viewport[4] = (s32)(((f32)arg1 + (f32)width * 0.5f) * 4.0f);
    viewport[5] = (s32)(((f32)arg2 + (f32)height * 0.5f) * 4.0f);
    osWritebackDCache(D_800797B8 + index * 0x10, 0x200);
}

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
