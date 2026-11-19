#include "common.h"
struct player_state_s;

void _bsbabykaz_entrypoint_1(struct player_state_s *);
void func_808003D0_bsbabykaz(struct player_state_s *);
void func_808003F0_bsbabykaz(void *);
void func_80800438_bsbabykaz(BtIntPtr);
void func_8080072C_bsbabykaz(BtIntPtr);
void func_80800754_bsbabykaz(BtIntPtr);
void func_8080077C_bsbabykaz(struct player_state_s *);
void func_808007EC_bsbabykaz(struct player_state_s *);
void func_8080080C_bsbabykaz(void *);
void func_80800864_bsbabykaz(struct player_state_s *);
void func_808009C4_bsbabykaz(BtIntPtr);
void func_808009EC_bsbabykaz(struct player_state_s *);
void func_80800B54_bsbabykaz(struct player_state_s *);
void func_80800D18_bsbabykaz(BtIntPtr);
void func_80800D40_bsbabykaz(BtIntPtr);
void func_80800D68_bsbabykaz(BtIntPtr);
void func_80800DD4_bsbabykaz(BtIntPtr);
void func_80800E0C_bsbabykaz(struct player_state_s *);
void func_80800EC8_bsbabykaz(struct player_state_s *);
void func_80801014_bsbabykaz(BtIntPtr);
void func_80801044_bsbabykaz(BtIntPtr);
void func_808010AC_bsbabykaz(BtIntPtr);
void func_808011EC_bsbabykaz(struct player_state_s *);
void func_808012C4_bsbabykaz(BtIntPtr);
void func_808012EC_bsbabykaz(struct player_state_s *);
void func_80801384_bsbabykaz(struct player_state_s *);

/* data_to_c.py: from asm/data/overlays/bs/babykaz.data.s */
BtFnWord D_80801730_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x0) = {
    (BtFnWord)func_808003D0_bsbabykaz, (BtFnWord)func_808003F0_bsbabykaz,
    (BtFnWord)func_80800438_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801740_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x10) = {
    (BtFnWord)func_8080072C_bsbabykaz, (BtFnWord)func_80800754_bsbabykaz,
    (BtFnWord)func_8080077C_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801750_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x20) = {
    (BtFnWord)func_808007EC_bsbabykaz, (BtFnWord)func_8080080C_bsbabykaz,
    (BtFnWord)func_80800864_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801760_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x30) = {
    (BtFnWord)func_808009C4_bsbabykaz, (BtFnWord)func_808009EC_bsbabykaz,
    (BtFnWord)func_80800B54_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801770_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x40) = {
    (BtFnWord)func_80800D18_bsbabykaz, (BtFnWord)func_80800D40_bsbabykaz,
    (BtFnWord)func_80800D68_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801780_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x50) = {
    (BtFnWord)func_80800DD4_bsbabykaz, (BtFnWord)func_80800E0C_bsbabykaz,
    (BtFnWord)func_80800EC8_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_80801790_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x60) = {
    (BtFnWord)func_80801014_bsbabykaz, (BtFnWord)func_80801044_bsbabykaz,
    (BtFnWord)func_808010AC_bsbabykaz, (BtFnWord)_bsbabykaz_entrypoint_1};
BtFnWord D_808017A0_bsbabykaz[4] BT_DATA(4, overlays_bs_babykaz, 0x70) = {
    (BtFnWord)func_808012C4_bsbabykaz, (BtFnWord)func_808012EC_bsbabykaz,
    (BtFnWord)func_80801384_bsbabykaz, (BtFnWord)func_808011EC_bsbabykaz};
