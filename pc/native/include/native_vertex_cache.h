#ifndef BT_NATIVE_VERTEX_CACHE_H
#define BT_NATIVE_VERTEX_CACHE_H
#include "native_model.h"
#include "freelist.h"
typedef struct { NativeVertexList *vertices[2]; s32 packed; u8 active,age; } NativeVertexCacheEntry;
typedef struct { void *data; s32 asset,palette,refs; u8 color[3]; } NativePackedVertexEntry;
void *glpackvtx_entrypoint_0(void *,const void *,s32 *);
void glpackvtx_entrypoint_1(void *);
void *func_80100480(s32,s32);
void func_8010052C(void),func_80100534(void),func_801005B8(void),func_80100610(void),func_80100670(void);
NativeVertexCacheEntry *func_80100690(s32 *);
NativePackedVertexEntry *func_801006E0(s32 *);
int func_8010072C(s32 *,u8 *);
s32 func_801007B8(void *,s32,s32,s32 *);
void func_80100938(s32),func_801009C4(NativeVertexCacheEntry *,s32);
void *func_80100A74(s16,s32),*func_80100AC4(s16);
void func_80100B3C(void),func_80100B4C(void),func_80100C74(void);
s16 func_80100D24(void *,s32,s32,s32,s32,s32 *);
void func_80100E18(s16),func_80100E54(void),func_80100F0C(s16,void *);
#endif
