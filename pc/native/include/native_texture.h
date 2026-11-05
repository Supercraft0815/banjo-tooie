#ifndef BT_NATIVE_TEXTURE_H
#define BT_NATIVE_TEXTURE_H
#include "types.h"
typedef struct {u32 offset;u16 format;u8 width,height;} NativeTextureEntry;
typedef struct {u32 size;u16 count,flags;NativeTextureEntry entries[];} NativeModelTextures;
_Static_assert(sizeof(NativeTextureEntry)==8 && sizeof(NativeModelTextures)==8,"model texture metadata layout");
/* Validate raw big-endian metadata. Pixel/palette bytes always retain N64 byte order. */
int native_texture_validate(const void *,u32);
int native_texture_decode(void *,u32);
/* Input metadata was decoded by the model loader. Inline blocks return NULL.
 * External blocks become owned inline blocks with offsets instead of asset IDs. */
void *dbtex_entrypoint_0(void *);
void dbtex_entrypoint_1(void *);
#endif
