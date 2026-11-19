#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "check failed at %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)

#undef sprintf
int _gczoombox_entrypoint_34(unsigned char *box);
#include "src/overlays/gc/newoption.c"
#include "gc/newpause.h"

_Static_assert(offsetof(PauseState, optionState) == 0x38, "native pause option state offset");
_Static_assert(sizeof(PauseState) == 0x3A0, "native pause state allocation extent");

static u8 *boxes[30];
static uint64_t arena[32768];
static size_t arena_used;
static int box_count;
static u8 *last_box;
static u32 *last_strings;
static const char *last_text;
static u32 text_result[4];
static u32 *init_strings;
static int callback_seen;
static void *expected_context;
static void *expected_option;

static void callback_probe(void *ctx, void *option, s32 selected, s32 event) {
    CHECK(ctx == expected_context);
    CHECK(option == expected_option);
    CHECK((uintptr_t)option > UINT32_MAX);
    CHECK(selected == 0);
    CHECK(event == 0);
    callback_seen++;
}

static void *high_map(size_t size) {
    size_t offset = (arena_used + 15u) & ~(size_t)15u;
    CHECK(offset + size <= sizeof(arena));
    void *p = (u8 *)arena + offset;
    arena_used = offset + size;
    for (size_t i = 0; i < size; i++) ((u8 *)p)[i] = 0;
    CHECK((uintptr_t)p > UINT32_MAX);
    return p;
}

u8 *_gczoombox_entrypoint_5(s32 y, s32 portrait_id, s32 mode, s32 option,
                            BtIntPtr callback) {
    (void)y; (void)portrait_id; (void)mode; (void)option; (void)callback;
    CHECK(box_count < 30);
    boxes[box_count] = high_map(4096);
    return boxes[box_count++];
}
void _gczoombox_entrypoint_41(void *box, f32 v) { CHECK(box == boxes[box_count - 1]); (void)v; }
void _gczoombox_entrypoint_42(void *box, f32 v) { CHECK(box == boxes[box_count - 1]); (void)v; }
void _gczoombox_entrypoint_26(void *box, s32 a, f32 b, f32 c, s32 d) { CHECK(box == boxes[box_count - 1]); (void)a; (void)b; (void)c; (void)d; }
void _gczoombox_entrypoint_44(void *box, s32 v) { CHECK(box == boxes[box_count - 1]); (void)v; }
void _gczoombox_entrypoint_23(void *box, s32 v) { CHECK(box == boxes[box_count - 1]); (void)v; }
void _gczoombox_entrypoint_20(void *box, f32 a, s32 b, s32 c, f32 d, s32 e, s32 f) { CHECK(box == boxes[box_count - 1]); (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; }
void _gczoombox_entrypoint_21(void *box, s32 v) { CHECK(box == boxes[box_count - 1]); (void)v; }
int _gczoombox_entrypoint_8(void *box, char *text) {
    CHECK(box == boxes[box_count - 1]);
    last_box = box;
    last_text = text;
    return 0;
}
u32 *_gldbstring_entrypoint_1(u32 *strings, s16 index) {
    CHECK(index == 0);
    last_strings = strings;
    return text_result;
}
u32 *_gldbstring_entrypoint_0(u32 *strings, u32 index) {
    CHECK((uintptr_t)strings > UINT32_MAX);
    CHECK(index == 0);
    init_strings = strings;
    return strings;
}
s32 _gldialog_entrypoint_0(void) { return 0; }
void _gczoombox_entrypoint_0(void *a) { (void)a; }
void _gczoombox_entrypoint_4(u8 *a) { (void)a; }
void _gczoombox_entrypoint_9(void *a) { (void)a; }
void _gczoombox_entrypoint_10(void *a) { (void)a; }
void _gczoombox_entrypoint_11(void *a) { (void)a; }
void _gczoombox_entrypoint_12(void) {}
u32 _gczoombox_entrypoint_3(u8 *a) { (void)a; return 0; }
u32 _gczoombox_entrypoint_22(void *a) { (void)a; return 0; }
s16 _gczoombox_entrypoint_29(void *a) { (void)a; return 0; }
int _gczoombox_entrypoint_32(void *a) { (void)a; return 0; }
int _gczoombox_entrypoint_33(u8 *a) { (void)a; return 0; }
int _gczoombox_entrypoint_34(u8 *a) { (void)a; return 0; }
void _gczoombox_entrypoint_27(void *a, void *b) { (void)a; (void)b; }
void _gczoombox_entrypoint_28(u8 *a, s16 b) { (void)a; (void)b; }
void _gczoombox_entrypoint_36(u8 *a, s16 b) { (void)a; (void)b; }
void _gczoombox_entrypoint_38(u8 *a, s32 b) { (void)a; (void)b; }
void _gczoombox_entrypoint_40(u8 *a, s32 b) { (void)a; (void)b; }
void _gczoomboxdata_entrypoint_0(s32 a) { (void)a; }
void func_80015E80(u32 a, void *b) { (void)a; (void)b; }
void func_80016068(u32 a, f32 *b) { (void)a; (void)b; }
f32 func_800D8FF8(void) { return 0.0f; }
s32 func_800D9078(f32 *a) { (void)a; return 0; }
f32 mlAbsF(f32 a) { return a < 0.0f ? -a : a; }

int main(void) {
    PauseState *pause = high_map(sizeof(*pause));
    OptionState *state = &pause->optionState;
    u32 *strings = high_map(4096);
    void *context = high_map(4096);
    u8 *data = state->data;

    CHECK((uintptr_t)pause > UINT32_MAX);
    CHECK((uintptr_t)state > UINT32_MAX);
    CHECK((u8 *)state - (u8 *)pause == offsetof(PauseState, optionState));
    state->native.text = strings;
    *(s16 *)(data + 0x02) = 29;      /* all 29 native box slots */
    *(s16 *)(data + 0x1DA) = 0;      /* item text index */
    *(s16 *)(data + 0x1DC) = 7;      /* portrait */
    *(s16 *)(data + 0x236) = 8;      /* header portrait */
    *(s16 *)(data + 0x238) = 1;      /* visible text */
    *(f32 *)(data + 0x14) = 1.0f;    /* item spacing */
    *(s16 *)(data + 0x254) = 44;
    *(f32 *)(data + 0x258) = 0.6f;
    *(f32 *)(data + 0x25C) = 0.6f;

    func_80800D28_gcnewoption(state);

    CHECK(box_count == 30);
    for (int i = 0; i < 29; i++) {
        CHECK(optionstate_native_item_box(state, i) == boxes[i]);
        CHECK((uintptr_t)optionstate_native_item_box(state, i) > UINT32_MAX);
    }
    CHECK(optionstate_native_box(state) == boxes[29]);
    CHECK((uintptr_t)optionstate_native_box(state) > UINT32_MAX);
    CHECK(last_box == boxes[29]);
    CHECK(last_strings == strings);
    CHECK((uintptr_t)last_strings > UINT32_MAX);
    CHECK(last_text == (const char *)text_result);

    gcnewoption_entrypoint_5(state, (BtIntPtr)callback_probe, 0, 0,
                             (Unk80132ED0 *)context);
    expected_context = context;
    expected_option = state;
    CHECK(init_strings == strings);
    CHECK(optionstate_native_context(state) == context);
    CHECK((uintptr_t)optionstate_native_context(state) > UINT32_MAX);
    CHECK(optionstate_native_callback(state) == callback_probe);
    CHECK((uintptr_t)optionstate_native_callback(state) > UINT32_MAX);
    box_count = 0;
    *(s16 *)(state->data + 0) = 1;
    gcnewoption_entrypoint_0(state);
    CHECK(callback_seen == 1);
    puts("OptionState LP64 high-pointer path passed");
    return 0;
}
