#include "native_drone_states.h"
#include "overlays/bs/drone/bubbled.h"

/* Native form of asm/data/overlays/bs/drone.data.s. */
extern void _bsdronegoto_entrypoint_0(PlayerState *);
extern void _bsdronegoto_entrypoint_1(PlayerState *);
extern void _bsdronegoto_entrypoint_2(PlayerState *);
extern void _bsdronegoto_entrypoint_3(PlayerState *);
extern void _bsdronelook_entrypoint_1(PlayerState *);
extern void _bsdronelook_entrypoint_3(PlayerState *);
extern void _bsdronelook_entrypoint_0(PlayerState *);
extern void _bsdronelook_entrypoint_4(PlayerState *);
extern void _bsdronesuckunder_entrypoint_1(PlayerState *);
extern void _bsdronesuckunder_entrypoint_3(PlayerState *);
extern void _bsdronesuckunder_entrypoint_0(PlayerState *);
extern void _bsdronesuckunder_entrypoint_2(PlayerState *);
extern void _bsdronexform_entrypoint_2(PlayerState *);
extern void _bsdronexform_entrypoint_3(PlayerState *);
extern void _bsdronexform_entrypoint_1(PlayerState *);
extern void func_80099AA8(PlayerState *);
extern void _bsdronevanish_entrypoint_0(PlayerState *);
extern void _bsdronevanish_entrypoint_1(PlayerState *);
extern void _bsdronevanish_entrypoint_2(PlayerState *);
extern void _bsdronebitten_entrypoint_1(PlayerState *);
extern void _bsdronebitten_entrypoint_3(PlayerState *);
extern void _bsdronebitten_entrypoint_0(PlayerState *);
extern void _bsdronebitten_entrypoint_7(PlayerState *);
extern void _bsdronebitten_entrypoint_9(PlayerState *);
extern void _bsdronebitten_entrypoint_6(PlayerState *);
extern void _bsdronebitten_entrypoint_8(PlayerState *);
extern void _bsdroneslide_entrypoint_0(PlayerState *);
extern void _bsdroneslide_entrypoint_1(PlayerState *);
extern void _bsdroneslide_entrypoint_2(PlayerState *);
extern void func_80099B94(PlayerState *);
extern void _bsdronejump_entrypoint_2(PlayerState *);
extern void _bsdronejump_entrypoint_4(PlayerState *);
extern void _bsdronejump_entrypoint_1(PlayerState *);
extern void _bsdronejump_entrypoint_3(PlayerState *);
extern void _bsdronefired_entrypoint_1(PlayerState *);
extern void _bsdronefired_entrypoint_3(PlayerState *);
extern void _bsdronefired_entrypoint_0(PlayerState *);
extern void _bsdronefired_entrypoint_2(PlayerState *);
extern void _bsdronewaitbabykaz_entrypoint_1(PlayerState *);
extern void _bsdronewaitbabykaz_entrypoint_3(PlayerState *);
extern void _bsdronewaitbabykaz_entrypoint_0(PlayerState *);
extern void _bsdronewaitbabykaz_entrypoint_2(PlayerState *);
extern void _bsdronefalldie_entrypoint_1(PlayerState *);
extern void _bsdronefalldie_entrypoint_3(PlayerState *);
extern void _bsdronefalldie_entrypoint_0(PlayerState *);
extern void _bsdronefalldie_entrypoint_2(PlayerState *);

const NativeDroneState D_80800180_bsdrone[16] = {
    {1, _bsdronegoto_entrypoint_0, _bsdronegoto_entrypoint_1, _bsdronegoto_entrypoint_2, _bsdronegoto_entrypoint_3},
    {2, _bsdronelook_entrypoint_1, _bsdronelook_entrypoint_3, _bsdronelook_entrypoint_0, _bsdronelook_entrypoint_4},
    {3, _bsdronesuckunder_entrypoint_1, _bsdronesuckunder_entrypoint_3, _bsdronesuckunder_entrypoint_0, _bsdronesuckunder_entrypoint_2},
    {4, _bsdronexform_entrypoint_2, _bsdronexform_entrypoint_3, _bsdronexform_entrypoint_1, func_80099AA8},
    {5, NULL, NULL, NULL, NULL},
    {6, _bsdronevanish_entrypoint_0, _bsdronevanish_entrypoint_1, _bsdronevanish_entrypoint_2, func_80099AA8},
    {7, _bsdronebitten_entrypoint_1, _bsdronebitten_entrypoint_3, _bsdronebitten_entrypoint_0, func_80099AA8},
    {8, _bsdronebitten_entrypoint_7, _bsdronebitten_entrypoint_9, _bsdronebitten_entrypoint_6, _bsdronebitten_entrypoint_8},
    {9, _bsdroneslide_entrypoint_0, _bsdroneslide_entrypoint_1, _bsdroneslide_entrypoint_2, func_80099B94},
    {10, _bsdronejump_entrypoint_2, _bsdronejump_entrypoint_4, _bsdronejump_entrypoint_1, _bsdronejump_entrypoint_3},
    {11, _bsdronefired_entrypoint_1, _bsdronefired_entrypoint_3, _bsdronefired_entrypoint_0, _bsdronefired_entrypoint_2},
    {12, _bsdronebubbled_entrypoint_1, _bsdronebubbled_entrypoint_3, _bsdronebubbled_entrypoint_0, _bsdronebubbled_entrypoint_2},
    {13, _bsdronebubbled_entrypoint_5, _bsdronebubbled_entrypoint_7, _bsdronebubbled_entrypoint_4, _bsdronebubbled_entrypoint_6},
    {14, _bsdronewaitbabykaz_entrypoint_1, _bsdronewaitbabykaz_entrypoint_3, _bsdronewaitbabykaz_entrypoint_0, _bsdronewaitbabykaz_entrypoint_2},
    {15, _bsdronefalldie_entrypoint_1, _bsdronefalldie_entrypoint_3, _bsdronefalldie_entrypoint_0, _bsdronefalldie_entrypoint_2},
    {0, NULL, NULL, NULL, NULL},
};

/* Original badrone state attributes from asm/data/overlays/ba/drone.data.s. */
u8 D_80800630_badrone[16] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0};
