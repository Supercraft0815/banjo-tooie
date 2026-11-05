#ifndef __CORE2_ANCTRL_H__
#define __CORE2_ANCTRL_H__

#include <ultra64.h>

#include "overlays/ba/assets.h"
#ifdef BT_NATIVE
#include <stdint.h>
#include <stddef.h>
typedef void (*AnimCallback)(void *bones, uintptr_t context);
#endif

typedef struct anctrl_s {
#ifdef BT_NATIVE
    f32 previous_timer;
    f32 range_start;
    f32 range_end;
    f32 duration;
    f32 transition_duration;
    f32 start;
    s16 index;
    u8 playback_type;
    u8 flags;
    _Alignas(void *) u8 animation[];
#else
    // TODO populate this struct
    u8 unk0;
#endif
} AnimCtrl;

#ifdef BT_NATIVE
_Static_assert(offsetof(AnimCtrl, index) == 0x18, "Animation controller scalar layout");
_Static_assert(offsetof(AnimCtrl, flags) == 0x1B, "Animation controller flag layout");
_Static_assert(offsetof(AnimCtrl, animation) == sizeof(AnimCtrl), "Animation payload alignment");
#define ANCTRL_HEADER_SIZE ((s32)sizeof(AnimCtrl))
#else
#define ANCTRL_HEADER_SIZE 0x1C
#endif

void anctrl_setIndex(AnimCtrl *, AssetId);
void anctrl_reset(AnimCtrl *);
void anctrl_setSmoothTransition(AnimCtrl *, s32);
void anctrl_setDuration(AnimCtrl *, f32);
void anctrl_setSubrange(AnimCtrl *, f32, f32);
void anctrl_setPlaybackType(AnimCtrl *, s32);
void func_8008B10C(AnimCtrl *, f32);
int anctrl_isAt(AnimCtrl *, f32);
void anctrl_setStart(AnimCtrl *, f32);
f32 anctrl_getAnimTimer(AnimCtrl *);
void anctrl_start(AnimCtrl *);
s32 anctrl_isStopped(AnimCtrl *);
int anctrl_getIndex(AnimCtrl *);

AnimCtrl *func_8008AD80(s32);
AnimCtrl *func_8008AEB4(AnimCtrl *);
void func_8008B1C8(AnimCtrl *, f32);
void func_8008B188(AnimCtrl *, s32);
s32 func_8008B28C(AnimCtrl *);
void func_8008B2E8(AnimCtrl *, s32);
#ifdef BT_NATIVE
void *func_8008B4D4(AnimCtrl *);
#else
s32 func_8008B4D4(AnimCtrl *);
#endif

#ifdef BT_NATIVE
f32 func_8008A990(AnimCtrl *);
void func_8008ADE4(AnimCtrl *);
void func_8008ADBC(AnimCtrl *);
void *func_8008AEDC(void *);
void func_8008AEE4(AnimCtrl *, AnimCallback);
void func_8008AF04(AnimCtrl *, uintptr_t);
void func_8008B304(AnimCtrl *);
f32 func_8008B2AC(f32 *);
u32 anctrl_getPlaybackType(u8 *);
u32 func_8008B29C(void *);
void func_8008B4A8(AnimCtrl *, s32);
u32 func_8008B4C4(void *);
s32 func_8008B4F4(void);
void func_8008B518(AnimCtrl *, s32);
void func_8008B5E8(AnimCtrl *);
#endif

#endif
