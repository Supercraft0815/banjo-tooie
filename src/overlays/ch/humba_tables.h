#include "core2/actor_animation_entry.h"

typedef union {
    struct {
        ActorAnimationEntry animations[21];
        s32 forms[9];
        s16 dialogs[9];
        s16 padding;
    } data;
    struct {
        u8 pad[164];
        s32 value[10];
    } forms;
    struct {
        u8 pad[202];
        s16 value[10];
    } dialogs;
} HumbaTables;

/* Humba numbers the nine huts starting at one. The zero entry overlaps
 * the preceding animation or form and therefore needs its N64 half order. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define HUMBA_FORM(table, i)                                                                       \
    ((i) ? (table).data.forms[(i) - 1]                                                             \
         : ((u32)(table).data.animations[20].index << 16) | (table).data.animations[20].flags)
#define HUMBA_DIALOG(table, i) ((i) ? (table).data.dialogs[(i) - 1] : (s16)(table).data.forms[8])
#else
#define HUMBA_FORM(table, i) ((table).forms.value[i])
#define HUMBA_DIALOG(table, i) ((table).dialogs.value[i])
#endif

extern HumbaTables D_808025A4_chhumba;
