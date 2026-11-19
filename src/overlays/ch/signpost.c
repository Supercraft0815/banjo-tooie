#include "common.h"

OSThread *chsignpost_entrypoint_0(void)
{
    extern ActorData D_808002E0_chsignpost[];

    return (OSThread *) D_808002E0_chsignpost;
}

void func_8080000C_chsignpost(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.75f);
    arg0->actorData[4] = ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x32;
}

void func_80800058_chsignpost(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    u32 func_800F54E4(void);
    s32 func_800F4B8C(BtUIntPtr, u32, s32);
    s32 func_8010CAC0(f32 *, u32);
    int func_8010CD88(Actor *, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 _subaddiedialog_entrypoint_11();
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    s32 func_80800274_chsignpost(u8 *);
    s32 flags;
    s32 radius;

    switch (arg0->unk70_10) {
    case 1:
        if (!func_800DA298(0x3A)) {
            if (func_8010CAC0(arg0->position, 350) &&
                func_8010CD88(arg0, 360.0f, 70.0f) &&
                func_800F4B8C(func_800F54E4(), -1, 0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x16C2, 0xE, arg0->position, 0x28);
                func_80101FDC(arg0, 2);
                func_800DA544(0x3A);
            }
        } else {
            flags = arg0->unk70_0 ? 4 : 0;
            radius = arg0->unk70_0 ? 350 : 250;
            if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1],
                    radius, 70, flags)) {
                arg0->unk70_10 = 2;
                func_80800274_chsignpost((u8 *)arg0);
            }
        }
        break;
    case 2:
        break;
    }
}

s32 func_8080019C_chsignpost(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void func_80800230_chsignpost(u8 *, s32, s32);
    void func_80800264_chsignpost(BtIntPtr, s32, s32);
    extern u32 D_80800328_chsignpost[6];

    switch (arg1) {
    case 0x2E:
        func_80800230_chsignpost((u8 *)arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x2F:
        func_80800264_chsignpost((BtIntPtr)arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800328_chsignpost, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800230_chsignpost(u8 *arg0, s32 arg1, s32 arg2) {
    if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 2) {
        *(u8 *)(arg0 + 0x72) = (*(u8 *)(arg0 + 0x72) & 0xFF03) | 4;
    }
}

void func_80800264_chsignpost(BtIntPtr arg0, s32 arg1, s32 arg2) {
}
/* extern */

s32 func_80800274_chsignpost(u8 *arg0) {
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, u8 *, s32);
    s32 func_800D3E40(s32, s32);
    s32 sp20;
    s32 var_a1;

    var_a1 = (*(s32 *)((s8 *)(arg0) + (0x28))) + 0x1686;
    if ((var_a1 >= 0x16B7) && (var_a1 < 0x16BF)) {
        sp20 = var_a1;
        if (func_800D3E40(6, var_a1) == 0) {
            var_a1 = 0x16BF;
        }
    }
    _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0))), var_a1, 0xF, arg0 + 4, 0x28);
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/signpost.data.s */
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808002E0_chsignpost [1] BT_DATA(4, overlays_ch_signpost, 0x0) = { { 557, 408, 1954, 1, 0, (void (*)(struct Actor *))func_80800058_chsignpost, 0, (void (*)(long, long))func_80101870, 29491200, 1069547520, 0, 0, 16384, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chsignpost, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32248, 9298, (void (*)(struct Actor *, long, long))func_8080019C_chsignpost, 0 } };
u32 D_80800328_chsignpost[6] BT_DATA(4, overlays_ch_signpost, 0x48) = { 0x43820000, 0x432F0000, 0x432F0000, 0x42960000, 0, 0 };
