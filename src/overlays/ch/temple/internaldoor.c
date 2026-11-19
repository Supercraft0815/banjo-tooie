#include "common.h"
#ifdef BT_NATIVE
typedef struct {
    u16 model, padding;
    f32 distance;
} TempleDoor;
_Static_assert(sizeof(TempleDoor) == 8, "temple door record");
TempleDoor D_80800208_chtempleinternaldoor[12] BT_DATA(4, overlays_ch_temple_internaldoor, 0x48) = {
    {0x83F, 0, 190.0f},
    {0x840, 0, 190.0f},
    {0x841, 0, 205.0f},
    {0x842, 0, 150.0f},
    {0x843, 0, 150.0f},
    {0x844, 0, 150.0f},
    {0x845, 0, 150.0f},
    {0x846, 0, 150.0f},
    {0x847, 0, 150.0f},
    {0x848, 0, 150.0f},
    {0x850, 0, 150.0f},
    {0x84F, 0, 150.0f},
};
#endif
BT_NATIVE_ONLY(s32 func_80103140(Actor *, u32, u16);)

OSThread *chtempleinternaldoor_entrypoint_0(void)
{
    extern ActorData D_808001C0_chtempleinternaldoor[];

    return (OSThread *) D_808001C0_chtempleinternaldoor;
}

void func_8080000C_chtempleinternaldoor(Actor *arg0) {
    extern u8 D_8012762C;
    BT_IDO_ONLY(extern f32 D_8080020C_chtempleinternaldoor[][2];)
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_7(u8 *, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_7(Actor *, f32);)
    void _chdoormake_entrypoint_8(void *, u32);
    void func_80101FDC(Actor *, u32);
    s32 index = arg0->unk74_7 - 0x32;
    s32 flags;
    f32 distance;

    switch (index) {
        default:
            flags = 0x1060A;
            break;
        case 0:
            flags = 0;
            break;
        case 1:
        case 10:
        case 11:
            if (D_8012762C == 0x1B) {
                flags = 0;
                break;
            }
            func_80101FDC(arg0, 4);
            flags = 0;
            break;
    }
    distance = BT_DATA_FIELD(D_80800208_chtempleinternaldoor[index].distance, D_8080020C_chtempleinternaldoor[index][0]);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, distance, flags, -1)) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_7(arg0, BT_DATA_FIELD(5.0f, 0x40A00000));
        _chdoormake_entrypoint_8(arg0, 5);
    }
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objinternaldoor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808000F8_chtempleinternaldoor(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(u8 *) arg0) {
    BT_IDO_ONLY(s32 _chdoor_entrypoint_0();) BT_NATIVE_ONLY(void _chdoor_entrypoint_0(BtIntPtr);)
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_7(u8 *, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_7(Actor *, f32);)
    _chdoor_entrypoint_0(BT_NATIVE_ONLY((BtIntPtr)arg0));
    if (BT_DATA_FIELD(arg0->unk70_10, ((u32) (((Objinternaldoor_arg0 *)arg0)->unk72) >> 0xA)) == 1) {
        _chdoormake_entrypoint_7(arg0, BT_DATA_FIELD(5.0f, 0x40A00000));
    }
}

/* extern */

void func_80800138_chtempleinternaldoor(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(s32) arg0, s32 arg1, BtIntPtr arg2) {
    BT_IDO_ONLY(s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);) BT_NATIVE_ONLY(s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);)
    s32 func_80800178_chtempleinternaldoor(BT_NATIVE_ONLY(Actor *));
    if (arg1 == 0x95) {
        func_80800178_chtempleinternaldoor(BT_NATIVE_ONLY(arg0));
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

s32 func_80800178_chtempleinternaldoor(Actor *arg0) {
    BT_IDO_ONLY(extern u8 D_80800208_chtempleinternaldoor[];)
    u32 index = arg0->unk74_7 - 0x32;
    BT_NATIVE_ONLY(return) func_80103140(arg0, BT_DATA_FIELD(D_80800208_chtempleinternaldoor[index].model, *(u16 *)(D_80800208_chtempleinternaldoor + index * 8)), arg0->unk0->unk16);
}
/* data_to_c.py: from asm/data/overlays/ch/temple/internaldoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808001C0_chtempleinternaldoor [1] BT_DATA(4, overlays_ch_temple_internaldoor, 0x0) = { { 172, 694, 2112, 1, 0, (void (*)(struct Actor *))func_808000F8_chtempleinternaldoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chtempleinternaldoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800138_chtempleinternaldoor, 0 } };
#ifndef BT_NATIVE
u8 D_80800208_chtempleinternaldoor [4] BT_DATA(4, overlays_ch_temple_internaldoor, 0x48) = { 8, 0x3F, 0, 0 };
f32 D_8080020C_chtempleinternaldoor [12] [ 2 ] BT_DATA(4, overlays_ch_temple_internaldoor, 0x4C) = { { 190.0f, 5.77779e-34f }, { 190.0f, 5.8078825e-34f }, { 205.0f, 5.837975e-34f }, { 150.0f, 5.868068e-34f }, { 150.0f, 5.8981605e-34f }, { 150.0f, 5.928253e-34f }, { 150.0f, 5.9583458e-34f }, { 150.0f, 5.9884384e-34f }, { 150.0f, 6.018531e-34f }, { 150.0f, 6.2592723e-34f }, { 150.0f, 6.2291797e-34f }, { 150.0f, 0.0f } };
#endif
