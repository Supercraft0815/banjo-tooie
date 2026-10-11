#include "common.h"

void mlspline_entrypoint_0(f32 t, s32 arg1, f32 points[2][3], f32 dst[3]) {
    int i;
    for (i = 0; i < 3; i++) {
        f32 start = points[0][i];
        f32 end = points[1][i];
        dst[i] = start + (end - start) * t;
    }
}

void mlspline_entrypoint_1(f32 arg0, s32 arg1, u8 *arg2, f32 *arg3) {
    f32 temp_f0;
    register f32 temp_f2;
    register f32 temp_f4;
    register f32 temp_f6;
    register f32 temp_f8;
    temp_f0 = *(f32 *)(arg2 + 0);
    temp_f2 = *(f32 *)(arg2 + 4);
    temp_f4 = temp_f2 - temp_f0;
    temp_f6 = temp_f4 * arg0;
    temp_f0 = (*(f32 *)((s8 *)(arg2) + (0)));
    *arg3 = (((*(f32 *)((s8 *)(arg2) + (4))) - temp_f0) * arg0) + temp_f0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_2.s")

void mlspline_entrypoint_3(f32 arg0, s32 arg1, void *arg2, f32 *arg3) {
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;

    temp_f0 = (*(f32 *)((s8 *)(arg2) + (0)));
    temp_f2 = (*(f32 *)((s8 *)(arg2) + (4)));
    temp_f14 = (*(f32 *)((s8 *)(arg2) + (8)));
    *arg3 = (((((temp_f14 + temp_f0) - (2.0f * temp_f2)) * (2.0f * arg0)) + (((4.0f * temp_f2) - (3.0f * temp_f0)) - temp_f14)) * arg0) + temp_f0;
}

void mlspline_entrypoint_4(f32 arg0, s32 arg1, f32 arg2[][3], volatile f32 *arg3) {
    f32 func_800F0D50(f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 scaled;
    s32 count;
    s32 index;
    s32 i;
    s32 j;
    s32 end;

    count = arg1 - 1;
    scaled = func_800F0D50(arg0, 0.0f, 1.0f);
    scaled *= count;
    count = arg1;
    index = (s32)scaled;
    i = index;
    arg0 = scaled - index;
    if (index == 0) {
        f32 p0, p1, p2;
        if (index < 3) {
        do {
            p0 = arg2[0][i];
            p1 = arg2[1][i];
            p2 = arg2[2][i];
            arg3[i] = (((p2 - p0) * 0.5f + (p0 - p1) * 1.5f) * arg0)
                + ((2.0f * p1 - p2 * 0.5f) - 1.5f * p0);
            arg3[i] *= arg0;
            arg3[i] += (p1 - p0) * 0.5f;
            arg3[i] *= arg0;
            arg3[i] += p0;
            i++;
        } while (i * 4 < 12);
        }
    } else {
        i--;
        end = i + 2;
        if (count == end) {
            func_800EE7F8((f32 *)arg3, &((f32 *)arg2)[count * 3 - 3]);
            return;
        }
        arg2 = (f32 (*)[3])((f32 *)arg2 + i * 3);
        end = i + 3;
        if (count == end) {
            f32 p0, p1, p2;
            for (j = 0; j != 12; j += 4) {
                p0 = *(f32 *)((u8 *)arg2[0] + j);
                p1 = *(f32 *)((u8 *)arg2[1] + j);
                p2 = *(f32 *)((u8 *)arg2[2] + j);
                *(volatile f32 *)((u8 *)arg3 + j) = (((p2 - p0) * 0.5f + (p1 - p2) * 1.5f) * arg0)
                    + ((p0 - p1 * 2.5f) + p2 * 1.5f);
                *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
                *(volatile f32 *)((u8 *)arg3 + j) += (p2 - p0) * 0.5f;
                *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
                *(volatile f32 *)((u8 *)arg3 + j) += p1;
            }
            return;
        }
        {
        f32 p0, p1, p2, p3;
        for (j = 0; j != 12; j += 4) {
            p0 = *(f32 *)((u8 *)arg2[0] + j);
            p1 = *(f32 *)((u8 *)arg2[1] + j);
            p2 = *(f32 *)((u8 *)arg2[2] + j);
            p3 = *(f32 *)((u8 *)arg2[3] + j);
            *(volatile f32 *)((u8 *)arg3 + j) = (((p3 - p0) * 0.5f + (p1 - p2) * 1.5f) * arg0)
                + (((p0 - p1 * 2.5f) + 2.0f * p2) - p3 * 0.5f);
            *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
            *(volatile f32 *)((u8 *)arg3 + j) += (p2 - p0) * 0.5f;
            *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
            *(volatile f32 *)((u8 *)arg3 + j) += p1;
        }
        }
    }
}

void mlspline_entrypoint_5(f32 arg0, s32 arg1, f32 *arg2, volatile f32 *arg3)
{
    f32 func_800F0D50(f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 scaled;
    s32 count;
    s32 i;
    s32 offset;
    s32 j;
    s32 end;

    count = arg1 - 1;
    scaled = func_800F0D50(arg0, 0.0f, 1.0f);
    scaled *= count;
    count = arg1;
    offset = (s32)scaled;
    i = offset;
    arg0 = scaled - (f32)offset;
    if (offset == 0) {
        f32 p0, p1, p2;
        if (offset < 3) {
        do {
            p0 = arg2[i];
            p1 = arg2[i + 3];
            p2 = arg2[i + 6];
            arg3[i] = ((p2 - p0) * 0.16666667f - (p1 - p0) * 0.5f) * arg0 + (p1 - p0) * 0.5f;
            arg3[i] *= arg0;
            arg3[i] += (p1 - p0) * 0.5f;
            arg3[i] *= arg0;
            arg3[i] += (p0 * 5.0f + p1) * 0.16666667f;
            i++;
        } while (i * 4 < 12);
        }
    } else {
        i--;
        end = i + 2;
        if (count == end) {
            arg2 += count * 3 - 3;
            func_800EE7F8((f32 *)arg3, arg2);
            return;
        }
        arg2 += i * 3;
        end = i + 3;
        if (count == end) {
            f32 p0, p1, p2, difference, sum;
            for (j = 0; j != 12; j += 4) {
                p0 = *(f32 *)((u8 *)arg2 + j);
                p2 = *(f32 *)((u8 *)(arg2 + 6) + j);
                p1 = *(f32 *)((u8 *)(arg2 + 3) + j);
                sum = p0 + p2;
                difference = p2 - p0;
                *(volatile f32 *)((u8 *)arg3 + j) = ((difference * 0.16666667f + (p1 - p2) * 0.5f) * arg0) + (sum * 0.5f - p1);
                *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
                *(volatile f32 *)((u8 *)arg3 + j) += difference * 0.5f;
                *(volatile f32 *)((u8 *)arg3 + j) *= arg0;
                *(volatile f32 *)((u8 *)arg3 + j) += sum * 0.16666667f + p1 * 0.6666667f;
            }
            return;
        }
        {
            f32 p0, p1, p2, p3;
            f32 *point = arg2;
            volatile f32 *out;
            i = 0;
            out = arg3;
            for (; i != 3; i++) {
                p0 = point[0];
                p1 = point[3];
                p2 = point[6];
                p3 = point[9];
                *out = ((p3 - p0) * 0.16666667f + (p1 - p2) * 0.5f) * arg0;
                *out += (p0 + p2) * 0.5f - p1;
                *out *= arg0;
                *out += (p2 - p0) * 0.5f;
                *out *= arg0;
                *out += (p0 + p2) * 0.16666667f + p1 * 0.6666667f;
                point++;
                out++;
            }
        }
    }
}

/* extern */

void mlspline_entrypoint_6(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800EFB24(s32, s32);
    func_800EFB24(arg3, arg2 + 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_7.s")

void mlspline_entrypoint_8(f32 arg0, s32 arg1, f32 *arg2, volatile f32 *arg3)
{
    f32 func_800F0D50(f32, f32, f32);
    f32 scaled;
    s32 count;
    s32 i;
    s32 offset;
    s32 j;
    s32 end;
    s32 penultimate;
    count = arg1 - 1;
    scaled = func_800F0D50(arg0, 0.0f, 1.0f);
    scaled *= count;
    count = arg1;
    offset = (s32) scaled;
    i = offset;
    arg0 = scaled - (f32) offset;
    if (offset == 0) {
        f32 a;
        f32 b;
        f32 c;
        for (; i < 3; i++) {
            a = arg2[(u32) i];
            b = arg2[(u32) i + 3];
            c = arg2[(u32) i + 6];
            arg3[i] = ((a - b) * 4.5f + 1.5f * (c - a)) * arg0
                    + (4.0f * b - c - 3.0f * a);
            arg3[i] *= arg0;
            arg3[i] += 0.5f * (b - a);
        }
    } else {
        i--;
        end = i + 2;
        penultimate = i + 3;
        arg2 += (u32) i * 3;
        if (count == end) {
            f32 a;
            f32 b;
            for (j = 0; j < 3; j++) {
                a = arg2[(u32) j];
                b = arg2[(u32) j + 3];
                arg3[j] = (b - a) * 0.5f;
            }
        } else if (count == penultimate) {
            f32 a;
            f32 b;
            f32 c;
            for (j = 0; j < 3; j++) {
                a = arg2[(u32) j];
                b = arg2[(u32) j + 3];
                c = arg2[(u32) j + 6];
                arg3[j] = ((b - c) * 4.5f + 1.5f * (c - a)) * arg0
                        + (2.0f * a - 5.0f * b + 3.0f * c);
                arg3[j] *= arg0;
                arg3[j] += 0.5f * (c - a);
            }
        } else {
            f32 a;
            f32 b;
            f32 c;
            f32 d;
            for (j = 0; j < 3; j++) {
                a = arg2[(u32) j];
                b = arg2[(u32) j + 3];
                c = arg2[(u32) j + 6];
                d = arg2[(u32) j + 9];
                arg3[j] = ((b - c) * 4.5f + 1.5f * (d - a)) * arg0
                        + (2.0f * a - 5.0f * b + 4.0f * c - d);
                arg3[j] *= arg0;
                arg3[j] += 0.5f * (c - a);
            }
        }
    }
}

void mlspline_entrypoint_9(f32 arg0, s32 arg1, f32 *arg2, volatile f32 *arg3)
{
    f32 func_800F0D50(f32, f32, f32);
    f32 scaled;
    s32 count;
    s32 i;
    s32 j;
    s32 offset;
    s32 end;
    s32 penultimate;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    count = arg1 - 1;
    scaled = func_800F0D50(arg0, 0.0f, 1.0f);
    scaled *= count;
    count = arg1;
    offset = (s32) scaled;
    i = offset;
    arg0 = scaled - (f32) offset;
    if (offset == 0) {
        if (offset < 1) {
            do {
                a = *(f32 *)((u8 *) arg2 + i * 4);
                b = *(f32 *)((u8 *) arg2 + i * 4 + 4);
                c = *(f32 *)((u8 *) arg2 + i * 4 + 8);
                *(volatile f32 *)((u8 *) arg3 + i * 4) = (((c - a) * 0.5f + (a - b) * 1.5f) * arg0)
                    + ((2.0f * b - c * 0.5f) - 1.5f * a);
                *(volatile f32 *)((u8 *) arg3 + i * 4) *= arg0;
                *(volatile f32 *)((u8 *) arg3 + i * 4) += (b - a) * 0.5f;
                *(volatile f32 *)((u8 *) arg3 + i * 4) *= arg0;
                *(volatile f32 *)((u8 *) arg3 + i * 4) += a;
                i++;
            } while (i * 4 < 4);
        }
    } else {
        i--;
        end = i + 2;
        penultimate = i + 3;
        if (count == end) {
            arg2 += (u32) count - 1;
            *arg3 = *arg2;
        } else {
            arg2 += i;
            if (count == penultimate) {
                f32 a;
                f32 b;
                f32 c;
                for (j = 0; j != 4; j += 4) {
                    a = *(f32 *)((u8 *) arg2 + j);
                    b = *(f32 *)((u8 *) arg2 + j + 4);
                    c = *(f32 *)((u8 *) arg2 + j + 8);
                    *(volatile f32 *)((u8 *) arg3 + j) = (((c - a) * 0.5f + (b - c) * 1.5f) * arg0)
                        + ((a - b * 2.5f) + c * 1.5f);
                    *(volatile f32 *)((u8 *) arg3 + j) *= arg0;
                    *(volatile f32 *)((u8 *) arg3 + j) += (c - a) * 0.5f;
                    *(volatile f32 *)((u8 *) arg3 + j) *= arg0;
                    *(volatile f32 *)((u8 *) arg3 + j) += b;
                }
            } else {
                f32 a;
                f32 b;
                f32 c;
                f32 d;
                for (j = 0; j != 4; j += 4) {
                    a = *(f32 *)((u8 *) arg2 + j);
                    b = *(f32 *)((u8 *) arg2 + j + 4);
                    c = *(f32 *)((u8 *) arg2 + j + 8);
                    d = *(f32 *)((u8 *) arg2 + j + 12);
                    *(volatile f32 *)((u8 *) arg3 + j) = (((d - a) * 0.5f + (b - c) * 1.5f) * arg0)
                        + (((a - b * 2.5f) + 2.0f * c) - d * 0.5f);
                    *(volatile f32 *)((u8 *) arg3 + j) *= arg0;
                    *(volatile f32 *)((u8 *) arg3 + j) += (c - a) * 0.5f;
                    *(volatile f32 *)((u8 *) arg3 + j) *= arg0;
                    *(volatile f32 *)((u8 *) arg3 + j) += b;
                }
            }
        }
    }
}

void mlspline_entrypoint_10(f32 arg0, s32 arg1, f32 *arg2, volatile f32 *arg3)
{
  f32 func_800F0D50(f32, f32, f32);
  f32 scaled;
  s32 count;
  s32 i;
  s32 end;
  s32 penultimate;
  f32 a;
  f32 b;
  f32 c;
  f32 d;
  f32 slope;
  count = arg1 - 1;
  scaled = func_800F0D50(arg0, 0.0f, 1.0f);
  scaled *= count;
  i = (s32) scaled;
  arg0 = scaled - ((f32) i);
  if (i == 0)
  {
    for (; i < 3; i++)
    {
      a = arg2[(u32) i];
      b = arg2[((u32) i) + 3];
      c = arg2[((u32) i) + 6];
      slope = b - a;
      arg3[(u32) i] = ((((c - a) * 0.5f) - (slope * 1.5f)) * arg0) + (b - a);
      arg3[(u32) i] *= arg0;
      arg3[(u32) i] += (b - a) * 0.5f;
    }

  }
  else
  {
    i--;
    arg2 += i * 3;
    end = i + 2;
    penultimate = i + 3;
    if (arg1 == end)
    {
      for (i = 0; i != 3; i++)
      {
        a = arg2[i];
        b = arg2[i + 3];
        arg3[i] = (b - a) * 0.5f;
      }

    }
    else
      if (arg1 == penultimate)
    {
      for (i = 0; i != 3; i++)
      {
        a = arg2[i];
        b = arg2[i + 3];
        c = arg2[i + 6];
        slope = (c - a) * 0.5f;
        arg3[i] = ((((b - c) * 1.5f) + slope) * arg0) + ((a + c) - (2.0f * b));
        arg3[i] *= arg0;
        arg3[i] += slope;
      }

    }
    else
    {
      for (i = 0; i != 3; i++)
      {
        a = arg2[i];
        b = arg2[i + 3];
        c = arg2[i + 6];
        d = arg2[i + 9];
        arg3[i] = ((((d - a) * 0.5f) + ((b - c) * 1.5f)) * arg0) + ((a + c) - (2.0f * b));
        arg3[i] *= arg0;
        arg3[i] += (c - a) * 0.5f;
      }

    }
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/func_8080145C_mlspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/func_80801488_mlspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ml/spline/mlspline_entrypoint_12.s")

f32 mlspline_entrypoint_13(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 (*arg5)(f32, s32, s32, f32 *)) {
    f32 func_800EEF94(f32 *);
    f32 func_80801488_mlspline(s32, s32, f32, f32, s32, f32, s32 (*)(f32, s32, s32, f32 *));
    f32 mlAbsF(f32);
    f32 spAC;
    f32 var_f24;
    f32 var_f22;
    s32 spA0;
    f32 var_f20;
    f32 speed;
    f32 sp8C[3];
    s32 var_s3;
    s32 var_s4;
    f32 temp_f12;
    f32 sp7C;

    var_s3 = 0;
    if (arg0 >= 4) {
        spA0 = arg0 - 1;
    } else {
        spA0 = 1;
    }
    var_s4 = 0;
    if (mlAbsF(arg3) < 0.01f) {
        return arg2;
    }
    arg5(arg2, arg0, arg1, sp8C);
    spAC = arg3 / (func_800EEF94(sp8C) * (f32) spA0);
    sp7C = mlAbsF(arg3);
    var_f24 = arg2 + spAC;
    do {
    var_f22 = var_f24;
    if (spAC > 0.0f) {
        if (var_f22 >= 1.0f) {
            if (arg4 == 1.0f) {
                var_f22 = 1.0f;
                var_f20 = func_80801488_mlspline(arg1, arg0, arg2, 1.0f, 0x400, 0.01f, arg5);
                if (var_f20 < arg3) {
                    var_s3 = 1;
                }
            } else {
                var_f22 += arg4;
                var_f22 -= (f32) (s32) var_f22;
                var_f20 = func_80801488_mlspline(arg1, arg0, arg2, 1.0f, 0x400, 0.01f, arg5);
                var_f20 += func_80801488_mlspline(arg1, arg0, arg4, var_f22, 0x400, 0.01f, arg5);
            }
        } else {
            var_f20 = func_80801488_mlspline(arg1, arg0, arg2, var_f22, 0x400, 0.01f, arg5);
        }
    } else if (arg4 == 1.0f) {
        if (var_f22 < 0.0f) {
            var_f22 = 0.0f;
            var_f20 = func_80801488_mlspline(arg1, arg0, arg2, 0.0f, 0x400, 0.01f, arg5);
            if (arg3 < var_f20) {
                var_s3 = 1;
            }
        } else {
            var_f20 = func_80801488_mlspline(arg1, arg0, arg2, var_f22, 0x400, 0.01f, arg5);
        }
    } else if (var_f22 < arg4) {
        var_f22 -= arg4;
        var_f22 -= (f32) (s32) var_f22;
        var_f22 += 1.0f;
        var_f20 = func_80801488_mlspline(arg1, arg0, arg2, arg4, 0x400, 0.01f, arg5);
        var_f20 += func_80801488_mlspline(arg1, arg0, 1.0f, var_f22, 0x400, 0.01f, arg5);
    } else {
        var_f20 = func_80801488_mlspline(arg1, arg0, arg2, var_f22, 0x400, 0.01f, arg5);
    }
    if ((var_s3 == 0) && (mlAbsF(var_f20 - sp7C) > 0.01f)) {
        arg5(var_f22, arg0, arg1, sp8C);
        speed = func_800EEF94(sp8C) * (f32) spA0;
        temp_f12 = (var_f20 - arg3) / speed;
        var_f24 = var_f22 - temp_f12;
        if (mlAbsF(temp_f12) < 0.000001f) {
            var_s3 = 1;
        }
        if (spAC > 0.0f) {
            if (var_f24 < arg2) {
                var_f24 += 1.0f - arg4;
            }
        } else if (arg2 < var_f24) {
            var_f24 -= 1.0f - arg4;
        }
    } else {
        var_s3 = 1;
    }
    var_s4 += 1;
    } while ((var_s3 == 0) && (var_s4 < 0xA));
    return var_f22;
}
