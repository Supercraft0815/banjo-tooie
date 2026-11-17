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

int rdp_gpu(void);  // BT_RENDERER=gpu: OpenGL render targets (rdp_gl.h) instead of the software raster

#define RDP_MAX_SCALE 4
#define RDP_MAX_SX 5  // horizontal factor in widescreen mode: round(RDP_MAX_SCALE * 4 / 3)
int rdp_scale(void);  // BT_SCALE=1 (default) to 4, vertical factor
void rdp_request_scale(int scale);  // any thread; takes effect at the next buffer swap
// widescreen: the game renders anamorphic 16:9, so the columns get a 4/3 larger factor
void rdp_register_framebuffer(u32 address, int width, int widescreen);
void rdp_begin(void);
void rdp_end(void);  // resolve color and depth before the DP completion event
// After the SP event: 1 when event (DP) is raised later, once the task's GPU output is in RDRAM.
int rdp_done_later(u32 event);
// copy XRGB8888; returns the vertical scale (0 if absent) and the horizontal one in *sx
int rdp_frame(u32 address, int width, int height, u32 *pixels, int *sx);
// Main thread, before the game starts: an SDL_Window with its GL context current, or NULL for
// headless rendering. Load GL and create shared render/completion contexts on this thread.
void rdp_gpu_share(void *window);
// The texture (rows top first) holding the picture rdp_frame would copy, or with index 0..2 the one
// rdp_interp_frame would; 0 when there is none (software renderer, no window).
unsigned rdp_frame_texture(u32 address, int width, int height, int index, int *sx, int *sy);
// Frame interpolation (presentation only): after rdp_begin, the in-between images this task may
// make; one more pass of the same display list per image between rdp_interp_begin (0: the task
// drew no VI image) and rdp_interp_end. rdp_interp_frame is
// rdp_frame for in-between image `index` of the picture last drawn into `address`.
void rdp_interp_arm(int images);
int rdp_interp_begin(void);
void rdp_interp_end(int index);
int rdp_interp_frame(u32 address, int width, int height, int index, u32 *pixels, int *sx);
// They run on a worker: the task posts them after rdp_end (a snapshot of game memory, 0 when the
// task drew no VI image); the worker takes the job (rdp_interp_next, which makes rdp_mem read the
// snapshot), runs the passes and calls rdp_interp_done. rdp_interp_wait blocks until it is idle.
int rdp_interp_post(int images);  // 1: posted (GPU: the task runs the passes itself, see rdp_gpu)
int rdp_interp_next(void);
void rdp_interp_done(void);
void rdp_interp_wait(void);
const u8 *rdp_mem(u32 addr, u32 n);  // game memory as the RSP/RDP read it (the snapshot on the worker)

#endif
