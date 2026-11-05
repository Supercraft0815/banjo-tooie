#include "core1/mlmtx.h"
#include <math.h>

void guMtxF2L(f32 input[4][4],Mtx *output) {
    u32 fixed[16];
    for(int row=0;row<4;++row)for(int col=0;col<4;++col) {
        f32 value=input[row][col]*65536.0f;
        /* MIPS trunc.w.s returns the indefinite integer for invalid conversion. */
        fixed[row*4+col]=!isfinite(value) || value < -2147483648.0f || value>=2147483648.0f ? 0x80000000u : (u32)(s32)value;
    }
    u32 *words=(u32 *)output;
    for(int i=0;i<8;++i) {
        words[i]=(fixed[i*2]&0xFFFF0000u)|(fixed[i*2+1]>>16);
        words[i+8]=(fixed[i*2]<<16)|(fixed[i*2+1]&0xFFFFu);
    }
}
void guMtxL2F(f32 output[4][4],Mtx *input) {
    u32 words[16];for(int i=0;i<16;++i)words[i]=((u32 *)input)[i];
    for(int i=0;i<8;++i) {
        s32 first=(words[i]&0xFFFF0000u)|(words[i+8]>>16);
        s32 second=(words[i]<<16)|(words[i+8]&0xFFFFu);
        output[(i*2)/4][(i*2)%4]=first*(1.0f/65536.0f);
        output[(i*2+1)/4][(i*2+1)%4]=second*(1.0f/65536.0f);
    }
}

void guMtxIdentF(f32 matrix[4][4]) {
    for(int i=0;i<4;++i)for(int j=0;j<4;++j)matrix[i][j]=i==j;
}
void guMtxIdent(Mtx *matrix) {
    f32 identity[4][4];guMtxIdentF(identity);guMtxF2L(identity,matrix);
}
void guOrthoF(f32 matrix[4][4],f32 left,f32 right,f32 bottom,f32 top,f32 near,f32 far,f32 scale) {
    guMtxIdentF(matrix);
    matrix[0][0]=2/(right-left);matrix[1][1]=2/(top-bottom);matrix[2][2]=-2/(far-near);
    matrix[3][0]=-(right+left)/(right-left);matrix[3][1]=-(top+bottom)/(top-bottom);matrix[3][2]=-(far+near)/(far-near);
    for(int i=0;i<4;++i)for(int j=0;j<4;++j)matrix[i][j]*=scale;
}
void guOrtho(Mtx *matrix,f32 left,f32 right,f32 bottom,f32 top,f32 near,f32 far,f32 scale) {
    f32 projection[4][4];guOrthoF(projection,left,right,bottom,top,near,far,scale);guMtxF2L(projection,matrix);
}
