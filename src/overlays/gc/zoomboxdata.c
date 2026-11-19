#include "common.h"
typedef struct {
    s16 sound;
    s16 rate;
    f32 volume;
} ZoomSound;

typedef struct {
    u16 asset;
    s8 x;
    s8 y;
    ZoomSound *sounds;
    u8 count;
    u8 padding[3];
} ZoomEntry;
void gczoomboxdata_entrypoint_0(s32 arg0) {
    u8 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C34CC(u8, s32);
    void func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    s32 func_800C42E0(s32);
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
    void func_800FC6B0(u32);
    s32 func_800FCCD4(s32);
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];

    s32 choice;
    ZoomEntry *entry;
    ZoomSound *selected;
    s32 rate;
    f32 volume;
    f32 lower = 0.2f;
    f32 upper = 0.0f;
    f32 low;
    f32 high;
    u8 id;

    entry = &D_80800AA8_gczoomboxdata[arg0];
    if (entry->sounds != NULL && entry->count != 0) {
        if (entry->sounds->volume == -1.0f) {
            if (!func_800FCCD4(entry->sounds->sound)) {
                func_800FC6B0(entry->sounds->sound);
            }
        } else {
            do {
                choice = func_800DC214(0, entry->count);
                selected = &entry->sounds[choice];
                rate = selected->rate;
            } while (!rate);
            volume = selected->volume;
            if (volume - lower < 0.1f) {
                low = 0.1f;
            } else {
                low = volume - lower;
            }
            if (low >= 2.0f) {
                low = 1.99f;
            }
            if (volume - upper < 2.0f) {
                high = volume - upper;
            } else {
                high = 2.0f;
            }
            if (!(high > 0.1f)) {
                high = 0.1f;
            }
            if (id = func_800C2E04()) {
                s32 minRate;
                s32 maxRate = 0;
                func_800C301C(id, entry->sounds[choice].sound);
                minRate = rate - 6000 < 0 ? 0 : rate - 6000;
                if (rate - maxRate < 0) {
                    maxRate = 0;
                } else {
                    maxRate = rate - maxRate;
                }
                func_800C3058(id, func_800DC214(minRate, maxRate));
                func_800C31DC(id, func_800DC264(low, high));
                func_800C330C(id, 1);
                func_800C3418(id, 0);
                func_800C34CC(id, 0);
                if (func_800C42E0(entry->sounds[choice].sound)) {
                    func_800C3A40(id, 0.1f, 0.5f, 0.1f);
                }
                func_800C3BDC(id);
            }
        }
    }
}

u16 gczoomboxdata_entrypoint_1(s32 arg0) {
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];
    return D_80800AA8_gczoomboxdata[arg0].asset;
}

void gczoomboxdata_entrypoint_2(s32 arg0, s8 *arg1, s8 *arg2) {
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];

    ZoomEntry *entry;

    entry = &D_80800AA8_gczoomboxdata[arg0];
    *arg1 = entry->x;
    *arg2 = entry->y;
}

u8 gczoomboxdata_entrypoint_3(s32 arg0) {
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];
    return D_80800AA8_gczoomboxdata[arg0].count;
}

void gczoomboxdata_entrypoint_4(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, f32 *arg4) {
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];
    ZoomEntry *entry;
    entry = &D_80800AA8_gczoomboxdata[arg0];
    *arg2 = entry->sounds[arg1].sound;
    *arg3 = entry->sounds[arg1].rate;
    *arg4 = entry->sounds[arg1].volume;
}

s32 gczoomboxdata_entrypoint_5(register s32 arg0) {
    s32 func_800D58FC(BtIntPtr arg0);
    extern ZoomEntry D_80800AA8_gczoomboxdata[210];
    union { struct { u16 pad; u16 value; } write; struct { u16 pad; volatile u16 value; } read; } saved;
    u16 asset;
    s32 flag;
    if (arg0 == 0x44) {
        return 0;
    }

    arg0 *= sizeof(ZoomEntry);
    asset = ((ZoomEntry *)((u8 *)D_80800AA8_gczoomboxdata + arg0))->asset;
    if (asset == 0 || (saved.write.value = asset, flag = func_800D58FC(asset), asset = saved.read.value, flag == 4)) {
        return 0;
    }
    return asset;
}

/* extern */

s32 gczoomboxdata_entrypoint_6(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 gczoomboxdata_entrypoint_5();
    s32 temp_v0;

#ifdef BT_NATIVE
    temp_v0 = ((s32 (*)())gczoomboxdata_entrypoint_5)(bt_a0);
#else
    temp_v0 = gczoomboxdata_entrypoint_5();
#endif
    if ((temp_v0 == 0) || (temp_v0 == 0xBAE)) {
        return 0;
    }
    return 1;
}

#include "zoomboxdata_data.inc"
