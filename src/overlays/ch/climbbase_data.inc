/* The four id/scale pairs end at the descriptor for the first climbable object. */
#include "core2/1EDED00.h"

void func_8010A730(s32, s32);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_actor.h"
#else
void *func_80107C2C(s32 *, s32, void *, s32, void *);
#endif

#ifdef BT_NATIVE
typedef Actor *(*ClimbFactory)(s32 *, s32, ActorData *, NativeActorFactory, Prop *);
#else
typedef void (*ClimbFactory)(void *, s32, void *, s32, void *);
#endif

struct ClimbEntry D_808003B0_chclimbbase[4] BT_DATA(4, overlays_ch_climbbase, 0x0) = {
    {1, 1.01f}, {2, 1.02f}, {3, 1.03f}, {4, 0.0f}
};

ActorData D_808003D0_chclimbbase[1] BT_DATA(4, overlays_ch_climbbase, 0x20) = {{
    53, 0x1F9, 0, 1, NULL,
    func_80800200_chclimbbase, func_80105834, func_8010A730,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    func_80800128_chclimbbase, (ClimbFactory)func_80107C2C,
    -32768, 0x2602, 0, 0
}};

ActorData D_80800418_chclimbbase[1] BT_DATA(4, overlays_ch_climbbase, 0x68) = {{
    53, 0x16E, 0, 1, NULL,
    func_80800200_chclimbbase, func_80105834, func_8010A730,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    func_80800128_chclimbbase, (ClimbFactory)func_80107C2C,
    -32768, 0x2602, 0, 0
}};
