#include "common.h"
#include "core2/world_effect.h"

extern u8 D_80135480[3], D_80135483;

f32 func_80800000_idbounce(void) {
    s32 func_8008FD48();

    switch (func_8008FD48()) {
        case 0x11:
            return 0.1f;
        case 0xA:
            return 0.7f;
        case 0xB:
            return 0.4f;
        default:
            return 1.0f;
    }
}

void idbounce_entrypoint_0(s32 arg0, u8 *arg1, BtUIntPtr arg2, s32 arg3, u8 *arg4) {
    u32 func_800F54E4(void);
    void func_800F83E4(BtIntPtr, f32);
    extern s32 D_8013546C;
    extern u8 D_80135480[];
    f32 originY;
    f32 sp78;
    f32 sp74;
    f32 temp_f24;
    f32 sp6C;
    f32 sp68;
    f32 temp_f26;
    f32 sp60;
    f32 *temp_v0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f20;
    f32 var_f20_2;
    BtUIntPtr temp_s4;
    BtUIntPtr var_s1;
    s32 temp_v0_2;
    u8 *var_s3;

    temp_s4 = (arg3 * 0x10) + arg2;
    sp78 = *(f32 *)(arg4 + 4);
    var_s1 = arg2;
    sp74 = *(f32 *)(arg4 + 0xC);
    temp_f24 = *(f32 *)(arg4 + 0x20);
    var_s3 = arg1;
    sp6C = ((BounceEffect *)arg4)->unk40;
    sp68 = ((BounceEffect *)arg4)->unk44;
    temp_f26 = *(f32 *)(arg4 + 0x1C);
    if (arg2 < temp_s4) {
        do {
            var_f20 = 0.0f;
            if (D_80135480[1] != 0) {
                temp_f0 = (f32)*(s16 *)var_s1 - sp78;
                temp_f2 = (f32)*(s16 *)(var_s1 + 4) - sp74;
                temp_f0_2 = sqrtf(temp_f0 * temp_f0 + temp_f2 * temp_f2);
                temp_f2_2 = ((BounceEffect *)arg4)->unk34;
                sp60 = temp_f0_2;
                if (temp_f0_2 < temp_f2_2) {
                    var_f20 = 0.0f - temp_f24;
                } else if (temp_f0_2 < ((BounceEffect *)arg4)->unk38) {
                    var_f20 -= temp_f24 * (1.0f - ((temp_f0_2 - temp_f2_2) * ((BounceEffect *)arg4)->unk3C));
                }
            }
            temp_v0 = ((BounceEffect *)arg4)->cursor;
            temp_f0_3 = *temp_v0;
            var_f20 += (f32)(*(s16 *)(var_s3 + 2) - *(s16 *)(var_s1 + 2)) * sp6C - temp_f0_3 * sp68;
            *temp_v0 += var_f20 * temp_f26;
            *(s16 *)(var_s1 + 2) += *((BounceEffect *)arg4)->cursor * temp_f26;
            if (D_80135480[1] != 0) {
                temp_v0_2 = D_80135480[2];
                if (temp_v0_2 == 0 && sp60 < ((BounceEffect *)arg4)->unk34) {
                    temp_f0_4 = *((BounceEffect *)arg4)->cursor;
                    if (temp_f0_4 < 0.0f) {
                        temp_v0_2 *= 1;
                    }
                    var_f20_2 = temp_f0_4;
                    if (temp_v0_2 == 0) {
                        if (var_f20_2 > 2000.0f) {
                            var_f20_2 = 2000.0f;
                        }
                        func_800F83E4(func_800F54E4(), var_f20_2);
                        D_80135480[2] = 1;
                    }
                }
            }
            var_s1 += 0x10;
            var_s3 += 0x10;
            (((BounceEffect *)arg4)->cursor)++;
        } while (var_s1 < temp_s4);
    }
}

void idbounce_entrypoint_1(s32 arg0, u8 *arg1, BtUIntPtr arg2, s32 arg3, u8 *arg4)
{
  u32 func_800F54E4(void);
  void func_800F83E4(BtIntPtr, f32);
  f32 sqrtf(f32);
  extern s32 D_8013546C;
  f32 unused;
  f32 sp78;
  f32 sp74;
  f32 temp_f26;
  f32 sp6C;
  f32 sp68;
  f32 temp_f28;
  f32 sp60;
  f32 *temp_v0;
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f2;
  f32 temp_f2_2;
  f32 var_f20;
  f32 var_f20_2;
  s32 *new_var;
  BtUIntPtr temp_s5;
  BtUIntPtr var_s1;
  s32 temp_v0_2;
  BtUIntPtr temp_s2;
  u8 *var_s3;
  temp_s5 = (arg3 * 0x10) + arg2;
  sp78 = *((f32 *) (arg4 + 4));
  var_s1 = arg2;
  sp74 = *((f32 *) (arg4 + 0xC));
  temp_f26 = *((f32 *) (arg4 + 0x20));
  var_s3 = arg1;
  sp6C = ((BounceEffect *)arg4)->unk40;
  sp68 = ((BounceEffect *)arg4)->unk44;
  temp_f28 = *((f32 *) (arg4 + 0x1C));
  if (arg2 < temp_s5)
  {
    new_var = &D_8013546C;
    if (!sp60)
    {
    }
    temp_s2 = (BtUIntPtr) BT_DATA_FIELD(D_80135480, (((u8 *) new_var) + 0x14));
    do
    {
      var_f20 = 0.0f;
      if ((*((u8 *) (temp_s2 + 1))) != 0)
      {
        temp_f0 = ((f32) (*((s16 *) var_s1))) - sp78;
        temp_f2 = ((f32) (*((s16 *) (var_s1 + 4)))) - sp74;
        temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        temp_f2_2 = ((BounceEffect *)arg4)->unk34;
        sp60 = temp_f0_2;
        if (temp_f0_2 < temp_f2_2)
        {
          var_f20 = 0.0f - temp_f26;
        }
        else
          if (temp_f0_2 < (((BounceEffect *)arg4)->unk38))
        {
          var_f20 -= temp_f26 * (1.0f - ((temp_f0_2 - temp_f2_2) * (((BounceEffect *)arg4)->unk3C)));
        }
      }
      temp_v0 = ((BounceEffect *)arg4)->cursor;
      temp_f0_3 = *temp_v0;
      var_f20 += (((f32) ((*((s16 *) (var_s3 + 2))) - (*((s16 *) (var_s1 + 2))))) * sp6C) - (temp_f0_3 * sp68);
      *temp_v0 += var_f20 * temp_f28;
      *((s16 *) (var_s1 + 2)) = (s32) (((*(((BounceEffect *)arg4)->cursor)) * temp_f28) + ((f32) (*((s16 *) (var_s1 + 2)))));
      if ((*((u8 *) (temp_s2 + 1))) != 0)
      {
        temp_v0_2 = *((u8 *) (temp_s2 + 2));
        if ((temp_v0_2 == 0) && (sp60 < (((BounceEffect *)arg4)->unk34)))
        {
          if ((*(((BounceEffect *)arg4)->cursor)) < 0.0f)
          {
            temp_v0_2 = temp_v0_2 * 1;
          }
          var_f20_2 = (*(((BounceEffect *)arg4)->cursor)) / (((BounceEffect *)arg4)->unk50);
          if (temp_v0_2 == 0)
          {
            if (var_f20_2 > 2000.0f)
            {
              var_f20_2 = 2000.0f;
            }
            func_800F83E4(func_800F54E4(), var_f20_2);
            *((u8 *) (temp_s2 + 2)) = 1;
          }
        }
      }
      var_s3 += 0x10;
      if ((*((s16 *) (var_s1 + 2))) < 0)
      {
        *((s16 *) (var_s1 + 2)) = 0;
      }
      var_s1 += 0x10;
      (((BounceEffect *)arg4)->cursor)++;
    }
    while (var_s1 < temp_s5);
  }
  if (!sp60)
  {
  }
}                    

void idbounce_entrypoint_2(u8 *arg0, BtUIntPtr arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u32 func_800F54E4(void);
    void func_800F83E4(BtIntPtr, f32);
    extern s32 D_8013546C;
    f32 temp_f30;
    f32 originY;
    f32 sp74;
    f32 temp_f24;
    f32 sp6C;
    f32 sp68;
    f32 *temp_v0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f12;
    f32 var_f20;
    f32 var_f20_2;
    s32 temp_s5;
    BtUIntPtr temp_s6;
    BtUIntPtr var_s1;
    s32 temp_v0_2;
    BtUIntPtr temp_s3;
    u8 *var_s2;
    u8 *var_s4;

    temp_f30 = (*(f32 *)((s8 *)(arg4) + (4)));
    originY = (*(f32 *)((s8 *)(arg4) + (8)));
    sp74 = (*(f32 *)((s8 *)(arg4) + (0xC)));
    temp_f24 = (*(f32 *)((s8 *)(arg4) + (0x20)));
    sp6C = (((BounceEffect *)arg4)->unk40);
    var_s1 = arg1;
    sp68 = (((BounceEffect *)arg4)->unk44);
    var_s2 = arg2;
    var_s4 = arg0;
    temp_s5 = (*(u8 *)((s8 *)(arg4) + (0))) == 2;
    temp_s6 = (arg3 * 0x10) + arg1;
    temp_f26 = (*(f32 *)((s8 *)(arg4) + (0x1C)));
    temp_s3 = (BtUIntPtr)BT_DATA_FIELD(D_80135480, ((u8 *)&D_8013546C + 0x14));
    while (var_s1 < temp_s6) {
            var_f12 = (((BounceEffect *)arg4)->unk38);
            var_f20 = 0.0f;
            if (*(u8 *)(temp_s3 + 1) != 0) {
                temp_f0 = (f32) (*(s16 *)((s8 *)(var_s2) + (0))) - temp_f30;
                temp_f2 = (f32) (*(s16 *)((s8 *)(var_s2) + (4))) - sp74;
                temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
                temp_f2_2 = (((BounceEffect *)arg4)->unk34);
                var_f12 = temp_f0_2;
                if (temp_f0_2 < temp_f2_2) {
                    var_f20 = 0.0f - temp_f24;
                } else if (temp_f0_2 < (((BounceEffect *)arg4)->unk38)) {
                    var_f20 -= temp_f24 * (1.0f - ((temp_f0_2 - temp_f2_2) * (((BounceEffect *)arg4)->unk3C)));
                }
            }
            temp_v0 = (((BounceEffect *)arg4)->cursor);
            temp_f0_3 = *temp_v0;
            var_f20 += ((f32) ((*(s16 *)((s8 *)(var_s4) + (2))) - (*(s16 *)((s8 *)(var_s2) + (2)))) * sp6C) - (temp_f0_3 * sp68);
            *temp_v0 += var_f20 * temp_f26;
            (*(s16 *)((s8 *)(var_s1) + (2))) = (s16) (s32) ((*(((BounceEffect *)arg4)->cursor) * temp_f26) + (f32) (*(s16 *)((s8 *)(var_s2) + (2))));
            if (*(u8 *)(temp_s3 + 1) != 0) {
                temp_v0_2 = *(u8 *)(temp_s3 + 2);
                if ((temp_v0_2 == 0) && (var_f12 < (((BounceEffect *)arg4)->unk34))) {
                    temp_f0_4 = *(((BounceEffect *)arg4)->cursor);
                    if (temp_f0_4 < 0.0f) {
                        var_f20_2 = temp_f0_4 / (((BounceEffect *)arg4)->unk50);
                    } else {
                        temp_f2_3 = (((BounceEffect *)arg4)->unk50);
                        if (temp_f0_4 < (10.0f * temp_f2_3)) {
                            var_f20_2 = -1.0f;
                        } else if ((((BounceEffect *)arg4)->unk48) < temp_f0_4) {
                            temp_f0_4 *= (((BounceEffect *)arg4)->unk4C);
                            var_f20_2 = temp_f0_4;
                        } else {
                            var_f20_2 = temp_f0_4 / temp_f2_3;
                        }
                    }
                    if (temp_v0_2 == 0) {
                        if (var_f20_2 > 2000.0f) {
                            var_f20_2 = 2000.0f;
                        }
                        func_800F83E4(func_800F54E4(), var_f20_2);
                        *(u8 *)(temp_s3 + 2) = 1U;
                    }
                }
            }
            var_s4 += 0x10;
            if ((temp_s5 != 0) && ((*(s16 *)((s8 *)(var_s1) + (2))) < 0)) {
                (*(s16 *)((s8 *)(var_s1) + (2))) = 0;
            }
            var_s1 += 0x10;
            var_s2 += 0x10;
            (((BounceEffect *)arg4)->cursor) = (f32 *) ((((BounceEffect *)arg4)->cursor) + 1);
    }
}

s32 *func_80800874_idbounce(s32 arg0) {
    extern s32 D_80800E50_idbounce[];
    s32 *var_v1 = D_80800E50_idbounce;
    while (-1 != *var_v1) {
        if (arg0 == *var_v1) {
            break;
        }
        var_v1 += 8;
    }
    return var_v1;
}

/* extern */

int func_808008B4_idbounce(void) {
    u32 func_800F54E4(void);
    s32 func_800F55FC(BtIntPtr);
    s32 func_800F6C5C(BtIntPtr);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6C5C(temp_v0) == 0) {
        return 0;
    }
    if (!(func_800F55FC(sp1C) & 0x8000)) {
        return 0;
    }
    return 1;
}

void idbounce_entrypoint_3(void *arg0) {
    void heap_free(void *);
    extern u8 D_80135480[];
    u8 *state;

    heap_free(((BounceEffect *)arg0)->begin);
    state = D_80135480;
    BT_NATIVE_ONLY(D_80135483--;) BT_IDO_ONLY(state[3]--;)
}

void idbounce_entrypoint_4(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 *func_80800874_idbounce(s32 arg0);
    s16 _glidmake_entrypoint_3(s32 *arg0, s32 arg1);
    void *heap_alloc(s32);
    BtIntPtr func_80106314(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EA05C(void);
    extern u8 D_80135480[];
    f32 *sp2C;
    s32 sp28;
    Actor *sp24;
    Actor *temp_v0;
    s32 map;
    u8 *counter;

    sp2C = func_80800874_idbounce(arg1);
    sp28 = _glidmake_entrypoint_3(arg2, arg3);
    ((BounceEffect *)arg0)->begin = heap_alloc(sp28 * 4);
    ((BounceEffect *)arg0)->end = ((BounceEffect *)arg0)->begin + sp28;
    ((BounceEffect *)arg0)->cursor = ((BounceEffect *)arg0)->begin;
    while (((BounceEffect *)arg0)->cursor < ((BounceEffect *)arg0)->end) {
        *((BounceEffect *)arg0)->cursor = 0.0f;
        (((BounceEffect *)arg0)->cursor)++;
    }
    ((BounceEffect *)arg0)->unk20 = 0.0f;
    ((BounceEffect *)arg0)->unk30 = -sp2C[1] / -2700.0f;
    ((BounceEffect *)arg0)->unk34 = sp2C[2];
    ((BounceEffect *)arg0)->unk38 = sp2C[3];
    ((BounceEffect *)arg0)->unk40 = sp2C[4];
    ((BounceEffect *)arg0)->unk44 = sp2C[5];
    ((BounceEffect *)arg0)->unk48 = sp2C[6];
    ((BounceEffect *)arg0)->unk4C = sp2C[7];
    if (arg4 == 4) {
        temp_v0 = func_80106790(func_80106314());
        sp24 = temp_v0;
        ((BounceEffect *)arg0)->unk50 = 1.0f / temp_v0->scale;
        func_800EE7F8(&((BounceEffect *)arg0)->unk54, temp_v0->position);
        switch (sp24->unk6C_9) {
            case 0x34C:
                *(s8 *)arg0 = 2;
                break;
            case 0x47E:
            case 0x4C4:
            case 0x4C5:
            case 0x4C6:
            case 0x4C7:
            case 0x50B:
            case 0x50C:
            case 0x531:
                *(s8 *)arg0 = 3;
                break;
            default:
                *(s8 *)arg0 = 1;
                break;
        }
    } else {
        ((BounceEffect *)arg0)->unk5C = 0.0f;
        ((BounceEffect *)arg0)->unk58 = 0.0f;
        ((BounceEffect *)arg0)->unk54 = 0.0f;
        map = func_800EA05C();
        if (map != 0xE2 && map != 0xE4 && map != 0xE5 && map != 0xF8 && map != 0x138) {
            ((BounceEffect *)arg0)->unk50 = 0.0f;
            *(s8 *)arg0 = 0;
        } else {
            *(s8 *)arg0 = 3;
            ((BounceEffect *)arg0)->unk50 = 1.0f;
        }
    }
    if (((BounceEffect *)arg0)->unk50) {
        ((BounceEffect *)arg0)->unk30 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk34 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk38 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk40 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk44 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk48 *= ((BounceEffect *)arg0)->unk50;
        ((BounceEffect *)arg0)->unk4C /= ((BounceEffect *)arg0)->unk50;
    }
    counter = D_80135480;
    ((BounceEffect *)arg0)->unk3C = 1.0f / (sp2C[3] - sp2C[2]);
    BT_NATIVE_ONLY(D_80135483++;) BT_IDO_ONLY(counter[3]++;)
}

void idbounce_entrypoint_5(void *arg0, void *arg1, s32 arg2) {
    f32 func_800D8FF8(void);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5D70(BtIntPtr, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    BT_IDO_ONLY(void _glid_entrypoint_1(u8 *arg0, s32 arg1, s32 (*arg2)(u8 *, u8 *, u8 *, s16, s32), BtIntPtr arg3);) BT_NATIVE_ONLY(void _glid_entrypoint_1(u8 *, s32, void (*)(u8 *, BtUIntPtr, u8 *, s32, u8 *), BtIntPtr);)
#ifndef BT_NATIVE
    extern s32 _idbounce_entrypoint_0;
#endif
#ifndef BT_NATIVE
    extern s32 _idbounce_entrypoint_1;
#endif
#ifndef BT_NATIVE
    extern s32 _idbounce_entrypoint_2;
#endif
    extern s32 D_8013546C;
    f32 sp34[3];

    ((BounceEffect *)arg0)->unk1C = func_800D8FF8();
    func_800F5A00(func_800F54E4(), &((BounceEffect *)arg0)->unk4);
    func_800EF3DC(&((BounceEffect *)arg0)->unk4, &((BounceEffect *)arg0)->unk54);
    if (((BounceEffect *)arg0)->unk50 != 0.0f) {
        func_800EF334(&((BounceEffect *)arg0)->unk4, ((BounceEffect *)arg0)->unk50);
    }
    ((BounceEffect *)arg0)->unk20 =
        -((BounceEffect *)arg0)->unk30 * func_80800000_idbounce() * -2700.0f;
    if (*BT_DATA_FIELD(D_80135480, ((u8 *)&D_8013546C + 0x14)) != 0) {
        func_800F5D70(func_800F54E4(), sp34);
        ((BounceEffect *)arg0)->unk20 -=
            (((BounceEffect *)arg0)->unk30 * func_80800000_idbounce() * sp34[1]) /
            ((BounceEffect *)arg0)->unk1C;
    }
    ((BounceEffect *)arg0)->cursor = ((BounceEffect *)arg0)->begin;
    switch (*(u8 *)arg0) {
        case 0:
            _glid_entrypoint_0(arg1, arg2, &_idbounce_entrypoint_0, (BtIntPtr)arg0);
            break;
        case 1:
            _glid_entrypoint_0(arg1, arg2, &_idbounce_entrypoint_1, (BtIntPtr)arg0);
            break;
        case 2:
        case 3:
            _glid_entrypoint_1(arg1, arg2, &_idbounce_entrypoint_2, (BtIntPtr)arg0);
            break;
    }
}

void idbounce_entrypoint_6(void) {
    extern u8 D_80135480[];
    s32 value;

    value = func_808008B4_idbounce();
    D_80135480[2] = 0;
    D_80135480[0] = !D_80135480[1] && value;
    D_80135480[1] = value;
}

void idbounce_entrypoint_7(void) {
    u32 func_800F54E4(void);
    void func_800F83E4(BtIntPtr, f32);
    extern u8 D_80135480[];
    if (D_80135480[1] != 0 && D_80135480[2] == 0) {
        func_800F83E4(func_800F54E4(), -1.0f);
    }
}
/* data_to_c.py: from asm/data/overlays/id/bounce.data.s */
s32 D_80800E50_idbounce [120] BT_DATA(4, overlays_id_bounce, 0x0) = { 1, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 10, 1148846080, 1128792064, 1133903872, 1120403456, 1077936128, 1128792064, 1073741824, 11, 1157234688, 1125515264, 1133903872, 1120403456, 1077936128, 1137180672, 1075000115, 15, 1140457472, 1125515264, 1128792064, 1120403456, 1077936128, 1128792064, 1073741824, 16, 1148846080, 1137180672, 1142292480, 1120403456, 1077936128, 1128792064, 1073741824, 21, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 30, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 36, 1148846080, 1125515264, 1128792064, 1140457472, 1084227584, 1128792064, 1069547520, 37, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 38, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 39, 1148846080, 1128792064, 1133903872, 1117782016, 1077936128, 1120403456, 1075838976, 40, 1148846080, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 50, 1140457472, 1125515264, 1133903872, 1120403456, 1077936128, 1128792064, 1069547520, 51, 1148846080, 1125515264, 1133903872, 1128792064, 1084227584, 1120403456, 1069547520, -1, 1157234688, 1125515264, 1133903872, 1120403456, 1077936128, 1137180672, 1075838976 };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80135480 [ 3 ] BT_DATA(4, bss_core2bss2_2, 0x25E0);
#endif
