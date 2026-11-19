#include "common.h"
#include "core2/actor_item_types.h"

void _idlight_entrypoint_2(void *, s32, void *, s32, s32);
void _idlight_entrypoint_3(void *, void *, s32);
void _idlight_entrypoint_1(void *);
void _idscroll_entrypoint_2(void *, s32, void *, s32, s32);
void _idscroll_entrypoint_3(void *, void *, s32);
void _idscroll_entrypoint_1(void *);
void func_800EDB20(void *, s32, void *, s32, s32);
void func_800EE108(void *, void *, s32);
void func_800EDAF4(void *);
void _idwater_entrypoint_3(void *, s32, void *, s32, s32);
void _idwater_entrypoint_4(void *, void *, s32);
void _idwater_entrypoint_2(void *);
void _idglow_entrypoint_2(void *, s32, void *, s32, s32);
void _idglow_entrypoint_3(void *, void *, s32);
void _idglow_entrypoint_1(void *);
void _idwave_entrypoint_2(void *, s32, void *, s32, s32);
void _idwave_entrypoint_3(void *, void *, s32);
void _idwave_entrypoint_1(void *);
void _idglowa_entrypoint_3(void *, s32, void *, s32, s32);
void _idglowa_entrypoint_4(void *, void *, s32);
void _idglowa_entrypoint_2(void *);
void _idflasha_entrypoint_3(void *, s32, void *, s32, s32);
void _idflasha_entrypoint_4(void *, void *, s32);
void _idflasha_entrypoint_2(void *);
void _idwibble_entrypoint_2(void *, s32, void *, s32, s32);
void _idwibble_entrypoint_3(void *, void *, s32);
void _idwibble_entrypoint_1(void *);
void _idflame_entrypoint_3(void *, s32, void *, s32, s32);
void _idflame_entrypoint_4(void *, void *, s32);
void _idflame_entrypoint_2(void *);
void _idbounce_entrypoint_4(void *, s32, void *, s32, s32);
void _idbounce_entrypoint_5(void *, void *, s32);
void _idbounce_entrypoint_3(void *);
void func_800EE55C(void *);

ActorItemType D_80124440[11] BT_DATA(4, actor_item_types, 0) = {
    {_idlight_entrypoint_2, _idlight_entrypoint_3, _idlight_entrypoint_1, NULL},
    {_idscroll_entrypoint_2, _idscroll_entrypoint_3, _idscroll_entrypoint_1, NULL},
    {func_800EDB20, func_800EE108, func_800EDAF4, NULL},
    {_idwater_entrypoint_3, _idwater_entrypoint_4, _idwater_entrypoint_2, NULL},
    {_idglow_entrypoint_2, _idglow_entrypoint_3, _idglow_entrypoint_1, NULL},
    {_idwave_entrypoint_2, _idwave_entrypoint_3, _idwave_entrypoint_1, NULL},
    {_idglowa_entrypoint_3, _idglowa_entrypoint_4, _idglowa_entrypoint_2, NULL},
    {_idflasha_entrypoint_3, _idflasha_entrypoint_4, _idflasha_entrypoint_2, NULL},
    {_idwibble_entrypoint_2, _idwibble_entrypoint_3, _idwibble_entrypoint_1, NULL},
    {_idflame_entrypoint_3, _idflame_entrypoint_4, _idflame_entrypoint_2, NULL},
    {_idbounce_entrypoint_4, _idbounce_entrypoint_5, _idbounce_entrypoint_3, func_800EE55C},
};
