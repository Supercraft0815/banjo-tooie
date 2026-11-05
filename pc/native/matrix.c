#include "core1/mlmtx.h"
#include <math.h>
extern MtxF D_8007B4F0[31];
extern MtxF *s_mtx_stack;
static f32 last_trig_component;
f32 func_800137F4(f32 degrees) {
    f32 angle=degrees*0.017453292519943295f;
    last_trig_component=cosf(angle);return sinf(angle);
}
f32 func_80013788(void) {return last_trig_component;}
f32 func_800137AC(f32 degrees) {
    f32 angle=degrees*0.017453292519943295f;
    last_trig_component=sinf(angle);return cosf(angle);
}
f32 func_800137C4(void) {return last_trig_component;}
MtxF *func_80019CD4(void) {
    s_mtx_stack=D_8007B4F0;
    for(int i=0;i<4;++i)for(int j=0;j<4;++j)s_mtx_stack->m[i][j]=i==j;
    return s_mtx_stack;
}
void mlMtxIdent(void) {func_80019CD4();}
void mlMtxTranslate(f32 x,f32 y,f32 z) {
    for(int i=0;i<3;++i) {
        s_mtx_stack->m[3][i]+=x*s_mtx_stack->m[0][i];
        s_mtx_stack->m[3][i]+=y*s_mtx_stack->m[1][i];
        s_mtx_stack->m[3][i]+=z*s_mtx_stack->m[2][i];
    }
}
void mlMtxScale_xyz(f32 x,f32 y,f32 z) {
    for(int i=0;i<3;++i){s_mtx_stack->m[0][i]*=x;s_mtx_stack->m[1][i]*=y;s_mtx_stack->m[2][i]*=z;}
}
void func_80019AA0(MtxF *parent,MtxF *local) {
    MtxF result={0};
    for(int r=0;r<4;++r)for(int c=0;c<3;++c) {
        result.m[r][c]=(local->m[r][0]*parent->m[0][c]+local->m[r][1]*parent->m[1][c])+local->m[r][2]*parent->m[2][c];
        if(r==3)result.m[r][c]+=parent->m[3][c];
    }
    result.m[3][3]=1;*++s_mtx_stack=result;
}
