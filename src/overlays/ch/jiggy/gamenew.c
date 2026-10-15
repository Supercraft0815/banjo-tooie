#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chjiggygamenew_entrypoint_0(void)
{
    extern u8 D_80803D44_chjiggygamenew[];

    return (OSThread *) D_80803D44_chjiggygamenew;
}

/* extern */

s32 func_8080000C_chjiggygamenew(void) {
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x20)));
}

/* extern */

s32 func_80800030_chjiggygamenew(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790();
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s16 selection;
        s16 slot;
        u16 state;
            s16 pad6;
        f32 timer;
        f32 position[3];
    } JiggyGameEntry;
    typedef struct {
        u8 pad0[0x1F4];
        s8 slots[20];
        s8 extraSlots[20];
    } JiggyGameData;
    Actor *actor;
    s16 (*data)[12];

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    if (arg1 < 20) {
        if (((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].state == 0x6B54 ||
            ((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].state == 0xC) {
            ((JiggyGameEntry *)data)[((JiggyGameData *)data)->slots[arg1]].timer = 0.0f;
            func_808007E4_chjiggygamenew(data, 0x78, ((JiggyGameData *)data)->slots[arg1]);
            actor->actorData[3] = ((JiggyGameData *)data)->slots[arg1];
            ((JiggyGameData *)data)->slots[arg1] = -1;
            return 1;
        }
        return 0;
    }
    arg1 -= 20;
    if (((JiggyGameData *)data)->extraSlots[arg1] != -1) {
        ((JiggyGameEntry *)data)[((JiggyGameData *)data)->extraSlots[arg1]].timer = 0.0f;
        func_808007E4_chjiggygamenew(data, 0xF54, ((JiggyGameData *)data)->extraSlots[arg1]);
        actor->actorData[3] = ((JiggyGameData *)data)->extraSlots[arg1];
        ((JiggyGameData *)data)->extraSlots[arg1] = -1;
        return 2;
    }
    return 0;
}

/* extern */

void func_80800158_chjiggygamenew(Unk80132ED0 *arg0) {
    Actor *func_80106790();
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    void func_808035C4_chjiggygamenew(Unk80132ED0 *, f32 *);
    typedef struct {
        s8 selection;
        s8 slot;
        u8 pad2[6];
        f32 timer;
        f32 position[3];
    } JiggyGameResetEntry;
    typedef struct {
        u8 pad0[0x1F4];
        s8 slots[12];
    } JiggyGameResetData;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    ((JiggyGameResetEntry *)data)[actor->actorData[3]].timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0xEB0, actor->actorData[3]);
    func_808035C4_chjiggygamenew(actor->unk3C, ((JiggyGameResetEntry *)data)[actor->actorData[3]].position);
    index = actor->actorData[3];
    ((JiggyGameResetData *)data)->slots[((JiggyGameResetEntry *)data)[index].slot] = index;
    actor->actorData[3] = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_8080020C_chjiggygamenew.s")

/* extern */

void func_80800368_chjiggygamenew(Unk80132ED0 *arg0) {
    Actor *func_80106790();
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s8 selection;
        u8 pad1[3];
        u16 input;
        u16 pad6;
        f32 timer;
        u8 padC[12];
    } JiggyGameEntry;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    index = actor->actorData[3];
    if (((JiggyGameEntry *)data)[index].input != 0x800) {
        if (((JiggyGameEntry *)data)[index].input == 0x1FFF) {
            ((JiggyGameEntry *)data)[index].selection--;
        }
    } else {
        ((JiggyGameEntry *)data)[index].selection++;
    }
    if (((JiggyGameEntry *)data)[index].selection < 0) {
        ((JiggyGameEntry *)data)[index].selection += 4;
    }
    if (((JiggyGameEntry *)data)[index].selection >= 4) {
        ((JiggyGameEntry *)data)[index].selection -= 4;
    }
    ((JiggyGameEntry *)data + index)->timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0x55C, index);
}

/* extern */

void func_80800424_chjiggygamenew(Unk80132ED0 *arg0) {
    Actor *func_80106790();
    void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2);
    typedef struct {
        s8 selection;
        u8 pad1[3];
        u16 input;
        u16 pad6;
        f32 timer;
        u8 padC[12];
    } JiggyGameEntry;
    Actor *actor;
    s16 (*data)[12];
    s32 index;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    index = actor->actorData[3];
    if (((JiggyGameEntry *)data)[index].input != 0x800) {
        if (((JiggyGameEntry *)data)[index].input == 0x1FFF) {
            ((JiggyGameEntry *)data)[index].selection--;
        }
    } else {
        ((JiggyGameEntry *)data)[index].selection++;
    }
    if (((JiggyGameEntry *)data)[index].selection < 0) {
        ((JiggyGameEntry *)data)[index].selection += 4;
    }
    if (((JiggyGameEntry *)data)[index].selection >= 4) {
        ((JiggyGameEntry *)data)[index].selection -= 4;
    }
    ((JiggyGameEntry *)data + index)->timer = 0.0f;
    func_808007E4_chjiggygamenew(data, 0x7F4, index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808004E0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808006E0_chjiggygamenew.s")

/* extern */

s32 func_808007BC_chjiggygamenew(void) {
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x28))) == 5;
}

/* extern */

void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2) {
    s32 rom_read_word(s32, u32 *);
    u32 sp1C[1];

    rom_read_word(arg1 - 0x50000000, sp1C);
    arg0[arg2][2] = sp1C[0] & 0xFFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800834_chjiggygamenew.s")

/* extern */

void func_80800AF8_chjiggygamenew(Actor *arg0) {
    struct Entry {
        u8 pad0[4];
        u16 unk4;
        u16 pad6;
        f32 unk8;
        u8 padC[12];
    };
    s32 var_s0;
    void *temp_v0;
    struct Entry *var_s1;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        if (var_s1->unk4 == 0x3000) {
            func_808007E4_chjiggygamenew(temp_v0, 0x844, var_s0);
            var_s1->unk8 = 0.0f;
        }
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800B88_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800CC0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808019E0_chjiggygamenew.s")

/* extern */

int func_80801C20_chjiggygamenew(Actor *arg0) {
    struct Entry { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; };
    struct Entry *entries;
    s32 i;

    entries = func_80100094(arg0, 0U);
    for (i = 0; i < 20; i++) {
        if (entries[i].unk4 != 0x18) {
            return 0;
        }
    }
    return 1;
}

int func_80801CB0_chjiggygamenew(u8 arg0, s32 arg1, void *arg2) {
    struct Entry { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; };
    u16 temp_v1 = ((struct Entry *)arg2)[arg1].unk4;

    return (temp_v1 == 0x6B54) || (temp_v1 == 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801CE8_chjiggygamenew.s")

/* extern */

void func_80801E4C_chjiggygamenew(Actor *arg0, s32 arg1) {
    struct JiggyGameData {
        f32 timer;
        u32 count;
        u8 pad8[8];
        s32 state;
        s32 jiggy;
        f32 duration;
    };
    f32 _sujiggy_entrypoint_3(s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800DA544(GameFlag);
    f32 temp_f0;

    func_800DA544(0xD49);
    if (arg1 == 0) {
        temp_f0 = _sujiggy_entrypoint_3(((struct JiggyGameData *)arg0->actorData)->jiggy);
        ((struct JiggyGameData *)arg0->actorData)->timer = temp_f0;
        ((struct JiggyGameData *)arg0->actorData)->duration = temp_f0;
        func_800CE8D8(4, temp_f0, (s32) temp_f0);
        func_800CE88C(4, 1);
        ((struct JiggyGameData *)arg0->actorData)->count = osGetCount();
    }
    ((struct JiggyGameData *)arg0->actorData)->state = 5;
    arg0->unk64_20 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801EE8_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802030_chjiggygamenew.s")

void func_8080245C_chjiggygamenew(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802464_chjiggygamenew.s")

void func_808024C8_chjiggygamenew(s32 arg0)
{
    func_800E4208();
    func_800E44FC(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808024F0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802858_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/chjiggygamenew_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/chjiggygamenew_entrypoint_2.s")

OSThread *chjiggygamenew_entrypoint_3(void)
{
    extern u8 D_80803E50_chjiggygamenew[];

    return (OSThread *) D_80803E50_chjiggygamenew;
}

/* extern */

void func_80802E80_chjiggygamenew(Actor *arg0) {
    struct JiggyGameInitData {
        f32 position[3];
        u8 padC[0x1C];
        s32 unk28;
        s32 unk2C;
        f32 unk30;
        f32 unk34;
        s32 buttons;
        f32 unk3C;
        f32 unk40;
    };
    s32 _subaddiefade_entrypoint_1(s32, s32);
    OSContPad *func_800169A8(void);
    void func_800EE7F8(f32 *, f32 *);
    OSContPad *sp24;
    struct JiggyGameInitData *sp20;
    struct JiggyGameInitData *temp_v0;

    sp24 = func_800169A8();
    temp_v0 = func_80100094(arg0, 0);
    sp20 = temp_v0;
    func_800EE7F8(temp_v0->position, arg0->position);
    arg0->scale = 0.18f;
    arg0->rotation[0] = 59.0f;
    arg0->rotation[2] = 63.0f;
    arg0->rotation[1] = -6.0f;
    sp20->unk30 = 1.0f;
    sp20->unk34 = 1.0f;
    sp20->unk28 = -1;
    sp20->unk2C = sp20->unk28;
    sp20->buttons = sp24->button;
    sp20->unk3C = 0.0f;
    sp20->unk40 = 0.0f;
    _subaddiefade_entrypoint_1(arg0, 0xB9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802F3C_chjiggygamenew.s")

void func_80803564_chjiggygamenew(s32 arg0) 
{
}
/* extern */

void func_8080356C_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(), 8);
}

/* extern */

void func_80803598_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(), 7);
}

void func_808035C4_chjiggygamenew(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790();
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(func_80106790(arg0), 0U) + 0xC));
}

void func_808035FC_chjiggygamenew(Actor *arg0, f32 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    u8 *temp_v0;

    temp_v0 = func_80100094(func_80106790((Unk80132ED0 *)arg0), 0U);
    arg1[0] = *(f32 *)((u8 *)temp_v0 + 0x18);
    arg1[1] = *(f32 *)((u8 *)temp_v0 + 0x1C);
}

s32 func_8080363C_chjiggygamenew(void) {
    Actor *func_80106790();
    return ((u32) (*(u16 *)((s8 *)(func_80106790()) + (0x72))) >> 0xA) == 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80803668_chjiggygamenew.s")

OSThread *chjiggygamenew_entrypoint_4(void)
{
    extern u8 D_80803EBC_chjiggygamenew[];

    return (OSThread *) D_80803EBC_chjiggygamenew;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_8080377C_chjiggygamenew.s")

void func_80803928_chjiggygamenew(Unk80132ED0 *arg0, Gfx **arg1) {
    s32 func_800E81D0(void);
    void func_80101870(Actor* arg0, void* arg1);
    Actor *func_80106790(Unk80132ED0 *);
    Gfx *sp18;
    Gfx *temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_800E81D0();
    if (temp_v0 != 0) {
        temp_v0_2 = (*arg1)++;
        temp_v0_2->words.w0 = 0xDB060010;
        sp18 = temp_v0_2;
        sp18->words.w1 = osVirtualToPhysical((u8 *) temp_v0);
        func_80101870(func_80106790(arg0), arg1);
    }
}
