typedef struct {
    s16 state;
    s16 pad;
    f32 weights[4];
    f32 timers[4];
} MorphFrame;

struct MorphEntry {
    MorphFrame *frames;
    s16 id;
    u8 frameCount;
    u8 count;
    u8 flags;
    u8 padding[3];
};

extern struct MorphEntry D_80801320_suexpressmorph[17];

/* The IDO view preserves the original aliasing and load schedule. The native
 * view uses the typed fields and the host's pointer width. */
#define MORPH_RECORD(i) (((u8 (*)[sizeof(struct MorphEntry)])D_80801320_suexpressmorph)[i])
#define MORPH_FOR_WORK(work) MORPH_RECORD(((Objexpressmorph_arg1 *)(work))->unk2)
#define MORPH_FIELD(record, field) BT_DATA_FIELD(((struct MorphEntry *)(record))->field,     (record)[offsetof(struct MorphEntry, field)])
#ifdef BT_NATIVE
typedef MorphFrame *MorphFrameCursor;
#define MORPH_FRAMES(record) (((struct MorphEntry *)(record))->frames)
#define MORPH_STATE(row) ((row)->state)
#define MORPH_FRAME_STEP 1
#define MORPH_CHANNEL(record, row, offset, field)     (*(f32 *)((u8 *)((struct MorphEntry *)(record))->frames[row].field + (offset)))
#else
typedef s16 *MorphFrameCursor;
#define MORPH_FRAMES(record) (*(s16 **)(record))
#define MORPH_STATE(row) (*(row))
#define MORPH_FRAME_STEP (sizeof(MorphFrame) / sizeof(s16))
#define MORPH_CHANNEL(record, row, offset, field)     (*(f32 *)((BtIntPtr)(*(f32 (**)[9])(record))[row] + (offset) + offsetof(MorphFrame, field)))
#endif
