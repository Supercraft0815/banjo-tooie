#include <stdint.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
#include "gc/dialog_state.h"

void gcdialogDll_entrypoint_0(GcDialogState *);
void func_800C00E0(void);
static unsigned reset_callbacks;
void _gcdialogexec_entrypoint_2(u8 *dialog) { if (dialog == (u8 *)&gc_dialog_state) reset_callbacks |= 1u; }
void _gcdialogexec_entrypoint_7(GcDialogState *dialog) { if (dialog == &gc_dialog_state) reset_callbacks |= 2u; }
void func_800FECB8(u32 value) { (void)value; reset_callbacks |= 4u; }
void func_800C075C(void);
void func_800C0308(void);
BtIntPtr func_800C7150(BtIntPtr p) { return p + 0x10; }
void *defrag(void *p) { return (void *)((uintptr_t)p + 0x20); }
s8 D_8011A7C0[16];
static int zoom_calls;
static BtIntPtr zoom_ptrs[2];
void _gczoombox_entrypoint_38(BtIntPtr box, s32 y) { (void)y; if (zoom_calls < 2) zoom_ptrs[zoom_calls] = box; zoom_calls++; }
void func_800EFD24(f32 *v) { v[0] = v[1] = v[2] = 0.0f; }

int main(void) {
    void *p[10];
    int i;
    CHECK(sizeof(GcDialogState) == 0x234);
    for (i = 0; i < 10; i++) p[i] = (void *)(uintptr_t)(0x123456780000ULL + (uintptr_t)(i + 1) * 0x100);
    CHECK((uintptr_t)p[0] > UINT32_MAX);
    gc_dialog_state.flags15C = ~0u;
    gc_dialog_state.unused15c = 0xA5;
    gc_dialog_state.numBoxes = 0x72;
    gc_dialog_state.unk162 = -1;
    gc_dialog_state.unk180 = 1;
    u32 expected = gc_dialog_state.flags15C;
    gc_dialog_state.unused15c = 0;
    u32 closed = gc_dialog_state.flags15C;
    gc_dialog_state.flags15C = expected;
    func_800C00E0();
    CHECK(reset_callbacks == 3 && gc_dialog_state.unk180 == 0);
    CHECK(gc_dialog_state.flags15C == closed && gc_dialog_state.numBoxes == 0x72);
    gcdialogDll_entrypoint_0(&gc_dialog_state);
    for (i = 0; i < 2; i++) {
        gc_dialog_set_text_entry(&gc_dialog_state, i, p[i]);
        gc_dialog_set_text_data(&gc_dialog_state, i, p[i + 2]);
        CHECK(gc_dialog_text_entry(&gc_dialog_state, i) == p[i]);
        CHECK(gc_dialog_text_data(&gc_dialog_state, i) == p[i + 2]);
        CHECK(gc_dialog_state.unk104[i] == 0 && gc_dialog_state.unk10C[i] == 0);
    }
    for (i = 0; i < 3; i++) {
        gc_dialog_set_box(&gc_dialog_state, i, p[i + 4]);
        CHECK(gc_dialog_box(&gc_dialog_state, i) == p[i + 4]);
    }
    gc_dialog_set_caller(&gc_dialog_state, p[7]);
    CHECK(gc_dialog_caller(&gc_dialog_state) == p[7]);
    gc_dialog_set_callback(&gc_dialog_state, 0, (s32 (*)(void *, s16, s8))(uintptr_t)p[5]);
    CHECK((uintptr_t)gc_dialog_callback(&gc_dialog_state, 0) == (uintptr_t)p[5]);
    for (i = 0; i < 4; i++) {
        gc_dialog_set_request_actor(&gc_dialog_state, i, p[8]);
        gc_dialog_set_request_callback(&gc_dialog_state, i, 0, p[9]);
        gc_dialog_set_request_callback(&gc_dialog_state, i, 1, p[7]);
        gc_dialog_set_request_callback(&gc_dialog_state, i, 2, p[6]);
        CHECK(gc_dialog_request_actor(&gc_dialog_state, i) == p[8]);
        CHECK(gc_dialog_request_callback(&gc_dialog_state, i, 0) == p[9]);
        CHECK(gc_dialog_request_callback(&gc_dialog_state, i, 1) == p[7]);
        CHECK(gc_dialog_request_callback(&gc_dialog_state, i, 2) == p[6]);
    }
    gc_dialog_set_text_entry(&gc_dialog_state, 0, p[0]);
    gc_dialog_set_text_data(&gc_dialog_state, 1, p[1]);
    gc_dialog_set_box(&gc_dialog_state, 0, p[2]);
    gc_dialog_set_box(&gc_dialog_state, 1, p[3]);
    gc_dialog_set_box(&gc_dialog_state, 2, p[4]);
    func_800C075C();
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 0) == (void *)((uintptr_t)p[0] + 0x20));
    CHECK(gc_dialog_text_data(&gc_dialog_state, 1) == p[1]);
    CHECK(gc_dialog_box(&gc_dialog_state, 0) == (void *)((uintptr_t)p[2] + 0x10));
    CHECK(gc_dialog_box(&gc_dialog_state, 1) == (void *)((uintptr_t)p[3] + 0x10));
    CHECK(gc_dialog_box(&gc_dialog_state, 2) == (void *)((uintptr_t)p[4] + 0x20));
    gc_dialog_set_box(&gc_dialog_state, 0, p[2]);
    gc_dialog_set_box(&gc_dialog_state, 1, p[3]);
    gc_dialog_state.unk166 = 11;
    gc_dialog_state.decremented = 1;
    gc_dialog_state.queued = 1;
    D_8011A7C0[12] = 5;
    zoom_calls = 0;
    func_800C0308();
    CHECK(zoom_calls == 2 && zoom_ptrs[0] == (BtIntPtr)p[2] && zoom_ptrs[1] == (BtIntPtr)p[3]);
    CHECK(gc_dialog_state.unk166 == 12 && gc_dialog_state.queued == 0);
    gcdialogDll_entrypoint_0(&gc_dialog_state);
    CHECK(gc_dialog_text_entry(&gc_dialog_state, 0) == 0);
    CHECK(gc_dialog_text_data(&gc_dialog_state, 1) == 0);
    CHECK(gc_dialog_box(&gc_dialog_state, 2) == 0);
    CHECK(gc_dialog_caller(&gc_dialog_state) == 0);
    CHECK(gc_dialog_callback(&gc_dialog_state, 0) == 0);
    CHECK(gc_dialog_request_actor(&gc_dialog_state, 3) == 0);
    CHECK(gc_dialog_request_callback(&gc_dialog_state, 3, 0) == 0);
    CHECK(gc_dialog_request_callback(&gc_dialog_state, 3, 1) == 0);
    CHECK(gc_dialog_request_callback(&gc_dialog_state, 3, 2) == 0);
    return 0;
}
