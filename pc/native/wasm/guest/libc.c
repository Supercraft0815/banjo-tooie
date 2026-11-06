// Guest C library: memory and string functions, formatted output, host files,
// malloc on the rdram arena and libm. Output and files go through host imports.
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include "bt_guest.h"
#include "native_rdram.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "zlib.h"

void BT_HOST(write)(int fd, const void *buf, size_t n);
_Noreturn void BT_HOST(exit)(int code);
_Noreturn void BT_HOST(unported)(const char *name);
int BT_HOST(fopen)(const char *path, const char *mode);
size_t BT_HOST(fread)(int fd, void *buf, size_t n);
size_t BT_HOST(fwrite)(int fd, const void *buf, size_t n);
int BT_HOST(fseek)(int fd, long off, int whence);
long BT_HOST(ftell)(int fd);
int BT_HOST(fclose)(int fd);
int BT_HOST(inflate_raw)(const void *src, uInt src_len, void *dst, uInt dst_len, uLong *in_used, uLong *out_used);

void *memcpy(void *d, const void *s, size_t n) { return __builtin_memcpy(d, s, n); }
void *memmove(void *d, const void *s, size_t n) { return __builtin_memmove(d, s, n); }
void *memset(void *d, int c, size_t n) { return __builtin_memset(d, c, n); }

int memcmp(const void *a, const void *b, size_t n) {
    const unsigned char *x = a, *y = b;
    for (; n; n--, x++, y++) {
        if (*x != *y) return *x - *y;
    }
    return 0;
}

void *memchr(const void *p, int c, size_t n) {
    const unsigned char *s = p;
    for (; n; n--, s++) {
        if (*s == (unsigned char)c) return (void *)s;
    }
    return NULL;
}

size_t strlen(const char *s) {
    const char *e = s;
    while (*e) e++;
    return e - s;
}

int strcmp(const char *a, const char *b) {
    while (*a && *a == *b) a++, b++;
    return (unsigned char)*a - (unsigned char)*b;
}

int strncmp(const char *a, const char *b, size_t n) {
    for (; n; n--, a++, b++) {
        if (*a != *b || !*a) return (unsigned char)*a - (unsigned char)*b;
    }
    return 0;
}

char *strcpy(char *d, const char *s) {
    char *r = d;
    while ((*d++ = *s++)) {}
    return r;
}

char *strncpy(char *d, const char *s, size_t n) {
    char *r = d;
    for (; n && *s; n--) *d++ = *s++;
    for (; n; n--) *d++ = 0;
    return r;
}

char *strcat(char *d, const char *s) {
    strcpy(d + strlen(d), s);
    return d;
}

char *strchr(const char *s, int c) {
    for (;; s++) {
        if (*s == (char)c) return (char *)s;
        if (!*s) return NULL;
    }
}

char *strrchr(const char *s, int c) {
    const char *r = NULL;
    for (;; s++) {
        if (*s == (char)c) r = s;
        if (!*s) return (char *)r;
    }
}

char *strstr(const char *h, const char *n) {
    size_t k = strlen(n);
    for (; *h; h++) {
        if (!strncmp(h, n, k)) return (char *)h;
    }
    return k ? NULL : (char *)h;
}

// libultra byte routines (signed lengths).
void bcopy(const void *s, void *d, int n) { if (n > 0) memmove(d, s, n); }
void bzero(void *d, int n) { if (n > 0) memset(d, 0, n); }
int bcmp(const void *a, const void *b, int n) { return n > 0 ? memcmp(a, b, n) : 0; }

int abs(int v) { return v < 0 ? -v : v; }
long labs(long v) { return v < 0 ? -v : v; }

unsigned long strtoul(const char *s, char **end, int base) {
    unsigned long v = 0;
    while (*s == ' ' || *s == '\t') s++;
    if ((base == 0 || base == 16) && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) s += 2, base = 16;
    else if (base == 0) base = *s == '0' ? 8 : 10;
    for (;; s++) {
        int d = *s >= '0' && *s <= '9' ? *s - '0' : *s >= 'a' && *s <= 'z' ? *s - 'a' + 10
              : *s >= 'A' && *s <= 'Z' ? *s - 'A' + 10 : 99;
        if (d >= base) break;
        v = v * base + d;
    }
    if (end) *end = (char *)s;
    return v;
}

long strtol(const char *s, char **end, int base) {
    while (*s == ' ' || *s == '\t') s++;
    if (*s == '-') return -(long)strtoul(s + 1, end, base);
    return (long)strtoul(*s == '+' ? s + 1 : s, end, base);
}

int atoi(const char *s) { return (int)strtol(s, NULL, 10); }
char *getenv(const char *name) { (void)name; return NULL; }

void qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *)) {
    unsigned char *b = base;
    for (size_t i = 1; i < n; i++) { // insertion sort: the game sorts short lists only
        for (size_t j = i; j > 0 && cmp(b + (j - 1) * size, b + j * size) > 0; j--) {
            for (size_t k = 0; k < size; k++) {
                unsigned char t = b[(j - 1) * size + k];
                b[(j - 1) * size + k] = b[j * size + k];
                b[j * size + k] = t;
            }
        }
    }
}

void *malloc(size_t n) { return bt_alloc(n); }
void free(void *p) { bt_free(p); }
void *realloc(void *p, size_t n) { return bt_realloc(p, n); }
void *calloc(size_t n, size_t size) { return memset(bt_alloc(n * size), 0, n * size); }

_Noreturn void abort(void) { host_unported("abort"); }
_Noreturn void exit(int code) { host_exit(code); }
_Noreturn void bt_unported(const char *name) { host_unported(name); }

_Noreturn void bt_assert_fail(const char *expr, const char *file, int line) {
    fprintf(stderr, "assertion failed: %s (%s:%d)\n", expr, file, line);
    abort();
}

// Formatted output.
typedef struct { char *buf; size_t cap, len; } Out;

static void out_c(Out *o, char c) {
    if (o->len + 1 < o->cap) o->buf[o->len] = c;
    o->len++;
}

static void out_pad(Out *o, char c, int n) { while (n-- > 0) out_c(o, c); }

static void out_num(Out *o, unsigned long long v, int neg, int base, int upper, int width, int prec, int left, char pad, char sign) {
    char tmp[24];
    int n = 0;
    const char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    do { tmp[n++] = digits[v % base]; v /= base; } while (v);
    if (prec >= 0) pad = ' ';
    int zeros = prec > n ? prec - n : 0;
    int total = n + zeros + (neg || sign);
    if (!left && pad == ' ') out_pad(o, ' ', width - total);
    if (neg) out_c(o, '-'); else if (sign) out_c(o, sign);
    if (!left && pad == '0') out_pad(o, '0', width - total);
    out_pad(o, '0', zeros);
    while (n) out_c(o, tmp[--n]);
    if (left) out_pad(o, ' ', width - total);
}

static void out_float(Out *o, double v, int prec, int width, int left, char pad, char sign) {
    char tmp[64];
    int n = 0, neg = v < 0;
    unsigned long long ip, fp, scale = 1;
    if (prec < 0) prec = 6;
    if (prec > 9) prec = 9;
    if (neg) v = -v;
    for (int i = 0; i < prec; i++) scale *= 10;
    v = v * scale + 0.5;
    if (v > 1.8e19) v = 1.8e19;
    ip = (unsigned long long)v / scale;
    fp = (unsigned long long)v % scale;
    for (int i = 0; i < prec; i++) { tmp[n++] = '0' + fp % 10; fp /= 10; }
    if (prec) tmp[n++] = '.';
    do { tmp[n++] = '0' + ip % 10; ip /= 10; } while (ip);
    int total = n + (neg || sign);
    if (!left && pad == ' ') out_pad(o, ' ', width - total);
    if (neg) out_c(o, '-'); else if (sign) out_c(o, sign);
    if (!left && pad == '0') out_pad(o, '0', width - total);
    while (n) out_c(o, tmp[--n]);
    if (left) out_pad(o, ' ', width - total);
}

int vsnprintf(char *buf, size_t cap, const char *f, va_list ap) {
    Out o = {buf, cap, 0};
    for (; *f; f++) {
        if (*f != '%') { out_c(&o, *f); continue; }
        int left = 0, width = 0, prec = -1, lng = 0;
        char pad = ' ', sign = 0;
        for (f++;; f++) {
            if (*f == '-') left = 1;
            else if (*f == '0') pad = '0';
            else if (*f == '+') sign = '+';
            else if (*f == ' ') sign = sign ? sign : ' ';
            else if (*f == '#') {}
            else break;
        }
        if (*f == '*') { width = va_arg(ap, int); f++; }
        else while (*f >= '0' && *f <= '9') width = width * 10 + *f++ - '0';
        if (*f == '.') {
            prec = 0;
            f++;
            if (*f == '*') { prec = va_arg(ap, int); f++; }
            else while (*f >= '0' && *f <= '9') prec = prec * 10 + *f++ - '0';
        }
        while (*f == 'l' || *f == 'h' || *f == 'z' || *f == 'j' || *f == 't' || *f == 'L') {
            if (*f == 'l') lng++;
            if (*f == 'j') lng = 2;
            f++;
        }
        switch (*f) {
        case 'd': case 'i': {
            long long v = lng >= 2 ? va_arg(ap, long long) : lng ? va_arg(ap, long) : va_arg(ap, int);
            out_num(&o, v < 0 ? -(unsigned long long)v : (unsigned long long)v, v < 0, 10, 0, width, prec, left, pad, sign);
            break;
        }
        case 'u': case 'x': case 'X': case 'o': {
            unsigned long long v = lng >= 2 ? va_arg(ap, unsigned long long) : lng ? va_arg(ap, unsigned long) : va_arg(ap, unsigned);
            out_num(&o, v, 0, *f == 'o' ? 8 : *f == 'u' ? 10 : 16, *f == 'X', width, prec, left, pad, 0);
            break;
        }
        case 'p':
            out_c(&o, '0'); out_c(&o, 'x');
            out_num(&o, (uintptr_t)va_arg(ap, void *), 0, 16, 0, 8, -1, 0, '0', 0);
            break;
        case 'c': out_pad(&o, ' ', left ? 0 : width - 1); out_c(&o, (char)va_arg(ap, int)); if (left) out_pad(&o, ' ', width - 1); break;
        case 's': {
            const char *s = va_arg(ap, const char *);
            int n;
            if (!s) s = "(null)";
            n = (int)strlen(s);
            if (prec >= 0 && n > prec) n = prec;
            if (!left) out_pad(&o, ' ', width - n);
            for (int i = 0; i < n; i++) out_c(&o, s[i]);
            if (left) out_pad(&o, ' ', width - n);
            break;
        }
        case 'f': case 'F': case 'e': case 'g': case 'G': case 'E':
            // shortcut: %e/%g print as %f; only diagnostics use them.
            out_float(&o, va_arg(ap, double), prec, width, left, pad, sign);
            break;
        case '%': out_c(&o, '%'); break;
        case 0: f--; break;
        default: out_c(&o, '%'); out_c(&o, *f); break;
        }
    }
    if (cap) buf[o.len < cap ? o.len : cap - 1] = 0;
    return (int)o.len;
}

int snprintf(char *buf, size_t cap, const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    int n = vsnprintf(buf, cap, f, ap);
    va_end(ap);
    return n;
}

int sprintf(char *buf, const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    int n = vsnprintf(buf, (size_t)-1 >> 1, f, ap);
    va_end(ap);
    return n;
}

// FILE is the host file number plus one (0 = no file); stdout and stderr are 1 and 2.
struct FILE { int fd; };
static FILE std_files[3] = {{0}, {1}, {2}};
FILE *stdin = &std_files[0], *stdout = &std_files[1], *stderr = &std_files[2];
static FILE files[16];

int vfprintf(FILE *fp, const char *f, va_list ap) {
    char buf[1024];
    int n = vsnprintf(buf, sizeof(buf), f, ap);
    host_write(fp->fd, buf, n < (int)sizeof(buf) ? (size_t)n : sizeof(buf) - 1);
    return n;
}

int fprintf(FILE *fp, const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    int n = vfprintf(fp, f, ap);
    va_end(ap);
    return n;
}

int printf(const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    int n = vfprintf(stdout, f, ap);
    va_end(ap);
    return n;
}

void osSyncPrintf(const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    vfprintf(stderr, f, ap);
    va_end(ap);
}

int fputs(const char *s, FILE *fp) { host_write(fp->fd, s, strlen(s)); return 0; }
int puts(const char *s) { fputs(s, stdout); return fputs("\n", stdout); }
int fputc(int c, FILE *fp) { char b = (char)c; host_write(fp->fd, &b, 1); return c; }
int putchar(int c) { return fputc(c, stdout); }
int fflush(FILE *fp) { (void)fp; return 0; }
void perror(const char *s) { fprintf(stderr, "%s: error\n", s); }

FILE *fopen(const char *path, const char *mode) {
    int fd = host_fopen(path, mode);
    if (fd < 0) return NULL;
    for (int i = 0; i < 16; i++) {
        if (!files[i].fd) { files[i].fd = fd; return &files[i]; }
    }
    host_fclose(fd);
    return NULL;
}

size_t fread(void *p, size_t size, size_t n, FILE *fp) { return size ? host_fread(fp->fd, p, size * n) / size : 0; }
size_t fwrite(const void *p, size_t size, size_t n, FILE *fp) { return size ? host_fwrite(fp->fd, p, size * n) / size : 0; }
int fseek(FILE *fp, long off, int whence) { return host_fseek(fp->fd, off, whence); }
long ftell(FILE *fp) { return host_ftell(fp->fd); }
int fclose(FILE *fp) { int r = host_fclose(fp->fd); fp->fd = 0; return r; }

// zlib subset: one raw-deflate call with Z_FINISH.
int inflateInit2(z_stream *z, int window_bits) { z->window_bits = window_bits; z->total_in = z->total_out = 0; return Z_OK; }
int inflateEnd(z_stream *z) { (void)z; return Z_OK; }

int inflate(z_stream *z, int flush) {
    uLong in = 0, out = 0;
    int r;
    if (flush != Z_FINISH || z->window_bits != -15) return Z_STREAM_ERROR;
    r = host_inflate_raw(z->next_in, z->avail_in, z->next_out, z->avail_out, &in, &out);
    z->next_in += in; z->avail_in -= in; z->total_in += in;
    z->next_out += out; z->avail_out -= out; z->total_out += out;
    return r;
}

// libm: wasm instructions where they exist, the host's libm otherwise.
float sqrtf(float x) { return __builtin_sqrtf(x); }
double sqrt(double x) { return __builtin_sqrt(x); }
float fabsf(float x) { return __builtin_fabsf(x); }
double fabs(double x) { return __builtin_fabs(x); }
float floorf(float x) { return __builtin_floorf(x); }
double floor(double x) { return __builtin_floor(x); }
float ceilf(float x) { return __builtin_ceilf(x); }
double ceil(double x) { return __builtin_ceil(x); }
float truncf(float x) { return __builtin_truncf(x); }
double trunc(double x) { return __builtin_trunc(x); }
float fminf(float a, float b) { return __builtin_fminf(a, b); }
float fmaxf(float a, float b) { return __builtin_fmaxf(a, b); }
float copysignf(float a, float b) { return __builtin_copysignf(a, b); }
float roundf(float x) { return x < 0 ? -__builtin_floorf(-x + 0.5f) : __builtin_floorf(x + 0.5f); }
double round(double x) { return x < 0 ? -__builtin_floor(-x + 0.5) : __builtin_floor(x + 0.5); }

#define LIBM1(name, T) T BT_HOST(name)(T); T name(T x) { return host_##name(x); }
#define LIBM2(name, T) T BT_HOST(name)(T, T); T name(T x, T y) { return host_##name(x, y); }
LIBM1(tanf, float) LIBM1(asinf, float) LIBM1(acosf, float) LIBM1(atanf, float)
LIBM2(atan2f, float) LIBM2(powf, float) LIBM1(expf, float) LIBM1(logf, float) LIBM2(fmodf, float)
LIBM1(sin, double) LIBM1(cos, double) LIBM1(tan, double) LIBM1(asin, double) LIBM1(acos, double)
LIBM1(atan, double) LIBM2(atan2, double) LIBM2(pow, double) LIBM1(exp, double) LIBM1(log, double)
LIBM2(fmod, double)

// libultra's sinf/cosf use this quiet NaN (libm_vals.s).
const unsigned int __libm_qnan_f = 0x7F810000;
