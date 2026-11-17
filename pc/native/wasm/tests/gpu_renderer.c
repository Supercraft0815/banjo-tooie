// Exercise guest CPU/GPU handoffs at native resolution with the existing RDP fixture. FB and FB2
// are VI framebuffers (the GPU renderer draws only those); ZB and RTT stay with the software path.
#define main fixture_main
#include "renderer.c"
#undef main

static void snapshot(void) { assert(fwrite(bt_mem+FB, 1, 4*4096, stdout) == 4*4096); }

int main(void) {
    bt_inst.w2c_memory.size = 0x80010000ull;
    bt_mem = mmap(NULL, bt_inst.w2c_memory.size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    assert(bt_mem != MAP_FAILED);
    rdp_register_framebuffer(FB, W, 0);
    rdp_register_framebuffer(FB2, W, 0);
    rdp_begin(); scene(); rdp_end(); snapshot();
    // CPU color writes survive another task, and borrowed depth keeps RGBA alpha bits.
    wr16(bt_mem+FB, 0x003F);
    rdp_begin(); target(ZB); fill(0xF80107C1,0,0,W,H); target(FB); rdp_end();
    assert(rd16(bt_mem+FB) == 0x003F);
    assert(rd16(bt_mem+ZB) == 0xF801 && rd16(bt_mem+ZB+2) == 0x07C1);
    snapshot();
    // Render-to-texture must resolve within a task, before the DP event.
    rdp_begin(); target(FB); fill(0xFFFFFFFF,0,0,2,2);
    rdp_command(0xFD100000 | (W-1), FB);
    assert(rd16(bt_mem+FB) == 0xFFFF);
    rdp_command(0xF5100000 | ((W*2/8)<<9),0);
    rdp_command(0xF4000000,4<<12|4);
    rdp_command(0xF2000000,4<<12|4);
    rdp_command(0xEF200000,0);
    rdp_texrect(0xE4000000|36<<12|36,32<<12|32,0,4096u<<16|1024,0);
    rdp_end();
    assert(rd16(bt_mem+FB+(8*W+8)*2)==0xFFFF);
    snapshot();
    // CPU copies of image/depth data are imported on the next task.
    memcpy(bt_mem+FB2,bt_mem+FB,W*H*2);
    rdp_begin(); target(FB2); fill(0x003F003F,0,0,1,1); target(FB); rdp_end();
    assert(rd16(bt_mem+FB2)==0x003F && rd16(bt_mem+FB2+(8*W+8)*2)==0xFFFF);
    snapshot();
    // Intro puzzle mask: clipped, untextured two-cycle black triangles.
    rdp_begin(); target(FB); fill(0xFFFFffff,0,0,W,H);
    rdp_command(0xEF982C00,0x0C192048);
    memcpy(R.rgb,(u8[2][4]){{6,3,5,3},{0,7,4,7}},sizeof R.rgb);
    memcpy(R.alpha,(u8[2][4]){{7,7,7,4},{0,7,5,7}},sizeof R.alpha);
    rdp_command(0xFB000000,0xFFFFFFFF);
    RdpVtx a={.x=-18,.y=-22,.w=1,.c={0,0,0,255}},b=a,c=a;
    b.x=-18;b.y=10;c.x=14;c.y=10;
    rdp_triangle(&a,&b,&c,RDP_SHADE);
    rdp_end();
    assert(rd16(bt_mem+FB+(5*W)*2)==0x0001);
    if (gpu_enabled()) assert(gpu.t[0].color && gpu.t[1].color);
    return 0;
}
