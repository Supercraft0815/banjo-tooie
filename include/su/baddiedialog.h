#ifndef __SU_BADDIE_DIALOG_H__
#define __SU_BADDIE_DIALOG_H__
#include "common.h"
#include "core1/1E2D890.h"
#include "core2/1EB45C0.h"
#include "core2/1ECE0B0.h"
#include "core2/1EDA900.h"
#include "core2/1EE5DF0.h"
#include "core2/1EB3750.h"
#include "core2/1E99980.h"
#include "core2/1ECB9F0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDB4D0.h"


#include "su/baddiedialog_descriptor.h"

s32 func_80800000_subaddiedialog(f32*, s32, s32);
s32 func_808010C8_subaddiedialog(Actor* a0, s32 arg1, s32 arg2);
s32 func_8080110C_subaddiedialog(f32*, s32, s32);
s32 func_8080118C_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801208_subaddiedialog(f32*, s32, s32, s32);
s32 func_80801394_subaddiedialog(Actor*, s32, s32);
void func_808013E4_subaddiedialog(Actor*, s32, u32);
s32 func_8080141C_subaddiedialog(void);
s32 _subaddiedialog_entrypoint_0(Actor* arg0, s32 arg1, s32 arg2);
s32 subaddiedialog_entrypoint_1(f32* a0, u32 a1, s32 arg2);
#ifdef BT_NATIVE
s32 _subaddiedialog_entrypoint_3(f32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#else
s32 _subaddiedialog_entrypoint_3(f32*, s32, u32, u32, s32);
#endif
s32 _subaddiedialog_entrypoint_4(f32*, s32, s32);
#ifdef BT_NATIVE
s32 _subaddiedialog_entrypoint_5(f32* arg0, s32 arg1, s32 arg2, s32 arg3);
#else
s32 _subaddiedialog_entrypoint_5(f32*, u32, u32, u32);
#endif
#ifdef BT_NATIVE
s32 _subaddiedialog_entrypoint_6(f32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
#else
s32 _subaddiedialog_entrypoint_6(f32*, s32, u32, u32, s32);
#endif
u32 subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, s16);
#ifndef BT_NATIVE
s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
#endif

#endif
