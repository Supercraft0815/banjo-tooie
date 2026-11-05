#include "native_geometry.h"
#include "native_vector_table.h"
#include "native_zones.h"
#include <limits.h>
void func_800193C4(f32 *,f32 *);
void func_80019224(f32 *,f32 *);
void func_80019AA0(MtxF *,MtxF *);
void func_800F23D0(MtxF *,f32 *,f32 *);
s32 func_800CAA24(f32 *,f32 *,f32 *);
s32 func_800CACEC(f32 *,f32 *,f32);
extern MtxF D_8007B4F0[31],*s_mtx_stack;
typedef struct {NativeGeometryContext *out;const u8 *start;u32 size;} GeometryRun;
static s16 geo_half(const u8 *p) {return *(const s16 *)p;}
static u32 geo_word(const u8 *p) {return *(const u32 *)p;}
static int geo_walk(GeometryRun *,const u8 *,unsigned);

static u32 geo_record(GeometryRun *run,const u8 *p,u32 op) {
    static const u8 minimum[]={24,40,12,12,8,12,12,12,32,8,24,8,12,24,20,16,12,16,48,8,8,12,12,16,48};
    u32 remaining=run->size-(u32)(p-run->start);
    if(op>=25 || remaining<minimum[op])return 0;
    u32 size=minimum[op];
    if(op==5 || op==22) {
        size=10;do {if(remaining-size<2)return 0;size+=2;}while(geo_half(p+size-2));
    } else if(op==12 || op==21) {
        s32 count=geo_half(p+8);if(count<0 || (u32)count>(remaining-12)/4)return 0;size=12+count*4;
    } else if(op==15)size=13+p[10];
    return size<=remaining ? size : 0;
}
static int geo_branch(GeometryRun *run,const u8 *p,u32 extent,s32 offset,unsigned depth) {
    if(!offset)return 1;
    if(offset<0 || (u32)offset<extent || (offset&3) || (u32)offset>run->size-(p-run->start)-8)return 0;
    return geo_walk(run,p+offset,depth+1);
}
static int geo_emit(NativeGeometryContext *out,u32 first,u32 second) {
    if(out->gfx==out->gfx_end)return 0;
    out->gfx->words.w0=first;out->gfx->words.w1=second;++out->gfx;return 1;
}
static int geo_display(NativeGeometryContext *out,s32 index) {
    NativeDisplayList *list=native_render.data.display_list;
    if(!list || index<0 || (u32)index>=list->header[0])return 0;
    u32 address=native_graphics_address(out->memory,&list->commands[index],sizeof(Gfx));
    return address && geo_emit(out,0xDE000000,address);
}
static u32 geo_matrix(NativeGeometryContext *out) {
    if(out->mtx==out->mtx_end)return 0;
    u32 address=native_graphics_address(out->memory,out->mtx,sizeof(Mtx));
    if(address)mlMtxApply(out->mtx++);
    return address;
}
static int geo_bone(NativeGeometryContext *out,s32 index) {
    MtxF *bone=func_800ADE2C(native_render.data.animation,index);
    if(!bone || s_mtx_stack>=D_8007B4F0+30)return 0;
    func_80019AA0(&out->base,bone);return 1;
}
static void geo_position(f32 *out,const f32 *in) {
    if(!native_render.geometry_mode)func_800193C4(out,(f32 *)in);
    else for(int i=0;i<3;++i)out[i]=in[i]*native_render.data.scale+(native_render.geometry_mode==2 ? native_render.data.position[i] : 0);
}
static int geo_box(NativeGeometryContext *out,f32 *low,f32 *high) {
    if(func_800CAA24(out->camera,low,high))return 1;
    if(!out->reflection)return 0;
    f32 a[3],b[3];func_800F23D0(out->reflection,a,low);func_800F23D0(out->reflection,b,high);
    for(int i=0;i<3;++i)if(b[i]<a[i]){f32 swap=a[i];a[i]=b[i];b[i]=swap;}
    return func_800CAA24(out->camera,a,b);
}
static int geo_sphere(NativeGeometryContext *out,f32 *center,f32 radius) {
    if(func_800CACEC(out->camera,center,radius))return 1;
    if(!out->reflection)return 0;
    f32 reflected[3];func_800F23D0(out->reflection,reflected,center);
    return func_800CACEC(out->camera,reflected,radius);
}
static int geo_billboard(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    s32 branch=geo_half(p+8);if(!branch)return 1;
    if(s_mtx_stack>=D_8007B4F0+30)return 0;
    NativeGeometryContext *out=run->out;f32 position[3];geo_position(position,(const f32 *)(p+12));
    mlMtx_push_translation(position[0],position[1],position[2]);mlMtxRotYaw(out->camera[7]);
    if(!geo_half(p+10))mlMtxRotPitch(out->camera[6]);
    mlMtxScale(native_render.data.scale);mlMtxTranslate(-((const f32 *)p)[3],-((const f32 *)p)[4],-((const f32 *)p)[5]);
    u32 matrix=geo_matrix(out);int result=matrix && geo_emit(out,0xDA380002,matrix) && geo_branch(run,p,extent,branch,depth);
    mlMtxPop();return result && geo_emit(out,0xD8380002,64);
}
static int geo_order(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    f32 a[3],b[3];int pushed=!native_render.geometry_mode && (p[33]&2);
    if(pushed && !geo_bone(run->out,(s8)p[32]))return 0;
    geo_position(a,(const f32 *)(p+8));geo_position(b,(const f32 *)(p+20));if(pushed)mlMtxPop();
    f32 delta[3];for(int i=0;i<3;++i){delta[i]=b[i]-a[i];a[i]-=run->out->camera[i];}
    f32 side=-(delta[0]*a[0]+delta[1]*a[1]+delta[2]*a[2]);
    s32 back=geo_half(p+34),front=(s32)geo_word(p+36);
    if(p[33]&1)return geo_branch(run,p,extent,side>=0 ? front : back,depth);
    return geo_branch(run,p,extent,side>=0 ? back : front,depth) && geo_branch(run,p,extent,side>=0 ? front : back,depth);
}
static int geo_bone_draw(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    int pushed=native_render.data.animation!=NULL,result=1;NativeGeometryContext *out=run->out;
    if(pushed) {
        if(!geo_bone(out,(s8)p[9]))return 0;
        u32 matrix=geo_matrix(out);result=matrix && geo_emit(out,0xDA380002,matrix);
    }
    if(result)result=geo_branch(run,p,extent,p[8],depth);
    if(pushed){mlMtxPop();result=result && geo_emit(out,0xD8380002,64);}
    return result;
}
static int geo_lod(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    s32 branch=(s32)geo_word(p+28);if(!branch)return 1;
    if(!native_render.geometry_mode && native_render.unknown_short[0]) {
        native_render.unknown_short[1]=(s16)((u16)native_render.unknown_short[1]+1);
        if(native_render.unknown_short[0]!=native_render.unknown_short[1])return 1;
    } else {
        f32 position[3],delta[3];geo_position(position,(const f32 *)(p+16));
        for(int i=0;i<3;++i)delta[i]=position[i]-run->out->camera[i];
        f32 distance=delta[0]*delta[0]+delta[1]*delta[1]+delta[2]*delta[2];
        f32 maximum=*(const f32 *)(p+8),minimum=*(const f32 *)(p+12);
        if(!(minimum*minimum<distance && distance<=maximum*maximum))return 1;
    }
    return geo_branch(run,p,extent,branch,depth);
}
static int geo_attachment(NativeGeometryContext *out,const u8 *p) {
    if(!native_render.attachments)return 1;
    int pushed=!native_render.geometry_mode && native_render.data.animation;
    if(pushed && !geo_bone(out,geo_half(p+10)))return 0;
    f32 point[3];geo_position(point,(const f32 *)(p+12));if(pushed)mlMtxPop();
    func_800DC028(native_render.attachments,geo_half(p+8),point);return 1;
}
static int geo_select(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    s32 index=geo_half(p+10),count=geo_half(p+8);if(index<0 || index>=60)return 0;
    s32 selection=native_render.switches[index];if(!index || !selection)return 1;
    if(selection>0)return selection>count || geo_branch(run,p,extent,(s32)geo_word(p+12+(selection-1)*4),depth);
    u32 mask=0u-(u32)selection;
    for(int i=0;i<count;++i) {
        if((mask&1) && !geo_branch(run,p,extent,(s32)geo_word(p+12+i*4),depth))return 0;
        mask=(mask>>1)|(mask&0x80000000u);
    }
    return 1;
}
static int geo_bounds(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    s32 branch=geo_half(p+20);if(!branch)return 1;
    f32 low[3],high[3];
    for(int i=0;i<3;++i) {
        f32 translation=native_render.geometry_mode==2 ? native_render.data.position[i] : 0;
        low[i]=geo_half(p+8+i*2)*native_render.data.scale+translation;
        high[i]=geo_half(p+14+i*2)*native_render.data.scale+translation;
    }
    return !geo_box(run->out,low,high) || geo_branch(run,p,extent,branch,depth);
}
static int geo_radius(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    f32 position[3];for(int i=0;i<3;++i)position[i]=geo_half(p+8+i*2);
    s32 bone=geo_half(p+18);f32 radius=geo_half(p+14)*native_render.data.scale;
    if(!native_render.geometry_mode && bone!=-1) {
        int pushed=native_render.data.animation!=NULL;
        if(pushed && !geo_bone(run->out,bone))return 0;
        func_80019224(position,position);if(pushed)mlMtxPop();
    } else for(int i=0;i<3;++i)position[i]=position[i]*native_render.data.scale+(native_render.geometry_mode==2 ? native_render.data.position[i] : 0);
    return !geo_sphere(run->out,position,radius) || geo_branch(run,p,extent,geo_half(p+16),depth);
}
static int geo_zone(GeometryRun *run,const u8 *p,u32 extent,unsigned depth) {
    if(!native_render.data.zones)return 0;
    int contains=dbzone_entrypoint_0(native_render.data.zones,(u8 *)p+13,p[10]);
    if((!contains && (p[11]&1)) || (contains && (p[11]&2))) {
        u8 *marks=native_render.zone_override;
        if(marks && p[12]) {if(p[12]>*marks)return 0;glzone_entrypoint_3((s8 *)marks,p[12]);}
        return geo_branch(run,p,extent,geo_half(p+8),depth);
    }
    return 1;
}
static int geo_vertices(NativeGeometryContext *out,MtxF *matrix,s32 *texture_start,s32 *light_start,s32 count,s32 flags) {
    if(count<0)return 0;
    NativeVertexList *vertices=native_render.data.vertices;
    if((flags&1) || out->vertex_callback) {
        if(!vertices)return 0;u32 total=func_800B2344(vertices);
        if((flags&1) && (*texture_start<0 || (u32)*texture_start>total || (u32)count>total-(u32)*texture_start || !native_render.data.normals))return 0;
        if(out->vertex_callback && (*light_start<0 || (u32)*light_start>total || (u32)count>total-(u32)*light_start))return 0;
    }
    if((flags&1) && !native_texture_projection_apply(&native_render.data,&matrix->m[0][0],texture_start,count))return 0;
    if(out->vertex_callback)out->vertex_callback(&matrix->m[0][0],light_start,count);
    return 1;
}
static int geo_vertex_pair(NativeGeometryContext *out,s32 *texture_start,s32 *light_start,s32 current,s32 previous,s32 flags) {
    if(current && !geo_vertices(out,s_mtx_stack,texture_start,light_start,current,flags))return 0;
    if(previous && (s_mtx_stack==D_8007B4F0 || !geo_vertices(out,s_mtx_stack-1,texture_start,light_start,previous,flags)))return 0;
    return 1;
}
static int geo_draws(NativeGeometryContext *out,const u8 *p,u32 op,u32 extent) {
    int after=op==22 || op==24,lit=op==18 || op==24;
    s32 start=lit ? geo_half(p+44) : 0,texture_start=start;
    u32 count=1;
    while((8+(count+1)*2<=extent) && geo_half(p+8+count*2)) {if(lit && count>=5)return 0;++count;}
    u32 matrix=0;
    if(after || lit){matrix=geo_matrix(out);if(!matrix)return 0;}
    for(u32 i=0;i<count;++i) {
        if(lit && !geo_vertex_pair(out,&texture_start,&start,geo_half(p+32+i*2),geo_half(p+20+i*2),geo_half(p+46)))return 0;
        if(i && !after && !geo_emit(out,0xDA380002,matrix))return 0;
        if(!geo_display(out,geo_half(p+8+i*2)))return 0;
        if(after && !geo_emit(out,0xDA380002,matrix))return 0;
        if(!lit && !after && !i){matrix=geo_matrix(out);if(!matrix)return 0;}
    }
    return 1;
}
static int geo_skin_vertices(NativeGeometryContext *out,const u8 *p) {
    if(!out->vertex_callback)return 1;
    s32 start=geo_half(p+10),unused=0,count=geo_half(p+8);
    for(int i=0;i<count;++i) {
        if(!geo_bone(out,geo_half(p+12+i*4)))return 0;
        int result=geo_vertices(out,s_mtx_stack,&unused,&start,geo_half(p+14+i*4),0);mlMtxPop();if(!result)return 0;
    }
    return 1;
}
static int geo_command(GeometryRun *run,const u8 *p,u32 op,u32 extent,unsigned depth) {
    NativeGeometryContext *out=run->out;
    /* These entries are no-ops in the original three dispatcher tables. */
    if(op==4 || op==9 || op==11 || op==19 || op==20)return 1;
    if(native_render.geometry_mode && (op==2 || op==5 || op>=18))return 1;
    if(native_render.geometry_mode==2 && op==15)return 1;
    switch(op) {
        case 0:return geo_billboard(run,p,extent,depth);
        case 1:return geo_order(run,p,extent,depth);
        case 2:return geo_bone_draw(run,p,extent,depth);
        case 3:return geo_display(out,geo_half(p+8));
        case 5:case 18:case 22:case 24:return geo_draws(out,p,op,extent);
        case 6:return geo_word(p+8) && geo_branch(run,p,extent,(s32)geo_word(p+8),depth);
        case 7:return geo_display(out,geo_half(p+10));
        case 8:return geo_lod(run,p,extent,depth);
        case 10:return geo_attachment(out,p);
        case 12:return geo_select(run,p,extent,depth);
        case 13:return geo_bounds(run,p,extent,depth);
        case 14:return geo_radius(run,p,extent,depth);
        case 15:return geo_zone(run,p,extent,depth);
        case 16: {
            u32 mode=geo_word(p+8);if(mode!=1 && mode!=2)return 1;
            u32 index=mode==1 ? 13 : 0;if(!out->mode_list || index>=out->mode_count)return 0;
            u32 address=native_graphics_address(out->memory,out->mode_list+index,sizeof(Gfx));
            return address && geo_emit(out,0xDE000000,address);
        }
        case 17: {
            s32 start=geo_half(p+10),texture_start=start;
            return geo_vertices(out,s_mtx_stack,&texture_start,&start,geo_half(p+12),geo_half(p+14)) && geo_display(out,geo_half(p+8));
        }
        case 21:return geo_skin_vertices(out,p);
        case 23: {
            s32 start=geo_half(p+8),texture_start=start;
            return geo_vertex_pair(out,&texture_start,&start,geo_half(p+10),geo_half(p+12),geo_half(p+14));
        }
    }
    return 0;
}
static int geo_walk(GeometryRun *run,const u8 *p,unsigned depth) {
    if(depth>1024)return 0;
    for(;;) {
        if(!run->out->remaining_commands)return 0;--run->out->remaining_commands;
        u32 op=geo_word(p),extent=geo_record(run,p,op);if(!extent || !geo_command(run,p,op,extent,depth))return 0;
        u32 next=geo_word(p+4);if(!next)return 1;
        if(next<extent || (next&3) || next>run->size-(p-run->start)-8)return 0;
        p+=next;
    }
}
int native_geometry_execute(NativeGeometryContext *out,const u8 *commands,u32 size) {
    if(!out || !out->memory || !out->camera || !commands || (uintptr_t)commands%4 || size<8 || size>INT_MAX ||
       native_render.geometry_mode>2 || (native_render.geometry_mode==2 && !native_render.data.position) ||
       !out->gfx || !out->mtx || !out->gfx_end || !out->mtx_end || out->gfx>out->gfx_end || out->mtx>out->mtx_end ||
       !s_mtx_stack || s_mtx_stack<D_8007B4F0 || s_mtx_stack>D_8007B4F0+30)return 0;
    MtxF *saved=s_mtx_stack;GeometryRun run={out,commands,size};int result=geo_walk(&run,commands,0);
    s_mtx_stack=saved;return result;
}
