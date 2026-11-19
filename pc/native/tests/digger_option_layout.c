#include "gc/newoption_state.h"

typedef struct {
    u8 pad0[0x40];
    s8 unk40;
    u8 pad41;
    s8 unk42;
    u8 pad43;
    u16 unk44;
    u8 pad46[2];
    s8 unk48;
    u8 pad49[0xC3 BT_LP64_ONLY(+4)];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    OptionState options;
#else
    u8 options[0x260];
#endif
} DiggerBossOptionStorage;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
_Static_assert(offsetof(DiggerBossOptionStorage, options) == 0x110,
               "Digger native option state is aligned after O32 header");
_Static_assert(sizeof(DiggerBossOptionStorage) == 0x478,
               "Digger actor allocation includes the native option sidecar");
#else
_Static_assert(offsetof(DiggerBossOptionStorage, options) == 0x10C,
               "Digger option buffer keeps O32 offset 0x10c");
_Static_assert(sizeof(DiggerBossOptionStorage) == 0x36C,
               "Digger guest actor data keeps its O32 extent");
#endif
