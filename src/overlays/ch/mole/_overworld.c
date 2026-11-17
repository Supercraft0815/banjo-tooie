#include "common.h"

s32 func_80800000_chmole_overworld(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sumole_entrypoint_3();
    void func_800D175C(s32, s32);
    s32 func_800D1A04(s32);
    u32 func_800D1A6C(u32);
    extern s32 D_80800190_chmole_overworld[20];
    extern s32 D_808001E0_chmole_overworld[];
    s32 sp20[2];
    s32 result;

    if (arg1 == 0x2F) {
        if (((s16 *)&arg2)[1] == 3) {
            sp20[0] = func_800D1A6C(D_808001E0_chmole_overworld[(s32)arg0->unk54]);
            func_800D175C(D_808001E0_chmole_overworld[(s32)arg0->unk54], sp20[0] - func_800D1A04(D_808001E0_chmole_overworld[(s32)arg0->unk54]));
            result = 1;
        } else {
            return _sumole_entrypoint_3(arg0, arg1, arg2, D_80800190_chmole_overworld);
        }
    } else {
        return _sumole_entrypoint_3(arg0, arg1, arg2, D_80800190_chmole_overworld);
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
    void _sumole_entrypoint_4(void *arg0, void *arg1);
    extern s32 D_80800190_chmole_overworld[20];
    _sumole_entrypoint_4(arg0, D_80800190_chmole_overworld);
}

OSThread *chmole_overworld_entrypoint_0(void)
{
    extern ActorData D_808001F0_chmole_overworld[];

    return (OSThread *) D_808001F0_chmole_overworld;
}
/* data_to_c.py: from asm/data/overlays/ch/mole/_overworld.data.s */
void func_8010A730();
void func_80107C2C();
s32 D_80800190_chmole_overworld[20] BT_DATA(4, overlays_ch_mole__overworld, 0x0) = { 1, 230165931, 229387519, 2949376, 1, 230231469, 229518847, 7209472, 1, 230297007, 229650175, 20644608, 1, 230362545, 229781503, 13108224, 1, 3403, 6399, 5573376 };
s32 D_808001E0_chmole_overworld [4] BT_DATA(4, overlays_ch_mole__overworld, 0x50) = { 65, 67, 68, 66 };
ActorData D_808001F0_chmole_overworld [1] BT_DATA(4, overlays_ch_mole__overworld, 0x60) = { { 746, 785, 0, 1, 0, (void (*)(struct Actor *))func_80800160_chmole_overworld, 0, (void (*)(long, long))func_8010A730, 32768000, 0, 0, 0, 8, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_808000F4_chmole_overworld, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8706, (void (*)(struct Actor *, long, long))func_80800000_chmole_overworld, 0 } };
