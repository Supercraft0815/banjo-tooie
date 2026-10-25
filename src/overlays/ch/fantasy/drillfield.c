#include "common.h"

void func_80800000_chfantasydrillfield(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80103014(u8 *);
    extern f32 D_808008D0_chfantasydrillfield[][4];
    u8 *actors[8];
    int index;
    int count;

    index = _subaddiefind_entrypoint_4(0x40A, actors, 8) - 1;
    count = 0;
    for (; index >= 0; --index) {
        if (((Actor *)actors[index])->pad6C_21 < arg0->pad6C_21) {
            ++count;
        }
    }
    func_800EFA4C(arg0->position, D_808008D0_chfantasydrillfield[count][0], D_808008D0_chfantasydrillfield[count][1], D_808008D0_chfantasydrillfield[count][2]);
    arg0->rotation[1] = D_808008D0_chfantasydrillfield[count][3];
    func_80103014((u8 *)arg0);
}

s32 func_808000C4_chfantasydrillfield(void *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 func_800DA544(s32);
    s32 func_800DC090(void);
    s32 func_800DC128(s32, s32);
    void func_800DC324(s32);
    s32 func_80800360_chfantasydrillfield();
    extern s32 B_80800A10_chfantasydrillfield[];
    typedef struct {
        s16 position[3];
        u16 flags;
        u16 item;
        u16 unkA;
        u32 unkC;
        u32 id : 11;
        u32 rest : 21;
    } DrillProp;
    Prop *props[8];
    s32 count;
    s32 i;
    s32 j;
    s32 oldSeed;
    s32 temp;
    s32 seed;
    s32 *entry;
    s32 readBits;
    s32 k;
    s32 writeBits;
    s32 choice;

    count = _gccubesearch_entrypoint_9(0x40A, props, 8);
    for (i = 0; i < count; i++) {
        ((s32 (*)[2])B_80800A10_chfantasydrillfield)[i][0] = ((DrillProp *)props[i])->id;
        ((s32 (*)[2])B_80800A10_chfantasydrillfield)[i][1] = -1;
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (((s32 (*)[2])B_80800A10_chfantasydrillfield)[i][0] < ((s32 (*)[2])B_80800A10_chfantasydrillfield)[j][0]) {
                temp = ((s32 (*)[2])B_80800A10_chfantasydrillfield)[j][0];
                ((s32 (*)[2])B_80800A10_chfantasydrillfield)[j][0] = ((s32 (*)[2])B_80800A10_chfantasydrillfield)[i][0];
                ((s32 (*)[2])B_80800A10_chfantasydrillfield)[i][0] = temp;
            }
        }
    }
    i = 0;
    if (func_800DA298(0x1DC)) {
        readBits = 4;
        seed = 0;
        for (k = 0; k < readBits; k++) {
            seed <<= 1;
            seed = func_800DA298(k + 0x1DD) | seed;
        }
    } else {
        writeBits = 4;
        seed = func_800DC128(0, 0x10);
        for (k = 0; k < writeBits; k++) {
            func_800DA3B8(k + 0x1DD, (seed >> (3 - k)) & 1);
        }
        func_800DA544(0x1DC);
    }
    oldSeed = func_800DC090();
    func_800DC324(seed);
    while (!func_80800360_chfantasydrillfield()) {
        choice = func_800DC128(0, 8);
        entry = ((s32 (*)[2])B_80800A10_chfantasydrillfield)[choice];
        if (entry[1] == -1) {
            entry[1] = i++;
        }
    }
    func_800DC324(oldSeed);
}

s32 func_80800360_chfantasydrillfield(s32 *entry, s32 *end) {
    extern s32 B_80800A10_chfantasydrillfield[];
    extern s32 B_80800A18_chfantasydrillfield[];
    register s32 sentinel;
    register int result;
    s32 i;

    sentinel = -1;
    result = 1;
    entry = B_80800A10_chfantasydrillfield; end = B_80800A18_chfantasydrillfield + 14;
    do {
        for (i = 0; i < 4; i++) {
            result &= (entry[1] != sentinel);
            entry += 2;
        }
    } while (entry != end);
    return result;
}

s32 func_808003C8_chfantasydrillfield(u32 arg0) {
    extern s32 B_80800A10_chfantasydrillfield[];
    extern s32 B_80800A18_chfantasydrillfield[];
    void func_800DA524(GameFlag);
    s32 result;
    register s32 value;
    int i;

    value = 0;
    for (i = 0; i < 8; i++) {
        if (arg0 == B_80800A10_chfantasydrillfield[i * 2]) {
            value = B_80800A10_chfantasydrillfield[i * 2 + 1];
            B_80800A10_chfantasydrillfield[i * 2] = 0;
            break;
        }
    }
    result = 1;
    for (i = 0; i < 9; i++) {
        result &= (B_80800A10_chfantasydrillfield[i * 2] == 0);
    }
    if (result) {
        func_800DA524(0xA0F);
    }
    return value;
}

/* extern */

void func_8080048C_chfantasydrillfield(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_80800000_chfantasydrillfield(Actor *);
    s32 func_808000C4_chfantasydrillfield(void *);
    s32 func_808003C8_chfantasydrillfield(u32);
    func_80800000_chfantasydrillfield(arg0);
    if (func_800DA298(0xA0F) == 0) {
        func_800DA544(0xA0F);
        func_808000C4_chfantasydrillfield(arg0);
    }
    (*(s32 *)((s8 *)(arg0) + (0x34))) = func_808003C8_chfantasydrillfield((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15);
}

void func_808004E8_chfantasydrillfield(Actor *arg0) {
    void func_80103110(Actor *, u32);
    s32 _subaddieDll_entrypoint_6(Actor *, s32);
    void func_80108B04(Actor *, u32);

    switch (arg0->unk70_10) {
    case 1:
        func_80103110(arg0, 0);
        return;
    case 2:
        if (_subaddieDll_entrypoint_6(arg0, 0xB) != 0) {
            func_80108B04(arg0, 1);
        }
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_8080054C_chfantasydrillfield.s")

OSThread *chfantasydrillfield_entrypoint_0(void)
{
    extern u8 D_808009C4_chfantasydrillfield[];

    return (OSThread *) D_808009C4_chfantasydrillfield;
}
