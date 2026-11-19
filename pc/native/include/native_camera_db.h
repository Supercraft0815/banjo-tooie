#ifndef BT_NATIVE_CAMERA_DB_H
#define BT_NATIVE_CAMERA_DB_H
#include "common.h"
#include "native_gsfile.h"
typedef struct { u8 type, index; } NativeCameraEntry;
typedef struct NativeCameraDatabase {
    s32 counts[8];
    s16 handles[8];
    s32 selected;
    u8 *current;
    s32 maximum;
    NativeCameraEntry entries[];
} NativeCameraDatabase;
#include "core2/player_form_data.h"
#define D_80119540 (player_form_data.database)
void func_800A5550(void *, void *);
void func_800A5598(void *, void *);
void func_800A55E0(void);
void func_800A5608(s32);
void func_800A5630(void);
void func_800A5654(void);
void func_800A56A4(void);
u8 *func_800A5790(s32, s32);
s32 func_800A57EC(s32);
u8 *func_800A5800(s32);
s32 func_800A5854(s32);
u8 *func_800A586C(void);
u8 func_800A587C(void);
s32 func_800A5898(void);
void func_800A58A8(s32, s32);
s32 func_800A58F0(void);
s32 func_800A5904(s32);
void cadbmgrDll_entrypoint_0(NativeCameraDatabase **, s32);
void cadbmgrDll_entrypoint_1(NativeCameraDatabase **);
s32 cadbmgrDll_entrypoint_2(NativeCameraDatabase *, s32, s32);
s32 func_808000F4_cadbmgrDll(s32);
s32 func_808003D8_cadbmgrDll(NativeCameraDatabase *, s32, s32);
s32 func_808004C4_cadbmgrDll(NativeCameraDatabase *, s32, s32);
void func_80800528_cadbmgrDll(NativeCameraDatabase *, s32, s32);
void func_808005AC_cadbmgrDll(NativeCameraDatabase *, s32, s32, s32);
void func_80800000_cadbio(GsFile *);
void cadbio_entrypoint_0(GsFile *);
s32 cadbfunc_entrypoint_0(f32 *);
s32 cadbfunc_entrypoint_1(f32 *);
s32 cadbfunc_entrypoint_2(f32 *);
s32 cadbfunc_entrypoint_3(f32 *);
s32 cadbfunc_entrypoint_4(f32 *);
s32 cadbfunc_entrypoint_5(f32 *);
s32 cadbfunc_entrypoint_6(f32 *, f32 *);
s32 cadbfunc_entrypoint_7(f32, f32);
s32 cadbfunc_entrypoint_8(f32 *, f32 *);
s32 cadbfunc_entrypoint_9(f32, f32);
s32 cadbfunc_entrypoint_10(f32 *);
s32 cadbfunc_entrypoint_11(f32);
s32 cadbfunc_entrypoint_12(f32 *);
s32 cadbfunc_entrypoint_13(f32);
s32 cadbfunc_entrypoint_14(f32 *);
s32 cadbfunc_entrypoint_15(f32);
s32 cadbfunc_entrypoint_16(s16 *);
s32 cadbfunc_entrypoint_17(s16);
s32 cadbfunc_entrypoint_18(f32 *);
s32 cadbfunc_entrypoint_19(f32);
s32 cadbfunc_entrypoint_20(f32 *);
s32 cadbfunc_entrypoint_21(f32);
s32 cadbfunc_entrypoint_22(s32 *);
s32 cadbfunc_entrypoint_23(s32);
s32 cadbfunc_entrypoint_24(s32 *);
s32 cadbfunc_entrypoint_25(s32);
s32 cadbfunc_entrypoint_26(s32 *);
s32 cadbfunc_entrypoint_27(s32);
s32 cadbfunc_entrypoint_28(s32, s32);
s32 cadbfunc_entrypoint_29(s32, s32 *);
s32 cadbfunc_entrypoint_30(s32 *);
s32 cadbfunc_entrypoint_31(s32);
s32 cadbfunc_entrypoint_32(f32 *);
s32 cadbfunc_entrypoint_33(f32);
s32 cadbfunc_entrypoint_34(s32 *);
s32 cadbfunc_entrypoint_35(s32);
#endif
