#include "common.h"

void glglobaldata_entrypoint_0(void) {
    extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 size[3];
    s32 data;
    void (**entry)(s32 *, s32 *);
    s32 total = 1;

    entry = D_80800230_glglobaldata; do {
        (*entry)(size, &data);
        total += size[0];
        entry++;
    } while (entry != D_80800238_glglobaldata);
}

s32 glglobaldata_entrypoint_1(u8 *arg0) {
    return *arg0 == 8;
}

void glglobaldata_entrypoint_2(u8 *arg0) {
    void rare_memcpy(void *, void *, int);
    extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 size[3];
    s32 data;
    void (**entry)(s32 *, s32 *);
    s32 offset = 1;

    entry = D_80800230_glglobaldata; do {
        (*entry)(size, &data);
        rare_memcpy((void *)data, arg0 + offset, size[0]);
        entry++;
        offset += size[0];
    } while (entry != D_80800238_glglobaldata);
}

void func_80800124_glglobaldata(u8 *arg0, s32 *arg1) { arg0[*arg1] = 8; *arg1 += 1; }

void glglobaldata_entrypoint_3(u8 *arg0) {
    s32 _glcrc_entrypoint_0(s32 *, s32);
    void glglobaldata_entrypoint_4(u8 *);
    void rare_memcpy(void *, void *, int);
    extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 padding;
    s32 offset;
    s32 size;
    s32 data;
    void (**entry)(s32 *, s32 *);

    glglobaldata_entrypoint_4(arg0);
    offset = 0;
    func_80800124_glglobaldata(arg0, &offset);
    entry = D_80800230_glglobaldata; do {
        (*entry)(&size, &data);
        rare_memcpy(arg0 + offset, (void *)data, size);
        entry++;
        offset += size;
    } while (entry != D_80800238_glglobaldata);
    _glcrc_entrypoint_0((s32 *)arg0, 0x80);
}

void glglobaldata_entrypoint_4(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        arg0[i] = 0;
    }
}
