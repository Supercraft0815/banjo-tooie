// One-shot raw inflate for the guest: inflate(Z_FINISH) runs on the host's zlib.
#ifndef BT_GUEST_ZLIB_H
#define BT_GUEST_ZLIB_H
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_DATA_ERROR (-3)
#define Z_BUF_ERROR (-5)
#define Z_STREAM_ERROR (-2)
#define Z_FINISH 4
typedef unsigned long uLong;
typedef unsigned int uInt;
typedef unsigned char Bytef;
typedef struct z_stream_s {
    const Bytef *next_in;
    uInt avail_in;
    uLong total_in;
    Bytef *next_out;
    uInt avail_out;
    uLong total_out;
    int window_bits;
} z_stream;
int inflateInit2(z_stream *, int window_bits);
int inflate(z_stream *, int flush);
int inflateEnd(z_stream *);
#endif
