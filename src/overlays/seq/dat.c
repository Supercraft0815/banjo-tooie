#include "common.h"

s16 seqdat_entrypoint_0(s32 arg0, s32 arg1) {
    extern s16 D_80800030_seqdat[];
    if (arg1 == 0) {
        return D_80800030_seqdat[arg0];
    }
    return 0;
}
