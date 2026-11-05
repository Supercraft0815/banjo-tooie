#ifndef BT_NATIVE_GSFILE_H
#define BT_NATIVE_GSFILE_H
#include "types.h"

typedef struct {
    u8 *asset_base_ptr, *asset_current_ptr, *base_ptr, *current_ptr, *end_ptr;
    s32 mode, last_expected, unk1C;
    s16 asset_id, pad22;
    int failed; /* Sticky I/O error: parsing loops must stop when set. */
} GsFile;

void gsmaker_entrypoint_0(void *);
GsFile *gsmaker_entrypoint_1(s32);
GsFile *gsmaker_entrypoint_2(s32);
GsFile *gsmaker_entrypoint_3(s32, s32);
GsFile *gsmaker_entrypoint_4(void *, s32);
GsFile *gsmaker_entrypoint_5(void);
void gsmaker_entrypoint_6(GsFile *, void **, s32 *);
void gsmaker_entrypoint_7(GsFile *, void *);
void gsmaker_entrypoint_8(GsFile *, void *, s32);
void gsmaker_entrypoint_9(GsFile *, void *);
void gsmaker_entrypoint_10(GsFile *, void *, s32);
void gsmaker_entrypoint_11(GsFile *, void *);
void gsmaker_entrypoint_12(GsFile *, void *, s32);
void gsmaker_entrypoint_13(GsFile *, void *, s32);
void gsmaker_entrypoint_14(GsFile *, void *);
void gsmaker_entrypoint_15(GsFile *, void *, s32);
s32 gsmaker_entrypoint_16(GsFile *, s32);
s32 gsmaker_entrypoint_17(GsFile *, s32, void *);
s32 gsmaker_entrypoint_18(GsFile *, s32, void *, s32);
s32 gsmaker_entrypoint_19(GsFile *, s32, void *);
s32 gsmaker_entrypoint_20(GsFile *, s32, void *, s32);
s32 gsmaker_entrypoint_21(GsFile *, s32, void *);
s32 gsmaker_entrypoint_22(GsFile *, s32, void *, s32);
s32 gsmaker_entrypoint_23(GsFile *, s32, void *, s32);
s32 gsmaker_entrypoint_24(GsFile *, s32, void *);
s32 gsmaker_entrypoint_25(GsFile *, s32, void *, s32);
#endif
