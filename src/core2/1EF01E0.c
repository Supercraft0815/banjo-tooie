#include "common.h"

void func_801168F0(void) {
    extern s32 D_8000E800;
    extern s32 D_80011000;
    extern s32 *D_80124A80;
    extern s32 *D_80124A8C;
    D_80124A8C = &D_80011000;
    D_80124A80 = &D_8000E800;
}

void func_80116914(u32 *b, u32 n, u32 s, u16 *d, u8 *e, struct Huft **t, s32 *m) {
    typedef struct Huft {
        u8 e;
        u8 b;
        union {
            u16 n;
            struct Huft *t;
        } v;
    } Huft;
    extern s32 *D_80124A80;
    extern s32 D_80137388;
    u32 a;
    u32 c[17];
    u32 f;
    s32 g;
    s32 h;
    u32 i;
    u32 j;
    s32 k;
    s32 l;
    u32 *p;
    Huft *q;
    Huft r;
    Huft *u[16];
    u32 v[288];
    s32 w;
    u32 x[17];
    u32 *xp;
    s32 y;
    u32 z;

    bzero(c, sizeof(c));
    p = b;
    i = n;
    do {
        c[*p++]++;
    } while (--i);
    if (c[0] == n) {
        *t = 0;
        *m = 0;
        return;
    }
    l = *m;
    for (j = 1; j <= 16; j++) {
        if (c[j]) {
            break;
        }
    }
    k = j;
    if ((u32)l < j) {
        l = j;
    }
    for (i = 16; i; i--) {
        if (c[i]) {
            break;
        }
    }
    g = i;
    if ((u32)l > i) {
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
                z = (z = g - w) > (u32)l ? l : z;
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
                q = D_80137388 + (Huft *)D_80124A80;
                D_80137388 += z + 1;
                *t = q + 1;
                *(t = &q->v.t) = 0;
                u[h] = ++q;
                if (h) {
                    x[h] = i;
                    r.b = l;
                    r.e = 16 + j;
                    r.v.t = q;
                    u[h - 1][i >> (w - l)] = r;
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
}
