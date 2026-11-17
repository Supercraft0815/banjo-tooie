#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_map_props.h"

void *gspropmarker_entrypoint_0(NativeWorldCell *cell, s32 id) {
    Prop *prop = cell ? func_800E9D68(cell) : NULL;
    Prop *end = cell ? func_800E9D90(cell) : NULL;
    for (; prop && prop < end; ++prop)
        if ((prop->unk6_0 || (prop->unk12 & 0x100)) && prop->unk6_1 == 6 && id == prop->ItemID)
            return prop;
    return NULL;
}

s32 gspropmarker_entrypoint_1(NativeWorldCell *cell, s32 *ids, Prop **output, s32 capacity) {
    s32 count = 0, *id;
    Prop *prop = cell ? func_800E9D68(cell) : NULL;
    Prop *end = cell ? func_800E9D90(cell) : NULL;
    for (; prop && prop < end && count < capacity; ++prop) {
        if ((prop->unk6_0 || (prop->unk12 & 0x100)) && prop->unk6_1 == 6) {
            for (id = ids; *id != -1; ++id) {
                if (prop->ItemID == *id) { output[count++] = prop; break; }
            }
        }
    }
    return count;
}

s32 gspropmarker_entrypoint_2(NativeWorldCell *cell, s32 id, f32 (*positions)[3], s32 capacity) {
    s32 count = 0, i;
    Prop *prop = cell ? func_800E9D68(cell) : NULL;
    Prop *end = cell ? func_800E9D90(cell) : NULL;
    for (; prop && prop < end && count < capacity; ++prop) {
        if ((prop->unk6_0 || (prop->unk12 & 0x100)) && prop->unk6_1 == 6 && id == prop->ItemID) {
            for (i = 0; i < 3; ++i) positions[count][i] = prop->position[i];
            ++count;
        }
    }
    return count;
}

f32 gspropmarker_entrypoint_3(void *context) {
    Prop *prop = context;
    u32 value = prop->flagsC & 0x7FFFFF;
    return value ? (f32)value * 0.01f : 1.0f;
}
#else
#include "common.h"

void *gspropmarker_entrypoint_0(s16 *arg0, s32 arg1) { Prop *func_800E9D68(s16 *); u32 func_800E9D90(s16 *); s32 func_800E9DC4(s16 *);
    Prop *start;
    Prop *prop;
    u32 end;

    if ((arg0 != NULL) && (func_800E9DC4(arg0) != 0)) {
        start = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        for (prop = start; (u32)prop < end; prop++) {
            if (((prop->unk6_0 == 1) || ((prop->unk6_0 == 0) && ((*(u8 *)((s8 *)prop + 0x12) & 1) == 1U))) && (prop->unk6_1 == 6) && (arg1 == prop->ItemID)) {
                return prop;
            }
        }
    }
    return NULL;
}

s32 gspropmarker_entrypoint_1(s16 *arg0, s32 *arg1, Prop **arg2, s32 arg3) { Prop *func_800E9D68(s16 *); u32 func_800E9D90(s16 *); s32 func_800E9DC4(s16 *);
    s32 count = 0;
    s32 pad;
    Prop *start;
    Prop *prop;
    u32 end;
    s32 *id;

    if (arg3 == 0) {
        return 0;
    }
    if ((arg0 != NULL) && (func_800E9DC4(arg0) != 0)) {
        start = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        for (prop = start; ((u32)prop < end) && (count < arg3); prop++) {
            if (((prop->unk6_0 == 1) || ((prop->unk6_0 == 0) && ((*(u8 *)((s8 *)prop + 0x12) & 1) == 1U))) && (prop->unk6_1 == 6)) {
                for (id = arg1; *id != -1; id++) {
                    if (prop->ItemID == *id) {
                        arg2[count++] = prop;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

s32 gspropmarker_entrypoint_2(s16 *arg0, s32 arg1, f32 (*arg2)[3], s32 arg3) { Prop *func_800E9D68(s16 *); u32 func_800E9D90(s16 *); s32 func_800E9DC4(s16 *);
    s32 count = 0;
    Prop *prop;
    u32 end;
    f32 *position;
    if ((arg0 != NULL) && (func_800E9DC4(arg0) != 0)) {
        prop = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        for (; ((u32)prop < end) && (count < arg3); prop++) {
            if (((prop->unk6_0 == 1) || ((prop->unk6_0 == 0) && ((*(u8 *)((s8 *)prop + 0x12) & 1) == 1U))) && (prop->unk6_1 == 6) && (arg1 == prop->ItemID)) {
                position = arg2[count++];
                position[0] = prop->position[0];
                position[1] = prop->position[1];
                position[2] = prop->position[2];
            }
        }
    }
    return count;
}

f32 gspropmarker_entrypoint_3(void *arg0) {
    f32 result;
    u32 value;

    value = *(u32 *)((s8 *)arg0 + 0xC) & 0x7FFFFF;
    if (value != 0) {
        result = (f32)value * 0.01f;
    } else {
        result = 1.0f;
    }
    return result;
}

#endif
