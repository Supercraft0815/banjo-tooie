#ifndef __CORE2_1EAF950_H__
#define __CORE2_1EAF950_H__

#include <common.h>
typedef struct ImageStruct {
	u8 pad[0x8];
	s16 unk8;
	s16 unkA;
} ImageStruct;
ImageStruct *func_800D674C(s32 a0);
void *func_800D7520(s32);
#ifdef BT_NATIVE
s32 func_800D6060(s32);
void func_800D61B4(u8 *);
s32 func_800D6254(s32);
void func_800D62E4(s32);
s32 func_800D6378(u8 *);
s32 func_800D6408(void *);
s32 func_800D6550(void *);
void func_800D66AC(void);
void *func_800D6B0C(s32);
s32 func_800D6C34(s32);
void func_800D6C64(void);
s32 func_800D6CEC(s32);
void func_800D6D68(void);
void func_800D6E54(s32);
uintptr_t func_800D7050(s32, s32);
void func_800D70D0(s32);
s32 func_800D70F8(s32, s32);
u32 func_800D7138(s32);
uintptr_t func_800D7184(s32, s32);
void func_800D71F4(s32);
s32 func_800D721C(s32, s32);
void *func_800D725C(s32);
s32 func_800D731C(s32);
s32 func_800D738C(s32);
s32 func_800D73AC(s32);
s32 func_800D73CC(s32);
#endif

#endif
