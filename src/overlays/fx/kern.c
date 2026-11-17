#include "common.h"
typedef struct { u8 first; u8 key; s8 value2; s8 value3; } KernEntry;
void func_80800000_fxkern(u8 arg0, u8 arg1, s32 *arg2, s32 *arg3) {

    extern KernEntry D_80800420_fxkern[];
    s32 key = arg0;
    s32 i;

    *arg3 = 0;
    *arg2 = 0;
    for (i = 0; D_80800420_fxkern[i].first != 0; i++) {
            if (key == D_80800420_fxkern[i].key && (D_80800420_fxkern[i].first == arg1 || D_80800420_fxkern[i].first == 0x2A)) {
                *arg2 = D_80800420_fxkern[i].value2;
                *arg3 = D_80800420_fxkern[i].value3;
                return;
            }
    }
}

s32 func_80800084_fxkern(u8 *arg0) {
    int func_800D36C4(s32, s32);
    extern f32 B_80800480_fxkern;
    extern f32 B_80800488_fxkern[][2];
    s32 i;
    s32 x;
    s32 y;

    B_80800488_fxkern[0][0] = 0.0f;
    B_80800488_fxkern[0][1] = 0.0f;
    for (i = 1; arg0[i] != 0 && i != 0x40; i++) {
        B_80800488_fxkern[i][0] = B_80800488_fxkern[i - 1][0];
        B_80800488_fxkern[i][0] += B_80800480_fxkern * (func_800D36C4(1, arg0[i - 1]) / 2);
        B_80800488_fxkern[i][0] += B_80800480_fxkern * (func_800D36C4(1, arg0[i]) / 2);
        B_80800488_fxkern[i][0] += B_80800480_fxkern * -4.0f;
        func_80800000_fxkern(arg0[i], arg0[i - 1], &x, &y);
        B_80800488_fxkern[i][0] += B_80800480_fxkern * x;
        B_80800488_fxkern[i][1] = y * B_80800480_fxkern;
    }
    return i - 1;
}

void func_80800224_fxkern(Gfx **arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8DEC(Gfx **, s32, s32, u8);
    extern f32 B_80800488_fxkern[][2];

    func_800B8C98(1);
    func_800B7F14(arg0);
    for (; arg4 >= 0; arg4--) {
        func_800B8DEC(arg0, (s32) (B_80800488_fxkern[arg4][0] + (f32) arg1), (s32) (B_80800488_fxkern[arg4][1] + (f32) arg2), arg3[arg4]);
    }
    func_800B811C(arg0);
}

/* extern */

void fxkern_entrypoint_0(Gfx **arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 func_80800084_fxkern(u8 *);
    void func_80800224_fxkern(Gfx **, s32, s32, u8 *, s32);
    func_80800224_fxkern(arg0, arg1, arg2, arg3, func_80800084_fxkern(arg3));
}

void fxkern_entrypoint_1(Gfx **arg0, s32 arg1, u8 *arg2) {
    s32 func_80800084_fxkern(u8 *);
    void func_80800224_fxkern(Gfx **, s32, s32, u8 *, s32);
    extern f32 B_80800488_fxkern[][2];
    s32 temp_v0;
    f32 divisor = 2.0f;

    temp_v0 = func_80800084_fxkern(arg2);
    func_80800224_fxkern(arg0, (s32) ((304.0f - B_80800488_fxkern[temp_v0][0]) / divisor), arg1, arg2, temp_v0);
}

void fxkern_entrypoint_2(void) {
    void func_800B8C50(void);
    extern f32 B_80800480_fxkern;
    func_800B8C50();
    B_80800480_fxkern = 1.0f;
}

void fxkern_entrypoint_3(f32 arg0) {
    void func_800B8CF0(f32 size);
    extern f32 B_80800480_fxkern;
    func_800B8CF0(arg0);
    B_80800480_fxkern = arg0;
}
/* data_to_c.py: from asm/data/overlays/fx/kern.data.s */
KernEntry D_80800420_fxkern [24] BT_DATA(4, overlays_fx_kern, 0x0) = { { 0x41, 0x56, -3, 0 }, { 0x57, 0x41, -3, 0 }, { 0x56, 0x41, -3, 0 }, { 0x59, 0x41, -2, 0 }, { 0x4D, 0x4F, -1, 0 }, { 0x44, 0x41, -1, 0 }, { 0x52, 0x4F, -2, 0 }, { 0x54, 0x41, -2, 0 }, { 0x53, 0x54, -1, 0 }, { 0x41, 0x4D, -1, 0 }, { 0x43, 0x4F, -1, 0 }, { 0x4F, 0x56, -1, 0 }, { 0x4C, 0x4F, -1, 0 }, { 0x4D, 0x55, -1, 0 }, { 0x55, 0x4D, -1, 0 }, { 0x4D, 0x41, -2, 0 }, { 0x4D, 0x30, -1, 0 }, { 0x48, 0x49, 1, 0 }, { 0x49, 0x50, 1, 0 }, { 0x45, 0x45, 0, 1 }, { 0x5A, 0x45, 0, -1 }, { 0x2A, 0x53, 1, 0 }, { 0x2A, 0x27, 3, 0 }, { 0, 0, 0, 0 } };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_80800480_fxkern BT_DATA(16, bss_fx_kern, 0x0);
f32 B_80800488_fxkern [ 65 ] [ 2 ] BT_DATA(4, bss_fx_kern, 0x8);
#endif
