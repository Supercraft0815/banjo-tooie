#include "common.h"

OSThread *chfactoryworkerwear_entrypoint_0(void)
{
    extern u8 D_80800438_chfactoryworkerwear[];

    return (OSThread *) D_80800438_chfactoryworkerwear;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_8080000C_chfactoryworkerwear.s")

void func_80800100_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x24))) = 0;
}

void func_80800124_chfactoryworkerwear(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_8080012C_chfactoryworkerwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_80800260_chfactoryworkerwear.s")

/* extern */

void func_808002E4_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 func_80101068(void);
    s32 func_80101038(u8 *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_80101038(temp_v0 + 0x10);
    (*(f32 *)((s8 *)(sp1C) + (0x1C))) = func_80101068();
}

void func_80800320_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 func_80101068(void);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    (*(f32 *)((s8 *)(sp1C) + (0x20))) = func_80101068();
}

/* extern */

s32 func_80800350_chfactoryworkerwear(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFA88(Unk80132ED0 *);
    void func_80800260_chfactoryworkerwear(Actor *, s16);
    switch (arg1) {                                 /* switch 1; irregular */
    case 33:                                        /* switch 1 */
        switch (((s16 *)&arg2)[0]) {                 /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            func_80800260_chfactoryworkerwear(arg0, ((s16 *)&arg2)[1]);
            break;
        case 2:                                     /* switch 2 */
            func_80800320_chfactoryworkerwear(arg0);
            break;
        case 3:                                     /* switch 2 */
            func_808002E4_chfactoryworkerwear(arg0);
            break;
        }
        break;
    case 44:                                        /* switch 1 */
        func_800FFA88(arg0->unk0);
        break;
    }
    return 0;
}
