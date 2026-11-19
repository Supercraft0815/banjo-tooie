#include "core2/1E76360.h"
#include "player_state_dispatch.inc"
s32 func_8009CA70(PlayerState *arg0, s32 arg1, s32 arg2) {
    typedef struct { s32 flags; s32 pad[2]; } Entry;
    extern Entry D_80117F34[];
    s32 result = 0;
    return (BT_DATA_FIELD(playerStates[arg1].flags, D_80117F34[arg1].flags) & arg2) ? 1 : result;
}

void (*func_8009CAAC(PlayerState *arg0, s32 arg1))(PlayerState *) {
    extern void (*(*D_80117F38[][3])(s32))(PlayerState *);
    BT_NATIVE_ONLY(BsScript (*temp_v0)(BsScriptType);) BT_IDO_ONLY(void (*(*temp_v0)(s32))(PlayerState *);)

    temp_v0 = BT_DATA_FIELD(playerStates[arg1].provider, D_80117F38[arg1][0]);
    if (temp_v0 != NULL) {
        return temp_v0(0);
    }
    return 0;
}

void (*func_8009CAF8(PlayerState *arg0, s32 arg1))(PlayerState *) {
    extern void (*(*D_80117F38[][3])(s32))(PlayerState *);
    BT_NATIVE_ONLY(BsScript (*temp_v0)(BsScriptType);) BT_IDO_ONLY(void (*(*temp_v0)(s32))(PlayerState *);)

    temp_v0 = BT_DATA_FIELD(playerStates[arg1].provider, D_80117F38[arg1][0]);
    if (temp_v0 != NULL) {
        return temp_v0(1);
    }
    return 0;
}

void (*func_8009CB44(PlayerState *arg0, s32 arg1))(PlayerState *) {
    extern void (*(*D_80117F38[][3])(s32))(PlayerState *);
    BT_NATIVE_ONLY(BsScript (*temp_v0)(BsScriptType);) BT_IDO_ONLY(void (*(*temp_v0)(s32))(PlayerState *);)

    temp_v0 = BT_DATA_FIELD(playerStates[arg1].provider, D_80117F38[arg1][0]);
    if (temp_v0 != NULL) {
        return temp_v0(3);
    }
    return 0;
}

void (*func_8009CB90(PlayerState *arg0, s32 arg1))(PlayerState *) {
    extern void (*(*D_80117F38[][3])(s32))(PlayerState *);
    BT_NATIVE_ONLY(BsScript (*temp_v0)(BsScriptType);) BT_IDO_ONLY(void (*(*temp_v0)(s32))(PlayerState *);)

    temp_v0 = BT_DATA_FIELD(playerStates[arg1].provider, D_80117F38[arg1][0]);
    if (temp_v0 != NULL) {
        return temp_v0(2);
    }
    return 0;
}

s16 func_8009CBDC(PlayerState *arg0, s32 arg1) {
    extern s16 D_80117F32[];
    return BT_DATA_FIELD(playerStates[arg1].category, *(s16 *)((u8 *)D_80117F32 + arg1 * 12));
}

void func_8009CBFC(void *arg0)
{
}
