#include "common.h"

void *func_80100094(Actor *, u32);
s8 func_800BF8E4(void);

OSThread *chflamer_entrypoint_0(void)
{
    extern u8 D_80800B20_chflamer[];

    return (OSThread *) D_80800B20_chflamer;
}

/* extern */

void func_8080000C_chflamer(Actor *arg0) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x1AC))) = 0;
    if (func_800BF8E4() > 0) {
        (*(s16 *)((s8 *)(sp1C) + (4))) = 0x190;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800050_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800434_chflamer.s")

/* extern */

s32 func_80800594_chflamer(Actor *arg0, s32 arg1, s32 arg2) {
    struct FlamerData {
        s32 unk0;
        u8 pad4[0x10];
        s8 unk14;
        u8 pad15[0x19F];
        u8 link[1];
    };
    s32 _subaddielink_entrypoint_3(u8 *);
    s32 func_800C8A98(void);
    struct FlamerData *sp1C;
    struct FlamerData *temp_v0;

    if (arg1 == 0x95) {
        temp_v0 = func_80100094(arg0, 0U);
        sp1C = temp_v0;
        _subaddielink_entrypoint_3(temp_v0->link);
        if (func_800BF8E4() > 0) {
            sp1C->unk0 = func_800C8A98();
            sp1C->unk14 = 0;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 func_8010108C();
s32 func_8010114C(s32, s32, s32);

void chflamer_entrypoint_1(Actor *arg0, Unk80132ED0 *arg1) {
    struct LinkedActorFlags {
        u8 pad[0x74];
        u8 pad74_1 : 7;
        u8 unk74_0 : 1;
    };
    struct LinkFlags {
        u8 pad[0x18];
        u16 flags;
    };
    void _chbaddiesetup_entrypoint_2(s32 *, Unk80132ED0 *, s32);
    extern s32 _chflamer_entrypoint_2;

    if (!arg0->unk64_17) {
        if (!((struct LinkedActorFlags *)arg0)->unk74_0) {
            if ((arg1 != NULL) && (((struct LinkFlags *)arg1)->flags & 1)) {
                func_8010114C(arg1, 0x92, 0);
            }
            ((struct LinkedActorFlags *)arg0)->unk74_0 = 1;
            func_8010108C(arg0, 0x2B, 1);
            _chbaddiesetup_entrypoint_2(&_chflamer_entrypoint_2, arg0->unk0, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/chflamer_entrypoint_2.s")

Actor *func_80800738_chflamer(Actor *arg0) {
    struct LinkedActorFlags {
        u8 pad[0x74];
        u8 pad74_1 : 7;
        u8 unk74_0 : 1;
    };
    s32 _subaddielink_entrypoint_0(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    u8 *sp1C;
    Actor *data;

    sp1C = func_80100094(arg0, 0U);
    data = _subaddielink_entrypoint_4(sp1C + 0x1B4);
    if (data != NULL) {
        ((struct LinkedActorFlags *)data)->unk74_0 = 0;
        func_8010108C(data, 0x2B, 0);
    }
    _subaddielink_entrypoint_0(sp1C + 0x1B4);
    arg0->unk70_10 = 3;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808007A8_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808008C0_chflamer.s")

void func_8080098C_chflamer(s32 arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    extern s32 D_80800B68_chflamer;
    _subaddieaudioloop_entrypoint_5(arg0, arg0 + 4, 1, -1, &D_80800B68_chflamer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808009C0_chflamer.s")
