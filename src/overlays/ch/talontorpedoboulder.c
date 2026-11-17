#include "common.h"

OSThread *chtalontorpedoboulder_entrypoint_0(void)
{
    extern ActorData D_808002B4_chtalontorpedoboulder[];

    return (OSThread *) D_808002B4_chtalontorpedoboulder;
}

/* extern */

void func_8080000C_chtalontorpedoboulder(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    s32 func_808001CC_chtalontorpedoboulder(u8 *);
    s32 temp_v0;

    temp_v0 = func_808001CC_chtalontorpedoboulder((u8 *)arg0);
    if ((temp_v0 != 0) && (func_800DA298(temp_v0) != 0)) {
        func_800FFAB0(arg0);
        return;
    }
    func_80102FDC(arg0, 2.0f * arg0->scale);
}

s32 func_80800070_chtalontorpedoboulder(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808001CC_chtalontorpedoboulder(u8 *);
    int func_808001F8_chtalontorpedoboulder(void *);
    extern s32 D_80800240_chtalontorpedoboulder[];
    extern u8 D_808002FC_chtalontorpedoboulder[];
    s32 flag;
    s32 pod;
    f32 *position;

    switch (arg1) {
        case 0x40:
            flag = func_808001CC_chtalontorpedoboulder((u8 *)arg0);
            pod = func_808001F8_chtalontorpedoboulder(arg0);
            position = arg0->position;
            _chexploder_entrypoint_3(arg0, position, 0xF);
            func_800BABB8(0, position, position, arg0->scale, D_80800240_chtalontorpedoboulder);
            _subaddieaudioquick_entrypoint_2(arg0, position, D_808002FC_chtalontorpedoboulder);
            if (flag != 0) {
                func_800DA544(flag);
            }
            if (pod != -1) {
                _capod_entrypoint_13(arg0->unk0, NULL, pod, 0x10);
            }
            break;
        case 0x90:
            arg0 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(arg0, 1, 2);
            _chexploder_entrypoint_9(arg0, 2, 0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800194_chtalontorpedoboulder(BtIntPtr arg0, BtIntPtr arg1) {
    void func_800DF744(s32 index,s32 value);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(2, 1);
    func_80101870(arg0, arg1);
}

s32 func_808001CC_chtalontorpedoboulder(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = ((u32) *(u16 *)(arg0 + 0x76) >> 7) - 0x32;
    if ((temp_v1 < 0) || (temp_v1 >= 5)) {
        return 0;
    }
    return temp_v1 + 0x3EF;
}

int func_808001F8_chtalontorpedoboulder(void *arg0) {
    extern s16 D_80800314_chtalontorpedoboulder[][2];
    extern s16 D_80800318_chtalontorpedoboulder[][2];
    int index = 0;
    int temp_v1;

    temp_v1 = ((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) - 0x32;
loop_1:
    if (temp_v1 == D_80800314_chtalontorpedoboulder[index][0]) {
        return D_80800314_chtalontorpedoboulder[index][1];
    }
    index++;
    if (D_80800318_chtalontorpedoboulder != &D_80800314_chtalontorpedoboulder[index]) {
        goto loop_1;
    }
    return -1;
}
/* data_to_c.py: from asm/data/overlays/ch/talontorpedoboulder.data.s */
void func_80102EC0();
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800240_chtalontorpedoboulder [29] BT_DATA(4, overlays_ch_talontorpedoboulder, 0x0) = { 68157462, -2147483619, 165478443, 134220288, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 68816656, 1902895, 1310742, -2054815699, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4919066, 0 };
ActorData D_808002B4_chtalontorpedoboulder [1] BT_DATA(4, overlays_ch_talontorpedoboulder, 0x74) = { { 267, 1138, 2346, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800194_chtalontorpedoboulder, 0, 0, 0, 0, 16384, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chtalontorpedoboulder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 3088, (void (*)(struct Actor *, long, long))func_80800070_chtalontorpedoboulder, 0 } };
u8 D_808002FC_chtalontorpedoboulder [24] BT_DATA(4, overlays_ch_talontorpedoboulder, 0xBC) = { 0, 0x1B, 0, 0x13, 4, 0x13, 0, 0xA, 0, 0xE6, 0, 0x16, 0x6D, 0x60, 0, 1, 4, 0xE2, 9, 0xC4, 0, 0, 0, 0 };
s16 D_80800314_chtalontorpedoboulder [1] [ 2 ] BT_DATA(4, overlays_ch_talontorpedoboulder, 0xD4) = { { 0, 2 } };
s16 D_80800318_chtalontorpedoboulder [2] [ 2 ] BT_DATA(4, overlays_ch_talontorpedoboulder, 0xD8) = { { 0, 0 }, { 0, 0 } };
