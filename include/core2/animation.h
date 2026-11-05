#ifndef __CORE2_ANIMATION_H__
#define __CORE2_ANIMATION_H__

#include "core2/anctrl.h"
#include "core2/1EB93C0.h"

#ifdef BT_NATIVE
/* Host pointers enlarge the prefix; scalar fields follow their native offsets. */
typedef struct {
    AnimCallback callback;
    uintptr_t context;
    u8 current_pose;
    u8 padding;
    s16 poses[3];
    f32 timer;
    f32 blend;
    s16 index;
    u8 blend_complete;
    u8 pending;
    u8 mode;
    u8 fresh;
    u8 loop;
    u8 padding_end;
} Animation;

void func_8008B610(void);
void func_8008B64C(void);
void func_8008B6E0(void);
void func_8008B768(void);
void func_8008B850(void);
s16 func_8008B8E0(void);
s32 func_8008B90C(s16);
void func_8008B954(s16);
s32 func_8008B9C4(s16, BoneTransformList **);
void func_8008BA5C(void);
s16 *func_8008BAC0(s32 *);
void func_8008BBC0(void *, void *);
void func_8008BBF0(void *, s32);
void func_8008BC2C(u8 *);
void func_8008BC4C(void *);
s32 func_8008BC6C(u8 *, s32);
s32 func_8008BC94(u8 *);
s32 func_8008BCB4(u8 *);
BoneTransformList *func_8008BCEC(void *, s32);
BoneTransformList *func_8008BD1C(void *);
BoneTransformList *func_8008BD3C(void *);
BoneTransformList *func_8008BD74(void *);
void func_8008BD94(void *);
void func_8008BEB4(u8 *);
void func_8008C038(void *);
void func_8008C0AC(s8 *);
s32 func_8008C0B8(void);
s32 func_8008C0C0(s16 *);
f32 func_8008C0C8(f32 *);
f32 func_8008C0D0(f32 *);
void func_8008C0D8(void *);
void func_8008C124(s16 *, s32);
void func_8008C1B8(s16 *, s32);
void func_8008C1C0(f32 *, f32);
void func_8008C1CC(s8 *, s32);
void func_8008C1D4(void *, AnimCallback);
void func_8008C1DC(void *, uintptr_t);
void func_8008C1E4(f32 *, f32);
void func_8008C1F0(void *, s32);
void func_8008C200(s16, void *, void *);
void func_8008C238(s16, void *, void *);
void func_8008C270(s8 *);
void *func_8008C27C(void *);
#endif
#endif
