#include "common.h"

s32 func_80800000_glgamedata() 
{
    return 0x2;
}

void func_80800008_glgamedata(s8 *arg0) {
    *arg0 = 0x1E;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_0.s")

s32 func_80800084_glgamedata(s32 *arg0) {
    *arg0 = 0x4B484A43;
    return 4;
}

void func_80800098_glgamedata(u8 *arg0, s32 *arg1, u8 arg2) {
    typedef s32 (*GameDataCallback)(void);
    typedef struct {
        GameDataCallback getSize;
        GameDataCallback unknown;
        void (*write)(u8 *, s32, u32, s32 *);
    } GameDataEntry;
    extern GameDataEntry D_808004F0_glgamedata[];
    s32 size;
    u8 *data;

    arg2 = arg2;
    if (D_808004F0_glgamedata[arg2].getSize != NULL) {
        size = D_808004F0_glgamedata[arg2].getSize();
    } else {
        size = 0;
    }
    data = *arg1 + arg0;
    data[0] = arg2;
    data[1] = size;
    data += 2;
    if (D_808004F0_glgamedata[arg2].write != NULL) {
        D_808004F0_glgamedata[arg2].write(data, size, arg2, arg1);
    }
    *arg1 = *arg1 + size + 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_1.s")

s32 func_808001E4_glgamedata(s32 arg0) {
    return 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/func_808001F0_glgamedata.s")

/* extern */

void glgamedata_entrypoint_2(s32 arg0) {
    s32 func_808001F0_glgamedata(s32, s32 *);
    s32 sp24;

    sp24 = func_808001E4_glgamedata(arg0);
    if (func_808001F0_glgamedata(arg0, &sp24) != 0) {
        do {

        } while (func_808001F0_glgamedata(arg0, &sp24) != 0);
    }
}

s32 func_808002CC_glgamedata(s32 *arg0) {
    s32 result;

    if (*arg0 == 0x4B484A43) {
        result = 4;
    } else {
        result = 0;
    }
    return result;
}

/* extern */

s32 glgamedata_entrypoint_3(u8 *arg0, s32 arg1, s32 *arg2, u32 *arg3) {
    s32 temp_v0;
    u8 temp_a0;
    u8 *temp_v0_2;

    temp_v0 = func_808002CC_glgamedata((s32 *)arg0);
    *arg2 = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
loop_3:
    temp_v0_2 = arg0 + *arg2;
    temp_a0 = *temp_v0_2++;
    *arg3 = *temp_v0_2;
    *arg2 += 2;
    if (temp_a0 == (u8)arg1) {
        return 1;
    }
    *arg2 += *arg3;
    if (temp_a0 == 0) {
        return 0;
    }
    goto loop_3;
}

 s32 glgamedata_entrypoint_4(u8 *arg0) {
    extern s32 glgamedata_entrypoint_3(u8 *, s32, s32 *, u32 *);
    s32 sp1C;
    u32 sp18;

    if (glgamedata_entrypoint_3(arg0, 1, &sp1C, &sp18)) {
        return arg0[sp1C] == 0x1E;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_5.s")

void glgamedata_entrypoint_6(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x1C0; i++) {
        arg0[i] = 0;
    }
}
