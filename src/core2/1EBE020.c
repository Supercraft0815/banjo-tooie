#include "common.h"
#include "gl/introsync_state.h"
#include "inflate_tables.inc"
struct huft {
    u8 e, b;
    union { u16 n; struct huft *t; } v;
};
struct decoder {
    u8 *input;
    s32 input_pos;
    u8 *output;
    u32 bits, count, output_pos;
    struct huft *tl, *td;
    s32 bl, bd;
    struct huft *tables;
    s32 used, offset;
    u8 *allocation;
    u8 stage, final;
    s16 asset, limit;
};
enum { decode_table_capacity = 0x2800 / 8 };
#ifdef BT_NATIVE
struct decoder *D_8012D560[4];
void *D_8012D570;
#ifdef BT_ILP32
_Static_assert(sizeof(struct decoder) == 0x40, "asset decoder size");
_Static_assert(sizeof(struct huft) == 8, "Huffman table entry");
_Static_assert(__builtin_offsetof(struct decoder, tables) == 0x28, "Huffman workspace");
_Static_assert(__builtin_offsetof(struct decoder, allocation) == 0x34, "decoded asset");
_Static_assert(__builtin_offsetof(struct decoder, asset) == 0x3A, "decoded asset id");
#endif
#endif

s32 func_800E4730(s32 arg0) {
#ifdef BT_NATIVE
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_8012D560[i] && D_8012D560[i]->asset == arg0) return i;
    }
    return -1;
#else
    extern struct decoder *D_8012D560[];
    extern struct decoder *D_8012D564;
    extern struct decoder *D_8012D568;
    extern struct decoder *D_8012D56C;
    if ((D_8012D560[0] != NULL) && (arg0 == D_8012D560[0]->asset)) {
        return 0;
    }
    if ((D_8012D564 != NULL) && (arg0 == D_8012D564->asset)) {
        return 1;
    }
    if ((D_8012D568 != NULL) && (arg0 == D_8012D568->asset)) {
        return 2;
    }
    if ((D_8012D56C != NULL) && (arg0 == D_8012D56C->asset)) {
        return 3;
    }
    return -1;
#endif
}

s32 func_800E47CC(void) {
#ifdef BT_NATIVE
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!D_8012D560[i] || D_8012D560[i]->asset == -1) return i;
    }
    return -1;
#else
    extern struct decoder *D_8012D560[];
    extern struct decoder *D_8012D564;
    extern struct decoder *D_8012D568;
    extern struct decoder *D_8012D56C;
    if (D_8012D560[0] == NULL) {
        return 0;
    }
    if (D_8012D560[0]->asset == -1) {
        return 0;
    }
    if (D_8012D564 == NULL) {
        return 1;
    }
    if (D_8012D564->asset == -1) {
        return 1;
    }
    if (D_8012D568 == NULL) {
        return 2;
    }
    if (D_8012D568->asset == -1) {
        return 2;
    }
    if (D_8012D56C == NULL) {
        return 3;
    }
    if (D_8012D56C->asset == -1) {
        return 3;
    }
    return -1;
#endif
}

s32 func_800E488C(s32 arg0) {
    BT_IDO_ONLY(extern struct decoder *D_8012D560[];)
    void *heap_alloc(s32);
    void heap_free(void *);
    void func_8001311C(u8 *, s32);
    s32 func_800D5A6C(s32);
    s32 func_800E4B1C(s32);
    s32 func_800E4D28(void *);
    s32 func_800E4E54(void *);
    int func_800E5EC0();
    s32 func_800E659C(void *);
    s32 func_800E6728(void *);
    s32 index;
    struct decoder *state;
    s32 size;
    s32 status;
    u32 result;

    index = func_800E4730(arg0);
    if (index == -1) {
        index = func_800E47CC();
        if (index < 0) return 0;
        D_8012D560[index] = heap_alloc(sizeof(*state));
        D_8012D560[index]->stage = 1;
        D_8012D560[index]->asset = arg0;
        D_8012D560[index]->limit = 2500;
    }
    state = D_8012D560[index];
    if (state->stage == 0) return 1;
    switch (state->stage) {
    case 1:
        state->allocation = NULL;
        state->bits = 0;
        state->count = 0;
        state->output_pos = 0;
        state->tables = heap_alloc(decode_table_capacity * sizeof(struct huft));
        state->offset = func_800D5A6C(state->asset);
        state->input = heap_alloc(0x1800);
        func_8001311C(state->input, state->offset);
        state->offset += 0x1800;
#ifdef BT_NATIVE
        size = ((u32)state->input[0] << 8) | state->input[1];
#else
        size = *(u32 *)state->input;
        size = (u32)size >> 16;
#endif
        size *= 16;
        state->input_pos = 2;
        state->allocation = heap_alloc(size);
        if (state->allocation == NULL) {
            func_800E4B1C(index);
            return 0;
        }
        state->output = state->allocation;
        state->stage = 2;
        return 0;
    case 2:
        state->used = 0;
        result = 0;
        status = func_800E4D28(state);
        switch (status) {
        case 2:
            do {
                func_800E5EC0((void *)state);
            } while (++result < 0);
            state->stage = 3;
            break;
        case 0:
            func_800E6728(state);
            state->stage = 4;
            return 0;
        case 1:
            func_800E659C(state);
            state->stage = 4;
            break;
        }
        return 0;
    case 3:
        if (func_800E4E54(state) == 0) state->stage = 4;
        return 0;
    case 4:
        if (state->final) {
            if (state->tables != NULL) {
                heap_free(state->tables);
                state->tables = NULL;
            }
            if (state->input != NULL) {
                heap_free(state->input);
                state->input = NULL;
            }
            state->stage = 0;
            osWritebackDCache(state->allocation, state->output_pos);
            return 1;
        } else {
            state->stage = 2;
            return 0;
        }
    case 0:
        return 1;
    }
    return 0;
}

/* extern */

s32 func_800E4AF0(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 func_800E4730();
#ifdef BT_NATIVE
    if (func_800E4730(bt_a0) < 0) {
#else
    if (func_800E4730() < 0) {
#endif
        return 0;
    }
    return 1;
}

s32 func_800E4B1C(s32 arg0) {
    void heap_free(void *);
    BT_IDO_ONLY(extern struct decoder *D_8012D560[];)
    if (D_8012D560[arg0] != NULL) {
        if (D_8012D560[arg0]->allocation != NULL) {
            heap_free(D_8012D560[arg0]->allocation);
        }
        if (D_8012D560[arg0]->input != NULL) {
            heap_free(D_8012D560[arg0]->input);
        }
        if (D_8012D560[arg0]->tables != NULL) {
            heap_free(D_8012D560[arg0]->tables);
        }
        heap_free(D_8012D560[arg0]);
        D_8012D560[arg0] = NULL;
    }
    BT_NATIVE_ONLY(return 0;) }

/* extern */

s32 func_800E4BB8(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 func_800E4730();
    s32 func_800E4B1C(s32);
    s32 temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_800E4730(bt_a0);
#else
    temp_v0 = func_800E4730();
#endif
    if (temp_v0 < 0) {
        return 0;
    }
    func_800E4B1C(temp_v0);
    return 1;
}

void * func_800E4BF4(s32 arg0) {
    s32 func_800E488C(s32);
    void heap_free(void *);
    BT_IDO_ONLY(extern struct decoder *D_8012D560[];)
    s32 sp24;
    void * sp20;
    s32 temp_v0;
    struct decoder **temp_s0;
    struct decoder *temp_a0;

    temp_v0 = func_800E4730(arg0);
    sp24 = temp_v0;
    if (temp_v0 == -1) {
        return 0;
    }
    if (func_800E488C(arg0) == 0) {
        do {

        } while (func_800E488C(arg0) == 0);
    }
    temp_s0 = &D_8012D560[sp24];
    temp_a0 = *temp_s0;
    sp20 = temp_a0->allocation;
    heap_free(temp_a0);
    *temp_s0 = NULL;
    return sp20;
}

#ifdef BT_NATIVE
void func_800E4C7C(void) {
    void *defrag(void *);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_8012D560[i]) D_8012D560[i] = defrag(D_8012D560[i]);
    }
    D_8012D570 = defrag(D_8012D570);
}
#else
void func_800E4C7C(void) { extern struct decoder *D_8012D560[]; extern void *D_8012D570; extern void *defrag(void *);  void **p;
p=(void **)D_8012D560; do { if(*p) *p=defrag(*p); p++; } while(p!=(void **)(unsigned long)&D_8012D570); D_8012D570=defrag(D_8012D570); }
#endif

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

s32 func_800E4D28(void *arg0) {
    void func_8001311C(u8 *, s32);
    struct decoder *d = arg0;
    u32 count;
    u8 *input;
    u32 bits;
    s32 pos;

    count = d->count;
    bits = d->bits;
    if (count == 0) {
        input = d->input;
        do {
            pos = d->input_pos;
            if (pos >= 0x1800) {
                d->input_pos = 0;
                func_8001311C(input, d->offset);
                pos = d->input_pos;
                d->offset += 0x1800;
                input = d->input;
            }
            bits |= input[pos] << count;
            d->input_pos = pos + 1;
            count += 8;
        } while (count == 0);
    }
    count--;
    d->final = bits & 1;
    bits >>= 1;
    if (count < 2) {
        input = d->input;
        do {
            pos = d->input_pos;
            if (pos >= 0x1800) {
                d->input_pos = 0;
                func_8001311C(input, d->offset);
                pos = d->input_pos;
                d->offset += 0x1800;
                input = d->input;
            }
            bits |= input[pos] << count;
            d->input_pos = pos + 1;
            count += 8;
        } while (count < 2);
    }
    d->bits = bits >> 2;
    count -= 2;
    d->count = count;
    return bits & 3;
}

s32 func_800E4E54(void *arg0) {
    void func_8001311C(u8 *, s32);
    extern u16 D_801232C0[];
    register unsigned int e;
    struct huft *t;
    register u32 b;
    register unsigned int k;
    u32 ml;
    u32 md;
    s32 counter = 0;
    struct huft *tl;
    struct huft *td;
    u8 *slide;
    unsigned int w;

    slide = ((struct decoder *)arg0)->output;
    tl = ((struct decoder *)arg0)->tl;
    td = ((struct decoder *)arg0)->td;
    b = ((struct decoder *)arg0)->bits;
    k = ((struct decoder *)arg0)->count;
    w = ((struct decoder *)arg0)->output_pos;
    ml = D_801232C0[((struct decoder *)arg0)->bl];
    md = D_801232C0[((struct decoder *)arg0)->bd];
    for (;;) {
        if (k < ((struct decoder *)arg0)->bl) {
            do {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            } while (k < ((struct decoder *)arg0)->bl);
        }
        t = tl + (b & ml);
        e = t->e;
        while (e > 16) {
            b >>= t->b;
            k -= t->b;
            e -= 16;
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            t = t->v.t + (b & D_801232C0[e]);
            e = t->e;
        }
        b >>= t->b;
        k -= t->b;
        if (e == 16) {
            slide[w++] = t->v.n;
        } else {
            unsigned int n;
            unsigned int d;
            u8 *dest;
            if (e == 15) {
                break;
            }
            dest = slide + w;
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            n = t->v.n + (b & D_801232C0[e]);
            b >>= e;
            k -= e;
            while (k < ((struct decoder *)arg0)->bd) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            t = td + (b & md);
            e = t->e;
            while (e > 16) {
                b >>= t->b;
                k -= t->b;
                e -= 16;
                while (k < e) {
                    if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                        ((struct decoder *)arg0)->input_pos = 0;
                        func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                        ((struct decoder *)arg0)->offset += 0x1800;
                    }
                    b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                    k += 8;
                }
                t = t->v.t + (b & D_801232C0[e]);
                e = t->e;
            }
            b >>= t->b;
            k -= t->b;
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            d = w - t->v.n - (b & D_801232C0[e]);
            b >>= e;
            k -= e;
            do {
                w++;
                *dest++ = slide[d++];
            } while (--n);
        }
        if (counter++ > ((struct decoder *)arg0)->limit) {
            ((struct decoder *)arg0)->output_pos = w;
            ((struct decoder *)arg0)->bits = b;
            ((struct decoder *)arg0)->count = k;
            return 1;
        }
    }
    ((struct decoder *)arg0)->output_pos = w;
    ((struct decoder *)arg0)->bits = b;
    ((struct decoder *)arg0)->count = k;
    return 0;
}

s32 func_800E5390(void *arg0) {
    void func_8001311C(u8 *, s32);
    extern u16 D_801232C0[];
    register unsigned int e;
    struct huft *t;
    register u32 b;
    register unsigned int k;
    u32 ml;
    u32 md;
    u8 *slide = ((struct decoder *)arg0)->output;
    struct huft *tl = ((struct decoder *)arg0)->tl;
    struct huft *td = ((struct decoder *)arg0)->td;
    unsigned int w;

    b = ((struct decoder *)arg0)->bits;
    k = ((struct decoder *)arg0)->count;
    w = ((struct decoder *)arg0)->output_pos;
    ml = D_801232C0[((struct decoder *)arg0)->bl];
    md = D_801232C0[((struct decoder *)arg0)->bd];
    for (;;) {
        if (k < ((struct decoder *)arg0)->bl) {
            do {
            if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                ((struct decoder *)arg0)->input_pos = 0;
                func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                ((struct decoder *)arg0)->offset += 0x1800;
            }
            b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
            k += 8;
            } while (k < ((struct decoder *)arg0)->bl);
        }
        t = tl + (b & ml);
        e = t->e;
        while (e > 16) {
            b >>= t->b;
            k -= t->b;
            e -= 16;
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            t = t->v.t + (b & D_801232C0[e]);
            e = t->e;
        }
        b >>= t->b;
        k -= t->b;
        if (e == 16) {
            slide[w++] = t->v.n;
        } else {
            unsigned int n;
            if (e == 15) {
                break;
            }
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            n = t->v.n + (b & D_801232C0[e]);
            b >>= e;
            k -= e;
            while (k < ((struct decoder *)arg0)->bd) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            t = td + (b & md);
            e = t->e;
            while (e > 16) {
                b >>= t->b;
                k -= t->b;
                e -= 16;
                while (k < e) {
                    if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                        ((struct decoder *)arg0)->input_pos = 0;
                        func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                        ((struct decoder *)arg0)->offset += 0x1800;
                    }
                    b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                    k += 8;
                }
                t = t->v.t + (b & D_801232C0[e]);
                e = t->e;
            }
            b >>= t->b;
            k -= t->b;
            while (k < e) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            {
            unsigned int d;
            d = w - t->v.n - (b & D_801232C0[e]);
            b >>= e;
            k -= e;
            do {
                slide[w++] = slide[d++];
            } while (--n);
            }
        }
    }
    ((struct decoder *)arg0)->output_pos = w;
    ((struct decoder *)arg0)->bits = b;
    ((struct decoder *)arg0)->count = k;
    return 0;
}

int func_800E589C(unsigned int *b, unsigned int n, unsigned int s, u16 *d, u8 *e, struct huft **t, int *m, struct decoder *state) {
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
    struct huft r;
    struct huft *u[16];
    unsigned int v[288];
    register int w;
    unsigned int x[17];
    unsigned int *xp;
    int y;
    unsigned int z;

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

int func_800E5EC0(struct decoder *arg0) {
    void func_8001311C(u8 *, s32);
    extern u8 D_801231F0[];

    extern u16 D_80123204[];
    extern u8 D_80123244[];
    extern u16 D_80123264[];
    extern u8 D_801232A0[];
    extern u16 D_801232C0[];
    unsigned int i;
    unsigned int j;
    unsigned int l;
    unsigned int m;
    unsigned int n;
    struct huft *tl;
    struct huft *td;
    int bl;
    int bd;
    unsigned int nb;
    unsigned int nl;
    unsigned int nd;
    unsigned int ll[316];
    register u32 b;
    register unsigned int k;

    bl = ((struct decoder *)arg0)->bl;
    bd = ((struct decoder *)arg0)->bd;
    tl = ((struct decoder *)arg0)->tl;
    td = ((struct decoder *)arg0)->td;
    b = ((struct decoder *)arg0)->bits;
    k = ((struct decoder *)arg0)->count;
    while (k < 5) {
        if (((struct decoder *)arg0)->input_pos >= 0x1800) {
            ((struct decoder *)arg0)->input_pos = 0;
            func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
            ((struct decoder *)arg0)->offset += 0x1800;
        }
        b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
        k += 8;
    }
    nl = 257 + (b & 31);
    b >>= 5;
    k -= 5;
    while (k < 5) {
        if (((struct decoder *)arg0)->input_pos >= 0x1800) {
            ((struct decoder *)arg0)->input_pos = 0;
            func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
            ((struct decoder *)arg0)->offset += 0x1800;
        }
        b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
        k += 8;
    }
    nd = 1 + (b & 31);
    b >>= 5;
    k -= 5;
    while (k < 4) {
        if (((struct decoder *)arg0)->input_pos >= 0x1800) {
            ((struct decoder *)arg0)->input_pos = 0;
            func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
            ((struct decoder *)arg0)->offset += 0x1800;
        }
        b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
        k += 8;
    }
    nb = 4 + (b & 15);
    b >>= 4;
    k -= 4;
    for (j = 0; j < nb; j++) {
        while (k < 3) {
            if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                ((struct decoder *)arg0)->input_pos = 0;
                func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                ((struct decoder *)arg0)->offset += 0x1800;
            }
            b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
            k += 8;
        }
        ll[D_801231F0[j]] = b & 7;
        b >>= 3;
        k -= 3;
    }
    for (; j < 19; j++) {
        ll[D_801231F0[j]] = 0;
    }
    bl = 7;
    func_800E589C(ll, 19, 19, 0, 0, (void *)&tl, &bl, arg0);
    n = nl + nd;
    m = D_801232C0[bl];
    i = l = 0;
    while (i < n) {
        while (k < bl) {
            if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                ((struct decoder *)arg0)->input_pos = 0;
                func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                ((struct decoder *)arg0)->offset += 0x1800;
            }
            b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
            k += 8;
        }
        j = (td = tl + ((unsigned int)b & m))->b;
        b >>= j;
        k -= j;
        j = td->v.n;
        if (j < 16) {
            ll[i++] = l = j;
        } else if (j == 16) {
            while (k < 2) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            j = 3 + (b & 3);
            b >>= 2;
            k -= 2;
            while (j--) {
                ll[i++] = l;
            }
        } else if (j == 17) {
            while (k < 3) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            j = 3 + (b & 7);
            b >>= 3;
            k -= 3;
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        } else {
            while (k < 7) {
                if (((struct decoder *)arg0)->input_pos >= 0x1800) {
                    ((struct decoder *)arg0)->input_pos = 0;
                    func_8001311C(((struct decoder *)arg0)->input, ((struct decoder *)arg0)->offset);
                    ((struct decoder *)arg0)->offset += 0x1800;
                }
                b |= (u32)((struct decoder *)arg0)->input[((struct decoder *)arg0)->input_pos++] << k;
                k += 8;
            }
            j = 11 + (b & 127);
            b >>= 7;
            k -= 7;
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        }
    }
    ((struct decoder *)arg0)->bits = b;
    ((struct decoder *)arg0)->count = k;
    bl = 9;
    func_800E589C(ll, nl, 257, D_80123204, D_80123244, (void *)&tl, &bl, arg0);
    bd = 6;
    func_800E589C(ll + nl, nd, 0, D_80123264, D_801232A0, (void *)&td, &bd, arg0);
    ((struct decoder *)arg0)->bl = bl;
    ((struct decoder *)arg0)->bd = bd;
    ((struct decoder *)arg0)->tl = tl;
    ((struct decoder *)arg0)->td = td;
    return 0;
}

s32 func_800E659C(void *arg0) {
    extern u16 D_80123204[];
    extern u8 D_80123244[];
    extern u16 D_80123264[];
    extern u8 D_801232A0[];
    unsigned int i;
    struct huft *tl;
    struct huft *td;
    int bl;
    int bd;
    unsigned int l[288];

    for (i = 0; i < 144; i++) {
        l[i] = 8;
    }
    for (; i < 256; i++) {
        l[i] = 9;
    }
    for (; i < 280; i++) {
        l[i] = 7;
    }
    for (; i < 288; i++) {
        l[i] = 8;
    }
    bl = 7;
    func_800E589C(l, 288, 257, D_80123204, D_80123244, &tl, &bl, arg0);
    for (i = 0; i < 30; i++) {
        l[i] = 5;
    }
    bd = 5;
    func_800E589C(l, 30, 0, D_80123264, D_801232A0, &td, &bd, arg0);
    ((struct decoder *)arg0)->bl = bl;
    ((struct decoder *)arg0)->bd = bd;
    ((struct decoder *)arg0)->tl = tl;
    ((struct decoder *)arg0)->td = td;
    func_800E5390(arg0);
    return 0;
}

s32 func_800E6728(void *arg0) {
    void func_8001311C(u8 *, s32);
    struct decoder *d = arg0;
    s32 unused;
    struct { u8 *ptr; s32 padding[2]; } output;
    u8 *input;
    u32 count;
    u32 bits;
    u32 length;
    s32 output_pos;
    s32 pos;
    u32 align;

    output.ptr = d->output;
    count = d->count;
    bits = d->bits;
    output_pos = d->output_pos;
    align = count & 7;
    count -= align;
    bits >>= align;
    if (count < 16) {
        input = d->input;
        do {
            pos = d->input_pos;
            if (pos >= 0x1800) {
                d->input_pos = 0;
                func_8001311C(input, d->offset);
                pos = d->input_pos;
                d->offset += 0x1800;
                input = d->input;
            }
            bits |= input[pos] << count;
            d->input_pos = pos + 1;
            count += 8;
        } while (count < 16);
    }
    length = bits & 0xFFFF;
    bits >>= 16;
    count -= 16;
    if (count < 16) {
        input = d->input;
        do {
            pos = d->input_pos;
            if (pos >= 0x1800) {
                d->input_pos = 0;
                func_8001311C(input, d->offset);
                pos = d->input_pos;
                d->offset += 0x1800;
                input = d->input;
            }
            bits |= input[pos] << count;
            d->input_pos = pos + 1;
            count += 8;
        } while (count < 16);
    }
    bits >>= 16;
    count -= 16;
    while (length--) {
        if (count < 8) {
            input = d->input;
            do {
                pos = d->input_pos;
                if (pos >= 0x1800) {
                    d->input_pos = 0;
                    func_8001311C(input, d->offset);
                    pos = d->input_pos;
                    d->offset += 0x1800;
                    input = d->input;
                }
                bits |= input[pos] << count;
                d->input_pos = pos + 1;
                count += 8;
            } while (count < 8);
        }
        output.ptr[output_pos++] = bits;
        bits >>= 8;
        count -= 8;
    }
    d->output_pos = output_pos;
    d->bits = bits;
    d->count = count;
    return 0;
}

void func_800E692C(void) {
    void *heap_alloc(s32);
    BT_IDO_ONLY(extern void *D_8012D570;)
    D_8012D570 = heap_alloc(0x40);
}

void *func_800E6950(s32 arg0, s32 arg1, void *arg2) {
    s32 func_800D5950(s32);
    s32 func_800D5A6C(s32);
    void func_800D5FDC(s32);
    void *func_80117248(s32, s32, void *);
    void *heap_alloc_sided(s32, s32);
    s32 rom_read_word(u32 address, u32 *value);
    s32 size;
    s32 sp30;
    u32 padding;
    u32 word;
    union {
        s32 side;
        void *ptr;
    } var_s0;
    var_s0.side = arg1;
    sp30 = func_800D5A6C(arg0);
    rom_read_word(sp30, &word);
    /* Keep the copy/merge/writeback sequence for IDO register allocation. */
    do { word >>= 0x10; size = word; size = size * 0x10; } while (0);
    word = size;
    size = word == (u32)size ? word : size;
    *(u32 *)&word = size;
    func_800D5FDC(word);
    if (arg2 == NULL)
    {
        var_s0.ptr = heap_alloc_sided(size, var_s0.side);
        if (var_s0.ptr == NULL)
        {
            return NULL;
        }
    }
    else
    {
        var_s0.ptr = arg2;
    }
    func_80117248(sp30, func_800D5950(arg0), var_s0.ptr);
    osWritebackDCache(var_s0.ptr, size);
    return var_s0.ptr;
}    typedef struct { u8 unk0; } Obj1EBE020_D_801275E0; /* offsets.py genstruct: fields from raw offsets on &D_801275E0; rename once understood */

u32 func_800E6A00(void) {
    extern u8 D_801275E0;
    return BT_DATA_FIELD(D_801275D0.active, *&((Obj1EBE020_D_801275E0 *)&D_801275E0)->unk0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
#endif
