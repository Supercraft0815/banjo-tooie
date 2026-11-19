#include "common.h"
#include "inflate_tables.inc"
typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E4730_D_8012D56C; /* offsets.py genstruct: fields from raw offsets on D_8012D56C; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E4730_D_8012D564; /* offsets.py genstruct: fields from raw offsets on D_8012D564; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E4730_D_8012D560; /* offsets.py genstruct: fields from raw offsets on D_8012D560; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E4730_D_8012D568; /* offsets.py genstruct: fields from raw offsets on D_8012D568; rename once understood */ s32 func_800E4730(s32 arg0) {
    extern void *D_8012D560;
    extern void *D_8012D564;
    extern void *D_8012D568;
    extern void *D_8012D56C;
    if ((D_8012D560 != NULL) && (arg0 == (((Obj1EBE020_func_800E4730_D_8012D560 *)D_8012D560)->unk3A))) {
        return 0;
    }
    if ((D_8012D564 != NULL) && (arg0 == (((Obj1EBE020_func_800E4730_D_8012D564 *)D_8012D564)->unk3A))) {
        return 1;
    }
    if ((D_8012D568 != NULL) && (arg0 == (((Obj1EBE020_func_800E4730_D_8012D568 *)D_8012D568)->unk3A))) {
        return 2;
    }
    if ((D_8012D56C != NULL) && (arg0 == (((Obj1EBE020_func_800E4730_D_8012D56C *)D_8012D56C)->unk3A))) {
        return 3;
    }
    return -1;
}    typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E47CC_D_8012D56C; /* offsets.py genstruct: fields from raw offsets on D_8012D56C; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E47CC_D_8012D564; /* offsets.py genstruct: fields from raw offsets on D_8012D564; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E47CC_D_8012D560; /* offsets.py genstruct: fields from raw offsets on D_8012D560; rename once understood */ typedef struct { u8 pad0[0x3A]; s16 unk3A; } Obj1EBE020_func_800E47CC_D_8012D568; /* offsets.py genstruct: fields from raw offsets on D_8012D568; rename once understood */

s32 func_800E47CC(void) {
    extern void *D_8012D560;
    extern void *D_8012D564;
    extern void *D_8012D568;
    extern void *D_8012D56C;
    if (D_8012D560 == NULL) {
        return 0;
    }
    if ((((Obj1EBE020_func_800E47CC_D_8012D560 *)D_8012D560)->unk3A) == -1) {
        return 0;
    }
    if (D_8012D564 == NULL) {
        return 1;
    }
    if ((((Obj1EBE020_func_800E47CC_D_8012D564 *)D_8012D564)->unk3A) == -1) {
        return 1;
    }
    if (D_8012D568 == NULL) {
        return 2;
    }
    if ((((Obj1EBE020_func_800E47CC_D_8012D568 *)D_8012D568)->unk3A) == -1) {
        return 2;
    }
    if (D_8012D56C == NULL) {
        return 3;
    }
    if ((((Obj1EBE020_func_800E47CC_D_8012D56C *)D_8012D56C)->unk3A) == -1) {
        return 3;
    }
    return -1;
}

s32 func_800E488C(s32 arg0) {
    extern void *D_8012D560;
    BtIntPtr heap_alloc(s32);
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
    u8 *state;
    s32 size;
    s32 status;
    u32 result;

    index = func_800E4730(arg0);
    if (index == -1) {
        index = func_800E47CC();
        if (index < 0) return 0;
        (&D_8012D560)[index] = heap_alloc(0x40);
        *((u8 *)(&D_8012D560)[index] + 0x38) = 1;
        *(s16 *)((u8 *)(&D_8012D560)[index] + 0x3A) = arg0;
        *(s16 *)((u8 *)(&D_8012D560)[index] + 0x3C) = 2500;
    }
    state = (&D_8012D560)[index];
    if (state[0x38] == 0) return 1;
    switch (state[0x38]) {
    case 1:
        *(void **)(state + 0x34) = NULL;
        *(s32 *)(state + 0xC) = 0;
        *(s32 *)(state + 0x10) = 0;
        *(s32 *)(state + 0x14) = 0;
        *(void **)(state + 0x28) = heap_alloc(0x2800);
        *(s32 *)(state + 0x30) = func_800D5A6C(*(s16 *)(state + 0x3A));
        *(void **)state = heap_alloc(0x1800);
        func_8001311C(*(u8 **)state, *(s32 *)(state + 0x30));
        *(s32 *)(state + 0x30) += 0x1800;
        size = **(u32 **)state;
        size = (u32)size >> 16;
        size *= 16;
        *(s32 *)(state + 4) = 2;
        *(void **)(state + 0x34) = heap_alloc(size);
        if (*(void **)(state + 0x34) == NULL) {
            func_800E4B1C(index);
            return 0;
        }
        *(void **)(state + 8) = *(void **)(state + 0x34);
        state[0x38] = 2;
        return 0;
    case 2:
        *(s32 *)(state + 0x2C) = 0;
        result = 0;
        status = func_800E4D28(state);
        switch (status) {
        case 2:
            do {
                func_800E5EC0((void *)state);
            } while (++result < 0);
            state[0x38] = 3;
            break;
        case 0:
            func_800E6728(state);
            state[0x38] = 4;
            return 0;
        case 1:
            func_800E659C(state);
            state[0x38] = 4;
            break;
        }
        return 0;
    case 3:
        if (func_800E4E54(state) == 0) state[0x38] = 4;
        return 0;
    case 4:
        if (state[0x39]) {
            if (*(void **)(state + 0x28) != NULL) {
                heap_free(*(void **)(state + 0x28));
                *(void **)(state + 0x28) = NULL;
            }
            if (*(void **)state != NULL) {
                heap_free(*(void **)state);
                *(void **)state = NULL;
            }
            state[0x38] = 0;
            osWritebackDCache(*(void **)(state + 0x34), *(s32 *)(state + 0x14));
            return 1;
        } else {
            state[0x38] = 2;
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
    if (((s32 (*)())func_800E4730)() < 0) {
#else
    if (func_800E4730() < 0) {
#endif
        return 0;
    }
    return 1;
}

s32 func_800E4B1C(s32 arg0) {
    void heap_free(void *);
    extern void *D_8012D560;
    if ((&D_8012D560)[arg0] != NULL) {
        if (*(void **)((s8 *)(&D_8012D560)[arg0] + 0x34) != NULL) {
            heap_free(*(void **)((s8 *)(&D_8012D560)[arg0] + 0x34));
        }
        if (*(void **)(&D_8012D560)[arg0] != NULL) {
            heap_free(*(void **)(&D_8012D560)[arg0]);
        }
        if (*(void **)((s8 *)(&D_8012D560)[arg0] + 0x28) != NULL) {
            heap_free(*(void **)((s8 *)(&D_8012D560)[arg0] + 0x28));
        }
        heap_free((&D_8012D560)[arg0]);
        (&D_8012D560)[arg0] = NULL;
    }
    BT_NATIVE_ONLY(return 0;) }

/* extern */

s32 func_800E4BB8(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 func_800E4730();
    s32 func_800E4B1C(s32);
    s32 temp_v0;

#ifdef BT_NATIVE
    temp_v0 = ((s32 (*)())func_800E4730)();
#else
    temp_v0 = func_800E4730();
#endif
    if (temp_v0 < 0) {
        return 0;
    }
    func_800E4B1C(temp_v0);
    return 1;
}    typedef struct { u8 pad0[0x34]; s32 unk34; } Obj1EBE020_func_800E4BF4_temp_a0; /* offsets.py genstruct: fields from raw offsets on temp_a0; rename once understood */

s32 func_800E4BF4(s32 arg0) {
    s32 func_800E488C(s32);
    void heap_free(void *);
    extern void *D_8012D560;
    s32 sp24;
    s32 sp20;
    s32 temp_v0;
    void **temp_s0;
    void *temp_a0;

    temp_v0 = func_800E4730(arg0);
    sp24 = temp_v0;
    if (temp_v0 == -1) {
        return 0;
    }
    if (func_800E488C(arg0) == 0) {
        do {

        } while (func_800E488C(arg0) == 0);
    }
    temp_s0 = &(&D_8012D560)[sp24];
    temp_a0 = *temp_s0;
    sp20 = (((Obj1EBE020_func_800E4BF4_temp_a0 *)temp_a0)->unk34);
    heap_free(temp_a0);
    *temp_s0 = NULL;
    return sp20;
}

void func_800E4C7C(void) { extern void *D_8012D560; extern long D_8012D570; extern void *defrag(void *);  void **p;
p=&D_8012D560; do { if(*p) *p=defrag(*p); p++; } while(p!=(void **)(unsigned long)&D_8012D570); D_8012D570=(long)defrag((void *)D_8012D570); }


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
    struct decoder {
        u8 *input;
        s32 input_pos;
        u8 *output;
        u32 bits;
        u32 count;
        s32 unused14[7];
        s32 offset;
        s32 unused34;
        u8 unused38;
        u8 final;
    };
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
    struct code {
        u8 e;
        u8 b;
        union {
            u16 n;
            struct code *t;
        } v;
    };
    struct decoder {
        u8 *input;
        s32 input_pos;
        u8 *output;
        u32 bits;
        u32 count;
        u32 output_pos;
        struct code *tl;
        struct code *td;
        s32 bl;
        s32 bd;
        s32 unused28;
        s32 unused2c;
        s32 offset;
        s32 unused34;
        s32 unused38;
        s16 limit;
    };
    void func_8001311C(u8 *, s32);
    extern u16 D_801232C0[];
    register unsigned int e;
    struct code *t;
    register u32 b;
    register unsigned int k;
    u32 ml;
    u32 md;
    s32 counter = 0;
    struct code *tl;
    struct code *td;
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
    struct code {
        u8 e;
        u8 b;
        union {
            u16 n;
            struct code *t;
        } v;
    };
    struct decoder {
        u8 *input;
        s32 input_pos;
        u8 *output;
        u32 bits;
        u32 count;
        u32 output_pos;
        struct code *tl;
        struct code *td;
        s32 bl;
        s32 bd;
        s32 unused28;
        s32 unused2c;
        s32 offset;
    };
    void func_8001311C(u8 *, s32);
    extern u16 D_801232C0[];
    register unsigned int e;
    struct code *t;
    register u32 b;
    register unsigned int k;
    u32 ml;
    u32 md;
    u8 *slide = ((struct decoder *)arg0)->output;
    struct code *tl = ((struct decoder *)arg0)->tl;
    struct code *td = ((struct decoder *)arg0)->td;
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

int func_800E5EC0(struct workspace *arg0) {
    struct code {
        u8 e;
        u8 b;
        union {
            u16 n;
            struct code *t;
        } v;
    };
    struct decoder {
        u8 *input;
        s32 input_pos;
        u8 *output;
        u32 bits;
        unsigned int count;
        unsigned int output_pos;
        struct code *tl;
        struct code *td;
        int bl;
        int bd;
        struct code *tables;
        s32 used;
        s32 offset;
    };
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
    struct code *tl;
    struct code *td;
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
}    typedef struct { u8 pad0[0x18]; struct huft * unk18; struct huft * unk1C; } Obj1EBE020_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

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
    *(int *)((u8 *)arg0 + 0x20) = bl;
    *(int *)((u8 *)arg0 + 0x24) = bd;
    ((Obj1EBE020_arg0 *)arg0)->unk18 = tl;
    ((Obj1EBE020_arg0 *)arg0)->unk1C = td;
    func_800E5390(arg0);
    return 0;
}

s32 func_800E6728(void *arg0) {
    struct decoder {
        u8 *input;
        s32 input_pos;
        u8 *output;
        u32 bits;
        u32 count;
        s32 output_pos;
        s32 unused18[6];
        s32 offset;
    };
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
    BtIntPtr heap_alloc(s32);
#ifdef BT_NATIVE
    extern long D_8012D570; // same type as in func_800E4C7C
#else
    extern s32 D_8012D570;
#endif
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
    return *&((Obj1EBE020_D_801275E0 *)&D_801275E0)->unk0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
void * D_8012D560 BT_DATA(4, bss_core2bss2_1, 0xC20);
void * D_8012D564 BT_DATA(4, bss_core2bss2_1, 0xC24);
void * D_8012D568 BT_DATA(4, bss_core2bss2_1, 0xC28);
void * D_8012D56C BT_DATA(4, bss_core2bss2_1, 0xC2C);
long D_8012D570 BT_DATA(4, bss_core2bss2_1, 0xC30);
#endif
