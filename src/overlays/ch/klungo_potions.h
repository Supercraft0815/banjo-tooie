#ifndef CH_KLUNGO_POTIONS_H
#define CH_KLUNGO_POTIONS_H
#include "klungo_tables.h"

typedef struct {
    s16 cuePrefix[6];
    u8 highCommandByte;
    u8 orders[7][3];
    u8 padding[2];
    BT_NATIVE_ONLY(u8 nextCueHighByte;)
} KlungoPotionLayout;

extern KlungoPotionLayout D_80803CF4_chklungo;
#ifdef BT_NATIVE
extern s16 klungoPotionCue[8];
#define KLUNGO_POTION_CUE klungoPotionCue
/* The saved order occupies three bits. Index seven reads two padding bytes
 * and the high byte of the next cue. A missing map gives column minus one. */
#define KLUNGO_ORDER_BYTES ((u8 *)&D_80803CF4_chklungo + offsetof(KlungoPotionLayout, orders))
#else
#define KLUNGO_POTION_CUE ((s16 *)&D_80803CF4_chklungo)
#endif
#endif
