typedef struct {
    s16 id;
    s8 x;
    s8 y;
    union {
        struct { s16 scale; u16 flags; } parts;
        s32 word;
    } value;
    void *data;
} InfobarEntry;

typedef s32 (*InfobarDraw)(s32, void *, s32, s32);
typedef s32 (*InfobarValue)(u8 *, s32);

typedef struct {
    InfobarDraw draw;
    InfobarValue value;
    f32 scale;
} InfobarStyle;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define INFOBAR_FIXED_VALUE(entry) ((s32)(((entry).value.parts.flags & 0x7fff) ^ 0x4000) - 0x4000)
#else
#define INFOBAR_FIXED_VALUE(entry) ((s32)((u32)(entry).value.word << 17) >> 17)
#endif
