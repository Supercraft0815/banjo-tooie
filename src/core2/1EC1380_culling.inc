#ifdef BT_NATIVE
#include "native_reflection.h"
#include "gfx.h"
u32 D_8012D5E0;
Gfx D_80123418[2]={{{0xD9FFFFFF,0x400}},{{0xDF000000,0}}};
Gfx D_80123428[2]={{{0xD9FFFFFF,0x200}},{{0xDF000000,0}}};
#else
extern Gfx D_80123418[],D_80123428[];
#endif
void func_800E7FF8(Gfx** gfx, u32 geometry_mode) {
    D_8012D5E0 = geometry_mode;
    gSPSetGeometryMode((*gfx)++, geometry_mode);
    gSPSegment((*gfx)++, RSP_SEGMENT_FACE_CULLING, osVirtualToPhysical(geometry_mode == G_CULL_BACK ? D_80123418 : D_80123428));
}

void func_800E8078(Gfx** gfx) {
    gSPDisplayList((*gfx)++, RSP_SEGMENT_FACE_CULLING << 24);
}
