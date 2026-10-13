#include "core2/1E9A960.h"

typedef struct {
    u8 pad0[0xC];
    f32 fade_inner_radius_sqr;
    f32 fade_outer_radius_sqr;
    u8 pad14[0x4C];
    u8 unk60;
    u8 unk61;
    u8 pad62[0xA];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    u8 pad78;
    u8 unk79;
} SoundSourceView;

/* extern */

void func_800C1070(f32 *arg0, f32 *arg1) {
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    void func_800E3980(f32 *);
    s32 func_800EA068(s32);
    s32 func_800F5310();
    s32 func_800F5EF8(s32);
    s32 func_8010FFA8(s32);
    void func_8010FFB0(s32, f32 *, f32 *);
    s32 temp_v0;
    s32 sp28;
    f32 sp1C[3];

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            _plsu_entrypoint_0(arg0, arg1);
            return;
        }
        temp_v0 = func_800F5EF8(_plsu_entrypoint_0(arg0, arg1));
        sp28 = temp_v0;
        if (func_8010FFA8(temp_v0) != 2) {
            func_8010FFB0(sp28, arg0, sp1C);
        }
    } else {
        func_800E3980(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1104.s")

void func_800C11F8(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char value : 3;
        unsigned char rest : 5;
    };
    ((struct Flags *)arg0)->value = arg1;
}

void func_800C1210(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char first : 3;
        unsigned char value : 3;
        unsigned char last : 2;
    };
    ((struct Flags *)arg0)->value = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C122C.s")

void func_800C13A0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) | arg1);
}

void func_800C13B0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) & ~arg1);
}

u32 func_800C13C4(u16 *arg0, u32 arg1)
{
    return (u32) arg0[0x3E] & arg1;
}

s32 func_800C13D0(void *arg0, s32 arg1) {
    return ((*(u16 *)((s8 *)(arg0) + (0x7C))) & arg1) == 0;
}

void func_800C13E4(void) {
    extern s32 D_80128B90;
    int i;
    for (i = 0; i < 60; i++) {
        *((u8 *)&D_80128B90 + i * 0x80 + 0x78) = 0;
    }
}

void *func_800C1414(u8 arg0) {
    extern s32 D_80128B90;
    s32 index = arg0;
    s32 *base = &D_80128B90;
    return (void *)((u8 *)base + (index << 7));
}

u8 *func_800C1430(s32 arg0) {
    extern s32 D_80128B10;
    return (u8 *) &D_80128B10 + ((arg0 << 3) - 8);
}

s32 func_800C1448(s32 arg0) {
    extern s64 D_80128B08;
    return *(s32 *)((u8 *)&D_80128B08 + (arg0 << 3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C145C.s")

void func_800C1568(s32 arg0) {
    extern s32 D_80128B0C;
    *((s32 *)((u8 *)&D_80128B0C + (arg0 << 3))) = 0;
}

void func_800C157C(void) {
    extern s32 D_80128B10;
    extern s32 D_80128B90;
    u32 end;
    s32 *var_v1;

    end = (u32)&D_80128B90;
    for (var_v1 = &D_80128B10; ; ) {
    var_v1 += 8;
    ((s32 *)var_v1)[-6] = 0;
    ((s32 *)var_v1)[-5] = 0;
    ((s32 *)var_v1)[-4] = 0;
    ((s32 *)var_v1)[-3] = 0;
    ((s32 *)var_v1)[-2] = 0;
    ((s32 *)var_v1)[-1] = 0;
    ((s32 *)var_v1)[-8] = 0;
    ((s32 *)var_v1)[-7] = 0;
        if ((u32)var_v1 == end) {
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C15BC.s")

void func_800C16A4(u8 index) {
    extern u8 D_80128C08[][0x80];
    SoundSourceView *ptr = func_800C1414(index);
    if (ptr->unk79) {
        func_800C1568(ptr->unk79);
        ptr->unk79 = 0;
    }
    D_80128C08[index][0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C16F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1860.s")

void func_800C18C8(s32 index, s32 a, s32 b, s32 c, s32 d) {
    s32 func_800C122C(s32, s32, s32, s32);
    s32 func_800DC48C(s32, s32);
    s32 parameters;
    s32 source;
    if (index) {
        source = func_800C1448(index);
        parameters = func_800C122C(a, b, c, d);
        func_800DC48C(source, parameters);
    }
}

/* extern */

void func_800C191C(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC4B0(s32, s32);
    if (arg0 != 0) {
        func_800DC4B0(func_800C1448(), arg1);
    }
}

/* extern */

void func_800C1950(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC42C(s32, s32);
    if (arg0 != 0) {
        func_800DC42C(func_800C1448(), arg1);
    }
}

void func_800C1984(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C1448(s32);
    void func_800DC454(s32, u16);
    extern f32 D_8011A878;

    if (arg0 != 0) {
        if (arg2 == 0) {
            arg1 = (s32) ((f32) arg1 * D_8011A878);
        }
        func_800DC454(func_800C1448(arg0), (u16) arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C19E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C269C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2718.s")

void func_800C2840(s32 uid, f32 volume, s32 sampleRate, s32 arg3, s32 arg4){
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C32C4(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C36F4(u8, s32);
    void func_800C3BDC(u8);

    s32 indx = func_800C2E04();
    if(indx){
        func_800C301C(indx, uid);
        func_800C3058(indx, sampleRate);
        func_800C31DC(indx, volume);
        func_800C32C4(indx, arg3);
        func_800C330C(indx, 1);
        func_800C3418(indx, arg4);
        func_800C36F4(indx, 0);
        func_800C3BDC(indx);
    }
}

void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2900.s")

void func_800C2A08(void) {
    void func_800C4308(f32, f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    func_800C28D8();
    func_800C4308(0.0f, 1.0f);
    func_800C4B64(1.0f);
    func_800C4B70(22000);
    func_800C4B7C(-1);
}

void func_800C2A5C(s32 arg0, s32 arg1) {
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2C4C.s")

s32 func_800C2E04(void) {
    u8 func_800C145C(void);
    s32 func_800C2C4C(u8);
    u8 index = func_800C145C();
    if (index == 0) return 0;
    func_800C2C4C(index);
    return index;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2E40.s")

s32 func_800C2FDC(u8 index) {
    void *ptr = func_800C1414(index);
    func_800C3CE8(index);
    func_800C1210(ptr, 3);
    return 0;
}

void func_800C301C(u8 id, s32 arg1) {
    if (id != 0) {
        (*(s16 *)((s8 *)(func_800C1414(id)) + (0x58))) = (s16) arg1;
    }
}

void func_800C3058(u8 index, s32 sample_rate) {
    struct Flags { u8 padding[0x78]; u32 high : 28; u32 varying_rate : 1; u32 low : 3; };
    u8 *source;
    if (index) {
        source = func_800C1414(index);
        *(s16 *)(source + 0x5A) = sample_rate;
        if (((struct Flags *)source)->varying_rate == 0) {
            *(s16 *)(source + 0x4C) = sample_rate;
            *(s16 *)(source + 0x4E) = sample_rate;
            *(f32 *)(source + 0x50) = 0.0f;
        }
        func_800C13A0(source, 8);
    }
}

void func_800C30B8(u8 index, s32 arg1, f32 position[3], f32 min_dist, f32 max_dist) {
    void func_800C1070(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800C3058(u8, s32);
    f32 pos[3];
    f32 distance;
    f32 scale;
    func_800C1070(pos, position);
    distance = func_800EEAD4(position, pos);
    if (max_dist <= distance) scale = 0.0f;
    else {
        if (min_dist <= distance) scale = 1.0f - (distance - min_dist) / (max_dist - min_dist);
        else scale = 1.0f;
    }
    func_800C3058(index, (s32)arg1 * scale);
}

/* extern */

void func_800C316C(u8 arg0, s32 arg1, s32 arg2, f32 arg3) { struct Flags { u8 pad[0x7B]; unsigned char first : 4; unsigned char flag : 1; unsigned char last : 3; }; void *temp_v0; if (arg0 != 0) { temp_v0 = func_800C1414(arg0); ((struct Flags *)temp_v0)->flag = 1; (*(s16 *)((s8 *)(temp_v0) + (0x4C))) = (s16) arg1; (*(s16 *)((s8 *)(temp_v0) + (0x4E))) = (s16) arg2; (*(f32 *)((s8 *)(temp_v0) + (0x50))) = arg3; (*(s16 *)((s8 *)(temp_v0) + (0x5A))) = 0; func_800C13A0(temp_v0, 8); } }

void func_800C31DC(u8 index, f32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk6C = value;
        func_800C13A0(ptr, 4);
    }
}

void func_800C3224(u8 index, f32 lower, f32 upper, f32 step) {
    f32 func_800C395C(u8);
    f32 func_800DC264(f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 rate = func_800C395C(index);
    if (rate < lower) {
        rate += step;
    } else if (upper < rate) {
        rate -= step;
    } else {
        rate += func_800DC264(-step, step);
        rate = func_800F0D50(rate, lower, upper);
    }
    func_800C31DC(index, rate);
}

void func_800C32C4(u8 index, s32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk60 = value;
        func_800C13A0(ptr, 16);
    }
}

void func_800C330C(u8 id, s32 arg1) {
    extern void func_800C11F8(void *, s32);
    extern void *func_800C1414(u8);

    if (id != 0) {
        func_800C11F8(func_800C1414(id), arg1);
    }
}

void func_800C334C(u8 index, s32 value) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk61 = value;
        func_800C13A0(ptr, 256);
    }
}

void func_800C3394(u8 arg0, s32 arg1, s32 arg2) {
    void *ptr;
    if (arg0 != 0) {
        ptr = func_800C1414(arg0);
        (*(s32 *)((s8 *)ptr + 0x64)) = arg1;
        (*(s32 *)((s8 *)ptr + 0x68)) = arg2;
    }
}
void func_800C33DC(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x1B))) = (s8) arg1;
    }
}

void func_800C3418(u8 indx, s32 arg1){

    void *temp_v0;
    if(indx){
        temp_v0 = func_800C1414(indx);
        switch(arg1){
            case 0:
                func_800C13B0(temp_v0, 0x40);
                func_800C13B0(temp_v0, 0x80);
                break;
            case 1:
                func_800C13A0(temp_v0, 0x40);
                func_800C13B0(temp_v0, 0x80);
                break;
            case 2:
                func_800C13A0(temp_v0, 0x40);
                func_800C13A0(temp_v0, 0x80);
                break;
        }
    }
}

void func_800C34CC(u8 index, s32 enabled) {
    void *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13B0(ptr, 512); }
        else { func_800C13A0(ptr, 512); }
    }
}

void func_800C3528(u8 index, s32 enabled) {
    void *ptr;
    if (index) {
        ptr = func_800C1414(index);
        if (enabled) { func_800C13A0(ptr, 1024); }
        else { func_800C13B0(ptr, 1024); }
    }
}

void func_800C3584(u8 index, f32 min, f32 max) {
    void func_800C368C(u8, s32);
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->fade_inner_radius_sqr = min * min;
        ptr->fade_outer_radius_sqr = max * max;
        func_800C368C(index, 1);
    }
}

void func_800C35E8(u8 index, f32 position[3]) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800C368C(u8, s32);
    s32 func_800EA05C(void);
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        func_800EE7F8((f32 *)ptr, position);
        func_800C368C(index, 1);
        *(s16 *)(ptr + 0x5E) = func_800EA05C();
    }
}

void func_800C3648(u8 index, s32 arg1) {
    s32 func_800EA05C(void);
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(s16 *)(ptr + 0x5E) = func_800EA05C();
    }
}

/* extern */

void func_800C368C(u8 arg0, s32 arg1) {
    void *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        if (arg1) { func_800C13A0(ptr, 2); }
        else { func_800C13B0(ptr, 2); }
        func_800C33DC(arg0, arg1);
    }
}

void func_800C36F4(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x62))) = (s8) arg1;
    }
}

void func_800C3730(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(u16 *)(ptr + 0x7A) = (*(u16 *)(ptr + 0x7A) & 0xFC3F) | 0x40;
        *(f32 *)(ptr + 0x28) = arg3;
        *(f32 *)(ptr + 0x2C) = arg2;
        func_800C31DC(index, arg1);
    }
}

void func_800C3798(u8 index, f32 arg1, f32 arg2) {
    SoundSourceView *ptr;
    if (index) {
        ptr = func_800C1414(index);
        ptr->unk70 = arg1;
        ptr->unk74 = arg2;
    }
}

void func_800C37E0(u8 index, f32 arg1, f32 arg2, f32 arg3) {
    u8 *ptr;
    if (index) {
        ptr = func_800C1414(index);
        *(u16 *)(ptr + 0x7A) = (*(u16 *)(ptr + 0x7A) & 0xFC3F) | 0x80;
        *(f32 *)(ptr + 0x30) = arg3;
        *(f32 *)(ptr + 0x2C) = arg1;
        *(f32 *)(ptr + 0x28) = arg2;
        func_800C31DC(index, (arg1 + arg2) * 0.5f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3868.s")

s16 func_800C38E4(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x58)));
}

s16 func_800C3920(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x5A)));
}

f32 func_800C395C(u8 index) {
    SoundSourceView *ptr;
    if (!index) return 1.0f;
    else {
        ptr = func_800C1414(index);
        return ptr->unk6C;
    }
}

s32 func_800C39A0(u8 id) {
    u16 *p = (u16 *) ((u8 *) func_800C1414(id) + 0x7A);
    return ((u32) *p) >> 13;
}

/* extern */

s32 func_800C39D0(u16 *arg0) {
    s32 func_800C19E4(u16 *, s16);
    s32 var_v1;

    if (func_800C13C4(arg0, 0x800U) != 0) {
        return 1;
    }
    if (((*(u8 *)((s8 *)(arg0) + (0x63))) != 0) && (func_800C13C4(arg0, 2U) != 0)) {
        var_v1 = func_800C19E4(arg0, (*(s16 *)((s8 *)(arg0) + (0x5A))));
    } else {
        var_v1 = (*(s16 *)((s8 *)(arg0) + (0x5A)));
    }
    return var_v1 >= 0x65;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3AE0.s")

/* extern */

void func_800C3B8C(u8 arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7B];
        unsigned char first : 6;
        unsigned char value : 1;
        unsigned char last : 1;
    };
    struct Flags *ptr;
    if (arg0) {
        ptr = func_800C1414(arg0);
        ptr->value = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3E00.s")

void func_800C3E88(s32 uid){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, 22000, 0, 2);
}

void func_800C3EB8(s32 uid){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, 22000, 0, 0);
}

void func_800C3EE4(s32 uid, s32 sampleRate){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, 1.0f, sampleRate, 0, 2);
}

void func_800C3F14(s32 uid, f32 arg1){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, arg1, 22000, 0, 2);
}

void func_800C3F48(u32 arg0) {
    func_800C2840(arg0 & 0x7FF, (f32) ((arg0 >> 0x15) & 0x7FF) / 1024, (arg0 >> 6) & 0x7FE0, 0, 2);
}

void func_800C3FC0(s32 uid, f32 pitch, s32 arg2){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, pitch, arg2, 0, 2);
}

void func_800C3FF0(s32 uid, f32 arg1, s32 arg2){
    void func_800C2840(s32, f32, s32, s32, s32);

    func_800C2840(uid, arg1, arg2, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C401C.s")

void func_800C4104(s32 arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);
    func_800C401C(arg0, arg1, arg2, (f32 *)arg3, arg4, arg5, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4140.s")

void func_800C4208(s32 uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);

    func_800C401C(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 1);
}

void func_800C4244(s32 uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    void func_800C401C(s32, f32, u32, f32 *, f32, f32, s32);

    func_800C401C(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 0);
}

void func_800C427C()
{
    func_800C2718();
}

u8 func_800C429C(s32 uid, s32 arg1){
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);

    u8 indx = func_800C2E04();
    func_800C301C(indx, uid);
    func_800C330C(indx, arg1);
    return indx;
}

/* extern */

void func_800C42E0(s32 arg0) {
    s32 func_800DC548(s32, s32, s32);
    func_800DC548(0, arg0 - 0x3E9, arg0);
}

void func_800C4308(f32 arg0, f32 arg1) {
    extern f32 D_8011A870;
    extern f32 D_8011A874;
    D_8011A870 = arg0;
    D_8011A874 = arg1;
}

void func_800C431C(u8 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x63))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4AF0.s")

void func_800C4B64(f32 arg0) {
    extern f32 D_8012A990;
    *(f32 *)((u8 *)&D_8012A990 + 0) = arg0;
}

void func_800C4B70(s32 arg0) {
    extern s16 D_8012A994;
    *(s16 *)((u8 *)&D_8012A994 + 0) = arg0;
}

void func_800C4B7C(s32 arg0) {
    extern s16 D_8012A996;
    *(s16 *)((u8 *)&D_8012A996 + 0) = arg0;
}
