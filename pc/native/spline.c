#include "native_spline.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"

s32 D_8011B920;

#ifndef BT_ILP32
void native_spline_clear_commands(NativeSplineContext *context) {
    heap_free(context->offsets);
    heap_free(context->commands);
    context->offsets = NULL;
    context->commands = NULL;
    context->command_size = context->unk1A0 = context->asset = 0;
    rare_memset(context->counters, 0, sizeof(context->counters));
    rare_memset(context->initial_counters, 0, sizeof(context->initial_counters));
}

int native_spline_load_commands(NativeSplineContext *context, s32 id) {
    const u8 *bytes = (u8 *)func_800D674C(id);
    s32 size = native_asset_cached_size(id), i;
    native_spline_clear_commands(context);
    if (!bytes || size < 12 || size % 4) return 0;
    context->commands = heap_alloc(size);
    context->command_size = size;
    context->asset = id;
    for (i = 0; i < size / 4; ++i) {
        context->commands[i] = (u32)bytes[i * 4] << 24 | (u32)bytes[i * 4 + 1] << 16 |
                               (u32)bytes[i * 4 + 2] << 8 | bytes[i * 4 + 3];
    }
    return 1;
}

Actor *native_spline_actor(NativeSplineContext *context, Actor *current, s32 id) {
    Actor *func_80106790(Unk80132ED0 *);
    if (!id) return current;
    if (id < 0 || id >= 33 || !context->actors[id]) return NULL;
    return func_80106790(context->actors[id]);
}

s32 *native_spline_script(NativeSplineContext *context, s32 id, s32 *count) {
    s32 offset, end;
    s32 *script;
    if (!context->commands || !context->offsets || id < 1 || id > context->unk1A0) return NULL;
    offset = context->offsets[id - 1];
    end = id == context->unk1A0 ? context->command_size : context->offsets[id];
    if (offset < 0 || offset % 4 || end % 4 || end > context->command_size || end < offset || end - offset < 12) return NULL;
    script = (s32 *)((u8 *)context->commands + offset);
    if (*script != 0x10005 && *script != 0x10006) return NULL;
    *count = (end - offset) / 4;
    return script;
}

s32 native_spline_command_words(s32 *script, s32 count, s32 index) {
    s32 words = 2;
    if (index < 1 || index > 0x1FFF || index >= count - 1) return 0;
    switch ((u32)script[index + 1] >> 16) {
        case 0xE: case 0xF: case 0x24: case 0x29: words = 3; break;
        case 0x26: case 0x27: words = 4; break;
    }
    return words <= count - index && words <= 0x2000 - index ? words : 0;
}
#endif
