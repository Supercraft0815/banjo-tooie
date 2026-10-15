#include "common.h"

s32 func_80800000_chmole_overworld(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sumole_entrypoint_3();
    void func_800D175C(s32, s32);
    s32 func_800D1A04(s32);
    u32 func_800D1A6C(u32);
    extern s32 D_80800190_chmole_overworld;
    extern s32 D_808001E0_chmole_overworld[];
    s32 sp20[2];
    s32 result;

    if (arg1 == 0x2F) {
        if (((s16 *)&arg2)[1] == 3) {
            sp20[0] = func_800D1A6C(D_808001E0_chmole_overworld[(s32)arg0->unk54]);
            func_800D175C(D_808001E0_chmole_overworld[(s32)arg0->unk54], sp20[0] - func_800D1A04(D_808001E0_chmole_overworld[(s32)arg0->unk54]));
            result = 1;
        } else {
            return _sumole_entrypoint_3(arg0, arg1, arg2, &D_80800190_chmole_overworld);
        }
    } else {
        return _sumole_entrypoint_3(arg0, arg1, arg2, &D_80800190_chmole_overworld);
    }
    return result;
}

void func_808000F4_chmole_overworld(Actor* arg0) 
{
    _sumole_entrypoint_0(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->unk54 = arg0->unk74_7;
}
void func_80800160_chmole_overworld(s32 *arg0) {
    s32 _sumole_entrypoint_4();
    extern s32 D_80800190_chmole_overworld;
    _sumole_entrypoint_4(arg0, &D_80800190_chmole_overworld);
}

OSThread *chmole_overworld_entrypoint_0(void)
{
    extern u8 D_808001F0_chmole_overworld[];

    return (OSThread *) D_808001F0_chmole_overworld;
}
