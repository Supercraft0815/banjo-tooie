#ifndef BT_NATIVE_MAP_SECTIONS_H
#define BT_NATIVE_MAP_SECTIONS_H
#include "native_map.h"
enum {SEC_VISIBLE=0x80,SEC_COLLIDABLE=0x40,SEC_ACTIVE=0x20,SEC_PINNED=0x10,
      SEC_PRIMARY=8,SEC_PREVIOUS=4,SEC_SECONDARY=1};
enum {S_READY,S_FORCE_PRIMARY,S_PREVIOUS_PRIMARY,S_PRIMARY,S_UNUSED,S_FORCE_SECONDARY,
      S_SECONDARY,S_MODE,S_FRUSTUM,S_INSTANCES,S_PLAYER_TESTED,S_FORCE_ALL};
struct NativeMapSection {
    f32 position[3],minimum[3],maximum[3],center[3],radius,height;
    u8 neighbors[4],hidden[4];
    u16 assets[2];
    void *textures[2];
    u8 flags,pinned[2];
    void *instances[2];
};
typedef struct {f32 position[3],minimum[3],maximum[3];s16 height;u16 assets[2];} NativeMapSectionConfig;
void gcmapsects_entrypoint_0(s16,s16,const f32 *,const f32 *,const f32 *,f32);
void gcmapsects_entrypoint_1(s16,s32);
void gcmapsects_entrypoint_2(s16,s32);
void gcmapsects_entrypoint_3(s16,s16);
s32 gcmapsects_entrypoint_4(f32 *);
u32 gcmapsects_entrypoint_5(s32);
s32 gcmapsects_entrypoint_6(NativeMap *,f32 *,f32 *);
s32 gcmapsects_entrypoint_7(f32 *);
void gcmapsects_entrypoint_8(NativeMap *);
void gcmapsects_entrypoint_9(NativeMap *);
void gcmapsects_entrypoint_10(s32);
void gcmapsects_entrypoint_11(s32,s32);
void gcmapsects_entrypoint_12(void (*)(NativeMap *));
void gcmapsects_entrypoint_13(s32);
void gcmapsects_entrypoint_14(s32);
s32 gcmapsects_entrypoint_15(NativeMap *);
void gcmapsects_entrypoint_16(NativeMap *);
void gcmapsects_entrypoint_17(NativeMap *);
void gcmapsects_entrypoint_18(NativeMap *,s32);
void gcmapsects_entrypoint_19(NativeMap *,s32);
s32 gcmapsects_entrypoint_20(NativeMap *,f32 *,f32 *,s16 (**)[3],s32,f32);
s32 gcmapsects_entrypoint_21(NativeMap *,f32 *,f32 *,f32 *,f32);
void *gcmapsects_entrypoint_22(NativeMap *,f32 *,f32 *,f32 *,s32);
void *gcmapsects_entrypoint_23(NativeMap *,f32 *,f32 *,f32,f32 *,s32,s32);
int gcmapsects_entrypoint_24(NativeMap *);
void *gcmapsects_entrypoint_25(NativeMap *,s32,f32 *,f32 *,f32 *,s32);
void *gcmapsects_entrypoint_26(NativeMap *,f32 *,f32,f32 *,u32);
s32 gcmapsects_entrypoint_27(s32);
void func_80800250_gcmapsects(NativeMap *,s32);
void func_8080035C_gcmapsects(NativeMap *,s32);
void func_808003F4_gcmapsects(NativeMap *,s32);
void func_808005D0_gcmapsects(NativeMap *,s32,void *);
void func_80800A08_gcmapsects(NativeMap *,s32);
void func_80800B58_gcmapsects(NativeMap *);
void func_80800C54_gcmapsects(NativeMap *);
s32 func_80800DC8_gcmapsects(NativeMap *,s32,f32 *);
s32 func_80801174_gcmapsects(NativeMap *,s32);
s32 func_80801320_gcmapsects(NativeMap *,s32,f32 *);
void func_808013C0_gcmapsects(NativeMap *,s32);
void func_80801554_gcmapsects(NativeMap *);
void func_80801640_gcmapsects(NativeMap *);
void func_80801724_gcmapsects(NativeMap *,s32);
void gcmapsects_lagoontop_entrypoint_0(void),gcmapsects_lagoonmid_entrypoint_0(void),gcmapsects_lagoonbot_entrypoint_0(void);
void gcmapsects_lagoontop_entrypoint_1(NativeMap *),gcmapsects_lagoonmid_entrypoint_1(NativeMap *),gcmapsects_lagoonbot_entrypoint_1(NativeMap *);
#endif
