#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800260_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800330_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_808003AC_subaddiestore.s")

u8 *func_808004FC_subaddiestore(u8 *arg0, u8 *arg1) {
    typedef struct {
        u8 pad0[0x10];
        u32 pad10:16;
        u32 id:15;
        u32 flag10:1;
        u32 pad14;
        u32 pad18:31;
        u32 flag18:1;
        u32 pad1C[2];
        u32 index:10;
        u32 pad24:22;
        u32 pad28:21;
        u32 flag28a:1;
        u32 flag28b:1;
        u32 value28:8;
        u32 pad2B:1;
    } Marker;
    typedef struct {
        u8 body[0x9C];
        u8 animFlag:1;
        u8 flag28a:1;
        u8 flag28b:1;
        u32 index:10;
        u8 playback:3;
        u32 animIndex:14;
        u8 flag9F:1;
        u8 pad9F:1;
        f32 duration;
        u16 timer;
        u16 transition;
        u16 start;
        u16 end;
        u8 loop:1;
        u32 id:15;
        u8 hasAnim:1;
        u8 value28:6;
        u32 flag10:1;
        u32 flag18:1;
        u8 padAF:7;
    } Saved;
    typedef struct { u8 data[0x48]; } Extra48;
    typedef struct { u8 data[0x18]; } Extra18;
    f32 anctrl_getAnimTimer(s32);
    s32 anctrl_getIndex(s32);
    s32 anctrl_getPlaybackType(s32);
    u8 *func_8001B798(s16);
    s32 func_8001B7B8(s16);
    void func_8008B238(s32, f32 *, f32 *);
    s32 func_8008B28C(s32);
    s32 func_8008B29C(s32);
    f32 func_8008B2AC(s32);
    f32 func_8008B2D4(s32);
    s32 func_80104248(u8 *);
    u8 *func_80105494(u8 *);
    u8 *func_80106F30(u8 *);
    s32 func_8010A698(u8 *);
    s32 func_80800260_subaddiestore(void);
    s32 func_80800F98_subaddiestore(u8 *);
    void rare_memcpy(void *, void *, int);
    Extra48 *first;
    Extra18 *second;
    f32 start;
    f32 end;
    s16 handle;
    u8 *base;
    s32 *sizes;
    u8 *out;
    s32 anim;
    s32 size;
    s32 i;
    u8 *entry;

    if (func_80800260_subaddiestore() != 1) {
        return arg1;
    }
    rare_memcpy(arg1, arg0, 0x9C);
    *(s16 *)(arg1 + 0x60) = 0;
    arg1[0x75] &= ~4;
    arg1[0x64] &= ~4;
    arg1[0x5F] = 0;
    *(s32 *)(arg1 + 0x40) = 0;
    *(s32 *)(arg1 + 0x3C) = 0;
    *(s16 *)(arg1 + 0x90) = 0;
    *(s16 *)(arg1 + 0x80) = 0;
    *(s16 *)(arg1 + 0x8E) = 0;
    arg1[0x73] &= ~8;
    arg1[0x74] &= ~0x80;
    ((Saved *)arg1)->index = (*(Marker **)arg0)->index;
    ((Saved *)arg1)->id = (*(Marker **)arg0)->id;
    ((Saved *)arg1)->flag28a = (*(Marker **)arg0)->flag28a;
    ((Saved *)arg1)->flag28b = (*(Marker **)arg0)->flag28b;
    ((Saved *)arg1)->flag9F = func_8010A698(arg0);
    ((Saved *)arg1)->value28 = (*(Marker **)arg0)->value28;
    ((Saved *)arg1)->flag10 = (*(Marker **)arg0)->flag10;
    ((Saved *)arg1)->flag18 = (*(Marker **)arg0)->flag18;
    if (*(s16 *)(arg0 + 0x8C) != 0) {
        anim = func_80104248(arg0);
        ((Saved *)arg1)->animIndex = anctrl_getIndex(anim);
        ((Saved *)arg1)->playback = anctrl_getPlaybackType(anim);
        ((Saved *)arg1)->loop = func_8008B28C(anim);
        ((Saved *)arg1)->animFlag = func_8008B29C(anim);
        *(f32 *)(arg1 + 0xA0) = func_8008B2AC(anim);
        func_8008B238(anim, &start, &end);
        *(s16 *)(arg1 + 0xA8) = (u32)(start * 32768.0f);
        *(s16 *)(arg1 + 0xAA) = (u32)(end * 32768.0f);
        *(s16 *)(arg1 + 0xA4) = (u32)(anctrl_getAnimTimer(anim) * 32768.0f);
        *(s16 *)(arg1 + 0xA6) = (u32)(func_8008B2D4(anim) * 32768.0f);
    }
    if (*(s16 *)(arg0 + 0x8C) != 0) {
        ((Saved *)arg1)->hasAnim = 1;
    } else {
        ((Saved *)arg1)->hasAnim = 0;
    }
    *(s16 *)(arg1 + 0x8C) = 0;
    *(s32 *)arg1 = 0;
    base = arg1 + 0xB0;
    entry = base;
    out = entry;
    if (*(s32 *)(arg0 + 0x7C) & 0xFFF) {
        first = (Extra48 *)out;
        rare_memcpy(out, func_80105494(arg0), 0x48);
        out = (u8 *)(first + 1);
    }
    second = (Extra18 *)out;
    if ((*(u32 *)(arg0 + 0x94) << 2) >> 22) {
        rare_memcpy(out, func_80106F30(arg0), 0x18);
        out = (u8 *)(second + 1);
    }
    if (func_80800F98_subaddiestore(arg0) != 0) {
        sizes = (s32 *)out;
        out += 0xC;
        entry = arg0;
        i = 0;
        do {
            handle = *(s16 *)(entry + 0x82);
            if (handle != 0) {
                size = func_8001B7B8(handle);
                *sizes = size;
                rare_memcpy(out, func_8001B798(*(s16 *)(entry + 0x82)), size);
                out += size;
            } else {
                *sizes = 0;
            }
            i += 4;
            entry += 2;
            sizes++;
        } while (i != 0xC);
    }
    return out;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800AD8_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800B24_subaddiestore.s")

s32 func_80800F98_subaddiestore(u8 *arg0) {
    s32 var_v1;
    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        if (((s16 *)(arg0 + 0x82))[var_v1] != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800FD0_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80801054_subaddiestore.s")
