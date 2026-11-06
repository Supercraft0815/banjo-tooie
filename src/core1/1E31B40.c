#include "common.h"

void func_80013D10(OSMesg);

#ifdef BT_NATIVE
// Host version: the N64 code keeps buffer addresses in s32 globals that it indexes
// as arrays across neighbouring symbols, and writes task records through raw
// offsets. The records match the scheduler's AudioTask/GraphicsTask in 1E2B840.c.
#include "memory.h"
#include "native_scheduler.h"

static void *native_depth_allocation; // D_8007BCC0
static void *native_depth_buffer;     // D_8007BCC4
static NativeSchedulerTask native_tasks[20]; // D_8007BCF8
// D_8007BCD0..E4: two gfx, two matrix/vertex and two extra buffers (one per frame);
// D_8007BCE8/EC and D_8007BCF0/F4: optional larger replacements.
static void *native_frame_buffers[3][2];
static void *native_large_buffers[2][2];

void func_8001A010(void) {
}

void *func_8001A018(s32 arg0) {
    u8 *p = heap_alloc(arg0 + 0x40);
    native_depth_allocation = p;
    return p + ((0x40 - ((uintptr_t)p & 0x3F)) & 0x3F);
}

void func_8001A080(void) {
    native_depth_buffer = func_8001A018(0x21D80);
}

void *func_8001A0A8(void) {
    return native_depth_buffer;
}

u32 func_8001A0B4(void) {
    return 0x00021D80U;
}

u16 func_8001A0C0(s32 arg0, s32 arg1) {
    return *(u16 *)((u8 *)native_depth_buffer + ((arg1 * 0x13) << 5) + (arg0 << 1));
}

void func_8001A0F0(void) {
    extern OSMesgQueue D_8007BEE0;
    osRecvMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A11C(void) {
    extern OSMesgQueue D_8007BEE0;
    osSendMesg(&D_8007BEE0, NULL, 1);
}

static NativeSchedulerTask *next_task(void) {
    extern s16 D_8007BED8;
    NativeSchedulerTask *task;
    func_8001A0F0();
    task = &native_tasks[D_8007BED8];
    D_8007BED8 = (s16)((s32)(D_8007BED8 + 1) % 20);
    func_8001A11C();
    return task;
}

void func_8001A148(Acmd *start, Acmd *end, OSMesgQueue *queue, OSMesg msg) {
    NativeSchedulerTask *task = next_task();
    task->type = 0;
    task->start = start;
    task->end = end;
    task->queue = queue;
    task->msg = msg;
    func_80013D10(task);
}

void func_8001A1E0(Gfx *arg0, Gfx *arg1, s32 arg2) {
    NativeSchedulerTask *task = next_task();
    task->type = 1;
    task->flags = arg2;
    task->start = arg0;
    task->end = arg1;
    func_80013D10(task);
}

void func_8001A270(Gfx *start, Gfx *end) {
    func_8001A1E0(start, end, 0x40000000);
}

void func_8001A290() {
    void func_80015190(void);
    func_80015190();
}

void func_8001A2B0() {
    func_80013D10((OSMesg)3);
}

void func_8001A2D0(void) {
    s32 func_80014C40();
    extern s16 D_8007BED8;
    extern OSMesgQueue D_8007BEE0;
    extern void *D_8007BEF8;
    D_8007BED8 = 0;
    osCreateMesgQueue(&D_8007BEE0, &D_8007BEF8, 1);
    osSendMesg(&D_8007BEE0, NULL, 1);
    func_80014C40();
}

s32 func_8001A63C(void);

void func_8001A324(void) {
    s32 i;
    if (native_frame_buffers[0][0] != NULL) {
        for (i = 0; i < 6; i++) {
            heap_free(native_frame_buffers[i / 2][i % 2]);
        }
        native_frame_buffers[0][0] = NULL;
    }
    func_8001A63C();
}

void func_8001A570(void);

void func_8001A3A0(void) {
    s32 func_800A9800();
    extern s16 D_8007BEDA;
    static const s32 sizes[3] = {0x76C0, 0x12C00, 0x1AE0};
    s32 i;
    if (native_frame_buffers[0][0] == NULL) {
        for (i = 0; i < 6; i++) {
            native_frame_buffers[i / 2][i % 2] = heap_alloc(sizes[i / 2]);
        }
        func_8001A570();
    }
    D_8007BEDA = 0;
    func_800A9800();
}

void func_8001A440(s32 arg0) {
    void func_80015430(s32);
    NativeSchedulerTask *task;
    func_8001A0F0();
    func_80015430(arg0);
    func_8001A11C();
    task = next_task();
    task->type = 7;
    func_80013D10(task);
}

// Fills the caller's {Gfx *, gfx data, extra} triple with this frame's buffers.
void func_8001A4B8(void *arg0) {
    extern s16 D_8007BEDA;
    void **out = arg0;
    D_8007BEDA = 1 - D_8007BEDA;
    out[0] = native_large_buffers[0][0] ? native_large_buffers[0][D_8007BEDA] : native_frame_buffers[0][D_8007BEDA];
    out[1] = native_large_buffers[1][0] ? native_large_buffers[1][D_8007BEDA] : native_frame_buffers[1][D_8007BEDA];
    out[2] = native_frame_buffers[2][D_8007BEDA];
}

void func_8001A570(void) {
}

void func_8001A578(s32 arg0) {
    s32 func_800D3948(void);
    s32 var_v0;
    s32 var_v1;

    if (func_800D3948() != 0) {
        var_v0 = 0x1388;
        if (arg0 != 0) {
            var_v0 = arg0 * 0xE00;
            var_v1 = arg0 * 0x1DB;
        } else {
            var_v1 = 0;
        }
        if (var_v0 != 0) {
            native_large_buffers[0][0] = heap_alloc(var_v0 * 8);
            native_large_buffers[0][1] = heap_alloc(var_v0 * 8);
        }
        if (var_v1 != 0) {
            native_large_buffers[1][0] = heap_alloc(var_v1 << 6);
            native_large_buffers[1][1] = heap_alloc(var_v1 << 6);
        }
    }
}

s32 func_8001A63C(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (native_large_buffers[i][0] != NULL) {
            heap_free(native_large_buffers[i][0]);
            heap_free(native_large_buffers[i][1]);
            native_large_buffers[i][0] = native_large_buffers[i][1] = NULL;
        }
    }
    return 0;
}
#else
extern s32 D_8007BCC4;

void func_8001A010(void) {
}

s32 func_8001A018(s32 arg0) {
    void *heap_alloc(s32);
    extern void *D_8007BCC0;
    s16 *var_v1;

    var_v1 = D_8007BCC0 = heap_alloc(arg0 + 0x40);
    if ((s32)var_v1 % 64) {
        do {
            var_v1++;
        } while ((s32)var_v1 % 64);
    }
    return (s32)var_v1;
}

/* extern */

void func_8001A080(void) {
    s32 func_8001A018(s32);
    D_8007BCC4 = func_8001A018(0x21D80);
}

s32 func_8001A0A8()
{
    return D_8007BCC4;
}

u32 func_8001A0B4(void) {
    return 0x00021D80U;
}

u16 func_8001A0C0(s32 arg0, s32 arg1) { return *(u16 *)((u8 *)D_8007BCC4 + ((arg1 * 0x13) << 5) + (arg0 << 1)); }

void func_8001A0F0(void) {
    extern OSMesgQueue D_8007BEE0;
    osRecvMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A11C(void) {
    extern OSMesgQueue D_8007BEE0;
    osSendMesg(&D_8007BEE0, NULL, 1);
}

void func_8001A148(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    u8 *temp_a0;

    func_8001A0F0();
    temp_a0 = (D_8007BED8 * 0x18) + &D_8007BCF8;
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    (*(s32 *)((s8 *)(temp_a0) + (0))) = 0;
    (*(s32 *)((s8 *)(temp_a0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_a0) + (0xC))) = arg1;
    (*(s32 *)((s8 *)(temp_a0) + (0x10))) = arg2;
    (*(s32 *)((s8 *)(temp_a0) + (0x14))) = arg3;
    func_80013D10(temp_a0);
}

void func_8001A1E0(Gfx *arg0, Gfx *arg1, s32 arg2) {
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    u8 *temp_a0;

    func_8001A0F0();
    temp_a0 = (D_8007BED8 * 0x18) + &D_8007BCF8;
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    (*(s32 *)((s8 *)(temp_a0) + (0))) = 1;
    (*(s32 *)((s8 *)(temp_a0) + (4))) = arg2;
    (*(s32 *)((s8 *)(temp_a0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_a0) + (0xC))) = arg1;
    func_80013D10(temp_a0);
}

void func_8001A270(Gfx *start, Gfx *end) {
    void func_8001A1E0(Gfx *start, Gfx *end, s32 flags);

    func_8001A1E0(start, end, 0x40000000);
}

void func_8001A290()
{
    func_80015190();
}

void func_8001A2B0()
{
    func_80013D10(0x3);
}

void func_8001A2D0(void) {
    s32 func_80014C40();
    extern s16 D_8007BED8;
    extern OSMesgQueue D_8007BEE0;
    extern void *D_8007BEF8;
    D_8007BED8 = 0;
    osCreateMesgQueue(&D_8007BEE0, &D_8007BEF8, 1);
    osSendMesg(&D_8007BEE0, NULL, 1);
    func_80014C40();
}

void func_8001A324(void) {
    s32 func_8001A63C();
    s32 heap_free(s32);
    extern s32 D_8007BCD0;
    extern s32 D_8007BCD4;
    extern s32 D_8007BCD8;
    extern s32 D_8007BCDC;
    extern s32 D_8007BCE0;
    extern s32 D_8007BCE4;
    if (D_8007BCD0 != 0) {
        heap_free(D_8007BCD0);
        heap_free(D_8007BCD4);
        heap_free(D_8007BCD8);
        heap_free(D_8007BCDC);
        heap_free(D_8007BCE0);
        heap_free(D_8007BCE4);
        D_8007BCD0 = 0;
    }
    func_8001A63C();
}

void func_8001A3A0(void) {
    void func_8001A570(void);
    s32 func_800A9800();
    void *heap_alloc(s32);
    extern s32 D_8007BCD0;
    extern s32 D_8007BCD4;
    extern s32 D_8007BCD8;
    extern s32 D_8007BCDC;
    extern s32 D_8007BCE0;
    extern s32 D_8007BCE4;
    extern s16 D_8007BEDA;
    if (D_8007BCD0 == 0) {
        D_8007BCD0 = heap_alloc(0x76C0);
        D_8007BCD4 = heap_alloc(0x76C0);
        D_8007BCD8 = heap_alloc(0x12C00);
        D_8007BCDC = heap_alloc(0x12C00);
        D_8007BCE0 = heap_alloc(0x1AE0);
        D_8007BCE4 = heap_alloc(0x1AE0);
        func_8001A570();
    }
    D_8007BEDA = 0;
    func_800A9800();
}

void func_8001A440(s32 arg0) {
    void func_80015430(s32);
    extern u8 D_8007BCF8;
    extern s16 D_8007BED8;
    s32 *temp_a0;

    func_8001A0F0();
    func_80015430(arg0);
    temp_a0 = (s32 *)((D_8007BED8 * 0x18) + &D_8007BCF8);
    D_8007BED8 = (s16) ((s32) (D_8007BED8 + 1) % 20);
    func_8001A11C();
    *temp_a0 = 7;
    func_80013D10(temp_a0);
}

void func_8001A4B8(void *arg0) {
    extern s32 D_8007BCD0;
    extern s32 D_8007BCD8;
    extern s32 D_8007BCE0;
    extern s32 D_8007BCE8;
    extern s32 D_8007BCF0;
    extern s16 D_8007BEDA;
    D_8007BEDA = 1 - D_8007BEDA;
    if (D_8007BCE8 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (&D_8007BCE8)[D_8007BEDA];
    } else {
        (*(s32 *)((s8 *)(arg0) + (0))) = (&D_8007BCD0)[D_8007BEDA];
    }
    if (D_8007BCF0 != 0) {
        (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (&D_8007BCF0)[D_8007BEDA];
    } else {
        (*(s32 *)((s8 *)(arg0) + (4))) = (&D_8007BCD8)[D_8007BEDA];
    }
    (*(s32 *)((s8 *)(arg0) + (8))) = (&D_8007BCE0)[D_8007BEDA];
}

void func_8001A570(void) {
}

void func_8001A578(s32 arg0) {
    s32 func_800D3948(void);
    void *heap_alloc(s32);
    extern s32 D_8007BCE8;
    extern s32 D_8007BCF0;
    void *sp34;
    void *sp30;
    void *sp2C;
    void *sp28;
    s32 var_v0;
    s32 var_v1;

    if (func_800D3948() != 0) {
        var_v0 = 0x1388;
        if (arg0 != 0) {
            var_v0 = arg0 * 0xE00;
            var_v1 = arg0 * 0x1DB;
        } else {
            var_v1 = 0;
        }
        if (var_v0 != 0) {
            sp34 = heap_alloc(var_v0 * 8);
            sp30 = heap_alloc(var_v0 * 8);
            (*(s32 *)((s8 *)(&D_8007BCE8) + (4))) = sp30;
            (*(s32 *)((s8 *)(&D_8007BCE8) + (0))) = sp34;
        }
        if (var_v1 != 0) {
            sp2C = heap_alloc(var_v1 << 6);
            sp28 = heap_alloc(var_v1 << 6);
            (*(s32 *)((s8 *)(&D_8007BCF0) + (4))) = sp28;
            (*(s32 *)((s8 *)(&D_8007BCF0) + (0))) = sp2C;
        }
    }
}

s32 func_8001A63C(void) {
    s32 heap_free(s32);
    extern s32 D_8007BCE8;
    extern s32 D_8007BCEC;
    extern s32 D_8007BCF0;
    extern s32 D_8007BCF4;
    s32 sp18[2];

    sp18[0] = D_8007BCF0;
    if (D_8007BCE8 != 0) {
        heap_free(D_8007BCE8);
        heap_free(D_8007BCEC);
        D_8007BCE8 = 0;
    }
    if (sp18[0] != 0) {
        heap_free(D_8007BCF0);
        heap_free(D_8007BCF4);
        D_8007BCF0 = 0;
    }
}
#endif
