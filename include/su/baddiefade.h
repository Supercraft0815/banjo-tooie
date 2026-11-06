#ifndef __SU_BADDIE_FADE_H__
#define __SU_BADDIE_FADE_H__

#include "common.h"

#ifdef BT_NATIVE
u32 _subaddiefade_entrypoint_0(u8 *arg0);
#else
s32 _subaddiefade_entrypoint_0(Actor*);
#endif
#ifdef BT_NATIVE
void _subaddiefade_entrypoint_3(void *arg0);
#else
void _subaddiefade_entrypoint_3(Actor*);
#endif
#ifdef BT_NATIVE
void _subaddiefade_entrypoint_4(void *arg0);
#else
void _subaddiefade_entrypoint_4(Actor*);
#endif
#ifdef BT_NATIVE
void _subaddiefade_entrypoint_8(void *arg0, s32 arg1);
#else
void _subaddiefade_entrypoint_8(Actor*, s32);
#endif
#endif
