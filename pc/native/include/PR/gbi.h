#ifndef BT_NATIVE_PR_GBI_H
#define BT_NATIVE_PR_GBI_H
#ifndef BT_NATIVE
#error "The host graphics ABI adapter is only for native builds"
#endif
#include <stdint.h>
/* SDK long/bitfield overlays are not the serialized packet layout on LP64. */
#define Gfx BtSdkGfx
#define Mtx BtSdkMtx
#define Mtx_t BtSdkMtx_t
#include "../../../../lib/ultralib/include/PR/gbi.h"
#undef Mtx_t
#undef Mtx
#undef Gfx

typedef int32_t Mtx_t[4][4];
typedef union {Mtx_t m;int64_t force_structure_alignment;} Mtx;
typedef union {Gwords words;int64_t force_structure_alignment;} Gfx;
_Static_assert(sizeof(Gfx)==8,"N64 display-list packet stride");
_Static_assert(sizeof(Mtx)==64,"N64 fixed matrix packet stride");
_Static_assert(sizeof(Vtx)==16 && sizeof(Vp)==16 && sizeof(LookAt)==32,"N64 vertex/viewport/light packet strides");

#include "native_graphics_memory.h"
#undef gSPMatrix
#define gSPMatrix(pkt,m,p) gDma2p((pkt),G_MTX,BT_GFX_ADDRESS(m),sizeof(Mtx),(p)^G_MTX_PUSH,0)
#undef gSPDisplayList
#define gSPDisplayList(pkt,dl) gDma1p((pkt),G_DL,BT_GFX_ADDRESS(dl),0,G_DL_PUSH)
#undef gSPBranchList
#define gSPBranchList(pkt,dl) gDma1p((pkt),G_DL,BT_GFX_ADDRESS(dl),0,G_DL_NOPUSH)
#undef gSPVertex
#define gSPVertex(pkt,v,n,v0) do { \
    Gfx *_g=(Gfx *)(pkt); \
    _g->words.w0=_SHIFTL(G_VTX,24,8)|_SHIFTL((n),12,8)|_SHIFTL((v0)+(n),1,7); \
    _g->words.w1=BT_GFX_ADDRESS(v); \
} while(0)
#undef gSPViewport
#define gSPViewport(pkt,v) gDma2p((pkt),G_MOVEMEM,BT_GFX_ADDRESS(v),sizeof(Vp),G_MV_VIEWPORT,0)
#undef gSPSegment
#define gSPSegment(pkt,segment,base) gMoveWd((pkt),G_MW_SEGMENT,(segment)*4,BT_GFX_ADDRESS(base))
#undef gSPLight
#define gSPLight(pkt,l,n) gDma2p((pkt),G_MOVEMEM,BT_GFX_ADDRESS(l),sizeof(Light),G_MV_LIGHT,(n)*24+24)
#undef gSPLookAtX
#define gSPLookAtX(pkt,l) gDma2p((pkt),G_MOVEMEM,BT_GFX_ADDRESS(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATX)
#undef gSPLookAtY
#define gSPLookAtY(pkt,l) gDma2p((pkt),G_MOVEMEM,BT_GFX_ADDRESS(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATY)
#undef gSetImage
#define gSetImage(pkt,cmd,fmt,siz,width,i) do { \
    Gfx *_g=(Gfx *)(pkt); \
    _g->words.w0=_SHIFTL(cmd,24,8)|_SHIFTL(fmt,21,3)|_SHIFTL(siz,19,2)|_SHIFTL((width)-1,0,12); \
    _g->words.w1=BT_GFX_ADDRESS(i); \
} while(0)
#endif
