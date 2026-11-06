// Element types for asm data that the game reaches only through casts or other names, so no
// game declaration tells data.py the field widths (irtypes.py reads these declarations).
#include <ultra64.h>

// ch/intro/char.c: 32-byte rows, read as u16[16] and, via func_80804158/60/68/6C_chintrochar
// (code-relative linker symbols), as u32 and f32 fields.
typedef struct { u16 model, unk2, anim; s16 expression; u32 flags8, flagsC, flags10; u8 color[4]; f32 scale, shadow; } IntroCharRow;
extern IntroCharRow D_80804790_chintrochar[];

// gc/transitionDll.c: 0x14-byte transition records (kind, next, duration, model asset,
// animation, ...), stored as .byte; and {map, u8 enter, u8 leave} pairs stored as .short.
typedef struct { u8 kind, next, unk2, unk3; f32 duration; s32 asset, animation, unk10; } TransitionRow;
typedef struct { u16 map; u8 enter, leave; } TransitionMapRow;
extern TransitionRow D_80800CB0_gctransitionDll[], D_80800EA4_gctransitionDll[];
extern TransitionMapRow D_8080105C_gctransitionDll[];

void *bt_data_types[] = {D_80804790_chintrochar, D_80800CB0_gctransitionDll, D_80800EA4_gctransitionDll,
                         D_8080105C_gctransitionDll};
