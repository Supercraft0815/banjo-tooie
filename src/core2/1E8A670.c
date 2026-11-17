#include "common.h"

s32 func_800B0D80(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, BtIntPtr arg6, f32 *arg7, f32 *arg8) {
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_80019AA0(void *, BtIntPtr);
    void * func_80019CD4(void);
    BtIntPtr func_800ADE2C(BtIntPtr, s32);
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
    void * func_80019CD4(void);
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
    void * func_80019CD4(void);
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
  void * func_80019CD4(void);
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
}    typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp9C; /* offsets.py genstruct: fields from raw offsets on sp9C; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp78; /* offsets.py genstruct: fields from raw offsets on sp78; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp60; /* offsets.py genstruct: fields from raw offsets on sp60; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp54; /* offsets.py genstruct: fields from raw offsets on sp54; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp6C; /* offsets.py genstruct: fields from raw offsets on sp6C; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_sp84; /* offsets.py genstruct: fields from raw offsets on sp84; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; } Obj1E8A670_func_800B1508_spA8; /* offsets.py genstruct: fields from raw offsets on spA8; rename once understood */

s32 func_800B1508(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019480(f32 *, f32, f32, f32);
    void func_80019994(f32 *, f32 *);
    void func_80019AA0(void *, BtIntPtr);
    BtIntPtr func_800ADE2C(BtIntPtr, s32);
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
            if (!(arg7 <= ((((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk8) * (0, normal.n.z)))) {
                func_800EFB24(sp84, arg6, sp90);
                if (!(arg7 <= -((((Obj1E8A670_func_800B1508_sp84 *)sp84)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp84 *)sp84)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp84 *)sp84)->unk8) * (0, normal.n.z)))) {
                    func_80019480(sp78, spD4[0], spE0[1], spE0[2]);
                    func_800EFB24(normal.v, spA8, sp78);
                    func_800EF2A0(normal.v);
                    if (!(arg7 <= ((((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk8) * (0, normal.n.z)))) {
                        if (1) {}
                        (((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk0) = (((Vec3f *)arg6)->pos.x) - (((Obj1E8A670_func_800B1508_sp78 *)sp78)->unk0);
                        (((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk4) = (((Vec3f *)arg6)->pos.y) - (((Obj1E8A670_func_800B1508_sp78 *)sp78)->unk4);
                        (((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk8) = (((Vec3f *)arg6)->pos.z) - (((Obj1E8A670_func_800B1508_sp78 *)sp78)->unk8);
                        if (!(arg7 <= -((((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp6C *)sp6C)->unk8) * (0, normal.n.z)))) {
                            func_80019480(sp60, spE0[0], spD4[1], spE0[2]);
                            normal.n.x = (((Obj1E8A670_func_800B1508_spA8 *)spA8)->unk0) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk0);
                            normal.n.y = (((Obj1E8A670_func_800B1508_spA8 *)spA8)->unk4) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk4);
                            normal.n.z = (((Obj1E8A670_func_800B1508_spA8 *)spA8)->unk8) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk8);
                            func_800EF2A0(normal.v);
                            if (!(arg7 <= ((((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp9C *)sp9C)->unk8) * (0, normal.n.z)))) {
                                if (1) {}
                                (((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk0) = (((Vec3f *)arg6)->pos.x) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk0);
                                (((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk4) = (((Vec3f *)arg6)->pos.y) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk4);
                                (((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk8) = (((Vec3f *)arg6)->pos.z) - (((Obj1E8A670_func_800B1508_sp60 *)sp60)->unk8);
                                if (!(arg7 <= -((((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk0) * normal.n.x + (((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk4) * normal.n.y + (((Obj1E8A670_func_800B1508_sp54 *)sp54)->unk8) * (0, normal.n.z)))) {
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

s32 func_800B196C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019480(f32 *, f32, f32, f32);
    void func_800198D4(f32 *, f32 *);
    void func_80019AA0(void *, BtIntPtr);
    BtIntPtr func_800ADE2C(BtIntPtr, s32);
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
    while ((BtUIntPtr)entry < (BtUIntPtr)limit) {
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

s32 func_800B1D3C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, s32 arg8) {
    void func_80019224(f32 *, f32 *);
    void func_800193C4(f32 *, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    void * func_80019CD4(void);
    BtIntPtr func_800ADE2C(BtIntPtr, s32);
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

s32 func_800B1F8C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, f32 *arg8, s32 arg9) { void func_80019750(f32 *, f32 *, f32, f32 *); void * func_80019CD4(void); s32 func_800B1508(u8 *, f32 *, f32 *, f32, f32 *, BtIntPtr, f32 *, f32, s32); void func_800EFA4C(f32 *, f32, f32, f32); void mlMtxGet(void *); extern s32 D_80127EA0; s32 result; f32 **translation = &arg1; f32 **rotation = &arg2; if (arg5 != 0) { func_80019CD4(); func_80019750(*translation, *rotation, arg3, arg4); mlMtxGet(&D_80127EA0); result = func_800B1D3C(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); if (result == 0) { result = func_800B1508(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); } if (result == 0) { result = func_800B196C(arg0, *translation, *rotation, arg3, arg4, arg5, arg6, arg7, arg9); } } else { result = func_800B1328(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); if (result == 0) { result = func_800B0ECC(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); } if (result == 0) { result = func_800B1110(arg0, *translation, *rotation, arg3, arg4, arg6, arg7, arg9); } } if (result != 0) { func_800EFA4C(arg8, 0.0f, 1.0f, 0.0f); } return result; }

#include "1E8A670_vertices.inc"

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80127EA0 BT_DATA(4, bss_core2bss1_0_2, 0x700);
s16 D_80127EE0 BT_DATA(4, bss_core2bss1_0_2, 0x740);
#endif
