#include "native_render.h"
Gfx *native_model_modes(s16 flags) {
    return flags&2 ? D_80122DF0 : flags&0x80 ? D_80122EB0 : flags&0x100 ? D_80122F70 : NULL;
}

#define BT_MODEL_BANKS_HOST
#include "core2/model_render_banks.inc"
#undef BT_MODEL_BANKS_HOST
Gfx *native_model_render_modes(s32 depth,s32 alpha) {
    if(depth==4)return native_render.custom_modes[alpha!=255];
    if (depth < 0 || depth >= 4) return NULL;
    return alpha == 255 ? model_material_modes[depth].opaque : model_material_modes[depth].translucent;
}
