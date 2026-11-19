// Element types for asm data that the game reaches only through casts or other names, so no
// game declaration tells data.py the field widths (irtypes.py reads these declarations).
#include <ultra64.h>

// The source module owns its original 32-byte intro-character records.
#include "overlays/ch/intro/char_tables.h"

// gc/transitionDll.c: 0x14-byte transition records (kind, next, duration, model asset,
// animation, ...), stored as .byte; and {map, u8 enter, u8 leave} pairs stored as .short.
typedef struct { u8 kind, next, unk2, unk3; f32 duration; s32 asset, animation, unk10; } TransitionRow;
typedef struct { u16 map; u8 enter, leave; } TransitionMapRow;
extern TransitionRow D_80800CB0_gctransitionDll[], D_80800EA4_gctransitionDll[];
extern TransitionMapRow D_8080105C_gctransitionDll[];

void *bt_data_types[] = {D_80804790_chintrochar, D_80800CB0_gctransitionDll, D_80800EA4_gctransitionDll,
                         D_8080105C_gctransitionDll};
