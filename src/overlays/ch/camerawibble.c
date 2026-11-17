#include "common.h"

OSThread *chcamerawibble_entrypoint_0(void)
{
    extern ActorData D_808000E0_chcamerawibble[];

    return (OSThread *) D_808000E0_chcamerawibble;
}                typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x10]; f32 unk38; u8 pad3C[0x18]; f32 unk54; u8 pad58[0x1E]; u16 unk76; } Objcamerawibble_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chcamerawibble(void *arg0) {
    ((Objcamerawibble_arg0 *)arg0)->unk24 = (f32)((u32)*&((Objcamerawibble_arg0 *)arg0)->unk76 >> 7) * 10.0f;
    ((Objcamerawibble_arg0 *)arg0)->unk54 = ((Objcamerawibble_arg0 *)arg0)->unk38;
}

void func_8080006C_chcamerawibble();

void func_8080004C_chcamerawibble(BT_NATIVE_ONLY(Actor *bt_a0))
{
    func_8080006C_chcamerawibble(BT_NATIVE_ONLY(bt_a0));
}

void func_8080006C_chcamerawibble(Actor *arg0) {
    f32 func_80013970(f32);
    void func_800C4B90(s32, f32, f32);
    f32 func_800D8FF8(void);
    f32 temp_f2;
    f32 delta;

    temp_f2 = func_80013970(arg0->unk58) * arg0->unk54;
    func_800C4B90(0, temp_f2, -temp_f2);
    delta = func_800D8FF8();
    arg0->unk58 += delta * ((f32 *)arg0->actorData)[3];
}
/* data_to_c.py: from asm/data/overlays/ch/camerawibble.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_808000E0_chcamerawibble [1] BT_DATA(4, overlays_ch_camerawibble, 0x0) = { { 344, 328, 0, 1, 0, (void (*)(struct Actor *))func_8080004C_chcamerawibble, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chcamerawibble, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
