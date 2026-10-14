#include "common.h"

OSThread *sucoasterhit_entrypoint_0(void)
{
    extern u8 D_80800CB0_sucoasterhit[];

    return (OSThread *) D_80800CB0_sucoasterhit;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_8080000C_sucoasterhit.s")

/* extern */

void func_80800114_sucoasterhit(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    void *func_80100094(Actor *, u32);
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct ActorFlags {
        u8 padding[0x78];
        u32 upper : 29;
        u32 flag : 1;
        u32 lower : 2;
    };
    struct DataFlags {
        u8 padding[0x18];
        u8 upper : 4;
        u8 flag : 1;
        u8 lower : 3;
    };
    Actor *actor;
    struct DataFlags *data;

    actor = func_80106790(arg0);
    if (!((struct ActorFlags *)actor)->flag) {
        data = func_80100094(actor, 0);
        if ((arg1->unk24 >> 22) == 0x27D) {
            if (actor->unk70_10 != 0xF) {
                _sucoaster_entrypoint_9(actor, 0xF, 4);
            }
            data->flag = 1;
        } else if (func_801021BC(actor, 0xB)) {
            _sucoaster_entrypoint_9(actor, 0xB, 4);
        }
    }
}

/* extern */

void func_808001C8_sucoasterhit(Unk80132ED0 *arg0, s32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    struct Flags {
        u8 padding[0x78];
        u32 upper : 29;
        u32 flag : 1;
        u32 lower : 2;
    };
    Actor *temp_v0;

    temp_v0 = func_80106790(arg0);
    if (!((struct Flags *)temp_v0)->flag) {
        _sucoaster_entrypoint_9(temp_v0, 0xC, 5);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800208_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800294_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800870_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/sucoasterhit_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800AEC_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/sucoasterhit_entrypoint_2.s")
