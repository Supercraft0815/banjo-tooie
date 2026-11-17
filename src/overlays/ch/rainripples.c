#include "common.h"

OSThread *chrainripples_entrypoint_0(void)
{
    extern ActorData D_80800290_chrainripples[];

    return (OSThread *) D_80800290_chrainripples;
}    typedef struct { u8 pad0[0x2C]; f32 unk2C; } Objrainripples_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_chrainripples(void *arg0) {
    f32 func_808001FC_chrainripples();
    (((Objrainripples_arg0 *)arg0)->unk2C) = (f32) (func_808001FC_chrainripples() + 4.0f);
}

void func_80800040_chrainripples(Actor *arg0) {
    int _fxrain_entrypoint_3(void *arg0);
    s32 func_800B7C98(void);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808002D8_chrainripples[];
    struct RippleData { s32 pad[4]; s32 index; f32 height; };
    struct RainPoint { f32 position[3]; s16 radius; };
    f32 angle;
    s32 count;
    s32 total;
    s32 i;
    BtIntPtr effect;
    BtIntPtr rain;
    f32 position[3];
    struct RainPoint *point;
    f32 delta;

    rain = func_800B7C98();
    if (rain != 0 && _fxrain_entrypoint_3(rain) != 0) {
        delta = func_800D8FF8();
        count = arg0->unk74_7 * delta;
        total = func_800CC5F4(arg0->unk70_25 - 1);
        effect = 0;
        if (count != 0) {
            effect = func_800B5BE4(3);
        }
        for (i = 0; i < count; i++) {
            point = func_800CC63C(arg0->unk70_25 - 1, ((struct RippleData *)arg0->actorData)->index);
            func_800EE7F8(position, point->position);
            angle = func_800DC178(0.0f, 359.0f);
            func_800EF1B8(position, angle, func_800DC178(0.0f, point->radius));
            position[1] = ((struct RippleData *)arg0->actorData)->height;
            func_800BABB8(effect, position, NULL, 1.0f, D_808002D8_chrainripples);
            if (++((struct RippleData *)arg0->actorData)->index >= total) {
                ((struct RippleData *)arg0->actorData)->index = 0;
            }
        }
    }
}

/* extern */

f32 func_808001FC_chrainripples(f32 *arg0) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0 + 1);
    func_800EE7F8(sp28, arg0 + 1);
    sp34[1] += 100.0f;
    sp28[1] -= 100.0f;
    if (func_800BEF00(sp34, sp28, sp1C, 0x1F00) != 0) {
        return sp28[1];
    }
    return arg0[2];
}
/* data_to_c.py: from asm/data/overlays/ch/rainripples.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800290_chrainripples [1] BT_DATA(4, overlays_ch_rainripples, 0x0) = { { 165, 991, 0, 1, 0, (void (*)(struct Actor *))func_80800040_chrainripples, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 0, 1, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chrainripples, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
s32 D_808002D8_chrainripples [10] BT_DATA(4, overlays_ch_rainripples, 0x48) = { 1903067, 1446401, 2818252, 16777237, 128, 2228249, 1638553, 16777247, -512, 18481152 };
