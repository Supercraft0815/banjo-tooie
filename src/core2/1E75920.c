#include "core2/1E75920.h"

s32 func_8009C030() 
{
    return 0x30;
}    typedef struct { u8 pad0[0xE4]; BtIntPtr unkE4; } Obj1E75920_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8009C038(void *arg0) {
    void func_800EFD24(f32 vec[3]);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4));
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0xC);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x18);
}

/* extern */

void func_8009C08C(void *arg0) {
    s32 func_8009C21C();
    void func_800EFD24(f32 vec[3]);
    func_8009C21C();
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
}

s32 func_8009C0BC(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(((Obj1E75920_arg0 *)arg0)->unkE4);
    return func_800EE7F8(((Obj1E75920_arg0 *)arg0)->unkE4 + 0xC, arg1);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_8009C0F8(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1)) {
    s32 func_800EE7F8(BT_IDO_ONLY(s32) BT_PASS2(s32, s32));
    BT_NATIVE_ONLY(return) func_800EE7F8(BT_IDO_ONLY((*(s32 *)((s8 *)(arg0) + (0xE4)))) BT_PASS2((*(s32 *)((s8 *)(arg0) + (0xE4))), bt_a1));
}

void func_8009C118(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 228) + 4) = arg1;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_8009C128(PlayerState *arg0, f32 arg1[3]) {
    s32 func_800EE7F8();
    BT_NATIVE_ONLY(return) func_800EE7F8((BtIntPtr)arg1, *(s32 *)((u8 *)arg0 + 0xE4));
}

f32 func_8009C150(PlayerState *arg0) {
    return (arg0->unkE4)[1];
}

/* Single line: IDO schedules this prologue by source line. */
void func_8009C15C(u8 *arg0, f32 *arg1) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0xC); }

void func_8009C188(u8 *arg0, BtIntPtr arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x18);
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1E75920_func_8009C1B4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009C1B4(void *arg0, f32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xE4)));
    (((Obj1E75920_func_8009C1B4_temp_v0 *)temp_v0)->unk4) = (f32) ((((Obj1E75920_func_8009C1B4_temp_v0 *)temp_v0)->unk4) + arg1);
}

void func_8009C1CC(u8 *arg0, BtIntPtr arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x24);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_8009C1F8(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1)) {
    s32 func_800EE7F8(BT_IDO_ONLY(s32) BT_PASS2(s32, s32));
    BT_NATIVE_ONLY(return) func_800EE7F8(BT_IDO_ONLY((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24) BT_PASS2((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24, bt_a1));
}

s32 func_8009C21C(u8 *arg0) {
    s32 func_800EE7F8();
    s32 temp;

    temp = *(s32 *)(arg0 + 0xE4);
    func_800EE7F8(temp + 0x18, temp + 0xC, temp);
    temp = *(s32 *)(arg0 + 0xE4);
    return func_800EE7F8(temp + 0xC, temp, temp);
}

/* extern */

void func_8009C25C(void *arg0) {
    void func_800EF04C(f32 *arg0, f32 *arg1);
    void func_800EFD24(f32 vec[3]);
    BtIntPtr temp_a0;

    temp_a0 = (((Obj1E75920_arg0 *)arg0)->unkE4);
    func_800EF04C(temp_a0, temp_a0 + 0x24);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
}
