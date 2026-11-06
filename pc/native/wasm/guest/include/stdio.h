#ifndef BT_GUEST_STDIO_H
#define BT_GUEST_STDIO_H
#include <stdarg.h>
#include <stddef.h>
typedef struct FILE FILE;
extern FILE *stdin, *stdout, *stderr;
#define EOF (-1)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
int printf(const char *, ...);
int fprintf(FILE *, const char *, ...);
int sprintf(char *, const char *, ...);
int snprintf(char *, size_t, const char *, ...);
int vsnprintf(char *, size_t, const char *, va_list);
int vfprintf(FILE *, const char *, va_list);
int fputs(const char *, FILE *);
int puts(const char *);
int fputc(int, FILE *);
int putchar(int);
int fflush(FILE *);
FILE *fopen(const char *, const char *);
size_t fread(void *, size_t, size_t, FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int fseek(FILE *, long, int);
long ftell(FILE *);
int fclose(FILE *);
void perror(const char *);
#endif
