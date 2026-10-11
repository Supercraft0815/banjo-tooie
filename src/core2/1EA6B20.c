#include "common.h"

void func_800CD230(f32 arg0) {
    extern f32 D_8012B010;
    *(f32 *)((u8 *)&D_8012B010 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA6B20/func_800CD6B4.s")

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
