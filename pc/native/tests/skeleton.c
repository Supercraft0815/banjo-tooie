#include "native_skinning.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
void func_800D9470(f32 *,f32 *,f32 *);
void func_800D952C(f32 *,f32 *);
static void near(f32 actual,f32 expected) {if(fabsf(actual-expected)>0.0002f){fprintf(stderr,"%g != %g\n",actual,expected);exit(1);}}
static void matrix_near(MtxF *a,MtxF *b) {for(int r=0;r<4;++r)for(int c=0;c<4;++c)near(a->m[r][c],b->m[r][c]);}
static BoneTransform transforms[109];
static BoneTransformList pose={transforms,109};
static void reset_pose(void) {
    for(int i=0;i<109;++i)transforms[i]=(BoneTransform){.unk0={0,0,0,1},.scale={1,1,1}};
}
static void test_hierarchy(void) {
    NativeSkeleton *s=heap_alloc(sizeof(*s)+3*sizeof(NativeBone));s->count=3;s->translation_scale=2;
    s->bones[0]=(NativeBone){{10,0,0},0,-1};
    s->bones[1]=(NativeBone){{20,0,0},1,0};
    s->bones[2]=(NativeBone){{10,5,0},108,0};
    NativeBoneMatrices *list=func_800ADF98();s16 handle=func_800AE020();CHECK(handle && !func_800AE080(0));
    CHECK(func_800AE0B8(NULL)==1 && !func_800AE0D0(NULL) && func_800AE0E8(0)==1 && !func_800AE124(0));
    reset_pose();func_800AE160(&list,s,&pose);CHECK(list->count==3 && list->capacity==3);
    for(int i=0;i<3;++i)matrix_near(&list->base,&list->matrices[i]);
    f32 half=sqrtf(0.5f);transforms[0].unk0[2]=transforms[0].unk0[3]=half;
    transforms[0].scale[0]=2;transforms[0].scale[1]=3;transforms[0].scale[2]=4;
    transforms[0].unk1C[0]=1;transforms[0].unk1C[1]=2;transforms[0].unk1C[2]=3;
    transforms[1].unk0[2]=-half;transforms[1].unk0[3]=half;
    transforms[1].scale[0]=5;transforms[1].unk1C[0]=1;
    transforms[108].unk1C[1]=2;
    func_800AE160(&list,s,&pose);func_800AE1E8(handle,s,&pose);
    MtxF expected[]={{.m={{0,2,0,0},{-3,0,0,0},{0,0,4,0},{12,-16,6,1}}},
                    {.m={{10,0,0,0},{0,3,0,0},{0,0,4,0},{-188,28,6,1}}},
                    {.m={{0,2,0,0},{-3,0,0,0},{0,0,4,0},{0,-16,6,1}}}};
    for(int i=0;i<3;++i){matrix_near(&list->matrices[i],&expected[i]);matrix_near(&func_800AE080(handle)->matrices[i],&expected[i]);}
    f32 pivot[3];CHECK(func_800AE630(list,s,1,pivot));near(pivot[0],12);near(pivot[1],28);near(pivot[2],6);
    CHECK(!func_800AE630(list,s,5,pivot) && !func_800ADE50(list,s,5));
    CHECK(func_800ADE50(list,s,108)==&list->matrices[2]);
    func_800AE290(handle,s,&pose);NativeBoneMatrices *rot=func_800AE080(handle);
    matrix_near(&rot->matrices[1],&rot->base);near(rot->matrices[2].m[0][1],1);near(rot->matrices[2].m[3][0],0);
    func_800AE40C(handle,s,&pose);rot=func_800AE080(handle);
    near(rot->matrices[1].m[0][0],15);near(rot->matrices[1].m[1][1],2);near(rot->matrices[2].m[0][1],2);
    NativeBoneMatrices *copy=func_800ADF98();CHECK(func_800AE708(list,s,&copy,s));
    for(int i=0;i<3;++i)matrix_near(&list->matrices[i],&copy->matrices[i]);
    s->bones[2].pose_index=1;func_800ADEC4(copy,s,1,&copy->base);
    matrix_near(&copy->matrices[1],&copy->base);matrix_near(&copy->matrices[2],&copy->base);
    s->count=1;func_800ADCD0(&copy,s);CHECK(copy->count==1 && copy->capacity==3 && !func_800ADE50(list,s,0));
    func_800ADD80(handle,s);CHECK(func_800AE0E8(handle)==1 && func_800AE124(handle)==1);matrix_near(&func_800AE080(handle)->matrices[0],&list->base);
    func_800ADF5C(copy);func_800ADFE0(handle);func_800ADF5C(list);heap_free(s);
}
static void test_expression(void) {
    NativeSkeleton *s=heap_alloc(sizeof(*s)+sizeof(NativeBone));s->count=1;s->translation_scale=2;s->bones[0]=(NativeBone){{0,0,0},31,-1};
    NativeBoneMatrices *list=func_800ADF98();Unkfunc_800E0960_1 *e=func_800E0960(4);CHECK(e && e->unk6==4 && !e->unk4 && !e->unkC);
    list->expression=e;CHECK(func_800AE6BC(list)==e);reset_pose();func_800E0AF0(e,1);
    func_800E0AFC(e,31,1,0,0,90);func_800E0B8C(e,31,1,2,3,4);func_800E0C20(e,31,1,5,6,7);
    CHECK((u32)e->unk10[0]==0x80000000u && e->unk8 && e->unk9 && e->unkA);
    func_800E0C20(e,128,1,1,1,1);CHECK(e->unk4==3);
    func_800AE160(&list,s,&pose);near(list->matrices[0].m[0][1],2);near(list->matrices[0].m[1][0],-3);near(list->matrices[0].m[3][0],10);
    CHECK(transforms[31].unk0[3]==1 && transforms[31].scale[0]==1 && transforms[31].unk1C[0]==0);
    func_800E0ACC(e);func_800E0AFC(e,31,-1,0,0,180);func_800E0B8C(e,31,-0.5f,3,5,7);func_800E0C20(e,31,-0.5f,8,10,12);
    func_800AE160(&list,s,&pose);near(list->matrices[0].m[0][0],-2);near(list->matrices[0].m[1][1],-3);near(list->matrices[0].m[3][0],8);
    func_800E0ACC(e);func_800E0AFC(e,31,-0.5f,0,0,90);func_800AE160(&list,s,&pose);near(list->matrices[0].m[0][1],sqrtf(0.5f));
    func_800E0AFC(e,31,0,0,0,90);func_800AE160(&list,s,&pose);near(list->matrices[0].m[0][1],sqrtf(0.5f));
    func_800E0C20(e,31,1,1,0,0);func_800E0C20(e,31,1,1,0,0);func_800E0C20(e,31,1,99,0,0);CHECK(e->unk4==4);
    func_800AE5F0(list);CHECK(e->unk0==(void *)(e+1));
    s16 handle=func_800AE020(),expression=func_800E09B8(2);func_800AE6FC(func_800AE080(handle),expression);
    Unkfunc_800E0960_1 *he=func_800AE6BC(func_800AE080(handle));CHECK(he==func_800E0A28(expression));
    func_800E0AF0(he,1);func_800E0C20(he,31,1,2,0,0);func_800AE1E8(handle,s,&pose);near(func_800AE080(handle)->matrices[0].m[3][0],4);
    func_800ADFE0(handle);CHECK(!func_800E0960(-1) && !func_800E0960(32768) && !func_800E09B8(-1) && !func_800E09B8(32768));
    func_800ADF5C(list);heap_free(s);
}
static void test_quaternions_and_pack(void) {
    f32 angles[3]={90,90,0},q[4];func_800D952C(q,angles);
    near(q[0],0.5f);near(q[1],0.5f);near(q[2],-0.5f);near(q[3],0.5f);
    f32 a[4]={0,0,1,0},b[4]={1,0,0,0};func_800D9470(a,a,b);CHECK(a[0]==0 && a[1]==1 && a[2]==0 && a[3]==0);
    f32 c[4]={0,0,1,0};func_800D9470(b,c,b);for(int i=0;i<4;++i)CHECK(a[i]==b[i]);
    NativeSkeleton *s=heap_alloc(sizeof(*s)+sizeof(NativeBone));s->count=1;
    NativeBoneMatrices *list=func_800ADF98();func_800ADCD0(&list,s);
    list->matrices[0].m[0][0]=-1.5f;list->matrices[0].m[0][1]=2.25f;
    list->matrices[0].m[3][0]=3.5f;list->matrices[0].m[3][1]=-4.25f;
    list->matrices[0].m[3][2]=INFINITY;list->matrices[0].m[0][3]=99;
    Mtx output[3],*cursor=output;func_800AE598(list,&cursor);CHECK(cursor==output+2);
    u32 *words=(u32 *)&output[0];CHECK(words[0]==0x00010000 && words[2]==1 && words[5]==0x00010000 && words[7]==1);
    words=(u32 *)&output[1];CHECK(words[0]==0xFFFE0002 && words[8]==0x80004000 && words[6]==0x0003FFFB && words[14]==0x8000C000 && words[7]==0x80000001);
    func_800ADF5C(list);heap_free(s);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));reset_pose();int skeletons=0,bones=0;
    NativeBoneMatrices *list=func_800ADF98();
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);
        NativeSkeleton *s=(NativeSkeleton *)func_800B27E0(model);
        if(s) {
            func_800AE160(&list,s,&pose);for(int i=0;i<s->count;++i)matrix_near(&list->matrices[i],&list->base);
            bones+=s->count;++skeletons;
        }
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(skeletons && bones);func_800ADF5C(list);native_assets_shutdown();
    printf("Native skeletons: %d original skeletons, %d bones restored to bind pose.\n",skeletons,bones);
}
int main(int argc,char **argv) {
    if(argc==2)test_archive(argv[1]);else {CHECK(argc==1);test_hierarchy();test_expression();test_quaternions_and_pack();}
    puts("native skeleton checks passed");return 0;
}
