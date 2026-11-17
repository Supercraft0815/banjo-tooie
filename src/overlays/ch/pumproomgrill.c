#include "common.h"

OSThread *chpumproomgrill_entrypoint_0(void)
{
    extern ActorData D_808000E0_chpumproomgrill[];

    return (OSThread *) D_808000E0_chpumproomgrill;
}

void func_8080000C_chpumproomgrill(s32 arg0) 
{
}
s32 func_80800014_chpumproomgrill(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_808000AC_chpumproomgrill(Actor *);
    f32 sp1C[3];

    switch (arg1) {
    case 0x40:
        func_800EE7F8(sp1C, arg0->position);
        func_800EF1B8(sp1C, arg0->rotation[1], -400.0f);
        _chexploder_entrypoint_3(arg0, sp1C, 0xF);
        break;
    case 0x90:
        func_808000AC_chpumproomgrill(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000AC_chpumproomgrill(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    void func_800DA544(s32 index);
    extern s32 D_80800128_chpumproomgrill[6];
    _subaddieaudioquick_entrypoint_2(arg0, &arg0->position[0], D_80800128_chpumproomgrill);
    func_800DA544(0x162);
}
/* data_to_c.py: from asm/data/overlays/ch/pumproomgrill.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808000E0_chpumproomgrill [1] BT_DATA(4, overlays_ch_pumproomgrill, 0x0) = { { 411, 842, 2177, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 354, 0, 16386, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chpumproomgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_80800014_chpumproomgrill, 0 } };
s32 D_80800128_chpumproomgrill[6] BT_DATA(4, overlays_ch_pumproomgrill, 0x48) = { 1246368, 655590, 1572864, 0, 0, 0 };
