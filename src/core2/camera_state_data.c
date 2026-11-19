#include "core2/camera_state_callbacks.h"

void _ncbaswim_entrypoint_2(struct player_state_s *);
void _ncbaswim_entrypoint_3(struct player_state_s *);
void _ncbaswim_entrypoint_1(struct player_state_s *);
void _ncbafly_entrypoint_1(struct player_state_s *);
void _ncbafly_entrypoint_3(struct player_state_s *);
void _ncbafly_entrypoint_2(struct player_state_s *);
void _ncbadive_entrypoint_1(struct player_state_s *);
void _ncbadive_entrypoint_3(struct player_state_s *);
void _ncbadive_entrypoint_2(struct player_state_s *);
void func_80110528(struct player_state_s *);
void _ncbafixpos_entrypoint_1(struct player_state_s *);
void _ncbafixpos_entrypoint_3(struct player_state_s *);
void _ncbafixpos_entrypoint_2(struct player_state_s *);
void _ncbapan_entrypoint_1(struct player_state_s *);
void _ncbapan_entrypoint_3(struct player_state_s *);
void _ncbapan_entrypoint_2(struct player_state_s *);
void _ncbadie_entrypoint_1(struct player_state_s *);
void _ncbadie_entrypoint_4(struct player_state_s *);
void _ncbadie_entrypoint_2(struct player_state_s *);
void _ncbaclimb_entrypoint_1(struct player_state_s *);
void _ncbaclimb_entrypoint_3(struct player_state_s *);
void _ncbaclimb_entrypoint_2(struct player_state_s *);
void _ncbadolly_entrypoint_1(struct player_state_s *);
void _ncbadolly_entrypoint_3(struct player_state_s *);
void _ncbadolly_entrypoint_2(struct player_state_s *);
void _ncbaspline_entrypoint_2(struct player_state_s *);
void _ncbaspline_entrypoint_4(struct player_state_s *);
void _ncbaspline_entrypoint_3(struct player_state_s *);
void _ncbaspiral_entrypoint_1(struct player_state_s *);
void _ncbaspiral_entrypoint_3(struct player_state_s *);
void _ncbaspiral_entrypoint_2(struct player_state_s *);
void _ncbapivot_entrypoint_1(struct player_state_s *);
void _ncbapivot_entrypoint_3(struct player_state_s *);
void _ncbapivot_entrypoint_2(struct player_state_s *);
void _ncbatarget_entrypoint_1(struct player_state_s *);
void _ncbatarget_entrypoint_3(struct player_state_s *);
void _ncbatarget_entrypoint_2(struct player_state_s *);
void _ncbaledge_entrypoint_0(struct player_state_s *);
void _ncbaledge_entrypoint_2(struct player_state_s *);
void _ncbaledge_entrypoint_1(struct player_state_s *);
void _ncbabee_entrypoint_0(struct player_state_s *);
void _ncbabee_entrypoint_2(struct player_state_s *);
void _ncbabee_entrypoint_1(struct player_state_s *);
void _ncbaglide_entrypoint_0(struct player_state_s *);
void _ncbaglide_entrypoint_2(struct player_state_s *);
void _ncbaglide_entrypoint_1(struct player_state_s *);
void _ncbasub_entrypoint_1(struct player_state_s *);
void _ncbasub_entrypoint_2(struct player_state_s *);
void _ncbasub_entrypoint_0(struct player_state_s *);
void _ncbasuck_entrypoint_0(struct player_state_s *);
void _ncbasuck_entrypoint_2(struct player_state_s *);
void _ncbasuck_entrypoint_1(struct player_state_s *);
void _ncbakaztorp_entrypoint_1(struct player_state_s *);
void _ncbakaztorp_entrypoint_2(struct player_state_s *);
void _ncbakaztorp_entrypoint_0(struct player_state_s *);
s32 _ncba1p_entrypoint_0(void);
s32 func_80115EA0(void);
s32 func_80114D90(void);
s32 _ncbaclimb_entrypoint_0(void);
s32 _ncbadie_entrypoint_0(void);
s32 func_80115350(void);
s32 _ncbadive_entrypoint_0(void);
s32 _ncbadolly_entrypoint_0(void);
s32 _ncbafixpos_entrypoint_0(void);
s32 _ncbafly_entrypoint_0(void);
s32 func_80112E90(void);
s32 _ncbajig_entrypoint_0(void);
s32 func_80112160(void);
s32 func_80111340(void);
s32 _ncbapan_entrypoint_0(void);
s32 func_80115610(void);
s32 _ncbapivot_entrypoint_0(void);
s32 _ncbaspline_entrypoint_0(void);
s32 _ncbaspiral_entrypoint_0(void);
s32 func_801125B0(void);
s32 _ncbastring_entrypoint_0(void);
s32 _ncbaswim_entrypoint_0(void);
s32 _ncbatarget_entrypoint_0(void);
s32 _ncbawaypoint_entrypoint_0(void);
s32 func_801127A0(void);

CameraStateCallbacks D_801247A0[27] BT_DATA(4, camera_state_data, 0) = {
    {NULL, NULL, NULL, 0x0},
    {NULL, NULL, NULL, 0x0},
    {_ncbaswim_entrypoint_2, _ncbaswim_entrypoint_3, _ncbaswim_entrypoint_1, 0x10001},
    {_ncbafly_entrypoint_1, _ncbafly_entrypoint_3, _ncbafly_entrypoint_2, 0x0},
    {_ncbadive_entrypoint_1, _ncbadive_entrypoint_3, _ncbadive_entrypoint_2, 0x0},
    {NULL, func_80110528, NULL, 0x0},
    {_ncbafixpos_entrypoint_1, _ncbafixpos_entrypoint_3, _ncbafixpos_entrypoint_2, 0x0},
    {NULL, NULL, NULL, 0x0},
    {_ncbapan_entrypoint_1, _ncbapan_entrypoint_3, _ncbapan_entrypoint_2, 0x10000},
    {NULL, NULL, NULL, 0x0},
    {_ncbadie_entrypoint_1, _ncbadie_entrypoint_4, _ncbadie_entrypoint_2, 0x0},
    {NULL, NULL, NULL, 0x0},
    {_ncbaclimb_entrypoint_1, _ncbaclimb_entrypoint_3, _ncbaclimb_entrypoint_2, 0x10002},
    {_ncbadolly_entrypoint_1, _ncbadolly_entrypoint_3, _ncbadolly_entrypoint_2, 0x0},
    {_ncbaspline_entrypoint_2, _ncbaspline_entrypoint_4, _ncbaspline_entrypoint_3, 0x0},
    {NULL, NULL, NULL, 0x0},
    {NULL, NULL, NULL, 0x0},
    {NULL, NULL, NULL, 0x0},
    {_ncbaspiral_entrypoint_1, _ncbaspiral_entrypoint_3, _ncbaspiral_entrypoint_2, 0x0},
    {_ncbapivot_entrypoint_1, _ncbapivot_entrypoint_3, _ncbapivot_entrypoint_2, 0x10000},
    {_ncbatarget_entrypoint_1, _ncbatarget_entrypoint_3, _ncbatarget_entrypoint_2, 0x0},
    {_ncbaledge_entrypoint_0, _ncbaledge_entrypoint_2, _ncbaledge_entrypoint_1, 0x10000},
    {_ncbabee_entrypoint_0, _ncbabee_entrypoint_2, _ncbabee_entrypoint_1, 0x10001},
    {_ncbaglide_entrypoint_0, _ncbaglide_entrypoint_2, _ncbaglide_entrypoint_1, 0x10001},
    {_ncbasub_entrypoint_1, _ncbasub_entrypoint_2, _ncbasub_entrypoint_0, 0x10001},
    {_ncbasuck_entrypoint_0, _ncbasuck_entrypoint_2, _ncbasuck_entrypoint_1, 0x10002},
    {_ncbakaztorp_entrypoint_1, _ncbakaztorp_entrypoint_2, _ncbakaztorp_entrypoint_0, 0x10001},
};

s32 (*D_80124950[28])(void) BT_DATA(4, camera_state_data, 0x1B0) = {
    _ncba1p_entrypoint_0, func_80115EA0, func_80114D90, _ncbaclimb_entrypoint_0,
    _ncbadie_entrypoint_0, func_80115350, _ncbadive_entrypoint_0, _ncbadolly_entrypoint_0,
    _ncbafixpos_entrypoint_0, _ncbafly_entrypoint_0, func_80112E90, _ncbajig_entrypoint_0,
    func_80112160, func_80111340, _ncbapan_entrypoint_0, func_80115610,
    _ncbapivot_entrypoint_0, _ncbaspline_entrypoint_0, _ncbaspiral_entrypoint_0, func_801125B0,
    _ncbastring_entrypoint_0, _ncbaswim_entrypoint_0, _ncbatarget_entrypoint_0, _ncbawaypoint_entrypoint_0,
    func_801127A0, NULL, NULL, NULL,
};
