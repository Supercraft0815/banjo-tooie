#include "common.h"
BT_NATIVE_ONLY(void func_80105834();)
OSThread *chklungoleave_entrypoint_0(void)
{
    extern ActorData D_80800130_chklungoleave[];

    return (OSThread *) D_80800130_chklungoleave;
}

/* extern */

void func_8080000C_chklungoleave(Actor *arg0) {
    void func_80105A9C(Actor*, f32);
    void func_80105BAC(Actor *arg0);
    func_80105A9C(arg0, 300.0f);
    func_80105BAC(arg0);
}

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
/* extern */

s32 func_80800060_chklungoleave(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800FFAB0(Actor *);
    switch (arg1) {
    case 0x95:
        if (_glcutDll_entrypoint_19(0x5B) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x162E, 0x44, arg0->position, 0xAB);
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x2911);
        } else {
            func_800FFAB0(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_808000F0_chklungoleave(s32 arg0) { s32 func_80105230(); extern s32 D_80800178_chklungoleave[6]; BT_NATIVE_ONLY(return) func_80105230(arg0, D_80800178_chklungoleave); }
/* data_to_c.py: from asm/data/overlays/ch/klungo/leave.data.s */
extern u8 D_80800120_chklungoleave[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u8 D_80800120_chklungoleave[16] BT_DATA(4, overlays_ch_klungo_leave, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x33, 0x33, 0x33, 0x02, 0x64, 0x00, 0x01 };
ActorData D_80800130_chklungoleave [1] BT_DATA(4, overlays_ch_klungo_leave, 0x10) = { { 344, 803, 2317, 1, (void *)D_80800120_chklungoleave, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80800038_chklungoleave, (void (*)(long, long))func_80101870, 0, 1073741824, 0, 0, 4, 256, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chklungoleave, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800060_chklungoleave, 0 } };
s32 D_80800178_chklungoleave[6] BT_DATA(4, overlays_ch_klungo_leave, 0x58) = { 0, 1056964608, -1082130432, 0, 0, 0 };
