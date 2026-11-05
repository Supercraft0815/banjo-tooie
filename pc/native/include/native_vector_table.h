#ifndef BT_NATIVE_VECTOR_TABLE_H
#define BT_NATIVE_VECTOR_TABLE_H
#include "types.h"
typedef struct {u32 header;f32 vectors[23][3];} NativeVectorTable;
void func_800DBEB0(void *);
void func_800DBEFC(void *,s32,f32 *);
void func_800DBF38(void *,s32,s32 *);
void func_800DBF74(void *,s32,s32,f32 *);
void func_800DBFD8(void *);
void *func_800DBFF8(void);
void func_800DC028(void *,s32,f32 *);
void *func_800DC060(void *);
#endif
