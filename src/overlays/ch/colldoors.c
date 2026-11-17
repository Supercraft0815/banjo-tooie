#include "common.h"

void func_80800000_chcolldoors(Actor *arg0)
{
    s32 func_800DA298(s32);
    s32 flag;

    switch (arg0->unk74_7) {
        case 0x33:
            flag = func_800DA298(0x577);
            break;
        case 0x34:
            flag = func_800DA298(0x368);
            break;
        case 0x35:
            flag = func_800DA298(0x369);
            break;
    }
    if (flag) {
        arg0->position[1] += 250.0f;
        arg0->unk70_10 = 3;
    }
}

void func_808000B8_chcolldoors(Actor *arg0)
{
    void _gcfrontend_entrypoint_9(s32 arg0);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    extern u32 D_80800270_chcolldoors[4];
    s32 flag;

    switch (arg0->unk70_10) {
        case 1:
            flag = 0;
            switch (arg0->unk74_7) {
                case 0x33:
                    flag = func_800DA298(0x577);
                    arg0->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x6E);
                    break;
                case 0x34:
                    flag = func_800DA298(0x368);
                    arg0->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x6F);
                    break;
                case 0x35:
                    flag = func_800DA298(0x369);
                    arg0->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x70);
                    break;
            }
            if (flag) {
                arg0->unk70_10 = 2;
                ((f32 *)arg0->actorData)[1] = arg0->position[1] + 250.0f;
            }
            break;
        case 2:
            if (arg0->unk58 <= 0.0f) {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800270_chcolldoors);
                if (arg0->position[1] < ((f32 *)arg0->actorData)[1]) {
                    arg0->position[1] += 150.0f * func_800D8FF8();
                } else {
                    arg0->unk70_10 = 3;
                }
            } else {
                arg0->unk58 -= func_800D8FF8();
            }
            break;
    }
}

OSThread *chcolldoors_entrypoint_0(void)
{
    extern ActorData D_80800280_chcolldoors[];

    return (OSThread *) D_80800280_chcolldoors;
}
/* data_to_c.py: from asm/data/overlays/ch/colldoors.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u32 D_80800270_chcolldoors[4] BT_DATA(4, overlays_ch_colldoors, 0x0) = { 0x1304AD, 0x1661A8, 0x100FA, 0xA8C0000 };
ActorData D_80800280_chcolldoors [1] BT_DATA(4, overlays_ch_colldoors, 0x10) = { { 172, 420, 2394, 1, 0, (void (*)(struct Actor *))func_808000B8_chcolldoors, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 8, 3076, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chcolldoors, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 2, 0, 0 } };
