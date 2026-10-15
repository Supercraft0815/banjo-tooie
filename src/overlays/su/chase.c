#include "common.h"

s32 suchase_entrypoint_0(void) {
    s32 func_8001211C();
    void func_8010D254(s32 *);
    void func_808000A8_suchase(s32 *, s32 *);
    extern s32 D_808001D0_suchase[2];
    s32 temp_v0;
    s32 sp18[3];

    temp_v0 = func_8001211C();
    if (temp_v0 != D_808001D0_suchase[0]) {
        func_8010D254(sp18);
        D_808001D0_suchase[1] = 0;
        D_808001D0_suchase[0] = temp_v0;
        func_808000A8_suchase(D_808001D0_suchase, sp18);
    }
    return D_808001D0_suchase[1];
}

/* extern */

int suchase_entrypoint_1(s32 *arg0) {
    s32 suchase_entrypoint_0();
    s32 value;
    value = suchase_entrypoint_0();
    return value == 0 || value == *arg0;
}

/* extern */

void func_808000A8_suchase(s32 *arg0, s32 *arg1) {
    typedef struct {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 unk8:27;
        u32 active:1;
        u32 unk9:3;
        u32 isMarker:1;
    } HitProp;
    typedef struct {
        u8 pad0[0x64];
        u32 pad64_31:1;
        u32 unk64_30:1;
        u32 unk64_29:1;
        u32 rest:29;
    } ChaseActorFlags;
    s32 *func_800BE444(f32 *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 distance;
    f32 best = 1e10f;
    s32 *cell;
    HitProp *prop;
    HitProp *end;
    Unk80132ED0 *marker;
    Actor *actor;

    cell = func_800BE444((f32 *)arg1);
    while (*cell) {
        prop = (HitProp *)func_800E9E88(*cell);
        end = (HitProp *)func_800E9EB4((s16 *)*cell);
        while (prop < end) {
            if (prop->isMarker) {
                marker = prop->marker;
                if (((u16 *)&marker->unk18)[0] & 1) {
                    actor = func_80106790(marker);
                    if (!((ChaseActorFlags *)actor)->unk64_29 && ((ChaseActorFlags *)actor)->unk64_30) {
                        distance = func_800EEB40(actor->position, (f32 *)arg1);
                        if (distance < best) {
                            arg0[1] = (s32)marker;
                            best = distance;
                        }
                    }
                }
            }
            prop++;
        }
        cell++;
    }
}
