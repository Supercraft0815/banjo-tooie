#include "common.h"

s32 func_80800000_chufoextdoor(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    extern s32 D_80800100_chufoextdoor[5];
    extern s32 D_80800114_chufoextdoor[13];

    struct {
        u8 pad0[0x1A];
        u16 id;
        u8 pad1C[8];
        u32 flags : 10;
        u32 rest : 22;
    } *temp;
    struct {
        f32 *source;
        f32 point[3];
    } local;

    if (arg1 == 0x3E) {
        temp = *(void **)&arg2;
        if (temp->flags != 0) {
            return 0;
        }
        if (func_800F52B8((u32)temp->id >> 5, arg0->unk0) != 0x14) {
            return 0;
        }
        func_800EE7F8(local.point, local.source = arg0->position);
        func_800EF1B8(local.point, arg0->rotation[1], -100.0f);
        _chexploder_entrypoint_3(arg0, local.point, 0xE);
        func_800BBCB8(local.source, local.point, 0.8f, 5, D_80800114_chufoextdoor);
        _subaddieaudioquick_entrypoint_2(arg0, local.source, D_80800100_chufoextdoor);
        func_800DA544(0x3AB);
        return 1;
    }
    return 0;
}

OSThread *chufoextdoor_entrypoint_0(void)
{
    extern ActorData D_80800148_chufoextdoor[];

    return (OSThread *) D_80800148_chufoextdoor;
}
/* data_to_c.py: from asm/data/overlays/ch/ufoextdoor.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800100_chufoextdoor[5] BT_DATA(4, overlays_ch_ufoextdoor, 0x0) = { 1246368, 655590, 1469792, 131099, 0 };
s32 D_80800114_chufoextdoor[13] BT_DATA(4, overlays_ch_ufoextdoor, 0x14) = { 1903069, 2818816, 67108898, 25166336, 75499008, 1376256, 10027033, 7, 2949170, 4915232, -2134327104, 917584, 6553600 };
ActorData D_80800148_chufoextdoor [1] BT_DATA(4, overlays_ch_ufoextdoor, 0x48) = { { 892, 1178, 2364, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 939, 0, 0, 2052, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800000_chufoextdoor, 0 } };
