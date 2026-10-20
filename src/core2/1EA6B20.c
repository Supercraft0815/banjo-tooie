#include "common.h"

void func_800CD230(f32 arg0) {
    extern f32 D_8012B010;
    *(f32 *)((u8 *)&D_8012B010 + 0) = arg0;
}

s32 func_800CD23C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800BD708(s32 *, s32 *, s32, s32, f32);
    s32 func_800BDAD4(s32 position[3]);
    void *func_800BDC44(void);
    s32 func_800EA628(s32, s32, s32, s32, s32);
    extern f32 D_8012B010;
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    s32 temp_v0;
    s32 var_s5;

    var_s5 = 0;
    func_800BD708(min, max, arg0, arg1, D_8012B010);
    min[1]--;
    for (cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++) {
        for (cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++) {
            for (cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++) {
                temp_v0 = func_800EA628(func_800BDAD4(cube_indx), arg0, arg1, arg2, arg3);
                if (temp_v0 != 0) {
                    var_s5 = temp_v0;
                }
            }
        }
    }
    temp_v0 = func_800EA628(func_800BDC44(), arg0, arg1, arg2, arg3);
    if (temp_v0 != 0) {
        var_s5 = temp_v0;
    }
    return var_s5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD544.s")

s32 func_800CD6B4(u8 *arg0, f32 *arg1, f32 arg2, f32 *arg3, s32 arg4) {
    typedef struct {
        u32 unused:27;
        u32 value:4;
        u32 rest:1;
    } QueryFlags;
    typedef struct {
        u32 unused:11;
        u32 value:4;
        u32 rest:17;
    } ResultFlags;
    typedef struct {
        u32 unused[3];
        u8 *(*getCustom)(void);
    } Marker;
    typedef struct {
        u32 unused[3];
        s32 (*test)(u8 *, f32 *, f32, f32 *, u32);
    } Custom;
    f32 func_800EC75C(void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    f32 radius;
    f32 sp78[3];
    s32 result;
    f32 sp68[3];
    s32 i;
    u8 *custom;
    f32 sp54[3];

    if (((Marker *)arg0)->getCustom != NULL) {
        custom = ((Marker *)arg0)->getCustom();
    } else {
        custom = NULL;
    }
    func_800EE7F8(sp78, arg1);
    for (i = 0; i < arg4; i++) {
        if (custom != NULL && ((Custom *)custom)->test != NULL) {
            result = ((Custom *)custom)->test(arg0, sp78, arg2, sp68, ((QueryFlags *)(arg0 + 0x18))->value);
            if (result != 0) {
                ((ResultFlags *)(arg0 + 0x18))->value = result;
                return 1;
            }
        } else {
            radius = func_800EC75C(arg0, sp54);
            if (func_800EEB40(sp78, sp54) < (radius + arg2) * (radius + arg2)) {
                return 1;
            }
        }
        func_800EF04C(sp78, arg3);
    }
    return 0;
}

u8 *func_800CD820(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    typedef struct {
        u8 *marker;
        s32 unk4;
        u32 unk8:27;
        u32 active:1;
        u32 unk9:3;
        u32 isMarker:1;
    } HitProp;
    typedef struct {
        u32 unused:22;
        u32 enabled:1;
        u32 rest:9;
    } MarkerFlags;
    typedef struct {
        u32 unused:14;
        u32 disabled:1;
        u32 rest:17;
    } ActorFlags;
    f32 _subaddiecustomhits_entrypoint_5(void *, f32 *);
    s32 *func_800BE444(f32 *);
    s16 func_800CB854(s32 *);
    s32 func_800CD6B4(u8 *, f32 *, f32, f32 *, s32);
    HitProp *func_800E9E88(s32);
    HitProp *func_800E9EB4(s32);
    u8 *func_800EC3C4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_801259A0;
    f32 length;
    f32 reach;
    f32 count;
    f32 sp100[3];
    f32 spF4[3];
    f32 spE8[3];
    f32 spDC[3];
    f32 rounded;
    f32 spCC[3];
    f32 spC0[3];
    s32 *spBC;
    f32 spB0[3];
    f32 nearestDistance;
    s32 samples;
    s32 spA4;
    f32 distance;
    f32 radius;
    HitProp *prop;
    HitProp *end;
    u8 *marker;
    u8 *actor;
    f32 sp80[3];
    u8 *nearest;
    u8 *callbacks;

    if (func_800CB854(NULL) != 0) {
        spA4 = 1 << (func_800CB854(NULL) + 0x1F);
    } else {
        spA4 = 0;
    }
    func_800EFB24(sp100, arg2, arg1);
    length = func_800EEF94(sp100);
    func_800EF410(spF4, sp100);
    reach = 2.0f * arg3;
    count = length / reach;
    samples = (s32)count;
    rounded = (f32)samples;
    if (rounded <= count) {
        samples++;
    }
    func_800EFE50(spB0, arg1, arg2, 0.5f);
    spBC = func_800BE444(spB0);
    nearestDistance = 0.0f;
    nearest = NULL;
    func_800EFA20(spDC, spF4, reach);
    func_800EFA20(spE8, spDC, (count - rounded) * 0.5f);
    func_800EE7F8(spCC, spE8);
    func_800EE88C(spC0, (s16 *)(arg0 + 0x1E));
    func_800EF04C(spC0, arg1);
    func_800EF04C(spC0, spCC);
    func_800EE7F8(spCC, spDC);
    if (*spBC != 0) {
        do {
            prop = func_800E9E88(*spBC);
            end = func_800E9EB4(*spBC);
            if (prop < end) {
                do {
                    if (prop->active && prop->isMarker) {
                        marker = prop->marker;
                        if (((MarkerFlags *)(marker + 0x28))->enabled && arg0 != marker) {
                            if (*(u16 *)(marker + 0x14) != 0 && *(u16 *)(marker + 0x14) != 0xFFFF && (*(u16 *)(marker + 0x18) & 1)) {
                                actor = (u8 *)func_80106790((Unk80132ED0 *)marker);
                                if (!((ActorFlags *)(actor + 0x64))->disabled && !(*(u16 *)(actor + 0x66) & spA4)) {
                                    reach = (f32)samples * arg3 * D_801259A0;
                                    radius = _subaddiecustomhits_entrypoint_5(actor, sp80);
                                    distance = func_800EEB40(sp80, spB0);
                                    if (!((radius + reach) * (radius + reach) < distance)) {
                                        distance = func_800EEB40(sp80, spC0);
                                        if (nearest == NULL || !(nearestDistance < distance)) {
                                            callbacks = func_800EC3C4(marker);
                                            if (*(s32 (**)(u8 *, u8 *))(callbacks + 0x10) == NULL ||
                                                (*(s32 (**)(u8 *, u8 *))(callbacks + 0x10))(marker, arg0) != 0) {
                                                if (func_800CD6B4(marker, spC0, arg3, spCC, samples) != 0) {
                                                    nearest = marker;
                                                    nearestDistance = distance;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    prop++;
                } while (prop < end);
            }
            spBC++;
        } while (*spBC != 0);
    }
    return nearest;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CDBA8.s")

s32 func_800CDFA8(s32 arg0, s32 *arg1) {
    extern u8 D_8012AF70[];
    *arg1 = D_8012AF70[arg0 + 0x80];
    return *(s32 *)(D_8012AF70 + (arg0 << 2));
}
