typedef struct {
    u16 model;
    u16 unk2;
    u16 anim;
    s16 expression;
    u32 flags8, flagsC, flags10;
    u8 color[4];
    f32 scale, shadow;
} IntroCharRow;
extern IntroCharRow D_80804790_chintrochar[87];

/* Intro-character variants start at 0x32. */
#define INTRO_CHAR_ROW(index) (&D_80804790_chintrochar[(index) - 0x32])

#define INTRO_CHAR_RAW_ROW(index) (((u16 (*)[16])D_80804790_chintrochar)[(index)])
