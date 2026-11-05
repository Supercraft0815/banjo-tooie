#ifndef BT_NATIVE_PR_OS_CONVERT_H
#define BT_NATIVE_PR_OS_CONVERT_H
#ifndef BT_NATIVE
#error "The host address adapter is only for native builds"
#endif
#include "../../../../lib/ultralib/include/PR/os_convert.h"
#include "native_graphics_memory.h"
#undef OS_K0_TO_PHYSICAL
#undef OS_K1_TO_PHYSICAL
#define OS_K0_TO_PHYSICAL(x) native_graphics_pointer(x)
#define OS_K1_TO_PHYSICAL(x) native_graphics_pointer(x)
#endif
