#include "native_actor_model.h"
#include "native_skinning.h"
#include "native_actor_animation.h"
#include "core2/1EDA900.h"
#include "native_custom_hits.h"
#include "native_assets.h"
#include "core2/1EAF950.h"

void func_80104504(Actor *),func_80104460(Actor *);
void _subaddiefade_entrypoint_9(Actor *,s32 *);
s16 func_800D88F8(void);
void func_800ADFE0(s16),func_800D8954(s16),func_800DBFD8(void *);
void *func_800DBFF8(void);

void func_800DF7F8(s32,f32,f32),func_800EE940(s16 *,f32 *);
void func_800EE7F8(f32 *,f32 *),func_800EE88C(f32 *,s16 *),func_800EE84C(f32 *,s32 *);
void func_800EF04C(f32 *,f32 *),func_800EF334(f32 *,f32);

s32 func_80103140(Actor *actor,u32 id,u16 palette) {
    Unk80132ED0 *marker=actor->unk0;u16 previous=marker->unk14,new_id=id;
    if(new_id==previous && palette==marker->unk16)return previous;
    s32 active=actor->flags70&8;
    func_8010381C(actor);func_80103938(actor);
    actor->flags74&=~0x80000000u;marker->collision=NULL;
    actor->pad68=0;actor->horizontal_radius=0;marker->unk18&=0x001FFFFFu;
    if(actor->animation_handle)func_80104328(actor);
    s32 type=func_800D58FC(new_id);
    marker->unk14=new_id;marker->unk16=palette;
    NativeMarkerProp *prop=(void *)marker->unk0;
    prop->flags=(prop->flags&~2u)|(!type ? 2 : 0);
    if(!type)func_80103328(actor);
    func_80103930(actor);
    if(active && !(actor->flags70&8) && !type) {func_801039E4(marker);func_800D62E4(marker->unk14);}
    return previous;
}
s32 func_801032B0(Actor *actor,u16 id,u16 palette) {
    s16 saved=actor->animation_handle;actor->animation_handle=0;
    s32 previous=func_80103140(actor,id,palette);
    if(actor->animation_handle)func_80104328(actor);
    actor->animation_handle=saved;return previous;
}
void func_80103328(Actor *actor) {
    if(actor->center_radius)return;
    void *model=func_80103964(actor->unk0);if(!model)return;
    func_800D62E4(actor->unk0->unk14);
    NativeVertexList *list=func_800B2840(model);
    actor->center_radius=list->center_radius;actor->model_radius=list->radius;
    actor->horizontal_radius=func_800B2248(list);
    s32 minimum[3],maximum[3];f32 center[3],radius;
    func_800B2198(list,minimum,maximum);actor->model_y_min=minimum[1];actor->model_y_max=maximum[1];
    func_800B237C(list,center,&radius);func_800EE940(actor->unk0->model_center,center);
    actor->unk0->unk18=(actor->unk0->unk18&0x1FFFFF)|(((u32)radius&0x7FF)<<21);
}
BtIntPtr func_8010347C(Unk80132ED0 *marker) {
    Actor *actor=func_80106790(marker);func_80103328(actor);
    func_800DF7F8(marker->unk14,actor->center_radius,actor->model_radius);return 0;
}
void func_80103508(Actor *actor) {
    if(actor->flags70&8)return;
    Unk80132ED0 *marker=actor->unk0;ActorData *settings=func_80100368(actor);
    void *model=func_801039A4(marker);
    if(!model) {
        model=func_801039E4(marker);
        /* Missing assets cannot initialize model-backed resources. */
        if(!model)return;
    }
    func_80103328(actor);
    void *palette=marker->unk16 ? (void *)func_800D674C(marker->unk16) : NULL;
    s32 packed=(actor->flags7A&0xC0)!=0,buffers=(actor->flags70&(1u<<24)) ? 2 : ((actor->flags70&(1u<<21)) ? 1 : 0);
    if((packed || buffers) && !actor->vertex_handle) {
        s32 color[3];s32 fade=(actor->pad94&0x8000)!=0;
        if(fade)_subaddiefade_entrypoint_9(actor,color);
        actor->vertex_handle=func_80100D24(model,marker->unk14,buffers,packed,marker->unk16,fade ? color : NULL);
    }
    if(palette && buffers>=2)func_800B25D8(func_80103D24(actor),func_800B2840(model),palette);
    if(palette) {
        func_800B25D8(func_80103C94(actor),func_800B2840(model),palette);
        func_800D6CEC(marker->unk16);
    }
    if(!marker->unk4 && func_80102FA0(settings,0x40))marker->unk4=func_800DBFF8();
    if(!((s16 *)&actor->pad90)[0] && func_80102FA0(settings,0x1000))func_80105DFC(actor);
    if(!(marker->unk10>>16) && func_80102FA0(settings,0x20))marker->unk10=(marker->unk10&0xFFFF)|((u32)(u16)func_800AE020()<<16);
    if(!actor->attachment_handle && func_80102FA0(settings,0x4000))actor->attachment_handle=func_800D88F8();
    if(!actor->animation_handle && (actor->flags74&(1u<<23)))func_80102424(actor,actor->unk70_10);
    if(!actor->expression_handle && func_80102FA0(settings,0x40000))func_80104460(actor);
    actor->flags70|=8;func_8010108C(actor,0x29,(uintptr_t)model);
}
void func_8010381C(Actor *actor) {
    if(!(actor->flags70&8))return;
    Unk80132ED0 *marker=actor->unk0;
    if(actor->vertex_handle){func_80100E18(actor->vertex_handle);actor->vertex_handle=0;}
    if(marker->unk4){func_800DBFD8(marker->unk4);marker->unk4=NULL;}
    if(((s16 *)&actor->pad90)[0])func_80106138(actor);
    if(marker->unk10>>16){func_800ADFE0((s16)(marker->unk10>>16));marker->unk10&=0xFFFF;}
    if(actor->attachment_handle){func_800D8954(actor->attachment_handle);actor->attachment_handle=0;}
    if((actor->flags74&(1u<<23)) && actor->animation_handle)func_80104328(actor);
    if(actor->expression_handle)func_80104504(actor);
    actor->flags70&=~8u;func_8010108C(actor,0x2A,0);
}
void func_80103930(void *actor) { }
void func_80103938(Actor *actor) {if(actor->expression_handle)func_80104504(actor);}
void *func_80103964(Unk80132ED0 *marker) {
    return !marker->unk14 || marker->unk14==0xFFFF ? NULL : (void *)func_800D674C(marker->unk14);
}
void *func_801039A4(Unk80132ED0 *marker) {
    return !marker->unk14 || marker->unk14==0xFFFF ? NULL : func_800D6B0C(marker->unk14);
}
void *func_801039E4(void *data) {
    Unk80132ED0 *marker=data;u8 *model=func_80103964(marker);if(!model)return NULL;
    Actor *actor=func_80106790(marker);func_80103D48(actor);func_80103508(actor);
    if(!(actor->flags74&0x80000000u) && !marker->collision) {
        if((((NativeMarkerProp *)marker->unk0)->flags&2) && func_800B2824(model))
            _subaddiecustomhits_entrypoint_0(actor,_subaddiecustomhits_entrypoint_1);
        actor->flags74|=0x80000000u;
    }
    func_80103D70(actor);return model;
}
void *func_80103AA0(Unk80132ED0 *marker) {return func_801039A4(marker);}
s32 func_80103AC0(Actor *actor) {return func_800D6C34(actor->unk0->unk14);}
void *func_80103AE4(Unk80132ED0 *marker) {return func_80103964(marker);}
void *func_80103B24(Actor *actor,s32 back,void *model) {
    if(!model)return NULL;
    if((actor->flags70&(1u<<24)) && actor->vertex_handle)return func_80100A74(actor->vertex_handle,((actor->flags70>>23)&1)^back);
    if((actor->flags70&(1u<<21)) && actor->vertex_handle)return func_80100A74(actor->vertex_handle,0);
    return func_800B2840(model);
}
void *func_80103BBC(Actor *actor) {return func_80103B24(actor,0,func_801039A4(actor->unk0));}
void *func_80103BF0(Actor *actor,u32 back,void *model) {
    if(!model)model=func_80103964(actor->unk0);
    if(!model)return NULL;
    if(actor->flags70&(1u<<24))return func_80100A74(actor->vertex_handle,((actor->flags70>>23)&1)^back);
    if(actor->flags70&(1u<<21))return func_80100A74(actor->vertex_handle,0);
    return func_800B2840(model);
}
void *func_80103C94(Actor *actor) {return func_80103BF0(actor,0,NULL);}
void *func_80103CB8(Actor *actor,void *model) {return func_80103BF0(actor,0,model);}
void *func_80103CDC(Actor *actor,void *model) {return func_80103B24(actor,0,model);}
void *func_80103D00(Actor *actor,void *model) {return func_80103B24(actor,1,model);}
void *func_80103D24(Actor *actor) {return func_80103BF0(actor,1,NULL);}
void func_80103D48(Actor *actor) {func_800D70F8(actor->unk0->unk14,1);}
s32 func_80103D70(Actor *actor) {return func_800D70F8(actor->unk0->unk14,0);}
void *func_80103D98(Unk80132ED0 *marker) {
    if(!func_800AE0E8((s16)(marker->unk10>>16)))return NULL;
    u8 *model=func_801039A4(marker);if(!model)return NULL;
    func_800D62E4(marker->unk14);return func_800B2824(model);
}
void func_80103DFC(Actor *actor,f32 *center) {
    if(actor->unk0->unk14==0xFFFF){func_800EE7F8(center,actor->position);return;}
    func_80103328(actor);func_800EE7F8(center,actor->position);
    center[1]+=actor->scale*((f32)actor->model_y_min+(f32)(actor->model_y_max-actor->model_y_min)*0.5f);
}
f32 func_80103EAC(Actor *actor) {func_80103328(actor);return actor->scale*(u16)actor->horizontal_radius;}
f32 func_80103EF4(Actor *actor) {func_80103328(actor);return (f32)(actor->model_y_max-actor->model_y_min)*actor->scale;}
f32 func_80103F38(Actor *actor,f32 *center) {
    func_80103328(actor);
    if(center){func_800EE88C(center,actor->unk0->model_center);func_800EF334(center,actor->scale);func_800EF04C(center,actor->position);}
    return actor->center_radius*actor->scale;
}
f32 func_80103FB8(Actor *actor) {func_80103328(actor);return actor->model_radius*actor->scale;}
s32 func_80104004(Actor *actor,f32 *minimum,f32 *maximum) {
    void *model=func_801039E4(actor->unk0);if(!model)return 0;
    func_800D62E4(actor->unk0->unk14);s32 low[3],high[3];
    func_800B2198(func_800B2840(model),low,high);
    func_800EE84C(minimum,low);func_800EE84C(maximum,high);
    func_800EF334(minimum,actor->scale);func_800EF334(maximum,actor->scale);return 1;
}
void *func_801040A8(Actor *actor) {return func_800AE080((s16)(actor->unk0->unk10>>16));}
