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

s32 func_808000C4_chfantasydrillfield(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    void func_800DA544(s32 index);
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
    s32 choice; BT_NATIVE_ONLY(s32 bt_result;)

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
    while (BT_IDO_ONLY(!func_80800360_chfantasydrillfield()) BT_NATIVE_ONLY(!(bt_result = func_80800360_chfantasydrillfield()))) {
        choice = func_800DC128(0, 8);
        entry = ((s32 (*)[2])B_80800A10_chfantasydrillfield)[choice];
        if (entry[1] == -1) {
            entry[1] = i++;
        }
    }
    func_800DC324(oldSeed); BT_NATIVE_ONLY(return bt_result;)
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
}                typedef struct { u8 pad0[0x34]; s32 unk34; u8 pad38[0x34]; u32 unk6C; } Objdrillfield_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080048C_chfantasydrillfield(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_80800000_chfantasydrillfield(Actor *);
    s32 func_808000C4_chfantasydrillfield(void * BT_PASS2(, s32));
    s32 func_808003C8_chfantasydrillfield(u32);
    func_80800000_chfantasydrillfield(arg0);
    if (func_800DA298(0xA0F) == 0) {
        func_800DA544(0xA0F);
        func_808000C4_chfantasydrillfield(arg0 BT_PASS2(, bt_a1));
    }
    (((Objdrillfield_arg0 *)arg0)->unk34) = func_808003C8_chfantasydrillfield((u32) (((Objdrillfield_arg0 *)arg0)->unk6C) >> 0x15);
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

s32 func_8080054C_chfantasydrillfield(Actor *arg0, s32 arg1, BtIntPtr arg2) {
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    s32 _subaddieDll_entrypoint_5(Actor *arg0, Unk80132ED0 *arg1);
    s32 _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800D0B68(u32, u32);
    BtIntPtr func_800D10D4(u32, u32, f32 *, s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_800DA524();
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    f32 func_80103EAC(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A624(Actor *);
    extern s32 D_808008B0_chfantasydrillfield[];
    extern s32 D_80800950_chfantasydrillfield[];
    extern s32 D_80800988_chfantasydrillfield[];
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    Actor *spawn;
    Actor *found;

    switch (arg1) {
    case 0x40:
        if (_subaddieDll_entrypoint_5(arg0, arg2)) {
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
        }
        return 1;
    case 0x3D:
        func_800EE7F8(end, arg0->position);
        func_800EE7F8(start, arg0->position);
        start[1] += 200.0f;
        end[1] -= 200.0f;
        func_800BEF00(start, end, normal, 0);
        switch (D_808008B0_chfantasydrillfield[arg0->actorData[7]]) {
        case 0:
            func_800FFA88(arg0->unk0);
            break;
        case 0x1F7:
            func_80106790(func_800D10D4(0x16, 2, end, 3, 0));
            break;
        default:
            spawn = func_80108528(D_808008B0_chfantasydrillfield[arg0->actorData[7]], end, 0, &arg0);
            if (spawn->unk6C_9 == 0x3DB) {
                spawn->rotation[1] = 20.0f;
            } else if (spawn->unk6C_9 == 0x40D) {
                spawn->unk74_7 = arg0->actorData[7];
            }
            break;
        }
        if (arg2) {
            func_800DA544(arg0->actorData[7] + 0x335);
            _chskeletonexplode_entrypoint_7(arg0, arg0->position);
            func_8010A570(arg0);
            func_8010A624(arg0);
            func_800FFA88(arg0->unk0);
        }
        return 1;
    case 0xF:
        func_800C4140(0x59919413, arg0->position, 0x04B000FA);
        func_800BBCB8(arg0->position, arg0->position, 1.0f, 6, D_80800950_chfantasydrillfield);
        func_800BBCB8(arg0->position, arg0->position, 1.0f, 3, D_80800988_chfantasydrillfield);
        return 1;
    case 0x95:
        if (func_800DA298(arg0->actorData[7] + 0x335)) {
            arg0->unk64_16 = 0;
            func_8010A570(arg0);
            func_8010A624(arg0);
            switch (D_808008B0_chfantasydrillfield[arg0->actorData[7]]) {
            case 0:
                func_800FFA88(arg0->unk0);
                break;
            case 0x1F7:
                if (func_800D0B68(0x16, 2)) {
                    func_800FFA88(arg0->unk0);
                } else {
                    func_80108B04(arg0, 0);
                }
                break;
            default:
                if (!_subaddiefind_entrypoint_5(D_808008B0_chfantasydrillfield[arg0->actorData[7]], &found, 1, arg0->position, func_80103EAC(arg0), func_800EEB40)) {
                    func_80108B04(arg0, 0);
                }
                break;
            }
        }
        func_800DA524(0xA0F);
        return 1;
    default:
        return 0;
    }
}

OSThread *chfantasydrillfield_entrypoint_0(void)
{
    extern ActorData D_808009C4_chfantasydrillfield[];

    return (OSThread *) D_808009C4_chfantasydrillfield;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/drillfield.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808008B0_chfantasydrillfield [8] BT_DATA(4, overlays_ch_fantasy_drillfield, 0x0) = { 1037, 1037, 553, 987, 503, 489, 1190, 0 };
f32 D_808008D0_chfantasydrillfield [8] [ 4 ] BT_DATA(4, overlays_ch_fantasy_drillfield, 0x20) = { { 4845.53f, 2540.0f, -5329.37f, 0.0f }, { 3727.57f, 2540.0f, -5898.67f, 45.0f }, { 3982.39f, 2540.0f, -6356.72f, 335.0f }, { 4253.13f, 2540.0f, -5679.16f, 345.0f }, { 4760.04f, 2540.0f, -5970.08f, 0.0f }, { 5161.16f, 2540.0f, -5691.5f, 25.0f }, { 4477.09f, 2540.0f, -6476.48f, 60.0f }, { 5202.73f, 2540.0f, -6440.36f, -20.0f } };
s32 D_80800950_chfantasydrillfield [14] BT_DATA(4, overlays_ch_fantasy_drillfield, 0xA0) = { 1902889, 1310742, 268828717, 39322400, 2818304, 33554459, -65471264, 2228480, 13369536, 12582919, 131085, 6553649, -3211289, 0 };
s32 D_80800988_chfantasydrillfield [15] BT_DATA(4, overlays_ch_fantasy_drillfield, 0xD8) = { 1903069, 2819072, 83886102, 268435490, 25166336, 75499008, 1376256, 2490393, 7, 2949170, 6553632, -559451712, 852068, 3276750, -1638400 };
ActorData D_808009C4_chfantasydrillfield [1] BT_DATA(4, overlays_ch_fantasy_drillfield, 0x114) = { { 852, 1034, 2092, 1, 0, (void (*)(struct Actor *))func_808004E8_chfantasydrillfield, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080048C_chfantasydrillfield, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9216, (void (*)(struct Actor *, long, long))func_8080054C_chfantasydrillfield, 0 } };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 B_80800A10_chfantasydrillfield [ 2 ] BT_DATA(16, bss_fantasy_drillfield, 0x0);
s32 B_80800A18_chfantasydrillfield [ 14 ] BT_DATA(4, bss_fantasy_drillfield, 0x8);
#endif
