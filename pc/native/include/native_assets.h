#ifndef BT_NATIVE_ASSETS_H
#define BT_NATIVE_ASSETS_H
#include "types.h"

/* One extracted assets.bin archive; opening initializes the game's reference cache. */
int native_assets_open(const char *path);
void native_assets_close(void);
void native_assets_shutdown(void);
s32 native_asset_count(void);
u32 native_asset_flags(s32 id);
s32 native_asset_packed_size(s32 id);
s32 native_asset_rom_offset(s32 id);
s32 native_asset_cached_size(s32 id);
int native_asset_can_pin(s32 id);
typedef struct { s16 step, count; u32 rate_bits; } NativeModelAnimationChannel;
_Static_assert(sizeof(NativeModelAnimationChannel) == 8, "model animation channel layout");
/* -1 invalid model bounds, 0 no animation, 1 seven native channels written. */
int native_asset_model_animation(s32 id, const void *model, NativeModelAnimationChannel output[7]);
void *native_asset_load(s32 id, s32 *size);
s32 native_asset_read_into(s32 id, void *destination, s32 capacity);

void func_800D5440(void *);
int func_800D54F0(void *);
void func_800D55A0(void);
void func_800D55DC(void);
void func_800D5688(void);
s32 func_800D56C4(void *);
void *func_800D5804(void *, s32);
void func_800D58AC(void);
void func_800D58CC(void);
s32 func_800D58FC(s32);
s32 func_800D593C(void);
s32 func_800D5944(void);
s32 func_800D5950(s32);
s32 func_800D59C0(s32);
s32 func_800D5A04(s32);
s32 func_800D5A6C(s32);
s32 func_800D5AB4(s32);
void func_800D5B24(void);
void *func_800D5B34(s32);
void func_800D5D70(void);
s32 func_800D5DB8(s32);
void func_800D5E28(void **);
void func_800D5E54(void *);
void func_800D5E74(void);
int func_800D5E94(void *);
s32 func_800D5EB4(s32, u8 *, s32);
void func_800D5FDC(s32);
void *func_800D5FE8(s32);
#endif
