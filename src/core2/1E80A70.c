#include "core2/1E80A70.h"

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
    s32 unk14;
    s8 unk18;
    s8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_80127630_unk;
extern s32 D_8011A3F0;
extern s32 D_8011A3F4;
extern f32 D_801255F8;
extern D_80127630_unk D_80127630;

extern s32 D_80127658;
extern s32 D_80127674;
extern void* D_801276BC;
typedef struct
{
    s32 unk0, unk4;
    f32 unk8;
} unk_D_80127688;
extern unk_D_80127688 D_80127688[];

s32* func_800A7180(void)
{
    return &D_80127658;
}

void func_800A718C(void) {
    extern f32 D_801255F0;
    void func_800E3BFC(f32, f32, f32);
    void func_800E3C58(f32, f32, f32);
    void func_800E3900(f32);
    void func_800E3CE8(void);
    func_800E3BFC(0.0f, 0.0f, 0.0f);
    func_800E3C58(-30.0f, 30.0f, 0.0f);
    func_800E3900(D_801255F0);
    func_800E3CE8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A71E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A72A4.s")

/* extern */

void func_800A7380(s32 arg0) {
    s32 func_8001A2B0();
    s32 func_80081724();
    s32 func_8008B768();
    s32 func_800A71E0();
    s32 func_800A8F68();
    s32 func_800C2AB8();
    s32 func_800D58CC();
    s32 func_800D6C64();
    s32 func_800EA0A8();
    func_800EA0A8();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A73F4.s")

void func_800A7584(s32 arg0, s32 arg1) {
    D_80127630.unk1A = arg0 + 1;
    D_80127630.unk1B = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A759C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A76F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7840.s")

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
    (*(s8 *)((s8 *)(&D_80127630) + (0x16))) = 1;
    (*(s8 *)((s8 *)(&D_80127630) + (0x15))) = 0;
    D_80127630.mapValue = (s16) arg0;
    D_80127630.entranceIndex = (s8) arg1;
}

void func_800A7A18(s32 arg0, s32 arg1) {
    void func_800FE8EC(s32);
    D_80127630_unk *state;
    func_800FE8EC(arg0);
    state = &D_80127630;
    *((s8 *)state + 0x16) = 0;
    *((s8 *)state + 0x15) = 1;
    state->mapValue = (s16)arg0;
    state->entranceIndex = (s8)arg1;
}

void func_800A7A5C(void) 
{
    D_80127630.unk18 = 1;
}
s32 func_800A7A6C(s32 arg0, s32 arg1)
{
    D_80127630_unk *state = &D_80127630;
    *((s8 *)state + 0x16) = 0;
    state->mapValue = (s16)arg0;
    state->entranceIndex = (s8)arg1;
    *((u8 *)state + 0x15) = *((u8 *)state + 0x18);
    state->unk18 = 0;
}

/* extern */

void func_800A7A90(s32 arg0) {
    s32 func_800C9610();
    (*(s8 *)((s8 *)(&D_80127630) + (0x14))) = (s8) arg0;
    (*(s8 *)((s8 *)(&D_80127630) + (0x17))) = 0;
    if ((arg0 != 0) && (func_800C9510() == 0)) {
        func_800C9610();
    }
}

void func_800A7AD4(s32 arg0, s32 arg1) {
    s32 func_800C9510();
    void func_800C964C(s32 arg0);
    (*(s8 *)((s8 *)(&D_80127630) + (0x14))) = (s8) arg0;
    (*(s8 *)((s8 *)(&D_80127630) + (0x17))) = (s8) arg1;
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

void func_800A7B24(void) {
    s32 _gcgame_entrypoint_1();
    s32 _gclevel_entrypoint_1();
    s32 _gcsectionDll_entrypoint_1(s32);
    s32 _glcutDll_entrypoint_2();
    s32 func_80013430();
    s32 func_8008B64C();
    void func_800A8710(void);
    s32 func_800B5DF4();
    s32 func_800C2A90();
    s32 func_800CA060();
    s32 func_800DF35C();
    s32 func_800E4290();
    s32 func_800FB908();
    func_800A759C(2, 0U);
    func_80013430();
    func_800B5DF4();
    func_800CA060();
    func_800DF35C();
    func_800A7380(0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7BB8.s")

void func_800A7D30(void) {
    s32 func_80014F4C();
    s32 func_800D8FA0(s32);
    extern f32 D_80127638;
    if (D_80127638 == 0.0f) {
        func_800D8FA0(0);
        return;
    }
    func_800D8FA0(func_80014F4C());
}

s32 func_800A7D84(void)
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
                func_800A76F4(3);
                return 0;
            case 2:
                func_800A76F4(D_80127630.unk2);
                return 0;
            case 3:
                func_800A9924(D_80127630.mapValue, D_80127630.entranceIndex);
                func_800A76F4(5);
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
        if ((D_801255F8 < D_80127630.unkC) && (func_800C0A34() != 0))
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
void func_800A95C4(void);
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
void func_8001B858(void);

// do_tidy
void func_800A7FD4(void) {
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
    func_800A95C4();
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
    a = _gcsectionDll_entrypoint_4(D_80127630.mapValue);
    b = _gcsectionDll_entrypoint_4(func_800EA05C());
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A84EC.s")

s32 func_800A85A8(void) {
    s32 func_800A8380(s32);
    s32 func_800A84EC(s32, s32);
    s32 var_s0;
    unk_D_80127688 *var_s1;

    var_s1 = D_80127688;
    var_s0 = 0;
    do {
        if (var_s1->unk0 != 0) {
            func_800A84EC(var_s0, func_800A8380(var_s0));
        }
        var_s0 += 1;
        var_s1 = (unk_D_80127688 *)((u8 *)var_s1 + 0xC);
    } while (var_s0 != 4);
    return func_800A84EC(4, 0);
}

void func_800A861C(void) {
    s32 func_800A84EC(s32, s32);
    extern s32 D_80127678;

    D_80127678 = 0;
    D_80127688[4].unk4 = (s32) func_800CA334();
    func_800E42B4(D_80127688[4].unk4);
    func_800A84EC(4, 0);
    func_800C5464();
    func_800A89BC(4);
}

void func_800A8670(void)
{
  s32 func_800C54F0(s32);
  s32 var_s0;
  unk_D_80127688 *var_s1;
  s32 *new_var;
 var_s0 = 0; var_s1 = D_80127688; do {
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
    if (D_801276BC != 0)
    {
        D_801276BC = func_800CA384(D_801276BC);
    }
}

void func_800A8710(void)
{
    extern s32 D_801276C4;
    s32 (*var_s0)[3];
    s32 temp_a0;
    void func_800158E4(s32 *);
    s32 func_800CA364(s32);
    func_800CA364(D_80127688[4].unk4);
    D_80127688[4].unk4 = 0;
    var_s0 = (s32 (*)[3])((s8 *)&D_801276BC - 0x34); do {
        temp_a0 = var_s0[0][0];
        if (temp_a0 != 0) {
            func_800158E4((s32 *)temp_a0);
            var_s0[0][0] = 0;
        }
        var_s0++;
    } while (var_s0 != (s32 (*)[3])&D_801276C4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A877C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A87FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A88C4.s")

s32 func_800A8948(s32 arg0)
{
    s32 temp_v0;

    if (D_80127688[arg0].unk0 == 0)
    {
        return 0;
    }
    temp_v0 = D_80127688[arg0].unk4;
    D_80127688[arg0].unk4 = 0;
    return temp_v0;
}

s32 func_800A8984(s32 arg0) 
{
    return D_80127688[arg0].unk4;
}

s32 func_800A89A0(s32 arg0) 
{
    return D_80127688[arg0].unk0;
}

void func_800A89BC(s32 arg0)
{
    D_80127674 = arg0;
    func_800E42B4(D_80127688[arg0].unk4);
}

s32 func_800A89F8()
{
    return D_80127674;
}

void func_800A8A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_80015CC0(D_80127688[arg0].unk0, arg1, arg2, arg3, arg4);
}

/* extern */

void func_800A8A44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800A8380(s32);
    s32 func_800A8424(s32, s32, s32, s32, s32);
    func_800A8424(func_800A8380(arg0), arg1, arg2, arg3, arg4);
}

/* extern */

void func_800A8A88(s32 arg0, f32 arg1) {
    s32 func_800CA558(s32, f32);
    s32 temp_a2;
    unk_D_80127688 *temp_v0;

    temp_v0 = &D_80127688[arg0];
    temp_a2 = temp_v0->unk4;
    temp_v0->unk8 = arg1;
    if (temp_a2 != 0) {
        func_800CA558(temp_a2, arg1);
    }
}

f32 func_800A8AD4(s32 arg0) 
{
    return D_80127688[arg0].unk8;
}

void func_800A8AF0(s32 arg0)
{
    func_80015D14(D_80127688[arg0].unk0);
}

/* extern */

void func_800A8B24(s32 arg0, s32 arg1) {
    s32 func_800157EC(s32, s32);
    s32 func_800E7EC0(s32);
    s32 func_800E7FB0(s32, s32, s32, s32);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp24 = D_80127688[D_80127674].unk0;
    func_80015CC0(sp24, (s32) &sp34, (s32) &sp30, (s32) &sp2C, (s32) &sp28);
    func_800E7FB0(sp34, sp30, sp2C, sp28);
    func_800E7EC0(arg0);
    func_800157EC(sp24, arg0);
}

void func_800A8BA8(Gfx** arg0, s32 arg1)
{
    D_80127674 = -1;
    func_800E7E70(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8BD4.s")

void func_800A8CCC(s32 arg0, s32 arg1)
{
    func_800A89BC(4);
    func_800A8B24(arg0, arg1);
}

void func_800A8D00(s32 arg0, s32 arg1) {
    s32 func_800A85A8();
    extern s32 D_80127670;
    if ((arg0 != ((*(s32 *)((s8 *)(&D_80127670) + (0xC))) * 2)) || (arg1 != ((*(s32 *)((s8 *)(&D_80127670) + (0x10))) * 2))) {
        (*(s32 *)((s8 *)(&D_80127670) + (0xC))) = (s32) (arg0 / 2);
        (*(s32 *)((s8 *)(&D_80127670) + (0x10))) = (s32) (arg1 / 2);
        func_800A85A8();
    }
}
