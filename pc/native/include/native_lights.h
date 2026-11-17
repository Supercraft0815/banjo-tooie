#ifndef BT_NATIVE_LIGHTS_H
#define BT_NATIVE_LIGHTS_H
#include "common.h"
#include "vector.h"
#include "native_gsfile.h"
typedef struct {
    s16 position[3], range[2];
    u8 color[3], padding[3];
    f32 inverse_range;
    u8 permanent, mask, dirty, enabled, disabled, moved, tail[2];
} NativeLight;
_Static_assert(sizeof(NativeLight)==28,"light scalar layout");
typedef struct {
    Vector *entries;
    s32 ambient[3], primary_color[3], secondary_color[3];
    f32 secondary_direction[3];
} NativeLighting;
extern NativeLighting native_lighting;
typedef u32 (*NativeLightPredicate)(NativeLight *,s32);
s32 func_800C84B0(s32);
u32 func_800C8560(NativeLight *,s32);
u32 func_800C8588(NativeLight *,s32);
u32 func_800C8594(NativeLight *,s32);
s32 func_800C85A0(NativeLightPredicate,s32);
s32 func_800C8678(s32,NativeLightPredicate,s32);
s32 func_800C8760(s32,s32);
s32 func_800C878C(s32,s32,s32);
void func_800C87B8(s32 *);
void func_800C87DC(s32 *);
void func_800C8800(BtIntPtr,f32 *);
void func_800C883C(s32,void *);
void func_800C8898(s32,f32 *);
void func_800C8900(s32,s32 *);
void func_800C8960(s32 *,f32 *);
u8 func_800C89A8(s32);
u8 func_800C89D8(s32);
void func_800C8A08(void);
s32 func_800C8A98(void);
void func_800C8B84(volatile s32);
s32 func_800C8BF4(void);
s32 func_800C8C18(void);
void func_800C8C90(s32 *);
void func_800C8CB8(s32,f32 *);
void func_800C8D4C(s32,f32 *);
void func_800C8E54(s32,f32,f32);
void func_800C8E84(s32,u32 *);
void func_800C8F08(s32 *,f32 *);
void func_800C8F64(s32,s32);
void func_800C8FB0(s32,u32,u32,u32);
void func_800C8FE0(s32,s32);
u8 func_800C9044(s32);
void func_800C9074(void);
void func_800C90AC(void);
void func_800C90D0(void);
void func_800C90F4(void *);
NativeLighting *func_800C911C(void);
s32 func_800C9128(f32 *);
void func_80800000_gclightsDll(NativeLighting *);
void gclightsDll_entrypoint_0(NativeLighting *);
void gclightsDll_entrypoint_1(NativeLighting *);
void gclightsDll_entrypoint_2(NativeLighting *,GsFile *);
s32 gclightsDll_entrypoint_3(NativeLighting *,f32 *);
s32 gclightsDll_entrypoint_4(void);
void gclightsDll_entrypoint_5(s32 *);
#endif
