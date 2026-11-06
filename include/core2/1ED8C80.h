#ifndef __CORE2_1ED8C80_H__
#define __CORE2_1ED8C80_H__

#include "common.h"
#include "core2/1EDFED0.h"

void func_800FFA88(Unk80132ED0*);
void func_800FFAB0(Actor*);
void func_800FFC14();
u32* func_80100074(Actor*, u32, u32);
void* func_80100094(Actor*, u32);
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
void *func_801000D8(Actor*, s32, s32);
void func_800FF390(void),func_800FF3EC(Actor *),func_800FF44C(void),func_800FF4A4(Actor *);
s32 func_800FF564(void);
void func_800FF62C(void),func_800FFA3C(Actor *),func_800FFB74(void),func_800FFBE4(void);
void func_800FFBEC(void),func_800FFC3C(void),func_800FFC90(void),func_800FFD10(s32);
void func_800FFDBC(void),func_800FFE08(void);
u32 *func_800FFECC(Actor *,s32,s32);
void func_801001D8(void),func_801002C0(void);
s32 func_80100230(Actor *,f32 *),func_8010038C(Actor *,f32 *);
#else
s32 func_801000D8(Actor*, s32, s32);
#endif
void func_80100120(Actor*);

#endif
