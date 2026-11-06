// Software RDP: rasterizes into the guest's color and depth images like the hardware,
// so CPU code that reads or copies framebuffers sees what it expects. Image and texture
// memory is read and written as big-endian bytes (N64 RDRAM order); assets keep that order.
#ifndef BT_HOST_RDP_H
#define BT_HOST_RDP_H
#include "guest.h"

// A screen-space vertex from the RSP: x, y in pixels, z in 18-bit RDP depth units,
// w the clip-space w (for perspective), c shade RGBA 0..255, s, t in texels * 32.
typedef struct { float x, y, z, w, c[4], s, t; } RdpVtx;

enum { RDP_SHADE = 1, RDP_TEX = 2, RDP_Z = 4 };

void rdp_command(u32 w0, u32 w1);  // raw RDP command; image addresses already resolved
void rdp_triangle(const RdpVtx *a, const RdpVtx *b, const RdpVtx *c, int flags);
void rdp_texrect(u32 w0, u32 w1, u32 st, u32 dsdt, int flip);
void rdp_set_texture(int tile, int levels);  // from G_TEXTURE
void rdp_othermode(int high, u32 mask, u32 value);

#endif
