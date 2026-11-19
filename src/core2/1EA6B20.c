#include "common.h"
#ifdef BT_NATIVE
#include "vector.h"

enum { MARKER_HIT_CAPACITY = 32 };
Unk80132ED0 *D_8012AF70[MARKER_HIT_CAPACITY];
#ifdef BT_ILP32
u8 D_8012AFF0[MARKER_HIT_CAPACITY];
#else
s32 D_8012AFF0[MARKER_HIT_CAPACITY];
#endif

typedef struct { Unk80132ED0 *marker; s32 sphere; } MarkerHit;
static Vector *extra_hits;
static s32 marker_hit_count;

static void marker_hits_clear(void) {
    marker_hit_count = 0;
    if (extra_hits) vector_clear(extra_hits);
}

static void marker_hits_append(Unk80132ED0 *marker, s32 sphere) {
    if (marker_hit_count < MARKER_HIT_CAPACITY) {
        D_8012AF70[marker_hit_count] = marker;
        D_8012AFF0[marker_hit_count] = sphere;
    } else {
        MarkerHit *hit;
        if (!extra_hits) extra_hits = vector_new(sizeof(MarkerHit), MARKER_HIT_CAPACITY);
        hit = vector_push_back(&extra_hits);
        hit->marker = marker;
        hit->sphere = sphere;
    }
    ++marker_hit_count;
}

Unk80132ED0 *func_800CDFA8(s32 index, s32 *sphere) {
    MarkerHit *hit;
    if (index < 0 || index >= marker_hit_count) {
        if (sphere) *sphere = -1;
        return NULL;
    }
    if (index < MARKER_HIT_CAPACITY) {
        if (sphere) *sphere = D_8012AFF0[index];
        return D_8012AF70[index];
    }
    hit = (MarkerHit *)vector_begin(extra_hits) + (index - MARKER_HIT_CAPACITY);
    if (sphere) *sphere = hit->sphere;
    return hit->marker;
}
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_world_collision.h"
static f32 D_8012B010;
#endif

void func_800CD230(f32 arg0) {
    extern f32 D_8012B010;
    *(f32 *)((u8 *)&D_8012B010 + 0) = arg0;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800CD23C(f32 *arg0, f32 *arg1, f32 *arg2, u32 arg3) {
#else
s32 func_800CD23C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800BD708(s32 *, s32 *, s32, s32, f32);
    s32 func_800BDAD4(s32 position[3]);
    void *func_800BDC44(void);
    s32 func_800EA628(s32, s32, s32, s32, s32);
#endif
    extern f32 D_8012B010;
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    void *temp_v0, *var_s5;
#else
    s32 temp_v0;
    s32 var_s5;
#endif

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

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800CD3A8(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3, s32 arg4, u32 arg5) {
#else
s32 func_800CD3A8(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
  void func_800BD708(s32 *, s32 *, s32, s32, f32);
  s32 func_800BDAD4(s32 position[3]);
  void *func_800BDC44(void);
  s32 func_800EAA2C(s32, s32, s32, f32, s32, s32, s32);
#endif
    extern f32 D_8012B010;
  s32 cube_indx[3];
  s32 min[3];
  s32 max[3];
  s32 pad[2];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
  void *temp_v0, *result;
#else
  s32 temp_v0;
  s32 result;
#endif
  result = 0;
 func_800BD708(min, max, arg0, arg1, arg2 + D_8012B010); min[1]--;
  cube_indx[0] = min[0];
  if (cube_indx[0] <= max[0])
  {
    if (cube_indx) { ; }
    do {
    for (cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++)
    {
      for (cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++)
      {
        temp_v0 = func_800EAA2C(func_800BDAD4(cube_indx), arg0, arg1, arg2, arg3, arg4, arg5);
        if (temp_v0 != 0)
        {
          result = temp_v0;
        }
      }

    }

    } while (++cube_indx[0] <= max[0]);
  }

  temp_v0 = func_800EAA2C(func_800BDC44(), arg0, arg1, arg2, arg3, arg4, arg5);
  if (temp_v0 != 0)
  {
    result = temp_v0;
  }
  return result;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void *func_800CD544(f32 *arg0, f32 arg1, f32 *arg2, u32 arg3) {
#else
s32 func_800CD544(s32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    void func_800BD708(s32 *, s32 *, s32, s32, f32);
    s32 func_800BDAD4(s32 position[3]);
    void *func_800BDC44(void);
    s32 func_800EADFC(s32, s32, f32, s32, s32);
#endif
    extern f32 D_8012B010;
    s32 cube_indx[3];
    s32 min[3];
    s32 max[3];
    s32 pad[2];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    void *temp_v0, *result;
#else
    s32 temp_v0;
    s32 result;
#endif

    result = 0;
    func_800BD708(min, max, arg0, arg0, arg1 + D_8012B010);
    min[1]--;
    for (cube_indx[0] = min[0]; cube_indx[0] <= max[0]; cube_indx[0]++) {
        for (cube_indx[1] = min[1]; cube_indx[1] <= max[1]; cube_indx[1]++) {
            for (cube_indx[2] = min[2]; cube_indx[2] <= max[2]; cube_indx[2]++) {
                temp_v0 = func_800EADFC(func_800BDAD4(cube_indx), arg0, arg1, arg2, arg3);
                if (temp_v0 != 0) {
                    result = temp_v0;
                }
            }
        }
    }
    temp_v0 = func_800EADFC(func_800BDC44(), arg0, arg1, arg2, arg3);
    if (temp_v0 != 0) {
        result = temp_v0;
    }
    return result;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "1EA6B20_native.inc"
#else
s32 func_800CD6B4(u8 *arg0, f32 *arg1, f32 arg2, f32 *arg3, s32 arg4) {
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused:27, u32 rest : 1);
        u32 value:4;
        BT_BITFIELD_ORDER(u32 rest:1, u32 unused : 27);
    } QueryFlags;
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused:11, u32 rest : 17);
        u32 value:4;
        BT_BITFIELD_ORDER(u32 rest:17, u32 unused : 11);
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

typedef struct {
    u8 *marker;
    s32 unk4;
    BT_BITFIELD_ORDER(u32 unk8:27, u32 isMarker : 1);
    BT_BITFIELD_ORDER(u32 active:1, u32 unk9 : 3);
    BT_BITFIELD_ORDER(u32 unk9:3, u32 active : 1);
    BT_BITFIELD_ORDER(u32 isMarker:1, u32 unk8 : 27);
} HitProp;

u8 *func_800CD820(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused:22, u32 rest : 9);
        u32 enabled:1;
        BT_BITFIELD_ORDER(u32 rest:9, u32 unused : 22);
    } MarkerFlags;
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused:14, u32 rest : 17);
        u32 disabled:1;
        BT_BITFIELD_ORDER(u32 rest:17, u32 unused : 14);
    } ActorFlags;
    f32 _subaddiecustomhits_entrypoint_5(void *, f32 *);
    s32 *func_800BE444(f32 *);
    s16 func_800CB854(BtIntPtr *);
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
                                    reach = (f32)samples * arg3 * 1.1f;
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

s32 func_800CDBA8(u8 *arg0, f32 *volatile arg1, f32 *arg2, s32 arg3) {
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused:22, u32 rest : 9);
        u32 enabled:1;
        BT_BITFIELD_ORDER(u32 rest:9, u32 unused : 22);
    } MarkerFlags;
    typedef union {
        struct { u16 collision; u16 other; } halves;
        struct { BT_BITFIELD_ORDER(u32 unused:27, u32 rest : 1); u32 value:4; BT_BITFIELD_ORDER(u32 rest:1, u32 unused : 27); } query;
        struct { BT_BITFIELD_ORDER(u32 unused:11, u32 rest : 17); u32 value:4; BT_BITFIELD_ORDER(u32 rest:17, u32 unused : 11); } result;
    } HitFlags;
    typedef struct {
        u32 unused[3];
        u8 *(*getCustom)(void);
        u32 unk10;
        u16 id;
        u16 unk16;
        HitFlags flags;
        u32 unk1C;
        u32 unk20;
        u32 unk24;
        BT_BITFIELD_ORDER(u32 stateUnused:22, u32 stateRest : 9);
        u32 enabled:1;
        BT_BITFIELD_ORDER(u32 stateRest:9, u32 stateUnused : 22);
    } Marker;
    typedef struct {
        u32 unused[3];
        s32 (*test)(u8 *, f32 *, f32, f32 *, u32);
    } Custom;
    typedef struct {
        u32 unused[4];
        s32 (*test)(u8 *, u8 *);
    } Callbacks;
    f32 _subaddiecustomhits_entrypoint_5(void *, f32 *);
    s32 *func_800BE444(f32 *);
    s16 func_800CB854(BtIntPtr *);
    HitProp *func_800E9E88(s32);
    HitProp *func_800E9EB4(s32);
    u8 *func_800EC3C4(u8 *);
    f32 func_800EC75C(void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);

    BT_IDO_ONLY(extern u8 D_8012AF70[];)
    BT_IDO_ONLY(extern u8 D_8012AFF0[];)
    register s32 count;
    s32 *cubes;
    f32 center[3];
    f32 reach;
    f32 radius;
    f32 position[3];
    s32 i;
    s32 mask;
    f32 distance;
    f32 extent;
    s32 result;
    HitProp *prop[1];
    HitProp *end;
    u8 *marker;
    Actor *actor;
    f32 contact[3];
    u8 *custom;
    f32 *point;
    f32 *radii;
    Callbacks *callbacks;

    BT_NATIVE_ONLY(marker_hits_clear(); if (arg3 <= 0) return 0;) count = 0;
    if (func_800CB854(NULL) != 0) {
        mask = BT_DATA_FIELD(1u << (((u32)func_800CB854(NULL) + 31) & 31), 1 << (func_800CB854(NULL) + 0x1F));
    } else {
        mask = 0;
    }
    func_800EE7F8(center, arg1);
    i = 1;
    if (arg3 >= 2) {
        point = arg1 + 3;
        do {
            func_800EF04C(center, point);
            i++;
            point += 3;
        } while (i != arg3);
    }
    func_800EF334(center, 1.0f / (f32)arg3);
    distance = func_800EEAD4(center, arg1);
    distance += arg2[0];
    reach = distance;
    i = 1;
    point = arg1;
    point += 3;
    if (arg3 >= 2) {
        radii = arg2 + 1;
        do {
            distance = func_800EEAD4(center, point);
            distance += *radii;
            extent = distance;
            if (reach < extent) {
                reach = extent;
            }
            i++;
            point += 3;
            radii++;
        } while (i != arg3);
    }
    reach *= 1.1f;
    cubes = func_800BE444(center);
    if (*cubes != 0) {
        do {
            prop[0] = func_800E9E88(*cubes);
            end = func_800E9EB4(*cubes);
            if (prop[0] < end) {
                do {
                    if (!prop[0]->active) goto next_prop;
                    if (!prop[0]->isMarker) goto next_prop;
                    {
                        marker = prop[0]->marker;
                        if (((Marker *)marker)->enabled && arg0 != marker) {
                            if (((Marker *)marker)->id != 0 && ((Marker *)marker)->id != 0xFFFF && (((Marker *)marker)->flags.halves.collision & 1)) {
                                actor = func_80106790((Unk80132ED0 *)marker);
                                if (!actor->unk64_17 && !(actor->unk64_0 & mask)) {
                                    radius = _subaddiecustomhits_entrypoint_5(actor, position);
                                    distance = func_800EEB40(position, center);
                                    if (!((radius + reach) * (radius + reach) < distance)) {
                                        callbacks = (Callbacks *)func_800EC3C4(marker);
                                        if (callbacks->test == NULL || callbacks->test(marker, arg0) != 0) {
                                            i = 0;
                                            if (((Marker *)marker)->getCustom != NULL) {
                                                custom = ((Marker *)marker)->getCustom();
                                            } else {
                                                custom = NULL;
                                            }
                                            point = arg1;
                                            if (arg3 > 0) {
                                                radii = arg2;
                                                do {
                                                if (custom != NULL && ((Custom *)custom)->test != NULL) {
                                                    result = ((Custom *)custom)->test(marker, point, *radii, contact, ((Marker *)marker)->flags.query.value);
                                                    if (result != 0) {
                                                        ((Marker *)marker)->flags.result.value = result;
                                                        BT_IDO_ONLY(D_8012AFF0[count] = i;) BT_NATIVE_ONLY(marker_hits_append((Unk80132ED0 *)marker, i);)
                                                        BT_IDO_ONLY(((u8 **)D_8012AF70)[count] = marker;)
                                                        count++;
                                                        break;
                                                    }
                                                } else {
                                                    radius = func_800EC75C(marker, position);
                                                    distance = func_800EEB40(point, position);
                                                    if (distance < (*radii + radius) * (*radii + radius)) {
                                                        BT_IDO_ONLY(D_8012AF70[count + 0x80] = i;) BT_NATIVE_ONLY(marker_hits_append((Unk80132ED0 *)marker, i);)
                                                        BT_IDO_ONLY(((u8 **)D_8012AF70)[count] = marker;)
                                                        count++;
                                                        break;
                                                    }
                                                }
                                                i++;
                                                point += 3;
                                                radii++;
                                                } while (i != arg3);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
next_prop:
                    prop[0]++;
                } while (prop[0] < end);
            }
            cubes++;
        } while (*cubes != 0);
    }
    return count;
}

#ifndef BT_NATIVE
s32 func_800CDFA8(s32 arg0, s32 *arg1) {
    extern u8 D_8012AF70[];
    *arg1 = D_8012AF70[arg0 + 0x80];
    return *(s32 *)(D_8012AF70 + (arg0 << 2));
}
#endif

#endif

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
BT_LP64_ONLY(static) f32 D_8012B010 BT_DATA(4, bss_core2bss1_1, 0x530);
#endif
