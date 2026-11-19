#include "common.h"
#ifdef BT_NATIVE
#include "memory.h"
#include "vector.h"
#include "native_assets.h"
#if defined(BT_ILP32)
#include "bt_guest.h"
u32 BT_HOST(asset_override)(u32 id, void *dst, u32 capacity);
void BT_HOST(asset_dump)(u32 id, const void *src, u32 size);
#endif
static Vector *native_asset_refs[2];
#define ASSET_REFS native_asset_refs
void *D_8012B450[130];
u8 D_8012B658[130];
s16 D_8012B6E0[130];
s8 D_8012B7E4, D_8012B7E5, D_8012B7E6;
s32 D_8012B7E8;
static s32 native_asset_sizes[130];

s32 native_asset_cached_size(s32 id) {
    s32 i;
    for (i = 0; i < (u8)D_8012B7E4; ++i)
        if (D_8012B6E0[i] == id) return native_asset_sizes[i];
    return 0;
}
#else
#define ASSET_REFS ((void **)&D_8012B7F0)
#endif

typedef struct { s32 unk0; void *unk1; } AssetReference;

extern s32 D_8012B7E8;

void func_800D5440(void *ptr){
    extern s32 D_8012B7F0;
#ifndef BT_NATIVE
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
#endif
    s32 func_800D56C4(void *);

    AssetReference *start_ptr;
    AssetReference *end_ptr;
    AssetReference *iPtr;

    end_ptr = (AssetReference *) vector_end(ASSET_REFS[0]);
    start_ptr = (AssetReference *) vector_begin(ASSET_REFS[0]);

    for (iPtr = start_ptr; iPtr < end_ptr && ptr != iPtr->unk1; iPtr++);

    if (iPtr < end_ptr) {
        iPtr->unk0++;
    }
    else {
        iPtr = (AssetReference *) vector_push_back(&ASSET_REFS[0]);
        iPtr->unk0 = 1;
        iPtr->unk1 = ptr;
    }
}

int func_800D54F0(void *arg0) {
    extern s32 D_8012B7F0;
#ifndef BT_NATIVE
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
#endif
    s32 func_800D56C4(void *);

    AssetReference *start_ptr;
    AssetReference *end_ptr;
    AssetReference *iPtr;
    s32 j;

    for(j = 0; j < 2; j++){
        end_ptr = (AssetReference *) vector_end(ASSET_REFS[j]);
        start_ptr = (AssetReference *) vector_begin(ASSET_REFS[j]);
        for(iPtr = start_ptr; iPtr < end_ptr && arg0 != iPtr->unk1; iPtr++){
        }
        if (iPtr < end_ptr){
            return 1;
        }
    }
    return 0;
}

void func_800D55A0(void) {
#ifdef BT_NATIVE
    native_asset_refs[0] = vector_new(sizeof(AssetReference), 0x10);
    native_asset_refs[1] = vector_new(sizeof(AssetReference), 0x10);
#else
#ifndef BT_NATIVE
    s32 vector_new(s32, s32);
#endif
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    D_8012B7F0 = vector_new(8, 0x10);
    D_8012B7F4 = vector_new(8, 0x10);
#endif
}

void func_800D55DC(void){
    extern s32 D_8012B7F0;
#ifndef BT_NATIVE
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
#endif
    s32 func_800D56C4(void *);

    void *tmp_a0;
    AssetReference *iPtr;
    AssetReference *start_ptr;
    AssetReference *endPtr;
    int i;

    tmp_a0 = ASSET_REFS[0];
    ASSET_REFS[0] = ASSET_REFS[1];
    ASSET_REFS[1] = tmp_a0;

    endPtr = (AssetReference *) vector_end(ASSET_REFS[0]);
    start_ptr = (AssetReference *) vector_begin(ASSET_REFS[0]);
    for(iPtr = start_ptr; iPtr < endPtr; iPtr++){
        for(i = 0; i < iPtr->unk0; i++)
            func_800D56C4(iPtr->unk1);
    }

    vector_clear(ASSET_REFS[0]);
}

void func_800D5688(void) {
#ifdef BT_NATIVE
    native_asset_refs[0] = vector_defrag(native_asset_refs[0]);
    native_asset_refs[1] = vector_defrag(native_asset_refs[1]);
#else
#ifndef BT_NATIVE
    s32 vector_defrag(s32);
#endif
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    (*(s32 *)((s8 *)(&D_8012B7F0) + (0))) = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (0))));
    D_8012B7F4 = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (4))));
#endif
}

s32 func_800D56C4(void *arg0) {
    extern void *D_8012B450[];
    extern u8 D_8012B658[];
    extern s16 D_8012B6E0[];
    extern s8 D_8012B7E4;
    extern s8 D_8012B7E5;
    s32 i;
    s32 count;

    if (arg0) {
        for (i = 0; i < (u8) D_8012B7E4 && arg0 != D_8012B450[i]; i++);
        if (i == (u8) D_8012B7E4)
            return 2;
        D_8012B7E5 = i;
        count = D_8012B658[i];
        if (count == 1) {
            heap_free(arg0);
            count = (u8) ((u8) D_8012B7E4 - 1);
            D_8012B7E4 = count;
            D_8012B658[i] = D_8012B658[count];
            D_8012B450[i] = D_8012B450[(u8) D_8012B7E4];
            D_8012B6E0[i] = D_8012B6E0[(u8) D_8012B7E4];
#ifdef BT_NATIVE
            native_asset_sizes[i] = native_asset_sizes[count];
#endif
            return 0;
        } else {
            D_8012B658[i] = count - 1;
            return 1;
        }
    } else {
        return 3;
    }
}

void *func_800D5804(void *arg0, s32 arg1) {
    void *defrag(void *);
    extern void *D_8012B450[];
    extern s8 D_8012B7E4;
    s32 i;
    void *result;

    for (i = 0; i < (u8) D_8012B7E4 && arg0 != D_8012B450[i]; i++);
    if (i == (u8) D_8012B7E4) {
        return arg0;
    }
    result = defrag(arg0);
    if (result != arg0) {
        D_8012B450[i] = result;
    }
    return result;
}

void func_800D58AC()
{
    func_800D5688();
}

void func_800D58CC(void) {
#ifndef BT_NATIVE
    func_8001A2B0();
#endif
    func_800D55DC();
    func_800D55DC();
}

s32 func_800D58FC(BtIntPtr arg0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_flags(arg0) & 15;
#else
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    rom_read_word((s32)((u32 *)D_8011B900 + arg0), &D_8012B440);
    return D_8012B440 & 0xF;
#endif
}

s32 func_800D593C() 
{
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_count();
#else
    return 0x3666;
#endif
}

s32 func_800D5944()
{
    return D_8012B7E8;
}

s32 func_800D5950(s32 arg0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_packed_size(arg0);
#else
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    extern u32 D_8012B444;
    s32 temp_v0[2];
    register s32 offset;

    offset = arg0 * 4;
    rom_read_word(D_8011B900 + offset, (temp_v0[1] = offset, &D_8012B440));
    offset = temp_v0[1];
    rom_read_word(D_8011B900 + offset + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440 >> 6);
#endif
}

s32 func_800D59C0(s32 index) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return (native_asset_flags(index) >> 4) & 1;
#else
    typedef struct {
        BT_BITFIELD_ORDER(u32 reserved : 26, u32 flags : 4);
        u32 encoding : 2;
        BT_BITFIELD_ORDER(u32 flags : 4, u32 reserved : 26);
    } AssetEncoding;
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    s32 rom_read_word(s32, u32 *);
    rom_read_word((s32)((u32 *)D_8011B900 + index), &D_8012B440);
    return ((AssetEncoding *)&D_8012B440)->encoding & 1;
#endif
}

s32 func_800D5A04(s32 arg0) {
    extern s16 D_8012B6E0[];
    extern s8 D_8012B7E4;
    s32 var_v0;

    var_v0 = 0;
    while (var_v0 < (u8) D_8012B7E4 && arg0 != D_8012B6E0[var_v0]) {
        var_v0++;
    }
    if (var_v0 < (u8) D_8012B7E4) {
        return 1;
    }
    return 0;
}

s32 func_800D5A6C(s32 arg0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_rom_offset(arg0);
#else
    s32 rom_read_word(s32, u32 *); extern s32 D_8011B900; extern u32 D_8012B440; extern s32 D_8012B448; rom_read_word((s32)((u32 *)D_8011B900 + arg0), &D_8012B440); return D_8012B448 + ((u32) D_8012B440 >> 6);
#endif
}

s32 func_800D5AB4(s32 arg0) {
    extern s16 D_8012B6E0[];
    extern s8 D_8012B7E4;
    extern s8 D_8012B7E5;
    s32 var_v1;

    var_v1 = 0;
    while (var_v1 < (u8) D_8012B7E4 && arg0 != D_8012B6E0[var_v1]) {
        var_v1++;
    }
    D_8012B7E5 = var_v1;
    if (var_v1 == 0x82) {
        return -1;
    }
    return var_v1;
}

void func_800D5B24(void) {
    extern s8 D_8012B7E6;
    D_8012B7E6 = 1;
}

void *func_800D5B34(s32 arg0)
{
#if !defined(BT_NATIVE) || defined(BT_ILP32)
  s32 func_800E4AF0();
  s32 func_800E4BF4(s32);
  void *func_800E6950(s32, s32, void *);
  void *_gldbDll_entrypoint_0(s32, s32 *);
  void *heap_alloc(s32);
  void rom_dma_read(u8 *, u8 *, u32);
  s32 rom_read_word(s32, u32 *);
  extern s32 D_8011B900;
  extern u32 D_8012B440;
  extern u32 D_8012B444;
  extern s32 D_8012B448;
#endif
  extern void *D_8012B450[];
  extern u8 D_8012B658[];
  extern s16 D_8012B6E0[];
  extern s8 D_8012B7E4;
  extern s8 D_8012B7E5;
  extern s8 D_8012B7E6;
  register s32 size;
  register s32 index;
  register void *result;
  s32 mode;
  mode = (u8) D_8012B7E6;
  D_8012B7E6 = 0;
  index = func_800D5AB4(arg0);
  if (index < 0)
  {
    return NULL;
  }
  if (index < ((u8) D_8012B7E4))
  {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    if (D_8012B658[index] == 255) return NULL;
    D_8012B7E8 = native_asset_sizes[index];
#endif
    D_8012B658[index]++;
    return D_8012B450[index];
  }
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
  result = native_asset_load(arg0, &D_8012B7E8);
  if (!result) return NULL;
#else
#if defined(BT_NATIVE) && defined(BT_ILP32)
  {
    u32 replacement_size = host_asset_override((u32)arg0, NULL, 0);
    if (replacement_size) {
      if (replacement_size > 0x7FFFFFFFu) return NULL;
      result = heap_alloc((s32)replacement_size);
      if (!result || host_asset_override((u32)arg0, result, replacement_size) != replacement_size) {
        if (result) heap_free(result);
        return NULL;
      }
      D_8012B7E8 = (s32)replacement_size;
    } else {
#endif
  index = arg0 * 4;
  rom_read_word(D_8011B900 + index, &D_8012B440);
  if ((!(D_8012B440 & 0xF)) && (mode == 0))
  {
    mode = 2;
  }
  if (func_800E4AF0(arg0))
  {
    result = func_800E4BF4(arg0);
  }
  else
    if ((D_8012B440 & 0xF) == 0xA)
  {
    result = _gldbDll_entrypoint_0(arg0, &D_8012B7E8);
  }
  else
    if (((D_8012B440 << 26) >> 30) & 1)
  {
    result = func_800E6950(arg0, mode, NULL);
  }
  else
  {
    rom_read_word((D_8011B900 + index) + 4, &D_8012B444);
    rom_read_word(D_8011B900 + index, &D_8012B440);
    size = (D_8012B444 >> 6) - (D_8012B440 >> 6);
    D_8012B7E8 = size;
    if (size & 1)
    {
      size++;
    }
    result = heap_alloc(size);
    rom_dma_read(result, (u8 *) (D_8012B448 + (D_8012B440 >> 6)), size);
  }
#if defined(BT_NATIVE) && defined(BT_ILP32)
    }
  }
#endif
#endif
#if defined(BT_NATIVE) && defined(BT_ILP32)
  if (result && D_8012B7E8 > 0) {
    host_asset_dump((u32)arg0, result, (u32)D_8012B7E8);
  }
#endif
  D_8012B7E5 = (u8) D_8012B7E4;
  size = (u8) D_8012B7E4;
  D_8012B658[size] = 1;
  D_8012B450[size] = result;
  D_8012B6E0[size] = arg0;
#ifdef BT_NATIVE
  native_asset_sizes[size] = D_8012B7E8;
#endif
  D_8012B7E4 = ((u8) D_8012B7E4) + 1;
  return result;
}

void func_800D5D70(void) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    native_assets_shutdown();
    D_8012B7E6 = 0;
    func_800D55A0();
#else
    extern s32 D_8012B448;
    extern s8 D_8012B7E4;
    extern s8 D_8012B7E6;
    extern s32 assets_ROM_START;
    D_8012B7E6 = 0;
    func_800D55A0();
    D_8012B7E4 = 0;
    D_8012B448 = (s32)&assets_ROM_START + 0xD9A4; BT_NATIVE_ONLY({ extern s32 D_8011B900; D_8011B900 = (s32)&assets_ROM_START + 8 + bt_asset_shift(); D_8012B448 += bt_asset_shift(); })
    func_800E4CE8();
#endif
}

s32 func_800D5DB8(s32 arg0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_packed_size(arg0);
#else
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    extern u32 D_8012B444;
    s32 temp_v0[2];
    register s32 offset;

    offset = arg0 * 4;
    rom_read_word(D_8011B900 + offset, (temp_v0[1] = offset, &D_8012B440));
    offset = temp_v0[1];
    rom_read_word(D_8011B900 + offset + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440 >> 6);
#endif
}

void func_800D5E28(void **arg0) {
    func_800D5440(*arg0);
    *arg0 = 0;
}

void func_800D5E54(void *arg0)
{
    func_800D5440((void *)arg0);
}

void func_800D5E74(void) 
{
    func_800D55DC();
}

int func_800D5E94(void *arg0)
{
    return func_800D54F0((void *)arg0);
}

s32 func_800D5EB4(s32 arg0, u8 *arg1, s32 arg2) {
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    return native_asset_read_into(arg0, arg1, arg2);
#else
#if defined(BT_NATIVE) && defined(BT_ILP32)
    u32 replacement_size;
    if (arg2 < 0) return 0;
    replacement_size = host_asset_override((u32)arg0, NULL, 0);
    if (replacement_size) {
        if (replacement_size > (u32)arg2 || replacement_size > 0x7FFFFFFFu) return 0;
        if (host_asset_override((u32)arg0, arg1, replacement_size) != replacement_size) return 0;
        host_asset_dump((u32)arg0, arg1, replacement_size);
        return (s32)replacement_size;
    }
#endif
    void *func_800E6950(s32, s32, void *);
    void rom_dma_read(u8 *, u8 *, u32);
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    extern u32 D_8012B444;
    extern s32 D_8012B448;
    s32 var_a2;
    u32 temp_t3;
    s32 var_v1;

    if (func_800D5AB4(arg0) < 0) {
        return 0;
    }
    var_v1 = arg0 * 4;
    rom_read_word(D_8011B900 + var_v1, &D_8012B440);
    if (((u32) (D_8012B440 << 0x1A) >> 0x1E) & 1) {
        func_800E6950(arg0, 0, arg1);
        var_v1 = D_8012B7E8;
#if defined(BT_NATIVE) && defined(BT_ILP32)
        if (var_v1 > 0) host_asset_dump((u32)arg0, arg1, (u32)var_v1);
#endif
    } else {
    rom_read_word(D_8011B900 + var_v1 + 4, &D_8012B444);
    var_a2 = ((u32) D_8012B444 >> 6) - (temp_t3 = (u32) D_8012B440 >> 6);
    if (var_a2 & 1) {
        var_a2 += 1;
    }
    var_v1 = var_a2;
    if ((var_a2 & 0xF) != 0) {
        var_v1 = (var_a2 - (var_a2 & 0xF)) + 0x10;
    }
    if (arg2 >= var_a2) {
        rom_dma_read(arg1, D_8012B448 + temp_t3, var_a2);
#if defined(BT_NATIVE) && defined(BT_ILP32)
        host_asset_dump((u32)arg0, arg1, (u32)var_a2);
#endif
    } else {
        return 0;
    }
    }
    return var_v1;
#endif
}

void func_800D5FDC(s32 arg0) {
    *(s32 *)((u8 *)&D_8012B7E8 + 0) = arg0;
}

void *func_800D5FE8(s32 arg0) {
    extern void *D_8012B450[];
    extern s16 D_8012B6E0[];
    extern s8 D_8012B7E4;
    s32 var_v1;

    var_v1 = 0;
    while (var_v1 < (u8) D_8012B7E4 && arg0 != D_8012B6E0[var_v1]) {
        var_v1++;
    }
    if (var_v1 >= (u8) D_8012B7E4) {
        return 0;
    }
    return D_8012B450[var_v1];
}

#ifdef BT_NATIVE
void native_assets_shutdown(void) {
    s32 i;
    if (native_asset_refs[0]) {
        func_800D55DC();
        func_800D55DC();
        vector_free(native_asset_refs[0]);
        vector_free(native_asset_refs[1]);
        native_asset_refs[0] = native_asset_refs[1] = NULL;
    }
    for (i = 0; i < (u8)D_8012B7E4; ++i) heap_free(D_8012B450[i]);
    D_8012B7E4 = 0;
}
#endif

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B7F0 BT_DATA(4, bss_core2bss1_2_status_tail, 0x3D0);
#endif
