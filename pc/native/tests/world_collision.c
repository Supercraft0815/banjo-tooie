#include "marker_world.h"
#include "native_custom_hits.h"
#include "native_collision_geometry.h"
#include "native_collision.h"
#include "native_actor.h"
#include "actor_model_dependencies.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)

/* Actor animation/deformation and skeleton geometry remain controlled boundaries. */
static int frame=100,attached,notifications,filter_allow=1;
static uintptr_t notified,token;
static int custom_calls[4],query_order[256],query_count;
static NativeActorHit last_hit;
static int skeleton_ready=1,skeleton_hit=7;
s32 func_8001211C(void) { return frame; }
s32 func_800A9F14(s32 mode) { return 0; }
s32 func_800A9F30(void) { return 1; }
s32 func_800B0CFC(void *p) { CHECK(0);return 0; }
void func_800EA400(s32 context,Unk80132ED0 *marker,f32 *point,void *triangle) {
    CHECK(context==3 && marker && point[1]==100 && triangle);++attached;
}
s32 func_800AE0B8(void *skeleton) { CHECK(skeleton);return skeleton_ready; }
f32 *func_801027F4(Actor *actor) { return actor->rotation; }
NativeActorHit *func_80104124(void) { return &last_hit; }
s16 func_800B1F8C(void *mesh,f32 *position,f32 *rotation,f32 scale,s32 zero,void *skeleton,f32 *point,f32 radius,f32 *normal,u32 kind) {
    CHECK(position && rotation && scale>0 && !zero && skeleton && point && radius==2 && normal && kind==3);return skeleton_hit;
}
static void notify_hit(uintptr_t object,uintptr_t userdata) { CHECK(userdata==token);notified=object;++notifications; }
static s32 allow_hit(Unk80132ED0 *marker,Unk80132ED0 *self) { CHECK(marker);return filter_allow; }
static OSThread *hit_filter(void) {
    static struct {void (*unused[4])(void);s32 (*filter)(Unk80132ED0 *,Unk80132ED0 *);} callbacks={.filter=allow_hit};
    return (void *)&callbacks;
}
static void record(Unk80132ED0 *marker,int type) {
    ++custom_calls[type];CHECK(query_count<256);query_order[query_count++]=marker->unk16;
}
static void *custom_line(Unk80132ED0 *marker,f32 *a,f32 *b,f32 *n,u32 flags) { CHECK(a && b && n && flags==0x123);record(marker,0);return marker; }
static void *custom_sweep(Unk80132ED0 *marker,f32 *a,f32 *b,f32 r,f32 *n,s32 steps,u32 flags) {CHECK(a && b && n && r==2 && steps==8 && flags==0x123);record(marker,1);return marker;}
static void *custom_sphere(Unk80132ED0 *marker,f32 *a,f32 r,f32 *n,u32 flags) {CHECK(a && n && r==2 && flags==0x123);record(marker,2);return marker;}
static s32 custom_test(Unk80132ED0 *marker,f32 *point,f32 radius,f32 *normal,u32 kind) {
    CHECK(kind==3 && radius>0 && normal);++custom_calls[3];return point[0]>=102 ? 0x17 : 0;
}
static NativeMarkerCollision methods={custom_line,custom_sweep,custom_sphere,custom_test};
static NativeMarkerCollision *custom_getter(void) { return &methods; }
static Unk80132ED0 *spawn(int x,int y,int z,int fallback) {
    s32 position[3]={x,y,z},index;
    Unk80132ED0 *marker=func_800EBED4(position,1,5,fallback);CHECK(marker);
    Actor *actor=func_80106668(&index);CHECK(actor);rare_memset(actor,0,sizeof(*actor));
    actor->unk0=marker;actor->factory=model_test_factory;actor->flags74|=1u<<28;actor->scale=1;actor->pad68=200;
    for(int i=0;i<3;++i) actor->position[i]=position[i];
    func_800EC340(marker,index);marker->unk14=148;marker->unk18|=0x10000|(3<<1);
    ((NativeMarkerProp *)marker->unk0)->flags|=8;
    marker->callback=hit_filter;return marker;
}
static void reset(void) {
    marker_world_reset();func_800EBB5C();func_800EBB94();func_801065E0();
    func_800CB870();func_800EA614();func_800CD230(0);
    for(int i=0;i<4;++i)custom_calls[i]=0;query_count=0;attached=notifications=0;model_test_reset();filter_allow=1;
}
static void cleanup(void) {
    func_800CDBA8(NULL,NULL,NULL,0);marker_world_cleanup();func_80106608();func_800EA614();func_800CB870();
}
static void test_static_model(void) {
    reset();NativeWorldCell *cell=marker_world[1];
    NativeMarkerProp *prop=func_800E9804(cell);
    *prop=(NativeMarkerProp){.sprite=4u<<20,.position={100,100,100},.flags=(100<<8)|0x12};
    f32 a[3]={75,105,75},b[3]={75,95,75},normal[3],point[3]={75,101,75};
    CHECK(!func_800EA628(cell,a,b,normal,0));CHECK(!func_800D6B0C(1500));
    func_800CB840(1,3);CHECK(func_800EA628(cell,a,b,normal,0) && b[1]==100 && normal[1]==1 && (prop->flags&8));
    func_800CB870();b[1]=95;CHECK(func_800CD23C(a,b,normal,0) && b[1]==100);
    CHECK(func_800EADFC(cell,point,2,normal,0) && normal[1]==1);
    CHECK(func_800CD544(point,2,normal,0));
    token=(uintptr_t)prop;func_800EA600(notify_hit,token);b[1]=101;
    CHECK(func_800CD3A8(a,b,2,normal,8,0) && b[1]>101.49f && b[1]<101.52f);
    CHECK(notifications==1 && notified==prop->sprite);
    prop->flags&=~0x10;b[1]=95;CHECK(!func_800EA628(cell,a,b,normal,0));
    prop->flags|=0x10;prop->sprite=0xFFF00000;b[1]=95;CHECK(!func_800EA628(cell,a,b,normal,0));
    /* With 90 degrees of yaw, (75, 75) lies exactly on the hypotenuse. */
    prop->sprite=(4u<<20)|(45<<8);a[2]=b[2]=50;b[1]=95;CHECK(!func_800EA628(cell,a,b,normal,0));
    a[0]=b[0]=75;a[2]=b[2]=125;b[1]=95;CHECK(func_800EA628(cell,a,b,normal,0));
    prop->sprite=4u<<20;prop->flags=(200<<8)|0x12;a[0]=b[0]=-50;a[2]=b[2]=50;b[1]=95;
    CHECK(func_800EA628(cell,a,b,normal,0) && b[1]==100);
    cleanup();
}
static void test_actor_geometry(void) {
    reset();Unk80132ED0 *marker=spawn(100,100,100,0);Actor *actor=func_80106790(marker);
    CHECK(func_800D674C(148));
    f32 a[3]={75,105,75},b[3]={75,95,75},normal[3],point[3]={75,101,75};
    token=(uintptr_t)&token;func_800EA600(notify_hit,token);func_800CB840(1,3);actor->pad80=1u<<16;
    CHECK(func_800CD23C(a,b,normal,0) && b[1]==100 && attached==1 && notifications==1 && notified==(uintptr_t)marker && model_test_loads==1);
    CHECK(func_800CD544(point,2,normal,0));b[1]=101;CHECK(func_800CD3A8(a,b,2,normal,8,0));
    CHECK(notifications==1);actor->unk64_17=1;b[1]=95;CHECK(!func_800CD23C(a,b,normal,0) && !func_800CD544(point,2,normal,0));
    actor->unk64_17=0;((NativeMarkerProp *)marker->unk0)->flags&=~8;CHECK(!func_800CD23C(a,b,normal,0));
    ((NativeMarkerProp *)marker->unk0)->flags|=8;marker->unk18&=~0x10000;CHECK(!func_800CD23C(a,b,normal,0));marker->unk18|=0x10000;
    actor->position[0]=2000;b[1]=95;CHECK(!func_800CD23C(a,b,normal,0) && !func_800CD544(point,2,normal,0));
    cleanup();
}
static void test_custom_dispatch(void) {
    reset();Unk80132ED0 *marker=spawn(100,100,100,0);func_800EC358(marker,custom_getter);
    f32 a[3]={100,105,100},b[3]={100,95,100},normal[3];
    NativeWorldCell *cell=marker_world[1];
    CHECK(func_800EA628(cell,a,b,normal,0x123)==marker);
    CHECK(func_800EAA2C(cell,a,b,2,normal,8,0x123)==marker);
    CHECK(func_800EADFC(cell,a,2,normal,0x123)==marker);
    CHECK(custom_calls[0]==1 && custom_calls[1]==1 && custom_calls[2]==1 && !model_test_loads);
    Actor *actor=func_80106790(marker);actor->unk64_17=1;
    CHECK(func_800EA628(cell,a,b,normal,0x123)==marker);
    CHECK(!func_800EAA2C(cell,a,b,2,normal,8,0x123) && !func_800EADFC(cell,a,2,normal,0x123));actor->unk64_17=0;
    Unk80132ED0 *other=spawn(1100,100,100,0);func_800EC358(other,custom_getter);other->unk16=1;
    Unk80132ED0 *fallback=spawn(5000,100,100,1);func_800EC358(fallback,custom_getter);fallback->unk16=2;
    query_count=0;b[0]=1100;
    CHECK(func_800CD23C(a,b,normal,0x123)==fallback && query_order[query_count-1]==2);
    int found_first=0,found_second=0;for(int i=0;i<query_count;++i){found_first|=query_order[i]==0;found_second|=query_order[i]==1;}
    CHECK(found_first && found_second);
    query_count=0;CHECK(func_800CD3A8(a,b,2,normal,8,0x123)==fallback);
    query_count=0;CHECK(func_800CD544(a,2,normal,0x123)==fallback);
    cleanup();
}
static void test_cell_order(void) {
    reset();NativeWorldGrid saved=native_world_grid;NativeWorldCell cells[8]={0};u8 counts[8]={0};
    native_world_grid=(NativeWorldGrid){.cells=cells,.upper={1,1,1},.row_stride=2,.plane_stride=4,
        .count=8,.dimensions={2,2,2},.cell_size=1000,.scale=0.001f,.model_counts=counts};
    for(int i=0;i<8;++i) {
        Unk80132ED0 *marker=spawn(100+1000*(i&1),100+1000*((i>>1)&1),100+1000*(i>>2),0);
        func_800EC358(marker,custom_getter);marker->unk16=i;
    }
    Unk80132ED0 *fallback=spawn(5000,5000,5000,1);func_800EC358(fallback,custom_getter);fallback->unk16=9;
    f32 a[3]={100,100,100},b[3]={1100,1100,1100},point[3]={600,600,600},normal[3];
    int line_order[]={9,9,0,1,2,3,9,9,4,5,6,7,9};
    int sphere_order[]={9,9,0,4,2,6,9,9,1,5,3,7,9};
    CHECK(func_800CD23C(a,b,normal,0x123)==fallback && query_count==13);
    for(int i=0;i<13;++i)CHECK(query_order[i]==line_order[i]);
    query_count=0;CHECK(func_800CD3A8(a,b,2,normal,8,0x123)==fallback && query_count==13);
    for(int i=0;i<13;++i)CHECK(query_order[i]==sphere_order[i]);
    func_800CD230(600);query_count=0;CHECK(func_800CD544(point,2,normal,0x123)==fallback && query_count==13);
    for(int i=0;i<13;++i)CHECK(query_order[i]==sphere_order[i]);
    for(int i=0;i<8;++i)func_800E9C44(cells+i);
    func_800E9C44(&native_world_grid.fallback);native_world_grid=saved;cleanup();
}
static void test_marker_hits(void) {
    reset();Unk80132ED0 *self=spawn(100,100,100,0),*target=spawn(104,100,100,0);
    f32 a[3]={100,100,100},b[3]={108,100,100},step[3]={2,0,0},radius[2]={2,2},points[6]={0,0,0,104,100,100};
    func_800EC358(target,custom_getter);
    CHECK(func_800CD6B4(target,a,2,step,3) && custom_calls[3]==2 && ((target->unk18>>17)&15)==7);
    CHECK(!func_800CD6B4(target,a,2,step,1));
    CHECK(func_800CD820(self,a,b,2)==target);
    CHECK(!func_800CD820(self,a,b,0) && !func_800CD820(self,a,b,NAN));
    s32 index;CHECK(func_800CDBA8(self,points,radius,2)==1 && func_800CDFA8(0,&index)==target && index==1);
    CHECK(!func_800CDFA8(-1,&index) && index==-1 && !func_800CDFA8(1,NULL));
    filter_allow=0;CHECK(!func_800CD820(self,a,b,2) && !func_800CDBA8(self,points,radius,2));filter_allow=1;
    func_80106790(target)->unk64_0=1;func_800CB840(1,17);CHECK(!func_800CD820(self,a,b,2));func_800CB840(33,17);CHECK(!func_800CD820(self,a,b,2));
    BtIntPtr context;
    func_800CB840(3,(BtIntPtr)target);
    CHECK(func_800CB854(&context)==3 && context==(BtIntPtr)target);
    func_800CB870();CHECK(func_800CB854(&context)==0 && context==0);
    func_80106790(target)->unk64_17=1;CHECK(!func_800CDBA8(self,points,radius,2));func_80106790(target)->unk64_17=0;
    target->unk28&=~0x200;CHECK(!func_800CD820(self,a,b,2));target->unk28|=0x200;
    func_800EC358(target,NULL);target->unk18=(target->unk18&0x1FFFFF)|(1u<<21);
    CHECK(func_800CD6B4(target,b,4,step,1));b[0]=109;CHECK(!func_800CD6B4(target,b,4,step,1));
    CHECK(func_800CDBA8(self,points,radius,2)==1);
    CHECK(!func_800CDBA8(self,NULL,NULL,0) && !func_800CDFA8(0,&index));
    cleanup();
}
static void test_many_hits(void) {
    reset();Unk80132ED0 *self=spawn(100,100,100,0);Unk80132ED0 *markers[80];
    for(int i=0;i<80;++i){markers[i]=spawn(100,100,100,0);markers[i]->unk18=(markers[i]->unk18&0x1FFFFF)|(1u<<21);}
    f32 point[3]={100,100,100},radius=2;
    CHECK(func_800CDBA8(self,point,&radius,1)==80);
    for(int i=0;i<80;++i){s32 sphere;CHECK(func_800CDFA8(i,&sphere)==markers[i] && sphere==0);}
    CHECK(func_800CD820(self,point,point,2)==markers[79]);
    cleanup();
}
static void test_skeleton_callbacks(void) {
    reset();Unk80132ED0 *marker=spawn(100,100,100,0);Actor *actor=func_80106790(marker);
    subaddiecustomhits_entrypoint_0(actor,subaddiecustomhits_entrypoint_1);
    CHECK((actor->flags74&0x80000000u) && marker->collision()==subaddiecustomhits_entrypoint_1());
    f32 point[3]={102,100,100},normal[3],out[3],radius;
    CHECK(subaddiecustomhits_entrypoint_2(marker,point,2,normal,3)==7);
    CHECK(last_hit.id==((marker->unk10>>1)&0x7FFF) && last_hit.frame==frame);
    CHECK(subaddiecustomhits_entrypoint_4(actor,out,&radius) && radius==2 && out[0]==102);
    ++frame;CHECK(!subaddiecustomhits_entrypoint_4(actor,out,&radius) && radius==200 && out[0]==100);
    skeleton_ready=0;CHECK(!subaddiecustomhits_entrypoint_2(marker,point,2,normal,3));skeleton_ready=1;
    actor->scale=0;CHECK(!subaddiecustomhits_entrypoint_2(marker,point,2,normal,3));actor->scale=1;
    CHECK(!subaddiecustomhits_entrypoint_3(actor,point,2));point[0]=1000;CHECK(subaddiecustomhits_entrypoint_3(actor,point,2));
    CHECK(fabsf(subaddiecustomhits_entrypoint_5(actor,out)-230)<0.01f && out[0]==100);
    cleanup();
}
static void test_original_props(void) {
    s16 _gsproplookup_entrypoint_0(NativeMarkerProp *);
    reset();NativeWorldCell *cell=marker_world[1];NativeMarkerProp *prop=func_800E9804(cell);
    int models=0,meshes=0,queries=0,hits=0;
    for(int index=0;index<4096;++index) {
        *prop=(NativeMarkerProp){.sprite=(u32)index<<20,.position={100,100,100},.flags=(100<<8)|0x12};
        int id=_gsproplookup_entrypoint_0(prop);if(!id)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);++models;
        NativeCollisionMesh *mesh=(void *)func_800B2720(model);NativeVertexList *vertices=func_800B2840(model);
        if(mesh) {
            ++meshes;NativeCollisionTriangle *tri=(void *)(mesh->cells+mesh->cell_count);
            for(int i=0,samples=0;i<mesh->triangle_count && samples<3;++i) {
                f32 center[3],ab[3],ac[3],normal[3],a[3],b[3];
                for(int j=0;j<3;++j) {
                    s16 x=vertices->vertices[tri[i].vertices[0]].v.ob[j],y=vertices->vertices[tri[i].vertices[1]].v.ob[j],z=vertices->vertices[tri[i].vertices[2]].v.ob[j];
                    center[j]=(x+y+z)/3.0f+100;ab[j]=y-x;ac[j]=z-x;
                }
                for(int j=0;j<3;++j)normal[j]=ab[(j+1)%3]*ac[(j+2)%3]-ab[(j+2)%3]*ac[(j+1)%3];
                f32 length=sqrtf(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2]);if(length<1)continue;
                for(int j=0;j<3;++j){normal[j]/=length;a[j]=center[j]+normal[j]*10;b[j]=center[j]-normal[j]*10;}
                NativeCollisionTriangle *hit=func_800EA628(cell,a,b,normal,0);++queries;++samples;
                if(hit){++hits;CHECK(hit>=tri && hit<tri+mesh->triangle_count);}
                for(int j=0;j<3;++j){a[j]=b[j]=center[j];CHECK(isfinite(normal[j]));}
                func_800EADFC(cell,a,5,normal,0);func_800EAA2C(cell,a,b,5,normal,4,0);
            }
        }
        func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(models>0 && meshes>0 && queries>0 && hits==queries);
    printf("Original static props: %d lookup entries, %d meshes, %d/%d rays through actual cell queries.\n",models,meshes,hits,queries);
    cleanup();
}
int main(int argc,char **argv) {
    CHECK((argc==2 || argc==3) && native_assets_open(argv[1]));func_800AB980();
    if(argc==3)test_original_props();
    else {test_static_model();test_actor_geometry();test_custom_dispatch();test_cell_order();test_marker_hits();test_many_hits();test_skeleton_callbacks();}
    func_800AB9D0();native_assets_shutdown();
    puts("native world collision checks passed");
    return 0;
}
