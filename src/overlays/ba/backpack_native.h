#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_vertex_cache.h"
#include "native_vector_table.h"
#else
BT_NATIVE_ONLY(u8 *func_800DBFF8(void);)
BT_NATIVE_ONLY(s16 func_80100D24(s32, s32, s32, s32, s32, s32);)
BT_NATIVE_ONLY(s32 func_80100A74(s16, s32);)
BT_NATIVE_ONLY(s32 func_80100AC4(s16);)
BT_NATIVE_ONLY(void func_80100E18(s16);)
#endif
