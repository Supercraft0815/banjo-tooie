#ifndef __CORE2_1ECE0B0_H__
#define __CORE2_1ECE0B0_H__

#include "../../src/overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "transformations.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7AB30.h"

#include "overlays/ba/anim.h"
#include "overlays/ba/key.h"
#include "overlays/ba/drone.h"
#include "ba/hold.h"

#include <ultra64.h>
void func_800F497C(BtIntPtr);
#ifdef BT_NATIVE
void func_800F49D4(BtIntPtr, BaDroneCallback, uintptr_t);
#else
void func_800F49D4(s32 arg0, void* arg1, s32 arg2);
#endif
void func_800F49A8(BtIntPtr, s32);
void func_800F4A00(BtIntPtr, s32);
void func_800F4A2C(BtIntPtr, f32 *);
void func_800F4A58(BtIntPtr, f32 *, f32);
void func_800F4AC0(BtIntPtr, f32 *, f32);
s32 func_800F4B4C(s32);
s32 func_800F4B8C(BtUIntPtr, u32, s32);
s32 func_800F4BB8(BtUIntPtr, u32, s32);
void func_800F4CC0(BtIntPtr);
void func_800F4CEC(BtIntPtr, u32);
s32 func_800F4E5C(s32, BtIntPtr, BtIntPtr, BtIntPtr, BtIntPtr);
s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
PlayerState* func_800F53D0(BtIntPtr arg0);
PlayerState* func_800F53E4(s32 arg0);
//Get the character control index
BtUIntPtr func_800F54E4(void);
s32 func_800F5578(BtIntPtr);
Unk80132ED0* func_800F56D8(BtIntPtr arg0);
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5A00(BtIntPtr, f32[3]);
void func_800F5D44(BtIntPtr, f32*);
f32 func_800F5F24(BtUIntPtr);
s32 func_800F5FE0(BtIntPtr);
void func_800F608C(BtIntPtr, s32);
void func_800F6388(BtIntPtr, s32);
void func_800F63E0(BtIntPtr, u32);
s32 func_800F6438(BtUIntPtr);
int func_800F6774(BtUIntPtr);

#ifdef BT_NATIVE
#define ALLOW_SHIFT(t) (1u << (((t) + 0x1Fu) & 0x1Fu)) // MIPS uses the low five bits of the shift count
#else
#define ALLOW_SHIFT(t) (1 << ((t) + 0x1F))
#endif
typedef enum
{
	ALLOW_TREXLARGE = ALLOW_SHIFT(TRANSFORM_13_TREXLARGE),
	ALLOW_TREXSMALL = ALLOW_SHIFT(TRANSFORM_12_TREXSMALL),
	ALLOW_CLOCKWORK = ALLOW_SHIFT(TRANSFORM_11_CLOCKWORK),
	ALLOW_VAN = ALLOW_SHIFT(TRANSFORM_10_VAN),
	ALLOW_DETONATOR = ALLOW_SHIFT(TRANSFORM_F_DETONATOR),
	ALLOW_GOLDENGOLIATH = ALLOW_SHIFT(TRANSFORM_E_GOLDENGOLIATH),
	ALLOW_MUMBO = ALLOW_SHIFT(TRANSFORM_D_MUMBO),
	ALLOW_SUB = ALLOW_SHIFT(TRANSFORM_C_SUB),
	ALLOW_KAZOOIE = ALLOW_SHIFT(TRANSFORM_B_KAZOOIE),
	ALLOW_BANJO = ALLOW_SHIFT(TRANSFORM_A_BANJO),
	ALLOW_FIRSTPERSON = ALLOW_SHIFT(TRANSFORM_9_FIRSTPERSON),
	ALLOW_STONY = ALLOW_SHIFT(TRANSFORM_8_STONY),
	ALLOW_WASHINGMACHINE = ALLOW_SHIFT(TRANSFORM_7_WASHINGMACHINE),
	ALLOW_BEE = ALLOW_SHIFT(TRANSFORM_6_BEE),
	ALLOW_SNOWBALL = ALLOW_SHIFT(TRANSFORM_2_SNOWBALL),
	ALLOW_BK = ALLOW_SHIFT(TRANSFORM_1_BK)
}AllowedTransformation;

//Does the character match the given transformation type
s32 func_800F64A4(BtIntPtr characterIndex, AllowedTransformation transformationType);
int func_800F7700(BtIntPtr, s32, f32*);
//The moving object is moved towards/away from the target
int func_800F78EC(BtIntPtr moving, f32* target, f32 verticalSpeed, f32 horizontalSpeed);
void func_800F7B9C(BtIntPtr, u32);
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7BC8(BtIntPtr, s32, Unk80132ED0*);
int func_800F8004(BtIntPtr);
void func_800F80E4(BtIntPtr, u32);
void func_800F822C(BtIntPtr, f32, f32);
void func_800F8294(BtIntPtr, f32*);
void func_800F82C0(s32);
void func_800F82D4(BtIntPtr, s32);
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F832C(BtIntPtr, f32*);
s32 func_800F8B64(void);
void func_800F8850();
void func_800F8DD8();
void func_800F8E08();
void func_800F911C(s32);
// Might take in a PlayerState *
void func_800F9BC4(void);


#endif // __CORE2_1ECE0B0_H__
