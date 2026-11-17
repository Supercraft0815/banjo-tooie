#include "core2/animation_resource.h"
#include "memory.h"
#include <limits.h>
#include <math.h>

f32 D_80125D70 = 0.9999989867210388f;

static u16 read_be16(const u8 *data) {
    return (u16)((u16)data[0] << 8 | data[1]);
}

s16 *native_animation_decode(const void *data, size_t size) {
    const u8 *bytes = data;
    size_t offset = 8, i, key;
    u16 channels, start, end;
    u16 *words;
    if (!data || size < 8 || size > INT_MAX) return NULL;
    start = read_be16(bytes);
    end = read_be16(bytes + 2);
    channels = read_be16(bytes + 4);
    if (start > end || end > 0x3FFF || !channels || channels > INT16_MAX) return NULL;
    for (i = 0; i < channels; ++i) {
        u16 code, count, previous = 0;
        if (size - offset < 4) return NULL;
        code = read_be16(bytes + offset);
        count = read_be16(bytes + offset + 2);
        if (!(code >> 4) || (code >> 4) >= 109 || (code & 15) > 11 ||
            !count || count > INT16_MAX || count > (size - offset - 4) / 4) return NULL;
        for (key = 0; key < count; ++key) {
            u16 frame = read_be16(bytes + offset + 4 + key * 4) & 0x3FFF;
            /* Shipped resources contain repeated timestamps, including tangent pairs. */
            if (key && frame < previous) return NULL;
            previous = frame;
        }
        offset += 4 + count * 4;
    }
    words = heap_alloc((s32)size);
    rare_memset(words, 0, (s32)size);
    for (i = 0; i < offset / 2; ++i) words[i] = read_be16(bytes + i * 2);
    return (s16 *)words;
}

/* Native C equivalent of the assembly channel sampler in 1EB9DB0.s. */
f32 func_800E04C0(u8 *channel, f32 time, s32 period) {
    const u16 *words = (const u16 *)channel;
    const s16 *keys = (const s16 *)(words + 2);
    s32 last = words[1] - 1, left, right, before, after;
    s32 left_time, right_time, p0, p1, p2, p3;
    u32 frame = (u32)(s32)time;
    u32 flags;
    f32 t = 1.0f, value;
    /* Keys are value * 64 (BK animationfile.c divides by 64); cubic adds the Catmull-Rom 1/2. */
    if (last == 0) return keys[1] * (1.0f / 64.0f);
    if (frame < (u32)(keys[0] & 0x3FFF)) {
        right = 0;
        left = period ? last : right;
        right_time = keys[0] & 0x3FFF;
        left_time = (keys[left * 2] & 0x3FFF) - (period ? period : 0);
    } else if (frame >= (u32)(keys[last * 2] & 0x3FFF)) {
        left = last;
        right = period ? 0 : left;
        left_time = keys[left * 2] & 0x3FFF;
        right_time = (keys[right * 2] & 0x3FFF) + (period ? period : 0);
    } else {
        left = 0;
        right = last;
        while (right - left > 1) {
            s32 middle = left + (right - left) / 2;
            if (frame < (u32)(keys[middle * 2] & 0x3FFF)) right = middle;
            else left = middle;
        }
        left_time = keys[left * 2] & 0x3FFF;
        right_time = keys[right * 2] & 0x3FFF;
    }
    if ((u32)right_time >= frame && right_time != left_time)
        t = (time - left_time) / (f32)(right_time - left_time);
    flags = (keys[left * 2] & 0x4000) | (keys[right * 2] & 0x8000);
    before = left;
    after = right;
    if (flags & 0x4000) before = left ? left - 1 : (period ? last : 0);
    if (flags & 0x8000) after = right < last ? right + 1 : (period ? 0 : last);
    p0 = keys[before * 2 + 1];
    p1 = keys[left * 2 + 1];
    p2 = keys[right * 2 + 1];
    p3 = keys[after * 2 + 1];
    if ((words[0] & 15) >= 9) {
        s32 values[4] = {p0, p1, p2, p3};
        s32 unwrapped[4] = {p0, 0, 0, 0};
        s32 i;
        for (i = 1; i < 4; ++i) {
            s32 delta = values[i] - values[i - 1];
            if ((u32)(delta + 0x5A00) > 0xB400) delta += delta < 0 ? 0xB400 : -0xB400;
            unwrapped[i] = unwrapped[i - 1] + delta;
        }
        p1 = unwrapped[1]; p2 = unwrapped[2]; p3 = unwrapped[3];
    }
    if (flags) {
        f32 a = (p3 - p0) - 3 * (p2 - p1);
        f32 b = 2 * p0 + 4 * (p2 - p1) - p1 - p3;
        f32 c = p2 - p0;
        value = (((a * t + b) * t + c) * t + 2 * p1) * (1.0f / 128.0f);
    } else {
        f32 first = p1 * (1.0f / 64.0f);
        f32 second = p2 * (1.0f / 64.0f);
        value = first + (second - first) * t;
    }
    if ((words[0] & 15) >= 9) {
        s32 negative = value < 0;
        value -= truncf(value * 0.0027777778450399637f) * 360.0f;
        if (negative) value += 360.0f;
    }
    return value;
}

void func_800E084C(BoneTransformList *poses, f32 *transform, u32 group) {
    void func_800D952C(f32[4], f32[3]);
    BoneTransform *bone = &poses->ptr[group];
    s32 i;
    for (i = 0; i < 3; ++i) {
        bone->scale[i] = transform[i + 3];
        bone->unk1C[i] = transform[i + 6];
    }
    func_800D952C(bone->unk0, transform);  /* 1EB9DB0.s inlines this variant, not 800D93A0 */
}
