#include "native_camera.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
void func_800EE940(s16 *,f32 *);
static void near(f32 value,f32 expected) {if(!isfinite(value) || fabsf(value-expected)>0.0001f){fprintf(stderr,"%g != %g\n",value,expected);exit(1);}}
static void vector(f32 *value,f32 x,f32 y,f32 z) {near(value[0],x);near(value[1],y);near(value[2],z);}
static void test_state(void) {
    NativeCamera *camera=func_800CA334();CHECK(camera && sizeof(*camera)==360 && func_800CA384(camera)==camera);
    vector(camera->position,0,0,0);vector(camera->rotation,0,0,0);vector(camera->forward,0,0,-1);
    CHECK(func_800CA794(camera)==40 && func_800CA6E8(camera)==1 && func_800CA7B4(camera)==1);near(func_800CA6FC(camera),4.0f/3);
    near(func_800CA79C(camera),1/tanf(20*0.017453292519943295f));
    f32 p[3]={11.25f,-22.5f,33.75f},r[3]={10,20,30},a[3],b[3];s32 integers[3]={-7,8,9};
    func_800CA5B8(camera,p);func_800CA7E4(camera,a);vector(a,p[0],p[1],p[2]);
    func_800CA5D8(camera,integers);func_800CA7E4(camera,a);vector(a,-7,8,9);
    func_800CA5F8(camera,1,2,3);func_800CA668(camera,r);func_800CA8B4(camera,a,b);vector(a,1,2,3);vector(b,10,20,30);
    func_800CA688(camera,40,50,60);func_800CA9D8(camera,a);vector(a,40,50,60);
    func_800CA628(camera,p,r);func_800CAA00(camera,a,a+1,a+2);vector(a,10,20,30);CHECK(func_800CAA1C(camera)==20);
    CHECK(func_800CAF00(camera,300)==50);
    func_800CA6C0(camera,5,500);func_800CA6D4(camera,a,a+1);CHECK(a[0]==5 && a[1]==500);
    func_800CA6F0(camera,2);CHECK(func_800CA6E8(camera)==2);
    func_800CA510(camera,2);func_800CA558(camera,90);f32 fov,aspect,close,far;
    func_800CA7BC(camera,&fov,&aspect,&close,&far);CHECK(fov==90 && aspect==2 && close==5 && far==500);near(camera->cotangent,1);
    near(camera->side[0],0);near(camera->side[2],1);near(camera->top[1],sqrtf(0.5f));near(camera->top[2],sqrtf(0.5f));
    NativeCamera copy;func_800CA314(&copy,camera);for(int i=0;i<90;++i)CHECK(copy.values[i]==camera->values[i]);
    func_800CA314(camera,camera);CHECK(func_800CA7A4(camera)==&camera->world_rotation && func_800CA7AC(camera)==&camera->view_rotation);
    func_800CA440(camera);func_800CA3A4(camera,10);vector(camera->position,0,0,10);
    func_800CA688(camera,0,90,0);func_800CA3A4(camera,5);vector(camera->position,5,0,10);
    f32 start[3]={0,0,0},point[3]={0,0,10};func_800CA3F4(start,point,3);vector(point,0,0,7);
    func_800CA3F4(start,start,3);vector(start,0,0,0);
    func_800CA440(camera);func_800CA5F8(camera,1,2,3);f32 target[3]={4,6,-9},delta[3];
    near(func_800CA704(camera,target,delta),12);vector(delta,3,4,-12);near(func_800CA768(camera,target),13);
    func_800CA740(camera,a);vector(a,0,0,-1);func_800CA8F4(camera,a,b);vector(a,1,2,3);vector(b,0,0,-1);
    func_800CA5F8(camera,1.9999f,-2.9999f,65537);func_800CA810(camera,integers);CHECK(integers[0]==1 && integers[1]==-2 && integers[2]==65537);
    s16 short_position[3];func_800CA934(camera,short_position);CHECK(short_position[0]==1 && short_position[1]==-2 && short_position[2]==1);
    func_800CA5F8(camera,NAN,INFINITY,-INFINITY);func_800CA810(camera,integers);for(int i=0;i<3;++i)CHECK(integers[i]==-4294967);
    f32 wide[3]={46248.75f,-46248.75f,65537.75f};func_800EE940(short_position,wide);
    CHECK(short_position[0]==-19288 && short_position[1]==19288 && short_position[2]==1);
    wide[0]=NAN;wide[1]=INFINITY;wide[2]=-2147483648.0f;func_800EE940(short_position,wide);
    CHECK(!short_position[0] && !short_position[1] && !short_position[2]);
    func_800CA364(camera);
}
static void test_orientation(void) {
    NativeCamera camera;func_800CA440(&camera);func_800CA5F8(&camera,10,20,30);
    for(int pitch=-60;pitch<=60;pitch+=30)for(int yaw=0;yaw<360;yaw+=45)for(int roll=0;roll<=90;roll+=90) {
        func_800CA688(&camera,pitch,yaw,roll);func_800CAF34(&camera);
        f32 squared=0;for(int i=0;i<3;++i)squared+=camera.forward[i]*camera.forward[i];near(squared,1);
        for(int r=0;r<4;++r)for(int c=0;c<4;++c) {
            f32 value=0;for(int k=0;k<4;++k)value+=camera.world_rotation.m[r][k]*camera.view_rotation.m[k][c];near(value,r==c);
        }
        f32 inside[3],outside[3],low[3],high[3];
        for(int i=0;i<3;++i){inside[i]=camera.position[i]+camera.forward[i]*100;outside[i]=camera.position[i]-camera.forward[i]*100;low[i]=inside[i]-1;high[i]=inside[i]+1;}
        CHECK(func_800CAD9C(&camera,inside[0],inside[1],inside[2]) && !func_800CAD9C(&camera,outside[0],outside[1],outside[2]));
        CHECK(func_800CAA24(camera.values,low,high) && func_800CACEC(camera.values,inside,1) && !func_800CACEC(camera.values,outside,1));
        for(int plane=0;plane<4;++plane) {
            f32 *p=camera.planes[plane];near(p[0]*p[0]+p[1]*p[1]+p[2]*p[2],1);
            near(p[0]*camera.position[0]+p[1]*camera.position[1]+p[2]*camera.position[2]+p[3],0);
        }
        for(int i=0;i<5;++i){f32 ray[3];func_800CB0E8(&camera,ray,i);near(ray[0]*ray[0]+ray[1]*ray[1]+ray[2]*ray[2],1);}
    }
    func_800CA688(&camera,0,90,0);func_800CAF34(&camera);vector(camera.forward,-1,0,0);
    func_800CA688(&camera,90,0,0);func_800CAF34(&camera);vector(camera.forward,0,1,0);
    func_800CA440(&camera);s16 low[3]={-1,-1,-101},high[3]={1,1,-99};CHECK(func_800CAB70(camera.values,low,high));
    f32 edge[3]={0,0,0};CHECK(func_800CAD9C(&camera,0,0,0) && !func_800CACEC(camera.values,edge,0) && !func_800CAA24(camera.values,edge,edge));
    CHECK(func_800CAEA4(&camera,0,-100,0) && !func_800CAEA4(&camera,0,100,0));
    f32 untouched[3]={4,5,6};func_800CB0E8(&camera,untouched,-1);func_800CB0E8(&camera,untouched,5);vector(untouched,4,5,6);
}
static void test_projection(void) {
    NativeCamera camera;func_800CA440(&camera);func_800CA510(&camera,2);func_800CA558(&camera,90);func_800CA6C0(&camera,10,1000);
    MtxF projection;CHECK(func_800CB124(&camera,&projection)==129);
    near(projection.m[0][0],0.25f);near(projection.m[1][1],0.5f);near(projection.m[2][2],-1010.0f/1980);near(projection.m[2][3],-0.5f);near(projection.m[3][2],-10000.0f/990);CHECK(!projection.m[3][3]);
    Mtx fixed;f32 decoded[4][4];guMtxF2L(projection.m,&fixed);guMtxL2F(decoded,&fixed);
    for(int r=0;r<4;++r)for(int c=0;c<4;++c)CHECK(fabsf(projection.m[r][c]-decoded[r][c])<1.0f/65536);
    for(int i=0;i<2;++i) {
        f32 z=i ? -1000 : -10,w=z*projection.m[2][3],clip=z*projection.m[2][2]+projection.m[3][2];near(clip/w,i ? 1 : -1);
    }
    func_800CA6C0(&camera,-1,0);CHECK(func_800CB124(&camera,&projection)==1285);near(projection.m[3][2],-1.01f);CHECK(camera.near_clip==-1 && !camera.far_clip);
    func_800CA6C0(&camera,100000,1000000);CHECK(func_800CB124(&camera,&projection)>0);CHECK(projection.m[3][2]>=-32767.01f && projection.m[3][2]<=-32766.99f);
    func_800CA6C0(&camera,1,1000000);CHECK(func_800CB124(&camera,&projection)==1);
    NativeCamera saved=camera;MtxF previous=projection;
    for(int i=0;i<6;++i) {
        camera=saved;
        if(i==0)camera.aspect=0;else if(i==1)camera.cotangent=NAN;else if(i==2)camera.near_clip=INFINITY;
        else if(i==3)camera.far_clip=INFINITY;else if(i==4)camera.near_clip=camera.far_clip=1e30f;else camera.far_clip=3e38f;
        CHECK(!func_800CB124(&camera,&projection));for(int r=0;r<4;++r)for(int c=0;c<4;++c)CHECK(projection.m[r][c]==previous.m[r][c]);
    }
}
int main(void) {test_state();test_orientation();test_projection();puts("native camera state, orientation, frustum and perspective checks passed");return 0;}
