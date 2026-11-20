#include "common.h"
BT_NATIVE_ONLY(typedef void (*GlobalSaveChunk)(s32 *, u8 **);)
void glglobaldata_entrypoint_0(void) {
    BT_NATIVE_ONLY(extern GlobalSaveChunk D_80800230_glglobaldata[2];) BT_IDO_ONLY(extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);)
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 size[3];
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) data;
    BT_NATIVE_ONLY(GlobalSaveChunk *entry;) BT_IDO_ONLY(void (**entry)(s32 *, s32 *);)
    s32 total = 1;

    entry = D_80800230_glglobaldata; do {
        (*entry)(size, &data);
        total += size[0];
        entry++;
    } while (entry != BT_DATA_FIELD(D_80800230_glglobaldata + ARRLEN(D_80800230_glglobaldata), D_80800238_glglobaldata));
}

s32 glglobaldata_entrypoint_1(u8 *arg0) {
    return *arg0 == 8;
}

void glglobaldata_entrypoint_2(u8 *arg0) {
    void rare_memcpy(void *, void *, int);
    BT_NATIVE_ONLY(extern GlobalSaveChunk D_80800230_glglobaldata[2];) BT_IDO_ONLY(extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);)
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 size[3];
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) data;
    BT_NATIVE_ONLY(GlobalSaveChunk *entry;) BT_IDO_ONLY(void (**entry)(s32 *, s32 *);)
    s32 offset = 1;

    entry = D_80800230_glglobaldata; do {
        (*entry)(size, &data);
        rare_memcpy((void *)data, arg0 + offset, size[0]);
        entry++;
        offset += size[0];
    } while (entry != BT_DATA_FIELD(D_80800230_glglobaldata + ARRLEN(D_80800230_glglobaldata), D_80800238_glglobaldata));
}

void func_80800124_glglobaldata(u8 *arg0, s32 *arg1) { arg0[*arg1] = 8; *arg1 += 1; }

void glglobaldata_entrypoint_3(u8 *arg0) {
    u32 _glcrc_entrypoint_0(BtIntPtr arg0, BtIntPtr arg1);
    void glglobaldata_entrypoint_4(u8 *);
    void rare_memcpy(void *, void *, int);
    BT_NATIVE_ONLY(extern GlobalSaveChunk D_80800230_glglobaldata[2];) BT_IDO_ONLY(extern void (*D_80800230_glglobaldata[])(s32 *, s32 *);)
    extern void (*D_80800238_glglobaldata[])(s32 *, s32 *);
    s32 padding;
    s32 offset;
    s32 size;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32) data;
    BT_NATIVE_ONLY(GlobalSaveChunk *entry;) BT_IDO_ONLY(void (**entry)(s32 *, s32 *);)

    glglobaldata_entrypoint_4(arg0);
    offset = 0;
    func_80800124_glglobaldata(arg0, &offset);
    entry = D_80800230_glglobaldata; do {
        (*entry)(&size, &data);
        rare_memcpy(arg0 + offset, (void *)data, size);
        entry++;
        offset += size;
    } while (entry != BT_DATA_FIELD(D_80800230_glglobaldata + ARRLEN(D_80800230_glglobaldata), D_80800238_glglobaldata));
    _glcrc_entrypoint_0((s32 *)arg0, 0x80);
}

void glglobaldata_entrypoint_4(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        arg0[i] = 0;
    }
}
/* data_to_c.py: from asm/data/overlays/gl/obaldata.data.s */
void func_800DABF0(BT_PASS2(s32 *size, u8 **data));
void func_800D21B0(BT_PASS2(s32 *size, u8 **data));
BT_NATIVE_ONLY(GlobalSaveChunk D_80800230_glglobaldata[2]) BT_IDO_ONLY(void ( * D_80800230_glglobaldata [2] ) ( s32 * , s32 * )) BT_DATA(4, overlays_gl_obaldata, 0x0) = { BT_IDO_ONLY((void (*)(long *, long *)))func_800DABF0, BT_IDO_ONLY((void (*)(long *, long *)))func_800D21B0 };
void ( * D_80800238_glglobaldata [2] ) ( s32 * , s32 * ) BT_DATA(4, overlays_gl_obaldata, 0x8) = { 0, 0 };
