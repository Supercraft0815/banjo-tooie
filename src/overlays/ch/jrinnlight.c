#include "common.h"

typedef struct { u8 pad0[0x58]; s32 unk58; } Objjrinnlight_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chjrinnlight(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (((Objjrinnlight_arg0 *)arg0)->unk58);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (((Objjrinnlight_arg0 *)arg0)->unk58) = 0;
    }
}

/* extern */

s32 func_80800038_chjrinnlight(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    s32 func_800DA298(s32);
    s32 temp_v0;

    if (arg1 == 0x95) {
        if (func_800DA298(0x3A9) != 0) {
            temp_v0 = func_800C8A98();
            *(s32 *)&arg0->unk58 = temp_v0;
            func_800C8CB8(temp_v0, arg0->position);
            func_800C8E54(*(s32 *)&arg0->unk58, 500.0f, 700.0f);
            func_800C8FB0(*(s32 *)&arg0->unk58, 0xFF, 0xFF, 0xFF);
            func_800C8F64(*(s32 *)&arg0->unk58, 0xB);
            return 1;
        } else {
            *(s32 *)&arg0->unk58 = 0;
        }
    } else {
        return 0;
    }
    return 1;
}

OSThread *chjrinnlight_entrypoint_0(void)
{
    extern ActorData D_808000F0_chjrinnlight[];

    return (OSThread *) D_808000F0_chjrinnlight;
}
/* data_to_c.py: from asm/data/overlays/ch/jrinnlight.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_808000F0_chjrinnlight [1] BT_DATA(4, overlays_ch_jrinnlight, 0x0) = { { 344, 1213, 0, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, (void (*)(struct Actor *))func_80800000_chjrinnlight, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9730, (void (*)(struct Actor *, long, long))func_80800038_chjrinnlight, 0 } };
