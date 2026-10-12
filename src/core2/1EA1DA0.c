#include "core2/1EA1DA0.h"

extern s32 D_8012AB00;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C84B0.s")

int func_800C8560(void *arg0, s32 arg1) {
    return ((u8 *)arg0)[0x16] && (((u8 *)arg0)[0x15] & arg1);
}

u32 func_800C8588(u8 *arg0, s32 arg1) {
    return arg0[0x14];
}

u32 func_800C8594(u8 *arg0, u32 arg1) {
    return arg0[0x15] & arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C85A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C878C.s")

void func_800C87B8(s32 *arg0) {
    s32 func_800EE830();
    extern s32 D_8012AB04;
    func_800EE830(arg0, &D_8012AB04);
}

void func_800C87DC(s32 *arg0) {
    s32 func_800EE830();
    extern s32 D_8012AB10;
    func_800EE830(arg0, &D_8012AB10);
}

void func_800C8800(s32 arg0, f32 *arg1) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    void *vector_at(s32, s32, s32);
    func_800EE88C(arg1, vector_at(D_8012AB00, arg0 - 1, arg0));
}

/* extern */

void func_800C883C(s32 arg0, void *arg1) {
    void *vector_at(s32, s32, s32);
    void *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1, arg0);
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (6)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (8)));
}

void func_800C8898(s32 arg0, s32 arg1) {
    void *vector_at(s32, s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1, arg1);
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (6)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (8)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x10)));
}

void func_800C8900(s32 arg0, u8 *arg1) {
    void func_800EFA88(void *arg0, s32 arg1, s32 arg2, s32 arg3);
    void func_800F2EE0(void *arg0, void *arg1);
    void *vector_at(s32, s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1, arg0);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x17))) == 0) {
        func_800EFA88(arg1, 0, 0, 0);
        return;
    }
    func_800F2EE0(arg1, temp_v0 + 0xA);
}

void func_800C8960(s32 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800EE830(s32 *, s32);
    extern s32 D_8012AB1C;
    extern f32 D_8012AB28;
    if (arg0 != NULL) {
        func_800EE830(arg0, (s32) &D_8012AB1C);
    }
    if (arg1 != NULL) {
        func_800EE7F8(arg1, &D_8012AB28);
    }
}

/* extern */

u8 func_800C89A8(s32 arg0) {
    void *vector_at(s32, s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1, arg0)) + (0x15)));
}

/* extern */

u8 func_800C89D8(s32 arg0) {
    void *vector_at(s32, s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1, arg0)) + (0x19)));
}

void func_800C8A08(void) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_8012AB00;
    u32 sp1C;
    u32 temp_v0;
    u32 var_v1;

    sp1C = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    var_v1 = sp1C;
    if (var_v1 < temp_v0) {
        do {
            if ((*(u8 *)((s8 *)(var_v1) + (0x15))) != 0) {
                if ((*(u8 *)((s8 *)(var_v1) + (0x16))) == 2) {
                    (*(u8 *)((s8 *)(var_v1) + (0x15))) = 0U;
                } else {
                    (*(u8 *)((s8 *)(var_v1) + (0x16))) = 0U;
                }
                if ((*(u8 *)((s8 *)(var_v1) + (0x18))) != 0) {
                    (*(u8 *)((s8 *)(var_v1) + (0x18))) = 0U;
                }
                (*(s8 *)((s8 *)(var_v1) + (0x19))) = 0;
            }
            var_v1 += 0x1C;
        } while (var_v1 < temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8B84.s")

/* extern */

void func_800C8BF4(void) {
    s32 vector_size(s32);
    vector_size(D_8012AB00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8C18.s")

void func_800C8C90(s32 arg0) {
    s32 func_800EE830(s32 *, s32);
    extern s32 D_8012AB04;
    func_800EE830(&D_8012AB04, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8E84.s")

void func_800C8F08(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800EE830(s32 *, s32);
    void func_800EF2A0(f32[3]);
    extern s32 D_8012AB1C;
    extern f32 D_8012AB28;
    if (arg0 != 0) {
        func_800EE830(&D_8012AB1C, arg0);
    }
    if (arg1 != NULL) {
        func_800EE7F8(&D_8012AB28, arg1);
        func_800EF2A0(&D_8012AB28);
    }
}

/* extern */

void func_800C8F64(s32 arg0, s32 arg1) {
    void *vector_at(s32, s32, s32);
    void *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1, arg0);
    if (arg1 != (*(u8 *)((s8 *)(temp_v0) + (0x15)))) {
        (*(u8 *)((s8 *)(temp_v0) + (0x15))) = (u8) arg1;
        (*(s8 *)((s8 *)(temp_v0) + (0x16))) = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C8FB0.s")

void func_800C8FE0(s32 arg0, s32 arg1) {
    void *vector_at(s32, s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1, arg1);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x16))) == 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0x16))) = (u8) (arg1 != (*(u8 *)((s8 *)(temp_v0) + (0x17))));
    }
    (*(u8 *)((s8 *)(temp_v0) + (0x17))) = (u8) arg1;
    if (arg1 == 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x18))) = 1;
    }
}

/* extern */

u8 func_800C9044(s32 arg0) {
    void *vector_at(s32, s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1, arg0)) + (0x17)));
}

/* extern */

void func_800C9074(void) {
    s32 vector_defrag(s32);
    if (D_8012AB00 != 0) {
        D_8012AB00 = vector_defrag(D_8012AB00);
    }
}

void func_800C90AC()
{
    _gclightsDll_entrypoint_0(&D_8012AB00);
}

void func_800C90D0()
{
    _gclightsDll_entrypoint_1(&D_8012AB00);
}

/* extern */

void func_800C90F4(s32 arg0) {
    s32 _gclightsDll_entrypoint_2(s32 *, s32);
    _gclightsDll_entrypoint_2(&D_8012AB00, arg0);
}

void * func_800C911C(void) {
    return &D_8012AB00;
}

/* extern */

void func_800C9128(s32 arg0) {
    s32 _gclightsDll_entrypoint_3(s32 *, s32);
    _gclightsDll_entrypoint_3(&D_8012AB00, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C91C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9214.s")

void func_800C929C()
{
	D_8012AB54 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C92A8.s")

void func_800C9310(void) {
    s32 _gctransitionDll_entrypoint_5(s32);
    extern s32 D_8012AB40;
    if ((*(u8 *)((s8 *)(&D_8012AB40) + (0x14))) != 0) {
        do {
            _gctransitionDll_entrypoint_5((*(s32 *)((s8 *)(&D_8012AB40) + (0))));
        } while ((*(u8 *)((s8 *)(&D_8012AB40) + (0x14))) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C940C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9484.s")

/* extern */

s32 func_800C9510(void) {
    s32 _gctransitionDll_entrypoint_4(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_4(temp_v0);
    }
    return 0;
}

/* extern */

s32 func_800C954C(void) {
    s32 _gctransitionDll_entrypoint_3(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 0;
}

f32 func_800C9588(void) {
    return 300.0f;
}

/* extern */

void func_800C9598(void) {
    s32 _gctransitionDll_entrypoint_1(s32);
    s32 func_800C9150(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_1(var_a0);
}

/* extern */

s32 func_800C95D4(void) {
    s32 _gctransitionDll_entrypoint_2(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_2(temp_v0);
    }
    return 1;
}

/* extern */

void func_800C9610(void) {
    s32 _gctransitionDll_entrypoint_6(s32);
    s32 func_800C9150(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_6(var_a0);
}

/* extern */

void func_800C964C(s32 arg0) {
    s32 _gctransitionDll_entrypoint_7(s32, s32);
    s32 func_800C9150(s32);
    s32 func_800C91C8(s32);
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg0);
}

/* extern */

void func_800C968C(s32 arg0, s32 arg1) {
    s32 _gctransitionDll_entrypoint_7(s32, s32);
    s32 func_800C9150(s32);
    s32 func_800C91C8();
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800C91C8();
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(arg0);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C96CC.s")

/* extern */

s32 func_800C9714(void) {
    s32 _gctransitionDll_entrypoint_3(s32);
    s32 func_800C91C8();
    s32 temp_v0;

    temp_v0 = func_800C91C8();
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C986C.s")

void func_800C9974()
{
    func_800FC63C();
}

void func_800C9994()
{
    func_800FCAE0();
}

void func_800C99B4(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C3FF0(s32, f32, s32);
    func_800C3FF0(arg0, arg1 / 1000.0f, arg2);
}

/* extern */

void func_800C99F0(u8 *arg0) {
    s32 func_800C4244(s32, s32, s32, u8 *, f32, f32);
    func_800C4244((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4))), (*(s32 *)((s8 *)(arg0) + (8))), arg0 + 0xC, (*(f32 *)((s8 *)(arg0) + (0x18))), (*(f32 *)((s8 *)(arg0) + (0x1C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9B30.s")

void func_800C9B84(void) {
    s32 vector_clear(s32);
    extern s32 D_8012AB60;
    if (D_8012AB60 != 0) {
        vector_clear(D_8012AB60);
    }
}

void func_800C9BB4(f32 time, s32 sound_id, f32 volume, s32 rate) {
    void func_800C9E64(f32, void *, s32, s32, s32);
    func_800C9E64(time, func_800C99B4, sound_id, (s32)(volume * 1000.0f), rate);
}

void func_800C9C04(f32 arg0, u32 arg1, u32 arg2) {
    func_800C9E20(arg0, (u32 *) func_800C9974, arg1, arg2);
}

void func_800C9C34(f32 time, s32 track_id, s32 volume, s32 duration) {
    void func_800C9E64(f32, void *, s32, s32, s32);
    func_800C9E64(time, func_800C9994, track_id, volume, duration);
}

void func_800C9C70(f32 time, u32 id, f32 volume, u32 rate, f32 position[3], f32 near, f32 far) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800C9EF8(f32, void *, void *);
    struct { u32 id; f32 volume; u32 rate; f32 position[3]; f32 near; f32 far; } data;
    data.id = id;
    data.rate = rate;
    data.volume = volume;
    data.near = near;
    data.far = far;
    func_800EE7F8(data.position, position);
    func_800C9EF8(time, func_800C99F0, &data);
}

void func_800C9CD0(f32 time, s32 arg1, s32 arg2, s32 arg3, f32 *position, s16 arg5) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800C9EF8(f32, void *, void *);
    void func_800C9A38(void *);
    struct { s32 arg1; s32 arg2; s32 arg3; f32 position[3]; s16 arg5; } data;
    data.arg1 = arg1;
    data.arg2 = arg2;
    data.arg3 = arg3;
    data.arg5 = arg5;
    if (position != NULL) {
        func_800EE7F8(data.position, position);
    } else {
        func_800EFD24(data.position);
    }
    func_800C9EF8(time, func_800C9A38, &data);
}

void func_800C9D38(f32 arg0, s32 arg1) {
    void func_800C9DE4(f32, void *, s32);
    extern s32 func_800C9AB0;
    func_800C9DE4(arg0, &func_800C9AB0, arg1);
}

void func_800C9D60(f32 time, s32 arg0) {
    void func_800C9DE4(f32, void *, s32);
    void func_800A54F8(s32);
    func_800C9DE4(time, func_800A54F8, arg0);
}

void func_800C9D88(f32 arg0) {
    void func_800C9DAC(f32, void *);
    extern s32 func_800A5524;
    func_800C9DAC(arg0, &func_800A5524);
}

void func_800C9DAC(f32 time, void *funcPtr) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    func_800C9750(time, 0, funcPtr, 0, 0, 0, 0, 0);
}

void func_800C9DE4(f32 time, void *funcPtr, s32 arg0) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    func_800C9750(time, 1, funcPtr, arg0, 0, 0, 0, 0);
}

void func_800C9E20(f32 time, u32 *funcPtr, u32 arg0, u32 arg1) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    func_800C9750(time, 2, funcPtr, arg0, arg1, 0, 0, 0);
}

void func_800C9E64(f32 time, void *funcPtr, s32 arg0, s32 arg1, s32 arg2) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    func_800C9750(time, 3, funcPtr, arg0, arg1, arg2, 0, 0);
}

void func_800C9EAC(f32 time, void *funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    func_800C9750(time, 4, funcPtr, arg0, arg1, arg2, arg3, 0);
}

void func_800C9EF8(f32 time, void *funcPtr, void *argPtr) {
    void *func_800C9750(f32, s32, void *, s32, s32, s32, s32, s32);
    void rare_memcpy(void *, void *, s32);
    u8 *q = func_800C9750(time, 6, funcPtr, 0, 0, 0, 0, 0);
    rare_memcpy(q + 0x20, argPtr, 0x50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9F48.s")

int func_800C9F94(void) {
    s32 vector_size(s32);
    extern s32 D_8012AB60;
    return D_8012AB60 == 0 || vector_size(D_8012AB60) == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800C9FD0.s")

void func_800CA060(void) {
    s32 vector_free(s32);
    extern s32 D_8012AB60;
    if (D_8012AB60 != 0) {
        vector_free(D_8012AB60);
        D_8012AB60 = 0;
    }
}

void func_800CA098(void) {
    extern f32 D_8012AB64;
    D_8012AB64 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1DA0/func_800CA0A8.s")

void func_800CA174(void) {
    s32 vector_defrag(s32);
    extern s32 D_8012AB60;
    if (D_8012AB60 != 0) {
        D_8012AB60 = vector_defrag(D_8012AB60);
    }
}
