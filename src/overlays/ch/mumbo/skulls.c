#include "common.h"

OSThread *chmumboskulls_entrypoint_0(void)
{
    extern ActorData D_808000C0_chmumboskulls[];

    return (OSThread *) D_808000C0_chmumboskulls;
}

void func_8080000C_chmumboskulls(s32 arg0)
{
    func_8010A800(arg0,1);
}

void func_8080002C_chmumboskulls(s32 arg0) 
{
}
/* extern */
void func_8080007C_chmumboskulls(Actor *);

s32 func_80800034_chmumboskulls(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0x95:
        func_8080007C_chmumboskulls(arg0);
        func_8010A63C((void ***) arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080007C_chmumboskulls(Actor *arg0) {
    s32 index = arg0->unk74_7;
    extern u16 D_80800108_chmumboskulls[];
    index -= 0x32;
    func_80103140(arg0, D_80800108_chmumboskulls[index], 0U);
}
/* data_to_c.py: from asm/data/overlays/ch/mumbo/skulls.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808000C0_chmumboskulls [1] BT_DATA(4, overlays_ch_mumbo_skulls, 0x0) = { { 344, 1123, -1, 1, 0, (void (*)(struct Actor *))func_8080002C_chmumboskulls, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 1024, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chmumboskulls, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800034_chmumboskulls, 0 } };
u16 D_80800108_chmumboskulls [4] BT_DATA(4, overlays_ch_mumbo_skulls, 0x48) = { 0x648, 0x8E0, 0x8E1, 0x867 };
