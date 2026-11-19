#include "common.h"
typedef struct PlayerState PlayerState;

void _bsbtrot_entrypoint_0(PlayerState *);
void _bsbtrot_entrypoint_1(PlayerState *);
void _bsbtrot_entrypoint_10(PlayerState *);
void _bsbtrot_entrypoint_12(PlayerState *);
void _bsbtrot_entrypoint_13(void *);
void _bsbtrot_entrypoint_14(BtIntPtr);
void _bsbtrot_entrypoint_16(BtIntPtr);
void _bsbtrot_entrypoint_17(PlayerState *);
void _bsbtrot_entrypoint_18(BtIntPtr);
void _bsbtrot_entrypoint_2(BtIntPtr);
void _bsbtrot_entrypoint_20(PlayerState *);
void _bsbtrot_entrypoint_21(PlayerState *);
void _bsbtrot_entrypoint_22(PlayerState *);
void _bsbtrot_entrypoint_24(PlayerState *);
void _bsbtrot_entrypoint_25(void *);
void _bsbtrot_entrypoint_26(PlayerState *);
void _bsbtrot_entrypoint_28(BtIntPtr);
void _bsbtrot_entrypoint_29(PlayerState *);
void _bsbtrot_entrypoint_30(PlayerState *);
void _bsbtrot_entrypoint_32(PlayerState *);
void _bsbtrot_entrypoint_33(PlayerState *);
void _bsbtrot_entrypoint_34(void *);
void _bsbtrot_entrypoint_36(PlayerState *);
void _bsbtrot_entrypoint_37(BtIntPtr);
void _bsbtrot_entrypoint_38(BtIntPtr);
void _bsbtrot_entrypoint_4(PlayerState *);
void _bsbtrot_entrypoint_40(PlayerState *);
void _bsbtrot_entrypoint_41(PlayerState *);
void _bsbtrot_entrypoint_42(PlayerState *);
void _bsbtrot_entrypoint_44(BtIntPtr);
void _bsbtrot_entrypoint_45(BtIntPtr);
void _bsbtrot_entrypoint_46(PlayerState *);
void _bsbtrot_entrypoint_48(void *);
void _bsbtrot_entrypoint_49(PlayerState *);
void _bsbtrot_entrypoint_5(PlayerState *);
void _bsbtrot_entrypoint_50(BtIntPtr);
void _bsbtrot_entrypoint_52(void *);
void _bsbtrot_entrypoint_53(PlayerState *);
void _bsbtrot_entrypoint_54(BtIntPtr);
void _bsbtrot_entrypoint_6(PlayerState *);
void _bsbtrot_entrypoint_8(BtIntPtr);
void _bsbtrot_entrypoint_9(PlayerState *);
void func_80099B94(PlayerState *);
void func_80800308_bsbtrot(PlayerState *);
void func_808003F0_bsbtrot(void *);
void func_8080163C_bsbtrot(BtIntPtr);

/* data_to_c.py: from asm/data/overlays/bs/btrot.data.s */
void func_80099B94(PlayerState *);
void _bsdrone_entrypoint_3();
BtFnWord D_80802E50_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x0) = {
    (BtFnWord)_bsbtrot_entrypoint_2, (BtFnWord)_bsbtrot_entrypoint_0,
    (BtFnWord)_bsbtrot_entrypoint_1, (BtFnWord)func_80099B94};
BtFnWord D_80802E60_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x10) = {
    (BtFnWord)_bsbtrot_entrypoint_6, (BtFnWord)_bsbtrot_entrypoint_4,
    (BtFnWord)_bsbtrot_entrypoint_5, (BtFnWord)func_80800308_bsbtrot};
BtFnWord D_80802E70_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x20) = {
    (BtFnWord)_bsbtrot_entrypoint_10, (BtFnWord)_bsbtrot_entrypoint_8,
    (BtFnWord)_bsbtrot_entrypoint_9, (BtFnWord)func_80800308_bsbtrot};
BtFnWord D_80802E80_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x30) = {
    (BtFnWord)_bsbtrot_entrypoint_14, (BtFnWord)_bsbtrot_entrypoint_12,
    (BtFnWord)_bsbtrot_entrypoint_13, (BtFnWord)func_80099B94};
BtFnWord D_80802E90_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x40) = {
    (BtFnWord)_bsbtrot_entrypoint_18, (BtFnWord)_bsbtrot_entrypoint_16,
    (BtFnWord)_bsbtrot_entrypoint_17, (BtFnWord)func_8080163C_bsbtrot};
BtFnWord D_80802EA0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x50) = {
    (BtFnWord)_bsbtrot_entrypoint_22, (BtFnWord)_bsbtrot_entrypoint_20,
    (BtFnWord)_bsbtrot_entrypoint_21, (BtFnWord)func_80099B94};
BtFnWord D_80802EB0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x60) = {
    (BtFnWord)_bsbtrot_entrypoint_26, (BtFnWord)_bsbtrot_entrypoint_24,
    (BtFnWord)_bsbtrot_entrypoint_25, (BtFnWord)func_80099B94};
BtFnWord D_80802EC0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x70) = {
    (BtFnWord)_bsbtrot_entrypoint_28, (BtFnWord)_bsbtrot_entrypoint_29,
    (BtFnWord)_bsbtrot_entrypoint_30, (BtFnWord)func_808003F0_bsbtrot};
BtFnWord D_80802ED0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x80) = {
    (BtFnWord)_bsbtrot_entrypoint_34, (BtFnWord)_bsbtrot_entrypoint_32,
    (BtFnWord)_bsbtrot_entrypoint_33, (BtFnWord)func_80099B94};
BtFnWord D_80802EE0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0x90) = {
    (BtFnWord)_bsbtrot_entrypoint_38, (BtFnWord)_bsbtrot_entrypoint_36,
    (BtFnWord)_bsbtrot_entrypoint_37, (BtFnWord)_bsdrone_entrypoint_3};
BtFnWord D_80802EF0_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0xA0) = {
    (BtFnWord)_bsbtrot_entrypoint_40, (BtFnWord)_bsbtrot_entrypoint_41,
    (BtFnWord)_bsbtrot_entrypoint_42, (BtFnWord)func_80099B94};
BtFnWord D_80802F00_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0xB0) = {
    (BtFnWord)_bsbtrot_entrypoint_44, (BtFnWord)_bsbtrot_entrypoint_45,
    (BtFnWord)_bsbtrot_entrypoint_46, (BtFnWord)func_80800308_bsbtrot};
BtFnWord D_80802F10_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0xC0) = {
    (BtFnWord)_bsbtrot_entrypoint_50, (BtFnWord)_bsbtrot_entrypoint_48,
    (BtFnWord)_bsbtrot_entrypoint_49, (BtFnWord)func_80800308_bsbtrot};
BtFnWord D_80802F20_bsbtrot[4] BT_DATA(4, overlays_bs_btrot, 0xD0) = {
    (BtFnWord)_bsbtrot_entrypoint_54, (BtFnWord)_bsbtrot_entrypoint_52,
    (BtFnWord)_bsbtrot_entrypoint_53, (BtFnWord)func_80800308_bsbtrot};
