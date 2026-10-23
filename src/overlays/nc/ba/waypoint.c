#include "common.h"

s32 ncbawaypoint_entrypoint_0() 
{
    return 0x84;
}

void ncbawaypoint_entrypoint_1(void *arg0) {
    *(*(s32 **)((s8 *)(arg0) + (0x5C))) = 0;
}

s32 ncbawaypoint_entrypoint_2(void *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    f32 *volatile point;
    s32 *data;
    s32 count;

    data = *(s32 **)((s8 *)arg0 + 0x5C);
    count = *data;
    if (count >= 4) {
        return 0;
    }
    func_800EE7F8(point = (f32 *)((s8 *)data + (count << 5) + 4), arg1);
    func_800EE7F8(point + 3, arg2);
    point[6] = arg3;
    data = *(s32 **)((s8 *)arg0 + 0x5C);
    *data += 1;
    return 1;
}

f32 ncbawaypoint_entrypoint_3(void *arg0, f32 *arg1, f32 *arg2) {
    void aligned4_memcpy(void *, void *, int);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    typedef struct {
        f32 position[3];
        f32 normal[3];
        f32 offset;
        f32 distance;
    } Waypoint;
    typedef struct {
        s32 count;
        Waypoint points[4];
    } WaypointData;
    Waypoint *entry;
    Waypoint *cursor;
    Waypoint *end;
    Waypoint point;
    f32 side1;
    f32 side2;
    f32 total;

    total = 0.0f;

    if ((*(WaypointData **)((s8 *)arg0 + 0x5C))->count == 0) {
        goto done;
    }
    {
        end = &(*(WaypointData **)((s8 *)arg0 + 0x5C))->points[(*(WaypointData **)((s8 *)arg0 + 0x5C))->count];
        for (entry = (*(WaypointData **)((s8 *)arg0 + 0x5C))->points; entry < end; entry++) {
            entry->distance = func_800EEAD4(entry->position, arg1);
        }
        for (entry = (*(WaypointData **)((s8 *)arg0 + 0x5C))->points + 1; entry < end; entry++) {
            cursor = entry - 1;
            aligned4_memcpy(&point, entry, sizeof(Waypoint));
            while (cursor >= (*(WaypointData **)((s8 *)arg0 + 0x5C))->points && point.distance < cursor->distance) {
                aligned4_memcpy(cursor + 1, cursor, sizeof(Waypoint));
                cursor--;
            }
            aligned4_memcpy(cursor + 1, &point, sizeof(Waypoint));
        }
        for (entry = (*(WaypointData **)((s8 *)arg0 + 0x5C))->points; entry < end; entry++) {
            side1 = func_800EEAA4(arg2, entry->normal) - entry->offset;
            side2 = func_800EEAA4(arg1, entry->normal) - entry->offset;
            if (side2 <= 0.0f && side1 <= 0.0f) {
                continue;
            }
            if (side2 >= 0.0f && side1 >= 0.0f) {
                continue;
            }
            total += func_800EEAD4(arg1, entry->position);
            func_800EE7F8(arg1, entry->position);
        }
    }
done:
    return total;
}
