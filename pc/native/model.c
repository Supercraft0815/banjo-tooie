#include "native_skinning.h"
#include "native_geometry.h"
#include "native_texture.h"
#include "memory.h"

static u16 model_be16(const u8 *p) {return (u16)p[0]<<8|p[1];}
static u32 model_be32(const u8 *p) {return (u32)model_be16(p)<<16|model_be16(p+2);}

static u32 model_section_end(const u8 *bytes,u32 size,u32 start) {
    u32 end=size;
    for(int field=4;field<=64;field+=4) {
        if(field==8)continue;
        u32 offset=model_be32(bytes+field);if(offset>start && offset<end)end=offset;
    }
    u32 texture=model_be16(bytes+8);if(texture>start && texture<end)end=texture;
    return end;
}

static u32 binding_extent(const u8 *bytes,u32 size,u32 vertices,s32 bones) {
    if(size<4)return 0;
    s32 groups=(s16)model_be16(bytes+2);u32 cursor=4;
    if(groups<0)return 0;
    for(s32 group=0;group<groups;++group) {
        if(size-cursor<6)return 0;
        s32 bone=(s16)model_be16(bytes+cursor),positions=(s16)model_be16(bytes+cursor+2),normals=(s16)model_be16(bytes+cursor+4);
        if(bone < -1 || bone>=bones || positions<0 || normals<0)return 0;
        cursor+=6;
        u32 payload=(u32)positions*6+(model_be16(bytes) ? (u32)normals*4 : 0);
        if(payload>size-cursor)return 0;cursor+=payload;
        s32 position=0,mapped=0,index;
        do {
            if(size-cursor<2)return 0;
            index=(s16)model_be16(bytes+cursor);cursor+=2;
            if(index==-1){if(++position>positions)return 0;}
            else if(index>=0) {
                if((u32)index>=vertices || position>=positions)return 0;
                ++mapped;
            }
        } while(index>=-1);
        if(model_be16(bytes) && mapped>normals)return 0;
    }
    return cursor;
}

static void decode_binding(u8 *bytes) {
    u32 groups=model_be16(bytes+2),cursor=4;int normals=model_be16(bytes)!=0;
    for(int i=0;i<4;i+=2){u16 value=model_be16(bytes+i);rare_memcpy(bytes+i,&value,2);}
    for(u32 group=0;group<groups;++group) {
        u32 positions=model_be16(bytes+cursor+2),normal_count=model_be16(bytes+cursor+4);
        u32 end=cursor+6+positions*6;
        for(;cursor<end;cursor+=2){u16 value=model_be16(bytes+cursor);rare_memcpy(bytes+cursor,&value,2);}
        if(normals)cursor+=normal_count*4;
        s16 index;
        do {index=(s16)model_be16(bytes+cursor);rare_memcpy(bytes+cursor,&index,2);cursor+=2;}while(index>=-1);
    }
}

static u32 collision_extent(const u8 *bytes,u32 size,u32 vertices) {
    if(size<24)return 0;
    u32 cells=model_be16(bytes+16),triangles=model_be16(bytes+20);
    s32 scale=(s16)model_be16(bytes+18);
    if(!cells || scale<0 || cells>(size-24)/4)return 0;
    u32 start=24+cells*4;
    if(triangles>(size-start)/12)return 0;
    if(scale) {
        u32 dimensions[3];
        for(int i=0;i<3;++i) {
            s32 a=(s16)model_be16(bytes+2*i),b=(s16)model_be16(bytes+6+2*i);
            if(a>b)return 0;dimensions[i]=b-a+1;
        }
        if(dimensions[0]>cells || dimensions[1]>cells/dimensions[0] ||
           dimensions[2]>cells/(dimensions[0]*dimensions[1]) ||
           dimensions[0]*dimensions[1]*dimensions[2]!=cells ||
           model_be16(bytes+12)!=dimensions[0] || model_be16(bytes+14)!=dimensions[0]*dimensions[1])return 0;
    }
    for(u32 i=0;i<cells;++i) {
        u32 first=model_be16(bytes+24+i*4),count=model_be16(bytes+26+i*4);
        if(first>triangles || count>triangles-first)return 0;
    }
    for(u32 i=0;i<triangles;++i)for(int j=0;j<3;++j)
        if(model_be16(bytes+start+i*12+j*2)>=vertices)return 0;
    return start+triangles*12;
}

int native_model_decode(void *model,s32 size) {
    u8 *bytes=model;
    u32 vertex,count,end,offset,collision,collision_end=0,binding,binding_end=0,skeleton,skeleton_end=0;
    if(!model || size<80 || (uintptr_t)model%8 || model_be32(bytes)!=11)return 0;
    vertex=model_be32(bytes+16);
    if(vertex<80 || vertex%8 || vertex>(u32)size || (u32)size-vertex<24)return 0;
    count=model_be16(bytes+vertex+22)>>1;
    if(count>((u32)size-vertex-24)/16)return 0;
    for(int i=0;i<3;++i)
        if((s16)model_be16(bytes+vertex+i*2)>(s16)model_be16(bytes+vertex+6+i*2))return 0;
    end=vertex+24+count*16;
    for(int i=4;i<=64;i+=4) {
        if(i==8 || i==16)continue;
        offset=model_be32(bytes+i);
        if(offset && (offset<80 || offset>=(u32)size || (offset>=vertex && offset<end)))return 0;
    }
    offset=model_be16(bytes+8);
    if(offset && (offset<80 || offset>32767 || offset>=(u32)size || (offset>=vertex && offset<end)))return 0;
    offset=model_be32(bytes+44);
    if(offset && (56>(u32)size-offset || (offset<vertex && 56>vertex-offset)))return 0;
    offset=model_be32(bytes+32);
    if(offset) {
        u32 extent=2+bytes[offset]*14;
        if(extent>(u32)size-offset || (offset<vertex && extent>vertex-offset))return 0;
    }

    skeleton=model_be32(bytes+24);
    s32 bones=0;
    if(skeleton) {
        if(skeleton%4 || (u32)size-skeleton<8 || (model_be32(bytes+skeleton)&0x7F800000u)==0x7F800000u)return 0;
        bones=(s16)model_be16(bytes+skeleton+4);
        if(bones<0 || (u32)bones>((u32)size-skeleton-8)/16)return 0;
        skeleton_end=skeleton+8+(u32)bones*16;
        if(skeleton<vertex && skeleton_end>vertex)return 0;
        for(int i=0;i<bones;++i) {
            const u8 *bone=bytes+skeleton+8+i*16;
            s32 pose=(s16)model_be16(bone+12),parent=(s16)model_be16(bone+14);
            if(pose<0 || pose>=109 || parent < -1 || parent>=i)return 0;
            for(int j=0;j<3;++j)if((model_be32(bone+j*4)&0x7F800000u)==0x7F800000u)return 0;
        }
        for(int field=4;field<=64;field+=4) {
            if(field==8 || field==24)continue;
            u32 section=model_be32(bytes+field);
            if(section>skeleton && section<skeleton_end)return 0;
        }
        u32 texture=model_be16(bytes+8);
        if(texture>skeleton && texture<skeleton_end)return 0;
    }

    binding=model_be32(bytes+40);
    if(binding) {
        if(binding%2)return 0;
        u32 extent=binding_extent(bytes+binding,(u32)size-binding,count,bones);
        if(!extent || (binding<vertex && extent>vertex-binding))return 0;
        binding_end=binding+extent;
        for(int field=4;field<=64;field+=4) {
            if(field==8 || field==40)continue;
            u32 section=model_be32(bytes+field);
            if(section>binding && section<binding_end)return 0;
        }
        u32 texture=model_be16(bytes+8);
        if(texture>binding && texture<binding_end)return 0;
    }

    collision=model_be32(bytes+28);
    if(collision) {
        if(collision%4)return 0;
        u32 extent=collision_extent(bytes+collision,(u32)size-collision,count);
        if(!extent || (collision<vertex && extent>vertex-collision))return 0;
        collision_end=collision+extent;
        for(int field=4;field<=64;field+=4) {
            if(field==8 || field==28)continue;
            u32 section=model_be32(bytes+field);
            if(section>=collision && section<collision_end)return 0;
            u32 length=field==24 && section ? skeleton_end-skeleton : field==44 ? 56 : field==40 && section ? binding_end-binding : field==32 && section ? 2+bytes[section]*14 : 0;
            if(section && section<collision && length>collision-section)return 0;
        }
        u32 texture=model_be16(bytes+8);
        if(texture>=collision && texture<collision_end)return 0;
    }

    u32 texture=model_be16(bytes+8),texture_size=0;
    if(texture) {
        for(int field=4;field<=64;field+=4)if(field!=8 && model_be32(bytes+field)==texture)return 0;
        texture_size=model_section_end(bytes,size,texture)-texture;
        if(!native_texture_validate(bytes+texture,texture_size))return 0;
    }

    u32 display=model_be32(bytes+12),display_count=0;
    if(display) {
        for(int field=4;field<=64;field+=4)if(field!=8 && field!=12 && model_be32(bytes+field)==display)return 0;
        if(model_be16(bytes+8)==display)return 0;
        u32 limit=model_section_end(bytes,size,display);
        if(display%8 || limit-display<8)return 0;
        display_count=model_be32(bytes+display);
        if(display_count>(limit-display-8)/8)return 0;
    }
    u32 geometry=model_be32(bytes+4);
    if(geometry) {
        for(int field=12;field<=64;field+=4)if(model_be32(bytes+field)==geometry)return 0;
        if(model_be16(bytes+8)==geometry)return 0;
    }
    if(geometry && !native_geometry_decode(bytes+geometry,model_section_end(bytes,size,geometry)-geometry,display_count,bones))return 0;
    if(texture)native_texture_decode(bytes+texture,texture_size);
    if(display)for(u32 i=display;i<display+8+display_count*8;i+=4) {
        u32 word=model_be32(bytes+i);rare_memcpy(bytes+i,&word,4);
    }

    for(int i=0;i<80;i+=4) {
        if(i==8 || i==68) {
            u16 a=model_be16(bytes+i),b=model_be16(bytes+i+2);
            rare_memcpy(bytes+i,&a,2);rare_memcpy(bytes+i+2,&b,2);
        } else {
            u32 word=model_be32(bytes+i);rare_memcpy(bytes+i,&word,4);
        }
    }
    for(u32 i=vertex;i<vertex+24;i+=2) {
        u16 value=model_be16(bytes+i);rare_memcpy(bytes+i,&value,2);
    }
    for(u32 i=vertex+24;i<end;i+=16) {
        for(u32 j=0;j<12;j+=2) {
            u16 value=model_be16(bytes+i+j);rare_memcpy(bytes+i+j,&value,2);
        }
    }
    if(collision) {
        u32 triangles=collision+24+model_be16(bytes+collision+16)*4;
        for(u32 i=collision;i<triangles;i+=2) {
            u16 value=model_be16(bytes+i);rare_memcpy(bytes+i,&value,2);
        }
        for(u32 i=triangles;i<collision_end;i+=12) {
            for(u32 j=0;j<8;j+=2){u16 value=model_be16(bytes+i+j);rare_memcpy(bytes+i+j,&value,2);}
            u32 flags=model_be32(bytes+i+8);rare_memcpy(bytes+i+8,&flags,4);
        }
    }
    if(skeleton) {
        u32 scale=model_be32(bytes+skeleton);rare_memcpy(bytes+skeleton,&scale,4);
        for(u32 i=skeleton+4;i<skeleton+8;i+=2){u16 value=model_be16(bytes+i);rare_memcpy(bytes+i,&value,2);}
        for(u32 i=skeleton+8;i<skeleton_end;i+=16) {
            for(int j=0;j<12;j+=4){u32 value=model_be32(bytes+i+j);rare_memcpy(bytes+i+j,&value,4);}
            for(int j=12;j<16;j+=2){u16 value=model_be16(bytes+i+j);rare_memcpy(bytes+i+j,&value,2);}
        }
    }
    if(binding)decode_binding(bytes+binding);
    return 1;
}
