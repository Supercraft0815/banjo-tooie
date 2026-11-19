#include "common.h"
#include "prop_triggers.inc"
void func_800D5250()
{
    func_800D52B0();
}

void func_800D5270(void)
{
    extern u8 D_8012B431;

    D_8012B431 = 0;
}    typedef struct { u8 unk0; s8 unk1; s16 unk2; } Obj1EAEB40_D_8012B430; /* offsets.py genstruct: fields from raw offsets on &D_8012B430; rename once understood */

void func_800D527C(s32 arg0) {
    extern u8 D_8012B430;
    (((Obj1EAEB40_D_8012B430 *)&D_8012B430)->unk0) = arg0 + 1;
    (((Obj1EAEB40_D_8012B430 *)&D_8012B430)->unk1) = 1;
}    typedef struct { u8 unk0; } Obj1EAEB40_D_8012B431; /* offsets.py genstruct: fields from raw offsets on &D_8012B431; rename once understood */

u32 func_800D5298(void) {
    extern u8 D_8012B431;
    return *&((Obj1EAEB40_D_8012B431 *)&D_8012B431)->unk0;
}

u32 func_800D52A4(void) {
    extern u8 D_8012B430;
    return *&((Obj1EAEB40_D_8012B430 *)&D_8012B430)->unk0;
}

int func_800D52B0(void) {
    extern u8 D_8012B430;
    (((Obj1EAEB40_D_8012B430 *)&D_8012B430)->unk1) = 0;
    (((Obj1EAEB40_D_8012B430 *)&D_8012B430)->unk2) = -1;
    (*(s8 *)((s8 *)(&D_8012B430) + (0))) = 0; BT_NATIVE_ONLY(return 0;)
}

void func_800D52CC(s32 arg0) {
    int func_800D52B0();
    extern s16 D_8012B432;
    func_800D52B0();
    D_8012B432 = (s16) arg0;
}    typedef struct { s16 unk0; } Obj1EAEB40_D_8012B432; /* offsets.py genstruct: fields from raw offsets on &D_8012B432; rename once understood */

s32 func_800D52F4(void) {
    extern s16 D_8012B432;
    return *&((Obj1EAEB40_D_8012B432 *)&D_8012B432)->unk0;
}

void func_800D5300(Prop *prop, Unk80132ED0 *marker) {
}
void func_800D530C(Prop *prop, Unk80132ED0 *marker) {
}                     typedef struct { u8 pad0[0x8]; u16 unk8; u8 padA[0x2]; s32 unkC; } Obj1EAEB40_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void func_800D5318(Prop *arg0, Unk80132ED0 *arg1) {
    extern s32 _gspropctrl_entrypoint_2(void *);
    extern s32 _gspropctrl_entrypoint_3(void *);
    extern s32 _gspropctrl_entrypoint_4(void *);
    extern void _gspropctrl_entrypoint_5(void *, s32);
    extern s32 func_8001211C(void);
    extern s32 _gcsectionskip_entrypoint_1(BtIntPtr arg0, s32 arg1, s32 arg2, u32 arg3, u8 *arg4);


    s32 frame;

    switch (_gspropctrl_entrypoint_2(arg0)) {
        case 3:
            frame = func_8001211C();
            if (_gspropctrl_entrypoint_3(arg0) + 1 != frame) {
                D_8011B680[_gspropctrl_entrypoint_4(arg0)](arg0, arg1);
            }
            _gspropctrl_entrypoint_5(arg0, frame);
            break;
        case 5:
            _gcsectionskip_entrypoint_1((BtIntPtr)arg0, arg0->ItemID + 0xA0,
                BT_DATA_FIELD(arg0->unkC_0, ((Obj1EAEB40_arg0 *)arg0)->unkC & 0x7FFFFF),
                BT_DATA_FIELD((u8)arg0->unkA, *((u8 *)arg0 + 0xB)), (u8 *)arg1);
            break;
        case 4:
            D_8011B7C0[_gspropctrl_entrypoint_4(arg0)](arg0, arg1);
            break;
    }
}

s32 func_800D5424(s32 arg0) {
    return arg0 - 0x16;
}

s32 func_800D542C(s32 arg0) {
    return arg0 + 0x9A;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_8012B430 BT_DATA(4, bss_core2bss1_2_status_tail, 0x10);
u8 D_8012B431 BT_DATA(4, bss_core2bss1_2_status_tail, 0x11);
s16 D_8012B432 BT_DATA(4, bss_core2bss1_2_status_tail, 0x12);
#endif
