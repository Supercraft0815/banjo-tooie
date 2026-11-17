#include "common.h"

/* extern */

typedef struct { u8 pad0[0x78]; u8 unk78; } Objzone_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void subaddiezone_entrypoint_0(u8 *arg0) {
    struct Flags { u8 pad[0x70]; unsigned int : 13; unsigned int disabled : 1; unsigned int : 18; };
    u8 _glzone_entrypoint_5(s32, u8 *, u8, u8 *);
    s32 func_800BEC28(s32);
    if (((struct Flags *)arg0)->disabled) return;
    (((Objzone_arg0 *)arg0)->unk78) = _glzone_entrypoint_5(func_800BEC28(0), arg0 + 4, (((Objzone_arg0 *)arg0)->unk78), arg0);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(u8) subaddiezone_entrypoint_1(void *arg0) {
    u8 _glzone_entrypoint_4(u8 *arg0, s32 arg1);
    void *func_800BEC1C(void);
    BT_NATIVE_ONLY(return) _glzone_entrypoint_4(func_800BEC1C(), (((Objzone_arg0 *)arg0)->unk78));
}
