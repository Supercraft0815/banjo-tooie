#include "native_render.h"
void func_800DE318(void) {
    native_render.pose=NULL;native_render.distance=30000;native_render.cull=1;native_render.range_scale=1;
    native_render.fade=native_render.callback_mode=native_render.color_mode=0;
    native_render.attachments=NULL;native_render.zone_override=0;
    NativeRenderData *data=&native_render.data;
    data->display_list=NULL;data->animation=NULL;data->textures=NULL;data->texture_animation=0;
    data->vertices=NULL;data->zones=NULL;data->normals=NULL;data->animated_vertices=NULL;data->colors=NULL;data->matrices=NULL;
    native_render.before=native_render.after=NULL;native_render.transform_mode=0;native_render.asset_id=0;
    native_render.depth_mode=0;native_render.unknown_short[0]=native_render.unknown_short[1]=0;native_render.geometry_mode=0;
    func_800DF744(1,1);func_800DF744(2,0);
    for(int i=0;i<4;++i){native_render.prim[i]=0;native_render.env[i]=255;}
}
