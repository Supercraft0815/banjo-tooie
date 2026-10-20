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

/* extern */

s32 func_808001A8_ncpodfixpos(u8 *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5BC4(s32, f32 *);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp54[3];
    f32 sp44[4];
    f32 sp38[3];
    f32 sp2C[3];

    if ((*(s16 *)(arg0 + 0x2C)) & 1) {
        if (func_80800000_ncpodfixpos((*(u8 **)((s8 *)(arg0) + (0x18))), (*(s32 *)((s8 *)(arg0) + (0x1C)))) != 0) {
            func_80103DFC(func_80106790((*(Unk80132ED0 **)((s8 *)(arg0) + (0x18)))), sp54);
            if ((*(s16 *)((s8 *)(arg0) + (0x2C))) & 0x400) {
                if ((*(u8 *)((s8 *)(arg0) + (0x42))) != 0) {
                    func_800EFB24(sp44, sp54, (f32 *)(arg0 + 0x20));
                    func_800EF334(sp44, 0.3f);
                    func_800EF04C((f32 *)(arg0 + 0x20), sp44);
                    return 1;
                }
            }
            func_800EE7F8((f32 *)(arg0 + 0x20), sp54);
            (*(u8 *)((s8 *)(arg0) + (0x42))) = 1U;
            goto block_6;
        }
block_6:
        return 1;
    }
    if ((*(s16 *)(arg0 + 0x2C)) & 0x40) {
        func_800F5BC4(func_800F54E4(), sp38);
        func_800F5A00(func_800F54E4(), sp54);
        func_800EF04C(sp54, sp38);
        if ((*(s16 *)((s8 *)(arg0) + (0x2C))) & 0x400) {
            if ((*(u8 *)((s8 *)(arg0) + (0x42))) != 0) {
                func_800EFB24(sp2C, sp54, (f32 *)(arg0 + 0x20));
                func_800EF334(sp2C, 0.3f);
                func_800EF04C((f32 *)(arg0 + 0x20), sp2C);
                return 1;
            }
        }
        (*(u8 *)((s8 *)(arg0) + (0x42))) = 1U;
        func_800EE7F8((f32 *)(arg0 + 0x20), sp54);
        return 1;
    }
    if ((*(s16 *)(arg0 + 0x2C)) & 0x80) {
        return 1;
    } else {
        return 0;
    }
}

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
