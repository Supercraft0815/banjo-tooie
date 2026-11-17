#include "common.h"

OSThread *chcamwaypoint_entrypoint_0(void)
{
    extern ActorData D_80800130_chcamwaypoint[];

    return (OSThread *) D_80800130_chcamwaypoint;
}    typedef struct { u8 pad0[0x24]; f32 unk24; } Objcamwaypoint_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chcamwaypoint(u8 *arg0) {
    f32 func_800EEAA4(f32 a[3], f32 b[3]);
    void func_800EEBF0(f32*, f32*, f32);
    func_800EEBF0((f32 *)(arg0 + 0x18), (f32 *)(arg0 + 0x44), 1.0f);
    (((Objcamwaypoint_arg0 *)arg0)->unk24) = func_800EEAA4(arg0 + 4, (f32 *)(arg0 + 0x18));
}

/* extern */

void func_8080005C_chcamwaypoint(Actor *arg0) {
    s32 _ncbawaypoint_entrypoint_2(BtIntPtr, f32 *, u32 *, u32);
    void func_8008FE68(f32 *);
    s32 func_8008FFE8();
    s32 func_800EFFB4(f32 *, f32, f32 *);
    s32 func_8010FAE4(s16 *);
    BtIntPtr func_80110014(s32 *);
    void func_801107F0(void *, f32 *);
    BtIntPtr sp34;
    BtIntPtr sp30;
    f32 sp2C;
    struct { f32 *point; f32 position[3]; } sp1C;

    sp30 = func_8008FFE8();
    if ((func_8010FAE4(sp30) == 2) && ((sp34 = func_80110014(sp30), sp2C = (f32) ((s32)arg0->unk74_7 * 10), func_8008FE68(sp1C.position), sp1C.point = arg0->position, (func_800EFFB4(sp1C.point, sp2C, sp1C.position) != 0)) || (func_801107F0(sp34, sp1C.position), (func_800EFFB4(sp1C.point, sp2C, sp1C.position) != 0)))) {
        _ncbawaypoint_entrypoint_2(sp34, sp1C.point, arg0->actorData, arg0->actorData[3]);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/camwaypoint.data.s */
void func_80102EC0();
void func_8010A730();
void func_80107C2C();
ActorData D_80800130_chcamwaypoint [1] BT_DATA(4, overlays_ch_camwaypoint, 0x0) = { { 344, 477, 0, 1, 0, (void (*)(struct Actor *))func_8080005C_chcamwaypoint, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chcamwaypoint, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9730, 0, 0 } };
