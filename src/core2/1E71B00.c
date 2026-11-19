#include "common.h"
#include "core2/player_motion_data.h"

s32 func_80098210() 
{
    return 0x30;
}

struct player_state_s;
s32 func_800EFD24();     
void func_80098218(struct player_state_s *arg0, s32 *arg1) {
    s32 func_80092B80(struct player_state_s *);
    void func_800DFC20(s32 *, s32, f32 *);
    void func_800DFF64(s32 *, s32, f32 *);
    void func_800DFFA0(s32 *, s32, f32 *);
    void func_800DFFDC(s32 *, s32, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 vec[3];
    f32 scale;

    switch (func_80092B80(arg0)) {
    case 0x607:
    case 0x608:
        if ((*(u8 **)((u8 *)arg0 + 0xAC))[0x28]) {
            func_800EFD24(vec);
            vec[0] = (*(f32 **)((u8 *)arg0 + 0xAC))[0];
            func_800DFFDC(arg1, 0x2C, vec);
            vec[0] = (*(f32 **)((u8 *)arg0 + 0xAC))[1];
            func_800DFFDC(arg1, 0x2D, vec);
            vec[0] = (*(f32 **)((u8 *)arg0 + 0xAC))[2];
            func_800DFFDC(arg1, 0x2E, vec);
            vec[0] = (*(f32 **)((u8 *)arg0 + 0xAC))[3];
            func_800DFFDC(arg1, 0x3D, vec);
        }
        if ((*(u8 **)((u8 *)arg0 + 0xAC))[0x2A]) {
            func_800DFFA0(arg1, 0x3C, *(f32 **)((u8 *)arg0 + 0xAC) + 7);
        }
        if ((*(u8 **)((u8 *)arg0 + 0xAC))[0x29]) {
            func_800DFF64(arg1, 0x3C, *(f32 **)((u8 *)arg0 + 0xAC) + 4);
            if ((*(f32 **)((u8 *)arg0 + 0xAC))[4] == (*(f32 **)((u8 *)arg0 + 0xAC))[5]
                && (*(f32 **)((u8 *)arg0 + 0xAC))[5] == (*(f32 **)((u8 *)arg0 + 0xAC))[6]
                && (*(f32 **)((u8 *)arg0 + 0xAC))[6] == 1.0f) {
                (*(u8 **)((u8 *)arg0 + 0xAC))[0x29] = 0;
            }
        }
        if ((*(f32 **)((u8 *)arg0 + 0xAC))[11] != 1.0f) {
            func_800DFC20(arg1, 0x6C, vec);
            scale = (*(f32 **)((u8 *)arg0 + 0xAC))[11];
            func_800EFA4C(vec, vec[0] * scale, vec[1] * scale, vec[2] * scale);
            func_800DFFA0(arg1, 0x6C, vec);
        }
    case 0x61C:
    case 0x623:
        return;
    }
}

void func_80098408(u8 *arg0) {
    void func_80098480(u8 *, s32, s32);
    void func_80098494(void *, f32, f32, f32, f32);
    void func_800984F0(u8 *, f32 *);
    void func_800984CC(void *, f32 *);
    void func_80098520(void *, f32);
    extern f32 D_80117E9C[3];
    extern f32 D_80117E90[3];

    func_80098480(arg0, 0, 0);
    func_80098494(arg0, 0.0f, 0.0f, 0.0f, 0.0f);
    func_800984F0(arg0, D_80117E9C);
    func_800984CC(arg0, D_80117E90);
    func_80098520(arg0, 1.0f);
} typedef struct { u8 pad0[0xAC]; union { void * unkAC; u8 * unkAC_u8p; }; u8 padB0[0x30]; union { void * unkE0; u8 * unkE0_u8p; }; } Obj1E71B00_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80098480(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC_u8p)) + (0x28))) = arg1;
    (*(s8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC_u8p)) + (0x2A))) = arg2;
}

void func_80098494(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC)) + (0))) = arg1;
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC)) + (4))) = arg2;
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC)) + (8))) = arg3;
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC)) + (0xC))) = arg4;
}

/* extern */

void func_800984CC(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8((f32 *)((u8 *)*&((Obj1E71B00_arg0 *)arg0)->unkAC + 0x1C), arg1);
}

void func_800984F0(u8 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    (*(s8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkAC_u8p)) + (0x29))) = 1;
    func_800EE7F8((f32 *)((((Obj1E71B00_arg0 *)arg0)->unkAC_u8p) + 0x10), arg1);
}

void func_80098520(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 172) + 44) = arg1;
}

s32 func_80098530() 
{
    return 0x34;
}

/* extern */

void func_80098538(u8 *arg0) {
    s32 func_800EFD24(u8 *, u8 *);
    func_800EFD24((((Obj1E71B00_arg0 *)arg0)->unkE0_u8p), arg0);
    func_800EFD24((((Obj1E71B00_arg0 *)arg0)->unkE0_u8p) + 0xC, arg0);
    (*(s8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0_u8p)) + (0x2C))) = 0;
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0_u8p)) + (0x28))) = 0.0f;
    (*(s8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0_u8p)) + (0x2F))) = 0;
}

void func_80098590(f32 **arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, arg0[56]);
}

f32 func_800985B8(f32 **arg0)
{
    return arg0[56][1];
}

s32 func_800985C4(void *arg0, f32 *arg1) {
    void _gspropctrl_entrypoint_11(Prop*, f32[3]);
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    void func_8009C128(void *, f32[3]);
    Prop *temp_v0;

    func_8009C128(arg0, arg1);
    temp_v0 = _gccubesearch_entrypoint_6(D_80117EB0, arg1);
    if (temp_v0 == NULL) {
        return 0;
    }
    _gspropctrl_entrypoint_11(temp_v0, arg1);
    return 1;
}

f32 func_80098610(void **arg0)
{
    return *(f32 *)((u8 *)arg0[56] + 0x30);
}

u32 func_8009861C(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 224) + 46);
}

f32 func_80098628(void *arg0) {
    return *(f32 *)((u8 *)*&((Obj1E71B00_arg0 *)arg0)->unkE0 + 24);
}

u32 func_80098634(void *arg0) {
    return *(u8 *)((u8 *)*&((Obj1E71B00_arg0 *)arg0)->unkE0 + 47);
}

u32 func_80098640(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 224) + 45);
}

f32 func_8009864C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 224) + 16);
}

void func_80098658(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4, s32 arg5) {
    void func_800EE7F8(f32 *, f32 *);
    f32 *temp_a3;

    temp_a3 = *(f32 **)(arg0 + 0xE0);
    if (!(temp_a3[10] > 0.0f) || temp_a3[7] != arg1[0] || temp_a3[8] != arg1[1] || temp_a3[9] != arg1[2]) {
        func_800EE7F8(temp_a3, arg1);
        func_800EE7F8(*(f32 **)(arg0 + 0xE0) + 3, arg2);
        (*(f32 **)(arg0 + 0xE0))[6] = arg3;
        (*(s8 **)(arg0 + 0xE0))[0x2D] = arg4;
        (*(s8 **)(arg0 + 0xE0))[0x2F] = arg5;
        (*(s8 **)(arg0 + 0xE0))[0x2C] = 1;
    }
}

/* extern */

void func_80098730(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4, s32 arg5) {
    void func_80098658(u8 *, f32 *, f32 *, f32, s32, s32);
    func_80098658(arg0, arg1, arg2, arg3, arg4, arg5);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xE0)))) + (0x2E))) = 1;
}

/* extern */

void func_80098778(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    void func_80098658(u8 *, f32 *, f32 *, f32, s32, s32);
    func_80098658(arg0, arg1, arg2, arg3, arg4, arg5);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xE0)))) + (0x2E))) = 2;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xE0)))) + (0x30))) = arg6;
}

/* extern */

void func_800987CC(void *arg0) {
    s32 func_8009E7C8(void *, s32);
    s32 func_800C6E38(s32);
    f32 func_800D8FF8();
    f32 func_800F0E00(f32, f32);
    (*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0)) + (0x28))) = func_800F0E00((*(f32 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0)) + (0x28))) - func_800D8FF8(), 0.0f);
    if (((*(u8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0)) + (0x2C))) != 0) && (func_800C6E38(5) != 0)) {
        func_8009E7C8(arg0, 0xC);
    }
    (*(u8 *)((s8 *)((((Obj1E71B00_arg0 *)arg0)->unkE0)) + (0x2C))) = 0U;
}

void func_80098840(u8 *arg0) {
    void func_800EE7F8(f32 *, f32 *);

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xE0)))) + (0x2C))) = 0;
    func_800EE7F8((f32 *)(*(u8 **)(arg0 + 0xE0) + 0x1C), (f32 *)*(u8 **)(arg0 + 0xE0));
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xE0)))) + (0x28))) = (f32) 0.6f;
}
