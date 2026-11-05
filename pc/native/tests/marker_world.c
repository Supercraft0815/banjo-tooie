#include "marker_world.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
NativeWorldCell *marker_world[3];
int marker_world_updates;
static NativeWorldCell cells[2];
static u8 model_counts[2];
static int initialized;
void marker_world_cleanup(void) {
    if(!initialized) return;
    for(int i=0;i<3;++i) func_800E9C44(marker_world[i]);
    func_800E9774();native_world_grid=(NativeWorldGrid){0};initialized=0;
}
void marker_world_reset(void) {
    marker_world_cleanup();
    bzero(cells,sizeof(cells));bzero(model_counts,sizeof(model_counts));
    native_world_grid=(NativeWorldGrid){.cells=cells,.upper={1,0,0},.row_stride=2,.plane_stride=2,
        .count=2,.dimensions={2,1,1},.cell_size=1000,.scale=0.001f,.model_counts=model_counts};
    marker_world[0]=&native_world_grid.fallback;marker_world[1]=cells;marker_world[2]=cells+1;
    marker_world_updates=0;func_800E9728();initialized=1;
}
s32 func_800DC214(s32 min,s32 max) { CHECK(min==0 && max==32);return 17; }
f32 func_800DC0C0(void) { return 0.25f; }
void func_800CDFD0(void *marker) { CHECK(marker);++marker_world_updates; }
