// Exercise guest CPU/GPU handoffs at native resolution with the existing RDP fixture. FB and FB2
// are VI framebuffers (the GPU renderer draws only those); ZB and RTT stay with the software path.
#ifdef BT_IMAGE_ACCESS_HOST
#include "../host/image_memory.h"
#endif
#define main fixture_main
#include "renderer.c"
#undef main

static void snapshot(void) { assert(fwrite(bt_mem+FB, 1, 4*4096, stdout) == 4*4096); }

static void *draw_first_task(void *unused) {
    (void)unused;
    rdp_begin(); scene(); rdp_end();
    return NULL;
}

// Render a single flat triangle into a shared, fractionally scaled target. Its physical image
// lets the Python check distinguish actual per-sample edge coverage from post-filtering.
static int sample_picture(int level, int wide, int backing_w, int backing_h) {
    test_window_size = 1;
    test_msaa = level;
    gpu_offscreen();
    rdp_window_size(backing_w, backing_h);
    rdp_gpu_share(gpu_window);
    fixture_memory(0x80010000ull);
    rdp_register_framebuffer(FB, W, wide);
    rdp_begin();
    rdp_command(0xED000000, W * 4 << 12 | H * 4);
    target(FB); fill(0x00010001, 0, 0, W, H);
    rdp_command(0xEF000000, 0);
    rdp_command(0xFCFFFFFF, 0xFFFE793C);
    RdpVtx a = {.x=3, .y=2, .w=1, .c={255,255,255,255}}, b=a, c=a;
    b.x=26; b.y=5; c.x=9; c.y=21;
    rdp_triangle(&a,&b,&c,RDP_SHADE);
    rdp_end();
    u32 *pixels = NULL;
    size_t capacity = 0;
    int w=0,h=0,tw=0,th=0, samples=0;
    assert(rdp_picture(FB,W,H,-1,&pixels,&capacity,&w,&h));
    assert(rdp_frame_texture(FB,W,H,-1,&tw,&th) && tw==w && th==h);
    if (gpu.t[0].samples) {
        glBindRenderbuffer(GL_RENDERBUFFER,gpu.t[0].ms_color);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER,GL_RENDERBUFFER_SAMPLES,&samples);
    }
    fprintf(stderr,"target=%dx%d samples=%d max=%d\n",w,h,samples,gpu.max_samples);
    assert(fwrite(pixels,sizeof *pixels,(size_t)w*h,stdout)==(size_t)w*h);
    free(pixels);
    return 0;
}

// CPU and software image writes become depth before a GPU depth test, including
// when the game reuses Z as a color buffer and switches Z addresses in one task.
static void depth_writes(void) {
    rdp_register_framebuffer(FB, W, 0);
    rdp_begin();
    rdp_command(0xED000000, W*4 << 12 | H*4);
    rdp_command(0xFE000000, ZB);
    target(ZB); fill(0xFFFCFFFC, 0, 0, W, H);
    target(FB); fill(0x00010001, 0, 0, W, H);
    RdpVtx a = {.x=1, .y=1, .z=10000, .w=1, .c={255,0,0,255}}, b=a, c=a;
    b.x=28; c.y=22;
    rdp_command(0xEF000000, 0x30);
    rdp_command(0xFCFFFFFF, 0xFFFE793C);
    rdp_triangle(&a,&b,&c,RDP_SHADE|RDP_Z);
    rdp_end();
    const int cell = (5*W+5)*2;
    wr16(bt_mem+ZB+cell, 0);
    rdp_begin();
    a.z=b.z=c.z=5000;
    a.c[0]=b.c[0]=c.c[0]=0; a.c[1]=b.c[1]=c.c[1]=255;
    rdp_triangle(&a,&b,&c,RDP_SHADE|RDP_Z);
    rdp_end();
    assert(rd16(bt_mem+FB+cell)==0xF801 && rd16(bt_mem+FB+cell+2)==0x07C1);
    assert(rd16(bt_mem+ZB+cell)==0);
    rdp_begin();
    target(ZB); fill(0x00000000,5,5,7,6);
    target(FB); rdp_command(0xEF000000, 0x30);
    a.z=b.z=c.z=3000;
    a.c[1]=b.c[1]=c.c[1]=0; a.c[2]=b.c[2]=c.c[2]=255;
    rdp_triangle(&a,&b,&c,RDP_SHADE|RDP_Z);
    rdp_end();
    assert(rd16(bt_mem+FB+cell)==0xF801 && rd16(bt_mem+FB+cell+2)==0x07C1);
    assert(rd16(bt_mem+FB+cell+4)==0x003F);
    for (int i=0;i<W*H;i++) wr16(bt_mem+RTT+2*i,0xFFFC);
    rdp_begin();
    rdp_command(0xFE000000,RTT);
    rdp_triangle(&a,&b,&c,RDP_SHADE|RDP_Z);
    rdp_end();
    assert(rd16(bt_mem+FB+cell)==0x003F && rd16(bt_mem+RTT+cell)!=0xFFFC);
    fwrite(bt_mem+FB,2,W*H,stdout);
}

// Draw the same 8x8 RGBA16 image whole and as two guest strips. At 4x each
// filtered subpixel across the shared edge must match the unsplit image.
static void strip_picture(int split) {
    rdp_register_framebuffer(FB, W, 0);
    rdp_begin();
    rdp_command(0xED000000, W*4 << 12 | H*4);
    target(FB); fill(0x00010001,0,0,W,H);
    for (int y=0;y<8;y++) for (int x=0;x<8;x++)
        wr16(bt_mem+TEX+2*(8*y+x), ((y<4?5:27)<<11)|((3*x)<<6)|((2*y)<<1)|1);
    rdp_command(0xEF001000, 0);
    for (int i=0;i<2;i++) {
        R.rgb[i][0]=R.rgb[i][1]=R.rgb[i][2]=C_ZERO; R.rgb[i][3]=C_T0;
        R.alpha[i][0]=R.alpha[i][1]=R.alpha[i][2]=C_ZERO; R.alpha[i][3]=C_T0_A;
    }
    rdp_command(0xFD100007, TEX);
    int rows=split?4:8;
    for (int y=0;y<8;y+=rows) {
        rdp_command(0xF5100400, (2<<18)|(2<<8));
        rdp_command(0xF4000000 | (y*4), (7*4)<<12 | ((y+rows-1)*4));
        rdp_command(0xF2000000 | (y*4), (7*4)<<12 | ((y+rows-1)*4));
        rdp_texrect(0xE4000000 | (12*4)<<12 | ((y+rows+4)*4),
                   (4*4)<<12 | ((y+4)*4), (u32)y*32, 1024u<<16|1024,0);
    }
    rdp_end();
    u32 *pixels=NULL; size_t cap=0; int w,h;
    assert(rdp_picture(FB,W,H,-1,&pixels,&cap,&w,&h));
    assert(fwrite(pixels,sizeof *pixels,(size_t)w*h,stdout)==(size_t)w*h);
    free(pixels);
}

// Keep one published texture selected while its producer publishes other
// pictures. Its contents must stay intact until the window releases it.
static void *publish_more(void *unused) {
    (void)unused;
    for (int i=0;i<80;i++) {
        rdp_begin(); target(FB); fill(i%2 ? 0x003F003F:0x07C107C1,0,0,W,H); rdp_end();
    }
    return NULL;
}
static int check_shared_frames(void) {
    gpu_offscreen();
    rdp_gpu_share(gpu_window);
    fixture_memory(0x80010000ull);
    rdp_register_framebuffer(FB,W,0);
    rdp_begin();
    rdp_command(0xED000000,W*4<<12|H*4);
    target(FB); fill(0xF801F801,0,0,W,H);
    rdp_end();
    int w=0,h=0;
    GLuint tex=rdp_frame_texture(FB,W,H,-1,&w,&h);
    assert(tex && w==W && h==H);
    pthread_t producer;
    assert(!pthread_create(&producer,NULL,publish_more,NULL));
    for (int i=0;i<32;i++) {
        u8 pixels[W*H*4];
        glBindTexture(GL_TEXTURE_2D,tex); glGetTexImage(GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE,pixels);
        for (int j=0;j<W*H;j++) assert(pixels[j*4]==255 && !pixels[j*4+1] && !pixels[j*4+2]);
        SDL_Delay(1);
    }
    pthread_join(producer,NULL);
    tex=rdp_frame_texture(FB,W,H,-1,&w,&h);
    u8 pixels[W*H*4];
    glBindTexture(GL_TEXTURE_2D,tex); glGetTexImage(GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE,pixels);
    for (int j=0;j<W*H;j++) assert(!pixels[j*4] && !pixels[j*4+1] && pixels[j*4+2]==255);
    return 0;
}

static void check_draw_programs(void) {
    rdp_register_framebuffer(FB,W,0);
    rdp_register_framebuffer(FB2,W,0);
    int wanted = atoi(getenv("BT_GPU_SPECIALIZE"));
    for (int i=0;i<300;i++) {
        rdp_begin(); scene(); rdp_end();
        if (i>=48 && (!wanted || programs.draws)) break;
        SDL_Delay(2);
    }
    if (wanted) assert(programs.draws && atomic_load(&programs.ready));
    else assert(!programs.draws && !atomic_load(&programs.ready));
    snapshot();
}

#ifdef BT_IMAGE_ACCESS_HOST
static void check_image_access(void) {
    rdp_register_framebuffer(FB, W, 0);
    rdp_register_framebuffer(FB2, W, 0);
    rdp_begin();
    rdp_command(0xED000000, W * 4 << 12 | H * 4);
    target(FB); fill(0xF801F801, 0, 0, W, H);
    target(FB2); fill(0x003F003F, 0, 0, W, H);
    rdp_end();
    assert(!rd16(bt_mem + FB) && !rd16(bt_mem + FB2));
    bt_image_scalar(FB - 1, 2);  // a word starts on the preceding, unowned page
    assert(rd16(bt_mem + FB) == 0xF801 && !rd16(bt_mem + FB2));
    bt_image_range(FB2 - 5000, 5002);  // bulk source begins more than a page away
    assert(rd16(bt_mem + FB2) == 0x003F);
    rdp_begin(); target(FB); fill(0x07C107C1, 0, 0, W, H); rdp_end();
    bt_image_scalar(FB + 4, 2);
    wr16(bt_mem + FB + 4, 0xFFFF);
    rdp_begin(); target(FB); fill(0x003F003F, 0, 0, 1, 1); rdp_end();
    bt_image_range(FB, W * H * 2);
    assert(rd16(bt_mem + FB) == 0x003F && rd16(bt_mem + FB + 4) == 0xFFFF);
}
#endif

int main(int argc, char **argv) {
    if (argc==2 && !strcmp(argv[1],"shared")) return check_shared_frames();
    if (argc == 5) return sample_picture(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    rdp_gpu_share(NULL);
    if (getenv("BT_TEST_NO_BARRIER")) gpu_barrier_available = 0;
    fixture_memory(0x80010000ull);
    if (argc == 2 && (!strcmp(argv[1],"whole") || !strcmp(argv[1],"strips"))) {
        strip_picture(!strcmp(argv[1],"strips")); return 0;
    }
    if (argc == 2 && !strcmp(argv[1], "depth")) { depth_writes(); return 0; }
#ifdef BT_IMAGE_ACCESS_HOST
    if (argc == 2 && !strcmp(argv[1], "image-access")) { check_image_access(); return 0; }
#endif
    if (argc==2 && !strcmp(argv[1],"programs")) { check_draw_programs(); return 0; }
    rdp_register_framebuffer(FB, W, 0);
    rdp_register_framebuffer(FB2, W, 0);
    // In the game the VI and graphics tasks live on separate host threads.
    pthread_t graphics;
    assert(pthread_create(&graphics, NULL, draw_first_task, NULL) == 0);
    assert(pthread_join(graphics, NULL) == 0);
    snapshot();
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
