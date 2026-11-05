#include "native_camera_frame.h"
#include "gfx.h"
#include "memory.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
extern MtxF D_8007B4F0[31];
extern Mtx *D_8012D554,*D_8012D558;
static void near(f32 value,f32 expected,f32 tolerance) {CHECK(isfinite(value) && fabsf(value-expected)<=tolerance);}
static void vector(f32 *v,f32 x,f32 y,f32 z) {near(v[0],x,0.0001f);near(v[1],y,0.0001f);near(v[2],z,0.0001f);}
static void test_orthographic_math(void) {
    Mtx packed;f32 matrix[4][4];
    guOrtho(&packed,-3,7,-2,6,4,20,0.5f);guMtxL2F(matrix,&packed);
    const f32 points[3][3]={{-3,-2,-4},{7,6,-20},{2,2,-12}};
    for(int point=0;point<3;++point)for(int col=0;col<3;++col) {
        f32 value=matrix[3][col];
        for(int row=0;row<3;++row)value+=points[point][row]*matrix[row][col];
        near(value,point==0 ? -0.5f : point==1 ? 0.5f : 0,0.0002f);
    }
    CHECK(matrix[3][3]==0.5f);
}
static void test_state(void) {
    NativeCamera camera,second;func_800CA440(&camera);func_800CA440(&second);
    func_800E4278();CHECK(!func_800E42A8());func_800E42B4(&camera);CHECK(func_800E42A8()==&camera);
    f32 p[3]={10,20,30},r[3]={1,2,3},out[3],rotation[3];s32 integer[3]={-10,11,12};s16 short_pos[3];
    func_800E3BAC(p);func_800E3980(out);vector(out,10,20,30);
    func_800E3BD4(integer);func_800E3A08(integer);CHECK(integer[0]==-10 && integer[1]==11 && integer[2]==12);
    func_800E3A30(short_pos);CHECK(short_pos[0]==-10 && short_pos[1]==11 && short_pos[2]==12);
    func_800E3BFC(1,2,3);func_800E3C30(r);func_800E39A8(out,rotation);vector(out,1,2,3);vector(rotation,1,2,3);
    func_800E39D8(p,r);func_800E3C58(4,5,6);func_800E3A58(out);vector(out,4,5,6);
    func_800E3B50(out,out+1,out+2);vector(out,4,5,6);CHECK(func_800E3A80()==5);
    CHECK(func_800E3AA4(6.5f)==359 && func_800E3AA4(725)==0 && func_800E3AA4(NAN)==0);
    CHECK(func_800E40AC(99,270)==5);
    func_800E3C8C(10,1000);func_800E3CB8(out,out+1);CHECK(out[0]==10 && out[1]==1000);
    CHECK(func_800E4088()==10);near(func_800E4064(),4.0f/3,0.00001f);
    func_800CA6F0(&camera,2);CHECK(func_800E42C0()==2);
    func_800E3CE8();CHECK(func_800E401C()==&camera.world_rotation && func_800E4040()==&camera.view_rotation);
    func_800E41CC();func_800E3B88();func_800E4208();func_800E39A8(out,rotation);vector(out,10,20,30);vector(rotation,4,5,6);
    CHECK(func_800E42C0()==2);func_800E4208();
    func_800E41CC();func_800E42B4(&second);func_800E4208();CHECK(second.position[1]==20 && camera.position[1]==20);
    func_800E3B88();func_800E3900(10);func_800E3980(out);vector(out,0,0,10);
    func_800E3958(out);vector(out,0,0,-1);f32 target[3]={3,4,-2};near(func_800E3928(target,out),12,0);vector(out,3,4,-12);
    f32 point[3]={0,0,0};func_800E4244(point,3);vector(point,0,0,3);
    func_800E41CC();func_800E41CC();func_800E4278();CHECK(!func_800E42A8());
    func_800E42B4(&camera);func_800E41CC();func_800E4290();CHECK(!func_800E42A8());
    s32 low[3]={-10,-20,-30},high[3]={10,20,30};f32 eye[3]={0,0,100},forward[3]={0,0,-1};
    CHECK(func_800E36D0(low,high,eye,forward)==130);forward[2]=1;CHECK(func_800E36D0(low,high,eye,forward)==0);
    func_800E37E8(low,high,10);CHECK(low[0]==-2 && low[1]==-3 && low[2]==-4 && high[0]==1 && high[1]==2 && high[2]==3);
    low[0]=INT_MIN;func_800E37E8(low,high,-1);CHECK(low[0]==INT_MAX);
}
static void test_frames(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);
    NativeGraphicsMemory memory={0};Gfx packets[12];Mtx matrices[6];
    u32 base=native_graphics_register(&memory,matrices,sizeof(matrices));CHECK(base);
    CHECK(native_graphics_register(&memory,packets,sizeof(packets)));native_graphics_bind(&memory);
    NativeGraphicsContext frame={packets,matrices,packets+12,matrices+6,&memory};
    func_800E4628();CHECK(!D_8012D554 && !D_8012D558);
    CHECK(func_800E44FC(&frame));CHECK(frame.gfx==packets+3 && frame.mtx==matrices+2 && D_8012D558==matrices);
    CHECK(packets[0].words.w0==0xDB0E0000 && packets[0].words.w1==13);
    CHECK(packets[1].words.w0==0xDA380007 && packets[1].words.w1==base);
    CHECK(packets[2].words.w0==0xDA380003 && packets[2].words.w1==base+64);
    f32 fixed[4][4];guMtxL2F(fixed,matrices+1);
    for(int i=0;i<4;++i)for(int j=0;j<4;++j)CHECK(fixed[i][j]==(i==j));
    Gfx *cursor=packets+3;func_800E42E4(0);func_800E4640(&cursor);CHECK(cursor==packets+4 && packets[3].words.w1==base);
    func_800E42E4(1);func_800E4640(&cursor);CHECK(packets[4].words.w0==0xDE000000 && packets[4].words.w1==0x08000000);
    func_800E46E0(&cursor,packets);CHECK(packets[5].words.w0==0xDB060020 && packets[5].words.w1==native_graphics_address(&memory,packets,8));
    CHECK(native_graphics_segment(&memory,8,packets[5].words.w1));CHECK(native_graphics_resolve(&memory,packets[4].words.w1,8)==packets);
    for(int enabled=0;enabled<2;++enabled)for(int requested=0;requested<2;++requested) {
        frame.gfx=packets;frame.mtx=matrices;widescreen_enabled=enabled;CHECK(func_800E42F0(&frame,requested));
        CHECK(frame.gfx==packets+2 && frame.mtx==matrices+2 && D_8012D554==matrices);
        guMtxL2F(fixed,matrices);f32 width=enabled && requested ? 810 : 608;
        near(fixed[0][0],1/width,1.0f/65536);near(fixed[1][1],1.0f/456,1.0f/65536);near(fixed[2][2],-0.02f,1.0f/65536);
    }
    widescreen_enabled=0;func_800E42E4(0);
    func_800CA5F8(&camera,10,-20,30);func_800CA6F0(&camera,2);
    for(int pitch=-60;pitch<=60;pitch+=30)for(int yaw=0;yaw<360;yaw+=45) {
        func_800CA688(&camera,pitch,yaw,20);func_800CAF34(&camera);frame.gfx=packets;frame.mtx=matrices;CHECK(func_800E44FC(&frame));
        guMtxL2F(fixed,matrices);f32 world[4],clip[4]={0};
        for(int i=0;i<3;++i)world[i]=camera.position[i]+100*camera.forward[i];world[3]=1;
        for(int col=0;col<4;++col)for(int row=0;row<4;++row)clip[col]+=world[row]*fixed[row][col];
        CHECK(clip[3]>0);near(clip[0]/clip[3],0,0.0002f);near(clip[1]/clip[3],0,0.0002f);
        near(clip[2]/clip[3],(10001.0f/9999)-(20000.0f/9999)/50,0.0002f);
    }
    func_800CA440(&camera);func_800CA5F8(&camera,40000,0,0);func_800CAF34(&camera);
    frame.gfx=packets;frame.mtx=matrices;CHECK(func_800E44FC(&frame));guMtxL2F(fixed,matrices);
    near(fixed[3][0],-20000*camera.cotangent/camera.aspect*0.5f,0.005f);CHECK(func_800E42C0()==1);
    guMtxIdentF(D_8012D510.m);D_8012D510.m[3][0]=3;f32 in[4]={1,2,3,2},out[4];func_800E46A4(out,in);CHECK(out[0]==7 && out[1]==2 && out[2]==3 && out[3]==2);
    D_8012D550=123;CHECK(func_800E46D4()==123);
    func_800E4628();func_800E4290();native_graphics_dispose(&memory);
}
static void test_failures(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);
    NativeGraphicsMemory memory={0};Gfx packets[3];Mtx matrices[2];
    NativeGraphicsContext frame={packets,matrices,packets+3,matrices+2,&memory};
    rare_memset(packets,0x56,sizeof(packets));rare_memset(matrices,0x78,sizeof(matrices));
    CHECK(!func_800E44FC(NULL) && !func_800E42F0(NULL,0));CHECK(!func_800E44FC(&frame) && !func_800E42F0(&frame,0));
    CHECK(native_graphics_register(&memory,matrices,sizeof(matrices)));
    frame.gfx_end=packets+1;CHECK(!func_800E44FC(&frame) && !func_800E42F0(&frame,0));frame.gfx_end=packets+3;
    frame.mtx_end=matrices+1;CHECK(!func_800E44FC(&frame) && !func_800E42F0(&frame,0));frame.mtx_end=matrices+2;
    func_800E42B4(NULL);CHECK(!func_800E44FC(&frame));func_800E42B4(&camera);
    camera.aspect=0;CHECK(!func_800E44FC(&frame));camera.aspect=4.0f/3;
    camera.range_scale=0;CHECK(!func_800E44FC(&frame));camera.range_scale=1;
    camera.position[0]=NAN;CHECK(!func_800E44FC(&frame));camera.position[0]=0;
    mlMtxIdent();mlMtx_push_translation(1,2,3);MtxF *previous=mlMtx_get_stack_pointer();
    camera.view_rotation.m[0][0]=INFINITY;CHECK(!func_800E44FC(&frame));
    CHECK(mlMtx_get_stack_pointer()==previous && previous->m[3][0]==1);
    for(int i=0;i<4;++i)for(int j=0;j<4;++j)CHECK(D_8007B4F0[0].m[i][j]==(i==j));
    CHECK(frame.gfx==packets && frame.mtx==matrices);
    for(size_t i=0;i<sizeof(packets);++i)CHECK(((u8 *)packets)[i]==0x56);
    for(size_t i=0;i<sizeof(matrices);++i)CHECK(((u8 *)matrices)[i]==0x78);
    native_graphics_dispose(&memory);func_800E4290();
}
int main(void) {test_orthographic_math();test_state();test_frames();test_failures();puts("native camera selection, snapshots, view projection, packet references and bounded frame outputs passed");return 0;}
