#include "native_camera_frame.h"
#include "native_reflection.h"
#include "gfx.h"
#include <math.h>
#include <limits.h>
#include <stdlib.h>

NativeCamera *D_8012D500,*D_8012D504;
s32 D_8012D508;
MtxF D_8012D510;
u16 D_8012D550;
Mtx *D_8012D554,*D_8012D558;
s16 widescreen_enabled;
extern MtxF *s_mtx_stack;
extern MtxF D_8007B4F0[31];
s32 func_80018BC4(void);
void func_800F2D34(MtxF *,f32 *,f32 *),func_800EE88C(f32 *,s16 *),func_800EFA4C(f32 *,f32,f32,f32);
/* shortcut: viewport calls still require their real owner; link it when ported. */
s32 func_800A89F8(void);
s32 func_800C4C34(s32,f32 *,f32 *,s32 *);
void func_800C4E58(s32,f32 *,f32 *);

s32 func_800E36D0(s32 *arg0, s32 *arg1, f32 *arg2, f32 *arg3) {
    f32 delta[3];
    f32 max;
    f32 dot;
    s32 i, j, k;

    max = 0.0f;
    for (i = 0; i != 2; i++) {
        for (j = 0; j != 2; j++) {
            for (k = 0; k != 2; k++) {
                delta[0] = (f32)(i ? arg0[0] : arg1[0]) - arg2[0];
                delta[1] = (f32)(j ? arg0[1] : arg1[1]) - arg2[1];
                delta[2] = (f32)(k ? arg0[2] : arg1[2]) - arg2[2];
                dot = arg3[0] * delta[0] + arg3[1] * delta[1] + arg3[2] * delta[2];
                if (max < dot) {
                    max = dot;
                }
            }
        }
    }
    return isfinite(max) && max < 2147483648.0f ? (s32)max : INT_MIN;
}

void func_800E37E8(s32 *arg0, s32 *arg1, s32 arg2) {
    if (!arg2) abort();
    for (int i=0;i<3;++i) {
        arg0[i]=(s32)((s64)arg0[i]/arg2)-(arg0[i]<0);
        arg1[i]=(s32)((s64)arg1[i]/arg2)-(arg1[i]<0);
    }
}

void func_800E3900(f32 arg0) {
    func_800CA3A4(D_8012D500, arg0);
}

f32 func_800E3928(f32 *arg0, f32 *arg1) {
    return func_800CA704(D_8012D500, arg0, arg1);
}

void func_800E3958(f32 *arg0) {
    func_800CA740(D_8012D500, arg0);
}

void func_800E3980(f32 *arg0) {
    func_800CA7E4(D_8012D500, arg0);
}

void func_800E39A8(f32 *arg0, f32 *arg1) {
    func_800CA8B4(D_8012D500, arg0, arg1);
}

void func_800E39D8(f32 *arg0, f32 *arg1) {
    func_800CA628(D_8012D500, arg0, arg1);
}

void func_800E3A08(s32 *arg0) {
    func_800CA810(D_8012D500, arg0);
}

void func_800E3A30(s16 *arg0) {
    func_800CA934(D_8012D500, arg0);
}

void func_800E3A58(f32 *arg0) {
    func_800CA9D8(D_8012D500, arg0);
}

f32 func_800E3A80(void) {
    return func_800CAA1C(D_8012D500);
}

s32 func_800E3AA4(f32 x) {
    f32 angle=func_800E3A80()-x;
    if (!isfinite(angle) || angle < -2147483648.0f || angle >= 2147483648.0f) return 0;
    s32 wrapped=(s32)angle%360;
    return wrapped<0 ? wrapped+360 : wrapped;
}

void func_800E3B50(f32 *arg0, f32 *arg1, f32 *arg2) {
    func_800CAA00(D_8012D500, arg0, arg1, arg2);
}

void func_800E3B88(void) {
    func_800CA440(D_8012D500);
}

void func_800E3BAC(f32 *arg0) {
    func_800CA5B8(D_8012D500, arg0);
}

void func_800E3BD4(s32 *arg0) {
    func_800CA5D8(D_8012D500, arg0);
}

void func_800E3BFC(f32 arg0, f32 arg1, f32 arg2) {
    func_800CA5F8(D_8012D500, arg0, arg1, arg2);
}

void func_800E3C30(f32 *arg0) {
    func_800CA668(D_8012D500, arg0);
}

void func_800E3C58(f32 arg0, f32 arg1, f32 arg2) {
    func_800CA688(D_8012D500, arg0, arg1, arg2);
}

void func_800E3C8C(f32 arg0, f32 arg1) {
    func_800CA6C0(D_8012D500, arg0, arg1);
}

void func_800E3CB8(f32 *arg0, f32 *arg1) {
    func_800CA6D4(D_8012D500, arg0, arg1);
}

void func_800E3CE8(void) {
    func_800CAF34(D_8012D500);
}

s32 func_800E3D0C(f32 *arg0, f32 *arg1) {
    s32 result;
    f32 temp;
    f32 first[3];
    f32 second[3];
    s32 i;

    result = func_800CAA24(D_8012D500->values, arg0, arg1);
    if ((func_800BCC58() != 0) && (result == 0)) {
        func_800BCC28(first, arg0);
        func_800BCC28(second, arg1);
        for (i = 0; i < 3; i++) {
            if (second[i] < first[i]) {
                temp = first[i];
                first[i] = second[i];
                second[i] = temp;
            }
        }
        result = func_800CAA24(D_8012D500->values, first, second);
    }
    return result;
}

s32 func_800E3DC0(s16 *arg0, s16 *arg1) {
    s32 result;
    f32 temp;
    f32 first[3];
    f32 second[3];
    s32 i;

    result = func_800CAB70(D_8012D500->values, arg0, arg1);
    if ((func_800BCC58() != 0) && (result == 0)) {
        func_800EE88C(first, arg0);
        func_800EE88C(second, arg1);
        func_800BCC28(first, first);
        func_800BCC28(second, second);
        for (i = 0; i < 3; i++) {
            if (second[i] < first[i]) {
                temp = first[i];
                first[i] = second[i];
                second[i] = temp;
            }
        }
        result = func_800CAA24(D_8012D500->values, first, second);
    }
    return result;
}

s32 func_800E3E8C(f32 *arg0, f32 arg1) {
    s32 var_v1;
    f32 sp18[3];

    var_v1 = func_800CACEC(D_8012D500->values, arg0, arg1);
    if ((func_800BCC58() != 0) && (var_v1 == 0)) {
        func_800BCC28(sp18, arg0);
        var_v1 = func_800CACEC(D_8012D500->values, sp18, arg1);
    }
    return var_v1;
}

s32 func_800E3EFC(f32 arg0, f32 arg1, f32 arg2) {
    s32 var_v1;
    f32 sp28[3];
    f32 sp1C[3];

    var_v1 = func_800CAD9C(D_8012D500, arg0, arg1, arg2);
    if ((func_800BCC58() != 0) && (var_v1 == 0)) {
        func_800EFA4C(sp1C, arg0, arg1, arg2);
        func_800BCC28(sp28, sp1C);
        var_v1 = func_800CAD9C(D_8012D500, sp28[0], sp28[1], sp28[2]);
    }
    return var_v1;
}

s32 func_800E3F8C(f32 arg0, f32 arg1, f32 arg2) {
    s32 var_v1;
    f32 sp28[3];
    f32 sp1C[3];

    var_v1 = func_800CAEA4(D_8012D500, arg0, arg1, arg2);
    if ((func_800BCC58() != 0) && (var_v1 == 0)) {
        func_800EFA4C(sp1C, arg0, arg1, arg2);
        func_800BCC28(sp28, sp1C);
        var_v1 = func_800CAEA4(D_8012D500, sp28[0], sp28[1], sp28[2]);
    }
    return var_v1;
}

MtxF *func_800E401C(void) {
    return func_800CA7A4(D_8012D500);
}

MtxF *func_800E4040(void) {
    return func_800CA7AC(D_8012D500);
}

f32 func_800E4064(void) {
    return func_800CA6FC(D_8012D500);
}

f32 func_800E4088(void) {
    return func_800CA7B4(D_8012D500);
}

f32 func_800E40AC(s32 arg0, f32 arg1) {
    (void)arg0; return func_800CAF00(D_8012D500, arg1);
}

f32 func_800E40DC(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    f32 sp1C[3];

    func_800CA9D8(D_8012D500, arg3);
    func_800EFA4C(sp1C, arg0, arg1, 200.0f);
    func_800C4E58(func_800A89F8(), sp1C, arg2);
    return 1.0f;
}

int func_800E4140(f32 *arg0, f32 *arg1) {
    int temp_t6;
    s32 sp20;

    temp_t6 = func_800C4C34(func_800A89F8(), arg0, arg1, &sp20);
    return temp_t6 && sp20;
}

void func_800E4190(f32 *arg0, f32 *arg1, s32* arg2) {
    func_800C4C34(func_800A89F8(), arg0, arg1, arg2);
}

void func_800E41CC(void) {
    if (!D_8012D504) D_8012D504 = func_800CA334();
    func_800CA314(D_8012D504, D_8012D500);
}

void func_800E4208(void) {
    if (!D_8012D504) return;
    func_800CA314(D_8012D500, D_8012D504);
    func_800CA364(D_8012D504);
    D_8012D504 = 0;
}

void func_800E4244(f32 *arg0, f32 arg1) {
    func_800CA3F4(D_8012D500->position, arg0, arg1);
}

void func_800E4278(void) {
    if (D_8012D504) func_800CA364(D_8012D504);
    D_8012D500 = D_8012D504 = NULL;
}

void func_800E4290(void) {
    if (D_8012D504) func_800CA364(D_8012D504);
    D_8012D500 = D_8012D504 = NULL;
}

NativeCamera *func_800E42A8(void) {
    return D_8012D500;
}

void func_800E42B4(NativeCamera *arg0) {
    D_8012D500 = arg0;
}

f32 func_800E42C0(void) {
    return func_800CA6E8(D_8012D500);
}

void func_800E42E4(s32 arg0) {
    D_8012D508 = arg0;
}

static u32 frame_matrices(NativeGraphicsContext *frame, size_t packets) {
    if (!frame || !frame->gfx || !frame->gfx_end || !frame->mtx || !frame->mtx_end ||
        frame->gfx_end-frame->gfx < (ptrdiff_t)packets || frame->mtx_end-frame->mtx < 2) return 0;
    return native_graphics_address(frame->memory,frame->mtx,2*sizeof(Mtx));
}

int func_800E42F0(NativeGraphicsContext *frame, s32 use_widescreen) {
    u32 address=frame_matrices(frame,2); if (!address) return 0;
    f32 width=use_widescreen && widescreen_enabled ? (s32)(SCREEN_WIDTH*2*WIDESCREEN_ADJUSTMENT) : SCREEN_WIDTH*2;
    guOrtho(frame->mtx,-width,width,-SCREEN_HEIGHT*2,SCREEN_HEIGHT*2,-50,50,1);
    guMtxIdent(frame->mtx+1);
    gSPMatrix(frame->gfx++,address,G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
    gSPMatrix(frame->gfx++,address+sizeof(Mtx),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    D_8012D554=frame->mtx;frame->mtx+=2;return 1;
}

void func_800E443C(MtxF* base_matrix, f32* translation, f32 scale) {
    f32 inv_scale;
    MtxF mat;

    mlMtxSet(base_matrix);

    func_80018C50(func_800CA7AC(D_8012D500));

    inv_scale = 1.0f / scale;

    mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = inv_scale;

    mat.m[0][1] = mat.m[0][2] = mat.m[0][3] = mat.m[1][0] = mat.m[1][2] = mat.m[1][3] = mat.m[2][0] = mat.m[2][1] = mat.m[2][3] = 0.0f;

    mat.m[3][0] = -translation[0] * inv_scale;
    mat.m[3][1] = -translation[1] * inv_scale;
    mat.m[3][2] = -translation[2] * inv_scale;
    mat.m[3][3] = 1.0f;

    func_80018C50(&mat);
}

int func_800E44FC(NativeGraphicsContext *frame) {
    u32 address=frame_matrices(frame,3);
    if (!address || !D_8012D500) return 0;
    f32 scale=func_800CA6E8(D_8012D500),translation[3];MtxF projection;
    u16 norm=func_800CB124(D_8012D500,&projection);
    if (!norm || !isfinite(scale) || scale<=0) return 0;
    func_800CA7E4(D_8012D500,translation);
    for (int i=0;i<3;++i) if (!isfinite(translation[i])) return 0;
    MtxF *previous=mlMtx_get_stack_pointer(),saved=D_8007B4F0[0];
    func_800E443C(&projection,translation,scale);
    if (func_80018BC4()) func_800E443C(&projection,translation,2*scale);
    MtxF *view=mlMtx_get_stack_pointer();
    for (int i=0;i<4;++i) for (int j=0;j<4;++j) if (!isfinite(view->m[i][j])) {
        D_8007B4F0[0]=saved;
        s_mtx_stack=previous;return 0;
    }
    mlMtxApply(frame->mtx);guMtxIdent(frame->mtx+1);
    gSPPerspNormalize(frame->gfx++,norm);
    gSPMatrix(frame->gfx++,address,G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
    gSPMatrix(frame->gfx++,address+sizeof(Mtx),G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    D_8012D558=frame->mtx;frame->mtx+=2;return 1;
}

void func_800E4628(void) {
    D_8012D558 = D_8012D554 = NULL;
}

void func_800E4640(Gfx** gfx) {
    if (D_8012D508 != 0) {
        gSPDisplayList((*gfx)++, 0x08000000);
        return;
    }
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL(D_8012D558), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void func_800E46A4(f32 out[4], f32 in[4]) {
    func_800F2D34(&D_8012D510, out, in);
}

u16 func_800E46D4(void) {
    return D_8012D550;
}

void func_800E46E0(Gfx** gfx, void* addr) {

    gSPSegment((*gfx)++, 0x08, osVirtualToPhysical(addr));
}
