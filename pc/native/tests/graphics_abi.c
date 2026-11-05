#include "native_skinning.h"
#include "memory.h"
#include <math.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static void test_packets(void) {
    CHECK(sizeof(Gfx)==8 && sizeof(Mtx)==64 && sizeof(Mtx_t)==64 && _Alignof(Gfx)==8 && _Alignof(Mtx)==8);
    struct {Gfx commands[4];u64 guard;} output={.guard=0xABCDEF0123456789ULL};Gfx *cursor=output.commands;
    gSPMatrix(cursor++,0x04000100,G_MTX_PUSH|G_MTX_LOAD|G_MTX_MODELVIEW);
    gSPDisplayList(cursor++,0x05000100);gSPPopMatrix(cursor++,G_MTX_MODELVIEW);gSPEndDisplayList(cursor++);
    CHECK(cursor==output.commands+4 && (u8 *)cursor-(u8 *)output.commands==32 && output.guard==0xABCDEF0123456789ULL);
    CHECK(output.commands[0].words.w0==0xDA380002 && output.commands[0].words.w1==0x04000100);
    CHECK(output.commands[1].words.w0==0xDE000000 && output.commands[1].words.w1==0x05000100);
    CHECK(output.commands[2].words.w0==0xD8380002 && output.commands[2].words.w1==64);
    CHECK(output.commands[3].words.w0==0xDF000000 && !output.commands[3].words.w1);
}
static void test_fixed_matrix(void) {
    f32 input[4][4]={{-1.5f,2.25f,0,0.125f},{0,1,0,-0.5f},{0,0,2,3},{3.5f,-4.25f,7.75f,0.75f}},decoded[4][4];
    struct {Mtx matrices[2];u64 guard;} output={.guard=0xABCDEF0123456789ULL};rare_memset(output.matrices,0xCD,sizeof(output.matrices));
    guMtxF2L(input,&output.matrices[0]);u32 *words=(u32 *)&output.matrices[0];
    CHECK(words[0]==0xFFFE0002 && words[8]==0x80004000 && words[9]==0x00002000 && words[11]==0x00008000);
    CHECK(words[6]==0x0003FFFB && words[14]==0x8000C000 && words[15]==0xC000C000);
    for(int i=64;i<128;++i)CHECK(((u8 *)output.matrices)[i]==0xCD);
    guMtxL2F(decoded,&output.matrices[0]);for(int r=0;r<4;++r)for(int c=0;c<4;++c)CHECK(decoded[r][c]==input[r][c]);
    input[0][0]=1.75f/65536;input[0][1]=-1.75f/65536;input[0][2]=NAN;input[0][3]=INFINITY;
    int mode=fegetround();CHECK(!fesetround(FE_UPWARD));guMtxF2L(input,&output.matrices[0]);CHECK(!fesetround(mode));
    guMtxL2F(decoded,&output.matrices[0]);CHECK(decoded[0][0]==1.0f/65536 && decoded[0][1]==-1.0f/65536 && decoded[0][2]==-32768 && decoded[0][3]==-32768);
    mlMtxIdent();mlMtxTranslate(3,4,5);mlMtxApply(&output.matrices[1]);guMtxL2F(decoded,&output.matrices[1]);
    for(int r=0;r<3;++r){CHECK(decoded[r][r]==1);CHECK(decoded[3][r]==r+3);}CHECK(output.guard==0xABCDEF0123456789ULL);
    NativeSkeleton *skeleton=heap_alloc(sizeof(*skeleton)+sizeof(NativeBone));skeleton->count=1;
    NativeBoneMatrices *bones=func_800ADF98();func_800ADCD0(&bones,skeleton);bones->matrices[0].m[3][0]=10;
    Mtx *cursor=output.matrices;func_800AE598(bones,&cursor);CHECK((u8 *)cursor-(u8 *)output.matrices==128 && output.guard==0xABCDEF0123456789ULL);
    guMtxL2F(decoded,&output.matrices[1]);CHECK(decoded[3][0]==10 && decoded[3][3]==1);
    func_800ADF5C(bones);heap_free(skeleton);
}
int main(void) {test_packets();test_fixed_matrix();puts("native graphics ABI and fixed matrix conversions passed");return 0;}
