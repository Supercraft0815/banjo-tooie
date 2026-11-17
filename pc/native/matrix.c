#include "core1/mlmtx.h"
#include <math.h>
extern MtxF D_8007B4F0[31];
extern MtxF *s_mtx_stack;
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
// mtx_asm.s func_80019BB8: the stack top's 3x3 times r (row-major 3x3), in place.
void func_80019BB8(f32 *r) {
    MtxF *m=s_mtx_stack;
    for(int j=0;j<3;++j) {
        f32 a=m->m[0][j],b=m->m[1][j],c=m->m[2][j];
        for(int i=0;i<3;++i)m->m[i][j]=(r[i*3]*a+r[i*3+1]*b)+r[i*3+2]*c;
    }
}
// mtx_asm.s func_80019D78: rotation from x/y/z angles in degrees. Like the asm it leaves m[15] as it
// is (it loads 1.0 for it but stores the zero of m[14] twice).
f32 func_800137AC(f32), func_800137C4(void);
void func_80019D78(f32 *m,f32 x,f32 y,f32 z) {
    f32 cx=func_800137AC(x),sx=func_800137C4(),cy=func_800137AC(y),sy=func_800137C4(),cz=func_800137AC(z),sz=func_800137C4();
    m[0]=cy*cz;m[1]=cy*sz;m[2]=-sy;m[3]=0;
    m[4]=(sx*cz)*sy-cx*sz;m[5]=(sx*sz)*sy+cx*cz;m[6]=sx*cy;m[7]=0;
    m[8]=(cx*cz)*sy+sx*sz;m[9]=(cx*sz)*sy-sx*cz;m[10]=cx*cy;m[11]=0;
    m[12]=m[13]=m[14]=0;
}
