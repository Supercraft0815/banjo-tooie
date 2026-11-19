#include "su/baddiedialog_descriptor.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define JOLLY_MESSAGE_HALF(value, index) ((s16)((u32)(value) >> ((1 - (index)) * 16)))
#else
#define JOLLY_MESSAGE_HALF(value, index) (((s16 *)&(value))[index])
#endif
