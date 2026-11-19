#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_gsfile.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"

void gsmaker_entrypoint_0(void *context) {
    GsFile *file = context;
    if (!file) return;
    if (file->mode == 2) {
        func_800D721C(file->asset_id, 0);
        func_800D70F8(file->asset_id, 0);
        func_800D6CEC(file->asset_id);
    } else if (file->mode == 4) {
        heap_free(file->base_ptr);
    }
    heap_free(file);
}

GsFile *gsmaker_entrypoint_1(s32 id) {
    GsFile *file;
    u8 *asset;
    if (id < 0 || id > INT16_MAX || id >= native_asset_count()) return NULL;
    /* The original cache has four-bit pin counters. */
    if (!native_asset_can_pin(id)) return NULL;
    asset = (u8 *)func_800D674C(id);
    if (!asset) return NULL;
    file = heap_alloc(sizeof(*file));
    *file = (GsFile){0};
    file->mode = 2;
    file->last_expected = file->unk1C = -1;
    file->asset_id = id;
    file->asset_base_ptr = file->asset_current_ptr = asset;
    file->end_ptr = asset + native_asset_cached_size(id);
    func_800D70D0(1);
    func_800D71F4(1);
    return file;
}

GsFile *gsmaker_entrypoint_2(s32 id) {
    return gsmaker_entrypoint_3(id, 0x955);
}

GsFile *gsmaker_entrypoint_3(s32 id, s32 offset) {
    s64 sum = (s64)id + offset;
    return sum >= 0 && sum <= INT16_MAX ? gsmaker_entrypoint_1((s32)sum) : NULL;
}

GsFile *gsmaker_entrypoint_4(void *buffer, s32 length) {
    GsFile *file;
    if (length < 0 || (!buffer && length)) return NULL;
    file = heap_alloc(sizeof(*file));
    *file = (GsFile){0};
    file->mode = 3;
    file->last_expected = file->unk1C = -1;
    file->base_ptr = file->current_ptr = buffer;
    file->end_ptr = length ? (u8 *)buffer + length : buffer;
    return file;
}

GsFile *gsmaker_entrypoint_5(void) {
    GsFile *file = gsmaker_entrypoint_4(heap_alloc(32), 32);
    file->mode = 4;
    return file;
}

void gsmaker_entrypoint_6(GsFile *file, void **dst, s32 *size) {
    if (dst) *dst = NULL;
    if (size) *size = 0;
    if (file && file->mode == 4 && !file->failed && dst && size) {
        *size = file->current_ptr - file->base_ptr;
        *dst = heap_realloc(file->base_ptr, *size);
        file->base_ptr = NULL;
    }
    gsmaker_entrypoint_0(file);
}

void gsmaker_entrypoint_13(GsFile *file, void *data, s32 length) {
    u8 *current;
    s32 offset, capacity, needed;
    if (!file || file->failed) return;
    if (length < 0 || (!data && length) || file->mode < 2 || file->mode > 4) {
        file->failed = 1;
        return;
    }
    if (!length) return;
    current = file->mode == 2 ? file->asset_current_ptr : file->current_ptr;
    if (file->mode != 4) {
        if (!current || length > file->end_ptr - current) {
            file->failed = 1;
            return;
        }
        rare_memcpy(data, current, length);
        if (file->mode == 2) file->asset_current_ptr += length;
        else file->current_ptr += length;
        return;
    }
    offset = current - file->base_ptr;
    capacity = file->end_ptr - file->base_ptr;
    if (length > INT32_MAX - offset) {
        file->failed = 1;
        return;
    }
    needed = offset + length;
    if (needed > capacity) {
        while (capacity < needed) capacity = capacity > INT32_MAX / 2 ? needed : capacity * 2;
        file->base_ptr = heap_realloc(file->base_ptr, capacity);
        file->current_ptr = file->base_ptr + offset;
        file->end_ptr = file->base_ptr + capacity;
    }
    rare_memcpy(file->current_ptr, data, length);
    file->current_ptr += length;
}

/* Raw blocks retain their file layout; only scalar accessors convert byte order. */
static void native_gsfile_scalar(GsFile *file, void *data, s32 width) {
    u8 bytes[4];
    u16 half;
    u32 value = 0;
    s32 i;
    if (!file || file->failed) return;
    if (!data) { file->failed = 1; return; }
    if (file->mode == 4) {
        if (width == 2) { rare_memcpy(&half, data, 2); value = half; }
        else rare_memcpy(&value, data, 4);
        for (i = 0; i < width; ++i) bytes[i] = value >> ((width - i - 1) * 8);
        gsmaker_entrypoint_13(file, bytes, width);
    } else {
        gsmaker_entrypoint_13(file, bytes, width);
        if (file->failed) return;
        for (i = 0; i < width; ++i) value = (value << 8) | bytes[i];
        if (width == 2) { half = value; rare_memcpy(data, &half, 2); }
        else rare_memcpy(data, &value, 4);
    }
}

static void native_gsfile_array(GsFile *file, void *data, s32 count, s32 width) {
    s32 i;
    if (!file || file->failed) return;
    if (count < 0 || count > INT32_MAX / width || (!data && count)) {
        file->failed = 1;
        return;
    }
    for (i = 0; i < count && !file->failed; ++i)
        native_gsfile_scalar(file, (u8 *)data + i * width, width);
}

void gsmaker_entrypoint_7(GsFile *file, void *data) {
    gsmaker_entrypoint_13(file, data, 1);
}
void gsmaker_entrypoint_8(GsFile *file, void *data, s32 count) {
    gsmaker_entrypoint_13(file, data, count);
}
void gsmaker_entrypoint_9(GsFile *file, void *data) {
    native_gsfile_scalar(file, data, 4);
}
void gsmaker_entrypoint_10(GsFile *file, void *data, s32 count) {
    native_gsfile_array(file, data, count, 4);
}
void gsmaker_entrypoint_11(GsFile *file, void *data) {
    native_gsfile_scalar(file, data, 4);
}
void gsmaker_entrypoint_12(GsFile *file, void *data, s32 count) {
    native_gsfile_array(file, data, count, 4);
}
void gsmaker_entrypoint_14(GsFile *file, void *data) {
    native_gsfile_scalar(file, data, 2);
}
void gsmaker_entrypoint_15(GsFile *file, void *data, s32 count) {
    native_gsfile_array(file, data, count, 2);
}

s32 gsmaker_entrypoint_16(GsFile *file, s32 expected) {
    u8 tag = expected;
    if (!file || file->failed) return 0;
    if (file->mode == 4) {
        gsmaker_entrypoint_7(file, &tag);
        return !file->failed;
    }
    if (file->last_expected == -1) {
        gsmaker_entrypoint_7(file, &tag);
        if (file->failed) return 0;
        if (expected == tag) return 1;
        file->last_expected = tag;
        return 0;
    }
    if (expected == file->last_expected) {
        file->last_expected = -1;
        return 1;
    }
    return 0;
}

s32 gsmaker_entrypoint_17(GsFile *file, s32 expected, void *data) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_7(file, data);
    return !file->failed;
}

s32 gsmaker_entrypoint_18(GsFile *file, s32 expected, void *data, s32 count) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_8(file, data, count);
    return !file->failed;
}

s32 gsmaker_entrypoint_19(GsFile *file, s32 expected, void *data) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_9(file, data);
    return !file->failed;
}

s32 gsmaker_entrypoint_20(GsFile *file, s32 expected, void *data, s32 count) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_10(file, data, count);
    return !file->failed;
}

s32 gsmaker_entrypoint_21(GsFile *file, s32 expected, void *data) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_11(file, data);
    return !file->failed;
}

s32 gsmaker_entrypoint_22(GsFile *file, s32 expected, void *data, s32 count) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_12(file, data, count);
    return !file->failed;
}

s32 gsmaker_entrypoint_23(GsFile *file, s32 expected, void *data, s32 count) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_13(file, data, count);
    return !file->failed;
}

s32 gsmaker_entrypoint_24(GsFile *file, s32 expected, void *data) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_14(file, data);
    return !file->failed;
}

s32 gsmaker_entrypoint_25(GsFile *file, s32 expected, void *data, s32 count) {
    if (!gsmaker_entrypoint_16(file, expected)) return 0;
    gsmaker_entrypoint_15(file, data, count);
    return !file->failed;
}

#else
#include "common.h"

typedef struct {
    void *asset_base_ptr;
    void *asset_current_ptr;
    void *base_ptr;
    void *current_ptr;
    void *end_ptr;
    s32 mode;
    s32 last_expected;
    s32 unk1C;
    s16 asset_id;
    s16 pad22;
} GsFile;

void gsmaker_entrypoint_13(GsFile *, void *, s32);

// void stuff() {
    
// }

/* extern */

void gsmaker_entrypoint_0(void *arg0) {
    s32 func_800D6CEC(BT_IDO_ONLY(s16) BT_NATIVE_ONLY(s32));
    s32 func_800D70F8(BT_IDO_ONLY(s16) BT_NATIVE_ONLY(s32), s32);
    s32 func_800D721C(BT_IDO_ONLY(s16) BT_NATIVE_ONLY(s32), s32);
    void heap_free(void *);
    if ((((GsFile *)arg0)->mode) == 2) {
        func_800D721C((((GsFile *)arg0)->asset_id), 0);
        func_800D70F8((((GsFile *)arg0)->asset_id), 0);
        func_800D6CEC((((GsFile *)arg0)->asset_id));
    }
    heap_free(arg0);
}

GsFile *gsmaker_entrypoint_1(s32 arg0) {
    void *func_800D674C(s32);
    void *heap_alloc(s32);
    void heap_free(void *);
    void func_800D70D0(s32);
    void func_800D71F4(s32);
    GsFile *this;

    this = heap_alloc(sizeof(GsFile));
    if (this == NULL) {
        return NULL;
    }
    this->mode = 2;
    this->last_expected = -1;
    this->unk1C = -1;
    this->asset_id = arg0;
    this->asset_base_ptr = func_800D674C(this->asset_id);
    this->asset_current_ptr = this->asset_base_ptr;
    func_800D70D0(1);
    func_800D71F4(1);
    if (this->asset_base_ptr != NULL) {
        return this;
    }
    heap_free(this);
    return NULL;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(GsFile *) gsmaker_entrypoint_2(s32 arg0) {
    GsFile *gsmaker_entrypoint_1(s32);
    BT_NATIVE_ONLY(return) gsmaker_entrypoint_1(arg0 + 0x955);
}

/* extern */

void gsmaker_entrypoint_3(s32 arg0, s32 arg1) {
    GsFile *gsmaker_entrypoint_1(s32);
    gsmaker_entrypoint_1(arg0 + arg1);
}

void gsmaker_entrypoint_4(s32 arg0, s32 arg1) {
    void* heap_alloc(s32 size);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 3;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0x10))) = (s32) (arg0 + arg1);
}

u8 *gsmaker_entrypoint_5(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;
    u8 *temp_v0_2;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 4;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    sp1C = temp_v0;
    temp_v0_2 = heap_alloc(0x20);
    (*(u8 **)((s8 *)(sp1C) + (8))) = temp_v0_2;
    (*(u8 **)((s8 *)(sp1C) + (0xC))) = temp_v0_2;
    (*(s32 *)((s8 *)(sp1C) + (0x10))) = (s32) (temp_v0_2 + 0x20);
    return sp1C;
}

void gsmaker_entrypoint_6(GsFile *file, void **dst, s32 *size) {
    void *heap_realloc(void *, s32);
    *size = (u32)file->current_ptr - (u32)file->base_ptr;
    *dst = heap_realloc(file->base_ptr, *size);
    file->base_ptr = NULL;
    gsmaker_entrypoint_0(file);
}

void gsmaker_entrypoint_7(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x1);
}

void gsmaker_entrypoint_8(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_7(file, dst);
        count--;
        dst += 1;
    }
}

void gsmaker_entrypoint_9(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x4);
}

void gsmaker_entrypoint_10(s32 arg0, s32 arg1, s32 arg2) {
    while (arg2 > 0) {
        gsmaker_entrypoint_9(arg0, arg1);
        arg2--;
        arg1 += 4;
    }
}

void gsmaker_entrypoint_11(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x4);
}

void gsmaker_entrypoint_12(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_11(file, dst);
        count--;
        dst += 4;
    }
}

void gsmaker_entrypoint_13(GsFile *file, void *dst, s32 len) {
    void *heap_realloc(void *, s32);
    void rare_memcpy(void *, void *, s32);
    u32 curr_offset;
    u32 capacity;
    void *new_base_ptr;

    if (file->mode == 2) {
        rare_memcpy(dst, file->asset_current_ptr, len);
        file->asset_current_ptr = (void *) ((u32)file->asset_current_ptr + len);
    }
    else if (file->mode == 3) {
        rare_memcpy(dst, file->current_ptr, len);
        file->current_ptr = (void *) ((u32)file->current_ptr + len);
    }
    else if (file->mode == 4) {
        if ((u8 *) file->end_ptr < (u8 *) file->current_ptr + len) {
            curr_offset = (u8 *) file->current_ptr - (u8 *) file->base_ptr;
            capacity = ((u8 *) file->end_ptr - (u8 *) file->base_ptr) * 2;

            while (((u8 *) file->base_ptr + capacity) < ((u8*) file->current_ptr + len)) {
                capacity *= 2;
            }

            new_base_ptr = heap_realloc(file->base_ptr, capacity);
            file->base_ptr = new_base_ptr;
            file->current_ptr = (u8 *) new_base_ptr + curr_offset;
            file->end_ptr = (u8 *) new_base_ptr + capacity;
        }

        rare_memcpy(file->current_ptr, dst, len);
        file->current_ptr = (u8 *) file->current_ptr + len;
    }
}

void gsmaker_entrypoint_14(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x2);
}

void gsmaker_entrypoint_15(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_14(file, dst);
        count--;
        dst += 2;
    }
}

s32 gsmaker_entrypoint_16(GsFile *file, s32 expected) {
    u8 saved_expected;

    saved_expected = expected;

    if ((file->mode == 1) || (file->mode == 4)) {
        gsmaker_entrypoint_7((s32)file, (s32)&saved_expected);
        return 1;
    }

    if (file->last_expected == -1) {
        gsmaker_entrypoint_7((s32)file, (s32)&saved_expected);

        if (expected == saved_expected) {
            return 1;
        }

        file->last_expected = saved_expected;
        return 0;
    }

    if (expected == file->last_expected) {
        file->last_expected = -1;
        return 1;
    }

    return 0;
}

/* extern */

s32 gsmaker_entrypoint_17(s32 arg0, s32 arg1, s32 arg2) {
    s32 gsmaker_entrypoint_16();
    if (gsmaker_entrypoint_16((GsFile *)arg0, arg1) == 0) {
        return 0;
    }
    gsmaker_entrypoint_7(arg0, arg2);
    return 1;
}

/* extern */

s32 gsmaker_entrypoint_18(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    void gsmaker_entrypoint_8(s32, s32, s32);
    if (gsmaker_entrypoint_16((GsFile *)file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_8(file, dst, count);
    return 1;
}

s32 gsmaker_entrypoint_19(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_9(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_20(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_10(file, dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_21(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_11(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_22(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_12(file, dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_23(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_13((GsFile *)file, (void *)dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_24(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_14(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_25(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_15(file, dst, count);
        return 1;
    }
}

#endif
