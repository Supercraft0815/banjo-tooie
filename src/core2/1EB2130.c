#include "common.h"
#include "core2/1EB2130.h"
#include "movement_defaults.inc"
f32 func_800D8840(s32 arg0) {
    BT_IDO_ONLY(extern f32 D_8011B964[][2];)
    return BT_DATA_FIELD(playerMovementDefaults[arg0].value, D_8011B964[arg0][0]);
}

s32 func_800D8854(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_8011B961[];)
    return BT_DATA_FIELD(playerMovementDefaults[arg0].flags, D_8011B961[arg0 * 8]) & 1;
}

void func_800D8870(void) {
    BT_IDO_ONLY(void * freelist_new(s32 element_size, s32 capacity);)
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    D_8012C020 = freelist_new(0x70, 0);
}

void func_800D8898(void) {
    BT_IDO_ONLY(void freelist_free(void *list);)
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    freelist_free(D_8012C020);
    D_8012C020 = 0;
}

void func_800D88C0(void) {
    BT_IDO_ONLY(BtIntPtr freelist_defrag(BtIntPtr);)
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    if (D_8012C020 != 0) {
        D_8012C020 = freelist_defrag(D_8012C020);
    }
}

s16 func_800D88F8(void) {
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    BtIntPtr func_800D8988(s16, s32);
    s32 index;
    s32 i;
    index = 0;
    freelist_next(&D_8012C020, &index);
    for (i = 0; i != 4; i++) {
        *(s8 *)(func_800D8988((s16)index, i) + 0x1A) = 0;
    }
    return BT_IDO_ONLY(*(s16 *)((u8 *)&index + 2)) BT_NATIVE_ONLY((s16)index);
}

void func_800D8954(s16 arg0) {
    BT_IDO_ONLY(void freelist_erase(void *list, s32 index);)
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    freelist_erase(D_8012C020, arg0);
}

BtIntPtr func_800D8988(s16 arg0, s32 arg1) {
    BT_IDO_ONLY(s32 freelist_at(s32, s16);)
    extern BT_IDO_ONLY(s32) BT_NATIVE_ONLY(FreeList *) D_8012C020;
    return BT_NATIVE_ONLY((BtIntPtr)) freelist_at(D_8012C020, arg0) + (arg1 * 0x1C);
}

s32 func_800D89C8(s16 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, u8 *arg6, f32 *arg7, f32 *arg8) {
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void * func_80019CD4(void);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);

    f32 edge1[3];
    f32 edge2[3];
    s32 i;
    s32 j;
    f32 points[3][3];
    s16 *vertex;
    u8 *entry;

    entry = (u8 *)func_800D8988(arg0, arg1);
    if (!entry[0x1A]) {
        return 0;
    }
    entry[0x1A] = 0;
    if (func_800EEAD4(arg7, (f32 *)(entry + 8)) > 0.1f) {
        return 0;
    }
    for (i = 0; i != 3; i++) {
        vertex = (s16 *)(arg6 + *(s16 *)(entry + 0x14 + i * 2) * 0x10 + 0x18);
        for (j = 0; j != 3; j++) {
            points[i][j] = vertex[j];
        }
    }
    func_800EFB24(edge1, points[1], points[0]);
    func_800EFB24(edge2, points[2], points[0]);
    func_800EFA4C(arg8,
        points[0][0] + *(f32 *)entry * edge1[0] + *(f32 *)(entry + 4) * edge2[0],
        points[0][1] + *(f32 *)entry * edge1[1] + *(f32 *)(entry + 4) * edge2[1],
        points[0][2] + *(f32 *)entry * edge1[2] + *(f32 *)(entry + 4) * edge2[2]);
    func_80019CD4();
    func_80019750(arg2, arg3, arg4, arg5);
    func_80019224(arg8, arg8);
    return 1;
}

void func_800D8B80(s16 arg0, s32 arg1, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 *) arg2, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 *) arg3, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32) arg4, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 *) arg5, u16 *arg6, u8 *arg7, f32 *arg8)
{
  void func_80019224(f32 *, f32 *);
  BT_IDO_ONLY(s32 func_8001980C(s32, s32, s32, s32);) BT_NATIVE_ONLY(void func_8001980C(f32 *, f32 *, f32, f32 *);)
  void * func_80019CD4(void);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EE97C(f32 *, f32 *, f32 *);
  f32 func_800EEF94(f32 *);
  void func_800EFA4C(f32 *, f32, f32, f32);
  void func_800EFB24(void *, void *, void *);
  f32 mlAbsF(f32);




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
 func_800EE97C(normal, edge1, edge2); bound = 100000.0f; if ((((((normal[0] > bound) || (bound < normal[1])) || (bound < normal[2])) || (normal[0] < -100000.0f)) || (normal[1] < -100000.0f)) || (normal[2] < -100000.0f)) { normal[0] *= 0.00001f; normal[1] *= 0.00001f;
    normal[2] *= 0.00001f;
  }
  if (func_800EEF94(normal) < 0.001f)
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

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
FreeList *D_8012C020 BT_DATA(4, bss_core2bss1_2_status_tail, 0xC00);
u8 D_8012C030 BT_DATA(4, bss_core2bss1_2_status_tail, 0xC10);
#endif
