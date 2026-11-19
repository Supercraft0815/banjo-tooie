#include "core2/1EDD9C0.h"
#include "actor_last_hit.inc"
typedef struct { s32 * unk0; s32 unk4; } Obj1EDD9C0_D_80135AB0; /* offsets.py genstruct: fields from raw offsets on &D_80135AB0; rename once understood */ BtIntPtr func_801040D0(void) {
    void func_800DFAD0(void *this);
    extern s32 D_80135AB0;
    extern s32 D_80135AB8;
    (((Obj1EDD9C0_D_80135AB0 *)&D_80135AB0)->unk0) = &D_80135AB8;
    (((Obj1EDD9C0_D_80135AB0 *)&D_80135AB0)->unk4) = 0x6D;
    func_800DFAD0(&D_80135AB0);
    return (BtIntPtr) &D_80135AB0;
}

void *func_8010410C(void)
{
    extern u8 D_80136BC0[];

    return D_80136BC0;
}

OSThread *func_80104118(void)
{
    extern u8 D_80136BE8[];

    return (OSThread *) D_80136BE8;
}

BT_IDO_ONLY(OSThread *) BT_ILP32_ONLY(OSThread *) BT_LP64_ONLY(NativeActorHit *) func_80104124(void)
{
    extern ActorHitData D_80124400;

    return (void *)&D_80124400;
}

OSThread *func_80104130(void)
{
    extern u8 D_80136BF8[];

    return (OSThread *) D_80136BF8;
}

OSThread *func_8010413C(void)
{
    extern u8 D_80136D10[];

    return (OSThread *) D_80136D10;
}

void *func_80104148(s32 arg0) {
    extern u8 D_80136D88[];
    return D_80136D88 + arg0 * 20;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80135AB0 BT_DATA(4, bss_core2bss2_2_music_tail, 0x90);
s32 D_80135AB8 BT_DATA(4, bss_core2bss2_2_music_tail, 0x98);
u8 D_80136BC0 [ 40 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x11A0);
u8 D_80136BE8 [ 16 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x11C8);
u8 D_80136BF8 [ 280 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x11D8);
u8 D_80136D10 [ 120 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x12F0);
u8 D_80136D88 [ 232 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1368);
#endif
