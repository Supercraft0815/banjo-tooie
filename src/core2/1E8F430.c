#include "core2/1E8F430.h"
#include "core2/particle_draw_data.h"
#ifdef BT_NATIVE
#include "vector.h"
void func_800E7828(Gfx **, u8 *);
#endif

typedef struct {
    s16 x, y, z;
    BT_BITFIELD_ORDER(u8 font : 4, u8 unused : 1);
    BT_BITFIELD_ORDER(u8 fixed_width : 1, u8 jitter : 1);
    u8 highlight : 1;
    BT_BITFIELD_ORDER(u8 jitter : 1, u8 fixed_width : 1);
    BT_BITFIELD_ORDER(u8 unused : 1, u8 font : 4);
    u8 pad;
    f32 scale;
    u8 *text;
    u8 color[4];
} TextEntry;

typedef struct {
    BT_NATIVE_ONLY(Vector *) BT_IDO_ONLY(s32) vector;
    s32 font_ready;
    s32 gradient_end;
    u8 pending_color[4];
    u8 pending_highlight, pending_font, pending_fixed_width, pending_jitter;
    s16 pending_fade_y;
    f32 pending_scale;
    u8 command;
    u8 mode;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedWidth;
    s16 fadeY;
    u8 color[4];
    s16 parameter28;
    s16 parameter2A;
} TextCommandState;

BT_IDO_ONLY(extern) TextCommandState D_80128180;
#ifdef BT_ILP32
_Static_assert(sizeof(TextEntry) == 0x14 && sizeof(TextCommandState) == 0x2C, "text queue layout");
#endif


extern s32 D_801282B4;

#ifdef BT_NATIVE
void func_800B5B40(void) {
    void func_800B58D4(u8);
    for (s32 i = 1; i < 41; ++i) {
        func_800B58D4(D_80128150[i]);
        D_80128150[i] = 0;
    }
}

void func_800B5B88(void) {
    u8 func_800B5758(s32);
    for (s32 i = 1; i < 41; ++i) {
        D_80128150[i] = func_800B5758(particle_emitter_settings[i].capacity);
    }
}
#else
void func_800B5B40(void) { BT_NATIVE_ONLY(void func_800B58D4(u8);)
    extern s32 D_80128151;
    extern s32 D_80128179;
    u8 *var_s0;
    u8 *var_s1;

    var_s0 = (u8 *) &D_80128151; var_s1 = (u8 *) &D_80128179;
    do {
        func_800B58D4(*var_s0);
        var_s0 += 1;
        var_s0[-1] = 0;
    } while (var_s0 != var_s1);
}

void func_800B5B88(void) {
    s8 func_800B5758(s32);
    extern s32 D_8011A5C2;
    extern s32 D_80128151;
    extern s32 D_80128179;
    s8 *var_s0;
    s8 *var_s1;
    s8 *var_s2;
    s8 temp_v0;

    var_s0 = (s8 *) &D_80128151; var_s1 = (s8 *) &D_8011A5C2; var_s2 = (s8 *) &D_80128179;
    do {
        temp_v0 = func_800B5758((s32) (*(u8 *)(var_s1 + 1)));
        var_s0 += 1;
        var_s1 += 2;
        var_s0[-1] = temp_v0;
    } while (var_s0 != var_s2);
}

#endif

BtIntPtr func_800B5BE4(s32 arg0) {
    void *func_800B56D0(u8);
    extern u8 D_80128150[];
    return (BtIntPtr) func_800B56D0(D_80128150[arg0]);
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Obj1E8F430_func_800B5C10_sp18; /* offsets.py genstruct: fields from raw offsets on sp18; rename once understood */

/* extern */

u8 *func_800B5C10(s32 arg0, s32 arg1, s32 *arg2, BtIntPtr *arg3) {
    s32 func_800B0D58(s16 *arg0);
    void *func_800B0D60(void *arg0);
    void *func_800B0D6C(void *arg0, s32 arg1);
    s16 *func_800D3524(s32);
    s16 *sp1C;
    u8 *sp18;
    s16 *temp_v0;

    temp_v0 = func_800D3524(arg0);
    sp1C = temp_v0;
    sp18 = func_800B0D6C(temp_v0, arg1);
    *arg2 = func_800B0D58(sp1C);
    *arg3 = (((Obj1E8F430_func_800B5C10_sp18 *)sp18)->unk4) + (BtIntPtr) func_800B0D60(sp1C);
    return sp18;
}

void func_800B5C7C(s32 height) {
    extern u8 D_801281B0[];
    u8 *pixels;
    s32 row;
    s32 column;
    s32 offset;

    D_80128180.gradient_end = height - 1;
    row = 0;
    offset = 0;
    while (row < height) {
        pixels = offset + D_801281B0;
        for (column = 0; column < 32; column++) {
            pixels[column] = row * 255 / D_80128180.gradient_end;
        }
        row++;
        offset += 32;
    }
    osWritebackDCache(D_801281B0, height << 5);
}

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void) {
}

void func_800B5DFC(void) {
}

void func_800B5E04(void) {
    BT_IDO_ONLY(s32 vector_free(s32);)
    if (D_80128180.vector != 0) {
        vector_free(D_80128180.vector);
        D_80128180.vector = 0;
    }
}

void func_800B5E3C(void) {
    BT_IDO_ONLY(s32 vector_defrag(s32);)
    if (D_80128180.vector != 0) {
        D_80128180.vector = vector_defrag(D_80128180.vector);
    }
}

s32 func_800B5E74(u8 arg0) {
    s32 state;

    state = D_80128180.command;
    D_80128180.command = 0;
    switch (state) {
        case 2:
            D_80128180.color[0] = arg0;
            D_80128180.command = 3;
            break;
        case 3:
            D_80128180.color[1] = arg0;
            D_80128180.command = 4;
            break;
        case 4:
            D_80128180.color[2] = arg0;
            break;
        case 5:
            D_80128180.color[3] = arg0;
            break;
        case 6:
            D_80128180.parameter28 = arg0;
            D_80128180.command = 7;
            break;
        case 7:
            D_80128180.parameter28 |= arg0 << 8;
            D_80128180.command = 8;
            break;
        case 8:
            D_80128180.parameter2A = arg0;
            break;
        case 1:
            switch (arg0) {
                case 'l':
                    D_80128180.jitter = 0;
                    break;
                case 'h':
                    D_80128180.jitter = 1;
                    break;
                case 'j':
                    D_80128180.font = 2;
                    D_80128180.mode = 0;
                    break;
                case 'a':
                    D_80128180.command = 5;
                    break;
                case 'c':
                    D_80128180.command = 2;
                    break;
                case 'i':
                    D_80128180.command = 6;
                    break;
                case 'p':
                    break;
                default:
                    return 0;
            }
            break;
        default:
            switch (arg0) {
                case 0xFD:
                    D_80128180.command = 1;
                    break;
                case 0xFE:
                    D_80128180.mode = 1;
                    break;
                case 0xFF:
                    D_80128180.mode = 2;
                    break;
                default:
                    return 0x21;
            }
            break;
    }
    return 1;
}

s32 func_800B5FE4(u8 arg0, f32 *arg1, f32 *volatile arg2, f32 arg3) {
    s32 func_800B5E74(u8);
    int func_800D3574(s32);
    u8 func_800D35BC(s32);
    s32 func_800D35D0();
    s32 result;
    s32 var_v0;

    if (D_80128180.command == 0) {
        result = func_800D35D0(D_80128180.font, (s32)arg0);
        if (result != -1) {
            return result;
        }
        if ((s32)arg0 == 0x20) {
            if (D_80128180.fixedWidth != 0) {
                var_v0 = func_800D35BC(D_80128180.font);
            } else {
                var_v0 = func_800D3574(D_80128180.font);
            }
            *arg1 += (f32) var_v0 * arg3;
            return -1;
        }
    }
    if (func_800B5E74(arg0) != 0) {
        return -1;
    }
    return -1;
}

void func_800B60C0(Gfx **arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800AF5B0(void *, s32 *, s32 *);
    struct ImageStruct *func_800D674C(s32);
    f32 func_800DC178(f32, f32);
    void func_800E24F8(s32, s32, s32);
    void func_800E253C(f32);
    void func_800E2568(s32, s32);
    void func_800E257C(s32);
    void func_800E2E48(u8 *, u8 *, s32, s32 *);
    s32 func_800E7988(Gfx **, s32);
    void func_800E7A2C(Gfx **);
    f32 x;
    f32 y;
    s32 width;
    s32 height;
    s32 imageWidth;
    s32 imageHeight;
    void *image;
    s32 coords[2];

    image = func_800D674C(D_80128180.parameter28);
    func_800AF5B0(image, &imageWidth, &imageHeight);
    width = imageWidth / 4;
    height = imageHeight / 4;
    if (D_80128180.centered == 0) {
        *arg1 -= (f32)width * 0.5f * arg3;
        D_80128180.centered = 1;
    }
    x = *arg1;
    y = *arg2;
    if (D_80128180.jitter != 0) {
        x += func_800DC178(-1.0f, 1.0f) * arg3;
        y += func_800DC178(-1.0f, 1.0f) * arg3;
    }
    y -= (f32)height * 0.5f * arg3;
    coords[0] = x * 4.0f;
    coords[1] = y * 4.0f;
    func_800E257C(D_80128180.color[3]);
    func_800E24F8(D_80128180.color[0], D_80128180.color[1], D_80128180.color[2]);
    func_800E2568(imageWidth, imageHeight);
    func_800E253C(arg3);
    func_800E7988(arg0, 0x80000);
    func_800E2E48((u8 *)arg0, image, D_80128180.parameter2A - 1, coords);
    *arg1 += (f32)width * arg3;
    func_800E7A2C(arg0);
    func_800E7988(arg0, 0);
    D_80128180.parameter2A = 0;
    D_80128180.parameter28 = D_80128180.parameter2A;
}

void func_800B62CC(Gfx **arg0, u8 arg1, f32 *arg2, f32 *arg3, f32 arg4)
{
  BT_IDO_ONLY(extern s32 D_801281A4;)
  extern u8 D_801281B0[];
  void func_800B60C0(Gfx **, f32 *, f32 *, f32);
  u8 func_800D35BC(s32);
  s32 func_800D3724();
  f32 func_800DC178(f32, f32);
  void func_800E7694(void);
  BT_IDO_ONLY(s32 func_800E7828(Gfx **, s32 *);)
  u8 *glyph;
  s32 index;
  s32 format;
  BtIntPtr pixels;
  f32 x;
  f32 y;
  f32 originalY;
  f32 advance;
  Gfx *gfx;
  index = func_800B5FE4(arg1, arg2, arg3, arg4);
  if ((D_80128180.parameter28 != 0) && (D_80128180.parameter2A != 0))
  {
    func_800B60C0(arg0, arg2, arg3, arg4);
    D_80128180.font_ready = func_800D3724(D_80128180.font);
    return;
  }
  if (index >= 0)
  {
    func_800E7828(arg0, BT_DATA_FIELD(D_80128180.color, &D_801281A4));
    gfx = *arg0;
    glyph = func_800B5C10(D_80128180.font, index, &format, &pixels);
    if (D_80128180.fixedWidth)
    {
      advance = (s32) func_800D35BC(D_80128180.font);
    }
    else
    {
      advance = glyph[2];
    }
    if (!D_80128180.centered)
    {
      *arg2 -= (advance * 0.5f) * arg4;
      D_80128180.centered = 1;
    }
    x = *arg2;
    y = *arg3;
    if (D_80128180.jitter)
    {
      x += func_800DC178(-1.0f, 1.0f) * arg4;
      y += func_800DC178(-1.0f, 1.0f) * arg4;
    }
    originalY = y;
    x += ((advance - glyph[2]) * 0.5f) * arg4;
    y -= (glyph[1] * 0.5f) * arg4;
    if (format == 0x800)
    {
      {
        gDPSetTextureImage(gfx++, 0, G_IM_SIZ_32b, glyph[0], pixels + 0x80000000);
        gDPSetTile(gfx++, 0, G_IM_SIZ_32b, ((glyph[2] * G_IM_SIZ_32b_TILE_BYTES) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 2)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 0, G_IM_SIZ_32b, ((glyph[2] * G_IM_SIZ_32b_LINE_BYTES) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    else
      if (format == 0x200)
    {
      {
        gDPSetTextureImage(gfx++, 3, G_IM_SIZ_16b, glyph[0], pixels + 0x80000000);
        gDPSetTile(gfx++, 3, G_IM_SIZ_16b, ((glyph[2] * G_IM_SIZ_16b_TILE_BYTES) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 2)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 3, G_IM_SIZ_16b, ((glyph[2] * G_IM_SIZ_16b_LINE_BYTES) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    else
      if (format == 0x100)
    {
      {
        gDPSetTextureImage(gfx++, 3, G_IM_SIZ_8b, glyph[0], pixels + 0x80000000);
        gDPSetTile(gfx++, 3, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_TILE_BYTES) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 2)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 3, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_LINE_BYTES) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    else
      if (format == 0x40)
    {
      {
        gDPSetTextureImage(gfx++, 4, G_IM_SIZ_8b, glyph[0], pixels + 0x80000000);
        gDPSetTile(gfx++, 4, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_TILE_BYTES) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 2)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 4, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_LINE_BYTES) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    else
      if (format == 0x20)
    {
      {
        gDPSetTextureImage(gfx++, 4, G_IM_SIZ_8b, glyph[0] >> 1, pixels + 0x80000000);
        gDPSetTile(gfx++, 4, G_IM_SIZ_8b, ((glyph[2] >> 1) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 1)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 4, G_IM_SIZ_4b, ((glyph[2] >> 1) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    else
      if (format == 4)
    {
      {
        gDPSetTextureImage(gfx++, 2, G_IM_SIZ_8b, glyph[0], pixels + 0x80000000);
        gDPSetTile(gfx++, 2, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_TILE_BYTES) + 7) >> 3, 0, 7, 0, 0x2, 0, 0, 0x2, 0, 0);
        {
          Gfx *sync = gfx++;
          Gfx *tile;
          sync->words.w0 = (unsigned int) ((((unsigned int) 0xe6) & ((0x01 << 8) - 1)) << 24);
          tile = gfx++;
          sync->words.w1 = 0;
          tile->words.w0 = (unsigned int) ((((unsigned int) 0xf4) & ((0x01 << 8) - 1)) << 24);
          tile->words.w1 = (((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((glyph[2] - 1) << 2)) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((glyph[3] - 1) << 2)) & ((0x01 << 12) - 1)) << 0));
        }
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, 2, G_IM_SIZ_8b, ((glyph[2] * G_IM_SIZ_8b_LINE_BYTES) + 7) >> 3, 0, 0, 0, 0x2, 0, 0, 0x2, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, (glyph[2] - 1) << 2, (glyph[3] - 1) << 2);
      }
    }
    if (D_80128180.fadeY != (-0x7FFF))
    {
      s32 offset;
      s32 top;
      offset = (D_80128180.fadeY - originalY) - D_80128180.gradient_end;
      top = -offset;
      if (top < 0)
      {
        top = 0;
      }
      if (top > D_80128180.gradient_end)
      {
 top = D_80128180.gradient_end; } if (offset < 0) { offset = 0; } gDPSetTextureImage(gfx++, 4, G_IM_SIZ_8b, 32, D_801281B0 - 0x80000000); gDPSetTile(gfx++, 4, G_IM_SIZ_8b, ((glyph[2] + 1) + 7) >> 3, 0x100, 7, 0, 0x2, 0, 0, 0x2, 0, 0); gDPLoadSync(gfx++); gDPLoadTile(gfx++, 7, 0, top * 4, glyph[2] * 4, D_80128180.gradient_end * 4); gDPPipeSync(gfx++); gDPSetTile(gfx++, 4, G_IM_SIZ_8b, ((glyph[2] + 1) + 7) >> 3, 0x100, 1, 0, 0x2, 0, 0, 0x2, 0, 0); gDPSetTileSize(gfx++, 1, 0, (top + offset) * 4, glyph[2] * 4, (D_80128180.gradient_end + offset) * 4); } {
      Gfx *rect = gfx++;
      rect->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) |
          _SHIFTL(MAX((s16)((s32)(((glyph[2] * arg4) + x) * 4.0f)), 0), 12, 12) |
          _SHIFTL(MAX((s16)((s32)(((glyph[3] * arg4) + y) * 4.0f)), 0), 0, 12);
      rect->words.w1 = _SHIFTL(0, 24, 3) |
          _SHIFTL(MAX((s16)((int)(x * 4.0f)), 0), 12, 12) |
          _SHIFTL(MAX((s16)((int)(y * 4.0f)), 0), 0, 12);
      {
        Gfx *half = gfx;
        gfx++;
        half->words.w0 = _SHIFTL(G_RDPHALF_1, 24, 8);
        half->words.w1 = (unsigned int)(
            _SHIFTL(0 - (((s16)((int)(x * 4.0f)) < 0) ?
                (((s16)((s32)(1024.0f / arg4)) < 0) ?
                    MAX(((s16)((int)(x * 4.0f)) * (s16)((s32)(1024.0f / arg4))) >> 7, 0) :
                    MIN(((s16)((int)(x * 4.0f)) * (s16)((s32)(1024.0f / arg4))) >> 7, 0)) : 0), 16, 16) |
            _SHIFTL(0 - ((((int)(y * 4.0f)) < 0) ?
                (((s16)((s32)(1024.0f / arg4)) < 0) ?
                    MAX(((s16)((int)(y * 4.0f)) * (s16)((s32)(1024.0f / arg4))) >> 7, 0) :
                    MIN(((s16)((int)(y * 4.0f)) * (s16)((s32)(1024.0f / arg4))) >> 7, 0)) : 0), 0, 16));
      }
      {
        Gfx *last = gfx++;
        index = (u16)(s32)(1024.0f / arg4); last->words.w0 = _SHIFTL(G_RDPHALF_2, 24, 8); last->words.w1 = ((u32)index << 16) | index;
      }
    } *arg2 += advance * arg4; *arg0 = gfx; func_800E7694(); }
}

void func_800B7174(u8 *arg0) {
    struct Input { union { struct { s16 value; u16 rest; } halves; struct { BT_BITFIELD_ORDER(unsigned int pad : 16, unsigned int rest : 12); unsigned int nibble : 4; BT_BITFIELD_ORDER(unsigned int rest : 12, unsigned int pad : 16); } nib; struct { BT_BITFIELD_ORDER(unsigned int pad : 20, unsigned int rest : 9); BT_BITFIELD_ORDER(unsigned int flag11 : 1, unsigned int flag9 : 1); unsigned int pad2 : 1; BT_BITFIELD_ORDER(unsigned int flag9 : 1, unsigned int flag11 : 1); BT_BITFIELD_ORDER(unsigned int rest : 9, unsigned int pad : 20); } bits; } data; };

    BT_IDO_ONLY(extern s32 D_801281A4;)
    void func_800F2EBC(void *, void *);
    TextCommandState *out = &D_80128180;
    BT_IDO_ONLY(struct Input *in = (struct Input *)(arg0 + 4);)
    out->mode = 0;
    out->command = 0;
    out->centered = 0;
    out->font = BT_DATA_FIELD(((TextEntry *)arg0)->font, (u32)(u16)(in->data.halves.rest & 0xFFFF) >> 12);
    out->fadeY = BT_DATA_FIELD(((TextEntry *)arg0)->z, in->data.halves.value);
    out->fixedWidth = BT_DATA_FIELD(((TextEntry *)arg0)->fixed_width, in->data.bits.flag11);
    out->jitter = BT_DATA_FIELD(((TextEntry *)arg0)->jitter, in->data.bits.flag9);
    out->parameter2A = 0;
    out->parameter28 = out->parameter2A;
    func_800F2EBC(BT_DATA_FIELD(out->color, &D_801281A4), BT_DATA_FIELD(((TextEntry *)arg0)->color, arg0 + 0x10));
}

BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) func_800B71F4(Gfx **arg0, u8 *arg1) {
    s32 func_800B0D58(s16 *);
    void *func_800B0D60(void *);
    s16 *func_800D3524(s32);
    void func_800E76A4(Gfx **, s32);
    s32 func_800E7778(Gfx **, s32);
    BT_IDO_ONLY(s32 func_800E7828(Gfx **, s32 *);)
    void func_800E78C8(Gfx **, s32);
    void func_800E7928(Gfx **, s32);
    s16 *font;
    s32 flags;
    void *palette;

    func_800E78C8(arg0, BT_DATA_FIELD(((TextEntry *)arg1)->font, ((u32)*(u16 *)(arg1 + 6) >> 12)) == 1 ? 0x2000 : 0);
    if (BT_DATA_FIELD(((TextEntry *)arg1)->z, *(s16 *)(arg1 + 4)) != -0x7FFF) {
        func_800E7778(arg0, 0x100000);
        func_800E76A4(arg0, 1);
    } else {
        func_800E7778(arg0, 0);
        func_800E76A4(arg0, 0);
    }
    func_800E7828(arg0, BT_DATA_FIELD(((TextEntry *)arg1)->color, (s32 *)(arg1 + 0x10)));
    font = func_800D3524(BT_DATA_FIELD(((TextEntry *)arg1)->font, ((u32)*(u16 *)(arg1 + 6) >> 12)));
    flags = func_800B0D58(font);
    if (flags & 5) {
        palette = func_800B0D60(font);
        func_800E7928(arg0, 0x8000);
        if (flags & 1) {
            gDPLoadTLUT_pal16((*arg0)++, 0, palette);
        } else {
            gDPLoadTLUT_pal256((*arg0)++, palette);
        }
    } else {
        func_800E7928(arg0, 0);
    }
}

void func_800B7448(Gfx **arg0) {
    void func_800B62CC(Gfx **, u8, f32 *, f32 *, f32);
    void func_800B7174(u8 *);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) func_800B71F4(Gfx **, u8 *);
    void func_800B7A98(void);
    u8 func_800D35BC(s32);
    s32 func_800D3724(u32);
    s32 func_800E7188(u8 *);
    void func_800E7694(void);
    void func_800E76A4(Gfx **, s32);
    s32 func_800E7778(Gfx **, s32);
    BT_IDO_ONLY(s32 func_800E7828(Gfx **, s32 *);)
    s32 func_800E7988(Gfx **, s32);
    s32 func_800E79E8(Gfx **);
    s32 func_800E7A4C(Gfx **);
    BT_IDO_ONLY(BtUIntPtr vector_begin(s32);)
    BT_IDO_ONLY(s32 vector_clear(s32);)
    BT_IDO_ONLY(BtUIntPtr vector_end(s32);)
    BT_IDO_ONLY(s32 vector_size(s32);)
    extern u8 D_8011A620[16];
    struct FlagWord { BT_BITFIELD_ORDER(u32 upper : 16, u32 lower : 10); BT_BITFIELD_ORDER(u32 font : 4, u32 highlight : 1); u32 bit11 : 1; BT_BITFIELD_ORDER(u32 highlight : 1, u32 font : 4); BT_BITFIELD_ORDER(u32 lower : 10, u32 upper : 16); };
    s32 var_s0;
    f32 sp88;
    f32 sp84;
    TextEntry *first;
    s32 temp_s3;
    TextEntry *end;
    f32 temp_f14;
    f32 temp_f20;
    TextEntry *entry;

    if ((D_80128180.vector != 0) && (vector_size(D_80128180.vector) > 0)) {
        func_800E79E8(arg0);
        func_800E7988(arg0, 0);
        first = (TextEntry *)vector_begin(D_80128180.vector);
        end = (TextEntry *)vector_end(D_80128180.vector);
        entry = first;
        if (first < end) {
            do {
                D_80128180.font_ready = func_800D3724(BT_DATA_FIELD(entry->font, ((struct FlagWord *)((u8 *)entry + 4))->font));
                if (D_80128180.font_ready != 0) {
                    sp88 = (f32)entry->x;
                    sp84 = (f32)entry->y;
                    if (BT_DATA_FIELD(entry->highlight, ((struct FlagWord *)((u8 *)entry + 4))->highlight)) {
                        temp_s3 = func_800D35BC(BT_DATA_FIELD(entry->font, ((struct FlagWord *)((u8 *)entry + 4))->font));
                        temp_f20 = (f32) ((func_800E7188(entry->text) - 1) * temp_s3);
                        func_800E7828(arg0, BT_IDO_ONLY((s32 *)) D_8011A620);
                        func_800E7778(arg0, 0);
                        func_800E76A4(arg0, 2);
                        temp_f14 = (f32) (temp_s3 / 2);
                        gDPFillRectangle((*arg0)++,
                            sp88 - temp_f14 > 1.0f ? sp88 - temp_f14 - 1.0f : 0.0f,
                            sp84 - temp_f14 > 1.0f ? sp84 - temp_f14 - 1.0f : 0.0f,
                            sp88 + temp_f20 + temp_f14 > 0.0f ? sp88 + temp_f20 + temp_f14 : 0.0f,
                            temp_f14 + sp84 + 1.0f > 0.0f ? temp_f14 + sp84 + 1.0f : 0.0f);
                        func_800E7694();
                    }
                    func_800B71F4(arg0, (u8 *)entry);
                    func_800B7174((u8 *)entry);
                    for (var_s0 = 0; (entry->text[var_s0] != 0) || (D_80128180.mode != 0) || (D_80128180.command != 0); var_s0++) {
                        func_800B62CC(arg0, entry->text[var_s0], &sp88, &sp84, entry->scale);
                        if (D_80128180.font_ready == 0) {
                            break;
                        }
                    }
                }
                entry++;
            } while (entry < end);
        }
        func_800E7A4C(arg0);
        vector_clear(D_80128180.vector);
    }
    func_800B7A98();
}

void func_800B798C(s32 arg0, s32 arg1, u8 *arg2) {
    BT_IDO_ONLY(void * vector_new(u32 element_size, u32 count);)
    BT_IDO_ONLY(void *vector_push_back(void **);)
    TextEntry *entry;

    if (arg2 != 0) {
        if (D_80128180.vector == 0) {
            D_80128180.vector = vector_new(sizeof(TextEntry), 8);
        }
        entry = vector_push_back(BT_DATA_FIELD(&D_80128180.vector, (void **)&D_80128180));
        entry->x = arg0;
        entry->y = arg1;
        entry->text = arg2;
        entry->font = D_80128180.pending_font;
        entry->fixed_width = D_80128180.pending_fixed_width;
        entry->highlight = D_80128180.pending_highlight;
        entry->jitter = D_80128180.pending_jitter;
        entry->z = D_80128180.pending_fade_y;
        entry->scale = D_80128180.pending_scale;
        entry->color[0] = D_80128180.pending_color[0];
        entry->color[1] = D_80128180.pending_color[1];
        entry->color[2] = D_80128180.pending_color[2];
        entry->color[3] = D_80128180.pending_color[3];
    }
}

void func_800B7A98(void) {
    D_80128180.pending_color[0] = D_80128180.pending_color[1] = D_80128180.pending_color[2] = D_80128180.pending_color[3] = 0xFF;
    D_80128180.pending_jitter = 0;
    D_80128180.pending_highlight = D_80128180.pending_jitter;
    D_80128180.pending_fixed_width = D_80128180.pending_highlight;
    D_80128180.pending_font = 0;
    D_80128180.pending_fade_y = -0x7FFF;
    D_80128180.pending_scale = 1.0f;
}

void func_800B7ADC(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_8012818F;)
    BT_DATA_FIELD(D_80128180.pending_color[3], D_8012818F) = arg0;
}

void func_800B7AE8(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_80128190;)
    void func_800B7B68(s32);
    if (arg0 != 0) {
        BT_DATA_FIELD(D_80128180.pending_highlight, D_80128190) = 1;
    } else {
        BT_DATA_FIELD(D_80128180.pending_highlight, D_80128190) = 0;
    }
    if (arg0 != 0) {
        func_800B7B68(1);
    }
}

void func_800B7B2C(s32 arg0) {
    BT_IDO_ONLY(extern s16 D_80128194;)
    BT_DATA_FIELD(D_80128180.pending_fade_y, D_80128194) = arg0;
}

void func_800B7B38(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_80128191;)
    BT_DATA_FIELD(D_80128180.pending_font, D_80128191) = arg0;
}

void func_800B7B44(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_80128193;)
    if (arg0 != 0) {
        BT_DATA_FIELD(D_80128180.pending_jitter, D_80128193) = 1;
        return;
    }
    BT_DATA_FIELD(D_80128180.pending_jitter, D_80128193) = 0;
}

void func_800B7B68(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_80128192;)
    if (arg0 != 0) {
        BT_DATA_FIELD(D_80128180.pending_fixed_width, D_80128192) = 1;
        return;
    }
    BT_DATA_FIELD(D_80128180.pending_fixed_width, D_80128192) = 0;
}

void func_800B7B8C(s32 arg0, s32 arg1, s32 arg2) {
    D_80128180.pending_color[0] = arg0;
    D_80128180.pending_color[1] = arg1;
    D_80128180.pending_color[2] = arg2;
}

void func_800B7BA4(f32 arg0) {
    BT_IDO_ONLY(extern f32 D_80128198;)
    BT_DATA_FIELD(D_80128180.pending_scale, D_80128198) = arg0;
}

void func_800B7BB0(void) {
    s32 _fxleaves_entrypoint_1(s32);
    s32 _fxrain_entrypoint_1(s32);
    s32 func_800B956C();
    extern s32 D_80127128;
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_1(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_1(D_801282B4);
    }
    if (D_80127128 != 0) {
        func_800B956C();
    }
}

s32 func_800B7C10(void) {
    extern s32 D_801282B0;
    void *_fxleaves_entrypoint_4(s32 arg0);

    if (D_801282B0 == 0) {
        D_801282B0 = _fxleaves_entrypoint_4(0x32);
    }
    return D_801282B0;
}

BtIntPtr func_800B7C54(void) {
    extern s32 D_801282B4;
    u8 *_fxrain_entrypoint_5(s32 arg0);

    if (D_801282B4 == 0) {
        D_801282B4 = _fxrain_entrypoint_5(0x1E);
    }
    return D_801282B4;
}

s32 func_800B7C98()
{
    return D_801282B4;
}

void func_800B7CA4()
{
    func_800B9038();
}

void func_800B7CC4(void) {
    s32 _fxleaves_entrypoint_3(s32);
    s32 _fxrain_entrypoint_4(s32);
    s32 func_800B8FEC();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_3(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_4(D_801282B4);
    }
    func_800B8FEC();
}    typedef struct { s32 unk0; s32 unk4; } Obj1E8F430_D_801282B0; /* offsets.py genstruct: fields from raw offsets on &D_801282B0; rename once understood */

void func_800B7D14(void) {
    extern s32 D_801282B0;
    (((Obj1E8F430_D_801282B0 *)&D_801282B0)->unk0) = 0;
    (((Obj1E8F430_D_801282B0 *)&D_801282B0)->unk4) = 0;
}

void func_800B7D28(void) {
    void _fxleaves_entrypoint_5(BtIntPtr arg0);
    void _fxrain_entrypoint_7(BtIntPtr arg0);
    void func_800B90C8(void);
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_5(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_7(D_801282B4);
    }
    func_800B90C8();
}

void func_800B7D78(void) {
    s32 _fxleaves_entrypoint_6(BtIntPtr);
    s32 _fxrain_entrypoint_8(s32);
    s32 func_800B90E8();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_6(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_8(D_801282B4);
    }
    func_800B90E8();
}

void func_800B7DC8(void) {
    s32 _fxleaves_entrypoint_0(s32);
    s32 _fxleaves_entrypoint_6(BtIntPtr);
    s32 _fxrain_entrypoint_0(s32);
    s32 _fxrain_entrypoint_8(s32);
    s32 func_800B8FE0();
    s32 func_800B90E8();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_0(D_801282B0);
        _fxleaves_entrypoint_6(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_0(D_801282B4);
        _fxrain_entrypoint_8(D_801282B4);
    }
    func_800B8FE0();
    func_800B90E8();
}

void func_800B7E38(void) {
    s32 _fxleaves_entrypoint_7(s32);
    s32 _fxrain_entrypoint_9(s32);
    s32 func_800B9170();
    extern s32 D_80127128;
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_7(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_9(D_801282B4);
    }
    if (D_80127128 != 0) {
        func_800B9170();
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80127128 BT_DATA(4, bss_core2bss1_0_1, 0xC8);
u8 D_80128150[41] BT_DATA(4, bss_core2bss1_0_2, 0x9B0);
u8 D_801281B0 [ 256 ] BT_DATA(4, bss_core2bss1_0_2, 0xA10);
s32 D_801282B0 BT_DATA(4, bss_core2bss1_0_2, 0xB10);
s32 D_801282B4 BT_DATA(4, bss_core2bss1_0_2, 0xB14);
#endif
