#include "common.h"

s32 func_80800000_ncpodfixpos(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

s16 ncpodfixpos_entrypoint_0(void) {
    s16 func_8001B668(s32, s32);
    void func_800EFD24(f32 *);
    void *ncpodfixpos_entrypoint_2(s16);
    s16 handle;
    u8 *data;

    handle = func_8001B668(0, 0x44);
    data = ncpodfixpos_entrypoint_2(handle);
    *(s32 *)(data + 0x18) = 0;
    func_800EFD24((f32 *)(data + 0x20));
    func_800EFD24((f32 *)data);
    func_800EFD24((f32 *)(data + 0xC));
    *(s16 *)(data + 0x2C) = 0;
    *(s16 *)(data + 0x38) = -1;
    data[0x40] = 0;
    data[0x41] = 0;
    data[0x42] = 0;
    *(s32 *)(data + 0x3C) = 0;
    *(s32 *)(data + 0x18) = 0;
    *(s32 *)(data + 0x1C) = -1;
    *(f32 *)(data + 0x30) = 40.0f;
    *(f32 *)(data + 0x34) = 1.0f;
    return handle;
}

/* extern */

void ncpodfixpos_entrypoint_1(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

/* extern */

void *ncpodfixpos_entrypoint_2(s16 arg0) {
    void *func_8001B798(s16);
    return func_8001B798(arg0);
}

/* extern */

void func_80800118_ncpodfixpos(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(u8 *);
    s32 func_800A5800(s16);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = arg2;
    if (arg2 == 1) {
        func_800A5800((*(s16 *)((s8 *)(arg0) + (0x38))));
        _cadbfunc_entrypoint_0(arg0);
        _cadbfunc_entrypoint_2(arg0 + 0xC);
        (*(s8 *)((s8 *)(arg0) + (0x42))) = 0;
    }
}

void ncpodfixpos_entrypoint_3(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x38))) = arg2;
    func_80800118_ncpodfixpos(arg0, arg1, 1);
}

void ncpodfixpos_entrypoint_4(u8 *arg0, u8 *arg1) {
    (*(u8 **)((s8 *)(arg0) + (0x18))) = arg1;
    (*(u32 *)((s8 *)(arg0) + (0x1C))) = (u32) (*(u16 *)((s8 *)(arg1) + (0x12))) >> 1;
}

void ncpodfixpos_entrypoint_5(s16 *arg0, s32 arg1) {
    arg0[22] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/func_808001A8_ncpodfixpos.s")

/* extern */

s32 ncpodfixpos_entrypoint_6(s16 arg0, s32 arg1) {
    s32 pad[2];
    s32 _ncpod_entrypoint_11(s32, s32);
    s32 _ncpod_entrypoint_8(s32, u8 *, u8 *);
    s32 _ncpod_entrypoint_9(s32, f32);
    f32 func_800136E4(f32);
    s32 func_800F18FC(u8 *, u8 *, u8 *);
    s32 func_80110024(s32);
    s32 func_808001A8_ncpodfixpos(u8 *);
    s32 sp24;
    s32 temp_v1;
    u8 *temp_v0;

    temp_v0 = ncpodfixpos_entrypoint_2(arg0);
    temp_v1 = (*(s32 *)((s8 *)(temp_v0) + (0x3C)));
    if ((temp_v1 != 0) && (temp_v1 == 1)) {
        sp24 = func_80110024(arg1);
        if (func_808001A8_ncpodfixpos(temp_v0) != 0) {
            func_800F18FC(temp_v0 + 0x20, temp_v0, temp_v0 + 0xC);
            (*(f32 *)((s8 *)(temp_v0) + (0xC))) = func_800136E4(-(*(f32 *)((s8 *)(temp_v0) + (0xC))));
        }
        _ncpod_entrypoint_8(sp24, temp_v0, temp_v0 + 0xC);
        _ncpod_entrypoint_9(sp24, (*(f32 *)((s8 *)(temp_v0) + (0x30))));
        if ((*(f32 *)((s8 *)(temp_v0) + (0x30))) == 40.0f) {
            _ncpod_entrypoint_11(sp24, (*(s32 *)((s8 *)(temp_v0) + (0x34))));
        }
    }
    return 3;
}
