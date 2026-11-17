#include "common.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_zones.h"
#include <math.h>
void func_800EE940(s16 *,f32 *);
static int zone_point(f32 *position,s16 *out) {
    for(int i=0;i<3;++i)if(!isfinite(position[i]) || position[i]<-2147483648.0f || position[i]>=2147483648.0f)return 0;
    func_800EE940(out,position);return 1;
}
int func_8080010C_dbzone(s16 *bounds,s16 *point) {
    for(int i=0;i<3;++i)if(point[i]<bounds[i] || point[i]>bounds[i+3])return 0;
    return 1;
}
static int zone_contains(u8 *entry,s16 *point) {
    s16 bounds[6];for(int i=0;i<6;++i)bounds[i]=(u16)entry[i*2]<<8|entry[i*2+1];
    return func_8080010C_dbzone(bounds,point);
}
s32 dbzone_entrypoint_0(u8 *zones,u8 *ids,u32 count) {
    for(u32 i=0;i<count;++i)if(ids[i]<*zones && zones[2+ids[i]*14+12])return 1;
    return 0;
}
void dbzone_entrypoint_1(u8 *zones,f32 *position,f32 scale,f32 *origin) {
    f32 local[3];s16 point[3];
    for(int i=0;i<3;++i)local[i]=(position[i]-origin[i])*(1.0f/scale);
    int valid=zone_point(local,point);
    for(int i=0;i<*zones;++i)zones[2+i*14+12]=valid && zone_contains(zones+2+i*14,point);
}
s32 dbzone_entrypoint_2(u8 *zones,f32 *position,s32 index) {
    s16 point[3];
    return index>=0 && index<*zones && zone_point(position,point) && zone_contains(zones+2+index*14,point);
}
s32 dbzone_entrypoint_3(u8 *zones,f32 *position) {
    s16 point[3];if(!zone_point(position,point))return -1;
    for(int i=0;i<*zones;++i)if(zone_contains(zones+2+i*14,point))return i;
    return -1;
}
s32 dbzone_entrypoint_4(u8 *zones,f32 *position,u8 *out) {
    s16 point[3];s32 count=0;if(!zone_point(position,point))return 0;
    for(int i=0;i<*zones;++i)if(zone_contains(zones+2+i*14,point))out[count++]=i;
    return count;
}
#else
s32 dbzone_entrypoint_0(u8 *arg0, u8 *arg1, u32 arg2) {
    struct {
        s16 bounds[6];
        u8 in_bounds;
        u8 pad;
    } *data_ptr = (void *)(arg0 + 2);

    while (arg2 != 0) {
        if (data_ptr[*arg1].in_bounds) {
            return 1;
        }
        arg2--;
        arg1++;
    }
    return 0;
}

int func_8080010C_dbzone(s16 *arg0, s16 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1[0];
    return temp_v1 >= arg0[0] && arg0[3] >= temp_v1 &&
        (temp_v1 = arg1[1]) >= arg0[1] && arg0[4] >= temp_v1 &&
        (temp_v1 = arg1[2]) >= arg0[2] && arg0[5] >= temp_v1;
}

void dbzone_entrypoint_1(u8 *arg0, f32 *arg1, f32 arg2, f32 *arg3) {
    u8 *cursor;
    u8 *end;
    f32 *src;
    f32 *origin;
    s16 point[3];
    s32 i;

    arg2 = 1.0f / arg2;
    for (i = 0; i < 3; i++) {
        point[i] = (s32)((arg1[i] - arg3[i]) * arg2);
    }
    cursor = arg0 + 2;
    end = arg0 + *arg0 * 14 + 2;
    while (cursor < end) {
        cursor[12] = func_8080010C_dbzone((s16 *)cursor, point);
        cursor += 14;
    }
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) dbzone_entrypoint_2(s16 arg0[][7], f32 *arg1, s32 arg2) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    int func_8080010C_dbzone(s16 *, s16 *);
    s16 sp1C[6];
    s16 (*temp)[7];

    func_800EE940(sp1C, arg1);
    temp = arg0;
    temp += arg2;
    BT_NATIVE_ONLY(return) func_8080010C_dbzone(temp[0] + 1, sp1C);
}

/* extern */

s32 dbzone_entrypoint_3(u8 *arg0, f32 *arg1) {
    void func_800EE940(s16 *, f32 *);
    u8 *sp28;
    u8 *var_s0;
    void *temp_s1;
    s16 sp2C[3];

    sp28 = arg0 + 2;
    temp_s1 = (*arg0 * 0xE) + arg0 + 2;
    func_800EE940(sp2C, arg1);
    var_s0 = arg0 + 2;
    if ((u32) var_s0 < (u32) temp_s1) {
loop_2:
        if (func_8080010C_dbzone((s16 *) var_s0, sp2C) != 0) {
            return (s32) (var_s0 - sp28) / 14;
        }
        var_s0 += 0xE;
        if ((u32) var_s0 >= (u32) temp_s1) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    return -1;
}

s32 dbzone_entrypoint_4(u8 *arg0, f32 *arg1, u8 *arg2) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    s32 count;
    u8 *start;
    u8 *cursor;
    s16 sp44[3];
    u8 *end;

    count = 0;
    end = arg0 + *arg0 * 14 + 2;
    func_800EE940(sp44, arg1);
    start = arg0 + 2;
    cursor = start;
    if ((u32)start < (u32)end) {
        do {
            if (func_8080010C_dbzone((s16 *)cursor, sp44) != 0) {
                arg2[count++] = (s32)(cursor - start) / 14;
            }
            cursor += 14;
        } while ((u32)cursor < (u32)end);
    }
    return count;
}
#endif
