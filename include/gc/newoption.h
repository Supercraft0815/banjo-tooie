#ifndef __GC_NEWOPTION_H__
#define __GC_NEWOPTION_H__

#include "common.h"

#include "gc/newoption_state.h"

#ifdef BT_NATIVE
void _gcnewoption_entrypoint_0(void *arg0);
#else
void _gcnewoption_entrypoint_0(OptionState*);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_1(u8 *arg0, BtIntPtr arg1);
#else
void _gcnewoption_entrypoint_1(OptionState*, u32);
#endif

//Get Memory Size of option menu
int gcnewoption_entrypoint_2(void);
int _gcnewoption_entrypoint_2(void);

#ifdef BT_NATIVE
void _gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
#else
void _gcnewoption_entrypoint_4(Actor*, u32, u32*, u32, s32);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_5(void *arg0, BtIntPtr arg1, BtIntPtr arg2, s32 arg3, Unk80132ED0 *arg4);
#else
void _gcnewoption_entrypoint_5(OptionState*, void*, u8, s16, s32);
#endif
#ifdef BT_NATIVE
BT_IDO_ONLY(void) BT_NATIVE_ONLY(void *) _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
#else
void _gcnewoption_entrypoint_6(OptionState*, u32);
#endif
void gcnewoption_entrypoint_7(OptionState* a0);
void _gcnewoption_entrypoint_7(OptionState* a0);
//Setup number of visible options
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_8(s16 *arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_8(OptionState*, u32);
#endif

//Setup number of usable options
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_9(s16 *arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_9(OptionState*, u32);
#endif


#ifdef BT_NATIVE
void _gcnewoption_entrypoint_10(void *arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_10(OptionState*, u8);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_11(s16 *arg0);
#else
void _gcnewoption_entrypoint_11(OptionState*);
#endif


//Setup Option Text
void gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);
void _gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_13(BtIntPtr arg0, s32 arg1, void *arg2);
#else
void _gcnewoption_entrypoint_13(OptionState*, u32, u32*);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
#else
void _gcnewoption_entrypoint_14(OptionState*, u32, u32, u32, f32);
#endif
#ifdef BT_NATIVE
s32 _gcnewoption_entrypoint_19(BtIntPtr arg0, s32 arg1);
#else
s32 _gcnewoption_entrypoint_19(OptionState*, s32);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_23(BtIntPtr arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_23(OptionState*, u32);
#endif

#ifdef BT_NATIVE
void _gcnewoption_entrypoint_31(BtIntPtr arg0, s32 arg1, s16 arg2);
#else
void _gcnewoption_entrypoint_31(OptionState*, s32, s16);
#endif
#ifdef BT_NATIVE
BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) _gcnewoption_entrypoint_32(void *arg0, s16 arg1);
#else
void _gcnewoption_entrypoint_32(OptionState*, u32);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_34(void *arg0, s16 arg1);
#else
void _gcnewoption_entrypoint_34(OptionState*, u32);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_36(void *arg0);
#else
void _gcnewoption_entrypoint_36(OptionState*);
#endif

//Hide Options
u32 gcnewoption_entrypoint_37(OptionState* a0, u32 a1);
u32 _gcnewoption_entrypoint_37(OptionState* a0, u32 a1);

#ifdef BT_NATIVE
s32 _gcnewoption_entrypoint_38(u8 *arg0, s32 arg1);
#else
s32 _gcnewoption_entrypoint_38(OptionState*, u32);
#endif
#ifdef BT_NATIVE
s32 _gcnewoption_entrypoint_39(u8 *arg0);
#else
s32 _gcnewoption_entrypoint_39(OptionState*);
#endif

#ifdef BT_NATIVE
void _gcnewoption_entrypoint_40(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);
#else
void _gcnewoption_entrypoint_40(OptionState*, s32, s32, u8, f32, f32);
#endif

void gcnewoption_entrypoint_41(OptionState*, s32);
void _gcnewoption_entrypoint_41(OptionState*, s32);

#ifdef BT_NATIVE
void _gcnewoption_entrypoint_42(void *arg0, f32 arg1);
#else
void _gcnewoption_entrypoint_42(OptionState*, f32);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_46(s8 *arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_46(OptionState*, u8);
#endif
#ifdef BT_NATIVE
void _gcnewoption_entrypoint_49(void *arg0, s32 arg1);
#else
void _gcnewoption_entrypoint_49(OptionState*, u8);
#endif

#endif
