#include "common.h"

typedef struct { s16 id; s16 fields[3]; u8 value; u8 unk9; u8 ability; u8 unkB; u8 unkC; u8 padD; } EggEntry;
s32 gcegg_entrypoint_0(s32 arg0) { extern EggEntry D_80800200_gcegg[8]; EggEntry *entry = D_80800200_gcegg; u8 *end = (u8 *)&D_80800200_gcegg[8]; loop_1: if (arg0 == entry[0].id) return entry[0].value; if (arg0 == entry[1].id) return entry[1].value; if (arg0 == entry[2].id) return entry[2].value; if (arg0 == entry[3].id) return entry[3].value; entry += 4; if ((u8 *)entry != end) goto loop_1; return 0; }

s32 gcegg_entrypoint_1(s32 arg0) { extern EggEntry D_80800200_gcegg[8]; EggEntry *entry = D_80800200_gcegg; u8 *end = (u8 *)&D_80800200_gcegg[8]; loop_1: if (arg0 == entry[0].fields[1]) return entry[0].value; if (arg0 == entry[1].fields[1]) return entry[1].value; if (arg0 == entry[2].fields[1]) return entry[2].value; if (arg0 == entry[3].fields[1]) return entry[3].value; entry += 4; if ((u8 *)entry != end) goto loop_1; return 0; }

s16 gcegg_entrypoint_2(s32 arg0) {
    extern EggEntry D_80800200_gcegg[8];
    return D_80800200_gcegg[arg0].fields[0];
}

s16 gcegg_entrypoint_3(s32 arg0) {
    extern EggEntry D_80800200_gcegg[8];
    return D_80800200_gcegg[arg0].fields[2];
}

u8 gcegg_entrypoint_4(s32 arg0) {
    extern EggEntry D_80800200_gcegg[8];
    return D_80800200_gcegg[arg0].unkC;
}

u8 gcegg_entrypoint_5(s32 arg0) {
    extern EggEntry D_80800200_gcegg[8];
    return D_80800200_gcegg[arg0].unk9;
}

int gcegg_entrypoint_6(s32 arg0) {
    int func_800C6E38(s32);
    extern EggEntry D_80800200_gcegg[8];
    s32 ability = D_80800200_gcegg[arg0].ability;
    return ability == 0x3C || func_800C6E38(ability);
}
int gcegg_entrypoint_7(s32 arg0) {
    s32 func_800D3948(void);
    extern EggEntry D_80800200_gcegg[8];
    if (func_800D3948() == 0) {
        return 1;
    }
    {
        u8 result = D_80800200_gcegg[arg0].unkB;
        return result;
    }
}
#include "egg_data.inc"
