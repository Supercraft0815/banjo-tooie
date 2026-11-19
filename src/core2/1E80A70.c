#include "core2/1E80A70.h"
BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcsectionDll_entrypoint_4(s32);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    s16 mapValue;
    u8 unk12;
    s8 entranceIndex;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    s8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} GameTransitionState;
#include "controller_sequence.inc"
#include "viewport_layout.inc"

BT_IDO_ONLY(extern) GameTransitionState D_80127630;
BT_NATIVE_ONLY(_Static_assert(sizeof(GameTransitionState) == 0x20, "game transition state");)

BT_IDO_ONLY(extern) Gfx *D_80127658 BT_NATIVE_ONLY([3]);
#define FRAME_BUFFERS BT_DATA_FIELD(D_80127658, &D_80127658)
#ifndef BT_NATIVE
extern s32 D_80127674;
extern void* D_801276BC;
typedef struct
{
    void *unk0;
    s32 unk4;
    f32 unk8;
} unk_D_80127688;
extern unk_D_80127688 D_80127688[];
#endif
#include "viewport_slots.inc"
Gfx **func_800A7180(void)
{
    return FRAME_BUFFERS;
}

void func_800A718C(void) {

    void func_800E3BFC(f32, f32, f32);
    void func_800E3C58(f32, f32, f32);
    void func_800E3900(f32);
    void func_800E3CE8(void);
    func_800E3BFC(0.0f, 0.0f, 0.0f);
    func_800E3C58(-30.0f, 30.0f, 0.0f);
    func_800E3900(6000.0f);
    func_800E3CE8();
}

void func_800A71E0(void) {
    void func_8001A570(void);
    void func_8001B840(void);
    void func_800D58CC(void);
    void func_800D58AC(void);
    void func_800CA174(void);
    void func_800FCD5C(void);
    void func_8001B518(s32);
    void func_800DF874(void);
    void func_800C9484(void);
    void func_800B5E3C(void);
    void func_800A9D00(void);
    void func_800B4380(void);
    void func_8008BA5C(void);
    void func_800DA1E0(void);
    void func_800D15CC(void);
    s32 i;

    func_800D58CC();
    func_8001A570();
    func_8001B840();
    for (i = 0; i < 0xF; i++) {
        func_8001B518(1);
        func_800DF874();
        _cosectionstor_entrypoint_2();
        func_800C9484();
        func_800B5E3C();
        func_800D58AC();
        func_800E4C7C();
        func_800CA174();
        func_800FCD5C();
        func_800A9D00();
        func_800C9484();
        func_800B4380();
        func_8008BA5C();
        func_800DA1E0();
        func_800D15CC();
    }
}

void func_800A72A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _gcgame_entrypoint_0(s32 arg0);
    void _gcgame_entrypoint_1(void);
    void _gclevel_entrypoint_0(s32 arg0, s32 arg1);
    void _gclevel_entrypoint_1(void);
    void _gcsectionDll_entrypoint_0(s32 arg0, s32 arg1);
    void _gcsectionDll_entrypoint_1(s32 arg0);
    s32 func_80081724();
    void func_800A8D70(s32, s32);
    void func_800E96E0(void);
    void func_800EA0CC(s32, s32, s32);
    void func_801101C0(void);
    extern u8 D_8012762C;
    s32 sp1C;
    s32 sp18;

    sp1C = D_8012762C;
    sp18 = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(arg0);
    func_800E96E0();
    _gcsectionDll_entrypoint_1(1);
    if (arg3 || arg2 || sp18 != sp1C) {
        _gclevel_entrypoint_1();
        if (arg3) {
            _gcgame_entrypoint_1();
            _gcgame_entrypoint_0(1);
        }
        _gclevel_entrypoint_0(arg0, arg1);
    }
    _gcsectionDll_entrypoint_0(arg0, arg1);
    func_801101C0();
    func_800A8D70(arg0, arg1);
    func_80081724();
    func_800EA0CC(arg0, arg1, 0);
    func_800A718C();
}

/* extern */

void func_800A7380(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1)) {
    s32 func_8001A2B0();
    s32 func_80081724();
    void func_8008B768(void);
    void func_800A71E0(void);
    void func_800A8F68(void);
    void func_800C2AB8(void);
    void func_800D58CC(void);
    void func_800D6C64(void);
    void func_800EA0A8();
    func_800EA0A8(BT_PASS2(arg0, bt_a1));
    func_800A8F68();
    func_800C2AB8();
    func_800FB968();
    func_8001A2B0();
    func_800D6C64();
    func_800D58CC();
    func_8008B768();
    func_80081724();
    if (arg0 != 0) {
        func_800A71E0();
    }
}

void func_800A73F4(s32 arg0, s32 arg1) {
    void func_800A8670(void);
    void func_800A9378(void);
    void func_800A9AA4();
    void func_800A8BA8(Gfx **, s32);
    s32 func_800A8BD4(Gfx **, s32, s32);
    void func_800A8CCC(BtIntPtr, s32);
    s32 func_800A89F8(void);
    void func_800B7448(Gfx **);
    void func_800C0130(BtIntPtr);
    void func_800C0984(BtIntPtr);
    void func_800C9358(Gfx **, s32);
    s32 func_800C940C(BtIntPtr, s32);
    void func_800D36A8(void);
    void func_800E7EF4(Gfx **);
    void func_800E9F20(s32, s32);
    s32 func_800EA358(void);
    void func_800EB51C(s32, BtIntPtr);
    void func_800F5184(void);
    void func_800F51A8(void);
    void func_800FA508(BtIntPtr);
    void func_800FFC90(void);
    BT_IDO_ONLY(extern s16 D_80127632;)
    Mtx *sp24;
    Vtx *sp20;
    Gfx **gfx = FRAME_BUFFERS;

    sp24 = (Mtx *)gfx[1];
    sp20 = (Vtx *)gfx[2];
    func_800A8670();
    func_800A9378();
    func_800F5184();
    func_800A8BA8(gfx, arg1);
    if (!func_800A8BD4(gfx, -1, arg1)) {
        goto views_done;
    }
render_view:
    func_800E9F20(func_800A89F8(), arg1);
    if (func_800A8BD4(gfx, -1, arg1)) {
        goto render_view;
    }
views_done:
    func_800A8CCC((BtIntPtr)gfx, arg1);
    if (BT_DATA_FIELD(D_80127630.unk2, D_80127632) == 5) {
        func_800A9AA4(gfx);
    }
    if (func_800EA358()) {
        func_800EB51C(3, (BtIntPtr)gfx);
    }
    func_800C0984((BtIntPtr)gfx);
    func_800C9358(gfx, arg1);
    func_800C0130((BtIntPtr)gfx);
    if (func_800EA358()) {
        func_800EB51C(4, (BtIntPtr)gfx);
    }
    func_800FA508((BtIntPtr)gfx);
    func_800B7448(gfx);
    func_800C940C((BtIntPtr)gfx, arg1);
    func_800E7EF4(gfx);
    osWritebackDCache(sp24, ((Mtx *)((Gfx *volatile *)gfx)[1] - sp24) * sizeof(Mtx));
    osWritebackDCache(sp20, ((Vtx *)((Gfx *volatile *)gfx)[2] - sp20) * sizeof(Vtx));
    func_800F51A8();
    func_800D36A8();
    func_800FFC90();
    func_800A89BC(0);
}

void func_800A7584(s32 arg0, s32 arg1) {
    D_80127630.unk1A = arg0 + 1;
    D_80127630.unk1B = arg1;
}

void func_800A759C(s32 arg0, s32 arg1) {
    void func_8001608C(void);
    void func_800A9998(void);
    void func_800C08F8(void);
    void func_800C0920(void);
    void func_800C9598(void);
    void func_800C9B84(void);
    void func_800EA148(s32);
    void func_800EA334(s32);
    BT_IDO_ONLY(extern s16 D_80127632;)
    BT_IDO_ONLY(extern f32 D_8012763C;)
    BT_IDO_ONLY(extern u8 D_80127647;)
    s32 previous = BT_DATA_FIELD(D_80127630.unk2, D_80127632);

    if ((BT_DATA_FIELD(D_80127630.unk2, D_80127632) == 3 && arg0 != 4) ||
        (BT_DATA_FIELD(D_80127630.unk2, D_80127632) == 4 && arg0 != 3)) {
        func_800C9B84();
    }
    if (BT_DATA_FIELD(D_80127630.unk2, D_80127632) == 4 && arg0 != 4) {
        func_800C0920();
    }
    if (BT_DATA_FIELD(D_80127630.unk2, D_80127632) == 5) {
        func_800A9AF8();
    }
    BT_DATA_FIELD(D_80127630.unk2, D_80127632) = arg0;
    switch (BT_DATA_FIELD(D_80127630.unk2, D_80127632)) {
        case 2:
            func_800EA148(3);
            break;
        case 5:
            func_800A9998();
        case 3:
            if (previous != 4) {
                func_800EA148(2);
            }
            if (arg1 != 0 && BT_DATA_FIELD(D_80127630.unk17, D_80127647) == 0) {
                func_800C9598();
            }
            BT_DATA_FIELD(D_80127630.unkC, D_8012763C) = 0.0f;
            break;
        case 4:
            func_800EA334(0);
            func_8001608C();
            func_800C08F8();
            break;
    }
}

void func_800A76F4(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1)) {
    s32 _cosectionstor_entrypoint_3(enum map_e);
    BT_IDO_ONLY(s32 _glintrosyncDll_entrypoint_0(s16);) BT_NATIVE_ONLY(void _glintrosyncDll_entrypoint_0(s32);)
    s32 _glintrosyncDll_entrypoint_1();
    void func_80015768(void);
    s32 func_8001A2B0();
    s32 func_80081724();
    void func_800A5C94(void);
    void func_800A5CF0(s32);
    extern u8 D_8012762C;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    func_800FB968();
    _glintrosyncDll_entrypoint_0(D_80127630.mapValue);
    func_8001A2B0();
    sp34 = D_80127630.unk16;
    sp30 = D_80127630.unk15;
    sp2C = D_80127630.unk14;
    sp28 = D_80127630.mapValue;
    sp24 = (u8)D_80127630.entranceIndex;
    sp20 = D_80127630.unk0;
    D_80127630.unk16 = 0;
    D_80127630.unk15 = 0;
    D_80127630.unk14 = 0;
    D_80127630.mapValue = 0;
    D_80127630.entranceIndex = 0;
    func_800A759C(2, 0U);
    D_80127630.unk1C = (u8) (s32) arg0;
    func_800A5CF0(0);
    if (((func_800DA9E4(FLAG2_647_UNK, 0) == 0) || (BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4((s32) D_80127630.mapValue) == D_8012762C)) && (func_800DA298(FLAG2_650_UNK) == 0)) {
        _cosectionstor_entrypoint_3(func_800EA05C());
    }
    func_800A7380(BT_IDO_ONLY(1) BT_PASS2(1, bt_a1));
    func_800A72A4(sp28, sp24, sp30, sp34);
    func_800A5CF0(1);
    func_800A5C94();
    func_80081724();
    _glintrosyncDll_entrypoint_1();
    D_80127630.unk0 = (s16) sp20;
    D_80127630.unk1C = 2;
    func_800A759C(arg0, sp2C);
    func_80015768();
}

void func_800A7840(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    s16 func_80014F58(void);
    void func_80015410(void);
    void func_80015878(void);
    void func_8001A270(Gfx *, Gfx *);
    void func_8001A4B8(void *);
    int func_8001BD50(f32);
    void func_800A73F4(s32, s32);
    void func_800A7FD4(BT_IDO_ONLY(void) BT_PASS2(s32, s32) BT_PASS2(, s32));
    void func_800E4628(void);
    void func_800E82EC(void);

    BT_IDO_ONLY(extern s16 D_80127634;)
    extern s32 D_80127650;
    Gfx *sp1C;
    Gfx *sp18;

    func_8001A4B8(FRAME_BUFFERS);
    if (BT_DATA_FIELD(D_80127630.unk4, D_80127634) != 0) {
        func_8001A4B8(FRAME_BUFFERS);
    }
    sp1C = BT_DATA_FIELD(D_80127658[0], D_80127658);
    func_800A73F4(func_80014F58(), arg0);
    if (BT_DATA_FIELD(D_80127630.unk4, D_80127634) == 0) {
        sp18 = BT_DATA_FIELD(D_80127658[0], D_80127658);
        func_80015410();
        if ((D_80127650 == 0) && (func_8001BD50(0.4f) != 0)) {
            func_800A7FD4(BT_PASS2(arg0, bt_a1) BT_PASS2(, bt_a2));
        }
        func_800E82EC();
        func_8001A270(sp1C, sp18);
    }
    func_80015878();
    func_800E4628();
    BT_DATA_FIELD(D_80127630.unk4, D_80127634) = 0;
    D_80127650 = 0;
}

void func_800A791C(s32 arg0, s32 arg1, s32 arg2)
{
    func_800A79D4(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

/* extern */

void func_800A794C(s32 arg0, s32 arg1, s32 arg2) {
    void func_800A7A18(s32, s32);
    void func_800FE8EC(s32);
    func_800FE8EC(arg0);
    func_800A7A18(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

/* extern */

void func_800A7990(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800A7A6C(s32, s32);
    void func_800FE8EC(s32);
    func_800FE8EC(arg0);
    func_800A7A6C(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

void func_800A79D4(s32 arg0, s32 arg1) {
    func_800FE4E4();
    D_80127630.unk16 = 1;
    D_80127630.unk15 = 0;
    D_80127630.mapValue = (s16) arg0;
    D_80127630.entranceIndex = (s8) arg1;
}

void func_800A7A18(s32 arg0, s32 arg1) {
    void func_800FE8EC(s32);
    GameTransitionState *state;
    func_800FE8EC(arg0);
    state = &D_80127630;
    state->unk16 = 0;
    state->unk15 = 1;
    state->mapValue = (s16)arg0;
    state->entranceIndex = (s8)arg1;
}

void func_800A7A5C(void) 
{
    D_80127630.unk18 = 1;
}
s32 func_800A7A6C(s32 arg0, s32 arg1)
{
    GameTransitionState *state = &D_80127630;
    state->unk16 = 0;
    state->mapValue = (s16)arg0;
    state->entranceIndex = (s8)arg1;
    state->unk15 = state->unk18;
    state->unk18 = 0; BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_800A7A90(s32 arg0) {
    void func_800C9610(void);
    D_80127630.unk14 = (s8) arg0;
    D_80127630.unk17 = 0;
    if ((arg0 != 0) && (func_800C9510() == 0)) {
        func_800C9610();
    }
}

void func_800A7AD4(s32 arg0, s32 arg1) {
    s32 func_800C9510();
    void func_800C964C(s32 arg0);
    D_80127630.unk14 = (s8) arg0;
    D_80127630.unk17 = (s8) arg1;
    if ((arg0 != 0) && (func_800C9510() == 0)) {
        func_800C964C(arg1);
    }
}

//Set Warp Bit To On
void func_800A7B18(u32 warpVal)
{
    D_80127630.unk12 = warpVal;
}

/* extern */

void func_800A7B24(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1)) {
    void _gcgame_entrypoint_1(void);
    void _gclevel_entrypoint_1(void);
    void _gcsectionDll_entrypoint_1(s32 arg0);
    void _glcutDll_entrypoint_2(void);
    void func_80013430(void);
    void func_8008B64C(void);
    void func_800A8710(void);
    void func_800B5DF4(void);
    void func_800C2A90();
    void func_800CA060(void);
    void func_800DF35C(void);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800E4290();
#endif
    void func_800FB908(void);
    func_800A759C(2, 0U);
    func_80013430();
    func_800B5DF4();
    func_800CA060();
    func_800DF35C();
    func_800A7380(BT_IDO_ONLY(0) BT_PASS2(0, bt_a1));
    _gcsectionDll_entrypoint_1(0);
    _gclevel_entrypoint_1();
    _gcgame_entrypoint_1();
    func_8008B64C();
    func_800FB908();
    func_800C2A90();
    func_800A8710();
    func_800E4290();
    _glcutDll_entrypoint_2();
}

void func_800A7BB8(s32 arg0) {
    void _gcgame_entrypoint_0(s32 arg0);
    void _gclevel_entrypoint_0(s32 arg0, s32 arg1);
    void _gcsectionDll_entrypoint_0(s32 arg0, s32 arg1);
    void func_800A5CF0(s32);
    void func_800A861C(void);
    void func_8008B610(void);
    void func_800133A0(void);
    void func_8001A290(void);
    void func_800B5DD4(void);
    void func_800D34A0(void);
    void func_800D3970(void);
    void func_800D8F84(void);
    void func_800D8FA0(s32 arg0);
    void func_800DC310(void);
    void func_800DF38C(void);
    void func_800EBB5C(void);
    void func_800FB808(void);

    func_800A5CF0(1);
    D_80127630.unk12 = 0;
    D_80127630.mapValue = (u8)(D_80127630.entranceIndex =
        D_80127630.unk14 = D_80127630.unk17 =
        D_80127630.unk15 = D_80127630.unk16 = 0);
    D_80127630.unk1A = 0;
    D_80127630.unk1B = 0;
    D_80127630.unk4 = 0;
    func_800A8240();
    func_800DA238();
    func_800DA268();
    _glglobaldata_entrypoint_0();
    _glglobalsettings_entrypoint_1();
    _glgamedata_entrypoint_0();
    func_800D3970();
    func_800E4278();
    func_800A861C();
    func_800C2A08();
    func_800FB808();
    _glcutDll_entrypoint_3();
    func_800CA098();
    func_800D34A0();
    func_800B5DD4();
    func_800133A0();
    func_800DF38C();
    func_8008B610();
    func_800DC310();
    func_8001A290();
    func_800D8F84();
    _gsattract_entrypoint_4();
    func_800EBB5C();
    _gcgame_entrypoint_0(0);
    D_80127630.unk2 = 2;
    D_80127630.unk8 = 0.0f;
    func_800D8FA0(0);
    _gclevel_entrypoint_0(arg0, 0);
    _gcsectionDll_entrypoint_0(arg0, 0);
    func_800A71E0();
    func_800A72A4(arg0, 0, 0, 0);
    D_80127630.unk0 = 0;
    func_800A759C(3, 1);
}

void func_800A7D30(void) {
    s32 func_80014F4C();
    void func_800D8FA0(s32 arg0);
    BT_IDO_ONLY(extern f32 D_80127638;)
    if (BT_DATA_FIELD(D_80127630.unk8, D_80127638) == 0.0f) {
        func_800D8FA0(0);
        return;
    }
    func_800D8FA0(func_80014F4C());
}

s32 func_800A7D84(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1))
{
    s32 sp1C;
    s32 temp_v0;

    D_80127630.unk8 += func_800D8FF8();


    if (func_800C9510() == 0)
    {

        temp_v0 = D_80127630.unk12;
        D_80127630.unk12 = 0U;
        if (temp_v0 != 0)
        {
            switch (temp_v0)
            {
            case 1:
                func_800A76F4(BT_IDO_ONLY(3) BT_PASS2(3, bt_a1));
                return 0;
            case 2:
                func_800A76F4(BT_IDO_ONLY(D_80127630.unk2) BT_PASS2(D_80127630.unk2, bt_a1));
                return 0;
            case 3:
                func_800A9924(D_80127630.mapValue, D_80127630.entranceIndex);
                func_800A76F4(BT_IDO_ONLY(5) BT_PASS2(5, bt_a1));
                return 0;
            }
        }
        temp_v0 = D_80127630.unk1A;
    }

    if (D_80127630.unk1A != 0)
    {
        func_800A759C(D_80127630.unk1A - 1, D_80127630.unk1B);
        D_80127630.unk1A = 0U;
    }
    sp1C = func_800EA170();

    if ((D_8011A3F4 != 0) && (D_8011A3F0 == 0))
    {
        func_800A8278();
    }
    func_800C7900();
    func_800C427C();
    func_800FB968();
    switch (D_80127630.unk2)
    {
    case 5:
        func_800A9A14();
        break;
    case 3:
        D_80127630.unkC += func_800D8FF8();
        if ((0.6f < D_80127630.unkC) && (func_800C0A34() != 0))
        {
            func_800A759C(4, 0U);
        }
        else if (sp1C == 0)
        {
            func_800A759C(3, 1U);
        }
        break;
    case 4:
        if (func_800C0948() != 0)
        {
            func_800EA334(1);
            func_800EA34C(1);
            func_800A759C(3, 0U);
            func_800FFC14();
            func_800F8850();
        }
    }
    if (func_800A819C() != 0)
    {
        func_800CA0A8();
    }
    func_800C92A8();
    return 1;

}

void func_800A7FB4(s32 arg0, s32 arg1)
{
    func_800A7584(arg0, arg1);
}


extern s32 D_80127650;

void func_8001B84C(void);
void func_8001B840(void);
void defragment_overlays(void);
void func_8001B518(s32);
void func_801015C8(void);
void func_80017840(void);
void func_800D8674(void);
void func_8008BA5C(void);
void func_800B5A6C(void);
void func_800A5654(void);
void func_800DF874(void);
void func_800A95C4(BT_IDO_ONLY(void) BT_PASS2(s32, s32) BT_PASS2(, s32));
void func_800F86D8(void);
void func_800F91EC(void);
void func_800B562C(void);
void func_800BF58C(void);
void func_800BD600(void);
void func_800CCFEC(void);
void func_800A5D6C(void);
void func_800B5E3C(void);
void func_800DA1E0(void);
void func_800D15CC(void);
void func_8010E030(void);
void func_800C075C(void);
void func_800C08C0(void);
void func_801005B8(void);
void func_800D6D68(void);
void func_80100E54(void);
void func_800BFFF4(void);
void func_800C9074(void);
void func_800DBB64(void);
void func_800E8B3C(void);
void func_800A86D8(void);
void func_800EE670(void);
void func_800ABA20(void);
void func_800FA608(void);
void func_800E8A20(void);
void func_800A9D00(void);
void func_800C9484(void);
void func_800B4380(void);
void func_800EB7A8(void);
void func_800D88C0(void);
void func_800FFE08(void);
s32 func_8001B858(void);

// do_tidy
void func_800A7FD4(BT_IDO_ONLY(void) BT_PASS2(s32 bt_a0, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    D_80127650 = 1;
    func_8001B84C();
    func_8001B840();
    defragment_overlays();
    func_8001B518(0);
    func_801015C8();
    func_80017840();
    func_800D8674();
    func_8008BA5C();
    func_800B5A6C();
    func_800A5654();
    func_800DF874();
    func_800A95C4(BT_PASS2(bt_a0, bt_a1) BT_PASS2(, bt_a2));
    func_800F86D8();
    func_800F91EC();
    func_800B562C();
    func_800BF58C();
    func_800BD600();
    func_800CCFEC();
    func_800A5D6C();
    func_800B5E3C();
    func_800DA1E0();
    func_800D15CC();
    func_8010E030();
    func_800C075C();
    if (D_80127630.unk2 == 4) {
        func_800C08C0();
    }
    func_801005B8();
    func_800D6D68();
    func_80100E54();
    func_800BFFF4();
    func_800C9074();
    func_800DBB64();
    func_800E8B3C();
    func_800A86D8();
    func_800EE670();
    func_800ABA20();
    func_800FA608();
    func_800E8A20();
    func_800A9D00();
    func_800C9484();
    func_800B4380();
    func_800EB7A8();
    func_800D88C0();
    func_800FFE08();
    func_8001B858();
}

void func_800A8168(void) {
    D_80127630.unk4 = 1;
}

s16 func_800A8178(void) {
    return D_80127630.unk4;
}

s16 func_800A8184(void) {
    return D_80127630.unk2;
}

u8 func_800A8190(void) {
    return D_80127630.unk1C;
}

int func_800A819C(void) {
    return D_80127630.unk2 == 3 || D_80127630.unk2 == 5;
}

int func_800A81C4(void) {
    s32 a, b;
    if (D_80127630.mapValue == 0) {
        return 0;
    }
    a = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(D_80127630.mapValue);
    b = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(func_800EA05C());
    return b != a && D_80127630.unk6 == 0;
}

void func_800A8230(void) {
    D_80127630.unk6 = 1;
}

void func_800A8240(void) {
    D_80127630.unk6 = 0;
}

s16 func_800A824C(void) {
    return D_80127630.unk6;
}

f32 func_800A8258(void) {
    return D_80127630.unk8;
}

int func_800A8264(void) {
    return D_80127630.unk12 != 0;
}

void func_800A8278(void) {
    void func_80015E80(s32, void *);
    void func_80015F28(s32, void *);
    s32 func_80015F84(s32);
    void func_80015FFC(s32, void *);


    s32 current;
    s32 i;
    s32 buttons[14];

    D_8011A3F4--;
    func_80015E80(0, buttons);
    func_80015F28(0, &buttons[6]);
    func_80015FFC(0, &buttons[9]);
    buttons[13] = func_80015F84(0);
    current = D_8011A3F8[D_8011A418];
    if (buttons[current] == 1) {
        D_8011A418++;
    }
    for (i = 0; i < 14; i++) {
        if (i != current && buttons[i] == 1) {
            D_8011A418 = 0;
            break;
        }
    }
    if (D_8011A3F8[D_8011A418] == -1) {
        D_8011A3F0 = 1;
    }
}    typedef struct { u8 pad0[0x8]; s32 unk8; s32 unkC; s32 unk10; } Obj1E80A70_D_80127670; /* offsets.py genstruct: fields from raw offsets on &D_80127670; rename once understood */

s32 func_800A8380(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_80127670;)
    s32 base;

    if (VIEWPORT_SPLIT_VERTICAL == 0) {
        base = 1;
    } else {
        base = 7;
    }
    switch (VIEWPORT_COUNT) {
        case 2:
            return base + arg0;
        case 3:
            if (base == 1) {
                return arg0 != 0 ? arg0 + 4 : base;
            }
            return arg0 != 0 ? arg0 * 2 + 2 : base;
        case 4:
            return arg0 + 3;
        default:
            return 0;
    }
}    typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Obj1E80A70_func_800A8424_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800A8424(BtIntPtr arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {

    BT_IDO_ONLY(extern s32 D_80127670;)
    s16 *temp_v0;

    temp_v0 = D_8011A420.bounds[arg0];
    *arg1 = VIEWPORT_HALF_WIDTH * temp_v0[0];
    if ((((Obj1E80A70_func_800A8424_temp_v0 *)temp_v0)->unk0) == 1) {
        *arg1 += 1;
    }
    *arg2 = VIEWPORT_HALF_HEIGHT * temp_v0[1];
    if ((((Obj1E80A70_func_800A8424_temp_v0 *)temp_v0)->unk2) != 0) {
        *arg2 += 1;
    }
    *arg3 = VIEWPORT_HALF_WIDTH * temp_v0[2];
    if ((((Obj1E80A70_func_800A8424_temp_v0 *)temp_v0)->unk4) == 1) {
        *arg3 -= 1;
    }
    *arg4 = VIEWPORT_HALF_HEIGHT * temp_v0[3];
    if ((((Obj1E80A70_func_800A8424_temp_v0 *)temp_v0)->unk6) == 1) {
        *arg4 -= 1;
    }
}

/* extern */

s32 func_800A84EC(s32 arg0, BtIntPtr arg1) {
    void func_800158E4(s32 *);
    void *func_8001592C(s32, s32, s32, s32);
    void func_80015CE8(void *, void *);
    void func_800C54CC(s32, f32, f32);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    if (viewportSlots[arg0].unk0 != NULL) {
        func_800158E4(viewportSlots[arg0].unk0);
    }
    func_800A8424(arg1, &sp34, &sp30, &sp2C, &sp28);
    viewportSlots[arg0].unk0 = func_8001592C(sp34, sp30, sp2C, sp28);
    arg1 = viewportSlots[arg0].unk4;
    viewportSlots[arg0].unk8 = 40.0f;
    if (arg1 != 0) {
        func_80015CE8(viewportSlots[arg0].unk0, arg1);
    }
    func_800C54CC(arg0, 40.0f, 1.0f); BT_NATIVE_ONLY(return 0;)
}

s32 func_800A85A8(void) {
    s32 func_800A8380(s32);
    s32 func_800A84EC(s32, BtIntPtr);
    s32 var_s0;
    ViewportSlot *var_s1;

    var_s1 = viewportSlots;
    var_s0 = 0;
    do {
        if (var_s1->unk0 != 0) {
            func_800A84EC(var_s0, func_800A8380(var_s0));
        }
        var_s0 += 1;
        var_s1++;
    } while (var_s0 != 4);
    return func_800A84EC(4, 0);
}

void func_800A861C(void) {
    s32 func_800A84EC(s32, BtIntPtr);
    BT_IDO_ONLY(extern s32 D_80127678;)

    BT_DATA_FIELD(VIEWPORT_SPLIT_VERTICAL, D_80127678) = 0;
    viewportSlots[4].unk4 = (BtIntPtr) func_800CA334();
    func_800E42B4(viewportSlots[4].unk4);
    func_800A84EC(4, 0);
    func_800C5464();
    func_800A89BC(4);
}

void func_800A8670(void)
{
  void func_800C54F0(s32 arg0);
  s32 var_s0;
  ViewportSlot *var_s1;
  BtIntPtr *new_var;
 var_s0 = 0; var_s1 = viewportSlots; do {
    new_var = &var_s1->unk4;
    if ((var_s1->unk0 != 0) && ((*new_var) != 0))
    {
      func_800C54F0(var_s0);
    }
    var_s0 += 1;
    var_s1 += 1;
  }
  while (var_s0 != 5);
}

void func_800A86D8(void)
{
    if (VIEWPORT_DEFAULT_CAMERA != 0)
    {
        VIEWPORT_DEFAULT_CAMERA = func_800CA384(VIEWPORT_DEFAULT_CAMERA);
    }
}

void func_800A8710(void)
{
    extern s32 D_801276C4;
    ViewportReleaseEntry *var_s0;
    BtIntPtr temp_a0;
    void func_800158E4(s32 *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800CA364(s32);
#endif
    BT_LP64_ONLY(func_800E42B4(NULL);) func_800CA364(viewportSlots[4].unk4);
    viewportSlots[4].unk4 = 0;
    var_s0 = VIEWPORT_RELEASE_BEGIN; do {
        temp_a0 = (BtIntPtr) VIEWPORT_RELEASE_HANDLE(var_s0);
        if (temp_a0 != 0) {
            func_800158E4((s32 *)temp_a0);
            VIEWPORT_RELEASE_HANDLE(var_s0) = 0;
        }
        var_s0++;
    } while (var_s0 != VIEWPORT_RELEASE_END);
}

s32 func_800A877C(s32 arg0) {
    s32 func_800A8380(s32);
    s32 func_800A84EC(s32, BtIntPtr);
    s32 func_800A85A8();
    BT_IDO_ONLY(extern s32 D_80127670;)
    if (viewportSlots[arg0].unk0 != 0) {
        return 1;
    } else {
        if (arg0 >= VIEWPORT_COUNT) {
            VIEWPORT_COUNT = arg0 + 1;
            func_800A85A8();
        }
        func_800A84EC(arg0, func_800A8380(arg0));
    }
    return 1;
}

s32 func_800A87FC(s32 arg0) {
    void func_800158E4(s32 *);
    BT_IDO_ONLY(extern s32 D_80127670;)
    s32 i;

    if (viewportSlots[arg0].unk0 == NULL) {
        return 0;
    }
    func_800158E4(viewportSlots[arg0].unk0);
    viewportSlots[arg0].unk0 = NULL;
    viewportSlots[arg0].unk4 = 0;
    if (arg0 + 1 == VIEWPORT_COUNT) {
        VIEWPORT_COUNT = 0;
        i = 0;
        do {
            i++;
            if (viewportSlots[arg0].unk0 != NULL) {
                VIEWPORT_COUNT++;
            }
        } while (i != 4);
        func_800A85A8();
    }
    if (VIEWPORT_COUNT == 0) {
        func_800E42B4((BtIntPtr)VIEWPORT_DEFAULT_CAMERA);
    }
    return 1;
}

/* extern */
#if !defined(BT_NATIVE) || defined(BT_ILP32)
BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800A88C4(s32 arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void func_80015CE8(void *, void *);
    BtIntPtr sp1C;

    arg2 = (BtIntPtr)viewportSlots[arg0].unk0;
    if (arg2 == 0) {
        return 0;
    }
    sp1C = viewportSlots[arg0].unk4;
    viewportSlots[arg0].unk4 = arg1;
    func_80015CE8(arg2, arg1);
    if (arg0 == VIEWPORT_CURRENT) {
        func_800E42B4(viewportSlots[arg0].unk4);
    }
    return sp1C;
}

BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800A8948(s32 arg0)
{
    BtIntPtr temp_v0;

    if (viewportSlots[arg0].unk0 == 0)
    {
        return 0;
    }
    temp_v0 = viewportSlots[arg0].unk4;
    viewportSlots[arg0].unk4 = 0;
    return temp_v0;
}

BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800A8984(s32 arg0)
{
    return viewportSlots[arg0].unk4;
}
#endif
void *func_800A89A0(s32 arg0) 
{
    return viewportSlots[arg0].unk0;
}

void func_800A89BC(s32 arg0)
{
    VIEWPORT_CURRENT = arg0;
    func_800E42B4(viewportSlots[arg0].unk4);
}

s32 func_800A89F8()
{
    return VIEWPORT_CURRENT;
}

void func_800A8A04(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4)
{
    func_80015CC0(viewportSlots[arg0].unk0, arg1, arg2, arg3, arg4);
}

/* extern */

void func_800A8A44(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 func_800A8380(s32);
    void func_800A8424(BtIntPtr, s32 *, s32 *, s32 *, s32 *);
    func_800A8424(func_800A8380(arg0), arg1, arg2, arg3, arg4);
}

/* extern */

void func_800A8A88(s32 arg0, f32 arg1) {
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800CA558(s32, f32);
#endif
    BtIntPtr temp_a2;
    ViewportSlot *temp_v0;

    temp_v0 = &viewportSlots[arg0];
    temp_a2 = temp_v0->unk4;
    temp_v0->unk8 = arg1;
    if (temp_a2 != 0) {
        func_800CA558(temp_a2, arg1);
    }
}

f32 func_800A8AD4(s32 arg0) 
{
    return viewportSlots[arg0].unk8;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) func_800A8AF0(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_80015D14(viewportSlots[arg0].unk0);
}

/* extern */

void func_800A8B24(BtIntPtr arg0, s32 arg1) {
    void func_800157EC(s32 *arg0, Gfx **arg1);
    void func_800E7EC0(Gfx** gfx);
    void func_800E7FB0(s32 x, s32 y, s32 width, s32 height);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    BtIntPtr sp24;

    sp24 = viewportSlots[VIEWPORT_CURRENT].unk0;
    func_80015CC0(sp24, (BtIntPtr) &sp34, (BtIntPtr) &sp30, (BtIntPtr) &sp2C, (BtIntPtr) &sp28);
    func_800E7FB0(sp34, sp30, sp2C, sp28);
    func_800E7EC0(arg0);
    func_800157EC(sp24, arg0);
}

void func_800A8BA8(Gfx** arg0, s32 arg1)
{
    VIEWPORT_CURRENT = -1;
    func_800E7E70(arg0);
}

s32 func_800A8BD4(Gfx **arg0, s32 arg1, s32 arg2) {
    void func_800C5668(s32, Gfx **);
    BT_IDO_ONLY(extern s32 D_80127670;)

    if (arg1 >= 0) {
        VIEWPORT_DRAW_INDEX = arg1 - 1;
    }
    if ((VIEWPORT_DRAW_INDEX >= 0) &&
        (viewportSlots[VIEWPORT_DRAW_INDEX].unk4 != 0)) {
        func_800C5668(VIEWPORT_DRAW_INDEX, arg0);
    }
    VIEWPORT_DRAW_INDEX++;
    for (; VIEWPORT_DRAW_INDEX < 4; VIEWPORT_DRAW_INDEX++) {
        if (viewportSlots[VIEWPORT_DRAW_INDEX].unk0 != 0) {
            break;
        }
    }
    if (VIEWPORT_DRAW_INDEX >= 4) {
        return 0;
    }
    func_800A89BC(VIEWPORT_DRAW_INDEX);
    func_800A8B24(arg0, arg2);
    return 1;
}

void func_800A8CCC(BtIntPtr arg0, s32 arg1)
{
    func_800A89BC(4);
    func_800A8B24(arg0, arg1);
}

void func_800A8D00(s32 arg0, s32 arg1) {
    s32 func_800A85A8();
    BT_IDO_ONLY(extern s32 D_80127670;)
    if ((arg0 != (VIEWPORT_HALF_WIDTH * 2)) || (arg1 != (VIEWPORT_HALF_HEIGHT * 2))) {
        VIEWPORT_HALF_WIDTH = (s32) (arg0 / 2);
        VIEWPORT_HALF_HEIGHT = (s32) (arg1 / 2);
        func_800A85A8();
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80127650 BT_DATA(4, bss_core2bss1_0_1, 0x5F0);
s32 D_801276C4 BT_DATA(4, bss_core2bss1_0_1, 0x664);
u8 D_8012AB54 BT_DATA(4, bss_core2bss1_1, 0x74);
MtxF D_8012D510 BT_DATA(4, bss_core2bss2_1, 0xBD0);
u16 D_8012D550 BT_DATA(4, bss_core2bss2_1, 0xC10);
#endif
