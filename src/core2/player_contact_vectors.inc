#ifdef BT_NATIVE
#include "core2/1E7BFA0.h"
#include "core2/1EC8070.h"

void func_800A32C4(PlayerState *player, f32 dst[3]) {
    func_800EE7F8(dst, player->unkA0);
}

void func_800A3328(PlayerState *player, f32 dst[3]) {
    func_800EE7F8(dst, player->unkA0 + 11);
}

void func_800A33A0(PlayerState *player, f32 dst[3]) {
    func_800EE7F8(dst, player->unkA0 + 3);
}

void func_800A33CC(PlayerState *player, f32 dst[3]) {
    func_800EE7F8(dst, player->unkA0 + 6);
}

void func_800A34AC(PlayerState *player, f32 src[3]) {
    func_800EE7F8(player->unkA0, src);
}

void func_800A34F0(PlayerState *player, f32 src[3]) {
    func_800EE7F8(player->unkA0 + 3, src);
}

void func_800A3514(PlayerState *player, f32 src[3]) {
    func_800EE7F8(player->unkA0 + 6, src);
}

#endif
