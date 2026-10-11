#include "common.h"

f32 func_800D8840(s32 arg0) {
    extern f32 D_8011B964[][2];
    return D_8011B964[arg0][0];
}

s32 func_800D8854(s32 arg0) {
    extern u8 D_8011B961[];
    return D_8011B961[arg0 * 8] & 1;
}

void func_800D8870(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_8012C020;
    D_8012C020 = freelist_new(0x70, 0);
}

void func_800D8898(void) {
    s32 freelist_free(s32);
    extern s32 D_8012C020;
    freelist_free(D_8012C020);
    D_8012C020 = 0;
}

void func_800D88C0(void) {
    s32 freelist_defrag(s32);
    extern s32 D_8012C020;
    if (D_8012C020 != 0) {
        D_8012C020 = freelist_defrag(D_8012C020);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D88F8.s")

void func_800D8954(s16 arg0) {
    s32 freelist_erase(s32, s16);
    extern s32 D_8012C020;
    freelist_erase(D_8012C020, arg0);
}

s32 func_800D8988(s16 arg0, s32 arg1) {
    s32 freelist_at(s32, s16);
    extern s32 D_8012C020;
    return freelist_at(D_8012C020, arg0) + (arg1 * 0x1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2130/func_800D89C8.s")

void func_800D8B80(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u16 *arg6, u8 *arg7, f32 *arg8)
{
  void func_80019224(f32 *, f32 *);
  s32 func_8001980C(s32, s32, s32, s32);
  s32 func_80019CD4(void);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EE97C(f32 *, f32 *, f32 *);
  f32 func_800EEF94(f32 *);
  void func_800EFA4C(f32 *, f32, f32, f32);
  void func_800EFB24(void *, void *, void *);
  f32 mlAbsF(f32);
  extern const f32 D_80125CF4[1];
  extern const f32 D_80125CF8;
  extern const f32 D_80125CFC;
  extern const f32 D_80125D00;
  f32 edge1[3];
  f32 edge2[3];
  f32 point[3];
  f32 row1[3];
  f32 row2[3];
  s32 i;
  s32 j;
  register f32 bound;
  s32 axis;
  s32 component;
  f32 determinant;
  f32 normal[3];
  f32 vertices[3][3];
  struct VertexPosition
  {
    s16 position[3];
    u8 rest[10];
  };
  struct VertexBuffer
  {
    u8 prefix[24];
    struct VertexPosition vertices[1];
  };
  struct VertexPosition *vertex;
  u8 *result;
  f32 magnitude;
  result = (u8 *) func_800D8988(arg0, arg1);
  func_800EE7F8((f32 *) (result + 8), arg8);
  func_80019CD4();
  func_8001980C(arg2, arg3, arg4, arg5);
  func_80019224(point, arg8);
  for (i = 0; i < 3; i++)
  {
    ((u16 *) (result + 0x14))[i] = arg6[i];
  }

  for (i = 0; i < 3; i++)
  {
    vertex = ((s16 *) (result + 0x14))[i] + ((struct VertexBuffer *) arg7)->vertices;
    for (j = 0; j < 3; j++)
    {
      vertices[i][j] = vertex->position[j];
    }

  }

  func_800EFB24(edge1, vertices[1], vertices[0]);
  func_800EFB24(edge2, vertices[2], vertices[0]);
 func_800EE97C(normal, edge1, edge2); bound = D_80125CF4[0]; if ((((((normal[0] > bound) || (bound < normal[1])) || (bound < normal[2])) || (normal[0] < D_80125CF8)) || (normal[1] < D_80125CF8)) || (normal[2] < D_80125CF8)) { normal[0] *= D_80125CFC; normal[1] *= D_80125CFC;
    normal[2] *= D_80125CFC;
  }
  if (func_800EEF94(normal) < D_80125D00)
  {
    result[0x1A] = 0;
    return;
  }
  magnitude = mlAbsF(normal[0]);
  axis = (mlAbsF(normal[1]) < magnitude) ? (0) : (1);
  magnitude = mlAbsF(normal[2]);
  if (mlAbsF(normal[axis]) < magnitude)
  {
    axis = 2;
  }
  component = (axis + 1) % 3;
  func_800EFA4C(row1, point[component] - vertices[0][component], edge1[component], edge2[component]);
  component = (axis + 2) % 3;
  func_800EFA4C(row2, point[component] - vertices[0][component], edge1[component], edge2[component]);
  determinant = (row1[1] * row2[2]) - (row2[1] * row1[2]);
  ((f32 *) result)[0] = ((row1[0] * row2[2]) - (row2[0] * row1[2])) / determinant;
  ((f32 *) result)[1] = ((row1[1] * row2[0]) - (row2[1] * row1[0])) / determinant;
  result[0x1A] = 1;
}

void * func_800D8F40(void) {
    extern u8 D_8012C030;
    return &D_8012C030;
}
