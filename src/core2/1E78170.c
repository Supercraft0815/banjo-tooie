#include "core2/1E78170.h"

typedef struct {
    s16 map;
    s16 entrance;
} RespawnExit;

typedef struct {
    f32 position[3];
    u8 unk0C;
    u8 pad0D[3];
    RespawnExit exits[4];
    u8 depth;
    u8 pad21[7];
    f32 secondary[3];
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 pad39[3];
    s16 unk3C;
    u8 pad3E[2];
    s32 unk40;
    u8 pad44[12];
} MapTransitionState;

MapTransitionState D_80127040_storage;

#ifdef BT_NATIVE
_Static_assert(sizeof(MapTransitionState) == 0x50, "map transition layout");
#else
extern f32 D_80127040;
extern f32 D_80127044;
extern f32 D_80127048;
extern u8 D_8012704C;
extern s32 D_80127050[4];
extern u8 D_80127060;
extern f32 D_80127068;
extern f32 D_8012706C;
extern f32 D_80127070;
extern u8 D_80127074;
extern u8 D_80127075;
extern u8 D_80127076;
extern u8 D_80127077;
extern u8 D_80127078;
extern s16 D_8012707C;
extern s32 D_80127080;
#endif

void func_8009E880(void) {
    BT_DATA_FIELD(D_80127040_storage.unk34, *(u8 *)((u8 *)&D_80127068 + 0xC)) = 1;
    BT_DATA_FIELD(D_80127040_storage.unk35, *(u8 *)((u8 *)&D_80127068 + 0xD)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk0C, *(u8 *)((u8 *)&D_80127040 + 0xC)) = 1;
    BT_DATA_FIELD(D_80127040_storage.position[0], D_80127040) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.position[1], *(f32 *)((u8 *)&D_80127040 + 0x4)) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.position[2], *(f32 *)((u8 *)&D_80127040 + 0x8)) = 0.0f;
}

void func_8009E8B4(void)
{
    BT_NATIVE_ONLY(void func_800C6E58(void);)
    func_800C6E58();
}
void func_8009E8D4(void) {
    void func_800C6E60(void);
    u32 func_800D3B60(void);
    void func_8009EAE8(s32);

    func_800C6E60();
    BT_DATA_FIELD(D_80127040_storage.unk0C, *(u8 *)((u8 *)&D_80127040 + 0xC)) = func_800D3B60();
    BT_DATA_FIELD(D_80127040_storage.unk40, *(s32 *)((u8 *)&D_80127068 + 0x18)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk34, *(u8 *)((u8 *)&D_80127068 + 0xC)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk35, *(u8 *)((u8 *)&D_80127068 + 0xD)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk36, *(u8 *)((u8 *)&D_80127068 + 0xE)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk37, *(u8 *)((u8 *)&D_80127068 + 0xF)) = 0;
    BT_DATA_FIELD(D_80127040_storage.unk38, *(u8 *)((u8 *)&D_80127068 + 0x10)) = 1;
    BT_DATA_FIELD(D_80127040_storage.position[0], D_80127040) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.position[1], *(f32 *)((u8 *)&D_80127040 + 0x4)) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.position[2], *(f32 *)((u8 *)&D_80127040 + 0x8)) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.secondary[0], D_80127068) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.secondary[1], *(f32 *)((u8 *)&D_80127068 + 0x4)) = 0.0f;
    BT_DATA_FIELD(D_80127040_storage.secondary[2], *(f32 *)((u8 *)&D_80127068 + 0x8)) = 0.0f;
    func_800DA524(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
    func_8009EAE8(0);
}

u32 func_8009E958(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk0C, D_8012704C);
}

u32 func_8009E964(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk38, D_80127078);
}

f32 func_8009E970(void) {
    return BT_DATA_FIELD(D_80127040_storage.position[2], D_80127048);
}

f32 func_8009E97C(void) {
    return BT_DATA_FIELD(D_80127040_storage.position[0], D_80127040);
}

f32 func_8009E988(void) {
    return BT_DATA_FIELD(D_80127040_storage.position[1], D_80127044);
}

u32 func_8009E994(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk35, D_80127075);
}

void func_8009E9A0(void) {
}

void func_8009E9A8(void) {
    extern void func_8009E9FC(f32);
    extern void func_8009EB0C(f32);
    func_8009E9FC(0.0f); func_8009EB0C(0.0f);
}

void func_8009E9D8(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk0C, D_8012704C) = arg0;
}

void func_8009E9E4(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk38, D_80127078) = arg0;
}

void func_8009E9F0(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.position[2], D_80127048) = arg0;
}

void func_8009E9FC(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.position[0], D_80127040) = arg0;
}

void func_8009EA08(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.secondary[2], D_80127070) = arg0;
}

f32 func_8009EA14(void) {
    return BT_DATA_FIELD(D_80127040_storage.secondary[1], D_8012706C);
}

u8 func_8009EA20(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk37, D_80127077);
}

s32 func_8009EA2C()
{
    return func_800DA298(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
}

u32 func_8009EA4C(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk34, D_80127074);
}

s32 func_8009EA58()
{
    return BT_DATA_FIELD(D_80127040_storage.unk40, D_80127080);
}

s32 func_8009EA64(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk3C, D_8012707C);
}

u32 func_8009EA70(void) {
    return BT_DATA_FIELD(D_80127040_storage.unk36, D_80127076);
}

f32 func_8009EA7C(void) {
    return BT_DATA_FIELD(D_80127040_storage.secondary[0], D_80127068);
}

f32 func_8009EA88(void) {
    return BT_DATA_FIELD(D_80127040_storage.secondary[2], D_80127070);
}

void func_8009EA94(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.secondary[1], D_8012706C) = arg0;
}

void func_8009EAA0(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk37, D_80127077) = arg0;
}

void func_8009EAAC(s32 arg0) {
    func_800DA3B8(FLAG_3EC_ABILITY_DRAGON_KAZOOIE, arg0);
}

void func_8009EAD0(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk34, D_80127074) = arg0;
}

void func_8009EADC(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk40, D_80127080) = arg0;
}

void func_8009EAE8(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk3C, D_8012707C) = arg0;
}

void func_8009EAF4(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk36, D_80127076) = arg0;
}

void func_8009EB00(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.secondary[0], D_80127068) = arg0;
}

void func_8009EB0C(f32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.position[1], D_80127044) = arg0;
}

void func_8009EB18(s32 arg0) {
    BT_DATA_FIELD(D_80127040_storage.unk35, D_80127075) = arg0;
}

void func_8009EB24(s16 arg0, s16 arg1)
{
    void func_8009EC60(s16, s16);
#ifdef BT_NATIVE
    s32 i;

    for (i = 3; i > 0; i--) {
        D_80127040_storage.exits[i] = D_80127040_storage.exits[i - 1];
    }
    D_80127040_storage.depth++;
#else
    s32 *var_v0;
    BtUIntPtr end;

    /* IDO schedules the two address loads together on this source line. */
    do { var_v0 = (s32 *) (&D_8012704C); end = (BtUIntPtr) (&D_80127040); while (1) { var_v0[4] = var_v0[3]; var_v0--; if (((BtUIntPtr) var_v0) == end) { break; } } } while (0);
    *((u8 *)&D_80127040 + 0x20) += 1;
#endif
    func_8009EC60(arg0, arg1);
}

void func_8009EB8C(s16 arg0, s16 arg1) {
    void func_8009EC3C(void);
    void func_8009EC60(s16, s16);
    func_8009EC3C();
    BT_DATA_FIELD(D_80127040_storage.depth, *((u8 *)&D_80127040 + 0x20)) += 1;
    func_8009EC60(arg0, arg1);
}

void func_8009EBD0(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
#ifdef BT_NATIVE
        D_80127040_storage.exits[i] = D_80127040_storage.exits[i + 1];
#else
        ((s32 *)&D_80127040)[i + 4] = ((s32 *)&D_80127040)[i + 5];
#endif
    }
    BT_DATA_FIELD(D_80127040_storage.depth, *((u8 *)&D_80127040 + 0x20)) -= 1;
}

s32 func_8009EC08(s16 *arg0, s16 *arg1) {
    if (BT_DATA_FIELD(D_80127040_storage.exits[0].map, *(s16 *)((u8 *)&D_80127040 + 0x10)) != 0) {
        *arg0 = BT_DATA_FIELD(D_80127040_storage.exits[0].map, *(s16 *)((u8 *)&D_80127040 + 0x10));
        *arg1 = BT_DATA_FIELD(D_80127040_storage.exits[0].entrance, *(s16 *)((u8 *)&D_80127040 + 0x12));
        return 1;
    }
    return 0;
}

void func_8009EC3C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
#ifdef BT_NATIVE
        D_80127040_storage.exits[i].map = 0;
        D_80127040_storage.exits[i].entrance = 0;
#else
        ((s32 *)D_80127040_storage.exits)[i] = 0;
#endif
    }
    BT_DATA_FIELD(D_80127040_storage.depth, D_80127060) = 0;
}

void func_8009EC60(s16 arg0, s16 arg1) {
    BT_DATA_FIELD(D_80127040_storage.exits[0].map, *(s16 *)((u8 *)&D_80127040 + 0x10)) = arg0;
    BT_DATA_FIELD(D_80127040_storage.exits[0].entrance, *(s16 *)((u8 *)&D_80127040 + 0x12)) = arg1;
}

u32 func_8009EC7C(void) {
    return BT_DATA_FIELD(D_80127040_storage.depth, D_80127060);
}

s32 func_8009EC88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < BT_DATA_FIELD(D_80127040_storage.depth, D_80127060) BT_NATIVE_ONLY(&& i < 4); i++) {
        if (arg0 == BT_DATA_FIELD(D_80127040_storage.exits[i].map, *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x10)) &&
            arg1 == BT_DATA_FIELD(D_80127040_storage.exits[i].entrance, *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x12))) {
            BT_DATA_FIELD(D_80127040_storage.exits[i].map, *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x10)) = arg2;
            BT_DATA_FIELD(D_80127040_storage.exits[i].entrance, *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x12)) = arg3;
            return 1;
        }
    }
    return 0;
}
