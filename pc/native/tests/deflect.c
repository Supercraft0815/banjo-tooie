#include "native_world_grid.h"
#include <stdlib.h>
static NativeWorldCell cell;
static NativeWorldCell *cells[2] = {&cell, NULL};
static NativeMarkerProp props[4];
static Unk80132ED0 markers[2];
static Actor actors[2];
static int hits, players, grid_calls, visited, enabled = 1;
static void check(int ok) { if (!ok) abort(); }
NativeWorldCell **func_800BE3F8(f32 *center) { check(center && center[0] == 0); grid_calls++; return cells; }
NativeMarkerProp *func_800E9E88(NativeWorldCell *c) { check(c == &cell); return props; }
NativeMarkerProp *func_800E9EB4(NativeWorldCell *c) { check(c == &cell); return props+4; }
s32 sueggmisc_entrypoint_0(Unk80132ED0 *marker) { return marker == &markers[0]; }
Actor *func_80106790(Unk80132ED0 *m) { check(m == &markers[0] || m == &markers[1]); return actors+(m-markers); }
s32 func_8010108C(Actor *actor, s32 command, s32 arg) {
    check(command == 5 && ((actor == &actors[0] && arg == 0) || (actor == &actors[1] && arg == -1)));
    hits++; return 1;
}
void func_800EE7F8(f32 *dst, f32 *src) { __builtin_memcpy(dst,src,3*sizeof(f32)); }
s32 func_800F0008(f32 *a,f32 ar,f32 *b,f32 br) { return ar>=0 && br>0 && a && b; }
int func_800F0064(f32 *a,f32 r,f32 *b) { return a && b && r>0; }
s32 func_800F6438(BtUIntPtr id) { check(id < 8); return enabled; }
s32 func_800F4F34(BtUIntPtr id,f32 *p,f32 lo,f32 hi) { check(id<8 && p);return 1; }
s32 func_800F4EC8(BtUIntPtr id,BtIntPtr p,f32 a,f32 b,f32 c) { check(id<8 && p);return 1; }
s32 func_800F4D18(BtIntPtr id,f32 *a,f32 *b) { check(id>=0 && id<8 && a && b);return 1; }
s32 func_800F4E5C(s32 id,BtIntPtr a,BtIntPtr b,BtIntPtr c,BtIntPtr d) { return a==1 && b==2 && c==3 && d==4; }
int func_800F6720(BtIntPtr id) { check(id==visited++);return 1; }
s32 func_800F5410(BtIntPtr id) { abort(); }
s32 func_800F52B8(BtIntPtr id, Unk80132ED0 *marker) { abort(); }
int func_800F7700(BtIntPtr id,s32 mode,f32 *p) { check(id==players++ && mode==17 && p);return 1; }
void func_800A52E0(f32 *p,f32 a,f32 b) { abort(); }
void func_800A5298(f32 *p,f32 a,f32 b,f32 c) { abort(); }
s32 sudeflect_entrypoint_0(f32 *,f32,f32,s32);
s32 sudeflect_entrypoint_1(f32 *,f32,f32,f32,s32);
s32 sudeflect_entrypoint_2(f32 *,f32 *,s32);
s32 sudeflect_entrypoint_3(BtIntPtr,BtIntPtr,BtIntPtr,BtIntPtr,s32);
void sudeflect_entrypoint_4(s32,f32 *);
int main(void) {
    f32 origin[3]={0}, low[3]={-12,-12,-12}, high[3]={12,12,12};
    if(sizeof(void *)>4) check((uintptr_t)cells>UINT32_MAX && (uintptr_t)props>UINT32_MAX);
    markers[1].unk24 = 0x27Au<<22;
    props[1].marker = &markers[0]; props[1].flags=1;
    props[2].marker = &markers[1]; props[2].flags=1;
    check(sudeflect_entrypoint_0(origin,0,10,0x1A)==0x1A);
    check(sudeflect_entrypoint_1(origin,0,-10,10,0x1A)==0x1A);
    check(sudeflect_entrypoint_2(low,high,0x1A)==0x1A);
    check(hits==6 && grid_calls==3);
    check(sudeflect_entrypoint_3(1,2,3,4,2)==2);
    sudeflect_entrypoint_4(17,origin);
    check(visited==8 && players==8);
    enabled=0; actors[1].unk64_17=1;
    check(sudeflect_entrypoint_0(origin,0,10,0x1A)==8 && hits==7);
    sudeflect_entrypoint_4(17,origin);
    check(visited==8 && players==8);
}
