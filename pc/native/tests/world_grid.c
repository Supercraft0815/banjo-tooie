#include "native_world_grid.h"
#include "native_fog.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
/* Grid metadata is supplied here; level loading/rendering remain external boundaries. */
static int trace[16],used,render_mode;
static u8 models[120],dynamic[120];
static void observed(NativeWorldGrid *grid,int id) { CHECK(grid==&native_world_grid);trace[used++]=id; }
s32 func_800EA068(s32 mask) { CHECK(mask==0x200);return render_mode; }
s32 func_800D3104(s32 mode,void *grid) { CHECK(mode==19);observed(grid,7);return 0; }
void func_8010A874(s32 mode) { CHECK(mode==23);trace[used++]=8; }
s32 func_800DC214(s32 lo,s32 hi) { CHECK(lo==0 && hi==32);return 17; }
static void setup(void) {
    native_world_grid=(NativeWorldGrid){.lower={-2,-1,-3},.upper={1,3,2},.row_stride=4,
        .plane_stride=20,.count=120,.dimensions={4,5,6},.cell_size=1000,.scale=0.001f};
    native_world_grid.cells=heap_alloc(120*sizeof(NativeWorldCell));
    native_world_grid.model_counts=heap_alloc(120);
    bzero(native_world_grid.cells,120*sizeof(NativeWorldCell));
    bzero(native_world_grid.model_counts,120);
    func_800E9728();func_800EBB5C();func_800EBB94();
}
static void test_coordinates(void) {
    NativeWorldCell *begin,*end,unrelated={0};s32 a[3],b[3];
    CHECK(func_800BDC50()==120 && func_800BDC5C()==1000);
    func_800BE52C(&begin,&end);CHECK(begin==native_world_grid.cells && end-begin==120);
    func_800BE554(a,b);
    for(int i=0;i<3;++i) CHECK(a[i]==native_world_grid.lower[i] && b[i]==native_world_grid.upper[i]);
    func_800BE58C(a,b);CHECK(a[0]==4 && a[1]==5 && a[2]==6 && b[0]==4 && b[1]==20 && b[2]==120);
    for(int i=0;i<120;++i) {
        s32 coord[3]={i%4-2,(i/4)%5-1,i/20-3};
        s32 pos[3]={coord[0]*1000+500,coord[1]*1000+500,coord[2]*1000+500};
        NativeWorldCell *cell=begin+i;
        CHECK(func_800BDAD4(coord)==cell && func_800BDB9C(i)==cell && func_800BD948(cell)==i);
        CHECK(func_800BD97C(pos)==i && func_800BDBC4(pos)==cell);
        func_800BD860(cell,a);for(int j=0;j<3;++j) CHECK(a[j]==coord[j]);
        CHECK(func_800BE5C4(cell)==native_world_grid.model_counts+i);
    }
    CHECK(func_800BDB9C(-1)==func_800BDC44() && func_800BDB9C(120)==func_800BDC44());
    CHECK(func_800BD948(func_800BDC44())==-1 && func_800BD948(&unrelated)==-1 && func_800BD948((u8 *)begin+1)==-1);
    CHECK(func_800BE5C4(func_800BDC44())==&native_world_grid.fallback_models);
    s32 outside[3]={2,0,0};CHECK(func_800BDAD4(outside)==func_800BDC44());
    s32 negative[3]={-1000,100,100};s32 exact[3]={-2,0,0};
    CHECK(func_800BDBC4(negative)==func_800BDAD4(exact));
    f32 fractional[3]={-0.5f,100,100};s32 zero[3]={0,0,0};
    CHECK(func_800BDBEC(fractional)==func_800BDAD4(zero));
    func_800BD64C(a,fractional);CHECK(a[0]==-1 && a[1]==0 && a[2]==0);
    f32 clamped[3]={-0.1f,-1000,100000};func_800BD64C(a,clamped);CHECK(a[0]==-1 && a[1]==-1 && a[2]==2);
    f32 p[3]={-3000,500,4000},q[3]={1500,-500,-1500};
    func_800BD708(a,b,p,q,100);CHECK(a[0]==-2 && a[1]==-1 && a[2]==-2 && b[0]==1 && b[1]==0 && b[2]==2);
}
static int reference(int *out,s32 *position,u8 *present) {
    int origin[3],count=0,interior=1,keys[27];
    for(int i=0;i<3;++i) {
        origin[i]=(s32)((f32)position[i]*0.001f-native_world_grid.lower[i]);
        if(origin[i]<=0 || origin[i]>=native_world_grid.dimensions[i]-1) interior=0;
    }
    for(int id=0;id<120;++id) {
        int xyz[3]={id%4,(id/4)%5,id/20};
        if(!present[id]) continue;
        if(abs(xyz[0]-origin[0])>1 || abs(xyz[1]-origin[1])>1 || abs(xyz[2]-origin[2])>1) continue;
        int key=interior ? id : (xyz[0]*5+xyz[1])*6+xyz[2],slot=count;
        while(slot>0 && keys[slot-1]>key) { keys[slot]=keys[slot-1];out[slot]=out[slot-1];--slot; }
        keys[slot]=key;out[slot]=id;++count;
    }
    return count;
}
static void check_neighbors(s32 *position,int fallback) {
    int expected[27],count=reference(expected,position,models);
    NativeWorldCell **found=func_800BDD24(position), *out[28];
    for(int i=0;i<count;++i) CHECK(found[i]==native_world_grid.cells+expected[i]);CHECK(!found[count]);
    count=reference(expected,position,dynamic);out[27]=&native_world_grid.fallback;
    CHECK(func_800BE09C(out,position)==count && out[27]==&native_world_grid.fallback);
    for(int i=0;i<count;++i) CHECK(out[i]==native_world_grid.cells+expected[i]);
    f32 point[3]={position[0],position[1],position[2]};found=func_800BE3F8(point);
    for(int i=0;i<count;++i) CHECK(found[i]==out[i]);CHECK(!found[count]);
    found=func_800BE444(point);for(int i=0;i<count;++i) CHECK(found[i]==out[i]);
    if(fallback) CHECK(found[count++]==func_800BDC44());CHECK(!found[count]);
}
static void test_neighbors(void) {
    for(int i=0;i<120;++i) {
        *func_800E9A24(native_world_grid.cells+i)=(Prop){0};models[i]=1;
        *func_800E9804(native_world_grid.cells+i)=(NativeMarkerProp){0};dynamic[i]=1;
    }
    s32 interior[3]={-500,1500,-500};check_neighbors(interior,0);
    *func_800E9804(func_800BDC44())=(NativeMarkerProp){0};check_neighbors(interior,1);
    for(int pass=0;pass<2;++pass) {
        for(int x=-4;x<=3;++x) for(int y=-3;y<=5;++y) for(int z=-5;z<=4;++z) {
            s32 pos[3]={x*1000+500,y*1000+500,z*1000+500};check_neighbors(pos,1);
        }
        if(!pass) for(int i=0;i<120;++i) {
            NativeWorldCell *cell=native_world_grid.cells+i;
            if(i%3==0) { func_800E9C44(cell);models[i]=dynamic[i]=0; }
            else if(i%5==0) { func_800E9B74(cell,func_800E9D68(cell));models[i]=0; }
            else if(i%7==0) { func_800E9AC0(cell,func_800E9E88(cell));dynamic[i]=0; }
        }
    }
}
static void test_marker_repair(void) {
    s32 pos[3]={500,500,500};
    Unk80132ED0 *a=func_800EBED4(pos,1,7,0), *b=func_800EBED4(pos,0,8,1);
    CHECK(a && b);NativeMarkerProp *pa=(void *)a->unk0,*pb=(void *)b->unk0;
    a->unk0=b->unk0=NULL;func_800BE4C4();CHECK(a->unk0==(u32 *)pa && b->unk0==(u32 *)pb);
    func_800D2CD0();CHECK(func_800D2E90(0));
    func_800BD600();CHECK(func_800D2E90(0) && ((NativeMarkerProp *)a->unk0)->marker==a && ((NativeMarkerProp *)b->unk0)->marker==b);
    func_800D2E4C();
    func_800EBFF4(a);func_800EBFF4(b);
}
static void test_wrappers(void) {
    render_mode=0;func_800BD594(19);render_mode=1;func_800BD594(23);
    CHECK(used==2 && trace[0]==7 && trace[1]==8);
}
int main(void) {
    setup();test_coordinates();test_neighbors();test_marker_repair();test_wrappers();
    for(int i=0;i<120;++i) func_800E9C44(native_world_grid.cells+i);
    func_800E9C44(func_800BDC44());func_800E9774();
    heap_free(native_world_grid.cells);heap_free(native_world_grid.model_counts);native_world_grid=(NativeWorldGrid){0};
    s32 pos[3]={0};NativeWorldCell *begin,*end;
    CHECK(func_800BD97C(pos)==-1 && func_800BDBC4(pos)==func_800BDC44() && !*func_800BDD24(pos));
    func_800BE52C(&begin,&end);CHECK(!begin && !end);func_800BE4C4();
    puts("Native world grid: coordinates, ordered neighbors, fallback cells, marker repair and wrappers passed");return 0;
}
