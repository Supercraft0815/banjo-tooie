#include "common.h"

/* extern */

void subaddiezone_entrypoint_0(u8 *arg0) {
    struct Flags { u8 pad[0x70]; unsigned int : 13; unsigned int disabled : 1; unsigned int : 18; };
    u8 _glzone_entrypoint_5(s32, u8 *, u8, u8 *);
    s32 func_800BEC28(s32);
    if (((struct Flags *)arg0)->disabled) return;
    (*(u8 *)((s8 *)(arg0) + 0x78)) = _glzone_entrypoint_5(func_800BEC28(0), arg0 + 4, (*(u8 *)((s8 *)(arg0) + 0x78)), arg0);
}

/* extern */

void subaddiezone_entrypoint_1(void *arg0) {
    s32 _glzone_entrypoint_4(s32, u8);
    s32 func_800BEC1C();
    _glzone_entrypoint_4(func_800BEC1C(), (*(u8 *)((s8 *)(arg0) + (0x78))));
}
