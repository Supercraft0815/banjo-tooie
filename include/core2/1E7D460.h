#ifndef __CORE2_1E7D460_H__
#define __CORE2_1E7D460_H__

#include <ultra64.h>

#include "overlays/ba/playerstate.h"

typedef struct {
    u8 bytes[0x3C];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    u32 legacy_camera; void *camera;
#else
    u32 camera;
#endif
} FirstPersonCameraState;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
_Static_assert(offsetof(FirstPersonCameraState, camera) == 0x40, "native camera pointer follows legacy slot");
_Static_assert(sizeof(FirstPersonCameraState) == 0x48, "native camera state includes full pointer");
#else
typedef char FirstPersonCameraStateAbi[(sizeof(FirstPersonCameraState) == 0x40) ? 1 : -1];
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define FIRSTPERSON_CAMERA_HANDLE(arg0) (((FirstPersonCameraState *)*(void **)((u8 *)(arg0) + 0x38))->camera)
#define FIRSTPERSON_CAMERA_HANDLE_U8(arg0) FIRSTPERSON_CAMERA_HANDLE(arg0)
#define FIRSTPERSON_CAMERA_RESULT(arg0) ((BtIntPtr)((FirstPersonCameraState *)*(void **)((u8 *)(arg0) + 56))->camera)
#else
#define FIRSTPERSON_CAMERA_HANDLE(arg0) (*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)(arg0))->unk38_voidp)) + (0x3C)))
#define FIRSTPERSON_CAMERA_HANDLE_U8(arg0) (*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)(arg0))->unk38)) + (0x3C)))
#define FIRSTPERSON_CAMERA_HANDLE_U8(arg0) (*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)(arg0))->unk38)) + (0x3C)))
#define FIRSTPERSON_CAMERA_RESULT(arg0) (*(s32 *)((u8 *)*(void **)((u8 *)(arg0) + 56) + 60))
#endif


f32 *func_800A4C48(PlayerState *);
PlayerState *func_800A4CA8(PlayerState *);
void func_800A4DA4(PlayerState *, s32);
void func_800A4DFC(PlayerState *, s32);
void func_800A4E30(PlayerState *);

#endif // __CORE2_1E7D460_H__
