#define main renderer_fixture_main
#include "renderer.c"
#undef main
int main(void) {
    fixture_memory(0x80010000ull);
    unsigned hash=2166136261u;
    for (int pass=0;pass<3;pass++) {
        for (int i=0;i<4096;i++) bt_mem[TEX+i]=(u8)(i*37+pass*71);
        for (int tile=0;tile<8;tile++) for (int fmt=0;fmt<5;fmt++) for (int siz=0;siz<4;siz++) {
            rdp_command(0xFD10001F,TEX);
            rdp_command(0xF5100100,7u<<24);
            rdp_command(0xF0000000,7u<<24|255<<14);
            rdp_command(0xFD00001F|(siz<<19),TEX);
            rdp_command(0xF5001000|(fmt<<21)|(siz<<19),(u32)tile<<24|3<<20|1<<18|5<<14|1<<8|5<<4);
            rdp_command(0xF3000000,(u32)tile<<24|1023<<12|128);
            rdp_command(0xF2000000,(u32)tile<<24|124<<12|124);
            for (int mode=0;mode<4;mode++) {
                // Exercise both full and partial othermode invalidation, including IA TLUTs.
                if (mode&1) rdp_othermode(1,0xC000,mode<<14);
                else rdp_command(0xEF000000|(mode<<14),0);
                for (int i=0;i<256;i++) {
                    int c[4];sample(tile,(i%37)-3.25f,(i%41)-2.5f,i&1,c);
                    for (int k=0;k<4;k++) hash=(hash^(unsigned)c[k])*16777619u;
                }
            }
        }
    }
    // LOD can drive a combiner even when neither texture color is consumed.
    target(FB); rdp_command(0xED000000,W*4<<12|H*4); fill(0x00010001,0,0,W,H);
    rdp_command(0xEF010000,0); rdp_set_texture(0,3);
    memset(R.rgb, C_ZERO, sizeof R.rgb); memset(R.alpha, C_ZERO, sizeof R.alpha);
    R.rgb[1][0]=C_ONE; R.rgb[1][2]=C_LOD; R.alpha[1][3]=C_ONE;
    RdpVtx a={.x=0,.y=0,.w=1},b=a,c=a;
    b.x=W; b.s=W*3*32; c.y=H;
    rdp_triangle(&a,&b,&c,RDP_TEX);
    assert(rd16(bt_mem+FB+(W+1)*2)==0x8421); // lod=128 -> RGBA5551 gray
    printf("%08x\n",hash);
}
