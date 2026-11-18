// Deterministic textured/occluded/blended 304x228 workload. Reuses fixture memory stubs.
#define main renderer_fixture_main
#include "renderer.c"
#undef main
#include <time.h>
int main(void) {
    const u32 fb=0x80010000u, zb=0x80040000u;
    const int width=304, height=228, count=120;
    fixture_memory(0x80200000ull);
    rdp_register_framebuffer(fb,width,0);
    // 32x32 RGBA16 checker texture in guest memory.
    for(int i=0;i<1024;i++) wr16(bt_mem+TEX+i*2, i&1 ? 0xF801 : 0x07C1);
    rdp_command(0xFD10001F,TEX);
    rdp_command(0xF5101000,0);
    rdp_command(0xF4000000,124<<12|124);
    rdp_command(0xF2000000,124<<12|124);
    // Two cycles: texel 0 * shade followed by combined; texel 1 unused.
    R.rgb[0][0]=C_T0;R.rgb[0][1]=C_ZERO;R.rgb[0][2]=C_SHADE;R.rgb[0][3]=C_ZERO;
    R.rgb[1][0]=C_ZERO;R.rgb[1][1]=C_ZERO;R.rgb[1][2]=C_ZERO;R.rgb[1][3]=C_COMB;
    R.alpha[0][3]=R.alpha[1][3]=C_SHADE;
    rdp_set_texture(0,0);
    RdpVtx a={.x=0,.y=0,.z=20000,.w=1,.s=0,.t=0,.c={255,255,255,200}};
    RdpVtx b=a,c=a,d=a;b.x=d.x=width;c.y=d.y=height;
    b.s=d.s=31*32;c.t=d.t=31*32;
    struct timespec start,end;clock_gettime(CLOCK_MONOTONIC,&start);
    for(int frame=0;frame<count;frame++) {
        rdp_begin();
        rdp_command(0xED000000,width*4<<12|height*4);
        rdp_command(0xFE000000,zb);
        rdp_command(0xFF100000|(width-1),zb);fill(0xFFFCFFFC,0,0,width,height);
        rdp_command(0xFF100000|(width-1),fb);fill(0x00010001,0,0,width,height);
        for(int layer=0;layer<3;layer++) {
            // First opaque, then hidden, then translucent nearer geometry.
            a.z=b.z=c.z=d.z=layer==1 ? 30000 : layer==2 ? 10000 : 20000;
            rdp_command(0xEF182000,layer==2 ? 0x00404030 : 0x30);
            rdp_triangle(&a,&b,&c,RDP_TEX|RDP_SHADE|RDP_Z);
            rdp_triangle(&b,&d,&c,RDP_TEX|RDP_SHADE|RDP_Z);
        }
        rdp_end();
    }
    clock_gettime(CLOCK_MONOTONIC,&end);
    double ms=(end.tv_sec-start.tv_sec)*1000.0+(end.tv_nsec-start.tv_nsec)*1e-6;
    unsigned hash=2166136261u;
    // Include every displayed subpixel and the guest color/depth readbacks.
    u32 *pixels=calloc((size_t)width*height*RDP_MAX_SX*RDP_MAX_SCALE,sizeof *pixels);
    int sx,scale=rdp_frame(fb,width,height,pixels,&sx);
    for(int i=0;i<width*height*scale*sx;i++)hash=(hash^pixels[i])*16777619u;
    for(int i=0;i<width*height*2;i++){hash=(hash^bt_mem[fb+i])*16777619u;hash=(hash^bt_mem[zb+i])*16777619u;}
    printf("scale=%d frames=%d ms/frame=%.3f hash=%08x\n",rdp_scale(),count,ms/count,hash);
    free(pixels);
}
