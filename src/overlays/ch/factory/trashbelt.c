#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/trashbelt/func_80800000_chfactorytrashbelt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/trashbelt/func_808001EC_chfactorytrashbelt.s")

s32 func_8080041C_chfactorytrashbelt(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_800DF660(s32, s32, s32, s32);
    void func_800DF720(s32);
    void func_800DF818(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80100A74(s16, s32);
    s32 func_80100AC4(s16);
    s16 func_80100D24(s32, s32, s32, s32, s32, s32);
    void func_80100E18(s16);
    struct { s32 index; s16 handles[7]; } *data;
    s32 i;
    s32 j;
    s32 k;
    s32 value;
    s16 handle;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x95:
        for (i = 0; i < 7; i++) {
            data->handles[i] = 0;
        }
        break;
    case 0x29:
        value = *(s32 *)&arg2;
        for (j = 0; j < 7; j++) {
            data->handles[j] = func_80100D24(value, arg0->unk0->unk14, 1, 1, arg0->unk0->unk16, 0);
        }
        break;
    case 0x2A:
        for (k = 0; k < 7; k++) {
            if (data->handles[k] != 0) {
                func_80100E18(data->handles[k]);
                data->handles[k] = 0;
            }
        }
        break;
    case 0x1F:
        handle = data->handles[data->index];
        func_800DF818(func_80100A74(handle, 0));
        func_800DF660(2, -2, 0, arg0->alpha);
        func_800DF720(func_80100AC4(handle));
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chfactorytrashbelt_entrypoint_0(void)
{
    extern u8 D_808005EC_chfactorytrashbelt[];

    return (OSThread *) D_808005EC_chfactorytrashbelt;
}
