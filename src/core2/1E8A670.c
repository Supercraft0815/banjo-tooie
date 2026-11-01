#include "common.h"

typedef struct VertexListView {
    u8 pad0[0x16];
    u16 count : 15;
    u16 flags : 1;
    Vtx vertices[1];
} VertexListView;

s32 func_800B0D80(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, s32 arg6, f32 *arg7, f32 *arg8) {
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_80019CD4(void);
    s32 func_800ADE2C(s32, s32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void mlMtxGet(void *);
    extern s32 D_80127EA0;
    u8 *first;
    u8 *end;
    u8 *entry;
    f32 y;
    f32 sp24[3];

    first = *(s16 *)arg0 * 0x18 + arg0 + 8;
    entry = *(s16 *)(arg0 + 2) * 0x10 + first;
    end = *(s16 *)(arg0 + 4) * 0xC + entry;
    while (entry < end) {
        if (arg1 == entry[8]) {
            break;
        }
        entry += 0xC;
    }
    if (entry == end) {
        return 0;
    }
    func_800EE88C(arg7, (s16 *)(entry + 2));
    func_800EFA4C(sp24, arg7[0], (f32)*(s16 *)entry + arg7[1], arg7[2]);
    func_80019CD4();
    func_80019750(arg2, arg3, arg4, arg5);
    mlMtxGet(&D_80127EA0);
    func_80019AA0(&D_80127EA0, func_800ADE2C(arg6, *(s8 *)(entry + 9)));
    func_80019224(arg7, arg7);
    func_80019224(sp24, sp24);
    if (arg8 != NULL) {
        *arg8 = func_800EEAD4(arg7, sp24);
    }
    return 1;
}

s32 func_800B0ECC(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, s32 arg7) {
    void func_800193C4(f32 *, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    void func_80019A10(f32 *, f32 *);
    s32 func_80019CD4(void);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF334(f32 *, f32);
    f32 radius;
    f32 origin[3];
    f32 minimum[3];
    f32 maximum[3];
    f32 rotation[3];
    int i;
    s32 id;
    f32 position[3];
    u8 *end;
    u8 *entry;

    end = *(s16 *)arg0 * 0x18 + arg0 + 8;
    for (entry = arg0 + 8; entry < end; entry += 0x18) {
        id = entry[0x15];
        id--;
        if ((1 << id) & arg7) {
            continue;
        }
            radius = arg6 / arg3;
            func_800EE88C(origin, (s16 *)(entry + 0xC));
            func_800EE88C(minimum, (s16 *)entry);
            func_800EE88C(maximum, (s16 *)(entry + 6));
            rotation[0] = (u32)entry[0x12];
            rotation[1] = (u32)entry[0x13];
            rotation[2] = (u32)entry[0x14];
            func_800EF334(rotation, 2.0f);
            func_80019CD4();
            func_80019A10(origin, rotation);
            func_8001980C(arg1, arg2, arg3, arg4);
            func_800193C4(position, arg5);
            for (i = 0; i != 3; i++) {
                if (minimum[i] >= position[i] + radius || position[i] - radius >= maximum[i]) {
                    break;
                }
            }
            if (i == 3) {
                return entry[0x15];
        }
    }
    return 0;
}

s32 func_800B1110(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, s32 arg7)
{
    void func_800193C4(f32 *, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    void func_80019924(f32 *, f32 *);
    s32 func_80019CD4(void);
    void func_800EE88C(f32 *, s16 *);
    f32 totalRadius;
    f32 center[3];
    f32 rotation[3];
    f32 radius;
    f32 height;
    f32 scaledRadius;
    f32 halfHeight;
    f32 position[3];
    s32 id;
    u8 *end;
    u8 *entry;

    entry = *(s16 *)arg0 * 0x18 + arg0 + 8;
    end = *(s16 *)(arg0 + 2) * 0x10 + entry;
    while (entry < end) {
        id = entry[0xD];
        id--;
        if (!((1 << id) & arg7)) {
            scaledRadius = arg6 / arg3;
            func_800EE88C(center, (s16 *)(entry + 4));
            rotation[0] = entry[0xA] * 2;
            rotation[1] = entry[0xB] * 2;
            rotation[2] = entry[0xC] * 2;
            radius = *(s16 *)entry;
            height = *(s16 *)(entry + 2);
            func_80019CD4();
            func_80019924(center, rotation);
            func_8001980C(arg1, arg2, arg3, arg4);
            func_800193C4(position, arg5);
            halfHeight = height * 0.5f;
            if (!(halfHeight <= position[2] - scaledRadius) &&
                !(position[2] + scaledRadius <= -halfHeight)) {
                totalRadius = scaledRadius + radius;
                if (!(totalRadius * totalRadius <= position[0] * position[0] + position[1] * position[1])) {
                    return entry[0xD];
                }
            }
        }
        entry += 0x10;
    }
    return 0;
}

s32 func_800B1328(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, s32 arg7)
{
  void func_800193C4(f32 *, f32 *);
  void func_8001980C(f32 *, f32 *, f32, f32 *);
  s32 func_80019CD4(void);
  f32 sqrtf(f32);
  extern s16 D_80127EE0;
  f32 distance;
  u8 *base;
  f32 position[3];
  f32 scaledRadius;
  f32 center[3];
  f32 radius;
  s32 id;
  register u8 *end;
  f32 delta[3];
  int new_var;
  u8 *entry;
  func_80019CD4();
  func_8001980C(arg1, arg2, arg3, arg4);
  func_800193C4(position, arg5);
  base = (((*((s16 *) arg0)) * 0x18) + arg0) + 8;
  entry = ((*((s16 *) (arg0 + 2))) * 0x10) + base;
  end = ((*((s16 *) (arg0 + 4))) * 0xC) + entry;
  while (entry < end)
  {
    id = entry[8];
    id--;
    if (1)
    {
      if (!((1 << id) & arg7))
      {
        scaledRadius = arg6 / arg3;
        center[0] = *((s16 *) (entry + 2));
        center[1] = *((s16 *) (entry + 4));
        new_var = 1;
        center[2] = *((s16 *) (entry + 6));
        radius = *((s16 *) entry);
        delta[0] = center[0] - position[0];
        delta[new_var] = center[new_var] - position[new_var];
        delta[2] = center[2] - position[2];
        distance = sqrtf(((delta[0] * delta[0]) + (delta[new_var] * delta[new_var])) + (delta[2] * delta[2]));
        if (!((scaledRadius + radius) <= distance))
        {
          D_80127EE0 = ((s32) ((entry - ((*((s16 *) (arg0 + 2))) * 0x10)) - base)) / 12;
          return entry[8];
        }
      }
      entry += 0xC;
    }
  }

  return 0;
}

s32 func_800B1508(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019480(f32 *, f32, f32, f32);
    void func_80019994(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF2A0(f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    extern s32 D_80127EA0;
    f32 spEC[3];
    f32 spE0[3];
    f32 spD4[3];
    f32 spC8[3];
    u8 *entry;
    u8 *end;
    union {
        struct { f32 x, y, z; } n;
        f32 v[3];
    } normal;
    f32 spA8[3];
    f32 sp9C[3];
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    s32 index;

    entry = arg0 + 8;
    end = arg0 + *(s16 *)arg0 * 0x18 + 8;
    while (entry < end) {
        index = entry[0x15];
        index--;
        if (!((1 << index) & arg8)) {
            func_800EE88C(spEC, (s16 *)(entry + 0xC));
            func_800EE88C(spE0, (s16 *)entry);
            func_800EE88C(spD4, (s16 *)(entry + 6));
            spC8[0] = (f32)(u32)entry[0x12];
            spC8[1] = (f32)(u32)entry[0x13];
            spC8[2] = (f32)(u32)entry[0x14];
            if (1) {}
            if (1) {}
            func_800EF334(spC8, 2.0f);
            func_80019AA0(&D_80127EA0, func_800ADE2C(arg5, (s8)entry[0x16]));
            func_80019994(spEC, spC8);
            func_80019480(spA8, spE0[0], spE0[1], spE0[2]);
            func_80019480(sp90, spE0[0], spE0[1], spD4[2]);
            func_800EFB24(normal.v, spA8, sp90);
            func_800EF2A0(normal.v);
            func_800EFB24(sp9C, arg6, spA8);
            if (!(arg7 <= ((*(f32 *)((s8 *)sp9C + 0)) * normal.n.x + (*(f32 *)((s8 *)sp9C + 4)) * normal.n.y + (*(f32 *)((s8 *)sp9C + 8)) * (0, normal.n.z)))) {
                func_800EFB24(sp84, arg6, sp90);
                if (!(arg7 <= -((*(f32 *)((s8 *)sp84 + 0)) * normal.n.x + (*(f32 *)((s8 *)sp84 + 4)) * normal.n.y + (*(f32 *)((s8 *)sp84 + 8)) * (0, normal.n.z)))) {
                    func_80019480(sp78, spD4[0], spE0[1], spE0[2]);
                    func_800EFB24(normal.v, spA8, sp78);
                    func_800EF2A0(normal.v);
                    if (!(arg7 <= ((*(f32 *)((s8 *)sp9C + 0)) * normal.n.x + (*(f32 *)((s8 *)sp9C + 4)) * normal.n.y + (*(f32 *)((s8 *)sp9C + 8)) * (0, normal.n.z)))) {
                        if (1) {}
                        (*(f32 *)((s8 *)sp6C + 0)) = (*(f32 *)((s8 *)arg6 + 0)) - (*(f32 *)((s8 *)sp78 + 0));
                        (*(f32 *)((s8 *)sp6C + 4)) = (*(f32 *)((s8 *)arg6 + 4)) - (*(f32 *)((s8 *)sp78 + 4));
                        (*(f32 *)((s8 *)sp6C + 8)) = (*(f32 *)((s8 *)arg6 + 8)) - (*(f32 *)((s8 *)sp78 + 8));
                        if (!(arg7 <= -((*(f32 *)((s8 *)sp6C + 0)) * normal.n.x + (*(f32 *)((s8 *)sp6C + 4)) * normal.n.y + (*(f32 *)((s8 *)sp6C + 8)) * (0, normal.n.z)))) {
                            func_80019480(sp60, spE0[0], spD4[1], spE0[2]);
                            normal.n.x = (*(f32 *)((s8 *)spA8 + 0)) - (*(f32 *)((s8 *)sp60 + 0));
                            normal.n.y = (*(f32 *)((s8 *)spA8 + 4)) - (*(f32 *)((s8 *)sp60 + 4));
                            normal.n.z = (*(f32 *)((s8 *)spA8 + 8)) - (*(f32 *)((s8 *)sp60 + 8));
                            func_800EF2A0(normal.v);
                            if (!(arg7 <= ((*(f32 *)((s8 *)sp9C + 0)) * normal.n.x + (*(f32 *)((s8 *)sp9C + 4)) * normal.n.y + (*(f32 *)((s8 *)sp9C + 8)) * (0, normal.n.z)))) {
                                if (1) {}
                                (*(f32 *)((s8 *)sp54 + 0)) = (*(f32 *)((s8 *)arg6 + 0)) - (*(f32 *)((s8 *)sp60 + 0));
                                (*(f32 *)((s8 *)sp54 + 4)) = (*(f32 *)((s8 *)arg6 + 4)) - (*(f32 *)((s8 *)sp60 + 4));
                                (*(f32 *)((s8 *)sp54 + 8)) = (*(f32 *)((s8 *)arg6 + 8)) - (*(f32 *)((s8 *)sp60 + 8));
                                if (!(arg7 <= -((*(f32 *)((s8 *)sp54 + 0)) * normal.n.x + (*(f32 *)((s8 *)sp54 + 4)) * normal.n.y + (*(f32 *)((s8 *)sp54 + 8)) * (0, normal.n.z)))) {
                                    return entry[0x15];
                                }
                            }
                        }
                    }
                }
            }
            mlMtxPop();
        }
        entry += 0x18;
    }
    return 0;
}

s32 func_800B196C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019480(f32 *, f32, f32, f32);
    void func_800198D4(f32 *, f32 *);
    void func_80019AA0(void *, s32);
    s32 func_800ADE2C(s32, s32);
    void func_800EF2A0(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    extern s32 D_80127EA0;
    s32 index;
    f32 position[3];
    f32 rotation[3];
    f32 distance;
    f32 radialDistance;
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    f32 delta[3];
    f32 radius[3];
    u8 *entry;
    u8 *limit;

    entry = *(s16 *)arg0 * 0x18 + arg0 + 8;
    limit = *(s16 *)(arg0 + 2) * 0x10 + entry;
    while ((u32)entry < (u32)limit) {
        index = entry[0xD] - 1;
        if (!((1 << index) & arg8)) {
            position[0] = *(s16 *)(entry + 4);
            position[1] = *(s16 *)(entry + 6);
            position[2] = *(s16 *)(entry + 8);
            rotation[0] = entry[0xA] * 2;
            rotation[1] = entry[0xB] * 2;
            rotation[2] = entry[0xC] * 2;
            func_80019AA0(&D_80127EA0, func_800ADE2C(arg5, *(s8 *)(entry + 0xE)));
            func_800198D4(position, rotation);
            func_80019480(start, 0.0f, 0.0f, (f32)-*(s16 *)(entry + 2) * 0.5f);
            func_80019480(end, 0.0f, 0.0f, (f32)*(s16 *)(entry + 2) * 0.5f);
            func_80019480(radius, (f32)*(s16 *)entry, 0.0f, (f32)-*(s16 *)(entry + 2) * 0.5f);
            func_800EF3DC(radius, start);
            func_800EFB24(normal, start, end);
            func_800EF2A0(normal);
            func_800EFB24(delta, arg6, start);
            distance = normal[0] * delta[0] + normal[1] * delta[1] + normal[2] * delta[2];
            if (arg7 < distance) {
                goto rejected;
            }
            func_800EFB24(delta, arg6, end);
            if (arg7 < -(normal[0] * delta[0] + normal[1] * delta[1] + normal[2] * delta[2])) {
                goto rejected;
            }
            delta[0] = arg6[0] - (start[0] + normal[0] * distance);
            delta[1] = arg6[1] - (start[1] + normal[1] * distance);
            delta[2] = arg6[2] - (start[2] + normal[2] * distance);
            radialDistance = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            if (sqrtf(radius[0] * radius[0] + radius[1] * radius[1] + radius[2] * radius[2]) < radialDistance - arg7) {
                goto rejected;
            }
            return entry[0xD];
rejected:
            mlMtxPop();
        }
        entry += 0x10;
    }
    return 0;
}

s32 func_800B1D3C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019224(f32 *, f32 *);
    void func_800193C4(f32 *, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    s32 func_80019CD4(void);
    s32 func_800ADE2C(s32, s32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void mlMtxSet(void *);
    f32 sqrtf(f32);
    extern s16 D_80127EE0;
    f32 scaledRadiusSquared;
    u8 *base;
    f32 position[3];
    f32 center[3];
    f32 edge[3];
    f32 radiusSquared;
    f32 radius;
    s32 id;
    f32 delta[3];
    u8 *entry;
    u8 *end;

    func_80019CD4();
    func_8001980C(arg1, arg2, arg3, arg4);
    func_800193C4(position, arg6);
    base = *(s16 *)arg0 * 0x18 + arg0 + 8;
    entry = *(s16 *)(arg0 + 2) * 0x10 + base;
    end = *(s16 *)(arg0 + 4) * 0xC + entry;
    arg7 /= arg3;
    for (; entry < end; entry += 0xC) {
        id = entry[8];
        id--;
        if ((1 << id) & arg8) {
            continue;
        }
        scaledRadiusSquared = arg7 * arg7;
        func_800EE88C(center, (s16 *)(entry + 2));
        func_800EFA4C(edge, (f32)*(s16 *)entry + center[0], center[1], center[2]);
        mlMtxSet(func_800ADE2C(arg5, *(s8 *)(entry + 9)));
        func_80019224(center, center);
        func_80019224(edge, edge);
        delta[0] = edge[0] - center[0];
        delta[1] = edge[1] - center[1];
        delta[2] = edge[2] - center[2];
        radiusSquared = func_800EEFD4(delta);
        radius = sqrtf(radiusSquared);
        if (func_800EEB40(center, position) <= scaledRadiusSquared + radiusSquared + 2.0f * radius * arg7) {
            D_80127EE0 = (s32)((entry - *(s16 *)(arg0 + 2) * 0x10) - base) / 12;
            return entry[8];
        }
    }
    return 0;
}

s32 func_800B1F8C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5, f32 *arg6, f32 arg7, f32 *arg8, s32 arg9) { void func_80019750(f32 *, f32 *, f32, f32 *); s32 func_80019CD4(void); s32 func_800B1508(u8 *, f32 *, f32 *, f32, f32 *, s32, f32 *, f32, s32); void func_800EFA4C(f32 *, f32, f32, f32); void mlMtxGet(void *); extern s32 D_80127EA0; s32 result; f32 **translation = &arg1; f32 **rotation = &arg2; if (arg5 != 0) { func_80019CD4(); func_80019750(*translation, *rotation, arg3, arg4); mlMtxGet(&D_80127EA0); result = func_800B1D3C(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); if (result == 0) { result = func_800B1508(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); } if (result == 0) { result = func_800B196C(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); } } else { result = func_800B1328(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); if (result == 0) { result = func_800B0ECC(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); } if (result == 0) { result = func_800B1110(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); } } if (result != 0) { func_800EFA4C(arg8, 0.0f, 1.0f, 0.0f); } return result; }

void *func_800B2190(void *arg0) {
    return (u8 *)arg0 + 0x18;
}

void func_800B2198(void *arg0, void *arg1, void *arg2) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    (*(s32 *)((s8 *)(arg2) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
    (*(s32 *)((s8 *)(arg2) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
    (*(s32 *)((s8 *)(arg2) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

void func_800B21CC(void *arg0, void *arg1, void *arg2) {
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(s16 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (*(s16 *)((s8 *)(arg0) + (6)));
    (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (*(s16 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

/* extern */

s32 func_800B2248(void *arg0) {
    f32 mlAbsF(f32);
    s32 maximum;
    s32 value;

    maximum = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 0)));
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 4)));
    if (maximum < value) {
        maximum = value;
    }
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 6)));
    if (maximum < value) {
        maximum = value;
    }
    value = (s32) mlAbsF((f32) (*(s16 *)((s8 *)arg0 + 0xA)));
    if (maximum < value) {
        maximum = value;
    }
    return maximum;
}

u8 *func_800B2324(u8 *arg0, u8 **arg1, u8 **arg2) {
    u8 *base;

    base = arg0 + 0x18;
    *arg1 = base;
    *arg2 = (u8 *)((((u32)*(u16 *)(arg0 + 0x16) >> 1) * 0x10) + (u32)*arg1);
    return base;
}

u32 func_800B2344(void *arg0) {
    return (u32) (*(u16 *)((s8 *)arg0 + 0x16)) >> 1;
}

f32 func_800B2354(void *arg0) {
    return (f32) (u32) *(u16 *)((s8 *)arg0 + 0x14);
}

void func_800B237C(void *list, f32 center[3], f32 *norm) {
    s16 *coords = (s16 *)list;
    center[0] = coords[6];
    center[1] = coords[7];
    center[2] = coords[8];
    *norm = (u32)((u16 *)list)[9];
}

void func_800B23E0(void* arg0) 
{
    heap_free(arg0);
}
void *func_800B2400(VertexListView *list, s32 side) {
    void *heap_alloc_sided(s32, s32);
    s32 aligned4_memcpy(void *, void *, s32);
    void *copy;
    s32 size;
    size = list->count * sizeof(Vtx) + 0x18;
    copy = heap_alloc_sided(size, side ? 1 : 2);
    aligned4_memcpy(copy, list, size);
    return copy;
}

void func_800B2464(VertexListView *this, s32 color[3], VertexListView *src) {
    Vtx *start_ptr, *end_ptr, *i_ptr, *src_ptr;
    int i;

    if (color[0] != 0xFF || color[1] != 0xFF || color[2] != 0xFF) {
        start_ptr = this->vertices;
        end_ptr = start_ptr + this->count;
        for (i_ptr = start_ptr, src_ptr = src->vertices; i_ptr < end_ptr; i_ptr++, src_ptr++) {
            for (i = 0; i < 3; i++) {
                i_ptr->v.cn[i] = (src_ptr->v.cn[i] * color[i]) >> 8;
            }
        }
        osWritebackDCache(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
    }
}

void func_800B2540(VertexListView *this, s32 color[3]) {
    Vtx *start_ptr, *end_ptr, *i_ptr;
    int i;

    start_ptr = this->vertices;
    end_ptr = start_ptr + this->count;

    for (i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++) {
        for (i = 0; i < 3; i++) {
            i_ptr->v.cn[i] = color[i];
        }
    }

    osWritebackDCache(start_ptr, (end_ptr - start_ptr) * sizeof(Vtx));
}

/* extern */

void func_800B25D8(VertexListView *arg0, VertexListView *arg1, s32 arg2) {
    s32 _dbpalette_entrypoint_0(s32, s32, s32 *);
    s32 sp5C[5];
    int i;
    Vtx *temp_s4;
    Vtx *temp_s6;
    Vtx *var_s1;
    Vtx *var_s2;

    temp_s6 = arg0->vertices;
    temp_s4 = arg0->count + arg0->vertices;
    var_s1 = temp_s6;
    var_s2 = arg1->vertices;
    if ((u32) temp_s6 < (u32) temp_s4) {
        do {
            _dbpalette_entrypoint_0(arg2, var_s2->v.flag & 0x1FF, sp5C);
            for (i = 0; i < 3; i++) {
                var_s1->v.cn[i] = (var_s2->v.cn[i] * sp5C[i]) >> 8;
            }
            var_s1++;
            var_s2++;
        } while ((u32) var_s1 < (u32) temp_s4);
    }
    osWritebackDCache(temp_s6, (temp_s4 - temp_s6) * sizeof(Vtx));
}

/* extern */

void func_800B26C8(void) {
    s32 defrag();
    defrag();
}
