#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr, "failed line %d: %s\n", __LINE__, #x); return __LINE__; } } while (0)
#include "gc/dialog_state.h"

GcDialogState gc_dialog_state;
GcDialogNativeState gc_dialog_native_state;
void gcdialogDll_entrypoint_0(GcDialogState *);
void func_800EFD24(f32 *v) { v[0] = v[1] = v[2] = 0.0f; }
static int zoom_close_calls;
static int zoom_reveal_calls;
static int zoom_finish_calls;
static int zoom_poll_calls;
static BtIntPtr box_results[8];
void func_800C01D8(void) {}
void _gcdialogcamera_entrypoint_10() {}
void _gczoombox_entrypoint_0() { zoom_close_calls++; }
void _gczoombox_entrypoint_10() { zoom_finish_calls++; }
void _gczoombox_entrypoint_11() {}
void _gczoombox_entrypoint_12() { zoom_reveal_calls++; }
void _gczoombox_entrypoint_26() {}
int _gczoombox_entrypoint_33(u8 *p) { CHECK((BtIntPtr)p == box_results[0] || (BtIntPtr)p == box_results[1] || (BtIntPtr)p == box_results[2]); zoom_poll_calls++; return 1; }
void _gczoombox_entrypoint_35() {}
int _gczoombox_entrypoint_39(BtIntPtr p, s32 code) { (void)p; (void)code; return 0; }
void _gczoombox_entrypoint_8() {}
void _gczoombox_entrypoint_9() {}
void _gldbstring_entrypoint_0() {}
void _gldbstring_entrypoint_1() {}
void _gldbstring_entrypoint_2() {}
void _gldialog_entrypoint_5() {}
void _subaddiedialog_entrypoint_12() {}
void _subaddiedialog_entrypoint_13() {}
void func_800C0890() {}
void func_800E715C() {}
void func_800F6438() {}
void func_800FECB8() {}
void func_80015E80(s32 a, void *p) { (void)a; (void)p; }
void func_80015ECC(s32 a, void *p) { (void)a; (void)p; }
void func_80015F28(s32 a, void *p) { (void)a; (void)p; }
void func_80015F5C(s32 a, void *p) { (void)a; (void)p; }
s32 func_80015F0C(s32 a, s32 b) { (void)a; (void)b; return 0; }
int _gcaudiolist_entrypoint_0() { return 0; }
int _gczoombox_entrypoint_1() { return 1; }
int _gczoombox_entrypoint_7() { return 0; }
int _gczoombox_entrypoint_18() { return 0; }
int _gczoombox_entrypoint_32() { return 0; }
int _gczoombox_entrypoint_37(s32 a, s16 b) { (void)a; (void)b; return 0; }
int _subaddiedialog_entrypoint_15() { return 0; }

static const u8 script[] = { 1, 0x81, 1, 'A', 1, 0x82, 1, 'B' };
static BtIntPtr box_results[8] = { 0x123456780100ULL, 0x123456780200ULL, 0x123456780300ULL, 0x123456780400ULL, 0x123456780500ULL, 0x123456780600ULL, 0x123456780700ULL, 0x123456780800ULL };
static int box_count;
static int animation_count;
static int source_released;
static int text_callback_calls;
static u8 callback_text[] = { 0xAE, 0 };
typedef struct { s16 code; s16 pad; u8 *text; } TestText;
static int queue_mode;
static struct { u8 pad[0x12]; u16 id; } actor_marker = { {0}, 0x345 };
void func_80800164_gcdialogexec(u8 *);
void *_gldialog_entrypoint_4(s32 id) { (void)id; return (void *)script; }
s32 _gldialog_entrypoint_1(volatile u8 *text) { (void)text; return 1; }
s32 _subaddiedialog_entrypoint_14(BtIntPtr p, s32 id, s32 seq) { (void)p; (void)id; (void)seq; return -1; }
void *heap_alloc(s32 size) { return calloc(1, (size_t)size); }
void heap_free(void *p) { source_released++; free(p); }
s32 func_800A9C98(void) { return 0; }
s32 func_800C0638(void) { return queue_mode; }
void func_800C0658(void) {}
int func_800EEEA8(f32 *vec) { (void)vec; return 0; }
void func_800EE7F8(f32 *dst, f32 *src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
u32 func_800F54E4(void) { return 0x1234; }
s32 func_800F5B0C(BtIntPtr p) { (void)p; return 0; }
void func_800F82D4(BtIntPtr p, s32 id) { (void)p; (void)id; }
void func_800F8300(BtIntPtr p, s32 mode, f32 *v) { (void)p; (void)mode; (void)v; }
void func_800FEC60(u32 p) { (void)p; }
void func_800E6DD8(char *out, s32 value, u8 mode, s32 format) { (void)value; (void)mode; (void)format; out[0] = 'C'; out[1] = 0; }
s32 text_callback(void *caller, s16 id, s32 seq) { (void)caller; (void)id; (void)seq; text_callback_calls++; return -1; }
BtIntPtr _gczoombox_entrypoint_5(s32 y, s32 id, s32 a, s32 b, BtIntPtr cb) {
    (void)y; (void)a; (void)b; (void)cb;
    return box_results[box_count++];
}
int _gczoombox_entrypoint_24(BtIntPtr p, s32 a) { (void)p; (void)a; return 0; }
int _gczoombox_entrypoint_25(BtIntPtr p, s32 a) { (void)p; (void)a; return 0; }
BtIntPtr _gczoombox_entrypoint_20(BtIntPtr p, f32 scale, s32 a, s32 b, f32 duration, s32 c, s32 d) {
    (void)scale; (void)a; (void)b; (void)duration; (void)c; (void)d;
    CHECK(p == box_results[0] || p == box_results[1] || p == box_results[2] || p == box_results[3] || p == box_results[4] || p == box_results[5] || p == box_results[6] || p == box_results[7]);
    animation_count++;
    return p;
}
void func_80801268_gcdialogexec(void *, s32, s32, void *, BtIntPtr, BtIntPtr, BtIntPtr, s16);
void func_808011A4_gcdialogexec(u8 *, s32, s32, s32, s32, s32);
void func_80800A50_gcdialogexec(u8 *, s32);
int func_80802020_gcdialogexec(u8 *);
int func_80801DB4_gcdialogexec(u8 *);
int func_8080064C_gcdialogexec(u8 *);
int func_80800478_gcdialogexec(u8 *, s32);
s32 gcdialogexec_entrypoint_0(void *, s32, s32, f32 *, void *, void *, void *, void *, s16);
void gcdialogexec_entrypoint_1(u8 *);
void gcdialogexec_entrypoint_2(u8 *);
void gcdialogexec_entrypoint_10(void *);

int main(void) {
    BtIntPtr callback = 0x123456789000ULL;
    gc_dialog_state.flags15C = ~0u;
    gcdialogDll_entrypoint_0(&gc_dialog_state);
    CHECK(gc_dialog_state.unused15c == 0 && gc_dialog_state.numBoxes == 0);
    CHECK(gc_dialog_state.flag7 == 0 && gc_dialog_state.flag5 == 0);
    CHECK(gc_dialog_state.flag6 && gc_dialog_state.flag4 && gc_dialog_state.flag3);
    CHECK(gc_dialog_state.flag2 && gc_dialog_state.flag1 && gc_dialog_state.flag0);
    CHECK(!(gc_dialog_state.mode0 | gc_dialog_state.mode1 | gc_dialog_state.mode2 | gc_dialog_state.mode3));
    gc_dialog_state.flags15C = 0;
    gcdialogDll_entrypoint_0(&gc_dialog_state);
    ((u8 *)&gc_dialog_state)[0x15C] = 1;
    ((u8 *)&gc_dialog_state)[0x15D] = 1;
    gc_dialog_set_box(&gc_dialog_state, 0, (void *)0x123456780000ULL);
    gc_dialog_set_box(&gc_dialog_state, 1, NULL);
    gcdialogexec_entrypoint_10(&gc_dialog_state);
    CHECK(((u8 *)&gc_dialog_state)[0x15C] == 1);
    func_80801268_gcdialogexec(&gc_dialog_state, 0x42, 0, NULL, callback, callback + 8, callback + 16, 0);
    CHECK(box_count == 2);
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 0) != NULL);
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 1) != NULL);
    CHECK(gc_dialog_text_data(&gc_dialog_state, 0) == &script[3]);
    CHECK(gc_dialog_text_data(&gc_dialog_state, 1) == &script[7]);
    CHECK(gc_dialog_box(&gc_dialog_state, 0) == (void *)box_results[0]);
    CHECK(gc_dialog_box(&gc_dialog_state, 1) == (void *)box_results[1]);
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 0) == (uintptr_t)callback);
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 1) == (uintptr_t)(callback + 8));
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 2) == (uintptr_t)(callback + 16));
    CHECK(gc_dialog_state.unk118[0] == 1 && gc_dialog_state.unk118[1] == 2);
    gc_dialog_state.flags15C = 0;
    gc_dialog_set_box(&gc_dialog_state, 0, (void *)box_results[0]);
    gc_dialog_set_box(&gc_dialog_state, 1, (void *)box_results[1]);
    gcdialogexec_entrypoint_2((u8 *)&gc_dialog_state);
    CHECK(zoom_poll_calls == 2 && gc_dialog_state.pending == 2);
    CHECK(gc_dialog_box(&gc_dialog_state, 0) == (void *)box_results[0]);
    gc_dialog_set_box(&gc_dialog_state, 0, NULL);
    gc_dialog_set_box(&gc_dialog_state, 1, NULL);
    gc_dialog_state.flags15C = 0;
    for (s32 channel = 0; channel < 2; channel++) {
        TestText *oldEntries = (TestText *)gc_dialog_text_entry(&gc_dialog_state, channel);
        TestText *testEntries = calloc(2, sizeof(*testEntries));
        CHECK(testEntries != NULL);
        testEntries[0].text = callback_text;
        testEntries[1].code = 0;
        heap_free(oldEntries);
        gc_dialog_set_text_entry(&gc_dialog_state, channel, testEntries);
    }
    *(u16 *)((u8 *)&gc_dialog_state + 0x15E) = 0;
    ((TestText *)gc_dialog_text_entry(&gc_dialog_state, 0))[0].code = -1;
    gc_dialog_state.unk116[0] = 0;
    CHECK(func_8080064C_gcdialogexec((u8 *)&gc_dialog_state) == 1);
    ((TestText *)gc_dialog_text_entry(&gc_dialog_state, 0))[0].code = -2;
    gc_dialog_state.unk116[0] = 0;
    CHECK(func_8080064C_gcdialogexec((u8 *)&gc_dialog_state) == 1);
    CHECK((u8)gc_dialog_state.unk158 == 0xAE);
    gc_dialog_state.unk116[0] = 0;
    gc_dialog_set_callback(&gc_dialog_state, 1, (s32 (*)(void *, s16, s8))(BtFnWord)text_callback);
    CHECK(func_80802020_gcdialogexec((u8 *)&gc_dialog_state) == 0);
    CHECK(text_callback_calls == 1);
    CHECK(func_80801DB4_gcdialogexec((u8 *)&gc_dialog_state) == -1);
    CHECK(text_callback_calls == 2);
    CHECK(func_80800478_gcdialogexec((u8 *)&gc_dialog_state, 9) == 0);
    CHECK(text_callback_calls == 3);
    gc_dialog_set_callback(&gc_dialog_state, 1, (s32 (*)(void *, s16, s8))(BtFnWord)(callback + 8));
    func_808011A4_gcdialogexec((u8 *)&gc_dialog_state, 5, 2, 0xF, 0, 0);
    CHECK(animation_count >= 2);
    gc_dialog_set_box(&gc_dialog_state, 2, (void *)box_results[2]);
    func_80800A50_gcdialogexec((u8 *)&gc_dialog_state, 5);
    CHECK(zoom_reveal_calls >= 1 && zoom_finish_calls >= 1);
    CHECK(gc_dialog_box(&gc_dialog_state, 2) == (void *)box_results[2]);
    func_80800A50_gcdialogexec((u8 *)&gc_dialog_state, 1);
    gc_dialog_set_callback(&gc_dialog_state, 0, NULL);
    gc_dialog_set_callback(&gc_dialog_state, 1, NULL);
    gc_dialog_set_callback(&gc_dialog_state, 2, NULL);
    func_80800A50_gcdialogexec((u8 *)&gc_dialog_state, 8);
    CHECK(gc_dialog_box(&gc_dialog_state, 0) == NULL);
    CHECK(gc_dialog_box(&gc_dialog_state, 1) == NULL);
    CHECK(zoom_close_calls >= 2);
    { int closes = zoom_close_calls; func_80800164_gcdialogexec((u8 *)&gc_dialog_state); CHECK(zoom_close_calls == closes); }
    /* closed boxes are already gone, so the owner close path must not close again */
    /* func_80800164_gcdialogexec was called above */
    CHECK(zoom_close_calls >= 2);
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 0) == NULL);
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 1) == NULL);
    CHECK(gc_dialog_text_data(&gc_dialog_state, 0) == NULL);
    CHECK(gc_dialog_text_data(&gc_dialog_state, 1) == NULL);
    CHECK(gc_dialog_box(&gc_dialog_state, 0) == NULL);
    CHECK(gc_dialog_box(&gc_dialog_state, 1) == NULL);
    CHECK(gc_dialog_callback(&gc_dialog_state, 2) == NULL);
    CHECK(gc_dialog_source(&gc_dialog_state) == NULL);
    CHECK(source_released >= 2);
    gcdialogDll_entrypoint_0(&gc_dialog_state);
    queue_mode = 1;
    CHECK(gcdialogexec_entrypoint_0(&gc_dialog_state, 0x55, 4, NULL, &actor_marker,
                                    (void *)callback, (void *)(callback + 8), (void *)(callback + 16), 0x66) == 1);
    CHECK(gc_dialog_request_actor(&gc_dialog_state, 0) == &actor_marker);
    CHECK((uintptr_t)gc_dialog_request_callback(&gc_dialog_state, 0, 0) == (uintptr_t)callback);
    CHECK((uintptr_t)gc_dialog_request_callback(&gc_dialog_state, 0, 1) == (uintptr_t)(callback + 8));
    CHECK((uintptr_t)gc_dialog_request_callback(&gc_dialog_state, 0, 2) == (uintptr_t)(callback + 16));
    gcdialogexec_entrypoint_1((u8 *)&gc_dialog_state);
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 0) == (uintptr_t)callback);
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 1) == (uintptr_t)(callback + 8));
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 2) == (uintptr_t)(callback + 16));
    queue_mode = 0;
    return 0;
}
