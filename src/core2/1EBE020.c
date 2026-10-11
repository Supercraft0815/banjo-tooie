#include "common.h"

s32 func_800E4730(s32 arg0) {
    extern void *D_8012D560;
    extern void *D_8012D564;
    extern void *D_8012D568;
    extern void *D_8012D56C;
    if ((D_8012D560 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D560) + (0x3A))))) {
        return 0;
    }
    if ((D_8012D564 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D564) + (0x3A))))) {
        return 1;
    }
    if ((D_8012D568 != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D568) + (0x3A))))) {
        return 2;
    }
    if ((D_8012D56C != NULL) && (arg0 == (*(s16 *)((s8 *)(D_8012D56C) + (0x3A))))) {
        return 3;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E47CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E488C.s")

/* extern */

s32 func_800E4AF0(void) {
    s32 func_800E4730();
    if (func_800E4730() < 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4B1C.s")

/* extern */

s32 func_800E4BB8(void) {
    s32 func_800E4730();
    s32 func_800E4B1C(s32);
    s32 temp_v0;

    temp_v0 = func_800E4730();
    if (temp_v0 < 0) {
        return 0;
    }
    func_800E4B1C(temp_v0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4C7C.s")

/* extern */

void func_800E4CE8(void) {
    s32 func_800E4B1C(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800E4B1C(var_s0);
        var_s0 += 1;
    } while (var_s0 != 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5390.s")

int func_800E589C(unsigned int *b, unsigned int n, unsigned int s, u16 *d, u8 *e, struct huft **t, int *m, struct workspace *state) {
    unsigned int a;
    unsigned int c[17];
    unsigned int f;
    int g;
    int h;
    register unsigned int i;
    register unsigned int j;
    register s32 k;
    int l;
    register unsigned int *p;
    register struct huft *q;
    struct huft {
        u8 e;
        u8 b;
        union {
            u16 n;
            struct huft *t;
        } v;
    } r;
    struct huft *u[16];
    unsigned int v[288];
    register int w;
    unsigned int x[17];
    unsigned int *xp;
    int y;
    unsigned int z;
    struct workspace {
        u8 pad[0x28];
        struct huft *tables;
        s32 used;
    };

    bzero(c, sizeof(c));
    p = b;
    i = n;
    do {
        c[*p++]++;
    } while (--i);
    if (c[0] == n) {
        *t = 0;
        *m = 0;
        return 0;
    }
    l = *m;
    for (j = 1; j <= 16; j++) {
        if (c[j]) {
            break;
        }
    }
    k = j;
    if ((unsigned int)l < j) {
        l = j;
    }
    for (i = 16; i; i--) {
        if (c[i]) {
            break;
        }
    }
    g = i;
    if ((unsigned int)l > i) {
        l = i;
    }
    *m = l;
    for (y = 1 << j; j < i; j++, y <<= 1) {
        y -= c[j];
    }
    y -= c[i];
    c[i] += y;
    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {
        *xp++ = (j += *p++);
    }
    p = b;
    i = 0;
    do {
        if ((j = *p++) != 0) {
            v[x[j]++] = i;
        }
    } while (++i < n);
    x[0] = i = 0;
    p = v;
    h = -1;
    w = -l;
    u[0] = 0;
    q = 0;
    z = 0;
    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            while (k > w + l) {
                h++;
                w += l;
                z = (z = g - w) > (unsigned int)l ? l : z;
                if ((f = 1 << (j = k - w)) > a + 1) {
                    f -= a + 1;
                    xp = c + k;
                    while (++j < z) {
                        if ((f <<= 1) <= *++xp) {
                            break;
                        }
                        f -= *xp;
                    }
                }
                z = 1 << j;
                q = state->tables + state->used;
                state->used += z + 1;
                *t = q + 1;
                *(t = &q->v.t) = 0;
                u[h] = ++q;
                if (h) {
                    x[h] = i;
                    r.b = l;
                    r.e = 16 + j;
                    r.v.t = q;
                    j = i >> (w - l);
                    u[h - 1][j] = r;
                }
            }
            r.b = k - w;
            if (p >= v + n) {
                r.e = 99;
            } else if (*p < s) {
                r.e = *p < 256 ? 16 : 15;
                r.v.n = *p++;
            } else {
                r.e = e[*p - s];
                r.v.n = d[*p++ - s];
            }
            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f) {
                q[j] = r;
            }
            for (j = 1 << (k - 1); i & j; j >>= 1) {
                i ^= j;
            }
            i ^= j;
            while ((i & ((1 << w) - 1)) != x[h]) {
                h--;
                w -= l;
            }
        }
    }
    return y != 0 && g != 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E659C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6728.s")

void func_800E692C(void) {
    s32 heap_alloc(s32);
    extern s32 D_8012D570;
    D_8012D570 = heap_alloc(0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6950.s")

u32 func_800E6A00(void) {
    extern u8 D_801275E0;
    return *(u8 *)((u8 *)&D_801275E0 + 0);
}
