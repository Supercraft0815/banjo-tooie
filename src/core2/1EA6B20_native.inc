#include "native_actor.h"
#include "vector.h"
#include <math.h>
#include <limits.h>

f32 _subaddiecustomhits_entrypoint_5(Actor *,f32 *);
void func_800EE7F8(f32 *,f32 *),func_800EE88C(f32 *,s16 *);
f32 func_800EEB40(f32 *,f32 *),func_800EEAD4(f32 *,f32 *),func_800EEF94(f32 *);
void func_800EF04C(f32 *,f32 *),func_800EF334(f32 *,f32),func_800EF410(f32 *,f32 *);
void func_800EFA20(void *,void *,f32),func_800EFB24(void *,void *,void *);
void func_800EFE50(f32 *,f32 *,f32 *,f32);

typedef struct { void (*unused[4])(void); s32 (*test)(Unk80132ED0 *,Unk80132ED0 *); } MarkerHitCallbacks;
typedef struct { Unk80132ED0 *marker; s32 sphere; } MarkerHit;
static Vector *marker_hits;

static u32 marker_collision_mask(void) {
    s16 kind=func_800CB854(NULL);
    /* MIPS variable shifts mask the shift count to five bits. */
    return kind ? 1u<<(((u32)kind+31)&31) : 0;
}
static Actor *marker_hit_candidate(NativeMarkerProp *prop,Unk80132ED0 *self,u32 mask) {
    if((prop->flags&0x11)!=0x11) return NULL;
    Unk80132ED0 *marker=prop->marker;
    if(marker==self || !(marker->unk28&0x200) || !marker->unk14 || marker->unk14==0xFFFF || !(marker->unk18&0x10000)) return NULL;
    Actor *actor=func_80106790(marker);
    return actor && !actor->unk64_17 && !(actor->unk64_0&mask) ? actor : NULL;
}
static int marker_hit_allowed(Unk80132ED0 *marker,Unk80132ED0 *self) {
    MarkerHitCallbacks *callbacks=func_800EC3C4(marker);
    return !callbacks->test || callbacks->test(marker,self);
}

s32 func_800CD6B4(Unk80132ED0 *marker,f32 *start,f32 radius,f32 *step,s32 samples) {
    NativeMarkerCollision *custom=marker->collision ? marker->collision() : NULL;
    f32 point[3],contact[3],center[3];
    func_800EE7F8(point,start);
    for(s32 i=0;i<samples;++i) {
        if(custom && custom->test) {
            s32 result=custom->test(marker,point,radius,contact,(marker->unk18>>1)&15);
            if(result) {
                marker->unk18=(marker->unk18&~(15u<<17))|(((u32)result&15)<<17);
                return 1;
            }
        } else {
            f32 extent=func_800EC75C(marker,center)+radius;
            if(func_800EEB40(point,center)<extent*extent) return 1;
        }
        func_800EF04C(point,step);
    }
    return 0;
}

Unk80132ED0 *func_800CD820(Unk80132ED0 *self,f32 *start,f32 *end,f32 radius) {
    f32 delta[3],direction[3],step[3],offset[3],point[3],midpoint[3],center[3];
    if(!self || !(radius>0) || !isfinite(radius)) return NULL;
    u32 mask=marker_collision_mask();
    func_800EFB24(delta,end,start);
    f32 length=func_800EEF94(delta),reach=2.0f*radius,count=length/reach;
    if(!isfinite(count) || count>=(f32)INT_MAX) return NULL;
    func_800EF410(direction,delta);
    s32 samples=(s32)count+1;
    func_800EFE50(midpoint,start,end,0.5f);
    NativeWorldCell **cells=func_800BE444(midpoint);
    func_800EFA20(step,direction,reach);
    func_800EFA20(offset,step,(count-(f32)(samples-1))*0.5f);
    func_800EE88C(point,self->model_center);
    func_800EF04C(point,start);func_800EF04C(point,offset);
    Unk80132ED0 *nearest=NULL;f32 nearest_distance=0;
    for(;*cells;++cells) {
        NativeMarkerProp *prop=func_800E9E88(*cells),*limit=func_800E9EB4(*cells);
        for(;prop<limit;++prop) {
            Actor *actor=marker_hit_candidate(prop,self,mask);
            if(!actor) continue;
            f32 extent=_subaddiecustomhits_entrypoint_5(actor,center)+(f32)samples*radius*1.100000024f;
            if(extent*extent<func_800EEB40(center,midpoint)) continue;
            f32 distance=func_800EEB40(center,point);
            if(nearest && nearest_distance<distance) continue;
            if(marker_hit_allowed(prop->marker,self) && func_800CD6B4(prop->marker,point,radius,step,samples)) {
                nearest=prop->marker;nearest_distance=distance;
            }
        }
    }
    return nearest;
}

s32 func_800CDBA8(Unk80132ED0 *self,f32 *points,f32 *radii,s32 spheres) {
    if(marker_hits) vector_clear(marker_hits);
    if(spheres<=0) return 0;
    u32 mask=marker_collision_mask();f32 center[3],position[3],reach;
    func_800EE7F8(center,points);
    for(s32 i=1;i<spheres;++i) func_800EF04C(center,points+3*i);
    func_800EF334(center,1.0f/(f32)spheres);
    reach=func_800EEAD4(center,points)+radii[0];
    for(s32 i=1;i<spheres;++i) {
        f32 extent=func_800EEAD4(center,points+3*i)+radii[i];
        if(reach<extent) reach=extent;
    }
    reach*=1.100000024f;
    for(NativeWorldCell **cells=func_800BE444(center);*cells;++cells) {
        NativeMarkerProp *prop=func_800E9E88(*cells),*limit=func_800E9EB4(*cells);
        for(;prop<limit;++prop) {
            Actor *actor=marker_hit_candidate(prop,self,mask);
            if(!actor) continue;
            f32 extent=_subaddiecustomhits_entrypoint_5(actor,position)+reach;
            if(extent*extent<func_800EEB40(position,center) || !marker_hit_allowed(prop->marker,self)) continue;
            NativeMarkerCollision *custom=prop->marker->collision ? prop->marker->collision() : NULL;
            for(s32 i=0;i<spheres;++i) {
                s32 result;
                if(custom && custom->test) {
                    f32 contact[3];
                    result=custom->test(prop->marker,points+3*i,radii[i],contact,(prop->marker->unk18>>1)&15);
                    if(result) prop->marker->unk18=(prop->marker->unk18&~(15u<<17))|(((u32)result&15)<<17);
                } else {
                    extent=func_800EC75C(prop->marker,position)+radii[i];
                    result=func_800EEB40(points+3*i,position)<extent*extent;
                }
                if(result) {
                    /* The original 32-entry array can overflow in crowded cells. */
                    if(!marker_hits) marker_hits=vector_new(sizeof(MarkerHit),32);
                    MarkerHit *hit=vector_push_back(&marker_hits);
                    *hit=(MarkerHit){prop->marker,i};break;
                }
            }
        }
    }
    return marker_hits ? vector_size(marker_hits) : 0;
}

Unk80132ED0 *func_800CDFA8(s32 index,s32 *sphere) {
    if(!marker_hits || index<0 || index>=vector_size(marker_hits)) { if(sphere) *sphere=-1; return NULL; }
    MarkerHit *hit=(MarkerHit *)vector_begin(marker_hits)+index;
    if(sphere) *sphere=hit->sphere;
    return hit->marker;
}
