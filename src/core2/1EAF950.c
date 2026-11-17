#include "core2/1EAF950.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_assets.h"
#include "native_spline.h"
#include "native_actor.h"
#include "native_marker.h"
NativeSplineContext native_spline_context;
#define D_8012BE70 native_spline_context
#define D_8012BFF4 native_spline_context.handle0
#define D_8012BFF6 native_spline_context.handle1
#define D_8012BFFC native_spline_context.pad18C
#define D_8012BF70 native_spline_context.actors
#define D_8012C000 native_spline_context.value0
#define D_8012C014 native_spline_context.cache
struct NativeAssetEntry {
    u32 frame : 27;
    u32 type : 4;
    u32 low : 1;
    ImageStruct *image;
    u32 id : 14;
    u32 used : 1;
    u32 twice : 1;
    u32 hi : 4;
    u32 lo : 4;
    u32 handle : 8;
};
static struct NativeAssetEntry native_asset_cache[136];
s16 D_8012BE60, D_8012BE62, D_8012BE64;
#define D_8012B800 ((u8 *)native_asset_cache)
#define Entry NativeAssetEntry
#define ReleaseEntry NativeAssetEntry
#define CacheEntry NativeAssetEntry
#define CACHE_ENTRY_SIZE sizeof(struct NativeAssetEntry)
#define CACHE_INFO(p) ((u32)((struct NativeAssetEntry *)(p))->id << 18)
#define CACHE_TYPE(p) (((struct NativeAssetEntry *)(p))->type)
#else
extern u8 D_8012B800[];
#define SPLINE_ACTOR(actor, field, original) (original)
#define SPLINE_FIELD(ctx, field, original) (original)
#define CACHE_ENTRY_SIZE 12
#define CACHE_INFO(p) (*(u32 *)((p) + 8))
#define CACHE_TYPE(p) ((*(u32 *)(p) << 27) >> 28)
#endif

struct Unk800C7A68;

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BE70;
#endif

s16 D_8011B910 = -1;

s32 func_800D6060(s32 arg0) {
    void aligned4_memmove(void *, void *, int);
    extern s16 D_8012BE62;
    s32 mid;
    u32 size = CACHE_ENTRY_SIZE;
    {
    u32 value;
    s32 high;
    s32 low;

    high = D_8012BE62 - 1;
    mid = 0;
    low = 0;
    while (high >= low) {
        mid = (high + low) >> 1;
        value = CACHE_INFO(D_8012B800 + mid * size);
        if ((s32)(value >> 18) < arg0) {
            low = mid + 1;
            if (low < D_8012BE62) {
                if (arg0 < (s32)(CACHE_INFO(D_8012B800 + low * size) >> 18)) {
                    mid = low;
                    break;
                }
            } else {
                mid = D_8012BE62;
                break;
            }
        } else {
            high = mid - 1;
            if (high >= 0) {
                if ((s32)(CACHE_INFO(D_8012B800 + high * size) >> 18) < arg0) {
                    break;
                }
            } else {
                mid = 0;
                break;
            }
        }
    }
    }
    if (mid < 0) {
        mid = 0;
    } else if (D_8012BE62 < mid) {
        mid = D_8012BE62;
    }
    if (mid < D_8012BE62) {
        s32 remaining = D_8012BE62 - mid;
        aligned4_memmove(D_8012B800 + mid * size + size, D_8012B800 + mid * size, remaining * size);
    }
    return mid;
}

void func_800D61B4(u8 *arg0) {
    void aligned4_memmove(void *, void *, int);
    extern s16 D_8012BE62;
    int remaining;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 unused0 : 27;
        u32 type : 4;
        u32 unused1 : 1;
        u32 unused4;
        u16 id : 14;
        u16 unused8 : 2;
        u16 unusedA;
    };
#endif
    struct Entry *last;

    remaining = D_8012BE62 - ((struct Entry *)arg0 - (struct Entry *)D_8012B800) - 1;
    if (remaining > 0) {
        aligned4_memmove(arg0, arg0 + CACHE_ENTRY_SIZE, remaining * CACHE_ENTRY_SIZE);
    }
    D_8012BE62--;
    ((struct Entry *)D_8012B800)[D_8012BE62].type = 0;
    ((struct Entry *)D_8012B800)[D_8012BE62].id = 0x3FFF;
}

s32 func_800D6254(s32 arg0) {
    extern s16 D_8012BE62;
    s32 high = D_8012BE62 - 1;
    s32 low = 0;
    s32 mid;
    s32 value;
    s32 size = CACHE_ENTRY_SIZE;
    while (low <= high) {
        mid = (high + low) >> 1;
        value = CACHE_INFO(D_8012B800 + mid * size) >> 18;
        if (value < arg0) {
            low = mid + 1;
        } else if (arg0 < value) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void func_800D62E4(s32 arg0) {
    extern s16 D_8012BE64;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 unused : 27;
        u32 type : 4;
        u32 low : 1;
        s32 image;
        u32 id : 14;
        u32 used : 1;
        u32 twice : 1;
        u32 tail : 16;
    };
#endif
    struct Entry *ptr;

    if (D_8012BE64 != 0) {
        ptr = (struct Entry *)(D_8012B800 + func_800D6254(arg0) * CACHE_ENTRY_SIZE);
        if (ptr->type == 2 && ptr->used && !ptr->twice) {
            ptr->used = 0;
        }
        D_8012BE64 = 0;
    }
}

s32 func_800D6378(u8 *arg0) {
    s32 func_800D56C4(void *arg0);
    void func_800DBB9C(u8 arg0);
    s32 result[1];
    int handle;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 unused : 27;
        u32 type : 4;
        u32 low : 1;
        void *image;
        u8 unused2[3];
        u8 handle;
    };
#endif
    struct Entry *ptr = (struct Entry *)arg0;
    switch (ptr->type) {
        case 2:
            result[0] = func_800D56C4(ptr->image);
            if ((handle = ptr->handle) != 0) {
                func_800DBB9C(handle);
                ptr->handle = 0;
            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            result[0] = func_800D56C4(ptr->image);
            break;
        case 1:
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
            result[0] = func_800D56C4(ptr->image);
#endif
            break;
    }
    func_800D61B4(arg0);
    return result[0];
}

s32 func_800D6408(void *arg0) {
    s32 func_8001211C(void);
    s32 func_800D56C4(void *);
    void func_800D5E54(void *);
    void func_800DBB9C(u8);
    /* Original leaves this result slot untouched for flag 1/default. */
    s32 result BT_NATIVE_ONLY(= 0);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct ReleaseEntry {
        u32 frame : 27;
        u32 type : 4;
        u32 low : 1;
        void *image;
        u32 id : 14;
        u32 used : 1;
        u32 twice : 1;
        u8 unused;
        u8 handle;
    };
#endif
    struct ReleaseEntry *ptr = arg0;
    int token;

    switch (ptr->type) {
        case 1:
#ifdef BT_NATIVE // ILP32 too: guard or init the original lacks
            result = func_800D56C4(ptr->image);
#endif
            break;
        case 6:
        case 7:
            result = (s32)ptr->frame + 1 < func_8001211C()
                ? func_800D56C4(ptr->image)
                : (func_800D5E54(ptr->image), -1);
            break;
        case 2:
            if ((s32)ptr->frame + 1 < func_8001211C()) {
                result = func_800D56C4(ptr->image);
            } else if (!ptr->used && !ptr->twice && !ptr->low) {
                result = func_800D56C4(ptr->image);
            } else {
                func_800D5E54(ptr->image);
                result = -1;
            }
            if ((token = ptr->handle) != 0) {
                func_800DBB9C(token);
                ptr->handle = 0;
            }
            break;
        case 3:
        case 4:
        case 5:
        case 8:
        case 9:
            result = func_800D56C4(ptr->image);
            break;
    }
    func_800D61B4(arg0);
    return result;
}

s32 func_800D6550(void *arg0) {
    s32 func_8001211C(void);
    int func_800D5E94(void *);
    void *func_800D5804(void *, s32);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 frame : 27;
        u32 type : 4;
        u32 low : 1;
        void *image;
        u32 id : 14;
        u32 used : 1;
        u32 twice : 1;
        u32 tail : 16;
    };
#endif
    struct Entry *ptr = arg0;
    switch (ptr->type) {
        case 1:
        case 9:
            return 0;
        case 3:
        case 4:
        case 5:
        case 8:
            if (!func_800D5E94(ptr->image)) {
                ptr->image = func_800D5804(ptr->image, 1);
            }
            return 1;
        case 6:
        case 7:
            if ((s32)ptr->frame + 1 < func_8001211C()) {
                ptr->image = func_800D5804(ptr->image, 1);
                return 1;
            }
            return 0;
        case 2:
            if ((s32)ptr->frame + 1 < func_8001211C()) {
                if (!func_800D5E94(ptr->image)) {
                    ptr->image = func_800D5804(ptr->image, 1);
                }
            } else if (!ptr->used && !ptr->twice && !ptr->low) {
                if (!func_800D5E94(ptr->image)) {
                    ptr->image = func_800D5804(ptr->image, 1);
                }
                return 1;
            } else {
                return 0;
            }
            break;
    }
    return 0;
}

void func_800D66AC(void) {
    extern s16 D_8011B910;
    extern s16 D_8012BE60;
    extern s16 D_8012BE62;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 unused : 27;
        u32 type : 4;
        u32 low : 1;
        s32 image;
        u16 id : 14;
        u16 low2 : 2;
        s16 tail;
    };
#endif
    struct Entry *ptr;

    s32 i;

    ptr = (struct Entry *)D_8012B800;
    for (i = 0; i < 136; i++) {
        ptr[i].type = 0;
        ptr[i].id = -1;
        ptr[i].image = 0;
    }
    D_8011B910 = -1;
    D_8012BE62 = 0;
}

s32 func_800D58FC(BtIntPtr);

ImageStruct *func_800D674C(s32 a0) {
    extern s16 D_8011B910;
    extern s16 D_8012BE62;
    extern s16 D_8012BE64;
    s32 func_8001211C(void);
    void *func_800D5B34(s32);
    u8 func_800DBA84(void);
    void func_800DBBF8(u8, void *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 frame : 27;
        u32 type : 4;
        u32 low : 1;
        ImageStruct *image;
        u32 id : 14;
        u32 used : 1;
        u32 twice : 1;
        u32 hi : 4;
        u32 lo : 4;
        u32 handle : 8;
    };
#endif
    s32 index;
    s32 type;
    struct Entry *entry;
    ImageStruct *image;
    void *aux;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    NativeModelAnimationChannel native_aux[7];
    s32 decoded;
#endif

    index = func_800D6254(a0);
    if (index != -1) {
        D_8011B910 = index;
        D_8012BE64 = a0;
        if (((struct Entry *)D_8012B800)[index].type == 2) {
            if (func_8001211C() == ((struct Entry *)D_8012B800)[index].frame) {
                if (((struct Entry *)D_8012B800)[index].used) {
                    ((struct Entry *)D_8012B800)[index].twice = 1;
                } else {
                    ((struct Entry *)D_8012B800)[index].used = 1;
                }
            } else {
                if (func_8001211C() == ((struct Entry *)D_8012B800)[index].frame + 1) {
                    ((struct Entry *)D_8012B800)[index].low = ((struct Entry *)D_8012B800)[index].used || ((struct Entry *)D_8012B800)[index].twice;
                }
                ((struct Entry *)D_8012B800)[index].used = 1;
                ((struct Entry *)D_8012B800)[index].twice = 0;
            }
        }
        ((struct Entry *)D_8012B800)[index].frame = func_8001211C();
        return ((struct Entry *)D_8012B800)[index].image;
    }
    if ((u32)D_8012BE62 >= 135U) {
        return NULL;
    }
    type = func_800D58FC(a0);
    image = func_800D5B34(a0);
    if (image == NULL) {
        D_8012BE64 = 0;
        return NULL;
    }
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32: the model animation stays raw (original code below)
    aux = NULL;
    if (type == 0) {
        decoded = native_asset_model_animation(a0, image, native_aux);
        if (decoded < 0) { func_800D56C4(image); return NULL; }
        if (decoded) aux = native_aux;
    }
#endif
    index = func_800D6060(a0);
    entry = &((struct Entry *)D_8012B800)[index];
    D_8012BE62++;
    D_8011B910 = index;
    entry->frame = func_8001211C();
    entry->image = image;
    entry->hi = 0;
    entry->lo = 0;
    entry->id = a0;
    D_8012BE64 = a0;
    switch (type) {
        case 0:
            entry->type = 2;
            entry->used = 1;
            entry->twice = 0;
            entry->handle = 0;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
            aux = *(s32 *)((u8 *)entry->image + 0x2C) ? (void *)&entry->image->pad[*(s32 *)((u8 *)entry->image + 0x2C)] : NULL;
#endif
            if (aux != NULL) {
                entry->handle = func_800DBA84();
                func_800DBBF8(entry->handle, aux);
            }
            break;
        case 1: entry->type = 1; break;
        case 3:
        case 10: entry->type = 4; break;
        case 5: entry->type = 3; break;
        case 6: entry->type = 5; break;
        case 7: entry->type = 6; break;
        case 8: entry->type = 7; break;
        case 2: entry->type = 8; break;
        case 9: entry->type = 9; break;
    }
    return image;
}

void *func_800D6B0C(s32 original) {
    s32 func_8001211C(void);
    extern s16 D_8012BE64;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 frame : 27;
        u32 type : 4;
        u32 low : 1;
        void *image;
        u32 id : 14;
        u32 used : 1;
        u32 twice : 1;
        u32 tail : 16;
    };
#endif
    s32 index;

    index = func_800D6254(original);
    if (index != -1) {
        D_8012BE64 = original;
        if (((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->type == 2) {
            if (func_8001211C() ==
                ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->frame) {
                if (((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->used) {
                    ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->twice = 1;
                } else {
                    ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->used = 1;
                }
            } else {
                ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->used = 1;
            }
        }
        ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->frame = func_8001211C();
        return ((struct Entry *)(D_8012B800 + index * CACHE_ENTRY_SIZE))->image;
    }
    return 0;
}

/* extern */

s32 func_800D6C34(s32 arg0) {
    s32 func_800D6254(s32);
    if (func_800D6254(arg0) != -1) {
        return 1;
    }
    return 0;
}

void func_800D6C64(void) {
    extern s16 D_8012BE62;
    s32 func_800D6408(void *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 pad[2];
        u32 id : 14;
        u32 rest : 18;
    };
#endif
    struct Entry *ptr;
    s32 index;
    s32 id;
    int size = CACHE_ENTRY_SIZE;

    index = D_8012BE62 - 1;
    if (index >= 0) {
        do {
            ptr = (struct Entry *)(D_8012B800 + index * size);
            id = ptr->id;
            if (id < 0x1DDD || id >= 0x1ED8) {
                func_800D6408(ptr);
            }
            index--;
        } while (index >= 0);
    }
}

s32 func_800D6CEC(s32 arg0) {
    s32 func_800D6408(void *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u8 pad[10];
        u16 hi : 4;
        u16 rest : 12;
    };
#endif
    s32 index;
    int size = CACHE_ENTRY_SIZE;

    index = func_800D6254(arg0);
    if (index != -1) {
        if (((struct Entry *)(D_8012B800 + index * size))->hi != 0) {
            return 1;
        }
        return func_800D6408(D_8012B800 + index * size);
    }
    return 2;
}

void func_800D6D68(void) {
    s32 func_800D6550(void *);
    extern s16 D_8012BE60;
    extern s16 D_8012BE62;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 pad[2];
        u32 id : 14;
        u32 unused : 2;
        u32 hi : 4;
        u32 lo : 4;
        u32 rest : 8;
    };
#endif
    s32 i = 0;
    s32 count = 0;
    int size = CACHE_ENTRY_SIZE;
    struct Entry *entry;

    do {
        entry = (struct Entry *)(D_8012B800 + D_8012BE60 * size);
        if (entry->id != 0x3FFF && entry->lo == 0) {
            func_800D6550(entry);
            count++;
        }
        D_8012BE60++;
        i++;
        if (D_8012BE60 >= D_8012BE62) {
            D_8012BE60 = 0;
        }
    } while (i < 32 && count < 8);
}

void func_800D6E54(s32 arg0) {
    static s32 nextEntry = 0;
    s32 func_8001211C(void);
    s32 func_800A9F14(s32);
    s32 func_800A9F30(void);
    s32 func_800D6378(u8 *);
    extern s16 D_8012BE62;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u32 frame : 27;
        u32 type : 4;
        u32 low : 1;
        void *image;
        u16 id : 14;
        u16 unused : 2;
        u16 hi : 4;
        u16 rest : 12;
    };
#endif
    s32 i;
    s32 cutoff;
    struct Entry *entry;
    f32 limit;

    limit = (f32)D_8012BE62 * 0.007352941204f;
    if (0.85f < limit || func_800A9F30() == 0 || arg0 != 1) {
        i = func_8001211C();
        cutoff = i - func_800A9F14(arg0);
        if (arg0 == 1) {
            i = 8;
        } else {
            i = D_8012BE62 - 1;
        }
        for (; i >= 0; i--) {
            entry = (struct Entry *)(D_8012B800 + nextEntry * CACHE_ENTRY_SIZE);
            if (entry->type != 0 && entry->hi == 0 &&
                ((s32)entry->frame < cutoff ||
                 (arg0 == 3 && (entry->type == 1 || entry->type == 2 ||
                                entry->type == 6 || entry->type == 7 ||
                                entry->type == 5 || entry->type == 8)))) {
                func_800D6378((u8 *)entry);
                if (nextEntry > 0) {
                    nextEntry--;
                }
            }
            if (nextEntry >= D_8012BE62 - 1) {
                nextEntry = 0;
            } else {
                nextEntry++;
            }
        }
    }
}

uintptr_t func_800D7050(s32 arg0, s32 arg1) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u8 pad[10];
        u16 hi : 4;
        u16 rest : 12;
    };
#endif
    struct Entry *temp_v0;
    struct Entry *temp_v0_2;
    if (arg1 != 0) {
        temp_v0_2 = (struct Entry *)D_8012B800 + arg0;
        temp_v0_2->hi++;
        return (uintptr_t) temp_v0_2;
    }
    temp_v0 = (struct Entry *)D_8012B800 + arg0;
    temp_v0->hi--;
    return (uintptr_t) temp_v0;
}

void func_800D70D0(s32 arg0) {
    uintptr_t func_800D7050(s32, s32);
    extern s16 D_8011B910;
    func_800D7050(D_8011B910, arg0);
}

s32 func_800D70F8(s32 arg0, s32 arg1) {
    s32 func_800D6254(s32);
    uintptr_t func_800D7050(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D6254(arg0);
    if (temp_v0 != -1) {
        func_800D7050(temp_v0, arg1);
        return 1;
    }
    return 0;
}

u32 func_800D7138(s32 arg0) {
    s32 func_800D6254(s32);
    extern u8 D_8012B80A[];
    s32 temp_v0;

    temp_v0 = func_800D6254(arg0);
    if (temp_v0 != -1) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        return native_asset_cache[temp_v0].hi;
#else
        return (u32) *(u16 *) (D_8012B80A + (temp_v0 * 0xC)) >> 0xC;
#endif
    }
    return -1U;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
int native_asset_can_pin(s32 id) {
    s32 index = func_800D6254(id);
    return index == -1 || (native_asset_cache[index].hi < 15 && native_asset_cache[index].lo < 15);
}
#endif

uintptr_t func_800D7184(s32 arg0, s32 arg1) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct Entry {
        u8 pad[10];
        u8 hi : 4;
        u8 lo : 4;
        u8 tail;
    };
#endif
    struct Entry *temp_v0;
    struct Entry *temp_v0_2;
    if (arg1 != 0) {
        temp_v0_2 = (struct Entry *)D_8012B800 + arg0;
        temp_v0_2->lo++;
        return (uintptr_t) temp_v0_2;
    }
    temp_v0 = (struct Entry *)D_8012B800 + arg0;
    temp_v0->lo--;
    return (uintptr_t) temp_v0;
}

void func_800D71F4(s32 arg0) {
    uintptr_t func_800D7184(s32, s32);
    extern s16 D_8011B910;
    func_800D7184(D_8011B910, arg0);
}

s32 func_800D721C(s32 arg0, s32 arg1) {
    s32 func_800D6254(s32);
    uintptr_t func_800D7184(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D6254(arg0);
    if (temp_v0 != -1) {
        func_800D7184(temp_v0, arg1);
        return 1;
    }
    return 0;
}

void *func_800D725C(s32 arg0) {
    extern s16 D_8011B910;
    s32 func_8001211C(void);
    s32 func_800D5950(s32);
    s32 func_800D5EB4(s32, u8 *, s32);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    struct CacheEntry {
        u32 frame : 27;
        u32 type : 5;
        void *image;
        u32 info;
    };
#endif
    s32 index;
    s32 frame;
    struct CacheEntry *entry;

    index = func_800D6254(arg0);
    if (index == -1) {
        return func_800D674C(arg0);
    }
    D_8011B910 = index;
    frame = func_8001211C();
    entry = (struct CacheEntry *)D_8012B800 + index;
    entry->frame = frame;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (func_800D5EB4(arg0, (u8 *)entry->image, native_asset_cached_size(arg0))) {
#else
    if (func_800D5EB4(arg0, (u8 *)entry->image, func_800D5950(arg0))) {
#endif
        return entry->image;
    }
    return NULL;
}

s32 func_800D731C(s32 arg0) {
    s32 func_800D6254(s32);
    s32 index;
    s32 size = CACHE_ENTRY_SIZE;

    index = func_800D6254(arg0);
    if (index != -1 && CACHE_TYPE(D_8012B800 + index * size) == 2) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        return native_asset_cache[index].handle;
#else
        return D_8012B800[index * size + 11];
#endif
    }
    return 0;
}

s32 func_800D738C(BtIntPtr arg0) {
    return func_800D58FC(arg0);
}

s32 func_800D73AC(s32 arg0)
{
    s32 func_800D59C0(s32);
    return func_800D59C0(arg0);
}

/* extern */

s32 func_800D73CC(s32 arg0) {
    s32 func_800D6254(s32);
    s32 var_v1;

    if (func_800D6254(arg0) == -1) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#undef Entry
#undef ReleaseEntry
#undef CacheEntry
void _glsplineDll_entrypoint_0(void *);
void _glsplineDll_entrypoint_1(void *);
void _glsplineDll_entrypoint_2(u8 *);
/* Actor lifecycle and script-command execution are integrated separately. */
#endif

void * func_800D7400(void) {
    return &D_8012BE70;
}

void func_800D740C(void)
{

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BFFC;
#endif


    D_8012BFFC = 0;
}

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

/* extern */

s32 func_800D7488(s16 arg0, s16 arg1) {
    void *func_8001B710(s16, s32);
    s16 *sp1C;
    s32 temp_t7;
    s16 *temp_v0;

    ++SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)(&D_8012BE70) + (0x188))));
    sp1C = func_8001B710(SPLINE_FIELD(&D_8012BE70, handle0, (*(s16 *)((s8 *)(&D_8012BE70) + (0x184)))), SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)&D_8012BE70 + 0x188))) * 2);
    temp_v0 = func_8001B710(SPLINE_FIELD(&D_8012BE70, handle1, (*(s16 *)((s8 *)(&D_8012BE70) + (0x186)))), SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)(&D_8012BE70) + (0x188)))) * 2);
    sp1C[SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)&D_8012BE70 + 0x188))) - 1] = arg0;
    temp_v0[SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)&D_8012BE70 + 0x188))) - 1] = arg1;
    return SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)(&D_8012BE70) + (0x188)))) - 1;
}

void *func_800D7520(s32 arg0) { void *func_8001B798(s16);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF4;
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
 if (arg0 < 0 || arg0 >= native_spline_context.count) return NULL;
#endif
 if (arg0 == -1) { return NULL; } return func_8001B798(*(s16 *)((s8 *)func_8001B798(D_8012BFF4) + arg0 * 2)); }

u8 *func_800D7570(s32 arg0) {
    void *func_8001B798(s16);

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF6;
#endif

    typedef struct {
        s32 count;
        u8 data[1];
    } Entry;
    s16 *table;
    Entry *entry;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (arg0 < 0 || arg0 >= native_spline_context.count) return NULL;
#endif
    table = func_8001B798(D_8012BFF6);
    if (arg0 == -1) {
        return NULL;
    }
    entry = func_8001B798(table[arg0]);
    if (entry->count == 0) {
        return NULL;
    }
    return entry->data;
}

s32 func_800D75DC(s32 arg0, f32 arg1) {
    void *func_8001B798(s16);

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF6;
#endif

    typedef struct {
        f32 time;
        f32 data[4];
    } Point;
    typedef struct {
        s32 count;
        Point points[1];
    } Entry;
    s16 *table;
    Entry *entry;
    f32 *start;
    Point *point;
    f32 *end;
    s32 count;
    s32 result;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (arg0 < 0 || arg0 >= native_spline_context.count) return 0;
#endif
    table = func_8001B798(D_8012BFF6);
    if (arg0 == -1) {
        return 0;
    }
    entry = func_8001B798(table[arg0]);
    count = entry->count;
    start = &entry->points[0].time;
    if (count == 0) {
        return 0;
    }
    point = (Point *)start;
    end = (f32 *)(count * 0x14 + (u8 *)entry + 4);
    result = 0;
    while ((f32 *)point < end && (point->time < arg1 || (arg1 == 1.0f && 1.0f == point->time))) {
        point++;
        result++;
    }
    return result;
}

f32 func_800D7708(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800D7520(s32);
    f32 func_800C7AE4(u8 *, f32, f32);
    return func_800C7AE4(func_800D7520(arg0), arg1, 1.0f) / ((f32)arg2 / 4);
}

void func_800D7754(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 unused[0x24];

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused27:6; u32 target:3; u32 unused26:4; u32 player:1; u32 yaw:1; u32 pitch:1; u32 unused24:16;
        u32 actor:6; u32 unused28:26;
#else
u32 unused24:16;
        u32 pitch:1;
        u32 yaw:1;
        u32 player:1;
        u32 unused26:4;
        u32 target:3;
        u32 unused27:6;
        u32 unused28:26;
        u32 actor:6;
#endif
} PathState;
    void *func_80105494(Actor *);
    PathState *state;

    state = func_80105494(arg0);
    switch (arg1) {
        case 1:
            state->actor = 0;
            state->target = 0;
            state->player = 1;
            state->pitch = 1;
            state->yaw = 1;
            break;
        case 2:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->pitch = 0;
            break;
        case 3:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->pitch = 1;
            break;
        case 4:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->yaw = 0;
            break;
        case 5:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->yaw = 1;
            break;
        case 6:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->pitch = 0;
            state->yaw = 0;
            break;
        case 7:
            state->actor = 0;
            state->target = 0;
            state->player = 0;
            state->pitch = 1;
            state->yaw = 1;
            break;
    }
}

void func_800D7900(uintptr_t arg0)
{
}
void func_800D7908(void *arg0, f32 *arg1) { void func_800A516C(f32 *, f32 *, f32 *); f32 sp1C[3]; func_800A516C(sp1C, arg1, SPLINE_ACTOR(arg0, position, (f32 *)((u8 *)arg0 + 4))); SPLINE_ACTOR(arg0, unk54, *(f32 *)((u8 *)arg0 + 0x54)) = sp1C[1]; SPLINE_ACTOR(arg0, unk50, *(f32 *)((u8 *)arg0 + 0x50)) = sp1C[0]; }

void func_800D7948(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {
        u8 unused[0x44];
        f32 pitch, yaw, roll, idealPitch, idealYaw;
    } Object;
    typedef struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused1:1; s32 path:10; s32 unused0:21;
#else
s32 unused0:21;
        s32 path:10;
        u32 unused1:1;
#endif
f32 unused4[2];
        f32 time;
        f32 unused10;
        f32 speed;
        u32 unused18[3];

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused26:6; u32 target:3; u32 unused25:4; u32 player:1; u32 unused24:18;
        u32 actor:6; u32 unused28:26;
#else
u32 unused24:18;
        u32 player:1;
        u32 unused25:4;
        u32 target:3;
        u32 unused26:6;
        u32 unused28:26;
        u32 actor:6;
#endif
u32 unused2C;
        f32 speedStart;
        f32 speedEnd;
        f32 start;
        f32 end;

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused40:5; u32 pitchStart:9; u32 yawStart:9; u32 yawEnd:9;
        u32 unused44:20; u32 pitchEnd:9; u32 mode:2; u32 globalTime:1;
#else
u32 yawEnd:9;
        u32 yawStart:9;
        u32 pitchStart:9;
        u32 unused40:5;
        u32 globalTime:1;
        u32 mode:2;
        u32 pitchEnd:9;
        u32 unused44:20;
#endif
} PathState;
    #if defined(BT_NATIVE) && !defined(BT_ILP32)
    typedef NativeSplineTarget Target;
#else
    typedef struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 rest:30; u32 fixed:1; u32 unused:1;
#else
u32 unused:1;
        u32 fixed:1;
        u32 rest:30;
#endif
u32 unused4;
        s16 **actor;
    } Target;
#endif
    void *func_80105494(Actor *);
    void func_800C810C(void *, f32, f32 *, f32 *);
    void func_800D7908(void *, f32 *);
    void func_8008FE68(f32 *);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    Actor *func_80106790(Unk80132ED0 *);
#else
    void *func_80106790(s32);
#endif
    f32 func_800136E4(f32);
    f32 func_800F1DCC(f32, f32);

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BF70[];
#endif


#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern f32 D_8012C000;
#endif


#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 *D_8012C014;
#endif

    PathState *state;
    f32 position[3];
    f32 rotation[3];
    s32 i;
    f32 targetPosition[3];
    Target *target;
    Object *object;
    f32 playerPosition[3];
    f32 time;
    f32 fraction;

    object = arg0;
    state = func_80105494((Actor *)object);
    if (arg1 & 0x300) {
        func_800C810C(func_800D7520(state->path), state->time, position, rotation);
        if (arg1 & 1) {
            if (arg1 & 0x100) {
                SPLINE_ACTOR(object, unk54, object->idealYaw) = rotation[1];
            }
            if (arg1 & 0x200) {
                SPLINE_ACTOR(object, unk50, object->idealPitch) = rotation[0];
            }
        } else {
            if (arg1 & 0x100) {
                if (rotation[1] >= 180.0f) {
                    SPLINE_ACTOR(object, unk54, object->idealYaw) = rotation[1] - 180.0f;
                } else {
                    SPLINE_ACTOR(object, unk54, object->idealYaw) = rotation[1] + 180.0f;
                }
            }
            if (arg1 & 0x200) {
                SPLINE_ACTOR(object, unk50, object->idealPitch) = 360.0f - rotation[0];
            }
        }
    }
    if (state->target) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        target = D_8012C014 ? (Target *)D_8012C014 + state->target - 1 : NULL;
        if (target && (target->fixed || (target->marker && target->marker->unk0))) {
#else
        target = (Target *)D_8012C014 + state->target - 1;
#endif
        if (target->fixed) {
            for (i = 0; i != 3; i++) {
                targetPosition[i] = ((s16 *)target)[i + 1];
            }
        } else {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
            for (i = 0; i != 3; i++) {
                targetPosition[i] = ((NativeMarkerProp *)target->marker->unk0)->position[i];
            }
#else
            for (i = 0; i != 3; i++) {
                targetPosition[i] = (*target->actor)[i + 2];
            }
#endif
        }
        func_800D7908(object, targetPosition);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        }
#endif
    } else if (state->actor) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        Actor *targetActor = native_spline_actor(&native_spline_context, (Actor *)object, state->actor);
        if (targetActor) func_800D7908(object, targetActor->position);
#else
        func_800D7908(object, SPLINE_ACTOR(func_80106790(D_8012BF70[state->actor]), position, (f32 *)((u8 *)func_80106790(D_8012BF70[state->actor]) + 4)));
#endif
    } else if (state->player) {
        func_8008FE68(playerPosition);
        func_800D7908(object, playerPosition);
    } else {
        time = state->globalTime ? D_8012C000 : state->time;
        if (time >= state->start && time < state->end) {
            fraction = (time - state->start) / (state->end - state->start);
            if (state->mode & 1) {
                if (arg1 & 0x800) {
                    SPLINE_ACTOR(object, unk54, object->idealYaw) = func_800136E4(func_800F1DCC(state->yawEnd, state->yawStart) * fraction + state->yawStart);
                }
                if (arg1 & 0x1000) {
                    SPLINE_ACTOR(object, unk50, object->idealPitch) = func_800136E4(func_800F1DCC(state->pitchEnd, state->pitchStart) * fraction + state->pitchStart);
                }
            }
            if (state->mode & 2) {
                state->speed = (state->speedEnd - state->speedStart) * fraction + state->speedStart;
            }
        } else if (0.0f != state->start || 0.0f != state->end) {
            state->globalTime = 0;
            state->end = state->start = 0;
        }
    }
    func_800D7900((uintptr_t)object);
    SPLINE_ACTOR(object, rotation[1], object->yaw) = SPLINE_ACTOR(object, unk54, object->idealYaw);
    SPLINE_ACTOR(object, rotation[0], object->pitch) = SPLINE_ACTOR(object, unk50, object->idealPitch);
}

s32 func_800D7DE8(Actor *arg0) { typedef struct { u32 pad[9];
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 rest:14; u32 flag2:1; u32 flag:1; u32 unused:16;
#else
u32 unused:16; u32 flag:1; u32 flag2:1; u32 rest:14;
#endif
} State; void *func_80105494(Actor *); s32 var_a0; s32 var_v1; State *temp_v0; temp_v0 = func_80105494(arg0); if (temp_v0->flag) { var_a0 = 0x800; } else { var_a0 = 0x100; } var_v1 = temp_v0->flag2 ? 0x1000 : 0x200; return var_v1 + var_a0; }

s32 func_800D7E38(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    typedef struct { u32 data[4]; u32 flags; } Node;
    typedef struct { s32 count; Node nodes[1]; } NodeList;
    typedef struct { f32 unused0[3]; f32 time; f32 unused10[10]; f32 start; f32 end; } PathState;
    void *func_8001B798(s16);
    void *func_80105494(Actor *);
    s32 _glsplinenode_entrypoint_1(void *, void *, void *, NodeList *);
    extern s32 D_8011B920;

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF6;
#endif

    f32 unused[4];
    s32 result;
    f32 unusedTimeAfter;
    f32 previousTime;
    f32 unusedTimeBefore;
    s16 *handles;
    NodeList *list;
    s32 count;
    u32 endOffset;
    s32 step;
    s32 index;
    s32 last;
    PathState *state;
    u8 *node;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (arg1 < 0 || arg1 >= native_spline_context.count || (arg5 != 1 && arg5 != -1)) return 0;
#endif
    handles = func_8001B798(D_8012BFF6);
    result = 0;
    state = func_80105494(arg0);
    list = func_8001B798(handles[arg1]);
    count = list->count;
    if (count == 0) {
        return result;
    }
    if (arg2 == -9999) {
        index = count - 1;
    } else {
        index = arg2;
    }
    step = arg5 * 20;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    last = arg3 == -9999 ? count + arg4 : arg3;
    if (last < -1 || last > count) return 0;
    while (index != last && index >= 0 && index < count && result != 1) {
        node = (u8 *)&list->nodes[index];
#else
    node = index * sizeof(Node) + (u8 *)list + sizeof(list->count);
    index = arg3 == -9999 ? count + arg4 : arg3;
    endOffset = index * sizeof(Node);
    while (node != (u8 *)(index + list->nodes) && result != 1) {
#endif
        if ((step >= 20 && !(((Node *)node)->flags & 1)) || (step < 0 && (((Node *)node)->flags & 1) == 1)) {
            if (D_8011B920 == 1) {
                previousTime = state->time;
            }
            result = _glsplinenode_entrypoint_1(&D_8012BE70, arg0, node, list);
            if ((0.0f != state->start || 0.0f != state->end) &&
                (!(state->start <= state->time) || !(state->time < state->end))) {
                state->start = 0.0f;
                state->end = 0.0f;
            }
        }
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        index += arg5;
#else
        node += step;
#endif
    }
    if (D_8011B920 == 1 && result == 1) {
        state->time = 0.00001f + previousTime;
    }
    return result;
}

s32 func_800D8070(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 initialized:1; s32 path:10; s32 unused0:21;
#else
s32 unused0:21;
        s32 path:10;
        u32 initialized:1;
#endif
f32 unused4[2];
        f32 time;
        f32 previousTime;
        f32 speed;

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused19:30; u32 realTime:1; u32 unused18:1;
#else
u32 unused18:1;
        u32 realTime:1;
        u32 unused19:30;
#endif
u32 unused1C;
        f32 delay;

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused25:9; u32 pause:4; u32 unused24:19;
        u32 actor:6; u32 clearFlag:1; u32 flag:9; u32 unused29:2; u32 condition:8; u32 unused28:6;
#else
u32 unused24:19;
        u32 pause:4;
        u32 unused25:9;
        u32 unused28:6;
        u32 condition:8;
        u32 unused29:2;
        u32 flag:9;
        u32 clearFlag:1;
        u32 actor:6;
#endif
f32 pod;
    } PathState;
    s32 _capod_entrypoint_16(f32);
    f32 _glintrosyncDll_entrypoint_5(void);
    s32 _seqdefine_entrypoint_0(s32);
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    f32 func_800C7E28(void *);
    f32 func_800C8070(u8 *, f32, f32, s32 *);
    s32 func_800D75DC(s32, f32);
    s32 func_800D7DE8(Actor *);
    s32 func_800D7E38(void *, s32, s32, s32, s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void *func_80105494();
    extern u8 D_8012BE6F[];

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF4;
#endif


#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BFFC;
#endif

    s32 start;
    s32 end;
    s32 wrapped;
    PathState *state;
    f32 speed;
    u8 *path;
    s32 node;
    s32 oldFlags;
    s32 newFlags;
    f32 delta;
    f32 duration;

    wrapped = 0;
    state = func_80105494(arg0);
    speed = state->speed;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (state->path < 0 || state->path >= native_spline_context.count || state->condition > 128) return 0;
#endif
    if (state->path == -1) {
        return 0;
    }
    state->previousTime = state->time;
    start = func_800D75DC(state->path, state->time);
    if (0.0f == state->delay && state->pause == 0 && state->flag == 0 && state->condition == 0 && 0.0f == state->pod) {
        path = func_8001B798(((s16 *)func_8001B798(D_8012BFF4))[state->path]);
        state->time = func_800C8070(path, state->time, speed, &wrapped);
        func_800C7A68((struct Unk800C7A68 *)path, state->time, SPLINE_ACTOR(arg0, position, (f32 *)arg0 + 1));
    } else {
        if (0.0f != state->delay) {
            delta = state->realTime ? _glintrosyncDll_entrypoint_5() : func_800D8FF8();
            state->delay -= delta;
            if (state->delay < 0.0f) {
                state->delay = 0.0f;
            }
        }
        if (state->flag != 0 && func_800DA298(_seqdefine_entrypoint_0(state->flag - 1))) {
            if (state->clearFlag) {
                state->clearFlag = 0;
                func_800DA524(_seqdefine_entrypoint_0(state->flag - 1));
            }
            state->flag = 0;
        }
        if (state->condition != 0 && SPLINE_FIELD(&D_8012BE70, counters[state->condition - 1], D_8012BE6F[state->condition]) == 0) {
            state->condition = 0;
        }
        if (state->pod > 0.0f && _capod_entrypoint_16(state->pod)) {
            state->pod = 0.0f;
        }
    }
    end = func_800D75DC(state->path, state->time);
    if (!state->initialized) {
        state->initialized = 1;
        SPLINE_ACTOR(arg0, rotation[1], ((f32 *)arg0)[0x48 / 4]) = SPLINE_ACTOR(arg0, unk54, ((f32 *)arg0)[0x54 / 4]);
        SPLINE_ACTOR(arg0, rotation[0], ((f32 *)arg0)[0x44 / 4]) = SPLINE_ACTOR(arg0, unk50, ((f32 *)arg0)[0x50 / 4]);
    }
    if (start == end && wrapped == 0) {
        func_800D7948(arg0, arg1, arg2, arg3);
    } else {
        oldFlags = func_800D7DE8(arg0);
        if (speed > 0.0f) {
            if (wrapped == 0) {
                if (func_800D7E38(arg0, state->path, start, end, 0, 1) == 2) {
                    D_8012BFFC = 1;
                }
            } else if (func_800D7E38(arg0, state->path, start, -9999, 0, 1) == 0) {
                duration = func_800C7E28(func_800D7520(state->path));
                node = func_800D75DC(state->path, duration);
                func_800D7E38(arg0, state->path, node, end, 0, 1);
            }
        } else if (speed < 0.0f) {
            if (wrapped == 0) {
                func_800D7E38(arg0, state->path, start - 1, end - 1, 0, -1);
            } else if (func_800D7E38(arg0, state->path, start - 1, -1, 0, -1) == 0) {
                func_800D7E38(arg0, state->path, -9999, end - 1, 0, -1);
            }
        }
        newFlags = func_800D7DE8(arg0);
        if (oldFlags == newFlags || (oldFlags != newFlags && oldFlags != (arg1 & 0x3F00))) {
            func_800D7948(arg0, arg1, arg2, arg3);
        } else {
            func_800D7948(arg0, (arg1 & ~0x3F00) | (newFlags & 0x3F00), arg2, arg3);
        }
    }
    return 1;
}

s32 func_800D8588(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 _glsplinecs_entrypoint_1(void *, Actor *);
#endif
    void *func_80105494(Actor *);

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BE70;
#endif

s16 D_8011B910 = -1;
    u8 *state;
    s32 var_s1;
    s32 var_v1;

    var_s1 = 0;
    state = func_80105494(arg0);
    do {
        SPLINE_FIELD(&D_8012BE70, pad18C, (*(s32 *)((s8 *)(&D_8012BE70) + (0x18C)))) = 0;
        var_s1 += func_800D8070(arg0, arg1, arg2, arg3);
    } while (SPLINE_FIELD(&D_8012BE70, pad18C, (*(s32 *)((s8 *)(&D_8012BE70) + (0x18C)))) != 0);
    #if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (*(u32 *)state >> 24) {
#else
    if (*state != 0) {
#endif
        _glsplinecs_entrypoint_1(&D_8012BE70, arg0);
    }
    if (var_s1 != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800D8648(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8((f32 *)((u8 *)func_800D7520(arg0) + 0x14), arg1);
}

/* extern */

void func_800D8674(void) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    void *defrag(void *);
#else
    s32 defrag(s32);
#endif
    s32 i;

    if (SPLINE_FIELD(&D_8012BE70, cache, (*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4)))) != 0) {
        SPLINE_FIELD(&D_8012BE70, cache, (*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4)))) = defrag(SPLINE_FIELD(&D_8012BE70, cache, (*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4)))));
    }
    for (i = 0; i < SPLINE_FIELD(&D_8012BE70, count, (*(s32 *)((s8 *)(&D_8012BE70) + (0x188)))); i++) {
    }
    if (SPLINE_FIELD(&D_8012BE70, offsets, (*(s32 *)((s8 *)(&D_8012BE70) + (0x19C)))) != 0) {
        SPLINE_FIELD(&D_8012BE70, offsets, (*(s32 *)((s8 *)(&D_8012BE70) + (0x19C)))) = defrag(SPLINE_FIELD(&D_8012BE70, offsets, (*(s32 *)((s8 *)(&D_8012BE70) + (0x19C)))));
    }
}

void func_800D86F0(s32 arg0, f32 arg1, f32 *arg2) {
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s16 D_8012BFF4;
#endif

    func_800C7A68(func_8001B798(((s16 *)func_8001B798(D_8012BFF4))[arg0]), arg1, arg2);
}

void func_800D8744(void) {
    f32 _glintrosyncDll_entrypoint_5();
    f32 func_800D8FF8();

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern f32 D_8012C000;
#endif

    f32 var_f0;

    SPLINE_FIELD(&D_8012BE70, value1, (*(f32 *)((s8 *)(&D_8012BE70) + (0x194)))) = (f32) SPLINE_FIELD(&D_8012BE70, value0, (*(f32 *)((s8 *)(&D_8012BE70) + (0x190))));
    if (SPLINE_FIELD(&D_8012BE70, map, (*(u8 *)((s8 *)(&D_8012BE70) + (0x1A8)))) != 0) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    D_8012C000 = SPLINE_FIELD(&D_8012BE70, value0, (*(f32 *)((s8 *)(&D_8012BE70) + (0x190)))) + (var_f0 * 60.0f);
}

void func_800D87B0()
{
    _glsplineDll_entrypoint_2((u8 *)&D_8012BE70);
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800D87D4(Actor *arg0, s32 arg1) {
    native_spline_context.actors[arg1] = arg0->unk0;
#else
void func_800D87D4(s32 *arg0, s32 arg1) {

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BF70[];
#endif

    D_8012BF70[arg1] = *arg0;
#endif
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Unk80132ED0 *func_800D87EC(s32 arg0) {
    return native_spline_context.actors[arg0];
#else
s32 func_800D87EC(s32 arg0) {

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 D_8012BF70[];
#endif

    return ((s32 *)&D_8012BF70)[arg0];
#endif
}

void func_800D8800(void) {
}

void func_800D8808(s32 arg0) {

#if !defined(BT_NATIVE) || defined(BT_ILP32)
extern s32 *D_8012C014;
#endif


    if (arg0 != 0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        native_spline_context.cache[arg0 - 1].used = 0;
#else
        ((s8 *)D_8012C014)[arg0 * 12 - 12] &= 0xFF7F;
#endif
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_8012B80A [ 1622 ] BT_DATA(4, bss_core2bss1_2_status_tail, 0x3EA);
u8 D_8012BE6F [ 1 ] BT_DATA(4, bss_core2bss1_2_status_tail, 0xA4F);
#endif
