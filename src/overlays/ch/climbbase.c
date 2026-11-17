#include "common.h"

/* extern */

s32 func_80800000_chclimbbase(Actor *arg0, f32 *arg1) {
    s32 _gccubesearch_entrypoint_13(f32 *, u32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 *temp_s0;
    s32 var_v1;
    s32 temp_v0;

    temp_s0 = arg0->position;
    var_v1 = _gccubesearch_entrypoint_13(sp44, 0x1FA, temp_s0);
    temp_v0 = _gccubesearch_entrypoint_13(sp38, 0x1FB, temp_s0);
    if ((var_v1 == 0) && (temp_v0 == 0)) {
        return 0;
    }
    if ((var_v1 != 0) && (temp_v0 != 0)) {
        sp34 = func_800EFB8C(temp_s0, sp44);
        if (func_800EFB8C(temp_s0, sp38) < sp34) {
            var_v1 = 0;
        }
    }
    if (var_v1 != 0) {
        func_800EE7F8(arg1, sp44);
        arg0->unk6C_0 = 1;
    } else {
        func_800EE7F8(arg1, sp38);
        arg0->unk6C_0 = 2;
    }
    return 1;
}

/* extern */

s32 func_808000FC_chclimbbase(void) {
    s32 _gclevel_entrypoint_4(s32);
    if (_gclevel_entrypoint_4(0x80) != 0) {
        return 2;
    }
    return 1;
}
struct ClimbEntry { s32 id; f32 scale; };
void func_80800128_chclimbbase(Actor *arg0) {
    f32 func_800EEAD4(f32 *, f32 *);

    struct ClimbFields { u8 pad[0x7C]; s16 distance; };
    extern struct ClimbEntry D_808003B0_chclimbbase[4];
    struct ClimbEntry *entry;

    func_80800000_chclimbbase(arg0, (f32 *)arg0->actorData);
    entry = D_808003B0_chclimbbase;
    if (1.0f == arg0->scale) {
        arg0->actorData[3] = func_808000FC_chclimbbase();
    } else {
        while (entry->id != 4 && entry->scale != arg0->scale) {
            entry++;
        }
        arg0->actorData[3] = entry->id;
    }
    ((struct ClimbFields *)arg0)->distance = (s32)func_800EEAD4(arg0->position, (f32 *)arg0->actorData) + 500;
}

void func_80800200_chclimbbase(Actor *arg0) {
    void func_800EFB24(void *, void *, void *);
    BtUIntPtr func_800F54E4(void);
    void func_800F7F00(BtIntPtr, BtIntPtr, BtIntPtr, f32, s32, s32, f32);
    void func_800F7F50(BtIntPtr, BtIntPtr, BtIntPtr, f32, s32, s32);
    void func_8010D254(f32 *);
    f32 difference[3];
    register f32 radius;
    f32 position[3];

    radius = (s32)arg0->unk74_7 + 25;
    func_8010D254(position);
    func_800EFB24(difference, arg0->position, position);
    if (difference[0] * difference[0] + difference[2] * difference[2] < radius * radius
        && arg0->position[1] < position[1]
        && position[1] <= ((f32 *)arg0->actorData)[1]) {
        switch (arg0->unk6C_9) {
            case 0x1F9:
                func_800F7F50(func_800F54E4(), (BtIntPtr)arg0->position, (BtIntPtr)arg0->actorData,
                    arg0->unk74_7, arg0->unk6C_0, arg0->actorData[3]);
                break;
            case 0x16E:
                func_800F7F00(func_800F54E4(), (BtIntPtr)arg0->position, (BtIntPtr)arg0->actorData,
                    arg0->unk74_7, arg0->unk6C_0, arg0->actorData[3], arg0->rotation[1]);
                break;
        }
    }
}
#include "climbbase_data.inc"
OSThread *chclimbbase_entrypoint_0(void)
{
    extern ActorData D_808003D0_chclimbbase[];

    return (OSThread *) D_808003D0_chclimbbase;
}

OSThread *chclimbbase_entrypoint_1(void)
{
    extern ActorData D_80800418_chclimbbase[];

    return (OSThread *) D_80800418_chclimbbase;
}
