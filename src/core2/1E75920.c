#include "core2/1E75920.h"
#ifdef BT_NATIVE
#include "core2/1EC8070.h"
#endif

s32 func_8009C030() 
{
    return 0x30;
} typedef struct { u8 pad0[0xE4]; union { BtIntPtr unkE4; void * unkE4_voidp; }; } Obj1E75920_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

#ifdef BT_NATIVE
void func_8009C038(PlayerState *player) {
    func_800EFD24(player->unkE4 + 9);
    func_800EFD24(player->unkE4);
    func_800EFD24(player->unkE4 + 3);
    func_800EFD24(player->unkE4 + 6);
}
#else
void func_8009C038(void *arg0) {
    void func_800EFD24(f32 vec[3]);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4));
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0xC);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x18);
}
#endif
/* extern */

#ifdef BT_NATIVE
void func_8009C08C(PlayerState *player) {
    func_8009C21C(player);
    func_800EFD24(player->unkE4 + 9);
}
#else
void func_8009C08C(void *arg0) {
    s32 func_8009C21C();
    void func_800EFD24(f32 vec[3]);
    func_8009C21C();
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
}
#endif
#ifdef BT_NATIVE
void func_8009C0BC(PlayerState *player, f32 position[3]) {
    func_800EE7F8(player->unkE4, position);
    func_800EE7F8(player->unkE4 + 3, position);
}
#else
s32 func_8009C0BC(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(((Obj1E75920_arg0 *)arg0)->unkE4);
    return func_800EE7F8(((Obj1E75920_arg0 *)arg0)->unkE4 + 0xC, arg1);
}
#endif
/* extern */

#ifdef BT_NATIVE
void func_8009C0F8(PlayerState *player, f32 position[3]) {
    func_800EE7F8(player->unkE4, position);
}
#else
void func_8009C0F8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(*(s32 *)((s8 *)arg0 + 0xE4));
}
#endif
#ifdef BT_NATIVE
void func_8009C118(PlayerState *player, f32 y) {
    player->unkE4[1] = y;
}
#else
void func_8009C118(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Obj1E75920_arg0 *)arg0)->unkE4_voidp + 4) = arg1;
}
#endif
#ifdef BT_NATIVE
void func_8009C128(PlayerState *player, f32 position[3]) {
    func_800EE7F8(position, player->unkE4);
}
#else
void func_8009C128(PlayerState *arg0, f32 arg1[3]) {
    s32 func_800EE7F8();
    func_800EE7F8((BtIntPtr)arg1, *(s32 *)((u8 *)arg0 + 0xE4));
}
#endif
f32 func_8009C150(PlayerState *arg0) {
    return (arg0->unkE4)[1];
}

/* Single line: IDO schedules this prologue by source line. */
#ifdef BT_NATIVE
void func_8009C15C(PlayerState *player, f32 position[3]) {
    func_800EE7F8(position, player->unkE4 + 3);
}
#else
void func_8009C15C(u8 *arg0, f32 *arg1) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0xC); }
#endif
#ifdef BT_NATIVE
void func_8009C188(PlayerState *player, f32 position[3]) {
    func_800EE7F8(position, player->unkE4 + 6);
}
#else
void func_8009C188(u8 *arg0, BtIntPtr arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x18);
}
#endif
typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1E75920_func_8009C1B4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

#ifdef BT_NATIVE
void func_8009C1B4(PlayerState *player, f32 delta) {
    player->unkE4[1] += delta;
}
#else
void func_8009C1B4(void *arg0, f32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xE4)));
    (((Obj1E75920_func_8009C1B4_temp_v0 *)temp_v0)->unk4) = (f32) ((((Obj1E75920_func_8009C1B4_temp_v0 *)temp_v0)->unk4) + arg1);
}
#endif
#ifdef BT_NATIVE
void func_8009C1CC(PlayerState *player, f32 position[3]) {
    func_800EE7F8(position, player->unkE4 + 9);
}
#else
void func_8009C1CC(u8 *arg0, BtIntPtr arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)(arg0 + 0xE4) + 0x24);
}
#endif
/* extern */

#ifdef BT_NATIVE
void func_8009C1F8(PlayerState *player, f32 source[3]) {
    func_800EE7F8(player->unkE4 + 9, source);
}
#else
void func_8009C1F8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
}
#endif

#ifdef BT_NATIVE
void func_8009C21C(PlayerState *player) {
    func_800EE7F8(player->unkE4 + 6, player->unkE4 + 3);
    func_800EE7F8(player->unkE4 + 3, player->unkE4);
}
#else
s32 func_8009C21C(u8 *arg0) {
    s32 func_800EE7F8();
    s32 temp;

    temp = *(s32 *)(arg0 + 0xE4);
    func_800EE7F8(temp + 0x18, temp + 0xC, temp);
    temp = *(s32 *)(arg0 + 0xE4);
    return func_800EE7F8(temp + 0xC, temp, temp);
}
#endif
/* extern */

#ifdef BT_NATIVE
void func_8009C25C(PlayerState *player) {
    func_800EF04C(player->unkE4, player->unkE4 + 9);
    func_800EFD24(player->unkE4 + 9);
}
#else
void func_8009C25C(void *arg0) {
    void func_800EF04C(f32 *arg0, f32 *arg1);
    void func_800EFD24(f32 vec[3]);
    BtIntPtr temp_a0;

    temp_a0 = (((Obj1E75920_arg0 *)arg0)->unkE4);
    func_800EF04C(temp_a0, temp_a0 + 0x24);
    func_800EFD24((((Obj1E75920_arg0 *)arg0)->unkE4) + 0x24);
}
#endif
