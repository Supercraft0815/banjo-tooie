#ifndef BT_NATIVE_WORLD_PROPS_H
#define BT_NATIVE_WORLD_PROPS_H
#include "native_marker.h"
typedef struct { s16 models[2], dynamic[2]; } NativeWorldCell;
extern u8 *D_80132DB0, *D_80132DB4;
void func_800E96E0(void);
void func_800E9708(void);
void func_800E9728(void);
void func_800E9774(void);
void func_800E97C0(void);
NativeMarkerProp *func_800E9804(NativeWorldCell *);
Prop *func_800E9898(NativeWorldCell *);
NativeMarkerProp *func_800E98C0(NativeWorldCell *);
NativeMarkerProp *func_800E99E0(NativeWorldCell *);
Prop *func_800E9A24(NativeWorldCell *);
u32 func_800E9AC0(NativeWorldCell *,NativeMarkerProp *);
void func_800E9B74(NativeWorldCell *,Prop *);
Prop *func_800E9BF4(NativeWorldCell *,s32);
void func_800E9C44(NativeWorldCell *);
void func_800E9CF4(NativeWorldCell *);
Prop *func_800E9D68(NativeWorldCell *);
Prop *func_800E9D90(NativeWorldCell *);
s32 func_800E9DC4(NativeWorldCell *);
s32 func_800E9DCC(NativeWorldCell *);
u8 func_800E9DD4(NativeWorldCell *);
void func_800E9DF8(void);
void func_800E9E4C(NativeWorldCell *,s32);
NativeMarkerProp *func_800E9E88(NativeWorldCell *);
NativeMarkerProp *func_800E9EB4(NativeWorldCell *);
void func_800E9EE8(s32);
#endif
