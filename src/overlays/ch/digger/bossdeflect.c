#include "common.h"

OSThread *chdiggerbossdeflect_entrypoint_0(void)
{
    extern ActorData D_80800040_chdiggerbossdeflect[];

    return (OSThread *) D_80800040_chdiggerbossdeflect;
}                typedef struct { u8 pad0[0x62]; s16 unk62; u8 pad64[0x4]; s16 unk68; s16 unk6A; } Objbossdeflect_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chdiggerbossdeflect(void *arg0) {
    (((Objbossdeflect_arg0 *)arg0)->unk62) = 0x1F4;
    (((Objbossdeflect_arg0 *)arg0)->unk6A) = 0x1F4;
    (((Objbossdeflect_arg0 *)arg0)->unk68) = 0x1F4;
}

void func_80800020_chdiggerbossdeflect(s32 arg0) 
{
}
s32 func_80800028_chdiggerbossdeflect(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/digger/bossdeflect.data.s */
void func_80102EC0();
void func_8010A730();
void func_80107C2C();
ActorData D_80800040_chdiggerbossdeflect [1] BT_DATA(4, overlays_ch_digger_bossdeflect, 0x0) = { { 344, 1279, 0, 1, 0, (void (*)(struct Actor *))func_80800020_chdiggerbossdeflect, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chdiggerbossdeflect, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 6150, (void (*)(struct Actor *, long, long))func_80800028_chdiggerbossdeflect, 0 } };
