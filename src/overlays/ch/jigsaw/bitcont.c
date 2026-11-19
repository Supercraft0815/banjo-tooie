#include "common.h"

void func_80800000_chjigsawbitcont(Actor *arg0, u32 arg1) {
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    extern s16 D_808009B4_chjigsawbitcont[][8];
    func_80101FDC(arg0, arg1);
    if ((arg1 == 2) && (func_800DA298(D_808009B4_chjigsawbitcont[arg0->unk74_7][0]) == 0)) {
        func_800DA544(D_808009B4_chjigsawbitcont[arg0->unk74_7][0]);
        func_80108B04(arg0, 0);
    }
}

s32 func_80800084_chjigsawbitcont(Actor *arg0, s32 arg1, s32 arg2) {
    void _chjigsawcollect_entrypoint_1(Actor **, s32, s32);
#ifndef BT_NATIVE
    s32 func_800DA298(s32);
#endif
    void *func_80100094(Actor *, u32);
    void func_80100120(Actor *);
    void func_80800890_chjigsawbitcont(Actor *, s32, s32);
    extern f32 D_808009A8_chjigsawbitcont[][4];
    typedef struct {
        s16 jiggy;
        s16 count;
        f32 range[2];
        s16 flag;
        s16 firstFlag;
    } BitConfig;
    typedef struct {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u32 pad74_22 : 10, u32 pad74_0 : 21);
        u32 initialized : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 21, u32 pad74_22 : 10);
    } BitController;
    s32 i;
    struct {
        f32 positions[3][3];
        s16 count;
    } *data;
    BitConfig *config;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x3D:
            if (arg2 == -1) {
                _chjigsawcollect_entrypoint_1(&arg0,
                    ((BitConfig *)D_808009A8_chjigsawbitcont)[arg0->unk74_7].jiggy, 0);
            } else {
                config = &((BitConfig *)D_808009A8_chjigsawbitcont)[arg0->unk74_7];
                for (i = 0; i < config->count; i++) {
                    if (!func_800DA298(config->firstFlag + i)) {
                        func_80800890_chjigsawbitcont(arg0, i, arg2);
                    } else {
                        data->count++;
                    }
                    config = &((BitConfig *)D_808009A8_chjigsawbitcont)[arg0->unk74_7];
                }
            }
            break;
        case 0xA:
            if (!((BitController *)arg0)->initialized) {
                func_80100120(arg0);
            }
            if (arg2 == arg0->unk74_7 &&
                !func_800DA298(((BitConfig *)D_808009A8_chjigsawbitcont)[arg0->unk74_7].flag)) {
                func_80800000_chjigsawbitcont(arg0, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800214_chjigsawbitcont(Actor *arg0)
{
    f32 func_800D8FF8(void);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);
    void *func_80100094(Actor *, u32);
    extern s16 D_808009AA_chjigsawbitcont[][8];
    struct BitContData
    {
        u8 pad[0x10];
        f32 timer;
    };
    struct JigsawData { f32 positions[3][3]; s16 count; } *data;
    f32 delta;
    u32 flags;
    data = func_80100094(arg0, 0);
    /* shortcut: IDO emits only the aligned low word; rework this view for other compilers. */
    flags = (u32)(*(u64 *)((u8 *)arg0 + 0x60) & 0x100000ULL);
    if (!flags)
    {
        return;
    }
    /* Keep the manager and actor homes live across the timer call. */
    if ((data && data) && data) {}
    delta = func_800D8FF8();
    if (((arg0 && arg0) && arg0) != 0)
    {
    }
    ((struct BitContData *) arg0->actorData)->timer -= delta;
    if (!(((struct BitContData *) arg0->actorData)->timer < 0.0f))
    {
        return;
    }
    ((struct BitContData *) arg0->actorData)->timer = 0.0f;
    arg0->unk64_20 = 0;
    if ((data->count < D_808009AA_chjigsawbitcont[arg0->unk74_7][0]) && func_800FCCD4(5))
    {
        func_800FCAE0(5, 0, 0x1F40);
        func_800FCA90(5);
    }
}

void func_808002E4_chjigsawbitcont(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 func_800D0B68(u32, u32);
#ifndef BT_NATIVE
    s32 func_800DA298(s32);
#endif
    void func_800EE88C(f32 *, s16 *);
    s32 func_800FFAB0(BtIntPtr);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    extern f32 D_808009A8_chjigsawbitcont[][4];
    typedef struct { s16 flag; s16 pad; f32 range[2]; s16 collected; s16 padE; } JigsawBitContEntry;
    extern s16 D_808009B4_chjigsawbitcont[][8];
    Prop *props[3];
    struct {
        f32 positions[3][3];
        s16 count;
    } *data;
    s32 count;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 50;
    if (arg0->unk74_7 != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (func_800D0B68(((JigsawBitContEntry *)D_808009A8_chjigsawbitcont)[arg0->unk74_7].flag, 1)) {
        func_800FFAB0(arg0);
        return;
    }
    data->count = 0;
    count = _gccubesearch_entrypoint_9(0x312, props, 3);
    for (i = 0; i < count; i++) {
        func_800EE88C(data->positions[i], props[i]->position);
    }
    if (func_800DA298(D_808009B4_chjigsawbitcont[arg0->unk74_7][0])) {
        func_80108B04(arg0, 1);
    }
}

s32 func_8080040C_chjigsawbitcont(BtIntPtr arg0) {
    void func_800D0BD4(s32, u32);
    void func_800DA544();
    void func_800FC660(u32);
    void func_800FCAE0(u32, u32, u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80108B04(Actor *, u32);
    extern f32 D_808009A8_chjigsawbitcont[][4];
    extern s16 D_808009B6_chjigsawbitcont[][8];
    s16 *entry;
    struct {
        s16 positions[18];
        s16 count;
    } *data;
    Actor *actor;
    s16 count;
    f32 ratio;
if (!entry) {}

    actor = func_80106790(((Actor *)arg0)->unk3C);
    data = func_80100094(actor, 0);
    data->count++;
    func_800DA544(D_808009B6_chjigsawbitcont[actor->unk74_7][0] + ((Actor *)arg0)->unk6C_0);
    count = data->count;
    entry = (s16 *)D_808009A8_chjigsawbitcont[actor->unk74_7];
    if (count == entry[1]) {
        func_800D0BD4(entry[0], 1);
        func_800FC660(5);
        func_80108B04(actor, -1);
        return;
    }
    if (!actor->unk64_20) {
        ratio = (f32)count / (f32)entry[1];
        ((f32 *)actor->actorData)[4] = 1.75f * ratio;
        func_800FC660(5);
    } else {
        ratio = 1.0f / (f32)entry[1];
        ((f32 *)actor->actorData)[4] += 1.75f * ratio;
        func_800FCAE0(5, 0x7FFF, 0x1F40);
    }
    actor->unk64_20 = 1; BT_NATIVE_ONLY(return 0;)
}

OSThread *chjigsawbitcont_entrypoint_0(void)
{
    extern u8 D_808009B8_chjigsawbitcont[];

    return (OSThread *) D_808009B8_chjigsawbitcont;
}

void func_80800570_chjigsawbitcont(Actor *arg0, u32 arg1) {
    void func_80101FDC(Actor *, u32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void _subaddiebounce_entrypoint_0(Actor *);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);

    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            arg0->unk79_4 = 3;
            ((f32 *)arg0->actorData)[3] = func_800DC178(0.0f, 250.0f);
            _subaddiebounce_entrypoint_0(arg0);
            arg0->unk64_16 = 1;
            break;
        case 3:
            func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
            _subaddieDll_entrypoint_4(arg0, 0);
            break;
        case 4:
            func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
            arg0->unk64_16 = 1;
            break;
    }
}

void func_80800634_chjigsawbitcont(BtIntPtr arg0) {
    s32 func_8001211C();
    BtIntPtr func_800BBCB8(BtIntPtr, BtIntPtr, s32, s32, s32 *);
    f32 func_800DC0C0();
    s32 func_800E3E8C(BtIntPtr, s32);
    s32 func_800FFAB0(BtIntPtr);
    s32 func_8010C9B0(BtIntPtr, s32);
    s32 func_8080040C_chjigsawbitcont(BtIntPtr);
    extern s32 D_80800A00_chjigsawbitcont;
    BtIntPtr sp24;
    BtIntPtr temp_a0;

    temp_a0 = arg0 + 4;
    sp24 = temp_a0;
    if ((func_800E3E8C(temp_a0, 0x42480000) != 0) && !(func_8001211C() & 3) && (func_800DC0C0() < 0.1f)) {
        func_800BBCB8(sp24, 0, 0x3F800000, 2, &D_80800A00_chjigsawbitcont);
    }
    if (func_8010C9B0(sp24, 0x32) != 0) {
        func_8080040C_chjigsawbitcont(arg0);
        func_800FFAB0(arg0);
    }
}

void func_808006D8_chjigsawbitcont(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 _subaddiebounce_entrypoint_1(Actor *);
    s32 _subaddiebounce_entrypoint_2(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u8 D_808009A0_chjigsawbitcont[];
    f32 sp24;
    f32 temp;

    switch (arg0->unk70_10) {
        case 1:
            arg0->unk64_16 = 0;
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_80800570_chjigsawbitcont(arg0, 2);
            }
            break;
        case 2:
            sp24 = func_800D8FF8();
            func_80800634_chjigsawbitcont((BtIntPtr)arg0);
            if (arg0->unk79_4 >= 3) {
                if (_subaddiebounce_entrypoint_1(arg0)) {
                    arg0->unk79_4 = 2;
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808009A0_chjigsawbitcont);
                }
                temp = 360.0f * sp24;
                arg0->rotation[1] += temp;
                arg0->rotation[0] += temp;
            } else if (_subaddiebounce_entrypoint_2(arg0)) {
                arg0->unk79_4--;
                if (arg0->unk79_4 <= 0) {
                    func_80800570_chjigsawbitcont(arg0, 3);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808009A0_chjigsawbitcont);
            }
            break;
        case 3:
        case 4:
            func_80800634_chjigsawbitcont((BtIntPtr)arg0);
            break;
    }
}                typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0xC]; f32 unk34; f32 unk38; } Objbitcont_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800868_chjigsawbitcont(void *arg0) {
    (((Objbitcont_arg0 *)arg0)->unk38) = 0.2f;
    (((Objbitcont_arg0 *)arg0)->unk34) = -1500.0f;
    (((Objbitcont_arg0 *)arg0)->unk24) = 840.0f;
}

void func_80800890_chjigsawbitcont(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *actor;
    f32 (*positions)[3];
    f32 *range;
    Actor *func_801084B0(BtIntPtr, Actor **);
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void func_80800570_chjigsawbitcont(Actor *, u32);
    extern f32 D_808009A8_chjigsawbitcont[][4];

    actor = func_801084B0(0x17F, &arg0);
    positions = func_80100094(arg0, 0);
    actor->unk6C_0 = arg1;
    func_800EE7F8((f32 *)actor->actorData, positions[actor->unk6C_0]);
    actor->unk3C = arg0->unk0;
    range = D_808009A8_chjigsawbitcont[arg0->unk74_7];
    actor->unk58 = func_800DC178(range[1], range[2]);
    switch (arg2) {
        case 0:
            _subaddieDll_entrypoint_4(actor, 1);
            break;
        case 1:
            func_80800570_chjigsawbitcont(actor, 4);
            break;
    }
}

OSThread *chjigsawbitcont_entrypoint_1(void)
{
    extern u8 D_80800A28_chjigsawbitcont[];

    return (OSThread *) D_80800A28_chjigsawbitcont;
}
